# 46 — Gate 2 Combat Resource Model Addendum

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Scope:** Combat Decision #10 for Issue #3. This file decides whether the representative Gate 2 core combat loop needs a universal player stamina/posture/integrity resource.

## Authority
Combat Decision #10 is locked under the owner's explicit scheduled-run delegation after a fresh focused research pass.

Resource principle:
> **Do not meter a decision that already has a real cost.**

---

## Combat Decision #10 — core combat resource model — LOCKED

### Gate 2 has no universal player combat stamina bar
The representative core combat loop does **not** consume a shared stamina/action-energy resource for:
- Light attacks;
- Heavy attacks;
- ordinary Guard;
- Perfect Guard attempts;
- Evade;
- ordinary Sprint;
- Jump.

There is no regenerating “action permission” bar that the player must watch before performing core combat verbs.

### No player posture / guard-integrity bar in the Gate 2 baseline
Combat #4 already constrained Guard through:
- directional coverage;
- guarded movement;
- Guard Reaction;
- unblockable/other authored threats;
- opportunity cost;
- multi-enemy flanking pressure.

Combat #10 therefore does not add:
- player posture meter;
- shield integrity meter;
- guard-break gauge;
- passive Guard drain;
- per-block stamina cost.

If a later playtest demonstrates that directional/temporal costs fail to prevent degenerate indefinite turtling, the project may open a specific resource revision based on observed evidence. It may not preemptively add a meter because another genre convention uses one.

### Evade remains timing/position constrained, not resource constrained
Combat #5 already costs the player:
- committed displacement;
- vulnerable Entry/Recovery;
- inability to attack/Guard during core travel;
- collision/world constraints;
- possible bad repositioning;
- bounded immunity timing.

No stamina charge is added to Evade.

Evade-spam failure must first be addressed through action timing, recovery, encounter pressure, and positioning. Only if human play proves those insufficient should a future revision consider a resource.

### Heavy remains commitment-for-payoff, not cost-for-payoff
Heavy's cost is its action contract:
- longer/readable Startup;
- stricter player-requested cancellation;
- less late facing correction;
- meaningful miss/recovery consequence;
- interrupt vulnerability under Combat #6.

Heavy does not consume a stamina chunk merely to distinguish it from Light.

### Light chain remains finite through state, not stamina
The three-entry Gate 2 Light baseline already limits itself through:
- one press → one entry;
- one pending continuation at most;
- authored continuation windows;
- finite chain depth;
- attack commitment/recovery;
- hit interruption.

No stamina drain is needed to stop infinite basic attacks because the action/state model already controls cadence.

### Perfect Guard costs timing risk, not meter currency
Perfect Guard remains a skill/tempo choice:
- early input = ordinary Guard;
- late input = possible hit;
- correct input = tempo preservation.

No stamina/posture fee is attached to attempts or successes.

### Health remains health; it is not an action resource
The player may still have health and later other game-specific meters. Combat #10 only rejects a universal resource that gates ordinary combat actions.

Health may not be spent automatically to permit core attacks/evades/Guard unless a future explicit mechanic earns that behavior.

### Special abilities may earn separate resources later
Combat #10 does **not** ban all meters from Stillring.

A later concrete verb may justify its own resource if the resource creates meaningful strategic pacing, for example:
- a rare power state;
- a tool with limited charge;
- a magic/ability system;
- an encounter-specific mechanic.

Such a resource must be attached to that verb's design problem and cannot retroactively tax Light/Heavy/Guard/Evade by convenience.

### Enemy posture/stun is a separate design question
The absence of a **player core-action resource** does not forbid enemies from later using:
- stun thresholds;
- poise/stability states;
- breakable guard states;
- boss-specific structural meters.

Those are enemy/encounter mechanics and require their own authority. They may not silently become a symmetric player posture bar.

### No hidden cooldown substitute for stamina
The project may not remove the visible bar and then secretly recreate it through arbitrary cooldown timers on every basic verb.

Core combat cadence comes from each action's authored state/phase/recovery.

Cooldowns are permitted only where a specific future ability explicitly needs them.

### No meter UI reserved “just in case”
Gate 2 UI/HUD should not reserve a generic stamina/posture bar for the player baseline.

Prototype diagnostics may show action phase/recovery timers in the dev-only Combat IDE, but these are not player-facing resources.

### Degenerate-play review is required before revising this decision
Human combat testing must specifically try to break the no-resource model through:
- repeated Evade as soon as legal;
- holding Guard and only reacting to unblockables/flanks;
- alternating Guard→Evade;
- repeated Heavy attempts;
- continuous Light-chain restarting;
- defensive play in multi-enemy pressure;
- boss pressure where spacing is limited.

If play remains readable and meaningful, a meter would be redundant friction.

If a failure is found, the correction order is:
1. verify action-state timing/cancel rules are working as designed;
2. verify encounter telegraphs/spacing/flanking pressure;
3. tune recovery/Guard Reaction/attack commitment where appropriate;
4. only then evaluate whether a resource adds a genuinely new decision.

### Any future resource proposal must answer a strict test
A resource revision must state:
- what degenerate behavior currently exists;
- why action timing/position/encounter design cannot solve it cleanly;
- which exact actions consume/recover the resource;
- what new player decision the meter creates;
- what happens at zero;
- accessibility/UI implications;
- whether the resource duplicates an existing consequence.

No “most action games have stamina” rationale is acceptable.

---

## Accessibility / readability

The no-universal-resource baseline reduces simultaneous HUD/resource monitoring and prevents core defensive accessibility from depending on resource-management speed.

Requirements:
- core Guard/Evade remain available based on state legality/timing rather than a hidden meter;
- no accessibility setting has to secretly refill stamina to make core controls usable;
- player-facing feedback focuses on actual state/commitment/threat rather than meter exhaustion;
- any later special resource must have non-color-only, readable UI and explicit accessibility review.

---

## Combat System IDE requirements

### Inspect
Expose:
- current combat action/state/phase;
- legal transitions;
- recovery/commitment timing;
- Guard Reaction;
- Evade phase/immunity;
- pending input intent;
- explicit proof that no universal core-action resource check is involved;
- any future special-resource ownership separately.

### Exercise
Provide abuse scenarios:
- continuous legal Light chains;
- repeated Heavy;
- repeated Evade at first legal frame;
- indefinite Guard with frontal attacker;
- Guard→Evade alternation;
- multi-enemy flank pressure;
- extended boss pressure;
- low-health combat without an action-resource penalty.

### Validate
Detect:
- Light/Heavy/Guard/Evade/Sprint/Jump unexpectedly checking a generic stamina resource;
- passive Guard drain;
- hidden per-Evade cost;
- Heavy stamina cost added in data without authority;
- generic cooldown recreated as hidden stamina substitute;
- player posture/guard meter added without revision;
- HUD generic stamina bar with no approved system owner;
- action denied with a resource-related rejection reason despite this authority.

### Capture
Record action requests, legality, recovery, Guard/Evade use, encounter pressure, and any attempted resource checks so prototype sessions can prove whether state costs alone create sufficient combat decisions.

---

## Representative tests

1. Execute repeated legal Light chains with no resource gating.
2. Use Heavy repeatedly as soon as state allows; verify recovery/interrupt risk is the limiter.
3. Evade repeatedly at earliest legal boundaries; check whether timing/position naturally constrains abuse.
4. Hold Guard for prolonged periods against frontal pressure; test flanks/unblockables/Guard Reactions.
5. Alternate Guard→Evade under pressure.
6. Run multi-enemy encounters where camera cannot rescue offscreen aggression.
7. Run boss proxy pressure in limited space.
8. Verify no player stamina/posture HUD or generic denial reason appears.
9. Verify 30/60/120+ FPS does not change cadence except normal action timing.
10. Capture sessions specifically looking for degenerate no-resource behavior before any future revision.

---

## Research basis / design lineage

A contemporary Game Developer postmortem for *Death of a Wish* explicitly discusses how removing a stamina resource changes combat texture, demonstrating that stamina is a design choice rather than a mandatory action-game substrate. PlayStation's official *God of War Ragnarök* combat materials also show a different resource philosophy: a meter can be reserved for a distinct high-impact power state while ordinary movement/defense/offense remain governed by their own action rules.

Stillring's baseline already encodes consequence directly in state, position, reaction, timing, and readability. A generic meter would currently duplicate those costs rather than create a new decision.

No resource rates, meter behavior, UI, balance values, or proprietary implementation are copied from reference games.

---

## Why this package is approved
Combat #10 deliberately keeps the combat model legible. The player reads the enemy and their own commitment, not a second permission gauge layered over every ordinary verb.

A meter remains available as a future tool **only if play evidence earns it**.

---

## Player-facing acceptance
Combat #10 passes when:
1. Light, Heavy, ordinary Guard, Perfect Guard, Evade, Sprint, and Jump have no universal stamina cost;
2. no player posture/guard-integrity meter exists in the Gate 2 baseline;
3. Guard has no passive drain and Evade has no hidden cost;
4. Heavy remains differentiated by commitment/payoff rather than resource tax;
5. no generic cooldown system silently recreates stamina gating;
6. HUD has no unjustified core stamina/posture bar;
7. enemy stun/posture remains a separate future system question;
8. any future special ability resource must be scoped to that concrete verb;
9. Combat IDE can prove action legality is state-based rather than resource-gated;
10. human red-team testing must demonstrate an actual unresolved degeneracy before this decision is revised.

---

## Next combat decision
**Combat Decision #11 — death / retry combat-state boundary.**

Research independently before approval. Define exactly when Death becomes authoritative, how active attack/Guard/Evade/reaction/pending inputs clean up, whether lock/camera persists during death presentation, player input suppression, checkpoint/retry reset invariants, and what must be restored without duplicating save/world-state policy.