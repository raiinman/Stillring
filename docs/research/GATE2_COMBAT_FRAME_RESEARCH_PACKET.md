# Gate 2 Combat Frame / State Model — Research Packet

**Status:** NON-CANONICAL / OWNER REVIEW REQUIRED  
**Updated:** 2026-09-05  
**Issue:** #3 — Define combat frame and state model

## Purpose
Prepare the next major player-feel/state-model conversation without allowing animation assets, Unreal defaults, or generic action-game conventions to become Stillring combat authority.

Stillring already locks several constraints that combat must respect:
- combat is target-relative when locked;
- spacing remains player-owned; no auto-orbit or auto-distance autopilot;
- exploration Sprint is not the combat evade;
- Jump remains Jump rather than becoming a hidden contextual dodge;
- camera/encounter readability must respect what the player can actually see;
- authoritative gameplay/state remains C++ first;
- Animation Blueprints present state rather than becoming a second contradictory rules engine;
- every combat system must grow alongside its Combat System IDE.

This packet is research, not approval.

---

## 1. Architecture conclusion — gameplay state owns animation, not the reverse

Unreal 5.8 provides several useful state/animation mechanisms, but none should be allowed to become Stillring's combat rules by accident.

- Animation Blueprint State Machines are explicitly animation-branching tools.
- Animation Montages provide controllable sections, slots, blending and interruption callbacks.
- StateTree is a general-purpose hierarchical state-machine framework with explicit states, enter conditions, tasks and transitions.

Recommended Stillring boundary:

> **Combat legality lives in authoritative gameplay state. Animation presents and timestamps that state.**

A montage finishing, a notify firing, or an AnimBP state change may report presentation progress; it should not secretly decide whether Neris is allowed to guard, evade, cancel, take damage, or enter another combat action unless the gameplay state contract explicitly delegates that timing boundary.

StateTree may be useful later for enemy behavior or authored high-level logic, but player combat does not need to adopt it merely because Unreal ships it. A compact C++ state/transition service is easier to keep deterministic, IDE-readable, and aligned with the existing C++-first authority unless prototype evidence shows otherwise.

---

## 2. Proposed player combat state families

These are **candidate semantic families**, not locked names/classes.

### Free / locomotion-ready
Neris can accept ordinary movement and eligible action requests.

### Light attack
Fast offensive commitment with chain windows. Exact chain count/timing is later tuning.

### Committed / heavy attack
Longer commitment with more deliberate startup/recovery. Must not simply be “light attack but slower.”

### Guard
Defensive state with explicit facing/coverage semantics to be decided.

### Evade
A dedicated combat reposition/avoidance action, separate from Sprint and Jump.

### Hit reaction
Gameplay reaction to being struck, parameterized by severity/interrupt result rather than every damage event forcing the same animation lock.

### Stagger / hard interrupt
Stronger loss-of-action state for attacks/effects that legitimately break commitment.

### Recovery
Post-action state/window where future actions may be restricted or selectively buffered.

### Death
Terminal player combat state until retry/reset authority.

### Higher-priority traversal / interaction ownership
Ladder, hang, mantle, swim, committed slide, tool-owned traversal, cinematic/scripted ownership etc. must explicitly define whether combat action requests are rejected, queued, or force an exit. Combat may not silently seize those states.

---

## 3. Core design question: commitment versus responsiveness

Research across action games points to the same design tension: if every action cancels instantly, attacks lack consequence; if every animation is an unbreakable lock, controls feel sluggish.

Recommended Stillring principle candidate:

> **Commit to the decision, not to dead time.**

Meaning:
- early action startup carries real commitment;
- recovery is readable and consequential;
- selected late windows may accept clearly defined follow-up/cancel requests;
- input buffering should preserve a player's near-window intention without allowing button mashing to pre-program long sequences;
- cancel permissions are semantic per action/state, not “anything cancels anything.”

Candidate action phases for authoritative state data:
1. `Startup`
2. `Active`
3. `Recovery`
4. optional action-specific `ChainWindow` / `CancelWindow`

These phases can be driven by reviewed combat data and synchronized with animation presentation. Exact frame/timing values remain prototype tuning.

---

## 4. Light-chain recommendation

The light chain should feel learnable without becoming an automatic combo movie.

Candidate rules:
- one press = one attack request;
- subsequent valid press during an approved buffer/chain window requests the next chain entry;
- at most one next action should normally be buffered at once;
- missing the chain window returns to recovery/free state rather than silently queueing multiple future attacks;
- directional movement/target-relative orientation can influence facing where explicitly approved, but attacks should not vacuum Neris large distances toward targets;
- target changes during a chain follow camera/targeting authority, not attack-animation target magnetism.

Open owner questions:
- chain depth;
- how much turn correction is allowed per swing;
- whether late-chain attacks become more committed;
- whether guard/evade may cancel selected recovery windows.

---

## 5. Heavy / committed attack recommendation

Heavy attacks should earn their identity through **commitment and consequence**, not merely damage values.

Candidate rules:
- more obvious startup and recovery than light attack;
- stronger interruption/guard-pressure result if later combat rules retain those concepts;
- less rotational correction after commitment begins;
- cannot be freely canceled during its core committed interval;
- clear visual/audio anticipation gives enemies/player time to read it;
- no arbitrary stamina tax is assumed here.

Open owner questions:
- charge/hold behavior versus fixed committed attack;
- whether specific late recovery can evade/guard cancel;
- whether heavy attacks interact with shields/armor/posture as a primary verb.

---

## 6. Guard research direction

Guard should be a deliberate defensive verb rather than a passive always-on damage reducer.

Candidate semantic questions for owner review:
- hold guard versus timed guard/parry distinction;
- directional/front-arc coverage versus omnidirectional lock-on abstraction;
- cost model: no cost, posture/guard integrity, combat-only stamina, or attack-specific break rules;
- what happens on successful ordinary block;
- what happens on precisely timed defensive input if a parry/perfect guard exists;
- whether ranged/projectile attacks follow the same coverage semantics;
- whether guard can be raised from selected recovery windows.

Do not let animation pose alone determine coverage. The gameplay service must be able to explain why a hit was blocked or not.

---

## 7. Evade / i-frame research direction

The combat evade must remain distinct from exploration Sprint.

Three credible families should be owner-compared before locking:

### A. Position-first evade
Avoidance comes mainly from rapid displacement/spacing; few or no invulnerability frames.

Pros: world-honest, highly readable.  
Risk: geometry/collision/enemy hit volumes must be exceptionally clean.

### B. Short justified invulnerability window
A brief central window forgives overlap while the visual action communicates a committed evade.

Pros: robust against complex melee volumes; familiar.  
Risk: can become rhythm-game rolling through attacks if too generous.

### C. Attack-specific evasion logic
Some attacks are avoided spatially, some through a small invulnerability class/window.

Pros: potentially expressive.  
Risk: harder to explain, test, and author consistently.

Recommended research hypothesis: start prototype testing around **position-first with a short, clearly bounded forgiveness window** rather than assuming either zero i-frames or Souls-like broad invulnerability. Exact existence/timing requires owner approval and human combat play.

---

## 8. Hit reaction / interrupt hierarchy

Every hit should not erase every player action. Conversely, “hyper armor everywhere” destroys combat readability.

Candidate authoritative result classes:
- `DamageOnly` — health/result changes, action continues;
- `LightReact` — cosmetic/small gameplay response if current state permits;
- `Interrupt` — current eligible action is broken into reaction/recovery;
- `HardStagger` — stronger explicit loss of action;
- `Death` — highest priority.

The incoming attack/effect and current Neris state together decide the result. The animation selected is presentation of that result.

Combat IDE must expose both:
- incoming hit properties;
- exact reason the current state did/did not interrupt.

---

## 9. Priority model candidate

Rather than allowing ad hoc transition checks scattered through attack code, use one authoritative transition request path.

Conceptual priority from highest to lowest:
1. death / invalid player state;
2. forced world/traversal/script ownership where explicitly authoritative;
3. hard stagger/forced hit reaction;
4. explicitly allowed defensive cancel;
5. action chain/follow-up;
6. new ordinary attack request;
7. locomotion-ready/free.

This hierarchy is research scaffolding only. Owner decisions on guard/evade/cancel philosophy can alter it.

Every rejected request should return a semantic reason suitable for the Combat IDE, e.g.:
- `Rejected_CommittedAttackPhase`
- `Rejected_HardStagger`
- `Rejected_TraversalOwnsMovement`
- `Rejected_NoValidTargetRequirement`
- `Rejected_ActionNotCancelableIntoGuard`

---

## 10. Input buffering candidate

Use small action-specific request buffers rather than global combo queuing.

Rules to test:
- only buffer actions meaningful for the current/next state;
- one pending request per semantic action lane by default;
- expiration is explicit and visible in the IDE;
- repeated identical button presses do not keep extending expiration indefinitely;
- a newly higher-priority explicit request may replace a lower-priority buffered request only if the state contract says so;
- buffering never survives unrelated state ownership changes unless explicitly designed.

The player should feel “the game heard me,” not “the game is executing commands I entered a second ago.”

---

## 11. Target-lock interaction

Locked locomotion/camera authority already establishes:
- radial forward/back movement;
- strafe/orbit left/right;
- player-owned spacing;
- no auto-distance maintenance;
- Jump remains Jump;
- established Relationship Frame camera.

Combat must therefore avoid hidden target autopilot:
- attacks should not auto-orbit around the target;
- rotation assistance, if any, must be bounded and action-specific;
- movement translation/magnetism toward a target must be extremely limited or absent unless explicitly owner-approved;
- losing lock during an attack must have deterministic facing/continuation behavior rather than snapping to another target;
- target switching remains camera #12 authority.

---

## 12. Enemy/encounter readability implications

Camera Decision #6 and the Zelda-lineage register already make encounter readability a system responsibility.

Gate 2 enemy behavior should eventually obey an **attack bandwidth** rule: not every enemy may deliver high-salience attacks simultaneously simply because AI can.

Research directions:
- distinguish pressure/positioning behaviors from committed attack tokens/opportunities;
- offscreen or occluded enemies should use reduced aggression or stronger telegraph/support rules where necessary;
- ranged enemies need readable line-of-fire/tell behavior compatible with the camera;
- shield/armor enemies should pressure verb choice, not merely inflate health.

Exact aggression coordination belongs in a later enemy/encounter decision, but the Combat IDE should be designed to visualize active attackers and queued pressure from the start.

---

## 13. Combat-specific resource question

ROADMAP explicitly permits a stamina/commitment model **for combat-specific mechanics only** if retained after testing. Ordinary Sprint must remain free.

Do not start implementation with a stamina bar merely because action games often have one.

Owner research comparison should test at least:
- no universal combat stamina; commitment comes from state/timing;
- evade/guard-specific resource only;
- one shared combat resource for defense/committed actions;
- posture/guard integrity separated from player action stamina.

A resource is justified only if it creates better decisions than the state/commitment windows already create.

---

## 14. Combat System IDE — required from first prototype

The Combat IDE should expose:

### Inspect
- current player combat state/family;
- action ID and phase;
- phase elapsed/remaining;
- current target/lock state;
- allowed transitions right now;
- rejected input requests and reasons;
- buffered request + expiry;
- current guard/evade/hit-reaction state;
- health/resources if any;
- last incoming/outgoing hit resolution;
- current facing correction / target-relative basis.

### Author / Tune
Only approved prototype values:
- startup/active/recovery/chain/cancel windows;
- bounded turn correction;
- damage/hit reaction prototype values;
- guard/evade prototype values after owner approval;
- input-buffer durations.

Every live edit must show canonical/session/staged/promoted provenance.

### Exercise
- spawn/reset melee/ranged/shield test enemies;
- set player/enemy health;
- grant representative loadout;
- force action/state for debugging without creating canonical gameplay shortcuts;
- replay attack-vs-guard/evade/hit cases;
- place target arrangements compatible with Camera IDE scenarios.

### Validate
- illegal transition graph edges;
- action with missing phase/cancel data;
- contradictory cancel rules;
- hit reaction with no resolution class;
- combat action that silently changes traversal authority;
- attack translation exceeding approved movement/magnetism boundaries;
- impossible buffered-action state;
- animation presentation state diverging from authoritative gameplay action/phase.

### Capture
Record state transition timeline + input requests + hit events + target/camera context so combat bugs can be reproduced without video archaeology alone.

---

## 15. Representative prototype matrix

### Action commitment
- light press once;
- light chain at early/on-time/late inputs;
- mash light continuously;
- heavy during free/light startup/light recovery;
- direction reversal during attacks;
- target loss mid-attack.

### Defense
- guard from free/startup/active/recovery;
- evade from same phases;
- hit during light/heavy/guard/evade/recovery;
- simultaneous hit/death boundary;
- repeated weak hits versus committed action.

### Movement/camera integration
- locked and unlocked attacks;
- switch target during allowed combat windows after #12 is approved;
- combat near wall/low ceiling/cramped camera;
- jump then attack requests (if airborne attacks are later proposed, currently do not infer them);
- traversal state receives combat input and clearly rejects/handles it.

### Input robustness
- low/high frame rate;
- controller/mouse+keyboard;
- short tap versus held inputs;
- buffered input just inside/outside validity window;
- repeated identical requests.

---

## 16. Recommended owner-decision sequence for Issue #3

Resolve these one at a time:
1. core attack commitment/cancel philosophy;
2. light chain semantics;
3. heavy/committed attack semantics;
4. guard model;
5. evade model and whether any invulnerability exists;
6. hit reaction / interrupt hierarchy;
7. input buffering rules;
8. target-facing/rotation assistance during attacks;
9. combat resource/stamina/posture decision;
10. death/retry combat-state boundary.

Then reconcile into one implementation-facing combat specification before broad Gate 2 implementation.

---

## 17. Research basis / engine boundary

Unreal Engine 5.8 research confirms:
- Animation Blueprint State Machines are animation logic systems;
- Animation Montages provide sections, slots and runtime-controlled animation playback;
- StateTree is a general-purpose hierarchical state machine with explicit states/conditions/tasks/transitions;
- these are available implementation primitives, not game-design authority.

Stillring should choose the smallest architecture that keeps gameplay rules explicit, C++-authoritative, IDE-inspectable, and independent of animation presentation.

Primary references:
- Epic UE5.8 StateTree Overview
- Epic UE5.8 Animation Montage documentation
- Epic UE5.8 Animation State Machines documentation
- `docs/01_GAME_VISION.md`
- `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md`
- `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`
- `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`

---

# Next future owner decision after camera closure

Recommended Issue #3 opening question:

> **When Neris commits to an attack, what should the player still be allowed to change before that attack is over?**

Candidate philosophy:
> **Commit to the decision, not to dead time.**
