# Stillring — Next Chat Handoff

**Updated:** 2026-09-05  
**Repository:** `raiinman/Stillring`  
**Operational boundary:** Core design through Save/World-State, Completion, Issue #9 Setup/Payoff, Issue #10 Traversal Transformation, and Issue #11 Null Meridian is documentation/design complete once the current Issue #11 closure package merges. UE5.8 runtime implementation, System IDE implementation, deterministic fixture execution, performance evidence, and human-play acceptance remain **UNVERIFIED** unless later authority explicitly proves them.

## Read first

1. `docs/132_NULL_MERIDIAN_ISSUE_11_CLOSURE_AUDIT.md`
2. `docs/133_NULL_MERIDIAN_DECISION_REGISTER_ADDENDUM.md`
3. `docs/134_NULL_MERIDIAN_SCENE_ORDER_PRECEDENCE_ADDENDUM.md`
4. `docs/131_NULL_MERIDIAN_DECISION_5_TAKE_IT_OFF_THE_BELL.md`
5. `docs/130_NULL_MERIDIAN_DECISION_4_SECOND_HALF_ESCALATION.md`
6. `docs/129_NULL_MERIDIAN_DECISION_3_FIRST_HALF_ADVENTURE_FLOW.md`
7. `docs/128_NULL_MERIDIAN_DECISION_2_ONE_GOVERNING_DUNGEON_IDEA.md`
8. `docs/127_NULL_MERIDIAN_DECISION_1_SYNTHESIS_ARCHITECTURE.md`
9. `docs/126_TRAVERSAL_TRANSFORMATION_DECISION_REGISTER_ADDENDUM.md`
10. `docs/125_TRAVERSAL_TRANSFORMATION_ISSUE_10_CLOSURE_AUDIT.md`
11. `docs/119_SETUP_PAYOFF_DECISION_REGISTER_ADDENDUM.md`
12. `docs/118_SETUP_PAYOFF_ISSUE_9_CLOSURE_AUDIT.md`
13. `docs/104_COMPLETION_LEDGER_RECONCILIATION_AUTHORITY_ADDENDUM.md`
14. `docs/88_SAVE_WORLD_STATE_CUMULATIVE_SPECIFICATION.md`
15. `docs/79_GATE4_HUSH_CUMULATIVE_SPECIFICATION.md`
16. `docs/69_GATE3_TOOL_SYSTEM_CUMULATIVE.md`
17. Gate 2 combat cumulative/locked addenda as referenced by `ROADMAP.md`
18. `docs/22_GATE1_CAMERA_SPECIFICATION.md`
19. `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`
20. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
21. `docs/18_PROJECT_DECISION_REGISTER.md`
22. `ROADMAP.md`
23. `AGENTS.md` / repository-local agent instructions if present

Always re-check exact current `main` before repository writes.

---

# Required method

For any unresolved design or implementation-readiness work:

**fresh research -> reconcile existing authority, IP, accessibility, failure/recovery, save semantics, System IDE, deterministic fixtures, content-production cost, and human-play implications -> owner review if the step changes canon -> document -> exact diff/review -> expected-head merge -> next step.**

Do not silently reopen a locked decision merely because an older authored document contains shorthand.

Use the authority/supersession chain.

Do not claim runtime proof from documentation.

---

# Project status

## Core system design

Design authority through these major systems is locked/documented:
- locomotion;
- camera;
- player combat;
- enemy/encounter behavior;
- Cantor/field tools;
- Hush/world-layer rules;
- Save/World-State;
- completion model and all 16 completion categories;
- Setup/Payoff;
- Line Skiff traversal transformation;
- Null Meridian final-dungeon synthesis architecture.

This does **not** mean the game exists as a proven UE5.8 runtime.

Major implementation/human-proof debt remains.

## Completion

Completion Decision #16 remains canonical in:

`docs/104_COMPLETION_LEDGER_RECONCILIATION_AUTHORITY_ADDENDUM.md`

There are **16 equal top-level completion categories**, each worth 6.25%.

Relevant locked counts include:
- Setup/Payoff chains — 12;
- Bellwright Refuges — 11;
- Resonance Faults — 36;
- Pulse Shards — 18;
- Cantor Patterns — 9;
- Tool Mastery Upgrades — 14;
- Skill Trials — 9;
- Micro-vaults — 24;
- Testimonies/Records — 32;
- Drift Knots — 12;
- Optional Elite Encounters — 8;
- Community Disconnection Projects — 6.

Drift Knot eligibility remains:

**10 reconciled Resonance Faults + existing story/Line Skiff prerequisites.**

Older 13-Fault language is superseded.

---

# Issue #9 — Setup/Payoff — CLOSED / design complete

Authority:
- `docs/112` — semantic state authority;
- `docs/113` — commit boundaries;
- `docs/114` — payoff materiality;
- `docs/115` — 12-chain portfolio;
- `docs/116` — authoring/data contract;
- `docs/117` — S01/S06/S11 canonical prototypes;
- `docs/118` — closure audit;
- `docs/119` — compact decision register.

Core rule:

> **Source systems own facts. Setup/Payoff evaluates them. It does not copy them.**

Runtime DataAssets, persistence, IDE, vertical-slice proof, and human-play proof remain future work.

---

# Issue #10 — Traversal Transformation — CLOSED / design complete

Authority:
- `docs/120` — Line Skiff selection;
- `docs/121` — route/network grammar;
- `docs/122` — Stillness/Hush/world route state;
- `docs/123` — acquisition/mastery;
- `docs/124` — network/optional integration;
- `docs/125` — closure audit;
- `docs/126` — compact register.

Core identity:

> **The Line Skiff is a network vehicle, not a mount. It makes authored roads newly expressive; it does not replace the world between them.**

Key constraints:
- no summon-anywhere behavior;
- no cross-country free roam;
- no ordinary traversal stamina/fuel/ticket tax;
- no normal mounted combat assumption;
- player owns acceleration/coast/brake/lateral placement/junction intent/momentum/camera;
- semantic route network owns legal macro travel;
- Roadhand Pulse wakes/identifies compatible route infrastructure and is not a generic boost;
- Switchshoe changes supported junction transfer behavior, not global top speed;
- Hush shift while riding requires explicit paired-route continuation;
- shared infrastructure serves story/courier/travel/mastery/Drift Knot purposes rather than building 12 bespoke racetracks.

Runtime Skiff, camera-at-speed, World Partition/HLOD performance, Hush transitions, save/reload, Trial 05, Drift Knots, Route Listener, accessibility, IDE, and human fun/readability remain unverified.

---

# Issue #11 — Null Meridian — CLOSED after current closure package / design complete

Authority:
- `docs/127` — six-sequence architecture;
- `docs/128` — one governing dungeon idea / plain-language rule;
- `docs/129` — first-half adventure flow;
- `docs/130` — second-half escalation;
- `docs/131` — S6 Take It Off the Bell;
- `docs/132` — closure audit;
- `docs/133` — compact decision register;
- `docs/134` — scene-order precedence over older M16 shorthand.

## Governing dungeon idea

> **Meridian keeps forcing distinct local things toward one authoritative state. Neris progresses by allowing legitimate local difference, preserving contradiction where needed, letting old states become past, and finally removing central command without destroying coordination.**

Every major sequence must be explainable in one ordinary player-facing sentence.

If a finale sequence requires teaching a new hidden systems model, simplify it or move that language earlier.

## Canonical sequence

```text
ENTRY / CEREMONIAL SHELL
        |
        +------ S1 HANGING WALK
        |
        +------ S2 EQUAL HOUSE
                 |
                 v
        WORKER MAINTENANCE DESCENT
                 |
                 v
        S3 THE DOOR THAT WAS THERE
                 |
                 v
           QUIET COURT ARCHIVE
                 |
                 v
        MAELOR DELIBERATE CORRECTION
                 |
                 v
        S4 CORRECTED PASSAGE
                 |
                 v
        S5 BATTLE THAT WON'T END
                 |
                 v
        MAELOR PERSONAL WORKSPACE
                 |
                 v
        S6 TAKE IT OFF THE BELL
                 |
                 v
              MAELOR
                 |
              LISTENER
                 |
        FINAL DECOMMISSION
```

S1/S2 may be order-flexible where blockout preserves the approved dependency logic.

## Six sequences

### S1 — Hanging Walk

> **These walkways are being forced to move together, and they're tearing themselves apart. Let them move separately.**

Anchor + Vane; physical coercion.

### S2 — Equal House

> **Meridian is forcing three different machines to run the same way. Put each one back into the condition it actually needs.**

Glasslung + Temper; heterogeneous operating states.

### S3 — The Door That Was There

> **The official plans say there was never a door here. The worker records say there was. Find what happened and use the old doorway.**

Palinode + Mirror; historical contradiction and local commitment.

Quiet Court is the **midpoint turn**, not the immediate pre-Maelor scene.

### S4 — Corrected Passage

> **Meridian keeps choosing one version of the route and erasing the other. Hold the part you need, cross through the Hush, and keep moving.**

Mirror + Hush seam + traversal + ordinary combat pressure.

Traversal is the objective, not mandatory enemy extermination.

### S5 — Battle That Won't End

> **Meridian is replaying an old fight on top of the one happening now. Find which formation is actually present, then fight it normally.**

Cantor/room diagnosis + preserved history + core lock-on combat.

Cantor is not an enemy-AI/future-attack scanner.

### S6 — Take It Off the Bell

> **These systems already know how to run without Meridian. Put them on their local controls, then shut the master relay off.**

Source-owned local service states + mandatory Common Measure + physical central-relay disconnection.

The relay stops; after a short readable pause, local systems continue at visibly different rhythms and open the route to Maelor.

`pattern.local_accord` remains optional.

## Critical-path protections

Mandatory Null Meridian progression must work with Story Minimum.

Forbidden mandatory gates:
- optional Cantor Patterns;
- optional Tool Mastery Upgrades;
- all six community projects;
- Freehand Frame;
- 100% completion;
- optional setup/payoff choices;
- new finale-only core verb.

Optional content may provide alternate/elegant routes, safer handling, extra evidence, richer acknowledgement, or credits specificity.

## Maelor / Listener

Maelor and Listener are outside the six.

Maelor remains a core-combat confrontation that escalates known systems rather than becoming six inventory locks.

Listener is not a third health-bar boss.

Final resolution is a player-performed decommission/release of Meridian's central heart; the ending is mechanically enacted, not merely selected in dialogue/cutscene.

## Scene-ledger precedence

Older `docs/story/07_SCENE_BEAT_LEDGER.md` Movement 16 shorthand is subordinate where it implies:

`paired trials -> Quiet Court -> immediately Maelor`.

Use `docs/134_NULL_MERIDIAN_SCENE_ORDER_PRECEDENCE_ADDENDUM.md`.

The broader scene ledger remains canonical for unaffected story beats.

## Runtime boundary

Still unverified:
- UE5.8 blockout;
- actual S1–S6 scripting;
- combat tuning;
- Hush transitions;
- Maelor boss runtime;
- Listener playable-state realization;
- save/reload;
- performance;
- accessibility implementation;
- Null Meridian System IDE;
- deterministic fixtures;
- human comprehension, pacing, emotional impact, and final-dungeon duration.

---

# NEXT PHASE — Documentation Closure Program

**Do not start broad UE5.8 implementation yet.**

Issues #9–#11 were intentionally the final design work before a comprehensive documentation closure pass.

The purpose is to make the repository safe for implementation by eliminating contradictory authority, hidden assumptions, ownership ambiguity, stale onboarding, and undocumented unknowns.

## Required closure outputs

At minimum create/reconcile:

1. **Canonical Authority Index**
   - every major system/content authority;
   - current status;
   - governing document;
   - implementation/runtime proof status.

2. **Supersession Graph**
   - explicit newer->older precedence;
   - reverted/closed historical work;
   - scoped conflict notes;
   - no agent should have to infer precedence from dates alone.

3. **Terminology / Glossary**
   - semantic terms such as Waking, Hush, Stillness, Stillring, Countertones, Motion, Memory, Ending, Common Measure, Local Accord, source fact, sequence settlement, etc.;
   - ban ambiguous synonyms where they would create implementation mistakes.

4. **System Ownership Map**
   - who owns each authoritative fact/state;
   - who may observe/consume it;
   - who may not duplicate it.

5. **Cross-System Contract Matrix**
   - locomotion/camera/combat/tools/Hush/save/world-state/setup-payoff/Skiff/completion/quest/Null Meridian interactions;
   - explicit boundary contracts and invalid ownership patterns.

6. **Unanswered-Question Register**
   - unknowns must be documented as unknowns;
   - distinguish tuning unknowns from architecture blockers;
   - identify owner review required vs runtime prototype required.

7. **Implementation-Readiness Gap Register**
   - what design exists but code/runtime does not;
   - dependencies/order;
   - vertical-slice proof targets;
   - no fake completion percentages.

8. **System IDE Coverage Matrix**
   - every major stateful/tuned system must have a shared in-game workbench/harness;
   - identify inspect/exercise/validate requirements;
   - confirm use of authoritative gameplay services, never a second hidden state model.

9. **Runtime Evidence Ledger**
   - design/documentation status vs actual UE5.8 evidence;
   - deterministic fixtures;
   - save/reload;
   - performance;
   - accessibility;
   - human-play acceptance.

10. **Content Traceability Matrix**
    - main story / region / quest / setup-payoff / completion / upgrades / trials / finale dependencies;
    - identify stale literals and content that no longer maps to canonical counts/IDs.

11. **Onboarding / Read-Order Path**
    - one safe entrypoint for future agents/engineers/writers;
    - no need to read every historical document to know current truth.

12. **Final Owner Review Package**
    - concise list of what is truly locked;
    - unresolved implementation/tuning decisions;
    - risks;
    - proposed UE5.8 implementation order;
    - explicit authorization boundary.

Only after the owner reviews that final closure package should broad UE5.8 implementation be authorized.

---

# Documentation Closure Program rules

- Do not rewrite history merely to make the repo look clean; preserve useful superseded records with explicit precedence.
- Prefer stable authority indexes/addenda over destructive mass edits unless a direct rewrite is clearly safer.
- Stale numeric literals that could cause implementation bugs must be called out explicitly.
- Unknowns are acceptable; undocumented unknowns are not.
- Every major system must identify its source of truth.
- Every persisted fact must have stable semantic identity or a documented migration plan.
- Every cross-system dependency must state directionality.
- Every design-complete claim must separately state runtime-proof status.
- Every System IDE/test harness must use the real gameplay services.
- Human play remains final authority for feel, clarity, pacing, puzzle readability, emotional impact, and whether the game is actually fun.

---

# Governing constraints

- Unreal Engine 5.8 target;
- C++ first; thin Blueprints;
- every major stateful/tuned system gets an in-game System IDE/workbench;
- no retail AI/API dependency;
- clean-room IP discipline;
- authored world over procedural duplication;
- puzzles/story remain central;
- no hidden morality meter;
- no ordinary traversal stamina tax;
- save/world facts use stable semantic IDs;
- accessibility accommodations do not invalidate canonical completion;
- human play is final authority for feel/readability/pacing/emotion.

**Build each system and its in-game IDE together when implementation is eventually authorized.**
