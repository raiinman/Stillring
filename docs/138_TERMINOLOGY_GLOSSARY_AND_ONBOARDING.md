# 138 — Terminology Glossary and Safe Onboarding

**Status:** CANONICAL LANGUAGE / ONBOARDING AUTHORITY  
**Updated:** 2026-09-05  
**Program:** Documentation Closure Phase 1

## Purpose

Stillring now has enough systems, story-state language, completion rules, and historical documents that ambiguous shorthand can create real implementation bugs.

This document provides:

1. canonical meanings for high-risk terms;
2. distinctions that must survive implementation;
3. shorthand to avoid when it obscures ownership/state;
4. safe read orders for different contributors.

If a term here conflicts with a more specific owner-approved system authority, the specific system authority controls behavior and this glossary should be updated during closure.

---

# 1. Project / proof vocabulary

## Canon / canonical

Owner-approved project truth for the scoped topic.

Canonical does not necessarily mean already implemented.

## Locked Design

The owner-approved behavioral/content contract exists.

Do not change it silently during implementation.

## Documentation Complete

The scoped authority has been reconciled well enough that current design truth is identified.

It does not mean the feature exists in UE5.8.

## Implemented

Relevant code/assets exist in the target UE5.8 project.

Implementation alone does not prove behavior is correct.

## Deterministically Verified

A repeatable runtime fixture/test against authoritative services demonstrates the scoped claim.

## Human-Play Verified

A human has exercised the intended playable context and accepted the scoped feel/readability/pacing claim.

## Production-Ready

Reserved for a feature whose required design, implementation, persistence/recovery, deterministic verification, accessibility/performance evidence, System IDE support, and human-play acceptance are all satisfied for the stated scope.

Avoid casual `done` when one of these more precise terms is available.

---

# 2. World-state vocabulary

## Orra

The game's world/continent.

Do not use `world` and `Orra` interchangeably in technical state naming when the distinction between runtime world subsystem and fiction location matters.

## Waking

The ordinary/current world-layer expression of a place/entity where the Hush system supports paired expression.

Waking is **not** automatically equivalent to `true`, `real`, or `canonical history`.

Both Waking and Hush may contain authoritative physical/state expressions under the Hush contract.

## Hush

A semantic world-layer expression containing preserved/discarded/contradictory possibility/history relationships as defined by Gate 4 and story authority.

Hush is not:
- a generic dark world;
- a hallucination flag;
- a second independent quest universe;
- a duplicate save-state tree;
- permission to teleport arbitrarily.

## Hush seam

An authored semantic transition relationship between compatible Waking/Hush expressions.

A seam is not a generic portal.

Its legality, destination, locomotion/combat continuity, persistence, and paired identity follow Gate 4 authority.

## Stillness

The changed-world condition produced by the Grand Ring/Stillring catastrophe in which local matter/relations are repeatedly dragged toward preserved relation instead of ordinary progression.

Avoid describing Stillness simply as `time stopped` in technical authority.

The project explicitly treats the phenomenon as state/relation behavior, not universal frozen time.

## Stillring

The catastrophic/world condition central to the game title and post-Grand-Ring state behavior.

Do not use `Stillring` as a generic synonym for every Hush effect, seam, pause, or preserved state.

## Grand Ring

The major catastrophic story activation/event that produces the changed-world boundary.

It is a story/world-state milestone, not a blanket implicit Setup/Payoff commit event.

## Unringing

The late-game community process by which regions/Cairnspire establish local authority, fallback, interoperability, and coordination without restoring Meridian as singular silent master.

Unringing does **not** mean every settlement becomes isolated or rejects standards.

---

# 3. Meridian / Waybell vocabulary

## Meridian / Meridian Bell

The central coordination infrastructure/system whose history includes real public utility, coercive accumulated authority, hidden failure, and the final permanent-hold conflict.

Avoid reducing it to `evil machine` in design/implementation naming.

## Waybells

Regional coordination infrastructure historically linked to Meridian.

They are not six elemental temples or six finale keys.

## Master reference / master phase / central coordinator

A single reference that other systems are forced to inherit or obey as authority.

This is different from **coordination** itself.

Stillring critiques coercive singular ownership, not every shared standard or coordinated operation.

## Local reference / local authority

A valid source-owned operating reference/state maintained by the relevant local system rather than silently inherited from one universal coordinator.

Local authority does not imply isolation or improvisation without safety rules.

## Interoperability

Unlike/local systems exchanging enough information or shared constraints to work together without one system permanently owning all valid state.

Cairnspire's late-game contribution is coordination expertise stripped of monopoly.

---

# 4. Cantor vocabulary

## Cantor Key

Neris's diagnostic/relational instrument and progression platform.

It is not a generic magic scanner.

It diagnoses/compares authored relationships according to Gate 3 authority.

## Cantor Pattern

A learned procedure applied through Cantor.

A Pattern is not automatically a new major core verb.

Major verbs such as Anchor Line, Glasslung Reed, Temper Gauntlet, Line Skiff, Vane Cloak, Mirror Nail/seam relationships remain their own system/progression authority.

## Common Measure

Mandatory early Cantor procedure that lets nearby independent machines agree on **one operation** without assigning a permanent master phase.

Important distinction:

> temporary compatible coordination != permanent central synchronization

In Null Meridian S6, Common Measure coordinates one route-opening operation before the master relay is disconnected.

## Local Accord

Optional late Cantor Pattern that negotiates a temporary shared operating window across independent machines that retain their local references.

It is **optional for the critical path**.

Do not make it mandatory for Null Meridian or the canonical ending.

## Palinode

Mandatory Pattern/procedure that makes incompatible resonance histories legible simultaneously without declaring which whole history is morally/factually `the one true version`.

Palinode is not a truth detector.

## Countertone

Story/system term associated with the learned relationships later named Motion, Memory, and Ending.

Do not implement a player-facing `collect three Countertones` quest/checklist.

The story explicitly removed that structure.

---

# 5. Motion / Memory / Ending

## Motion

A learned relation associated with allowing change/motion rather than preserving one safe state forever.

It emerges through play/story and is named after the relevant experience.

## Memory

A learned relation associated with preserving what happened/what was known without requiring that state to remain physically present forever.

Memory is not `freeze old version`.

## Ending

A learned relation associated with allowing a useful/preserved state to complete/release rather than treating continuation as the only valid outcome.

Ending is not simply destruction.

## Set rule

Motion / Memory / Ending may later be discussed as a learned set.

They must not become an upfront three-item fetch structure.

---

# 6. Major field-tool vocabulary

## Anchor Line

Bounded authored load/tension relationship tool.

Not freeform grappling/swinging.

## Glasslung Reed

Pressure/flow manipulation tool under explicit source/intake/discharge compatibility.

Not generic air magic/ammo.

## Temper Gauntlet

Thermal/material-state manipulation tool.

Stillring often values safe heterogeneous thermal states rather than `make everything one temperature`.

## Vane Cloak

Authored airflow traversal/relationship tool.

Not free flight.

## Mirror Nail

Temporary local echo/state commitment tool.

It can make a useful local state operational without declaring that state universal historical truth.

Not a generic reality toggle.

## Freehand Frame / Unstandard Tool

Optional prestige tool/category with one global completion item and twelve internal stages.

It is never required for canonical critical-path traversal, bosses, or Null Meridian completion.

---

# 7. Line Skiff vocabulary

## Line Skiff

A **network vehicle, not a mount**.

It travels on authored compatible reinforcement-strip route infrastructure.

It is not:
- summon-anywhere transport;
- cross-country vehicle;
- horse analogue;
- ordinary mounted-combat platform;
- stamina/fuel-ticket tax system.

## Semantic route graph / route network

Authoritative macro description of legal Skiff connectivity and route relationships.

The player owns moment-to-moment handling inside the supported route corridor.

## Route segment

A stable semantic portion of Skiff-compatible infrastructure with authored route properties/continuations.

Do not identify canonical route state only by spline actor path or map component identity.

## Paired route continuation

Explicit Waking/Hush route relationship that permits a legal layer transition while the Skiff owns traversal.

No declaration = no aboard-Skiff Hush shift.

## Roadhand Pulse

Mandatory Cantor Pattern/procedure for waking/identifying compatible legacy reinforcement strips and route infrastructure.

It is **not a generic speed boost**.

## Switchshoe

Optional Skiff mastery upgrade that enables transfer between adjacent supported legacy strips at authored junctions without stopping.

It is not `+X% top speed` and never permits leaving supported route infrastructure.

## Drift Knot

Deterministic moving synchronization error/hunt target associated with Line Skiff/network mastery.

Not a ghost collectible.

Current eligibility uses **10 reconciled Resonance Faults + existing story/Line Skiff prerequisites**.

---

# 8. Save / semantic identity vocabulary

## Semantic ID

Stable authored identity describing what a fact/content item **means**, independent of runtime actor instance or presentation path.

Examples of style:
- `setup.brindle.crooked_fire_bell`
- `pattern.roadhand_pulse`
- `upgrade.anchor.brake_reel`

Exact naming schemas belong to their system authorities.

## Persistent ID

Semantic identity used by persistence/save/reconciliation.

Must not be actor path, display string, map coordinate, temporary object pointer, or runtime instance ID.

## Source system / owner

The subsystem that has authority to decide/write a fact.

Other systems may observe/consume that fact but may not create a second contradictory authority copy.

## Source fact

An authoritative semantic fact exposed by its owning system.

## Derived state

State computed from authoritative source facts/history and therefore not blindly persisted when it can be safely reconstructed.

Example: many Setup/Payoff transient lifecycle labels are derived.

## Presentation state

Visual/audio/UI/animation realization of authoritative state.

Presentation can be saved/reconstructed where needed, but may not outrank semantic truth.

## Reconciliation

Process of rebuilding/validating derived/runtime state from authoritative semantic facts, persistent receipts, schema migrations, and owner contracts.

Reconciliation must fail conservatively/audit contradictions rather than invent truth silently.

## Migration

Explicit transformation/alias/split/merge/tombstone handling required when persisted semantic schema changes.

Renaming a save-relevant ID without migration is not allowed.

---

# 9. Setup/Payoff vocabulary

## Setup/Payoff chain

Stable-ID authored semantic state machine relating earlier player/world history to a later meaningful, player-perceivable consequence.

Canonical ID style:

`setup.<region>.<slug>`

## Core ownership rule

> **Source systems own facts. Setup/Payoff evaluates them. It does not copy them.**

## Dormant

Current authoritative conditions do not yet prime the chain.

Derived/transient.

## Primed

Setup conditions are meaningfully established, but the irreversible semantic commit has not occurred.

Derived/transient.

## Committed

An explicit authored physical/social/operational/catastrophe semantic boundary has created durable history.

Do not equate saving, map transition, dialogue end, cutscene completion, or Hush transition with commit unless the chain's actual semantic event is the boundary.

## Payoff Available

Later consequence is currently encounterable under authoritative conditions.

Not equivalent to completion/resolution.

## Resolved

One valid authored payoff path has satisfied the chain's exact resolution predicate.

## Unavailable

Temporary canonical access prevention.

Not failure, not resolution, not permanent loss.

## Superseded

Original staged payoff became impossible after an irreversible world transition, and an explicit equivalent resolution path must exist so completion is not silently destroyed.

## Commit Receipt

Minimal durable history recording the semantic commit/boundary/variant/schema provenance needed for reconciliation.

## Resolution Receipt

Minimal durable history recording the valid outcome/resolution/schema/idempotent settlement needed for reconciliation.

## Variant

Stable semantic committed history, such as `variant.locally_tuned`.

Never use array position, `ChoiceA`, or `ChoiceIndex0` as persistence identity.

## Non-intervention

Explicit authored history for not taking the setup action where that history is meaningful/supported.

It is not an accidental `else` fallback.

---

# 10. Completion vocabulary

## Completion Ledger

Derived reconciliation view of canonical completion facts.

It is **not** the owner of the source facts that make content complete.

## Completion category

One of sixteen equal top-level completion buckets.

Each is worth 6.25%.

## Global item vs internal stage

Important distinction:

- Unstandard Tool prestige = **1 global completion item**, 12 internal stages.
- Broken Standard Yard = **1 global completion item**, 7 internal commissions.

Do not weight internal stages/commissions as separate global categories/items.

## Reconciled count

Count derived from current canonical semantic items after aliases/migrations/splits/merges/tombstones and current completion authority.

Use reconciled counts for thresholds, not stale raw historical IDs.

## Completion assist

Authored/accessibility discovery support tiers.

Assist/accessibility does not invalidate completion.

## 100%

All sixteen category requirements resolved under canonical reconciliation.

Display rules include one decimal and prevent incomplete rounded values from presenting as 100.0.

100% is not required for the canonical valid story ending.

---

# 11. Combat / targeting vocabulary

## Core lock-on combat

Stillring's target-oriented combat coordination model under Gate 1 camera + Gate 2 combat authority.

Target lock does not mean enemies are allowed to ignore camera/readability bandwidth.

## PressureCommit / encounter pressure

Encounter scheduling/authority term for committing attack pressure under Gate 2 constraints.

Do not use encounter pressure as permission to spawn unreadable threats behind the player.

## Semantic target ID

Stable identity of the combat entity across valid expression transitions where supported.

During a legal Hush transition, target lock may remain on the same semantic target while its physical expression changes.

## Seam combat continuity

A Hush seam does not restart attack/evade/guard timing, grant fresh invulnerability, reset momentum, erase projectiles, or arbitrarily retarget.

---

# 12. System IDE vocabulary

## System IDE

Dedicated in-game development workbench for a substantial system, registered into one shared developer shell.

It exists to make authoring/tuning/state reproduction/validation practical while the game runs.

It is not a retail feature.

## Shared developer shell

Common runtime Development/Editor-only host for registered System IDE workbenches.

Issue #58 tracks implementation.

## Inspect

Read authoritative semantic/runtime state and why a system made its current decision.

## Author / Tune

Change approved live-editable values/data within the system's authority boundaries.

## Exercise

Force/reproduce reviewed test states and transitions through real services.

## Validate

Run system-specific assertions and explain rejection/failure reasons.

## Capture / Promote

Capture evidence or deliberate changes and promote them through a reviewable repository-backed path.

## Session override

Temporary live change clearly distinguished from canonical/persisted/promoted authority.

## Shadow state

Forbidden duplicate IDE/debug state that pretends to represent the system without using the real authoritative service.

---

# 13. Null Meridian vocabulary

## Null Meridian

Final dungeon/service architecture of Meridian partly exposed/pulled through Hush relationships.

Not a villain castle detached from Cairnspire's ordinary infrastructure.

## Governing dungeon idea

> **Meridian keeps forcing distinct local things toward one authoritative state. Neris progresses by allowing legitimate local difference, preserving contradiction where needed, letting old states become past, and finally removing central command without destroying coordination.**

## S1 — Hanging Walk

Different suspended structures are forced into one motion and fail; allow independent useful motion.

## S2 — Equal House

Unlike service machines are forced toward one standardized operating state; return each to its own valid condition.

## S3 — The Door That Was There

Official history says no worker door existed; worker history says it did; preserve/use the local doorway history to reach Quiet Court.

## Quiet Court midpoint

Quiet Court is the midpoint turn of Null Meridian, not the room immediately before Maelor.

## S4 — Corrected Passage

Meridian forces a paired route toward one authorized expression; preserve the useful local part, cross Hush, continue under combat pressure.

## S5 — Battle That Won't End

Preserved old combat history overlays the current fight; identify the physically current formation relationship and fight normally.

Cantor is not an enemy-AI future-action scanner.

## S6 — Take It Off the Bell

Transfer ordinary Meridian service branches to valid local control, use Common Measure for one shared operation, then physically disconnect the master relay and observe local continuation.

## Listener

Emergent composite/being associated with compressed Hush possibility and endings-as-containment pressure.

Must remain partly unknowable.

Not simply a benevolent ghost after release and not a third health-bar boss.

## Decommission

Final player-performed action that ends Meridian's central coercive hold rather than taking control of the system.

Not equivalent to `blow up everything`.

---

# 14. Ambiguous shorthand to avoid

Avoid these unless the surrounding context makes the canonical meaning explicit.

## `timeline`

Problem:
May imply two complete alternate universes.

Prefer:
- Waking/Hush expression;
- historical state;
- incompatible history;
- local echo-state;
- preserved state.

## `dark world`

Problem:
Mischaracterizes Hush as a generic alternate evil map.

Prefer `Hush` with its authored semantic meaning.

## `choice`

Problem:
Can hide whether the action actually commits durable history.

Prefer:
- proposed action;
- semantic commit boundary;
- committed variant;
- non-intervention;
- payoff outcome.

## `quest flag`

Problem:
Can become an untyped catch-all.

Prefer the authoritative source fact and owner where possible.

## `save the actor`

Problem:
May imply actor path/runtime object persistence.

Prefer save the semantic fact/entity state by stable ID.

## `load the Hush layer`

Problem:
May incorrectly make Data Layer load state authoritative.

Prefer transition/reconcile semantic Hush expression, with presentation/streaming following the authority contract.

## `mounted`

Problem:
Invites horse/mount assumptions for Line Skiff.

Prefer aboard Skiff / Skiff traversal state.

## `boost`

Problem:
Roadhand Pulse is not a speed boost.

Use the actual route-infrastructure function.

## `three Countertones`

Problem:
Can reintroduce removed fetch-checklist structure.

Prefer Motion / Memory / Ending as story-learned relations in the context where the characters have actually named them.

## `final trials`

Problem:
Makes Null Meridian sound like six scoreboard rooms.

Prefer major problem sequences / dungeon sequences unless discussing Issue #11's historical wording.

---

# 15. Safe onboarding — everyone

A new contributor should **not** read all documents chronologically.

Start here:

1. `README.md`
2. `ROADMAP.md`
3. `docs/NEXT_CHAT_HANDOFF.md`
4. `docs/135_DOCUMENTATION_CLOSURE_PROGRAM_CHARTER.md`
5. `docs/136_CANONICAL_AUTHORITY_INDEX.md`
6. `docs/137_SUPERSESSION_GRAPH.md`
7. this glossary
8. `docs/15_CANON_TO_PLAY_PIPELINE.md`
9. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`

Then branch into the relevant discipline.

Historical/individual decision addenda should be read **after** the current cumulative authority when implementation needs exact edge rationale.

---

# 16. Safe onboarding — gameplay engineer

After the common path:

## Gate 1
- `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`
- `docs/22_GATE1_CAMERA_SPECIFICATION.md`
- Issue #5

## Gate 2
- `docs/48_GATE2_COMBAT_STATE_MODEL.md`
- relevant docs 50–59

## Gate 3
- `docs/69_GATE3_TOOL_SYSTEM_CUMULATIVE.md`
- `docs/13_CANTOR_AND_UPGRADE_CATALOG.md`

## Gate 4
- `docs/79_GATE4_HUSH_CUMULATIVE_SPECIFICATION.md`
- `docs/88_SAVE_WORLD_STATE_CUMULATIVE_SPECIFICATION.md`
- Issue #4

Never begin implementation from an old issue comment/chat handoff when a cumulative authority exists.

---

# 17. Safe onboarding — save/world-state engineer

Read:

1. common onboarding path;
2. `docs/88_SAVE_WORLD_STATE_CUMULATIVE_SPECIFICATION.md`;
3. docs 81–87;
4. `docs/79_GATE4_HUSH_CUMULATIVE_SPECIFICATION.md`;
5. `docs/104_COMPLETION_LEDGER_RECONCILIATION_AUTHORITY_ADDENDUM.md`;
6. docs 112–119 Setup/Payoff;
7. docs 120–126 Line Skiff;
8. docs 127–134 Null Meridian;
9. Issue #4;
10. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`.

The phase-2 ownership/cross-system matrices will become mandatory companions once merged.

---

# 18. Safe onboarding — writer / narrative designer

Read:

1. common onboarding path;
2. `docs/02_STORY_BIBLE.md`;
3. `docs/09_STILLRING_PROGRESSION_BLUEPRINT.md`;
4. current `docs/story/` scene/reveal/objective/region files;
5. `docs/104_COMPLETION_LEDGER_RECONCILIATION_AUTHORITY_ADDENDUM.md` **before using any completion count**;
6. `docs/115_SETUP_PAYOFF_PORTFOLIO_AUTHORITY_ADDENDUM.md`;
7. `docs/117_SETUP_PAYOFF_PROTOTYPE_INSTANTIATION_AUTHORITY.md`;
8. docs 127–134 for Null Meridian/finale exact flow.

Never infer current 100% counts solely from older story/ledger prose.

---

# 19. Safe onboarding — content / quest implementer

Read:

1. common onboarding path;
2. story authority for the content being implemented;
3. `docs/88_SAVE_WORLD_STATE_CUMULATIVE_SPECIFICATION.md`;
4. `docs/104_COMPLETION_LEDGER_RECONCILIATION_AUTHORITY_ADDENDUM.md`;
5. Setup/Payoff docs if the content participates in a chain;
6. relevant tool/Hush/traversal authority;
7. System IDE contract;
8. future phase-2 ownership and cross-system matrices.

Content implementation must not create ad-hoc Blueprint quest truth because the authored scene knows what happens next.

---

# 20. Safe onboarding — QA / automation / agent

Read:

1. common onboarding path;
2. `docs/16_DEVELOPER_TOOLING_AND_MACHINE_QA.md`;
3. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`;
4. system cumulative authority;
5. system-specific fixture/IDE addenda;
6. Save/World-State if the test crosses persistence;
7. future Runtime Evidence Ledger.

Automation should prefer:
- semantic actions;
- semantic state reads;
- deterministic presets;
- explicit source-owner assertions;

over screenshot/pixel scripting or editor-click choreography.

---

# 21. When to read historical documents

Read older/individual decision documents when:
- implementing an edge case not fully restated in the cumulative spec;
- understanding why a rule exists;
- building deterministic fixtures that mirror the original acceptance contract;
- auditing a suspected regression/supersession;
- researching a proposed revision.

Do not read historical documents to shop for a more convenient old answer after a newer authority has locked the topic.

---

# 22. Escalation rule

If implementation discovers something that appears impossible, contradictory, or materially worse under current authority:

1. reproduce the problem;
2. capture runtime evidence;
3. identify the exact authority being challenged;
4. classify the problem as architecture, implementation choice, tuning, content, runtime evidence, or owner decision;
5. propose the smallest scoped revision;
6. obtain required owner approval before changing canon.

Do not let code become an undocumented supersession graph.
