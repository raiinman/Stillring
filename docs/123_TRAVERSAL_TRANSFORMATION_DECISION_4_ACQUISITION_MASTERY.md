# 123 — Traversal Transformation Decision #4 — Line Skiff Acquisition and Mastery Loop

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #10 — Design Stillring traversal transformation and mastery loop  
**Parents:** `docs/120_TRAVERSAL_TRANSFORMATION_DECISION_1_LINE_SKIFF_SELECTION.md`, `docs/121_TRAVERSAL_TRANSFORMATION_DECISION_2_ROUTE_NETWORK_GRAMMAR.md`, `docs/122_TRAVERSAL_TRANSFORMATION_DECISION_3_WORLD_LAYER_ROUTE_STATE.md`  
**Cross-authority:** `docs/13_CANTOR_AND_UPGRADE_CATALOG.md`, `docs/98_COMPLETION_SKILL_TRIAL_AUTHORITY_ADDENDUM.md`, `docs/100_COMPLETION_DRIFT_KNOT_AUTHORITY_ADDENDUM.md`, canonical Movement 9 scene/route contracts  
**Decision:** #4 — acquisition teaching sequence, Roadhand Pulse onboarding, mastery progression, Trial 05 Relay Run, Switchshoe settlement, failure/retry, accessibility, and anti-time-trial-grind rules

## Locked principle

> **Teach the Skiff as a new way to enjoy a road before asking the player to prove mastery of it.**

The acquisition sequence is not a race exam, tutorial popup gauntlet, or crisis-only vehicle chase.

The intended learning arc is:

```text
SEE IT WORK
    ↓
WAKE / COUPLE / MOVE SAFELY
    ↓
ENJOY A KNOWN ROAD AT SPEED
    ↓
LEARN MOMENTUM + ROUTE CHOICE
    ↓
USE ROADHAND PULSE IN CONTEXT
    ↓
PRACTICE IN NORMAL WORLD TRAVEL
    ↓
RELAY RUN MASTERY TRIAL
    ↓
SWITCHSHOE EXPANDS ROUTE POSSIBILITY
    ↓
ADVANCED COURIER / DRIFT KNOT SYNTHESIS
```

The Skiff's skill ceiling comes from **route fluency**, not leaderboard times.

---

# 1. Canonical acquisition context

Existing story authority remains intact:

- the player sees the mothballed Line Skiff at Graymile during the First Circuit;
- Tessa's earlier route/courier history gives the machine social context before it becomes a player tool;
- after Grand Ring, Tessa returns during a moving window using that same route technology;
- the changed-world return is the acquisition moment for usable Line Skiff + `pattern.roadhand_pulse`;
- the first useful ride occurs after the player already knows the affected bell roads on foot.

This matters because the acquisition is a **transformation of remembered geography**, not an excuse to skip an unfamiliar map.

## Emotional pacing

The first controlled Skiff experience must preserve the canonical changed-Brindle pacing goal:

> After catastrophe and loss, the player gets a genuine stretch where movement is simply enjoyable again.

Do not turn Tessa's return into:

- a timed chase before the player knows the controls;
- an exposition-heavy tutorial chamber;
- an immediate Drift Knot hunt;
- a combat gauntlet;
- a failure-prone precision course.

The player should have room to laugh, experiment, look around, and feel the difference in speed.

---

# 2. Tutorial philosophy

Fresh tutorial-design research reinforces a gradual gameplay-first approach:

- GDC tutorial talks such as **Prime, Teach, Observe** and **Teaching by Design** emphasize priming players, introducing one useful concept at a time, then observing whether they can apply it in actual play rather than dumping instructions first;
- accessibility design guidance emphasizes allowing players to practice skills on their own time and adapt controls/assistance before being judged by a mastery challenge;
- high-speed traversal design benefits from a short safe adaptation period before introducing meaningful pressure.

Stillring uses these design problems only; exact tutorial scripting, timings, controls, presentation, and challenges remain original.

## Core teaching rule

> **Every tutorial instruction must immediately correspond to something useful the player is already trying to do.**

No controller-diagram wall listing future inputs before the player needs them.

---

# 3. Acquisition teaching sequence

The exact road art/layout remains content-authoring work, but the semantic teaching order is locked.

## Phase A — Observe: Tessa demonstrates the fantasy

Before the player operates the Skiff, Tessa's arrival visibly proves:

- the machine can use changed-world route strips;
- it carries momentum rather than teleporting between stops;
- it belongs to courier/maintenance infrastructure;
- it can operate without the old central route-bell authority.

The player sees the answer before receiving a tutorial explanation.

## Phase B — Roadhand wake / safe coupling

At a forgiving compatible node, the player learns the minimum semantic relationship:

1. identify/wake compatible reinforcement infrastructure with Roadhand Pulse;
2. couple/board the Skiff;
3. accelerate from rest;
4. deliberately brake/park.

This first exercise has no failure timer.

Roadhand Pulse is introduced as **infrastructure communication**, not magical vehicle ignition and not boost.

## Phase C — Free joy stretch

The player receives a broad, readable, already-familiar route segment with:

- no leaderboard timer;
- no mandatory combat;
- no Drift Knot;
- no precision Switchshoe transfer;
- no instant fail hazard;
- enough space to accelerate, coast, brake, and look around.

The route may include forgiving visual changes that make the new speed exciting, but it must not demand perfect execution.

The design goal is adaptation + pleasure.

## Phase D — Basic handling through useful road events

After the free stretch, the route introduces lightweight authored needs:

- one gentle lateral obstacle/positioning problem;
- one brake/coast opportunity where slowing is obviously useful;
- one readable standard junction;
- one practical park/leave point.

Each demonstrates an existing control rather than adding another button for spectacle.

## Phase E — Roadhand in motion

The first moving Roadhand interaction introduces a dormant-but-compatible route element ahead.

Normal teaching behavior:

- the route clearly communicates that the strip ahead is dormant/wakeable;
- Roadhand Pulse can wake it during a generous approach window;
- success preserves smooth travel;
- missing the input does **not** kill the player or throw the Skiff off-network;
- the route safely decelerates/stops at the appropriate boundary, letting the player Pulse and continue.

This establishes the mastery distinction:

> correct timing preserves flow; understanding the system still lets you proceed if you were late.

## Phase F — Independent normal travel

After the guided first-use sequence, the player gets ordinary Skiff network access according to story/world state.

The game stops tutorializing every action.

The player can naturally practice through:

- cross-region travel;
- courier routes;
- safe optional detours;
- early route-state problems;
- eventually eligible Drift Knots.

Trial 05 is not forced immediately at acquisition.

---

# 4. Roadhand Pulse teaching authority

`pattern.roadhand_pulse` remains mandatory for Line Skiff use, but its learning curve must be understandable without treating it as a generic context button.

## Base concepts taught

The player must learn:

1. compatible physical route infrastructure has recognizable world language;
2. Pulse queries/wakes that infrastructure where source facts permit;
3. not every road is compatible;
4. not every compatible strip is currently wakeable;
5. failure has a reason;
6. Pulse does not choose the route for the player.

## Input burden

Ordinary Roadhand use requires one deliberate remappable action.

No rapid tapping, mashing, rhythm-string, stick gesture, or arbitrary resource consumption is required.

## Timing

For ordinary travel, Roadhand timing windows are generous and late use results in loss of momentum/stop rather than catastrophic failure.

Advanced hunts/mastery may reward earlier recognition and cleaner timing without changing the underlying semantic rule.

## No spam economy

There is no gameplay resource meter whose purpose is to prevent the player from using Roadhand on ordinary compatible route infrastructure.

Implementation may use a short presentation/input debounce to prevent duplicated sound/VFX or repeated event dispatch from one press; this is not a strategic cooldown.

---

# 5. What Line Skiff mastery means

Mastery is **not** top speed.

A skilled player demonstrates:

- efficient acceleration rather than holding forward without thought;
- useful coasting;
- braking before information becomes unreadable;
- preserving momentum through route decisions;
- lateral line choice inside the corridor;
- identifying branch opportunities early;
- committing to the intended junction cleanly;
- recognizing dormant/wakeable infrastructure;
- using Roadhand Pulse without unnecessarily stopping;
- knowing when slowing down is better than maximizing speed;
- recovering from small mistakes without panic/reset;
- after Switchshoe, reading and executing compatible at-speed transfers.

Canonical maxim:

> **Fast is a result of reading the road well, not the only skill the road measures.**

---

# 6. Mastery progression stages

These stages describe player learning, not character XP levels.

## Stage 0 — Recognition

Before acquisition:

- Graymile foreshadowing;
- Tessa route history;
- reinforcement-strip visual language begins entering player memory.

## Stage 1 — Operation

Acquisition tutorial teaches:

- Roadhand wake;
- couple;
- accelerate;
- coast;
- brake;
- park;
- basic lateral placement.

## Stage 2 — Route literacy

Normal post-acquisition use teaches:

- standard branch reading;
- state cues;
- maintaining momentum through familiar roads;
- choosing when to stop for on-foot content;
- first optional moving-route work.

## Stage 3 — Integrated mastery / Relay Run

Trial 05 tests the combined baseline grammar:

- momentum management;
- junction reading;
- route choice;
- Roadhand Pulse;
- recovery after imperfect contact.

The trial proves fluency with the base Skiff, not the Switchshoe.

## Stage 4 — Expanded network / Switchshoe

A qualifying Relay Run awards:

`upgrade.lineskiff.switchshoe`

Switchshoe adds a genuinely new authored route action:

- at-speed transfer between marked adjacent legacy reinforcement strips.

The player now re-reads earlier junctions/routes with a new possibility.

## Stage 5 — Synthesis

Later optional content combines the expanded Skiff grammar with:

- Drift Knots;
- regional tools;
- Crosswind Measure;
- Palinode/Mirror;
- Fine Fork;
- seam mode;
- changed-world route variants.

No second generic `faster Skiff` upgrade tree is required.

---

# 7. Trial 05 — The Relay Run

Canonical ID:

`trial.circuit.line_skiff_relay_run`

Existing location/premise remain:

- old courier loop from Graymile toward Cairnspire outer road;
- three physical relay flags must be delivered through a network whose central routing is dead;
- challenge is momentum + junction timing + route choice + Roadhand Pulse;
- it is not a race against a named rival.

## Trial purpose

The Relay Run answers:

> Can the player read and operate the base route network as one coherent skill instead of merely knowing each button separately?

## Qualifying clear

The existing completion authority remains:

- all three required relay flags are delivered within their generous authored mechanical timing contract;
- collisions do not automatically fail the trial;
- the player may recover from imperfect lines and still qualify;
- completion is binary: semantic mastery clear or not cleared.

## Mechanical clocks, not esports stopwatch

The time pressure belongs to the fiction/mechanism of the relay flags/network.

Player-facing presentation may show how much viable mechanical window remains, but does not turn the trial into a giant global race leaderboard by default.

The qualifying window must be generous enough that:

- route understanding matters more than memorizing a speedrun line;
- one minor collision does not invalidate the run;
- accessibility timing extensions can preserve equal completion;
- the player can make a small recovery decision instead of restarting instantly.

## No rank requirement

100% does not require:

- bronze/silver/gold;
- par-time tiers;
- developer time;
- leaderboard placement;
- perfect route;
- no-collision clear;
- maximum speed;
- repeated clears;
- personal-best improvement.

Optional personal-best display may exist if cheap/useful, but it carries:

- no completion weight;
- no unique mandatory upgrade;
- no hidden story state;
- no superior canonical result.

---

# 8. Trial route design

The Relay Run must combine baseline Skiff concepts rather than introduce unrelated gimmicks.

A valid course should include:

- an opening acceleration/coasting decision;
- at least one branch where reading the route matters;
- at least one dormant compatible section requiring Roadhand;
- at least one reason to brake or shed speed intentionally;
- at least one line-placement/collision-recovery opportunity;
- three delivery interactions whose locations make route planning meaningful;
- a clear safe finish/settlement node.

Do not include Switchshoe-required transfers in the qualifying course because Switchshoe is the reward.

The course may visually preview legacy transfer sites that become newly usable afterward.

---

# 9. Failure and retry

## Failure reasons

A run may fail semantically because:

- a required relay flag's mechanical window expires;
- the player abandons/leaves the trial boundary;
- an authored unrecoverable trial condition occurs.

Minor collision, braking, imperfect line choice, or briefly stopping are not automatic failures.

## Immediate clarity

Failure must state the practical reason in player-facing terms.

Do not merely flash `FAILED` while hiding which flag/window was lost.

## Retry cost

Retry requires:

- no currency;
- no consumable ticket;
- no long cross-region return trip;
- no full reload through unrelated story content.

After failure, the course returns to a stable semantic trial staging/restart state quickly.

Exact presentation may be an in-world relay reset rather than a menu loading screen.

## Partial delivery settlement

A failed attempt does not permanently settle partial flag delivery for the qualifying clear.

The next attempt starts from the trial's authored initial relay state.

This is trial state, not a rewritten world-history fact.

## Save/load

Saving/loading cannot manufacture a qualifying clear from a partially completed failed attempt or duplicate the Switchshoe reward.

Mid-trial save behavior may restore to a deterministic staging/restart state unless broader save authority later explicitly supports exact trial resume.

---

# 10. Practice and re-entry

Players should be able to practice Skiff handling without wagering a trial attempt.

The ordinary network is the primary practice space.

The Relay Run may additionally provide a development/content-supported **practice/no-settlement mode** if playtesting shows it useful, especially for:

- learning the course;
- testing new control mappings;
- accessibility calibration;
- returning after a long break.

Practice mode:

- does not award the semantic Trial clear;
- does not consume resources;
- may omit/relax mechanical flag expiry;
- uses the same route/vehicle systems rather than a fake simulator.

A practice option is recommended but not required if ordinary route access already provides sufficient low-pressure rehearsal in human testing.

---

# 11. Switchshoe acquisition / settlement

A qualifying Relay Run settles the canonical upgrade:

`upgrade.lineskiff.switchshoe`

## Semantic settlement

The Skill Trial authority owns the qualifying clear.

Progression/Tool authority owns Switchshoe acquisition.

The reward transaction must be idempotent:

- first qualifying clear settles Trial 05 exactly once;
- Switchshoe acquisition settles exactly once;
- replay cannot duplicate a permanent upgrade/reward;
- load/re-entry cannot temporarily remove the upgrade after the trial is settled.

## Presentation

Exact installation animation/dialogue may be authored around Tessa/route infrastructure, but presentation does not own the upgrade fact.

## Immediate teaching payoff

Soon after acquisition, the player should receive a safe/readable opportunity to use an at-speed marked legacy transfer.

The upgrade should not sit dormant for hours after being earned.

This first Switchshoe use is not another mandatory mastery exam; it demonstrates the newly opened possibility.

---

# 12. Post-Switchshoe mastery

Switchshoe expands expression without adding a new grind tier.

After acquisition, mastery becomes:

- recognizing transfer-capable junctions;
- selecting the correct adjacent strip early enough;
- preserving useful momentum through transfer;
- combining transfer with Roadhand route state;
- later combining with Drift Knot and regional tool states.

There is no requirement to level Switchshoe, purchase transfer charges, or beat a faster version of Relay Run to keep it functional.

---

# 13. Relationship to Drift Knots

Drift Knots remain a separate completion-bearing hunt family under `docs/100`.

The Skiff mastery loop prepares the player for them but does not collapse them into the mastery trial.

Sequence:

1. acquire Skiff/Roadhand;
2. gain normal route fluency;
3. Drift Knot family becomes eligible at its locked story + Line Skiff + 10 reconciled Fault prerequisites;
4. base Knots test route pursuit plus regional relationships;
5. Relay Run may be completed before or during the broader hunt period according to natural player order;
6. Switchshoe enables advanced authored transfer problems such as Outer Loop Stutter;
7. later Knots synthesize more tools rather than only demanding more speed.

Trial 05 is one mastery proof.

Drift Knots are twelve authored moving route faults.

Do not turn one into the other.

---

# 14. Accessibility authority

Accessible mastery earns identical completion and Switchshoe authority.

Required support where practical includes:

- fully remappable Skiff/Roadhand/trial inputs;
- acceleration Hold/Toggle or equivalent low-fatigue option if testing supports it;
- configurable steering sensitivity/dead zones;
- corridor-centering steering assistance that does not choose branches;
- widened branch-intent windows;
- wider Roadhand timing/readability windows;
- reduced Skiff/trial relative speed where needed;
- longer relay-flag mechanical windows;
- reduced camera shake/motion intensity;
- high-contrast/redundant route-state and flag-timer cues;
- visual/haptic alternatives for essential audio cues;
- pause-safe trial objective review;
- no rapid mash or simultaneous-input requirement without accessible alternative.

## Equal authority

Using an accessibility timing, speed, steering, or presentation accommodation:

- does not mark the Trial clear as assisted/inferior;
- does not reduce reward;
- does not disable Switchshoe;
- does not alter completion weight;
- does not change story legitimacy.

The cognitive skill that remains is understanding the route/system relationship appropriate to the player's configured experience.

---

# 15. Player-facing failure/help escalation

The game may provide stronger instructional support after repeated trouble, but it must not become condescending or automatically solve the course.

Potential escalation, gated by human UX testing:

1. normal failure reason;
2. clearer reminder of the specific lost mechanical window/route state;
3. optional stronger route-state/junction readability assistance;
4. optional practice mode / accessibility adjustment suggestion.

Do not:

- secretly steer the correct branch after several failures;
- auto-complete the trial;
- shame the player;
- lock the upgrade behind refusing assistance.

---

# 16. System IDE additions

The Line Skiff / Route Network workbench must add an **Acquisition & Mastery** surface.

## Acquisition tutorial inspection

Expose:

- current teaching phase;
- required semantic skill/action;
- prompt state;
- prompt suppression/completion reason;
- input event received;
- route state when input occurred;
- success/fallback result;
- player speed/lateral state;
- Roadhand candidate/result;
- whether free-joy stretch remains unpressured as authored.

## Mastery profile telemetry

Development-only, non-retail scoring may inspect:

- acceleration/coast/brake usage;
- speed lost to late braking;
- lateral edge scrub;
- junction approach speed;
- branch-intent timing;
- Roadhand timing;
- minor collisions;
- recovery duration;
- stop frequency.

This is tuning evidence, not a hidden retail player grade.

## Trial 05 inspection

Expose:

- trial semantic ID/state;
- each relay flag state;
- each mechanical window remaining;
- current route segment/node;
- current intended/committed branch;
- Roadhand events;
- collision/recovery events;
- active accessibility modifiers;
- qualifying-clear predicate;
- exact failure reason;
- settled clear fact;
- Switchshoe reward settlement/idempotency.

## Exercise / validate

At minimum:

- run each acquisition tutorial phase independently;
- skip/interrupt/re-enter tutorial safely;
- test missed Roadhand moving window fallback;
- test first park/leave/reboard;
- start Trial 05 clean;
- expire each relay flag independently;
- collide and still qualify;
- test route branch alternatives;
- test widened accessibility window;
- test reduced-speed accessibility clear;
- fail/retry repeatedly;
- save/load before, during, and after trial;
- replay after clear;
- verify Switchshoe settles once;
- exercise first post-reward transfer.

The IDE must use the same gameplay Trial/Route/Progression services as retail.

---

# 17. Deterministic Decision #4 fixtures

Future implementation evidence must prove at minimum:

1. Tessa/Graymile foreshadow precedes player acquisition in canonical progression;
2. first Roadhand wake/coupling can be completed without timer pressure;
3. free-joy stretch contains no hidden mastery clock/failure gate;
4. accelerate/coast/brake can be learned independently before complex route challenge;
5. first standard junction is readable at intended beginner speed;
6. missed tutorial Roadhand timing produces safe stop/retry rather than death/reset;
7. acquisition completes without Switchshoe;
8. ordinary Skiff travel remains available for practice before Relay Run;
9. Trial 05 requires all three flag deliveries under its authored mechanical-window predicate;
10. minor collision does not automatically fail the trial;
11. no rank/par/leaderboard score is required for completion;
12. failure identifies the exact semantic reason;
13. retry requires no currency/long return trip;
14. failed partial delivery cannot leak into a fresh qualifying attempt;
15. accessibility-expanded timing still produces identical Trial completion;
16. steering assistance never chooses a branch;
17. first qualifying clear settles Trial 05 once;
18. Switchshoe settles exactly once from qualifying clear;
19. replay after clear cannot duplicate reward;
20. first post-Switchshoe transfer demonstrates at-speed adjacent-strip possibility;
21. Switchshoe never becomes a speed-stat requirement;
22. advanced Drift Knot content can consume Switchshoe without making every Knot a speed race;
23. save/load cannot manufacture Trial clear or lose settled Switchshoe ownership;
24. System IDE can explain tutorial/trial/reward state in one trace.

---

# 18. Rejection conditions

Reject/revise implementation if:

- the first playable Skiff sequence begins with a meaningful failure timer;
- tutorial front-loads a large control diagram or text dump;
- the player is judged before receiving a safe adaptation/joy period;
- Roadhand is taught as a boost rather than route infrastructure interaction;
- ordinary Roadhand use requires mashing/resource farming;
- mastery is defined mainly as holding maximum acceleration;
- Trial 05 is a named-rival race;
- completion requires bronze/silver/gold/par time/leaderboard placement;
- one minor collision automatically invalidates a run;
- failure requires a long world traversal to retry;
- retry consumes currency/items;
- accessibility assistance disables completion or Switchshoe;
- Switchshoe is obtained before base route fluency is demonstrated;
- Switchshoe's primary effect becomes increased top speed;
- qualifying Trial clear and reward settlement can duplicate on replay/load;
- tutorial scripts use fake movement/network state different from actual gameplay services;
- the acquisition sequence forgets the intended emotional beat of joy/agency after catastrophe.

---

# Research basis

Fresh research used for this decision includes:

- GDC `Prime, Teach, Observe: Tutorializing Innovative Mechanics` — prime players, teach in context, then observe application rather than front-loading explanations;
- GDC `Teaching by Design: Tips for Effective Tutorials from Mushroom 11` — gradual focused teaching through actual gameplay with limited hand-holding;
- GDC accessible-player-experience guidance — provide low-pressure training/practice opportunities so players can gain competence with their chosen control/accessibility setup;
- traversal/onboarding literature emphasizing an initial adaptation/play period before meaningful high-speed challenge;
- existing Stillring Trial 05, Roadhand Pulse, Switchshoe, Drift Knot, story, camera, and completion authority.

These sources inform teaching/accessibility problems only. Stillring's exact acquisition sequence, route trial, fiction, inputs, upgrade, content, and values remain original.

## Approval

**APPROVED / LOCKED under the owner's prior locomotion/traversal delegation and current instruction to continue.**

## Final locked statement

> **The Line Skiff acquisition teaches by doing in a fixed progression: observe Tessa use the seeded infrastructure, safely wake/couple/accelerate/brake, receive an unpressured fun stretch, then learn route positioning, junctions, parking, and Roadhand-in-motion before normal world practice. Trial 05 Relay Run comes after the player has had ordinary practice and tests integrated momentum, route choice, junction reading, and Roadhand Pulse through three physical relay deliveries with a generous authored mechanical window. Collisions do not automatically fail; no rank/par/leaderboard/perfect-route requirement carries completion weight. Accessible timing/steering/speed support receives identical completion. A qualifying clear settles Switchshoe exactly once, adding authored at-speed adjacent-strip transfers rather than a speed-stat upgrade.**

## Next decision

Issue #10 Decision #5 — **Drift Knot / optional-system network integration and route coverage:** how the 12 hunts distribute across the Skiff network, how ordinary courier/service content keeps the Skiff useful beyond hunts, route coverage density, discovery/reacquisition, cross-tool synthesis, and anti-content-bloat / anti-racing-repetition rules.
