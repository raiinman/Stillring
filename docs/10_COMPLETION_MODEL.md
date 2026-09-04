# 10 — Stillring 100% Completion Model

**Status:** canonical completion contract  
**Related:** `docs/11_QUEST_AND_COMPLETION_LEDGER.md`, `docs/12_100_PERCENT_ROUTE.md`, `docs/13_CANTOR_AND_UPGRADE_CATALOG.md`, `docs/14_PRESTIGE_AND_MASTERY_CONTENT.md`

This document defines what **100% completion means** for Project Stillring.

The detailed named content lives in docs 11–14. This file owns the rules, shipping category counts, and completion semantics.

---

# 1. Goal

Stillring should support a satisfying, auditable 100% playthrough without turning Orra into an icon vacuum.

Completion content must do at least one of these jobs:

1. teach or retest a game verb;
2. reveal character/world information;
3. make an old place newly useful;
4. improve a capability the player already understands;
5. create a cross-region dependency;
6. visibly affect a community or credits-state montage;
7. pay off an earlier authored choice;
8. provide a mastery challenge worth doing for its own sake.

If content does none of those things, it is filler and should be cut even if cutting changes a target count.

---

# 2. Completion philosophy

## C1 — 100% is authored from pre-production

Every region receives its completion inventory before production lock.

Do not finish the main route and then scatter collectibles into empty corners because the world feels sparse.

## C2 — New verbs reopen remembered spaces

Every major verb must create a curated revisit wave.

The player should periodically think:

> I remember somewhere this could work.

The game may help with regional category counts later, but should not immediately convert each new verb into a map covered in icons.

## C3 — Visible promises beat invisible chores

Whenever practical, gated optional content is seen before it is reachable:

- a service hatch above a broken span;
- a flooded pressure housing;
- an odd hollow return from a wall;
- a route strip with no active skiff;
- a contradictory reflection;
- an unstable Hush seam.

The player remembers the world instead of reading a shopping list.

## C4 — 100% must deepen story

Stillring's optional content is part of the narrative fabric.

A completionist should know:

- more workers by name;
- more consequences of Meridian standardization;
- more of Tessa's route network;
- more of Ilyra and Maelor's research history;
- more regional practices that survive the collapse;
- more specific reasons decentralization is difficult but possible.

The critical path remains understandable without those details.

## C5 — No hidden morality grading

A repair contract counts when it reaches a resolved authored state.

100% does not require the developer's preferred moral choice.

Different decisions may alter later work, routes, people, dialogue, or credits images.

## C6 — No random or grind completion

100% must never require:

- random rare drops;
- repeated gambling/loot rolls;
- arbitrary currency accumulation after all purchases are complete;
- perfect leaderboard times unless one explicit mastery threshold is authored;
- repeatable enemies killed a certain number of times with no story/system purpose.

## C7 — No single 'true ending'

The canonical ending is the same core ending for a critical-path player and a 100% player:

- Meridian's central heart is destroyed;
- forced synchronization ends;
- the Hush settles into local seams;
- Maelor survives to face trial;
- communities inherit responsibility for their own systems;
- Neris leaves as a traveling bellwright.

100% changes **specificity and visible consequence**, not whether the player earned the morally correct universe.

---

# 3. Shipping completion taxonomy

The counts below are the current shipping content budget.

They are canonical enough for planning and persistence IDs. They may change only through an explicit content-budget decision that updates docs 10–14 together.

| Category | Shipping target | 100% bearing? | Canonical detail source |
|---|---:|---|---|
| Main story | 1 complete route | yes | Story Bible + doc 12 |
| Local Repair Contracts | 24 | yes | doc 11 |
| Cross-state Setup/Payoff chains | 12 | yes | doc 11 |
| Bellwright Refuges | 11 | yes | doc 11 |
| Resonance Faults | 48 | yes | doc 11 |
| Pulse Shards | 28 | yes | doc 11 |
| Cantor Patterns | 9 | yes | doc 13 |
| Tool Mastery Upgrades | 14 | yes | doc 13 |
| Skill Trials | 9 | yes | doc 14 |
| Micro-vaults / maintenance cavities | 30 | yes | doc 11 |
| Testimonies / field records | 32 | yes | doc 11 |
| Prestige craft quest | 12 stages | yes | doc 14 |
| Drift Knot traversal hunt | 12 targets | yes | doc 14 |
| Optional elite encounters | 8 | yes | doc 14 |
| Community disconnection projects | 6 | yes | doc 14 / story route |
| Mastery complex | 1 | yes | doc 14 |
| Repeatable score improvement | unlimited | no | activity-specific |
| Currency / ordinary materials | variable | no | economy design |
| Random drops | variable | no | never completion-bearing |

---

# 4. Stable completion IDs

Completion state is stored by semantic authored ID, not by scene-tree paths or display strings.

Canonical families:

```text
story.<movement>.<beat>
contract.<region>.<slug>
setup.<region>.<slug>
refuge.<region>.<slug>
fault.<region>.<slug>
pulse.<region>.<slug>
vault.<region>.<slug>
record.<set>.<slug>
pattern.<slug>
upgrade.<tool>.<slug>
trial.<region>.<slug>
prestige.unstandard.<stage>
hunt.<region>.<slug>
elite.<region>.<slug>
community.<region>.<slug>
mastery.broken_standard_yard
```

Display names may change without save migration.

Semantic IDs should not change once save compatibility matters unless a migration is supplied.

---

# 5. Core category rules

## 5.1 Resonance Faults — 48

Resonance Faults are persistent local synchronization defects.

They are the broad exploration track, but are not generic floating tokens.

A Fault may require diagnosis, a major verb, a particular world state, environmental timing, a multi-tool interaction, or understanding from a testimony or pattern.

Threshold rewards arrive during the journey and improve current exploration. The authored ledger may tune exact threshold values during playtest, but the progression must include early fault-family recognition, regional unresolved-count assistance, at least one Cantor diagnostic improvement, one late exploration-quality improvement, and a final narrative/service acknowledgement.

## 5.2 Pulse Shards — 28

Pulse Shards reinforce Neris's field harness/resonance tolerance at refuges.

They are deliberately not shaped/presented as hearts and do not use a four-pieces-equals-one-heart rule.

Their upgrade curve is a tuning problem for prototyping.

## 5.3 Bellwright Refuges — 11

Refuges are authored local workshops/emergency stations.

Discovery/resolution counts toward completion.

They are not magical cave shrines.

## 5.4 Repair Contracts — 24

A contract is a person/community problem expressed through bellwright work.

100% requires the contract to reach a resolved state, not a prescribed moral outcome.

## 5.5 Cross-state Setup/Payoff chains — 12

A setup stores an authored pre-Grand-Ring action whose consequence becomes visible after Stillness.

Completion requires reaching the later payoff state.

The early choice may alter what the payoff problem is.

## 5.6 Cantor Patterns — 9

Patterns are reusable operational tuning procedures.

They are not melodies and should never become memorized note-string keycards.

Every shipping pattern has at least three authored uses outside its acquisition scene.

## 5.7 Tool Mastery Upgrades — 14

Major verbs come from the critical path.

Optional upgrades expand possibility, control, or combination—not only numeric power.

## 5.8 Skill Trials — 9

First completion at the authored mastery threshold counts.

Faster times / higher scores beyond that threshold do not affect 100%.

## 5.9 Micro-vaults — 30

Each compact space should contain one strong 1–5 minute authored idea.

Do not ship thirty reskinned caves.

## 5.10 Testimonies / field records — 32

Records are grouped into meaningful sets rather than a pile of lore notes.

A set may produce active systemic payoff through Palinode, Witness Interval, quest options, or final testimony context.

## 5.11 The Unstandard Tool — 12 stages

The complete prestige quest is required for 100%.

Every stage contains diagnosis, craft, traversal, relationship work, or mechanical action.

Walking an arbitrary object from NPC A to NPC B is not enough.

The reward is the **Freehand Frame** and its unique stance/repair interactions.

## 5.12 Drift Knots — 12

Drift Knots are moving route synchronization faults pursued with the Line Skiff and later verbs.

They are authored/deterministic after unlock.

No random waiting for a spawn.

## 5.13 Optional elites — 8

Elites test combinations the critical path does not require.

Each must have a mechanical identity beyond inflated health/damage.

## 5.14 Community disconnection projects — 6

One major project per region proves the Unringing is something communities **do**, not merely something Neris announces.

All six are required for 100% but not required to reach the canonical ending.

## 5.15 Broken Standard Yard — 1 mastery complex

The mastery complex is the optional synthesis exam.

Completion requires clearing the authored threshold once.

Score optimization afterward does not affect 100%.

---

# 6. Regional allocation contract

Current global allocation from doc 11:

| Region / phase | Contracts | Setups | Refuges | Faults | Pulse | Vaults | Records |
|---|---:|---:|---:|---:|---:|---:|---:|
| Brindle / Cairnspire / First Circuit | 5 | 3 | 3 | 8 | 5 | 6 | 6 |
| Rootmere | 4 | 2 | 1 | 7 | 4 | 4 | 4 |
| Saltreach | 4 | 2 | 1 | 7 | 4 | 4 | 4 |
| Emberstep | 4 | 2 | 1 | 7 | 4 | 4 | 4 |
| High Aerie | 3 | 1 | 2 | 6 | 3 | 3 | 4 |
| Mireglass | 2 | 1 | 1 | 6 | 3 | 3 | 4 |
| Cairnfall | 2 | 1 | 1 | 5 | 3 | 3 | 3 |
| Still-Cairn / Null Meridian | 0 | 0 | 1 | 2 | 2 | 3 | 3 |
| **Total** | **24** | **12** | **11** | **48** | **28** | **30** | **32** |

This allocation is a production budget, not an instruction that every region should feel equally dense.

---

# 7. Revisit-wave requirement

No major region reaches production-complete status with blank revisit responsibilities.

Each region's planning sheet must explicitly record what changes after base-kit exploration, Anchor Line, Glasslung Reed, Temper Gauntlet, Grand Ring / Stillness, Line Skiff, Vane Cloak, Palinode Pattern, Mirror Nail, seam mode, and the Unringing.

Not every region needs content for every verb.

Every major verb does need meaningful old-space payoffs in multiple earlier locations.

---

# 8. 100% route timing

The canonical spoiler route is doc 12.

Completion is intentionally braided through the story rather than deferred.

Broad sweep rhythm:

1. **Opening / First Circuit:** learn completion language, leave visible promises unresolved.
2. **Anchor wave:** revisit remembered structural points.
3. **Glasslung wave:** reopen pressure/water content.
4. **Temper wave:** reopen material-state content, but story urgency limits cleanup before Grand Ring.
5. **Changed-world wave:** see payoff of early authored choices.
6. **Vane / Palinode wave:** vertical and historical reinterpretation.
7. **Mirror wave:** largest optional reopening; old places gain committed echo-state content.
8. **Seam-mode wave:** deepest dual-layer access and late Drift Knot tiers.
9. **Unringing:** natural full-world completion sweep before Null Meridian.
10. **Null Meridian:** final allocated completion content and story completion.

---

# 9. Completion-assist policy

A player pursuing 100% must be able to determine **what categories remain** without external websites.

The game does not have to reveal exact coordinates for every secret.

Early game journal tracking may show discovered items while leaving regional totals unknown.

By the Unringing, Tessa's courier network and Bellwright Refuge records should provide a regional unresolved-category board.

After Ending is learned, specialists may provide stronger physical hints such as:

> “The missing fault sounds downstream of the widow's ferry when river load is high.”

Accessibility settings may permit stronger map assistance.

---

# 10. Save-file percentage

A plain percentage may appear on save select/status for players who want it.

Normal in-world presentation uses authored records:

- work orders;
- refuge stamps;
- fault journal;
- field records;
- tool catalog;
- courier route ledger;
- community disconnection board.

The percentage is computed from completion-bearing authored items, not playtime or currency.

Category weighting should avoid one single 48-item track dominating the entire displayed percentage simply because it contains many IDs.

---

# 11. Point of no return and postgame

Null Meridian should clearly warn the player before committing to the finale.

At that point the completion journal must state whether unresolved world content remains.

The player may continue the story without 100%.

After credits, a save can return to a **pre-Null-Meridian world-state checkpoint** for completion cleanup if the player wants it.

This is a convenience save state, not a canon timeline where Meridian was destroyed and then magically restored for free roam.

100% should be achievable naturally **before** the finale except for completion-bearing content intentionally located inside Null Meridian and the story-complete flag itself.

---

# 12. Credits-state policy

Optional completion affects credits through authored consequence.

Examples include repaired local warning systems, named workers restored to records, independent courier routes, community heat/water/navigation practices, visible Freehand Frame variants, open archives, and additional testimony at Maelor's trial.

No completion state grants a hidden golden universe where every consequence disappears.

---

# 13. Definition of 100%

A save is **100% complete** when:

- the main story has reached credits;
- every shipping item in every category marked **yes** in the completion taxonomy has reached its resolved/completed authored state;
- all 12 cross-state chains have reached a payoff state regardless of which legitimate early branch was chosen;
- all six community projects are complete;
- The Unstandard Tool has reached Stage 12 and the Freehand Frame is assembled;
- all 12 Drift Knots are reconciled;
- all 8 elite encounters are cleared;
- Broken Standard Yard's completion threshold is cleared;
- all final-dungeon completion-bearing content is resolved.

100% does **not** require:

- maximum currency;
- every ordinary material stack;
- perfect minigame times beyond mastery marks;
- every dialogue variant;
- every mutually exclusive branch outcome on one save;
- repeated random drops;
- external knowledge.

---

# 14. Change-control rule

Any addition or removal of a completion-bearing category/item must update, as applicable:

- this document;
- `docs/11_QUEST_AND_COMPLETION_LEDGER.md`;
- `docs/12_100_PERCENT_ROUTE.md`;
- `docs/13_CANTOR_AND_UPGRADE_CATALOG.md`;
- `docs/14_PRESTIGE_AND_MASTERY_CONTENT.md`;
- save-schema documentation;
- relevant regional content sheet;
- tests/fixtures once implemented.

Never change a shipping count in one document and leave the rest inconsistent.
