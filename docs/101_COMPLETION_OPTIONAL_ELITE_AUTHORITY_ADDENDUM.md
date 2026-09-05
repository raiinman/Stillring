# 101 — Completion Decision #13 — Optional Elite Encounter Authority

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #8 — Define 100% completion taxonomy and persistence contract  
**Decision:** #13 — elite catalog/count, qualification rules, one-time resolution, retry/revisit, reward discipline, accessibility/difficulty, persistence, IDE, and anti-health-sponge constraints

## Decision question

Do Stillring's existing eight Optional Elite Encounters all justify completion-bearing status, and how do we guarantee they remain authored mastery fights rather than palette swaps, gear checks, inflated health bars, or repeat-farm chores?

## Fresh research conclusion

**Keep all 8 existing Optional Elite Encounters.**

The catalog survives individual review because each encounter is built around a different already-learned system relationship. Their identity comes from the decision they force under pressure, not merely enemy durability or damage output.

Each elite counts exactly once when its unique authored encounter reaches its settled resolution state. Repeat kills, respawns, better times, no-damage runs, challenge difficulty, and loot farming carry no additional completion weight.

The decisive rule is:

> **An elite earns completion status by testing a learned system under pressure, not by taking longer to kill.**

## Locked philosophy

> **Harder should mean more demanding decisions—not more sponge.**

## Shipping target — 8

The existing elite catalog in `docs/14_PRESTIGE_AND_MASTERY_CONTENT.md` is **CONFIRMED**:

1. `elite.rootmere.ironbound_keeper` — The Ironbound Keeper;
2. `elite.saltreach.breakwater_mother` — Breakwater Mother;
3. `elite.emberstep.whitehot_inspector` — Whitehot Inspector;
4. `elite.highaerie.three_rooks` — The Three Rooks;
5. `elite.mireglass.reed_magistrate` — Reed Magistrate;
6. `elite.cairnfall.orrery_bailiff` — Orrery Bailiff;
7. `elite.circuit.court_pursuer` — Quiet Court Pursuer;
8. `elite.stillcairn.safety_inspector` — The Safety Inspector.

## What qualifies as an Optional Elite

A completion-bearing elite must satisfy all of:
1. stable semantic encounter identity;
2. authored arena/route/world context that materially affects the fight;
3. at least one distinct pressure relationship beyond ordinary enemy behavior;
4. meaningful use of previously taught player systems;
5. readable counterplay that can be explained in gameplay terms;
6. one authoritative resolution state with persistent world/completion ownership;
7. difficulty that comes primarily from decision density, coordination, positioning, state management, or synthesis—not raw health inflation.

An enlarged ordinary enemy with a different color, doubled health, and a rare drop does **not** qualify.

## Individual catalog validation

### E01 — The Ironbound Keeper
**System exam:** target switching + Anchor interrupts + environmental load.  
**Why it survives:** the player must choose brace components and manage heavy sweep pressure instead of simply burning a large health pool. Breaking/redirecting its load behavior is the encounter grammar.

### E02 — Breakwater Mother
**System exam:** pressure-lane management + core melee.  
**Why it survives:** pressure state changes safe spatial lanes in the arena. The fight asks the player to manipulate the environment while maintaining ordinary combat readability.

### E03 — Whitehot Inspector
**System exam:** unequal thermal-state maintenance while fighting.  
**Why it survives:** the enemy attempts to normalize the arena, directly attacking a learned thermal principle rather than just dealing more damage.

**Optional-upgrade dependency:** Quench Collar remains a valid explicit prerequisite under `docs/97` because advanced optional content may advertise and require a specific optional mastery capability. Trial 04 awards it before this elite becomes part of the natural 100% route. The dependency must be visible and non-circular; the elite may not award the prerequisite it requires.

### E04 — The Three Rooks
**System exam:** visual threat reading + target switching + Vane positioning against three coordinated roles.  
**Why it survives:** feint/displacement/strike roles create an aggression-budget problem instead of three simultaneous damage sponges. Existing encounter-readability authority remains binding.

### E05 — Reed Magistrate
**System exam:** contradictory-state preservation under combat pressure.  
**Why it survives:** the construct removes arena routes/cover from disfavored states, requiring Mirror/Palinode understanding to create openings while still fighting.

### E06 — Orrery Bailiff
**System exam:** adaptation against repeated reference-frame/tool strategy.  
**Why it survives:** it reacts to overused orientation/tool assumptions and rewards deliberate variation. The adaptation must remain readable; it cannot secretly inspect controller inputs and arbitrarily counter whatever the player presses.

### E07 — Quiet Court Pursuer
**System exam:** Line Skiff approach → mixed on-foot combat/diagnosis.  
**Why it survives:** the encounter crosses traversal and combat grammars and uses capture-field pressure rather than merely escalating lethality.

**Prestige quest dependency:** its access token may satisfy The Unstandard Tool Stage 11's elite requirement. Clearing E07 once settles the elite resolution and the token fact; Prestige Stage 11 must recognize that existing fact. The player is never required to replay E07 merely because the prestige quest is advanced later.

### E08 — The Safety Inspector
**System exam:** Ending-logic preview—release useful safe states while surviving forced restoration.  
**Why it survives:** it previews late synthesis through playable state decisions rather than raw combat escalation.

## Health / damage / duration ceiling

Elite tuning may exceed ordinary enemies, but identity may not depend on numerical bloat.

Required tuning review:
- health must support enough repetitions to learn/read the mechanic, then get out of the way;
- stagger/interrupt resistance must have semantic reasons, not blanket immunity;
- damage must preserve readable consequences without turning every mistake into a one-shot gear check;
- phases must change pressure relationships, not simply refill health;
- encounter length must remain bounded enough that a late failure does not turn a learning fight into an endurance tax.

If playtest feedback says "I understood it two minutes ago and am still chewing the bar," the elite fails review.

## Gear / upgrade authority

Completion-bearing elites may require clearly advertised story verbs and, in limited cases, specific completion-bearing mastery upgrades already locked elsewhere.

They may **not** require:
- hidden gear score;
- random rare equipment;
- farming materials to reach a damage threshold;
- all optional upgrades as a generic power check;
- prestige optimization or leaderboard performance;
- the Freehand Frame unless a future explicit revision changes an encounter's authored identity.

Critical-path completion remains valid without clearing any of the eight elites.

## Resolution event

An elite counts when its authoritative encounter result reaches `Resolved/Cleared` and any required world-state consequence settles.

Completion Ledger then satisfies the unique `elite.*` semantic ID once.

Completion is **not** derived from:
- enemy death animation alone;
- loot pickup;
- arena exit;
- achievement popup;
- scoreboard/time result;
- temporary Blueprint destruction;
- repeated respawn kill count.

Where an elite is a construct/system that is released, disabled, reconciled, or redirected rather than literally killed, that authored resolution is the completion event.

## Failure / retry cadence

Elite encounters are optional mastery tests, not corpse-run punishment.

Locked rules:
- local failure returns to a nearby safe encounter approach/reset point;
- repeated intro cinematics/dialogue are skippable after first view;
- deterministic encounter setup is restored;
- stage/arena-only consumables are restored or virtualized;
- ordinary campaign resources are not arbitrarily deleted beyond normal existing combat rules;
- retry does not reroll an easier/harder elite variant;
- quitting/abandoning restores a stable unresolved encounter state;
- a failed attempt never settles reward/completion facts.

Long traversal back from a distant Refuge cannot be the default penalty for learning an elite.

## Respawn / revisit

The unique semantic elite encounter does **not** respawn as fresh completion content after resolution.

Production may support one of these non-completion forms where fiction allows:
- post-clear arena practice simulation;
- related ordinary enemy variants elsewhere;
- encounter replay from a development/training surface;
- changed-world visual aftermath.

But the original `elite.*` completion fact stays resolved and permanent. Replays cannot duplicate rewards or alter completion percentage.

## Rewards

Existing contextual rewards in `docs/14` remain conceptually valid:
- rare tool materials;
- prestige clues/tokens;
- Pulse service credit;
- Maker/Testimony routes;
- seam component;
- field-kit modifier / late Pulse clue.

Rules:
- unique/permanent reward settles once;
- no random loot table is necessary for completion;
- no elite-specific currency grind;
- reward is not used to justify an otherwise weak encounter;
- duplicate replay cannot duplicate permanent progression.

### Cross-system reward idempotency
E07's Prestige Stage 11 access token and any other cross-system result are persistent semantic facts. If the receiving quest/category is not yet active, the fact waits; the player does not repeat the elite later to "re-earn" it.

## Difficulty / accessibility authority

**Any supported gameplay difficulty and accessibility configuration may earn the same elite completion and rewards.**

The project may tune damage, enemy aggression, assist strength, timing leniency, lock-on/camera assistance, or checkpoint support according to global difficulty/accessibility policy without creating a lesser completion tier.

Current shipped-game accessibility precedent demonstrates that combat assists, lock-on variants, evade assistance, reduced repeated-button burden, motion reduction, and miniboss checkpoint support can coexist with authored combat challenges. Stillring uses those ideas only as problem-solving references; exact implementation follows its own authority.

Required support where applicable:
- remappable combat/tool inputs;
- hold/toggle alternatives under existing control authority;
- no mandatory rapid mashing without alternate input;
- readable threat telegraphs through redundant visual/audio/haptic channels;
- non-color-only arena state indication;
- reduced shake/motion effects;
- camera/lock-on assists consistent with locked camera authority;
- timing/defense windows adjustable where global accessibility policy permits;
- aggression/damage tuning that preserves the encounter's semantic relationship;
- nearby retry/checkpoint support.

Accessibility may reduce motor/timing burden while preserving the meaningful decision the elite tests. Completion UI never labels an assisted clear inferior.

## Multi-enemy readability — Three Rooks

The Three Rooks must obey locked camera/encounter readability principles:
- only a readable number of high-salience attacks may commit simultaneously;
- feint/displacement/strike roles are telegraphed distinctly;
- offscreen pressure receives appropriate restraint/signaling;
- the camera is not forced into tactical zoom-out to compensate for bad aggression design;
- target switching remains player intent, not automatic roulette.

If human play cannot parse who is actually attacking, reduce encounter concurrency rather than adding UI clutter to excuse it.

## Missability / world-state recovery

All eight completion-bearing elites remain resolvable during the natural late-game completion sweep.

If a location changes:
- preserve an authored changed-world encounter variant or credible relocated encounter context;
- keep the same semantic elite ID and core mastery relationship;
- do not auto-complete because the original arena disappeared;
- prior resolution remains resolved through world transitions.

No ordinary story phase permanently bricks 8/8.

## Persistence ownership

Encounter/World State owns elite resolution.

Persist:
- semantic elite ID;
- availability/prerequisite state;
- resolved/unresolved fact;
- changed-world arena variant where relevant;
- unique reward-settled/idempotency facts;
- cross-system token/clue outputs;
- optional personal-best/replay metadata only if retained, completely separate from completion authority.

Completion Ledger derives each `elite.*` item from the settled encounter resolution fact.

Save/load at the final hit/resolution boundary must neither lose the clear nor duplicate rewards.

## Encounter / Combat / Completion System IDE

The shared workbench must expose:
- semantic elite ID;
- availability prerequisites and rejection reasons;
- encounter phase/state;
- current systemic pressure mechanic;
- health/stagger/interrupt values with canonical/session/staged provenance;
- active targets/aggression roles;
- arena-system state (pressure/heat/reference/etc.);
- incoming attack telemetry and readable telegraph classification;
- current accessibility/difficulty modifiers;
- failure/reset/checkpoint state;
- resolved fact;
- reward/idempotency outputs;
- cross-system quest/token facts;
- Completion Ledger reconciliation.

Required fixtures:
1. each elite unavailable before its explicit gate;
2. first valid encounter clear;
3. death/failure early/mid/late → nearby deterministic retry;
4. save/load immediately before and after resolution;
5. duplicate reward blocked;
6. supported low/high difficulty clears earn identical completion;
7. accessibility assist clear earns identical completion/reward;
8. health-sponge tuning detector / human duration review marker;
9. E03 Quench Collar prerequisite explicit and non-circular;
10. E07 clear before Prestige Stage 11 → later quest recognizes token without replay;
11. E07 clear during Stage 11 → same one-time fact;
12. Three Rooks aggression/readability matrix;
13. changed-world arena availability;
14. 7/8 completion audit identifying exact missing elite.

## Red-team / rejection conditions

Revise or remove an elite if:
- its identity is primarily extra health/damage;
- it is a palette/model swap with ordinary behavior;
- it requires hidden gear score or random-drop farming;
- it becomes mandatory for critical-path story completion;
- it requires broad optional-upgrade ownership rather than a clear authored gate;
- it uses RNG spawn/respawn farming;
- completion depends on par time, rank, no-hit, difficulty mode, or repeat count;
- a failed attempt requires a long corpse run unrelated to mastery;
- accessibility/difficulty settings disable completion or rewards;
- world-state progression makes it permanently missable;
- save/load can duplicate unique reward or lose the clear;
- its system mechanic is unreadable and compensated only by more HUD markers;
- it survives only to preserve the number eight.

## Research basis

Fresh review used:
- the full eight-elite catalog in `docs/14_PRESTIGE_AND_MASTERY_CONTENT.md`;
- locked Stillring combat/camera/tool authorities defining target ownership, readability, tool semantics, and optional-power boundaries;
- PlayStation's current published God of War Ragnarök accessibility options as shipped-game evidence that combat assists, lock-on variants, motor accommodations, motion reduction, and miniboss checkpointing can preserve participation in demanding encounters;
- Nintendo's Zelda design lineage as problem-level evidence that combat depth comes from varied attacks, tools, environment, and resourceful response rather than health inflation alone.

These references inform design problems only. Elite identities, mechanics, arenas, rewards, tuning, and implementation remain original Stillring authority.

## Approval

**APPROVED / LOCKED under the owner's scheduled-run delegation.**

### Final locked statement

> **Stillring keeps 8 Optional Elite Encounters because each is an authored exam of a distinct learned system under combat pressure. Each unique elite resolves once; repeat kills, ranks, difficulty modes, loot farming, and health inflation do not add completion weight. Difficulty/accessibility assists retain equal completion authority, retries are nearby and deterministic, rewards/cross-system outputs settle idempotently, and no elite may become a hidden critical-path gear check.**

## Next decision

Completion Decision #14 — **Community Disconnection Project authority: validate the current six regional projects, define project completion versus prerequisite checklist weight, critical-path/100% boundary, changed-world persistence, accessibility, IDE, and anti-tower-shutdown / anti-fetch-project constraints.**
