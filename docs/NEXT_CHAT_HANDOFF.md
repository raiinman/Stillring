# Stillring — Next Chat Handoff

**Updated:** 2026-09-05  
**Repository:** `raiinman/Stillring`  
**Status:** Gate 1 locomotion FINAL OWNER APPROVED. Gate 1 camera Decisions #1–#18 COMPLETE / LOCKED. Camera Issue #2 is ready to close after this handoff/register update. The next design system is Gate 2 combat, beginning from GitHub Issue #3 with a fresh one-decision-at-a-time research pass.

## Read first
1. `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`
2. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
3. `docs/22_GATE1_CAMERA_SPECIFICATION.md`
4. `docs/23_GATE1_CAMERA_CRAMPED_ROOM_ADDENDUM.md`
5. `docs/24_GATE1_CAMERA_LOW_CEILING_ADDENDUM.md`
6. `docs/25_GATE1_CAMERA_VERTICAL_SPACE_ADDENDUM.md`
7. `docs/26_GATE1_CAMERA_LOCK_ACQUISITION_ADDENDUM.md`
8. `docs/27_GATE1_CAMERA_LOCK_FRAMING_ADDENDUM.md`
9. `docs/28_GATE1_CAMERA_10_11_RECONCILIATION_COMPANION.md`
10. `docs/29_GATE1_CAMERA_TARGET_SWITCH_ADDENDUM.md`
11. `docs/30_GATE1_CAMERA_MULTI_ENEMY_FRAMING_ADDENDUM.md`
12. `docs/31_GATE1_CAMERA_LARGE_BOSS_FRAMING_ADDENDUM.md`
13. `docs/32_GATE1_CAMERA_AIRBORNE_TRAVERSAL_ADDENDUM.md`
14. `docs/33_GATE1_CAMERA_SHAKE_ACCESSIBILITY_ADDENDUM.md`
15. `docs/34_GATE1_CAMERA_INPUT_PARITY_ADDENDUM.md`
16. `docs/35_GATE1_CAMERA_AIM_MODE_BOUNDARY_ADDENDUM.md`
17. `docs/36_GATE1_CAMERA_DECISION_REGISTER_EXTENSION.md`
18. `docs/18_PROJECT_DECISION_REGISTER.md`
19. `ROADMAP.md`
20. GitHub Issue #3 — combat frame/state model

Always re-check exact current `main` before repository writes.

## Methodical approval workflow — REQUIRED
The owner has explicitly delegated approval during scheduled deep-work runs **only after each individual decision receives its own complete pass**.

For every meaningful decision/system:
1. fresh focused research for the current decision;
2. current primary sources + relevant shipped-game design lineage at the abstract problem-solving level;
3. reconcile against all locked Stillring authority, IP guardrails, accessibility, controls, failure cases, System IDE requirements, tests, and implementation boundaries;
4. produce one coherent decision package;
5. only when that individual package is genuinely complete, scheduled-run delegation permits locking/approving it;
6. document, inspect exact diff, merge with expected head verification;
7. only then begin the next decision.

**Work for as long as productively possible in each scheduled wake/session.** Continue through as many complete individual decisions/systems as possible, but never batch unresolved decisions or skip the research/approval/documentation loop.

## Camera system — COMPLETE
Camera Decisions #1–#18 are individually resolved.

Key later-system obligations:
- target acquisition/switching is explicit and target identity is authoritative;
- target switching is one request → at most one switch, directional in screen space, no wraparound roulette;
- ordinary lock frames one chosen Neris↔target relationship;
- secondary enemies do **not** steer/zoom/FOV the camera; combat/encounter/threat communication must make crowds fair within actual visual bandwidth;
- large bosses use authored camera framing profiles; camera-only anchors are not gameplay target identities;
- jump/fall/mantle/hang camera follows gameplay state, not animation bones;
- gameplay shake is optional feedback and can be reduced to true zero;
- controller/mouse camera input uses native device processing and full remapping constraints;
- Gate 1 contains no generic precision-aim, first-person, or gyro grammar; a future concrete verb must earn its own camera contract.

Camera philosophy:
> **The player should look at Orra, not babysit the camera.**

### Camera documentation mechanics debt — not design debt
`docs/28_GATE1_CAMERA_10_11_RECONCILIATION_COMPANION.md` temporarily carries cumulative #10/#11 reconciliation because the current connector could not safely patch the very large `docs/22` without whole-file replacement.

When a normal git workspace is available:
- mechanically fold #10 then #11 into `docs/22`;
- verify against `docs/26`, `docs/27`, `docs/28`;
- retire `docs/28`;
- fold `docs/36` into `docs/18` and retire `docs/36`.

Do not reopen camera policy merely because this mechanical consolidation remains.

## Immediate next work — Gate 2 combat
Start from **Issue #3** and research combat fresh. The previously created premature Gate 2 combat packet was removed/reverted and is **not authority**. Do not reconstruct or rely on it as a shortcut.

Before approving any combat implementation policy:
- read Issue #3 and relevant vision/lineage/locomotion/camera authority;
- define the first meaningful combat decision narrowly;
- research it independently;
- build Combat System IDE inspect/tune/exercise/validate/capture requirements alongside the decision;
- lock/document/merge that one decision;
- then move to the next combat decision.

Likely first research question, subject to Issue #3 authority:
> **When Neris commits to an attack, what remains player-changeable before that action ends?**

Do not assume the answer from generic Souls/Zelda/action-game conventions.

### Combat constraints already inherited from settled systems
- locked locomotion is target-relative with player-owned spacing;
- ordinary Sprint is not combat evade and has no stamina tax;
- Jump remains Jump rather than hidden contextual dodge;
- target switching is explicit and deterministic;
- camera will not rescue unreadable multi-enemy aggression;
- combat/encounter design must communicate offscreen threats honestly;
- animation presentation may not silently become gameplay authority;
- no generic precision-aim camera exists unless a later concrete verb earns it;
- every substantial combat state/rejection/tuning surface must be inspectable in the Combat IDE.

## Governing rules
- Unreal Engine 5.8.
- Claude primary implementation agent.
- C++ first for gameplay/state authority; thin Blueprint presentation.
- No retail runtime AI/model/API dependency.
- Pipeline: CANON → PRODUCTION → IMPLEMENTATION → VERIFICATION → PLAY.
- Human play remains authoritative for feel.
- Research before every major design recommendation.
- Engine/template defaults are implementation options, never owner policy.
- `docs/05_IP_GUARDRAILS.md` clean-room rules apply to all comparative game research.

Movement principle:
> **Simple intention, capable character, honest world.**

System IDE rule:
> **Build the system and its in-game IDE together.**

## Recent closure PRs
- #83 — reconcile already-approved Camera #10/#11 — merge `a91081b58bbfbb3c9b679858a371c3bd4c6288f2`
- #84 — Camera #12 target switching — merge `992bad0a4a265664cc63669c54ced453e3927762`
- #85 — Camera #13 multiple-enemy framing — merge `18f9238830abf498fab69289ce8a6cada37a94bf`
- #86 — Camera #14 large-boss framing — merge `2dbd32737c83ad8383f58f32fec104d31a1e801c`
- #87 — Camera #15 airborne/traversal — merge `9ba2c0cc1b023f9a0bb2873f7922baee22013a94`
- #88 — Camera #16 shake/accessibility — merge `334de5a169741c83fd21237292c2e23056300a10`
- #89 — Camera #17 input parity — merge `604fdcc588e72f00f9b7112a268e78dff94eca61`
- #90 — Camera #18 aim-mode boundary — merge `1c6af7aefffe460dbd958fc6c9aeaef8345e738c`

Next: close Issue #2 after closure docs merge, then begin Issue #3 decision-by-decision combat research.