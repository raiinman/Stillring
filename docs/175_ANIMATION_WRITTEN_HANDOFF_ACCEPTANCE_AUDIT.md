# 175 — Animation Written-Handoff Acceptance Audit

**Status:** ACTIVE / SCOPED ANIMATION-HANDOFF RECONCILIATION / DOCUMENTATION-ONLY  
**Updated:** 2026-09-06  
**Parent program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Gap baseline:** `docs/152_STUDIO_HANDOFF_GAP_REGISTER.md`  
**Acceptance baseline:** `docs/153_STUDIO_HANDOFF_ACCEPTANCE_CHECKLIST.md`  
**Animation Bible:** `docs/173_STILLRING_ANIMATION_BIBLE.md`  
**Animation manifest:** `docs/174_ANIMATION_PRODUCTION_MANIFEST.md`  
**Decision rights:** `docs/170_STUDIO_DECISION_RIGHTS_MATRIX.md`  
**Boundary:** this audit evaluates written production authority only. It does not authorize rigging, animation production, UE5.8 implementation, runtime testing, performance profiling, facial-tech selection, motion capture, final animation budgets, or human-play acceptance.

---

# 1. Purpose

`docs/152` identified nine animation-production gaps.

The project now has:
- a discipline Animation Bible;
- root-motion/displacement policy;
- rig/skeleton/retargeting boundaries;
- procedural/IK/additive policy;
- facial/performance tiers;
- event/notify ownership;
- explicit Neris gameplay animation inventory;
- principal/C3/NPC occupation burden;
- ordinary enemy and major boss animation burden;
- Line Skiff/Hush/mechanism burden;
- animation System IDE/debug requirements;
- production review gates;
- runtime-gated unknown classification.

This audit determines which `SH-ANI-*` gaps are now closed at the written-handoff stage and which still honestly depend on another documentation package or runtime evidence.

---

# 2. Scope and precedence

For current status of `SH-ANI-001` through `SH-ANI-009`:

1. use `docs/152` for the original gap definition;
2. use `docs/173` for animation doctrine/ownership/pipeline authority;
3. use `docs/174` for production inventory/burden;
4. use this audit for current scoped status.

This audit does not supersede gameplay, art, story, enemy, region or technical-production authority.

---

# 3. `SH-ANI-*` reconciliation

| Gap | Current result | Current written evidence | Remaining honest work |
|---|---|---|---|
| `SH-ANI-001` rig/skeleton/retarget standards | **PASS — WRITTEN AUTHORITY** | `docs/173` §§6–7; UE5.8 technique envelope §5 | actual hero/shared/fauna/machine rigs; runtime/baked retarget choice; deformation/performance evidence |
| `SH-ANI-002` Neris animation inventory | **PASS — WRITTEN INVENTORY** | `docs/174` §§4–12 | exact source-clip decomposition; production execution; runtime feel/contact tuning |
| `SH-ANI-003` enemy-family animation manifests | **PASS — WRITTEN FAMILY/BOSS BURDEN** | `docs/174` §§18–19; visual source `docs/159` | exact final retail archetype split/distribution; source clips; encounter-timing integration; runtime readability/performance |
| `SH-ANI-004` NPC ambient/social/occupation loops | **PASS — WRITTEN FAMILY BURDEN** | `docs/174` §§13–17; C3/region source `docs/160` | exact loop counts/assignments; crowd scheduling; implementation/performance; scene-specific cleanup |
| `SH-ANI-005` root-motion policy | **PASS — WRITTEN AUTHORITY** | `docs/173` §9 | family-level implementation choices; representative motion-warp/root-motion evidence; human feel |
| `SH-ANI-006` IK/additive/procedural responsibilities | **PASS — WRITTEN AUTHORITY** | `docs/173` §§19–24 | exact solvers/tolerances; rig integration; runtime/performance evidence |
| `SH-ANI-007` facial/performance scope | **PASS — SCOPE/TIER AUTHORITY** | `docs/173` §16; `docs/174` §22 | final facial technology; VO-dependent pipeline; localization/performance tests; actual facial assets |
| `SH-ANI-008` cinematic animation burden | **PARTIAL — METHOD AND ACTOR TIERS CLOSED / EXACT SCENE INVENTORY DEPENDENCY-BOUND** | `docs/173` §26; `docs/174` §23 | scene-by-scene cinematic inventory from Narrative/Cinematic Production package, then exact bespoke/reuse counts |
| `SH-ANI-009` animation event ownership | **PASS — WRITTEN AUTHORITY** | `docs/173` §§8, 22; gameplay boundary in `docs/48` | implementation validation proving no notify/shadow-state ownership |

---

# 4. Why `SH-ANI-008` remains partial

The animation discipline can define **how** cinematic burden must be classified without inventing a cinematic list that belongs to narrative production.

Current authority already defines classification:
- gameplay reuse;
- gameplay reuse + cleanup;
- bespoke body;
- bespoke face;
- crowd;
- mechanism;
- Hush relational staging.

It also defines required per-scene fields:
- actors;
- costume/state;
- props;
- camera distance;
- dialogue/VO dependency;
- entry/exit semantic state;
- skip behavior;
- reuse class.

What does not yet exist is the authoritative **scene-by-scene cinematic production inventory**.

That must be derived from the later Narrative Production / Cinematic Manifest workstream rather than guessed by animation.

Therefore:

> **Animation has no undefined cinematic methodology, but exact cinematic animation volume remains dependency-bound.**

---

# 5. `docs/153` Animation Production reconciliation

| Acceptance item | Current result | Evidence / note |
|---|---|---|
| skeleton/rig strategy explicit | **PASS** | `docs/173` §§6–7 |
| retargeting policy explicit | **PASS** | `docs/173` §7 |
| root-motion vs in-place policy explicit | **PASS** | per-family displacement policy `docs/173` §9 |
| Neris locomotion inventory explicit | **PASS** | `docs/174` §§4–6 |
| traversal/ledge/ladder/swim inventory explicit | **PASS** | `docs/174` §5 |
| combat inventory explicit | **PASS** | `docs/174` §7 |
| tool/Cantor inventory explicit | **PASS** | `docs/174` §8 |
| Line Skiff inventory explicit | **PASS** | `docs/174` §10 |
| enemy/boss animation families explicit | **PASS** | `docs/174` §§18–19 |
| NPC ambient/social/occupation families explicit | **PASS** | `docs/174` §§14–17 |
| facial-performance tiers explicit | **PASS** | `docs/173` §16; `docs/174` §22 |
| IK/procedural/additive responsibilities explicit | **PASS** | `docs/173` §§19–24 |
| Hush animation behavior explicit | **PASS** | `docs/173` §14; `docs/174` §§11, 21 |
| animation event/gameplay-state ownership explicit | **PASS** | `docs/173` §§8, 22 |
| cinematic animation burden explicit | **PARTIAL** | classification/method pass; exact scene inventory awaits Narrative/Cinematic package |
| source/provenance/review expectations explicit | **PASS** | `docs/173` §§28–30; `docs/174` §25 |
| runtime-gated animation values have evidence path | **PASS** | `docs/173` review gates + `docs/170` promotion contract; `docs/174` §28 |

## 5.1 Animation-section result

> **SUBSTANTIALLY PASS — WRITTEN ANIMATION AUTHORITY; EXACT CINEMATIC SCENE BURDEN REMAINS DEPENDENCY-BOUND.**

No item is left as an ambiguous `TBD`.

---

# 6. Gameplay-state ownership adversarial audit

## “Can the montage end Recovery?”

Not by itself.

Combat owns Startup/Active/Recovery. Animation may present/mark reviewed boundaries but cannot extend or shorten authoritative state independently.

## “Can a Motion Warping window make an almost-valid mantle work?”

No.

Locomotion first validates the mantle/ledge transaction. Warping may align presentation inside the approved contact envelope only.

## “Can an Anim Notify turn damage on?”

Only as a reviewed marker consumed/validated by Combat’s authoritative action data. The notify cannot be the only source of combat legality.

## “Can an Evade clip’s root motion define immunity?”

No.

Combat owns both collision-honest displacement envelope and immunity timing.

## “Can the Hush transition restart an attack animation to look smoother?”

Not if that restarts semantic action timing. Destination presentation must rebind/continue the same gameplay state.

## “Can a boss concept demand an animation that implies a new weak point?”

No.

Animation/art may present only authored combat/component semantics.

No player-facing ownership gap remains in these cases.

---

# 7. Negative-space audit

The package removes several dangerous vague phrases.

## “Appropriate animations”

Replaced with explicit family inventories for player, tools, Skiff, NPCs, enemies, bosses, mechanisms and Hush relationships.

## “Root motion where needed”

Replaced with family-specific displacement policy and explicit prohibited uses.

## “Use IK”

Replaced with valid application categories, hard limits and runtime-gated solver selection.

## “Retarget NPCs”

Replaced with compatibility/cleanup rules that protect body identity and prop/contact quality.

## “Facial animation later”

Replaced with F0/F1/F2 production scope while technology remains honestly gated.

## “Cinematics need bespoke animation”

Replaced with a scene-classification method; exact scene burden is explicitly assigned to the Narrative/Cinematic dependency.

## “Animation event”

Replaced with presentation marker, reviewed gameplay marker, and forbidden authority-notify classes.

---

# 8. Content-burden audit

The animation production surface now explicitly includes:

- complete C0 Neris gameplay coverage;
- F0 principal performance subjects;
- C2/F1 major recurring cast;
- all C3/C3+ named recurring regional characters from current art authority;
- eight regional occupation-animation packages;
- shared humanoid motion foundations;
- ordinary enemy starter-family burden;
- twelve major boss/pressure bespoke packages;
- civic/mechanism animation;
- Hush relational animation;
- Line Skiff rider + vehicle support;
- facial systems;
- cinematic classification;
- procedural/additive/secondary-motion support;
- source/provenance fields;
- animation test galleries/System IDE diagnostics.

A production team can estimate categories and unique/shared burden without inventing the animation design philosophy.

---

# 9. Runtime-gated items remain honest

No final values are claimed for:
- blend timing;
- locomotion directional source count;
- Evade variants;
- reaction variants;
- IK tolerances;
- Motion Warping envelopes;
- Motion Matching adoption;
- runtime retargeting;
- facial technology;
- animation LOD budgets;
- compression/memory budgets;
- crowd tick rates;
- final boss attack timings;
- final cinematic clip count.

These remain tied to representative implementation, technical production, encounter authoring, cinematic enumeration or human play.

---

# 10. Current animation owner decisions

No new owner-only decision is required to continue documentation.

Potential later owner/product dependency:
- VO scope affects facial/lip-sync/recording production, but facial performance tiers are valid regardless.

Ordinary choices such as IK solver, rig control architecture, retarget technique, DCC, compression and blend implementation belong to studio/technical animation within documented bounds.

---

# 11. Next highest-value unresolved workstream

The Studio Handoff sequence now advances to:

> **UI / UX Production Specification and Screen-State Manifest — `SH-UI-001` through `SH-UI-010`.**

That package must cover the complete player interface, including:
- shell/title/save/load;
- HUD/combat/targeting;
- interaction/tool/Cantor state;
- inventory/equipment/progression;
- map/navigation;
- quest/journal/records;
- completion;
- pause/settings/accessibility;
- controller and keyboard/mouse navigation;
- remapping/conflicts;
- warnings/errors/recovery/death/retry/credits;
- localization/text expansion;
- UI-state ownership and persistence boundaries;
- screen inventory and transition matrix;
- System IDE/debug visibility where applicable.

---

# 12. Audit conclusion

At written-handoff level:

> **Animation production is substantially closed: `SH-ANI-001`–`007` and `009` PASS; `SH-ANI-008` is explicitly dependency-bound to the future scene-by-scene Narrative/Cinematic inventory.**

This is not animation production completion.

No rigs, clips, facial systems, UE5.8 runtime integration, performance evidence or human-play proof are claimed.

Global Studio Production Handoff Closure remains **IN PROGRESS**.