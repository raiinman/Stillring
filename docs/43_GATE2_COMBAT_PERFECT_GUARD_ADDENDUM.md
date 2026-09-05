# 43 — Gate 2 Combat Perfect Guard Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Combat Decision #7 for Issue #3. This file decides whether Stillring retains a precision-timed defensive layer above ordinary Guard and defines its player-facing semantics.

## Authority
Combat Decision #7 is locked under the owner's explicit scheduled-run delegation after a fresh focused research pass.

Combat #4 already makes ordinary Guard viable. Perfect Guard therefore exists to reward a deliberate read with **tempo**, not to make ordinary blocking obsolete.

Perfect-Guard principle:
> **Read the hit, meet it cleanly, keep your turn.**

---

## Combat Decision #7 — Perfect Guard — LOCKED

### Perfect Guard is retained
Stillring keeps a precision Guard result because it creates a distinct skill expression that ordinary Guard and Evade do not:
- ordinary Guard trades freedom for reliable frontal defense;
- Evade trades position for brief timing forgiveness;
- Perfect Guard risks later defensive timing to preserve or gain combat tempo.

It is a layer on ordinary Guard, not a replacement defense.

### Same Guard action; no separate parry button
Perfect Guard uses the same remappable `Guard` action.

A Perfect Guard attempt occurs when:
- Guard is newly activated from a legal non-Guard state;
- coverage/facing rules from Combat #4 are satisfied;
- an eligible incoming hit contacts during the authored Perfect Guard timing window.

No extra button, stick click, QTE, or attack+guard chord is required.

Hold and Toggle Guard input modes remain gameplay-equivalent: the activation press that turns Guard on is the timing event.

### Timing is pre-contact and authoritative
The Perfect Guard window is a short interval based on authoritative Guard activation/contact timing.

- the player must activate Guard shortly **before** contact;
- pressing after the hit has resolved cannot retroactively parry it;
- exact milliseconds remain human-play tuning;
- the window is gameplay state/data, not simply a montage notify;
- animation replacement/playback changes cannot silently widen/narrow it.

### Holding Guard early yields ordinary Guard
If Guard is already stably active well before contact:
- a valid frontal Guardable hit resolves as ordinary Guard;
- the player does not receive Perfect Guard merely because the shield is up;
- no button pumping is needed to keep ordinary Guard viable.

This preserves the difference between safety and timing skill.

### Eligibility is explicit and separate from ordinary Guardability
Incoming attacks expose Perfect Guard eligibility explicitly.

Gate 2 baseline:
- ordinary `Guardable` direct melee/projectile attacks are normally `PerfectGuardEligible`;
- attacks authored `Unblockable` under Combat #4 are **not** automatically Perfect-Guardable;
- exceptional future attacks may define separate behavior only through explicit data/authority.

Visual telegraphs may communicate eligibility but are not implementation authority.

### Perfect Guard preserves HP and skips ordinary Guard Reaction
A successful Perfect Guard:
- prevents that eligible hit's normal direct HP damage, like ordinary Guard;
- does **not** enter the ordinary Guard Reaction delay;
- resolves into a short `PerfectGuardAdvantage` state/window in which Neris regains player action authority promptly;
- gives clear audio/visual feedback that remains readable with camera shake/haptics disabled.

The principal reward is **tempo**, not a canned retaliation.

### PerfectGuardAdvantage does not auto-attack
During/after a successful Perfect Guard:
- no automatic counterattack occurs;
- no canned finisher occurs;
- no lock-on target is silently changed;
- the player may choose a legal next action when the advantage release permits it;
- Light, Heavy, Evade, Guard, or movement remain player choices subject to their own legality.

The system rewards the read without playing the game for the player.

### No generic attacker stun is required for baseline authority
Combat #7 does not assume every Perfect Guard hard-staggers the attacker.

A representative enemy may later expose a short authored deflect/recoil response for readability, but enemy reaction severity belongs to enemy/combat interaction authority and cannot be inferred from the player's Perfect Guard alone.

The player-side guaranteed reward is avoiding ordinary Guard Reaction and preserving tempo.

### No generic projectile reflection
Perfect Guard can successfully defend against an eligible projectile without ordinary Guard Reaction, but it does not automatically reflect the projectile back to its source.

Projectile reflection/redirect is a separate weapon/tool/attack mechanic if later proposed.

### No slow motion dependency
Perfect Guard does not require:
- gameplay slowdown;
- freeze-frame longer than ordinary optional hitstop feedback;
- camera punch/zoom;
- QTE prompt.

Presentation may emphasize success, but core timing and follow-up remain understandable with motion-reduction settings and camera shake Off.

### Failed timing falls back honestly
If the player activates Guard too early but coverage remains valid at contact:
- the hit becomes ordinary Guard.

If Guard activation is too late and coverage is not active before contact:
- the hit resolves through Combat #6's unguarded hit hierarchy.

There is no hidden leniency that converts a post-hit press into success.

### Perfect Guard cannot erase committed attacks
Combat #1 remains authoritative.

Guard activation is only available from source states that explicitly allow Guard. Therefore Perfect Guard cannot be used as a universal cancel from Light/Heavy Startup/Active.

A later source-action `DefensiveCancelWindow` may permit Guard; if Guard is legally activated there, the normal Perfect Guard timing rules may apply. The timing layer does not create the transition edge itself.

### Guard Reaction cannot Perfect Guard
While ordinary Guard Reaction owns Neris:
- new Guard activation is not rearmed;
- incoming hits resolve under Guard/reaction/retrigger authority;
- repeated tapping cannot fish Perfect Guard windows through a block reaction.

### Fresh activation / rearm rule
A Perfect Guard attempt requires a **fresh Guard activation** after Guard has fully returned to an inactive/rearmed state.

- repeatedly pressing while Guard is already Active creates no new Perfect Guard windows;
- releasing/toggling off must complete authoritative Guard exit before a new activation can arm another window;
- exact exit/rearm timing remains tuning but cannot be zero-frame spam by accidental input event repetition;
- animation lowering/raising speed does not own the rearm.

### Perfect Guard has no stamina/posture cost
Combat #7 adds no resource meter and no per-attempt stamina cost.

Its cost is timing risk:
- early = ordinary Guard and Guard Reaction if hit;
- late = unguarded hit;
- correct = tempo preservation.

This is sufficient for the Gate 2 baseline before any combat-resource decision.

### Multiple-hit attacks resolve each contact independently
A Perfect Guard succeeds on the contact whose timing window was met.

It does not create blanket invulnerability for the remainder of a multi-hit sequence.

Subsequent contacts:
- require ordinary Guard coverage or a newly legal/rearmed defensive action;
- may hit during follow-up action depending on state;
- are not automatically Perfect Guarded.

### Target lock/camera remain separate
Perfect Guard uses Neris's Guard-facing coverage, not camera yaw or target identity magic.

- attacks from outside the defended sector are not Perfect Guarded;
- target switching does not retroactively turn the body toward a hit;
- the camera may provide feedback but never decides success.

---

## Accessibility

Perfect Guard is optional skill expression; ordinary Guard remains viable without precision timing.

Requirements:
- no required rapid repetition;
- Guard remains fully remappable;
- Hold/Toggle modes have identical timing semantics at activation;
- a **Perfect Guard Timing Assist** setting must be supported with at least `Standard` and `Extended` timing profiles;
- `Extended` widens only the pre-contact success window within bounded reviewed limits;
- it does not expand Guard arc, make Unblockable attacks eligible, add post-hit success, change damage, auto-counter, or disable world collision;
- exact Standard/Extended window values require human play/accessibility tuning.

This keeps the precision mechanic usable without turning accessibility into invisible autopilot.

---

## Combat System IDE requirements

### Inspect
Expose:
- Guard activation timestamp/frame;
- FreshGuardActivation / rearm state;
- Perfect Guard window start/end;
- timing-assist profile;
- incoming hit contact time;
- Guard/PerfectGuard eligibility;
- coverage direction/arc result;
- classification: `PerfectGuard`, `OrdinaryGuard`, `TooLate/Unguarded`, `Ineligible`, `OutsideArc`;
- damage result;
- Guard Reaction skipped/entered;
- PerfectGuardAdvantage state/release;
- current animation separately.

### Tune
Prototype values:
- Standard timing window;
- Extended timing window;
- Guard exit/rearm timing;
- PerfectGuardAdvantage duration/release;
- presentation-only feedback values.

### Exercise
Scenarios:
- guard far early / just early / exact / just late / clearly late;
- Hold versus Toggle;
- eligible versus Unblockable hit;
- frontal/sector-edge/flank contact;
- multi-hit sequence;
- projectile contact;
- Guard Reaction spam attempt;
- repeated Guard on/off fishing;
- attack Recovery → legally allowed Guard timing when future windows exist;
- Standard/Extended assist comparisons.

### Validate
Detect:
- Perfect Guard from an already-held stable Guard;
- post-hit retroactive success;
- animation notify as sole timing authority;
- repeated button events arming overlapping windows;
- Unblockable attacks Perfect Guarded without explicit authority;
- generic projectile reflection;
- automatic counterattack;
- ordinary Guard becoming nonviable because Perfect Guard is required;
- timing-assist changing arc/damage/eligibility;
- frame-rate-dependent success.

### Capture
Record input activation, rearm, timing window, contact, eligibility, coverage, result, damage, reaction/advantage state, follow-up request, and animation markers.

---

## Representative tests

1. Early Guard produces ordinary block, not Perfect Guard.
2. Standard-window activation produces Perfect Guard.
3. Late activation produces an unguarded hit when coverage was not active.
4. Holding Guard across several hits never repeatedly Perfect Guards.
5. Releasing/rearming creates a new future opportunity only after legal exit.
6. Multi-hit contacts do not inherit blanket success from the first Perfect Guard.
7. Side/rear hits fail coverage even with perfect timing.
8. Unblockable attacks remain unaffected unless separately authored later.
9. Perfect Guard skips ordinary Guard Reaction and returns player tempo promptly.
10. No automatic attack/stun/reflection/slow motion is required.
11. Standard/Extended timing profiles change only bounded pre-contact forgiveness.
12. 30/60/120+ FPS and altered animation playback produce identical authoritative timing outcomes.

---

## Research basis / design lineage

Nintendo's official *Tears of the Kingdom* combat guidance describes Perfect Guard as activating shield defense immediately before impact and creating a counter opportunity. PlayStation's official *God of War Ragnarök* guide likewise distinguishes ordinary held blocking from precisely timed parry outcomes. The common abstract design lesson is valuable: a reliable basic guard can coexist with a higher-skill timing reward.

Stillring's expression is deliberately its own:
- same semantic Guard action;
- front-sector authority inherited from Combat #4;
- tempo-preservation reward rather than guaranteed attacker stun;
- no generic projectile reflection;
- no required slow motion;
- explicit accessibility timing profile;
- no copied timing/control/presentation values.

---

## Why this package is approved
Perfect Guard adds depth without making defense brittle. Ordinary Guard remains the dependable choice; Evade remains the repositioning choice; Perfect Guard is the deliberate tempo choice.

---

## Player-facing acceptance
Combat #7 passes when:
1. ordinary Guard remains fully viable without Perfect Guard;
2. one fresh Guard activation shortly before eligible frontal contact can Perfect Guard;
3. early input falls back to ordinary Guard and late input can fail honestly;
4. successful Perfect Guard prevents normal direct HP damage and skips ordinary Guard Reaction;
5. player regains action tempo through an explicit PerfectGuardAdvantage release rather than an automatic counter;
6. no universal attacker stun, projectile reflection, slow motion, or resource cost is assumed;
7. holding Guard or button-spamming cannot generate repeated fresh timing windows;
8. Unblockable and outside-arc attacks remain honest;
9. multi-hit contacts resolve independently;
10. Standard/Extended timing profiles alter only bounded pre-contact forgiveness;
11. Combat IDE can explain every attempt and classification;
12. timing remains gameplay authority independent of animation.

---

## Next combat decision
**Combat Decision #8 — input buffering rules.**

Research independently before approval. Define which near-window player requests may wait, maximum queue depth, replacement/priority, expiration, state-change cleanup, whether defense and offense use different windows, and how buffering can improve responsiveness without executing stale commands.