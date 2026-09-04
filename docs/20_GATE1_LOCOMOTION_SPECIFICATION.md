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
- valid ladder entry region;
- movement intent directed into/toward the ladder;
- physically plausible approach/alignment;
- valid attach position and no blocker;
- no conflicting higher-priority state.

Incidental proximity, sideways brushing, parallel movement, camera orientation alone, neutral standing, drift, and dead-zone noise do not mount. A short authored alignment transition is allowed, but not magnetic long-distance snapping.

### 5.3 Ladder top/bottom dismount
- valid upper exit + continued up → automatic transition onto valid clear top;
- valid lower exit + continued down → automatic step off onto clear ground;
- neutral input at either end remains attached;
- blocked/unsafe exits remain attached rather than clipping or forcing placement;
- local exit alignment may be smoothed only as far as the immediate authored exit requires.

### 5.4 Ladder Drop/Release
- the same distinct deliberate Drop/Release action as ledge release detaches Neris promptly;
- no hold-to-confirm delay;
- down remains climb-down while attached;
- away/side/diagonal/partial input, drift, and dead-zone noise never detach;
- release hands movement directly to normal airborne/fall behavior;
- no special safety state or free reattachment;
- physical binding remains remappable.

---

## 6. Swimming baseline — LOCKED

Stillring supports competent **surface swimming** without turning water into a universal three-dimensional bypass.

### Water entry
- ordinary valid deep swimmable water automatically enters surface swim;
- no separate start-swimming button;
- authored shallow/wade water stays ordinary ground locomotion;
- hazardous liquids/currents/scripted water may define separate honest rules;
- extreme-height entry consequences follow the later fall rules.

### Surface movement
- camera-relative analog steering;
- neutral input treads/holds approximate position;
- no repeated button presses or stick wiggling to stay afloat;
- no ordinary swim stamina meter, breath meter, or periodic slowdown;
- one competent surface travel band; ground Sprint does not create a water-sprint state;
- player retains camera control;
- exact speed/drag/turn/animation remain tuning.

### Underwater boundary
- no baseline free underwater diving or 3D underwater traversal;
- camera pitch/down input does not silently dive;
- underwater exploration requires a later explicit authored tool/capability/mode;
- submerged spaces may remain progression/puzzle language.

### Exiting water
- direct movement toward a valid low bank/dock/beach/step/reachable mantle automatically exits;
- no redundant context button for valid low exits;
- high/blocked/unsafe/non-standable edges remain traversal problems;
- neutral near an exit keeps swimming/treading.

---

## 7. Crouch / stealth posture — LOCKED: NO BASELINE CROUCH

- no always-available crouch or generic stealth-posture state;
- careful/quiet-feeling/precise positioning is existing analog low-speed movement;
- no generic collision-capsule shrink from an ambient crouch input;
- ordinary geometry does not assume universal crouch traversal;
- a later crawlspace, squeeze, concealment posture, stealth sequence, or tool-assisted posture requires an explicit authored need and honest affordance;
- such a future posture does not create universal crouch or a general stealth system.

---

## 8. Slope scrambling / sliding — LOCKED

Stillring distinguishes normal ground, borderline traversable slopes, and genuinely steep/low-traction terrain instead of treating every incline as either flat ground or an invisible wall.

### Ordinary walkable slopes
- slopes inside the normal authored walkable range remain ordinary ground locomotion;
- Neris keeps normal analog control and does not enter a special slope animation/state merely because the terrain is inclined;
- small terrain undulations do not steal speed or produce repeated micro-slides.

### Borderline uphill scramble
- a **short, plausible borderline slope** may automatically enter a brief uphill scramble when sustained direct uphill movement clearly communicates the attempt and the surface provides credible traction;
- the scramble is a continuation of movement intent, not a separate button;
- uphill scramble is slower than normal run/sprint and does not consume stamina;
- it exists to smooth believable short transitions, banks, broken earth, or rough inclines—not to create universal mountain climbing;
- if the incline becomes too steep, too long, too low-traction, or otherwise outside the authored scramble band, uphill progress stops cleanly or transitions into the appropriate downhill/slide response rather than allowing repeated input/jump exploits to inch upward;
- sprint does not grant extra slope-climbing authority beyond the valid scramble band.

### Steep / low-traction downhill slide
- when terrain is sufficiently steep and/or low-traction that ordinary footing is no longer credible, downhill motion may automatically transition into a slide;
- the player retains camera control;
- while sliding, directional input provides **limited lateral steering and line correction**, not full ground-locomotion authority or uphill reversal;
- the player may influence where the slide goes, but cannot simply point uphill and cancel the physical commitment;
- no baseline dedicated “slide/surf” button exists;
- exact slide acceleration, lateral authority, friction, minimum/maximum duration, recoverable-angle thresholds, and animation remain Gate 1 tuning;
- when the surface becomes safely walkable again, the slide returns promptly and predictably to ordinary locomotion rather than carrying hidden residual momentum for a long distance.

### Authored-terrain protection
- slope systems may not create a “mountain goat” loophole that bypasses cliffs, intended routes, traversal tools, or puzzle gates;
- jump spam, sprint spam, diagonal stick tricks, or animation resets must not let Neris ratchet up terrain outside the supported scramble band;
- visual/material/shape language should make major non-traversable or slide-prone surfaces understandable wherever practical;
- deliberately slippery, unstable, icy, ashy, muddy, or otherwise special materials may adjust traction only when the world communicates that difference consistently.

Exact angles and traction coefficients are prototype tuning values tied to Neris and representative level geometry; the semantic bands above are locked.

---

## Current locked movement grammar

```text
tiny step / stair / minor floor lip       → automatic terrain handling
careful movement                           → analog low-speed movement
ordinary travel                            → run
faster ground travel                       → unlimited sustained sprint
sprint input                                → Hold default / Toggle optional
normal sprint steering                     → highly responsive
hard sprint reversal                       → brief momentum loss + planted turn
sprint → jump                               → preserve horizontal sprint momentum
jump speed                                  → no bonus speed added
land while sprint still requested          → continue/return to sprint
sprint → acquire target lock                → end sprint state, keep brief physical momentum
lock transition                             → short deceleration/pivot
locked movement                             → precise target-relative combat locomotion
small gap / intentional vertical move      → deliberate jump
knee → waist obstacle                      → fluent automatic step/vault/mantle
waist → lower-chest obstacle               → deliberate direct approach/jump + automatic mantle
shoulder-height and above                  → NO baseline auto-mantle; traversal problem
valid reachable ledge + clear intent       → automatic catch → hang
hang + neutral movement                    → remain hanging
hang + continued toward/up intent          → pull up if top valid/clear
hang + left/right same handhold            → simple lateral shimmy
shimmy corner/gap/new wall                 → stop; NO automatic continuation
shimmy toward higher/lower handhold        → NO vertical transfer/climb
hang + analog down/away                    → remain hanging; NEVER implicit drop
hang + explicit Drop/Release press         → promptly let go
ordinary wall/cliff/rough surface          → NO baseline free climbing
authored climb structure/tool/capability   → separately supported traversal
direct valid approach into ladder         → automatic ladder mount
incidental/parallel ladder proximity       → NO ladder mount
on ladder + up/down                        → player-driven climb
on ladder + neutral                        → hold current position
ladder valid end + continued direction     → automatic safe dismount
ladder blocked end                         → remain attached
ladder + explicit Drop/Release             → detach → normal airborne/fall
enter ordinary deep swimmable water        → automatic surface swim
surface swim + movement                    → camera-relative analog swim
surface swim + neutral                     → tread/hold approximate position
surface swim + Sprint                      → no separate swim-sprint
surface swim + down/camera pitch           → NO baseline dive
surface swim + direct valid low exit       → automatically leave water
generic crouch input                       → NO baseline crouch state
authored crawl/squeeze/special posture     → separate later state if approved
ordinary walkable slope                    → ordinary ground locomotion
short borderline uphill + clear intent     → automatic limited scramble
slope outside uphill scramble band         → NO ratcheting/mountain-goat progress
steep/low-traction downhill terrain        → automatic slide
slide + lateral input                      → limited line correction
slide + uphill input                       → cannot cancel/reverse committed slide
return to walkable terrain                 → prompt ordinary locomotion recovery
invalid or blocked ledge top               → remain hanging
sideways/incidental/implausible ledge      → NO catch
passing near/alongside mantle geometry     → NO mantle
major cliff / meaningful height gate       → route, tool, or later capability
```

---

## Next locomotion decision

**Fall damage / landing recovery.**

After that: jump arc/air control, interaction while moving, traversal-tool overrides, controller/dead-zone behavior, analog thresholds, acceleration/deceleration philosophy, target-lock movement detail, accessibility implications, and the final five-minute human-play acceptance test.
