# 85 — Persistent World-State / Save Decision #5 — Integrity, Containment, and Recovery

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #4 — Define persistent world-state and save schema  
**Decision:** #5 — corruption detection, last-known-good preservation, recovery boundaries, and player/developer communication

## Decision question

How does Stillring detect, contain, recover from, and explain malformed/corrupt/incompatible saves without destroying the player's last known good state or inventing progression?

## Locked philosophy

> **A bad save may cost convenience. It must not be allowed to erase the last verified truth.**

Recovery prioritizes preservation and semantic honesty over aggressive automatic repair. Stillring may fall back to a previously verified snapshot; it may not fabricate quest/world/inventory/completion facts merely to make a damaged file load.

## Research basis

Fresh Unreal Engine 5.8 research confirms:
- Unreal supports multiple save files/slots and project-defined `USaveGame` data;
- `AsyncSaveGameToSlot` reports completion success/failure and is recommended for active-play saves to reduce hitches;
- binary save data can be serialized to memory before disk I/O;
- platform-specific save locations/behavior vary, so Stillring's semantic integrity/recovery contract must sit above the storage implementation;
- some platforms may not support concurrent save/load operations, reinforcing the need for one coordinated save pipeline rather than overlapping arbitrary calls.

Primary references:
- Epic UE5.8 — Saving and Loading Your Game: https://dev.epicgames.com/documentation/unreal-engine/saving-and-loading-your-game-in-unreal-engine
- Epic UE5.8 — `UGameplayStatics::AsyncSaveGameToSlot`: https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Engine/UGameplayStatics/AsyncSaveGameToSlot
- Epic UE5.8 — `UAsyncActionHandleSaveGame::AsyncSaveGameToSlot`: https://dev.epicgames.com/documentation/unreal-engine/API/Runtime/Engine/UAsyncActionHandleSaveGame/AsyncSaveGameToSlot

Project authority reconciled:
- `docs/81_SAVE_PERSISTENT_IDENTITY_ADDENDUM.md`
- `docs/82_SAVE_STATE_TAXONOMY_OWNERSHIP_ADDENDUM.md`
- `docs/83_SAVE_SCHEMA_V1_STRUCTURE_ADDENDUM.md`
- `docs/84_SAVE_VERSION_MIGRATION_POLICY_ADDENDUM.md`
- `docs/75_GATE4_HUSH_SAVE_RELOAD_ADDENDUM.md`

## 1. Failure classes are explicit

The loader must classify failures instead of collapsing everything into `LoadFailed`.

Required semantic classes:

### `StorageMissing`
No save exists for the requested generation/slot.

### `StorageReadFailure`
The platform/storage layer could not read bytes reliably.

### `EnvelopeMalformed`
Required header/section framing cannot be decoded or required fields are structurally invalid.

### `IntegrityMismatch`
Stored integrity metadata/checksum does not match the bytes/semantic payload it protects.

### `SaveFromNewerVersion`
Decision #4 forward-version protection.

### `UnsupportedHistoricalVersion`
The source version is older but no supported migration chain exists.

### `MigrationFailure`
A known source version cannot deterministically migrate to current.

### `UnknownPersistentId`
A current/supported semantic record references an ID with no current owner or migration/tombstone disposition.

### `UnknownRecordKindOrVersion`
Known schema contains data the loader does not understand under its declared compatibility contract.

### `SemanticInvariantFailure`
Data parses/migrates, but canonical truth is contradictory or impossible: duplicate ownership, invalid quest/world combination, impossible inventory/world transaction result, Hush mismatch, etc.

### `RepresentationReconstructionFailure`
Semantic state is valid, but current content/runtime cannot materialize a safe playable representation/checkpoint.

These classes drive recovery and diagnostics differently.

## 2. Integrity metadata

Each persisted generation must carry enough metadata to detect accidental/truncated/corrupted writes before gameplay reconstruction.

At minimum, the storage envelope includes:
- schema/header identity;
- snapshot/playthrough IDs;
- payload length where useful;
- a deterministic integrity digest/checksum over the canonical serialized payload/envelope as implemented by the platform/runtime layer;
- completed-write marker/generation metadata where the chosen storage backend supports it.

The digest is corruption detection, **not anti-cheat/security authentication**. Cryptographic signing/encryption is out of scope unless platform requirements later demand it.

A checksum match does not prove semantic validity; invariant validation still runs.

## 3. Generational preservation model

A logical playthrough slot does not rely on one mutable file as its only durable copy.

The storage adapter preserves at least:
- **Current candidate** — newest completed generation intended to become primary;
- **Last Known Good (LKG)** — most recent generation that previously passed full load/migration/semantic validation;
- optional older rotating recovery generation(s) if storage budget/platform policy permits.

Exact user-visible slot count/cadence is Decision #6. This decision locks the preservation principle.

A new save must not destroy the only verified LKG before the new generation has completed its write and passed the required post-write validation policy.

## 4. Transactional save publication

Conceptual save pipeline:

1. reach save-stable semantic barrier;
2. construct immutable canonical snapshot;
3. validate snapshot before serialization;
4. serialize to memory/candidate representation;
5. compute integrity metadata;
6. write a **new candidate generation** through the platform adapter;
7. receive explicit storage success/failure;
8. when feasible, read/validate candidate metadata/bytes or otherwise verify platform completion contract;
9. mark candidate as newest valid generation;
10. retain previous verified LKG according to retention policy;
11. only later rotate/prune older generations.

Never implement semantic safety as “overwrite the current file first, then hope.”

The platform-specific mechanism may use temporary files + replace/rename where supported, platform save-slot APIs, or another transactional abstraction. Stillring's higher-level invariant is generation preservation, not dependence on one filesystem primitive.

## 5. Interrupted/crashed write behavior

If the process/platform dies during a save:
- any incomplete/unpublished candidate is ignored/quarantined on next boot/load;
- the previous LKG remains eligible;
- a partially written candidate never outranks a complete verified older generation merely because its timestamp is newer;
- snapshot IDs/generation metadata allow tooling to identify which write was interrupted.

If platform APIs guarantee their own atomic transaction, Stillring may leverage that guarantee but still maintains semantic generation/integrity validation above it.

## 6. Load selection order

For a logical playthrough:
1. inspect available generations newest-first;
2. validate storage envelope/integrity;
3. check version compatibility;
4. migrate in memory if required;
5. validate canonical semantic invariants;
6. validate checkpoint/representation reconstruction enough to establish loadability;
7. select the newest generation that passes all required gates;
8. if newest fails and an older verified generation succeeds, recover from the older generation and surface that recovery occurred.

The failed newest generation is preserved/quarantined for diagnostics unless platform/storage pressure or explicit player action requires removal.

## 7. No speculative semantic repair

Automatic recovery may safely do things whose correct meaning is deterministic, including:
- apply approved schema migrations;
- resolve explicit persistent-ID aliases/tombstones;
- recompute derived completion percentages from canonical entries;
- reconstruct Hush/representation state from semantic truth;
- use authored checkpoint-safe fallback when raw saved transform is invalid but semantic checkpoint is valid.

Automatic recovery may **not** guess:
- which quest branch the player “probably” chose;
- whether an unknown pickup should count as collected;
- whether a boss should be alive or dead;
- which layer-local fact was intended when data conflicts;
- missing inventory rewards from ambiguous world facts;
- an arbitrary nearby checkpoint because coordinates look plausible;
- unknown/newer fields as harmless defaults.

If preserving meaning requires guessing, fail that generation and try LKG.

## 8. Quarantine

A failing generation receives a diagnostic quarantine record containing, where available:
- playthrough/snapshot/generation ID;
- failure class;
- source schema/content revision;
- failing section/record/persistent ID;
- integrity result;
- migration plan/result;
- semantic invariant failures;
- timestamp/build metadata;
- canonical forensic export only when parsing safely succeeded.

Quarantine state is developer/support metadata, not canonical playthrough truth.

Retail builds need not expose raw files or technical internals, but must avoid silently deleting the failed generation before recovery/support options are exhausted.

## 9. Player-facing behavior

### Healthy load
No special message.

### Newest generation failed; LKG recovered
Load the verified older generation and clearly but calmly tell the player that the newest save could not be used and the previous safe save was restored. Show human-readable timestamp/playtime difference if available.

Do **not** say the save was “fixed” if Stillring actually rolled back.

### No usable generation
Do not start a fake partially reconstructed playthrough. Present a clear recovery state with options appropriate to platform/product capabilities, such as retry/rescan, return to title, inspect available older recovery point, or start a new game only through explicit player choice.

### Save from newer game version
Explain that the save was created by a newer version and requires that version or later. Do not call it corrupt.

### Storage failure while saving
Gameplay may continue when safe, but the UI must communicate that the save did not complete. Never show a successful-save indicator before the storage completion callback/contract confirms success.

Final wording/localization is UX production work, but semantic distinctions are locked.

## 10. Accessibility of recovery UI

Recovery UI must:
- be fully controller/keyboard navigable and remappable where relevant;
- work with screen-reader/accessibility text infrastructure if adopted;
- never rely on color alone to distinguish safe/failed saves;
- use plain-language status plus technical detail only in an expandable diagnostics/support view;
- avoid countdown/auto-select pressure for destructive actions;
- require explicit confirmation before deleting/quarantined/older generations when deletion is user-facing;
- preserve subtitle/text-size/contrast settings because profile/settings persistence is separate from the failed playthrough.

## 11. Save indicator truthfulness

A save icon/message has three semantic phases:
- `Saving` — snapshot captured/write underway;
- `Saved` — platform write completion + required publication checks succeeded;
- `SaveFailed` — candidate did not publish successfully.

Snapshot capture alone is not “Saved.”

If a later post-write verification fails, the generation is not promoted to valid current/LKG.

## 12. Autosave/backup relationship boundary

This decision does not pick final autosave frequency or number of visible slots, but locks:
- autosaves obey identical semantic integrity/version rules as manual/checkpoint saves;
- an autosave may not destroy the last known good generation before its own success is established;
- manual and automatic saves for one playthrough share compatible schema/migration/integrity machinery;
- developer saves are explicitly marked and must not masquerade as retail recovery points.

Decision #6 owns cadence, trigger policy, user-visible slot model, and retention counts.

## 13. Hush-specific recovery

Gate 4 remains authoritative.

For a valid semantic save whose raw transform is no longer legal after content migration:
- reconstruct the saved committed semantic layer;
- use the authored checkpoint/occupancy recovery contract;
- do not switch Waking/Hush just to make coordinates work;
- do not reconstruct in-flight seam state;
- do not search for a puzzle-winning location.

If Hush facts themselves violate current invariants and no explicit migration resolves them, fail the generation rather than choosing a layer/fact outcome by convenience.

## 14. Developer/System IDE recovery surface

The Save / World-State workbench must expose:

### Inspect
- all generations for a logical playthrough;
- candidate/LKG/quarantined status;
- snapshot IDs/timestamps/playtime;
- envelope/integrity result;
- schema/content revision;
- migration status;
- semantic validation result;
- selected recovery generation and reason.

### Exercise / fault injection
Development-only deterministic corruption tools may:
- truncate candidate bytes;
- alter integrity digest;
- remove required section;
- inject duplicate persistent ID;
- inject unknown ID/kind/version;
- create invalid Hush checkpoint/layer combination;
- simulate async/platform save failure;
- simulate crash before candidate publication.

Fault injection is never included/enabled in Shipping.

### Capture
Export a recovery report containing generation metadata, failure class, migration trace, canonical semantic diff/forensic export when safe, and selected fallback. Never require video archaeology to diagnose a save regression.

## 15. Verification fixtures

### S5-F01 — clean newest
Newest generation validates and loads; older LKG remains untouched.

### S5-F02 — truncated newest
Newest candidate fails structural/integrity checks; prior LKG loads.

### S5-F03 — bad digest
Integrity mismatch quarantines newest; prior LKG loads.

### S5-F04 — semantically contradictory newest
Bytes parse but duplicate/contradictory ownership fails invariants; LKG loads.

### S5-F05 — newer-version save
Returns `SaveFromNewerVersion`; does not label corrupt, mutate, or downgrade it.

### S5-F06 — interrupted write
Simulated interruption leaves incomplete candidate unpublished; LKG remains selectable.

### S5-F07 — save callback failure
UI reports SaveFailed; prior valid generation remains primary.

### S5-F08 — deterministic migration then valid load
Old released save migrates successfully in memory and loads without overwriting source.

### S5-F09 — migration ambiguity
Migration cannot deterministically map old fact; generation fails/quarantines, LKG chosen.

### S5-F10 — invalid transform, valid checkpoint
Semantic state valid; authored checkpoint recovery resolves placement without changing world facts/layer.

### S5-F11 — Hush semantic corruption
Invalid paired/layer facts cannot be honestly repaired; generation rejected rather than silently flipping layer/state.

### S5-F12 — no good generations
All generations fail; game presents recovery state and never constructs partial gameplay.

### S5-F13 — truthful save indicator
`Saved` occurs only after successful publication; failure never leaves false success UI.

### S5-F14 — source preservation
Failed/quarantined newest and prior LKG remain byte-identifiable/available through test completion.

## 16. Acceptance hard failures

Any of these blocks save-system acceptance:
- overwrite-only persistence with no LKG preservation strategy;
- failed newest generation causes automatic new-game/reset without explicit player choice;
- corruption recovery invents progression/world facts;
- newer-version save is loaded/downgraded best-effort;
- save-success UI fires before write success;
- corrupt candidate becomes primary solely because it is newest;
- profile/accessibility settings become inaccessible because one playthrough save is damaged;
- quarantined save is silently destroyed before diagnostic/recovery policy allows it.

## 17. IP boundary

This is an original recovery/integrity contract built from generic robust persistence principles and public Unreal save APIs. It does not reproduce proprietary Nintendo/Zelda backup rotation, byte layouts, recovery screens, or reverse-engineered platform behavior.

## 18. Rejected alternatives

### One file, overwrite in place
Rejected as the project-level semantic durability strategy.

### “Parse what we can” recovery
Rejected: turns corruption into silent progression mutation.

### Reset unknown values to defaults
Rejected unless an explicit version migration proves defaulting preserves meaning.

### Auto-delete failed save after rollback
Rejected: destroys evidence and possible future recovery/support path.

### Treat every failure as corrupt
Rejected: newer-version, storage-read, migration, and semantic failures require distinct behavior.

## 19. Approval

**APPROVED / LOCKED under the owner's scheduled-run delegation.**

Issue #4 Decision #5 is complete.

### Locked statement

> **Stillring publishes new save generations without sacrificing the last verified one. When a generation cannot be understood honestly, it is contained—not guessed into existence.**

## Next decision

Issue #4 Decision #6:

> **When and where does Stillring save: slot model, manual/checkpoint/autosave triggers, retention cadence, and death/retry interaction?**
