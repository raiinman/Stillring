# Camera Decisions #12–#18 — Research Packet

**Status:** NON-CANONICAL / OWNER REVIEW REQUIRED  
**Updated:** 2026-09-05  
**Scope:** Research and recommendation packet only. Nothing in this file is LOCKED unless later promoted into camera authority after explicit owner approval.

## Authority boundary
Read with:
- `docs/22_GATE1_CAMERA_SPECIFICATION.md`
- `docs/26_GATE1_CAMERA_LOCK_ACQUISITION_ADDENDUM.md`
- `docs/27_GATE1_CAMERA_LOCK_FRAMING_ADDENDUM.md`
- `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`
- `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
- GitHub Issue #2

Locked camera behavior through Decision #11 remains authority. This packet must not silently override it.

Research basis includes Unreal Engine 5.8 Enhanced Input, Gameplay Cameras/rig transitions, multi-actor framing primitives, Camera Shake, and established lock-on design patterns. Engine capabilities are implementation options, not Stillring policy.

---

# Decision #12 — target-switch transition behavior

## Research conclusion
Target switching should be an **explicit directional selection command inside the current combat relationship**, not an automatic re-ranking event and not a free-camera gesture disguised as targeting.

## Recommended package
- A deliberate switch request samples eligible established-lock candidates once.
- Direction is interpreted primarily in **screen space relative to the current locked target**, because #11 makes the current relationship frame the player's combat visual reference.
- Left/right switch requests prefer the nearest valid candidate in that screen-space direction; vertical separation can contribute but should not make a target on the wrong side win merely because it is closer in world space.
- Candidates must satisfy targetability and switching-specific range/visibility rules; brief current-target occlusion grace does not automatically authorize switching through a wall.
- A successful switch commits target identity immediately, then performs one short eased relationship-frame transition from the current camera pose to the new pair frame.
- No intermediate recenter, camera cut, FOV punch, freeze, slowdown, or target-cycle carousel.
- No candidate in the requested direction = no target change and no camera lurch.
- Repeated flicks are debounced enough to prevent accidental multi-skip but remain responsive; exact thresholds/timing remain tuning.
- Switching never happens silently because another enemy scored higher.

## Critical control conflict with #11 manual nudge
Recommendation: distinguish **discrete directional flick** from **sustained camera nudge** semantically. Enhanced Input supports contextual actions, triggers, radial dead zones, and prioritization, but the exact thresholds must be tuned and accessible. Mouse input likely needs a separate explicit switch binding rather than trying to infer a mouse “flick.” Decision #17 should own final device mapping.

## Rejected
- nearest-enemy cycle regardless of view direction;
- automatic retarget on every camera nudge;
- unlimited rapid target roulette;
- switch-through-hard-cover by default;
- camera snapping before target identity changes;
- hidden priority based on health/threat/quest relevance.

## IDE/test evidence
Expose switch request vector, current target, eligible candidates, screen-space direction/error, LOS, rejection reasons, winner, debounce state, nudge-vs-switch classification, commit frame, transition progress, and no-candidate result.

Adversarial tests: three targets clustered on one side; one closer target on wrong side; target above-left versus farther pure-left; wall-hidden requested-side target; rapid alternating flicks; sustained camera nudge that must not switch; mouse/controller parity.

---

# Decision #13 — multiple-enemy framing limits

## Research conclusion
Stillring should **not** turn ordinary lock-on into a group-camera that tries to keep every nearby enemy visible. That destroys #11's stable relationship frame and encourages tactical zoom-out.

## Recommended package
- #11 remains a two-subject frame: Neris + current target.
- Secondary enemies may contribute only to **readability pressure**, not become equal framing subjects.
- The camera may make a very small bounded composition bias when a dangerous secondary enemy is already near a screen edge and doing so does not materially damage the primary pair frame.
- No automatic dolly just because enemy count rises.
- No FOV widening because three enemies entered the arena.
- No camera orbit toward offscreen secondary enemies.
- Encounter design and aggression rules must respect the actual visual bandwidth; #6 already makes this a production obligation.
- Offscreen-threat communication should be handled by combat/UI/audio policy later rather than camera contortion.

## Hard limit
If preserving the primary pair plus meaningful secondary-threat awareness requires a tactical zoom-out, the encounter/camera staging is wrong for ordinary lock-on. #13 should not rescue unreadable arenas.

## IDE/test evidence
Expose secondary candidate positions, edge proximity, whether any secondary composition bias is active, maximum allowed bias, reason for rejection, and a screen-space threat occupancy overlay for tuning encounter readability.

Tests: 2/3/5 enemies distributed around Neris; all on one side; one behind camera; doorway funnel; cramped room; ranged enemy at edge while melee target is locked; rapid secondary crossing behind primary target.

---

# Decision #14 — large-boss framing

## Research conclusion
Boss scale requires a **boss-authored framing profile**, but not a bespoke cinematic camera grammar for every boss.

## Recommended package
- Large bosses provide explicit authored camera framing bounds/anchors rather than relying on one skeletal bone.
- The relationship frame can use a larger target bound and a boss-specific canonical distance envelope.
- Camera may dolly farther than ordinary #11 limits, but remains capped and level-tested.
- Stable FOV remains preferred; modest boss-specific FOV tuning is allowed only if human play proves physical dolly cannot preserve attack readability without excessive distance.
- Camera should frame the **action-relevant portion** of a huge target, not insist on showing the entire body at all times.
- Authored phase/action anchors may move the meaningful target region, but they must correspond to visible combat anatomy/action—not hidden “look here” solution metadata.
- Extremely tall targets use bounded pitch/vertical composition; camera never points so high that Neris/footing become unreadable.
- Arena geometry must be authored around valid boss camera envelopes.

## Rejected
- always fit entire boss silhouette;
- indefinite zoom-out;
- target head hard-centered;
- phase-driven cinematic cuts during ordinary control;
- hidden attack predictor steering camera before readable animation/world evidence.

## IDE/test evidence
Show boss framing profile, active target bounds/anchor, phase/action anchor reason, requested/resolved pair frame, min/max boss dolly, FOV, player/target screen occupancy, collision constraints, and unreadable-frame warnings.

Tests: tall humanoid, wide quadruped, long body crossing frame, target part above/below Neris, boss against wall, boss in cramped edge of arena, phase anchor change during movement, airborne boss action.

---

# Decision #15 — jump / fall / mantle camera

## Research conclusion
Airborne/traversal camera should preserve **continuity and landing readability**, not add cinematic lag or automatic spectacle.

## Recommended package
- Ordinary jump keeps the current exploration/lock camera grammar; no jump-specific zoom or FOV kick.
- Vertical camera response uses a small dead zone so modest jump arc does not bob the entire camera.
- During a meaningful fall, Neris may move within a larger vertical framing envelope before camera translation follows; the goal is to reveal landing/trajectory context without chasing every centimeter.
- Player manual camera input remains authoritative unless a physical camera constraint applies.
- No automatic pitch-down merely because Neris is falling; drop/landing visibility may justify bounded composition bias only when supported by actual trajectory/ground evidence.
- Mantle/scramble should preserve camera continuity through the authored character displacement; the camera should not attach to animation root motion or snap to a new pivot.
- Ledge catch/hang remains a real state. Camera should smoothly resolve to a readable hang composition while preserving player orbit where geometry permits; exact hang-specific framing can remain tuning if it does not change control grammar.
- Lock disappearing in air continues to obey the locomotion rule that freezes the last stable target-relative frame for air correction; camera must not retroactively reinterpret movement.

## Rejected
- landing camera slam;
- automatic dramatic look-down on every fall;
- camera spring overshoot after jump apex;
- mantle camera cut;
- animation-bone camera attachment;
- hidden fall-target prediction.

## IDE/test evidence
Expose locomotion/traversal state, camera vertical dead-zone occupancy, requested/resolved vertical follow, ground/landing evidence, manual suppression, mantle/hang state, collision constraints, and transition ownership.

Tests: tiny hop, max ordinary jump, sprint jump, jump under low ceiling, fall next to wall, long fall, ledge catch, pull-up, drop/release, mantle toward/away camera, locked-target jump.

---

# Decision #16 — camera shake default / accessibility range

## Research conclusion
Camera shake should be **event-authored feedback layered after camera composition**, never part of targeting/collision logic. Unreal exposes per-shake scale, play space, attenuation, blend, and global/instance scaling primitives.

## Recommended package
- Default shake is restrained; gameplay readability outranks impact spectacle.
- Separate semantic categories: locomotion/landing, player hit, attack impact, environmental/world event, boss/heavy event, cinematic-only where applicable.
- Final settings require at minimum **Full / Reduced / Off** or an equivalent continuous global intensity slider that reaches zero.
- Critical gameplay information may not depend solely on camera shake.
- Reducing/off must not change hit timing, damage, invulnerability, animation, or game-state outcomes.
- Rotational shake should be more conservative than positional micro-shake because it can directly disrupt aiming/orientation.
- Long or looping environmental shake requires attenuation/comfort review.
- No shake may fight collision or target framing by permanently altering solved camera state; shake is additive/transient.

## IDE/test evidence
Expose active shake instances, semantic category, source, raw scale, accessibility multiplier, final scale, play space, duration/blend, attenuation, and one-click category preview.

Tests: stacked hit+boss+environment shake, Reduced/Off, repeated rapid hits, camera against wall, lock-on, low ceiling, sustained rumble source, controller rumble independently disabled.

---

# Decision #17 — sensitivity / inversion / mouse parity

## Research conclusion
Controller and mouse should share **camera semantics but not forced identical transfer functions**. Enhanced Input supports modifiers, dead zones, contextual mappings, triggers, and remapping.

## Recommended package
- Separate horizontal and vertical camera sensitivity controls.
- Separate controller and mouse sensitivity values.
- Independent invert-Y; invert-X should also be available for camera because accessibility/remapping cost is low and some players require it.
- Controller camera uses radial dead-zone semantics with configurable inner dead zone and outer saturation, consistent with locomotion philosophy.
- Mouse has no artificial stick-style dead zone or acceleration by default.
- Raw mouse delta should map predictably to angular camera change; frame-rate independence is mandatory.
- Controller response curve may be tuned for precision near center and speed near edge, but no opaque acceleration that prevents repeatable camera movement.
- Lock-on nudge and target-switch classification must use device-appropriate thresholds rather than pretending mouse movement is a gamepad flick.
- Remapping must cover recenter, lock/cancel, switch actions, camera axes, Sprint, jump, and explicit traversal release.
- Settings should expose meaningful names, not engine CVars.

## IDE/test evidence
Expose raw input, post-dead-zone/modifier input, active mapping context, sensitivity/inversion, final angular request, device source, switch/nudge classifier state, and frame-time normalized result.

Tests: low/high DPI mouse, 30/60/120+ fps, small stick drift, low/high controller sensitivity, inversion combinations, lock-on nudge, target switch, accessibility Reduced camera assist with custom sensitivity.

---

# Decision #18 — aim / first-person / gyro if later proposed

## Research conclusion
**Do not add these modes in Gate 1 without a demonstrated gameplay verb requiring them.** This is the strongest current recommendation.

## Recommended package
- Gate 1 ships no generic first-person toggle, no shoulder-aim mode, and no gyro requirement.
- If a later tool/mechanic genuinely needs precision aiming, open a new owner decision with that tool's exact problem first.
- Any future aim mode must state whether it changes locomotion, target lock, FOV, shoulder position, reticle authority, camera collision, accessibility, and input mapping.
- Gyro, if proposed later, should be optional additive fine-aim input with recenter/calibration and platform-specific testing—not a hidden substitute for stick/mouse camera.
- First-person must never become an automatic cramped-room fallback because #7 explicitly rejects that.

## Why defer
Adding an unused camera grammar now expands controller mapping, accessibility, collision, animation, UI, tuning, QA, and System IDE surfaces without proving player value. That violates Stillring's integration-cost rule.

---

# Cross-decision recommendations

## Proposed approval order
12. target switching  
13. multiple-enemy limits  
14. large-boss framing  
15. jump/fall/mantle camera  
16. shake/accessibility  
17. sensitivity/inversion/mouse parity  
18. explicitly defer generic aim/first-person/gyro unless a later verb requires it

## Camera / Targeting IDE additions across #12–#18
The workbench should eventually combine:
- target acquisition/switch candidate overlays and rejection reasons;
- relationship-frame zones and target bounds;
- primary versus secondary-threat occupancy;
- boss framing profiles;
- airborne/traversal camera ownership and vertical dead zones;
- active shake stack and accessibility multiplier;
- raw→processed camera input diagnostics and active device/mapping context;
- one-click named camera scenarios covering every approved decision;
- canonical/session/staged/promoted provenance for all live-tunable values.

## Gate 1 red-team matrix
At minimum combine decisions rather than test each in isolation:
- target switch during wall compression;
- target switch under low ceiling;
- manual nudge versus switch classification;
- jump while locked, then target invalidates;
- boss framing near arena wall;
- camera shake while collision-compressed;
- Reduced/Off shake while target switching;
- mouse versus controller at different sensitivities;
- secondary enemies entering/leaving screen during a primary lock;
- long fall with manual camera input and nearby target;
- cramped-room lock-on with multiple enemies;
- all camera assists reduced/off where supported.

## Research references
Primary engine references consulted:
- Unreal Engine 5.8 Enhanced Input documentation — contextual mappings, 2D actions, triggers, radial dead zones, remapping.
- Unreal Engine 5.8 Gameplay Cameras API — camera rigs, transitions, actor-group/target framing, raw input camera nodes.
- Unreal Engine 5.8 Camera Rig Transition API — explicit blend/transition conditions and orientation behavior.
- Unreal Engine 5.8 Camera Shake documentation/API — pattern, scale, blend, play space, attenuation, instance control.

Comparative game references are used only for design-problem study; exact controls/timings/presentation are not authority.

---

# Owner-review queue
This packet makes Decisions #12–#18 **research-ready**, not approved.

The next owner decision remains:
> **#12 — target-switch transition behavior.**

Recommended philosophy candidate:
> **Switch by intent, not by roulette.**
