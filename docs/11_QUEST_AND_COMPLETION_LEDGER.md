# 11 — Quest and Completion Ledger

**Status:** canonical content plan for 100% coverage  
**Related:** `docs/10_COMPLETION_MODEL.md`, Issue #14

This document answers a question the project must be able to answer before full production:

> What does a complete Stillring save actually contain?

The counts below are **content-budget targets**, not promises that bad content survives playtesting just to preserve a number. Cutting or adding an entry requires updating this ledger and the 100% route in the same change.

The design target is not to imitate another game's side quests. It is to reproduce the **discipline of a fully authored adventure**: optional systems appear early, new verbs reopen old spaces, relationships cross regions, and late completion reflects what the player actually learned and changed.

---

# 1. Stable ID contract

All completion-bearing authored content receives a semantic ID before implementation.

Formats:

```text
contract.<region>.<slug>
setup.<region>.<slug>
refuge.<region>.<slug>
fault.<region>.<slug>
pulse.<region>.<slug>
vault.<region>.<slug>
record.<set>.<slug>
trial.<region>.<slug>
elite.<region>.<slug>
community.<region>.<slug>
hunt.<region>.<slug>
pattern.<slug>
upgrade.<tool>.<slug>
prestige.unstandard.<stage>
```

Display names may change. IDs should not change after save compatibility matters unless a migration is supplied.

Node paths, translated strings, scene-tree instance IDs, coordinates, and quest titles are not persistence keys.

---

# 2. Shipping completion budget

| Category | Target | 100% bearing? | Notes |
|---|---:|---|---|
| Main story | 1 complete route | yes | Credits must be reached. |
| Local Repair Contracts | 24 | yes | Mandatory tutorial contracts count automatically when completed in story. |
| Cross-state Setup/Payoff chains | 12 | yes | 100% requires reaching each payoff state, not choosing a prescribed moral answer. |
| Bellwright Refuges | 11 | yes | Discover and resolve each unique service/record. |
| Resonance Faults | 48 | yes | Global verb-gated exploration track. |
| Pulse Shards | 28 | yes | Field-harness resilience track; not grouped as four-heart pieces. |
| Cantor Patterns | 9 | yes | Cataloged in `docs/13_CANTOR_AND_UPGRADE_CATALOG.md`. |
| Tool Mastery Upgrades | 14 | yes | Cataloged in doc 13. |
| Skill Trials | 9 | yes | Defined in doc 14. |
| Micro-vaults / maintenance cavities | 30 | yes | One compact authored idea each. |
| Testimonies / field records | 32 | yes | Organized into eight meaningful sets. |
| Prestige craft quest | 12 stages | yes | `The Unstandard Tool`; defined in doc 14. |
| Moving traversal hunt | 12 targets | yes | Defined in doc 14. |
| Optional elite encounters | 8 | yes | Defined in doc 14. |
| Community disconnection projects | 6 | yes | One per major region; credits-state impact. |
| Mastery complex | 1 | yes | Completion reward required; score optimization is not. |
| Repeatable scores / currency / random drops | unlimited | **no** | Never required for 100%. |

---

# 3. Regional allocation

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

---

# 4. Local Repair Contracts — 24

A contract is a person/community problem expressed through bellwright work. Generic “bring me five ore” jobs do not qualify unless transport/material constraints themselves create the interesting mechanic.

## First Circuit — 5

### C01 — The Crooked Fire Bell
**ID:** `contract.brindle.crooked_fire_bell`  
**NPC:** Mara Pell, retired carpenter  
**Availability:** opening/First Circuit  
**Problem:** Brindle's old fire bell rings off-frequency after its bracket warps. Cairnspire's replacement standard would require discarding the bell Mara's late wife cast.  
**Play:** diagnose the bracket, test the bell under load, then either replace the bracket to standard or brace/tune around the bell's existing imperfection.  
**Reward:** Pulse Shard + Mara's workshop access.  
**Later consequence:** feeds Setup S01. Neither resolution is labeled good/evil, but only the locally tuned imperfect bell produces the particular moving pocket described after Stillness; the standardized solution has a different later safety payoff.

### C02 — Twelve Minutes Missing
**ID:** `contract.cairnspire.route_house_timestamps`  
**NPCs:** Tessa; route clerk Pellon Vey  
**Availability:** Cairnspire registration; critical-path contract  
**Problem:** a courier relay's timestamps have been falsified to hide chronic understaffing, causing route synchronization errors.  
**Play:** compare physical wear, route ledgers, and signal timing; the answer is social as well as technical.  
**Reward:** access to Ilyra's certification search; counts automatically for completion.  
**Later consequence:** Pellon can become a useful independent dispatcher during the Unringing if the staffing abuse is documented rather than pinned on one exhausted clerk.

### C03 — Graymile's Open Bypass
**ID:** `contract.circuit.graymile_bypass`  
**NPC:** Kest Lorn, route technician  
**Availability:** First Circuit  
**Problem:** workers use an unauthorized maintenance bypass because the certified service tunnel is structurally unsafe. Management wants the bypass sealed rather than the tunnel fixed.  
**Play:** inspect both routes, brace the bypass or seal it, and document why the official route failed.  
**Reward:** micro-vault access + route-worker testimony.  
**Later consequence:** feeds Setup S02.

### C04 — A Lantern Without a Bell
**ID:** `contract.circuit.lantern_without_bell`  
**NPC:** Dori Senn, keeper of a tiny roadside inn  
**Availability:** First Circuit  
**Problem:** the inn's arrival lantern was designed to pulse from a road-bell signal that no longer exists. Dori refuses an expensive state replacement.  
**Play:** repurpose a wind-driven shutter and local chime into a mechanical arrival indicator.  
**Reward:** first optional field-kit service discount + Pulse Shard.  
**Later consequence:** after Stillness the purely local mechanism continues working and becomes a courier rendezvous.

### C05 — The Fourth Landing
**ID:** `contract.cairnspire.fourth_landing`  
**NPC:** Jeren Coil, municipal lift mechanic  
**Availability:** after Glasslung Reed; first seen before Rootmere  
**Problem:** a public pressure lift has skipped the fourth maintenance landing for years because central pressure specifications make that stop “inefficient.” Residents above it have turned the inaccessible landing into an unofficial repair commons.  
**Play:** use Glasslung to re-balance the lift without breaking service to other floors.  
**Reward:** Refuge R03 fully opens + Anchor/Glasslung upgrade component.  
**World role:** demonstrates that revisits are about people and access, not only hidden chests.

## Rootmere — 4

### C06 — The Root That Isn't Sick
**ID:** `contract.rootmere.root_not_sick`  
**NPC:** Keeper Amsa Wren  
**Availability:** regional approach; required to gain Root Cathedral access  
**Problem:** Cairnspire blames the bell-oak for resonance collapse; Amsa believes old foreign braces are poisoning its load paths.  
**Play:** trace water pressure, bark vibration, and buried metal strain.  
**Reward:** dungeon access; records an official contradiction.  
**Completion:** critical-path and automatic.

### C07 — Widow's Ferrygate
**ID:** `contract.rootmere.widows_ferrygate`  
**NPC:** Lio Fen, ferry operator  
**Availability:** after Anchor Line  
**Problem:** Lio's late husband's hand-built gate opens unevenly and the state inspector wants the entire ferry closed.  
**Play:** tension the gate under changing river load and decide whether to preserve the asymmetric mechanism or rebuild its linkage.  
**Reward:** Pulse Shard + permanent river shortcut.  
**Later:** the chosen linkage behaves differently in Stillness pulses but both remain viable.

### C08 — Orchard of Split Notes
**ID:** `contract.rootmere.split_note_orchard`  
**NPC:** Nemi Tal, orchard keeper  
**Availability:** after Glasslung Reed  
**Problem:** irrigation bells make two tones depending on water pressure; the central diagnostic treats one as failure although both correspond to healthy seasonal states.  
**Play:** restore pressure channels and record both states with the Cantor Key.  
**Reward:** Cantor pattern clue + Fault location count for Rootmere.  
**Theme:** prepares the player to distrust single-state diagnostics.

### C09 — A Name Under Bark
**ID:** `contract.rootmere.name_under_bark`  
**NPC:** child keeper Olo Wren; later Caldrin  
**Availability:** post-Stillness with Palinode Pattern  
**Problem:** a bark scar seems to contain a name that official Rootmere records do not recognize.  
**Play:** hear two incompatible maintenance histories, locate a buried pre-network marker, and decide how the community records the worker whose name was erased.  
**Reward:** testimony + tool mastery component.  
**Credits:** recovered name appears on the public Rootmere maintenance board.

## Saltreach — 4

### C10 — The Fog Tower That Lies
**ID:** `contract.saltreach.fog_tower_lies`  
**NPC:** old signal keeper Vessa Mor  
**Availability:** before Tide Foundry  
**Problem:** a tower reports correct timing but wrong direction because its state-issued calibration assumes a shoreline that moved decades ago.  
**Play:** triangulate actual sound paths from boats and coastal markers.  
**Reward:** safe harbor route + record.  
**Later:** feeds Setup S06.

### C11 — Dry Dock at Low Water
**ID:** `contract.saltreach.dry_dock_low_water`  
**NPC:** shipwright Pell Aro  
**Availability:** after Glasslung  
**Problem:** temporal tide irregularities trap a dry dock between pressure states.  
**Play:** use Glasslung to equalize chambers in a sequence determined by physical gauges, not a button code.  
**Reward:** Pulse Shard + cheaper equipment service.  
**Revisit:** later Mirror Nail reveals a never-built auxiliary dock with one optional route.

### C12 — Kelp Bell Funeral
**ID:** `contract.saltreach.kelp_bell_funeral`  
**NPC:** Marao family  
**Availability:** after Tide Foundry  
**Problem:** a family wants to recover a drowned navigation bell used in a relative's final rescue, but the harbor authority wants it left as evidence.  
**Play:** locate the bell, recover its recording cylinder, then choose whether the physical bell stays in the water while its sound/memory is preserved ashore.  
**Reward:** Pulse Shard + testimony.  
**Theme:** memory without compulsory physical possession.

### C13 — Two Captains, One Tide
**ID:** `contract.saltreach.two_captains_one_tide`  
**NPCs:** Captain Rell Dava; Captain Imi Sorn  
**Availability:** post-Stillness  
**Problem:** two moving pockets overlap on opposite sides of the harbor, and each captain wants scarce manual signal equipment first.  
**Play:** use route knowledge and local pressure bells to create a schedule that coordinates without one master clock.  
**Reward:** community-project prerequisite + fault-hunt service.  
**Credits:** both fleets can appear if resolved.

## Emberstep — 4

### C14 — Names Ground Flat
**ID:** `contract.emberstep.names_ground_flat`  
**NPC:** Sena Ash  
**Availability:** regional approach; part of access story  
**Problem:** state seals replaced individual maker names on public bell castings. Sena wants proof before accusing the capital publicly.  
**Play:** inspect erased castings, compare old molds, and route evidence through Tessa's couriers.  
**Reward:** Kiln access + maker-record set begins.  
**Completion:** critical-path and automatic.

### C15 — The Cold Kiln
**ID:** `contract.emberstep.cold_kiln`  
**NPC:** apprentice foreman Varo Neel  
**Availability:** after Temper Gauntlet  
**Problem:** a small community kiln cannot reach uniform state-certified temperature, but its uneven heat is ideal for repair alloys the state no longer teaches.  
**Play:** map thermal zones and redesign work placement instead of forcing uniform heat.  
**Reward:** Temper upgrade component + new repair recipes/services.  
**Theme:** make variance useful.

### C16 — Crack in the Foreman's Cup
**ID:** `contract.emberstep.foreman_cup`  
**NPC:** Sena Ash  
**Availability:** after Kiln of Names  
**Problem:** a cheap metal cup used by Sena's dead mentor has a crack that makes one diagnostic machine reject it as scrap. Sena asks Neris to repair it without removing the crack's visible history.  
**Play:** controlled heat, quench, and brace; no combat.  
**Reward:** Pulse Shard + personal Sena scene.  
**Story mirror:** deliberately echoes Ilyra's habit of listening to cracked cups without copying a quest from another game.

### C17 — Borrowed Heat
**ID:** `contract.emberstep.borrowed_heat`  
**NPCs:** clinic engineer Ressa Pai; foundry scheduler Ko Marn  
**Availability:** post-Stillness  
**Problem:** the clinic needs waste heat from a foundry whose normal timing is frozen.  
**Play:** combine Glasslung and Temper to route intermittent steam manually; establish a local signaling procedure.  
**Reward:** community-project prerequisite + refuge service expansion.  
**Later:** feeds Setup S09 if the emergency quench bypass was preserved.

## High Aerie — 3

### C18 — Weight of the Archive
**ID:** `contract.highaerie.archive_weight`  
**NPC:** Brother Caldrin  
**Availability:** changed-world approach  
**Problem:** frozen archive counterweights will drop entire shelves when motion returns. The order wants to save canonical records first.  
**Play:** choose structural priorities based on physical load and create a distributed rescue plan; optional records saved depend on earlier evidence.  
**Reward:** High Aerie refuge access + records.  
**Theme:** preserving knowledge cannot mean preserving hierarchy first.

### C19 — Chain Nine Sings
**ID:** `contract.highaerie.chain_nine`  
**NPC:** rigging master Sal Em  
**Availability:** after Vane Cloak  
**Problem:** one suspension chain emits a tone only during crosswind and is scheduled for replacement as defective. In fact it is warning of lateral load the other chains cannot sense.  
**Play:** Vane traversal + Anchor tension tests in changing gusts.  
**Reward:** Anchor upgrade component + permanent vertical shortcut.

### C20 — The Novice Who Cut the Bellrope
**ID:** `contract.highaerie.cut_bellrope`  
**NPC:** novice Pera Dinn  
**Availability:** after Motion  
**Problem:** Pera cut a ceremonial rope during the Grand Ring and believes the act caused part of the monastery failure. The order wants a confession; physical evidence says the cut prevented forced entrainment from reaching a dormitory.  
**Play:** reconstruct load history with Palinode Pattern and interview survivors.  
**Reward:** testimony + Pulse Shard.  
**Credits:** Pera appears training new riggers if the event is publicly recorded accurately.

## Mireglass — 2

### C21 — The House That Remembers a Door
**ID:** `contract.mireglass.house_remembers_door`  
**NPC:** Iven and Sol Marr  
**Availability:** after Mirror Nail  
**Problem:** a family home has an echo-door leading to a room demolished after a child's death. One partner wants it pinned permanently; the other wants it gone.  
**Play:** use Palinode and Mirror Nail to recover what the room actually contains, then help choose a limited memorial use rather than permanent physical restoration.  
**Reward:** Pulse Shard + Memory-themed record.  
**Rule:** neither partner is designated the morally correct one.

### C22 — Witness at Reedwater
**ID:** `contract.mireglass.reedwater_witness`  
**NPC:** former court interpreter Senae Pell  
**Availability:** after Memory  
**Problem:** a historic treaty has three surviving versions and a Hush witness that cannot speak while one copy is being treated as canonical.  
**Play:** collect/compare the versions, use Palinode, commit short states with Mirror Nail, and produce an annotated public account containing disagreement.  
**Reward:** Mireglass fault-count upgrade + testimony set completion path.

## Cairnfall — 2

### C23 — The Telescope That Disagrees
**ID:** `contract.cairnfall.telescope_disagrees`  
**NPC:** surveyor Hett Vara  
**Availability:** before Fallen Orrery  
**Problem:** two observation instruments disagree about a star's apparent phase. The correction network marks one as broken; both are functioning from different reference assumptions.  
**Play:** compare raw measurements, Palinode histories, and local mechanical drift.  
**Reward:** observatory side route + record.  
**Teaching:** direct setup for Cairnfall's reference-frame dungeon language.

### C24 — No Correction Required
**ID:** `contract.cairnfall.no_correction_required`  
**NPC:** Hett Vara + junior survey crew  
**Availability:** after Gravemoon Engine  
**Problem:** local instruments keep reporting disagreement after central correction is disabled. Young surveyors assume that means the repair failed.  
**Play:** establish a reporting protocol that preserves disagreement and uncertainty instead of forcing one corrected figure.  
**Reward:** community project unlocked + Key upgrade component.  
**Credits:** school observatory uses the protocol.

---

# 5. Cross-state Setup / Payoff chains — 12

Each setup is a **remembered authored action** whose consequence becomes visible after Stillness. Completion requires resolving the later payoff, not making one predetermined early choice.

| ID | Setup before Grand Ring | Post-Stillness payoff |
|---|---|---|
| `setup.brindle.crooked_fire_bell` | Resolve C01 by standard replacement or local asymmetric brace. | Standard replacement gives reliable warning during brief motion but phase-locks fully; local brace creates a smaller irregular moving pocket. Both produce different survivor scenes and both can be resolved to completion. |
| `setup.circuit.graymile_bypass` | Seal or reinforce the unofficial worker bypass in C03. | Reinforced route becomes a courier escape path with Hush contamination risk; sealed route keeps contamination out but forces a later exterior rescue route. |
| `setup.circuit.unregistered_pattern` | Learn Common Measure from independent viaduct bellwrights instead of dismissing it as uncertified. | The pattern stabilizes small machines without Meridian reference and becomes the first practical tool for creating local moving pockets. |
| `setup.rootmere.green_span` | During first visit, choose how to brace a young living root bridge: rigid state plate or flexible keeper weave. | The rigid version remains intact but frozen; flexible weave continues oscillating and opens a moving route. Later work can recover whichever route was lost. |
| `setup.rootmere.wrens_margin` | Copy Amsa Wren's handwritten warning into Neris's field journal before turning over the official report. | After archives freeze, the personal copy gives Caldrin evidence needed to locate A Name Under Bark. |
| `setup.saltreach.manual_fog_code` | Repaint Vessa Mor's local fog code while resolving C10. | Manual code is readable when central navigation freezes and determines which harbor shelter becomes reachable first. |
| `setup.saltreach.levis_pressure_release` | After the Leviathan encounter, leave the old cistern pressure bypass independent rather than reconnecting it to central regulation. | The bypass pulses out of phase and creates a moving deep-inlet refuge; reconnecting it instead protects a different dock from pressure damage. |
| `setup.emberstep.maker_marks` | Preserve/republish individual maker marks during C14. | Post-Stillness workers can identify which castings use local alloys and selectively disconnect them instead of scrapping everything. |
| `setup.emberstep.quench_bypass` | During Kiln cleanup, repair or permanently close a manually operated emergency quench branch. | Repaired branch creates the steam moving-pocket used in C17; closed branch prevents a dangerous rupture but requires another clinic heat route. |
| `setup.highaerie.distributed_copy` | During Cairnspire Act One, allow Caldrin to send a disputed record copy through Tessa instead of keeping evidence secret until verified. | When High Aerie's master archive freezes, the traveling copy lets novices challenge the sealed official account sooner. |
| `setup.mireglass.personal_provenance` | A Mireglass traveler on the First Circuit asks Neris to register a cracked diplomatic hand-mirror as personal provenance rather than anonymous state salvage. | The named provenance later identifies the shared mundane event used to resolve one Palace Under Reeds memory branch. |
| `setup.cairnfall.uncorrected_lens` | In Cairnspire's civic collection, leave an obsolete Cairnfall survey lens with its documented drift rather than recalibrating it as a favor. | Ilyra uses the known drift after Stillness to distinguish a real Cairnfall phase coordinate from Meridian's corrected false coordinate. |

---

# 6. Bellwright Refuges — 11

Refuges are service/history nodes grounded in actual infrastructure. They are not identical magical caves.

| ID | Name | First access | Unique reason to exist |
|---|---|---|---|
| `refuge.circuit.old_viaduct` | Old Viaduct Refuge | First Circuit | independent bellwright workshop; teaches Common Measure; seeds prestige quest |
| `refuge.brindle.east_culvert` | East Culvert Shed | after first Brindle revisit | Orin's old flood-service locker; early field-harness service |
| `refuge.cairnspire.fourth_landing` | Fourth Landing Commons | after C05 / Glasslung | unofficial municipal repair commons hidden by lift routing |
| `refuge.rootmere.reed_screw_house` | Reed-Screw House | Rootmere first visit | keeper-made living-material repair station |
| `refuge.saltreach.lowwater_locker` | Lowwater Locker | low tide / Glasslung | harbor pressure-service cache; underwater-route support |
| `refuge.emberstep.ashbreak_room` | Ashbreak Room | after Temper | worker rest/repair chamber built into thermal dead zone |
| `refuge.highaerie.chainhouse_seven` | Chainhouse Seven | High Aerie approach | suspension-rig workshop and Vane service |
| `refuge.highaerie.storm_blind` | Storm Blind | after Vane | tiny weather station above normal monastery routes |
| `refuge.mireglass.reed_chapel_shop` | Reed-Chapel Workshop | Mireglass | civic repair room in a deconsecrated diplomatic chapel; memory services |
| `refuge.cairnfall.night_survey_hut` | Night Survey Hut | Cairnfall | instrument calibration and seam-safe staging |
| `refuge.hush.ilyras_workbench` | Ilyra's Workbench | after Grand Ring | Hush anchor rebuilt from Ilyra's memory; narrative/service node, not a physical shop |

100% requires discovering each refuge and resolving its unique one-time service, lesson, or record. Merely walking past the doorway is not enough.

---

# 7. Resonance Faults — 48

A Resonance Fault is a localized synchronization defect. Reconciliation means making the fault safe/readable **without forcing every site to the same state**.

## First Circuit — 8

| ID | Short name | Earliest gate |
|---|---|---|
| `fault.brindle.bell_shed_eave` | Bell-Shed Double Ring | Cantor Key base |
| `fault.brindle.old_mill_tailrace` | Tailrace Tension Hum | Anchor Line |
| `fault.graymile.toll_chime` | Toll Chime Aftertone | base |
| `fault.graymile.bypass_joint` | Bypass Split History | Palinode |
| `fault.cairnspire.late_warning_duct` | Late Warning Echo | base after Cairnspire access |
| `fault.cairnspire.pressure_lift` | Fourth-Landing Pressure Ghost | Glasslung |
| `fault.viaduct.refuge_spandrel` | Spandrel Counterpull | Anchor Line |
| `fault.circuit.old_route_marker` | Moving Route Marker | post-Stillness + Line Skiff |

## Rootmere — 7

| ID | Short name | Earliest gate |
|---|---|---|
| `fault.rootmere.ferry_rootfork` | Ferry Rootfork | base |
| `fault.rootmere.cathedral_seed_gallery` | Seed Gallery Residue | Root Cathedral clear |
| `fault.rootmere.floodgate_crown` | Floodgate Crown Strain | Anchor Line |
| `fault.rootmere.deep_sluice` | Deep Sluice Bubble | Glasslung |
| `fault.rootmere.resin_brace` | Resin-Brace Heat Memory | Temper |
| `fault.rootmere.remembered_orchard` | Orchard That Wasn't | Mirror Nail |
| `fault.rootmere.hush_bell_oak` | Bell-Oak Seam | seam mode |

## Saltreach — 7

| ID | Short name | Earliest gate |
|---|---|---|
| `fault.saltreach.fog_tower_foot` | Fog Tower False North | base |
| `fault.saltreach.foundry_catwalk` | Catwalk Pressure Ring | Tide Foundry clear |
| `fault.saltreach.ballast_pipe` | Ballast Pipe Tension | Anchor Line |
| `fault.saltreach.lowwater_cistern` | Lowwater Countercurrent | Glasslung |
| `fault.saltreach.boiler_hulk` | Cold Boiler Heatprint | Temper |
| `fault.saltreach.unbuilt_pier` | Unbuilt Pier Reflection | Mirror Nail |
| `fault.saltreach.deep_tide_seam` | Deep Tide Seam | seam mode |

## Emberstep — 7

| ID | Short name | Earliest gate |
|---|---|---|
| `fault.emberstep.slag_canal` | Slag Canal Overtone | base |
| `fault.emberstep.kiln_lift` | Kiln Lift Delay | Kiln clear |
| `fault.emberstep.hanging_mold` | Hanging Mold Counterpull | Anchor Line |
| `fault.emberstep.quench_manifold` | Quench Manifold Backpulse | Glasslung |
| `fault.emberstep.cold_forge` | Cold Forge Thermal Echo | Temper |
| `fault.emberstep.erased_maker_wall` | Erased Maker Chorus | Palinode |
| `fault.emberstep.ghost_casting_floor` | Casting Floor Double State | Mirror Nail |

## High Aerie — 6

| ID | Short name | Earliest gate |
|---|---|---|
| `fault.highaerie.chainhouse_lower` | Chainhouse Standing Wave | High Aerie access |
| `fault.highaerie.updraft_gallery` | Broken Updraft Loop | Vane Cloak |
| `fault.highaerie.archive_false_shelf` | False Shelf History | Palinode |
| `fault.highaerie.tempest_rod` | Tempest Rod Delay | Motion |
| `fault.highaerie.varo_memorial` | Heroic Reset | Mirror Nail |
| `fault.highaerie.storm_seam` | Storm Blind Seam | seam mode |

## Mireglass — 6

| ID | Short name | Earliest gate |
|---|---|---|
| `fault.mireglass.reed_causeway` | Reed Causeway Echo Step | Mireglass access |
| `fault.mireglass.diplomat_cistern` | Diplomat Cistern Voice | Glasslung |
| `fault.mireglass.mirror_hall` | Mirror Hall Contradiction | Palinode |
| `fault.mireglass.false_veranda` | Veranda With No House | Mirror Nail |
| `fault.mireglass.widow_chamber` | Shared Memory Residue | Memory |
| `fault.mireglass.buried_seam` | Reed-Bed Seam | seam mode |

## Cairnfall — 5

| ID | Short name | Earliest gate |
|---|---|---|
| `fault.cairnfall.outer_lenswalk` | Lenswalk Crosswind Error | Vane Cloak |
| `fault.cairnfall.starweight` | Starweight Tension Drift | Anchor Line |
| `fault.cairnfall.correction_ring` | Correction Ring Disagreement | Palinode |
| `fault.cairnfall.abandoned_prediction` | Prediction Made Physical | Mirror Nail |
| `fault.cairnfall.null_well` | Null Observation Well | seam mode |

## Late — 2

| ID | Short name | Earliest gate |
|---|---|---|
| `fault.stillcairn.unbuilt_station` | Station That Almost Opened | Mirror Nail + seam mode |
| `fault.nullmeridian.worker_bypass` | Court Worker Bypass | Null Meridian finale |

### Fault reward cadence

Thresholds are intentionally not borrowed from another game's exact numbers:

- **6 reconciled:** Cantor diagnostic remembers the last heard fault signature.
- **13:** field-kit utility slot/service expansion.
- **21:** journal gains exact unresolved-fault count per discovered region.
- **30:** one Cantor recovery-quality upgrade.
- **39:** access to the final moving-fault hunt tier and rare tool component.
- **48:** completion recognition, a postgame diagnostic mode, and a credits annotation showing the network mapped as local seams rather than a single repaired grid.

These thresholds can be tuned in playtest, but changes require migration-safe reward logic.

---

# 8. Pulse Shards — 28

Pulse Shards are resonant ceramic/metallic reinforcement pieces fitted into Neris's field harness at refuges. They are **not heart-shaped**, not automatically assembled in groups of four, and not a direct copy of another health-piece system.

The shipping curve should use varying service requirements so finds remain individually meaningful. Exact resilience math is a balance task.

| ID | Source / authored context | Earliest phase |
|---|---|---|
| `pulse.brindle.kite_roof` | optional opening traversal/kite help payoff | opening |
| `pulse.brindle.crooked_fire_bell` | C01 | First Circuit |
| `pulse.circuit.lantern_inn` | C04 | First Circuit |
| `pulse.cairnspire.public_lift` | Fourth Landing service | Glasslung revisit |
| `pulse.circuit.viaduct_trial` | First Circuit mastery trial | First Circuit |
| `pulse.rootmere.ferrygate` | C07 | Anchor |
| `pulse.rootmere.cathedral_side` | optional Root Cathedral side branch | Rootmere |
| `pulse.rootmere.split_orchard` | Orchard side route | Glasslung revisit |
| `pulse.rootmere.memory_hollow` | late Rootmere micro-vault | Mirror Nail |
| `pulse.saltreach.dry_dock` | C11 | Glasslung |
| `pulse.saltreach.kelp_funeral` | C12 | Saltreach clear |
| `pulse.saltreach.fog_trial` | signal-reading mastery trial | Saltreach |
| `pulse.saltreach.unbuilt_pier` | echo-state micro-vault | Mirror Nail |
| `pulse.emberstep.foreman_cup` | C16 | Temper |
| `pulse.emberstep.cold_kiln` | C15 | Temper |
| `pulse.emberstep.slag_trial` | thermal mastery trial | Emberstep |
| `pulse.emberstep.erased_name` | late testimony/vault payoff | Palinode |
| `pulse.highaerie.archive_weight` | C18 | High Aerie |
| `pulse.highaerie.cut_rope` | C20 | Motion |
| `pulse.highaerie.storm_blind` | Storm Blind refuge challenge | Vane |
| `pulse.mireglass.remembered_door` | C21 | Mirror Nail |
| `pulse.mireglass.reedwater` | C22 | Memory |
| `pulse.mireglass.sunken_witness` | micro-vault | seam mode |
| `pulse.cairnfall.disagreeing_scope` | C23 | Cairnfall |
| `pulse.cairnfall.night_survey` | refuge calibration puzzle | Cairnfall |
| `pulse.cairnfall.null_pocket` | micro-vault | seam mode |
| `pulse.stillcairn.family_stair` | optional Still-Cairn route | Ending arc |
| `pulse.stillcairn.unreleased_room` | optional deliberate-release puzzle | Ending arc |

---

# 9. Micro-vaults / Maintenance Cavities — 30

These are 1–5 minute authored spaces. Names indicate fiction and gate; they are **not room-layout specifications**.

## First Circuit — 6

| ID | Name | Gate | Reward class |
|---|---|---|---|
| `vault.brindle.mill_tailbox` | Mill Tailbox | Anchor | Fault / material cache |
| `vault.graymile.drain_bell` | Graymile Drain Bell | base observation | record / currency |
| `vault.cairnspire.pressure_lift_pocket` | Pressure-Lift Pocket | Glasslung | Pulse / refuge access |
| `vault.viaduct.rope_cage` | Viaduct Rope Cage | Anchor | prestige component clue |
| `vault.circuit.tollhouse_echo_niche` | Tollhouse Echo Niche | Palinode | record / Fault clue |
| `vault.circuit.culvert_seam_box` | Culvert Seam Box | seam mode | rare upgrade component |

## Rootmere — 4

| ID | Name | Gate | Reward class |
|---|---|---|---|
| `vault.rootmere.floodgate_cheek` | Floodgate Cheek | Anchor | Pulse / material |
| `vault.rootmere.silt_choir_shaft` | Silt Choir Shaft | Glasslung | Fault / record |
| `vault.rootmere.resin_lockbox` | Resin Lockbox | Temper | upgrade component |
| `vault.rootmere.memory_root_hollow` | Memory-Root Hollow | Mirror Nail | Pulse / testimony |

## Saltreach — 4

| ID | Name | Gate | Reward class |
|---|---|---|---|
| `vault.saltreach.dry_cistern_lip` | Dry Cistern Lip | Anchor | material / Fault clue |
| `vault.saltreach.ballast_tube` | Sealed Ballast Tube | Glasslung | Pulse / upgrade component |
| `vault.saltreach.boiler_shell` | Boiler Shell | Temper | tool material |
| `vault.saltreach.drowned_ledger_booth` | Drowned Ledger Booth | Mirror Nail | testimony / prestige clue |

## Emberstep — 4

| ID | Name | Gate | Reward class |
|---|---|---|---|
| `vault.emberstep.slag_chute` | Slag Chute Locker | base / movement | material / currency |
| `vault.emberstep.suspended_mold_cage` | Suspended Mold Cage | Anchor | Pulse / component |
| `vault.emberstep.quench_throat` | Quench Throat | Glasslung + Temper | upgrade component |
| `vault.emberstep.erased_name_vault` | Erased-Name Vault | Palinode + Mirror | testimony / prestige stage |

## High Aerie — 3

| ID | Name | Gate | Reward class |
|---|---|---|---|
| `vault.highaerie.counterweight_loft` | Counterweight Loft | Vane + Anchor | upgrade component |
| `vault.highaerie.silent_draft_duct` | Silent Draft Duct | Palinode | record / Fault |
| `vault.highaerie.storm_anchor_cell` | Storm Anchor Cell | Mirror + seam | rare component |

## Mireglass — 3

| ID | Name | Gate | Reward class |
|---|---|---|---|
| `vault.mireglass.reed_cellar` | Reed Cellar | Glasslung | material / record |
| `vault.mireglass.reflection_annex` | Reflection Annex | Mirror Nail | Pulse / Fault |
| `vault.mireglass.sunken_witness_room` | Sunken Witness Room | seam mode | Pulse / testimony |

## Cairnfall — 3

| ID | Name | Gate | Reward class |
|---|---|---|---|
| `vault.cairnfall.starweight_ring` | Starweight Service Ring | Vane + Anchor | upgrade component |
| `vault.cairnfall.correction_well` | Correction Well | Mirror Nail | record / Fault |
| `vault.cairnfall.null_observation_pocket` | Null Observation Pocket | seam mode | Pulse / prestige component |

## Late — 3

| ID | Name | Gate | Reward class |
|---|---|---|---|
| `vault.stillcairn.unbuilt_civic_stair` | Unbuilt Civic Stair | Mirror + seam | Pulse / Fault clue |
| `vault.stillcairn.demolished_clockroom` | Demolished Clockroom | Ending | testimony / rare material |
| `vault.nullmeridian.court_test_cell` | Abandoned Court Test Cell | finale synthesis | final testimony / cosmetic recognition |

---

# 10. Testimonies / Field Records — 32

Records are organized into sets with a reason to collect them. They are not thirty-two disconnected lore paragraphs.

## Set A — Ilyra's Margins — 5

| ID | Title / source | Region / gate |
|---|---|---|
| `record.ilyra.margin_load_limit` | “Do Not Force Full Synchronization” maintenance plate | Rootmere |
| `record.ilyra.margin_pressure_people` | Saltreach shipping manifest margin questioning pressure tests on crews | Saltreach |
| `record.ilyra.margin_alloy_batch` | experimental Cantor alloy order | Emberstep |
| `record.ilyra.margin_three_reference` | objection to three-point phase test | Emberstep / Act-One convergence |
| `record.ilyra.margin_lens_drift` | Cairnfall lens note preserving intentional calibration drift | Cairnfall |

**Set payoff:** Neris's journal reconstructs Ilyra's technical position as evolving work rather than one prophetic warning.

## Set B — Bellwarden Incident Corrections — 5

| ID | Title / source | Region / gate |
|---|---|---|
| `record.incident.brindle_first_ring` | older Brindle relay casualty correction | First Circuit archive |
| `record.incident.rootmere_poisoning` | revised Rootmere brace-failure report | Rootmere |
| `record.incident.saltreach_fleet_loss` | navigation-bell fleet loss with conflicting count | Saltreach |
| `record.incident.highaerie_varo` | Saint Varo incident correction | High Aerie |
| `record.incident.cairnfall_observer` | survey crew erased after reporting phase disagreement | Cairnfall |

**Set payoff:** Caldrin can create an annotated public incident chronology during the Unringing.

## Set C — Maker Names — 4

| ID | Title / source | Region / gate |
|---|---|---|
| `record.makers.sena_mentor` | Sena's mentor's erased stamp | Emberstep |
| `record.makers.rootmere_bracecrew` | names of workers who installed the harmful Rootmere braces | Rootmere / Palinode |
| `record.makers.saltreach_pressurewright` | pressure-chamber makers listed inside Leviathan hardware | Saltreach |
| `record.makers.cairnspire_public_bells` | municipal makers replaced by state seal | Cairnspire late revisit |

**Set payoff:** Emberstep's credits workshop publicly restores maker attribution practices.

## Set D — Route Workers — 4

| ID | Title / source | Region / gate |
|---|---|---|
| `record.routes.graymile_bypass` | anonymous bypass safety complaint | First Circuit |
| `record.routes.twelve_minutes` | staffing schedule behind falsified timestamps | Cairnspire |
| `record.routes.old_skiff_manual` | pre-central Line Skiff service card | changed-world Brindle |
| `record.routes.unringing_manifest` | first independent courier routing sheet | post-Cairnfall |

**Set payoff:** improves Tessa's route-network completion display and reveals one moving-hunt target window.

## Set E — Saltreach Shipping — 4

| ID | Title / source | Region / gate |
|---|---|---|
| `record.shipping.quiet_crate_one` | sealed Quiet Court equipment manifest | Saltreach |
| `record.shipping.tessa_alias` | old route alias tying Tessa unknowingly to shipment | Saltreach |
| `record.shipping.pressure_chambers` | Leviathan chamber transfer log | Saltreach dungeon |
| `record.shipping.returned_empty` | crate returned empty to a Cairnspire address that did not officially exist | Cairnspire / Palinode |

**Set payoff:** opens a Quiet Court archive side cell in Null Meridian without changing critical path.

## Set F — High Aerie Contradictions — 4

| ID | Title / source | Region / gate |
|---|---|---|
| `record.aerie.varo_hymn` | ceremonial account of Varo | High Aerie |
| `record.aerie.varo_rigger_note` | worker account contradicting the hymn | High Aerie |
| `record.aerie.listener_tablet` | oldest tablet describing Listener containment | High Aerie |
| `record.aerie.master_seal_rule` | policy allowing master copy to override local records | Bone Archive / Caldrin |

**Set payoff:** all four versions display together in the open archive rather than collapsing into a single unlock text.

## Set G — Mireglass Witness Pairs — 3

| ID | Title / source | Region / gate |
|---|---|---|
| `record.mireglass.treaty_a` | first treaty witness account | Mireglass |
| `record.mireglass.treaty_b` | contradictory second account | Mireglass |
| `record.mireglass.kitchen_worker` | mundane worker memory shared across versions | Mirror Widow aftermath |

**Set payoff:** lets C22 resolve with full annotated context and changes a public memorial label.

## Set H — Quiet Court Letters — 3

| ID | Title / source | Region / gate |
|---|---|---|
| `record.court.grieving_families` | early letter demanding honest accident investigation | Null Meridian archive |
| `record.court.ilyra_exit` | Ilyra's unsent explanation for leaving the Court | Still-Cairn / seam route |
| `record.court.state_continuity` | late Maelor memo where people become “state continuity” in his technical language | Null Meridian archive |

**Set payoff:** final journal entry shows how a legitimate accountability movement hardened into coercive ideology without rewriting Maelor as secretly evil from the start.

---

# 11. Region authoring checklist for completion

A region cannot move from content design to production graybox until its ledger answers:

```text
REGION:
critical-path purpose:
first-visit optional content:
pre-Stillness setup/payoffs:
Anchor revisit:
Glasslung revisit:
Temper revisit:
post-Stillness changes:
Line Skiff interaction:
Vane revisit:
Palinode revisit:
Mirror Nail revisit:
seam-mode revisit:
contracts:
refuges:
fault IDs:
pulse IDs:
vault IDs:
record IDs:
trial / elite / hunt entries:
community project:
credits-state consequence:
```

Blank revisit rows are blockers, not “future polish.”

---

# 12. 100% rule

A player reaches 100% by resolving all completion-bearing authored IDs and finishing the story.

**Not required:**
- maximum currency;
- random loot;
- every repeatable score beyond the defined mastery threshold;
- speedrun times;
- cosmetic-only random drops;
- choosing one designer-approved answer in moral/social quests.

The game must expose regional/category completion counts through the field journal by late game so a player can finish a save without reverse-engineering hidden state.

A late diagnostic assist may narrow unresolved content to a subregion after the finale or after a dedicated completion upgrade. It should help completionists without turning the first playthrough into a GPS checklist.