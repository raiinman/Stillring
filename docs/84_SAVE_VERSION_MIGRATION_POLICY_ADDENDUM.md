# 84 — Persistent World-State / Save Decision #4 — Version and Migration Policy

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #4 — Define persistent world-state and save schema  
**Decision:** #4 — version responsibility, compatibility direction, deterministic migrations, and persistent-ID retirement

## Decision question

How does Stillring evolve Save Schema v1 without silently losing player history when fields, record kinds, persistent IDs, Hush representation, or authored content change?

## Locked philosophy

> **Migrate meaning forward. Never guess, never downgrade, never overwrite the only source copy while proving a migration.**

A migration is an explicit semantic translation from one known save contract to another. It is not a permissive deserializer hoping renamed properties happen to line up.

## Research basis

Fresh Unreal Engine 5.8 research confirms a useful precedent: Unreal's own asset/package versioning is monotonic, older data can be read by newer code when compatibility is defined, newer-version data is rejected by older readers to protect against data loss, and project/system-specific custom versions can use GUID-scoped version streams. `FArchive::CustomVer`/custom serialization are implementation primitives; Stillring's player-save compatibility policy remains project-owned.

Primary references:
- Epic UE5.8 — Versioning of Assets and Packages: https://dev.epicgames.com/documentation/unreal-engine/versioning-of-assets-and-packages-in-unreal-engine
- Epic UE5.8 — `FArchiveState::CustomVer`: https://dev.epicgames.com/documentation/unreal-engine/API/Runtime/Core/FArchiveState/CustomVer
- Epic UE5.8 — Saving and Loading Your Game: https://dev.epicgames.com/documentation/unreal-engine/saving-and-loading-your-game-in-unreal-engine

Project authority reconciled:
- `docs/81_SAVE_PERSISTENT_IDENTITY_ADDENDUM.md`
- `docs/82_SAVE_STATE_TAXONOMY_OWNERSHIP_ADDENDUM.md`
- `docs/83_SAVE_SCHEMA_V1_STRUCTURE_ADDENDUM.md`
- `docs/75_GATE4_HUSH_SAVE_RELOAD_ADDENDUM.md`

## 1. Version hierarchy

Stillring keeps three explicit monotonic version scopes.

### Global `SchemaVersion`
Increment when the aggregate on-disk semantic contract changes in a way that requires a migration step or changes how a loader interprets the save as a whole.

### `SectionVersion`
Increment when one top-level domain section changes structure/semantics. This localizes migration work and lets tooling explain which domain changed.

### `RecordVersion`
Increment when one stable `RecordKind` changes payload semantics/shape.

Rules:
- versions never decrease;
- versions are integers, not build timestamps;
- a global schema migration may invoke multiple narrower section/record migrations;
- narrow versions do not replace the global compatibility contract;
- version numbers describe serialized semantics, not feature marketing versions.

## 2. Content revision is not schema version

`ContentRevision` from Save v1 identifies the authored content/build context useful to compatibility diagnostics and content migrations.

A new build/content revision does **not** automatically require a schema bump.

Examples not requiring schema migration:
- art/audio replacement;
- Actor/package rename while semantic IDs remain stable;
- Hush representation moved between Runtime Data Layers without changing semantic facts;
- balance numbers that do not alter stored meaning.

Examples requiring reviewed migration/version change:
- persistent fact meaning changes;
- record payload changes interpretation;
- persistent ID retired/replaced/split/merged;
- quest stage encoding changes;
- save section ownership/shape changes.

## 3. Compatibility direction

### Older save -> newer executable
Supported only through an explicit known migration chain.

The loader:
1. reads/validates immutable source envelope;
2. identifies exact source schema/section/record versions;
3. builds an ordered migration plan;
4. migrates **in memory** toward current version;
5. canonicalizes;
6. validates all current invariants;
7. only then reconstructs gameplay.

### Newer save -> older executable
Never guessed or downgraded.

If `SourceSchemaVersion > CurrentSchemaVersion`, return a distinct `SaveFromNewerVersion` compatibility result. Leave the file untouched. The older executable may explain that a newer game version is required, but it must not load-and-resave the save with unknown data discarded.

### Same version
Still validate section/record versions, persistent IDs, ownership, and semantic invariants. Matching a global version does not waive validation.

## 4. Public compatibility promise

Before a public/release compatibility boundary is declared, development/test saves may be intentionally disposable **only when explicitly marked development-only**.

Once a save version ships to players, later builds of the same Stillring product should retain forward-reading support through explicit migrations for released saves unless a truly exceptional incompatibility is documented and approved.

Do not casually prune released migration paths merely because code has changed.

## 5. Migration pipeline

A migration step is an explicit deterministic transform:

```text
Migrate_Save_vN_to_vNPlus1(Source) -> Result<Destination, MigrationError>
```

Properties:
- exact source version precondition;
- produces a new destination representation rather than mutating the only source buffer/file;
- deterministic for identical input + migration tables;
- no world/Actor dependency;
- no network/model/API dependency;
- no player-input dependency;
- records every semantic transformation for diagnostics;
- fails closed when required meaning is ambiguous.

Migration steps run sequentially: v1 -> v2 -> v3, not a collection of ad hoc conditionals sprinkled through gameplay code.

## 6. Idempotence / replay safety

Migration is version-gated.

A v1->v2 transform only accepts a v1 source and emits canonical v2. Running the load pipeline again on the resulting v2 cannot reapply the v1 transform.

Where a migration helper transforms an individual record, the resulting record/version must make repeat application a no-op/rejection rather than duplicating rewards, facts, inventory, or completion.

## 7. Persistent-ID migration registry

Decision #1 IDs are never recycled. Content evolution uses an explicit migration registry.

Each retired ID has one disposition:

### `Alias` / one-to-one replacement
`OldId -> NewId`

Used only when semantic identity is genuinely continuous but the canonical ID must change for an exceptional reviewed reason.

### `RetireDrop`
Old record becomes obsolete and is intentionally consumed/dropped with documented reason and proof that no durable player entitlement/history is lost.

### `RetireToFact`
Old entity state is converted into another current semantic fact.

### `Split`
One old semantic record becomes multiple current records through deterministic authored rules.

Example: an old combined community state becomes separate infrastructure + relationship facts. Migration must state how every old value maps to each new fact.

### `Merge`
Multiple old records combine into one current record through explicit precedence/combination rules.

No first-found/map-order behavior.

### `Incompatible`
Reserved for cases with no honest deterministic interpretation. Recovery handling is Decision #5; this disposition must be rare and documented.

## 8. Tombstone lifetime

A retired persistent ID remains in the migration/tombstone registry for as long as any supported released save may contain it.

Deleting source content does not delete migration knowledge.

Tooling must block reuse of a tombstoned GUID.

## 9. Quest/content evolution rules

### Renaming display/content representation
No migration if semantic ID and meaning stay unchanged.

### Removing optional content
Migration must decide whether its old completion/reward/history remains represented, maps to successor content, or is intentionally retired without breaking 100% integrity for that playthrough.

### Quest stages reordered/refactored
Do not map by numeric ordinal alone. Use old schema/record version plus semantic stage meaning to translate into a valid current state.

### Content split/merge
Use explicit `Split`/`Merge` migrations; never infer from actor/package structure.

### Completion taxonomy changes
Protect already-earned durable entitlements. Completion recomputation after migration must be explainable from migrated canonical records and current authored taxonomy.

## 10. Hush representation changes

Gate 4's semantic layer authority makes ordinary Unreal representation refactors migration-free when semantic meaning is unchanged.

Examples:
- Data Layer asset renamed;
- World Partition representation replaced by explicit levels;
- paired Actor classes refactored;
- material/presentation pipeline replaced.

If the same semantic persistent IDs/facts remain, reload materializes the new representation from old semantic truth.

A migration is required only when the semantic Hush facts themselves change.

## 11. Unknown records/IDs under a supported version

A loader must distinguish:
- newer/unsupported schema;
- known schema with unsupported record version;
- known schema with unknown `RecordKind`;
- known record kind with unknown/tombstoned `RecordId`.

For a supported released source version, these normally indicate missing migration code/table or corrupted/inconsistent data; they must not silently default away.

Exact player recovery/quarantine behavior is Decision #5.

## 12. No backward writing / downgrade

Stillring writes only the executable's current canonical save schema.

It does not:
- save back into an older schema;
- provide lossy downgrade migrations;
- let an older executable rewrite a newer save;
- preserve unknown future fields by pretending it understands them.

This avoids the classic data-loss path where older code loads partially understood data then overwrites the source.

## 13. Source-file safety during migration

Migration operates on loaded bytes/data and keeps the original disk save unchanged until the current-version semantic state has fully migrated and validated.

A successful migration does **not** need to immediately overwrite the source slot. The next explicit successful save may write the current schema under the transactional disk policy defined later.

This keeps a recoverable original if gameplay reconstruction or later validation exposes a defect.

## 14. Migration registry location

Migration code/tables are repository-backed production authority.

Required durable artifacts:
- global schema migration list;
- section/record migration adapters;
- persistent-ID tombstone/replacement registry;
- golden input/output fixtures for every supported historical version;
- migration notes explaining player-facing semantic effect.

Do not hide compatibility tables only inside binary assets or editor state.

## 15. System IDE — migration surface

The Save / World-State workbench must provide development-only **Migration Preview**.

For a selected save/fixture show:
- source/current schema version;
- section/record versions;
- planned ordered migration steps;
- every persistent-ID disposition;
- records added/removed/transformed;
- warnings/errors;
- pre/post canonical semantic diff;
- invariant-validation result;
- whether the source is released-supported vs development-disposable.

Preview does not overwrite the source.

A migration audit export must be attachable to PR evidence.

## 16. Verification fixtures

### S4-F01 — v1 current no-op
Current v1 fixture loads with no migration transform and canonicalizes identically.

### S4-F02 — ordered synthetic v1->v2->v3
Fixture proves migrations run exactly once and in order.

### S4-F03 — deterministic replay
Two migration runs from identical immutable source produce byte-for-byte identical canonical semantic export.

### S4-F04 — newer save rejection
Current v1 executable receives synthetic v2 save; returns `SaveFromNewerVersion`, does not modify source.

### S4-F05 — ID alias
Old ID maps to reviewed successor without duplicate record/reward.

### S4-F06 — retired ID
Old record is consumed according to explicit tombstone disposition and never attaches to unrelated new content.

### S4-F07 — split
One old record deterministically generates required current records; rerun cannot duplicate state.

### S4-F08 — merge
Two old records combine with explicit deterministic precedence.

### S4-F09 — quest-stage refactor
Old numeric/stage representation maps by documented semantic version rule, not current ordinal coincidence.

### S4-F10 — Hush representation-only refactor
Old save reconstructs new representation with no semantic migration because IDs/facts are unchanged.

### S4-F11 — missing migration
Supported old version with no required adapter hard-fails migration validation rather than defaulting fields.

### S4-F12 — source preservation
Force post-migration invariant failure; original source file/fixture remains byte-identical.

## 17. CI / release gate

Before a build may claim compatibility with a prior released save version:
- every historical golden fixture in the supported window migrates to current;
- canonical post-migration invariants pass;
- completion/quest/world/Hush ownership validation passes;
- no duplicate rewards/facts appear;
- source fixtures remain unchanged;
- current build can save/reload the migrated semantic state in its own current schema once runtime implementation exists.

Automated migration proof cannot replace human play around high-value story/world pivots, but it is a hard machine gate.

## 18. Accessibility / player-facing implications

Migration must preserve accessibility-neutral gameplay entitlements and world history; accessibility/profile settings live separately per Decision #2. Compatibility errors/recovery UI must use comprehensible wording rather than raw schema jargon, while diagnostic detail remains available to developers.

## 19. IP boundary

This is an original migration/versioning policy based on generic durable-data engineering and public Unreal versioning primitives. It does not use proprietary Nintendo/Zelda save migrations, flag translations, byte layouts, or reverse-engineered compatibility behavior.

## 20. Rejected alternatives

### Best-effort property deserialization
Rejected: renamed/defaulted fields can silently corrupt meaning.

### One enormous `if (Version < X)` loader forever
Rejected: tangled, hard to test, and encourages partial side effects during read.

### Actor/package path redirects as world-history migration
Rejected: representation redirects are not semantic persistence mappings.

### Reuse deleted GUIDs
Rejected absolutely.

### Always overwrite old save immediately after migration
Rejected: destroys the strongest recovery artifact before migration/runtime validation has proved itself.

### Backward save downgrade
Rejected: lossy and dangerous.

## 21. Approval

**APPROVED / LOCKED under the owner's scheduled-run delegation.**

Issue #4 Decision #4 is complete.

### Locked statement

> **Released saves move forward only through explicit deterministic migrations. Older code never guesses at newer saves, and retired semantic IDs remain accounted for until no supported save can reference them.**

## Next decision

Issue #4 Decision #5:

> **How does Stillring detect, contain, recover from, and communicate malformed/corrupt/incompatible saves without destroying the player's last good state?**
