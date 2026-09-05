# Stillring — Next Chat Handoff

**Updated:** 2026-09-05  
**Repository:** `raiinman/Stillring`  
**Status:** Gate 1 locomotion/camera, Gate 2 combat/encounter, Gate 3 Tool-Puzzle, and Gate 4 Waking/Hush design are COMPLETE / LOCKED. Gate 4 playable Unreal implementation/human acceptance remain UNVERIFIED. Issue #4 persistent world-state/save design is active; Decisions #1–#2 are LOCKED under scheduled-run delegation.

## Read first
1. `docs/81_SAVE_PERSISTENT_IDENTITY_ADDENDUM.md`
2. `docs/82_SAVE_STATE_TAXONOMY_OWNERSHIP_ADDENDUM.md`
3. `docs/75_GATE4_HUSH_SAVE_RELOAD_ADDENDUM.md`
4. `docs/79_GATE4_HUSH_CUMULATIVE_SPECIFICATION.md`
5. `docs/10_COMPLETION_MODEL.md`
6. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
7. `ROADMAP.md`
8. GitHub Issue #4 — `Define persistent world-state and save schema`

Always re-check exact current `main` before repository writes.

## Required method
Fresh focused research for exactly one decision → reconcile locked authority/IP/accessibility/failure cases/System IDE/tests → coherent package → scheduled-run approval only when complete → document → inspect exact diff → merge with expected head → only then next decision.

**Work for as long as productively possible in every scheduled wake. Never batch unresolved decisions.**

## Issue #4 save/world-state decisions
### #1 — stable persistent identity — LOCKED
Authority: `docs/81`.

> **Save identity belongs to the authored game meaning, not to the current Unreal object instance.**

Project-owned semantic GUIDs are canonical. Runtime/path/package/Data-Layer/Actor identities are not save keys.

### #2 — persistent state taxonomy and ownership — LOCKED
Authority: `docs/82`.

> **Each durable fact has one gameplay owner; the save system snapshots those owners. Runtime presentation is rebuilt, not promoted into truth.**

Locked categories include save metadata, player progression, inventory/tools, quest/story, world facts, Hush semantic state, encounter outcomes, shortcuts/interactables, completion, catastrophe/world pivots, NPC recurrence, and checkpoint/location. Settings/profile data are separate. Movement/camera/combat/AI/tool/Hush/UI process state is transient/derived unless later explicitly promoted.

### #3 — Save Schema v1 top-level structure and record shape — NEXT
Freshly research and decide:
- exact v1 top-level semantic sections;
- typed record/envelope structure;
- GUID/category/owner representation;
- sparse/default omission policy;
- deterministic ordering/canonicalization;
- unknown-field/unknown-record forward compatibility posture;
- snapshot metadata needed before migration policy;
- no raw UObject/Actor graph serialization;
- example serialized v1 fixture;
- System IDE schema inspection/validation;
- deterministic round-trip fixtures.

Do not decide migration policy until Decision #3 is individually closed.

## Governing constraints
- Unreal Engine 5.8.
- C++ first for gameplay/state authority; thin Blueprint presentation.
- System IDE remains first-class production infrastructure.
- No retail runtime AI/model/API dependency.
- Human play is final authority for feel/readability.
- Clean-room IP rules apply.
- Engine representation never outranks Stillring semantic authority.

Movement: **Simple intention, capable character, honest world.**  
Camera: **The player should look at Orra, not babysit the camera.**  
Tools: **Cantor explains the relationship. Anchor changes the load.**  
Hush: **One place. One history of facts. Two authored expressions.**  
Save/world-state: **Persist meaning, reconstruct presentation.**  
System IDE: **Build the system and its in-game IDE together.**
