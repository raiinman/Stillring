# 190 — Production Dependency / Discipline Matrix

**Status:** ACTIVE / STUDIO-HANDOFF PRODUCTION AUTHORITY / DOCUMENTATION-ONLY  
**Updated:** 2026-09-06  
**Parent program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Gap register:** `docs/152_STUDIO_HANDOFF_GAP_REGISTER.md`  
**Acceptance checklist:** `docs/153_STUDIO_HANDOFF_ACCEPTANCE_CHECKLIST.md`  
**Decision rights:** `docs/170_STUDIO_DECISION_RIGHTS_MATRIX.md`  
**Product/platform boundary:** `docs/171_PERFORMANCE_PLATFORM_PRODUCT_BRIEF.md`  
**Technical production:** `docs/188_TECHNICAL_PRODUCTION_BIBLE.md`  
**Region/content production:** `docs/185_REGION_WORLD_CONTENT_PRODUCTION_MANIFEST.md`, `docs/186_DUNGEON_ENCOUNTER_AND_NETWORK_PRODUCTION_MANIFEST.md`  
**Boundary:** this file defines sequencing, dependency, ownership, review, outsourcing, and change-control logic. It does not authorize UE5.8 implementation, production staffing commitments, vendor selection, budget, schedule dates, runtime testing, or merge.

---

# 1. Purpose

Stillring now has strong discipline-specific production authority. A studio can understand art, animation, UI/UX, audio, narrative, world/content, and technical intent.

That is not enough by itself.

A full-production handoff also has to answer:

- what must happen before what;
- what may happen in parallel;
- which team owns each deliverable;
- which team consumes it;
- what evidence makes a handoff valid;
- what is unsafe to outsource before upstream authority exists;
- how integration/review time is protected;
- how a proposed departure is classified and approved;
- how changes propagate downstream without creating silent production drift.

The governing rule is:

> **No discipline may treat another discipline's unfinished assumption as its own permanent authority.**

A second rule is equally important:

> **Parallel work is allowed only where interfaces are stable enough that parallelism does not manufacture rework.**

This matrix is intentionally a production-control layer, not a staffing chart.

It does **not** invent:
- headcount;
- team size;
- vendor count;
- sprint length;
- milestone dates;
- dollar budgets;
- burn rate;
- outsourcing percentage.

Those require actual studio capacity, commercial constraints, and later implementation evidence.

---

# 2. Production dependency vocabulary

## 2.1 HARD BLOCKER

Downstream work cannot responsibly enter production because an upstream decision, representation, or evidence gate materially controls the deliverable.

Examples:
- final Hush environment mass production before Hush representation architecture is selected by Gate 4 evidence;
- platform certification work before launch-platform scope is selected;
- final performance budgets before target PC/platform and representative runtime evidence exist;
- VO recording before VO scope and recordable script state are locked.

A hard blocker does not prohibit low-cost research, concept exploration, or disposable tests if those are explicitly classified as such.

## 2.2 SOFT DEPENDENCY

Downstream work may begin with bounded assumptions, but the upstream item must close before final approval or broad production scale.

Examples:
- environment concept work can proceed before final module dimensions;
- animation planning can proceed before final locomotion tuning values;
- UI wireframes can proceed before final visual styling;
- audio asset family design can proceed before final runtime mix values.

Soft dependencies require the downstream package to record the assumption boundary so it can be revisited deliberately.

## 2.3 INTERFACE CONTRACT

Two disciplines may work in parallel because the repository already defines the boundary between them.

Examples:
- gameplay owns combat legality while animation owns presentation;
- Hush/World-Layer owns semantic layer while streaming/presentation realizes it;
- Quest/Story owns narrative progression while cinematics present it;
- source systems own durable facts while Completion derives completion state.

Interface contracts are the safest form of parallelization.

## 2.4 REVIEW DEPENDENCY

Work may be produced, but it cannot be accepted until another discipline validates the result.

Examples:
- enemy art needs gameplay-distance readability review;
- animation needs gameplay-state timing review;
- UI needs localization/accessibility stress review;
- audio needs critical-cue redundancy review;
- binary Unreal content later needs integration/load/reference evidence.

## 2.5 RUNTIME GATE

The downstream answer is intentionally held open until implementation, profiling, accessibility evaluation, or human play produces evidence.

A runtime gate is not a documentation failure when:
- the decision owner is explicit;
- the fixture/evidence path is explicit;
- downstream work knows which assumptions remain provisional.

## 2.6 OWNER / PRODUCT GATE

A genuine product or creative choice remains unresolved and cannot be made by production convenience.

Current known examples include:
- target-PC baseline;
- launch platforms beyond PC-first;
- VO scope;
- commercial title when public-release planning requires it;
- any material departure from locked product/game/story/art identity.

---

# 3. Discipline ownership model

Stillring uses **authority ownership**, not personality ownership.

A future studio may assign one person to several roles or many people to one role. This document defines responsibilities, not org-chart headcount.

| Discipline / production function | Primary production responsibility | Must consume | May not silently own |
|---|---|---|---|
| Product / Owner | product scope, owner gates, material creative/product changes | repository audits, runtime evidence, producer recommendations | ordinary implementation details or numeric tuning that belong to studio/runtime review |
| Production Management | dependency planning, milestone integration, risk, status, handoffs, vendor package health | all discipline manifests, decision rights, gap/audit state | gameplay canon, art direction, technical architecture by schedule convenience |
| Creative / Game Direction | cross-discipline player-experience coherence within locked authority | gameplay, story, art/audio/UI/animation outputs, human-play evidence | owner-gated product changes |
| Gameplay / Systems Engineering | authoritative gameplay/state implementation | docs 20–140, technical bible, relevant production manifests | art/animation/UI presentation authority or story canon |
| Technical / Core Engineering | project architecture, build, data plumbing, save, tooling, integration, profiling infrastructure | technical bible, ownership maps, runtime evidence ledger | gameplay semantics or platform/product commitments |
| Level / World Design | playable spatial/content assembly inside locked mechanics and region/story authority | locomotion/camera/tool/Hush rules, region manifests, narrative objectives | new traversal verbs, new completion categories, hidden state ownership |
| Narrative | final production writing/staging context inside canon | story canon, narrative package, world states, VO/localization boundaries | system facts, product scope, arbitrary cutscene state ownership |
| Cinematics | authored presentation of approved scenes | narrative scene manifest, animation, audio, gameplay/camera state contracts | quest/world-state truth through timeline side effects |
| Character Art | character execution and source assets | art bible, character manifests, animation rig needs, technical constraints | character canon or gameplay semantics |
| Environment / Prop Art | regional kits, hero assets, props, state variants | art/world manifests, level-design needs, Hush classes, technical constraints | traversal eligibility or persistent world facts |
| Technical Art | shaders/materials/VFX pipeline, rig support, optimization support, content validation | art bible, technical bible, runtime budgets when available | gameplay rules, Hush semantic truth, final product targets without evidence |
| Animation | movement/combat/tool/NPC/boss/cinematic performance | animation bible/manifest, gameplay timing/state, character rigs | gameplay legality or persistent state |
| VFX | player/world feedback and spectacle within visual grammar | art/VFX manifest, gameplay state events, accessibility redundancy | gameplay outcomes or single-channel critical information |
| Audio / Music | ambience, SFX, score, mix, VO production where authorized | audio bible/manifest, narrative, gameplay events, accessibility captions | gameplay state or final VO scope if owner-unresolved |
| UI/UX | player-facing information architecture and interaction | UI spec, source-system state, accessibility/localization | duplicate gameplay truth or hidden progression rules |
| Accessibility | cross-discipline accessibility requirements and review | gameplay, UI, art/VFX, audio, camera, narrative | product scope or gameplay semantics beyond approved accommodation rules |
| Localization | translation/localization production and linguistic QA | final/localizable text, context metadata, UI constraints, VO scope | canon changes or raw gameplay-state logic |
| QA | evidence planning, deterministic/runtime regression, content validation, bug reproduction | acceptance criteria, fixtures, System IDE, evidence taxonomy | subjective creative acceptance unless explicitly requested as evaluation input |
| Build / Release Engineering | reproducible builds, packaging, symbols/artifacts, release configuration | technical bible, platform scope, certification requirements | target platform/product scope |
| External Development / Vendor Management | onboarding, brief integrity, delivery tracking, feedback loop, integration readiness, offboarding/knowledge transfer | approved outsource package, owner/discipline contact, review criteria | canon, owner decisions, acceptance criteria by contract convenience |

---

# 4. Production phase / deliverable taxonomy

This taxonomy converts `docs/03_PRODUCTION_WORKFLOW.md` into discipline-facing production states.

It does not assign calendar dates.

## D0 — AUTHORITY / BRIEF READY

A deliverable is ready to be commissioned or scheduled when:
- authoritative source documents are named;
- semantic/content identity is known where applicable;
- required inputs are available or explicitly marked soft/runtime-gated;
- forbidden reinterpretations are explicit;
- decision rights are known;
- acceptance owner is named by discipline/function;
- expected output format/source package is defined;
- dependencies and downstream consumers are known.

A mood paragraph alone does not pass D0.

## D1 — EXPLORATION / TEST

Purpose:
- compare approaches cheaply;
- test shape, workflow, representation, or feasibility;
- resolve bounded production questions.

D1 output is not automatically production reusable.

Every D1 artifact must identify:
- hypothesis;
- what is disposable;
- what would be required for promotion;
- which runtime/owner gate it informs.

## D2 — PROTOTYPE-ACCEPTED

The approach is valid enough to support a scoped playable/system prototype.

D2 does not mean:
- final art;
- final animation;
- final performance;
- production-scale authoring safety.

## D3 — VERTICAL-SLICE QUALITY

Representative work reaches intended cross-discipline quality far enough to test:
- integration;
- production cost;
- readability;
- authoring workflow;
- technical viability;
- acceptance/review loop.

Vertical-slice quality is not permission to mass-produce every region if a major production architecture is still unresolved.

## D4 — FIRST-PRODUCTION / PIPELINE LOCK

A reusable production pattern is accepted for scale.

Required qualities vary by discipline but generally include:
- source package convention stable;
- integration workflow stable;
- validation/review path stable;
- representative performance/readability evidence where relevant;
- rework risks understood;
- outsource/onboarding package proven if external production will use it.

## D5 — PRODUCTION-COMPLETE DELIVERABLE

The scoped asset/system/content is complete against current authority and accepted by its required reviewers.

This does not mean the game is Alpha.

## D6 — ALPHA-INTEGRATED

Feature/content exists in the playable start-to-finish build where applicable.

At Alpha:
- core feature/content burden is present;
- known polish/balance/content-quality debt may remain;
- missing foundational systems are not acceptable.

## D7 — BETA / CONTENT-LOCKED

Content is substantially complete.

Allowed work is primarily:
- bugs;
- performance;
- balance;
- accessibility;
- localization;
- polish;
- compatibility;
- content correction rather than feature expansion.

## D8 — RELEASE-CANDIDATE ACCEPTED

The build/package could ship unchanged if no blocker is found.

Requires later evidence for:
- fresh install/build reproducibility;
- platform scope/certification as applicable;
- save/recovery;
- final performance;
- credits/licenses;
- development-tool exclusion;
- release artifact archival.

---

# 5. Dependency classes by major workstream

| Workstream | May begin from written authority | Hard blockers before broad production | Soft dependencies / parallel work | Final acceptance dependencies |
|---|---|---|---|---|
| Gameplay/Locomotion/Camera | after owner implementation authorization | no `.uproject`/Gate 1 bootstrap; implementation authorization | animation exploration, UI wireframes, graybox course planning | deterministic fixtures + human feel/readability |
| Combat/Encounter | design/animation concept planning now | Gate 1 runtime foundation before real implementation | enemy art/animation family exploration | combat/encounter fixtures + camera/readability + human play |
| Tools/Puzzles | mechanism/content planning now | Gate 1/2 runtime patterns before scalable implementation | prop/mechanism concept, audio/VFX grammar | tool IDE, mechanism reset/validation, human comprehension |
| Hush | visual/content classification and paired-state planning now | **production representation selection before mass paired-content production** | concept art, semantic IDs, H0–H4 state planning, audio/UI grammar | Gate 4 comparison + save/continuity/performance evidence |
| Save/World State | schema/data planning now | real runtime owners + paired Hush state before Issue #4 closure | fixture definitions, migration tables | process exit/reload, restore ordering, corruption/migration proof |
| Completion | semantic taxonomy and authoring planning now | reconciled item registry before full implementation/content audit | UI, content-location planning, late-assist writing | exact registry/weight/migration fixtures + full roster reconciliation |
| Setup/Payoff | all 12 content packages may be planned | source-system/runtime foundation before live chain evaluation | narrative/art/world variants | S01 vertical-slice materiality + save/reload + all-chain fixtures |
| Line Skiff | route/world planning now | ordinary locomotion/camera + route representation + streaming evidence before broad network production | route concept, infrastructure art, Drift Knot planning | representative route + Trial 05 + Hush/save/perf/human-play |
| Null Meridian | complete written/asset burden planning now | prerequisite gameplay systems and Hush architecture before blockout production | concept, script, score/theme planning | S1–S6 fixtures + Maelor + save/retry + pacing/human play |
| Character Art | source concepts/production sheets may proceed | final rig/scale implications before irreversible final deformation/topology standards | costume, material, face, C3 planning | animation/tech-art deformation + gameplay/readability + art review |
| Environment Art | concept/kit planning may proceed | tested metric conversion before final module standard; Hush representation before mass paired variants | prop kits, material studies, ordinary-state asset production | level design, tech art, readability, performance evidence |
| Animation | manifest scheduling and tests may proceed | rig/skeleton production standard before mass clips; runtime gameplay timing before final feel-sensitive clips | cinematic blocking, NPC ambient prototyping | gameplay-state validation, deformation, human feel |
| UI/UX | wireframes, component architecture, asset families may proceed | no hard blocker for written production | localization/accessibility stress, source-system adapters | controller+KBM parity, runtime state accuracy, localization/accessibility review |
| Audio/Music | ambience/SFX/score development may proceed | **VO recording blocked by VO-scope owner decision + recordable script lock** | score sketches, SFX design, ambience, pronunciation planning | mix/readability, captions, runtime adaptive-state proof |
| Narrative | final writing may proceed from canon | recordable VO script depends on VO model/recording lock | localization context, cinematic staging | continuity/canon review, implementation context, localization/VO lock |
| Localization | pipeline design/pseudo-localization may proceed | final language staffing blocked by product language scope; translation blocked by sufficiently locked source text | terminology/glossary/context prep | linguistic QA + UI/audio/caption integration |
| QA | test design/fixture inventories may proceed now | runtime execution requires executable build | automation naming, content validation plans | evidence per gate; does not replace human subjective acceptance |
| Platform/Certification | research may proceed | **launch-platform owner decision** | PC-first packaging planning | platform-specific certification/runtime evidence |
| Performance | measurement architecture planning may proceed | **target-PC/product context + representative runtime content** for final budgets | instrumentation, representative-scene planning | measured budgets and acceptance on declared hardware |

---

# 6. Core critical-path dependency graph

The production critical path is not one giant waterfall, but several downstream systems depend on common foundations.

```text
DOCUMENTATION HANDOFF CLOSURE
        |
        v
OWNER IMPLEMENTATION AUTHORIZATION
        |
        v
GATE 1 BOOTSTRAP + SHARED SYSTEM IDE PATTERN
        |
        +-------------------------+
        |                         |
        v                         v
LOCOMOTION/CAMERA RUNTIME     BUILD / DATA / FIXTURE FOUNDATION
        |
        v
COMBAT / ENCOUNTER
        |
        v
TOOLS / MECHANISMS
        |
        v
HUSH REPRESENTATION COMPARISON  <---- paired semantic content/art planning in parallel
        |
        +-------------------------+
        |                         |
        v                         v
SAVE/WORLD PROOF             REGION PIPELINE LOCK
        |                         |
        +------------+------------+
                     |
                     v
            FIRST CROSS-SYSTEM SLICE
                     |
        +------------+-------------+----------------+
        |                          |                |
        v                          v                v
COMPLETION/CONTENT PIPELINE   LINE SKIFF        REGION POD SCALE
        |                          |                |
        +-------------+------------+----------------+
                      |
                      v
                 NULL MERIDIAN
                      |
                      v
                 ALPHA -> BETA -> RC
```

This graph does **not** mean art/audio/narrative/UI sit idle until engineering reaches them.

They proceed in parallel where their interface is already stable, but broad irreversible production is gated where representation/metrics/runtime truth materially controls the output.

---

# 7. Region-pod ownership model

Stillring should scale content as integrated **region pods**, consistent with `docs/03` and `docs/185`.

A region pod is a production container, not a separate architecture.

Each region pod includes the relevant combination of:
- level/world design;
- environment/prop art;
- population/character support;
- enemies/encounters;
- dungeon/hero space;
- tool/mechanism use;
- contracts and Setup/Payoff;
- optional completion content;
- Hush/state variants where authored;
- narrative/dialogue;
- cinematics where classified;
- ambience/music;
- VFX;
- UI/map data;
- save/checkpoint/world facts;
- System IDE fixtures;
- accessibility/localization/QA coverage;
- performance review.

## 7.1 Pod lead responsibility

The future production organization must assign one accountable **region-pod production owner** per active pod.

This is a coordination role, not canon ownership.

The pod owner is responsible for:
- dependency health;
- deliverable status;
- integration order;
- cross-discipline review scheduling;
- risk escalation;
- ensuring reused systems/assets are not forked locally;
- ensuring region-specific work does not become hidden global architecture.

## 7.2 Shared-system ownership outranks pod convenience

A region pod may not create private forks of:
- locomotion;
- camera;
- combat;
- Cantor/tools;
- Hush semantics;
- Save Coordinator;
- Completion Ledger;
- Setup/Payoff evaluator;
- Line Skiff route grammar;
- UI shell;
- System IDE architecture.

Region-specific content uses shared systems through their contracts.

If a region genuinely requires a new systemic capability, it enters change control rather than being hidden in local Blueprint/content logic.

## 7.3 Recommended production scaling order

After the appropriate runtime/pipeline gates, scale through representative pods rather than all-region shotgun production.

The first cross-system slice remains the repository-authorized Brindle/S01-oriented proof path, with other region work proceeding at safe concept/production-definition levels.

Later pod order may be scheduled by the production studio based on staffing and dependency readiness **without changing canonical story progression**.

Production schedule order and player story order are not automatically the same thing.

---

# 8. Shared-system versus content-pod parallelization

## Safe parallelization examples

- narrative can draft final dialogue while UI builds journal architecture, provided both consume semantic scene/state IDs;
- environment art can build ordinary-state regional kits while Hush representation remains runtime-gated, provided paired/Hush-specific irreversible assets are not mass-produced;
- character art and animation rig tests can proceed together under a shared rig acceptance packet;
- audio can build regional ambience and SFX families while adaptive runtime implementation is still absent;
- QA can author semantic fixture matrices before runtime exists;
- localization can build glossary/context standards and pseudo-localization tests before final language staffing;
- UI asset production can proceed while source systems remain unimplemented if every displayed value has a declared future source owner and placeholder data is clearly noncanonical.

## Unsafe parallelization examples

- mass-producing Hush duplicate maps before Gate 4 representation selection;
- recording thousands of lines before script/VO scope lock;
- finalizing modular metrics from guessed Neris/camera scale;
- commissioning every Drift Knot as a bespoke racetrack before the route runtime proves supported corridors and streaming;
- finalizing platform-specific UI/certification packages before platform scope selection;
- outsourcing gameplay feature implementation where the package does not include ownership contracts/System IDE requirements;
- shipping region-specific Blueprint state machines because shared systems are not ready yet.

---

# 9. Deliverable dependency packet

Every production deliverable that crosses discipline boundaries must carry a minimum dependency packet.

Required fields:

1. **Deliverable ID** — stable production identifier.
2. **Player-facing / production purpose** — why it exists.
3. **Authority sources** — exact repository files/semantic IDs.
4. **Decision class** — LOCKED / DERIVED / STUDIO CHOICE / RUNTIME-GATED / TBD OWNER / PROHIBITED as applicable.
5. **Upstream inputs** — what must exist first.
6. **Downstream consumers** — who depends on it.
7. **Assumption ledger** — any provisional assumption and its closure gate.
8. **Output/source package** — expected files/artifacts/source data.
9. **Integration owner** — role/function accountable for integrating the result.
10. **Reviewers** — discipline reviews required before acceptance.
11. **Acceptance state** — D0–D8 as applicable.
12. **Known variants** — Waking/Hush/state/platform/localization/LOD etc. where relevant.
13. **Runtime evidence dependency** — if final approval needs later proof.
14. **Change propagation list** — known consumers that must be notified/revalidated after material change.
15. **Provenance / rights** — source ownership, license/reference/clean-room status where relevant.

A handoff packet missing authority or integration ownership is not ready for external production.

---

# 10. Outsourcing / co-development package classes

External production is allowed only where the package can be bounded without hidden owner intent.

## O0 — NOT OUTSOURCE-READY

Do not commission production work yet.

Triggers:
- material owner decision unresolved;
- upstream architecture materially controls deliverable and is not selected;
- acceptance criteria missing;
- semantic/content identity ambiguous;
- source package absent;
- no internal integration/review owner.

## O1 — EXPLORATION / TEST PACKAGE

Suitable for:
- concept exploration;
- art tests;
- rig tests;
- pipeline tests;
- audio test assets;
- technical spikes;
- partner evaluation.

Must be labeled non-production unless promoted after review.

## O2 — EXECUTION PACKAGE

Suitable when:
- authority and asset brief are stable;
- reusable/unique classification is known;
- technical/source format is known;
- feedback owner exists;
- acceptance criteria are explicit;
- downstream integration path is known.

Examples may include:
- regional prop families;
- bounded environment-kit components;
- named C3 character execution;
- approved animation families after rig standard;
- sound asset families;
- UI icon/glyph families;
- localization once source text/language scope is ready.

## O3 — CO-DEVELOPMENT FEATURE PACKAGE

A partner may own bounded implementation/execution responsibility when:
- system ownership boundaries are explicit;
- source repo/access/onboarding is sufficient;
- System IDE/fixture requirements are included;
- internal design/technical acceptance owners remain explicit;
- partner work uses project architecture rather than creating a parallel framework.

External ownership means responsibility for delivery, not authority to redefine canon.

## O4 — PLATFORM / RELEASE PACKAGE

Porting/certification/external QA packages require selected platform/product scope and appropriate runtime baseline.

Until then, only exploratory capability research is appropriate.

---

# 11. Outsourcing package minimums

Every external package must include:

- one internal accountable owner;
- one external accountable delivery owner;
- exact authority/brief bundle;
- deliverable list and acceptance state;
- technical/source specifications;
- repository/source-control workflow where applicable;
- file naming/package rules;
- rights/IP/reference restrictions;
- sample/reference deliverable where useful;
- review cadence/feedback channel;
- response expectation for blocked questions;
- integration window before the internal milestone;
- change-notification procedure;
- rejection/rework categories;
- offboarding/knowledge-transfer requirement;
- final source-file return requirement;
- dependency assumptions.

## 11.1 Integration buffer rule

An external delivery date is **not** the same as internal acceptance date.

Production scheduling must reserve time for:
- source/package validation;
- import/integration;
- technical review;
- creative review;
- revision;
- runtime verification where applicable.

A vendor drop immediately before the dependent internal milestone is a planning failure, not a successful on-time handoff.

## 11.2 Feedback authority rule

External teams must not receive contradictory unranked feedback from multiple internal voices.

Each package needs:
- one consolidated feedback owner;
- named specialist reviewers;
- a mechanism for resolving conflicting specialist feedback against repository authority.

## 11.3 Question escalation rule

If a partner discovers missing authority:

```text
partner question
  -> package owner classifies
      -> existing authority answers it; OR
      -> studio-choice decision recorded; OR
      -> runtime gate recorded; OR
      -> owner/product escalation
```

The partner is not expected to invent the missing answer to keep schedule green.

---

# 12. Change-control process

Every proposed material departure follows this path.

## Step 1 — identify the proposed change

Record:
- current authority;
- proposed departure;
- reason;
- affected deliverables/systems;
- urgency;
- whether a workaround exists inside current bounds.

## Step 2 — classify decision rights

Use `docs/170`:
- LOCKED/CANONICAL;
- DERIVED;
- STUDIO CHOICE WITHIN BOUNDS;
- RUNTIME-GATED;
- TBD OWNER;
- PROHIBITED.

## Step 3 — determine impact radius

At minimum check:
- player-facing behavior;
- story/canon;
- semantic IDs/persistence;
- save migration;
- completion;
- UI;
- animation;
- audio;
- art/VFX;
- level/world content;
- localization;
- accessibility;
- QA fixtures;
- platform/performance;
- outsourcing packages already in flight.

## Step 4 — choose approval path

### Studio choice within bounds

Technical/discipline lead may approve according to studio process.

Must still be documented when it changes shared convention or downstream assumptions.

### Runtime-gated selection

Prototype and evidence are required.

Do not convert the hypothesis into production authority until the acceptance gate is completed and repository authority is updated.

### Locked-authority departure

Requires coordinated authority update; material game/story/art/product changes require owner review.

### TBD owner

Owner/product decision required before dependent commitment.

### Prohibited

Reject unless a higher-authority change explicitly removes the prohibition.

## Step 5 — update authority before downstream dependence

A durable approved change must update:
- governing repository authority;
- decision register where project-significant;
- affected manifests/matrices;
- fixtures/test assumptions;
- vendor packages in flight;
- migration/compatibility notes where relevant.

Chat approval without repository update is not sufficient production authority.

## Step 6 — downstream revalidation

The change owner must explicitly list which accepted deliverables need:
- no action;
- documentation refresh;
- re-review;
- re-export/rebuild;
- migration;
- runtime regression;
- human-play review.

A change is not operationally closed merely because its originating file was edited.

---

# 13. Change severity classes

## C0 — LOCAL / NON-SEMANTIC

Examples:
- internal naming cleanup;
- source-file organization that does not change paths required by runtime assets;
- minor asset polish inside approved brief.

Approval:
- discipline/studio process.

## C1 — SHARED PRODUCTION INTERFACE

Examples:
- naming convention;
- asset export requirement;
- rig control interface;
- data schema field used by several systems;
- UI component contract.

Approval:
- relevant technical/discipline leads;
- notify downstream owners;
- migration/update plan if already consumed.

## C2 — RUNTIME / PLAYER-FACING WITHIN LOCKED DESIGN

Examples:
- selected Hush representation after required evidence;
- tuned locomotion value;
- camera tuning;
- animation displacement technique with player-facing consequences.

Approval:
- required runtime/human evidence + appropriate design/technical review.

## C3 — CANON / PRODUCT / SCOPE MATERIAL CHANGE

Examples:
- platform scope;
- major mechanic identity;
- story canon;
- completion model;
- region identity;
- VO scope;
- large content-scope cut/add that changes locked experience.

Approval:
- owner/product authority.

## C4 — PROHIBITED / SAFETY / IP VIOLATION

Examples:
- copied protected game assets/expression;
- AI/API dependency in retail contrary to authority;
- secret duplicate gameplay truth;
- shipping developer control surfaces;
- actor/package paths replacing required semantic persistence identity.

Action:
- reject and remediate.

---

# 14. Cross-discipline approval matrix

`A` = accountable acceptance function  
`R` = required specialist review  
`C` = consulted when affected  
`E` = evidence required later/runtime  

This is a responsibility model, not a staffing chart.

| Deliverable | Product/Creative | Production | Design/Gameplay | Tech | Art/Tech Art | Animation | Narrative/Cinematics | Audio | UI/UX | QA/Access/Loc |
|---|---|---|---|---|---|---|---|---|---|---|
| Core gameplay system | C | C | A | R | C | C | C | C | C | E/R |
| Save/world-state system | C | C | R | A | C | C | C | C | C | E/R |
| Hush representation selection | C | C | R | A | R | C | C | R | C | E/R |
| Character production standard | C/A for identity | C | C | R | A | R | C | C | C | R |
| Environment modular standard | C | C | R | R | A | C | C | C | C | R |
| Animation rig/retarget standard | C | C | R | R | R | A | C | C | C | R |
| UI retail screen/component | C | C | C | R | R | C | C | C | A | R |
| Audio regional identity/cue family | C | C | C | C | C | C | R | A | C | R |
| Narrative scene/script | C/A where canon-sensitive | C | C | C | C | C | A | C | C | R |
| Region pod | C | A coordination | R | R | R | R | R | R | R | R |
| External package | C if creative-critical | A package health | R as applicable | R as applicable | R as applicable | R as applicable | R as applicable | R as applicable | R as applicable | R as applicable |
| Performance budget promotion | C/Product confirmation | C | C | A | R | R | C | R | C | E/R |
| Platform certification package | A product scope | C | C | A technical | C | C | C | C | R | R |

No cell grants authority beyond the decision classes in `docs/170`.

---

# 15. Integration ownership rules

## 15.1 Every binary/content deliverable needs an integrator

The creator of an asset is not automatically the person responsible for proving it works in Stillring.

Each package must identify an integration owner responsible for:
- correct source package;
- import/reference health;
- naming/path compliance;
- dependency resolution;
- build/load validation later;
- acceptance evidence;
- rollback/recovery if integration fails.

## 15.2 Integration is part of the estimate

Production estimates must include:
- review;
- feedback;
- integration;
- revisions;
- validation;
- documentation/source return.

Raw creation time alone is not a complete production estimate.

## 15.3 First-of-family rule

Before a high-volume asset/content family scales, complete and accept at least one representative **first-of-family** package through its entire path:

```text
brief -> source -> delivery -> integration -> review -> revision -> acceptance -> provenance
```

Examples:
- first C3 regional character;
- first modular regional building kit;
- first ordinary enemy family;
- first boss package of each materially different class where workflow differs;
- first UI screen family;
- first localized journal/record stress fixture;
- first outsourced animation family;
- first region-pod Setup/Payoff implementation later;
- first Hush paired-space implementation after architecture selection.

Mass production before the first-of-family loop closes is production risk accepted without evidence.

---

# 16. Dependency freeze / assumption management

A dependency is not considered stable just because a meeting ended.

Every shared production assumption should be in one of four states:

1. **LOCKED** — repository-backed and safe to consume.
2. **PROVISIONAL / SOFT** — work may continue but must record the assumption.
3. **RUNTIME-GATED** — work may prepare, but irreversible downstream commitment waits for evidence.
4. **BLOCKED** — downstream production may not proceed beyond exploration.

Production tracking should expose these states visibly.

A team must not silently convert `PROVISIONAL` into `LOCKED` because work has already started.

---

# 17. Workstream-specific handoff gates

## 17.1 Art -> Animation

Animation mass production requires:
- approved character identity/source model direction;
- skeleton/rig/retarget standard;
- deformation-critical costume/prop decisions;
- scale reference sufficient for animation tests.

Art may continue material/texture/polish work in parallel after deformation interfaces stabilize.

## 17.2 Gameplay -> Animation

Animation consumes:
- semantic action states;
- timing ownership;
- displacement/root-motion boundaries;
- interaction contact intent.

Animation does not wait for final numeric tuning to inventory/workflow-test most families, but final feel-sensitive clips require runtime review.

## 17.3 Gameplay/World -> UI

UI needs:
- source owner for every displayed state;
- reason codes where failure/explanation exists;
- spoiler/disclosure policy;
- input-action identity.

UI may prototype against fixture data; fixture data must not become shadow gameplay truth.

## 17.4 Narrative -> VO

VO recording requires:
- VO scope selected;
- line classified recordable;
- speaker/context/intent known;
- pronunciation/context notes;
- branch/state variants enumerated;
- localization/caption impact considered;
- change-lock policy appropriate to recording cost.

## 17.5 Narrative -> Cinematics

Cinematics require:
- canonical scene identity;
- delivery classification;
- required interactivity boundary;
- semantic state entry/exit contract;
- character/prop/location burden;
- interruption/skip behavior requirements where applicable.

## 17.6 Environment -> Level Design

Environment production requires:
- region construction/shape language;
- reusable-vs-unique class;
- gameplay readability constraints;
- blockout interface where final metrics matter.

Level design should not wait for finished art to establish playable structure.

## 17.7 Hush Semantics -> Hush Content

Hush content may classify/design relationships now.

Broad paired-content implementation waits for production representation selection.

No team may make Data Layer existence itself the semantic content contract.

## 17.8 Technical -> All Content

Before mass Unreal content production later, technical production must provide:
- stable project/package conventions;
- semantic-ID/validation pattern;
- binary/LFS workflow;
- build/load validation path;
- asset-reference policy;
- source data/import rules where applicable;
- development-tool stripping boundary.

This written authority now exists; runtime tooling still requires implementation authorization and proof.

## 17.9 QA -> Production Acceptance

QA participates before Beta through:
- fixture design;
- acceptance-route design;
- validation coverage;
- reproduction standards;
- evidence package review.

QA is not a late department that receives the whole game after production finishes.

---

# 18. Production risk classes

Track risks by impact and dependency radius rather than anxiety.

## R1 — LOCAL DELIVERY

Contained to one deliverable/family.

## R2 — SHARED PIPELINE

Can rework a discipline or asset family.

Examples:
- rig standard failure;
- package/import convention failure;
- localization-hostile UI component.

## R3 — CROSS-SYSTEM / REGION

Can rework several disciplines or a region pod.

Examples:
- Hush paired-space representation failure;
- route streaming failure;
- save-state ownership mismatch.

## R4 — PROJECT / PRODUCT

Can alter broad scope, schedule, commercial plan, or shipped experience.

Examples:
- target platform change;
- target hardware impossible at intended quality;
- major canon/feature scope revision;
- content production rate incompatible with 20–30 hour target.

R3/R4 risks require explicit producer visibility and named mitigation/decision gates.

---

# 19. Production status reporting minimum

For each major workstream/region/external package, production should be able to report:

- current D-state (D0–D8);
- current dependency state (LOCKED / PROVISIONAL / RUNTIME-GATED / BLOCKED);
- upstream blocker owner;
- next acceptance event;
- in-review deliverables;
- rejected/rework items;
- external package health where applicable;
- open change requests;
- downstream teams affected by a delay/change;
- evidence still required;
- owner/product decisions waiting;
- runtime gates waiting.

Do not report `90% done` without identifying what definition of done the percentage refers to.

---

# 20. Production management anti-patterns — reject

Reject a production plan that:

- schedules mass Hush content before representation evidence;
- treats art delivery as done before integration/review;
- begins VO recording without a defined VO model and recordable script state;
- treats QA/accessibility/localization as post-content cleanup;
- lets every region invent local versions of shared systems;
- gives external teams a giant repository dump without a bounded authority/acceptance package;
- assigns multiple independent feedback owners to one vendor package;
- counts a vendor delivery date as the same thing as integrated acceptance;
- builds all regions simultaneously before representative family/pod workflows are proven;
- hides unresolved assumptions because work is already underway;
- uses milestone pressure to downgrade LOCKED authority into studio choice;
- introduces new feature scope during Beta without explicit approved exception;
- uses chat, meeting memory, or private spreadsheets as the only record of a material production decision;
- presents staffing/headcount/budget numbers as canonical without actual studio capacity/commercial input;
- labels a runtime-gated decision `PASS` simply because documentation is detailed.

---

# 21. Outsource-safe package examples under current documentation boundary

The following are examples of packages that can become outsource-safe **after ordinary commercial/vendor setup and the named upstream dependencies**, not authorization to commission them now.

## Generally strong candidates after first-of-family approval

- bounded regional prop families;
- environment modular components inside an approved kit;
- selected C3 character execution from approved production sheets;
- animation families after rig/retarget standard and gameplay contacts are established;
- selected VFX families after state/event and accessibility rules are locked;
- audio asset families under the Audio Bible;
- UI icon/glyph families under the UI asset manifest;
- localization after language scope/source-text readiness;
- bounded QA/content-validation packages after runtime fixtures exist.

## Requires stronger integration / co-dev relationship

- gameplay feature engineering;
- Save/World State;
- Hush runtime representation;
- Line Skiff runtime/network traversal;
- System IDE modules;
- region pod assembly;
- cinematics with substantial gameplay-state interaction;
- Null Meridian implementation.

## Not safe to outsource as an authority problem

- resolving owner product decisions;
- redefining story canon;
- inventing missing completion identities;
- deciding target platform/hardware by vendor convenience;
- choosing Hush semantics;
- deciding which locked mechanics to remove because a schedule is tight.

---

# 22. Current explicit project gates that production must track

| Gate | Class | Current state | Blocks |
|---|---|---|---|
| Broad UE5.8 implementation authorization | OWNER | not authorized under current boundary | executable production work |
| VO scope | OWNER | TBD | casting/recording/final VO budget |
| Launch platforms beyond PC | OWNER | TBD | platform-specific UI/save/certification/porting commitments |
| Target-PC baseline | OWNER | TBD before objective performance acceptance | final performance budget/acceptance |
| Commercial title | OWNER / CLEARANCE | later | public branding/store/legal finalization |
| Hush representation | RUNTIME | Gate 4 comparative proof required | mass paired-content implementation |
| Final module/world metrics | RUNTIME | representative Neris/camera/traversal proof required | irreversible modular scale standard |
| Final gameplay/camera/combat/Skiff feel | RUNTIME/HUMAN | respective prototype/play gates | final tuning acceptance |
| Final performance budgets | RUNTIME/PRODUCT | target hardware + representative profiling | final optimization acceptance |
| `CONTENT-ROSTER-RECONCILIATION-001` | DOCUMENTATION / CONTENT AUTHORITY | open | final item-level 36 Fault / 18 Shard / 24 Vault regional traceability |

---

# 23. Research basis

Current external-development production practice reviewed for this package includes:

- External Development Summit (XDS) 2026 Insights: distributed/external development increasingly depends on coordination/governance and reports communication as the leading challenge;
- XDS 2025 studio-ready external-development sessions emphasizing explicit onboarding requirements, roles, milestone alignment, production workflows, feedback cycles, risk management, and clean offboarding/knowledge transfer;
- longstanding external-production guidance that vendor milestone dates must leave realistic integration/review time before internal milestones.

These sources inform production-control mechanics only.

Stillring's authority, content, systems, approval boundaries, and production sequence remain project-specific and repository-controlled.

---

# 24. Decision rights

## LOCKED

- dependencies do not transfer semantic ownership;
- region pods may not fork shared-system authority;
- integration/review are part of production completion;
- external delivery is not internal acceptance;
- one consolidated feedback owner per external package;
- material decisions must be repository-backed;
- runtime-gated answers remain runtime-gated until evidence exists;
- owner decisions remain owner decisions;
- no fake headcount/budget/schedule authority;
- no production pressure may silently redefine locked game/story/art/product authority.

## STUDIO CHOICE WITHIN BOUNDS

- project-management software;
- board/list/status implementation;
- sprint/cadence model;
- exact internal role titles;
- exact pod staffing composition;
- which competent partner/vendor is selected after commercial evaluation;
- detailed calendar scheduling inside dependency rules;
- internal review-meeting cadence;
- packaging of multiple compatible deliverables into one commercial statement of work.

## RUNTIME-GATED

- exact production throughput assumptions derived from actual first-of-family/vertical-slice data;
- final performance/optimization planning numbers;
- Hush production representation consequences;
- actual integration cost of Unreal binary/content families;
- final content-pod velocity.

## OWNER / PRODUCT

- material product/platform/scope changes;
- target PC;
- launch platforms;
- VO scope;
- commercial title/public identity;
- any change that materially rewrites locked creative/game authority.

---

# 25. Hard-pass acceptance criteria

This matrix is considered production-management complete at written-handoff level only if an external producer can answer, from repository authority:

1. Which work may begin now at documentation/pre-production level?
2. Which work is hard-blocked before runtime or owner decisions?
3. Which disciplines may safely proceed in parallel?
4. What does `done` mean at prototype, vertical-slice, first-production, production-complete, Alpha, Beta and RC levels?
5. Who owns coordination versus semantic authority?
6. How are region pods prevented from becoming private forks of the game?
7. What must every cross-discipline deliverable packet contain?
8. What makes an outsource package ready or not ready?
9. Who consolidates vendor feedback?
10. Where is integration/review time represented?
11. How does a partner escalate missing authority without inventing it?
12. What change classes exist and who approves each?
13. How are downstream consumers revalidated after change?
14. What current owner/runtime/documentation gates remain open?
15. Which things may never be converted into schedule-driven assumptions?

If any of those answers depends on chat history or producer intuition rather than this repository, the package fails.

---

# 26. Boundary

This document does not authorize:

- implementation;
- staffing;
- hiring;
- outsourcing contracts;
- vendor access;
- budgets;
- production schedules;
- UE5 asset creation;
- testing;
- profiling;
- platform commitments;
- VO recording;
- merge.

It defines how those activities must be coordinated once separately authorized.
