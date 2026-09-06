# 136 — Canonical Authority Index

**Status:** CANONICAL NAVIGATION AUTHORITY  
**Updated:** 2026-09-05  
**Program:** Documentation Closure Phase 1  
**Baseline:** `f3874de569e7e791c1f34fee093539bc34970fb4`

## Purpose

This index answers one question:

> **If you are about to implement, author, tune, test, or revise something in Stillring, which document contains the current authority for that topic?**

It is a navigation/precedence document.

It does not replace the detailed authority files it points to.

Do not infer runtime completion from the presence of a design authority file.

Status vocabulary follows `docs/135_DOCUMENTATION_CLOSURE_PROGRAM_CHARTER.md`.

---

# 1. Project-level authority

| Domain | Current authority | Design/document status | Runtime status |
|---|---|---|---|
| Project roadmap / gate order | `ROADMAP.md` | Current gate-based production plan | Gates 1+ largely unimplemented/unverified |
| Canon-to-play process | `docs/15_CANON_TO_PLAY_PIPELINE.md` | Locked project process | Must be followed during implementation |
| Developer tooling / machine QA | `docs/16_DEVELOPER_TOOLING_AND_MACHINE_QA.md` | Locked design contract | Runtime tooling largely unimplemented |
| Zelda design lineage / control principles | `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md` | Locked reference discipline | Human-play application unverified |
| Project decision register | `docs/18_PROJECT_DECISION_REGISTER.md` plus scoped later decision registers | Locked decisions/navigation | Not runtime proof |
| Shared in-game System IDE | `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md` | Locked design contract | **OPEN ISSUE #58 — implementation unverified** |
| Current handoff / operational boundary | `docs/NEXT_CHAT_HANDOFF.md` | Current operational entrypoint | N/A |
| Documentation closure process | `docs/135_DOCUMENTATION_CLOSURE_PROGRAM_CHARTER.md` | Active governing process | N/A |
| Canonical authority navigation | this document | Active/current | N/A |
| Supersession / precedence | `docs/137_SUPERSESSION_GRAPH.md` | Active/current | N/A |
| Terminology / onboarding | `docs/138_TERMINOLOGY_GLOSSARY_AND_ONBOARDING.md` | Active/current | N/A |

---

# 2. Narrative / world / content authority

The canonical story lives primarily in `docs/story/` plus the project story/content bibles and completion authority.

Do not treat an older side-content count as current if it conflicts with Completion Decision #16.

| Topic | Current authority | Notes |
|---|---|---|
| Core story premise / beginning-to-end story spine | `docs/02_STORY_BIBLE.md` and current `docs/story/` canon | Story facts remain subject to later scoped addenda such as Null Meridian precedence |
| Progression structure | `docs/09_STILLRING_PROGRESSION_BLUEPRINT.md` | Use with later tool/Hush/traversal/finale authority |
| Completion model | `docs/104_COMPLETION_LEDGER_RECONCILIATION_AUTHORITY_ADDENDUM.md` | **Numeric authority** for completion counts/weights/thresholds |
| 100% route | `docs/12_100_PERCENT_ROUTE.md` | Narrative/content route; numeric literals subordinate to doc 104 where stale |
| Cantor patterns / tool upgrades catalog | `docs/13_CANTOR_AND_UPGRADE_CATALOG.md` | Content catalog; completion thresholds/counts subordinate to doc 104 where stale |
| Prestige / mastery content | `docs/14_PRESTIGE_AND_MASTERY_CONTENT.md` + docs 96–103 where relevant | Category counts/weights subordinate to completion authority |
| Main scene order | `docs/story/07_SCENE_BEAT_LEDGER.md` | Null Meridian exact M16 order is superseded by doc 134 |
| Reveal/foreshadow | `docs/story/08_REVEAL_AND_FORESHADOW_LEDGER.md` | Must remain consistent with later scoped finale authority |
| Main quest objective flow | `docs/story/09_MAIN_QUEST_OBJECTIVE_FLOW.md` | Objective presentation is subordinate to semantic state ownership |
| Narrative flow repair/audit | `docs/story/11_NARRATIVE_FLOW_AUDIT.md` | Current audit context; not a substitute for system authority |
| World change / offscreen action | `docs/story/12_WORLD_PULSE_LEDGER.md` | World-state runtime owner still follows Save/World-State authority |
| Emotional pacing | `docs/story/13_EMOTIONAL_PACING_MAP.md` | Human-play proof remains future work |
| Regional story bibles | `docs/story/regions/` | Canonical region-specific narrative, subject to later scoped addenda |
| Hush-Cairnspire / Null Meridian story | `docs/story/regions/09_HUSH_CAIRNSPIRE_AND_NULL_MERIDIAN.md` + docs 127–134 | Docs 127–134 control exact final-dungeon mechanics/order |

---

# 3. Gate 1 — locomotion

## Governing authority

- `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`

This is the current cumulative locomotion specification after the owner-led locomotion decision program.

### Locked examples
- useful analog movement from low speed through full speed;
- sustained sprint from beginning of game;
- **no stamina/resource cost for ordinary sprint/travel**;
- deliberate always-available modest jump;
- small authored mantle/scramble for obviously low obstacles;
- automatic stairs/small terrain handling;
- meaningful height gates remain meaningful;
- no universal/free climbing;
- hang shimmy limited to the same continuous handhold;
- explicit ledge release;
- locomotion design may not silently mutate during implementation.

### Runtime status

**Not UE5.8 proven.**

Issue #5 remains open for the Gate 1 prototype harness.

Exact speeds, curves, thresholds, animation response, jump feel, air control, collision tuning, and human comfort remain prototype/human-play work where not explicitly locked.

---

# 4. Gate 1 — camera / targeting

## Governing authority

- `docs/22_GATE1_CAMERA_SPECIFICATION.md`
- supporting camera decision addenda in `docs/23`–`36` where implementation detail is needed

### Locked direction

Camera follows Stillring's modernized third-person control principles rather than copying OoT-era hardware constraints.

Free camera, recenter convenience, camera collision, target lock, target switching, combat readability, high/low geometry behavior, locomotion continuity, and deterministic test requirements are documented in the camera package.

### Runtime status

**Not UE5.8/human-play proven.**

Gate 1 harness implementation remains under Issue #5.

---

# 5. Gate 2 — player combat

## Governing authority

- `docs/48_GATE2_COMBAT_STATE_MODEL.md`
- supporting locked Gate 2 player-combat decisions in `docs/37`–`49`

Use the later/cumulative state-model authority for conflicts within the player-combat package.

### Key boundary

Combat state is authoritative gameplay state; Animation Blueprint/presentation may represent it but must not own a contradictory combat model.

### Runtime status

**Design locked / runtime unverified.**

No claim that final hit timing, balance, damage, animation feel, enemy pressure, or human combat readability is proven.

---

# 6. Gate 2 — enemy / encounter

## Governing authority

- locked encounter/enemy addenda `docs/50`–`59`
- `docs/59_GATE2_ENCOUNTER_FIXTURE_CLOSURE.md` for the closure/fixture boundary

### Key authority themes

- attack bandwidth/readability;
- melee/ranged/offscreen pressure constraints;
- enemy reaction/interrupt semantics;
- authored encounter composition;
- no unfair hidden pressure fixes;
- deterministic encounter fixtures;
- camera/combat coordination.

### Runtime status

**Design locked / runtime unverified.**

Actual AI behavior, nav/spacing, animation, difficulty tuning, encounter fun, accessibility, and performance require UE5.8 proof.

---

# 7. Gate 3 — Cantor / field tools / puzzle mechanisms

## Governing authority

- `docs/69_GATE3_TOOL_SYSTEM_CUMULATIVE.md`
- supporting decisions `docs/60`–`68`
- content/catalog relationships in `docs/13_CANTOR_AND_UPGRADE_CATALOG.md`

### Important filename rule

The canonical cumulative file is:

`docs/69_GATE3_TOOL_SYSTEM_CUMULATIVE.md`

Not:

`docs/69_GATE3_TOOL_PUZZLE_CUMULATIVE_SPECIFICATION.md`

Any older reference to the latter is stale.

### Key authority themes

- Cantor diagnoses/compares relationships; it is not a generic magic scanner;
- tool interactions use coherent physical/semantic contracts;
- Anchor spans traversal/combat-pressure/puzzle use without becoming freeform grappling;
- source systems retain authority for actual world state;
- deterministic test fixtures and IDE surfaces are required.

### Runtime status

**Design locked / runtime unverified.**

---

# 8. Gate 4 — Hush / world-layer system

## Governing authority

- `docs/79_GATE4_HUSH_CUMULATIVE_SPECIFICATION.md`
- supporting decisions `docs/70`–`78`
- prototype/closure context `docs/80_GATE4_ISSUE_227_CLOSURE_AND_PROTOTYPE_PLAN.md`

### Key boundaries

- Waking/Hush are semantic world-layer expressions, not duplicated quest truths;
- seams obey explicit legality and transition contracts;
- locomotion/combat state is not magically reset by layer transition;
- seam grants no generic invulnerability/action cancel/momentum reset;
- paired persistent identity is semantic;
- Data Layer load state cannot become quest/world-state authority.

### Architecture status

World Partition + Runtime Data Layers has been used as a prototype direction with spatial streaming disabled in the prototype context, but final production architecture still requires real UE5.8 evidence for authoring/source-control/performance/save/reload behavior.

### Runtime status

**Design locked / production runtime unverified.**

---

# 9. Save / World-State

## Governing authority

- `docs/81_SAVE_PERSISTENT_IDENTITY_ADDENDUM.md`
- `docs/82_SAVE_STATE_TAXONOMY_OWNERSHIP_ADDENDUM.md`
- `docs/83_SAVE_SCHEMA_V1_STRUCTURE_ADDENDUM.md`
- `docs/84_SAVE_VERSION_MIGRATION_POLICY_ADDENDUM.md`
- `docs/85_SAVE_INTEGRITY_RECOVERY_ADDENDUM.md`
- `docs/86_SAVE_SLOT_CADENCE_RETRY_ADDENDUM.md`
- `docs/87_SAVE_WORLD_STATE_IDE_ADDENDUM.md`
- **cumulative:** `docs/88_SAVE_WORLD_STATE_CUMULATIVE_SPECIFICATION.md`

### Key boundaries

- stable semantic IDs;
- actor paths/runtime instance IDs forbidden as canonical persistence keys;
- state categories and owners explicit;
- schema v1/versioning/migration;
- malformed/incompatible save recovery;
- source systems restore before derived consumers reconcile;
- transient presentation does not outrank semantic facts;
- half-transitions are not valid save authority.

### GitHub issue status

**Issue #4 remains OPEN.**

Its design criteria are substantially documented, but verification explicitly requires a paired-layer runtime save/exit/reload proof.

### Runtime status

**Design locked / runtime verification outstanding.**

---

# 10. Completion / 100%

## Numeric and reconciliation authority

- `docs/104_COMPLETION_LEDGER_RECONCILIATION_AUTHORITY_ADDENDUM.md`

## Category-specific authorities

- docs `89`–`103`

## Cleanup / stale-literal authorities

- docs `105`–`111`
- especially `docs/109_COMPLETION_LEGACY_LITERAL_BLOCKLIST.md`

### Locked top-level model

There are **16 equal completion categories**, each worth **6.25%**.

Current key counts:
- Main Story — 1 route;
- Local Repair Contracts — 24;
- Setup/Payoff — 12;
- Bellwright Refuges — 11;
- Resonance Faults — 36;
- Pulse Shards — 18;
- Cantor Patterns — 9;
- Tool Mastery Upgrades — 14;
- Skill Trials — 9;
- Micro-vaults — 24;
- Testimonies / Records — 32;
- Unstandard Tool prestige — 1 global item / 12 internal stages;
- Drift Knots — 12;
- Optional Elite Encounters — 8;
- Community Disconnection Projects — 6;
- Broken Standard Yard — 1 global item / 7 internal commissions.

Drift Knot eligibility:

**10 reconciled Resonance Faults + existing story/Line Skiff prerequisites.**

Stale values such as 48 Faults / 28 Pulse Shards / 30 Vaults / Drift=13 / K02=30 must not be implemented.

### Runtime status

**Design/documentation locked / runtime ledger and 100% reconciliation unverified.**

---

# 11. Setup/Payoff — Issue #9

## Governing authority

- `docs/112_SETUP_PAYOFF_STATE_AUTHORITY_ADDENDUM.md`
- `docs/113_SETUP_PAYOFF_COMMIT_BOUNDARY_AUTHORITY_ADDENDUM.md`
- `docs/114_SETUP_PAYOFF_PAYOFF_MATERIALITY_AUTHORITY_ADDENDUM.md`
- `docs/115_SETUP_PAYOFF_PORTFOLIO_AUTHORITY_ADDENDUM.md`
- `docs/116_SETUP_PAYOFF_AUTHORING_DATA_AUTHORITY_ADDENDUM.md`
- `docs/117_SETUP_PAYOFF_PROTOTYPE_INSTANTIATION_AUTHORITY.md`
- closure: `docs/118_SETUP_PAYOFF_ISSUE_9_CLOSURE_AUDIT.md`
- navigation: `docs/119_SETUP_PAYOFF_DECISION_REGISTER_ADDENDUM.md`

### Core rule

> **Source systems own facts. Setup/Payoff evaluates them. It does not copy them.**

### Runtime status

Issue #9 is closed as design/documentation complete.

Primary DataAsset/runtime definition implementation, persistence, IDE, vertical-slice proof, migrations, and human legibility remain unverified.

---

# 12. Traversal Transformation / Line Skiff — Issue #10

## Governing authority

- `docs/120_TRAVERSAL_TRANSFORMATION_DECISION_1_LINE_SKIFF_SELECTION.md`
- `docs/121_TRAVERSAL_TRANSFORMATION_DECISION_2_ROUTE_NETWORK_GRAMMAR.md`
- `docs/122_TRAVERSAL_TRANSFORMATION_DECISION_3_WORLD_LAYER_ROUTE_STATE.md`
- `docs/123_TRAVERSAL_TRANSFORMATION_DECISION_4_ACQUISITION_MASTERY.md`
- `docs/124_TRAVERSAL_TRANSFORMATION_DECISION_5_NETWORK_INTEGRATION.md`
- closure: `docs/125_TRAVERSAL_TRANSFORMATION_ISSUE_10_CLOSURE_AUDIT.md`
- navigation: `docs/126_TRAVERSAL_TRANSFORMATION_DECISION_REGISTER_ADDENDUM.md`

### Core identity

> **The Line Skiff is a network vehicle, not a mount. It makes authored roads newly expressive; it does not replace the world between them.**

### Runtime status

Issue #10 is closed as design/documentation complete.

Vehicle handling, high-speed camera, semantic route graph, World Partition/HLOD behavior, save/reload, Hush paired-route continuation, Trial 05, Drift Knots, Route Listener, accessibility, IDE, and human fun remain unverified.

---

# 13. Null Meridian — Issue #11

## Governing authority

- `docs/127_NULL_MERIDIAN_DECISION_1_SYNTHESIS_ARCHITECTURE.md`
- `docs/128_NULL_MERIDIAN_DECISION_2_ONE_GOVERNING_DUNGEON_IDEA.md`
- `docs/129_NULL_MERIDIAN_DECISION_3_FIRST_HALF_ADVENTURE_FLOW.md`
- `docs/130_NULL_MERIDIAN_DECISION_4_SECOND_HALF_ESCALATION.md`
- `docs/131_NULL_MERIDIAN_DECISION_5_TAKE_IT_OFF_THE_BELL.md`
- closure: `docs/132_NULL_MERIDIAN_ISSUE_11_CLOSURE_AUDIT.md`
- navigation: `docs/133_NULL_MERIDIAN_DECISION_REGISTER_ADDENDUM.md`
- exact scene-order precedence: `docs/134_NULL_MERIDIAN_SCENE_ORDER_PRECEDENCE_ADDENDUM.md`

### Governing idea

> **Meridian keeps forcing distinct local things toward one authoritative state. Neris progresses by allowing legitimate local difference, preserving contradiction where needed, letting old states become past, and finally removing central command without destroying coordination.**

### Runtime status

Issue #11 is closed as design/documentation complete.

Blockout, actual S1–S6 scripting, combat, Hush, Maelor, Listener, save/reload, accessibility, performance, IDE, fixtures, human comprehension, and emotional pacing remain unverified.

---

# 14. System IDE authority

## Shared shell

- `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`

## System-specific IDE requirements

Many system packages add explicit IDE obligations, including:
- locomotion;
- camera/targeting;
- combat/encounter;
- Cantor/tools/puzzles;
- Hush/world layer;
- Save/World-State;
- Completion;
- Setup/Payoff;
- Line Skiff;
- Null Meridian.

The phase-2 `System IDE Coverage Matrix` will consolidate these.

### GitHub issue status

**Issue #58 remains OPEN.**

Design is specified; shared runtime shell/workbench implementation is not proven.

---

# 15. UE5.8 implementation bootstrap authority

## Governing issue

**Issue #5 — Bootstrap Gate 1 Unreal Engine 5.8 C++ prototype harness**

The issue is intentionally still open.

It requires real runtime evidence including:
- project opens cleanly in UE5.8;
- reproducible C++ build;
- Enhanced Input;
- graybox Gate 1 course;
- reset/reload/runtime readout;
- Automation/smoke path;
- Git LFS-safe `.uasset`/`.umap` policy;
- fresh-checkout verification.

The Documentation Closure Program does not close or bypass this issue.

---

# 16. Fast implementation read order by task

## Movement / camera engineer

Read:
1. `docs/135_DOCUMENTATION_CLOSURE_PROGRAM_CHARTER.md`
2. this index;
3. `docs/137_SUPERSESSION_GRAPH.md`;
4. `docs/138_TERMINOLOGY_GLOSSARY_AND_ONBOARDING.md`;
5. `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`;
6. `docs/22_GATE1_CAMERA_SPECIFICATION.md`;
7. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`;
8. Issue #5 acceptance criteria;
9. supporting Gate 1 addenda only when needed for exact edge behavior.

## Combat / encounter engineer

Read:
1. closure docs 135–138;
2. `docs/22_GATE1_CAMERA_SPECIFICATION.md` for targeting/camera constraints;
3. `docs/48_GATE2_COMBAT_STATE_MODEL.md`;
4. `docs/50`–`59` as relevant;
5. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`.

## Tool / puzzle engineer

Read:
1. closure docs 135–138;
2. `docs/69_GATE3_TOOL_SYSTEM_CUMULATIVE.md`;
3. `docs/13_CANTOR_AND_UPGRADE_CATALOG.md` for authored capability content;
4. relevant Gate 3 addenda;
5. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`.

## Hush / world-layer engineer

Read:
1. closure docs 135–138;
2. `docs/79_GATE4_HUSH_CUMULATIVE_SPECIFICATION.md`;
3. `docs/88_SAVE_WORLD_STATE_CUMULATIVE_SPECIFICATION.md`;
4. relevant Gate 4 addenda;
5. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`;
6. Issue #4 runtime verification boundary.

## Save / world-state engineer

Read:
1. closure docs 135–138;
2. `docs/88_SAVE_WORLD_STATE_CUMULATIVE_SPECIFICATION.md`;
3. docs 81–87 for exact subcontracts;
4. completion doc 104;
5. Setup/Payoff docs 112–119;
6. Hush doc 79;
7. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`;
8. Issue #4.

## Story / content writer

Read:
1. `docs/138_TERMINOLOGY_GLOSSARY_AND_ONBOARDING.md`;
2. this index;
3. `docs/02_STORY_BIBLE.md`;
4. current `docs/story/` story spine/scene/reveal/objective/region authority;
5. `docs/104_COMPLETION_LEDGER_RECONCILIATION_AUTHORITY_ADDENDUM.md` before using completion counts;
6. Setup/Payoff docs 115/117 for cross-state authored chains;
7. Null Meridian docs 127–134 for final-dungeon content/order.

---

# 17. Current proof boundary summary

At the time of this index:

### Documentation/design complete
- narrative/design foundation;
- Gate 1 locomotion/camera specifications;
- Gate 2 combat/encounter specifications;
- Gate 3 tool system design;
- Gate 4 Hush design;
- Save/World-State design package;
- completion design;
- Setup/Payoff design;
- Line Skiff design;
- Null Meridian design.

### Still open / runtime-dependent
- Issue #4 — paired-layer save/world-state verification;
- Issue #5 — UE5.8 Gate 1 harness implementation;
- Issue #58 — shared System IDE implementation.

### Broad implementation authorization

**Not yet granted by the Documentation Closure Program.**

Finish closure phases and final owner review first.