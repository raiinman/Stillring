# Project Stillring — Narrative Flow Red-Team Audit

**Status:** completed verification record  
**Related:** Issue #19, `docs/reference/OOT_100_PERCENT_ANATOMY.md`

This document records the major holes found during the story red-team pass and the canonical repairs now integrated directly into the final story contracts.

It is **not** an authority layer over the scene/reveal/objective/100% documents. Those documents now contain the fixes themselves.

---

# Reference standard

The audit used structural principles extracted from Ocarina of Time without copying protected expression:
- clear human motivation from one beat to the next;
- world ownership before escalation;
- familiar places changed rather than endless replacement locations;
- new verbs reopening remembered spaces;
- optional content braided into the route;
- recurring people and places;
- concise exposition supported by action/environment;
- major traversal transformation seeded before payoff;
- dungeon/encounter variety;
- final synthesis of learned vocabulary.

Stillring's additional target is a more persistent living world: communities change while Neris is absent, relationships recur, and optional actions produce authored consequences.

---

# Resolved blocker 1 — late regions lacked before-memories

## Hole
High Aerie, Mireglass, and Cairnfall originally received their first substantial player visits after Grand Ring, weakening the world-state pivot.

## Repair
The First Circuit now requires compact ordinary-life visits to **all six** regional cultures before Rootmere's full crisis:
- Rootmere ferry / freely moving bell-oak;
- Saltreach harbor meal / working fog signals;
- Emberstep shift change / successful pour;
- High Aerie Wind Kitchen / normal wind span;
- Mireglass reflection game / lantern ferry;
- Cairnfall public observation night.

## Verification
`07_SCENE_BEAT_LEDGER.md` owns scenes `M03-S04` through `M03-S09`; `12_100_PERCENT_ROUTE.md` owns the corresponding optional timing and memory anchors.

**Resolved.**

---

# Resolved blocker 2 — why Maelor needs Neris

## Hole
If Maelor can simply confiscate Ilyra's Key and use trained crews, Neris's Act One role becomes protagonist convenience.

## Repair
Normal Bellwarden diagnostics assume Meridian as master reference. Ilyra's Key can compare local relationships without accepting Meridian first. The Brindle overload damages its field memory and partially calibrates it around Neris; sustained field use drifts away from Neris until safely retrained.

This is circumstance, not destiny.

## Verification
- `M02-S02` physically demonstrates the drift;
- `M03-S11` demonstrates successful independent calibration;
- reveal R02 protects the non-chosen-one interpretation.

**Resolved.**

---

# Resolved blocker 3 — First Ring had no precise causal owner

## Hole
The opening catastrophe was mysterious in a way that left writers themselves unsure whether Maelor, Meridian, the Key, or the ritual caused it.

## Repair
- Meridian is genuinely failing;
- First Ring includes an inherited full-reference check;
- Maelor deliberately disables one emergency damping layer to force hidden drift into the open;
- he expects a containable crisis;
- released Hush pressure is worse than predicted;
- Ilyra's buried Key concentrates the Vale workshop seam;
- Orin is taken by consequence, not targeting.

Maelor's responsibility is real and specific without erasing institutional failure.

## Verification
Authorial truth lives in `01_FOUNDATIONS_AND_OPENING.md`; reveal R04 controls the player-facing discovery sequence; `M07-S02` owns the admission.

**Resolved.**

---

# Resolved high risk 1 — First Circuit fought Orin's urgency

## Hole
“Tour the countryside before rescuing your father” felt like designer pacing rather than character motivation.

## Repair
The damaged Key cannot be trusted until it has independent baselines. A false central calibration may lead Neris away from Orin.

Neris therefore wants the Circuit for the same reason the player wants the story to move forward.

**Resolved.**

---

# Resolved high risk 2 — Line Skiff appeared from nowhere

## Hole
Tessa's post-Grand-Ring vehicle risked feeling like an Act Two convenience.

## Repair
A mothballed Line Skiff appears during the First Circuit at Graymile. Tessa has personal history with the technology and old reinforcement strips are explained before the world needs them.

Post-Grand-Ring acquisition is recognition/payoff.

**Resolved.**

---

# Resolved high risk 3 — Countertones felt like a three-item checklist

## Hole
Ilyra originally introduced Motion, Memory, and Ending together soon after reunion, exposing the second-half structure too cleanly.

## Repair
- Ilyra points only to High Aerie because something there is still changing.
- Player performs the relation before it is named **Motion**.
- High Aerie evidence leads to Bone Archive.
- Palinode and contradiction lead naturally to Mireglass.
- Player performs the relation before it is named **Memory**.
- Cairnfall raw observation detects Orin's workshop state that cannot finish.
- Player releases the perfect workshop before the relation is named **Ending**.

The set can be summarized only after all three were lived.

**Resolved.**

---

# Resolved high risk 4 — Ilyra became an exposition terminal

## Hole
The reunion could have delivered eleven years of cosmology, family history, technical explanation, and the next act plan at once.

## Repair
The reunion is structured as:
1. recognition;
2. anger;
3. wrong workbench / wrong breakfast / wrong drawer;
4. practical Key repair;
5. minimum necessary admissions;
6. one immediate problem: something at High Aerie still moves.

Ilyra's remaining truth arrives through Bone Archive and Mireglass evidence.

**Resolved.**

---

# Resolved high risk 5 — Maelor explained evidence the heroes already possessed

## Hole
The Grand Ring confrontation risked becoming a villain lecture.

## Repair
By Emberstep, Neris/Tessa/Sena/Caldrin/Rusk can derive three-point entrainment themselves. They go to Maelor to stop activation.

Maelor supplies only information they cannot prove: his intent, his First Ring intervention, deliberate site selection, and the already-committed first entrainment step.

The confrontation happens while everyone physically acts.

**Resolved.**

---

# Resolved medium risk — boss moral grammar repeated too often

## Hole
Too many major encounters risked using “the monster was actually an innocent victim of the system.”

## Repair
- Mossjaw: ordinary territorial animal.
- Mawhart: liberation encounter.
- Leviathan: current abuse stopped, but accumulated damage later kills it.
- Cinder Regent: unambiguous hazardous machine.
- Choir of Talons: ordinary predators exploiting changed conditions.
- Varo/Mirror/Gravemoon retain distinct later narrative grammar.

**Resolved.**

---

# Resolved medium risk — side content became thematic homework

## Hole
Too many optional interactions could reduce Orra to people independently explaining the central thesis.

## Repair
Optional content is balanced among:
- **theme-bearing** interaction;
- **character-bearing** interaction;
- **life-bearing** interaction with no completion requirement.

Examples include meals, games, bad tools, nicknames, petty competitions, children misreporting stories, local jokes, and ordinary work.

See `17_SIDE_INTERACTION_REBALANCE.md`.

**Resolved as authoring rule; playtest remains responsible for density.**

---

# Resolved medium risk — world froze when Neris left

## Hole
Regional bibles had recurrence, but the critical path did not guarantee enough visible offscreen change.

## Repair
`12_WORLD_PULSE_LEDGER.md` now tracks offscreen action after each major milestone: investigations advance, rumors travel, jobs move, local preparations begin, courier copies spread, and communities start disconnection attempts after Cairnfall without waiting for Neris.

**Resolved as state-design contract.**

---

# Resolved medium risk — emotional intensity stacked too long

## Repair
Protected breathing beats now include:
- First Circuit ordinary-life postcards;
- Rootmere evening;
- Saltreach road after Leviathan news;
- wrong-breakfast/workbench interaction with Ilyra;
- first fun Line Skiff stretch;
- Wind Kitchen after Motion;
- silent road after Bone Archive;
- free-roam interval after Mercy Window;
- Cairnfall public-sky calm;
- Unringing meals and ordinary repair life.

See `13_EMOTIONAL_PACING_MAP.md` and `14_QUIET_MOMENTS_AND_TRAVEL_BEATS.md`.

**Resolved.**

---

# Resolved medium risk — final Listener temptation was generic

## Hole
Generic “perfect family” alternate worlds would not capitalize on the living-world work.

## Repair
Where feasible, Listener sequences draw from actual save-state memories: ferry, Wind Kitchen, reflection game, public sky, Crooked Fire Bell, optional recurring people, and beloved imperfections.

The trap is not perfection. It is **the imperfect world the player loved, held forever**.

**Resolved as finale contract.**

---

# Resolved thematic risk — every region taught the same politics

## Repair
The final story explicitly preserves cases where shared standards are useful:
- watershed flood coordination;
- harbor timing;
- industrial safety constraints;
- archive evidence discipline;
- compatible survey coordinates.

The problem is coerced singularity, hidden assumptions, and unaccountable authority—not “standards bad.” Local autonomy can fail visibly too.

**Resolved.**

---

# Final OoT-principle verification

| Principle | Stillring implementation | Result |
|---|---|---|
| Clear next motivation | Orin → trustworthy Key → crisis evidence → stop Maelor → moving relation → old rescue record → Mireglass → Orin signal → Unringing → Null | Pass |
| World before escalation | Six-region First Circuit + Brindle/Cairnspire ordinary life | Pass |
| Recontextualized familiar places | Grand Ring montage and all changed-world returns use before-memories | Pass |
| New verbs reopen old spaces | Anchor, Glasslung, Temper, Palinode, Mirror, seam waves | Pass |
| Side content braided into route | 100% route integrates completion by story windows | Pass |
| Recurring people | regional bibles + world pulse + credits recurrence | Pass |
| Exposition restraint | Maelor/Ilyra information moved into playable evidence and work | Pass |
| Traversal transformation seeded | Line Skiff at Graymile before Grand Ring | Pass |
| Encounter variety | distinct boss narrative grammar | Pass |
| Final synthesis | Null Meridian recombines learned tools/relations | Pass |
| Living-world extension beyond reference | offscreen regional change and save-state-sensitive callbacks | Pass |

---

# Final human-motivation chain

The story now reduces cleanly to:

**Orin is taken → Neris needs a trustworthy way to find him → the damaged Key needs the world as calibration → the regional repairs reveal that Maelor chose the route → Neris tries to stop him and fails → Ilyra helps Neris survive the altered world → High Aerie's continuing motion leads to older rescue history → that contradiction leads to Mireglass and the complete family truth → Cairnfall finds Orin's repeating signal → freeing Orin teaches how a preserved state can end → communities begin disconnecting → their independent signals open Null Meridian → Neris dismantles the central hold instead of restoring it.**

That is the final flow standard future implementation must preserve.