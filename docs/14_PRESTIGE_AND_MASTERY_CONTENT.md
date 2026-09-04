# 14 — Prestige and Mastery Content

**Status:** canonical optional-content plan  
**Related:** Issue #14, `docs/11_QUEST_AND_COMPLETION_LEDGER.md`

This document defines Stillring's large optional systems: content that makes a 100% playthrough feel like deeper mastery of Orra rather than a second job vacuuming icons.

---

# 1. Skill Trials — 9

A Skill Trial is an authored mastery activity using controls/systems the main game already teaches. First completion at the defined mastery threshold counts toward 100%. Repeating for faster times, fewer mistakes, or leaderboard-style scores does not.

## Trial 01 — The Balance Bench
**ID:** `trial.circuit.balance_bench`  
**Location:** Old Viaduct Refuge  
**Availability:** First Circuit  
**Mechanics:** movement, camera, interaction, simple Cantor diagnosis  
**Premise:** independent bellwright Eda Vell uses a deliberately ugly training rig with shifting weights, loose boards, and three mismatched signal plates. The goal is to diagnose which component actually needs adjustment without “fixing” the harmless imperfections.  
**Mastery threshold:** finish with no unnecessary part replacement.  
**Reward:** Pulse Shard + prestige-quest Stage 1.

## Trial 02 — River Under Tension
**ID:** `trial.rootmere.river_tension`  
**Location:** Rootmere ferry practice rig  
**Availability:** after Anchor Line  
**Mechanics:** Anchor target choice, load reading, movement under tension  
**Premise:** stabilize a moving ferry assembly through three river loads using the fewest valid anchor placements.  
**Mastery threshold:** complete all loads without snapping a sacrificial training tether.  
**Reward:** Anchor Brake Reel.

## Trial 03 — Fogline Pressure
**ID:** `trial.saltreach.fogline_pressure`  
**Location:** abandoned signal tower pair outside Saltreach  
**Availability:** after Glasslung Reed  
**Mechanics:** pressure reading, controlled discharge, line-of-sight navigation through fog  
**Premise:** keep three manual fog signals readable while pressure changes and visual range collapses.  
**Mastery threshold:** no tower may drop below safe signal pressure.  
**Reward:** Glasslung Metered Valve + Pulse Shard.

## Trial 04 — Three-Heat Cast
**ID:** `trial.emberstep.three_heat_cast`  
**Location:** community training kiln  
**Availability:** after Temper Gauntlet  
**Mechanics:** thermal state, Glasslung-assisted quench, timing  
**Premise:** produce one useful repair bracket from a mixed-alloy blank without ever making the whole blank one temperature.  
**Mastery threshold:** preserve all three material zones through final set.  
**Reward:** Quench Collar + Pulse Shard.

## Trial 05 — The Relay Run
**ID:** `trial.circuit.line_skiff_relay_run`  
**Location:** old courier loop from Graymile to Cairnspire outer road  
**Availability:** after Line Skiff  
**Mechanics:** acceleration, coasting, route reading, Roadhand Pulse  
**Premise:** deliver three physical relay flags through a network whose central routing is dead. The challenge is choosing momentum and junction timing, not racing a named rival.  
**Mastery threshold:** all flags delivered before their mechanical clocks expire; collisions do not automatically fail the run.  
**Reward:** Line Skiff Switchshoe.

## Trial 06 — Crosswind Traverse
**ID:** `trial.highaerie.crosswind_traverse`  
**Location:** Chainhouse Seven training span  
**Availability:** after Vane Cloak  
**Mechanics:** Vane deployment, Anchor recovery, Crosswind Measure  
**Premise:** inspect a suspension line during gusts while carrying a fragile mechanical gauge.  
**Mastery threshold:** inspect every node without the gauge exceeding its shock limit.  
**Reward:** Vane Crossstay.

## Trial 07 — Two Histories, One Repair
**ID:** `trial.mireglass.two_histories`  
**Location:** Reed-Chapel Workshop  
**Availability:** after Mirror Nail + Palinode  
**Mechanics:** compare incompatible states, local commitment, repair planning  
**Premise:** two valid historical configurations of a pump survive in the Hush. The player must keep both legible while committing only the parts needed to build a safe present configuration.  
**Mastery threshold:** no historical state is erased from the journal and the present pump functions.  
**Reward:** Mirror Nail Duplex Head.

## Trial 08 — Drift Survey
**ID:** `trial.cairnfall.drift_survey`  
**Location:** Night Survey Hut / outer observatory  
**Availability:** after Cairnfall access; full mastery after seam mode  
**Mechanics:** reference-frame reading, seam control, Vane/Anchor movement  
**Premise:** record three observations that deliberately disagree and return without allowing the correction system to normalize them.  
**Mastery threshold:** preserve all three raw readings and close every opened seam safely.  
**Reward:** rare Cantor component used by Seam Brace.

## Trial 09 — The No-Bell Drill
**ID:** `trial.unringing.no_bell_drill`  
**Location:** independent courier relief yard outside Cairnspire  
**Availability:** after High Aerie  
**Mechanics:** lock-on, visual tells, target switching, multi-enemy pressure, no audio tells  
**Premise:** Tessa's couriers train to defend moving relief teams when Stillness suppresses warning sounds. Training opponents use padded rigs and mechanical hazards.  
**Mastery threshold:** protect all three relief stations through the drill; damage taken is allowed.  
**Reward:** combat field-kit modifier + final Pulse Shard clue.

---

# 2. Prestige Quest — The Unstandard Tool

**Quest family ID:** `prestige.unstandard.*`  
**Stages:** 12  
**First available:** First Circuit  
**Completable:** after Cairnfall / before Null Meridian  
**100% bearing:** yes

## Premise

The Quiet Court and later Bellwarden administrations did not merely suppress dangerous inventions. They also standardized ordinary field work so aggressively that several useful **local bellwright practices became impossible to certify**.

At the Old Viaduct Refuge, Eda Vell owns one broken part from a tool older than that standardization. She calls it an “unstandard tool,” but that phrase is misleading: there was never one official design.

Different regions built compatible parts according to different traditions.

The quest is therefore not about passing a string of arbitrary objects between NPCs. It is about reconstructing a working tool from **distributed expertise that no central archive contains**.

## Final reward — Freehand Frame

The completed **Freehand Frame** is a folding shoulder/forearm counterbrace used by traveling bellwrights who worked without cranes or standardized mounts.

### Gameplay identity

When equipped, Neris can enter a **brace stance** on stable ground:
- movement is slower and evasive options are reduced;
- Anchor Line cannot be fired while the Frame is fully loaded;
- Neris can catch/redirect a limited class of high-force mechanical impacts or heavy enemy strikes that normally require evasion;
- a successful brace stores mechanical load briefly, which can be released into a compatible lever, jammed mechanism, or heavy counterattack;
- it is excellent for deliberate posture/control play and poor for mobile crowd combat.

It is not “the strongest sword.” It creates a different way to solve certain fights and field problems.

## Stage 01 — The Bent Yoke
**ID:** `prestige.unstandard.01_bent_yoke`  
**Location:** Old Viaduct Refuge  
**Trigger:** complete Trial 01  
**Action:** Eda shows Neris a bent shoulder yoke with three incompatible maker marks and asks whether it looks broken or unfinished. Hollow Measure reveals one arm was designed to accept a missing flexure, not a standard hinge.  
**Output:** yoke cataloged; Tessa recognizes a Saltreach pressurewright mark.

## Stage 02 — The Pressurewright's Mark
**ID:** `prestige.unstandard.02_pressurewright_mark`  
**Location:** Saltreach  
**NPC:** retired pressurewright Vessa Mor  
**Action:** Vessa identifies the mark as belonging to **Dalen Mor**, her grandfather, who built flexible pressure couplers that were banned because no two were dimensionally identical. She does not have the coupler, but knows Rootmere keepers traded him living fiber for seals.  
**Output:** recipe describes a *relationship* between flex and pressure, not exact dimensions.

## Stage 03 — Fiber That Refuses a Ruler
**ID:** `prestige.unstandard.03_living_fiber`  
**Location:** Rootmere  
**NPC:** Amsa Wren  
**Requirement:** Root Cathedral clear  
**Action:** Amsa refuses to cut living fiber from the bell-oak for a dead tool. Neris instead helps recover naturally shed load-fiber from a root bridge and must test which strand changes tension without losing memory of its relaxed shape.  
**Output:** living flexure material; teaches why standard fixed dimensions failed.

## Stage 04 — A Coupler That Breathes
**ID:** `prestige.unstandard.04_breathing_coupler`  
**Location:** Saltreach Lowwater Locker  
**Requirement:** Glasslung Reed  
**Action:** use pressure history and living fiber to build a coupler whose shape changes safely under load. It must be tested across both air and water pressure rather than handed to an NPC through dialogue.  
**Output:** functional flexure/coupler.

## Stage 05 — Metal With More Than One Temperature
**ID:** `prestige.unstandard.05_split_alloy`  
**Location:** Emberstep  
**NPC:** Sena Ash  
**Requirement:** Temper Gauntlet / C15  
**Action:** Sena recognizes the frame needs a mixed-state alloy the old state code banned because inspection assumed uniform heat treatment. Trial-like forge sequence creates a blank with hard outer rails and a flexible center.  
**Output:** frame rail blank.

## Stage 06 — Carry It Wrong
**ID:** `prestige.unstandard.06_live_transport`  
**Location:** Emberstep → Graymile  
**Requirement:** post-Grand Ring Line Skiff  
**Action:** the newly treated rail will creep out of alignment if held perfectly still while cooling. Neris must transport it on the Line Skiff through a route where vibration stays inside a required band. The task is not a pure speed race: too smooth and too rough both fail the material state.  
**Output:** stabilized rail; unlocks a special route readout for this stage only.

## Stage 07 — The Drawing That Wasn't a Drawing
**ID:** `prestige.unstandard.07_archive_gesture`  
**Location:** High Aerie  
**NPC:** Caldrin  
**Requirement:** Weight of the Archive / Palinode access path  
**Action:** a banned “drawing” is actually a sequence of rigging gestures recorded as marginal figures because the tool was adjusted to each worker's body. Neris reconstructs the sequence on a training rig.  
**Output:** brace-load procedure.

## Stage 08 — The Missing Dimension
**ID:** `prestige.unstandard.08_missing_dimension`  
**Location:** Bone Archive  
**Requirement:** Palinode Pattern  
**Action:** two records give contradictory dimensions for the same tool. Palinode reveals both are correct because the dimension was specified as **loaded versus unloaded relation**, not length.  
**Output:** relational calibration rule.

## Stage 09 — How It Was Actually Used
**ID:** `prestige.unstandard.09_echo_demonstration`  
**Location:** Mireglass  
**Requirement:** Mirror Nail  
**Action:** a Hush impression of an anonymous field worker uses a similar frame during a collapsed-gate repair. Neris cannot simply copy the pose; the player pins short moments and reconstructs what forces the worker was redirecting.  
**Output:** heavy-load catch geometry; unlocks prototype brace stance at refuges.

## Stage 10 — Two Correct Calibrations
**ID:** `prestige.unstandard.10_double_calibration`  
**Location:** Cairnfall  
**Requirement:** C23 / seam mode  
**Action:** calibrate the frame against two observation instruments that disagree. It only passes if it remains safe under both reference assumptions rather than being corrected to one.  
**Output:** field-ready Freehand Frame, but Eda refuses to call it finished.

## Stage 11 — The Court's Confiscated Rack
**ID:** `prestige.unstandard.11_confiscated_rack`  
**Location:** Quiet Court field cache unlocked by records, outside the final dungeon  
**Requirement:** selected Quiet Court testimonies + one elite encounter  
**Action:** locate a confiscation rack holding nonstandard field-tool fittings. The useful piece is not unique loot; it is an **open coupler** allowing future workers to replace parts without matching one proprietary dimension.  
**Output:** open coupler.

## Stage 12 — No Master Pattern
**ID:** `prestige.unstandard.12_no_master_pattern`  
**Location:** Old Viaduct Refuge during the Unringing  
**NPCs:** Eda, Tessa, Sena; Caldrin contributes records remotely  
**Action:** assemble the final tool. Eda deliberately destroys the tracing jig after everyone copies the *principles* needed to build compatible variants. Neris records no master dimensions, only safe operating relationships and maker notes.  
**Reward:** permanent Freehand Frame + unique repair interactions + credits shot showing apprentices building visibly different compatible frames.

### Quest rule

No stage should be implemented as “NPC A gives item; walk to NPC B.” Travel can be part of a stage, but every stage must contain diagnosis, traversal, craft, social context, or mechanical action.

---

# 3. Moving Traversal Hunt — Drift Knots

**Family:** `hunt.*`  
**Targets:** 12  
**Unlock:** Line Skiff + first 13 Resonance Faults  
**Final tiers:** Vane / Mirror / Fine Fork / seam mode

## Fiction

Stillring's forced phase does not create twelve collectible ghosts. It creates **Drift Knots**: compact synchronization errors that propagate along old route reinforcement strips because the network keeps trying to correct a fault that is moving faster than its local reference.

They are dangerous to route workers because a Knot can briefly phase-lock or misalign a section of road.

## Interaction

1. Tessa provides a rough route window based on courier reports.
2. Player rides the Line Skiff and listens for the Knot's changing signature.
3. Route hazards / junction choices matter.
4. When close enough, the player must use a Cantor diagnostic interaction at the correct reference window; some targets require an additional learned verb.
5. Reconciled Knot becomes a permanent safe route correction, not an inventory ghost.

The targets are authored and deterministic once their unlock conditions are met. No random spawn camping.

| ID | Name | Route | Extra gate / twist | Intermediate payoff |
|---|---|---|---|---|
| `hunt.circuit.graymile_bellwake` | Graymile Bellwake | Cairnspire–Graymile | base Line Skiff | route repair material |
| `hunt.rootmere.reedrunner` | Reedrunner | Rootmere low road | Anchor timing at a broken strip | Fault journal clue |
| `hunt.saltreach.breakwater_skip` | Breakwater Skip | coastal reinforcement line | Glasslung pressure gate | Glasslung service part |
| `hunt.emberstep.ashline` | Ashline Flicker | freight road | Temper opens jammed switch housing | tool material |
| `hunt.cairnspire.outer_loop` | Outer Loop Stutter | capital ring road | Switchshoe junction transfer | courier route upgrade |
| `hunt.highaerie.downline` | Downline Crosswind | mountain descent | Vane + Crosswind Measure | Vane service part |
| `hunt.mireglass.reedglass_flicker` | Reedglass Flicker | marsh causeway | Palinode distinguishes two apparent targets | testimony clue |
| `hunt.cairnfall.night_arc` | Night Arc | observatory service road | must run during a specified observation window | Key component |
| `hunt.rootmere.afterimage` | Rootmere Afterimage | post-Mirror forest route | Mirror Nail commits one false branch while Knot takes the other | rare material |
| `hunt.saltreach.false_harbor` | False Harbor Line | Hush-bleeding coast | Mirror + Line Skiff | field-kit modifier |
| `hunt.emberstep.quench_runner` | Quench Runner | steam freight line | Fine Fork separates Knot from machinery noise | rare upgrade material |
| `hunt.meridian.blackline` | Blackline Knot | abandoned pre-capital route | seam mode + Switchshoe + Fine Fork | final hunt reward |

### Hunt completion reward

After all 12, Tessa installs a **Route Listener** service into the Line Skiff dock network. It does not reveal treasure. It shows whether an entered road sector still contains an unresolved route-class Fault or uncompleted courier service.

It also adds one credits shot of couriers mapping safe routes without Meridian control.

---

# 4. Optional Elite Encounters — 8

Elite encounters are authored tests of combinations the critical path teaches but does not require at high difficulty. They are not recolored bosses with inflated health.

## E01 — The Ironbound Keeper
**ID:** `elite.rootmere.ironbound_keeper`  
**Location:** Rootmere abandoned state maintenance yard  
**Unlock:** Anchor Line  
**Concept:** an old load-management automaton keeps reattaching foreign braces to living structures. Player must prioritize brace components while defending against the machine's heavy sweeps.  
**Mastery:** target switching + Anchor interrupts + environmental load.  
**Reward:** rare Anchor material / prestige clue.

## E02 — Breakwater Mother
**ID:** `elite.saltreach.breakwater_mother`  
**Location:** disused storm basin  
**Unlock:** Glasslung + Saltreach clear  
**Concept:** a territorial shell-creature has incorporated pressure vents into a nest; pressure state controls which lanes are safe.  
**Mastery:** spatial pressure management + core melee.  
**Reward:** Glasslung material + Pulse service credit.

## E03 — Whitehot Inspector
**ID:** `elite.emberstep.whitehot_inspector`  
**Location:** sealed standards foundry  
**Unlock:** Temper + Quench Collar  
**Concept:** inspection machine rejects any object outside one thermal profile and attempts to reheat the arena into uniformity.  
**Mastery:** deliberately maintain unequal heat zones while fighting.  
**Reward:** Temper material + Maker record route.

## E04 — The Three Rooks
**ID:** `elite.highaerie.three_rooks`  
**Location:** abandoned courier suspension line  
**Unlock:** Vane  
**Concept:** three intelligent aerial predators have learned different pressure roles: feint, displacement, strike. Their aggression budget is deliberately choreographed.  
**Mastery:** lock-on switching, visual threat reading, Vane positioning.  
**Reward:** Vane material / No-Bell Drill modifier.

## E05 — Reed Magistrate
**ID:** `elite.mireglass.reed_magistrate`  
**Location:** flooded civic court echo  
**Unlock:** Palinode + Mirror Nail  
**Concept:** a Hush construct continually declares one arena state “official” and removes cover/routes belonging to the others.  
**Mastery:** preserve contradictory states long enough to create openings; combat remains necessary.  
**Reward:** Mirror material + testimony.

## E06 — Orrery Bailiff
**ID:** `elite.cairnfall.orrery_bailiff`  
**Location:** outer correction ring  
**Unlock:** Mirror + Vane/Anchor  
**Concept:** a maintenance defense rig physically reorients itself to whichever reference frame the player uses most.  
**Mastery:** vary tools and orientation; punish one-strategy repetition.  
**Reward:** seam component.

## E07 — Quiet Court Pursuer
**ID:** `elite.circuit.court_pursuer`  
**Location:** moving encounter across an abandoned route depot  
**Unlock:** after Mireglass + enough Quiet Court records  
**Concept:** unmanned Court recovery machine activates to repossess Ilyra's prototype Key and confiscated nonstandard tools. It uses capture fields rather than lethal weapons.  
**Mastery:** Line Skiff approach followed by mixed on-foot combat/diagnosis.  
**Reward:** access token to Prestige Stage 11 cache.

## E08 — The Safety Inspector
**ID:** `elite.stillcairn.safety_inspector`  
**Location:** optional Still-Cairn civic layer  
**Unlock:** seam mode + Memory  
**Concept:** a Hush construct made from generations of inspection forms preserves every space at its last “approved safe state,” trapping moving civilians and routes.  
**Mastery:** Ending logic preview—release useful safe states while surviving the construct's attempts to restore them.  
**Reward:** rare field-kit modifier + late Pulse clue.

---

# 5. Community Disconnection Projects — 6

These unlock after Cairnfall stops Meridian's correction loop. Each project lets a region build a **local future**, not merely turn off a tower.

Critical story progress assumes communities begin acting. 100% requires completing all six full projects.

## D01 — Many Roots, Many Bells
**ID:** `community.rootmere.many_roots_many_bells`  
**Goal:** replace the single state-linked bell-oak reference with several smaller living resonators maintained by keeper families.  
**Requirements:** Rootmere contracts C07–C09, Common Measure, at least one local testimony, optional Anchor upgrade makes work easier but is not required.  
**Gameplay:** inspect safe load ranges, distribute resonators, let them drift inside agreed tolerances.  
**Reward:** permanent Rootmere moving state, local service shortcut, credits expansion.

## D02 — Fog Without Meridian
**ID:** `community.saltreach.fog_without_meridian`  
**Goal:** coordinate manual fog towers and pressure bells without one capital time signal.  
**Requirements:** C10/C13, Breath Ledger, Common Measure; Local Accord gives the best convenience result but is not required for initial success.  
**Gameplay:** establish overlapping warning windows and physically test a ship route.  
**Reward:** harbor travel service + credits fleet shot.

## D03 — Maker's Clock
**ID:** `community.emberstep.makers_clock`  
**Goal:** foundries share practical heat/shift warnings while preserving independent local kiln cycles.  
**Requirements:** C14/C17, Temper Cycle, maker records.  
**Gameplay:** route waste heat, set local signal tolerances, decide which old state hardware is melted down for community bells.  
**Reward:** advanced forge service + credits maker-name display.

## D04 — Open Copies
**ID:** `community.highaerie.open_copies`  
**Goal:** eliminate the single master archive while keeping enough cross-reference that contradictory records remain usable.  
**Requirements:** High Aerie contradiction records, C20, Palinode.  
**Gameplay:** physically distribute copy sets through courier routes and annotate conflicts rather than selecting a winner.  
**Reward:** region lore-assist service + credits traveling library.

## D05 — Public Seams
**ID:** `community.mireglass.public_seams`  
**Goal:** identify safe natural Hush seams as civic memory/mourning spaces rather than either hiding them or forcing them closed.  
**Requirements:** C21/C22, Mirror Nail, Memory, selected Witness records.  
**Gameplay:** stabilize boundaries, establish use rules with residents, resolve one seam that is unsafe and must be closed.  
**Reward:** Mireglass seam travel convenience + credits family scenes.

## D06 — Report the Drift
**ID:** `community.cairnfall.report_the_drift`  
**Goal:** convert the observatory from a correction system into a network that reports disagreement honestly.  
**Requirements:** C23/C24, seam mode, Local Accord optional but recommended.  
**Gameplay:** disconnect correction actuators while keeping observation instruments alive; publish raw ranges to other regions.  
**Reward:** late completion-assist upgrade showing unresolved category counts by subregion + credits school scene.

---

# 6. Mastery Complex — The Broken Standard Yard

**ID:** `mastery.broken_standard_yard`  
**Availability:** Unringing, after all critical-path major verbs  
**100% requirement:** complete the seven commissions once  
**Score chase:** not part of 100%

## Fiction

Outside Cairnspire sits an abandoned Bellwarden certification yard built to prove every field worker could perform procedures exactly the same way.

Tessa, Eda Vell, and relief crews repurpose it into the opposite thing: a place to test whether a bellwright can understand **why** a procedure works and adapt when the standard setup is wrong.

The yard's old numbered stations remain visible, but new workers have painted over their original instructions with questions.

## Commission 1 — Load Under Fire
**Systems:** Anchor Line + lock-on combat  
**Problem:** keep a suspended relief load safe while pressure enemies attack from two directions. The player cannot simply kill everything first because the load drifts continuously.

## Commission 2 — Flooded Heatline
**Systems:** Glasslung + Temper + Breath Ledger  
**Problem:** restore a heat exchanger in a partially flooded chamber while keeping two incompatible materials inside different safe ranges.

## Commission 3 — Silent Diagnosis
**Systems:** core combat + Palinode + visual reads  
**Problem:** identify which of three apparent threats is physically committed while all audio tells are suppressed.

## Commission 4 — Moving Relief
**Systems:** Vane + Anchor + movement  
**Problem:** carry a fragile medical rig across moving suspension infrastructure; dropping the rig changes the route but does not hard-fail the room, forcing recovery.

## Commission 5 — Contradictory Machine
**Systems:** Palinode + Mirror Nail  
**Problem:** two working historical configurations overlap. Build a safe present state without erasing either recorded configuration.

## Commission 6 — Close Behind You
**Systems:** seam mode + Seam Brace + Ending principle  
**Problem:** crossing is easy if the player leaves every seam open; doing so destabilizes the departure area. Progress requires closing useful routes after committing to them.

## Commission 7 — The Field Commission
**Systems:** player-selected loadout; at least four major verbs  
**Problem:** a deliberately under-specified failed civic machine presents symptoms rather than objectives. Multiple safe solutions are accepted if they satisfy physical constraints. Combat pressure may occur depending on the chosen route, but there is no single designer-prescribed sequence.

### Completion reward — Open-Hand Coupler

The Yard's reward is an **Open-Hand Coupler** for Neris's field kit.

Effect:
- outside combat and active hazard states, Neris may swap one compatible optional tool modifier in the field rather than returning to a refuge;
- no new mandatory verb;
- no raw damage bonus;
- valuable for postgame completion and experimentation.

Cosmetic recognition:
- Neris receives a cloth field wrap stamped by several independent workshops, each mark visibly different.

The old Bellwarden yard does not issue a master certification seal.

---

# 7. Anti-grind and failure rules

- Trials may be retried instantly or from a nearby restart point.
- Moving Hunt targets are authored and deterministic; failure should reset the local target route without forcing a world reload.
- Elite encounters can be abandoned and revisited.
- Prestige stages never require random drops.
- Community projects remember completed substeps through stable IDs.
- Mastery Yard rooms can be practiced individually after first discovery.
- No content in this document requires online connectivity for 100%.

---

# 8. Vertical-slice subset

The vertical slice should prove this large-content philosophy with a tiny representative set:

- one Skill Trial tied to the slice's tool;
- one two-stage local prestige teaser that cannot yet complete;
- one optional elite encounter or high-pressure variant;
- one miniature community consequence after the slice state change;
- one challenge where the reward changes a tool's operation rather than a stat;
- completion journal entries for all of the above.

If those feel like disconnected errands, the content architecture has failed before scale becomes expensive.