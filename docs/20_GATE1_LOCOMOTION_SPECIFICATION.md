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

Fall consequences use **body/level-design-relative severity bands**, not one arbitrary permanent centimeter cutoff. Exact thresholds must be tuned against Neris's scale, jump arc, ordinary traversal envelope, representative cliffs, and level geometry.

### Ordinary traversal falls — no damage
- jumps, mantle drops, ordinary ledge releases, common ladder exits, small route drops, and falls inside the expected normal traversal envelope do **not** deal fall damage;
- ordinary safe landings acknowledge impact visually/audio-wise without stealing meaningful control time;
- the player should never be afraid to use the movement verbs the game teaches as routine traversal.

### Heavy but non-damaging edge band
- a fall near the upper end of the safe traversal envelope may use a firmer landing/compression response for physical weight;
- this response must be brief and must not become a long canned stun;
- control returns promptly and predictably;
- exact boundary between ordinary and heavy-safe landing remains tuning.

### Damaging falls
- above the safe envelope, fall damage increases with impact severity rather than using a single binary “safe/dead” threshold;
- moderate damaging falls may use a brief stumble/knee/impact recovery, but recovery is proportionate and never a long helpless animation tax;
- player intent should be acknowledged as soon as the recovery state permits, with no hidden extra delay after the visible recovery is complete;
- severe falls can deal major health loss;
- genuinely extreme falls may be lethal.

### No input gimmick to erase impact
- jump, Sprint, analog direction, Drop/Release, or any future crouch-like input at the instant of landing does not magically cancel fall damage;
- there is no hidden “perfect landing” button or timing exploit in baseline locomotion;
- a future explicitly designed traversal tool/capability may alter fall consequences only through its own documented rules.

### Water impact
- sufficiently deep, valid swimmable water can **reduce** impact severity for ordinary-to-moderate water entries when the authored volume has clear safe depth;
- water is not universal fall-damage immunity: extreme-height impacts may still damage or kill Neris, and shallow/blocked/hazardous water may not cushion a fall;
- exact water-cushioning thresholds remain tuning and must be consistent enough that comparable water depths behave comparably;
- scripted safe dives or special water mechanics require explicit authored rules rather than silently changing the baseline.

### Relationship to release and slopes
- ledge Drop/Release and ladder Drop/Release feed directly into the same fall-severity rules;
- sliding off a slope/edge does not reset accumulated fall severity through a state-transition exploit;
- catching a valid reachable ledge before impact legitimately ends the free-fall impact path because Neris physically caught the ledge; it is not a damage-cancel input trick.

The design goal is consequence without making ordinary exploration timid: routine movement is trusted, reckless/high falls matter, and recovery communicates impact without repeatedly taking the controller away.

---

## Current locked movement grammar
```text
ordinary terrain / careful movement       → analog ground locomotion
ordinary travel / sprint                  → run / unlimited requested sprint
small intentional vertical move           → deliberate jump
low obstacle                              → automatic valid mantle
deliberate reachable ledge                → automatic catch → hang
hang neutral / toward-up / left-right      → hold / valid pull-up / same-handhold shimmy
hang explicit Drop/Release                 → normal fall
ordinary rough wall/cliff                  → NO free climbing
authored ladder                            → auto valid mount; player-driven climb; safe directional exits; explicit release
ordinary deep swimmable water              → surface swim; no baseline dive
generic crouch                             → NO baseline crouch
short plausible borderline uphill slope    → limited automatic scramble
out-of-band uphill slope                   → no ratcheting progress
steep/low-traction descent                 → automatic steerable-limited slide
ordinary traversal-scale fall              → no damage; prompt landing control
upper safe-envelope fall                   → firm but brief non-damaging landing
moderate/severe fall                       → proportional damage + proportionate brief recovery
extreme fall                               → may be lethal
deep valid water impact                    → reduced severity, NOT universal immunity
landing input gimmick                      → cannot cancel impact severity
```

---

## Next locomotion decision
**Jump arc / air control.**

After that: interaction while moving, traversal-tool overrides, controller/dead-zone behavior, analog thresholds, acceleration/deceleration philosophy, target-lock movement detail, accessibility implications, and the final five-minute human-play acceptance test.
