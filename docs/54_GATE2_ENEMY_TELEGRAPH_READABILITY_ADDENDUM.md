# 54 — Gate 2 Enemy Telegraph / Readability Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Enemy / Encounter Decision #5 for GitHub Issue #104. Defines the shared warning grammar for representative melee, ranged, and shield attacks. It does not yet define the full offscreen/occluded threat policy, which remains Decision #6.

## Authority
Locked under the owner's scheduled-run delegation after a fresh focused research pass.

Telegraph principle:
> **If the game asks for a reaction, the world must first make the question legible.**

---

## Decision #5 — enemy telegraph / readability contract — LOCKED

### Telegraphs are gameplay promises
A real attack telegraph is not decoration. Once an enemy has received the encounter permission required for its attack and begins the gameplay-significant warning, the player should be able to trust that the action has actually committed unless a visible gameplay event legitimately interrupts it.

This establishes a strict distinction:
- **Readiness / pressure presentation** — an enemy may look alert, tense, armed, or prepared while no attack is committed;
- **Committed Telegraph** — the attack has encounter permission and is now giving the player readable evidence that danger is coming;
- **Active Danger** — the attack's hit/projectile/contact authority is live;
- **Recovery / Resolution** — the attack has ended its danger window and is visibly resolving.

Enemies denied attack permission may use readiness presentation. They may not repeatedly imitate the same urgent committed tell used by a real attack.

### Encounter permission precedes the committed tell
Decision #1 remains authoritative:
- `MajorCommit` / `PressureCommit` permission is granted before the gameplay-significant telegraph begins;
- no two enemies may both begin genuine MajorCommit tells and later cancel one merely because the scheduler chose a winner;
- the attack reservation remains owned through the period where the action still demands the reviewed attention lane.

This keeps the warning language causally honest.

### Shared semantic attack phases
Every representative enemy attack must expose these gameplay-readable phases even if its animation implementation differs:

1. **Ready** — attack could become possible but is not committed; no urgent promise;
2. **Telegraph** — committed warning interval after encounter permission;
3. **Active** — reviewed damage/contact/projectile-launch authority;
4. **Recovery** — no longer active; attack consequence remains visible/interruptible as authored;
5. **Resolved / Interrupted** — returns to the archetype's legal next state and releases encounter ownership when appropriate.

An attack may have finer internal data, but these meanings must remain inspectable.

### The primary warning channel is embodied/world-space evidence
For ordinary on-screen Gate 2 attacks, the default telegraph must be understandable from the enemy/action itself rather than requiring a floating icon.

Primary evidence may combine:
- body weight shift / stance change;
- weapon draw-back, lift, charge, or directional preparation;
- shield opening/reorientation associated with an attack;
- readable projectile charge/origin cue;
- movement/lunge preparation that corresponds to the actual attack path;
- world-space effect attached to the attack source where fiction supports it.

The chosen presentation must preserve recognizable silhouette/motion in representative camera distances and backgrounds.

### Baseline Gate 2 does not use mandatory colored attack rings
The representative melee, ranged, and shield attacks do **not** require a universal red/yellow/blue ring or equivalent attack-type icon above enemies.

Reasons:
- the player should first learn attack intent from enemy/world behavior;
- color-only danger classes are accessibility-hostile;
- a universal ring system can collapse distinct enemy actions into UI prompts rather than readable combat;
- Gate 2 currently has no need for a large taxonomy of unblockable/parry-only attack classes.

A future concrete attack type may earn supplemental UI through a separate decision if embodied warning proves insufficient.

### Guardability is not encoded by color alone
For the current representative Gate 2 attacks:
- ordinary melee strike is Guardable when it reaches the approved front sector;
- Standard Ranged Shot is ordinarily Guardable under Decision #3;
- shield enemy's representative offensive action must state its guardability in attack data.

If future attacks become unguardable or require a special response, they must communicate that distinction through at least one non-color-only channel and receive explicit authority. Decision #5 does not invent an unblockable class merely to populate a warning system.

### Audio is reinforcement, never the sole critical tell
Enemy attacks may use:
- vocalization;
- weapon sound;
- foot/armor movement;
- projectile charge/release sound;
- spatial audio direction.

But a player who cannot hear that channel must still receive sufficient critical warning through visual/world-space evidence or later approved visual accessibility assistance.

Audio timing must also agree with the gameplay action rather than becoming an independent danger clock.

### Controller vibration is optional reinforcement only
Vibration/haptics may reinforce an attack or impact where appropriate.

Turning vibration off cannot:
- remove required warning;
- alter attack timing;
- alter Guard/Evade/Perfect Guard windows;
- make the player unable to distinguish active danger from recovery.

### Committed tells cannot casually lie
Once Committed Telegraph begins, it may terminate early only for an honest gameplay reason, such as:
- enemy is interrupted/staggered/dead under later reaction authority;
- attack path/world condition becomes invalid in a way the action contract explicitly allows to abort;
- scripted ownership explicitly cancels the encounter for a legitimate higher-priority state;
- encounter reset/death cleanup.

It may not cancel because:
- Neris moved out of ideal range and the AI wants a better attack;
- another enemy became a higher scheduler score;
- target lock changed;
- a random local behavior reevaluation chose something else;
- animation blend convenience made another clip preferable.

If interruption occurs after a committed tell, the interruption itself must be readable enough that the player can understand the threat ended.

### Attack direction must agree with the tell
The visible preparation must reasonably predict the attack's actual dangerous space.

Requirements:
- melee wind-up should correspond to the authored swing/lunge direction/envelope;
- shield attack Exposure and weapon/body motion must agree;
- ranged charge/origin must correspond to projectile source;
- no animation shows a narrow straight strike while gameplay resolves a huge unexplained side/rear volume;
- no late facing snap rotates the danger into a player who correctly moved outside the telegraphed line beyond separately-approved bounded correction.

Exact hit volumes remain attack tuning, but gross mismatch is invalid.

### Telegraph time is response budget, not cinematic delay
Telegraph duration exists to make the required player response perceivable and actionable.

It must account for:
- camera distance / on-screen size;
- attack travel time;
- required defensive action complexity;
- whether a MajorCommit and PressureCommit overlap;
- player control commitments that legitimately restrict reaction;
- representative frame rates;
- accessibility timing options where retained.

Longer is not automatically fairer. Excessive wind-up that destroys pressure or feels theatrical is also a failure.

Exact timings remain human-play tuning.

### Readability is measured from interpretable evidence, not internal state entry
The attack cannot claim a long warning window merely because gameplay entered `Telegraph` while the character remained visually indistinguishable from Ready for most of that time.

For testing, measure:
> **time from first reasonably interpretable committed evidence to the player's last practical response opportunity.**

The IDE should expose both internal phase start and configured/observed presentation markers so mismatches can be diagnosed.

### Active danger is gameplay-owned
Enemy contact/hit authority becomes active according to reviewed gameplay attack data/state.

Animation Notifies may synchronize presentation or report animation progress, but an Anim Notify is not by itself the reason an attack is allowed to hurt Neris.

Requirements:
- attack data/state owns the intended active interval/conditions;
- animation markers can be validated against that authority;
- blend, dropped notify, filtered notify, or alternate animation asset cannot silently invent/remove combat legality;
- animation and gameplay mismatch must be visible in the IDE.

### Interruption cleans active danger immediately
If an attack is legitimately interrupted before/during Active:
- future unearned hit events are disabled;
- encounter commit ownership is released at the reviewed point;
- stale animation callbacks cannot reactivate the attack;
- projectile already launched remains governed by projectile/world authority rather than being erased merely because the shooter was interrupted, unless later attack data explicitly says otherwise.

### Recovery must look like recovery
When gameplay says the attack has left Active:
- presentation should no longer look like an imminent new hit from the same action unless the attack genuinely contains another separately-authored Active interval;
- the enemy may remain physically dangerous as a body, but no invisible lingering attack volume persists;
- recovery should help the player understand when an earned punish/opening exists.

### Ranged projectile adds a second readable layer
For Decision #3's Standard Ranged Shot:
- firing telegraph makes launch imminent;
- projectile itself remains visible enough to track in representative play;
- travel time is part of the response budget;
- projectile danger does not require the player to keep staring at the shooter's animation after launch.

A projectile that becomes visually lost against representative backgrounds is a readability failure even if its pre-fire tell was excellent.

### Shield states share the same truth rule
For Decision #4:
- `Shielded`, `ShieldDisplaced`, and attack `Exposure` must each have distinct enough body/shield presentation that the player can learn when direct frontal attacks are ineffective or an opening exists;
- presentation cannot show a fully raised stable shield while gameplay secretly treats the sector as open for a long unexplained interval;
- Heavy displacement feedback must clearly differ from an ordinary Light deflection.

### Overlapping Major + PressureCommit must stay separable
When a Standard Ranged Shot overlaps one MajorCommit:
- both attack tells must remain individually attributable;
- the ranged tell/projectile may not visually mask the Major attacker;
- their last-practical-response moments should not be intentionally synchronized into an unavoidable contradictory input unless a future authored exception is separately approved;
- encounter IDE must flag suspicious timing collapse.

Decision #5 does not require perfectly alternating rhythms; it forbids deliberately unreadable stacking.

### No warning spam from non-threats
Enemies not holding attack permission may produce ambient combat motion/sound, but must avoid flooding the same salient channels used for committed tells.

Examples to avoid:
- every denied melee enemy repeatedly raising a weapon exactly like its real attack wind-up;
- multiple ranged enemies showing full charge flash with no permission to fire;
- shield enemies repeatedly opening attack exposure as fake pressure;
- generic danger audio stingers from enemies with no committed threat.

A busy encounter should feel alive without destroying signal-to-noise ratio.

### Baseline on-screen attacks need no mandatory attack UI
For ordinary on-screen Gate 2 combat, no floating attack-arrow/ring is required by default.

Optional accessibility or offscreen threat UI may be added by Decision #6, but must supplement rather than excuse poor on-screen body/world telegraphs.

### Accessibility presentation may strengthen evidence, not rewrite semantics
Permitted future options include:
- high-contrast enemy/projectile presentation;
- adjustable critical UI color where UI exists;
- larger supplemental threat indicators;
- visual alternatives for audio cues;
- reduced nonessential effects that obscure telegraphs;
- bounded additional warning/timing assistance where separately tuned.

These may not:
- change whether an attack is Guardable;
- secretly turn a MajorCommit into PressureCommit;
- create a Perfect Guard automatically;
- change hit geometry;
- make a fake tell legal.

### Difficulty scales within readability floors
Difficulty may tune attack timing/cadence inside reviewed envelopes, but must preserve a minimum interpretable warning standard.

Higher difficulty should not mean:
- removing the first readable wind-up frame;
- making projectile telegraphs indistinguishable from idle;
- adding unexplained Active frames before visible preparation;
- using offscreen attacks with no approved communication;
- making animation/gameplay timing intentionally misleading.

---

## Unreal Engine 5.8 implementation boundary

Epic's Animation Notifies are useful synchronization mechanisms tied to animation timelines, with Notify States, Montage Notifies, filtering, trigger thresholds, and different tick/accuracy modes. That flexibility is precisely why Stillring cannot let a notify asset become sole combat authority.

Recommended split:
- **authoritative C++ attack data/state:** semantic Ready/Telegraph/Active/Recovery, commit ownership, hit legality, guardability and reaction properties;
- **animation:** presents those states;
- **Notifies / curves / montage markers:** synchronization/evidence points validated against gameplay authority;
- **Niagara/audio/haptics:** supplemental presentation;
- **Encounter IDE:** overlays semantic phase beside actual animation marker/timing.

No requirement to adopt GAS follows from this decision.

---

## Combat / Encounter IDE requirements

### Inspect
Expose for every potentially attacking enemy:
- attack ID/type;
- permission class and reservation state;
- semantic phase: Ready / Telegraph / Active / Recovery / Interrupted;
- phase elapsed/remaining;
- first configured readable-evidence timestamp/marker;
- current animation/montage/section/notify state;
- difference between gameplay phase and animation presentation timing;
- guardability/special properties from gameplay data;
- current facing / predicted danger envelope;
- visual readability eligibility / screen occupancy where measured;
- active audio/haptic/FX cues;
- whether supplemental UI is active;
- last interruption/cancel reason;
- Major + Pressure overlap timing.

### Tune
With provenance:
- Telegraph/Active/Recovery timing values inside approved attack data;
- presentation marker alignment offsets;
- projectile visual contrast/scale parameters where appropriate;
- nonessential FX suppression profiles;
- accessibility warning-assist envelope;
- overlap timing tolerance/warning thresholds.

No live tune control may silently change guardability, attack-permission class, hit geometry, or semantic threat class without the owning authority.

### Exercise
Fixtures:
- each representative melee/ranged/shield attack in isolation;
- early/on-time/late Guard;
- early/on-time/late Perfect Guard;
- Evade at multiple telegraph points;
- player walks out of melee line during Telegraph;
- attacker interrupted during Telegraph and Active;
- attacker killed during Telegraph;
- Standard Ranged Shot projectile in bright/dark/cluttered backgrounds;
- one Major + one PressureCommit overlapping at varied offsets;
- 2/3/5 enemies producing non-urgent pressure motion around one real tell;
- audio muted;
- vibration off;
- high-contrast/accessibility modes;
- camera compressed/low ceiling where applicable;
- 30/60/120+ FPS.

### Validate
Detect:
- committed telegraph beginning without encounter permission;
- Active danger before reviewed Telegraph/presentation evidence;
- attack hurt authority existing only in an animation notify;
- stale active hit state after interruption;
- gameplay Active interval materially mismatching attack presentation;
- fake committed tell from denied enemy;
- target-lock change canceling a committed tell without gameplay cause;
- projectile too visually indistinct under representative test presets;
- Shielded/Displaced/Exposure presentation contradicting gameplay state;
- mandatory color-only attack information;
- mandatory audio-only attack information;
- Major/Pressure response moments collapsing below approved readability floor;
- difficulty/accessibility setting altering semantic legality.

### Capture
Record a deterministic threat timeline containing:
- permission request/grant;
- semantic phase transitions;
- first readable-evidence marker;
- animation state/notifies/curves;
- audio/FX/UI cue starts;
- facing/danger envelope;
- Active start/end;
- player input/action response;
- hit/Guard/PerfectGuard/Evade/miss result;
- interruption/cancel reason;
- camera visibility context;
- frame/time stamps.

---

## Representative red-team tests

1. Denied melee enemy loops combat idle: never emits genuine attack wind-up.
2. MajorCommit granted: committed tell is immediately attributable and leads to the promised action unless visibly interrupted.
3. Neris moves out of range during committed tell: attack may whiff; AI does not casually cancel and pick a new move.
4. Kill attacker during Telegraph: tell visibly resolves/interruption cleans danger.
5. Force animation blend/alternate clip: gameplay Active authority remains correct and mismatch is caught by IDE.
6. Mute all audio: on-screen representative attacks remain understandable.
7. Disable vibration: no warning information is lost.
8. Simulate common color-vision constraints: no required attack class depends only on hue.
9. Major melee + ranged Pressure shot overlap: distinct readable signals and no intentionally collapsed unavoidable response instant.
10. Five enemies animate around Neris: one real urgent tell remains visually separable from ambient pressure.
11. Shield Heavy displacement versus Light deflection: visually distinguishable without audio/color-only dependence.
12. Projectile crosses bright/dark/cluttered environments: remains trackable or fails validation.
13. 30/60/120+ FPS: semantic phase ordering remains stable and presentation markers stay within reviewed tolerance.

---

## Research basis / design lineage

Primary/current references:
- Epic Games, Unreal Engine 5.8, *Animation Notifies*: Notifies/Notify States synchronize events to animations and support trigger thresholds, filtering, queued versus branching-point timing, and montage windows. Stillring uses them as synchronization/presentation evidence rather than sole gameplay authority. https://dev.epicgames.com/documentation/unreal-engine/animation-notifies-in-unreal-engine
- Epic Games, Unreal Engine 5.8, *Animation Insights*: tooling can inspect montage state, blend weights, animation graph updates, and timing, supporting the need to compare presentation against authoritative combat timelines. https://dev.epicgames.com/documentation/unreal-engine/animation-insights-in-unreal-engine
- PlayStation, *God of War Ragnarök Accessibility*: official options include color alternatives, high contrast, Audio Cue Alternatives, directional audio indicators, UI color correction for critical combat UI, reduced flashing, and configurable visual aids. The abstract lesson is multi-channel critical information and configurable presentation—not copying its attack-ring language. https://www.playstation.com/en-us/games/god-of-war-ragnarok/accessibility/

No proprietary warning icons, color grammar, exact timings, audio cues, animation frames, or UI layouts are copied.

---

## Why this package is approved
The contract keeps combat readable without outsourcing combat understanding to floating symbols.

The enemy's body, weapon, shield, projectile, and world-space motion carry the normal on-screen warning. Audio/FX/haptics reinforce it. Accessibility can strengthen or duplicate information. Gameplay remains the truth source.

Most importantly, the player can learn one consistent rule:
> **When the game shows a committed attack tell, believe it.**

---

## Player-facing acceptance
Decision #5 passes when:
1. each representative attack exposes Ready/Telegraph/Active/Recovery semantics;
2. encounter permission is granted before genuine committed tell;
3. ordinary on-screen attacks remain understandable from world/body evidence without mandatory attack icons;
4. no critical warning depends only on audio, vibration, or color;
5. a committed tell proceeds unless an honest visible gameplay interruption occurs;
6. visible attack direction and actual danger envelope broadly agree;
7. gameplay owns Active danger; animation notifies synchronize/present rather than define legality;
8. ranged projectile remains a readable threat after launch;
9. shield defensive/open states visibly agree with gameplay state;
10. Major + PressureCommit overlap remains separable;
11. difficulty/accessibility preserve semantic legality and a minimum readability floor;
12. IDE can prove the exact warning-to-danger timeline and catch presentation mismatch.

---

## Next enemy / encounter decision
**Decision #6 — offscreen / occluded threat rules and optional communication.**

Research independently before approval. Resolve when an enemy that is not meaningfully visible may begin/continue a committed attack, how ongoing attacks behave when they leave frame, whether/when directional threat indicators are justified, and how to preserve fairness without making the camera or UI omniscient.
