# 185 — Stillring Region / World / Content Production Manifest

**Status:** ACTIVE / STUDIO-HANDOFF WORLD-CONTENT PRODUCTION AUTHORITY / DOCUMENTATION-ONLY  
**Updated:** 2026-09-06  
**Parent program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Gap register:** `docs/152_STUDIO_HANDOFF_GAP_REGISTER.md`  
**Acceptance checklist:** `docs/153_STUDIO_HANDOFF_ACCEPTANCE_CHECKLIST.md`  
**Decision rights:** `docs/170_STUDIO_DECISION_RIGHTS_MATRIX.md`  
**Current completion authority:** `docs/104_COMPLETION_LEDGER_RECONCILIATION_AUTHORITY_ADDENDUM.md`  
**Content traceability:** `docs/146_CONTENT_TRACEABILITY_MATRIX.md`  
**Art production dependencies:** `docs/154_STILLRING_ART_BIBLE.md`, `docs/158_CHARACTER_PRODUCTION_MANIFEST.md`, `docs/159_ENEMY_BOSS_ART_MANIFEST.md`, `docs/160_REGION_ENVIRONMENT_PROP_MANIFEST.md`, `docs/161_REGIONAL_COLOR_MATERIAL_LIGHTING_SCRIPTS.md`, `docs/162_HUSH_VISUAL_PRODUCTION_MATRIX.md`, `docs/163_VFX_PRODUCTION_MANIFEST.md`  
**Animation dependencies:** `docs/173_STILLRING_ANIMATION_BIBLE.md`, `docs/174_ANIMATION_PRODUCTION_MANIFEST.md`  
**UI dependencies:** `docs/176_UI_UX_PRODUCTION_SPECIFICATION.md`, `docs/177_UI_SCREEN_STATE_AND_ASSET_MANIFEST.md`  
**Audio dependencies:** `docs/179_STILLRING_AUDIO_MUSIC_VO_BIBLE.md`, `docs/180_AUDIO_CUE_ASSET_AND_MUSIC_MANIFEST.md`  
**Narrative dependencies:** `docs/182_STILLRING_NARRATIVE_PRODUCTION_BIBLE.md`, `docs/183_NARRATIVE_SCENE_DIALOGUE_TEXT_MANIFEST.md`, canonical story ledgers under `docs/story/`  
**Setup/Payoff authority:** `docs/112`–`docs/119`, especially `docs/115_SETUP_PAYOFF_PORTFOLIO_AUTHORITY_ADDENDUM.md`  
**Line Skiff authority:** `docs/120`–`docs/126`  
**Null Meridian authority:** `docs/127`–`docs/134`  
**Companion:** `docs/186_DUNGEON_ENCOUNTER_AND_NETWORK_PRODUCTION_MANIFEST.md`  
**Closes toward:** `SH-CONT-001` through `SH-CONT-010`  
**Boundary:** this manifest consolidates quoteable regional/world/content workload and cross-discipline dependencies. It does not authorize UE5.8 implementation, final world dimensions, final encounter counts, exact asset counts, runtime representation, performance budgets, final content cuts, or gameplay testing.

---

# 1. Purpose

Stillring already has strong region art, story, animation, audio, UI, completion, Hush, Setup/Payoff and traversal authority.

What production still needs is a single answer to:

> **What must actually exist in each place, in each major world state, and which disciplines must touch it before that place can be called production-complete?**

This document is that consolidation layer.

It does **not** create a duplicate canon database.

It converts current authority into production burden while preserving the governing rule:

> **A region is a lived place with changing work, people, routes, systems and consequences — not a biome plus a dungeon.**

---

# 2. Authority and non-duplication rule

This manifest owns production packaging and dependency visibility only.

It does not override:
- story facts;
- scene order;
- art identity;
- Hush semantics;
- combat or tool rules;
- completion counts;
- Setup/Payoff outcomes;
- Skiff route semantics;
- save/world-state ownership;
- Null Meridian sequence order.

When this manifest names a content unit, the semantic source remains its canonical owner.

Examples:
- a Repair Contract remains Quest/Story + source-world truth;
- a Setup/Payoff chain remains governed by `docs/112`–`119`;
- a Resonance Fault remains its tool/world semantic fact;
- a Line Skiff route remains route-network authority;
- a Hush expression remains one semantic place expressed through Hush authority;
- a scene remains `Mxx-Sxx` story identity rather than a map or Sequencer asset name.

---

# 3. Current canonical content budget — LOCKED

The production package must use the following current global totals from `docs/104` and `docs/146`:

| Category | Current global burden |
|---|---:|
| Main Story | 1 complete route |
| Local Repair Contracts | 24 |
| Cross-state Setup/Payoff chains | 12 |
| Bellwright Refuges | 11 |
| Resonance Faults | 36 |
| Pulse Shards | 18 |
| Cantor Patterns | 9 |
| Tool Mastery Upgrades | 14 |
| Skill Trials | 9 |
| Micro-vaults / maintenance cavities | 24 |
| Testimonies / Records | 32 |
| The Unstandard Tool | 1 global completion item / 12 authored internal stages |
| Drift Knots | 12 |
| Optional Elite Encounters | 8 |
| Community Disconnection Projects | 6 |
| Broken Standard Yard | 1 global completion item / 7 authored internal commissions |

All sixteen top-level completion categories remain equally weighted at **6.25% each**.

## 3.1 Blocklisted legacy literals

Production must not reintroduce:
- 48 Faults;
- 28 Pulse Shards;
- 30 Micro-vaults;
- K02 at 30 Faults;
- Drift Knot unlock at 13 Faults;
- 12 Unstandard Tool stages as 12 global completion items;
- 7 Broken Standard Yard commissions as 7 global completion items.

Current thresholds:
- K01 Field Memory: 6 reconciled Faults;
- K02 Fine Fork: 24 reconciled Faults;
- Drift Knot family eligibility: 10 reconciled Faults + existing story/Skiff prerequisites.

---

# 4. Regional allocation reconciliation warning — ACTIVE CONTENT AUTHORING DEPENDENCY

The current global totals are locked.

However, older `docs/11` regional allocation tables still describe the superseded 48-Fault / 28-Shard / 30-vault plan. No newer authority currently enumerates, item by item, which legacy Fault/Shard/Vault semantic IDs were retained, merged, moved or retired to reach the current 36 / 18 / 24 totals.

Therefore:

> **Do not derive current per-region Fault, Pulse Shard or Micro-vault counts by proportionally trimming old tables or by copying the stale regional allocation.**

Before full regional content scheduling or a machine-readable production registry is frozen, content design must reconcile the current item-level roster against `docs/104`.

That reconciliation must record for every affected legacy item:
- retained unchanged;
- renamed/migrated;
- merged;
- moved region/subregion;
- retired/non-bearing;
- replaced by a new current semantic ID.

This is a bounded content-authoring reconciliation task, not permission to alter the locked global totals.

Until that roster exists:
- global workload is quoteable;
- regional qualitative workload is quoteable;
- exact per-region Fault/Shard/Vault line-item totals are **not** authority.

---

# 5. Production-unit model

Each region is scheduled through the following production units.

## W0 — ordinary-life baseline

Must establish why the place matters before disaster.

Includes:
- work;
- food/service;
- travel;
- civic machinery;
- ordinary disputes;
- named recurring people;
- environmental sound and motion;
- player-readable landmarks.

## W1 — critical-path regional problem

The main regional story/dungeon/encounter burden.

Includes:
- access problem;
- core dungeon or pressure complex;
- tool/procedure acquisition where applicable;
- boss/major pressure;
- evidence/reveal;
- local aftermath.

## W2 — optional authored content

Includes current applicable families:
- Repair Contracts;
- Setup/Payoff;
- Refuges;
- Faults;
- Shards;
- Patterns;
- upgrades;
- trials;
- vaults;
- records;
- elites;
- prestige/mastery content.

## W3 — revisit / verb-gated reopening

Old places must support new understanding through accumulated tools rather than isolated new-map content.

## W4 — Grand Ring / Stillness / Hush change

Specific authored change package.

Must express what this place loses, preserves, repeats, contradicts or can still do.

## W5 — Unringing / community action

Local systems begin functioning without waiting for Neris to solve everything personally.

## W6 — credits / consequence state

Final visible accounting of people, work and institutional practice.

## W7 — cross-region infrastructure

Waybells, route systems, Skiff corridors, courier networks, records, completion reporting and other dependencies that span places.

---

# 6. Cross-discipline readiness packet required per region

A region cannot be considered production-handoff complete merely because environment art has a kit.

Each region packet eventually needs:

1. canonical regional story source;
2. current `Mxx-Sxx` scene burden from `docs/183`;
3. environment/prop kit from `docs/160`;
4. named character + population burden from `docs/158`/`160`;
5. enemy/boss burden from `docs/159` and companion `docs/186`;
6. animation families from `docs/174`;
7. ambience/music/mechanism/audio package from `docs/179`/`180`;
8. UI/map/journal/disclosure obligations from `docs/176`/`177`;
9. Setup/Payoff chains assigned to the region;
10. completion-bearing semantic content assigned to the region;
11. Hush/Stillness pairing class;
12. Line Skiff route relationship where applicable;
13. save/world-state facts and semantic IDs;
14. credits consequence;
15. explicit reusable-versus-unique classification;
16. final open evidence gates.

---

# 7. Brindle / First Circuit / Graymile production package

## Identity

Home, apprenticeship, ordinary repair, agriculture and road-service life.

Brindle must be emotionally worth returning to.

## W0 ordinary-life obligations

Required authored experiences include:
- Vale Workshop work;
- First Ring preparation;
- mill/flood signal maintenance;
- roofs/short traversal routes;
- food/gossip/community activity;
- Tessa sparring and courier presence;
- Dori's road-inn life;
- Graymile worker/service infrastructure;
- Old Viaduct / Common Measure exposure.

Art package: Brindle/Circuit regional kit and hero spaces from `docs/160`.

Narrative burden: Movements 0, 1 and relevant First Circuit entries in Movement 3.

## W1 critical-path burden

Primary production beats:
- First Ring celebration and failure;
- Vale Workshop breach;
- first Hush sight;
- road/flood-relay expansion of stakes;
- Cairnspire departure path;
- Common Measure learning;
- six-baseline First Circuit role;
- later Changed Brindle / Skiff reacquisition.

## W2 current optional/content obligations

Canonical Setup/Payoff allocation:
- `setup.brindle.crooked_fire_bell` — S01 Crooked Fire Bell;
- `setup.circuit.graymile_bypass` — S02 Graymile Bypass;
- `setup.circuit.unregistered_pattern` — S03 Common Measure, story-mandatory.

Additional global families must be represented through current semantic registries/catalogs:
- Repair Contracts;
- Refuges;
- Faults/Shards/Vaults after current roster reconciliation;
- records;
- Unstandard Tool relationships;
- applicable trial/upgrade content.

## W3 revisit burden

Brindle/Circuit must support meaningful return after new verbs, especially:
- access/maintenance spaces that become legible with Anchor/Glasslung/Palinode/Mirror/seam tools as authored;
- changed route-worker spaces;
- Graymile Skiff infrastructure;
- earlier Setup/Payoff consequences.

## W4 Grand Ring / changed-world burden

Must show:
- moving and frozen pockets;
- different shelter/route consequences from early setups;
- local mechanisms continuing where central timing fails;
- ordinary people adapting rather than becoming passive survivors.

## W5 Unringing burden

Brindle begins practical local signaling before Neris finishes all regional work.

Local bells, workshops, courier rendezvous and route relationships become the visible language.

## W6 credits burden

Core credits state:
- Orin still repairing ordinary things;
- Ilyra present but changed;
- practical bells ringing at slightly different times;
- early setup choices visible in rebuilt village life.

## W7 cross-region burden

- Skiff acquisition / first joyful fast road;
- Tessa courier network;
- Graymile route history;
- Drift Knot `Graymile Bellwake`;
- connection into Cairnspire/major trunks.

## Reuse policy

High reuse of ordinary regional kit across opening, changed Brindle and epilogue is required so the player recognizes the same place.

Changed-world impact should come from state, inhabitants, route availability, props and local alterations—not an unrelated rebuilt map.

---

# 8. Cairnspire / Meridian capital production package

## Identity

Vertical civic-service capital built around coordination, public machinery and institutional dependence rather than royal spectacle.

## W0 ordinary-life obligations

Must establish:
- queues and broken civic devices;
- Route House labor;
- public lifts;
- archive work;
- municipal maintenance;
- South Step / food-service life;
- Fourth Landing residents;
- public signal boards and manual corrections.

Narrative burden includes Movements 2 and Grand Ring convergence.

## W1 critical-path burden

- Rusk's attempted Key seizure;
- Maelor's intervention/calibration;
- Public Bell Office diagnosis;
- Twelve Minutes Missing;
- Caldrin archive material;
- Instrument Room commissions;
- return for Grand Ring;
- Meridian district crisis and silent activation.

## W2 optional/content obligations

Cairnspire participates in:
- Repair Contract burden including Route House / Fourth Landing content;
- Refuge/service recurrence;
- records/provenance;
- Fault/Shard/Vault roster after current reconciliation;
- Skiff Outer Loop content;
- later public-disclosure consequences.

No new completion category exists for civic districts, lifts, archive pages or route-map coverage.

## W3 revisit burden

Later states must reopen:
- Fourth Landing;
- restricted/provenance material;
- route/service infrastructure;
- Meridian district relationships;
- Hush-corresponding civic fragments where authored.

## W4 Grand Ring / Hush burden

Grand Ring is a major cross-discipline setpiece:
- civilian movement;
- manual locks;
- Tessa/Caldrin/Sena/Rusk independent action;
- silent Meridian swing;
- regional freeze montage.

Changed Cairnspire becomes fragmented civic islands, not generic apocalypse rubble.

Hush-Cairnspire is related-distinct production, governed by `docs/162`, not a purple duplicate city.

## W5 Unringing burden

Local wards operate through:
- route runners;
- pressure signals;
- chalk boards;
- borrowed regional practices;
- public service diagrams.

## W6 credits burden

- Fourth Landing officially visible but contested;
- Meridian diagrams open to public inspection;
- citizens openly challenge Rusk;
- no final political unanimity.

## W7 cross-region burden

Cairnspire is the old network center but must not remain the only useful travel hub after Unringing.

Skiff Outer Loop / civic ring relationships must preserve hub-approach safety and on-foot social spaces.

---

# 9. Rootmere production package

## Identity

Wet floodplain society where living infrastructure and engineered systems coexist.

## W0 ordinary-life obligations

Before-memory requires:
- Lio Fen's ferry;
- Olo's marker work;
- Amsa/Tavin low-stakes disagreement;
- flexible bell-oak movement;
- orchards/flood halls;
- visible living-material maintenance.

## W1 critical-path burden

- State Stamp / local distrust;
- Root That Isn't Sick diagnosis;
- Root Cathedral;
- Anchor Line reconstruction;
- Mossjaw encounter;
- Mawhart boss/liberation;
- Ilyra warning plate;
- post-repair ferry/community evening.

## W2 optional/content obligations

Setup/Payoff:
- `setup.rootmere.green_span` — S04 Green Span;
- `setup.rootmere.wrens_margin` — S05 Wren's Margin.

Other region work must include its current share of:
- Contracts;
- Refuge content;
- records/testimonies;
- current Fault/Shard/Vault roster after reconciliation;
- upgrades/trials/elites where catalogued;
- one Community Disconnection Project.

## W3 revisit burden

Rootmere is a major accumulated-verb return region:
- Bone Archive access beneath familiar terrain;
- Palinode-dependent record contradictions;
- Mirror/seam-dependent content where authored;
- Skiff route use at regional perimeter/service corridors.

## W4 Stillness/Hush burden

Specific change:
- rigid hardware phase-lock;
- living spans retaining limited oscillation;
- water-pressure mismatch;
- partial moving tissue/structure without corruption shorthand;
- local ferry/message action during movement windows.

## W5 Unringing burden

Community Project: **Living Accord Network**.

Production must show:
- root tension reporting;
- water-height observations;
- ferry signals;
- orchard pressure tones;
- watershed-scale coordination without singular phase authority.

## W6 credits burden

- recovered worker names;
- ferry life;
- imperfect official practices continuing as mundane habits;
- mature Living Accord state scaled to player involvement.

## W7 Skiff/route burden

- regional trunk/service approach;
- wet reinforcement strips;
- living-root crossing relationships;
- Drift Knots `Reedrunner` and `Rootmere Afterimage`;
- no Skiff penetration that erases ferry/social-space value.

---

# 10. Saltreach production package

## Identity

Moving coastline where water condition, fog and pressure relationships matter more than centralized clock time.

## W0 ordinary-life obligations

Before-memory requires:
- working harbor launch;
- captains arguing over berth timing;
- Reedbreak food/social life;
- trustworthy-enough fog signals;
- Tessa's old-route familiarity;
- visible changing coastline.

## W1 critical-path burden

- Familiar Harbor / wrong signal;
- Fog Tower triangulation;
- Tide Foundry;
- Glasslung Reed reconstruction;
- Nine-Lung Leviathan;
- freight manifest / Tessa confession;
- Maelor narrow truth;
- later Leviathan-death report and remembrance.

## W2 optional/content obligations

Setup/Payoff:
- `setup.saltreach.manual_fog_code` — S06 Manual Fog Code, story-mandatory;
- `setup.saltreach.levis_pressure_release` — S07 Levi's Pressure Release.

Other current families:
- Contracts;
- Refuge;
- records/shipping/provenance;
- current Fault/Shard/Vault roster after reconciliation;
- upgrades/trials/elites where catalogued;
- one Community Disconnection Project.

S07 production must preserve its revised primary payoff: local-versus-central operational control, not merely another refuge/moving-pocket variant.

## W3 revisit burden

- pressure-route changes;
- Mirror/Hush bleeding route relationships;
- old manifests/records;
- optional dry-dock/harbor access;
- Skiff coastal-service corridors.

## W4 Stillness/Hush burden

Must distinguish:
- frozen surface water from continuing deep pressure;
- trapped hulls;
- central signal repetition;
- manual code usefulness;
- isolated pressure-motion windows.

## W5 Unringing burden

Community Project: **Many-Tide Harbor Accord**.

Visible production needs:
- condition boards;
- local fog marks;
- manual signal equipment;
- chamber-state indicators;
- competing but coordinated route windows.

## W6 credits burden

- Vessa repainting markers;
- captains still disagreeing;
- Leviathan remembrance integrated into working harbor;
- route state dependent on optional work.

## W7 Skiff burden

- coastal/breakwater service routes;
- pressure/tide dependencies;
- Drift Knots `Breakwater Skip` and `False Harbor Line`;
- network usefulness without converting harbor into a racecourse.

---

# 11. Emberstep production package

## Identity

Industrial highland where heat is useful because it is uneven, stored, redirected, timed and allowed to cool.

## W0 ordinary-life obligations

Before-memory requires:
- shift change;
- successful pour;
- maker stamps;
- ugly-but-functional bracket competition;
- worker rest/service life;
- heat as ordinary labor rather than constant crisis.

## W1 critical-path burden

- Cooling Court accusation;
- Names Ground Flat investigation;
- Kiln of Names;
- Temper Gauntlet;
- Cinder Regent;
- sealed records / three-point geometry;
- urgent copy distribution toward Cairnspire.

## W2 optional/content obligations

Setup/Payoff:
- `setup.emberstep.maker_marks` — S08 Maker Marks, story-mandatory;
- `setup.emberstep.quench_bypass` — S09 Quench Bypass.

Other region burden:
- Contracts;
- Refuge/service content;
- maker/Quiet Court records;
- current Fault/Shard/Vault roster after reconciliation;
- upgrades/trials/elites where catalogued;
- one Community Disconnection Project.

## W3 revisit burden

- quench/heat infrastructure reopened through prior tools;
- Fine Fork signal discrimination;
- Skiff freight routes;
- provenance consequences visible in later manufacture.

## W4 Stillness/Hush burden

Specific state package:
- phase-locked metal with continuing heat;
- moving quench water against frozen hoists;
- pressure behind locked valves;
- small manual kilns recovering first;
- clinic/foundry coordination during movement windows.

## W5 Unringing burden

Community Project: **Open Heat Ledger**.

Must visibly express:
- distributed availability boards;
- maker provenance;
- multiple heat-source lines;
- clinic/production negotiation;
- constraint windows instead of one central schedule.

## W6 credits burden

- apprentices stamp their own names;
- visible mistakes are documented rather than ground away;
- distributed hardware spreads beyond the region.

## W7 Skiff burden

- freight roads;
- thermal switch housings;
- Drift Knots `Ashline Flicker` and `Quench Runner`;
- practical heavy-industry route context.

---

# 12. High Aerie production package

## Identity

Suspended mountain civic settlements where wind, load, archive stewardship and ordinary communal life are inseparable.

## W0 ordinary-life obligations

Before-memory requires:
- cargo lift;
- ordinary wind span;
- apprentices botching rope signals;
- Wind Kitchen meal;
- swaying laundry;
- archive/service tension before catastrophe.

## W1 critical-path burden

- Wind Kitchen Without Wind;
- Weight of the Archive triage;
- Vane Cloak rebuild;
- Choir of Talons;
- Saint Varo state encounter;
- Motion recognition;
- archive seal break and lead to Bone Archive.

## W2 optional/content obligations

Setup/Payoff:
- `setup.highaerie.distributed_copy` — S10 Distributed Copy.

S10 must produce distributed agency/knowledge, not merely “backup survived.”

Other burden:
- Contracts;
- Refuges;
- records/contradictory accounts;
- current Fault/Shard/Vault roster after reconciliation;
- trial/upgrade/elite content where catalogued;
- one Community Disconnection Project.

## W3 revisit burden

- archive material changes standing as Palinode becomes available;
- Vane/Skiff route relationships;
- saved/distributed records alter who can act;
- remembered ordinary spaces must persist through changed state.

## W4 Stillness/Hush burden

The absence of wind is structural.

Required changed-state content:
- frozen spans under wrong loads;
- partially fallen geometry caught mid-state;
- counterweight danger;
- food distribution changes;
- archive rescue priorities;
- moving-air pockets.

## W5 Unringing burden

Community Project: **Open Load Accord**.

Must show:
- local wind stations;
- chain-load reports;
- manual bridge windows;
- open-copy/provenance practice.

## W6 credits burden

- Pera teaching deviation drills;
- Caldrin shelving contradictions together;
- Wind Kitchen reclaiming civic space;
- optional testimony changing displayed material.

## W7 Skiff burden

- descent lines / wind-exposed elevated infrastructure;
- Vane/Crosswind relationships;
- Drift Knot `Downline Crosswind`;
- arrival must preserve on-foot suspended-settlement experience.

---

# 13. Bone Archive production package

Bone Archive is geographically beneath/through Rootmere but is a distinct late production complex.

## Required burden

- familiar Rootmere return route opened by accumulated verbs;
- contradictory archive-space language;
- Archivist Without a Face pressure encounters;
- Palinode acquisition/teaching;
- Mercy Window predecessor evidence;
- Ilyra authorship confession;
- quiet outbound travel beat rather than immediate explanatory debate.

## Reuse / uniqueness

Reuse Rootmere structural ancestry and archive/provenance language where honest.

Create unique late archive states only where contradiction/history requires them.

Bone Archive must not look like a generic underground library disconnected from Rootmere maintenance history.

---

# 14. Mireglass production package

## Identity

Reflective wetland society built around ferries, reeds, paper, interpretation and conflicting accounts.

## W0 ordinary-life obligations

Before-memory requires:
- Neve Or ferry;
- children reflection game;
- Three Tables mundane dispute;
- lanterns/reeds/laughter;
- reflection strangeness that is ordinary before it becomes threatening.

## W1 critical-path burden

- reflection game becoming wrong;
- Palace Under Reeds;
- Palinode-supported contradictory histories;
- Mirror Nail completion;
- Mirror Widow;
- Memory recognition;
- full Mercy Window reconstruction and Ilyra's “Yes.”

## W2 optional/content obligations

Setup/Payoff:
- `setup.mireglass.personal_provenance` — S11 Personal Provenance.

Other burden:
- Contracts;
- Refuge;
- witness-pair records;
- current Fault/Shard/Vault roster after reconciliation;
- upgrades/trials/elites where catalogued;
- one Community Disconnection Project.

## W3 revisit burden

Mirror Nail and seam mode must make old spaces legible differently without turning the region into one giant alternate-map puzzle.

## W4 Stillness/Hush burden

Specific contradiction burden:
- alternate rooms/doors;
- reflected versus physical routes;
- competing document states;
- recognizable people/spaces in incompatible states;
- residents changing behavior around mirrors before Neris arrives.

## W5 Unringing burden

Community Project: **Marked Seams Compact**.

Must present real disagreement:
- close some seams;
- mark some;
- allow controlled access to others;
- preserve provenance/witness records;
- keep ferry routes physically intelligible.

## W6 credits burden

- Neve ferrying past marked seams;
- children cautiously resuming the game;
- Senae/Oren continuing a public disagreement while still signing workable policy.

## W7 Skiff burden

- wetland/reed routes;
- history discrimination;
- Drift Knot `Reedglass Flicker`;
- route presentation may become unreliable, but control grammar remains stable.

---

# 15. Cairnfall production package

## Identity

High dry observatory/survey society where calibration, public measurement and disagreement between instruments are everyday practice.

## W0 ordinary-life obligations

Before-memory requires:
- public observation night;
- flawed teaching scope;
- students betting on which instrument is wrong;
- Long Table food;
- disagreement as ordinary play.

## W1 critical-path burden

- Public Sky Corrected;
- Fallen Orrery;
- reference-frame/correction-loop puzzles;
- Seam Mode collaboration with Ilyra;
- Gravemoon Engine;
- local “No Correction Required” protocol;
- uncorrected observation revealing Orin's repeated signal.

## W2 optional/content obligations

Setup/Payoff:
- `setup.cairnfall.uncorrected_lens` — S12 Uncorrected Lens.

Other burden:
- Contracts;
- Refuge;
- measurement/provenance records;
- current Fault/Shard/Vault roster after reconciliation;
- upgrades/trials/elites where catalogued;
- one Community Disconnection Project.

## W3 revisit burden

- raw versus corrected data changes;
- seam-mode access;
- late Skiff observation windows;
- optional lenses/records affecting interpretability rather than “correct answer glow.”

## W4 Stillness/Hush burden

Required change:
- arrays point to one impossible coordinate;
- clocks agree while physical events diverge;
- corrected maps become dangerously self-consistent;
- route beacons steer toward wrong references;
- crews split over raw versus corrected evidence.

## W5 Unringing burden

Community Project: **Open Baseline Network**.

Must show:
- raw and corrected values together;
- confidence ranges;
- local reference annotations;
- independent audits;
- cross-region reports using compatible formats without identical timing.

## W6 credits burden

- outlier remains visible;
- transparent correction dial;
- flawed training instrument reused as a teaching tool;
- public observation night continues.

## W7 Skiff burden

- observatory/night routes;
- reference-frame windows;
- Drift Knot `Night Arc`;
- regional trunk approach without bypassing public observation identity.

---

# 16. Hush-Cairnspire / Ilyra workbench production package

This is not a full second capital.

Its production burden is relational and selective.

Required content states:
- wrong-but-recognizable Brindle/Cairnspire workbench relation;
- Ilyra survival ritual;
- tool-drawer and breakfast domestic mismatch;
- local Hush teaching/demonstration spaces;
- temporary Brindle re-entry;
- workbench evolution across Motion, Bone Archive, Memory and Cairnfall;
- final shared-present workspace rather than preservation ritual.

Production rule:

> **The workbench changes because Ilyra changes.**

Do not substitute random spooky clutter for that continuity.

---

# 17. Still-Cairn production package

Still-Cairn is a late R4 package built from Cairnspire/Vale correspondences rather than an unrelated final-world biome.

Required content:
- city possibilities that almost existed;
- Echo-bound Orin safe-state encounter;
- useful arena states becoming cages when preserved;
- Perfect Vale Workshop;
- deliberate release of the preserved state;
- Ending relation;
- Orin truth walk/talk;
- family-not-reunion scene.

Its burden is high state complexity and narrative/animation/audio sensitivity, not broad open-world acreage.

---

# 18. Unringing cross-region production package

Movement 15 is not six disconnected chores.

Production must show that communities have already started acting.

The six Community Disconnection Projects are region-owned manifestations of one global transition:
- Rootmere — Living Accord Network;
- Saltreach — Many-Tide Harbor Accord;
- Emberstep — Open Heat Ledger;
- High Aerie — Open Load Accord;
- Mireglass — Marked Seams Compact;
- Cairnfall — Open Baseline Network.

A mandatory authored subset must be sufficient for finale access according to story authority.

All six remain completion-bearing under Completion authority.

Optional completion may improve preparedness, named participation, route/service maturity and credits specificity.

It may not create a hidden “true ending.”

---

# 19. Completion-content production burden by family

## Repair Contracts — 24

Every contract must expose:
- stable semantic ID;
- region/subregion;
- primary NPC/role;
- availability/state prerequisites;
- player activity;
- mechanism/tool dependency;
- world-space asset burden;
- dialogue/journal burden;
- reward/progression dependency;
- durable consequence owner;
- later recurrence/credits effect if any.

No generic fetch quest counts merely because it fills a slot.

## Setup/Payoff — 12

All twelve current chain IDs and regional allocation are locked by `docs/115`.

Each requires:
- setup state;
- commit boundary;
- historical receipt;
- payoff state(s);
- source-owned facts;
- world/prop/dialogue variation;
- reconvergence policy;
- completion settlement;
- save/reload continuity;
- System IDE explanation.

## Refuges — 11

Each refuge requires:
- semantic identity;
- discoverable place/service function;
- named or population owner where authored;
- world-state continuity;
- journal/map/disclosure behavior;
- service/loadout restrictions if any;
- no generic identical safe-room copy.

## Faults — 36

Production count is locked globally.

Exact current per-region roster is pending item-level reconciliation described in section 4.

Each current Fault eventually needs:
- semantic ID;
- region/subregion;
- spatial presentation;
- Cantor/tool relationship;
- discovery tier;
- resolution predicate;
- completion owner;
- accessibility/readability support;
- no old 48-item assumption.

## Pulse Shards — 18

Same regional reconciliation requirement applies.

Each current shard requires:
- semantic ID;
- acquisition source;
- region/subregion;
- world/quest/trial relationship;
- player-progression ownership;
- no four-piece-heart or generic collectible visual assumption.

## Cantor Patterns — 9

Patterns remain capability/procedure content.

Production burden includes:
- learning context;
- journal/reference representation;
- interaction feedback;
- audio pattern language;
- later reuse.

## Tool Mastery Upgrades — 14

Each upgrade requires:
- stable semantic ownership;
- legitimate acquisition source;
- world revisit consequence;
- animation/UI/audio/readability needs;
- no stale threshold assumptions.

## Skill Trials — 9

Each requires:
- authored training purpose;
- region/space relationship;
- clear mastery criterion;
- retry state;
- UI/result presentation;
- no dependence on arbitrary score farming.

Trial 05 is the Line Skiff mastery course and remains believable route infrastructure.

## Micro-vaults — 24

Global count locked.

Current item-level regional roster must be reconciled before exact regional schedule lock.

Each surviving current vault needs:
- one compact authored idea;
- semantic ID;
- tool/verb gate;
- region fiction;
- reward class;
- entry/exit clarity;
- no bespoke-room explosion for a trivial pickup.

## Records/Testimonies — 32

Current set structure and production writing burden are defined in `docs/183`.

World production must provide:
- discoverable physical/source context where appropriate;
- provenance;
- journal representation;
- state/spoiler conditions;
- optional environmental evidence supporting the text.

## Unstandard Tool — 1 / 12 stages

The twelve stages are internal authored production burden.

Only the completed family contributes one top-level completion item.

Stages may reuse regional craftspeople, benches, material routes and existing mechanisms rather than commissioning twelve unrelated hero quests.

## Drift Knots — 12

Network/content integration is consolidated in `docs/186` and docs 120–126.

No thirteenth hidden route-completion category is created.

## Optional Elites — 8

Each elite must be a unique authored encounter resolution fact.

Production should reuse legitimate enemy/region systems where possible while preserving one meaningful encounter idea per elite.

Exact combat values/spawn counts remain later design/runtime work.

## Community Projects — 6

One per major region during Unringing.

Projects must visibly grow from practices the player saw earlier.

## Broken Standard Yard — 1 / 7 commissions

Seven internal commissions are production burden but one global completion item.

It is a mastery complex, not seven extra global categories.

---

# 20. Hush production classification per content unit

Every regional content entry must use one Hush relationship class from current visual/world-layer authority:

## H0 — unchanged semantic object, ordinary presentation only

No Hush production copy required.

## H1 — same semantic object, paired presentation

Waking/Hush expressions correspond to one durable identity.

## H2 — layer-local presentation/state

A durable fact is explicitly layer-scoped by its owning system.

## H3 — related-distinct counterpart

Two authored expressions are related narratively/spatially but are not one shared object state.

## H4 — Hush-only content

Exists only in Hush/Still-Cairn/Null contexts under explicit authority.

Rules:
- Data Layer membership is not semantic identity;
- Actor duplication is not two completion items;
- a recolor does not satisfy paired-state production;
- full duplicate regional kits are prohibited unless actual topology/space changes require them.

---

# 21. State-variant production policy

Before commissioning a unique state variant, classify the change:

1. **fact-only** — data/dialogue/UI change, no new art needed;
2. **prop dressing** — added/removed/rearranged props;
3. **material/presentation** — existing geometry with legitimate surface/lighting change;
4. **structural** — topology/traversal/physical relationship changed;
5. **population/social** — people, work loops, signage, queues, services changed;
6. **Hush relational** — paired or related-distinct spatial expression;
7. **hero unique** — bespoke asset/setpiece justified by story or gameplay.

Prefer the lowest truthful burden.

Do not create duplicate assets merely to make a state feel “different enough.”

---

# 22. Reusable-versus-unique content policy — LOCKED

## Reuse is preferred for

- shared tool interaction grammar;
- common civic hardware ancestry;
- population family foundations;
- generic service props;
- repeated UI/journal patterns;
- common encounter readability;
- route-node architecture;
- System IDE/debug fixtures;
- authored mechanism families whose semantics are genuinely shared.

## Regional reuse is preferred for

- region kit modules;
- local food/work furniture;
- regional signage;
- regional mechanism housings;
- ordinary NPC occupation families;
- environmental ambience layers;
- common route-service objects.

## Bespoke content is justified for

- hero landmarks;
- principal/named character identity where required;
- major bosses/pressure encounters;
- one-off story evidence with high recognition value;
- structurally unique Hush relationships;
- Null Meridian sequence-specific mechanisms/spaces;
- credits consequence shots whose specificity is the point.

## Reject bespoke content when

- an existing family already expresses the same function;
- the only justification is collectible count;
- the asset is visible for seconds but creates a new material/rig/VFX pipeline with no reuse;
- a side quest could use an existing lived place more meaningfully;
- a duplicate dungeon room exists solely to isolate one reward.

---

# 23. Production dependency ordering inside a region

Safe order:

1. confirm semantic story/content IDs and current count authority;
2. identify ordinary-life baseline and hero spaces;
3. define critical path/dungeon relationship;
4. classify reusable kits and named-character burden;
5. attach Setup/Payoff and optional content;
6. attach enemy/encounter families;
7. attach Hush/Stillness state classes;
8. attach Skiff/route relationships;
9. attach narrative/audio/UI/animation obligations;
10. reconcile save/semantic ownership;
11. blockout later only after owner implementation boundary changes;
12. use runtime/human evidence for dimensions, density, pacing and exact tuning.

Do not start by filling a map with collectible markers and then inventing fiction around them.

---

# 24. World-content deliverable taxonomy

## WC-A — authority packet

Documentation complete enough to estimate.

Requires:
- this manifest;
- companion dungeon/network manifest;
- upstream art/narrative/audio/animation/UI packages;
- current semantic catalogs;
- unresolved dependencies explicitly named.

## WC-B — authoring registry

Future pre-implementation content-data package.

Requires machine-checkable current semantic entries for all production content, including the reconciled Fault/Shard/Vault roster.

Not yet created.

## WC-C — graybox/content proof

Future implementation gate.

Requires actual world blockout, route traversal, persistence, Hush transitions and content state proof.

Not authorized.

## WC-D — production-complete region

Future final-production gate.

Requires accepted art, animation, audio, narrative, UI, content, performance, accessibility and save-state evidence.

Not claimed.

---

# 25. Decision rights

## LOCKED

- current global completion totals;
- six major-region Community Project structure;
- twelve Setup/Payoff portfolio and allocation;
- ordinary-life-before-catastrophe doctrine;
- regional identities;
- critical story order and motivations;
- Hush semantic boundaries;
- Skiff network is infrastructure, not a mount/checklist;
- optional completion does not gate the canonical ending;
- reuse-before-bespoke policy where semantics allow;
- no stale 48/28/30 literals.

## STUDIO CHOICE WITHIN BOUNDS

- exact prop reuse inside approved families;
- ordinary encounter dressing;
- module decomposition;
- non-semantic room dressing;
- content-production task breakdown;
- exact authoring asset layout subject to Technical Production Bible;
- ordinary population variation.

## CONTENT-DESIGN RECONCILIATION REQUIRED

- item-level current roster for the 36 Faults, 18 Shards and 24 vaults where legacy regional catalogs still contain superseded extra items.

This reconciliation may choose retain/merge/retire/move within locked global totals and existing world/story constraints.

Material changes to named hero content or story-bearing consequences require higher-authority review.

## RUNTIME-GATED

- exact world dimensions;
- exact walking/Skiff travel times;
- encounter density;
- spawn placement;
- final vault dimensions;
- final route geometry;
- streaming boundaries;
- final collision;
- final NPC density;
- performance budgets;
- Hush technical representation.

---

# 26. Quoteable burden after this manifest

A studio can now quote the project as requiring, at minimum:

- 8 ordinary-world regional production packages: Brindle/Circuit, Cairnspire, Rootmere, Saltreach, Emberstep, High Aerie, Mireglass, Cairnfall;
- 3 major late relational packages: Hush-Cairnspire, Still-Cairn, Null Meridian/Listener;
- region state coverage from ordinary baseline through local repair, Grand Ring/Stillness, changed-world operation, Unringing and credits where applicable;
- 1 complete critical story route represented by the 113 authored scene entries in `docs/183`;
- 24 Repair Contracts;
- 12 Setup/Payoff chains;
- 11 Refuges;
- 36 Faults;
- 18 Shards;
- 9 Patterns;
- 14 upgrades;
- 9 Trials;
- 24 Micro-vaults;
- 32 Records/Testimonies;
- 1 Unstandard Tool family with 12 internal stages;
- 12 Drift Knots;
- 8 Optional Elites;
- 6 Community Disconnection Projects;
- 1 Broken Standard Yard with 7 internal commissions;
- cross-region Line Skiff infrastructure approaching every major region;
- region-specific Hush/Stillness and credits consequences;
- late finale synthesis through Null Meridian.

The studio may not yet quote exact per-region Fault/Shard/Vault line counts until the current item-level roster is reconciled.

---

# 27. Governing world-content rules

1. **Build the place before its disaster.**
2. **Content belongs to semantic systems, not map files.**
3. **A region changes while Neris is elsewhere.**
4. **New verbs reopen remembered places.**
5. **Optional content deepens the world; it does not buy the only valid ending.**
6. **Setup/Payoff consequences must remain causally legible after reconvergence.**
7. **Hush is a relationship to the same world, not a duplicate collectible map.**
8. **The Skiff connects places; it does not erase them.**
9. **Reuse lived spaces before commissioning side-content boxes.**
10. **Current semantic counts outrank stale planning tables.**
11. **Exact runtime density comes from evidence, not spreadsheet aesthetics.**
12. **A production estimate may contain explicit unknowns; it may not contain invented certainty.**
