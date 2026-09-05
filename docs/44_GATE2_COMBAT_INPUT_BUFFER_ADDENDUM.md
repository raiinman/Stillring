# 44 — Gate 2 Combat Input Buffer Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Combat Decision #8 for Issue #3. This file defines when a near-future combat input may wait for legality without becoming a stale command queue.

## Authority
Combat Decision #8 is locked under the owner's explicit scheduled-run delegation after a fresh focused research pass.

Buffer principle:
> **Remember near-future intent, not old commands.**

---

## Combat Decision #8 — input buffering — LOCKED

### Buffering exists only across a known near-future legal edge
A combat request may be buffered only when all are true:
- the requested action is not legal **right now**;
- the current authoritative state/action already defines a future transition edge to that requested action;
- the request occurs inside that edge's short authored `BufferWindow` before legality opens;
- no higher-priority state makes the future edge uncertain/invalid.

If an action is illegal because no transition exists, the request is rejected. The game does not store it “just in case.”

### One global pending combat intent
Gate 2 maintains **at most one pending future combat request** per player.

The pending record includes:
- requested semantic action;
- request timestamp/frame;
- source state/action/phase;
- intended transition edge;
- expiration;
- optional direction/target snapshot required by that request;
- replacement/clear reason.

There is no multi-command FIFO and no ability to pre-program an attack-defense sequence.

### Combat #2 Light continuation uses this same one-slot model
The Light chain's already-locked one-slot continuation intent is the Light-specific use of the same global principle.

Implementation must not create:
- one global slot **plus** an extra hidden Light slot;
- separate per-button queues that allow multiple future actions.

When a Light continuation is pending, it occupies the pending combat intent.

### Immediate legality always wins over buffering
If the requested action is legal on the request frame:
- execute/accept it immediately through the authoritative transition path;
- do not put it into a buffer first;
- record `AcceptedImmediate`.

Buffering is only for the short gap before a known legal edge.

### Buffer windows are transition-specific
There is no single genre-wide “all inputs remember for X milliseconds” rule.

Each approved transition may expose a bounded pre-open `BufferWindow`, such as:
- Light continuation;
- post-Recovery Light/Heavy;
- near-release Guard/Evade;
- near-release action after hit recovery/HardStagger;
- other later reviewed transitions.

Exact durations remain human-play tuning. Their semantics are inspectable action/state data.

### Requests too early are rejected, not remembered
If an input occurs before the transition's buffer window:
- reject it with semantic reason `TooEarlyForBuffer` / equivalent;
- do not save it;
- repeated early presses cannot creep expiration toward the future edge.

This is the primary stale-command defense.

### Repeated input never extends expiration
If the same action is pressed again while an identical pending request already exists:
- it does not extend the original expiration indefinitely;
- if the new press falls inside a newly valid later buffer context, it may replace the old record with a fresh valid request only through normal replacement rules;
- otherwise it is recorded as redundant/rejected.

Mashing cannot keep a future action alive forever.

### Replacement policy is explicit and defense-biased
Because only one pending request can exist, replacement is deterministic.

Baseline priority for pending requests:
1. `Evade`
2. `Guard`
3. `Heavy`
4. `Light`

Rules:
- a newly buffer-eligible higher-priority request replaces a lower-priority pending request;
- a lower-priority request does not replace a higher-priority pending request;
- same-priority/new same-action request replaces only when it represents a genuinely new valid buffer opportunity; it cannot extend one expiration indefinitely;
- the replacement is recorded with reason.

This is a **pending-intent safety bias**, not universal transition priority. Once an action has executed/committed, Decision #1 and action-specific rules own cancellation.

### Pending intent executes only if its original edge is still valid
At the moment the intended transition opens, the buffered request is revalidated.

Execution requires:
- source state/action continuity still matches the buffered edge;
- requested action is legal now;
- required target/context is still valid if the action needs one;
- no higher-priority reaction/traversal/death state has taken ownership;
- request has not expired.

If revalidation fails, clear the request with a semantic reason. Never force execution because the input was once accepted into the buffer.

### Forced state changes clear stale requests
Clear pending combat intent when unrelated authoritative ownership changes invalidate its context, including:
- `Interrupt`;
- `HardStagger`;
- Death;
- traversal/scripted ownership;
- forced reset;
- chain reset when pending continuation belongs to that chain;
- target requirement invalidation where the request explicitly required that target/context.

A hit should not knock Neris down and then cause an old attack button to fire after recovery unless a **new** near-release request was made during that reaction's own valid buffer window.

### Reaction states may accept fresh near-release input
Combat #6 rejected ordinary inputs during reactions pending this decision. Combat #8 now allows short buffering near a known reaction-release edge.

Rules:
- early reaction inputs are rejected;
- near release, approved actions may buffer according to that reaction state's explicit edges;
- the request must be made during the current reaction, not inherited from before the hit;
- `HardStagger` can use narrower or later buffer windows than ordinary `Interrupt` if human play requires;
- exact windows remain tuning.

This preserves responsiveness without allowing a button pressed before being hit to execute after the hit.

### Guard buffering enters ordinary Guard only
A buffered Guard request that executes when Guard becomes legal:
- enters ordinary Guard;
- does **not** count its old input timestamp as a Perfect Guard attempt;
- cannot produce Perfect Guard merely because impact happens near the delayed activation.

Combat #7 Perfect Guard requires a fresh legal Guard activation timing read, not an older buffered press.

If Guard is already held in Hold mode when state becomes legal, implementation may treat persistent current hold intent as ordinary Guard entry, but not Perfect Guard.

### Evade buffering starts immunity at action execution, not request time
If a near-release Evade request buffers successfully:
- movement direction/context is resolved according to Evade authority when the Evade actually accepts/starts, using any explicitly captured intent rules;
- Evade immunity begins only at its authoritative action interval;
- the buffer itself provides no immunity.

### Directional/context data is captured intentionally
For requests whose direction matters, the pending request must state whether direction is sampled:
- at request time;
- at action acceptance time;
- or according to that action's own locked rule.

Gate 2 baseline:
- Evade resolves direction at actual Evade acceptance using current valid movement intent/frame, unless the request explicitly stored a stable intended direction because the transition edge requires it;
- attack-facing/target context remains governed by the later facing decision;
- buffer implementation cannot silently use stale camera yaw/target identity without action authority.

### Held inputs do not become invisible infinite buffers
Enhanced Input may report held/ongoing state, but combat state must distinguish:
- a distinct action request;
- a persistent Hold semantic intentionally supported by that action.

Baseline:
- Light/Heavy/Evade require distinct presses and are not auto-buffered continuously by holding;
- Guard Hold may represent persistent intent to guard when legal, but still follows Guard state legality and cannot create Perfect Guard timing automatically;
- OS key repeat/device repeat must not generate unintended semantic presses.

### Buffered request is not a cancel permission
A buffered Evade/Guard/attack request does not create a transition edge.

It can execute only when the source state's already-approved transition becomes legal.

Therefore:
- buffering Evade during Heavy Active cannot cancel Heavy if Heavy has no Evade edge there;
- buffering Guard during Light Startup cannot bypass attack commitment;
- buffering Heavy cannot create Light→Heavy chain authority that does not exist.

### Buffer expiration is visible and deterministic
Every buffered request has a defined expiration tied to the intended edge/window.

- expiration does not depend on animation clip ending;
- expiration is simulation-time/state authority;
- hitstop/time scaling treatment must be explicit and consistent with action timing;
- frame rate cannot change whether the same timestamped request is accepted.

### Paused/menu/non-gameplay input does not buffer combat actions
Combat buffering is active only when the authoritative player gameplay state accepts combat input evaluation.

Opening menus/pausing does not queue future attacks/evades to fire upon resume unless a future explicit feature says otherwise.

---

## Accessibility

Buffering itself is a responsiveness/accessibility aid when bounded.

Requirements:
- a user-facing **Combat Input Timing** profile must support at least `Standard` and `Extended`;
- `Extended` modestly widens approved pre-open BufferWindows but does not add transition edges, additional queue slots, automatic actions, post-expiration execution, Perfect Guard automation, or state immunity;
- exact window ranges require human play/accessibility tuning;
- remapping remains action-semantic;
- no mechanic requires rapid mashing to make buffering work.

This gives players more timing forgiveness without rewriting combat rules.

---

## Combat System IDE requirements

### Inspect
Expose:
- most recent semantic input request;
- immediate/buffered/rejected classification;
- pending slot empty/filled;
- pending action;
- source state/action/phase;
- intended transition edge;
- buffer-window open/close;
- request timestamp and expiration;
- timing profile Standard/Extended;
- replacement priority/result;
- revalidation result;
- clear/consume reason;
- target/direction context captured;
- current Enhanced Input raw/semantic event separately.

### Tune
Prototype values:
- per-transition Standard BufferWindow;
- corresponding Extended profile widths;
- reaction-release buffer windows;
- no queue-depth tuning: depth is locked at one.

### Exercise
Scenarios:
- press each action far too early / just before window / at edge / after open;
- spam identical input;
- buffer Light then request Evade;
- buffer Evade then request Light;
- same-priority replacement;
- get interrupted with pending Light;
- make a new request near reaction release;
- target invalidates before buffered edge;
- buffered Guard then incoming Perfect-Guard-timed hit;
- Hold Guard across release;
- Standard/Extended comparison.

### Validate
Detect:
- more than one pending request;
- separate hidden Light/global queues;
- early illegal action stored outside approved window;
- mashing extending expiration indefinitely;
- pending request surviving unrelated Interrupt/HardStagger/Death/traversal;
- stale target/camera context used without action authority;
- buffered Guard generating Perfect Guard from old timestamp;
- buffer granting Evade immunity before action starts;
- held Light/Heavy/Evade auto-repeating;
- queue creating transition edge not present in combat graph;
- frame-rate-dependent acceptance;
- menu/pause input firing combat action on resume.

### Capture
Record semantic inputs, source state, buffer window state, acceptance classification, pending replacements, expiration, forced clears, revalidation, action execution, direction/target snapshots, and timing profile.

---

## Representative tests

1. Far-early Light/Heavy/Guard/Evade is rejected.
2. Near-edge legal future requests buffer once.
3. Immediate legal requests execute immediately.
4. Only one pending request can exist.
5. Higher-priority defensive request can replace lower pending offense; lower offense cannot displace buffered defense.
6. Repeated presses cannot extend expiration forever.
7. Interrupt clears prior attack continuation; a fresh near-release request can buffer independently.
8. Buffered Guard produces ordinary Guard only, never retroactive Perfect Guard.
9. Buffered Evade has no immunity until Evade starts.
10. Invalid target/context clears instead of forcing stale execution.
11. Hold Guard can persist as guard intent without turning every frame into a new request.
12. Standard/Extended profiles change bounded timing only.
13. 30/60/120+ FPS and altered animation playback produce the same timestamped decisions.

---

## Research basis / design lineage

Epic's Unreal Engine 5.8 Enhanced Input represents logical `InputAction`s and trigger states separately from gameplay legality. Its combo trigger also exposes explicit completion/cancellation states and a time-to-press concept. Gameplay Ability tasks can wait for later presses. These demonstrate that short, explicit intent windows are technically straightforward, but they do not define Stillring policy.

Former *God of War* combat designer Eric Williams described both buffered and instant cancel handling as tools for responsiveness, with explicit timing ranges per transition rather than one opaque queue. Stillring keeps the abstract lesson—near-window intent can be remembered—but drastically limits queue depth and stale persistence.

No exact timing, branch data, queue behavior, control layout, or proprietary implementation is copied.

---

## Why this package is approved
Combat #8 makes controls forgiving without making them predictive. A legal future edge can hear a slightly early input; the game will not execute commands from an old state after the world has changed.

---

## Player-facing acceptance
Combat #8 passes when:
1. buffering exists only near a known future legal edge;
2. at most one global future combat request is pending;
3. Light continuation uses that same one-slot principle;
4. immediate legal inputs execute immediately;
5. too-early inputs are rejected rather than remembered;
6. repeated input cannot extend expiration indefinitely;
7. replacement is deterministic and defense-biased while pending;
8. forced ownership changes clear stale requests;
9. reaction states may accept fresh near-release inputs only inside their own buffer windows;
10. buffered Guard cannot earn Perfect Guard from an old press;
11. buffered Evade grants no pre-action immunity;
12. buffering never creates a cancel/transition edge;
13. Standard/Extended timing profiles alter only bounded pre-open forgiveness;
14. IDE can explain pending intent, replacement, expiration, revalidation, consume/clear reason;
15. all outcomes remain deterministic across frame rate/animation changes.

---

## Next combat decision
**Combat Decision #9 — attack-facing / rotation assistance.**

Research independently before approval. Define how much Light and Heavy may rotate toward player intent/target during Startup, whether assistance uses target lock or input direction, how unlocked attacks face, what happens when target changes between Light entries, hard caps that prevent vacuum/spin, and how movement/translation remains player/world honest.