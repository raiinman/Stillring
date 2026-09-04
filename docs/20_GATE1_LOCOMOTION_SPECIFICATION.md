# 20 — Gate 1 Locomotion Specification

**Status:** detailed locomotion authority — owner final review pending  
**Updated:** 2026-09-04  
**Scope:** player locomotion only; camera composition, combat actions, animation production, and world-content authoring remain governed elsewhere.

## Authority and review protocol

This file is the implementation-facing accumulation of settled Gate 1 locomotion behavior. It complements `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md`: the lineage file explains the design reasoning; this file states the movement contract Claude may implement.

The owner has delegated approval for the remaining **locomotion-only** decisions in this workstream so the specification can be completed without stopping for approval after every step. Each meaningful choice must still be reasoned through, documented, reviewed in diff, and merged separately or in an explicitly scoped locomotion decision PR. This delegation does **not** extend to camera, combat, story, world design, tools outside their locomotion override semantics, or other systems.

The complete locomotion specification remains **pending final owner review** before Issue #1 can be considered closed/final.

Governing principle:

> **Simple intention, capable character, honest world.**

---

## 1. Ground locomotion — LOCKED

- Exploration movement is camera-relative and analog on controller.
- Useful low-speed careful movement remains available below ordinary run.
- Stairs, small steps, minor floor lips, and ordinary uneven ground resolve automatically.
- Neris has an always-available modest deliberate jump.
- Major cliffs and meaningful height gates remain authored traversal problems.
- Traversal affordances must be visually honest.

### Sprint

- Sustained sprint is available from the beginning.
- Ordinary sprint has no stamina/resource cost and may be sustained indefinitely.
- Sprint supports Hold and Toggle; Hold is default.
- Sprint is separate from combat evade.
- Ordinary sprint steering is highly responsive.
- Hard reversals briefly shed momentum and use a quick planted turn/re-acceleration rather than instant full-speed reversal or a large turning circle.
- Sprint → jump preserves existing horizontal sprint momentum and adds no bonus speed.
- Landing returns to/continues sprint when still requested and no higher-priority state overrides it.
- Acquiring target lock ends exploration sprint without hard-zeroing velocity; a short natural deceleration/pivot settles into target-relative combat locomotion.
- Full exploration sprint is unavailable while target-locked.

Exact speeds and curves remain Gate 1 tuning unless separately locked below.

---

## 2. Mantle / scramble — LOCKED

- Low-obstacle mantle/scramble is automatic from clear movement or jump intent.
- There is no separate mantle button.
- Automatic mantle requires valid geometry, reachable landing/top, appropriate approach, sufficient clearance/standing space, and no conflicting higher-priority state.
- Passing near, brushing, or moving parallel to geometry must not trigger a mantle.

Body-relative scope:
- knee → waist: fluent ordinary traversal;
- waist → lower chest: baseline mantleable with clearly deliberate direct approach/jump intent;
- shoulder height and above: not baseline auto-mantle territory.

Exact centimeters, approach angles, detection volumes, animation choices, and timing remain Gate 1 tuning tied to Neris's actual scale.

---

## 3. Ledge catch / hang / shimmy / pull-up / drop — LOCKED

### Catch

- Above the mantle band, a valid reachable ledge may be caught automatically when jump/fall trajectory and directional intent clearly communicate the attempt.
- There is no dedicated grab button.
- Catch requires plausible reach, valid handhold/hang geometry, clear intent, and no conflicting higher-priority state.
- Incidental proximity, sideways/parallel passes, wall brushing, implausible rescue distance, and arbitrary cliff falls do not trigger catch.
- Every successful catch enters a real hang state before any continuation.

### Hang and pull-up

- Neutral movement remains hanging.
- Continued toward/up intent requests pull-up with no separate climb button.
- Pull-up completes only onto a valid, standable, sufficiently clear top.
- Invalid or blocked tops leave Neris hanging.

### Shimmy

- Left/right input shimmies along the same continuous valid handhold.
- Releasing lateral input holds the current position.
- Baseline shimmy does not wrap corners, cross gaps, change walls/ledges, jump laterally, or move vertically between handholds.
- Reaching a prohibited boundary stops cleanly rather than inventing continuation.

### Drop / release

- Letting go requires a distinct deliberate Drop/Release action press.
- Analog down, away, diagonal-down, partial-stick input, drift, or dead-zone noise never releases a ledge.
- A deliberate Drop/Release press acts promptly with no hold-to-confirm delay.
- Physical binding remains remappable control-layout/accessibility policy.

---

## 4. Broader climbing boundary — LOCKED

- Neris has no baseline universal/free-climbing capability beyond the ledge grammar above.
- Ordinary rough walls, cliffs, masonry, roots, rock faces, and similar surfaces do not become climbable merely because they look physically grippable.
- Catch → hang → same-handhold shimmy → pull-up/drop does not chain into vertical free climbing or corner traversal.
- Broader climbing exists only through explicitly authored traversal structures, tools, or later capabilities.
- Supported climbing uses a consistent visible world language rather than hidden arbitrary climb flags on visually equivalent geometry.
- This boundary explicitly protects authored traversal puzzles, route memory, and progression from universal surface solvability.

---

## 5. Authored ladders — LOCKED

### 5.1 Player-driven ladder movement

Once Neris is attached to a valid authored ladder:

```text
up input       → climb up
down input     → climb down
neutral input  → hold current ladder position
camera input   → player retains camera control
```

- Entering a ladder never starts an automatic ride/climb sequence.
- Exact ladder speed, acceleration, alignment tolerance, hand/foot cadence, and animation timing remain Gate 1 tuning.

### 5.2 Ladder mounting

Neris automatically mounts a valid authored ladder from **clear deliberate movement intent** when the entry path and alignment are valid. There is no separate ladder-interact button.

Required safeguards:
- Neris is approaching a valid ladder entry region rather than merely passing near the ladder;
- movement intent is directed into/toward the ladder strongly enough to communicate traversal intent;
- approach/alignment are physically plausible for the authored entry;
- the ladder has a valid attach position and no blocking geometry/state;
- a higher-priority locomotion/action state may prevent the mount when explicitly designed to do so.

Must **not** mount from:
- incidental proximity;
- brushing the ladder sideways;
- moving parallel past it;
- camera orientation alone;
- standing nearby with neutral movement;
- stick drift/dead-zone noise.

The mount may use a short authored alignment transition, but it may not magnetically pull Neris from an implausible offset or long distance.

### 5.3 Ladder top/bottom dismount

Ladder-end dismount is a fluent continuation of the player's existing climb direction; it does not require a separate interaction button.

At the **top**:
- when Neris reaches the valid upper exit and the player continues pressing up, she automatically transitions onto the top surface;
- the top must be valid, standable, and sufficiently clear for safe completion;
- neutral input at the top holds Neris attached rather than forcing an exit;
- if the top is blocked, invalid, too small, or otherwise unsafe, continued up input does not clip or teleport Neris through the obstruction; she remains on the ladder.

At the **bottom**:
- when Neris reaches the valid lower exit and the player continues pressing down, she automatically steps off onto the ground;
- the floor/exit must be valid and clear enough for safe placement;
- neutral input at the bottom holds Neris attached rather than forcing an exit;
- blocked or unsafe lower exits keep Neris attached instead of forcing placement.

The exit transition may smoothly align Neris with the authored standing position, but it may not snap her through geometry or carry her farther than the local ladder exit requires.

### 5.4 Ladder Drop/Release

While attached to a ladder, Neris detaches only when the player presses the same distinct deliberate **Drop/Release** action used for ledge release.

Locked behavior:
- the Drop/Release press acts promptly with no hold-to-confirm delay;
- ordinary analog direction never detaches Neris from the ladder;
- down input remains unambiguously **climb down** while attached;
- away-from-ladder, sideways, diagonal, partial-stick input, drift, and dead-zone noise do not release the ladder;
- explicit Drop/Release immediately ends the ladder state and hands movement to normal airborne/fall behavior;
- after release, ordinary fall, landing, and valid ledge-catch rules apply; ladder release does not grant a special safety state or free reattachment;
- the exact physical button/key remains remappable and should match the broader Drop/Release semantic unless a later accessibility review deliberately changes the control mapping.

This completes the baseline authored-ladder grammar. Special ladder damage, combat, broken-rung behavior, moving ladders, or tool-specific ladder interactions are content/system questions and are not implied here.

---

## 6. Swimming baseline — LOCKED

Stillring supports competent **surface swimming** as an ordinary baseline traversal state without turning water into a universal three-dimensional bypass.

### Water entry

- Entering ordinary authored swimmable water transitions Neris automatically from ground/air locomotion into the surface-swim state when the water volume and local geometry are valid.
- There is no separate “start swimming” interaction button.
- Shallow water that is explicitly authored as walk/wade depth remains ordinary ground locomotion rather than needlessly switching states.
- Hazardous liquids, violent currents, scripted flood states, or other non-ordinary water may define separate authored rules and must communicate those rules honestly.
- Extreme-height water-entry consequences are governed by the later fall-damage/recovery decision; ordinary swimming does not silently guarantee immunity to every possible fall.

### Surface movement

- Surface swimming is camera-relative and analog, preserving the same intention-first relationship as exploration movement.
- Movement input directly steers Neris across the water surface; exact speed, acceleration, turn rate, drag, and animation cadence remain Gate 1 tuning.
- Neutral movement input keeps Neris afloat/treading at approximately the current position without repeated button presses or stick wiggling.
- Ordinary surface swimming has **no stamina meter, breath meter, or periodic forced slowdown**.
- Baseline swimming uses one competent travel band; ordinary ground Sprint input does not create a second water-sprint state unless a future design specifically earns one.
- The player retains camera control while swimming.

### Underwater boundary

- Baseline locomotion does **not** include free underwater diving or free three-dimensional underwater traversal.
- Camera pitch, down input, or holding a direction toward the lakebed does not silently submerge Neris into a dive state.
- Underwater exploration may exist later only as an explicitly approved tool/capability or authored traversal mode with its own readable affordances and rules.
- This preserves water depth, submerged structures, and remembered locations as potential progression/puzzle language rather than making every body of water immediately solvable.

### Exiting water

- Direct movement intent toward a valid low bank, dock edge, beach, step, or reachable mantle/ledge automatically transitions Neris out of surface swimming when the exit is valid and clear.
- Low water exits reuse the established intention-first terrain/mantle philosophy; they do not require a redundant context button.
- A high, blocked, unsafe, or non-standable water edge does not magnetically pull Neris out or invent a climb. It remains a route/traversal problem under the existing ledge/climbing rules.
- Neutral input near an exit keeps Neris swimming/treading rather than forcing her ashore.

Combat actions while swimming, special water hazards, boats, currents, diving tools, and underwater content remain separate systems/content questions; this section defines only baseline locomotion.

---

## Current locked movement grammar

```text
tiny step / stair / minor floor lip     → automatic terrain handling
careful movement                         → analog low-speed movement
ordinary travel                          → run
faster ground travel                     → unlimited sustained sprint
sprint input                              → Hold default / Toggle optional
normal sprint steering                   → highly responsive
hard sprint reversal                     → brief momentum loss + planted turn
sprint → jump                             → preserve horizontal sprint momentum
jump speed                                → no bonus speed added
land while sprint still requested        → continue/return to sprint
sprint → acquire target lock              → end sprint state, keep brief physical momentum
lock transition                           → short deceleration/pivot
locked movement                           → precise target-relative combat locomotion
small gap / intentional vertical move    → deliberate jump
knee → waist obstacle                    → fluent automatic step/vault/mantle
waist → lower-chest obstacle             → deliberate direct approach/jump + automatic mantle
shoulder-height and above                → NO baseline auto-mantle; traversal problem
valid reachable ledge + clear intent     → automatic catch → hang
hang + neutral movement                  → remain hanging
hang + continued toward/up intent        → pull up if top valid/clear
hang + left/right same handhold          → simple lateral shimmy
shimmy corner/gap/new wall               → stop; NO automatic continuation
shimmy toward higher/lower handhold      → NO vertical transfer/climb
hang + analog down/away                  → remain hanging; NEVER implicit drop
hang + explicit Drop/Release press       → promptly let go
ordinary wall/cliff/rough surface        → NO baseline free climbing
authored climb structure/tool/capability → separately supported traversal
direct valid approach into ladder       → automatic ladder mount
incidental/parallel ladder proximity     → NO ladder mount
on ladder + up input                     → climb up
on ladder + down input                   → climb down
on ladder + neutral input                → hold current ladder position
on ladder + camera input                 → player controls camera
ladder top + continued up + valid exit   → automatically dismount onto top
ladder bottom + continued down + valid exit → automatically step off
ladder end + neutral input               → remain attached
ladder end + blocked/unsafe exit         → remain attached; NO forced placement
ladder + explicit Drop/Release press     → detach promptly → normal airborne/fall
ladder + analog away/side/down noise     → remain attached; NO implicit release
enter ordinary deep swimmable water      → automatic surface-swim state
surface swim + movement input            → camera-relative analog swim
surface swim + neutral input             → tread/hold approximate position
surface swim + ordinary Sprint input     → no separate swim-sprint state
surface swim + down/camera pitch         → remain surface swimming; NO baseline dive
surface swim + direct valid low exit     → automatically leave water
surface swim + blocked/high invalid exit → remain swimming; NO magnetic climb
invalid or blocked ledge top             → remain hanging; NO forced pull-up
sideways/incidental/implausible ledge    → NO catch
passing near/alongside mantle geometry   → NO mantle
combat defense/reposition                → eventual evade, NOT sprint
major cliff / meaningful height gate     → route, tool, or later traversal capability
```

---

## Next locomotion decision

**Crouch / stealth posture.**

After that: slope scramble/slide, fall damage/recovery, jump arc/air control, interaction while moving, traversal-tool overrides, controller/dead-zone behavior, analog thresholds, acceleration/deceleration philosophy, target-lock movement detail, accessibility implications, and the final five-minute human-play acceptance test.
