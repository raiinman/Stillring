# 152 — Studio Handoff Gap Register

**Status:** ACTIVE / CURRENT  
**Updated:** 2026-09-06  
**Parent:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Runtime boundary:** documentation only; no testing or UE5.8 implementation authorized

---

# 1. Purpose

This register answers a stricter question than the Implementation-Readiness Gap Register:

> **If a competent external game studio received Stillring today, what would still force them to invent production intent, assume scope, or return to the owner for clarification before they could confidently quote and build the finished game?**

A gap is not automatically a design defect.

Some gaps are normal pre-production unknowns.

The requirement is that every gap is visible, owned, bounded, and assigned a closure artifact or future gate.

---

# 2. Current overall assessment

## Design handoff

**STRONG**

The repository communicates core gameplay, story, progression, traversal, Hush, save, completion, finale, ownership, and implementation boundaries well enough that a studio should not need to invent the game's identity.

## Engineering handoff

**STRONG FOR SCOPED PROTOTYPE / NOT RUNTIME-PROVEN**

The architecture boundaries and implementation order are clear, but there is not yet a real UE5.8 project/runtime.

## Full production handoff

**INCOMPLETE**

The repository does not yet contain enough discipline-specific production authority for reliable full-game staffing, quoting, outsourcing, asset planning, animation planning, audio planning, UI planning, cinematic planning, or platform-performance planning.

## Ship handoff

**NOT READY**

No implementation, production assets, runtime evidence, certification scope, or final platform target exists yet.

---

# 3. Gap classes

- **P0 — studio-blocking product ambiguity**: studio cannot responsibly scope/quote affected work without an explicit owner/product boundary.
- **P1 — production-authority gap**: studio understands intent but lacks enough concrete production definition to staff/author consistently.
- **P2 — manifest/scheduling gap**: production direction exists but deliverable volume/dependencies are not estimateable enough.
- **P3 — later runtime/tuning dependency**: cannot be closed honestly until implementation or human play; must be explicitly gated rather than guessed.

---

# 4. Product / platform gaps

| ID | Class | Gap | Existing authority | Why studio cares | Closure |
|---|---|---|---|---|---|
| SH-PROD-001 | **P0** | Exact target-PC performance baseline is not selected | PC-first; later performance proof required | staffing/optimization budgets and final quality assumptions depend on it | `Performance / Platform Product Brief`; owner decision before objective Gate 5 performance acceptance |
| SH-PROD-002 | **P0** | Intended launch-platform scope is not selected beyond PC-first | project charter says PC first | console support changes input, UI, memory/perf, save, certification, QA, packaging | product brief records current PC-first status and `TBD OWNER`; owner selects before platform-specific production commitments |
| SH-PROD-003 | **P1** | Commercial title/name clearance is not production-ready | Stillring is internal codename | publishing/store/legal/branding work cannot use a presumed final title | later naming/trademark clearance package; not required for gameplay pre-production |
| SH-PROD-004 | **P1/P3** | Exact target resolution/framerate matrix is not final | rendering direction exists | drives art/performance/QA expectations | select after target hardware/platform scope and representative rendering evaluation |

---

# 5. Art-direction production gaps — reconciled current status

The original `SH-ART-*` rows correctly identified missing production-operational art authority before the current art package existed.

That written package now exists across `docs/154`–`docs/169`.

For current `SH-ART-001`–`SH-ART-010` status:

1. use this section for the global gap-register summary;
2. use `docs/169_ART_WRITTEN_HANDOFF_ACCEPTANCE_AUDIT.md` for the scoped evidence and acceptance reasoning;
3. use `docs/157_ART_WORKSTREAM_CLOSURE_STATUS.md` for active sequencing and remaining art evidence.

The governing distinction is:

> **Written production authority may be closed while visual execution, production assets, runtime proof, accessibility validation and human-play acceptance remain open.**

Stillring should therefore no longer be described as lacking production-operational art authority in general.

| ID | Original class | Current status | Current authority | Remaining honest closure |
|---|---|---|---|---|
| `SH-ART-001` | **P1** | **PASS — WRITTEN AUTHORITY** | `docs/154`, `docs/158`, `docs/164`, integrated benchmark use in `docs/168` | Board 03/06 rendered verification; final concept/model execution; rig/scale/performance evidence |
| `SH-ART-002` | **P1** | **PARTIAL — PRINCIPAL CAST CLOSED / C3 EXECUTION PLANNING REMAINS** | `docs/158`, C3/C3+ enumeration and burden in `docs/160`, Board 03 brief `docs/164` | rendered principal verification; C3 production sheets/head-costume assignments and execution planning |
| `SH-ART-003` | **P1/P2** | **PARTIAL — POPULATION STRATEGY CLOSED / EXACT POOL PLAN REMAINS** | `docs/154`, `docs/156`, `docs/158`, `docs/160`, `docs/164` | exact regional C4 body/head/hair/garment pool counts, reuse matrix and production-volume plan during staffing/asset planning |
| `SH-ART-004` | **P1** | **PASS — WRITTEN AUTHORITY** | `docs/154`, `docs/156`, `docs/159`, readability integration in `docs/167` | concept/model/animation/VFX execution; gameplay-distance readability and performance evidence |
| `SH-ART-005` | **P1/P2** | **PARTIAL — WRITTEN MODULAR LANGUAGE CLOSED / METRIC CONVERSION DEPENDENCY-BOUND** | `docs/156`, `docs/160`, `docs/165`, `docs/167`, `docs/168` | final module dimensions/grid, collision envelopes and tested world-scale conversion after representative Neris/camera/traversal implementation |
| `SH-ART-006` | **P1** | **PASS — WRITTEN AUTHORITY** | `docs/154`, `docs/156`, `docs/161`, `docs/166`, integrated benchmark in `docs/168` | Board 04/06 rendered keys; exact runtime exposure/light/fog behavior; measured performance proof |
| `SH-ART-007` | **P1** | **PASS — WRITTEN AUTHORITY** | `docs/154`, `docs/156`, `docs/160`–`docs/162`, Boards 02–06 integration in `docs/164`–`docs/168` | visual execution; per-asset Hush tracking during production; runtime/accessibility/performance proof |
| `SH-ART-008` | **P1** | **PASS — WRITTEN AUTHORITY** | `docs/154`, `docs/156`, `docs/159`, `docs/161`–`docs/163`, `docs/166`–`docs/168` | Board 05/06 rendered verification; implementation; Reduced Effects/accessibility validation; measured runtime budgets |
| `SH-ART-009` | **P2** | **PASS — WRITTEN INVENTORY AUTHORITY** | `docs/156`, detailed regional environment/prop manifests in `docs/160`, regional scripts and Boards 02–06 in `docs/161`, `docs/165`–`docs/168` | detailed production-estimate counts and asset scheduling; rendered Board 02/04/05/06 verification; runtime proof |
| `SH-ART-010` | **P1** | **RUNTIME-GATED / PARTIAL REFERENCE ANCHORS EXIST** | `docs/156`, design-reference heights in `docs/158`, non-runtime scale presentation in `docs/164`/`docs/165`, benchmark noncanonical-layout boundary in `docs/168` | tested door/stair/ledge/interaction/module metrics after representative Neris + camera + traversal implementation; do not invent “standard Unreal” values now |

## 5.1 What remains an actual art handoff gap

The remaining art work is now concentrated rather than broad:

- C3 recurring-character execution sheets and assignments;
- exact C4 regional population/reuse pool counts for staffing and scheduling;
- owner-reviewed rendered execution for Boards 02–06;
- representative Q2 character/environment/VFX production evidence;
- final modular/world-scale metrics derived from later implementation rather than guessed;
- per-asset Hush/VFX production tracking;
- runtime accessibility, readability, scalability and performance evidence.

These remaining items do not reopen locked art doctrine, principal character identity, regional art identity, enemy/boss taxonomy, Hush grammar, VFX language or visual-board source authority.

A studio should not infer art direction from mood references, Zelda/N64 lineage, Unreal defaults, or chat history. The current written package is the authority.

---

# 6. Animation-production gaps

Gameplay semantics strongly constrain animation authority, but production inventory is not yet complete.

| ID | Class | Gap | Required closure |
|---|---|---|---|
| SH-ANI-001 | **P1** | skeleton/rig/retargeting production standard | Animation Bible |
| SH-ANI-002 | **P2** | Neris animation inventory | locomotion, jump/fall, traversal, target lock, combat, tools, interactions, Hush, Skiff, cinematics |
| SH-ANI-003 | **P2** | enemy animation family inventory | per-archetype locomotion, telegraphs, attacks, reactions, defense, death, special state |
| SH-ANI-004 | **P2** | NPC ambient/social animation inventory | region/social-role families, work loops, conversation, seated/idle, changed-world reactions |
| SH-ANI-005 | **P1** | root-motion policy by animation family | preserve gameplay authority; identify allowed authored exceptions |
| SH-ANI-006 | **P1** | IK/additive/procedural responsibilities | feet, hands, ledges, ladders, tool contact, slope adaptation, look/aim layers where allowed |
| SH-ANI-007 | **P1/P2** | facial/performance approach | dialogue/cinematic facial scope, lip-sync approach, performance quality bar |
| SH-ANI-008 | **P2** | cinematic animation burden | scene list mapped to in-game, staged real-time, bespoke animation, or simple conversation presentation |
| SH-ANI-009 | **P1** | animation-event ownership rules consolidated | animation may signal authored windows/events but may not silently own semantic gameplay state |

---

# 7. Audio / music / VO gaps

Current authority says audio is mechanical and narrative, Hush changes ambience dramatically, and critical information cannot be audio-only.

That is not yet enough to brief a complete audio department.

| ID | Class | Gap | Required closure |
|---|---|---|---|
| SH-AUD-001 | **P1** | region ambience bible | Waking/Hush layers, weather, machinery, wildlife/population, silence expectations |
| SH-AUD-002 | **P1** | bell/resonance sonic grammar | semantic distinction among Waybells, Cantor, faults, patterns, successful/unsafe states |
| SH-AUD-003 | **P1** | combat feedback hierarchy | attack, guard, Perfect Guard, evade, hit, armor, shield, danger/offscreen redundancy |
| SH-AUD-004 | **P1** | score/music identity | instrumentation boundaries, regional identity, dynamic-state rules, travel, bosses, finale |
| SH-AUD-005 | **P1** | leitmotif policy | what characters/ideas/regions earn recurring motifs and what must not become copied franchise language |
| SH-AUD-006 | **P2** | music cue manifest | story, region, dungeon, boss, travel, quiet, Hush, credits requirements |
| SH-AUD-007 | **P0/P1** | VO scope decision | full VO, partial VO, key-scene VO, or another explicit production model; affects budget and narrative production |
| SH-AUD-008 | **P1/P2** | voice/performance bible | character vocal identity, pronunciation, emotional/performance direction, effort/bark requirements |
| SH-AUD-009 | **P2** | bark/dialogue audio manifest | combat, traversal, ambient NPC, story, changed-state variation |
| SH-AUD-010 | **P1** | mix/readability rules | critical-cue priority, subtitle/caption redundancy, Hush silence/readability, accessibility |

VO scope is a real future owner/product decision if current story authority does not already settle it.

---

# 8. UI/UX production gaps

Current UI philosophy is coherent but does not yet enumerate every production surface.

| ID | Class | Gap | Required closure |
|---|---|---|---|
| SH-UI-001 | **P1** | complete screen/state inventory | UI/UX Production Specification |
| SH-UI-002 | **P1** | complete controller navigation/focus contract | all menus, dialogs, journals, remapping, long text, grids/lists |
| SH-UI-003 | **P1** | keyboard/mouse parity for menus | pointer/focus coexistence, key prompts, scroll behavior |
| SH-UI-004 | **P1** | HUD state matrix | exploration, combat, targeting, tools, Skiff, Hush, contextual warnings |
| SH-UI-005 | **P1** | map production grammar | route/landmark presentation, region state, completion-assist disclosure, no GPS-spam boundary |
| SH-UI-006 | **P1** | journal/quest/record information architecture | clues, commitments, records/testimonies, dialogue history, spoiler control |
| SH-UI-007 | **P1** | save/load/recovery UX | slots, autosave/manual indicators, corrupt/incompatible recovery, deferred-save explanation |
| SH-UI-008 | **P1** | accessibility/settings IA | remap, camera, subtitles, motion, color-independent cues, timing/support options |
| SH-UI-009 | **P1** | error/warning state catalog | device changes, save failure, unsupported state, destructive confirmation, migration/recovery |
| SH-UI-010 | **P2** | UI asset/icon/glyph manifest | icon families, tool/pattern representations, controller glyph strategy, typography needs |

---

# 9. Narrative-production gaps

Canonical story is substantially developed, but a studio still needs production-ready script/scene inventories.

| ID | Class | Gap | Required closure |
|---|---|---|---|
| SH-NAR-001 | **P1** | script-status taxonomy | canonical beat vs final dialogue vs placeholder vs optional incidental text |
| SH-NAR-002 | **P2** | cinematic/scene production list | every scene classified by presentation burden |
| SH-NAR-003 | **P2** | dialogue scene inventory | speakers, location/state, branch conditions, VO status, localization notes |
| SH-NAR-004 | **P2** | NPC ambient conversation/bark families | region/state/event variants |
| SH-NAR-005 | **P1** | character performance bible | speech style, emotional range, relationships, pronunciation, forbidden flattening/stereotypes |
| SH-NAR-006 | **P2** | records/testimonies final text inventory | 32 records plus story-critical documents and archive material |
| SH-NAR-007 | **P1** | gameplay/cutscene delivery boundary | what must remain interactive versus what may be staged |
| SH-NAR-008 | **P1** | localization context rules | variables, gender/number/context, pronunciation, line intent, spoiler flags |
| SH-NAR-009 | **P2** | credits/consequence text requirements | optional specificity, completion acknowledgements, branch-safe outcomes |

The studio should not turn canonical scene contracts into whatever cinematic scope happens to fit its preferred pipeline.

---

# 10. World/content production gaps

Stillring has strong authored counts and content identities. It needs production manifests that translate those facts into discipline workload.

| ID | Class | Gap | Required closure |
|---|---|---|---|
| SH-CONT-001 | **P2** | region-by-region environment burden | Region Production Manifest |
| SH-CONT-002 | **P2** | quest/contract production burden | route, NPC, dialogue, mechanism, encounter, reward, save-state dependencies |
| SH-CONT-003 | **P2** | Setup/Payoff consequence asset burden | pre/post states, dialogue, props, world change, alternate variants |
| SH-CONT-004 | **P2** | Hush paired-state burden per region/content type | paired, layer-exclusive, related-distinct, unchanged assets |
| SH-CONT-005 | **P2** | completion-category production burden | faults, shards, patterns, trials, vaults, records, elites, projects, etc. |
| SH-CONT-006 | **P2** | enemy/encounter distribution plan | archetype use by region, encounter family, optional elite dependencies |
| SH-CONT-007 | **P2** | dungeon production manifest | central idea, unique kits/mechanisms, boss, music/VFX, state, optional content |
| SH-CONT-008 | **P2** | Line Skiff network production burden | route lengths/segments, nodes, spurs, old lanes, mastery course, Drift Knot segments |
| SH-CONT-009 | **P2** | Null Meridian unique-production manifest | S1–S6, worker layer, archive, Maelor space, boss, Listener, final decommission |
| SH-CONT-010 | **P2** | reusable-versus-unique asset policy | prevents every quest/region from commissioning bespoke content unnecessarily |

---

# 11. Technical-production documentation gaps

Architecture ownership is strong. Studio production still needs a single technical-operational consolidation.

| ID | Class | Gap | Required closure |
|---|---|---|---|
| SH-TECH-001 | **P1** | naming/folder/package conventions | Technical Production Bible |
| SH-TECH-002 | **P1** | content/data authoring convention | DataAssets/tables/semantic registries/validation boundaries by system |
| SH-TECH-003 | **P1** | plugin/framework adoption process | explicit review criteria and banned assumption that availability equals authority |
| SH-TECH-004 | **P1** | source-control/LFS binary workflow | Unreal binary list/review conventions, ownership/locking strategy if needed |
| SH-TECH-005 | **P1** | build-configuration and dev-tool stripping policy | Editor/Development/Test/Shipping behavior |
| SH-TECH-006 | **P1** | logging/capture/provenance standard | common fixture/capture names, evidence packages, System IDE promotion records |
| SH-TECH-007 | **P1** | localization-ready text pipeline expectation | stable IDs/context/variables; no hardcoded production dialogue in gameplay logic |
| SH-TECH-008 | **P1** | asset-reference/persistence rule consolidation | no display/path/runtime IDs where semantic identity is required |
| SH-TECH-009 | **P3** | Hush production representation selection | compare runtime approaches later; document as unresolved architecture gate now |
| SH-TECH-010 | **P3** | concrete performance budgets | require actual target platform/hardware + representative runtime evidence |

---

# 12. Production-management / staffing gaps

The repo currently provides roadmap sequencing, not a full external-studio staffing package.

| ID | Class | Gap | Required closure |
|---|---|---|---|
| SH-MGMT-001 | **P2** | discipline dependency matrix | identify upstream/downstream dependencies across design, engineering, art, animation, narrative, audio, UI, QA |
| SH-MGMT-002 | **P2** | deliverable taxonomy | prototype, vertical-slice, first-production, alpha, beta/release candidate definitions by discipline where appropriate |
| SH-MGMT-003 | **P2** | region/workstream ownership model | safe parallelization boundaries and shared-system dependencies |
| SH-MGMT-004 | **P2** | approval/decision-rights matrix | locked vs studio-choice vs tuning vs owner decision |
| SH-MGMT-005 | **P2** | outsourcing package boundaries | what can be externally produced without exposing contractor to unresolved authority |
| SH-MGMT-006 | **P2** | change-control process | how a studio proposes necessary departures from locked authority and who approves them |

No fake headcount or dollar estimate should be invented before these manifests exist.

---

# 13. QA / accessibility / localization / release gaps

These do not require active testing now, but the production expectations must be documented.

| ID | Class | Gap | Required closure |
|---|---|---|---|
| SH-QA-001 | **P1** | feature-level acceptance evidence taxonomy consolidated for studio use | Technical/QA production section referencing existing runtime-evidence rules |
| SH-QA-002 | **P1** | accessibility feature matrix by system/UI/content | consolidate existing requirements and identify production owner |
| SH-QA-003 | **P1** | localization scope/readiness rules | languages may be TBD, pipeline cannot be localization-hostile |
| SH-QA-004 | **P0/P3** | platform certification scope | remains TBD until platform selection |
| SH-QA-005 | **P3** | final performance, memory, loading, save integrity budgets | runtime/target-platform evidence required later |

---

# 14. What is explicitly **not** a handoff gap

Do not reopen these simply because final production details are not yet created:

- whether Sprint costs stamina — it does not;
- whether Line Skiff is a mount — it is not;
- whether Hush Data Layers own semantic truth — they do not;
- whether Setup/Payoff copies world facts — it does not;
- whether optional completion gates the canonical ending — it does not;
- whether Null Meridian introduces a new mandatory core verb — it does not;
- whether completion counts are still provisional — current reconciled counts are locked;
- whether every exact movement/combat/camera number must be frozen before implementation — it should not be;
- whether System IDEs may maintain separate gameplay truth — they may not;
- whether the studio may copy Zelda/Nintendo expression — it may not.

Production closure must add detail without reopening settled identity.

---

# 15. Genuine owner decisions currently visible

These should remain few and explicit.

## Owner/product decisions definitely still visible

1. **Launch platform scope** beyond current PC-first direction.
2. **Target-PC hardware/performance baseline** before objective later performance acceptance.
3. **VO scope**, if current authority does not already decide the extent of voiced dialogue.
4. **Commercial title/name**, after proper clearance and when public-release planning requires it.
5. Any future proposal to materially change locked art direction, scope, core mechanics, story canon, completion model, or platform strategy.

## Not owner decisions

Do not ask the owner to choose:

- class names;
- Slate versus UMG unless the choice changes product behavior;
- exact mesh decomposition;
- internal implementation patterns inside locked boundaries;
- numeric tuning that should be prototyped;
- ordinary production-tool choices that preserve authority.

---

# 16. Recommended documentation sequence

To avoid creating disconnected bibles, complete Studio Production Handoff Closure in this order:

1. **Studio Decision-Rights Matrix + Product/Platform Brief skeleton** — establishes what is locked/TBD and prevents other docs from assuming product choices.
2. **Art Bible + scale/material/lighting/Hush production rules.**
3. **Character/Environment/Prop Production Manifests.**
4. **Animation Bible + animation manifest.**
5. **UI/UX Production Specification.**
6. **Audio/Music/VO Bible.**
7. **Narrative Production Package.**
8. **Region-by-Region Production Manifest.**
9. **Technical Production Bible.**
10. **Production Dependency/Discipline Matrix.**
11. **QA/accessibility/localization production consolidation.**
12. **Final Studio Handoff Acceptance Audit.**

Cross-link instead of duplicating canonical gameplay/story authority.

---

# 17. Closure test

A gap is closed only when an external studio can determine one of the following without owner-intent reconstruction:

- **LOCKED:** implement exactly within stated authority;
- **STUDIO CHOICE:** choose a reasonable implementation within explicit bounds;
- **TUNING/PROTOTYPE:** defer final value until runtime/human evidence;
- **TBD OWNER:** do not assume; wait for the named decision gate.

If the answer is merely “use good judgment,” the gap is not closed.
