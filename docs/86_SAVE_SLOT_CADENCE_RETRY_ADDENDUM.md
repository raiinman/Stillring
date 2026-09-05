# 86 — Persistent World-State / Save Decision #6 — Slot, Cadence, and Retry Policy

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #4 — Define persistent world-state and save schema  
**Decision:** #6 — logical playthrough slots, manual/checkpoint/autosave triggers, generation retention, and death/retry interaction

## Decision question

When does Stillring create durable saves, what does the player see as a save slot, how are internal generations retained, and what exactly does death/retry restore?

## Locked philosophy

> **Saving protects the journey; retry restores the encounter. Neither should make the player babysit file management.**

Stillring uses reliable automatic persistence plus an explicit manual-save option at safe semantic boundaries. Internal recovery generations remain an implementation/recovery detail rather than cluttering the ordinary load menu.

## Research basis

Fresh Unreal Engine 5.8 research confirms:
- SaveGame slots are project-selected logical names/user IDs; Unreal does not impose Stillring's playthrough model.
- `AsyncSaveGameToSlot` is the preferred active-play write path and reports completion success/failure.
- Async save serialization happens on the game thread and platform writing occurs on a worker thread; overlapping load/save may not be supported on every platform, so Stillring requires a coordinated queue.

Primary references:
- Epic UE5.8 — Saving and Loading Your Game: https://dev.epicgames.com/documentation/unreal-engine/saving-and-loading-your-game-in-unreal-engine
- Epic UE5.8 — `UGameplayStatics::AsyncSaveGameToSlot`: https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Engine/UGameplayStatics/AsyncSaveGameToSlot
- Epic UE5.8 — `UAsyncActionHandleSaveGame::AsyncSaveGameToSlot`: https://dev.epicgames.com/documentation/unreal-engine/API/Runtime/Engine/UAsyncActionHandleSaveGame/AsyncSaveGameToSlot

Project authority reconciled:
- `docs/47_GATE2_COMBAT_DEATH_RETRY_ADDENDUM.md`
- `docs/75_GATE4_HUSH_SAVE_RELOAD_ADDENDUM.md`
- `docs/81`–`docs/85`

## 1. Player-facing playthrough model

A **Playthrough Slot** is one independent canonical journey identified by `PlaythroughId`.

The player may maintain multiple playthroughs. Exact maximum visible slot count is a product/platform storage tuning value, not core gameplay policy, but the architecture must support more than one playthrough without filename hacks or shared mutable world state.

Each player-facing playthrough shows only useful human information:
- playtime;
- current semantic region/checkpoint;
- major story phase where spoiler-safe;
- completion summary where appropriate;
- last successful save timestamp;
- recovery warning only if the newest generation failed and LKG was used.

Internal candidate/LKG/backup generations are not presented as five separate “save files” during ordinary healthy use.

## 2. Internal generations per playthrough

Each logical playthrough maintains:
- current published generation;
- verified Last Known Good generation;
- at least one additional rotating recovery generation when platform storage permits.

Recommended production target: **current + LKG + one older recovery generation** per logical playthrough, subject to platform certification/storage proof.

This is a resilience target, not three player-visible manual slots.

Developer/test configurations may retain more generations for diagnostics.

## 3. Manual save availability

Manual save is available from the pause/system menu during ordinary controllable gameplay whenever the Save Coordinator can reach a reviewed save-stable semantic boundary promptly.

Manual save is not restricted to physical “save points.” Stillring is an authored adventure, not a file-management punishment.

A manual request may be **deferred** briefly rather than rejected when the game is inside a transient unsafe boundary such as:
- Hush seam preparing/committed but not save-stable;
- atomic pickup/boss/quest/world transaction still settling;
- mantle/ledge/ladder/traversal state whose current transform is not a valid reload state;
- cinematic/scripted state with incomplete persistent transaction;
- active loading/map transition;
- save/load operation already owning the storage pipeline.

The UI reports `Save Pending`/equivalent until a stable boundary is reached. If the request cannot become safe within the containing activity, explain why rather than silently dropping it.

## 4. Combat and manual saving

Manual durable saving is **deferred during active hostile combat**.

Reasons:
- Gate 2 deliberately treats attack/AI/targeting state as transient;
- loading into a half-resolved attack is forbidden;
- save-scumming individual attack frames would pressure the schema toward persisting combat simulation it intentionally excludes.

The request may remain pending and commit when combat exits to a safe stable state.

This does not prevent autosaves immediately after meaningful encounter resolution once the outcome transaction has settled.

## 5. Autosave philosophy

Autosaves occur on **meaningful durable progress**, not every few seconds and not only at long chapter boundaries.

Primary trigger families:

### Checkpoint / area transition
- authored checkpoint activation;
- safe entry into a major region/dungeon segment;
- major travel transition after destination state is stable.

### Durable progression
- acquisition of a major tool/capability;
- meaningful upgrade/permanent progression change;
- critical inventory transaction whose loss would feel unfair.

### Quest/world progression
- major objective/quest stage commit;
- contract resolution;
- significant persistent world repair/shortcut;
- catastrophe/world-pivot transaction;
- major Hush cross-layer causal resolution.

### Encounter resolution
- boss/unique encounter resolved and its reward/world consequences settled;
- optional elite completion where completion-bearing.

### Completion milestones
- significant collectible/completion item where replay cost is non-trivial;
- refuge/major optional authored resolution.

Do not autosave merely because:
- a camera changed;
- an enemy noticed the player;
- a UI page opened;
- a small transient movement state changed;
- a Hush seam animation began before semantic save stability.

## 6. Autosave coalescing / anti-spam

Multiple save triggers occurring inside one short semantic transaction window coalesce into one pending save request.

Example:
Boss death -> world consequence -> quest stage -> reward -> completion entry should produce one coherent post-transaction snapshot, not five overlapping disk writes.

Rules:
- never run competing writes for the same playthrough;
- if a save is in flight and newer durable progress occurs, mark the playthrough dirty and schedule one follow-up snapshot after completion/stability;
- never discard the later semantic mutation just because an older snapshot is currently writing;
- exact debounce seconds are implementation tuning; semantic coalescing is the authority.

## 7. Autosave visibility

Autosaves use the truthful phases from Decision #5:
- Saving;
- Saved;
- SaveFailed.

The indicator is subtle but readable and does not require the player to watch it.

The game should avoid a permanent noisy save icon every time a trivial fact changes. Coalescing and meaningful triggers keep feedback useful.

## 8. Manual save does not create a branching quick-save history

Saving manually updates the current logical playthrough through the same generational publication pipeline.

Stillring does **not** expose unrestricted named quick-save branches inside one playthrough as a core design feature.

Why:
- authored choices/world recurrence should remain part of a journey rather than a save-tree management mini-game;
- internal generations already provide resilience;
- multiple distinct playthrough slots provide legitimate branch/replay space;
- implementation/test complexity remains bounded.

Developer builds may expose arbitrary fixture slots separately.

## 9. Death/retry semantic checkpoint

Combat authority says retry restores a valid world, not a half-dead combat frame.

Stillring therefore maintains a **Retry Checkpoint Snapshot** distinct from the most recent durable disk generation.

A retry snapshot is an in-memory/semantic checkpoint state constructed at the last authored retry boundary. It defines exactly what the death loop restores for the current encounter/segment.

It may be refreshed when:
- an authored checkpoint is activated;
- an encounter boundary intentionally begins;
- a boss phase checkpoint is explicitly designed and approved;
- another system requests a reviewed retry boundary.

It is not continuously updated every frame.

## 10. What retry restores

Retry uses the checkpoint/world/encounter contract, not an arbitrary disk rewind.

By default, a retry snapshot restores:
- player position to authored checkpoint/retry spawn;
- player alive/neutral locomotion/combat baseline;
- health/resources according to checkpoint/encounter policy;
- encounter actors/state according to authored retry semantics;
- transient combat/projectile/AI action state freshly reconstructed;
- active semantic Hush/Waking state only as defined by the checkpoint snapshot and durable facts.

Durable progress already committed **before** the retry boundary remains durable unless a later system explicitly defines a reversible transaction.

Durable progress committed **inside** an encounter after the retry snapshot must follow the owning system's authored retry semantics; one-shot durable rewards/facts may not duplicate on repeated deaths.

## 11. Death is not an autosave trigger by itself

Death does **not** immediately write a new durable disk save merely because the player died.

That avoids:
- persisting a dead transient state;
- rotating out a better LKG with a death-only snapshot;
- coupling combat failure to disk I/O;
- accidental reward/world-state duplication around fatal frames.

After retry reconstructs a stable checkpoint state, a durable save may occur only if a normal save trigger/policy requires it.

## 12. Quit-to-title / application exit

When the player explicitly chooses Quit to Title / Exit Game from a state where saving is allowed:
- if there are dirty durable facts newer than the last successful save, request a save and clearly show completion/failure before final exit where platform UX permits;
- if currently in an unsafe boundary, the game may wait/defer to the nearest safe boundary only if the interaction can complete promptly and honestly;
- if safe saving cannot be completed, warn that unsaved progress exists rather than claiming success.

Do not silently synthesize a save from unsafe transient state just because the player is exiting.

Platform forced termination cannot be guaranteed; meaningful autosaves limit exposure.

## 13. New game / overwrite / delete

### New game
Creates a fresh `PlaythroughId` in a free/new logical slot and canonical default state.

### Overwrite/restart an existing playthrough
Destructive. Requires explicit confirmation showing which playthrough will be replaced.

### Delete playthrough
Destructive. Requires explicit confirmation. Delete encompasses its internal generations after platform/storage operation succeeds.

No timed confirmation or color-only warning.

If slots are not at capacity, starting a new game must not silently overwrite the oldest playthrough.

## 14. Developer slots

Development/test saves are separate from retail playthrough slots.

Requirements:
- clearly marked `Developer` save reason/profile;
- may retain extra generations/debug metadata;
- named semantic presets remain preferred for reproducible states;
- test save cannot appear as a normal player recovery candidate;
- retail Shipping build excludes developer-only mutation/fault-injection surfaces.

## 15. Hush seam/save interaction

`docs/75` remains authoritative:
- save requested during seam Requested/Preparing waits;
- post-semantic-commit but pre-save-stable state waits;
- only settled committed layer + coherent facts are snapshotted;
- load never resumes an in-flight seam presentation.

A seam itself is not automatically a save trigger merely because the player toggled layers. Autosave occurs when the seam accompanies a meaningful durable fact/checkpoint or other trigger.

## 16. Traversal/save interaction

Manual/autosave request while Neris is in a non-reload-safe traversal microstate is deferred to a stable landing/hang/checkpoint boundary rather than serializing animation/traversal process state.

A real stable hang may eventually qualify if implementation/human testing proves deterministic reload safety, but v1 should prefer authored ground/checkpoint states rather than expanding save complexity prematurely.

## 17. Retention and LKG rotation

Internal generation rotation follows Decision #5:
1. new candidate publishes successfully;
2. candidate passes required validity checks;
3. prior current becomes LKG/recovery generation;
4. previous older recovery may rotate/prune only after the new chain is healthy.

A generation known to be corrupt is quarantined and does not count as the sole LKG.

Exact disk-space pruning thresholds remain platform implementation tuning but may never prune all verified recovery generations before a replacement is valid.

## 18. Save Coordinator request priorities

When multiple requests exist:
1. explicit player manual/quit save has highest service urgency once safe;
2. critical progression/checkpoint autosave;
3. ordinary meaningful autosave;
4. developer diagnostic save.

Priority changes timing, not snapshot meaning. Requests coalesce around the newest stable durable state where doing so does not lie about a manual save the player specifically requested earlier.

## 19. System IDE / Save workbench

### Inspect
- logical playthrough ID;
- last successful durable generation;
- LKG/older recovery generation;
- current dirty domains;
- queued/coalesced save reasons;
- save-stable barrier blockers;
- in-flight snapshot ID;
- Retry Checkpoint Snapshot ID/source;
- last save success/failure;
- Hush/combat/traversal defer reason.

### Exercise
- request manual save during free exploration/combat/Hush seam/traversal;
- trigger several durable events in one transaction and prove coalescing;
- simulate progress arriving during in-flight save;
- force death before/after durable progress and compare retry vs disk load;
- rotate generations and prove LKG preservation;
- simulate quit with dirty state/save failure;
- create/delete developer versus retail playthrough slots.

### Validate
Hard fail on:
- overlapping writes to same playthrough;
- death frame serialized as durable canonical state;
- retry implemented as arbitrary latest-disk reload without checkpoint authority;
- autosave trigger before transaction settles;
- save requested in unsafe state marked `Saved` before actual publication;
- developer save selected as retail LKG;
- new game silently overwrites a different playthrough.

## 20. Deterministic fixtures

### S6-F01 — manual exploration save
Manual request from safe exploration captures current stable semantic state.

### S6-F02 — manual combat defer
Request during active combat remains pending; commits once combat resolves/exits safely.

### S6-F03 — Hush seam defer
Request mid-seam captures neither half-state; commits only at save-stable boundary.

### S6-F04 — trigger coalescing
Boss+quest+reward+completion triggers produce one coherent save.

### S6-F05 — dirty-during-write
New durable mutation while save is in flight schedules one subsequent save; mutation is not lost.

### S6-F06 — death retry vs disk
Death restores retry snapshot, not arbitrary latest durable disk generation.

### S6-F07 — no death save
Fatal frame itself causes no disk generation.

### S6-F08 — one-shot reward across retries
Durable reward/fact cannot duplicate after repeated death/retry.

### S6-F09 — generation rotation
Current/LKG/older generation rotate only after candidate validity.

### S6-F10 — new game isolation
Two playthrough IDs never share world/inventory/quest state.

### S6-F11 — explicit destructive action
Overwrite/delete requires confirmation and affects only selected playthrough.

### S6-F12 — developer isolation
Developer save/preset never appears as a retail recovery generation.

### S6-F13 — quit dirty state
Quit with dirty stable state saves; forced failure produces honest unsaved-progress warning.

### S6-F14 — accessibility
All slot/delete/recovery/save-status UI remains usable without color-only cues, timed input, or rapid presses.

## 21. IP boundary

This is an original save-cadence/retry contract informed by general adventure-game usability goals and public Unreal save APIs. It does not reproduce another game's exact slot count, autosave timing, checkpoint layout, UI, or proprietary retry behavior.

## 22. Rejected alternatives

### Physical save points only
Rejected: unnecessary friction for a long modern authored adventure.

### Save literally anywhere including active combat frame
Rejected: conflicts with the semantic snapshot model and transient combat authority.

### Autosave every fixed N seconds regardless of state
Rejected: noisy I/O, poor semantics, and increased chance of snapshots at meaningless/unsafe boundaries.

### Death = load most recent disk save
Rejected: combat already delegates retry to explicit checkpoint/world authority, and disk cadence is not encounter design.

### One exposed save slot only
Rejected: prevents clean replay/branching/new-game separation and increases overwrite risk.

### Unlimited quick-save tree as core UX
Rejected: turns authored world consequences into save-management overhead and materially expands UI/testing/migration burden.

## 23. Approval

**APPROVED / LOCKED under the owner's scheduled-run delegation.**

Issue #4 Decision #6 is complete.

### Locked statement

> **Stillring autosaves meaningful durable progress, lets the player manually save at safe boundaries, and keeps death/retry on an authored checkpoint snapshot instead of pretending the disk file is a combat rewind.**

## Next decision

Issue #4 Decision #7:

> **What is the complete Save / World-State System IDE authoring, inspection, validation, preset, capture, and Shipping-exclusion contract?**
