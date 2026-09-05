# 40 — Gate 2 Combat Guard Model Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Combat Decision #4 for Issue #3. This file defines the representative Gate 2 ordinary Guard model after attack commitment, light-chain, and Heavy semantics are locked.

## Authority
Combat Decision #4 is locked under the owner's explicit scheduled-run delegation after a fresh focused research pass.

This decision answers:
- how Guard input behaves;
- whether Guard is directional or omnidirectional;
- what an ordinary successful block does;
- whether basic Guard consumes stamina/posture/integrity;
- how Guard movement and target lock behave;
- how Guard enters/exits combat state;
- what remains reserved for a later timed Perfect Guard/parry decision.

It does **not** yet define evade/i-frames, Perfect Guard/parry timing/reward, final hit reaction/interrupt hierarchy, universal combat resources, or final weapon/equipment roster.

Combat principle:
> **Commit to the meaningful decision, not to decorative dead time.**

Guard principle:
> **Defense should hold a line, not erase the fight.**

---

## Combat Decision #4 — ordinary Guard model — LOCKED

### Default Guard input is hold; Toggle is an accessibility-equivalent option
The representative Gate 2 Guard is a semantic `Guard` action.

Default behavior:
- press-and-hold Guard requests entry into Guard when legal;
- releasing Guard requests Guard exit when legal;
- Guard does not auto-toggle by default;
- holding Guard does not repeatedly generate new Guard actions.

Accessibility requirement:
- players must be able to switch Guard to **Toggle** behavior;
- Toggle and Hold must produce the same gameplay legality, coverage, reaction, and timing rules;
- changing Hold/Toggle is input ergonomics, not a combat-balance modifier;
- remapping Guard remains mandatory.

### Guard is a real gameplay state, not an animation pose
When Guard is accepted, authoritative combat state records Guard ownership.

Guard state must expose:
- Guard active/inactive;
- coverage orientation;
- blockable/non-blockable result for incoming attacks;
- Guard reaction state;
- movement authority while guarding;
- current target/facing context;
- Guard input mode (Hold/Toggle) as presentation/input metadata, not legality.

Animation presents Guard. An AnimBP pose alone may not make Neris block damage.

### Ordinary Guard is directional
Ordinary Guard protects a **front-facing defensive arc/sector**, not all directions.

Rules:
- incoming attack direction is evaluated against Neris's current authoritative guard-facing basis;
- attacks from sufficiently behind/outside the guard sector are not ordinary blocks;
- exact angular width remains prototype tuning;
- Guard does not become omnidirectional merely because target lock is active;
- the camera never counts as Guard facing authority;
- vertical attacks/projectiles still require physical/logical intersection with the defended sector rather than a magic spherical shield.

This preserves flanking, crowd positioning, and encounter readability.

### Lock-on helps maintain intentional facing but does not create auto-defense
When locked:
- normal target-relative combat facing may orient Neris toward the current target according to later facing authority;
- Guard uses Neris's resolved facing, not the target identity directly;
- switching lock target does not instantly turn an already-resolving block into protection from another direction unless Neris's body facing actually changes under legal facing rules;
- secondary enemies can still threaten from outside the defended arc.

When unlocked:
- Guard uses Neris's current body facing;
- the player may deliberately reposition/turn under guarded movement rules;
- Guard does not automatically seek the nearest enemy.

### Ordinary successful block negates normal direct HP damage from guardable attacks
For the representative baseline:
- a **guardable** incoming attack that arrives inside the defended sector while Guard is active is blocked;
- a successful ordinary block prevents that attack's normal direct HP damage;
- the blocked hit still produces an authored Guard Reaction and combat consequences such as short movement/attack delay, displacement, presentation, and later severity hooks;
- the block result must be explicit gameplay state, not merely a visual shield impact.

This makes Guard a dependable defensive verb rather than partial RNG-like mitigation.

### The cost of ordinary Guard is positional/temporal, not a stamina drain
Decision #4 does **not** add a universal Guard stamina meter, posture bar, shield-integrity meter, or passive drain.

Baseline cost comes from:
- front-facing coverage rather than 360° safety;
- reduced freedom while Guard is held;
- Guard Reaction after absorbing an attack;
- exposure to flanking/unblockable/grab/other later-authored threats;
- inability to freely attack while a blocking reaction owns the state;
- opportunity cost: time spent defending is time not spent attacking/repositioning freely.

A future combat-resource decision may add guard integrity/posture only if testing proves these state/position costs do not create enough decisions.

### No passive drain for simply holding Guard
Holding Guard while nothing hits Neris does not:
- drain stamina;
- consume health;
- degrade an invisible meter;
- cause escalating penalty merely because time passes.

The player is allowed to wait behind Guard, but Guard's limited direction, movement constraints, and encounter pressure prevent it from being total safety.

### Guard-capable versus unblockable attacks are explicit authored properties
Incoming attacks/effects must declare whether ordinary Guard can block them.

Minimum categories for Gate 2 testing:
- `Guardable` — ordinary Guard can block if direction/timing/state are valid;
- `Unblockable` — ordinary Guard cannot block; must have strong readable telegraph/presentation and a later valid response such as evade/spacing/interruption according to future authority.

Do not infer unblockability from animation size, damage amount, enemy type, or VFX alone.

A later Perfect Guard decision may optionally interact with attack categories, but ordinary Guard authority remains explicit.

### Guard Reaction is mandatory on a successful ordinary block
A successful block is not “nothing happened.”

The authoritative result enters a short Guard Reaction whose severity can later be parameterized.

Baseline semantics:
- offensive action requests are rejected while Guard Reaction owns the state unless later explicit transition authority permits otherwise;
- movement may be reduced/temporarily limited during the reaction;
- the reaction must end on gameplay timing, not animation clip end;
- exact reaction duration/displacement remain prototype tuning;
- different incoming attack weights may later map to different Guard Reaction severities under hit/interrupt authority.

This provides defense cost without immediately inventing a meter.

### Guard does not automatically counterattack
Ordinary block by itself does not:
- damage the attacker;
- stagger the attacker;
- open a guaranteed punish window;
- trigger slow motion;
- trigger a canned retaliation;
- grant invulnerability after the block.

A timed Perfect Guard/parry may later earn some of those outcomes through its own explicit decision.

### Guard movement is deliberate and slower than free combat locomotion
While Guard is active and not in Guard Reaction:
- Neris retains bounded movement/repositioning authority;
- movement is deliberate/guarded rather than full free-run speed;
- Sprint is unavailable while ordinary Guard is actively held/toggled on;
- Jump is not silently converted into a defensive hop;
- exact guarded movement speed/acceleration are tuning;
- target-relative strafing can remain available when locked;
- Guard movement never auto-orbits to keep every threat inside the defended arc.

This lets the player hold ground or adjust position without turning Guard into a stationary statue.

### Guard facing may track intentional combat facing, not camera yaw
Guard orientation follows Neris's authoritative facing solution.

The camera cannot rotate Guard coverage by itself.

If the player looks behind Neris with the camera while Neris keeps facing forward:
- Guard still protects Neris's forward defensive sector;
- visual camera freedom does not create hidden shield coverage behind her.

### Guard entry is immediate from legal free combat state
When Guard is legal from Free/locomotion-ready combat state:
- Guard request is acknowledged immediately;
- gameplay enters Guard without an arbitrary hidden delay;
- animation raises/presents the defensive posture promptly;
- the exact point at which coverage becomes active must be authoritative gameplay timing and visible in the IDE.

The coverage-active boundary may include a short raise time if human play proves it necessary, but this must be explicit data—not montage latency.

### Guard does not automatically cancel committed attacks
Decision #1 remains authoritative.

Until a later defensive-cancel decision explicitly adds edges:
- Guard request during Attack Startup/Active is rejected if the current action contract does not permit Guard;
- Heavy remains especially committed;
- Light chain does not gain free Guard cancellation merely because Guard now exists;
- late Recovery may eventually allow Guard through explicit per-action transition windows, but none are silently created here.

The Combat IDE must explain `Rejected_AttackCommitted` rather than dropping the input invisibly.

### Guard exit returns through explicit state authority
When Guard release/toggle-off is accepted:
- Guard ownership ends;
- ordinary locomotion/combat-ready state resumes subject to current Guard Reaction/recovery;
- animation blends down without creating extra gameplay lockout;
- releasing Guard during an active Guard Reaction may record exit intent, but Guard Reaction authority finishes according to its contract before offensive freedom returns unless later tuning/authority says otherwise.

No hidden “must finish lowering shield animation” delay is allowed.

### Multiple incoming hits are resolved individually
Guard does not create a temporary invulnerability bubble after one successful block.

For rapid/sequential attacks:
- each incoming hit evaluates Guard active state, defended sector, guardability, and current reaction rules;
- a valid second hit may also be blocked if Guard coverage remains active and reaction rules allow;
- attacks from another direction may hit normally;
- exact stacked reaction behavior remains hit/interrupt tuning, but no generic post-block i-frames are created here.

### Guard and projectiles use the same honesty rule
A projectile may be ordinary-blocked when:
- it is authored `Guardable`;
- its incoming direction falls inside the defended sector;
- Guard coverage is active at contact.

Ordinary Guard does not automatically reflect projectiles.

Projectile reflection is reserved for future Perfect Guard/parry or tool-specific authority.

### Guard and grabs / non-strike threats
Grabs, ground hazards, explosions, status fields, and similar effects do not become Guardable by default.

Each effect class must explicitly declare ordinary-Guard interaction.

A big visual effect is not automatically unblockable, and a small one is not automatically guardable; the authored semantic property controls the result.

### No hidden equipment durability rule
Decision #4 does not assume shield/weapon durability loss from blocking.

If Stillring later adopts equipment durability, guard durability interaction requires explicit separate authority. Ordinary Guard cannot silently consume item durability because a reference game does so.

---

## Timed defense boundary — explicitly deferred

Stillring will research **Perfect Guard / parry timing and payoff separately** rather than bundling it into ordinary Guard.

Decision #4 therefore does not yet define:
- perfect timing window;
- attacker stagger;
- projectile reflection;
- damage bonuses;
- instant counterattack permission;
- slow motion;
- special VFX/audio reward;
- whether Perfect Guard can handle attacks ordinary Guard cannot.

Ordinary Guard must stand on its own as a viable defensive verb before a precision-timing reward layer is added.

---

## Combat state-model requirements created by Decision #4

Minimum Guard state data:
- `GuardState` (`Inactive`, `Raising/Entering` if used, `Active`, `Reaction`, `Exiting` if semantically needed);
- `CoverageActive`;
- guard-facing basis/vector;
- defended sector angle/value;
- current Guard input intent;
- Hold/Toggle input mode;
- current incoming-hit guardability;
- incoming direction relative to guard-facing;
- block result and rejection/failure reason;
- Guard Reaction severity/duration placeholder;
- movement/facing authority owner;
- target identity separately from facing;
- animation state separately from gameplay state.

Every incoming combat hit must be able to report why it was:
- blocked;
- not blocked because outside arc;
- not blocked because Guard inactive;
- not blocked because attack Unblockable;
- not blocked because another higher-priority state owned Neris.

---

## Accessibility / controls

Requirements:
- Guard fully remappable;
- Hold and Toggle modes available;
- both modes have identical gameplay semantics;
- no rapid tapping required to maintain Guard;
- no prolonged hold is mandatory because Toggle exists;
- block success/failure cannot be communicated solely by camera shake/haptics;
- Guard facing/readiness should be readable through character posture and effects without requiring tiny HUD indicators;
- future Perfect Guard timing assists, if any, must be researched separately rather than altering ordinary Guard silently.

This follows current Xbox accessibility guidance that recommends alternatives to prolonged holds and supports action-level remapping.

---

## Combat System IDE requirements

### Inspect
Expose at minimum:
- Guard input intent + Hold/Toggle mode;
- Guard state;
- coverage active/inactive and transition timestamp;
- guard-facing vector/basis;
- defended arc visualization;
- incoming attack ID/source;
- incoming direction;
- `Guardable`/`Unblockable` property;
- block success/failure;
- semantic reason;
- current Guard Reaction state/severity/timer;
- movement/facing authority owner;
- current target separately;
- animation pose/montage state separately;
- gameplay↔animation mismatch warning.

### Tune
Prototype values:
- defended arc width;
- optional explicit Guard raise/coverage delay if retained after playtest;
- guarded movement speed/acceleration;
- Guard Reaction duration/displacement by representative hit class;
- visual blends that do not change gameplay legality.

No stamina/posture/integrity values exist unless a later decision adds them.

### Exercise
Scenarios/tools:
- guard frontal strike;
- guard strike from side/behind;
- guard rapid two-hit sequence;
- guard projectile;
- test `Unblockable` attack;
- rotate Neris/camera independently and inspect sector;
- lock target A while enemy B attacks from flank;
- toggle Hold/Toggle input mode;
- request Guard during Light/Heavy Startup/Active/Recovery;
- release/toggle-off during Guard Reaction;
- reset Guard state and verify cleanup.

### Validate
Detect:
- Guard animation active while gameplay Guard inactive or vice versa;
- camera yaw changing guard coverage without Neris facing change;
- omnidirectional ordinary Guard;
- ordinary block draining stamina/integrity despite no such authority;
- successful block causing no Guard Reaction at all;
- successful block secretly granting post-block invulnerability;
- ordinary block automatically staggering/reflecting/countering;
- Guard freely canceling committed attacks without explicit edge;
- Guard coverage timing owned only by montage/notify;
- projectile reflection occurring under ordinary Guard;
- hidden equipment durability loss;
- Hold/Toggle producing different combat results;
- frame-rate-dependent guard activation/block result.

### Capture
Record:
- Guard input events;
- Guard state/coverage changes;
- facing/sector state;
- incoming attack ID/direction/guardability;
- block result/failure reason;
- Guard Reaction start/end;
- movement/facing ownership;
- target changes;
- animation markers/state;
- Guard exit/reset reason.

---

## Representative test matrix

### Basic input
- Hold mode: press/hold/release Guard;
- Toggle mode: toggle on/off;
- remapped keyboard/controller inputs;
- switch input mode between sessions.

Expected: identical gameplay Guard semantics regardless of Hold/Toggle.

### Coverage
- strike directly ahead;
- strike just inside/outside tuned sector edge;
- strike from 90° side;
- strike from behind;
- camera rotated away while Neris facing stays fixed;
- target switched while Neris has not yet turned.

Expected: block follows Neris-facing sector, never camera/lock magic.

### Block reaction
- one normal guardable hit;
- rapid double hit;
- stronger representative guardable hit;
- hit during Guard Reaction;
- release Guard during reaction.

Expected: explicit explainable reaction; no hidden stamina meter or post-block i-frames.

### Unblockable/non-strike
- authored unblockable melee;
- grab;
- ground hazard;
- explosion/status field placeholder;
- projectile marked guardable/unblockable.

Expected: semantic authored interaction, not visual guesswork.

### Attack-state integration
- Guard from Free;
- Guard during Light Startup/Active/Recovery;
- Guard during Heavy Startup/Active/Recovery;
- Guard after chain ends;
- Guard while target switch occurs.

Expected: Decision #1 transition authority remains explicit; no free cancel leakage.

### Multi-enemy
- enemy A locked ahead, B attacks side;
- two frontal attackers;
- one front + one rear;
- camera compressed/occluded under approved camera states.

Expected: ordinary Guard cannot solve 360° crowd pressure; encounter fairness must respect actual coverage/readability.

### Robustness
- 30/60/120+ FPS;
- altered animation playback rate;
- longer/shorter Guard raise animation;
- reset during Guard Reaction;
- Hold/Toggle accessibility mode.

---

## Research basis / design lineage

### Unreal Engine 5.8 primary sources
Epic's Enhanced Input system treats actions semantically and supports press/hold/release trigger states, dynamic mapping contexts, player-mappable controls, and user input settings. This makes Hold and Toggle ergonomics implementation choices around one authoritative Guard state rather than separate combat systems.

Primary references:
- Epic Unreal Engine 5.8 Enhanced Input documentation;
- Epic `UEnhancedInputUserSettings` API;
- Epic player-mappable input/context APIs.

Engine capability does not define Guard policy.

### Shipped-game / official problem study
Relevant abstract lessons:
- PlayStation's official *God of War Ragnarök* combat guide describes a held shield block that lets the player stand ground, while precisely timed blocks can create stronger parry outcomes. This cleanly separates ordinary blocking from a timing-reward layer.
- Nintendo's official *Breath of the Wild* Explorer's Guide describes Perfect Guard as a specifically timed defensive technique that can stagger/reflect, reinforcing that precision defense can be a separate reward above ordinary shield use.
- Monster Hunter's broader defensive/resource models demonstrate that stamina/resource costs are one possible way to constrain defense, not a universal requirement.

Stillring keeps the abstract separation—reliable ordinary defense versus later precision reward—but uses its own directional/state model and deliberately avoids assuming stamina or equipment durability.

No exact timing, arc values, shield data, animation, control layout, or proprietary implementation is copied.

### Accessibility basis
Current Microsoft Xbox accessibility guidance recommends alternatives to prolonged holds and action-level remapping. Stillring therefore provides Guard Hold/Toggle parity from the beginning.

---

## Why this package is approved
Combat #4 gives Stillring a viable non-dodge defensive foundation without creating a passive stamina tax or 360° safety blanket.

It locks:
- reliable directional ordinary block;
- positional/temporal cost instead of universal resource drain;
- explicit Guard Reaction;
- honest multi-enemy/flanking vulnerability;
- movement while guarding without Sprint;
- Hold/Toggle accessibility parity;
- clean separation from later Perfect Guard/parry precision gameplay.

---

## Player-facing acceptance
Combat Decision #4 passes when:
1. Guard is a real gameplay state and not merely an animation pose;
2. default input is Hold, with gameplay-equivalent Toggle accessibility mode;
3. ordinary Guard protects a tunable front-facing sector rather than 360°;
4. guard-facing comes from Neris's body/facing authority, not camera yaw or target identity alone;
5. a guardable frontal attack is reliably blocked and does not deal its normal direct HP damage;
6. successful block creates an explicit Guard Reaction/cost rather than doing nothing;
7. simply holding Guard drains no stamina/posture/integrity in the baseline;
8. Guard has no hidden equipment-durability cost;
9. ordinary Guard does not automatically stagger, counter, reflect projectiles, slow time, or grant post-block i-frames;
10. Guard allows deliberate reduced movement but not Sprint;
11. flank/rear attacks remain real threats;
12. attacks explicitly declare Guardable/Unblockable instead of inferring from visuals;
13. Guard does not freely cancel committed Light/Heavy attacks without explicit transition authority;
14. Combat IDE explains coverage, facing, incoming direction, guardability, result, reaction, and failure reason;
15. Perfect Guard/parry timing/reward remains a separate next defensive decision rather than hidden ordinary-Guard behavior.

---

## Next combat decision
**Combat Decision #5 — evade model / invulnerability philosophy.**

Research independently before approval. Compare position-first evade, brief justified invulnerability, and mixed attack-specific approaches; define input/state entry, displacement, directional control, collision, target-lock behavior, attack-cancel boundaries, repeated-evade behavior, accessibility, and whether any invulnerability window is genuinely necessary.