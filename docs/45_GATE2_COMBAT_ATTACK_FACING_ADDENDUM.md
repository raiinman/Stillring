# 45 — Gate 2 Combat Attack-Facing / Rotation Assistance Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Combat Decision #9 for Issue #3. This file defines how player attacks acquire facing intent and how much rotational assistance may occur without becoming homing/magnetism.

## Authority
Combat Decision #9 is locked under the owner's explicit scheduled-run delegation after a fresh focused research pass.

Facing principle:
> **Help the player finish the turn they meant. Never choose the attack for them.**

---

## Combat Decision #9 — attack-facing / rotation assistance — LOCKED

### Attack facing is explicit gameplay authority
Every player attack records an authoritative attack-facing intent/basis. Animation may visually present rotation but may not independently decide where the gameplay attack turns.

The combat state must distinguish:
- Neris's body facing;
- movement input direction;
- current lock target;
- attack-facing intent;
- requested rotational correction;
- resolved/capped rotational correction;
- animation/root rotation separately.

### Lock-on supplies a chosen target, not unlimited homing
When target lock is active, the currently authoritative locked target may inform attack-facing assistance.

However:
- only the explicitly locked target may be used;
- the attack solver does not search for a “better” nearby enemy;
- no nearest-enemy magnetism occurs when the chosen target is absent/outside limits;
- target identity does not authorize translation/vacuum;
- camera centering does not authorize rotation.

### Light attacks get modest early-Startup facing assistance
For each accepted Light chain entry:
- sample the current authoritative target at that **entry's acceptance** if locked;
- compute the yaw error from Neris's current body/attack-facing basis toward that target;
- allow a modest authored correction during early Startup only;
- cap both correction rate and total yaw correction;
- close attack-facing assistance before the attack's Active interval;
- once closed, the committed strike direction remains stable.

Exact degrees/rates/window timing remain prototype tuning.

### Each Light entry is a fresh facing decision
Combat #2 allows a target change between chain entries. Combat #9 now defines the result:
- `Light_1` does not turn toward a target selected after its facing window closes;
- if `Light_2` is later accepted, it samples the then-current target and may apply its own bounded early-Startup correction;
- same for `Light_3`;
- a switch to a target far behind Neris may exceed the allowed cap, in which case the new entry corrects only within its limits and may miss.

This keeps target switching responsive without turning the chain into a spinning auto-combo.

### Heavy samples facing intent once at acceptance
Heavy is more committed.

At Heavy acceptance:
- capture the current locked target if present and valid for facing assistance;
- resolve the intended attack direction from that acceptance context;
- allow a smaller/stricter early-Startup correction than baseline Light;
- close the correction window earlier;
- later target switches do not retarget the current Heavy even if they occur before Active.

This strengthens Heavy's existing “choose first, commit harder” identity.

### No late Active-phase rotation assistance
For Light and Heavy baseline attacks:
- attack-facing assistance is closed by Active;
- no target-follow rotation occurs through Active;
- Recovery does not keep rotating the completed strike toward the target;
- hitstop does not reopen correction.

The body may naturally blend into post-action locomotion once gameplay facing authority returns, but the completed attack direction is not rewritten.

### Assistance is angular only
Attack-facing assistance may rotate Neris within approved yaw limits. It does **not**:
- translate Neris toward a target;
- preserve distance;
- orbit around a target;
- warp root position;
- enlarge attack reach;
- change hitboxes to compensate for missed facing;
- pull the target toward Neris.

Any attack-authored translation from Heavy/other future actions remains separately capped movement authority.

### Unlocked attacks use player movement intent, not enemy search
When not locked:
- meaningful movement input at attack acceptance supplies the preferred horizontal facing direction;
- if movement input is below meaningful threshold, Neris's current body facing is used;
- camera yaw alone does not snap Neris toward the camera forward direction unless movement input expresses that direction through the already-approved camera-relative locomotion frame;
- the combat system does not automatically select or rotate toward an enemy simply because one is nearby/on screen.

This keeps unlocked combat player-authored.

### Target validity and assistance range are bounded
A locked target may inform facing only if the targeting relationship remains valid and the attack-facing solver can compute a physically sensible direction.

If target context is invalid/lost:
- use the stable attack-facing intent already captured;
- do not silently acquire a replacement target;
- no large corrective spin occurs.

Exact distance/cone thresholds for whether assistance is useful remain tuning, but no attack can use an off-authority target.

### Assistance cone / hard yaw cap
Every assisted attack family must define a hard maximum yaw correction.

Rules:
- targets already near the intended forward direction may receive the full useful correction needed within the cap;
- large side/rear errors are capped rather than fully solved;
- a target behind Neris never guarantees a 180° attack spin;
- the cap is gameplay data and visible in the IDE;
- animation cannot exceed the gameplay cap through root rotation while keeping hit logic pointed elsewhere.

### Player input can bias future facing, not freely steer a committed strike
Movement input during a current committed attack:
- does not rotate the Active strike freely;
- may be sampled for the next Light entry at its acceptance or for post-Recovery locomotion;
- cannot exceed the current action's correction authority.

### Guard/Evade facing remain separate
- Guard uses Neris's authoritative body-facing sector from Combat #4.
- Evade direction is committed from its movement frame at acceptance under Combat #5.
- attack-facing assistance cannot rotate an already committed Evade.
- Perfect Guard timing does not turn Neris automatically toward incoming attacks.

### Reaction/interrupt can terminate facing authority
If Combat #6 interrupts/staggers an attack:
- attack-facing correction ends immediately with action cleanup;
- reaction movement/facing authority takes over;
- old rotational assistance may not continue in the background.

### Root motion / animation must conform
If an animation includes rotational root motion:
- gameplay attack-facing authority remains the cap/source of truth;
- root motion must be authored/processed to match approved correction;
- an animation asset replacement may not add hidden 90°/180° gameplay turns;
- IDE validation must detect actor/gameplay facing versus root/mesh mismatch beyond presentation allowance.

---

## Accessibility / settings

Stillring must expose **Melee Facing Assist**:
- `Standard` — reviewed baseline bounded assistance;
- `Reduced` — smaller correction magnitude/rate within identical semantic rules;
- `Off` — no automatic target/input correction after attack acceptance beyond the initial explicit player/body direction.

Changing this setting may not:
- change target selection;
- add translation/magnetism;
- alter damage/reach;
- expand hitboxes;
- change lock-on behavior;
- make Heavy less committed in other ways.

Exact values require human play tuning.

---

## Combat System IDE requirements

### Inspect
Expose:
- attack ActionId/family/phase;
- locked/unlocked state;
- target sampled for facing, if any;
- body facing at acceptance;
- movement-input facing intent;
- attack-facing desired yaw;
- current yaw error;
- assist setting Standard/Reduced/Off;
- correction window open/closed;
- total yaw cap/rate;
- requested versus resolved correction;
- whether target was outside cap/cone;
- animation/root rotation separately;
- action-authored translation separately.

### Tune
Prototype values:
- Light per-entry correction cap/rate/window;
- Heavy smaller cap/rate/window;
- unlocked input meaningful threshold;
- assistance-distance/cone bounds;
- Reduced profile scale;
- visual root/mesh blending that does not change gameplay facing.

### Exercise
Scenarios:
- locked target 0/15/30/60/90/135/180° off current facing;
- target switch between Light entries;
- target switch during current Light Active;
- target switch during Heavy early/late Startup;
- unlocked attack with forward/side/back/no movement input;
- camera facing opposite Neris while unlocked;
- target dies/invalidates during correction;
- wall/collision near target;
- Standard/Reduced/Off comparison;
- altered rotational root-motion animation.

### Validate
Detect:
- attack automatically selecting a non-locked enemy;
- correction beyond hard yaw cap;
- Active-phase target tracking;
- Heavy retarget after acceptance;
- target switch rewriting current committed Light entry after window closes;
- rotation assistance moving/translating the actor;
- camera yaw directly steering unlocked attack without movement/body intent;
- root-motion rotation exceeding gameplay authority;
- interrupted attack retaining rotation assistance;
- setting changing damage/reach/target selection;
- frame-rate-dependent rotation amount.

### Capture
Record facing inputs/target, acceptance body yaw, desired target yaw, correction window/caps, per-frame or sampled resolved correction, final attack yaw, target changes, interrupts, animation/root rotation, and setting profile.

---

## Representative tests

1. Small locked-target yaw error is assisted smoothly during Light Startup.
2. Large/rear error is capped and can miss rather than spin 180°.
3. Target switched after Light facing closes does not redirect current strike.
4. Next Light entry may face the newly selected target within its own cap.
5. Heavy samples once at acceptance and ignores later target switches for current action.
6. Unlocked meaningful movement input determines intended attack facing; no input uses current body facing.
7. Unlocked attacks do not search for nearby enemies.
8. Assistance never moves Neris toward the target.
9. Interrupt cleans up correction immediately.
10. Standard/Reduced/Off preserve identical target/collision/damage semantics.
11. Root-motion/animation changes cannot exceed gameplay yaw authority.
12. 30/60/120+ FPS produces equivalent bounded correction.

---

## Research basis / design lineage

Epic's Unreal Engine 5.8 CharacterMovement supports smooth rotation toward controller or movement-derived desired rotations, and the Game Animation Sample demonstrates state-dependent turn/pivot/root-yaw handling. These are useful implementation primitives, but Stillring uses an action-owned attack-facing contract rather than inheriting generic controller orientation.

PlayStation's *God of War Ragnarök* accessibility options explicitly separate target/aim/strafe assistance from raw control and allow assist strength/behavior to be configured. Stillring applies the abstract accessibility lesson—assistance should be explicit and reducible—without copying target-selection behavior, exact values, or camera grammar.

No exact yaw values, animation, target magnetism, controls, or proprietary implementation are copied.

---

## Why this package is approved
Combat #9 makes attacks forgiving enough to feel intentional while preserving the possibility of a miss. Light can make a small new decision at each chain entry; Heavy cannot rewrite its commitment after acceptance; unlocked attacks remain authored by movement/body intent.

---

## Player-facing acceptance
Combat #9 passes when:
1. attack-facing is gameplay authority independent of animation;
2. only the explicitly locked target can inform locked attack assistance;
3. Light receives modest early-Startup correction with hard total/rate caps;
4. each new Light entry may sample the current target independently;
5. current Light Active never tracks target changes;
6. Heavy samples target/facing once at acceptance and has stricter/earlier-closing correction;
7. unlocked attacks use movement intent or body facing and do not enemy-search;
8. no assistance translates/vacuums/orbits/extends reach;
9. rear/large-angle targets can remain outside the strike instead of forcing a spin;
10. interrupts cleanly terminate correction;
11. Standard/Reduced/Off affect only bounded rotational assistance;
12. IDE explains every desired/resolved correction and cap result.

---

## Next combat decision
**Combat Decision #10 — combat resource / stamina / posture decision.**

Research independently before approval. Determine whether the already-defined commitment, Guard Reaction, directional coverage, Evade timing, and reaction hierarchy create enough cost without a universal resource; compare no resource versus defense-only integrity/posture versus shared combat stamina, and add a meter only if it creates decisions the state model cannot already create.