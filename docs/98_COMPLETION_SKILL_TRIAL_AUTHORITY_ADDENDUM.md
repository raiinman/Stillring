# 98 — Completion Decision #10 — Skill Trial Authority

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #8 — Define 100% completion taxonomy and persistence contract  
**Decision:** #10 — Skill Trial count, mastery-threshold semantics, retry/scoring rules, accessibility, rewards, persistence, IDE, and anti-grind constraints

## Decision question

Do Stillring's current nine Skill Trials all justify completion-bearing status, and exactly what must a player accomplish for a Trial to count without turning 100% into leaderboard grind, perfect-score chasing, or inaccessible twitch execution?

## Fresh research conclusion

**Keep all 9 existing Skill Trials.**

The current catalog survives individual review because each Trial evaluates a different already-taught gameplay relationship rather than merely asking the player to repeat one generic race, combat arena, or score attack nine times.

The decisive rule is:

> **A Skill Trial tests understanding expressed through execution. Completion requires one qualifying mastery clear, not optimization after mastery has already been demonstrated.**

A Trial may use time, pressure, mistakes, resource preservation, target protection, state preservation, or route quality as part of its authored test. But the completion-bearing threshold must be a semantic success condition tied to the tested skill. Faster times, perfect scores, no-damage runs, leaderboard placement, repeated farming, and prestige medals are outside 100% authority.

## Locked philosophy

> **Prove the lesson once. Chase perfection only if you enjoy it.**

## Shipping target — 9

The existing nine-Trial catalog in `docs/14_PRESTIGE_AND_MASTERY_CONTENT.md` is **CONFIRMED**:

1. `trial.circuit.balance_bench` — The Balance Bench;
2. `trial.rootmere.river_tension` — River Under Tension;
3. `trial.saltreach.fogline_pressure` — Fogline Pressure;
4. `trial.emberstep.three_heat_cast` — Three-Heat Cast;
5. `trial.circuit.line_skiff_relay_run` — The Relay Run;
6. `trial.highaerie.crosswind_traverse` — Crosswind Traverse;
7. `trial.mireglass.two_histories` — Two Histories, One Repair;
8. `trial.cairnfall.drift_survey` — Drift Survey;
9. `trial.unringing.no_bell_drill` — The No-Bell Drill.

## Individual catalog validation

### Trial 01 — The Balance Bench
**Tested mastery:** diagnosis before intervention.  
**Qualifying clear:** complete the rig without replacing an unnecessary part.  
**Why it survives:** this measures whether the player can distinguish harmless irregularity from a real fault; it is not speed-gated.

### Trial 02 — River Under Tension
**Tested mastery:** Anchor target choice and load management.  
**Qualifying clear:** stabilize all loads without snapping the sacrificial tether.  
**Why it survives:** failure is tied to misunderstood load handling rather than a generic timer.

### Trial 03 — Fogline Pressure
**Tested mastery:** pressure reading and controlled discharge under reduced visual certainty.  
**Qualifying clear:** keep all three towers at or above safe signal pressure.  
**Why it survives:** the threshold expresses state control, not score accumulation.

### Trial 04 — Three-Heat Cast
**Tested mastery:** maintaining intentionally different thermal states.  
**Qualifying clear:** preserve all three material zones through final set.  
**Why it survives:** this is a direct exam of the thermal grammar already taught.

### Trial 05 — The Relay Run
**Tested mastery:** Line Skiff momentum, junction reading, route choice, and Roadhand Pulse.  
**Qualifying clear:** deliver all three flags before their mechanical clocks expire. Collisions do not automatically fail the Trial.  
**Why it survives:** timing is legitimate here because managing momentum and route timing is the skill itself. The completion threshold remains a generous authored delivery window, not a leaderboard time.

### Trial 06 — Crosswind Traverse
**Tested mastery:** Vane/Anchor coordination under gust load.  
**Qualifying clear:** inspect every node without exceeding the gauge's shock limit.  
**Why it survives:** the player is preserving a meaningful physical state rather than chasing arbitrary speed.

### Trial 07 — Two Histories, One Repair
**Tested mastery:** maintaining incompatible historical evidence while committing a safe present state.  
**Qualifying clear:** preserve both historical records and finish with a functioning present pump.  
**Why it survives:** this is a synthesis exam for Mirror/Palinode understanding, not a collectible or trivia quiz.

### Trial 08 — Drift Survey
**Tested mastery:** reference-frame reading, seam discipline, and safe closure.  
**Qualifying clear:** preserve all three raw readings and safely close every opened seam.  
**Why it survives:** the player must resist false normalization while controlling a dangerous late-game system.

### Trial 09 — The No-Bell Drill
**Tested mastery:** visual combat reading, target switching, and protection under missing audio tells.  
**Qualifying clear:** protect all three relief stations through the drill; player damage is allowed.  
**Why it survives:** the objective measures battlefield reading/protection rather than demanding no-hit combat.

## Mastery-threshold semantics

Every Trial has exactly one completion-bearing **Qualifying Clear** state.

A qualifying clear must:
1. test a gameplay relationship already taught in ordinary play;
2. state the success condition before the attempt begins;
3. derive success from authoritative gameplay/world state rather than opaque scoring math;
4. allow the player to understand why an attempt failed;
5. be achievable without optional prestige optimization;
6. be deterministic enough that identical relevant outcomes do not randomly pass/fail.

A Trial may display optional performance data after a clear, but those values never alter completion percentage once the qualifying clear has settled.

## Scores, times, ranks, and leaderboards

Stillring may retain local personal-best information for players who enjoy mastery chasing, but 100% completion ignores it.

Allowed optional post-clear data:
- best completion time where timing is meaningful;
- mistakes / resets;
- tether breaks avoided;
- pressure margin;
- gauge shock peak;
- damage taken;
- route efficiency;
- authored challenge badges that carry no completion weight.

Forbidden 100% requirements:
- S/A/B rank ladders;
- global or friend leaderboard placement;
- developer par time after the qualifying threshold is already met;
- no-damage clear unless damage avoidance is explicitly the semantic lesson of a future Trial;
- perfect score;
- repeated clears;
- win streaks;
- farming Trial currency.

No Trial gives additional completion percentage for optimization.

## Retry / reset / failure cadence

Trials are practice spaces, not punishment loops.

Locked retry rules:
- failure returns the player to a nearby Trial reset state, not a distant Refuge or long traversal approach;
- restart is available promptly from pause/failure UI;
- intro dialogue/cutscene is skippable after first viewing;
- deterministic setup is restored on retry;
- consumables/resources used only for the Trial are restored or virtualized so practice cannot drain the campaign inventory;
- ordinary campaign state outside the Trial is not rewound except where a clearly isolated Trial instance requires it;
- a failed attempt never creates a completion fact or duplicates a reward;
- abandoning a Trial returns the player to a safe authored exit with pre-Trial campaign ownership intact.

Checkpointing inside a Trial is allowed only if the Trial remains an honest test of the intended combined skill. A checkpoint may not let the player separately brute-force pieces that were explicitly meant to be sustained together.

## Accessibility authority

Accessibility accommodations **do not invalidate a qualifying clear**.

The design target is to preserve the semantic skill while reducing unrelated physical, sensory, or cognitive barriers.

Required accommodation families where applicable:
- full input remapping;
- hold/toggle alternatives;
- alternatives to rapid repeated presses or prolonged holds;
- configurable stick dead zones/sensitivity under existing input authority;
- extended timing windows when exact default timing is not the core semantic skill;
- slowed dynamic elements where doing so preserves the tested relationship;
- stronger non-audio cues for information otherwise carried by sound;
- stronger non-color cues for state distinctions;
- readable objective/failure-reason recap;
- camera/aim assists already allowed by the relevant gameplay authority;
- reduced shake and comfort settings;
- retry without resource loss.

### Timing-specific rule
If timing itself is part of the learned relationship, accommodations may widen the window, slow the environment, or reduce simultaneous demands while preserving the need to make the correct timed decision.

The accommodation must not be treated as a lesser completion state. Completion UI, percentage, rewards, and save-file reporting do not mark an accessible qualifying clear as inferior.

### No blanket prestige gate
No Skill Trial may require optional Tool Mastery Upgrades merely to reach its normal qualifying threshold. A Trial can award an upgrade; it cannot require that reward in advance. Later optional remix/challenge variants may assume optional upgrades, but they carry no base 100% weight unless separately approved.

## Rewards and Tool Mastery relationship

Existing Trial rewards remain conceptually valid subject to their owning category authority:
- several Trials award one of the locked 14 Tool Mastery Upgrades;
- some also award a Pulse Shard or progression into the prestige craft quest;
- Trial 08 awards a component used toward Seam Brace rather than silently granting unrelated power;
- Trial 09 may award its authored combat field-kit modifier, but that modifier must be checked against the final completion/category taxonomy before implementation if it is proposed as a separate completion-bearing item.

A Trial reward settles exactly once on the first qualifying clear.

Repeating a Trial may improve personal-best metadata but cannot duplicate permanent rewards, progression facts, Pulse Shards, upgrade ownership, or completion credit.

## Missability / availability

All nine completion-bearing Trials must remain available during the natural late-game completion sweep.

If world-state changes invalidate an original physical setup, production must provide one of:
- a changed-world version of the same Trial;
- a Refuge/workshop reconstruction;
- an authored simulator/training rig justified by the fiction.

The semantic Trial ID remains stable. Story progression cannot permanently brick 9/9.

## Persistence ownership

The Trial system owns authoritative attempt and qualifying-clear facts.

Completion Ledger derives `trial.<region-or-family>.<slug>` satisfaction from the settled first qualifying clear.

Persist:
- semantic Trial ID;
- unlocked/available state where appropriate;
- first qualifying clear fact;
- reward-settled/idempotency state;
- optional personal-best data if retained;
- relevant accessibility/profile provenance only where needed to reproduce/debug behavior, never as a completion penalty.

Do not persist completion from UI animation, scoreboard display, transient Blueprint state, or leaderboard service response.

Save/load during or immediately after settlement must never duplicate reward or lose a legitimate qualifying clear.

## Trial / Completion System IDE

The shared development workbench must expose:
- Trial semantic ID and owning region/system;
- unlock/availability requirements;
- tested gameplay relationship;
- canonical qualifying-clear predicates;
- live predicate state during an attempt;
- exact failure reason(s);
- active accessibility modifiers relevant to the Trial;
- timer source/window if timing is used;
- reset/checkpoint state;
- campaign resources isolated/restored by the Trial;
- first-clear fact;
- reward settlement/idempotency;
- Completion Ledger reconciliation;
- optional personal-best values clearly separated from completion authority.

Required fixtures:
1. first qualifying clear for each Trial;
2. clear exactly on each boundary threshold;
3. fail just outside each threshold with explicit reason;
4. immediate retry/reset;
5. abandon/re-enter;
6. save/load before clear, during settlement, and after clear;
7. repeated post-clear completion without duplicate reward;
8. accessibility timing/input accommodation still granting equal completion;
9. optional upgrade absent while normal Trial remains completable;
10. leaderboard/personal-best service unavailable with completion unaffected;
11. late-game world-state version remains accessible;
12. 8/9 completion audit identifying the exact missing Trial.

## Red-team / rejection conditions

Reject or revise a Skill Trial if:
- its only identity is "do the same thing faster";
- it uses a hidden score formula the player cannot understand;
- completion requires leaderboard position, rank medals, or repeated grinding;
- normal 100% requires an optional mastery upgrade the Trial itself is meant to award;
- failure creates a long corpse-run/travel tax;
- repeated attempts consume campaign resources without restoration;
- accessibility settings disable completion credit or rewards;
- the Trial relies on audio-only, color-only, mashing, or inaccessible simultaneous-input demands with no accommodation;
- success/failure depends on nondeterministic spawn/RNG behavior;
- save/load can duplicate rewards or erase the qualifying clear;
- world-state progression makes the Trial permanently missable;
- a Trial survives only to preserve the number nine.

## Research basis

Fresh review used current platform accessibility guidance and shipped-game problem-solving references, including:
- Microsoft Xbox Accessibility Guidelines on alternative input methods and game-difficulty grading;
- PlayStation's published God of War Ragnarök accessibility design, including extended puzzle timing and control assists;
- Nintendo's Zelda lineage examples of authored mastery spaces that teach/test existing verbs rather than depending on leaderboard progression.

These sources inform problem-solving principles only. Exact expression, layout, timings, content, rewards, and mechanics remain original Stillring authority.

## Approval

**APPROVED / LOCKED under the owner's scheduled-run delegation.**

### Final locked statement

> **Stillring keeps 9 Skill Trials. Each is a distinct authored exam of a gameplay relationship already taught in ordinary play. One qualifying semantic mastery clear counts toward 100%; faster times, ranks, perfect scores, repeated clears, and leaderboards do not. Accessibility accommodations preserve equal completion/reward authority while reducing unrelated barriers. Trial retries are fast and deterministic, rewards settle once, and no Trial may require its own optional mastery reward in advance.**

## Next decision

Completion Decision #11 — **Prestige craft quest authority: validate whether The Unstandard Tool's 12 authored stages all deserve completion-bearing status, define stage-versus-quest counting, failure/missability/recovery, reward semantics, accessibility, persistence, and anti-fetch-quest constraints.**
