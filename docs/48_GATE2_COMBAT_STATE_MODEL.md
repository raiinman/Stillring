# 48 — Gate 2 Combat State Model

**Status:** CUMULATIVE / FINAL OWNER-DELEGATED AUTHORITY  
**Updated:** 2026-09-05  
**Scope:** Reconciles Combat Decisions #1–#11 for GitHub Issue #3 into one implementation-facing player combat state model. This file adds no new combat policy; where detail differs, the numbered decision addenda remain provenance authority.

## Governing combat principle

> **Commit to the meaningful decision, not to decorative dead time.**

Gameplay/state authority is C++ first. Animation presents and timestamps reviewed action state; it does not silently decide legality, cancellation, immunity, damage response, or death.

---

## 1. Authority chain

1. `docs/37_GATE2_COMBAT_COMMITMENT_CANCEL_ADDENDUM.md` — Decision #1
2. `docs/38_GATE2_COMBAT_LIGHT_CHAIN_ADDENDUM.md` — Decision #2
3. `docs/39_GATE2_COMBAT_HEAVY_COMMITMENT_ADDENDUM.md` — Decision #3
4. `docs/40_GATE2_COMBAT_GUARD_MODEL_ADDENDUM.md` — Decision #4
5. `docs/41_GATE2_COMBAT_EVADE_MODEL_ADDENDUM.md` — Decision #5
6. `docs/42_GATE2_COMBAT_HIT_INTERRUPT_ADDENDUM.md` — Decision #6
7. `docs/43_GATE2_COMBAT_PERFECT_GUARD_ADDENDUM.md` — Decision #7
8. `docs/44_GATE2_COMBAT_INPUT_BUFFER_ADDENDUM.md` — Decision #8
9. `docs/45_GATE2_COMBAT_ATTACK_FACING_ADDENDUM.md` — Decision #9
10. `docs/46_GATE2_COMBAT_RESOURCE_MODEL_ADDENDUM.md` — Decision #10
11. `docs/47_GATE2_COMBAT_DEATH_RETRY_ADDENDUM.md` — Decision #11

Locomotion, camera/targeting, System IDE, IP, save/world-state, and later enemy/encounter authority remain external constraints rather than duplicated here.

---

## 2. High-level state model

Combat is modeled as one authoritative player-state graph plus orthogonal data such as target lock, the single pending input intent, attack-facing samples, and externally-owned checkpoint/world state.

```text
                         ┌────────────────────┐
                         │  FREE / LOCOMOTION │
                         └─────────┬──────────┘
                                   │ accepted request
           ┌───────────────────────┼────────────────────────┐
           │                       │                        │
           v                       v                        v
   ┌───────────────┐       ┌───────────────┐        ┌───────────────┐
   │ LIGHT ATTACK  │       │ HEAVY ATTACK  │        │     GUARD     │
   │ S→A→R         │       │ S→A→R         │        │ directional   │
   │ entries 1–3   │       │ fixed commit  │        └──────┬────────┘
   └──────┬────────┘       └──────┬────────┘               │
          │                       │                         ├─ eligible timed contact
          │                       │                         v
          │                       │                 ┌───────────────────┐
          │                       │                 │ PERFECT GUARD     │
          │                       │                 │ ADVANTAGE         │
          │                       │                 └─────────┬─────────┘
          │                       │                           │
          └──────────┬────────────┴───────────────┬──────────┘
                     │ legal recovery/exit        │
                     v                            v
               ┌─────────────────────────────────────┐
               │        FREE / LOCOMOTION            │
               └─────────────────────────────────────┘

   FREE or specifically-authorized source state
                    │
                    v
          ┌────────────────────┐
          │       EVADE        │
          │ Entry→Immune→Recov │
          └─────────┬──────────┘
                    │
                    v
               FREE / LOCOMOTION

Incoming hit resolution may produce:
  NoHit ───────────────> state unchanged
  DamageOnly ──────────> state may continue
  LightReact ──────────> LIGHT REACTION where permitted
  Interrupt ───────────> INTERRUPT / REACTION
  HardStagger ─────────> HARD STAGGER
  Death ───────────────> DEATH (highest priority)

Any non-Death reaction resolves back through its authored recovery to a legal neutral/action state.
DEATH cannot be player-canceled; retry rebuilds a clean combat-local baseline from external restore authority.
```

`S→A→R` means authoritative Startup → Active → Recovery, not animation clip sections by themselves.

---

## 3. Core state families

### Free / locomotion-ready
No committed combat action owns the player. Legal action requests may be accepted subject to locomotion/traversal/world context.

### Light attack
Three authored entries. Each entry owns Startup, Active, Recovery. One press requests one strike. Continuation is explicit; no hold-auto-combo and no unbounded queue.

### Heavy attack
Separate fixed press-to-commit family, not `Light_4`. It carries greater commitment, stricter player-requested cancellation, less late facing correction, and meaningful miss/recovery consequence.

### Guard
Directional front-sector defensive state. Ordinary Guard is reliable against eligible frontal guardable hits, with Guard Reaction as the baseline consequence. It has no passive stamina/posture drain.

### Perfect Guard Advantage
A successful fresh precisely-timed Guard activation against an eligible frontal hit skips ordinary Guard Reaction and preserves tempo. It does not auto-counter, generically stun, reflect all projectiles, slow time, or consume a resource.

### Evade
Dedicated one-press combat action with committed collision-honest displacement. It has vulnerable entry and recovery around a short central combat-immunity interval. It is not Sprint and has no stamina tax.

### Hit reaction / interrupt / hard stagger
Incoming hit reaction is resolved independently from damage. Current state plus incoming `ReactionForce` determine whether the action continues, lightly reacts, interrupts, hard-staggers, or dies.

### Death
Highest-priority terminal player-combat state. It atomically clears all transient combat ownership. Retry is an external checkpoint/world restoration followed by a fresh neutral combat-local baseline.

---

## 4. Legal / conditional / illegal transition matrix

Legend:
- **YES** — generally legal when destination-specific eligibility is satisfied.
- **CONDITIONAL** — only through an explicit reviewed source-phase/window/context rule.
- **NO** — not a normal player-requested transition.
- **FORCED** — only through authoritative external hit/death/world ownership.

| From \ To | Light | Heavy | Guard | Evade | Free/Locomotion | Reaction/Stagger | Death |
|---|---:|---:|---:|---:|---:|---:|---:|
| Free/Locomotion | YES | YES | YES | YES | — | FORCED | FORCED |
| Light Startup | CONDITIONAL | CONDITIONAL | CONDITIONAL | CONDITIONAL | NO | FORCED | FORCED |
| Light Active | CONDITIONAL | CONDITIONAL | CONDITIONAL | CONDITIONAL | NO | FORCED | FORCED |
| Light Recovery | CONDITIONAL | CONDITIONAL | CONDITIONAL | CONDITIONAL | CONDITIONAL | FORCED | FORCED |
| Heavy Startup | CONDITIONAL | NO by default | CONDITIONAL | CONDITIONAL | NO | FORCED | FORCED |
| Heavy Active | NO by default | NO | NO by default | NO by default | NO | FORCED | FORCED |
| Heavy Recovery | CONDITIONAL | CONDITIONAL | CONDITIONAL | CONDITIONAL | CONDITIONAL | FORCED | FORCED |
| Guard | CONDITIONAL | CONDITIONAL | — | YES from stable Guard | YES on release/cancel when legal | FORCED / GuardReaction | FORCED |
| Guard Reaction | NO by default | NO by default | CONDITIONAL after recovery | **NO to Evade during Guard Reaction** | CONDITIONAL after recovery | FORCED | FORCED |
| Perfect Guard Advantage | CONDITIONAL | CONDITIONAL | CONDITIONAL | CONDITIONAL | CONDITIONAL | FORCED | FORCED |
| Evade Entry/Immune/Recovery | NO by default | NO by default | NO by default | NO chain | CONDITIONAL after recovery | FORCED when vulnerable; `NoHit` in immunity for eligible hits | FORCED |
| Reaction / Interrupt / HardStagger | NO until its contract permits | NO until permitted | CONDITIONAL after recovery | CONDITIONAL after recovery | CONDITIONAL after recovery | stronger/equal handling per #6 | FORCED |
| Death | NO | NO | NO | NO | NO | NO | — |

This matrix intentionally does **not** invent one universal cancel timestamp. Exact source-phase→destination openings live in action data under Decision #1 and later decision-specific authority. A transition that is not explicitly authorized is rejected with a semantic reason.

### Light-chain special edge
`Light_1 → Light_2 → Light_3` occurs only through each entry's approved continuation request/window. There is no `Light_4`, no hold-to-auto-chain, and no FIFO of future strikes.

### Guard / Perfect Guard special edge
Perfect Guard is not a freely-entered mode. It is the resolved result of a fresh eligible Guard activation meeting the timing/contact rules in Decision #7.

### Evade special edge
Stable ordinary Guard may transition to Evade. Guard Reaction may not evade-cancel its consequence. Evade never self-chains into another Evade as a special bypass around recovery.

---

## 5. Orthogonal state that must not become hidden authority

### Target lock
Target lock is tactical targeting/camera state, not a replacement combat-state machine.

- target switching is explicit and deterministic;
- current target changes do not rewrite a committed Heavy;
- each new Light chain entry may resample the current explicit lock target under Decision #9;
- unlocked attacks use player movement intent/body facing rather than enemy-search;
- no attack vacuum/orbit/reach extension is created by target lock;
- Death clears gameplay lock immediately.

### Input buffer
The buffer is not a state queue. It is one bounded pending combat intent near a known legal transition window.

- one global pending combat intent maximum;
- no multi-command FIFO;
- repeated mash does not extend expiry indefinitely;
- execution revalidates legality;
- interrupts, Death, traversal/context invalidation clear it;
- buffered Guard cannot retroactively create Perfect Guard;
- buffered Evade grants no immunity before Evade begins.

### Facing assistance
Facing assist is bounded gameplay correction, not animation authority.

- Light: modest capped early-Startup correction;
- Heavy: stricter earlier-closing correction sampled at acceptance;
- no Active-phase target tracking;
- no rear-target 180° snap;
- no translation/vacuum/orbit/reach extension;
- Standard / Reduced / Off assistance preserves action legality.

### Resources
No universal player combat stamina/posture/integrity resource gates core Light, Heavy, Guard, Perfect Guard, Evade, Sprint, or Jump. Their costs are already state, timing, position, reaction, and recovery. A future concrete verb/resource must earn separate authority.

---

## 6. Incoming hit resolution and priority

Damage and reaction are separate outputs.

Representative reaction results from Decision #6:
1. `NoHit`
2. `GuardReaction`
3. `DamageOnly`
4. `LightReact`
5. `Interrupt`
6. `HardStagger`
7. `Death`

Priority rules:
- successful eligible Evade immunity resolves eligible combat contact as `NoHit` rather than relying on animation invulnerability;
- ordinary successful Guard resolves through Guard authority rather than pretending damage/reaction did not occur;
- Perfect Guard uses its separate successful timing result;
- attacks have no assumed universal hyper armor;
- equal/lower reaction pressure cannot indefinitely refresh control loss because Reaction Retrigger Protection is bounded; stronger reactions may escalate;
- Death outranks every player combat action/reaction and clears transient state exactly once.

---

## 7. Gameplay versus animation boundary

Gameplay owns:
- action acceptance/rejection;
- Startup/Active/Recovery;
- legal transitions and cancel windows;
- hit/hurt authority;
- Guard/Perfect Guard/Evade legality;
- Evade immunity;
- damage/reaction resolution;
- input buffer state;
- attack-facing authority;
- Death and cleanup.

Animation may:
- present action state;
- use reviewed timing markers/branching points;
- blend from one legal gameplay state to another;
- visually continue harmless follow-through after gameplay authority has returned where approved.

Animation may not:
- extend Recovery because a clip is longer;
- grant an unreviewed cancel because a notify exists;
- grant immunity;
- decide Guard coverage;
- decide hit interruption/death;
- keep the player logically busy after gameplay says the state ended;
- resurrect a canceled/dead action through stale callbacks.

---

## 8. Combat System IDE cumulative contract

The Combat IDE must make this state model explainable during play.

### Inspect
At minimum expose:
- current high-level combat state;
- action ID/family and phase;
- legal transitions right now;
- last rejected request + reason;
- single pending intent + expiry/replacement reason;
- current Guard / Guard Reaction / Perfect Guard state;
- current Evade phase + immunity state;
- incoming `ReactionForce` and resolved reaction result;
- Reaction Retrigger Protection;
- current target and attack target/facing sample;
- facing-assist mode/correction;
- health and separately-owned resources;
- alive/dead state and death cleanup status;
- animation/montage state beside gameplay state;
- gameplay↔presentation mismatch warnings.

### Tune
Only reviewed prototype values, with canonical/session/staged/promoted provenance:
- action phase timings;
- continuation/cancel windows;
- Guard/Perfect Guard timings and Guard Reaction tuning;
- Evade entry/immunity/recovery and displacement envelope;
- reaction/retrigger timing;
- input-buffer pre-open/expiry windows;
- bounded facing-assist values.

Live tuning may not change semantic state classes or silently add a core stamina/posture gate.

### Exercise
Provide rapid fixtures for:
- each Light entry and timing edge;
- Heavy hit/miss/recovery;
- Guard frontal/flank/unblockable cases;
- Perfect Guard early/in-window/late/rearm cases;
- Evade entry/immunity/recovery/collision cases;
- every hit-reaction class and stunlock red-team case;
- input-buffer replacement/expiry/clear cases;
- locked/unlocked/facing-assist cases;
- no-resource abuse cases;
- fatal hit during every major state plus repeated retry.

### Validate
Detect at minimum:
- illegal graph edges;
- unowned or unexplained transition rejection;
- animation defining gameplay lockout;
- stale attack hit state after cancel/interrupt;
- Guard/Evade/Perfect Guard behavior outside reviewed authority;
- immunity outside Evade's approved interval;
- buffer FIFO/stale intent leakage;
- attack magnetism/translation/reach extension from facing assist;
- generic core stamina/posture checks;
- leaked combat state across Death/retry.

### Capture
Produce a deterministic timeline containing input, accept/reject, action/phase, target/facing, hit/reaction, Guard/Evade/immunity, pending-intent, animation markers, death cleanup, and retry baseline.

---

## 9. Issue #3 acceptance reconciliation

| Issue #3 acceptance criterion | Status | Authority |
|---|---|---|
| Combat state diagram exists | **PASS** | This document §2 plus Decisions #1–#11 |
| Legal and illegal transitions explicit | **PASS** | This document §4; Decision #1 transition authority; Decisions #2–#11 special edges |
| Attack commitment/cancel philosophy defined | **PASS** | Decision #1; Light #2; Heavy #3 |
| Guard and evade timing philosophy defined | **PASS** | Guard #4; Evade #5; Perfect Guard #7 |
| Hit reaction and interrupt priority defined | **PASS** | Decision #6; Death #11 |
| Invulnerability frames, if any, explicitly justified | **PASS** | Decision #5: short central Evade combat-immunity forgiveness interval, vulnerable entry/recovery, position-first/collision-honest |
| Target-lock interaction with combat state defined | **PASS** | Camera #10–#14 constraints; Combat #1/#2/#9/#11; this document §5 |
| Gameplay logic separated from animation presentation | **PASS** | Decision #1; Decision #11; this document §7 |

Issue #3 non-goals remain intact:
- no final balance numbers;
- no final animation set;
- no enemy AI implementation.

**Conclusion:** Issue #3's player combat frame/state-model design is complete and implementation-ready without inventing contradictory player-state rules.

---

## 10. What Issue #3 closure does not finish

Closing the **player combat state model** does not mean every Gate 2 design problem is complete.

Still outstanding before the full Gate 2 combat prototype can be considered specification-complete:
- melee enemy behavior/state contract;
- ranged enemy behavior/state contract;
- shield/armor enemy behavior/state contract;
- multi-enemy attack bandwidth/aggression/readability policy required by camera authority;
- enemy stun/poise/guard-break semantics if retained;
- encounter reset/restore behavior where it crosses checkpoint/world-state authority;
- exact numeric combat tuning through human play.

Those must be researched as their own decisions/systems. They may not be inferred from this player-state model.

---

## 11. Implementation boundary

A Gate 2 implementation may now build the player combat state/service and Combat IDE against Decisions #1–#11 without inventing player combat grammar.

It may **not** silently decide unresolved enemy/encounter policy while doing so.

Human acceptance remains authoritative: the state model can be semantically correct and still require numeric/timing/animation tuning if repeated combat feels sluggish, spammy, unreadable, or overly forgiving.

---

## Closure verdict

**Gate 2 player combat state model: COMPLETE / LOCKED.**

Issue #3 may close after repository handoff/register bookkeeping is merged.
