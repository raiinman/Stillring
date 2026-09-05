# 80 — Gate 4 Hush Decision Register Extension

**Status:** living authority index extension  
**Updated:** 2026-09-05  
**Scope:** durable index for Gate 4 Waking/Hush design Decisions #1–#10. Detailed authority remains in `docs/70`–`docs/79`; this file does not supersede them.

## Gate 4 decision status

| Gate 4 decision | Status | Locked decision | Detailed authority |
|---|---|---|---|
| H4-D01 | LOCKED | Waking and Hush are two authored expressions of one semantic Orra, owned by one authoritative world-layer service. Stable semantic IDs, not Actor/Data Layer/package identity, own persistent paired meaning. | `docs/70_GATE4_HUSH_SEMANTIC_LAYER_IDENTITY_ADDENDUM.md` |
| H4-D02 | LOCKED | A seam request rejects before commitment or commits semantic reality exactly once. Presentation may continue after commit but is never a third gameplay reality; locomotion/camera remain under existing player authority. | `docs/71_GATE4_HUSH_SEAM_TRANSITION_ADDENDUM.md` |
| H4-D03 | LOCKED | Loaded, presented, and physically authoritative are separate. Only the active authored expression owns ordinary collision/gameplay queries; paired geometry hands authority over deterministically at semantic commit. | `docs/72_GATE4_HUSH_GEOMETRY_COLLISION_AUTHORITY_ADDENDUM.md` |
| H4-D04 | LOCKED | Cross-layer puzzles share authored semantic facts and causal relationships rather than arbitrary Actor state. Gate 3 tool rules remain unchanged; layer shifting is not a hidden puzzle key. | `docs/73_GATE4_HUSH_CROSS_LAYER_PUZZLE_STATE_ADDENDUM.md` |
| H4-D05 | LOCKED | Seam transitions change expression, not combat/NPC/interactable history. Health, death, aggro, committed player state and one-shot facts do not reset; target continuity follows semantic identity only. | `docs/74_GATE4_HUSH_COMBAT_NPC_INTERACTABLE_CONTINUITY_ADDENDUM.md` |
| H4-D06 | LOCKED | A Hush save records one settled semantic layer plus durable facts by stable semantic ID. Reload reconstructs semantic truth first and engine expressions second; the complete project save schema remains Issue #4 authority. | `docs/75_GATE4_HUSH_SAVE_RELOAD_ADDENDUM.md` |
| H4-D07 | LOCKED | Hush identity is world-space authored expression first, atmosphere/post-process second. Reduced Hush Effects preserves gameplay/readability; critical cues are not color-only and hazardous flashing/camera motion are avoided by design. | `docs/76_GATE4_HUSH_PRESENTATION_AUDIO_ACCESSIBILITY_ADDENDUM.md` |
| H4-D08 | LOCKED | The Hush / World-Layer System IDE must expose semantic truth and engine representation together, safely exercise/reset fixtures, validate divergence, capture evidence, and remain development-only. | `docs/77_GATE4_HUSH_WORLD_LAYER_IDE_ADDENDUM.md` |
| H4-D09 | LOCKED / PROVISIONAL IMPLEMENTATION DIRECTION | First prototype candidate is World Partition + Runtime Data Layers with spatial streaming disabled for the tiny test initially. Runtime Data Layers express rather than define semantic truth. Explicit non-WP level/Actor layering remains fallback until real evidence proves the architecture. | `docs/78_GATE4_HUSH_REPRESENTATION_COMPARISON_ADDENDUM.md` |
| H4-D10 | LOCKED | Gate 4 design is cumulatively closed with deterministic paired-layer fixtures, machine/human/performance/source-control evidence requirements, hard invariants, and an explicit line between approved design and unverified real-engine implementation. | `docs/79_GATE4_HUSH_CUMULATIVE_SPECIFICATION.md` |

## Gate 4 closure status

**Design:** COMPLETE / LOCKED.

**Implementation evidence:** PENDING.

Still required before the provisional representation may be called production-proven:
- real Unreal Engine 5.8 compile/editor/map execution;
- deterministic H4-F01–H4-F15 fixture evidence and H4-F16 if fallback criteria trigger;
- transition performance and memory measurements;
- save/reload runtime convergence;
- Git/Git-LFS / One File Per Actor authoring evidence;
- accessibility/photosensitivity/readability evidence;
- human play acceptance.

No documentation-only decision or engine documentation citation may be substituted for these tests.

## Important naming correction

The canonical Decision #1 file is:

`docs/70_GATE4_HUSH_SEMANTIC_LAYER_IDENTITY_ADDENDUM.md`

Any earlier incidental research-reference text that spells this as `...SEMANTIC_STATE_IDENTITY...` is a documentation typo only and does not refer to a second authority file. The `docs/70` file above is the sole Gate 4 Decision #1 authority.

## Next design dependency

After Issue #126 design closure, re-check `ROADMAP.md` and open issues. Issue #4 — **Define persistent world-state and save schema** — remains an explicit prerequisite because Gate 4 Decision #6 intentionally defers the full project-wide stable-ID/save-category/version/migration/malformed-save contract to it.
