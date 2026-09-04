# 20 — Gate 1 Locomotion Specification

**Status:** detailed locomotion authority — owner final review pending  
**Updated:** 2026-09-04  
**Scope:** player locomotion only; camera composition, combat actions, animation production, and world-content authoring remain governed elsewhere.

## Authority and review protocol
This file is the implementation-facing accumulation of settled Gate 1 locomotion behavior. `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md` explains the reasoning; this file states the movement contract Claude may implement.

The owner delegated approval for the remaining **locomotion-only** decisions in this pass. Each meaningful choice is still reasoned through, documented, diff-reviewed, and merged. The completed package remains **pending final owner review** before Issue #1 closes.

> **Simple intention, capable character, honest world.**

---

## 1. Ground locomotion — LOCKED
- camera-relative analog exploration movement;
- useful careful low-speed movement;
- automatic stairs/small steps/minor floor lips/ordinary uneven ground;
- always-available modest deliberate jump;
- meaningful height gates remain authored traversal problems;
- affordances must be visually honest.

### Sprint
- sustained from the beginning;
- no stamina/resource cost;
- Hold and Toggle, Hold default;
- separate from combat evade;
- highly steerable through ordinary curves;
- hard reversal briefly sheds momentum and uses a planted reversal/re-acceleration;
- sprint → jump preserves horizontal momentum and adds no speed boost;
- landing continues/returns to sprint when still requested;
- target lock ends exploration sprint without hard-zeroing velocity, using a short natural deceleration/pivot;
- full exploration sprint unavailable while target-locked.

Exact speeds/curves remain Gate 1 tuning.

---

## 2. Mantle / scramble — LOCKED
- automatic from clear movement/jump intent; no mantle button;
- requires valid geometry/top/approach/clearance and no higher-priority conflict;
- incidental proximity/parallel movement does not trigger.

Body-relative scope:
- knee → waist: fluent ordinary traversal;
- waist → lower chest: baseline mantleable with deliberate direct approach/jump;
- shoulder height and above: not baseline auto-mantle.

Exact dimensions/angles/timing remain tuning tied to Neris's scale.

---

## 3. Ledge grammar — LOCKED
### Catch
- automatic only for valid reachable ledge + clear trajectory/directional intent;
- no grab button;
- plausible reach/handhold/clearance required;
- incidental/sideways/parallel/implausible rescue cases do not catch;
- catch always enters a real hang first.

### Hang / pull-up
- neutral stays hanging;
- continued toward/up requests pull-up with no extra button;
- valid clear standable top required;
- blocked/unsafe top stays hanging.

### Shimmy
- left/right only along same continuous valid handhold;
- neutral holds current position;
- no corners, gaps, wall transfers, lateral jumps, or vertical handhold climbing.

### Drop / release
- distinct deliberate Drop/Release press only;
- analog down/away/diagonal/drift/dead-zone noise never drops;
- prompt release, no hold confirmation;
- physical binding remappable.

---

## 4. Broader climbing boundary — LOCKED
- no baseline universal/free climbing beyond the ledge grammar;
- rough walls/cliffs/masonry/roots/rock faces do not become climbable merely because they look grippable;
- ledge grammar does not chain into vertical/corner free climbing;
- broader climbing only through explicit authored structures/tools/later capabilities;
- consistent visible world language required;
- protects authored route, puzzle, and progression meaning.

---

## 5. Authored ladders — LOCKED
### Movement
```text
up input       → climb up
down input     → climb down
neutral input  → hold current ladder position
camera input   → player retains camera control
```
No automatic climb sequence. Exact speed/alignment/animation remain tuning.

### Mount
- automatic from clear deliberate valid approach intent;
- no separate interact button;
- valid entry/alignment/attach point/no blocker required;
- proximity, parallel/sideways movement, camera orientation, neutral standing, drift do not mount;
- short local alignment okay, no magnetic snapping.

### End dismount
- valid top + continued up → automatic safe top exit;
- valid bottom + continued down → automatic safe bottom exit;
- neutral at end stays attached;
- blocked/unsafe exit stays attached.

### Drop/Release
- same explicit deliberate Drop/Release semantic as ledges;
- prompt, no hold delay;
- down remains climb-down;
- analog away/side/diagonal/drift never detaches;
- release → normal airborne/fall rules;
- no special safety/free reattachment.

---

## 6. Swimming baseline — LOCKED
### Entry
- ordinary deep swimmable water automatically enters surface swim;
- no start-swimming button;
- authored shallow/wade water remains ground locomotion;
- hazardous liquids/currents/scripted water may define separate honest rules.

### Surface movement
- camera-relative analog steering;
- neutral treads/holds approximate position without repeated input;
- no ordinary swim stamina/breath meter/periodic slowdown;
- one competent surface travel band; ground Sprint does not add water-sprint;
- player retains camera control;
- exact speed/drag/turn remain tuning.

### Underwater boundary
- no baseline free underwater diving or 3D underwater traversal;
- camera pitch/down does not silently dive;
- underwater exploration requires later explicit authored tool/capability/mode.

### Exit
- direct movement toward valid low exit automatically leaves water;
- no redundant context button;
- high/blocked/unsafe edge remains a traversal problem;
- neutral near exit stays swimming.

---

## 7. Crouch / stealth posture — LOCKED: NO BASELINE CROUCH
- no always-available crouch/generic stealth posture;
- careful/quiet-feeling positioning uses analog low-speed movement;
- no generic capsule shrink from crouch input;
- future crawl/squeeze/concealment/stealth/tool posture requires explicit authored design and affordance;
- future special posture does not create universal crouch or a general stealth system.

---

## 8. Slope scrambling / sliding — LOCKED
### Ordinary slopes
- normal walkable range stays ordinary ground locomotion;
- no needless special slope state/micro-sliding.

### Borderline uphill scramble
- short plausible borderline slope + sustained direct uphill intent + credible traction → automatic brief scramble;
- no separate input;
- slower than run/sprint, no stamina;
- too steep/long/slippery/out-of-band terrain stops uphill progress cleanly;
- sprint/jump/diagonal tricks cannot ratchet upward;
- sprint adds no extra climbing authority.

### Downhill slide
- sufficiently steep/low-traction descent may automatically slide;
- camera remains player-owned;
- limited lateral line correction only;
- cannot point uphill to cancel/reverse committed slide;
- no baseline slide/surf button;
- returns promptly to ordinary movement when footing becomes safely walkable.

Exact angles/traction/friction/slide authority remain tuning. Slope rules may not bypass authored height gates.

---

## 9. Fall damage / landing recovery — LOCKED
Fall consequences use body/level-design-relative severity bands. Exact thresholds are tuned against Neris's scale, jump arc, ordinary traversal envelope, representative cliffs, and level geometry.

### Safe traversal falls
- routine traversal drops inside the intended envelope deal no damage;
- normal landings acknowledge impact without stealing meaningful control;
- upper-safe falls may use a firmer but brief non-damaging response.

### Damaging falls
- above the safe envelope, damage increases with impact severity;
- moderate damaging falls use proportionate brief recovery, never long helpless stun;
- severe falls can cause major health loss;
- genuinely extreme falls may be lethal;
- visible recovery completion and actual control return must agree.

### No landing exploit
- jump/Sprint/direction/Drop/Release/future crouch-like landing input cannot magically cancel damage;
- no hidden perfect-landing timing mechanic;
- only separately designed future capabilities may modify fall consequences.

### Water impact / state continuity
- sufficiently deep valid water may reduce ordinary-to-moderate impact severity but is not universal immunity;
- ledge/ladder release uses the same fall rules;
- slide-off transitions do not reset fall severity;
- a physical valid ledge catch before impact legitimately ends the fall path.

---

## 10. Jump arc / air control — LOCKED
### Arc and takeoff
- consistent modest readable baseline arc;
- jump hold duration does not meaningfully increase height;
- no double jump, air jump, hover, or repeated-jump extension;
- takeoff acknowledges input immediately when legal;
- existing horizontal velocity is inherited; sprint-jump preservation remains binding;
- no hidden horizontal speed boost.

### Air control
- useful but limited landing correction;
- can bend line/correct a slightly imperfect takeoff, not produce full ground turning authority;
- no instant full-speed 180-degree midair reversal;
- air steering adds no speed beyond originating ground authority;
- neutral preserves natural trajectory;
- exact influence remains tuning.

### Coyote / buffer
- short coyote window immediately after ordinary valid ground-edge departure;
- does not reactivate after deliberate release, long fall, out-of-window slide-off, or explicit airborne/traversal state;
- short jump-input buffer honors a request just before becoming legally able to jump;
- buffer cannot bypass damaging-fall recovery, blocked states, committed interactions, or explicit traversal restrictions;
- exact windows remain tuning.

### Collision
- blocked takeoff/low ceiling behaves honestly rather than clipping;
- coyote/buffer cannot ratchet slopes or bypass authored height gates.

---

## 11. Interaction while moving — LOCKED

The player does **not** need to come to a perfect standstill before ordinary interaction input becomes valid. Interaction acceptance and movement transition depend on what the specific interaction physically requires.

### Accepting interaction input
- an explicit interaction request may be accepted while Neris is walking, running, or sprinting when the target is valid, in range, and otherwise interactable;
- movement speed alone does not make an obviously valid nearby interaction fail;
- proximity by itself never auto-fires a generic interaction; traversal verbs that are already intentionally automatic (mantle, ladder mount, water entry, etc.) remain governed by their own rules;
- ordinary ground interactions do not yank Neris out of an airborne, hanging, ladder, swimming, slide, or other incompatible locomotion state unless that interaction is explicitly authored to support that state.

### Movement-compatible interactions
- an interaction explicitly designed to work while moving may complete without forcing Neris to stop;
- such interactions may not secretly zero velocity, rotate the character, or snap position unless their own authored behavior requires it;
- content examples are decided by the interaction/content specification, not by locomotion authority.

### Planted / alignment-required interactions
When an interaction physically requires a planted position, facing, or hand placement:
- accepting the interaction ends Sprint if active and transitions through a **short natural deceleration** rather than an instantaneous hard stop;
- Neris may use a small local alignment step/turn into the authored interaction pose only when already inside a plausible valid interaction envelope;
- alignment may not teleport Neris across a room, pull through collision, cross a gap, or bypass a traversal restriction;
- if valid alignment/clearance cannot be achieved locally, the interaction does not commit and the player keeps movement authority;
- exact local alignment radius/angle and blend timing remain tuning/content-authoring values.

### Pre-commit cancellation and commitment
- before the interaction has committed, moving away/out of the valid envelope may cleanly cancel the pending request rather than dragging Neris back magnetically;
- the system must not queue an interaction for a long time and fire it unexpectedly after the player has moved elsewhere;
- once a committed interaction legitimately owns movement, its authored action state may temporarily override locomotion until its release point;
- when the interaction releases movement authority, current valid movement input is acknowledged promptly rather than requiring the stick/key to be released and pressed again.

### Sprint and traversal boundaries
- sprint-to-interaction uses the same philosophy as sprint-to-lock: the state can end promptly without pretending existing velocity vanished instantly;
- interaction input does not silently extend mantle reach, ledge reach, ladder magnetism, slope scramble authority, or any other traversal envelope;
- movement/interact overlap must be tested for accidental double-trigger cases at doors, mechanisms, pickups, ledges, ladders, water edges, and other representative boundaries.

This keeps interaction flow modern without turning every interactable into a magnetic cutscene anchor.

---

## Current locked movement grammar
```text
ordinary terrain / careful movement        → analog ground locomotion
ordinary travel / sprint                   → run / unlimited requested sprint
jump                                       → predictable modest arc + limited air correction
coyote / jump buffer                       → short intent forgiveness only
low obstacle                               → automatic valid mantle
deliberate reachable ledge                 → automatic catch → hang
hang explicit Drop/Release                 → normal fall
ordinary rough wall/cliff                  → NO free climbing
authored ladder                            → authored ladder grammar
ordinary deep swimmable water               → surface swim; no baseline dive
generic crouch                              → NO baseline crouch
borderline slope / steep descent            → limited scramble / limited-steer slide
fall severity                               → safe band → proportional damage → possible lethal extreme
interaction input while moving + valid      → request accepted; do not require standstill
moving-compatible interaction              → may complete without forced stop
planted interaction                        → short natural decel + small valid local alignment
invalid/nonlocal alignment                 → do not commit; preserve movement
move away before commit                    → cancel cleanly; NO magnetic pullback
interaction completes/releases movement    → current movement input resumes promptly
```

---

## Next locomotion decision
**Traversal-tool overrides.**

After that: controller/dead-zone behavior, analog thresholds, acceleration/deceleration philosophy, target-lock movement detail, accessibility implications, and the final five-minute human-play acceptance test.
