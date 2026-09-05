# 88 — Persistent World-State / Save Cumulative Specification

**Status:** FINAL OWNER-DELEGATED APPROVAL / ISSUE #4 DESIGN CLOSURE AUTHORITY  
**Updated:** 2026-09-05  
**Issue:** #4 — Define persistent world-state and save schema  
**Scope:** cumulative implementation-facing reconciliation of Save / World-State Decisions #1–#7

## Purpose

This document reconciles the individually researched and approved save/world-state decisions into one implementation-facing contract. Detailed provenance remains in `docs/81`–`docs/87`; if this cumulative specification and an addendum ever disagree, stop and reconcile rather than inventing a third rule.

## Core philosophy

> **Persist meaning, reconstruct presentation.**

Supporting rules:

> **Save identity belongs to the authored game meaning, not to the current Unreal object instance.**

> **Each durable fact has one gameplay owner; the save system snapshots those owners.**

> **Released saves move forward only through explicit deterministic migrations.**

> **Stillring publishes new generations without sacrificing the last verified one.**

> **Saving protects the journey; retry restores the encounter.**

> **The Save IDE explains and exercises authority; it never becomes a second owner.**

---

# 1. Canonical identity

Stillring uses project-owned semantic persistent IDs based on non-zero `FGuid` values.

Persistent identity survives representation changes including:
- Actor/label rename;
- package/map movement;
- World Partition/Data Layer representation changes;
- Blueprint/C++ refactor;
- Hush/Waking materialization refactor;
- loaded/unloaded streaming lifecycle.

Forbidden canonical keys include runtime pointers, process-local IDs, Actor names/labels, UObject paths, package paths, World Partition cells, Data Layer names, OFPA filenames, array positions, coordinates, and engine/editor Actor GUIDs used as semantic world identity.

Persistent GUIDs are authored once, validated for uniqueness, never recycled, and retained through tombstone/migration knowledge when retired.

A Waking/Hush pair representing one semantic entity shares one persistent semantic identity; layer-exclusive durable entities have their own identity.

Authority: `docs/81_SAVE_PERSISTENT_IDENTITY_ADDENDUM.md`.

---

# 2. State ownership

Every durable canonical fact has exactly one gameplay owner. The Save Coordinator owns snapshot orchestration/serialization, not gameplay meaning.

Canonical domains:
- Save Header / Schema — Save Coordinator;
- Player durable progression — Player Progression;
- Inventory/tools/currency/owned upgrades — Inventory & Tool Progression;
- Quest/objective/narrative progression — Quest / Story State;
- persistent environment/world facts — World State;
- Hush/Waking semantic layer/facts — World-Layer/Hush authority;
- boss/unique encounter outcomes — Encounter State;
- completion/collectibles — Completion Ledger;
- persistent NPC recurrence facts — World State until a dedicated recurrence owner is promoted;
- checkpoint/location — Checkpoint / Travel service.

Settings/profile persistence is separate from playthrough world state.

Transient/derived state is reconstructed and is not canonical save truth by default, including movement phases, camera state, lock candidates, attack phases, buffered input, AI task stacks, projectiles, tool previews, in-flight Hush seams, streaming handles, UI state, and System IDE session overrides.

Cross-domain operations settle as semantic transactions before a save snapshot is allowed.

Authority: `docs/82_SAVE_STATE_TAXONOMY_OWNERSHIP_ADDENDUM.md`.

---

# 3. Save Schema v1

Canonical conceptual structure:

```text
FStillringSaveV1
  Header
  Checkpoint
  PlayerProgression
  Inventory
  QuestState
  WorldState
  HushState
  EncounterState
  CompletionState
  NpcRecurrenceState
```

Header includes at minimum:
- `SchemaVersion = 1`;
- `PlaythroughId`;
- `SnapshotId`;
- UTC capture timestamp;
- accumulated playtime;
- content revision;
- save reason.

Each section declares a stable section identity/version. Persistent records use a stable semantic envelope:

```text
RecordId      : FStillringPersistentId
RecordKind    : stable project-owned semantic kind
RecordVersion : uint32
LayerScope    : optional Shared | Waking | Hush
Payload       : kind-specific typed semantic data
```

`RecordKind` must not be a UObject/Blueprint/package/class/reflected-struct path.

Schema is sparse only when absence has one explicit canonical meaning. Canonical output order is deterministic. Development builds provide a human-readable canonical semantic export from the same snapshot used for production serialization.

Raw Actor/UObject graphs are not canonical save data.

Authority: `docs/83_SAVE_SCHEMA_V1_STRUCTURE_ADDENDUM.md`.

---

# 4. Snapshot barrier

A durable save snapshot may be captured only after authoritative semantic transactions reach a save-stable boundary.

Required conceptual sequence:
1. semantic transactions settle;
2. authoritative domain owners produce immutable snapshots;
3. cross-owner invariants validate;
4. Save Coordinator assembles/canonicalizes schema v1;
5. integrity metadata is generated;
6. immutable candidate is handed to storage;
7. completion/publication result is observed;
8. later gameplay mutations belong to a later snapshot.

The disk serializer does not query live Actors while writing bytes.

Hush authority remains explicit: an in-flight seam is never serialized as a half-state. Save waits until the committed semantic layer and facts are stable.

---

# 5. Versioning and migration

Versions are monotonic at global schema, section, and record scopes.

`ContentRevision` is diagnostic/migration context, not a substitute for schema version.

Older released saves may load in newer builds only through explicit deterministic migration chains. Migration:
- runs on immutable source data in memory;
- applies exact ordered version steps;
- never depends on loaded Actors/world state;
- canonicalizes and validates before gameplay reconstruction;
- never overwrites the only source copy while proving translation.

Newer saves are never guessed/downgraded by older executables.

Persistent-ID evolution uses repository-backed dispositions:
- Alias;
- RetireDrop;
- RetireToFact;
- Split;
- Merge;
- explicitly Incompatible only when no honest deterministic interpretation exists.

Retired IDs remain tombstoned while any supported save may reference them.

Ordinary Hush/World Partition/Data Layer representation refactors require no save migration when semantic IDs/facts remain unchanged.

Authority: `docs/84_SAVE_VERSION_MIGRATION_POLICY_ADDENDUM.md`.

---

# 6. Integrity and recovery

Load failures are classified, including storage/read failure, malformed envelope, integrity mismatch, newer version, unsupported historical version, migration failure, unknown ID/kind/version, semantic invariant failure, and representation reconstruction failure.

A logical playthrough preserves generations above the platform storage abstraction:
- newest candidate/current;
- verified Last Known Good;
- older rotating recovery generation where platform storage permits.

A new save cannot sacrifice the only verified LKG before the candidate successfully publishes and passes required validity checks.

Load selection examines generations newest-first and picks the newest generation that passes:
1. storage/envelope/integrity;
2. version compatibility/migration;
3. semantic invariants;
4. safe checkpoint/representation reconstruction.

Failed newest generations are quarantined/preserved for diagnostics where practical; recovery may fall back to LKG.

Automatic repair is allowed only when semantic meaning is deterministic. Stillring never guesses quest choice, boss state, item ownership, completion, Hush fact, or other durable history to force a damaged generation to load.

Player-facing messaging distinguishes rollback, corruption, newer-version incompatibility, and storage write failure honestly.

Authority: `docs/85_SAVE_INTEGRITY_RECOVERY_ADDENDUM.md`.

---

# 7. Slots, autosave, manual save, and retry

A player-facing Playthrough Slot is one independent journey keyed by `PlaythroughId`. Internal recovery generations are not ordinary save-menu clutter.

Stillring:
- supports multiple independent playthroughs;
- autosaves meaningful durable progress;
- supports manual save from ordinary controllable gameplay at safe semantic boundaries;
- defers manual saves during active hostile combat, in-flight Hush seams, unsafe traversal microstates, unsettled cross-domain transactions, map/load transitions, or another owning save/load operation;
- coalesces multiple triggers into one coherent post-transaction snapshot;
- never runs competing writes to the same playthrough;
- queues a follow-up snapshot if durable mutations occur during an in-flight write;
- truthfully reports Saving / Saved / SaveFailed.

Autosave triggers include meaningful checkpoint/area transitions, durable progression/tool acquisition, major quest/world facts, boss/unique encounter resolution, significant completion, shortcuts/refuges, and major Hush causal resolution after semantic settlement.

Death itself is not a disk-save trigger.

Death/retry uses a dedicated **Retry Checkpoint Snapshot**, distinct from the latest durable disk generation. Retry restores a fresh valid encounter/world/player baseline under checkpoint/world/encounter authority, never a half-dead combat frame.

Authority: `docs/86_SAVE_SLOT_CADENCE_RETRY_ADDENDUM.md`, reconciled with `docs/47_GATE2_COMBAT_DEATH_RETRY_ADDENDUM.md`.

---

# 8. Hush reconciliation

Gate 4 authority remains unchanged:

> **Save the truth once. Rebuild the expression from the truth.**

Save stores:
- committed active semantic layer when save-stable;
- shared facts once per semantic identity;
- explicitly layer-local facts with semantic layer scope;
- cross-layer causal facts required by gameplay/history.

Save does not store:
- Runtime Data Layer activation handles;
- streaming progress;
- seam blend percentage;
- collision handoff timeline;
- post-process/audio transition state;
- half-materialized representation.

Load/migration restores semantic truth before representation, then materializes the current authored Waking/Hush implementation.

Authority: `docs/75_GATE4_HUSH_SAVE_RELOAD_ADDENDUM.md`, `docs/79_GATE4_HUSH_CUMULATIVE_SPECIFICATION.md`.

---

# 9. Save / World-State System IDE

Development-only workbench modes:
- Overview;
- Identity;
- Live State;
- Snapshot / Schema;
- Fixtures / Presets;
- Migration;
- Recovery / Generations;
- Validation;
- Capture / Diff.

The workbench must answer:
- what does the game currently believe?;
- who owns each durable fact?;
- what will be captured by a save now?;
- why is saving blocked/deferred?;
- why did a load/migration/recovery succeed or fail?;
- what semantic state changed between snapshots?;
- how can this state be reproduced from a repository-backed preset?;
- which exact validation rule failed?

Named presets are semantic recipes applied through authoritative owner APIs, not opaque magic saves/private-field mutation.

Fault injection is deterministic and Development/Test only. Shipping excludes workbench UI, fault injection, arbitrary fixture mutation, developer generation selection, raw forensic tooling, external listeners, model/API dependencies, and any bypass of retail save protections.

Automation Specs/CQTest/Gauntlet should call the same semantic test services used by the IDE where practical.

Authority: `docs/87_SAVE_WORLD_STATE_IDE_ADDENDUM.md`, `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`.

---

# 10. Full-playthrough persistence fixture contract

The save system must eventually prove a representative synthetic/playable route containing at least:

### P0 — clean new game
- canonical default snapshot;
- no duplicate/missing IDs;
- initial checkpoint/layer valid.

### P1 — early exploration
- ordinary inventory/currency progress;
- one persistent interactable/shortcut;
- manual save/load;
- representation unload/reload.

### P2 — quest/world transaction
- quest stage and world consequence settle under separate owners;
- one snapshot after transaction;
- derived objective/UI state reconstructs.

### P3 — major tool/progression acquisition
- tool ownership persists;
- tool runtime preview/target state does not;
- autosave trigger occurs after transaction.

### P4 — Hush checkpoint
- committed Hush layer;
- one shared paired fact;
- one layer-local fact;
- save/exit/load reconstructs semantic state before representation.

### P5 — encounter death/retry
- retry snapshot differs from durable disk snapshot;
- combat transient state clears;
- no death-frame save;
- no reward duplication.

### P6 — boss/unique encounter resolution
- encounter outcome, world consequence, quest result, completion, and reward settle coherently;
- one coalesced durable snapshot;
- repeated reload cannot duplicate reward/fact.

### P7 — catastrophe/world pivot
- irreversible semantic world fact persists;
- current representation reconstructs from fact;
- old Actor/package/Data Layer paths are irrelevant.

### P8 — completion reconciliation
- completion IDs persist;
- percentages/counts recompute;
- 100% model does not depend on duplicated cached truth.

### P9 — migration
- historical golden fixture migrates deterministically to current schema;
- source unchanged;
- current canonical export matches expected fixture.

### P10 — corruption recovery
- newest generation corrupted/semantically invalid;
- LKG selected;
- rollback is disclosed;
- failed generation does not become truth.

### P11 — refactor immunity
- representative Actor/package/Blueprint/Hush representation changes retain semantic GUIDs;
- old save still reconstructs intended meaning.

### P12 — Shipping boundary
- retail save/load works;
- Save IDE/fault/preset mutation surfaces are unavailable;
- no runtime model/API dependency exists.

---

# 11. Issue #4 acceptance matrix

| Issue acceptance criterion | Authority | Design status |
|---|---|---|
| Persistent ID format and ownership rules | `docs/81`, this spec §1 | SATISFIED |
| Player/inventory/quest/world/boss/shortcut/collectible/catastrophe categories | `docs/82`, this spec §2 | SATISFIED |
| Waking/Hush persistence rules | `docs/75`, `docs/79`, this spec §8 | SATISFIED |
| Save schema version field from v1 | `docs/83`, this spec §3 | SATISFIED |
| Migration policy | `docs/84`, this spec §5 | SATISFIED |
| Node paths/runtime IDs forbidden as canonical keys | `docs/81`, `docs/83`, this spec §1/§3 | SATISFIED |
| Example serialized fixture | `docs/83` | SATISFIED |
| Malformed/incompatible recovery | `docs/85`, this spec §6 | SATISFIED |

Issue #4's **design acceptance criteria are satisfied**.

Its separate runtime verification statement — a paired-layer prototype can save, exit, reload, and reproduce intended semantic world state — is **NOT YET EXECUTED**. Closing the design issue does not claim that Unreal prototype proof exists.

---

# 12. Implementation authorization

The save/world-state design is implementation-authorized against this specification.

Safe implementation sequence:
1. semantic persistent ID type/registry + validation;
2. owner-domain snapshot interfaces;
3. explicit v1 schema structs/semantic kinds;
4. Save Coordinator stable-barrier/canonical snapshot service;
5. development canonical export + fixture tests;
6. current-version serialize/load round trip;
7. Hush semantic reconstruction integration;
8. migration registry/pipeline + historical fixtures;
9. generation/integrity/recovery storage adapter;
10. manual/autosave/coalescing/retry integration;
11. Save / World-State IDE alongside every slice;
12. packaged/Shipping exclusion and platform verification.

Do not let implementation reorder semantic ownership for convenience.

---

# 13. Still-unverified evidence

Design closure does **not** prove:
- UE 5.8 compilation of save implementation;
- Editor/package load behavior;
- actual platform save-location/transaction semantics;
- disk-space/certification constraints;
- async performance/hitch behavior;
- real World Partition/Data Layer materialization;
- actual LKG/crash recovery on target platforms;
- Shipping exclusion in a packaged build;
- full-playthrough save/load fixture execution;
- human UX acceptance of save/recovery/menu behavior.

These become implementation/verification obligations. No documentation may claim them passed before evidence exists.

---

# 14. Hard implementation failures

Reject implementation that:
- keys saves by Actor/node/path/runtime instance;
- makes every Actor its own persistence database;
- lets Save Coordinator own gameplay truth;
- serializes transient combat/camera/Hush process state;
- persists the same fact under competing owners;
- guesses unknown/newer/corrupt data into defaults;
- overwrites the only verified save generation before candidate proof;
- implements death as arbitrary latest-disk reload;
- allows duplicate one-shot rewards after retry/load;
- stores Hush representation rather than semantic facts;
- hides migration/tombstone logic only in opaque assets;
- exposes Save IDE/fault mutation in Shipping;
- requires runtime AI/model/API services.

---

# 15. Decision #8 approval

**APPROVED / LOCKED under the owner's scheduled-run delegation.**

Issue #4 Save / World-State design is cumulatively reconciled and may close as a **design issue**.

### Final locked statement

> **Stillring saves a versioned snapshot of semantic game truth: stable identities, one owner per durable fact, explicit migrations, preserved recovery generations, authored retry checkpoints, and reconstructable world presentation.**
