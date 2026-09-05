# 30 — Gate 1 Camera Multi-Enemy Framing Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Camera Decision #13 for Issue #2. This file extends the cumulative camera authority through Decisions #1–#13.

## Authority
Camera Decision #13 is locked under the owner's explicit scheduled-run delegation after a fresh independent research pass.

Decision #13 answers one question: **what influence do non-selected enemies have on ordinary established lock-on camera composition?**

Camera goal:
> **The player should look at Orra, not babysit the camera.**

Decision #11 remains the Neris↔current-target Relationship Frame. Decision #12 chooses which single target is current. Decision #13 decides whether everybody else gets to steer the camera.

---

## Camera Decision #13 — multiple-enemy framing limits — LOCKED

### Core philosophy
Ordinary established lock-on frames **one combat relationship at a time**.

> **Frame the fight you chose. Make the encounter respect what you can see.**

Secondary enemies do **not** automatically become camera framing subjects merely because they are nearby, dangerous, attacking, or numerous.

### No group-camera takeover
While one target is locked:
- #11 continues to frame Neris + the current target + readable space between them;
- secondary enemies do not enter the pair solver as equal or weighted framing targets;
- enemy count does not automatically widen the camera;
- enemy count does not automatically increase camera distance;
- enemy count does not automatically widen FOV;
- secondary enemies do not cause autonomous yaw/pitch orbit;
- offscreen enemies do not drag the camera toward themselves;
- threat scores, damage potential, AI aggression, quest relevance, or hidden attack timing do not secretly steer ordinary camera composition.

The camera therefore remains visually causal: it moves because Neris, the selected target, the player, or physical camera constraints require it—not because an unseen AI became important behind the player.

### Why group framing is rejected for ordinary combat
Modern camera systems can frame multiple actors or weighted groups. That is an engine capability, not Stillring policy.

Automatic group framing creates several risks for Stillring:
- tactical zoom-out as enemy count rises;
- constant distance/FOV breathing as enemies enter/leave the group;
- camera motion caused by actors the player did not choose;
- unstable composition when enemies cross, spawn, retreat, or circle offscreen;
- reduced readability of Neris and the selected target;
- hidden coupling between AI behavior and camera motion;
- pressure to solve unfair encounter staging with camera omniscience instead of encounter design.

Stillring rejects those tradeoffs for ordinary lock-on.

### Secondary enemies may still be visible
This rule does not hide secondary enemies or crop them intentionally.

- if other enemies naturally fall inside the #11 Relationship Frame, they remain visible;
- their presence does not change the camera solution;
- encounter composition may intentionally stage enemies where they remain readable inside ordinary framing;
- the camera does not avoid showing secondary enemies; it simply does not chase them.

### Switching remains explicit
If the player wants a different enemy to become the camera/combat relationship subject, Decision #12 is the mechanism.

- switch target explicitly;
- new target commits;
- #11 frames the new pair;
- previous target becomes secondary and loses ordinary camera influence.

No secondary enemy becomes primary merely because it attacks, moves closer, deals more damage, or occupies a more dramatic screen position.

### Offscreen threat responsibility
Secondary-threat readability is a **combat/encounter/UI/audio responsibility**, not an excuse for camera contortion.

Future systems may use deliberately reviewed tools such as:
- directional attack indicators;
- directional audio cues;
- enemy vocal/animation telegraphs;
- attack-bandwidth/aggression coordination;
- encounter spacing/staging rules;
- difficulty/accessibility assists.

Those systems must communicate threat without silently converting the camera into a radar dish.

Decision #13 does not approve any specific HUD icon or audio language; it establishes where the responsibility belongs.

### Encounter-design obligation
Encounter design must respect the visual bandwidth of the approved camera.

A combat encounter fails review if it routinely requires the player to react to high-consequence attacks from enemies that ordinary framing cannot reasonably reveal or communicate in time.

Therefore later combat/enemy design must define:
- how many enemies may make high-salience committed attacks simultaneously;
- how offscreen/occluded enemies telegraph or limit aggression;
- how ranged attackers communicate line-of-fire danger;
- how arenas avoid surrounding the player with unreadable simultaneous commitments;
- how difficulty changes preserve fairness rather than simply increasing invisible attack volume.

The camera is not required to rescue an encounter that exceeds its readable combat bandwidth.

### No automatic secondary-threat composition bias
Decision #13 explicitly rejects a default “small secondary-threat bias” in ordinary camera composition.

Reasons:
- even small automatic bias creates hidden camera ownership by non-selected enemies;
- it can fight #11 manual nudge and target relationship stability;
- threat scoring belongs to combat/AI and may change rapidly;
- it complicates accessibility and debugging for modest benefit;
- the same awareness can be delivered more honestly through encounter behavior and explicit threat communication.

If human playtesting later demonstrates a concrete accessibility need for optional group tracking, that must be opened as a separate explicit assist decision rather than smuggled into ordinary camera behavior.

### No automatic combat zoom by crowd size
The following are forbidden ordinary responses to increasing nearby enemy count:
- widening FOV;
- backing the camera away;
- raising the camera toward tactical/top-down presentation;
- flattening vertical composition;
- changing Neris/target screen anchors;
- changing camera damping/lag merely because more enemies entered range.

Large-boss framing remains Decision #14 and is not an enemy-count exception.

### Physical/occlusion authority remains unchanged
Secondary enemies do not override Decisions #5/#6/#7/#8.

- the camera still obeys collision;
- hard cover remains honest;
- Close Quarters Camera remains severe-compression authority;
- Ceiling-Constrained Camera remains low-ceiling authority;
- a visible secondary enemy does not justify clipping, wall-orbiting, or dissolving meaningful geometry.

### Target-switch candidate boundary
Decision #12 may inspect multiple enemies to decide an explicit target switch. That does not make those candidates camera subjects before or after the switch.

Candidate visualization/debug data belongs in the System IDE; ordinary player camera framing remains #11 until a winner commits.

### Large boss boundary
Decision #13 governs multiple **ordinary enemy identities** around one selected target. Large target scale, giant silhouettes, boss anchors, body-part framing, and boss-specific distance envelopes remain Decision #14.

---

## Accessibility boundary
Camera motion reduction benefits from this decision because crowd count cannot create extra automatic camera movement by default.

Future accessibility systems may offer:
- stronger directional threat indicators;
- enhanced audio cues;
- larger/high-contrast offscreen warnings;
- encounter assist settings;
- optional camera/combat assistance opened under explicit separate authority.

No critical secondary threat may be communicated solely by color, tiny UI, vibration, or camera motion.

God of War Ragnarök is useful problem evidence here: it exposes group camera tracking, lock-on variants, offscreen enemy indicators, directional audio/visual information, and motion-reduction controls as distinct assists/settings rather than one inseparable camera behavior. Stillring takes the abstract lesson—separate threat communication from camera ownership—not the exact implementation.

---

## Camera / Targeting System IDE requirements

The workbench must expose enough evidence to prove secondary enemies are **not** silently steering ordinary framing.

At minimum show:
- current primary lock target;
- #11 Relationship Frame requested/resolved pose;
- all nearby targetable secondary enemies;
- each secondary's screen position/on-offscreen classification;
- secondary LOS/occlusion state where useful;
- secondary current AI/combat salience if later systems provide it, explicitly labeled **diagnostic only / no camera authority**;
- camera target list used by the active framing solver;
- explicit assertion that only Neris + current target are ordinary framing subjects;
- current FOV/distance and proof no enemy-count modifier is active;
- target-switch candidate set separately from framing-target set;
- active #5/#6/#7/#8 constraints;
- any future threat indicators/audio-cue state as separate systems when implemented.

The IDE should provide a debug overlay that colors/labels **PRIMARY CAMERA SUBJECT**, **SWITCH CANDIDATE**, and **SECONDARY / NO CAMERA AUTHORITY** distinctly.

### Validation checks
At minimum detect:
- a secondary enemy accidentally added to ordinary group framing;
- camera distance/FOV changing solely due to enemy count;
- camera yaw/pitch contribution sourced from a non-primary enemy;
- hidden threat score influencing framing;
- encounter test case where an offscreen enemy delivers an untelegraphed high-salience attack;
- non-selected candidate retaining framing authority after a target switch.

---

## Representative test matrix

### Crowd count
- 1 locked target + 1 secondary;
- 1 locked target + 2 secondaries;
- 1 locked target + 4+ secondaries;
- enemies enter/leave range repeatedly;
- enemies spawn/despawn at edge/offscreen;
- all secondaries move while primary pair remains still.

Expected: ordinary camera remains the same #11 pair solution unless primary/player/physical constraints change.

### Spatial arrangements
- secondaries all on one side;
- one secondary directly behind camera;
- secondaries surrounding Neris;
- secondary crosses between Neris and primary;
- ranged secondary at screen edge;
- secondary above/below on stairs;
- cramped room with several enemies;
- low ceiling with several enemies.

Expected: no crowd-driven camera steering/zoom/FOV.

### Switching integration
- switch from primary A to secondary B;
- after commit, B becomes sole primary target and A immediately loses camera influence;
- rapid explicit switching across three enemies;
- no switch input while secondaries attack or move aggressively.

Expected: only explicit #12 commitment changes the primary relationship.

### Encounter fairness red-team
- offscreen melee windup;
- offscreen ranged attack;
- two simultaneous high-salience attacks;
- doorway funnel;
- surrounding enemies in narrow arena;
- visually occluded secondary behind hard cover.

Expected: failures are attributed to combat/encounter/threat-communication design, not solved by unauthorized camera motion.

---

## Research basis / design lineage

### Unreal Engine 5.8 primary references
Gameplay Cameras can explicitly work with multiple target actors and actor groups. `UAttachToActorGroupCameraNode` moves toward a weighted actor-group center, while `UBaseFramingCameraNode` supports one or more target actors and framing zones.

References:
- https://dev.epicgames.com/documentation/unreal-engine/API/Plugins/GameplayCameras/UAttachToActorGroupCameraNode
- https://dev.epicgames.com/documentation/unreal-engine/API/Plugins/GameplayCameras/UBaseFramingCameraNode
- https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Plugins/GameplayCameras

These prove group framing is technically available. They do not establish that Stillring should use it for ordinary combat.

### Shipped-game problem study
God of War Ragnarök's official accessibility documentation separates:
- Lock-On Camera options;
- Strafe Assist that can track groups of enemies;
- offscreen enemy indicators;
- directional audio/visual information;
- recenter assists;
- motion-reduction settings.

Reference:
- https://www.playstation.com/en-us/games/god-of-war-ragnarok/accessibility/

The useful abstract lesson is architectural separation: **camera tracking, lock-on, group awareness, offscreen threat communication, and motion accessibility are different tools.** Stillring therefore does not make group tracking an invisible default requirement.

### IP boundary
This decision copies no exact game camera values, threat indicators, lock rules, UI art, timing, or control mapping. It applies `docs/05_IP_GUARDRAILS.md`: study the general player problem and invent Stillring's own expression.

---

## Why this package is approved
This decision strengthens existing authority rather than creating contradictions:
- #11 explicitly defines a two-subject relationship frame;
- #12 explicitly selects one primary target at a time;
- #6 already states encounter design must respect what the player can see;
- #3/#9 protect the player from unnecessary automatic camera steering;
- the System IDE contract requires the system to explain who owns behavior;
- motion/accessibility concerns favor fewer hidden camera drivers.

The cleanest rule is therefore: secondary enemies may affect **combat decisions and threat communication**, but not ordinary camera composition until the player explicitly selects one.

---

## Player-facing acceptance
Decision #13 passes when:
1. adding nearby enemies does not automatically zoom, widen FOV, orbit, raise, or otherwise transform the ordinary lock camera;
2. #11 remains Neris + current target + useful space between them;
3. nearby secondaries can naturally appear in frame without becoming camera subjects;
4. offscreen enemies do not drag the camera;
5. explicit #12 switching is the normal way another enemy becomes primary;
6. previous targets lose camera authority immediately after a switch;
7. crowd fairness is handled by encounter aggression, telegraphs, UI/audio/accessibility systems rather than camera omniscience;
8. the IDE proves only the current target is a primary enemy framing subject;
9. enemy-count changes alone do not produce camera breathing;
10. #14 large-boss framing remains unresolved and separate.

---

## Next decision
**Camera Decision #14 — large-boss framing.**

Research it independently. Do not infer giant-target bounds, camera distance envelopes, body-part anchors, vertical framing, FOV exceptions, arena obligations, or multi-anchor switching from ordinary #11/#13 behavior.