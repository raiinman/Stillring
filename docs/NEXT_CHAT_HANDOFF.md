# Stillring — Next Chat Handoff

**Updated:** 2026-09-05  
**Repository:** `raiinman/Stillring`  
**Status:** Gate 1 locomotion/camera design COMPLETE / LOCKED. Gate 2 player combat + enemy/encounter design COMPLETE / LOCKED. Gate 3 Cantor Key / Anchor Line Tool-Puzzle design COMPLETE / LOCKED. Gate 4 Waking/Hush design Decisions #1–#10 COMPLETE / LOCKED and merged. Gate 4 playable Unreal implementation and human acceptance remain UNVERIFIED / NOT YET EXECUTED. Issue #4 persistent world-state/save design is now active; Decision #1 stable persistent identity is LOCKED under scheduled-run delegation.

## Read first
1. `docs/81_SAVE_PERSISTENT_IDENTITY_ADDENDUM.md`
2. `docs/79_GATE4_HUSH_CUMULATIVE_SPECIFICATION.md`
3. `docs/75_GATE4_HUSH_SAVE_RELOAD_ADDENDUM.md`
4. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
5. `ROADMAP.md`
6. GitHub Issue #4 — `Define persistent world-state and save schema`

Always re-check exact current `main` before repository writes.

## Required method
Fresh focused research for exactly one decision → reconcile locked authority/IP/accessibility/failure cases/System IDE/tests → coherent package → scheduled-run approval only when complete → document → inspect exact diff → merge with expected head → only then next decision.

**Work for as long as productively possible in every scheduled wake. Never batch unresolved decisions.**

## Completed design systems
- Gate 1 locomotion/camera — COMPLETE / LOCKED.
- Gate 2 player combat + enemy/encounter — COMPLETE / LOCKED.
- Gate 3 Cantor Key / Anchor Line Tool-Puzzle — COMPLETE / LOCKED.
- Gate 4 Waking/Hush Decisions #1–#10 — COMPLETE / LOCKED. `docs/79` is cumulative authority.

## Issue #4 save/world-state decisions
### #1 — stable persistent identity — LOCKED
Authority: `docs/81_SAVE_PERSISTENT_IDENTITY_ADDENDUM.md`.

Locked principle:
> **Save identity belongs to the authored game meaning, not to the current Unreal object instance.**

Stillring uses project-owned semantic GUIDs. Names, object paths, package paths, runtime Actor instances, Actor labels, World Partition cells/Data Layers, OFPA filenames, transforms, array indices, and editor Actor GUIDs are not canonical save keys. Persistent IDs are authored once, preserved through representation refactors, never recycled, and validated for duplicate/missing/unknown/tombstoned use. Hush/Waking paired expressions share one semantic persistent ID where Gate 4 says they are one entity.

### #2 — state categories and ownership — NEXT
Freshly research and decide:
- player state;
- inventory/tool state;
- quest/objective state;
- world facts;
- boss/encounter persistence;
- shortcuts/interactables;
- collectibles/completion;
- catastrophe/region pivot state;
- Hush/Waking active semantic layer and paired facts;
- transient/derived state that must **not** be serialized;
- category ownership boundaries so two systems never write contradictory truth;
- reset/new-game/dev-preset implications;
- System IDE inspection/validation and deterministic fixtures.

Do not start schema layout/version/migration until Decision #2 is individually closed.

## Gate 4 implementation authorization boundary
Gate 4 design authorizes prototype work, but actual UE5.8 compile/editor/map/performance/save/Git-LFS/human-play evidence remains unproven. Do not fabricate it. Issue #4 must finish its save contract before implementation depends on full persistence semantics.

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
