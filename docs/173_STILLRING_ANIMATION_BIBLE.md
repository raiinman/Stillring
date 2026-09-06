# 173 — Stillring Animation Bible

**Status:** ACTIVE / PRODUCTION-AUTHORITY / DOCUMENTATION-ONLY  
**Updated:** 2026-09-06  
**Parent program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Decision rights:** `docs/170_STUDIO_DECISION_RIGHTS_MATRIX.md`  
**Art authority:** `docs/154_STILLRING_ART_BIBLE.md`, `docs/158_CHARACTER_PRODUCTION_MANIFEST.md`, `docs/159_ENEMY_BOSS_ART_MANIFEST.md`  
**Gameplay authority:** `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`, `docs/48_GATE2_COMBAT_STATE_MODEL.md`, `docs/69_GATE3_TOOL_SYSTEM_CUMULATIVE.md`, `docs/79_GATE4_HUSH_CUMULATIVE_SPECIFICATION.md`, docs `120`–`126`, docs `127`–`134`  
**System IDE:** `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`, `docs/141_SYSTEM_IDE_COVERAGE_MATRIX.md`  
**Companion inventory:** `docs/174_ANIMATION_PRODUCTION_MANIFEST.md`  
**Closes toward:** `SH-ANI-001` through `SH-ANI-009`  
**Boundary:** this file defines animation-production authority. It does not authorize rig creation, animation production, UE5.8 implementation, motion-capture recording, runtime tuning, performance claims, or human-play acceptance.

---

# 1. Purpose

Stillring has enough movement, combat, tools, characters, creatures, machines, Hush states and cinematics that animation cannot be treated as “make appropriate clips later.”

This bible defines:
- what animation is responsible for;
- what animation is explicitly **not** allowed to own;
- rig/skeleton/retargeting strategy boundaries;
- displacement/root-motion policy;
- locomotion and traversal presentation rules;
- combat animation rules;
- tool/Cantor interaction rules;
- NPC and population motion language;
- enemy/boss motion language;
- facial/performance scope;
- cinematic animation boundaries;
- IK/procedural/additive responsibilities;
- event/notify ownership;
- Hush-state animation rules;
- technical acceptance and runtime gates;
- System IDE/debug requirements.

The companion manifest enumerates the actual animation families a studio must schedule.

The governing principle is:

> **Animation makes an authoritative action readable, physical and memorable. It does not become a secret second gameplay system.**

---

# 2. What Stillring animation should feel like

Stillring animation follows **Playable Fantasy Illustration** rather than photoreal simulation or exaggerated cartoon timing.

Required qualities:
- clear intention before contact;
- strong readable silhouette changes;
- weight without sluggish input acknowledgement;
- enough anticipation for fairness, not decorative delay;
- grounded contact with tools, surfaces and mechanisms;
- authored asymmetry and imperfection where work/history demands it;
- restrained secondary motion;
- expressive hands and face at conversation distance;
- clear enemy threat direction at gameplay distance;
- actions that remain understandable with VFX reduced.

Avoid:
- motion-capture mush where intention is visible only in micro-movement;
- over-smoothed “AAA realism” that delays player response;
- universal heroic posing;
- floaty blend soup;
- idle fidgeting that makes every person theatrically busy;
- animation cancel behavior created accidentally by clip length or montage sections;
- animation-driven locomotion that fights the locked control grammar;
- boss spectacle that hides force direction.

The N64-era lineage applies here as a readability lesson:

> **A pose should explain itself before surface detail or particles do.**

It is not a requirement to reproduce 1998 animation frame counts or technical limitations.

---

# 3. Authority order

Resolve animation conflicts in this order:

1. canonical gameplay/story/state authority;
2. system ownership and cross-system contracts (`docs/139`, `docs/140`);
3. this Animation Bible;
4. `docs/174_ANIMATION_PRODUCTION_MANIFEST.md`;
5. character/enemy/environment production authority;
6. approved rig/animation execution sheets;
7. runtime evidence and human play for explicitly runtime-gated values.

If a beautiful animation contradicts gameplay authority, the animation changes.

If gameplay is ambiguous, animation does not get permission to invent the missing rule; the gap returns to the correct authority.

---

# 4. Decision classes for animation

## LOCKED

- animation is presentation of gameplay state, not canonical gameplay-state owner;
- Neris must acknowledge valid movement/action intent promptly within the locked locomotion/combat rules;
- target-lock, combat legality, evade immunity, guard coverage, hit/reaction resolution, traversal eligibility and persistent state are not owned by animation;
- enemy telegraphs must remain readable through pose/silhouette/motion before VFX;
- Hush transitions do not reset gameplay state or create duplicate semantic identity;
- principal character identity/proportions from `docs/158` remain intact;
- boss narrative grammar and threat origins from `docs/159` remain intact;
- cinematic completion cannot be sole authority for broad quest/world state;
- development workbenches must expose animation/gameplay mismatches and are excluded/hard-disabled in Shipping.

## STUDIO CHOICE WITHIN BOUNDS

The animation/technical-animation team may choose:
- DCC package;
- exact control-rig construction;
- naming implementation details inside project naming rules;
- shared skeleton versus compatible skeleton variants where visual identity/deformation survives;
- IK solver implementation;
- whether a particular procedural correction uses Control Rig, IK Rig, native AnimGraph nodes, code, or another UE5.8-supported method;
- compression settings;
- curve organization;
- additive layer implementation;
- secondary-motion technique;
- offline versus runtime retargeting where quality/performance requirements are met;
- montage/sequence/state-machine organization where gameplay authority remains external.

## RUNTIME-GATED

Requires representative rigs, animation and UE5.8 evidence:
- exact blend times;
- exact stride scaling and turn thresholds;
- exact root-motion/warping envelopes;
- final foot/hand IK tolerances;
- final motion-warping use per traversal family;
- motion-matching adoption, if proposed;
- runtime retargeting versus baked retargeted sequences at production scale;
- cloth/hair simulation methods;
- facial technology;
- animation LOD/budget policy;
- final tick/interpolation significance rules;
- final animation-memory/compression budgets;
- final boss animation timing and readability.

## PROHIBITED

- montage section or Anim Notify as sole authority for gameplay legality;
- animation length extending a gameplay lockout after the owner system releases it;
- root motion bypassing collision/state ownership without an explicit gameplay transaction;
- animation Blueprint maintaining a contradictory movement/combat/Hush state machine;
- notify-driven persistent world/quest/completion changes;
- procedural IK moving gameplay collision to “make the feet fit”;
- retargeting that changes a character’s canonical silhouette/body identity simply to reuse motion;
- motion warping used as hidden teleportation to rescue invalid traversal or interaction geometry;
- full-body motion-capture fidelity taking priority over player readability or responsiveness.

---

# 5. UE5.8 animation technology posture

Stillring uses Unreal Engine 5.8, but engine features remain tools rather than doctrine.

Current Epic documentation establishes that UE5.8 supports:
- IK Rig / IK Retargeter across different skeleton structures/proportions;
- Control Rig and Full-Body IK for procedural adjustment such as ground alignment/reaching;
- Motion Warping for controlled root-motion alignment to authored targets;
- Pose Warping for orientation/stride/slope adaptation;
- Distance Matching for distance-driven animation playback;
- Animation Montages, Slots and Notifies;
- Animation Budget Allocator for significance-based throttling of skeletal updates.

Stillring may use any of these where evidence shows a production benefit.

None is mandatory merely because Epic provides it.

The production question is always:

> **Does this technique preserve authoritative gameplay, readable contact, authoring clarity and target performance better than the simpler alternative?**

---

# 6. Skeleton / rig strategy

## 6.1 Rig families, not one universal skeleton

Stillring should share technical foundations where morphology genuinely supports sharing.

It must not force every body onto one skeleton simply to maximize reuse.

Required production families:

### RIG-HUM-HERO

For Neris and any principal humanoid whose cinematic/facial/body burden justifies hero controls.

Requirements:
- full-body deformation suitable for locomotion, combat, ladders, ledges, swimming and tool use;
- stable hand/finger controls for Cantor/tool/repair interactions;
- foot contacts suitable for slope/stair correction;
- spine/shoulder range suitable for target-relative combat and tool bracing;
- head/eye/facial attachment compatible with chosen facial pipeline;
- equipment attachment references for Neris’s documented tool carry;
- cloth/hair proxy controls where production requires them.

### RIG-HUM-SHARED

For compatible C1–C4 humanoids where body proportions can share/retarget motion without flattening identity.

Requirements:
- body-proportion variance must be preserved;
- occupation loops must not make everyone move like Neris;
- height/build variation must not create foot sliding or hand-prop errors severe enough to expose reuse;
- named characters may use shared technical hierarchy while receiving unique motion layers/poses.

### RIG-FAUNA-FAMILY

One per genuinely compatible morphology family.

Examples may include:
- root-beast quadrupeds;
- cliff-predator Talons family;
- regional small-fauna families.

Do not force unrelated anatomy such as Mawhart and Mossjaw onto the same production skeleton if locomotion/contact quality would suffer.

### RIG-MACHINE

Machines animate according to mechanism degrees of freedom rather than humanoid convention.

Cinder Regent and Gravemoon are not characters wearing machine skins.

Their rigs must expose:
- true rotational/translation axes;
- service joints;
- counterweight relationships;
- state-readable control groups;
- detachable/interactive components where authored.

### RIG-HUSH-RELATION

Hush encounters such as Archivist/Listener may not require conventional skeletal rigs at all.

Use skeletal, transform, material, geometry, Sequencer or procedural systems according to the semantic relationship.

Do not create a humanoid skeleton just because the animation department expects one.

---

# 7. Skeleton compatibility and retargeting policy

Retargeting is a reuse tool, not a character homogenizer.

## 7.1 Allowed reuse

Retargeted animation is encouraged for:
- common civilian locomotion foundations;
- generic seated/standing transitions;
- compatible work loops;
- background social gestures;
- testing/blockout;
- shared humanoid interaction foundations that receive character-specific cleanup.

## 7.2 Retargeting requires cleanup when

- hand/prop contact is visible;
- feet must land on authored geometry;
- body proportions change silhouette/readability;
- a named character’s posture/personality matters;
- a cinematic uses medium/close framing;
- traversal contact determines player trust;
- combat anticipation/recovery readability is affected.

## 7.3 Runtime versus baked retargeting

Both remain **STUDIO CHOICE / RUNTIME-GATED**.

Use runtime retargeting only if:
- CPU cost is measured and acceptable;
- deterministic playback/contact remains reliable;
- authoring/debugging burden is lower than baked variants;
- animation LOD does not create visible identity loss;
- packaging/dependency complexity remains reasonable.

Baked/offline retargeted sequences are preferred where:
- hero quality requires hand cleanup;
- deterministic authored timing matters;
- runtime cost is not justified;
- source/target proportions need manual correction.

UE5.8 IK Retargeter is an approved candidate, not a mandatory canonical implementation.

---

# 8. Gameplay ownership versus animation ownership

## Gameplay owns

- action acceptance/rejection;
- movement/traversal eligibility;
- movement state;
- combat Startup/Active/Recovery;
- cancel windows;
- attack/guard/evade legality;
- evade immunity;
- damage and reaction result;
- target identity;
- Hush semantic layer;
- world/mechanism facts;
- interaction commit;
- save/persistence;
- quest/completion state.

## Animation owns

- pose selection;
- transition presentation;
- contact posing;
- authored anticipation/follow-through within gameplay timing;
- body mechanics;
- readable recovery pose;
- secondary motion;
- facial/body performance;
- presentation markers for audio/VFX when semantically safe;
- cinematic movement where explicit cinematic control is active.

## Animation may request, not decide

An animation marker may request or annotate:
- footstep sound/VFX;
- cloth/prop handling sound;
- a contact sample;
- a reviewed gameplay callback at a known state boundary.

The gameplay owner still validates any gameplay-affecting consequence.

---

# 9. Root-motion and displacement policy

Stillring does **not** use one global “root motion on/off” rule.

Displacement policy is assigned by action family.

## 9.1 Ordinary ground locomotion

**Default: gameplay/capsule movement owns displacement.**

Animation follows the authoritative requested/actual movement.

Allowed supporting techniques:
- stride warping;
- orientation warping;
- distance matching for stops/starts/lands where useful;
- turn-in-place/plant presentation;
- slope/foot IK;
- additive lean.

Animation may not:
- slow Neris because a run clip has not finished;
- create extra speed from root translation;
- preserve forward animation while gameplay has already reversed except for a brief readable plant/reversal presentation;
- drag the capsule to save foot placement.

## 9.2 Combat attacks

**Default: Combat/Locomotion own action displacement envelope.**

Bounded authored root-motion-like movement may be used only when:
- the attack data explicitly requests displacement;
- Locomotion/Combat validates collision/space;
- the movement does not create target vacuum/orbit/reach extension;
- gameplay state remains the owner of timing and cancellation;
- interrupted/dead states can stop/redirect presentation safely.

A montage’s root track may implement approved displacement, but the montage does not create permission for it.

## 9.3 Evade

Evade has committed collision-honest displacement under Combat authority.

Animation must match the validated evade path.

No visual roll/step may grant immunity, clip through blockers, or move farther than gameplay authority.

## 9.4 Mantle / ledge / ladder / authored traversal

These are prime candidates for **bounded authored alignment**.

Motion Warping or equivalent may be used when evidence shows it improves contact, but only after Locomotion has already accepted a valid traversal transaction and provided approved start/contact/end references.

Warping may align:
- hands to a valid mantle/ledge contact;
- feet/body to a legal mantle top;
- body to a ladder attach lane;
- authored interaction stances.

Warping may not:
- turn an invalid ledge into a valid one;
- increase reach to save bad geometry;
- teleport through collision;
- cross a gap/corner prohibited by ledge grammar;
- remount the same deliberately released attachment without valid re-entry.

## 9.5 Tool traversal

Tool systems own their state and Locomotion owns physical movement handoff.

Animation may present cable tension, bracing, body pull and landing alignment only inside the accepted tool traversal contract.

## 9.6 Line Skiff

Vehicle movement owns macro motion.

Neris animation owns:
- boarding/disembarking presentation;
- rider stance;
- weight shift;
- grip changes;
- bracing;
- look/body response to junctions/acceleration;
- safe fall/recovery presentation if authored.

Rider animation does not steer the Skiff.

## 9.7 Cinematics

Sequencer/cinematic animation may own temporary staged transforms only under explicit cinematic-control authority.

At entry/exit:
- gameplay state is validated;
- cinematic control is explicit;
- required semantic commits use owner services;
- final gameplay location/state is reconciled deliberately.

A cinematic transform track is not persistent-world truth.

---

# 10. Locomotion animation doctrine

## 10.1 Ground locomotion

Required reads:
- careful low-speed movement feels intentional, not a slow version of jogging;
- ordinary run is the default confident travel state;
- Sprint communicates sustained purposeful travel, not combat panic;
- acceleration/deceleration are visible through weight shift without input lag;
- hard reversal uses a planted redirection consistent with locomotion authority;
- camera-relative direction changes do not create skating.

## 10.2 Starts/stops/pivots

Animation should support:
- low-speed start;
- run start;
- Sprint start;
- ordinary stop;
- hard stop/reversal plant;
- directional pivots;
- target-lock entry/exit pivot.

Exact thresholds remain runtime-gated.

Distance Matching is an approved candidate for stop/start/landing synchronization if it improves matching between gameplay distance and pose timing.

## 10.3 Jump/fall/land

Must preserve:
- immediate believable takeoff after accepted Jump;
- no hidden jump-height increase from animation;
- inherited horizontal momentum;
- readable rising/apex/falling states;
- landing response scaled by authoritative fall severity;
- Sprint continuation after ordinary landing when gameplay still requests Sprint;
- no input gimmick in the animation that cancels fall consequence.

Animation families must include:
- ordinary takeoff;
- airborne loop/pose response;
- safe landing;
- upper-safe firm landing;
- moderate damaging recovery;
- severe landing/near-collapse;
- lethal/death handoff where relevant.

## 10.4 Slopes and stairs

Ordinary steps/slopes should disappear beneath competent movement.

Use procedural foot placement/slope adaptation where useful.

Do not create constant bespoke step animations that make ordinary terrain feel like traversal obstacles.

Borderline scramble and committed downhill slide remain distinct authored motion families because gameplay state changes.

## 10.5 Mantle / ledge

Mantle/hang animation must make the accepted state obvious:
- contact/catch;
- stable hang;
- same-handhold shimmy;
- pull-up;
- deliberate release;
- fall continuation.

No corner wrap or gap transfer animation belongs in baseline inventory.

A catch must visibly enter a real hang before pull-up; do not visually skip the locked state because a high ledge transition clip is convenient.

## 10.6 Ladder

Needs:
- approach/attach;
- climb up;
- climb down;
- neutral hold;
- top exit;
- bottom exit;
- deliberate release;
- interruption/recovery as supported.

Camera remains player-owned.

## 10.7 Surface swimming

Needs:
- deep-water entry;
- surface travel;
- neutral tread;
- turning;
- low valid exit;
- blocked/high-edge continuation;
- damage/death/recovery as gameplay requires.

No baseline underwater free-dive animation family should imply an unavailable gameplay verb.

---

# 11. Target-lock locomotion

Target-lock motion is not ordinary strafe animation pasted over free movement.

Required:
- body orientation clearly communicates target-relative frame;
- forward/back/lateral/diagonal movement remain readable;
- pivots avoid foot skating;
- attack-facing assistance is visible but bounded;
- lock loss does not cause abrupt body reinterpretation during committed states;
- target-lock Jump preserves the stable target-relative air-control frame defined by locomotion authority.

The animation set may use directional blends, orientation warping, authored variants or a hybrid.

Exact implementation is studio choice; the player-facing relationship is locked.

---

# 12. Combat animation doctrine

## 12.1 Core principle

> **Commit to the meaningful decision, not decorative dead time.**

The animation should make Startup, Active intent and Recovery understandable, but gameplay owns those phases.

## 12.2 Light chain

Three authored entries.

Animation requirements:
- each press reads as one intentional strike;
- entries distinguish themselves through line/height/body mechanics rather than flashy escalation;
- continuation poses connect naturally without hiding the fact that each entry is separately accepted;
- no visual suggestion of a fourth strike;
- no held-input auto-combo performance.

## 12.3 Heavy attack

Must read as a different commitment family, not merely Light_4.

Requirements:
- stronger preparatory body commitment;
- clear force origin;
- narrower late facing correction;
- miss/recovery consequence visible;
- no comically long anticipation added only to prove “weight.”

## 12.4 Guard

Guard pose must:
- communicate defended front sector;
- remain readable from normal camera distance;
- support stable Guard locomotion where gameplay permits;
- distinguish ordinary Guard Reaction from Perfect Guard Advantage through posture/timing, not mandatory flash/color.

## 12.5 Perfect Guard

Perfect Guard is a resolved timing result, not a special animation mode entered freely.

Animation may provide:
- sharper contact absorption;
- immediate controlled recovery/advantage posture;
- attacker/defender contact clarity.

It may not:
- auto-counter;
- imply time stop;
- create a generic stun;
- grant gameplay advantage beyond Combat authority.

## 12.6 Evade

Evade must visually match collision-honest displacement.

No acrobatic flourish should:
- hide recovery;
- imply larger invulnerability window;
- imply chained dodge permission;
- travel farther than the capsule.

The exact physical form—step, roll, low shift or hybrid—must be selected through representative human play and costume/tool clearance while preserving combat grammar.

## 12.7 Hit reactions

Animation maps to authoritative reaction results:
- DamageOnly;
- LightReact;
- Interrupt;
- HardStagger;
- GuardReaction;
- Death.

Do not infer reaction severity from damage number alone.

Reaction families need directional/force readability without exhaustive cinematic hit variants.

## 12.8 Death/retry

Death animation begins only after Combat resolves Death.

It must not:
- keep attack/hit state alive;
- write checkpoint state;
- choose retry point;
- delay cleanup because the clip is unfinished.

Visual presentation may finish after gameplay has atomically cleared transient combat ownership if the state is safely terminal.

---

# 13. Tool and Cantor animation doctrine

## 13.1 Cantor Key handling

Neris’s right-rear swivel cradle and two-hand draw/stow logic from `docs/158` are locked visual constraints.

Animation must support:
- draw;
- ready/listen posture;
- view-directed diagnostic aim without gun-language posing;
- slider/prong/hammer manipulation;
- procedure performance;
- re-measure;
- failed/not-actionable response without theatrical spell recoil;
- stow;
- interruption where gameplay permits.

Cantor should look like skilled diagnostic work, not spellcasting.

## 13.2 Anchor Line

Needs clear body mechanics for:
- equip/ready;
- target/latch;
- tension pull;
- brace;
- reclaim;
- traversal pull;
- combat-pressure component manipulation;
- puzzle/mechanism use;
- blocked/failed tension;
- interruption/release.

Neris’s body should visibly communicate load direction.

The cable/hand pose follows semantic load state; it does not define it.

## 13.3 Later tools

Glasslung Reed, Temper Gauntlet, Vane Cloak and Mirror Nail require their own motion families in the manifest.

General rule:
- every tool must look physically/operationally different;
- avoid one universal “cast” animation reused with different VFX;
- hand/prop contact should explain what the tool actually does;
- exact clip count follows authored use families, not arbitrary one-animation-per-button production.

---

# 14. Hush animation doctrine

Hush is not an animation skin.

## 14.1 Player continuity

Across a legal seam:
- locomotion state continues according to Gate 4;
- combat phase continues;
- Guard/Evade timing continues;
- target semantic identity transfers only when valid;
- animation presentation may blend/rebind to destination representation without restarting gameplay state.

A seam must not replay attack starts, restart jump takeoff, reset an evade, or manufacture a landing.

## 14.2 Character/NPC Hush variants

Use animation differences only where the semantic relationship warrants them.

Possible examples:
- a gesture preserved at a different point;
- a recurring motion missing its expected completion;
- contradictory remembered postures;
- local repetition tied to a specific preserved relation.

Do not apply:
- universal slow motion;
- universal twitching;
- universal reversed animation;
- universal looped idle;
- “ghost float” movement to every Hush entity.

## 14.3 Hush composites

Saint Varo, Mirror Widow, Archivist and Listener each require distinct motion logic tied to their narrative grammar.

Their animation solution may combine:
- skeletal performance;
- spatial transform systems;
- repeated pose states;
- environment animation;
- material/geometry changes;
- Sequencer/procedural systems.

No requirement says “make a Hush boss skeleton.”

---

# 15. NPC animation doctrine

Ordinary people make Stillring’s regions worth caring about before catastrophe.

NPC animation therefore needs more than idle breathing and conversation gestures.

## 15.1 Population motion families

Every major settlement should draw from region/occupation-aware families such as:
- carrying/setting loads;
- maintaining civic machinery;
- food preparation/service;
- cleaning/repairing tools;
- writing/reading/filing;
- ferry/dock work;
- kiln/foundry work;
- rope/lift/wind infrastructure work;
- reed/marsh handling;
- observatory/measurement work;
- sitting/resting/eating;
- greeting/exchanging objects;
- arguing/explaining/teaching;
- tending children/elders/animals where authored;
- reacting to weather/state changes.

The exact regional assignment belongs in the manifest/region production package.

## 15.2 Named-character personality

C1–C3 named characters need identifiable motion traits derived from occupation, age, build and relationship—not a library of exaggerated “personality idles.”

Examples of legitimate differentiation:
- Tessa’s route-worker economy and long-distance posture;
- Ilyra’s technical hand precision;
- Orin’s broad repair-worker weight and familiar one-sided half-smile/body response;
- Maelor’s controlled precision that later becomes physically strained rather than villainous.

## 15.3 Reuse rules

Shared NPC loops are allowed, but:
- adjacent characters should not visibly sync;
- named NPCs cannot depend only on generic background loops;
- one region must not look like another through identical occupation motion;
- state variants must correspond to actual world changes;
- animation reuse cannot erase age/build/mobility distinctions.

---

# 16. Facial / performance strategy

Final facial technology remains **RUNTIME/PRODUCTION-GATED**.

The performance scope is not.

## 16.1 Performance tiers

Use current character art tiers as production input:

### F0 — principal cinematic performance

Neris, Tessa, Ilyra, Orin, Maelor.

Needs:
- brows/eyes/lids;
- jaw/lips/cheeks sufficient for intelligible speech and silence;
- asymmetry;
- eye aim/focus;
- breath/swallow/micro-pause where performance warrants it;
- medium/close cinematic viability;
- authored silent reactions.

### F1 — major recurring dialogue performance

Caldrin, Sena, Rusk and selected C3 characters.

Needs:
- readable speech shapes;
- brows/eyes;
- clear emotion states;
- reduced but intentional close-up burden.

### F2 — population dialogue

Needs:
- basic speech/jaw/eye response;
- emotion/attention presets;
- no expectation of hero close-up fidelity.

## 16.2 VO independence

VO scope remains a later owner/product decision.

Therefore facial production must support:
- voiced dialogue if selected;
- text-led dialogue without dead faces if partial/no VO is selected;
- meaningful silent performance;
- localization timing variability.

Do not hard-lock facial clips to one English recording before VO scope/language production is settled.

## 16.3 Lip sync

Exact solution—hand-authored, curve/phoneme driven, audio analysis, external tool, or hybrid—is studio choice pending production tests.

Acceptance is based on:
- character readability;
- localization scalability;
- editorial control;
- performance quality;
- runtime budget;
- repeatability.

---

# 17. Enemy and boss motion doctrine

`docs/159` defines the body/problem.

Animation must make the force/problem readable.

## 17.1 Ordinary fauna

Movement should appear ecologically plausible before “enemy-like.”

Required:
- locomotion anatomy;
- threat direction;
- anticipation;
- contact/recovery;
- damaged/retreat/death behavior where authored.

Do not give every animal a videogame crouch-windup if its anatomy suggests a better readable tell.

## 17.2 Infrastructure-entangled fauna

Mossjaw/Mawhart/Leviathan-style animation must separate:
- creature’s own movement;
- imposed hardware movement;
- constraint/load response;
- released state.

Hardware should lag, pull, bind or settle according to its physical relationship.

Liberation is not a generic death montage.

## 17.3 Machines

Cinder Regent and Gravemoon animate through mechanism logic.

A machine anticipation is:
- valve state;
- counterweight movement;
- arm indexing;
- ring alignment;
- pressure/thermal buildup;
- latch/release.

Do not anthropomorphize them into punches/dodges unless the mechanical function actually creates those actions.

## 17.4 Hush composites

Motion is state argument, not supernatural flourish.

- Varo: monumental official poses gradually regain human asymmetry/fatigue.
- Archivist: movement simplifies room/record relationships rather than becoming a ghost attack set.
- Mirror Widow: incompatible versions share human identity while postures/gestures contradict.
- Listener: repeated ordinary-world motions become perceptually disturbing through exact repetition; no fixed monster body.

## 17.5 Orin

Use Orin’s normal human rig/performance.

The encounter burden lies in repeated/preserved state around him.

Do not create boss locomotion/monster attack animation simply because he occupies a boss slot.

## 17.6 Maelor

Maelor remains a skilled human engineer.

Animation should escalate through:
- precise technical action;
- controlled economy;
- environmental coordination;
- increasing strain/fatigue;
- altered timing/pressure;

not transformation into a dark-lord movement vocabulary.

---

# 18. Boss resolution animation

Every major encounter package must inventory its **resolution**, not just combat death.

Resolution families include:
- ordinary death;
- escape;
- hardware release;
- machine shutdown;
- central coupling disconnect;
- loop ending;
- contradictory states settling without erasure;
- preserved relation releasing;
- human defeat/disconnection;
- Listener decommission/release.

A production tracker that contains only `Idle / Attack / Hit / Death` is insufficient for Stillring.

---

# 19. IK, procedural adjustment and contact rules

Procedural animation exists to preserve contact/readability across authored variation.

It does not exist to hide invalid level geometry.

## Allowed applications

- foot placement on modest slopes/steps;
- pelvis adjustment;
- hand contact on approved ladders/ledges/interactions;
- tool grip offsets;
- head/eye aim;
- bounded reach toward interaction handles;
- rider stance adaptation on Skiff;
- creature foot contacts;
- machine linkage following exact constraints.

## Hard limits

Procedural systems may not:
- change gameplay collision;
- extend interaction/traversal eligibility;
- stretch limbs beyond character style/anatomy to reach bad targets;
- move Neris through blockers;
- create a new weak point;
- create a new persistent mechanism state;
- conceal a broken authored metric standard indefinitely.

Full-Body IK/Control Rig is an approved candidate where multi-contact correction is useful.

Two-bone/simple IK is preferable where the simpler method solves the problem.

---

# 20. Pose/stride/orientation warping policy

Pose Warping is an optional production technique.

Good candidates:
- stride adjustment across approved speed ranges;
- target-lock orientation support;
- slope adaptation;
- modest body-direction correction.

Acceptance conditions:
- no visible limb distortion;
- no implausible pelvis twist;
- no foot sliding worse than the unwarped source;
- does not mask wrong gameplay speeds;
- preserved style silhouette;
- deterministic enough for capture/reproduction.

If warping must become extreme to make the animation fit, create better source animation or revise approved tuning—do not normalize deformation.

---

# 21. Motion matching policy

Motion Matching/Pose Search is **not currently mandatory**.

It may be proposed if a representative Neris locomotion set shows it materially improves:
- responsiveness;
- start/stop/pivot quality;
- directional variety;
- authoring scalability;

without causing:
- opaque debugging;
- content explosion;
- unpredictable transition choice;
- state-ownership confusion;
- unacceptable CPU/memory cost;
- difficulty preserving deliberate stylized pose language.

A conventional state/blend/distance/warping solution remains fully valid.

If Motion Matching is evaluated, compare it against a simpler baseline using the same Gate 1 human-play course.

---

# 22. Animation events / notifies

Epic’s Animation Notifies are useful for events synchronized to animation, including presentation events.

Stillring classifies notify use.

## A — presentation notify

Safe examples:
- footstep SFX;
- cloth/gear sound;
- dust/water VFX;
- minor camera impulse request;
- hand-contact sound;
- non-authoritative prop visibility.

## B — reviewed gameplay marker

May annotate a gameplay-defined event boundary only when the owning gameplay service validates it.

Examples:
- contact sample point for an already accepted traversal transaction;
- reviewed attack trace timing marker used by Combat’s authoritative action data;
- release/contact marker where gameplay already owns the transition.

The notify is not the only source of truth.

## C — forbidden authority notify

Never use a notify alone to:
- grant Evade immunity;
- decide Perfect Guard;
- set quest stage;
- set world fact;
- satisfy completion;
- change Hush semantic layer;
- grant/remove inventory;
- determine target-lock identity;
- decide death;
- authorize mantle/ledge catch;
- write persistent save data.

Branching Points may offer more precise dispatch in UE5.8, but precision does not transfer ownership.

---

# 23. Additive animation

Additives should carry secondary state without duplicating the base state machine.

Candidate layers:
- breathing/exertion;
- injury presentation after source health state;
- aim/head/eye attention;
- tool brace/tension;
- wet/ash/wind response where justified;
- conversational hand/upper-body overlays;
- Maelor fatigue;
- limited status/hazard reactions.

Do not layer so many simultaneous additives that silhouette/timing becomes unreadable.

Gameplay remains readable with cosmetic additive layers disabled.

---

# 24. Cloth, hair and secondary motion

Stillring’s shape language is more important than simulation.

## Neris

- short bob must preserve compact wedge silhouette;
- Vane Cloak must not obscure ledges, ladders, tools or combat poses;
- equipment should settle with believable inertia without becoming noisy.

## NPCs

Use simulation sparingly according to garment need.

## Bosses/fauna

Secondary motion may clarify mass and force but cannot hide attack origins.

Exact technique—physics, AnimDynamics, cloth system, procedural bones, authored secondary clips—is runtime/tech-art choice.

Acceptance requires:
- stable collision/contact;
- no explosive simulation on save/load/teleport/reset;
- deterministic enough reset for fixtures;
- scalable cost;
- shape remains readable when simulation quality is reduced.

---

# 25. Equipment / prop attachment

Every repeated handheld/worn object needs declared:
- semantic prop ID/family;
- primary hand/contact points;
- stow attachment;
- draw/stow path;
- two-hand relationship if any;
- collision/clearance risks;
- traversal fallback/stow state;
- cinematic close-up burden.

For Neris, tool carry from `docs/158` controls visual placement.

Animation cannot float a tool to a convenient hand socket when the documented draw/stow mechanism says otherwise.

Temporary blockout shortcuts are allowed only when clearly labeled Q0/Q1 and replaced before production acceptance.

---

# 26. Cinematic animation

Cinematic animation must preserve character and game-state truth.

Each cinematic animation package must identify:
- entry semantic state;
- actors/props;
- expected costumes/variants;
- gameplay handoff;
- facial tier;
- dialogue/VO dependency;
- required interactions;
- camera distance;
- crowd/background burden;
- exit semantic state;
- skip/reload behavior;
- whether motion can reuse gameplay animation or needs bespoke performance.

Do not build a bespoke cinematic clip where a stable gameplay animation works and continuity benefits from reuse.

Do not reuse gameplay idles in an emotionally important close-up merely to save work.

---

# 27. Animation LOD / scalability

Final numeric budgets are runtime-gated.

The required production concept is **significance-based quality**.

Highest significance:
- Neris;
- current combat target/nearby attackers;
- principal cinematic actors;
- boss state-critical components;
- NPCs in direct dialogue;
- traversal/contact-critical actors.

Lower significance may reduce:
- facial evaluation;
- secondary motion;
- update rate;
- IK complexity;
- background additive layers;
- distant crowd animation frequency.

It may not reduce:
- gameplay collision/state;
- attack timing logic;
- critical telegraph clarity at intended encounter range;
- save/world-state truth;
- required Hush paired semantics.

UE5.8 Animation Budget Allocator is an approved candidate for measured production optimization, not a pre-committed architecture.

---

# 28. Animation naming/source conventions

Exact global Technical Production naming may later supersede these prefixes.

Until then, animation source/manifest entries should use semantic names rather than vague clip numbers.

Recommended source pattern:

`AN_<Subject>_<Family>_<Action>_<Variant>`

Examples:
- `AN_Neris_Loco_Run_Start_Fwd`
- `AN_Neris_Traversal_Ledge_Catch`
- `AN_Neris_Combat_Light_02`
- `AN_Neris_Tool_Cantor_Listen`
- `AN_Mawhart_Resolution_BraceRelease`
- `AN_Maelor_Combat_HeavyRecovery`

Rig/source assets should maintain:
- source file provenance;
- author/version;
- target rig;
- retarget source if any;
- gameplay action/fixture links;
- facial/audio dependencies;
- review status.

Do not encode canonical gameplay IDs only in filenames; manifests/source data should hold explicit semantic references.

---

# 29. Animation review gates

## ANI-A — authority brief

Before animating:
- gameplay/story purpose known;
- owning system known;
- character/creature/machine identity known;
- start/end state known;
- contact points known;
- runtime-gated values identified.

## ANI-B — blockout

Evaluate:
- silhouette;
- force direction;
- contact geometry;
- response latency;
- state readability;
- cancellation/interrupt pose viability.

No polish required.

## ANI-C — gameplay integration candidate

Requires:
- real authoritative state driving playback;
- root/displacement contract respected;
- collision/contact validated;
- interruption/death/reset safe;
- System IDE mismatch inspection;
- Reduced Effects/VFX-off readability where relevant.

## ANI-D — production quality

Requires:
- deformation cleanup;
- prop/contact cleanup;
- secondary motion plan;
- facial performance where needed;
- retarget/reuse classification;
- audio/VFX marker review;
- accessibility/readability review;
- performance profile in representative context.

## ANI-E — final acceptance

Requires later:
- human-play feel/readability;
- final target performance/scalability;
- cinematic/editorial acceptance where relevant;
- regression fixtures;
- source/provenance complete.

No current asset is claimed to have reached ANI-E.

---

# 30. Animation System IDE / developer-workbench contract

Animation does not need a shadow gameplay workbench.

It needs an **Animation diagnostic view** integrated into relevant System IDEs and optionally an Animation review workbench registered in the shared shell.

## Inspect

Expose:
- gameplay owner/state;
- animation state/asset/montage/section;
- pose source stack;
- blend weights;
- root-motion extraction/request versus gameplay-approved displacement;
- current warp target and approved transaction ID;
- IK goals/solver state;
- foot/hand contact error;
- active additives;
- notify/marker timeline;
- equipment attachment state;
- facial tier/state;
- animation LOD/update state;
- gameplay↔animation mismatch warnings.

## Author/Tune

Development-only overrides may include:
- blend durations;
- IK weights;
- stride/orientation-warp bounds;
- additive weights;
- secondary-motion tuning;
- preview playback rates where gameplay authority explicitly permits testing.

Do not expose a tune field that changes canonical gameplay legality merely because the animation needs it.

## Exercise

Provide direct access to:
- Neris locomotion course;
- traversal fixtures;
- combat action/reaction fixtures;
- tool fixtures;
- Skiff boarding/riding route fixture;
- Hush transition fixture;
- NPC occupation loop gallery;
- enemy telegraph gallery;
- boss state/resolution fixtures;
- cinematic performance review clips.

## Validate

Detect:
- animation active when gameplay says state ended;
- gameplay active with no valid animation response;
- root displacement outside approved envelope;
- warp target not bound to accepted semantic interaction;
- foot/hand contact error over project tolerance after tolerance is runtime-proven;
- notify attempting forbidden state mutation;
- missing interruption/death route;
- missing equipment stow state for traversal;
- retargeted deformation/contact failure;
- animation LOD suppressing critical telegraph.

## Capture / Promote

Capture:
- build/commit;
- fixture;
- rig/mesh/animation asset IDs;
- gameplay timeline;
- animation timeline;
- root/warp/IK diagnostics;
- settings/overrides;
- video/screenshot reference;
- reviewer notes.

Promotion of tuned values follows `docs/170` runtime-gated promotion contract.

---

# 31. Accessibility requirements

Animation must not create mandatory barriers through:
- color-only cues;
- tiny facial micro-expressions as sole gameplay information;
- single-frame attack tells;
- high-frequency flashing/strobing;
- compulsory camera shake embedded in animation assets;
- motion that becomes unreadable when VFX is reduced;
- background crowd motion so dense that it obscures threats/interactions.

Critical combat/puzzle/traversal state should combine motion/silhouette with other appropriate channels.

Timing accommodations may adjust gameplay timing where separately authorized; animation must follow the authoritative adjusted timing rather than becoming desynchronized.

Reduced Effects may simplify secondary motion/VFX but cannot suppress the action pose/state needed to understand gameplay.

---

# 32. Localization / dialogue implications

Animation production must assume dialogue length can change.

Therefore:
- conversational idles must tolerate variable text/VO duration;
- facial performance should be segmentable/retimeable where practical;
- gesture beats should attach to semantic dialogue beats rather than absolute English word timestamps when possible;
- subtitles may continue after a gesture if localization requires it without breaking gameplay state;
- cinematic edits that cannot tolerate text/VO expansion must be explicitly flagged for localization planning.

---

# 33. Cross-discipline handoff requirements

Animation depends on:

## Gameplay
- authoritative state graph;
- action IDs;
- movement/displacement envelopes;
- contact/interrupt rules;
- target frames.

## Character/Creature Art
- final enough proportions;
- costume/tool clearance;
- deforming materials;
- attachment points;
- state variants.

## Level/Environment
- traversal/interact metrics;
- contact surfaces;
- ladders/ledges/handles;
- boss arena geometry.

## Audio
- footstep/material map;
- impact/gear/cloth cues;
- dialogue/VO timing if selected.

## VFX
- presentation events tied to authoritative state;
- reduced-effects behavior.

## Cinematics/Narrative
- scene objectives;
- performance beats;
- knowledge/emotional states;
- skip/reload contract.

## Technical
- rig/runtime feature support;
- source-control conventions;
- performance/scalability;
- automation/capture.

A missing upstream dependency should be logged, not silently invented by an animator.

---

# 34. Research basis

Current production research used to define the **available technique envelope**, not to override Stillring design:

- Epic Games, Unreal Engine 5.8 — **IK Rig Animation Retargeting**: retargeting between different skeletons/proportions with IK support.
- Epic Games, Unreal Engine 5.8 — **Control Rig Full-Body IK**: procedural multi-effector adjustment such as ground alignment/reaching.
- Epic Games, Unreal Engine 5.8 — **Motion Warping**: dynamically adapting root motion to authored warp targets/windows.
- Epic Games, Unreal Engine 5.8 — **Pose Warping**: orientation, stride and slope adaptation.
- Epic Games, Unreal Engine 5.8 — **Distance Matching**: distance-driven animation playback.
- Epic Games, Unreal Engine 5.8 — **Animation Notifies** and **Animation Montage**: synchronized presentation/events and montage organization.
- Epic Games, Unreal Engine 5.8 — **Animation Budget Allocator**: significance/budget-driven skeletal update throttling.

These are candidate tools only.

The repository’s ownership, gameplay, art and accessibility contracts remain authority.

---

# 35. Governing animation rules

1. **Gameplay decides; animation explains.**
2. **Input acknowledgement outranks decorative inertia.**
3. **Contact must be honest.**
4. **Root motion is family-specific, never blanket authority.**
5. **Retargeting may share motion, not identity.**
6. **Procedural correction may repair presentation, not eligibility.**
7. **A notify may synchronize an event, not become persistent truth.**
8. **Boss motion explains force before spectacle.**
9. **Ordinary people need ordinary work motion so the world lives before it suffers.**
10. **Hush animation expresses a semantic relationship; it is never a universal effect preset.**
11. **Every major verb and resolution state must appear in the production manifest.**
12. **Exact feel/performance values become authoritative only through the stated runtime evidence path.**

This bible is complete only together with the companion inventory.