# 12 — Final 100% Narrative Route

**Status:** final canonical spoiler route for story timing and completion sequencing  
**Related:** `docs/02_STORY_BIBLE.md`, `docs/story/07_SCENE_BEAT_LEDGER.md`, `docs/story/08_REVEAL_AND_FORESHADOW_LEDGER.md`, `docs/story/09_MAIN_QUEST_OBJECTIVE_FLOW.md`, `docs/11_QUEST_AND_COMPLETION_LEDGER.md`, `docs/13_CANTOR_AND_UPGRADE_CATALOG.md`, `docs/14_PRESTIGE_AND_MASTERY_CONTENT.md`

This is the authoritative spoiler-heavy route for a complete Stillring save.

It does **not** prescribe one exact order for every optional activity. It records:
- what the critical path is doing at every phase;
- what Neris and the player may know;
- what optional stories are available and why they matter;
- when new verbs reopen remembered places;
- when regional people recur;
- when setup choices pay off;
- where narrative urgency should suppress cleanup nudges;
- how a player can reach 100% without the final hours becoming icon archaeology.

The core rule is:

> **100% should feel like living through more of Orra, not postponing the ending until every icon is vacuumed off the map.**

---

# 0. Route-wide continuity rules

## 0.1 Knowledge has ownership
A fact may be known by Neris, the player, one NPC, a faction, or the antagonist. Those are not one global knowledge pool.

Optional evidence may let a completionist infer a truth early. Mandatory scenes acknowledge that inference instead of pretending the evidence was never found.

## 0.2 Optional depth may not carry mandatory logic alone
The critical path must explain everything required to understand:
- why Maelor can trigger Grand Ring;
- why Neris is the useful Key operator;
- what Ilyra actually did;
- why Meridian cannot simply be repaired and left in charge;
- why the final release is possible.

Optional content may reveal victims, provenance, local consequences, competing interpretations, and more personal versions of those truths.

## 0.3 No hidden morality meter
Local repair choices may create different later routes, survivor scenes, burdens, dialogue, and credits images. The game does not secretly score one as the “correct compassionate” answer.

## 0.4 Narrative pressure outranks efficient routing
If Neris has just learned Maelor is about to activate a continent-scale system, the UI does not enthusiastically recommend collecting three nearby vaults.

Optional content can remain technically available while presentation respects urgency.

## 0.5 Every major region has a before-memory
Rootmere, Saltreach, Emberstep, High Aerie, Mireglass, and Cairnfall all receive a short ordinary-life visit during the First Circuit before Grand Ring changes them.

The later catastrophe must recontextualize places the player remembers.

## 0.6 World pulse continues while Neris travels
Regional residents, Rusk, Caldrin, Tessa, Sena, Maelor, and local institutions act between visits. The route references `docs/story/12_WORLD_PULSE_LEDGER.md` for offscreen changes.

---

# 1. Movement 0 — Brindle before First Ring

**Target feel:** comfort, competence, anticipation.  
**Completion density:** intentionally light.

## Mandatory
Follow `M00-S01` through `M00-S07`: ordinary work, Tessa spar, Orin's almost-confession, First Ring, Vale workshop breach, first Hush crossing.

## Optional content that belongs here

### C01 — The Crooked Fire Bell
May be completed before First Ring or on the first Brindle revisit.

Doing it before catastrophe gives Mara Pell and the neighborhood stronger recognition later.

### Small non-completion interactions
- children arguing over contradictory stories about Ilyra;
- help with food/festival setup;
- roof shortcut race;
- mill keeper complains about an unreachable tailbox;
- inspect Ilyra's locked traveling case;
- hear the fire bell's particular imperfect tone before deciding anything about it.

These interactions may award nothing.

## Completion policy
Do **not** let the opening become a checklist. Visible inaccessible spaces are useful promises.

## Knowledge checkpoint
Neris knows:
- Orin crossed into the Hush and looked back;
- the Cantor Key belonged to Ilyra;
- Orin knew the official death story was false.

Neris does not know Quiet Court, Maelor, the Listener, Mercy Window, or First Ring's causal owner.

---

# 2. Movement 1 — Road to Cairnspire

**Target feel:** urgency opening into scale.

## Mandatory
Flood relay → Meridian ridge → capital route ward.

## Optional seeds
- first Resonance Fault;
- one visibly locked maintenance cavity;
- Mireglass traveler with cracked diplomatic hand-mirror;
- drifted Cairnfall training lens on display;
- route-worker gossip about worsening bell timing.

These are seeds, not mini-quests.

## Relationship
Tessa challenges Neris's certainty without dismissing it:

> “Looking back and finding a road back are different jobs.”

This establishes that hope needs a route.

---

# 3. Movement 2 — Cairnspire / registration chain

**Target feel:** busy life, institutional friction, useful suspicion.

## Mandatory
- `M02-S02` Rusk/Key conflict;
- Public Bell Office diagnostic;
- **C02 — Twelve Minutes Missing**;
- Lower Archive / Caldrin;
- Maelor calibration.

C02 counts automatically toward 100% when completed through the story.

## Optional setup work

### `setup.highaerie.distributed_copy`
Allow Caldrin's disputed record to travel with Tessa rather than keeping the only copy in the archive.

### `setup.mireglass.personal_provenance`
Register the cracked Mireglass hand-mirror as named personal provenance rather than anonymous state salvage.

### `setup.cairnfall.uncorrected_lens`
Document the survey lens with its known drift instead of “fixing” it to state calibration.

## Early optional systems
The player can encounter:
- Cairnspire Faults;
- one or more early records;
- civic micro-vault promises;
- Route House relationship content;
- first Bellwarden policy arguments with Rusk.

## Important story logic
The Key drift demonstration makes the later route necessary. Maelor's three commissions exist, but Neris cannot safely trust the damaged Key until multiple independent baselines are compared.

---

# 4. Movement 3 — First Circuit / make Orra belong to the player

**Target feel:** curiosity, ownership, ordinary life.  
**Target duration:** substantial enough to remember the world, compact enough that Orin's urgency remains alive.

The Circuit is one calibration journey, not six quest hubs.

## Core stop — Old Viaduct Refuge

Meet Eda Vell and learn **P01 Common Measure**.

### Trial 01 — The Balance Bench
Introduces practical mastery and can begin the prestige chain.

### Prestige Stage 01 — Bent Yoke
The Unstandard Tool begins with an object that has no single archival solution.

## First Circuit ordinary-life postcards

### Rootmere
Ride Lio Fen's ferry. See Olo carrying marker notes and Amsa in an ordinary disagreement. The bell-oak moves freely.

**Setup opportunities:**
- `setup.rootmere.green_span` — choose rigid plate or flexible keeper weave for a young bridge;
- `setup.rootmere.wrens_margin` — preserve Amsa's handwritten warning once available.

### Saltreach
Ride a normal harbor launch. Meet Vessa. Hear berth arguments and functioning fog signals.

**Setup opportunity:** seed `setup.saltreach.manual_fog_code`; full repaint resolves with C10 later.

### Emberstep
See a successful pour and ordinary shift change. Meet maker culture before the false accusation.

**Setup opportunity:** seed `setup.emberstep.maker_marks` through freight/maker conversations.

### High Aerie
Ride a working cargo lift, cross a normal wind span, eat at the Wind Kitchen.

The player should know what wind and ordinary height feel like here before Stillness.

### Mireglass
Ride the lantern ferry; see children using strange reflections as a game.

The player learns Mireglass weirdness can be funny and domestic before it becomes horror.

### Cairnfall
Attend public observation night; use a deliberately flawed teaching scope; see students bet food on instrument disagreement.

The sky is pleasure before it is plot.

### Graymile
See the mothballed Line Skiff in `M03-S10`.

## First Circuit contracts

### C03 — Graymile's Open Bypass
Resolve whether to reinforce the unauthorized worker route or seal it and document why the certified tunnel failed.

Feeds `setup.circuit.graymile_bypass`.

### C04 — A Lantern Without a Bell
Build Dori Senn a purely local arrival indicator.

The humble mechanical solution later becomes a useful post-Grand-Ring rendezvous.

## Setup — unregistered Common Measure
Learning Common Measure establishes `setup.circuit.unregistered_pattern` and later proves small machines can coordinate without Meridian.

## First completion sweep — base/Cantor wave
A dedicated 100% player may reasonably clear:
- available Brindle/Cairnspire/First Circuit contracts;
- Old Viaduct Refuge and early refuges;
- base-access Faults;
- base Pulse Shards;
- base micro-vaults;
- early records/testimonies;
- Balance Bench;
- Common Measure;
- Prestige Stage 01.

Do not permit total regional exhaustion. Visible Anchor/Glasslung/Temper/Palinode/Mirror/seam locks should remain.

## Key story result
`M03-S11` compares **all six** healthy-but-different baselines. The player learns through play that disagreement is not automatically damage.

The Key now points to Rootmere as the strongest actual crisis.

---

# 5. Movement 4 — Rootmere / Anchor wave

**Target feel:** conflict → diagnosis → wonder → competent release.

## Mandatory

### C06 — The Root That Isn't Sick
Critical-path contract. Counts automatically.

Neris proves old foreign bracing, not the living bell-oak itself, is causing the collapse.

### Root Cathedral
Acquire **Anchor Line**.

Mossjaw remains an ordinary animal encounter. Mawhart is the liberation boss: remove the harmful load relationship; creature survives.

### Ilyra plate
Obtain the first hard warning against forced full-network synchronization and evidence that First Ring damping was abnormal.

## Optional Rootmere after dungeon

### C07 — Widow's Ferrygate
Use Anchor under changing river load. Lio's late husband's asymmetric mechanism can be preserved or reworked; either path has later behavior.

### Trial 02 — River Under Tension
Anchor mastery.

### Prestige progression
Living material for the Unstandard Tool must come from naturally shed fiber rather than cutting healthy growth.

### Ordinary return beat
Eat, ferry, hear disagreement about the repair, and see people act without waiting for Neris.

## Anchor revisit wave
Recommended natural route before Saltreach:
- Brindle mill tailbox;
- Graymile span/service cavity;
- Old Viaduct high tension route;
- Cairnspire service gantry;
- Rootmere ferry/high root spaces.

The purpose is memory transformation, not cleanup optimization.

---

# 6. Movement 5 — Saltreach / Glasslung wave

**Target feel:** familiarity → suspicion → pressure → relationship fracture → quiet loss.

## Mandatory

### C10 — The Fog Tower That Lies
The same harbor seen during the Circuit now misbehaves because the official calibration assumes an old coastline.

Completing the local fog code establishes `setup.saltreach.manual_fog_code`.

### Tide Foundry
Acquire **Glasslung Reed**.

### Nine-Lung Leviathan
Remove coercive pressure hardware. Leviathan escapes but later dies offshore from accumulated damage.

### Tessa manifest
Tessa's old restricted freight becomes personal. Her failure is deliberate incuriosity, not secret Stillring knowledge.

## Optional Saltreach

### C11 — Dry Dock at Low Water
Pressure-state repair; Mirror Nail later creates another route.

### C12 — Kelp Bell Funeral
A family decides what preserving a rescue memory means when physical possession and evidence conflict.

### Trial 03 — Fogline Pressure
Signal/pressure mastery.

### Breath Ledger
Optional/required catalog timing follows doc 13.

### `setup.saltreach.levis_pressure_release`
The old cistern bypass can remain independent or reconnect centrally; both create distinct later consequences.

### Prestige Stages 02–04
Pressurewright mark, living fiber, breathing coupler.

## Neris/Tessa relationship
The argument after the manifest is not instantly healed. A quiet camp lets both admit what they are projecting without requiring absolution.

## Leviathan remembrance
News of its death travels during the road out, not as a reward popup. Saltreach begins a small harbor remembrance while Neris is elsewhere.

## Glasslung revisit wave
Natural 100% opportunities:
- **C05 — The Fourth Landing** in Cairnspire;
- **C08 — Orchard of Split Notes** in Rootmere;
- submerged First Circuit pockets;
- pressure vaults/refuge services;
- associated Faults/Pulse Shards/upgrades.

---

# 7. Movement 6 — Emberstep / Temper wave

**Target feel:** social pressure → public evidence → industrial mastery → betrayal proof.

## Mandatory

### C14 — Names Ground Flat
Critical-path contract. Publish maker evidence and disprove the convenient impurity accusation.

Feeds `setup.emberstep.maker_marks`.

### Kiln of Names
Acquire **Temper Gauntlet**.

### Cinder Regent
Dangerous machine. No “actually innocent victim” repeat.

### Sealed records
Establish:
- three-point reference geometry;
- Ilyra/Maelor collaboration;
- privileged First Ring damping path;
- Mercy Window mark.

Neris's group can understand the mechanism before confronting Maelor.

## Optional Emberstep window
Short only. Story pressure should dominate.

### C15 — The Cold Kiln
Use controlled uneven heat rather than force uniform certification.

### C16 — Crack in the Foreman's Cup
Personal Sena scene about repairing without erasing visible history.

### Trial 04 — Three-Heat Cast
Thermal mastery.

### `setup.emberstep.quench_bypass`
Repair or close the manual emergency branch; later clinic heat route differs accordingly.

### Prestige Stage 05
Multi-temperature material requirement.

## Temper revisit wave
Technically opens older heat-memory routes, but the UI does not advertise a grand sweep after `M06-S05`.

**Narrative action:** return to Cairnspire now.

---

# 8. Movement 7 — Grand Ring / no-cleanup lock

**Target feel:** dread → attempted intervention → betrayal → catastrophe.

Once the player enters the Meridian district, this sequence is a story lock.

## Mandatory
- evidence converges independently;
- Maelor admits deliberate reference selection;
- Maelor admits disabling First Ring damping to expose hidden failure;
- Mercy Window/Ilyra-alive pressure lands;
- Neris attempts to stop activation;
- Rusk, Tessa, Caldrin, Sena act independently;
- Orra freezes through **remembered** regional places;
- Neris escapes into Hush.

## Optional-state acknowledgements
Early setup choices alter:
- accessible crisis side routes;
- which civilians/helpers appear;
- what equipment keeps working;
- who can move briefly.

They do not prevent Grand Ring.

## Knowledge checkpoint
Neris knows Maelor deliberately used the three repairs and worsened First Ring. Maelor's final ideology and Ilyra's full culpability remain incomplete.

---

# 9. Movement 8 — Ilyra / Hush-Cairnspire

**Target feel:** impossible hope → anger → awkward humanity → minimal practical plan.

## Mandatory
- find Ilyra;
- wrong workbench recognition;
- stabilize the Key;
- hear only the necessary admissions;
- learn that High Aerie is still exhibiting a changing relation;
- create Brindle re-entry.

## Important removal
Ilyra does **not** introduce “the three Countertones” as a checklist.

At this point there is only one practical lead: something at High Aerie is still moving.

## Quiet character content
Required mundane moments:
- Ilyra remembers a childhood food wrong;
- Neris puts tools in a drawer Ilyra keeps correcting;
- Ilyra catches herself speaking to a six-year-old;
- neither gets a perfect reunion hug that resets eleven years.

## Optional Hush content
Ilyra's Workbench refuge can provide one-time service/history without turning Ilyra into an always-on quest dispenser.

---

# 10. Movement 9 — changed Brindle / Line Skiff / first payoff sweep

**Target feel:** recognition → hurt → surprise joy → regained mobility.

## Mandatory Brindle return
The player sees:
- C01 outcome;
- Dori's local lantern if C04 completed;
- Graymile bypass consequence;
- Brindle social spaces changed rather than simply recolored.

## Tessa / Line Skiff
Tessa arrives with the seeded Graymile technology. This is a payoff, not an unexplained traversal gift.

Acquire **Roadhand Pulse** and usable **Line Skiff**.

## First fun Skiff stretch
Do not make the first vehicle sequence pure urgency. The player needs one period where changed traversal simply feels good.

## Post-Grand-Ring setup payoffs now visible

### S01 Crooked Fire Bell
Standard replacement and asymmetric brace produce different movement/safety outcomes.

### S02 Graymile bypass
Reinforced route can become courier escape with Hush risk; sealed route protects against contamination but requires exterior rescue.

### S03 Common Measure
Independent machines can create small local operating windows.

### S04 Rootmere green span
Rigid and flexible solutions preserve different routes.

### S05 Wren margin copy
Personal copy survives archive failure and later helps C09.

### S06 Saltreach manual fog code
Manual signal determines early reachable harbor shelter.

### S07 Leviathan pressure release
Independent bypass or central reconnection protects different infrastructure.

### S08 Emberstep maker marks
Workers can identify local alloys and disconnect selectively.

### S09 Emberstep quench bypass
Creates one clinic heat route or prevents rupture and requires another.

### S10 High Aerie distributed copy
Traveling evidence challenges archive authority earlier.

### S11 Mireglass personal provenance
Named hand-mirror later identifies a mundane shared memory.

### S12 Cairnfall uncorrected lens
Known drift later separates real coordinates from Meridian-corrected false ones.

## Moving hunt
**Drift Knots** begin once the required Fault threshold and Line Skiff state are met. They are deterministic moving synchronization errors, not ghost collection.

---

# 11. Movement 10 — High Aerie / Vane / Motion

**Target feel:** loss of familiar wind → rescue competence → historical ambiguity → relief.

## Before-memory payoff
Return to the Wind Kitchen, suspended lift, laundry, and familiar people from M03-S07.

## Mandatory

### C18 — Weight of the Archive
Strongly integrated early. Physical rescue priorities force Caldrin to confront archive hierarchy.

### Monastery/Tempest campaign
Acquire **Vane Cloak**.

### Choir of Talons
Ordinary predators; combat curriculum without a tragic lore explanation.

### Saint Varo
Preserve failure **and** courage. The relation is named **Motion only after the player performs it**.

## Optional High Aerie

### C19 — Chain Nine Sings
Crosswind/Anchor structure problem.

### C20 — The Novice Who Cut the Bellrope
Post-Motion reconstruction; Pera's “failure” prevented worse entrainment.

### Trial 06 — Crosswind Traverse
Vane mastery.

### High Aerie upgrades/refuges/records
Chainhouse Seven, Storm Blind, Vane/Anchor components, record sets.

## Quiet meal
Wind Kitchen reopens imperfectly. This is a required breathing beat.

## Story lead
Caldrin's released records point beneath Rootmere to an older rescue relation. The next destination emerges from evidence, not a “next Countertone” marker.

---

# 12. Movement 11 — Bone Archive / Palinode

**Target feel:** claustrophobic curiosity → intellectual tension → family accusation → silence.

## Mandatory
- re-enter familiar Rootmere through accumulated verbs;
- Archivist Without a Face pressure pattern;
- acquire **Palinode Pattern**;
- find pre-Meridian local-hold rescue history;
- Ilyra admits she designed Mercy Window.

## Optional integration

### C09 — A Name Under Bark
Now fully resolvable with Palinode and the earlier Wren margin copy.

### Prestige Stage 08
Contradictory dimensions become a tool-design lesson.

### Rootmere late records/Faults
Can be resolved naturally during departure rather than forcing another separate trip.

## Pacing rule
The immediate road afterward is quiet. No next-objective exposition monologue. The contradictory resonance itself points toward Mireglass.

---

# 13. Movement 12 — Mireglass / Mirror / Memory

**Target feel:** familiar strangeness becomes intimate horror → problem solving → grief.

## Before-memory payoff
The reflection game from M03-S08 is now wrong in a way the player personally understands.

## Recommended pre-palace side story

### C21 — The House That Remembers a Door
A domestic version of preservation: a lost room comforts one person and traps another in grief. No moral-score answer.

## Mandatory
- Palace Under Reeds;
- complete **Mirror Nail**;
- resolve Mirror Widow through a shared mundane memory;
- relation named **Memory** only after action;
- reconstruct full Mercy Window.

## Full family truth
Ilyra's work saved lives and materially enabled Maelor's later path. She accepts responsibility without accepting responsibility for his choices.

This is the Neris/Ilyra emotional low point.

## Optional Mireglass

### C22 — Witness at Reedwater
Feeds **Witness Interval** and civic provenance.

### Trial 07 — Two Histories, One Repair
Palinode/Mirror mastery.

### Mireglass records/vaults/Faults
Now include committed echo-state routes.

## Mirror/Palinode mega-revisit wave
This is the largest optional expansion in the game.

Older regions gain:
- alternate useful states;
- unresolved records that can now coexist;
- hidden spaces based on never-built/remembered geometry;
- late Pulse Shards;
- late tool upgrades;
- elite access;
- prestige stages.

**Presentation rule:** the world is available, not nagging. Give the player emotional space after Mercy Window before surfacing completion assistance.

---

# 14. Movement 13 — Cairnfall / seam mode

**Target feel:** calm technical disagreement → collaboration → regained possibility → new family lead.

## Before-memory payoff
Return to public observation night space. The fun flawed scopes now insist on one impossible coordinate.

## Mandatory

### C23 — The Telescope That Disagrees
Critical teaching for reference-frame logic.

### Fallen Orrery
Accumulated tool synthesis.

### Neris/Ilyra collaboration
Complete **Cantor Key seam mode**. This is cooperation after truth, not forgiveness reward.

### Gravemoon Engine
Disconnect Meridian correction while preserving local instruments.

### C24 — No Correction Required
Strongly integrated post-dungeon. Establish a local disagreement-reporting protocol and **Local Accord**.

## Main-story lead
Raw uncorrected observation detects a repeating Vale workshop signal that cannot finish releasing its state.

The next objective is **find Orin**, not “collect Ending.”

## Optional Cairnfall
- Trial 08 Drift Survey;
- Night Survey Hut;
- seam-mode Faults/vaults;
- late tool upgrade components;
- Prestige Stage 10;
- late Drift Knot tiers.

## World-state consequence
Because correction is disabled, moving pockets last long enough for regional communities to begin their own disconnection attempts **without waiting for Neris**.

---

# 15. Seam-mode world sweep

**Target feel:** world depth and player mastery, not final checklist panic.

This optional wave can be taken before or after Still-Cairn depending on pacing, except where a story gate requires Ending.

Seam mode opens:
- final regional seam Faults;
- late micro-vaults;
- late Pulse Shards;
- Ilyra Workbench/Hush service interactions;
- several record/testimony conclusions;
- final stages of moving hunt access.

The player should see communities attempting solutions during these revisits. Some succeed, some fail, some ask for help, some choose not to use Neris's preferred method.

---

# 16. Movement 14 — Still-Cairn / Orin / Ending

**Target feel:** uncanny possibility → personal safety → temptation → release → family fracture.

## Mandatory
- enter layered Hush-Cairnspire;
- learn through repeated play that preserved useful states become barriers;
- reach Echo-bound Orin;
- reach perfect Vale workshop;
- release it;
- relation named **Ending** afterward;
- hear Orin's full confession.

## Important sequence rule
Only now may characters naturally summarize **Motion / Memory / Ending** as a learned set.

The set has emerged from lived problems rather than being handed out as a collection quest.

## Family outcome
Ilyra and Orin do not reconcile their marriage in the dungeon. They agree only that neither gets to control Neris's future through withheld information.

## Pacing rule
Do not immediately throw a 100%-remaining checklist on screen after Orin's confession.

Return to ordinary people first.

---

# 17. Movement 15 — Unringing / natural home of final 100% sweep

**Target feel:** rebuilding, responsibility, community competence, earned preparation.

The world has already started moving. Neris helps communities finish practical disconnection rather than arriving as the sole inventor of local life.

The critical path needs an authored subset of cooperation to open Null Meridian.

A 100% player stays and resolves **all six community projects plus remaining completion-bearing content**.

## Rootmere — Many Roots, Many Bells
- complete remaining C07/C08/C09 if unresolved;
- living-resonator project;
- final setup payoffs;
- remaining Faults/Pulse/vaults/records;
- Rootmere elite;
- keeper coordination still includes watershed-scale shared warning where useful.

## Saltreach — Fog Without Meridian
- **C13 — Two Captains, One Tide**;
- manual fog/pressure network;
- remaining underwater/Mirror/seam spaces;
- Saltreach elite;
- Drift Knot routes;
- harbor coordination changes with tide rather than demanding tide fit a schedule.

## Emberstep — Maker's Clock
- **C17 — Borrowed Heat**;
- clinic/foundry heat-sharing outcome;
- maker-name restoration;
- remaining Faults/vaults/records/upgrades;
- Emberstep elite.

## High Aerie — Open Copies
- finish C19/C20 if unresolved;
- archive distribution project;
- remaining Vane/Anchor content;
- High Aerie elite/trial completion;
- Caldrin's archive retains evidence discipline without one master copy.

## Mireglass — Public Seams
- finish C21/C22;
- safe civic seam project;
- remaining Mirror/Palinode content;
- Mireglass elite;
- residents may disagree about whether public seam access should exist at all.

## Cairnfall — Report the Drift
- finish C23/C24 if unresolved;
- independent survey network;
- remaining seam content;
- Cairnfall elite;
- school/observation practices begin **before** the credits.

## Prestige quest — The Unstandard Tool
Stages 11–12 complete here.

Final reward: **Freehand Frame**. Different workshops can build compatible but visibly different versions; no master pattern becomes the new sacred standard.

## Moving hunt — Drift Knots
All 12 targets can now be resolved if earlier thresholds and verbs are complete.

Final reward: **Route Listener**, a route-sector unresolved-service/fault aid, not treasure radar.

## Optional elites — 8
All eight become resolvable by late Unringing according to doc 14.

## Mastery complex — Broken Standard Yard
Seven commissions test actual disaster-response combinations. Final reward **Open-Hand Coupler** improves field experimentation/convenience without adding a new mandatory verb or damage tier.

## Bellwright Refuges — 11
All refuges and their unique one-time services/history should now be resolvable, including Ilyra's Hush workbench.

## 100% pre-finale verification
Before Null Meridian, a complete route should have resolved every completion-bearing category except content physically allocated inside Null Meridian and the story-complete flag.

Diegetic completion assistance may report unresolved **categories by region** through courier/refuge services. It should not default to exact hidden coordinates.

---

# 18. Movement 16 — Null Meridian

**Target feel:** mastery → institutional truth → confrontation → dread.

## Point of no return
Before entry:
- create recoverable pre-finale save;
- show unresolved completion categories;
- allow cancellation;
- never imply 100% is required for the legitimate ending.

## Optional-completion effects
Completion may change:
- which approach routes remain open;
- which allies appear;
- final refuge services;
- optional Null Meridian side rooms;
- dialogue acknowledging relationships;
- witness/record specificity.

It never makes Neris more “worthy.”

## Final dungeon
Paired-mechanic synthesis, not one nostalgia room per region:
- Anchor + Vane;
- Glasslung + Temper;
- Palinode + Mirror;
- Mirror + seam;
- Cantor + combat;
- Local Accord + unstable infrastructure;
- Line Skiff approach segment.

No new mandatory core verb.

## Quiet Court archive
Critical path establishes the reform-to-coercion history. Optional records add people, victims, dissenters, and compromises.

## Maelor
Human-scale first phase, more integrated second phase. He remains responsible and physically human rather than being transformed into a possessed monster.

His final offer is preservation from future loss, not power.

Neris defeats him. Maelor opens Listener containment rather than accept disconnection.

---

# 19. Movement 17 — Listener / preserved beloved world

**Target feel:** temptation → recognition → existential sadness → release.

## Save-state personalization
Where production allows, preserved possibilities use actual remembered content:
- Lio's ferry;
- Wind Kitchen;
- Mireglass reflection game;
- Cairnfall public sky;
- Brindle festival table;
- Crooked Fire Bell;
- optional NPCs with completed arcs;
- Tessa's ordinary jokes;
- imperfect household details.

The Listener does not offer a shiny perfect utopia.

It offers the imperfect world the player loved **forever**.

## Recognition
The ferry never finishes docking. Laughter never finishes becoming silence. Nobody reaches the next sentence.

The player understands pleasant preservation is still a cage when no state may become past.

## Final question

> **“MUST ALL ENDINGS BE CAGES?”**

## Final action
Motion allows change, Memory keeps what happened knowable, Ending allows state to become past.

Neris shatters Meridian's central heart.

The Hush settles into many local seams. The Listener is no longer forced into one compressed singular consciousness.

---

# 20. Epilogue / credits

**Target feel:** relief without reset.

## Brindle
Playable return through a village that is familiar and changed. Early repair history is still visible.

## Ilyra
Present but not restored. Relationship begins again between who Neris and Ilyra are now.

## Orin
Answers plainly and gives Neris Ilyra's traveling case.

## Tessa
Independent courier network is durable civic work, not a temporary adventure job.

## Caldrin
Public archive preserves provenance, uncertainty, contradiction, and revision history.

## Sena
New civic bells and hardware carry maker names.

## Rusk
Can testify and assist disclosure without becoming the reform hero.

## Maelor
Public trial is ongoing.

## Neris
Carries a repaired but permanently cracked Cantor Key and leaves as a traveling bellwright.

Tessa:

> “You coming, bellwright?”

Neris:

> **“Yeah. I heard something cracked.”**

## Credits variation policy
There is one canonical ending.

100% changes specificity, not moral rank:
- named workers appear on public boards;
- chosen repair consequences remain visible;
- optional families and social spaces recur;
- courier routes reflect completed Drift Knots;
- Freehand Frame variants appear if prestige quest completed;
- Maelor trial includes additional witnesses based on record/testimony sets;
- community projects show fuller preparedness.

An incomplete player does not receive a “bad ending.”

## Post-credits
A bell rings beneath an ocean far beyond Orra. A second ring answers from impossible depth.

---

# 21. Completion-bearing category closure map

| Category | Early availability | Major revisit wave | Expected closure |
|---|---|---|---|
| Main story | Brindle | continuous | Epilogue |
| 24 Local Repair Contracts | C01/C02/C03/C04 early | tool/world-state gated | Unringing |
| 12 Setup/Payoff chains | First Circuit/Act I setups | post-Grand-Ring payoffs | Unringing |
| 11 Bellwright Refuges | First Circuit onward | tool/Hush gated | pre-Null |
| 48 Resonance Faults | base Key | Anchor → Glasslung → Temper → Palinode → Mirror → seam | Null allocation/finale |
| 28 Pulse Shards | opening onward | all major verb waves | pre-Null except late allocated |
| 9 Cantor Patterns | Common Measure early | regional/story acquisition | Unringing |
| 14 Tool Mastery Upgrades | first major tool | regional revisit waves | Unringing |
| 9 Skill Trials | Balance Bench | each mastery wave | Unringing |
| 30 Micro-vaults | First Circuit | all verb waves | Null allocation/finale |
| 32 Records/Testimonies | Cairnspire onward | Palinode/Mirror/seam deepen sets | Null allocation/finale |
| 12-stage prestige quest | First Circuit | cross-region continuous | Unringing |
| 12 Drift Knots | post-Grand Ring + threshold | later verb tiers | Unringing |
| 8 optional elites | regional mastery | later verbs | Unringing |
| 6 community projects | after Cairnfall | Unringing | Unringing |
| Broken Standard Yard | late game | mastery synthesis | pre-Null |

---

# 22. Local Repair Contract route index

| ID | Contract | Earliest meaningful window | Natural payoff/revisit |
|---|---|---|---|
| C01 | The Crooked Fire Bell | Brindle opening | changed Brindle / credits |
| C02 | Twelve Minutes Missing | Cairnspire registration | Tessa courier network |
| C03 | Graymile's Open Bypass | First Circuit | changed-world route |
| C04 | A Lantern Without a Bell | First Circuit | changed-world rendezvous |
| C05 | The Fourth Landing | Glasslung revisit | Cairnspire refuge/community |
| C06 | The Root That Isn't Sick | Rootmere critical | Root Cathedral access |
| C07 | Widow's Ferrygate | Anchor | Stillness behavior / route |
| C08 | Orchard of Split Notes | Glasslung revisit | Hollow/diagnostic progression |
| C09 | A Name Under Bark | Palinode | public Rootmere record |
| C10 | The Fog Tower That Lies | Saltreach critical | manual signal payoff |
| C11 | Dry Dock at Low Water | Glasslung | Mirror late route |
| C12 | Kelp Bell Funeral | post-Foundry | Memory theme / testimony |
| C13 | Two Captains, One Tide | post-Stillness | community project |
| C14 | Names Ground Flat | Emberstep critical | maker-mark payoff |
| C15 | The Cold Kiln | Temper | Temper mastery/service |
| C16 | Crack in the Foreman's Cup | post-Kiln | Sena personal recurrence |
| C17 | Borrowed Heat | post-Stillness | Emberstep community project |
| C18 | Weight of the Archive | High Aerie arrival | Caldrin arc |
| C19 | Chain Nine Sings | Vane | permanent High Aerie route |
| C20 | The Novice Who Cut the Bellrope | post-Motion | credits / archive truth |
| C21 | The House That Remembers a Door | Mireglass | domestic Memory setup |
| C22 | Witness at Reedwater | Memory | Witness Interval/community |
| C23 | The Telescope That Disagrees | Cairnfall | dungeon teaching |
| C24 | No Correction Required | post-Gravemoon | Local Accord/community |

---

# 23. Player-knowledge checkpoint

| Checkpoint | Neris knows | Player stance toward Maelor | Ilyra state | Immediate human question |
|---|---|---|---|---|
| Brindle departure | Orin crossed; death story false | unknown | presumed dead | how do I get Orin back? |
| Cairnspire | Ilyra records altered; Key uniquely stable with Neris | useful, withholding | presumed dead | why was her work hidden? |
| First Circuit | six healthy regions disagree naturally | useful, suspicious | presumed dead | which crisis actually matters? |
| Rootmere | Ilyra warned against forced synchronization; First Ring damping abnormal | credible but increasingly suspicious | presumed dead | what was she warning about? |
| Saltreach | Maelor/Ilyra funded restricted work; Tessa chose not to know | morally ambiguous, still helpful | presumed dead | what did they disagree about? |
| Emberstep | three-point plan and Mercy Window/Ilyra lead | deception proven | presumed dead | what is Mercy Window and what is Maelor doing now? |
| Grand Ring | Maelor selected references and worsened First Ring | antagonist with partially understood ideology | survival implied possible | is Ilyra alive? |
| Ilyra reunion | she joined Quiet Court and built precursor tech | catastrophic choice understood | alive in Hush | how responsible was she? |
| High Aerie | Motion discovered; official history curated | ideology clearer | confession incomplete | why does old rescue history resemble this? |
| Bone Archive | Ilyra designed Mercy Window | Maelor's path has a real technical ancestor | culpability admitted partially | what happened when they used it? |
| Mireglass | complete Mercy Window truth | origin understandable, permanent choice unacceptable | culpability accepted | can Neris work with her without absolving her? |
| Cairnfall | local disagreement can be safe; seam mode works | still technically dangerous and ideologically committed | adult collaboration possible | why can't Orin's workshop signal finish? |
| Still-Cairn | Orin's secrecy exposed; Ending discovered | finale unavoidable | family truth shared | what can replace Meridian? |
| Unringing | communities can coordinate without singular control | premise disproven in practice | reintegration becomes possible | can central hold end safely? |
| Null Meridian | core history known | accountable tragic antagonist | active ally through seams | repair or decommission? |
| Ending | change accepted as condition of life | survives for trial | changed survivor | what happens after? |

---

# 24. Final 100% route quality test

A full-completion player should be able to say:
- “I kept coming back because these places changed,” not “I cleared the map.”
- “I knew these people before the catastrophe.”
- “New tools made old places mean something different.”
- “Optional stories changed who showed up and what I understood, but the main story never depended on finding a hidden note.”
- “The world did things while I was gone.”
- “The final dungeon asked me to use what I had learned instead of giving me a new gimmick.”
- “100% made the ending more specific, not more morally correct.”

If playtesting instead produces long stretches of cleanup divorced from current character motivation, the route must be rebalanced even if the completion counts are technically perfect.