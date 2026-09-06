# 170 — Studio Decision-Rights Matrix

**Status:** ACTIVE / PRODUCTION-AUTHORITY / DOCUMENTATION-ONLY  
**Updated:** 2026-09-06  
**Parent program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Gap register:** `docs/152_STUDIO_HANDOFF_GAP_REGISTER.md`  
**Acceptance checklist:** `docs/153_STUDIO_HANDOFF_ACCEPTANCE_CHECKLIST.md`  
**Depends on:** `docs/136`–`docs/147`, current system/story authorities, and `docs/154`–`docs/169` where art production is concerned  
**Boundary:** no UE5.8 implementation, gameplay testing, production asset creation, runtime tuning, profiling, or merge authorization is granted by this document.

---

# 1. Purpose

This matrix answers a production question that must not be left to personality, studio habit, Unreal defaults, or chat memory:

> **Who may decide what, within what bounds, with what evidence, and when must a proposed decision return to project authority or the owner?**

Stillring locks the game more tightly than it locks implementation technique.

The governing distinction is:

> **Creative and player-facing authority is not the same thing as internal implementation freedom.**

A studio is expected to make thousands of ordinary professional choices without asking the owner for permission.

A studio is not authorized to use that freedom to redesign Stillring.

---

# 2. Decision classes

Every material unresolved production decision must be classified into exactly one primary class.

## 2.1 LOCKED / CANONICAL

Repository authority already determines the answer.

The studio may implement, realize, schedule, optimize, and polish the answer, but may not reinterpret its meaning.

Examples:
- ordinary Sprint has no stamina/resource tax;
- Neris does not gain baseline universal/free climbing;
- Line Skiff is a route-network vehicle, not a summon-anywhere mount;
- optional completion does not gate the canonical ending;
- Hush semantic truth is not Runtime Data Layer activation state;
- source systems own facts and derived systems evaluate them;
- Stillring uses Unreal Engine 5.8 unless a later approved migration supersedes that authority.

## 2.2 DERIVED

The answer follows mechanically from existing authority and should be documented rather than escalated.

Examples:
- a Hush presentation layer cannot become canonical quest state because docs 79, 139 and 140 already forbid that ownership inversion;
- an animation graph cannot become the sole owner of combat legality because combat state ownership is already assigned elsewhere;
- a completion UI percentage is derived from Completion Ledger authority rather than independently persisted as gameplay truth.

A derived answer must cite the source authority that makes the derivation valid.

## 2.3 STUDIO CHOICE WITHIN BOUNDS

The studio may choose the internal method without owner approval, provided all locked behavior, ownership, production quality, evidence, accessibility, and shipping constraints are preserved.

Examples:
- exact C++ class decomposition inside an already-declared system owner;
- internal helper types;
- whether a dev-only shell is implemented with UMG, Slate, or a hybrid;
- exact mesh decomposition or modular asset split inside the approved environment kit language;
- rig-control implementation details inside the future Animation Bible;
- ordinary source-control helper scripts;
- use of a Data Asset versus another reviewable Unreal-friendly representation where the owning authority deliberately leaves the representation open.

Studio choice is not permission to change player-facing semantics.

## 2.4 RUNTIME-GATED

The design envelope is known but a final value or technical selection cannot be responsibly fixed before representative UE5.8 implementation, profiling, accessibility evaluation, or human play.

Every runtime-gated decision must include:
- why paper authority is insufficient;
- what representative fixture/content is required;
- who evaluates it;
- what evidence is captured;
- acceptance/failure boundaries where knowable;
- what authority is updated after selection;
- what downstream systems require revalidation.

Examples:
- exact movement speeds/curves;
- exact camera distance/lag/collision recovery;
- Hush production representation after comparing credible approaches;
- tested environment metric conversion from Neris/camera/traversal;
- final target-resolution/framerate matrix after target hardware/platform and representative content exist;
- exact combat timing/balance;
- exact Skiff handling values.

## 2.5 TBD OWNER

A genuine product, commercial, or creative identity decision remains unresolved and cannot be inferred safely.

Owner questions must remain few.

Current known owner/product decisions include:
- launch-platform scope beyond the locked PC-first direction;
- target-PC hardware/performance baseline before objective Gate 5 performance acceptance;
- VO scope if current Audio/Narrative production work does not resolve it from prior authority;
- eventual commercial title/name after clearance;
- any proposal that materially changes locked game, story, art, product, or platform identity.

## 2.6 PROHIBITED

An interpretation is explicitly not allowed even if technically convenient.

Examples:
- silently replacing semantic persistent IDs with Actor paths, map paths, runtime IDs, or display strings;
- shipping development System IDEs, external AI/model dependencies, API keys, or remote debug-control dependencies;
- turning Hush into a universal recolor/glitch filter or independent duplicate quest timeline;
- using completion percentage as a second gameplay database;
- treating a prototype Unreal feature choice as permanent architecture without the required evidence gate;
- copying protected Nintendo/game expression under a “similar but renamed” rationale.

---

# 3. Precedence rule

This document classifies decision rights.

It does not replace detailed system authority.

When a row says `LOCKED`, the exact behavior comes from the cited canonical system/story/production authority, especially:
- `docs/136_CANONICAL_AUTHORITY_INDEX.md`;
- `docs/137_SUPERSESSION_GRAPH.md`;
- `docs/139_SYSTEM_OWNERSHIP_MAP.md`;
- `docs/140_CROSS_SYSTEM_CONTRACT_MATRIX.md`;
- `docs/144_UNANSWERED_QUESTION_REGISTER.md`;
- `docs/145_IMPLEMENTATION_READINESS_GAP_REGISTER.md`;
- system-specific cumulative authorities;
- current story canon;
- current production bibles/manifests.

If an apparent conflict exists, resolve precedence first. Do not use this matrix to manufacture a third answer.

---

# 4. Product and commercial decision rights

| Topic | Class | Current authority / permitted envelope | Escalation or gate |
|---|---|---|---|
| Product mode | **LOCKED** | single-player; no base-game multiplayer; no live service; authored campaign | owner only for material product-scope change |
| PC-first direction | **LOCKED** | PC is first production target | platform expansion still separate owner decision |
| Launch platforms beyond PC-first | **TBD OWNER** | do not assume console commitment, certification scope, or console-specific production burden | resolve before platform-specific production/certification commitments |
| Target-PC baseline | **TBD OWNER** | prototype may run on available development hardware without pretending it is the shipping target | resolve before objective Gate 5 performance acceptance |
| Final resolution/framerate matrix | **RUNTIME-GATED / PRODUCT-CONFIRMED** | derive after target hardware/platform selection and representative rendering/profile evidence | promote accepted matrix into product/performance authority before Gate 5 exit is claimed |
| First-playthrough duration | **LOCKED** | 20–30 hour target | material scope change requires owner approval |
| Major dungeon-scale-space target | **LOCKED** | 8–10 including finale under Project Charter | material scope change requires owner approval |
| World structure | **LOCKED** | interconnected authored world with regional hubs; not checklist-open-world production | owner approval for material structure change |
| Online/backend dependency | **LOCKED / PROHIBITED** | shipped authored campaign must not require a project-owned live-service backend, player-funded AI API, or development agent | optional platform services later must not become gameplay-state authority |
| Commercial title | **TBD OWNER / LATER CLEARANCE** | `Project Stillring` remains internal codename until proper name/trademark clearance | before public-release branding |
| Commercial/monetization model | **TBD OWNER WHEN PUBLISHING REQUIRES IT** | studio may not invent live-service, loot-rarity, or progression monetization that changes locked game design | owner/publishing decision before commercial commitment |
| Localization language list | **TBD PRODUCT LATER** | pipeline must remain localization-ready regardless of initial language list | select before localization staffing/ship scope |

---

# 5. Core gameplay decision rights

| Topic | Class | Studio freedom | Forbidden reinterpretation |
|---|---|---|---|
| Locomotion behavior class | **LOCKED** | implement and later tune approved numeric parameters | no traversal stamina tax, no universal climb, no stock-template semantic substitutions |
| Locomotion numeric feel | **RUNTIME-GATED** | tune in Gate 1 using canonical fixtures and human play | tuning may not alter the locked movement grammar |
| Camera/targeting behavior class | **LOCKED** | choose internal architecture that preserves camera/target ownership | no target-lock autopilot or copied Zelda/Unreal defaults as authority |
| Camera numeric feel | **RUNTIME-GATED** | tune in representative exploration/combat/geometry fixtures | no paper-only “final” values without human comfort/readability proof |
| Combat state grammar | **LOCKED** | implement within Combat ownership | animation montage state cannot silently become gameplay owner |
| Combat timings/balance | **RUNTIME-GATED** | tune through deterministic fixtures + repeated human play | no tuning that bypasses readability or accessibility contracts |
| Encounter pressure grammar | **LOCKED** | choose AI implementation inside scheduler/AI ownership split | difficulty may not override attack-bandwidth/readability rules |
| Cantor/tool semantics | **LOCKED** | internal implementation/data representation may vary | no generic spell scanner, generic grappling, or one-purpose colored-key collapse |
| Puzzle geometry/pacing | **STUDIO CHOICE WITHIN BOUNDS / RUNTIME-GATED** | author unique rooms using locked puzzle grammar and representative play | no conflicting mechanism ownership or arbitrary hidden solution logic |
| Hush semantic behavior | **LOCKED** | presentation/runtime technique may vary | no independent duplicate universe/state truth |
| Hush production representation | **RUNTIME-GATED** | compare credible Unreal approaches as required by Gate 4 | first prototype may not become architecture by inertia |
| Save semantics/ownership | **LOCKED** | choose serialization/container mechanics inside schema policy | Save Coordinator may not become gameplay god object |
| Line Skiff identity/network grammar | **LOCKED** | choose vehicle/route implementation inside corridor/network authority | no summon-anywhere mount or ordinary fuel/stamina tax |
| Skiff handling/camera values | **RUNTIME-GATED** | tune in representative route fixtures | no route automation that removes player handling ownership |
| Completion constants | **LOCKED** | implement current doc 104/109 values and derived arithmetic | stale 48/28/30/13/30-Fault values prohibited |
| Setup/Payoff semantics | **LOCKED** | implementation/data representation within docs 112–119 | no copied source facts or morality-meter rewrite |
| Null Meridian sequence/ending | **LOCKED** | blockout and tune spaces later inside docs 127–134 | no optional “true ending” gate or new mandatory finale-only core verb |

---

# 6. Narrative decision rights

| Topic | Class | Permitted envelope | Escalation |
|---|---|---|---|
| Story spine, reveal order, character culpability, canonical ending | **LOCKED** | production team may stage/write within explicit scene/dialogue authority and future script-status rules | material canon change requires owner authority and coordinated canon update |
| Scene delivery format | **STUDIO CHOICE WITHIN BOUNDS / PRODUCTION AUTHORITY** | future Narrative Production Package may classify gameplay, simple conversation, staged real-time, or cinematic delivery | may not change scene meaning, knowledge state, agency, or required interactivity |
| Final dialogue wording where not already final | **PRODUCTION AUTHORING WITHIN LOCKED INTENT** | narrative team writes to scene objective, character voice, knowledge state, branch/state context | canon-changing wording escalates; VO status follows future VO decision |
| Incidental NPC dialogue/barks | **PRODUCTION AUTHORING WITHIN LOCKED REGIONAL/NPC RULES** | may enrich ordinary life and recurrence | cannot contradict world/quest facts or flatten every interaction into central-theme exposition |
| Records/testimonies wording | **PRODUCTION AUTHORING WITHIN LOCKED FACTS** | final prose can be authored from canonical record purpose/facts | historical/reveal contradiction requires canon review |
| Cinematic skip behavior | **PRODUCTION AUTHORITY / TECHNICAL CHOICE WITHIN BOUNDS** | skip may change presentation time only | skip cannot bypass required semantic state commit/recovery |
| VO scope | **TBD OWNER** unless later authority proves it already settled | Audio/Narrative package must present burden/options without assuming full VO | owner/product selection before casting/recording commitment |

---

# 7. Art and visual production decision rights

Current written visual authority is `docs/154`–`docs/169` on the active art handoff stack.

| Topic | Class | Studio freedom | Prohibited |
|---|---|---|---|
| Playable Fantasy Illustration doctrine | **LOCKED** | execute within visual quality/readability rules | generic Unreal dark fantasy; literal 1998 technical imitation as automatic target |
| Neris/principal character identity | **LOCKED** | production execution, anatomy refinement, topology, texture implementation inside manifest | redesigning occupation/readability/identity without owner review |
| C3 recurring character execution | **PRODUCTION CHOICE WITHIN MANIFEST** | assign approved heads/garments/props/reuse classes consistent with `docs/160` | collapsing named recurring people into anonymous filler |
| C4 population pool counts | **PRODUCTION-PLANNING CHOICE WITHIN BOUNDS** | select exact pool sizes after staffing/rig/memory constraints are known | simple palette-swap crowd or every-NPC-bespoke explosion |
| Mesh decomposition/topology/UVs | **STUDIO CHOICE WITHIN BOUNDS** | art/tech-art decision | may not break silhouette, deformation, gameplay readability, material or performance acceptance |
| Final modular metric conversion | **RUNTIME-GATED** | derive from representative Neris/camera/traversal implementation | guessed “standard Unreal” values may not become canon |
| Lumen/Nanite/renderer feature use | **RUNTIME-GATED / STUDIO RECOMMENDATION** | evaluate only where they solve demonstrated production/visual problems | engine availability is not authority |
| Hush visual grammar | **LOCKED** | per-asset realization follows H0–H5 and regional authority | universal recolor/glitch shader shortcut |
| VFX presentation | **LOCKED LANGUAGE / STUDIO IMPLEMENTATION** | choose emitters/material technique/scalability implementation | VFX may not own gameplay state or hide critical information in color alone |
| Rendered visual-board execution | **OWNER REVIEW FOR CREATIVE CONVERGENCE** | art team produces alternatives within written briefs | board acceptance does not prove runtime/performance |

---

# 8. Animation decision rights

Until the Animation Bible/Manifest exists, gameplay authority already establishes several hard boundaries.

| Topic | Class | Current envelope |
|---|---|---|
| Animation owning gameplay state | **PROHIBITED** | animation presents/requests authored events; gameplay owner decides semantic state |
| Root-motion policy by family | **UPCOMING PRODUCTION AUTHORITY / RUNTIME-GATED WHERE FEEL DEPENDS ON IT** | future Animation Bible must map which families may use authored displacement without stealing Locomotion/Combat authority |
| Rig/skeleton/retarget technology | **STUDIO CHOICE WITHIN FUTURE BIBLE** | choose production-efficient solution that preserves character/anatomy/performance requirements |
| Exact clip counts | **PRODUCTION MANIFEST** | must be inventoried from gameplay/content burden; not guessed ad hoc per animator |
| Blend/additive/IK implementation | **STUDIO CHOICE WITHIN FUTURE BIBLE** | implementation detail unless it changes player-facing timing/eligibility |
| Player-feel animation timing | **RUNTIME-GATED** | human play decides presentation response inside locked gameplay timing authority |

---

# 9. UI/UX decision rights

| Topic | Class | Current envelope |
|---|---|---|
| Information architecture that reflects gameplay/state truth | **LOCKED BY SYSTEM + UPCOMING UI SPEC** | UI presents authoritative state; it does not invent parallel facts |
| Visual layout/component implementation | **STUDIO CHOICE WITHIN UI SPEC** | UMG/Slate/component choices are implementation decisions unless behavior changes |
| Controller-first navigation + KB/mouse support | **LOCKED** | exact focus implementation is studio choice; parity/readability must pass |
| Critical cue redundancy/accessibility | **LOCKED** | no color-only/audio-only critical information |
| Exact animation durations/transitions | **RUNTIME-GATED / UI PRODUCTION CHOICE** | tune for readability and responsiveness; cannot block input or hide state improperly |
| Map icon density | **LOCKED PHILOSOPHY / PRODUCTION AUTHORING** | landmarks/routes over GPS/icon spam; future UI spec enumerates exact grammar |

---

# 10. Audio, music and VO decision rights

| Topic | Class | Current envelope |
|---|---|---|
| Original score / no copied recognizable melodies | **LOCKED / PROHIBITED** | original composition only; reference analysis may extract abstract principles |
| Mechanical/narrative audio role | **LOCKED** | bells/resonance/silence/Hush relationships require production-operational bible |
| Exact sound design implementation | **STUDIO CHOICE WITHIN FUTURE AUDIO BIBLE** | recordings/synthesis/layering are production technique |
| Critical audio cue redundancy | **LOCKED** | critical information must have non-audio support |
| Mix values/loudness | **RUNTIME-GATED** | representative scenes, accessibility and device tests required |
| Music adaptive implementation | **STUDIO CHOICE WITHIN FUTURE MUSIC RULES** | middleware/Unreal implementation must preserve authored state transitions |
| VO scope | **TBD OWNER** | do not cast/record under an assumed full-VO model |

---

# 11. Technical-production decision rights

| Topic | Class | Current envelope |
|---|---|---|
| UE version | **LOCKED** | UE5.8 production baseline; migration requires explicit blocker/benefit, migration proof and approval |
| C++-first / thin Blueprint authority | **LOCKED** | Blueprint may present/assemble/tune; core semantic gameplay/state remains reviewable authority |
| Exact C++ class names and helper decomposition | **STUDIO CHOICE WITHIN BOUNDS** | preserve docs 139/140 owner boundaries |
| Unreal heavyweight frameworks/plugins | **STUDIO PROPOSAL / EVIDENCE-GATED** | adopt only for demonstrated production problem; availability is not justification |
| Persistence IDs | **LOCKED** | stable project-owned semantic IDs; actor/path/runtime identity not canonical |
| Save serialization/container details | **STUDIO CHOICE WITHIN LOCKED SCHEMA/RECOVERY POLICY** | runtime proof required |
| Hush streaming/data representation | **RUNTIME-GATED** | compare credible approaches before production lock |
| Source-control helper tooling | **STUDIO CHOICE** | must preserve reviewability/LFS/binary evidence requirements |
| System IDE technology | **STUDIO CHOICE WITHIN BOUNDS** | shared dev-only shell; no shadow state; shipping stripped/disabled |
| Development AI/agent tooling | **STUDIO CHOICE FOR DEVELOPMENT ONLY** | may assist production; may not become retail dependency or hidden source of canon |

---

# 12. QA, accessibility and localization decision rights

| Topic | Class | Current envelope |
|---|---|---|
| Evidence taxonomy | **LOCKED** | design, implementation, deterministic, persistence, accessibility, performance and human-play proof remain distinct |
| Accessibility baseline | **LOCKED MINIMUM / FUTURE CONSOLIDATION** | remap, subtitle options, color-independent cues, camera controls, shake/reduced effects and affected-system accommodations remain production inputs |
| Exact accessibility tuning | **RUNTIME-GATED** | validate with representative content/users where appropriate; may not alter canonical completion truth silently |
| Localization-ready pipeline | **LOCKED REQUIREMENT** | stable IDs/context/variables; no production dialogue hardcoded in gameplay logic |
| Initial language list | **TBD PRODUCT LATER** | pipeline cannot become hostile to expansion while list remains unsettled |
| Platform certification | **TBD OWNER / PLATFORM-GATED** | do not invent console requirements before platform scope exists |

---

# 13. Production-management decision rights

## 13.1 Studio may decide without owner approval

The studio may normally decide:
- internal task breakdown;
- ordinary file/folder placement within current conventions;
- exact source-control helper workflow;
- modeling topology and UV strategy;
- rig-control implementation;
- animation blend technology;
- internal test helper architecture;
- ordinary coding patterns inside locked owner boundaries;
- tool/vendor choice that does not create retail dependency or alter product behavior;
- exact production sequence between parallelizable tasks when upstream authority is satisfied.

## 13.2 Studio must return to canonical authority, not the owner, when

A question looks unanswered but is actually resolved by:
- later cumulative authority;
- a supersession addendum;
- a system ownership rule;
- a blocklist;
- a production bible/manfiest;
- a runtime-gated validation plan.

The first action is repository reconciliation, not owner interruption.

## 13.3 Studio must escalate to the owner when

The proposal would materially change:
- product mode/platform scope;
- major player-facing mechanics;
- canonical story/ending/character culpability;
- major art identity;
- core scope/content category structure;
- commercial title/branding;
- another owner-reserved creative/product commitment.

---

# 14. Change-control path

A proposed departure from locked/current authority must not be smuggled into implementation or an asset review.

Use this sequence.

## Step 1 — identify the exact authority being challenged

Record:
- document/path/section;
- current decision class;
- affected systems/content;
- whether the issue is semantic, production, technical, accessibility, performance, or schedule-related.

## Step 2 — prove it is not already a studio choice or runtime gate

Check:
- `docs/136` authority index;
- `docs/137` supersession;
- `docs/139`/`140` ownership/contracts;
- `docs/144` unknown register;
- relevant production bible/manifest;
- current gap/audit authority.

## Step 3 — produce the smallest useful proposal

Include:
- problem statement;
- evidence;
- options;
- recommended option;
- player-facing consequence;
- production consequence;
- accessibility/localization consequence where relevant;
- persistence/state-owner consequence where relevant;
- affected authorities that would require update.

## Step 4 — route by class

- **STUDIO CHOICE:** responsible discipline selects and records the decision/provenance.
- **RUNTIME-GATED:** run the named future experiment when implementation is authorized; promote accepted result after evidence.
- **TBD OWNER:** owner chooses among materially distinct product/creative options.
- **LOCKED change request:** owner approval is required if the proposal changes product/creative meaning; technical implementation changes inside the same meaning remain studio choice.

## Step 5 — update authority before downstream work depends on the change

If accepted:
- update the canonical source;
- update supersession/decision register where required;
- update ownership/cross-system matrices if boundaries changed;
- update production manifests/dependencies;
- update validation fixtures/gates;
- update `NEXT_CHAT_HANDOFF.md` when operational sequencing changes.

No accepted chat/meeting decision may remain the only source of truth.

---

# 15. Runtime-gated promotion contract

A runtime-gated value does not become canonical because one developer likes a test value.

Promotion requires:

1. representative implementation/content named in the gate;
2. captured build/commit and relevant configuration;
3. deterministic evidence where applicable;
4. accessibility/performance evidence where applicable;
5. human-play review for feel/readability/pacing claims;
6. comparison against hard-fail conditions;
7. recorded winning value/approach and rejected alternatives where material;
8. authority update;
9. downstream regression list.

Session overrides in System IDEs remain temporary until this promotion occurs.

---

# 16. Outsourcing decision-rights boundary

A package is outsourcing-safe only when the contractor can determine:
- canonical inputs;
- required output/deliverables;
- quality bar;
- dependencies;
- reuse/uniqueness rules;
- revision authority;
- acceptance criteria;
- what may not be redesigned.

Contractors may make normal craft decisions inside the package.

They may not resolve owner/product ambiguity on the project's behalf.

If a package still contains an unresolved owner decision that changes the requested asset/work, the package is not yet safe to commission as final production.

---

# 17. Prohibited “studio decides” shortcuts

The phrase `studio decides` is invalid when it hides any of these:
- a player-facing behavior class;
- a narrative outcome;
- a state owner;
- a completion count/prerequisite;
- a regional identity;
- a Hush semantic relationship;
- an accessibility requirement;
- a persistent-ID rule;
- a content-volume commitment;
- a product/platform assumption.

Where the studio truly has freedom, this document or a scoped authority must state the bounds.

---

# 18. Acceptance test

This matrix passes at written-authority level when a competent external studio can answer:

- Can we choose this ourselves?
- What are the boundaries?
- What evidence is required?
- When do we escalate?
- What is explicitly forbidden?

without asking the owner to make ordinary implementation decisions and without using technical freedom to rewrite the game.

At creation of this document:

> **The project-wide decision-rights framework is PASS at written-authority level.**

This does not close discipline-specific bibles, production dependency mapping, owner product decisions, runtime evidence, or implementation authorization.