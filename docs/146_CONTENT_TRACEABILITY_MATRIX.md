# 146 — Content Traceability Matrix

**Status:** DOCUMENTATION CLOSURE PHASE 3 — CURRENT  
**Updated:** 2026-09-05  
**Baseline main:** `22b4074e3d08358b302fd7a518773803f303990f`

## Purpose

This matrix connects player-facing content to current systemic authority so production does not inherit old counts, scene order, state ownership, or implementation assumptions by accident.

It is a traceability/navigation layer, not a replacement for the detailed source files.

Core rule:

> **Content may be authored in many files, but every gameplay consequence must still resolve through the current authoritative system owner.**

---

# 1. Main story / regional traceability

| Content area | Canonical narrative source | Primary gameplay/system dependencies | Persistence/derived consumers | Key precedence notes |
|---|---|---|---|---|
| Opening / core premise | `docs/02_STORY_BIBLE.md`, `docs/story/01_*` | Quest/Story, locomotion, camera, interaction | Save/World State, objective UI | Later scoped system authority controls mechanics, not old story shorthand |
| Cairnspire / First Circuit | `docs/story/02_ACT_ONE_WAYBELLS.md`, `docs/story/regions/02_CAIRNSPIRE.md` | Quest/Story, regional world facts, NPC recurrence, Setup/Payoff seeds | Save, Completion, later recurrence | Setup/Payoff commit/resolution uses docs 112–119, not scene-path scripting |
| Rootmere | `docs/story/regions/03_ROOTMERE.md` | Quest/Story, tools, world mechanisms, Setup/Payoff | Save, Completion | S04/S07-style authored consequences must preserve their current locked definitions |
| Saltreach | `docs/story/regions/04_SALTREACH.md` | Quest/Story, world mechanisms, Setup/Payoff, later Skiff routes | Save, Completion | Route/state facts remain semantic; no map-coordinate persistence |
| Emberstep | `docs/story/regions/05_EMBERSTEP.md` | Quest/Story, tool/mechanism state, Setup/Payoff | Save, Completion | S08/S09-era provenance/redundancy questions follow docs 115–119 |
| High Aerie | `docs/story/regions/06_HIGH_AERIE.md` | Quest/Story, Hush/world state, Setup/Payoff, records | Save, Completion | S10 is distributed agency/knowledge, not simply duplicate-record survival |
| Mireglass | regional story authority under `docs/story/regions/` | Quest/Story, Hush/tool content, Setup/Payoff | Save, Completion | Current Setup/Payoff portfolio allocation is controlled by doc 115 |
| Cairnfall | `docs/story/regions/08_CAIRNFALL.md` | Quest/Story, epistemic world state, Setup/Payoff | Save, Completion | S12 concept remains known-error/truth tension; do not reduce to a generic calibration puzzle |
| Hush Cairnspire / Null Meridian | `docs/story/regions/09_HUSH_CAIRNSPIRE_AND_NULL_MERIDIAN.md`, docs 127–134 | all major gameplay systems | Save, Completion, ending/credits consequences | Exact Null Meridian scene/mechanical order is controlled by doc 134 |

---

# 2. Main story scene / objective traceability

| Layer | Current source | System owner | Implementation rule |
|---|---|---|---|
| Scene order | `docs/story/07_SCENE_BEAT_LEDGER.md` | Quest/Story | Scene order may present semantic prerequisites but must not become the only state authority |
| Reveal/foreshadow | `docs/story/08_REVEAL_AND_FORESHADOW_LEDGER.md` | Quest/Story + NPC/Record consumers | Do not let debug/objective state reveal future outcomes early |
| Main objectives | `docs/story/09_MAIN_QUEST_OBJECTIVE_FLOW.md` | Quest/Story | Objective text is presentation of semantic state, not a private alternate truth |
| World pulse/offscreen change | `docs/story/12_WORLD_PULSE_LEDGER.md` | World State for durable facts; Story requests transitions | Offscreen presentation may derive from durable facts; save owns no separate duplicate copy |
| Emotional pacing | `docs/story/13_EMOTIONAL_PACING_MAP.md` | content direction only | Requires human-play proof; not a runtime state owner |
| OoT principle compliance | `docs/story/15_OOT_PRINCIPLE_COMPLIANCE.md` | design reference | Principle reference does not override Stillring-specific later authority |

### Null Meridian exception

Any old M16 shorthand that conflicts with docs 127–134 is subordinate to:

- `docs/134_NULL_MERIDIAN_SCENE_ORDER_PRECEDENCE_ADDENDUM.md`.

---

# 3. Completion category traceability

**Global numeric authority:** `docs/104_COMPLETION_LEDGER_RECONCILIATION_AUTHORITY_ADDENDUM.md`

Every top-level category is exactly **1/16 = 6.25%**.

| # | Category | Canonical count / global treatment | Gameplay source owner | Completion behavior / authority |
|---:|---|---:|---|---|
| 1 | Main Story | 1 route | Quest/Story | Binary global category at story completion |
| 2 | Local Repair Contracts | 24 | Quest/Story + source world systems | Completion derives from legitimate resolved contract outcomes |
| 3 | Setup/Payoff | 12 | Setup/Payoff owns chain history; source systems own observed/consequence facts | One valid authored payoff per chain; no prescribed morality |
| 4 | Bellwright Refuges | 11 | World/Quest as authored | Category authority in completion addenda; persistent semantic IDs |
| 5 | Resonance Faults | 36 | Tool/World/Quest depending authored fault | **Not 48** |
| 6 | Pulse Shards | 18 | Inventory/Player Progression acquisition fact | **Not 28** |
| 7 | Cantor Patterns | 9 | Inventory/Tool Progression | Stable owned pattern facts |
| 8 | Tool Mastery Upgrades | 14 | Inventory/Tool Progression | Thresholds subordinate to later completion authority where older catalogs differ |
| 9 | Skill Trials | 9 | Trial/Quest/Progression as authored | One completion semantic ID per legitimate trial resolution |
| 10 | Micro-vaults / maintenance cavities | 24 | World/Quest/Tool depending authored vault | **Not 30** |
| 11 | Testimonies / Records | 32 | Record/Quest/World as authored | Completion derives from acquired semantic record/testimony IDs |
| 12 | Unstandard Tool prestige | 1 global item / 12 internal stages | Quest/Progression | **12 stages are not 12 global completion items** |
| 13 | Drift Knots | 12 | Skiff/World/Completion interplay | Eligibility = Line Skiff + 10 reconciled Faults + existing story prereqs |
| 14 | Optional Elite Encounters | 8 | Encounter State | Completion derives from legitimate unique encounter resolution |
| 15 | Community Disconnection Projects | 6 | Quest/World | Resolutions derive from source-owned project/world facts |
| 16 | Broken Standard Yard | 1 global item / 7 commissions | Quest/World/Progression | **7 commissions are not 7 global completion items** |

Completion percentages/summaries are derived; they are not independent gameplay truth.

---

# 4. Completion stale-source traceability

Older active planning/catalog files may still contain superseded literals.

| Older source | Known danger | Current authority |
|---|---|---|
| `docs/10_COMPLETION_MODEL.md` | old 48 Fault language remains in portions of file | docs 90/104/109 |
| `docs/11_QUEST_AND_COMPLETION_LEDGER.md` | legacy count/allocation tables | docs 89–104, especially doc 104 |
| `docs/12_100_PERCENT_ROUTE.md` | legacy summary totals | docs 90/91/93/104 |
| `docs/13_CANTOR_AND_UPGRADE_CATALOG.md` | K02 old 30-Fault threshold | doc 104: 24 reconciled Faults |
| `docs/14_PRESTIGE_AND_MASTERY_CONTENT.md` | old 13-Fault Drift unlock | doc 104: 10 reconciled Faults + existing prereqs |

No implementation/data registry may consume those stale literals.

---

# 5. Setup/Payoff traceability

## Portfolio authority

- `docs/112_SETUP_PAYOFF_STATE_AUTHORITY_ADDENDUM.md`
- `docs/113_SETUP_PAYOFF_COMMIT_BOUNDARY_AUTHORITY_ADDENDUM.md`
- `docs/114_SETUP_PAYOFF_PAYOFF_MATERIALITY_AUTHORITY_ADDENDUM.md`
- `docs/115_SETUP_PAYOFF_PORTFOLIO_AUTHORITY_ADDENDUM.md`
- `docs/116_SETUP_PAYOFF_AUTHORING_DATA_AUTHORITY_ADDENDUM.md`
- `docs/117_SETUP_PAYOFF_PROTOTYPE_INSTANTIATION_AUTHORITY.md`
- `docs/118_SETUP_PAYOFF_ISSUE_9_CLOSURE_AUDIT.md`
- `docs/119_SETUP_PAYOFF_DECISION_REGISTER_ADDENDUM.md`

## Regional allocation

| Region | Chain count | Traceability note |
|---|---:|---|
| Brindle / First Circuit / Graymile | 3 | includes S01 vertical-slice flagship and current early portfolio work |
| Rootmere | 2 | local infrastructure/living-system questions |
| Saltreach | 2 | regional operations/control consequences |
| Emberstep | 2 | provenance/redundancy/production questions |
| High Aerie | 1 | S10 distributed agency/knowledge |
| Mireglass | 1 | one portfolio chain |
| Cairnfall | 1 | one portfolio chain |

## Mandatory status

Story-mandatory chains:

- S03 Common Measure;
- S06 Manual Fog Code;
- S08 Maker Marks.

Story-optional but 100%-bearing:

- S01, S02, S04, S05, S07, S09, S10, S11, S12.

## Prototype traceability

| Chain | Role | Primary stress test |
|---|---|---|
| S01 Crooked Fire Bell | vertical-slice flagship | physical/elective consequence and natural remembered payoff |
| S06 Manual Fog Code | prototype | operational/mandatory history |
| S11 Personal Provenance | prototype | epistemic-memory/elective history |

### Ownership

Setup/Payoff owns only chain-specific commit/resolution history.

It observes source-owned facts and does not copy them.

---

# 6. Traversal / Line Skiff traceability

Authority:

- docs 120–126.

| Content/system | Source authority | Dependency |
|---|---|---|
| Line Skiff identity | doc 120 | ordinary locomotion/camera foundation |
| Route network grammar | doc 121 | semantic route graph + player control contract |
| Waking/Hush route state | doc 122 | World State + Hush active semantic layer |
| Acquisition/mastery | doc 123 | story/progression + authored trials |
| Network integration | doc 124 | regions, Drift Knots, Route Listener, completion |
| Issue #10 closure | docs 125/126 | navigation/status only; runtime still unverified |

### Key content dependencies

- ordinary use has no stamina/fuel grind;
- Trial 05 is a mastery proving ground, not permission to convert all routes into racetracks;
- Drift Knots require the Skiff and current completion prereqs;
- Route Listener unlocks only after all 12 Drift Knots and never locates still-required Knots;
- Hush route continuity derives from World State + active semantic layer + route definitions.

---

# 7. Gate 3 tool / puzzle traceability

Authority:

- `docs/69_GATE3_TOOL_SYSTEM_CUMULATIVE.md`;
- supporting docs 60–68;
- `docs/13_CANTOR_AND_UPGRADE_CATALOG.md` for content catalog, subject to later completion thresholds.

| Content | Owner/dependency | Traceability rule |
|---|---|---|
| Cantor patterns | Inventory/Tool Progression | stable acquired pattern facts |
| Tool upgrades | Inventory/Tool Progression | completion/canonical thresholds come from later completion authority |
| Puzzle mechanisms | World/Mechanism owner | mechanism pose is derived from semantic fact where reconstructable |
| Tool target eligibility | Tool/interaction authority | failure reasons must be inspectable; no hidden quest-solution scoring |
| Hush cross-layer tool effects | Tool + World/Hush owners | one owner per durable fact; presentation layer does not become truth |

---

# 8. Hush / world-layer traceability

Authority:

- docs 70–80, cumulative `docs/79_GATE4_HUSH_CUMULATIVE_SPECIFICATION.md`.

| Content/state | Owner | Traceability rule |
|---|---|---|
| active semantic layer | Hush/World-Layer service | Waking/Hush are expressions of one semantic place |
| shared persistent fact | declaring gameplay owner / World State orchestration | saved once per semantic identity |
| layer-local durable fact | named owner with semantic layer scope | explicit, not inferred from Actor existence |
| Data Layer activation | presentation/streaming | never quest/world-state authority |
| seam transition presentation | Hush presentation | transient; cannot silently mutate save truth |
| paired interactable identity | semantic ID | Actor paths/runtime instance IDs forbidden as persistence identity |

Production representation remains evidence-dependent.

---

# 9. Save / world-state traceability

Authority:

- docs 81–88.

| State family | Gameplay owner | Save behavior |
|---|---|---|
| player durable progression | Player Progression | persisted semantic progression facts |
| tools/inventory/upgrades | Inventory & Tool Progression | persisted ownership/counts as authored |
| quest/story progression | Quest/Story | persisted semantic stage/resolution facts |
| world/environment facts | World State | persisted semantic facts independent of loaded Actors |
| active Hush/Waking semantic layer | Hush/World-Layer | persisted only at save-stable boundary |
| unique encounter outcome | Encounter State | persisted outcome; world consequences exported to owner systems |
| completion consequences | Completion Ledger | semantic completion facts; summaries derived |
| checkpoint/location | Checkpoint/Travel | semantic checkpoint outranks raw coordinates |

Save Coordinator coordinates snapshot/serialization. It does not own every gameplay fact.

Issue #4 remains open until paired-layer runtime save/exit/reload verification exists.

---

# 10. Null Meridian traceability

Authority:

- docs 127–134.

| Sequence/content | Core dependency | Traceability requirement |
|---|---|---|
| S1–S5 | current locked sequence architecture | each situation must remain understandable without merely naming tools |
| S6 — Take It Off the Bell | local branch readiness + player physical action | player removes master authority; surrounding systems continue at legitimate local rhythms |
| Maelor | core combat + finale thematic escalation | optional completion may not become a `true ending` gate |
| Listener realization | actual player history where feasible | cannot invent a false save-state history merely for spectacle |
| story minimum/partial/full matrices | Quest/Progression/Completion | optional content changes specificity/texture, not access to the canonical ending |
| scene order | doc 134 | overrides stale M16 shorthand for exact finale order |

Null Meridian is a synthesis consumer of prior systems, not the owner of their rules.

---

# 11. Content-production validation rules

Before a content PR is accepted, the authoring/validation pipeline should be able to answer:

1. What is this content's stable semantic ID?
2. Which system owns every durable fact it changes?
3. Which current authority defines its rules/counts/prerequisites?
4. Does it consume any blocklisted legacy literal?
5. Does it assume scene order instead of semantic prerequisites?
6. Does it use Actor/map/node paths as identity?
7. What save/reload behavior applies?
8. What completion consequence is derived, if any?
9. What System IDE workbench can inspect/reset/explain it?
10. What deterministic fixture proves the key state transitions?
11. What human-play question remains?

A content asset that cannot answer those questions is not ready for production scale.

---

# 12. Traceability boundary

This matrix intentionally does not enumerate every individual authored object by name when a canonical catalog already exists.

The production registry/content pipeline should eventually provide machine-checkable item-level traceability for every:

- contract;
- completion item;
- Setup/Payoff chain;
- tool/pattern/upgrade;
- trial;
- route segment;
- persistent world fact;
- named NPC recurrence fact;
- Null Meridian fixture.

That machine-readable layer does not exist yet and must not be simulated by hand-maintained duplicate truth in this document.