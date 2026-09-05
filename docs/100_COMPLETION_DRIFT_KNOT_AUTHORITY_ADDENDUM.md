# 100 — Completion Decision #12 — Drift Knot Authority

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #8 — Define 100% completion taxonomy and persistence contract  
**Decision:** #12 — Drift Knot count, deterministic moving-route behavior, resolution semantics, retry/reacquisition, rewards, accessibility, persistence, IDE, and anti-spawn-grind rules

## Decision question

Do the existing twelve Drift Knots all deserve completion-bearing status, and how should a moving traversal hunt work so that it rewards route reading and system synthesis rather than random spawn camping, repeated racing, or following an audio beep until the game gives up?

## Fresh research conclusion

**Keep all 12 existing Drift Knots.**

The catalog survives individual review because the twelve targets are distributed across distinct routes and progressively combine Line Skiff traversal with Anchor, Glasslung, Temper, Vane, Palinode, Mirror, Fine Fork, seam mode, and Switchshoe relationships. They are not twelve cosmetic copies of one chase.

Each Knot counts once when the player **reconciles its synchronization fault through the correct authored reference window**. Merely entering the route, seeing the Knot, touching its visual effect, or riding near it does not count.

The decisive rule is:

> **A Drift Knot is an authored moving fault with a learnable route, not a random collectible that happens to move.**

## Locked philosophy

> **Track the pattern. Catch the window. Repair the road.**

## Shipping target — 12

The existing catalog in `docs/14_PRESTIGE_AND_MASTERY_CONTENT.md` is **CONFIRMED**:

1. `hunt.circuit.graymile_bellwake` — Graymile Bellwake;
2. `hunt.rootmere.reedrunner` — Reedrunner;
3. `hunt.saltreach.breakwater_skip` — Breakwater Skip;
4. `hunt.emberstep.ashline` — Ashline Flicker;
5. `hunt.cairnspire.outer_loop` — Outer Loop Stutter;
6. `hunt.highaerie.downline` — Downline Crosswind;
7. `hunt.mireglass.reedglass_flicker` — Reedglass Flicker;
8. `hunt.cairnfall.night_arc` — Night Arc;
9. `hunt.rootmere.afterimage` — Rootmere Afterimage;
10. `hunt.saltreach.false_harbor` — False Harbor Line;
11. `hunt.emberstep.quench_runner` — Quench Runner;
12. `hunt.meridian.blackline` — Blackline Knot.

## Individual catalog validation

### 1 — Graymile Bellwake
**Core test:** baseline Line Skiff pursuit + Cantor window.  
**Why it survives:** establishes the moving-fault grammar with no extra late-game trick.

### 2 — Reedrunner
**Core test:** moving route pursuit plus Anchor timing at a damaged reinforcement strip.  
**Why it survives:** introduces active structural intervention rather than pure steering.

### 3 — Breakwater Skip
**Core test:** coastal route tracking plus Glasslung pressure gate.  
**Why it survives:** forces pressure-state reading inside a moving route problem.

### 4 — Ashline Flicker
**Core test:** freight-route pursuit plus Temper access to a jammed switch housing.  
**Why it survives:** route choice is connected to authored thermal machinery state.

### 5 — Outer Loop Stutter
**Core test:** Line Skiff junction transfer using Switchshoe.  
**Why it survives:** tests network routing rather than top-speed racing.

### 6 — Downline Crosswind
**Core test:** descending route control with Vane + Crosswind Measure.  
**Why it survives:** introduces wind/reference handling while the target remains mobile.

### 7 — Reedglass Flicker
**Core test:** Palinode distinguishes two apparent moving targets.  
**Why it survives:** the challenge is identifying which observed route history is real enough to reconcile.

### 8 — Night Arc
**Core test:** timed observation-window pursuit.  
**Why it survives:** the authored observation window is part of the fiction/system, not a random real-world spawn schedule.

### 9 — Rootmere Afterimage
**Core test:** Mirror Nail commits one false branch while the Knot takes another.  
**Why it survives:** moving pursuit becomes state-branch control rather than speed alone.

### 10 — False Harbor Line
**Core test:** Mirror + Line Skiff through Hush-bleeding coast.  
**Why it survives:** route continuity itself becomes unreliable and must be interpreted.

### 11 — Quench Runner
**Core test:** Fine Fork separates the Knot from machinery noise.  
**Why it survives:** signal discrimination becomes the meaningful challenge.

### 12 — Blackline Knot
**Core test:** seam mode + Switchshoe + Fine Fork synthesis.  
**Why it survives:** final hunt combines the route/fault language rather than merely increasing speed.

## Deterministic availability

Drift Knots are deterministic authored world activities.

Rules:
- no random spawn percentage;
- no server clock / daily rotation;
- no real-world waiting;
- no despawn because another activity was completed;
- each Knot has an authored route corridor, movement state graph, and availability gate;
- once its gate is met, the Knot remains recoverably available until resolved;
- weather/world-state variants may alter presentation or route difficulty only if a valid authored route remains.

The journal/map may provide a broad route sector or courier report, but not a GPS marker glued permanently to the moving Knot.

## Unlock-threshold reconciliation

`docs/14` currently says the hunt family unlocks after Line Skiff + the first **13 Resonance Faults**.

Completion Decision #2 reduced Resonance Faults from 48 to 36. Therefore:
- the hunt still begins at an **early-to-mid Fault-track milestone** after Line Skiff acquisition;
- the literal `13` is **PROVISIONAL / SUPERSEDED AS FIXED AUTHORITY**;
- cumulative Issue #8 reconciliation must choose the final numeric milestone against the 36-Fault cadence;
- implementation must not hardcode 13/48-era assumptions until that reconciliation is complete.

## Tracking and chase semantics

A Knot moves according to authored route logic rather than teleporting randomly.

The player should be able to learn:
- which route family it occupies;
- whether its signal is strengthening/weakening;
- branch/junction tendencies;
- the extra tool/state relationship needed for interception;
- the correct reference window for reconciliation.

Tracking uses **redundant sensory channels**:
- Cantor/audio signature;
- visual phase/reference indicator;
- optional haptic pattern;
- route/environment reaction where appropriate.

No essential target identity or direction is audio-only.

## Resolution event

A Drift Knot counts when:
1. the correct semantic Knot is active and eligible;
2. Neris reaches the authored reconciliation condition/window;
3. any Knot-specific gate/tool state is valid;
4. the Cantor reconciliation transaction succeeds;
5. the resulting route correction settles into persistent world state.

Completion Ledger then satisfies the unique `hunt.*` semantic ID exactly once.

Riding through the Knot without the valid reconciliation state does not count.

## Failure / loss / reacquisition

Losing a Knot should cost attention, not ten minutes of dead road.

Rules:
- if the target moves beyond tracking range, the player receives a clear lost-signal state rather than silent failure;
- the Knot continues or returns to a deterministic authored route phase;
- reacquisition starts from the nearest reasonable route sector/report state, not from repeating an entire long approach;
- ordinary collision or a missed branch is recoverable unless a particular authored hazard legitimately ends the attempt;
- local failure never permanently consumes the Knot;
- abandonment returns the hunt to a stable recoverable state;
- no consumable "hunt ticket" or retry currency exists.

## Anti-route-grind authority

A resolved Knot is permanently resolved for completion.

No completion requirement for:
- beating a time record;
- repeating the chase at higher speed;
- clearing every possible branch;
- collecting drops during the chase;
- farming route currency;
- maintaining a streak;
- resolving the same Knot in multiple world states.

Optional personal-best chase data may exist for fun, but it carries no completion weight and no unique mandatory reward.

## Rewards

Intermediate rewards in `docs/14` remain allowed because they are varied contextual payoffs rather than a universal currency ladder.

Rules:
- each target reward settles once;
- reward value must not become the only reason a Knot exists;
- no randomized loot table is required to justify replay;
- duplicate resolution cannot duplicate permanent progression or rare components.

### Final reward — Route Listener
After all 12 are resolved, Tessa installs the **Route Listener** service into the Line Skiff dock network.

Locked function:
- when the player enters/uses an eligible road sector, the service may indicate whether unresolved **route-class Fault work or courier service** remains in that sector;
- it does not reveal treasure, puzzle answers, unrelated collectibles, secret doors, or exact coordinates;
- it is a completion-assist/readability service earned by mastering the route network, not a universal radar.

The final service settles once at 12/12.

## Accessibility authority

Accessibility accommodations retain full completion and reward authority.

Required support where applicable:
- remappable Skiff/Cantor/tool inputs;
- configurable steering sensitivity/dead zones under existing input authority;
- steering assistance that reduces motor burden without selecting the correct route branch automatically;
- reduced camera shake / motion effects;
- stronger route-edge and junction readability;
- visual/haptic equivalents for Knot audio-signature direction and phase;
- widened reconciliation windows;
- reduced Knot relative speed or slowed environmental timing where needed;
- stronger signal-strength indicators;
- pause-safe objective review;
- no rapid-mash or mandatory simultaneous-input gate without alternate input.

An accommodation may reduce steering/timing burden while preserving the need to identify the target, choose the relevant route/state response, and reconcile it correctly.

Accessible resolution is not marked as inferior and awards identical completion/rewards.

## Night Arc timing rule

Night Arc's "specified observation window" is **in-world authored availability**, not a real-world daily timer.

If the player arrives outside the observation state:
- the journal/environment clearly communicates the required in-world condition;
- waiting may be accelerated through established rest/time systems where compatible with world authority;
- missing one window cannot force a long real-time wait;
- accessibility can widen the active observation period if needed without changing the underlying reference-frame concept.

## Missability / changed-world routes

All 12 must remain resolvable during the natural completion sweep.

If a road is damaged/closed/rebuilt by later world state:
- provide a changed-world authored route variant or credible relocated reinforcement strip;
- preserve the same semantic Knot ID;
- preserve the Knot's core tool/reference test;
- do not silently auto-complete the Knot because its original road disappeared.

## Persistence ownership

Route/World State owns Knot movement eligibility and resolved route correction.

Persist:
- semantic Knot ID;
- availability/gate state;
- resolved/unresolved fact;
- route variant where necessary;
- reward-settled idempotency;
- final Route Listener unlock fact.

Transient chase position does not need exact frame-perfect persistence unless save design explicitly supports mid-chase saving. If loading resumes from a stable reacquisition state, it must do so predictably without duplicating rewards or losing a legitimate resolution.

Completion Ledger derives each `hunt.*` item from the settled route-correction fact.

## Hunt / Traversal / Completion System IDE

The shared workbench must expose:
- Knot semantic ID;
- availability prerequisites;
- authored route corridor/state graph;
- current route branch/phase;
- raw + processed signal strength/direction;
- sensory cue outputs;
- required tool/reference gate;
- tracking / lost / reacquiring / reconciliation state;
- reconciliation-window bounds;
- active accessibility modifiers;
- failure/retry/reacquisition reason;
- world-state route variant;
- resolved fact;
- reward/idempotency state;
- Completion Ledger reconciliation;
- Route Listener 12/12 derivation.

Required fixtures:
1. each Knot available at correct gate;
2. unavailable before gate with explicit reason;
3. acquire/lose/reacquire signal;
4. wrong branch / missed junction recovery;
5. correct reconciliation at window boundary;
6. invalid reconciliation rejected with reason;
7. accessibility visual-only tracking with audio muted;
8. steering/timing assist still producing equal completion;
9. abandon/re-enter hunt;
10. save/load before, during, and immediately after resolution;
11. duplicate reward blocked;
12. changed-world route variant;
13. 11/12 completion audit;
14. Route Listener unlock exactly once.

## Red-team / rejection conditions

Revise a Drift Knot if:
- it uses RNG spawn camping;
- it can become permanently unavailable through ordinary story progress;
- the only difference from another Knot is target speed;
- audio is the only practical tracking channel;
- failure forces a full long-route replay with no meaningful new decision;
- completion requires a par time, score, streak, or repeated clear;
- random loot farming becomes the replay incentive;
- assists disable completion/rewards;
- a changed-world road bricks the target;
- save/load duplicates reward or loses resolution;
- Route Listener turns into universal collectible radar;
- a target survives only to preserve the number twelve.

## Research basis

Fresh review used:
- the existing 12-target catalog in `docs/14_PRESTIGE_AND_MASTERY_CONTENT.md`;
- current platform accessibility guidance emphasizing remapping, alternative input, visual comfort, and redundant interaction channels;
- modern Zelda route/history assistance as design-lineage evidence that completion support can point players toward unexplored/unresolved spaces without solving the activity itself.

These references inform design problems only. Drift Knot fiction, routes, tools, names, mechanics, rewards, and implementation remain original Stillring authority.

## Approval

**APPROVED / LOCKED under the owner's scheduled-run delegation.**

### Final locked statement

> **Stillring keeps 12 Drift Knots as deterministic authored moving route faults. Each counts once only when its correct reconciliation transaction settles; random spawning, replay grind, par times, and audio-only tracking are forbidden. Lost targets are recoverably reacquired without full-route punishment, accessibility assists retain equal authority, changed-world routes preserve availability, and 12/12 unlocks the bounded Route Listener service rather than universal radar. The old 13-Fault family unlock is provisional and must be recalibrated against the locked 36-Fault track.**

## Next decision

Completion Decision #13 — **Optional Elite Encounter authority: validate the current elite catalog/count, what qualifies as an elite completion, repeat/failure/reward rules, accessibility, persistence, IDE, and anti-respawn-farm / anti-health-sponge constraints.**
