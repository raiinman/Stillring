# 20 — Gate 1 Locomotion Specification

**Status:** detailed locomotion authority — FINAL OWNER APPROVED  
**Updated:** 2026-09-04  
**Scope:** player locomotion only; camera composition, combat actions, animation production, and world-content authoring remain governed elsewhere.

## Authority and review protocol
This file is the implementation-facing accumulation of settled Gate 1 locomotion behavior. `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md` explains the reasoning; this file states the movement contract Claude may implement.

The owner delegated approval for the remaining **locomotion-only** decisions in this pass and, during the final review, explicitly instructed the three discovered edge-case closures to be walked through and then auto-approved. Each is recorded below. **Final owner review is complete.**

> **Simple intention, capable character, honest world.**

---

## 1. Ground locomotion — LOCKED
- camera-relative analog exploration movement;
- useful careful low-speed movement;
- automatic stairs/small steps/minor floor lips/ordinary uneven ground;
- always-available modest deliberate jump;
- meaningful height gates remain authored traversal problems;
- affordances must be visually honest.

### Ordinary edge commitment
- ordinary unsupported ground edges have **no invisible edge guard / auto-brake**;
- if the player continues giving movement intent toward an unsupported edge, Neris may walk/run/Sprint off it and enter ordinary airborne/fall rules;
- careful analog movement, brisk stopping control, and level readability are the baseline tools for approaching ordinary edges safely;
- coyote time remains the already-locked short jump-forgiveness window after ordinary ground-edge departure; it is not an edge-prevention system;
- ordinary edge commitment does not authorize magnetic ledge catches: a catch still requires the existing reachable-ledge trajectory/intent rules;
- a future explicitly authored precarious state such as a balance beam, rail, squeeze, or special traversal mode may define different edge-safety behavior only in its own explicit state contract.

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

### Deliberate-release re-catch suppression
- deliberately releasing a ledge makes the **released handhold** temporarily ineligible for automatic re-catch;
- Neris must genuinely separate from that handhold and establish a new plausible approach/trajectory before the same handhold can become catchable again;
- implementation may use geometric separation/state evidence rather than an arbitrary long lockout timer; exact local thresholds are tuning so long as deliberate Drop cannot immediately undo itself;
- this suppression is handhold-specific, not a blanket ban on all ledge catches after release;
- while falling, a **different** valid ledge may still be caught when the normal reach/trajectory/directional-intent rules genuinely support it;
- deliberate release never grants fall immunity, free reattachment, altered fall severity, or extra steering authority.

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
- neutral at either end remains attached;
- blocked/unsafe exit stays attached.

### Drop/Release
- same explicit deliberate Drop/Release semantic as ledges;
- prompt, no hold delay;
- down remains climb-down;
- analog away/side/diagonal/drift never detaches;
- release → normal airborne/fall rules;
- no special safety/free reattachment.

A deliberate ladder release must likewise not immediately reattach to the same ladder from the unchanged release position merely because the normal mount detector still overlaps it. Re-entry requires genuine separation plus a new valid deliberate mount approach under the ladder rules.

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
- ledge/ladder/slide-off/ordinary-edge departures feed the same fall model.

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

## 13. Controller movement axes / dead-zone behavior — LOCKED

The movement stick is treated as a **two-dimensional intention vector**, not as two unrelated digital-ish axes. Dead-zone processing exists to suppress hardware noise without distorting the direction the player actually pointed.

### Radial inner dead zone
- movement uses a **radial / magnitude-based inner dead zone** centered on stick neutral;
- input whose vector magnitude remains inside the configured dead zone is treated as zero movement intent;
- separate per-axis dead zones are not the baseline because they distort diagonals and create square/cross-shaped response artifacts;
- once magnitude exceeds the inner dead zone, the original stick direction is preserved;
- post-dead-zone magnitude is smoothly rescaled from the dead-zone boundary toward full input rather than creating a sudden speed step at activation.

### Drift and traversal intent
- ordinary controller drift, jitter, and dead-zone noise must not move Neris;
- the same processed movement-intent vector is used by locomotion systems that depend on analog intent, so drift cannot mount ladders, start mantles, request pull-up, leave neutral hang, steer a slide, exit water, or trigger another directional traversal transition;
- traversal states that intentionally listen to a different action button remain governed by that explicit action instead of raw-stick noise;
- neutral means neutral consistently across ground, hang, ladder, surface swim, and other analog-driven states.

### Full-range response / worn controllers
- a small configurable outer saturation margin may map near-maximum physical stick travel to full movement intent so worn controllers can still reach 100% requested magnitude;
- outer saturation must not alter the intended direction or create faster-than-maximum movement;
- exact default inner and outer values remain Gate 1 tuning against representative controllers rather than being hard-coded here.

### Configuration and accessibility boundary
- movement dead-zone values must be exposed through player settings within safe supported bounds;
- defaults should work for healthy modern controllers without requiring setup;
- increasing the inner dead zone trades fine low-speed precision for drift resistance; decreasing it trades drift tolerance for earlier response, and the settings presentation should communicate that tradeoff plainly;
- reset-to-default must be available;
- dead-zone settings affect movement intent processing, not authored traversal distances, speeds, stamina rules, or world eligibility.

### Digital movement inputs
- keyboard/digital directional inputs map to explicit directional movement intent rather than emulating noisy analog values;
- simultaneous digital diagonals are vector-normalized so diagonal movement does not exceed the intended maximum movement magnitude;
- digital input still passes through the same locomotion-state speed/acceleration rules after its direction/magnitude is formed.

### Scope boundary
- this section governs **movement-stick locomotion input**;
- look-stick dead zones, camera sensitivity, acceleration, inversion, and camera response curves belong to Issue #2 / camera accessibility authority and are not silently decided here;
- exact Enhanced Input modifier implementation is an implementation detail so long as the player-facing semantics above are preserved.

Gate 1 must explicitly test centered healthy controllers, mild drift, near-dead-zone diagonals, slow circular stick motion, worn-controller maximum travel, keyboard diagonals, and traversal states whose neutral behavior must remain neutral.

---

## 14. Analog speed bands / sprint threshold philosophy — LOCKED

Processed movement-stick magnitude represents **how strongly the player wants to travel**, and baseline speed should respond continuously rather than snapping through arbitrary walk/run gears.

### Careful movement through ordinary run
- after dead-zone processing, analog magnitude maps continuously from very low-speed careful movement toward ordinary run;
- there is no separate baseline Walk button or Walk/Run toggle required to access precision movement;
- low stick magnitude must provide a genuinely useful careful-speed band for lining up traversal, approaching edges, interacting, and moving through tight spaces;
- increasing stick magnitude should increase requested travel speed smoothly enough that crossing an animation blend threshold does not feel like a gameplay speed switch;
- without Sprint requested, high/full analog magnitude reaches the ordinary run ceiling and does not silently enter Sprint.

### Sprint unlocks the upper band
- Sprint remains an **explicit request** through the already-locked Hold/Toggle control option;
- requesting Sprint does not turn a tiny stick tilt into full-speed sprint: low analog magnitude continues to mean low movement intent;
- Sprint becomes the active locomotion state only when both Sprint is requested and movement magnitude enters a clear upper travel-intent band;
- while Sprint is requested, increasing magnitude through that upper band blends toward the sprint ceiling; full valid magnitude reaches full sprint speed;
- lowering magnitude deliberately allows the player to return toward run/careful movement without first releasing the Sprint control;
- Sprint does not increase mantle height, ledge reach, slope scramble authority, jump impulse, or any traversal eligibility other than the already-locked preservation of existing horizontal sprint momentum into a jump.

### Threshold hysteresis / no state chatter
- the Sprint engage boundary and disengage boundary use a small hysteresis band rather than one razor-thin identical threshold;
- once Sprint is active, tiny stick fluctuations around the engage point do not repeatedly enter/exit Sprint every frame;
- dropping clearly below the lower disengage boundary exits active Sprint cleanly;
- exact engage/disengage magnitudes and the magnitude-to-speed response curve remain Gate 1 tuning, but the semantic separation must be stable and easy to reproduce across controller hardware.

### Hold / Toggle request lifetime
- **Hold**: Sprint is requested only while the Sprint control is held;
- **Toggle**: a toggled Sprint request may remain armed through brief ordinary neutral movement so the option actually reduces repeated button presses;
- entering an explicitly incompatible locomotion state—such as target lock, hanging, ladder traversal, swimming, committed slide, planted interaction, or damaging-fall recovery—clears active Sprint and clears a toggled Sprint request so exiting that state does not unexpectedly launch Neris back into Sprint;
- the player can always toggle Sprint off manually before such a transition;
- exact brief-neutral persistence timing, if any is needed to distinguish a pause from a state transition, remains implementation tuning and must not create surprise movement.

### Digital movement
- digital movement input represents full directional magnitude for the currently allowed non-Sprint movement band;
- without Sprint requested, digital movement reaches ordinary run;
- with Sprint requested and Sprint legally available, digital movement reaches full Sprint;
- diagonal normalization remains binding, so keyboard diagonal run/sprint is not faster than cardinal run/sprint.

The target is one readable continuum: **tilt a little to move carefully, push farther to run, explicitly request Sprint to unlock the fastest travel band.**

---

## 15. Acceleration / deceleration / turning philosophy — LOCKED

Stillring prioritizes **immediate intention acknowledgement with speed-dependent physical weight**. The character should feel responsive at all speeds, but higher momentum should be visible and believable rather than erased.

### Input acknowledgement
- a valid change in movement intent begins affecting requested movement immediately; basic locomotion does not wait for an animation anticipation, foot plant, or turn clip before acknowledging input;
- acceleration curves may shape how quickly velocity changes, but they may not create a perceptible dead pause before motion begins;
- gameplay movement/state remains authoritative; animation follows the locomotion result rather than owning ordinary exploration trajectory through opaque root-motion delays.

### Careful / low-speed movement
- careful movement accelerates, decelerates, and changes direction very quickly so precision positioning does not feel mushy;
- releasing the stick from low speed should settle to rest promptly without skating or a long stopping animation;
- small directional corrections near edges or interaction points should feel direct and trustworthy.

### Ordinary run
- ordinary run uses brisk acceleration to requested speed and brisk deceleration when intent is reduced or released;
- stopping distance is short enough that ordinary running never feels like moving on ice;
- deceleration may be slightly stronger than acceleration where useful for control, but exact rates remain Gate 1 tuning;
- ordinary run can make tight practical turns without being forced through a broad vehicle-like turning radius;
- a hard run reversal may use a quick planted pivot/reorientation, but control response remains substantially faster/lighter than a full-speed Sprint reversal.

### Sprint weight
- Sprint carries more visible momentum than run, especially when stopping or making a hard reversal;
- ordinary Sprint curves remain highly steerable as already locked;
- hard Sprint reversal still briefly sheds momentum, plants, redirects, and re-accelerates rather than instantly preserving full speed in the opposite direction;
- releasing Sprint or reducing analog magnitude uses a short controlled deceleration into the requested lower-speed band instead of either hard-zeroing velocity or coasting excessively;
- Sprint momentum may be visually sold through lean, stride, pivot, and recovery animation, but those animations may not add hidden control lock beyond the movement-state rules.

### Direction / facing
- in free exploration, Neris turns toward the requested movement direction promptly and smoothly enough that the character never feels like a tank;
- at careful and ordinary run speeds, facing should converge quickly to movement intent;
- at Sprint speed, facing/velocity may visibly lag a hard direction change just enough to communicate momentum, while ordinary curves remain responsive;
- exact rotation rates and animation blending remain Gate 1 tuning and must be evaluated together with camera behavior later under Issue #2.

### Digital parity
- keyboard/digital inputs use the same speed-band acceleration/deceleration philosophy as controller input rather than bypassing directly to physically impossible instantaneous velocity;
- digital direction changes must remain responsive, and diagonal normalization remains binding.

### Collision / state-transition continuity
- ordinary collision contact must not create pinball bounce, unexplained speed gain, or long residual sliding;
- transitions into jump, interaction, target lock, mantle, ladder, swim, slide, or another explicit state preserve or shed velocity only according to that state's documented rules;
- animation-state changes, frame-rate variation, or repeated state toggling may not manufacture extra acceleration/deceleration impulses.

Exact acceleration, braking, friction, rotation, and pivot values remain prototype tuning. The semantic target is locked: **precision is immediate, running is brisk, Sprint has believable extra weight, and no locomotion animation is allowed to make intention feel late.**

---

## 16. Target-lock locomotion — LOCKED

Target lock changes **movement reference and precision**, not the basic ownership principle. The player still controls position; the system does not secretly orbit, maintain distance, or choose combat spacing on the player's behalf.

### Target-relative movement frame
While target-lock locomotion is active on ordinary ground:
- forward input moves Neris toward the locked target;
- backward input moves away from the locked target;
- left/right input strafes/orbits around the target on the local horizontal plane;
- diagonals combine those radial and lateral components normally and remain magnitude-normalized;
- the target-relative forward axis is based on the horizontal/projected direction to the target, not on camera pitch or target height;
- if Neris and the target become nearly co-located such that the radial frame would become numerically unstable, locomotion uses the last valid horizontal target-relative frame until a stable direction exists again rather than flipping controls unpredictably.

### Player owns combat spacing
- target-lock locomotion does **not** automatically maintain a preferred distance;
- it does not automatically orbit when the stick is neutral;
- it does not push Neris forward/back to preserve framing;
- target collision/spacing may prevent physical overlap, but collision does not become an invisible auto-positioning system;
- attacks, evades, pulls, knockback, or other combat actions may have their own movement authority later, but ordinary locked locomotion itself does not lunge or reposition automatically.

### Speed / precision
- target-lock movement preserves analog low-speed precision and the same processed dead-zone semantics as exploration movement;
- full exploration Sprint is unavailable while locked as already established;
- locked ground movement uses a deliberate combat-appropriate maximum travel band below exploration Sprint speed;
- forward, backward, and lateral movement must all remain useful and responsive; any directional speed differences are modest tuning choices rather than severe hidden penalties or disabled directions;
- acceleration/deceleration is brisk and precise, following the low/run responsiveness philosophy rather than Sprint-weight inertia;
- exact locked maximum speeds, directional multipliers, acceleration, and rotation rates remain Gate 1 tuning.

### Facing
- while locked and not overridden by a higher-priority action, Neris faces/orients toward the target promptly enough to support readable strafing and radial movement;
- facing may blend physically rather than snapping, but animation may not delay movement input;
- ordinary target-lock locomotion does not turn into tank controls when the target moves rapidly across Neris's facing.

### Entering lock
- acquiring target lock ends active exploration Sprint immediately as a state while preserving brief physical velocity through the already-locked short deceleration/pivot;
- remaining velocity settles into the target-relative locomotion frame rather than being hard-zeroed;
- the current held movement input is honored in the new target-relative frame without requiring the player to release and press again;
- any toggled Sprint request is cleared by entry into target lock, preventing surprise Sprint when lock later ends.

### Jump / traversal boundary while locked
- Jump remains the same deliberate baseline jump when legally available; target lock does **not** silently convert Jump into a side-hop, backflip, dodge, or contextual evade;
- combat evade/reposition remains a separate combat verb/system;
- routine step handling remains available;
- automatic exploration entries that could unexpectedly seize combat movement—especially mantle initiation and ladder mounting—are suppressed while target-lock ground locomotion is active unless a later explicit combat/traversal rule authorizes them;
- if Neris physically enters an incompatible traversal state such as hang, ladder, surface swim, committed slide, or a tool-owned traversal state, target-lock locomotion ends; target retention/camera behavior after that transition belongs to Issue #2/combat lock authority;
- a valid ledge catch caused by an actual airborne trajectory may still save a fall under the existing ledge rules, and entering the hang state ends target-lock locomotion.

### Target-lock jump air-control frame
- when Neris jumps while target-lock locomotion is valid, her already-limited airborne movement correction remains **target-relative**, preserving the same movement language used at takeoff;
- the jump gains no additional air-control magnitude, speed, jump impulse, or combat-evade behavior from target lock;
- if target lock remains valid throughout the airborne state, the target-relative frame may continue updating normally from the valid target relationship so long as the resulting limited correction remains predictable;
- if lock is voluntarily released, lost, or invalidated while Neris is airborne, the movement reference **does not snap to camera-relative mid-jump**;
- instead, the last stable horizontal target-relative frame is frozen for the remainder of that short ordinary airborne state, preserving the meaning of currently held movement input;
- landing with no active lock restores ordinary camera-relative exploration movement immediately;
- entering another explicit traversal/movement-authority state before landing hands control to that state's documented grammar instead;
- this stable-frame rule prevents reference-frame betrayal; it does not preserve target lock for camera/targeting purposes after the lock itself is gone.

### Releasing / losing lock on ground
- voluntarily releasing lock or losing a valid target while grounded returns movement to camera-relative exploration semantics without hard-zeroing existing velocity;
- held movement input is reinterpreted under exploration movement immediately; no stick/key re-press is required;
- because the Sprint request was cleared on lock entry, leaving lock never auto-Sprints Neris;
- camera recentering, target-selection behavior, lock-loss presentation, and camera framing remain Issue #2 / combat-camera authority.

The target feel is **precise position control around an opponent, with no invisible autopilot and no midair control-reference surprise**.

---

## 17. Locomotion accessibility implications — LOCKED

Accessibility support should reduce **input burden and hardware friction without changing authored world rules**. A player may choose a more comfortable way to express the same locomotion intent, but accessibility settings do not secretly expand traversal reach, grant immunity, or change puzzle geography.

### Remapping and action independence
- all player-facing locomotion actions must be remappable through Enhanced Input, including movement directions/axis source, Sprint, Jump, and Drop/Release;
- controls that overlap with interaction or target-lock systems must remain remappable in their own control authority as well;
- remapping must preserve action semantics: Drop/Release stays a deliberate release action, Jump stays Jump, and Sprint remains distinct from evade;
- the control UI must detect or clearly warn about destructive binding conflicts instead of silently making a locomotion action unreachable;
- no locomotion rule depends on one specific manufacturer button label or keyboard key.

### Sustained-input alternatives / no mashing
- Sprint supports Hold and Toggle as already locked, with Hold default;
- ordinary swimming never requires repeated button tapping to remain afloat;
- mantle, ledge catch, ladder mount, and valid water entry use intention/geometry rather than repeated grab/interact presses;
- ordinary ledge hang and ladder hold do not require continuously holding a grab button;
- no baseline locomotion verb requires rapid repeated tapping, stick wiggling, a multi-button chord, or a long hold-to-confirm action;
- ordinary safe landing has no mandatory timed “perfect landing” input or QTE.

### Controller hardware tolerance
- player-configurable radial movement dead-zone and supported outer-saturation settings remain required;
- settings expose reset-to-default and explain the precision-versus-drift tradeoff in plain language;
- drift tolerance may change when movement begins responding, but it may not change maximum movement speed, traversal reach, or world eligibility;
- worn-controller support must be tested without treating broken/noisy input as intentional traversal direction.

### Digital precision option
- keyboard/digital movement normally represents full ordinary run magnitude as already locked;
- an **optional remappable Digital Precision modifier** must be available so digital-input players can deliberately access the careful movement band without needing analog hardware;
- the modifier may support Hold and/or Toggle presentation according to accessibility/control settings, but its locomotion meaning is simply “request the tuned careful digital movement magnitude”;
- Digital Precision does not create crouch, stealth bonuses, new collision size, extra traversal eligibility, or a separate gameplay state beyond requested movement magnitude;
- Sprint request while Digital Precision is active does not override the precision request into full Sprint until the player leaves precision mode or otherwise expresses full travel intent;
- exact careful digital magnitude remains Gate 1 tuning and should match a useful region of the controller careful-movement band.

### Timing forgiveness is baseline, not an assist cheat
- the short coyote window and jump-input buffer are baseline control forgiveness for all players rather than hidden difficulty assists;
- they do not need to be manually enabled to make basic movement reliable;
- neither may bypass authored traversal restrictions, damaging recovery, deliberate release states, or height gates.

### No accessibility tax on world honesty
- an accessibility setting may alter input ergonomics, dead-zone tolerance, Hold/Toggle behavior, or access to the careful digital speed band;
- it may not silently increase mantle height, ledge-catch reach, ladder magnetism, slope scramble authority, jump arc, air control, water access, or fall-damage safety;
- any future assist that intentionally changes traversal geometry or timing windows beyond the locked baseline must be proposed, named, and reviewed as a separate accessibility/gameplay rule rather than smuggled in through input settings.

### Scope boundary
- camera inversion, camera sensitivity, look-stick dead zones, motion reduction, target-lock presentation, and camera assistance belong to Issue #2 / broader accessibility authority;
- combat input assists belong to combat authority;
- this section records only locomotion-facing implications.

Gate 1 accessibility verification must include at minimum: fully remapped locomotion controls, Hold and Toggle Sprint, a drifting controller with adjusted dead zone, a worn controller using outer saturation, keyboard diagonal normalization, keyboard Digital Precision, and confirmation that no accessibility setting changes authored traversal eligibility.

---

## 18. Canonical five-minute human-play acceptance test — LOCKED

This is the **owner-facing feel gate**, not a substitute for automated/unit/functional testing. It is designed to expose betrayal of player intent quickly. Passing automated checks does not override a human result of “this feels wrong.”

### Test-course requirement
Gate 1 must provide one compact representative locomotion course that can be completed continuously without menus/loading and contains, in route order or a similarly efficient layout:
- flat open movement space, a tight precision area, small stairs/steps/floor lips, and an ordinary unsupported edge that can be approached carefully or deliberately walked off;
- knee/waist and waist/lower-chest mantle obstacles plus a shoulder-height obstacle that must **not** baseline auto-mantle;
- a small authored jump gap, a catchable ledge, same-handhold shimmy segment, valid pull-up top, blocked pull-up top, deliberate Drop/Release case, and a nearby alternate catch opportunity suitable for proving same-handhold suppression without globally disabling catches;
- a ladder positioned so the player can intentionally approach it and also pass nearby/parallel without mounting; valid top/bottom exits and a mid-ladder release opportunity;
- shallow/wade water, ordinary deep swimmable water, a valid low exit, and a high/blocked exit;
- normal walkable slope, short borderline scramble slope, and steep/low-traction slide slope;
- safe traversal drop, upper-safe/heavy landing, and a controlled damaging-fall example;
- one movement-compatible interaction and one planted/alignment-required interaction;
- one target-lock dummy with enough space for radial/strafe movement, ordinary jumping, and a nearby mantle/ladder temptation that should remain suppressed while locked;
- one visually plausible but unsupported rough wall/cliff route that proves baseline free climbing remains impossible.

The course may use graybox geometry. Visual polish is irrelevant; semantic readability and repeatability are mandatory.

### Five-minute script
Run the following as one continuous pass. Times are targets, not frame-perfect requirements.

**0:00–0:45 — ground trust / speed bands / edge ownership**
- start from neutral and make several tiny analog movements in different directions;
- smoothly push from careful → run → requested Sprint, then reduce magnitude without releasing Sprint;
- release movement from run and Sprint and judge stopping distance;
- perform normal curved Sprint steering and one hard Sprint reversal;
- intentionally hover around the Sprint threshold to check for chatter;
- pass over stairs/small lips without special input;
- approach an ordinary unsupported edge carefully, stop close to it, then deliberately continue forward on a second attempt and verify Neris **walks off rather than invisibly braking**.

**0:45–1:35 — jump / mantle / ledge intent**
- perform ordinary jump from stand/run/Sprint and verify no hidden speed boost;
- intentionally press Jump slightly late at an ordinary edge once to feel the coyote window, and slightly early before a legal landing once to feel the buffer;
- make a small midair correction and then attempt an unreasonable hard reverse that must remain limited;
- approach low mantle geometry directly, then brush/pass parallel to similar geometry and verify only the deliberate case triggers;
- test the upper mantle boundary so shoulder-height+ does not silently auto-mantle;
- deliberately catch a valid ledge, remain neutral, shimmy, stop at a forbidden corner/gap, pull up on a valid top, remain hanging at a blocked top, and use explicit Drop/Release;
- after deliberate Drop/Release, verify the **same released handhold does not instantly re-catch Neris** without real separation/new approach;
- where the course provides it, confirm a different genuinely reachable ledge can still be caught during a valid falling trajectory;
- push analog down/away while hanging once and verify it does **not** drop.

**1:35–2:15 — ladder trust**
- pass close/parallel to the ladder without mounting;
- directly approach with clear intent and mount;
- climb up, down, stop neutral mid-ladder, then complete a valid end exit;
- repeat enough to test the opposite end if needed;
- use explicit Drop/Release mid-ladder and verify analog direction alone never releases;
- confirm deliberate release does not instantly remount the same ladder from unchanged overlap;
- confirm no magnetic long-distance alignment or forced blocked-end placement.

**2:15–2:55 — water / slope / fall consequence**
- wade through shallow water without entering unnecessary swim state;
- enter deep water automatically, swim camera-relative, release movement and tread, press down/look downward without silently diving, then use a valid low exit;
- test a high/blocked water edge and verify no invented climb;
- traverse ordinary slope, deliberate short scramble slope, and committed slide with limited steering;
- attempt one out-of-band uphill trick/diagonal/jump-spam approach and verify no mountain-goat ratcheting;
- take a safe drop and a controlled damaging fall and judge whether consequence is clear without excessive control theft.

**2:55–3:35 — interaction continuity**
- trigger a movement-compatible interaction while moving and verify movement is not unnecessarily zeroed;
- approach a planted interaction at run/Sprint, request it while moving, and verify short natural deceleration plus only local plausible alignment;
- move away before commit once and verify clean cancellation/no delayed surprise trigger;
- after a committed interaction releases movement, keep holding a valid direction and verify Neris resumes without requiring input re-press.

**3:35–4:20 — target-lock precision / airborne frame stability**
- acquire target lock while moving fast enough to expose the Sprint→lock transition;
- move toward, away, left/right, and diagonally around the dummy;
- release stick and verify there is no auto-orbit or auto-distance correction;
- press Sprint and verify exploration Sprint remains unavailable;
- press Jump and verify it remains the baseline jump rather than a contextual evade flip;
- while airborne from target lock, make a small allowed correction and verify its movement frame remains target-relative;
- lose/release lock during one ordinary jump and keep holding a directional correction: verify the **last stable target-relative frame remains in force until landing** rather than snapping the held input to camera-relative midair;
- deliberately move toward the nearby mantle/ladder temptation and verify locked ground locomotion does not accidentally seize that exploration traversal;
- release/lose lock while grounded and holding movement and verify physical continuity plus immediate return to camera-relative exploration without re-press or surprise Sprint.

**4:20–5:00 — stress loop / forbidden behavior**
- chain Sprint → jump → landing → interaction → target lock → unlock → Sprint again;
- repeat a ledge/ladder/water boundary quickly enough to expose accidental double triggers;
- run directly at the unsupported rough wall/cliff and try obvious jump/Sprint/diagonal abuse: baseline free climbing must remain impossible;
- finish with several rapid but reasonable direction/speed changes and ask whether the controls disappear beneath intention rather than demanding attention themselves.

### Input-profile repetition
- the canonical test unit is **five minutes per input profile**, not five minutes split between devices;
- run at least once with a representative controller using default movement settings;
- run again on keyboard/digital input using ordinary movement and the Digital Precision option before Gate 1 locomotion is considered input-complete;
- Hold/Toggle Sprint, drift/worn-controller settings, and remap functionality also receive their separate accessibility verification; they need not all fit inside one five-minute feel pass.

### Hard-fail conditions
Any one of these fails the locomotion feel gate regardless of automated pass status:
- Neris moves, mounts, mantles, drops, dives, climbs, exits, or interacts without a player intent that reasonably explains it;
- ordinary unsupported edges invisibly stop/guard deliberate movement without an explicit authored traversal state that owns that behavior;
- a deliberate Drop/Release immediately re-catches/re-mounts the same released traversal attachment without genuine separation/new valid approach;
- clear legal intent is ignored because an animation/state waits unnecessarily or requires input release/re-press;
- a target-lock jump changes the meaning of held airborne movement mid-jump because the lock was lost/released;
- a transition hard-snaps/teleports position or velocity where the contract requires physical continuity;
- analog drift/noise triggers movement or traversal;
- repeated state transitions manufacture speed, height, fall reset, or collision bypass;
- an unsupported wall/slope becomes solvable through input spam or diagonal abuse;
- target lock auto-positions the player or exploration traversal steals locked combat movement unexpectedly;
- accessibility settings change authored traversal eligibility;
- the human tester reports that routine movement feels slippery, mushy, late, magnetic, unpredictable, or tiring enough that they are thinking about fighting the controls instead of playing.

### Tuning note versus semantic failure
A test may produce **tuning notes** without failing the locked design when the behavior class is correct but an exact value needs adjustment—for example sprint acceleration slightly too quick, shimmy speed slightly slow, coyote window slightly generous, or a mantle angle needing refinement.

A **semantic failure** is not a tuning note. Examples: analog-down drops a ledge, Sprint adds jump speed, ladder proximity auto-mounts, an ordinary edge invisibly refuses deliberate walk-off, deliberate Drop instantly re-grabs the same handhold, target-lock loss remaps held air correction mid-jump, target lock auto-orbits, a blocked water edge pulls Neris out, or shoulder-height geometry baseline auto-mantles. Semantic failures must be fixed before proceeding.

### Required human verdict
After each five-minute run, the tester records:
1. **Did Neris go where I intended?**
2. **Did Neris ever move/traverse when I did not intend it?**
3. **Did any animation or state hold control longer than the visible action justified?**
4. **Did the world ever lie about what looked traversable?**
5. **Was I thinking about the destination/problem, or thinking about fighting the controls?**

For final owner acceptance, questions 1 and 5 must resolve positively and questions 2–4 must have no unresolved material failure. The owner may reject locomotion on feel even when every machine-verifiable check passes.

### Regression rule
Re-run this five-minute test after any material change to movement physics, collision, traversal detection, movement animation/root motion, Enhanced Input processing, target-lock movement, or representative environment geometry. Art/prop/collision changes that alter traversal routes are not exempt.

---

## Current locked movement grammar
```text
baseline ground/jump/sprint                   → ordinary locomotion contract
ordinary ground + deliberate edgeward intent → NO invisible edge guard; unsupported edge may be left
ordinary ground-edge departure               → airborne/fall rules + short coyote opportunity
mantle / ledge / ladder / swim / slope        → their explicit locked state grammar
explicit ledge/ladder Drop                    → released attachment cannot immediately auto-recatch/remount
post-release different valid ledge            → may catch only under normal trajectory/intent rules
interaction while moving                      → valid flow without magnetic snapping
future traversal tool owned                   → NO passive universal movement expansion
valid authored tool affordance + clear intent → enter that tool's explicit traversal state
invalid tool target/entry                     → do not seize movement / do not magnetically pull
tool traversal active                         → only documented axes/verbs/overrides apply
tool cancel/exit/failure                      → restore baseline movement predictably
tool state churn                              → NO free height/speed/fall reset/collision bypass
movement stick inside radial dead zone        → zero movement intent
movement stick outside radial dead zone       → preserve direction + smoothly rescaled magnitude
stick drift / dead-zone noise                 → NO movement and NO directional traversal intent
near-full worn-controller input               → configurable outer saturation may reach full intent
analog low magnitude                          → useful careful movement
analog high magnitude, no Sprint request      → ordinary run ceiling
Sprint requested + low magnitude              → remain low/ordinary movement; NO forced full sprint
Sprint requested + upper magnitude band       → stable Sprint engagement and blend toward sprint ceiling
Sprint threshold noise                        → hysteresis prevents state chatter
careful movement intent change                → near-immediate precise acceleration/deceleration/turn
ordinary run intent change                    → brisk response; short stopping distance; tight practical turns
Sprint ordinary curve                         → highly steerable with visible momentum
Sprint hard reversal                          → brief momentum shed + planted redirect + re-acceleration
release/reduce Sprint intent                  → short controlled deceleration to requested lower band
target lock + forward/back                    → move toward/away from target
target lock + left/right                      → strafe/orbit; player owns spacing
target lock + neutral                         → no automatic orbit/distance correction
target lock + Sprint request                  → NO exploration Sprint
target lock + Jump                            → normal baseline jump; NO contextual evade flip
target-lock jump + valid lock                 → limited air correction remains target-relative
lock lost/released during ordinary jump       → freeze last stable target-relative frame until landing/state change
target lock → incompatible traversal state    → end target-lock locomotion; enter explicit traversal state
grounded release/lose target lock             → preserve physical velocity; return to camera-relative exploration
remapped locomotion actions                   → same semantics on chosen bindings
Digital Precision active                      → tuned careful digital movement magnitude; NO new traversal eligibility
accessibility input settings                  → ergonomics/tolerance only; NO hidden world-rule expansion
human five-minute feel test                   → owner feel verdict outranks automated pass
animation transition                          → follows movement authority; NO hidden input-delay ownership
```

---

## Final owner-review closure — COMPLETE

The final red-team review exposed and closed three implementation ambiguities:
1. ordinary ground edges do not use an invisible edge guard;
2. deliberate Drop/Release cannot immediately auto-recatch/remount the released attachment without genuine separation and a new valid approach;
3. target-lock airborne correction retains a stable target-relative frame through an ordinary committed jump, freezing the last stable frame if lock disappears before landing.

The owner explicitly instructed these items to be walked through and auto-approved. They are now **LOCKED**. Issue #1 may close after repository/decision-register bookkeeping confirms this final authority state.
