# 180 — Audio Cue, Asset and Music Production Manifest

**Status:** ACTIVE / STUDIO-HANDOFF PRODUCTION MANIFEST / DOCUMENTATION-ONLY  
**Updated:** 2026-09-06  
**Parent:** `docs/179_STILLRING_AUDIO_MUSIC_VO_BIBLE.md`  
**Program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Cross-authority:** `docs/159_ENEMY_BOSS_ART_MANIFEST.md`, `docs/160_REGION_ENVIRONMENT_PROP_MANIFEST.md`, `docs/176_UI_UX_PRODUCTION_SPECIFICATION.md`, `docs/177_UI_SCREEN_STATE_AND_ASSET_MANIFEST.md`, story scene/region authority  
**Purpose:** make audio/music/voice workload estimateable without inventing final wave counts, VO line counts, final instrumentation, final mix values or runtime architecture.

---

# 1. Manifest rule

This manifest inventories **production families and required semantic coverage**.

It does not pretend a final asset count exists before:
- level blockout;
- exact material/surface registry;
- enemy final archetype allocation;
- Narrative scene/dialogue inventory;
- VO scope decision;
- target-PC/platform audio budgets;
- runtime concurrency/streaming evidence.

The production question is:

> **What must the audio department be prepared to design, compose, record, edit, integrate and validate?**

---

# 2. Naming / ID grammar

Working semantic IDs:

```text
AUD.<FAMILY>.<SCOPE>.<EVENT_OR_STATE>
MUS.<SCOPE>.<CUE_OR_STATE>
VO.<CHARACTER>.<FAMILY>.<CONTEXT>
```

Examples:
- `AUD.RES.CANTOR.LISTEN_CLEAR`
- `AUD.CMB.PLAYER.PERFECT_GUARD_SUCCESS`
- `AUD.AMB.SALTREACH.FOG_COAST_DAY`
- `AUD.SKIFF.ROUTE.ROADHAND_ACCEPT`
- `MUS.ROOTMERE.EXPLORATION_BASE`
- `VO.NERIS.EFFORT.LEDGE_CATCH`

Exact Unreal package naming belongs to the later Technical Production Bible; semantic family naming must remain recognizable.

---

# 3. Deliverable classes

## A0 — critical gameplay audio

Examples:
- committed threat reinforcement;
- Guard / Perfect Guard result;
- Cantor diagnostic result;
- critical mechanism transition;
- Skiff route-state warning;
- save success/failure UI feedback.

Requirements:
- source owner identified;
- non-audio redundancy identified;
- mix priority defined;
- stress-tested under music/ambience/dialogue.

## A1 — high-identity systemic audio

Examples:
- Cantor;
- Waybells;
- Meridian;
- Line Skiff;
- Hush seam;
- core player combat palette.

Requires unique sonic concept work and reuse rules.

## A2 — region identity audio

Examples:
- ambience;
- civic machinery;
- local wildlife;
- region material/work families;
- regional score identity.

## A3 — encounter / hero content

Examples:
- boss package;
- hero mechanism;
- major story scene;
- finale sequence.

## A4 — reusable support

Examples:
- common doors;
- basic cloth;
- ordinary footsteps where materials are shared;
- generic-but-authored UI primitives.

A4 may be shared only where regional identity is not erased.

---

# 4. Neris body / locomotion package

Minimum production families:

## `AUD.PLAYER.MOVE.GROUND`

- careful low-speed step;
- ordinary walk/run;
- Sprint intensity;
- acceleration/start weight;
- deceleration/stop;
- planted reversal/pivot;
- turn/contact accents where needed;
- clothing/tool-carry layers.

Surface variation is material-driven and final surface count is Technical/Environment dependent.

## `AUD.PLAYER.MOVE.AIR`

- jump takeoff;
- airborne clothing/body movement only where audible;
- routine landing;
- upper-safe firm landing;
- damaging landing severity families;
- extreme/fatal impact handoff.

## `AUD.PLAYER.TRAVERSAL.LEDGE`

- catch hand/contact;
- hang body/cloth settling;
- shimmy hand/foot contact;
- pull-up strain/contact;
- deliberate release;
- failed/blocked pull-up where useful.

## `AUD.PLAYER.TRAVERSAL.LADDER`

- mount;
- climb hand/foot cycles;
- hold/settle;
- top/bottom dismount;
- deliberate drop.

## `AUD.PLAYER.TRAVERSAL.MANTLE`

- low fluent mantle;
- higher deliberate mantle/scramble;
- hand/body/contact variations.

## `AUD.PLAYER.TRAVERSAL.SLOPE`

- uphill scramble;
- slide material contact;
- slide exit.

## `AUD.PLAYER.SWIM`

- water entry by severity;
- surface strokes;
- tread/idle;
- turn/surge;
- low-edge exit;
- blocked/high-edge attempt only if gameplay actually presents one.

## Vocal effort dependency

Potential Neris efforts are tracked separately under `VO.NERIS.EFFORT.*` and do not replace body/contact sound.

---

# 5. Player combat package

## `AUD.CMB.PLAYER.ACTION`

- Light family entries 1–3: motion/weapon/body layers according to final combat equipment;
- Heavy action: startup commitment, active force, miss/recovery;
- attack impact material families;
- blocked/deflected contact where source combat state supports it;
- no universal magical weapon trail sound unless an actual system owns one.

## `AUD.CMB.PLAYER.GUARD`

- Guard enter/ready where useful;
- ordinary successful Guard impact;
- Guard Reaction consequence;
- Guard release/return only if audibly useful.

## `AUD.CMB.PLAYER.PERFECT_GUARD`

- success signature;
- opponent/contact layer remains physically grounded;
- optional short temporal accent must leave follow-up readable.

## `AUD.CMB.PLAYER.EVADE`

- body/foot displacement;
- near-threat passage reinforcement where physically appropriate;
- collision/stop case;
- no “invulnerability shimmer” required.

## `AUD.CMB.PLAYER.REACT`

- damage-only feedback;
- light reaction;
- interrupt;
- hard stagger;
- death entry;
- retry/reset audio belongs UI/world restoration, not a death explosion cue.

## Off-screen threat family

`AUD.CMB.THREAT.OFFSCREEN_COMMITTED`

Only allowed for attacks already meeting `docs/55` semantics.

May include directional attack-source/projectile/vocal reinforcement; never a generic enemy-presence ping.

---

# 6. Cantor / resonance package

## Cantor core

IDs must cover:
- `LISTEN_BEGIN`;
- `LISTEN_CLEAR`;
- `LISTEN_AMBIGUOUS`;
- `LISTEN_NOT_ACTIONABLE`;
- `LISTEN_NONE`;
- `LISTEN_BLOCKED`;
- `FOCUS_ACQUIRE`;
- `FOCUS_LOST`;
- `PROCEDURE_ACCEPT`;
- `PROCEDURE_REJECT`;
- `REMEASURE_CHANGED`;
- pattern/procedure-specific treatment where semantic distinction requires it.

Do not build nine entirely unrelated magical spell sounds for nine Cantor Patterns. Shared instrument ancestry must remain audible.

## Resonance infrastructure

Production families:
- ordinary local bell;
- regional Waybell families;
- Meridian reference family;
- Bellwarden diagnostic/inspection hardware;
- Resonance Fault;
- Common Measure;
- Palinode;
- seam/resonance relationship support;
- route/Roadhand relationship.

Each region’s Waybell package should identify:
- physical strike/activation source;
- body material;
- environmental coupling;
- local civic function;
- Waking/Post-Stillness/Hush needs.

---

# 7. Anchor Line package

Required semantic events:
- candidate acknowledgement only where UI/world needs audio;
- latch success;
- latch reject;
- line deploy;
- slack movement;
- tension rise;
- stable load;
- over/invalid load state only if gameplay exposes one;
- obstruction/no-force state;
- movement of a legal load;
- constrained track movement;
- detachable component release;
- static brace establish/release;
- traversal pull engage/travel/arrival;
- reclaim;
- hit/interruption cleanup;
- Hush/state variant only where the same semantic load differs audibly.

Cable/rope sound must not become authority for tension/load truth.

---

# 8. Later tool-family placeholder contract

Glasslung Reed, Temper Gauntlet, Vane Cloak and Mirror Nail require dedicated packages when their production manifests are fully enumerated.

Each package must identify:
- ready/activate;
- valid target/relationship;
- working/held state;
- state change;
- reject/failure;
- release/cancel;
- traversal/combat/puzzle-specific use;
- Hush relationship;
- accessibility redundancy.

Do not reuse Cantor sparkle or one generic “tool magic” source across all tools.

---

# 9. Line Skiff package

Core IDs/families:
- `AUD.SKIFF.BODY.IDLE`;
- `WAKE`;
- `COUPLE`;
- `ACCELERATE`;
- `CRUISE`;
- `COAST`;
- `BRAKE`;
- `HARD_BRAKE` only if handling supports it;
- `LATERAL_LOAD`;
- `ROUTE_CONTACT`;
- `JUNCTION_APPROACH` when world readability needs reinforcement;
- `BRANCH_COMMIT`;
- `ROADHAND_COMPATIBLE`;
- `ROADHAND_ACCEPT`;
- `ROADHAND_REJECT`;
- `ROUTE_DORMANT_STOP`;
- `PARK`;
- `LEAVE`;
- `SWITCHSHOE_TRANSFER`;
- collision/contact families if gameplay retains them;
- `HUSH_ROUTE_TRANSITION` only on declared paired route continuation.

## Trial 05

Additional production needs:
- relay flag pickup/carry/delivery physical state;
- mechanical viability window communication with visual redundancy;
- trial start/reset/qualify;
- no bronze/silver/gold score stingers;
- no leaderboard fanfare.

---

# 10. Shared world/mechanism library

Reusable physical families are expected for:
- doors/gates/latches;
- rope/chain/tension;
- wood structures;
- cast/forged metal;
- ceramic/insulation;
- stone contact;
- water flow/pressure;
- steam/heat/venting;
- wind cloth/vanes;
- lifts/counterweights;
- carts/freight;
- hand tools/workbench activity;
- paper/books/records;
- glass/lenses/instrument mechanisms;
- domestic cookware/furniture;
- route boards/signals.

Reuse must preserve foreground regional specificity.

---

# 11. Region ambience production template

Every ordinary major region requires, where environmentally applicable:

1. exterior day bed;
2. exterior night bed;
3. weather variants;
4. exposed/interior transition behavior;
5. quiet/sheltered variant;
6. settlement social/work bed;
7. region machinery/civic bed;
8. wildlife/insect/fauna detail family;
9. hero-location packages;
10. dungeon/interior package;
11. Post-Stillness changed package;
12. Unringing/recovery package where materially different;
13. Hush relationship package for authored Hush content;
14. one or more intentional-silence profiles.

These are **families**, not a demand for fourteen looping WAVs per region.

---

# 12. Brindle / First Circuit audio manifest

Required families:
- hill/orchard/field ambience;
- flood/irrigation channel water;
- mill/tailbox mechanisms;
- Vale Workshop tools/bench/household;
- carpenter shed;
- Road Inn interior/social/kitchen;
- Relay Square / local Waybell;
- road/courier arrivals;
- Graymile/viaduct route infrastructure;
- frost/flood chimes;
- manual pump/flywheel;
- changed-world moving-pocket package;
- Common Measure sequence;
- Line Skiff acquisition/first joy stretch;
- Still-Cairn/Vale-memory transformed material later.

Music packages:
- `MUS.BRINDLE.ORDINARY`;
- `MUS.BRINDLE.TRAVEL_FIRST_CIRCUIT`;
- `MUS.BRINDLE.CHANGED`;
- `MUS.BRINDLE.SKIFF_RETURN`;
- `MUS.BRINDLE.MEMORY_REPRISE` as required by later story scene inventory.

---

# 13. Cairnspire audio manifest

Required families:
- vertical city exterior;
- pressure-lift families;
- freight bridges/route traffic;
- Public Bell Office;
- Route House;
- Lower Archive;
- Fourth Landing Commons;
- Instrument Ward;
- service alleys/maintenance;
- South Step food/washery/work life;
- Meridian Service Ring;
- central Meridian distant/local states;
- Grand Ring crisis;
- changed-city isolated civic islands;
- manual local clock/coordination systems;
- Hush-Cairnspire transformed package.

Music packages:
- `MUS.CAIRNSPIRE.ARRIVAL`;
- `MUS.CAIRNSPIRE.CIVIC_BASE`;
- `MUS.CAIRNSPIRE.MERIDIAN_PRESENCE`;
- `MUS.CAIRNSPIRE.GRAND_RING`;
- `MUS.CAIRNSPIRE.CHANGED`;
- `MUS.CAIRNSPIRE.UNRINGING`;
- `MUS.CAIRNSPIRE.HUSH`.

---

# 14. Rootmere audio manifest

Required families:
- wet woodland day/night;
- floodplain/water-level states;
- bell-oak/living-root structure;
- ferry/landing;
- orchard;
- flood hall;
- Reed-Screw House;
- flexible joint/resin/root maintenance;
- Root Cathedral;
- ordinary fauna;
- Mossjaw;
- Mawhart;
- hardware-vs-living-state contrast;
- Post-Stillness rigid/living divergence;
- Hush Rootmere relationships where authored.

Music packages:
- `MUS.ROOTMERE.ARRIVAL`;
- `MUS.ROOTMERE.EXPLORATION`;
- `MUS.ROOTMERE.SETTLEMENT`;
- `MUS.ROOTMERE.DUNGEON`;
- `MUS.ROOTMERE.MOSSJAW` if encounter warrants bespoke material;
- `MUS.ROOTMERE.MAWHART`;
- `MUS.ROOTMERE.RESOLUTION`;
- `MUS.ROOTMERE.CHANGED_HUSH` as state requires.

---

# 15. Saltreach audio manifest

Required families:
- coast/tide states;
- fog/wind;
- harbor/dock/mooring;
- vessel/hull work;
- Lowwater Market;
- Dry Dock Three;
- fog tower;
- pressure machinery;
- Tide Foundry;
- Memorial Jetty;
- Split Mast social/service space where canon uses it;
- navigation bell/signal system;
- Nine-Lung Leviathan body/respiration;
- Leviathan chamber infrastructure;
- changed frozen-surface/deep-pressure package;
- Hush variants where authored.

Music packages:
- `MUS.SALTREACH.ARRIVAL`;
- `MUS.SALTREACH.COAST`;
- `MUS.SALTREACH.FOG`;
- `MUS.SALTREACH.FOUNDRY`;
- `MUS.SALTREACH.LEVIATHAN`;
- `MUS.SALTREACH.AFTERMATH`;
- `MUS.SALTREACH.CHANGED`.

---

# 16. Emberstep audio manifest

Required families:
- dry/geothermal exterior;
- vents;
- ash/wind;
- foundry work;
- kiln;
- ceramic handling;
- mold/casting;
- quench/steam;
- heavy haul;
- Cooling Yard;
- Clinic Row;
- Maker Wall / provenance handling;
- Kiln of Names;
- Cinder Regent operation/attack/shutdown;
- changed heat-vs-locked-hardware states;
- Hush treatment where authored.

Music packages:
- `MUS.EMBERSTEP.ARRIVAL`;
- `MUS.EMBERSTEP.WORK_RHYTHM`;
- `MUS.EMBERSTEP.DUNGEON`;
- `MUS.EMBERSTEP.CINDER_REGENT`;
- `MUS.EMBERSTEP.GRAND_RING_LEADIN` as scene authority requires;
- `MUS.EMBERSTEP.CHANGED`;
- `MUS.EMBERSTEP.UNRINGING`.

---

# 17. High Aerie audio manifest

Required families:
- exposed wind classes;
- sheltered/interior wind;
- rope/chain spans;
- cargo/rope lifts;
- bridge/load vibration;
- Wind Kitchen;
- archive halls;
- monastery/service spaces;
- storm shelter;
- weather observation;
- cliff fauna;
- Choir of Talons;
- Saint Varo official-memory/human-contradiction states;
- wind-stopped Grand Ring package;
- Unringing load-report/local-weather system;
- Hush variant.

Music packages:
- `MUS.HIGH_AERIE.ARRIVAL`;
- `MUS.HIGH_AERIE.OPEN_AIR`;
- `MUS.HIGH_AERIE.WIND_KITCHEN`;
- `MUS.HIGH_AERIE.ARCHIVE`;
- `MUS.HIGH_AERIE.CHOIR_TALONS`;
- `MUS.HIGH_AERIE.SAINT_VARO`;
- `MUS.HIGH_AERIE.WIND_STOP`;
- `MUS.HIGH_AERIE.UNRINGING`.

---

# 18. Mireglass audio manifest

Required families:
- marsh day/night;
- reed movement;
- shallow water;
- ferry/pole/dock;
- paper/reed-fiber production;
- interpretation/civic spaces;
- map/copy work;
- Three Tables;
- Reedwater Exchange;
- Palace Under Reeds;
- household state packages where canonical;
- Mirror Widow same-person variant treatment;
- Hush contradictory local sources;
- changed-state ferry/seam signals.

Music packages:
- `MUS.MIREGLASS.ARRIVAL`;
- `MUS.MIREGLASS.MARSH`;
- `MUS.MIREGLASS.INTERPRETATION`;
- `MUS.MIREGLASS.PALACE`;
- `MUS.MIREGLASS.MIRROR_WIDOW`;
- `MUS.MIREGLASS.RESOLUTION`;
- `MUS.MIREGLASS.HUSH`.

---

# 19. Cairnfall audio manifest

Required families:
- dry plateau day/night;
- exposed wind;
- survey marker/instrument;
- observation deck;
- lens/instrument workshop;
- public teaching/observation;
- route beacon;
- Night Survey Hut;
- Fallen Orrery rings/pylons/counterweights;
- Gravemoon local readings;
- Gravemoon central correction;
- corrected-vs-raw data relationship cues where world/UI uses them;
- changed one-reference state;
- Hush variant.

Music packages:
- `MUS.CAIRNFALL.ARRIVAL`;
- `MUS.CAIRNFALL.SURVEY_DAY`;
- `MUS.CAIRNFALL.NIGHT_OBSERVATION`;
- `MUS.CAIRNFALL.ORRERY`;
- `MUS.CAIRNFALL.GRAVEMOON`;
- `MUS.CAIRNFALL.ILYRA_COLLABORATION` where scene authority requires;
- `MUS.CAIRNFALL.UNRINGING`.

---

# 20. Hush / Still-Cairn / Null Meridian audio manifest

Required transformed families:
- Hush-Cairnspire civic fragments;
- Vale workshop preserved-memory variants;
- repeated domestic/work sounds;
- Still-Cairn defensive preserved-state loops;
- Meridian exposed-service machinery;
- Null Meridian worker/local-system layers;
- Common Measure route-opening operation;
- Palinode contradictory-record states;
- Maelor phase-one human/technical package;
- Maelor phase-two central-mechanism package;
- Listener preserved-memory fragments;
- final master-reference removal;
- release/decommission;
- post-release local independent rhythms.

Music packages:
- `MUS.STILL_CAIRN.ENTRY`;
- `MUS.STILL_CAIRN.ORIN`;
- `MUS.STILL_CAIRN.WORKSHOP_MEMORY`;
- `MUS.NULL_MERIDIAN.S1` through `S6` as required by scene-order authority;
- `MUS.NULL_MERIDIAN.MAELOR_1`;
- `MUS.NULL_MERIDIAN.MAELOR_2`;
- `MUS.NULL_MERIDIAN.LISTENER`;
- `MUS.NULL_MERIDIAN.DECOMMISSION`;
- `MUS.ENDING.RELEASE`;
- `MUS.CREDITS` with branch-safe/optional-specificity support.

Exact cue segmentation across S1–S6 is reconciled later against the Narrative scene-production list; this manifest establishes the musical burden now.

---

# 21. Boss / major-pressure asset checklist

Every major package must identify:
- body/mechanism source layers;
- anticipation/telegraph audio where appropriate;
- active force source;
- recovery/settle;
- environmental/arena relationship;
- component states;
- damage/reaction only if combat grammar uses them;
- Hush/state variants;
- resolution state;
- music relationship;
- caption/visual redundancy for critical cues;
- reusable versus bespoke source burden.

Major packages:
1. Mossjaw;
2. Mawhart;
3. Nine-Lung Leviathan;
4. Cinder Regent;
5. Choir of Talons;
6. Saint Varo;
7. Archivist Without a Face;
8. Mirror Widow;
9. Gravemoon Engine;
10. Echo-bound Orin;
11. Maelor;
12. Listener.

Do not estimate them as twelve conventional health-bar monster sound sets.

---

# 22. Ordinary enemy family manifest

Each final ordinary enemy family requires:
- locomotion/body Foley;
- idle/awareness;
- readable telegraph;
- attack family;
- miss/contact;
- reaction;
- defeat/death/resolution according to encounter grammar;
- group/spacing cues where needed;
- region/Hush variant burden;
- off-screen warning interaction;
- accessibility review.

Current production families to plan for include the regional starters in `docs/159`:
- Rootmere burrower/flood-stalker/harnessed variants;
- Saltreach tide crawler/pressure-water predator/dock scavenger family;
- Emberstep ash runner/kiln scavenger/hazard-machine family;
- High Aerie Talons relatives/cliff stalker/wind scavenger;
- Mireglass reed ambusher/shallow-water predator/Hush residue family;
- Cairnfall plateau runner/instrument scavenger/correction-linked machine hazard;
- Hush/Null repeating impressions/residues/composites/service hazards.

Exact retail roster remains region/content production authority.

---

# 23. NPC / ordinary-life audio burden

Every populated region needs ordinary human activity that is not a wall of random chatter.

Required families by context:
- workbench/tool activity;
- food/service;
- freight/carrying;
- repair;
- agriculture/local production;
- civic counter/record work;
- seated/rest/social;
- child/youth activity where present;
- changed-world emergency work;
- Unringing coordination work.

Human vocal content is separated into:
- nonverbal effort;
- authored functional bark;
- ambient conversational line;
- full dialogue scene.

Narrative Production defines exact lines/counts.

Ambient crowds may use nonverbal texture only where that better avoids repetition and localization burden.

---

# 24. Principal voice-performance burden

Regardless of final VO scope, casting/recording estimates must distinguish:

## V0 — Neris

Potential burden:
- narrative dialogue if selected;
- cinematic dialogue if selected;
- effort library;
- damage/death vocalization;
- tool/traversal effort where justified;
- incidental barks approved by Narrative;
- Hush/preserved-scene variants where actual voice state differs.

## V1 — principal recurring

- Tessa;
- Ilyra;
- Orin;
- Maelor.

If VO scope includes narrative performance, these carry major continuity/pickup requirements.

## V2 — major recurring

- Caldrin;
- Sena;
- Rusk.

## V3 — C3/C3+ regional recurring

Exact VO inclusion depends on selected VO model and Narrative scene inventory.

## V4 — ordinary population

No assumption of fully voiced ambient NPC dialogue until scope is selected.

---

# 25. VO decision-estimation matrix

| Production area | VO-A Full | VO-B Selective | VO-C Gameplay vocalization |
|---|---:|---:|---:|
| principal story dialogue recording | high | selected scenes | none |
| C3 dialogue recording | broad | limited/none unless selected | none |
| localized VO | potentially very high | selective | efforts may remain language-neutral where appropriate |
| lip-sync/facial burden | broad | selected scenes | minimal/nonverbal |
| pickup sensitivity to script changes | high | medium | low |
| efforts/damage/traversal | yes | yes | yes |
| subtitles for recorded speech | yes | yes | efforts captions only if meaning-critical |

This matrix is informational. Owner selection remains unresolved.

---

# 26. UI audio manifest

Required semantic families mapped to `docs/176`/`177`:
- title/shell focus/confirm/back;
- playthrough select/new/delete;
- modal open/close;
- disabled/rejected;
- destructive confirm warning;
- pause/tab/category;
- Map/Journal/Tools/Completion navigation;
- record/objective acquisition/update;
- Save start/success/failure;
- recovery/rollback warning;
- controls listening/captured/conflict;
- settings preview/reset;
- subtitle/caption settings preview where useful;
- controller disconnect/reconnect;
- death/retry;
- credits controls.

No audio cue substitutes for visible focus or text.

---

# 27. Caption event registry

Audio Production and UI/Accessibility must share a semantic caption registry.

Each candidate event should declare:
- event ID;
- plain-language caption;
- whether source/speaker/direction matters;
- importance class;
- whether a visual cue already carries equivalent information;
- repeat suppression behavior;
- localization context.

Critical candidate classes:
- committed off-screen attack;
- critical route warning;
- critical mechanism transition;
- significant offscreen story sound;
- Cantor result only if UI/world redundancy otherwise insufficient;
- dangerous environmental event.

Decorative ambience is excluded unless later accessibility product scope explicitly expands environmental captioning.

---

# 28. Music cue manifest — global story / travel

Minimum score burden includes:

## Opening / home
- ordinary Brindle/Vale life;
- First Ring / opening disruption;
- departure / first travel transition.

## First Circuit
- road/travel material;
- Tessa/courier relationship support;
- Cairnspire first arrival;
- first major Meridian/civic exposure.

## Regional progression
Each major region needs:
- arrival/identity presentation;
- exploration/ordinary state;
- settlement/social support where musically distinct;
- dungeon/major authored-space support;
- boss/major pressure support;
- resolution/return variation;
- changed-world/Hush transformation where appropriate.

## Midpoint / Grand Ring
- pre-event convergence;
- Grand Ring event sequence;
- aftermath silence/score policy;
- changed-world re-entry.

## Line Skiff
- Tessa return/acquisition;
- first joy stretch;
- ordinary Skiff travel layer/cue if final music direction supports it;
- Relay Run trial;
- later mastery/Drift Knot support without racing-score cliché.

## Deep-story arc
- Ilyra reunion;
- Bone Archive;
- Mercy Window/Mireglass truth;
- Cairnfall collaboration;
- Still-Cairn;
- Orin release.

## Finale
- Null Meridian S1–S6;
- Maelor phases;
- Listener;
- decommission;
- ending/epilogue;
- credits.

Exact scene cue cuts are finalized by Narrative Production, but the musical production burden is established here.

---

# 29. Music cue state metadata

Every production cue must eventually declare:
- `CueId`;
- `Narrative/Region Scope`;
- `EntrySemanticCondition`;
- `ExitSemanticCondition`;
- `LoopPolicy`;
- `TransitionPolicy`;
- `Stems` if any;
- `DialoguePriorityBehavior`;
- `CombatCompatibility`;
- `HushVariantRelationship`;
- `PostStillnessRelationship`;
- `ReentryBehavior`;
- `Credits/BranchSpecificity` where relevant;
- `SourceSession/ComposerProvenance`.

This metadata belongs in reviewable source data or an equivalent transparent pipeline later.

---

# 30. Music hard failures

Reject score design that:
- runs at full emotional intensity through ordinary exploration;
- uses one generic orchestral palette for all regions;
- treats every Hush cue as minor-key/detuned Waking music;
- gives Maelor obvious villain music from first appearance;
- turns every boss resolution into triumph;
- makes Listener a giant choir deity;
- replaces region identity with cinematic prestige in Null Meridian;
- copies recognizable Zelda melodic/harmonic/earcon structure;
- uses music as the only threat/objective timer.

---

# 31. Sound-source provenance / rights manifest

Every source package eventually records:
- source ID;
- creator/recordist/composer/performer;
- recording/session date;
- original file/session location;
- license/contract status;
- third-party library and license if applicable;
- edits/processes;
- derived assets;
- attribution requirement if any;
- AI/synthetic-generation status if applicable;
- approval state.

Unclear rights = not production-ready.

---

# 32. Audio deliverable review sheet

Every A0–A3 package should answer:

1. What semantic state does this audio present?
2. Who owns that state?
3. Is the sound critical, reinforcing or decorative?
4. What non-audio redundancy exists if critical?
5. Is this source reusable? Where?
6. What region/state variants exist?
7. What mix priority is required?
8. What Hush behavior applies?
9. What accessibility/caption obligation applies?
10. What user volume category owns it?
11. What runtime evidence remains?
12. What source-rights/provenance exists?

A package that cannot answer these questions is not ready to integrate.

---

# 33. Quoteable burden summary

The current repository now tells an external audio team to plan for, at minimum:

- 8 ordinary major-region ambience identities plus Brindle/First Circuit and Cairnspire hub-specific packages;
- late Hush-Cairnspire / Still-Cairn / Null Meridian transformed-memory package;
- region-specific Waybell/resonance adaptations;
- one global Cantor diagnostic grammar with pattern/procedure extension;
- Anchor and later tool families;
- complete Neris locomotion/traversal/combat Foley/action package;
- Line Skiff network-vehicle package;
- ordinary enemy families across all regions;
- 12 major boss/pressure audio packages;
- shared civic/world-mechanism libraries;
- complete UI semantic audio family;
- adaptive regional/story score with opening, regional, midpoint, changed-world, Skiff, deep-story, finale and credits burden;
- principal human effort/performance packages;
- narrative VO recording burden selected later by explicit owner VO-scope decision;
- caption event registry and accessibility mix routing;
- source-provenance/rights tracking.

This is enough to estimate discipline categories and production dependencies without pretending final wave/line/minute counts are known.

---

# 34. Decision rights

## LOCKED

- package families and semantic coverage in this manifest;
- all A0 critical audio requires source ownership + redundancy;
- region packages include ordinary pre-crisis sound;
- Hush packages transform known relationships rather than applying universal processing;
- all 12 major encounters require grammar-specific audio/resolution support;
- Line Skiff package is network/route machinery, not racing-car audio;
- UI Saved/failed/recovery sounds follow real Save state;
- music production includes region identity, midpoint/change, finale and credits burden;
- source rights/provenance are mandatory.

## STUDIO CHOICE WITHIN BOUNDS

- exact number of source takes/variants;
- exact recording libraries;
- exact stem decomposition;
- exact ambience placement architecture;
- exact source reuse;
- exact session layout;
- exact music instrumentation.

## RUNTIME-GATED

- final concurrency/voice limits;
- compression/streaming;
- final spatialization;
- exact material-surface implementation count;
- final ambience density;
- mix levels;
- dynamic transition values;
- CPU/memory/DSP budgets.

## TBD OWNER / UPSTREAM DEPENDENCY

- VO scope;
- ship-language list / localized VO strategy;
- target platforms beyond PC-first;
- exact cinematic/dialogue line inventory from Narrative Production.

---

# 35. Manifest closure statement

At written-handoff level this manifest now supplies:
- audio-family taxonomy;
- regional production packages;
- Neris/traversal/combat/tool/Skiff coverage;
- ordinary enemy and boss coverage;
- UI audio coverage;
- caption registry requirements;
- principal voice-performance classes;
- VO-scope budget consequences;
- music cue burden and adaptive metadata;
- source-rights/provenance requirements;
- quoteable scope without fake final asset counts.

It does not claim audio assets exist.

It does not select VO scope.

It does not claim final music, voice casting, mix, UE5 implementation or runtime proof.