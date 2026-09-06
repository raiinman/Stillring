# 125 — Issue #10 Traversal Transformation / Mastery Closure Audit

**Status:** DESIGN / DOCUMENTATION CLOSURE CANDIDATE  
**Updated:** 2026-09-05  
**Issue:** #10 — Design Stillring traversal transformation and mastery loop  
**Authority set:** `docs/120` through `docs/124`

## Purpose

This audit determines whether Issue #10 is complete as **design/documentation authority** while preserving the boundary that UE5.8 implementation, performance, feel, and human-play evidence remain unproven.

---

# 1. Original goal — PASS at design level

Issue #10 asks for a midgame traversal transformation that materially changes route planning and supports optional systems without becoming a horse analogue.

The locked answer is the **Line Skiff**:

- physically present Orra-native courier/maintenance infrastructure;
- foreshadowed through Tessa + Graymile before acquisition;
- acquired after Grand Ring on the changed-world return;
- bound to authored reinforcement-strip networks;
- faster/more expressive than ordinary known-road travel;
- not summon-anywhere;
- not free-roam cross-country;
- not a combat mount;
- not ordinary fuel/stamina/ticket grind;
- not universal fast travel;
- preserves on-foot last-mile exploration and later authored traversal verbs.

Detailed selection authority: `docs/120_TRAVERSAL_TRANSFORMATION_DECISION_1_LINE_SKIFF_SELECTION.md`.

---

# 2. Acceptance criterion — three concepts evaluated — PASS

Decision #1 evaluates:

1. **Line Skiff / resonance road-sled** — SELECTED;
2. **Wind-rig / updraft travel** — REJECTED as the midgame transformation because it overlaps Vane/High Aerie identity, widens 3D camera/world scope, and risks vertical-puzzle bypass;
3. **Maintenance Strider** — REJECTED because it behaves too much like a conventional mount and creates disproportionate terrain/IK/collision/dismount/pathing scope.

Evaluation covers:

- existing story foreshadowing;
- timing fit;
- Orra-native fiction;
- horse-analogue avoidance;
- movement/camera architecture;
- authored-puzzle preservation;
- production cost;
- Drift Knot fit;
- mastery fit;
- Hush/Stillness potential;
- existing-canon churn.

---

# 3. Acceptance criterion — one concept selected for prototype — PASS

Selected prototype direction:

> **Line Skiff as a route-bound network vehicle.**

Core maxim:

> **It makes authored roads newly expressive; it does not replace the world between them.**

The concept is already integrated with canonical story timing, `pattern.roadhand_pulse`, Trial 05, Switchshoe, and Drift Knots.

---

# 4. Acceptance criterion — route/network requirements documented — PASS

Decision #2 (`docs/121`) locks:

- stable semantic route IDs `skiff.route.<region>.<slug>`;
- stable semantic node IDs `skiff.node.<region>.<slug>`;
- semantic graph authority over spline/Actor/map identity;
- route segment/node definitions;
- acceleration/coasting/braking/low-speed reverse;
- bounded lateral corridor control;
- route-edge scrub/resistance;
- standard junction player intent;
- safe no-default junction stopping;
- Roadhand Pulse infrastructure semantics;
- pre/post-Switchshoe adjacent-strip transfer grammar;
- compatible-node boarding/parking/dismount;
- no ordinary high-speed dismount;
- collision/failure/recovery policy;
- on-foot content preservation;
- camera/manual-look authority;
- accessibility requirements;
- save/resume boundary;
- Line Skiff / Route Network System IDE.

Locked control philosophy:

> **The authored network owns the Skiff's macro route; the player owns momentum, lateral placement, junction intent, and moment-to-moment execution.**

---

# 5. Acceptance criterion — Hush/Stillness interaction documented — PASS

Decision #3 (`docs/122`) reconciles Line Skiff with Hush and Save/World-State authority.

Locked separation:

- Story/World State owns durable Stillness/route-history facts;
- Hush/World-Layer owns active semantic layer (`Waking` / `Hush`);
- Route Network derives current legal Skiff traversal and paired route continuity;
- Runtime Data Layers/streaming remain representation, not semantic save truth.

A Waking↔Hush shift while riding is legal only where the route explicitly declares a deterministic paired continuation and destination occupancy can be validated before Hush commit.

No authored route contract = seam request rejected before commit.

Decision #3 also defines:

- Shared Invariant / Paired Expression / Layer Exclusive / Related Distinct route relationships;
- route expression versus stable route identity;
- Roadhand Pulse inability to override destroyed/story/tool-gated roads;
- occupied-segment continuity contracts for non-deferrable world changes;
- semantic route repair/reroute settlement;
- changed-world route replacement identity;
- Drift Knot completion safety;
- save/reload ordering and node migration/recovery;
- Hush/Route/Save workbench integration.

---

# 6. Acceptance criterion — optional hunt hook defined — PASS

Decision #5 (`docs/124`) integrates the existing 12 Drift Knots with the Skiff network.

The canonical catalog remains:

1. Graymile Bellwake;
2. Reedrunner;
3. Breakwater Skip;
4. Ashline Flicker;
5. Outer Loop Stutter;
6. Downline Crosswind;
7. Reedglass Flicker;
8. Night Arc;
9. Rootmere Afterimage;
10. False Harbor Line;
11. Quench Runner;
12. Blackline Knot.

The hunts:

- use deterministic authored route corridors;
- reuse ordinary/story/courier infrastructure where practical;
- escalate through different route/tool reasoning rather than speed alone;
- retain loss/reacquisition semantics from `docs/100`;
- remain completion-safe across changed-world route variants;
- may not become 12 disconnected racetracks;
- do not create a separate route-discovery completion category.

Eligibility authority is **10 reconciled Resonance Faults + existing story/Line Skiff prerequisites** under `docs/104`.

Older fixed **13-Fault** literals are superseded and must not be implemented.

---

# 7. Acceptance criterion — mastery activity defined — PASS

Decision #4 (`docs/123`) locks Trial 05:

`trial.circuit.line_skiff_relay_run`

Mastery tested:

- acceleration;
- coasting;
- braking judgment;
- momentum preservation;
- route/junction reading;
- route choice;
- Roadhand Pulse;
- recovery after imperfect contact.

Three physical relay flags must be delivered under generous authored mechanical timing.

Completion does **not** require:

- bronze/silver/gold;
- leaderboard placement;
- developer time;
- perfect/no-collision run;
- maximum speed;
- repeated clears;
- personal-best improvement.

A qualifying clear settles Trial 05 and grants `upgrade.lineskiff.switchshoe` exactly once.

Switchshoe changes route possibility—at-speed transfer between authored adjacent legacy strips—rather than becoming a speed-stat upgrade.

---

# 8. Foreshadowing requirement — PASS

Line Skiff is intentionally seeded before acquisition:

- mothballed Skiff at Graymile during First Circuit;
- Tessa's prior route/courier history;
- post-Grand-Ring Tessa arrival using the same infrastructure;
- Roadhand Pulse learned during changed-world return.

The object is therefore part of Orra before it becomes a player mobility reward.

---

# 9. Faster / more expressive cross-region travel requirement — PASS at design level

The late-game network is required to meaningfully approach every major region where story/world state permits.

Network family includes:

- trunk corridors;
- hub approaches;
- regional spurs;
- legacy/maintenance lanes;
- hazard/hunt segments;
- the authored mastery course.

Trunks should materially improve travel time/flow over ordinary Sprint on known long connectors while hub approaches return the player to place-scale/on-foot exploration.

Exact speed values and whether the transformation **feels** sufficiently meaningful remain runtime/human tuning evidence.

---

# 10. Limitation / authored-space preservation requirement — PASS

Hard limits include:

- no arbitrary off-network travel;
- no summon-anywhere vehicle;
- no pocket inventory Skiff;
- no all-road conversion;
- no baseline mounted combat tree;
- no ordinary high-speed dismount exploit;
- no universal free-climbing/vertical bypass;
- no generic full-speed mounted use of every tool;
- no high-speed penetration of every social hub;
- no replacement of the last meaningful on-foot exploration stretch;
- no ordinary fuel/stamina travel tax.

Tool interactions while riding require explicit Route Tool Interaction Contracts.

---

# 11. Accessibility cumulative contract

Issue #10 design requires equal completion/reward authority under accessibility accommodations.

Across Decisions #2–#5 the system supports where needed:

- remappable Skiff/Roadhand/Park/junction/trial inputs;
- analog sensitivity/dead-zone tuning;
- acceleration Hold/Toggle or low-fatigue equivalent where testing supports it;
- steering assistance that keeps the player inside the valid corridor without choosing branches;
- widened junction intent windows;
- widened Roadhand interaction windows;
- reduced challenge/relative speed;
- longer Relay Run mechanical windows;
- reduced camera shake/motion intensity;
- stronger route-edge/junction/state contrast;
- visual/haptic alternatives for essential audio-only information;
- pause-safe objective review;
- no required rapid mashing or unsupported simultaneous-input gate.

Accessible completion:

- is not marked inferior;
- does not disable Trial 05 completion;
- does not disable Switchshoe;
- does not reduce Drift Knot authority/rewards;
- does not change global completion weight.

---

# 12. Save/reload cumulative contract

Durable semantic facts belong to their source systems.

Persist as needed:

- Skiff acquisition;
- Switchshoe acquisition;
- durable world/route facts;
- stable parked/recovery node;
- route/world variant where necessary;
- settled Trial/Hunt/reward facts.

Do not require frame-perfect persistence of:

- spline coordinate;
- lateral centimeters;
- instantaneous velocity;
- transient collision state;
- camera state.

Load may restore to a deterministic safe semantic resume/recovery point.

It may not:

- duplicate the Skiff;
- strand it off-network;
- bypass route gates;
- duplicate rewards;
- lose legitimate Trial/Hunt/world settlement.

Waking/Hush save follows Gate 4 semantic snapshot authority and never records a half-seam transition.

---

# 13. Performance / production contract

The network is selective partly because high-speed travel multiplies world-production cost.

Every sustained-speed route needs evidence for:

- World Partition/streaming readiness;
- HLOD/pop stability;
- collision continuity;
- junction sightlines;
- camera lookahead/occlusion;
- audio transitions;
- route-state changes;
- safe stop/recovery;
- changed-world/Hush representation;
- expected encounter/NPC streaming.

Current UE5.8 World Partition/Data Layer representation remains subject to real prototype performance proof.

If the Skiff outruns world readiness, that is a performance/content failure to solve—not automatic permission for unexplained invisible throttling.

---

# 14. System IDE cumulative closure contract

A dedicated **Line Skiff / Route Network** workbench is required inside the shared development shell.

It must use authoritative gameplay services and expose at least:

## Network / semantic truth
- route IDs;
- node IDs/types;
- endpoints;
- graph connectivity;
- route/world/layer expressions;
- source facts and owners;
- availability/block reasons;
- park/recovery nodes;
- Hush pairing/continuity.

## Live handling
- control state;
- speed;
- throttle/coast/brake;
- lateral offset;
- route-edge correction/scrub;
- junction window/intent/commit;
- Roadhand request/result;
- Switchshoe transfer eligibility/result;
- collision/recovery state.

## Camera/accessibility
- active Skiff camera state;
- travel-direction frame;
- follow/manual override;
- junction lookahead;
- active accessibility modifiers.

## Mastery
- acquisition tutorial phase;
- Trial 05 state;
- flag timers/state;
- failure reason;
- qualifying-clear predicate;
- Switchshoe settlement/idempotency.

## Optional systems
- Drift Knot route/variant allocation;
- signal/reacquisition state;
- route-tool interaction contract;
- Route Listener derivation;
- courier/story/community consumers.

## Validation
- off-network bypass detector;
- unreachable-safe-node audit;
- first-visit/before-memory bypass audit;
- high-speed hub intrusion audit;
- route graph orphan/access audit;
- Hush pair/occupancy audit;
- changed-world Drift Knot availability audit;
- duplicate semantic ID audit;
- one-off expensive route/content-bloat review;
- high-speed performance evidence capture.

The workbench ships disabled/removed according to shared System IDE authority and never becomes a retail remote-debug surface.

---

# 15. Consolidated deterministic fixture matrix

Implementation evidence for Issue #10 must eventually include at least:

### Concept / authored-boundary
1. Skiff cannot free-roam off supported network;
2. cannot summon to arbitrary player position;
3. owning Skiff does not alter baseline on-foot traversal eligibility;
4. no normal fuel/stamina/ticket tax blocks ordinary use.

### Handling / network
5. accelerate/coast/brake player authority;
6. meaningful bounded lateral control;
7. route-edge scrub instead of invisible bounce;
8. readable standard-junction branch intent;
9. no quest-marker auto-branching;
10. safe no-default junction stop;
11. practical Park request and last-mile access;
12. minor collision momentum loss without automatic failure;
13. major blocked route controlled safe stop.

### Roadhand / Switchshoe
14. Roadhand wakes compatible dormant route;
15. Roadhand rejects destroyed/story/tool-gated route with reason;
16. Roadhand never behaves as generic boost;
17. pre-Switchshoe legacy transfer requires stop/re-couple where authored;
18. post-Switchshoe supported adjacent-strip transfer succeeds at speed;
19. Switchshoe cannot hop to unsupported/off-network geometry.

### Hush / changed world
20. route legality derives from semantic facts, not Data Layer visibility;
21. legal paired seam preserves deterministic Skiff continuity;
22. unsupported seam rejects before commit;
23. Neris and controlled Skiff cannot split across semantic layers;
24. world event cannot invalidate occupied route without continuity contract;
25. semantic repair/reroute settles coherently;
26. changed-world route retains or replaces semantic identity correctly.

### Acquisition / mastery
27. acquisition starts with non-timed safe teaching;
28. free-joy stretch has no hidden mastery timer;
29. first moving Roadhand miss falls back safely;
30. ordinary practice exists before Trial 05;
31. Trial 05 requires all three authored deliveries;
32. minor collision can still qualify;
33. no completion rank/par/leaderboard requirement;
34. retry is local and resource-free;
35. accessibility timing/steering/speed support earns same clear;
36. Trial clear and Switchshoe settle exactly once.

### Optional/network portfolio
37. network meaningfully approaches all major regions in late-game state where allowed;
38. social hubs retain last-mile/on-foot identity;
39. all 12 Drift Knots have valid route/changed-world variants;
40. lost Knot is deterministically reacquirable;
41. later Knots change reasoning, not only speed;
42. route-tool interactions obey explicit contracts;
43. route discovery does not create a hidden completion category;
44. no required repeatable courier grind;
45. Route Listener remains bounded after 12/12.

### Save / camera / performance
46. save/load during travel returns to valid semantic resume state;
47. no Skiff/reward duplication after load/replay;
48. manual camera input remains authoritative at speed;
49. reduced-motion camera remains route-readable;
50. representative trunk can stream/render/collide at target Skiff speed without unacceptable pop/stall;
51. Hush/changed-world route transition meets performance/readiness budget;
52. human player can read junctions and choose routes on first reasonable approach.

---

# 16. Stale/superseded traversal literals

## Drift Knot family unlock

Older `docs/14` / `docs/100` material may still mention a fixed **13 Resonance Fault** unlock.

That literal is superseded.

Current authority:

> **10 reconciled Resonance Faults + existing story/Line Skiff prerequisites**

Source: Completion Decision #16 reconciliation in `docs/104`.

Do not implement 13.

## Candidate concepts

Issue #10's original candidate list remains historical problem framing.

Current authority is Line Skiff selection in `docs/120`; wind-rig and maintenance strider are rejected as the primary midgame traversal transformation.

## Existing Roadhand / Switchshoe authored content

`docs/13`, `docs/98`, `docs/100`, story/progression documents remain useful content sources where consistent.

Newer `docs/120`–`docs/125` control conflicts in Line Skiff concept, network grammar, Hush/world-state handling, acquisition/mastery, and network integration.

---

# 17. Runtime evidence explicitly NOT claimed

Closing Issue #10 as design/documentation complete does not claim:

- UE5.8 Skiff pawn/controller implementation;
- semantic route-graph implementation;
- route spline/corridor authoring tools;
- Roadhand runtime implementation;
- Switchshoe runtime implementation;
- Skiff camera tuning;
- World Partition streaming at target speed;
- Hush paired-route runtime transitions;
- save/reload implementation;
- Trial 05 playable implementation;
- Drift Knot playable implementation;
- Route Listener implementation;
- Line Skiff / Route Network System IDE implementation;
- accessibility implementation;
- performance acceptance;
- human confirmation that the Skiff feels fun, fast, readable, and transformative;
- human confirmation that it does not trivialize on-foot spaces.

These are later implementation/verification/play gates.

---

# 18. Closure conclusion

**Issue #10 is design/documentation complete once this closure package merges.**

Every original acceptance criterion has explicit authority:

- three concepts evaluated;
- one selected;
- route/network requirements documented;
- Hush/Stillness interaction documented;
- optional hunt hook defined;
- mastery activity defined;
- foreshadowing preserved;
- faster/more expressive known-world travel specified;
- limitations preserve on-foot authored spaces.

Remaining uncertainty is implementation/runtime evidence, not missing design policy.

The next unresolved design issue is:

**Issue #11 — Define Null Meridian synthesis trial matrix.**

Issue #11 is outside the owner's prior locomotion/traversal auto-approval delegation. Future work should research and present its substantive owner decisions for explicit review rather than silently auto-locking them.
