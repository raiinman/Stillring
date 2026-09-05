# Stillring — Next Chat Handoff

**Updated:** 2026-09-05  
**Repository:** `raiinman/Stillring`  
**Status:** Gate 1 locomotion/camera, Gate 2 combat/encounter, Gate 3 Tool-Puzzle, and Gate 4 Waking/Hush design are COMPLETE / LOCKED. Gate 4 playable Unreal implementation/human acceptance remain UNVERIFIED. Issue #4 persistent world-state/save design is active; Decisions #1–#3 are LOCKED under scheduled-run delegation.

## Read first
1. `docs/81_SAVE_PERSISTENT_IDENTITY_ADDENDUM.md`
2. `docs/82_SAVE_STATE_TAXONOMY_OWNERSHIP_ADDENDUM.md`
3. `docs/83_SAVE_SCHEMA_V1_STRUCTURE_ADDENDUM.md`
4. `docs/75_GATE4_HUSH_SAVE_RELOAD_ADDENDUM.md`
5. `docs/10_COMPLETION_MODEL.md`
6. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
7. `ROADMAP.md`
8. GitHub Issue #4 — `Define persistent world-state and save schema`

Always re-check exact current `main` before repository writes.

## Required method
Fresh focused research for exactly one decision → reconcile locked authority/IP/accessibility/failure cases/System IDE/tests → coherent package → scheduled-run approval only when complete → document → inspect exact diff → merge with expected head → only then next decision.

**Work for as long as productively possible in every scheduled wake. Never batch unresolved decisions.**

## Issue #4 save/world-state decisions
### #1 — stable persistent identity — LOCKED (`docs/81`)
> **Save identity belongs to the authored game meaning, not to the current Unreal object instance.**

### #2 — persistent state taxonomy and ownership — LOCKED (`docs/82`)
> **Each durable fact has one gameplay owner; the save system snapshots those owners. Runtime presentation is rebuilt, not promoted into truth.**

### #3 — Save Schema v1 structure — LOCKED (`docs/83`)
> **Save v1 is an explicit, versioned, typed semantic aggregate with deterministic ordering and stable IDs. Unreal serializes it; Unreal does not define its meaning.**

Schema v1 has explicit semantic sections, section/record versions, stable record kinds independent of UObject paths, typed payloads, sparse/default rules, deterministic canonical ordering, a development-only human-readable canonical export, and a concrete v1 fixture.

### #4 — versioning and migration policy — NEXT
Freshly research and decide:
- compatibility contract from schema v1 onward;
- global/section/record version responsibilities;
- ordered migration pipeline and idempotence;
- old persistent-ID rename/retirement/tombstone mapping;
- content removed/replaced/split/merged semantics;
- forward-version/newer-save handling;
- migration validation and golden fixtures;
- rollback/backward-write expectations;
- build/content revision relationship to schema version;
- Hush representation refactor guarantees;
- System IDE migration preview/audit surface.

Do not decide malformed/corrupt-save player recovery UX until Decision #4 is individually closed.

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
