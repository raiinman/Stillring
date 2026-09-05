# 38 — Gate 2 Combat Light Attack Chain Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Combat Decision #2 for Issue #3. This file defines the representative Gate 2 light-attack chain semantics after Decision #1 locked attack commitment/cancel grammar.

## Authority
Combat Decision #2 is locked under the owner's explicit scheduled-run delegation after a fresh focused research pass.

This decision answers:
- what one Light Attack press means;
- how many light entries the representative Gate 2 prototype tests;
- when a continuation can be requested;
- how much continuation intent may wait;
- what happens when the player stops pressing;
- how chain state interacts with movement/target changes without rewriting the current committed attack.

It does **not** yet define heavy/committed attack semantics, guard/evade cancels, final global input-buffer durations, hit-reaction priority, combat resources, or final weapon roster.

Combat principle:
> **Commit to the meaningful decision, not to decorative dead time.**

Light-chain principle:
> **One press, one strike, one next decision.**

---

## Combat Decision #2 — light attack chain semantics — LOCKED

### Representative Gate 2 chain
The representative Gate 2 light attack uses a **three-entry authored chain**:

- `Light_1`
- `Light_2`
- `Light_3`

This three-entry count is **Gate 2 prototype authority for the representative baseline combat style**, not a universal rule that every future weapon/tool/combat style must have exactly three attacks.

Any future combat style with a different chain depth must define that depth explicitly under its own action data/design authority. It may not inherit “3” merely because Gate 2 used it.

### One press means one attack entry
A distinct Light Attack press requests **one** light-chain entry.

- pressing Light once starts `Light_1` when legal;
- the game does not automatically continue to `Light_2`/`Light_3` because the button remains held;
- held input is not auto-repeat combo authority;
- one press cannot schedule multiple future strikes;
- every continuation beyond the current attack requires another distinct player request.

This keeps the chain player-authored rather than an automatic combo movie.

### Chain entry identity is authoritative gameplay state
When an entry is accepted, combat state records:
- current chain entry ID/index;
- its Startup / Active / Recovery phase from Decision #1;
- whether the chain may still continue;
- current one-slot continuation intent, if any;
- next eligible light entry;
- chain expiration/reset state.

Animation/Montage sections may present the entries but may not decide which chain index the player is in.

### The chain is linear in the Gate 2 baseline
The representative prototype path is:

```text
Free -> Light_1 -> Light_2 -> Light_3 -> Free
```

Decision #2 does not add branching light finishers, directional variants, pause combos, aerial chains, weapon stance branches, or context-sensitive hidden replacements.

Those would be separate future combat-style/tool decisions.

A linear baseline is deliberately chosen so Gate 2 can prove commitment, continuation timing, target/facing behavior, hit reactions, defense, and buffering without a move-list tree obscuring the state model.

### Continuation is explicit, not automatic
Each light entry defines an authored **Light Continuation Window** during which a valid pending Light continuation may promote into the next entry.

Semantic rules:
- a continuation never begins before the current action contract permits it;
- entering the continuation window does not automatically continue the chain;
- if no Light continuation request exists, the current attack completes Recovery and returns toward free combat/locomotion state;
- if a valid request exists, the next entry starts through an explicit Decision #1 transition edge;
- `Light_3` has no baseline light continuation edge and resolves to Recovery/free state.

Exact timing of each window remains prototype tuning.

### One-slot continuation intent
The light chain may store **at most one pending Light continuation request**.

This is not a general command queue.

- one valid continuation request fills the slot;
- repeated Light presses while the slot is already filled do not enqueue `Light_3`, `Light_4`, etc.;
- repeated presses do not extend the pending request forever;
- the pending request is consumed once when its next legal chain transition occurs;
- after consumption, the new entry may later accept one fresh continuation request for its own next entry;
- if the chain ends/resets/is interrupted, the pending continuation is cleared unless later authority explicitly says otherwise.

This ensures mashing cannot pre-program several future attacks.

### Short pre-window forgiveness is allowed for light continuation
For responsiveness, the baseline light chain may accept a Light continuation request **slightly before** the formal transition window and hold it in the one-slot continuation intent.

Requirements:
- the early-accept region is short and explicitly authored/tunable;
- it exists only to forgive a near-window press, not to queue inputs from the beginning of the current strike;
- a Light press far too early is rejected rather than silently remembered for a long time;
- the Combat IDE exposes whether the press was `AcceptedImmediate`, `AcceptedPendingContinuation`, or `RejectedTooEarly`;
- exact milliseconds/normalized phase thresholds are deferred to the dedicated input-buffer tuning decision after guard/evade windows are known.

Thus Decision #2 establishes **one-slot near-window forgiveness** without pretending the global buffer policy is already finished.

### Late presses either continue now or miss cleanly
A Light request made while the current entry's continuation transition is already legal may be accepted immediately for the next entry according to the action contract.

Once the continuation opportunity has closed:
- a late press does not retroactively continue the old chain;
- if combat state has already returned to a legal free state, the press may start a fresh `Light_1` as a new action;
- if the player is still in non-chain Recovery where a fresh attack is not yet legal, the request is rejected/potentially handled by later global buffer authority—not silently converted into a chain continuation.

The System IDE must distinguish **continued chain** from **new chain started after reset**.

### Stopping is always valid
The player is never obligated to finish the three-entry chain.

After any entry:
- if no valid continuation request exists, the current attack simply completes through Recovery;
- the chain resets cleanly to free state;
- there is no failure animation, stumble, stamina penalty, or hidden punishment for choosing not to continue;
- no “combo dropped” UI is required for ordinary combat.

The chain exists to give follow-up options, not force choreography.

### Mashing does not create a better queue
Repeated Light presses during a committed phase:
- may fill the one allowed continuation slot if the current timing permits near-window forgiveness;
- otherwise are rejected/ignored with explicit diagnostic reason;
- do not build a multi-entry FIFO;
- do not extend continuation expiration;
- do not speed up attack playback;
- do not bypass Startup/Active commitment;
- do not increase damage or hidden combo priority merely through frequency.

The player may mash physically, but the state machine still accepts at most one meaningful future continuation at a time.

### Chain tempo is readable rather than rhythm-game strict
Stillring's light chain should encourage deliberate presses but should not require frame-perfect rhythm memorization.

- continuation windows must be broad enough for ordinary human reaction/intent;
- near-window forgiveness exists because intent can arrive a little early;
- the player should learn the chain through animation/contact rhythm, not HUD timing bars;
- exact windows remain human-play tuning;
- accessibility may later offer combat-assist timing options, but canonical combat state remains unchanged unless that assist is explicitly approved.

### `Light_3` is a chain conclusion, not automatically a heavy attack
The third baseline light entry may have a distinct animation/impact feel, but Decision #2 does not classify it as the committed/heavy action from Decision #3.

- it remains part of the Light action family;
- it may have somewhat different Startup/Active/Recovery values as authored;
- it does not automatically inherit armor breaking, stamina cost, charge, guard-breaking, or heavy-specific cancel rules;
- if testing later shows `Light_3` should be more committed, that may be tuned within light-family bounds or explicitly revised—it cannot silently become “heavy.”

### Chain reset conditions
The light-chain index/pending continuation resets when any of the following becomes authoritative:
- chain resolves to free state after no continuation;
- `Light_3` completes;
- a future legal transition leaves the light-chain family (guard/evade/heavy/etc. under later authority);
- a forced interrupt/hard stagger/death terminates the chain under later rules;
- a higher-priority traversal/script state takes ownership;
- combat state is explicitly reset/restarted through debug/death/retry authority.

Target switching alone does **not** necessarily reset chain index; target-facing consumption is handled below.

### Target changes affect the next decision, not the current committed strike
Camera/targeting authority may change the current lock target when switching is legal.

For the light chain:
- the current committed light entry continues under Decision #1 and is not automatically retargeted/warped to the new lock target;
- after the current entry reaches a legal continuation boundary, the **next** light entry may consume the current authoritative target and apply whatever bounded facing/rotation assistance is later approved for light attacks;
- the chain does not silently teleport/vacuum Neris across space to preserve continuity;
- if the target becomes invalid and no new target is selected, a continuation may still execute in a stable world/facing direction if later attack-facing authority allows unlocked continuation;
- exact attack-facing correction remains a later combat decision.

This lets target switching matter quickly without rewriting a strike the player already committed.

### Movement intent can prepare the next entry but does not cancel the current one
Decision #2 does not yet finalize attack translation/facing correction, but it establishes:
- ordinary movement input does not cancel Startup/Active of the current light entry;
- movement input may be sampled as **next-entry intent** at an approved continuation boundary once later facing/movement authority defines its effect;
- free locomotion returns according to the current entry's Recovery permissions from Decision #1;
- no analog direction automatically selects hidden alternate combo animations in the Gate 2 baseline.

### Chain does not require a hit to continue
The baseline light chain is **input/action-state driven**, not “only continue if the previous strike hit.”

- whiffing does not automatically cancel chain eligibility;
- hitting does not automatically continue the chain;
- damage/hit-confirm may later affect presentation, resources, enemy reactions, or special combat systems, but baseline continuation comes from the player's valid Light request;
- this keeps the control contract predictable whether the target dodges, dies, moves, or the player intentionally swings into space.

A future specific weapon/style could add hit-confirm branches only under explicit authority.

### No hitstop-dependent input semantics
Future hitstop may briefly affect presentation/simulation timing to sell contact, but light continuation intent cannot become frame-rate/feedback dependent in an opaque way.

The implementation must define whether authoritative input-window clocks pause/scale during approved hitstop and expose that decision in the IDE. Decision #2 does not allow “the combo window changed because hitstop happened accidentally.”

### Chain requests are semantic input events
Light Attack is a remappable semantic action.

- physical keyboard/controller button selection is global control-map authority;
- one distinct `Triggered/Pressed`-equivalent action event represents one Light request;
- held action does not auto-repeat;
- device repeat behavior/OS key repeat must not generate unintended extra chain requests;
- prompts/UI must reflect remaps under production input authority.

---

## Combat System IDE requirements

The workbench must make chain intent and timing fully explainable.

### Inspect
At minimum show:
- current combat action/phase;
- current light chain entry/index;
- next light entry, if any;
- chain continuation eligibility;
- continuation window start/end;
- pre-window forgiveness region;
- pending continuation slot: empty/filled;
- pending request timestamp/frame;
- request classification: immediate/pending/rejected-too-early/rejected-too-late/rejected-state;
- whether request was consumed;
- chain reset reason;
- current target at action start/current target now;
- movement input sampled during current entry;
- animation/montage section separately from authoritative entry state;
- exact transition/rejection reason from Decision #1.

### Tune
Prototype-tunable values:
- each light entry Startup/Active/Recovery boundaries;
- continuation-window placement/width;
- pre-window forgiveness width;
- blend timing/presentation values that do not alter semantics;
- later approved movement/facing values once authority exists.

### Exercise
One-click tools/scenarios:
- start `Light_1/2/3` independently for debug;
- press continuation at selected normalized timestamps;
- fill/clear pending continuation slot;
- simulate no-hit/hit/target death between entries;
- switch target between entries;
- hold Light versus repeated distinct presses;
- mash at high frequency;
- stop after entry 1 or 2;
- force interrupt/reset and prove queue cleanup.

### Validate
At minimum detect:
- held Light auto-repeating without distinct semantic presses;
- more than one pending continuation stored;
- repeated presses extending expiration indefinitely;
- early request accepted outside approved forgiveness region;
- `Light_3` incorrectly chaining to hidden `Light_4`;
- chain index owned by montage section instead of gameplay state;
- animation section jump occurring without authoritative chain transition;
- chain requiring a hit despite baseline no-hit-gate authority;
- target switch warping the current committed entry;
- stale continuation surviving chain reset/interrupt;
- device/OS key repeat creating extra semantic requests;
- frame-rate-dependent continuation acceptance.

### Capture
Combat timeline must record:
- Light input events;
- classification/accept/reject;
- pending-slot state changes;
- chain entry transitions;
- phase boundaries;
- hit/no-hit events for correlation;
- target changes;
- movement input;
- animation section/markers;
- chain reset reason.

---

## Representative test matrix

### One press / hold
- tap Light once;
- hold Light from free state;
- hold through entire `Light_1`;
- hold/release at different phases.

Expected: exactly one entry from one initial press; no automatic chain from hold.

### Deliberate continuation
For each transition `1→2` and `2→3`:
- press far too early;
- press just inside pre-window forgiveness;
- press exactly at window open;
- press mid-window;
- press at window edge;
- press after window closes;
- press twice rapidly while pending slot already filled.

Expected: at most one next action scheduled; classifications explainable.

### Stopping
- stop after `Light_1`;
- stop after `Light_2`;
- complete `Light_3`;
- move away during Recovery after choosing not to continue.

Expected: clean return to free state, no penalty/stumble/ghost queue.

### Mashing
- 5–10 rapid Light presses during `Light_1`;
- continuous rapid presses through entire three-entry chain;
- mash before any continuation forgiveness starts.

Expected: only one pending continuation at a time; no pre-programmed whole chain.

### Target integration
- hit target A, switch to B before next legal continuation;
- switch during current Startup/Active;
- target A dies after `Light_1`;
- target disappears with pending continuation;
- unlocked chain into empty space.

Expected: current committed entry is not rewritten; next entry uses later-approved facing rules/current target context.

### Hit/no-hit
- all three hits connect;
- first whiffs, second/third requested;
- first hits, second whiffs;
- enemy dies on first/second;
- collision/wall prevents clean contact.

Expected: baseline chain eligibility follows valid input/state, not hit confirmation.

### Robustness
- 30/60/120+ FPS;
- controller and keyboard;
- key/button repeat edge cases;
- animation playback-rate variation;
- future hitstop prototype on/off;
- forced interrupt with continuation pending.

---

## Research basis / design lineage

### Unreal Engine 5.8 primary references
Enhanced Input and Gameplay Ability primitives demonstrate that repeated input events and waiting for specific subsequent presses can be modeled explicitly rather than inferred from animation playback:
- Enhanced Input exposes semantic action trigger states (`Started`, `Ongoing`, `Triggered`, `Completed`, `Canceled`) and Pressed/Released/Hold-style triggers;
- `UAbilityTask_WaitInputPress` waits for a subsequent press;
- `UAbilityTask_WaitInputRelease` independently tracks release;
- Montage/Ability tasks expose completion/interruption/cancel separately from gameplay input.

References:
- https://dev.epicgames.com/documentation/unreal-engine/enhanced-input-in-unreal-engine
- https://dev.epicgames.com/documentation/unreal-engine/API/Plugins/GameplayAbilities/UAbilityTask_WaitInputPress
- https://dev.epicgames.com/documentation/unreal-engine/API/Plugins/GameplayAbilities/UAbilityTask_WaitInputRelease
- https://dev.epicgames.com/documentation/en-us/unreal-engine/BlueprintAPI/Ability/Tasks/PlayMontageAndWait

These prove implementation feasibility only; they do not require GAS or define Stillring chain timing.

### Shipped-game / developer problem study
The combat-design sources used for Decision #1 remain relevant at a narrower chain level:
- former God of War combat designer Eric Williams distinguishes buffered versus instant cancels and emphasizes that permissive basic attacks and stricter stronger actions can coexist;
- PlatinumGames' NieR:Automata team explicitly built tooling to tune cancellation timing because response between button press and attack must feel good;
- Bayonetta 2 design commentary emphasizes consistency between player intention and onscreen result.

Stillring's chain intentionally synthesizes the abstract lessons into its own expression:
- one press has one clear consequence;
- near-window intent is forgiven;
- mashing cannot pre-author several actions;
- the player can stop after any entry;
- timing is tunable/inspectable rather than hidden in clips.

References:
- https://www.gamedeveloper.com/game-platforms/combat-canceled-i-god-of-war-i-action-game-design
- https://www.platinumgames.com/official-blog/article/8997
- https://www.gamedeveloper.com/design/-i-bayonetta-i-s-combat-design-philosophy-creating-a-direct-link-to-your-brain

No exact combo count/timing/control map/animation from those games is copied. The representative three-entry prototype count is Stillring's own narrow Gate 2 test choice and may not become a universal future weapon rule by accident.

### Stillring vision
`docs/01_GAME_VISION.md` requires readable attack commitment, viable defensive play, target-lock readability, and multi-enemy fairness. A short linear baseline chain gives later guard/evade/interrupt decisions a simple deterministic surface to test before combat complexity expands.

---

## Why this package is approved
Combat Decision #2 creates enough light-attack structure to test the state model without prematurely designing a full weapon system.

It deliberately locks:
- one press/one entry;
- short representative three-entry chain;
- explicit continuation windows;
- one-slot near-window continuation intent;
- no hold-auto-combo or multi-command queue;
- clean stop/reset;
- target changes affect future entries rather than rewriting current commitment.

It deliberately leaves exact timing, global input-buffer duration, facing correction, defense cancels, heavy identity, and resources for their own research passes.

---

## Player-facing acceptance
Combat Decision #2 passes when:
1. tapping Light once produces one attack and stops if the player does nothing else;
2. holding Light does not auto-complete the chain;
3. the Gate 2 baseline has three explicit light entries and no hidden fourth;
4. every continuation requires a distinct Light request;
5. at most one next Light continuation can be pending;
6. a near-window early press can receive short forgiveness, but far-early mashing cannot queue the chain;
7. repeated presses cannot extend a pending request forever or pre-program multiple future entries;
8. stopping after `Light_1` or `Light_2` returns cleanly through Recovery with no punishment;
9. chain continuation does not require hit-confirm in the baseline;
10. switching/losing target does not rewrite the current committed attack; only a future legal entry may consume new target/facing context;
11. `Light_3` remains light-family authority and does not silently become the heavy action;
12. chain index/pending intent are gameplay state rather than Montage state;
13. Combat IDE explains every request, continuation window, pending slot, entry transition, and reset reason;
14. exact buffer timing, attack-facing assistance, guard/evade cancels, and heavy semantics remain separate later decisions.

---

## Next combat decision
**Combat Decision #3 — heavy / committed attack semantics.**

Research independently before approval. Define whether heavy is fixed or hold/charge, why it is different from `Light_3`, its commitment/movement/facing rules, what payoff it earns, what can/cannot cancel it, and how it interacts with future guard/armor/posture concepts without assuming a stamina tax.