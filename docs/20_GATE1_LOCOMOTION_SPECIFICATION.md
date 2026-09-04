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
- routine jump/mantle/ledge/ladder/route drops inside the intended traversal envelope deal no damage;
- normal landings acknowledge impact without stealing meaningful control;
- upper-safe falls may use a firmer but brief non-damaging landing response.

### Damaging falls
- above the safe envelope, damage increases with impact severity;
- moderate damaging falls may use proportionate brief stumble/impact recovery, never long helpless stun;
- severe falls can cause major health loss;
- genuinely extreme falls may be lethal;
- visible recovery completion and actual control return must agree.

### No landing exploit
- jump/Sprint/direction/Drop/Release/future crouch-like landing input cannot magically cancel damage;
- no hidden perfect-landing timing mechanic;
- only separately designed future capabilities may modify fall consequences.

### Water impact
- sufficiently deep valid swimmable water may reduce ordinary-to-moderate impact severity;
- water is not universal immunity; extreme falls may still damage/kill, and shallow/blocked/hazardous water may not cushion;
- comparable water depths should behave consistently.

### State continuity
- ledge/ladder release feeds the same fall rules;
- sliding off an edge does not reset severity through a state exploit;
- an actual valid ledge catch before impact legitimately ends the fall path.

---

## 10. Jump arc / air control — LOCKED

Stillring's jump is a **predictable authored traversal verb**, not a platformer movement system layered on top of the game.

### Arc and takeoff
- the baseline jump uses a consistent, modest, readable vertical arc tuned for ordinary small gaps and intentional vertical movement;
- jump height is **not meaningfully variable based on how long the jump button is held**; a deliberate press requests the same baseline jump arc so authored gaps remain learnable and predictable;
- there is no baseline double jump, air jump, hover, or repeated-jump extension;
- takeoff immediately acknowledges the jump request when the locomotion state permits it;
- existing horizontal velocity is inherited into the jump; sprint-jump momentum preservation remains binding;
- jumping never adds a hidden horizontal speed boost.

### Air control
- Neris has **useful but limited** air steering for landing correction;
- air input may bend the travel line and correct a slightly imperfect takeoff, but it cannot instantly rewrite a committed jump or produce full ground-style turning authority;
- at meaningful forward speed, opposite input may reduce/redirect horizontal momentum gradually but cannot create an immediate full-speed 180-degree reversal in midair;
- air steering must not increase horizontal speed above the momentum/authority available from the originating ground state;
- neutral air input preserves the natural takeoff trajectory rather than applying hidden braking;
- exact air-control acceleration, turn influence, and momentum-retention values remain Gate 1 tuning.

### Forgiveness at the edge: short coyote window
- a **short coyote-time window** exists immediately after Neris unintentionally leaves an ordinary valid ground edge, allowing a jump request that was clearly intended at the edge to still begin;
- this window is a control-forgiveness mechanism, not a traversal extension: it must be short enough that the jump still visually belongs to the edge departure;
- coyote time does not reactivate after deliberate ledge Drop/Release, ladder release, a long fall, a slide-off already outside the valid edge window, or another explicit airborne/traversal state;
- exact time is Gate 1 tuning.

### Jump input buffering
- a **short jump-input buffer** exists so a jump pressed just before a valid landing/state transition can execute when Neris becomes legally able to jump;
- the buffer must feel like honoring an already-expressed request, not queuing actions far into the future;
- buffered jump does not bypass damaging-fall recovery, blocked states, authored interaction commitments, or traversal-state rules that explicitly prohibit immediate jumping;
- exact buffer time is Gate 1 tuning.

### Collision / failed jump cases
- low ceilings or blocked takeoff space prevent/limit the jump honestly rather than clipping Neris through geometry;
- landing on ordinary walkable terrain returns to the appropriate requested ground state promptly;
- jump, coyote, and buffering rules may not be exploited to ratchet up out-of-band slopes or bypass authored height gates.

The target feel is forgiving execution with predictable geography: the player can correct a small mistake, but cannot turn a bad committed jump into arbitrary flight.

---

## Current locked movement grammar
```text
ordinary terrain / careful movement       → analog ground locomotion
ordinary travel / sprint                  → run / unlimited requested sprint
jump press from valid ground              → consistent modest jump arc
jump hold duration                        → no meaningful extra jump height
sprint → jump                             → preserve existing horizontal momentum; no boost
air + directional correction             → useful limited steering
air + hard reverse                        → gradual correction; NO instant full-speed 180
air + neutral                             → preserve natural trajectory
just left ordinary ground edge            → short coyote jump eligibility
jump pressed just before valid landing    → short input buffer, execute when legal
double/air jump input                     → NO baseline extra jump
low obstacle                              → automatic valid mantle
deliberate reachable ledge                → automatic catch → hang
hang explicit Drop/Release                → normal fall
ordinary rough wall/cliff                 → NO free climbing
authored ladder                            → authored ladder grammar
ordinary deep swimmable water              → surface swim; no baseline dive
generic crouch                             → NO baseline crouch
short plausible borderline uphill slope    → limited automatic scramble
out-of-band uphill slope                   → no ratcheting progress
steep/low-traction descent                 → automatic limited-steer slide
ordinary traversal-scale fall              → no damage; prompt landing control
moderate/severe fall                       → proportional damage + brief proportional recovery
extreme fall                               → may be lethal
landing input gimmick                      → cannot cancel impact severity
```

---

## Next locomotion decision
**Interaction while moving.**

After that: traversal-tool overrides, controller/dead-zone behavior, analog thresholds, acceleration/deceleration philosophy, target-lock movement detail, accessibility implications, and the final five-minute human-play acceptance test.
