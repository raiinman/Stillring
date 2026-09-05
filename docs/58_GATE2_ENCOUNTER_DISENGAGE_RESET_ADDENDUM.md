# 58 — Gate 2 Encounter Disengage / Reset / Re-entry Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Enemy / Encounter Decision #9 for GitHub Issue #104. Defines when an active encounter stops pursuing Neris, how enemies leave combat and return to authored territory, what state may reset, and how repeated leave/re-enter behavior avoids leash exploits.

## Authority
Locked under the owner's scheduled-run delegation after a fresh focused research pass.

Disengage principle:
> **An encounter ends because the fight is no longer credible—not because Neris crossed an invisible circle.**

---

## Decision #9 — disengage / reset / leash / re-entry — LOCKED

### 1. No single magic leash radius
Stillring does not use one distance threshold as the complete combat-disengage rule.

Distance may contribute, but the encounter evaluates a semantic **Engagement Viability** state using honest evidence such as:
- authored encounter territory / connected combat space;
- whether a legal navigable pursuit route remains;
- recent meaningful perception/contact evidence;
- time since any enemy had a credible attack/approach opportunity;
- whether Neris entered an explicitly non-combat-owned traversal/world state;
- whether all living encounter enemies can no longer participate meaningfully.

Exact thresholds remain tuning.

### 2. Engagement states
Baseline encounter lifecycle:
1. **Dormant / Ready** — encounter not actively fighting Neris;
2. **Engaged** — normal attack-bandwidth/pressure rules active;
3. **Disengaging** — no new offensive commitments; unresolved honest danger cleans up;
4. **Returning** — enemies move toward authored fallback/home state without attacking Neris;
5. **Reset-Ready** — encounter has reached its approved post-disengage stable state;
6. **Re-engaged** — Neris creates a new valid engagement before/after reset-ready.

Exact implementation names may differ; semantics are locked.

### 3. Disengage requires sustained loss of a credible fight
A momentary LOS break, camera turn, dodge behind a pillar, target-lock loss, or one failed path query does **not** end combat.

Disengage begins only after the encounter has sustained evidence that continued pursuit is no longer a credible authored fight.

This avoids boundary flicker and pillar cheese.

### 4. Authored encounter territory is a soft ownership boundary, not a damage wall
Encounters may define an authored territory / pursuit envelope representing where that group legitimately operates.

Crossing its edge does not instantly:
- cancel active attacks;
- refill health;
- teleport enemies home;
- make enemies invulnerable;
- erase projectiles.

Instead, being materially outside supported territory contributes strongly to Engagement Viability and may cause transition to Disengaging.

### 5. Connected-space reachability matters
If Neris is outside the encounter's practical connected combat space and enemies cannot find a legal authored pursuit path for a sustained interval, the encounter may disengage.

Navigation failure is evidence, not sole authority:
- one temporary path failure does not reset the encounter;
- partial paths do not authorize attacks across gaps/walls;
- enemies do not teleport to preserve pursuit;
- inaccessible traversal states may trigger disengage if the encounter has no authored answer.

### 6. AI memory does not equal indefinite combat
An enemy may still remember Neris's last known location after direct perception is lost.

That memory can support:
- short investigation/reposition behavior;
- return toward last credible contact;
- maintaining engagement briefly while LOS is reacquired.

It cannot keep the encounter hostile forever after the player has clearly left the fight.

### 7. Disengaging stops new commit grants
Once the encounter enters `Disengaging`:
- no new MajorCommit or PressureCommit is granted;
- enemies stop beginning fresh committed Telegraphs;
- new offscreen threat indicators are not created from mere pursuit/readiness;
- occupancy reservations transition toward return/fallback use.

### 8. Already-committed honest attacks resolve causally
If an attack was already committed before disengage begins:
- it may finish only where doing so remains physically/world-causally valid and does not become a long-distance pursuit attack;
- unlaunched attacks may be canceled through an explicit visible disengage interruption when continuing would be nonsensical;
- already-launched projectiles remain real under #3/#6 and collide normally;
- stale hit volumes/telegraphs are cleaned when the action is terminated.

No invisible 'all bullets disappear at leash' rule.

### 9. Returning enemies do not attack
During `Returning`:
- enemies do not request/receive new attack commits;
- they may navigate around real obstacles;
- they preserve collision/world honesty;
- they may use a readable non-urgent return/guard presentation;
- they do not sprint backward invulnerably while still damaging Neris.

### 10. Returning enemies are not automatically invulnerable
Neris may still hit a returning enemy where physically reachable unless an explicit world-state transition has already removed that actor.

However, hitting a returning enemy is a valid **re-engagement signal** if the encounter can still support combat there.

The system must not create an exploit where enemies become free punching bags while refusing to defend indefinitely.

### 11. Re-engagement during return is supported
If Neris re-establishes a credible fight while enemies are Disengaging/Returning:
- the encounter may transition back to Engaged;
- no duplicate enemy instance is spawned;
- current real health/state remains authoritative unless a completed reset already occurred;
- attack bandwidth restarts through normal permission, not instant retaliation;
- the player receives ordinary telegraph/readability standards.

### 12. Health does not instantly refill at disengage
Baseline Gate 2 rule:
- enemy health remains as actually earned while the encounter is Disengaging/Returning;
- no one-frame full heal occurs at a leash boundary.

When the encounter reaches a completed authored reset, health may restore according to the encounter's reset policy in Decision #10/checkpoint authority.

This prevents obvious pull-hit-retreat healing weirdness and keeps re-entry causal.

### 13. Completed reset may restore canonical encounter state
After enemies reach their stable reset/home state and the encounter formally completes reset:
- transient combat state is cleared;
- attack/reaction/occupancy reservations are cleared;
- enemies return to the approved starting/fallback state;
- health/resources may restore to the encounter fixture/canonical start values;
- dead enemies do **not** silently respawn unless Decision #10/checkpoint/world-state authority says the encounter resets them.

Decision #9 does not define persistence/respawn timing beyond this boundary.

### 14. Dead enemies do not walk home or revive because aggro dropped
Death remains real during the current encounter lifecycle.

A dead enemy:
- is removed from active roster/commit scheduling;
- does not enter Return;
- does not regain health because surviving allies disengaged;
- only returns through an explicit later spawn/reset authority.

### 15. No leash-edge farming
The encounter must resist repeated boundary exploitation.

Invalid behavior:
- Neris steps across a line, enemies instantly turn around;
- Neris steps back, they immediately resume with no transition;
- repeat to land free back attacks forever.

Mitigation is semantic hysteresis:
- sustained evidence required to enter Disengaging;
- a return-state re-engagement has a clear transition;
- enemies may reorient/defend during re-engagement before becoming attack-ready;
- no immediate health refill gives the player a binary heal-line exploit;
- exact timings remain human-play tuning.

### 16. No infinite cross-map pursuit
Enemies should not chase Neris indefinitely through regions unrelated to their encounter merely because pathfinding remains technically possible.

Authored ownership/territory remains a legitimate strong disengage input.

This protects:
- encounter pacing;
- NPC/story spaces;
- traversal/puzzle areas;
- performance and world simulation assumptions;
- authored enemy identity.

### 17. No magical teleport-home baseline
Returning enemies should physically return through legal world navigation when reasonably possible.

Teleport/despawn relocation is allowed only when:
- the actor is safely outside meaningful player observation/interaction;
- physical return would be excessively long or impossible;
- the encounter/reset contract explicitly owns the transition;
- no active projectile/threat or player interaction is being invalidated;
- the IDE records the relocation reason.

### 18. World-state/traversal ownership can force disengage
If Neris enters a state where the encounter cannot legally continue—e.g. an authored transition, cinematic/world-layer change, long traversal, checkpoint reset—the higher-level world system may request encounter disengage/cleanup.

It must use the same explicit cleanup contract rather than simply deleting combat actors mid-hit.

### 19. Player death is separate high-priority cleanup
On Neris Death:
- no new enemy commits are issued;
- active threats clean according to death authority;
- enemies transition to the death/retry/reset integration path;
- Decision #10 owns the final fixture/checkpoint restoration behavior.

### 20. Difficulty does not change the world boundary unfairly
Difficulty may tune pursuit persistence within reviewed bounds, but cannot:
- grant enemies cross-region pursuit to surprise the player;
- allow attacks through inaccessible geometry;
- remove disengage hysteresis to create boundary flicker;
- heal enemies instantly at the leash line.

---

## Unreal Engine 5.8 implementation boundary

Current engine systems provide useful evidence/execution primitives:
- AI Perception can retain or forget stale perceived actors based on stimulus aging/system settings;
- navigation/path-following can pursue moving actors, return failure/partial-path behavior, and determine reachable routes;
- Behavior Trees/StateTree/native C++ can execute explicit engagement-state transitions.

None defines Stillring's disengage policy.

Recommended authority split:
- **Encounter coordinator:** Engagement Viability and lifecycle state;
- **authored encounter data:** territory/fallback/home semantics;
- **AI perception:** current/recent sensory evidence only;
- **navigation:** reachability/path evidence and return movement;
- **enemy local AI:** executes investigation/return/re-engage behavior;
- **world/checkpoint system:** requests explicit higher-level reset where authorized;
- **Combat/Encounter IDE:** explains exactly why engagement was retained/lost/restored.

---

## Accessibility / readability boundary

Requirements:
- disengage/return should be visually understandable without relying only on audio;
- enemies should not look like they are still committed to attack while gameplay has disabled all threat;
- re-engagement must use normal attack telegraph floors;
- no camera movement communicates leash state;
- no color-only indicator is required to understand whether the enemy is returning.

---

## Combat / Encounter IDE requirements

### Inspect
Expose:
- encounter lifecycle state;
- authored territory/fallback/home reference;
- current distance/path/connected-space evidence;
- current and remembered perception timestamps;
- last credible attack/approach opportunity;
- Engagement Viability inputs and exact transition reason;
- active commit/projectile state;
- per-enemy return target/path result;
- health/reaction state retained during return;
- reset-ready/completed status;
- last re-engagement reason;
- higher-level world/checkpoint reset request.

### Tune
With provenance:
- disengage grace/hysteresis windows;
- authored pursuit territory margins;
- investigation/return timing;
- re-engagement transition timing;
- safe relocation conditions where approved.

No tune control may create instant heal-at-radius or cross-wall pursuit.

### Exercise
Fixtures:
- run just outside territory then return immediately;
- remain outside territory long enough to disengage;
- break LOS behind pillar then reacquire;
- reach an inaccessible ledge;
- leave through valid long corridor;
- attack a returning enemy;
- re-enter before return completes;
- kill one enemy then disengage survivors;
- projectile in flight during disengage;
- navigation route home blocked dynamically;
- player death mid-MajorCommit;
- world transition requests cleanup;
- repeated boundary crossing stress test.

### Validate
Detect:
- one-frame radius-line disengage;
- new committed attack starting after Disengaging;
- returning enemy attacking;
- instant heal before completed reset;
- dead enemy revived by aggro loss;
- projectile erased only because leash changed;
- enemy pursuing indefinitely outside authored territory;
- teleport-home while player can meaningfully observe/interact;
- stale commit/occupancy/reaction after reset-ready;
- repeated edge exploit producing free attack loop;
- target lock used as engagement authority;
- path failure alone causing immediate reset.

### Capture
Record engagement timeline:
- perception/LOS/path evidence;
- territory state;
- lifecycle transitions/reasons;
- commit cleanup;
- projectile persistence;
- health/reaction retention;
- return path/arrival;
- re-engagement events;
- reset completion;
- player position/inputs;
- frame/time stamps.

A designer must be able to answer:
> **Why did this encounter stop chasing me here, and exactly what did it reset?**

---

## Representative red-team tests

1. Step across territory boundary for one second: encounter stays engaged; no instant turn/heal.
2. Leave far enough through valid route, remain absent: encounter visibly disengages and returns.
3. Duck behind cover briefly: no aggro reset from momentary LOS loss.
4. Reach inaccessible geometry: after sustained inability to maintain credible fight, disengage rather than wall-running/path spam.
5. On-screen committed attack then run across boundary: action remains causal or visibly aborts under explicit cleanup; no silent snap.
6. Projectile launched before disengage: projectile remains physical.
7. Hit returning enemy: valid re-engagement when combat space supports it; no free punching-bag loop.
8. Kill one of three enemies, disengage: dead member does not revive merely because survivors return.
9. Re-enter before full reset: surviving enemies keep real current health/state and re-engage through normal readiness.
10. Complete authored reset: transient state clears; any health/respawn restoration happens only through approved reset authority.
11. Repeatedly straddle boundary: hysteresis prevents leash farming.
12. Path home becomes blocked: no teleport in front of player; IDE explains fallback/relocation decision.
13. Target-lock loss/gain: no direct effect on engagement ownership.
14. Player death: new commits stop and reset integration proceeds deterministically.

---

## Research basis

### Current primary engine references
- Epic Games, Unreal Engine 5.8, **AI System Settings** — `Forget Stale Actors` controls whether expired perception stimuli are forgotten. This is an implementation memory mechanism, not a combat-disengage rule.  
  https://dev.epicgames.com/documentation/unreal-engine/ai-system-settings-in-the-unreal-engine-project-settings
- Epic Games, Unreal Engine 5.8, **AIController MoveToActor / Move To Location** — AI path-following can continuously pursue moving goals and may allow partial paths. Stillring uses navigation as reachability evidence/execution rather than letting a path API define encounter ownership.  
  https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/AIModule/AAIController/MoveToActor  
  https://dev.epicgames.com/documentation/unreal-engine/BlueprintAPI/AI/Navigation/MovetoLocation
- Epic Games, Unreal Engine 5.8, **StateTree selectors/debugging** — explicit states/transitions are available implementation tools and can be inspected/debugged; Stillring's semantic lifecycle remains gameplay authority.  
  https://dev.epicgames.com/documentation/unreal-engine/statetree-debugger-quick-start-guide

### IP boundary
No chase radius, reset duration, home position logic, respawn timing, AI state names, or exploit mitigation values are copied from another game. This contract derives from Stillring's world-honesty and player-control principles.

---

## Why this package is approved
The model makes disengagement causal rather than videogame-magical:
- temporary LOS/path noise does not reset fights;
- encounters do not chase across the whole world;
- no instant leash-line heal/invulnerability/turnaround;
- already-launched physical danger remains real;
- re-entry uses the same combat rules instead of spawning a duplicate state;
- dead enemies remain dead until actual reset authority says otherwise;
- the IDE explains every transition and reset fact.

---

## Player-facing acceptance
Decision #9 passes when:
1. leaving a fight does not reveal an obvious one-step aggro radius exploit;
2. brief LOS/path loss does not reset combat;
3. enemies eventually stop pursuing when the fight is genuinely no longer credible/authored;
4. return behavior is readable and non-offensive;
5. health does not instantly refill at disengage;
6. dead enemies do not revive from aggro loss;
7. re-engagement before completed reset preserves causal current state;
8. projectiles/committed danger are cleaned honestly;
9. no cross-map pursuit or magical visible teleport-home occurs;
10. the IDE explains exactly why/how an encounter disengaged and reset.

---

## Next decision
**Enemy / Encounter Decision #10 — encounter spawn/reset/debug fixture contract + cumulative Gate 2 enemy/encounter closure.**

Research independently before approval. Define fixture identity, spawn/reset determinism, checkpoint/death integration boundary, IDE controls, validation, and cumulative acceptance without inventing production wave scripting.