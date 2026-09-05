# 55 — Gate 2 Offscreen / Occluded Threat Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Enemy / Encounter Decision #6 for GitHub Issue #104. Defines when enemies outside the player's meaningful view may begin or continue committed attacks, how hard occlusion differs from ordinary offscreen status, and what supplemental threat communication may reveal.

## Authority
Locked under the owner's scheduled-run delegation after a fresh focused research pass.

Threat-awareness principle:
> **Do not punish the player for information the game chose not to make available.**

This decision extends, but does not replace:
- Camera #13: secondary enemies receive no ordinary camera steering authority;
- Encounter #1: offscreen status never lowers the fairness bar for commit permission;
- Ranged #3: Standard Ranged Shot `PressureCommit` requires presentation readability;
- Telegraph #5: committed warnings are honest gameplay promises and audio/color/vibration cannot be the only critical warning.

---

## Decision #6 — offscreen / occluded threat rules — LOCKED

### 1. Three distinct presentation states
Encounter logic must distinguish at least:

1. **Meaningfully visible** — the enemy or its attack source is sufficiently presented that the committed tell can reasonably be interpreted under Decision #5.
2. **Offscreen but not hard-occluded** — the enemy is outside the current frame or too close to its edge to rely on body animation, but the world does not physically block the threat path.
3. **Hard-occluded** — meaningful opaque geometry blocks line of sight and/or the attack's actual path from enemy to Neris.

These are not interchangeable. Being behind the camera is a presentation problem. Being behind a stone wall is both a presentation and world-geometry problem.

### 2. New MajorCommit attacks should ordinarily begin from meaningful visibility
The baseline rule for ordinary high-salience enemy attacks is:

> **A fresh `MajorCommit` should not begin from fully offscreen presentation unless that specific attack has an approved offscreen warning contract that provides a fair practical response window.**

For Gate 2 representative melee and shield attacks, no such special offscreen-start exception is needed. They therefore require meaningful player-facing readability before entering their committed Telegraph.

An enemy that is offscreen may:
- reposition;
- seek a better approach lane;
- maintain non-urgent pressure;
- request future commit eligibility;
- move into a readable attack position.

It may not simply begin a normal high-salience melee/shield tell behind the player's back and claim the body animation was sufficient.

### 3. Offscreen does not cancel an attack that already committed honestly
If an attack entered Telegraph while meaningfully readable and then the player turns the camera, switches targets, or otherwise lets that attacker leave frame:
- the attack remains committed;
- the enemy does not automatically freeze or cancel;
- the scheduler does not refund the player merely because the camera moved;
- the attack continues according to its established path/timing unless interrupted by legitimate gameplay.

This protects causality and Decision #5's promise rule.

However, once the attack is no longer meaningfully visible, any remaining reaction requirement must still satisfy its approved warning/communication floor. If the player could reasonably lose all actionable evidence before the last practical response opportunity, the attack or its supplemental communication must be redesigned.

### 4. Hard occlusion is stricter than offscreen status
A hard-occluded enemy may not begin an attack that requires an unobstructed physical path through the blocking geometry.

Examples:
- melee cannot hit through a solid wall;
- a Standard Ranged Shot cannot launch through a wall merely because the AI still knows Neris's location;
- shield lunges cannot phase through doors/columns;
- encounter permission cannot override collision/LOS legality.

AI memory, Blackboard knowledge, perception persistence, nav data, or prediction never create projectile/melee wall vision.

If the attack legitimately arcs around/over geometry or originates from a visible world mechanism, that is a separate authored attack contract and must prove its own warning/path readability.

### 5. An already-launched physical projectile remains real
Once a projectile has legitimately launched:
- killing or occluding the shooter does not erase it;
- camera rotation does not erase it;
- target-lock changes do not erase it;
- the projectile follows its reviewed physical/travel rules.

If it subsequently passes behind meaningful opaque geometry, that geometry blocks it according to collision. If it re-enters view after a temporarily hidden but physically valid path, the projectile still must preserve enough readable travel evidence to support a fair response.

### 6. Standard Ranged Shot PressureCommit remains presentation-gated
Decision #3's Standard Ranged Shot may use `PressureCommit` only when the attack has sufficient current presentation evidence.

Decision #6 makes that concrete:
- **Meaningfully visible source/telegraph:** eligible if all other rules pass.
- **Offscreen source without approved supplemental warning:** not eligible for a fresh PressureCommit.
- **Offscreen source with approved supplemental warning and legal clear shot:** may become eligible once the warning is interpretable early enough to preserve the response budget.
- **Hard-occluded source / blocked fire corridor:** ineligible regardless of indicator.

A HUD arrow can communicate danger; it cannot make an impossible shot legal.

### 7. Supplemental offscreen warning is allowed but bounded
Stillring approves an **optional directional threat indicator system** for committed offscreen attacks when needed to preserve fairness.

Its job is narrow:
> **Tell the player that a committed threat is approaching from a direction they cannot presently see.**

Baseline information it may communicate:
- coarse direction around Neris / screen edge;
- that danger is committed rather than ambient;
- broad urgency/timing progression when presentation testing proves direction alone insufficient;
- a small set of response-relevant semantic classes only if a future attack genuinely requires different responses and the distinction is independently approved.

It must not become enemy radar.

It should not reveal by default:
- exact enemy world position;
- enemy identity/name;
- health;
- distance number;
- route/path around walls;
- whether an unseen enemy is merely ready but not committed;
- future attack intention before commit permission;
- hidden target-selection/scheduler scores;
- objective/puzzle/secret relevance.

### 8. Do not show urgent indicators for enemies that are not committed threats
To preserve signal quality:
- ordinary offscreen presence does not create a danger arrow;
- readiness does not create a danger arrow;
- repositioning does not create a danger arrow;
- a denied attacker does not create a danger arrow;
- the indicator appears only when a committed offscreen threat meets the approved communication trigger.

This prevents the HUD from becoming a permanent circular enemy detector.

### 9. Indicator timing begins when body/world evidence is no longer sufficient
The system should not duplicate strong on-screen tells unnecessarily.

A committed threat may transition from embodied evidence to supplemental indication when:
- its source leaves meaningful frame coverage;
- its body telegraph is too small/edge-clipped to remain the reliable critical channel;
- projectile travel leaves ordinary trackability while still preserving a valid future threat.

The transition must avoid a warning gap and avoid double-signaling so aggressively that the UI becomes noisier than the fight.

Exact screen-space thresholds and blend timing remain human-play tuning.

### 10. Audio reinforces direction; it never owns fairness
Spatial enemy vocalization, weapon sound, projectile travel sound, and impact cues may reinforce offscreen direction.

But:
- muting audio cannot make an approved offscreen attack unfair;
- mono output or limited spatial hearing must still preserve essential warning through visual/supplemental channels;
- no attack receives permission solely because a stereo audio cue exists.

### 11. Vibration is never required threat information
Controller haptics may reinforce an imminent offscreen threat but cannot be the only warning or encode a required attack class.

### 12. Color is never the only distinction
If indicators later distinguish threat categories, they require shape/icon/motion or another non-color-only difference. Color may reinforce but not carry the entire semantic distinction.

### 13. Accessibility may strengthen the warning without changing attack legality
Approved accessibility direction includes:
- indicator On / Reduced / Off presentation choice where practical;
- scalable indicator size/contrast;
- stronger visual directional warning for players who cannot use audio;
- non-color-only category communication;
- optional broader timing assistance inside reviewed bounds;
- reduced nonessential combat FX that obscure the warning.

Turning the indicator Off must not secretly make the default encounter depend on impossible invisible reactions. The baseline attack-bandwidth/readability design remains responsible for fairness.

Where an encounter genuinely contains offscreen-capable attacks that rely on supplemental warning, the UI-off mode may require the attack/encounter to use stricter visibility eligibility rather than simply removing the player's information and leaving semantics unchanged. Any such accessibility/presentation substitution must be explicit and inspectable.

### 14. Camera remains uninvolved
No offscreen threat may:
- pull yaw;
- force recenter;
- widen FOV;
- back the camera away;
- raise camera height;
- override Relationship Frame;
- become primary target automatically.

The player may choose to turn, recenter, or target-switch after receiving threat information. The camera does not make that choice for them.

### 15. Target lock is not threat visibility
An enemy can be:
- locked but briefly occluded;
- unlocked but visible;
- unlocked and offscreen;
- current MajorCommit holder without being the lock target.

Encounter threat communication therefore derives from committed attack/presentation state, not target-lock identity.

### 16. PressureCommit overlap requires stricter offscreen proof
A PressureCommit overlapping a MajorCommit is allowed only when the player can separately attribute and respond to both threats.

If the pressure source is offscreen:
- its supplemental warning must be interpretable before the response conflict collapses;
- direction/urgency must remain distinguishable from the Major threat;
- the overlap must not demand mutually exclusive defensive responses at the same instant unless a future authored exception is explicitly approved;
- if those conditions are not met, the PressureCommit request is denied/delayed.

### 17. Difficulty cannot buy invisible aggression
Higher difficulty may tighten timing only within the readability floors already approved.

It may not:
- allow fresh offscreen MajorCommit attacks with no approved warning;
- remove supplemental warning while keeping the same invisible attack;
- grant ranged PressureCommit through hard occlusion;
- multiply simultaneous offscreen threats beyond proven communication bandwidth.

### 18. Encounter composition must respect indicator bandwidth
A warning system is not permission to fill the HUD with arrows.

If an encounter routinely produces several simultaneous offscreen committed warnings, the encounter composition/attack bandwidth is wrong for the baseline camera.

The indicator is a safety/readability layer, not a substitute for authored group behavior.

---

## Implementation boundary — Unreal Engine 5.8

Epic's AI Perception system can provide current/known perception state, sight ranges, peripheral vision, remembered stimuli, and debugging data. EQS/navigation can help enemies find legal readable positions.

Those tools are implementation inputs only.

Recommended authority split:
- **Encounter coordinator:** owns commit/readability eligibility and reason codes;
- **Attack/world service:** owns real path, collision, fire corridor, range, projectile legality;
- **Enemy AI/perception:** supplies honest sensed/known context and requests action;
- **Presentation visibility classifier:** reports meaningful on-screen/offscreen/occluded state for fairness policy;
- **Threat communication service:** renders only approved committed-threat information;
- **Camera:** no secondary-threat steering authority;
- **Combat / Encounter IDE:** exposes the complete chain from visibility → legality → permission → warning.

Do not equate AI Perception's remembered target location with player-visible threat information.

No requirement to adopt GAS follows from this decision. If Gameplay Cues or another presentation framework is later used, it presents approved semantic threat state rather than owning attack permission.

---

## Combat / Encounter IDE requirements

### Inspect
For every enemy / active attack expose:
- meaningful visibility state: visible / edge-degraded / offscreen / hard-occluded;
- real LOS/path/fire-corridor state;
- current target perception versus remembered target information;
- attack readiness;
- requested permission lane;
- commit grant/denial and exact reason;
- committed Telegraph / Active / Recovery phase;
- current offscreen-warning eligibility;
- warning channel active: body/world / indicator / audio reinforcement / haptic reinforcement;
- time warning became interpretable;
- last practical response time;
- current target-lock identity separately;
- projectile position/visibility/collision if launched;
- Major/Pressure overlap attribution state.

### Tune
With provenance:
- meaningful-screen-visibility thresholds;
- indicator size/contrast/motion parameters;
- warning handoff/blend thresholds;
- approved offscreen timing-assist envelope;
- ranged PressureCommit offscreen eligibility thresholds;
- overlap readability thresholds.

No tune control may turn blocked geometry into legal line of fire or silently allow unapproved offscreen attack classes.

### Exercise
Named fixtures:
- melee attacker directly behind camera;
- shield attacker behind camera;
- ranged attacker just beyond left/right screen edge;
- ranged attacker directly behind camera;
- ranged attacker behind solid wall;
- ranged attacker behind thin decorative/nonblocking clutter;
- committed on-screen melee moves offscreen during Telegraph;
- launched projectile shooter moves offscreen;
- launched projectile passes behind wall;
- one visible Major + offscreen Pressure shot;
- two possible offscreen Pressure sources competing;
- camera target switch during committed threat;
- rapid manual camera orbit causing repeated on/offscreen transitions;
- cramped room / doorway / column occlusion;
- audio muted;
- vibration disabled;
- indicator disabled/reduced/full;
- color-vision simulation;
- 30/60/120+ FPS.

### Validate
Detect:
- fresh ordinary melee/shield MajorCommit beginning fully offscreen without approved exception;
- fresh ranged PressureCommit beginning offscreen without sufficient approved warning;
- blocked fire corridor granted because AI remembers Neris;
- urgent threat indicator shown before actual committed threat;
- indicator revealing exact hidden enemy location through geometry;
- warning gap when threat leaves frame;
- warning disappearing before practical response need ends;
- hard-occluded melee/projectile damage through meaningful opaque geometry;
- target lock incorrectly controlling indicator eligibility;
- camera movement sourced from secondary threat;
- audio-only or vibration-only offscreen fairness;
- color-only required indicator class;
- Major + offscreen Pressure overlap below readability floor;
- difficulty enabling otherwise-forbidden invisible commits;
- excessive simultaneous indicators indicating encounter-bandwidth failure.

### Capture
Record:
- enemy visibility classification changes;
- real LOS/path legality;
- commit request/grant/deny/release;
- attack phase timeline;
- warning-channel transitions;
- indicator direction/urgency state;
- audio/haptic reinforcement;
- projectile world path/collision;
- player camera/lock state;
- player defensive response;
- hit/miss/Guard/PerfectGuard/Evade result;
- frame/time stamps.

A designer must be able to answer:
> **Why was this enemy allowed to attack when I couldn't see it, and exactly what warning did the game believe I had?**

---

## Representative red-team tests

1. Melee enemy starts behind camera with MajorCommit available: it repositions; it does not begin the normal committed swing offscreen.
2. On-screen melee begins Telegraph, player rotates camera away: attack continues honestly; supplemental warning prevents a critical information gap if still needed.
3. Shield attacker hidden behind solid wall: no through-wall commitment/hit.
4. Ranged enemy visible at frame edge: Standard Shot can commit if readable and legal.
5. Ranged enemy fully offscreen with indicator disabled and no other sufficient visual evidence: fresh PressureCommit is denied/delayed.
6. Same ranged case with approved indicator enabled: commit becomes eligible only when warning starts early enough to preserve response budget.
7. Ranged enemy behind wall with perfect indicator opportunity: still cannot fire through wall.
8. Shooter dies after projectile launch: projectile remains real and collides normally.
9. Visible Major melee + offscreen Pressure shot: warnings remain attributable and do not collapse into an unavoidable response conflict.
10. Rotate camera rapidly around three enemies: warning transitions do not flicker, double-fire, or produce radar-like presence arrows.
11. Target-switch away from current commit holder: threat/indicator semantics remain tied to committed action, not lock identity.
12. Mute audio / disable vibration: visual threat communication remains sufficient.
13. Disable indicator: encounter/attack eligibility falls back to stricter visibility where required rather than preserving impossible invisible attacks.
14. Hard cover repeatedly crosses between ranged enemy and Neris: fire permission follows real corridor legality, not remembered perception.
15. Five-enemy encounter: indicator count remains low because attack bandwidth limits committed danger; if warnings become a pinwheel, encounter validation fails.
16. 30/60/120+ FPS: visibility state hysteresis and warning handoff remain semantically stable.

---

## Research basis / design lineage

### Current primary engine reference
- Epic Games, Unreal Engine 5.8, **AI Perception** — sight/hearing/known perception state and debugging are available implementation inputs, including remembered stimuli and sight configuration. Stillring explicitly does not treat remembered AI knowledge as player-facing visibility authority.  
  https://dev.epicgames.com/documentation/unreal-engine/ai-perception-in-unreal-engine

### Shipped-game problem study
- PlayStation, **God of War Ragnarök Accessibility** — officially exposes a separate Enemy Off-Screen Indicator that points toward incoming attacks, and separately exposes camera-recenter/tracking options. The useful design lesson is separation between threat communication and camera ownership. Stillring does not copy its visual design, timing, attack taxonomy, or control behavior.  
  https://www.playstation.com/en-us/games/god-of-war-ragnarok/accessibility/

### Existing Stillring lineage
- Camera #13 already assigns offscreen threat fairness to encounter/UI/audio and refuses secondary-threat camera steering.
- Encounter #1 requires offscreen attacks to meet the same fairness standard as visible attacks.
- Telegraph #5 requires interpretable evidence, forbids critical audio/color/vibration-only signaling, and treats committed tells as promises.

### IP boundary
This decision copies no exact UI artwork, arrow geometry, colors, sound language, warning timing, enemy logic, camera values, or encounter composition from another title. It applies the general player problem under Stillring's own clean-room authority.

---

## Why this package is approved
The decision closes the loophole between camera honesty and encounter aggression:
- the camera does not reveal secondary enemies;
- enemies do not get to exploit that blindness;
- already-readable committed attacks remain causally honest if the player looks away;
- hard geometry remains physically meaningful;
- ranged pressure can exist offscreen only when an approved warning genuinely preserves response time;
- supplemental UI communicates a threat, not a hidden enemy database;
- accessibility substitutions are explicit and inspectable;
- the IDE can prove exactly why an unseen threat was allowed.

---

## Player-facing acceptance
Decision #6 passes when:
1. ordinary melee/shield enemies do not begin high-salience attacks invisibly behind the player;
2. committed attacks do not become fake/cancelled merely because the player turns the camera;
3. walls remain real barriers to attacks and projectiles;
4. ranged offscreen pressure is presentation-gated and never enabled by wall vision;
5. any supplemental offscreen indicator communicates only actionable committed-threat information rather than acting as radar;
6. no critical threat depends solely on audio, vibration, or color;
7. camera composition never changes because of secondary threats;
8. UI-off accessibility/presentation choices do not leave impossible invisible reactions in the baseline encounter;
9. Major + offscreen Pressure overlap remains attributable and responsive;
10. the IDE explains every unseen-attack permission and warning transition.

---

## Next decision
**Enemy / Encounter Decision #7 — enemy reaction / stun / poise / guard-break model if retained.**

Research independently before approval. Do not infer enemy stagger, super armor, poise meters, stun resources, guard-break rules, boss immunity, or interrupt thresholds from player combat authority.