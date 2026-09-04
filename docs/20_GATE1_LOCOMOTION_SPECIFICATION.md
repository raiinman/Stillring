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

- routine traversal drops inside the safe envelope deal no damage;
- upper-safe falls may use a firm but brief non-damaging response;
- above safe range, damage scales with impact severity;
- moderate damaging falls use proportionate brief recovery, severe falls can cause major health loss, extreme falls may be lethal;
- no landing-input gimmick cancels impact;
- deep valid water may reduce ordinary-to-moderate severity but is not universal immunity;
- ledge/ladder/slide-off states feed the same fall model.

---

## 10. Jump arc / air control — LOCKED
### Arc
- consistent modest readable baseline arc;
- jump hold does not meaningfully increase height;
- no double/air jump, hover, or repeated extension;
- takeoff inherits existing horizontal velocity and adds no hidden speed boost.

### Air control
- useful but limited landing correction;
- can bend line, not instantly rewrite a committed jump;
- no instant full-speed midair 180;
- no air-created speed beyond originating authority;
- neutral preserves natural trajectory.

### Coyote / buffer
- short coyote window immediately after ordinary ground-edge departure;
- short jump-input buffer before becoming legally able to jump;
- neither bypasses deliberate release, long falls, damaging recovery, committed interactions, explicit traversal restrictions, or authored height gates;
- exact windows remain tuning.

---

## 11. Interaction while moving — LOCKED
- explicit interaction request may be accepted while walking/running/sprinting when target/range/state are valid;
- movement speed alone does not invalidate an otherwise valid interaction;
- proximity alone does not auto-fire generic interactions;
- incompatible traversal states are not yanked into ordinary ground interactions unless explicitly supported;
- movement-compatible interactions may complete without forced stop;
- planted interactions end Sprint and use short natural deceleration + small plausible local alignment;
- no teleport/pull through collision/gap/traversal restriction;
- invalid local alignment does not commit;
- moving away before commit cancels cleanly and no long delayed queue fires later;
- committed interactions may temporarily own movement;
- current valid movement input resumes promptly when movement authority returns;
- interaction overlap may not extend mantle/ledge/ladder/slope traversal envelopes.

---

## 12. Traversal-tool / capability overrides — LOCKED

This section defines how a **future explicitly designed traversal tool or progression capability** may override baseline locomotion. It does not authorize a specific new tool or movement verb by itself.

### Explicit authored scope only
- every traversal override must be tied to a clearly specified tool/capability and a clearly supported affordance, target, state, or authored environment condition;
- equipping/owning a tool does not silently make arbitrary walls, gaps, water, ceilings, or terrain universally traversable;
- a traversal capability may expand movement vocabulary only where its own design contract explicitly says it does;
- visibly equivalent supported targets must follow a consistent world language; hidden arbitrary eligibility remains disallowed.

### Required state contract
Before any traversal override can become implementation authority, its own specification must define at minimum:
- entry eligibility and required player intent;
- activation input/trigger semantics;
- what movement axes/steering remain player-controlled while engaged;
- what baseline locomotion verbs are temporarily suppressed or still allowed;
- how cancel/release works;
- successful exit/landing behavior;
- blocked/invalid/failure behavior;
- interaction with fall severity if the capability changes it;
- state priority/conflicts with hang, ladder, swimming, sliding, target lock, combat actions, and other traversal states;
- how baseline movement authority is restored afterward.

Camera composition for a tool-owned traversal state belongs to Issue #2 / that tool's presentation specification, but the locomotion contract must identify when ordinary movement authority has changed.

### Clean entry / exit
- entering a tool traversal state may temporarily override baseline movement only after the authored entry condition has actually succeeded;
- failed activation does not consume control or pull Neris toward an invalid target;
- on normal exit/cancel/failure recovery, baseline locomotion returns promptly and predictably;
- current valid held movement may resume when appropriate, but the state transition must not reinterpret the same held input as a second unintended traversal action;
- an exit may use a small authored local placement/alignment only when physically justified and valid; no large teleport/snapping through geometry.

### No accidental system-wide expansion
- tool traversal cannot silently enlarge ordinary mantle height, ledge-catch reach, ladder magnetism, coyote time, slope scramble band, or baseline air control;
- if a capability intentionally changes one of those rules while active, that change must be explicit in its own contract and limited to the active state/affordance;
- gaining a tool does not retroactively make every previously blocked surface passable unless that global world-language change is itself deliberately designed and documented;
- traversal progression should make remembered spaces newly legible rather than erase route-reading from the entire world.

### Safety / exploit continuity
- switching into/out of a tool traversal state cannot reset accumulated fall severity, create free momentum, duplicate jump impulses, or bypass collision through state churn;
- tool cancellation cannot be spammed to ratchet up blocked slopes/walls or gain height/speed;
- any intentional momentum transfer is documented and tested as part of the capability rather than inherited accidentally from Unreal defaults.

The governing rule is simple: **future traversal verbs are allowed to be powerful, but their power must be explicit, authored, state-bounded, and honest.**

---

## Current locked movement grammar
```text
baseline ground/jump/sprint                  → ordinary locomotion contract
mantle / ledge / ladder / swim / slope       → their explicit locked state grammar
interaction while moving                     → valid flow without magnetic snapping
future traversal tool owned                  → NO passive universal movement expansion
valid authored tool affordance + clear intent→ enter that tool's explicit traversal state
invalid tool target/entry                    → do not seize movement / do not magnetically pull
tool traversal active                        → only documented axes/verbs/overrides apply
tool cancel/exit/failure                     → restore baseline movement predictably
tool state churn                             → NO free height/speed/fall reset/collision bypass
```

---

## Next locomotion decision
**Controller axes / dead-zone behavior.**

After that: analog thresholds, acceleration/deceleration philosophy, target-lock movement detail, accessibility implications, and the final five-minute human-play acceptance test.
