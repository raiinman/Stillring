# 99 — Completion Decision #11 — Prestige Craft Quest Authority

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #8 — Define 100% completion taxonomy and persistence contract  
**Decision:** #11 — The Unstandard Tool stage validation, completion counting, reward authority, anti-fetch constraints, accessibility, persistence, recovery, IDE, and anti-grind rules

## Decision question

Does the existing twelve-stage prestige quest, **The Unstandard Tool**, deserve completion-bearing status as written, and how should its twelve authored stages count without overweighting one quest family or allowing the chain to decay into courier errands and material grind?

## Fresh research conclusion

**Keep all 12 authored stages, but count the prestige quest as ONE completion-bearing quest-family resolution.**

The twelve stages are progression/state checkpoints inside one authored optional arc. They are not twelve separate percentage-bearing collectibles.

Each current stage survives individual review because every one contains diagnosis, traversal, craft, social interpretation, reconstruction, calibration, or mechanical action. None exists solely as "carry object from NPC A to NPC B."

The decisive rule is:

> **The twelve stages are the anatomy of one prestige story. Completion counts the finished work, not twelve errands.**

## Locked philosophy

> **Earn the tool by understanding how it was made and why it mattered.**

## Shipping structure

**Quest family:** `prestige.unstandard.*`  
**Authored stages:** **12 confirmed**  
**Completion-bearing unit:** **1 quest-family completion**  
**Final completion event:** authoritative settlement of Stage 12, `prestige.unstandard.12_no_master_pattern`

Stage progression is still persisted individually for save/recovery/debugging, but global 100% receives one category item for resolving the full prestige quest.

## Individual stage validation

### Stage 01 — The Bent Yoke
**Action identity:** diagnosis / interpretation.  
**Survives because:** the player must distinguish unfinished design from damage using already-taught diagnostic language. It also opens the quest through demonstrated understanding rather than a generic map marker.

### Stage 02 — The Pressurewright's Mark
**Action identity:** social/history investigation.  
**Survives because:** Vessa does not hand over the required part. She explains why the original craft rejected fixed standardized dimensions and points to the next material relationship.

### Stage 03 — Fiber That Refuses a Ruler
**Action identity:** traversal / material judgment.  
**Survives because:** the player recovers naturally shed load-fiber and evaluates shape-memory behavior instead of harvesting arbitrary quantities.

### Stage 04 — A Coupler That Breathes
**Action identity:** pressure-state fabrication.  
**Survives because:** the player builds and tests a flexible coupler under both air and water pressure; this is applied understanding, not menu crafting.

### Stage 05 — Metal With More Than One Temperature
**Action identity:** thermal-state craft.  
**Survives because:** the player creates a mixed-state alloy whose outer rails and center intentionally hold different properties. The challenge reinforces existing thermal grammar.

### Stage 06 — Carry It Wrong
**Action identity:** Line Skiff transport as mechanical state management.  
**Survives because:** travel itself is the mechanic: the rail must remain inside a vibration band, with both excessive roughness and excessive smoothness being wrong. It is not a fetch leg disguised as travel.

### Stage 07 — The Drawing That Wasn't a Drawing
**Action identity:** rigging reconstruction / embodied procedure.  
**Survives because:** the player learns that the archive artifact records gestures and body-relative setup, not a blueprint to copy literally.

### Stage 08 — The Missing Dimension
**Action identity:** contradictory-record interpretation.  
**Survives because:** Palinode is used to reconcile loaded versus unloaded relational dimensions. It converts lore contradiction into a mechanical calibration insight.

### Stage 09 — How It Was Actually Used
**Action identity:** Hush evidence reconstruction.  
**Survives because:** the player reconstructs forces rather than merely copying a pose or watching an echo. It turns historical evidence into practical operating knowledge.

### Stage 10 — Two Correct Calibrations
**Action identity:** seam/reference-frame calibration.  
**Survives because:** the frame must remain safe under two disagreeing observation assumptions instead of forcing one canonical reading.

### Stage 11 — The Court's Confiscated Rack
**Action identity:** evidence-gated recovery / optional encounter synthesis.  
**Survives because:** the useful fitting is reached through Quiet Court records plus one elite encounter and is selected for its open-repair principle, not because it is unique magical loot.

### Stage 12 — No Master Pattern
**Action identity:** final assembly / thematic resolution.  
**Survives because:** multiple regional practices are assembled into one working frame while deliberately refusing a single proprietary master template. This closes both gameplay and narrative meaning.

## Completion counting

The Completion Ledger exposes one item:

`prestige.unstandard.complete`

It becomes satisfied only when Stage 12's final assembly transaction settles successfully.

The twelve stage IDs remain authoritative quest-progression facts, but they do not each add separate global completion weight.

Why:
- twelve separate percentage items would overweight one optional quest family relative to categories containing many unrelated authored experiences;
- stage-by-stage counting would encourage the player to read the arc as checklist fragments instead of one coherent craft story;
- several stages are intentionally dependent chapters rather than independent activities;
- the final reward and thematic closure only exist as a complete sequence.

UI may show `8 / 12 stages` inside the quest journal for progress clarity without treating that as twelve global completion entries.

## Anti-fetch / anti-busywork authority

Every shipping stage must contain at least one authored player action that changes understanding or system state.

Allowed action families:
- diagnosis;
- traversal under a meaningful state constraint;
- tool/system manipulation;
- craft with gameplay-state consequences;
- evidence comparison;
- social interpretation that unlocks a playable next step;
- reconstruction/calibration;
- authored encounter resolution.

Forbidden prestige-stage filler:
- speak to one NPC, receive parcel, speak to another NPC with no intervening playable problem;
- collect N generic ore/fiber/material drops from repeatable world nodes;
- buy an arbitrary expensive ingredient bundle;
- wait real-world time;
- repeat an already-completed Trial only to pad quest length;
- kill a generic number of enemies unrelated to the craft problem;
- return to a previous NPC solely to hear "good job" before the next map marker appears.

Travel may connect stages, but travel itself only qualifies as authored stage gameplay when the state of the carried object, route, vehicle, environment, or investigation makes the journey mechanically meaningful.

## Freehand Frame reward authority

The final **Freehand Frame** identity in `docs/14` is retained.

It is a qualitative optional capability, not a stat reward:
- deliberate brace stance on stable ground;
- slower movement / reduced evasion while fully committed;
- catches or redirects a limited class of high-force impacts;
- stores mechanical load briefly for release into compatible mechanisms or heavy counterplay;
- intentionally poor fit for mobile crowd combat.

### Optional-power ceiling
The Freehand Frame is **never required for the canonical critical path**.

Mandatory traversal, story bosses, and Null Meridian completion must retain valid baseline solutions without it.

Optional content may recognize or exploit the Frame as an alternate solution where appropriate, but the prestige quest cannot secretly become required progression merely because its reward is powerful or interesting.

The reward is granted exactly once on Stage 12 settlement.

## Stage resources / anti-grind

Quest-specific authored components are stateful quest objects, not commodity grind sinks.

Rules:
- naturally shed fiber, couplers, calibration data, confiscated fittings, etc. are unique authored stage facts/objects;
- losing or retrying a stage cannot force the player to re-farm generic materials for hours;
- stage-only consumables are restored or deterministically recoverable after failure;
- ordinary campaign inventory may participate where sensible, but no stage requires randomized rare-drop farming;
- no prestige currency/shop track exists;
- no material quality RNG decides success.

## Failure / retry / abandonment

A prestige stage may fail locally when its gameplay problem permits failure, but the quest family itself is not permanently failed.

Required behavior:
- local mechanical failure resets to a nearby safe authored state;
- already-settled prior stages remain complete;
- stage intro dialogue/cutscene is skippable after first viewing;
- abandon/re-entry restores the current stage's canonical setup or a documented recoverable equivalent;
- quest-specific carried objects cannot be permanently lost by dropping, selling, physics destruction, or world cleanup;
- save/load during stage settlement cannot duplicate output or regress the quest;
- no timed story phase permanently expires the quest.

## Changed-world recovery / missability

The Unstandard Tool must remain completable during the natural late-game 100% sweep.

If an original NPC/location becomes unavailable because the world changed, preserve the authored meaning through a credible successor route, for example:
- NPC relocated to an already-established refuge/workshop;
- notes, apprentices, or workshop records preserve the same knowledge interaction;
- a destroyed rig is rebuilt in a changed-world form;
- confiscated materials move into an authored recovery location.

Recovery must not collapse an active stage into a menu checkbox. The player still performs the meaningful stage action.

Semantic stage IDs remain unchanged across world-state variants.

## Accessibility authority

Accessibility accommodations retain full quest completion and reward authority.

Relevant requirements:
- all stage-critical controls are remappable;
- no stage depends on rapid mashing or unaccommodated simultaneous input holds;
- hold/toggle alternatives apply where existing input authority requires them;
- thermal/pressure/calibration state must be readable through more than color alone;
- sound-dependent information has visual/haptic/textual equivalents where feasible;
- exact timing windows may be widened or dynamic processes slowed when default precision is not the thematic concept being tested;
- Stage 06 may widen vibration-band tolerance, slow clock/state drift, or strengthen instrumentation while preserving the requirement to manage the transport state;
- Stage 07 rigging gestures may use stepwise confirmation rather than requiring fast gesture execution;
- Stage 10 calibration may offer longer observation windows and stronger state labels;
- reduced motion/shake must not remove essential state information;
- quest journal summaries clearly restate the current stage's objective and learned relationship.

Accessibility settings never mark the final Frame or completion item as lesser.

## Quest persistence ownership

Quest/World State owns the twelve stage facts.

Persist:
- current stage / resolved stages;
- stable semantic stage IDs;
- unique quest-object ownership / recovery state;
- stage outputs required by later stages;
- prototype / final Freehand Frame state;
- final reward-settled/idempotency fact;
- final quest-family completion fact.

Completion Ledger derives `prestige.unstandard.complete` from the settled Stage 12 resolution.

Do not derive completion from dialogue playback, quest-journal visibility, item icon presence alone, or a transient cinematic flag.

## Quest / Completion System IDE

The shared workbench must expose:
- quest-family semantic ID;
- all 12 stage IDs and current stage state;
- unlock prerequisites and owning world-state facts;
- stage-specific meaningful-action predicate(s);
- required quest-object/state dependencies;
- failure/reset/recovery point;
- changed-world variant currently selected and why;
- active accessibility modifiers relevant to the stage;
- stage settlement / idempotency;
- Freehand Frame prototype/final ownership;
- final `prestige.unstandard.complete` derivation;
- invalid sequence / skipped-stage validator;
- missing quest-object recovery validator.

Required fixtures:
1. clean start at Stage 01;
2. save/load between every pair of stages;
3. local failure/retry for each mechanically fallible stage;
4. abandon/re-enter current stage;
5. quest-object lost/destroyed/recovered;
6. original NPC unavailable → changed-world recovery route;
7. accessibility-modified forge/transport/rigging/calibration clear;
8. Stage 10 prototype Frame without final completion;
9. Stage 11 resolved with Stage 12 still incomplete;
10. Stage 12 settlement exactly once;
11. duplicate final reward blocked;
12. quest complete while all unrelated optional content remains incomplete;
13. critical path complete without beginning the prestige quest;
14. journal stage count and global completion count remain distinct.

## Red-team / rejection conditions

Revise the prestige quest if:
- any stage becomes a pure parcel-delivery errand;
- a stage requires randomized commodity farming;
- multiple stages test the exact same gameplay relationship with no new meaning;
- the Freehand Frame becomes required for mandatory story completion;
- the twelve stages each receive independent global completion weight;
- a story-state transition makes the chain permanently missable;
- an NPC/object loss can brick progression;
- save/load duplicates a stage output or final reward;
- accessibility options disable completion or the Frame reward;
- stage failure imposes long travel/material punishment unrelated to the skill;
- the chain exists mainly to make the prestige quest feel long.

## Research basis

Fresh review used:
- the full existing twelve-stage contract in `docs/14_PRESTIGE_AND_MASTERY_CONTENT.md`;
- current Microsoft Xbox Accessibility Guidelines on alternate input and timing burdens;
- Nintendo's published Tears of the Kingdom developer interviews as design-lineage evidence for preserving player agency and meaningful interaction rather than treating content as prescribed single-solution chores.

These sources inform design problems only. Stillring's characters, craft fiction, stage structure, mechanics, reward, wording, and exact implementation remain original project authority.

## Approval

**APPROVED / LOCKED under the owner's scheduled-run delegation.**

### Final locked statement

> **The Unstandard Tool keeps all 12 authored stages, but counts as one completion-bearing prestige quest resolved at Stage 12. Every stage must contain meaningful diagnosis, traversal, craft, evidence, social interpretation, calibration, or encounter action; generic errands and material grind do not qualify. The Freehand Frame remains a qualitative optional reward, never critical-path power. Stage progress is persistent and recoverable, accessibility accommodations retain full authority, and the final reward/completion transaction settles exactly once.**

## Next decision

Completion Decision #12 — **Drift Knot authority: validate the current 12 moving traversal hunts, deterministic discovery/tracking, chase/reset semantics, completion event, rewards, accessibility, persistence, IDE, and anti-random-spawn / anti-route-grind constraints.**
