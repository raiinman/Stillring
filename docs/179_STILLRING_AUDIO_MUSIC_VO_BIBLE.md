# 179 — Stillring Audio / Music / VO Bible

**Status:** ACTIVE / STUDIO-HANDOFF PRODUCTION AUTHORITY / DOCUMENTATION-ONLY  
**Updated:** 2026-09-06  
**Parent program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Decision rights:** `docs/170_STUDIO_DECISION_RIGHTS_MATRIX.md`  
**Product boundary:** `docs/171_PERFORMANCE_PLATFORM_PRODUCT_BRIEF.md`  
**Core design authority:** `docs/00_PROJECT_CHARTER.md`, `docs/01_GAME_VISION.md`, `docs/48_GATE2_COMBAT_STATE_MODEL.md`, `docs/54_GATE2_ENEMY_TELEGRAPH_READABILITY_ADDENDUM.md`, `docs/55_GATE2_OFFSCREEN_OCCLUDED_THREAT_ADDENDUM.md`, `docs/69_GATE3_TOOL_SYSTEM_CUMULATIVE.md`, `docs/76_GATE4_HUSH_PRESENTATION_AUDIO_ACCESSIBILITY_ADDENDUM.md`, `docs/79_GATE4_HUSH_CUMULATIVE_SPECIFICATION.md`, `docs/123_TRAVERSAL_TRANSFORMATION_DECISION_4_ACQUISITION_MASTERY.md`  
**Narrative / performance authority:** `docs/02_STORY_BIBLE.md`, `docs/story/06_CHARACTER_ARCS_AND_RELATIONSHIPS.md`, `docs/story/07_SCENE_BEAT_LEDGER.md`, `docs/story/13_EMOTIONAL_PACING_MAP.md`  
**Art / region authority:** `docs/154_STILLRING_ART_BIBLE.md`, `docs/159_ENEMY_BOSS_ART_MANIFEST.md`, `docs/160_REGION_ENVIRONMENT_PROP_MANIFEST.md`, `docs/161_REGIONAL_COLOR_MATERIAL_LIGHTING_SCRIPTS.md`, `docs/162_HUSH_VISUAL_PRODUCTION_MATRIX.md`, `docs/163_VFX_PRODUCTION_MANIFEST.md`  
**UI / captions:** `docs/176_UI_UX_PRODUCTION_SPECIFICATION.md`, `docs/177_UI_SCREEN_STATE_AND_ASSET_MANIFEST.md`  
**Companion manifest:** `docs/180_AUDIO_CUE_ASSET_AND_MUSIC_MANIFEST.md`  
**Closes toward:** `SH-AUD-001` through `SH-AUD-010`  
**Boundary:** this file defines production-facing sonic identity, score grammar, cue hierarchy, recording/performance rules, VO decision boundaries, accessibility requirements and evidence gates. It does not authorize final composition, recording, voice casting, UE5.8 implementation, final mix values, platform mastering, runtime profiling or certification claims.

---

# 1. Purpose

Stillring already says that sound is mechanical and narrative, that bells/resonance matter, that the Hush changes ambience, and that critical information cannot be audio-only.

That is not enough for a studio audio department.

This document answers the production questions an audio director, sound designer, composer, dialogue supervisor and technical sound designer need answered before estimating the game:

- What does ordinary Orra sound like before anything goes wrong?
- What makes one region sonically distinct from another?
- What does a Waybell sound like compared with Meridian, Cantor, a Resonance Fault or a Hush seam?
- When is silence intentional rather than unfinished?
- Which combat cues are allowed to carry urgent information and which are only reinforcement?
- How does music support discovery without wallpapering exploration?
- How does the score transform after Stillness without turning every region into the same mournful remix?
- Which characters/ideas may earn recurring musical material?
- What audio does the Line Skiff need without becoming a racing-game dashboard?
- What is the performance direction for principal characters if dialogue is voiced?
- What remains a genuine owner decision?

The governing principle is:

> **Stillring sounds like a world people use, maintain, misread, preserve, repair and eventually allow to change. Sound must reveal relationships before it decorates them.**

---

# 2. Authority boundary

Audio is primarily a **presentation consumer of authoritative game state**.

Audio may:
- sonify source-owned state;
- reinforce attack, tool, mechanism, route, Hush and save events;
- create regional ambience and score layers;
- provide spatial context;
- use procedural or adaptive systems to make authored state feel continuous;
- expose meaningful authored parameters for tuning;
- support accessibility through separate mix controls and captions.

Audio may not:
- grant attack permission;
- decide Perfect Guard, Evade immunity, hit validity or damage;
- decide Cantor compatibility;
- decide Anchor eligibility;
- decide Hush semantic state;
- decide Line Skiff route legality;
- decide quest progression;
- decide save success;
- invent a puzzle solution because a sound designer wants a stronger cue;
- create a hidden gameplay timer by making a music stem the only warning;
- become a second narrative state machine.

If a sound and gameplay state disagree, the sound is wrong unless the owning system is independently proven wrong.

---

# 3. Sonic identity — what Stillring is and is not

Stillring audio should be:
- tactile;
- spatial;
- mechanically believable;
- region-specific;
- selective rather than constantly busy;
- melodic when music has something to say;
- capable of beauty before catastrophe;
- capable of silence without treating silence as horror shorthand;
- readable under combat pressure;
- restrained enough that a single bell, rope strain, pressure hiss or missing room tone can matter.

Stillring audio should **not** default to:
- generic fantasy choir beds;
- constant mystical chimes;
- every magical/system event sounding like glassy sparkle;
- horror drones whenever the Hush appears;
- cinematic sub-booms on every interaction;
- modern trailer braams;
- UI sounds made entirely from bells;
- every region using the same ambient wind + birds + distant bell recipe;
- copied melodic or timbral signatures from Zelda or another franchise;
- audio-only critical tells.

Clean-room originality applies to melody, interval sequence, rhythm, instrumentation combinations, signature earcons, monster vocals, UI cues and bell motifs as strongly as it applies to visual assets.

---

# 4. Audio priority and mix hierarchy

When sound layers compete, use this production priority:

1. **immediate player survival / committed threat information**;
2. **player action confirmation and defensive contact**;
3. **tool / interaction / mechanism evidence needed to understand current play**;
4. **dialogue or critical authored voice**;
5. **route / traversal state that must be read at speed**;
6. **important story-world events**;
7. **music**;
8. **region ambience / wildlife / population / machinery bed**;
9. **decorative detail**.

This does not mean music is always quiet. It means a dramatic score cue cannot erase the attack tell, Cantor result, dialogue line or route warning the player must actually understand.

The final mix may use ducking, sidechain-like priority behavior, submix routing, modulation, source concurrency, spectral separation or authored orchestration. The implementation method is studio-owned; the hierarchy is not.

---

# 5. UE5.8 implementation technique envelope

Current Unreal Engine 5.8 audio capabilities are valid tools, not automatic project requirements.

## MetaSounds

Valid for:
- procedural mechanical sources;
- layered bell/resonance systems;
- route/vehicle state sonification;
- randomized but bounded ambient detail;
- synthesis where recording alone is inefficient;
- sample-accurate internal sound construction.

MetaSounds are not permission to proceduralize authored music, replace sound direction with random generation, or make gameplay state live inside an audio graph.

## Quartz

Valid candidate for:
- sample-accurate adaptive music transitions;
- bar/beat-synchronized stem changes;
- tightly timed musical state changes where audible discontinuity would be distracting.

Quartz timing does not own story or combat state. Gameplay requests a semantic music transition; the music system schedules an appropriate audible transition.

## Audio Modulation / Submixes / Sound Classes

Valid for:
- state-aware mix snapshots;
- accessibility/user volume controls;
- Hush ambience transformation;
- dialogue and critical-cue priority;
- regional environmental processing;
- dynamic-range management.

## Soundscape

Epic currently documents Soundscape as a Beta feature and recommends caution when shipping.

Therefore:

> **Soundscape is an optional prototype candidate, not the production ambience architecture by default.**

If tested later, it must beat a simpler authored-placement / ambient-manager approach on clarity, source control, debugging, memory/performance and regional authorship.

## General rule

Heavyweight audio plugins/frameworks require the same adoption discipline as gameplay systems:
- identify a real production problem;
- prove the tool solves it;
- preserve source ownership;
- document Shipping dependencies;
- avoid locking the whole project to a Beta/experimental feature without evidence.

---

# 6. Sound family taxonomy

Production organizes sound by semantic family rather than by whichever folder an asset happens to live in.

Core families:

- `AUD.PLAYER` — Neris body, clothing, locomotion, exertion, interactions;
- `AUD.COMBAT` — player/enemy combat, Guard, Perfect Guard, Evade, impacts, threat communication;
- `AUD.TOOL` — Cantor, Anchor and later field-tool audio;
- `AUD.RESONANCE` — bells, Waybells, Meridian, faults, procedures, standards/reference relationships;
- `AUD.WORLD` — machinery, civic systems, doors, lifts, water, heat, pressure, ropes, route systems;
- `AUD.AMB` — regional ambience, weather, wildlife, population, environmental beds/details;
- `AUD.HUSH` — authored alternate-expression audio, residue, absence, seam presentation;
- `AUD.SKIFF` — Line Skiff vehicle/network/route state;
- `AUD.CREATURE` — ordinary fauna and hostile creature vocal/body families;
- `AUD.BOSS` — encounter-specific sound packages beyond reusable family audio;
- `AUD.UI` — menu/HUD/save/error/interface feedback;
- `AUD.MUSIC` — score, stems, stingers, transition material;
- `AUD.VOICE` — spoken dialogue if in scope, efforts, barks, incidental vocalizations;
- `AUD.CIN` — bespoke cinematic sound not safely represented by reusable systems.

Every produced asset/event should be traceable to a family and a semantic use.

---

# 7. Physical-world sound doctrine

The world is full of maintained systems.

Sound design should communicate **how things work**.

Examples:
- a lift should expose pressure, load, latch and mechanical settling rather than one generic elevator loop;
- a flood gate should communicate water load separately from the gate mechanism;
- a kiln should communicate combustion/heat flow, ceramic/material response and moving hardware separately;
- a rope span should communicate load, wind and contact rather than emit random creaks at all times;
- a Waybell should have strike/transmission/resonance/decay relationships appropriate to its physical role.

Wear is audible when it has cause.

Do not add squeaks, rattles, metallic groans or electrical crackle to every old mechanism merely to make it sound antique.

A well-maintained old system may sound clean, solid and predictable.

---

# 8. Bell / resonance sonic grammar

This is one of Stillring’s highest-identity audio systems.

The project must not collapse every resonance state into one pleasant chime.

## 8.1 Ordinary civic / local bells

Purpose:
- warnings;
- route coordination;
- local work signals;
- domestic/civic rhythm.

Sound character:
- physically struck;
- local material and construction visible in the sound;
- imperfect decay and environmental interaction;
- regionally adapted hardware;
- human-scale unless the object is physically large.

They are part of ordinary life before they are mystical symbols.

## 8.2 Waybells

A Waybell is a significant civic mechanism.

Required audible structure:
1. physical excitation / strike or activation mechanism;
2. primary body tone;
3. secondary structural resonance;
4. audible relationship to surrounding machinery/space;
5. region-specific adaptation.

Waybells should share ancestry across Orra without being identical presets.

A Rootmere Waybell may couple to living/wood/water relationships differently from a Saltreach pressure-linked bell or Emberstep industrial casting system.

## 8.3 Meridian

Meridian should sound **too coherent**, not simply louder.

Its sonic idea is centralized reference:
- stable phase relationships;
- unusually controlled decay/alignment;
- repeated correction toward a singular reference;
- broad reach without requiring constant giant-bell spectacle.

As Meridian becomes harmful, the sound does not need to become “evil.”

The disturbing quality comes from other local sounds being pulled toward its relationship, timing or spectral organization.

## 8.4 Cantor Key

Cantor is a diagnostic/mechanical instrument, not a magic wand and not an ocarina substitute.

Its baseline palette should feel:
- close;
- precise;
- small enough to belong in Neris’s hands;
- mechanical;
- repeatable enough to learn;
- capable of representing relationships without becoming melody memorization.

### Cantor result classes

Each semantic result must have a distinguishable multi-channel presentation:

- `Clear / actionable relationship`;
- `Ambiguous`;
- `Not actionable`;
- `None`;
- `Blocked`;
- `Procedure accepted`;
- `Procedure rejected`;
- `Relationship changed / re-measure useful`.

Audio may distinguish these through timing, density, beating, interval width, transient/decay or mechanical response.

Do not rely only on pitch height or major/minor emotional coding.

## 8.5 Resonance Faults

A Fault should sound like a **relationship that does not agree with itself**, not like collectible sparkle.

Candidate design relationships:
- beating;
- drift;
- unstable decay;
- close but unresolved alignment;
- mechanical/structural response around the source.

Exact synthesis/recording approach is studio choice.

## 8.6 Common Measure

Common Measure is temporary compatible coordination without permanent master phase.

Audio rule:

> Several independent sources become mutually workable while retaining audible local identity.

Do not portray success as every sound collapsing into one identical pitch/timbre.

## 8.7 Palinode

Palinode makes incompatible resonance histories legible together.

Audio should support coexistence:
- layered contradictory evidence;
- distinct sources preserved;
- increased intelligibility without declaring one source correct.

It is not a truth-detector “success chord.”

## 8.8 Roadhand Pulse

Roadhand Pulse is infrastructure communication.

Its sound must distinguish:
- compatible route recognized;
- wake request accepted;
- route already active;
- route unavailable / blocked;
- successful moving use.

It must not sound like boost, nitro, weapon fire or generic magic cast.

---

# 9. Silence policy

Silence is a real production tool.

Stillring may intentionally remove or reduce:
- machinery bed;
- population noise;
- wind motion;
- music;
- expected decay;
- local animal/insect presence;
- repeating civic signals.

Silence is useful when the player knows what should have been there.

Therefore pre-crisis ordinary sound is mandatory production work.

## Hard rules

Silence may not:
- remove a critical attack cue without replacement;
- make required dialogue unintelligible;
- become a universal Hush effect;
- be filled automatically with low horror drone because a mix feels “empty.”

A quiet room can remain genuinely quiet.

---

# 10. Waking / Hush audio relationship

Existing Hush authority controls this section.

The Hush is the same semantic place expressed differently.

Sound design should ask:

> What familiar acoustic relationship is present, absent, repeated, incomplete, contradictory or preserved here?

Valid methods include:
- familiar source missing while its room response remains;
- source present with altered decay because geometry differs;
- local residue reproducing a meaningful action fragment;
- two incompatible historical source states audible together;
- a mechanism sustaining a state that would normally release;
- environmental motion audio disappearing where motion is preserved;
- familiar regional motif/source retaining identity but losing normal continuation.

Avoid the default stack:
- low-pass entire mix;
- add giant reverb;
- pitch everything down;
- reverse samples;
- whisper layer;
- glitch loop.

Those techniques may appear locally if semantically justified. None defines the Hush globally.

## Hush priority

Hush ambience remains below:
- combat tells;
- player action confirmation;
- tool/mechanism evidence;
- dialogue.

Reduced Hush Effects may reduce decorative/residue audio intensity while preserving semantic identification.

---

# 11. Regional ambience identities

Each region must sound worth visiting **before** catastrophe.

## 11.1 Brindle / First Circuit

Core identity:
- hill agriculture;
- workshop-home life;
- flood/irrigation control;
- road/courier movement;
- small mechanical bells/chimes;
- people using tools nearby.

Required ambience families:
- orchard/field wind and insects/birds appropriate to place;
- water channels and mill/tailbox flow;
- workshop handwork and small machinery;
- inn/relay-square social bed;
- courier/road arrivals;
- frost/flood chime behavior;
- night quiet distinct from daytime labor.

After Stillness:
- missing synchronized signals matter;
- handwritten/manual systems produce smaller local cues;
- moving pockets reintroduce ordinary sound unevenly.

Hush:
- domestic/workshop familiarity should be recognizable before distortion is added.

## 11.2 Cairnspire

Core identity:
- vertical civic-service city;
- pressure lifts;
- freight bridges;
- route boards;
- archives;
- public service machinery;
- layered human work rather than royal grandeur.

Required ambience:
- lift pressure cycles;
- freight wheel/rope/bridge contact;
- clerical/public-counter room tone;
- service alleys and repair shops;
- route house dispatch activity;
- food/washery/common-space life;
- distant Meridian/civic reference presence used sparingly.

Post-Stillness:
- frozen lifts and missing synchronized cycles create large acoustic gaps;
- local manual clocks/boards/work teams produce smaller asynchronous islands.

## 11.3 Rootmere

Core identity:
- wet floodplain;
- living root structures;
- ferries;
- bell-oaks;
- flexible joints;
- water/wood/resin maintenance.

Required ambience:
- water levels/current families;
- canopy/rain/wet foliage;
- root/wood load movement where physically appropriate;
- ferry contact, poles/ropes/gates;
- orchard/flood-hall life;
- bell-oak structural resonance distinct from metal civic bells.

Avoid mystical forest choir wallpaper.

Post-Stillness should make rigid hardware and living systems audibly diverge.

## 11.4 Saltreach

Core identity:
- tide;
- wind;
- fog signaling;
- docks/moorings;
- lowwater market;
- pressure machinery;
- working vessels.

Required ambience:
- tide state families;
- surf/harbor water differentiated by location;
- rope, hull, mooring and dock contact;
- fog signal system;
- pressure gate/chamber systems;
- market/shipyard labor;
- exposed-lowwater ambience;
- storm/fog variants.

Avoid pirate tavern cliché as regional shorthand.

Stillness must distinguish frozen surface behavior from continuing deep pressure.

## 11.5 Emberstep

Core identity:
- geothermal heat;
- black-glass terrain;
- foundry/kiln production;
- cooling/quench systems;
- heavy hauling;
- ceramic/metal material work.

Required ambience:
- vent/heat-flow families;
- kiln/furnace cycles;
- ceramic movement/stacking;
- metal casting/handling;
- quench water/steam;
- freight platforms;
- worker rest/shade spaces;
- clinic/sterilizer systems.

Avoid constant roaring fire and permanent industrial noise wall.

Production rhythms should have rests.

## 11.6 High Aerie

Core identity:
- wind;
- suspended load;
- rope/chain spans;
- lifts;
- kitchens/archives/monastery work;
- large vertical space.

Required ambience:
- multiple wind exposure classes;
- rope/chain load behavior;
- suspension bridge vibration/contact;
- cargo lift movement;
- wind-organ/listening structures where canon supports them;
- communal kitchen interior;
- archive/monastery quiet;
- distant cliff fauna.

Pre-crisis wind movement is essential so the Grand Ring absence is emotionally legible.

## 11.7 Mireglass

Core identity:
- shallow water;
- reeds;
- ferries;
- paper/copy work;
- interpretation/mediation spaces;
- reflection and uncertain depth.

Required ambience:
- reed movement at several distances;
- shallow water/ferry pole/contact;
- paper/reed-fiber production;
- covered interior water/roof ambience;
- civic interpretation spaces;
- insects/birds/fauna appropriate to wetland;
- quiet reflective zones.

Hush differences should create contradictory familiar sources, not a generic ghost swamp.

## 11.8 Cairnfall

Core identity:
- high dry plateau;
- survey instruments;
- public observation;
- calibration workshops;
- long sightlines;
- multiple legitimate measurement references.

Required ambience:
- exposed dry wind;
- instrument movement;
- mechanical pointers/rings/locks;
- lens/instrument work;
- public observation activity;
- night survey quiet;
- distant route beacons/mechanical reference cues where appropriate.

Stillness should make synchronized agreement sound suspiciously clean while real physical events diverge.

## 11.9 Hush-Cairnspire / Still-Cairn / Null Meridian

Late-game audio should primarily **transform remembered material**.

Do not invent a detached “final dimension” sonic palette.

Use:
- known family/workshop sounds in impossible repetition;
- civic sounds with missing human causes;
- familiar regional material returning in altered relationships;
- Meridian’s central reference becoming increasingly exposed;
- final decommission allowing independent local rhythms to remain rather than ending in one perfect resolving chord.

---

# 12. Score philosophy

Stillring’s score should support memory, curiosity and change.

The score is not required to run continuously.

Core principles:

1. **Let places earn themes through time spent there.**
2. **Introduce beauty and ordinary warmth before loss.**
3. **Use recurring material to make changed places emotionally legible.**
4. **Do not tell the player what to feel before the scene has earned it.**
5. **Combat music supports pressure without erasing attack audio.**
6. **Hush music should transform relationships, not just minor-key the Waking cue.**
7. **The finale should synthesize known material instead of unveiling a completely unrelated prestige soundtrack.**
8. **Silence is allowed.**

## No franchise imitation

Do not copy:
- recognizable Zelda melodic contours;
- instrument-as-brand shortcuts resembling another franchise’s signature;
- exact dungeon-music layering tricks;
- item-acquisition fanfares;
- boss cadence shapes;
- familiar “lost woods”/fairy/temple harmonic shorthand.

Stillring may learn from the general principle that memorable games use strong thematic recurrence and economical orchestration.

---

# 13. Regional musical identities

The following are **musical behavior and material-family directions**, not final orchestration locks.

Exact instruments, performers, sample libraries, synthesis and ensemble size are `STUDIO CHOICE WITHIN BOUNDS` until budget/production planning.

## Brindle

Character:
- tactile;
- small-scale;
- warm;
- curious;
- practical.

Candidate families:
- plucked/struck acoustic textures;
- hand percussion;
- restrained bowed support;
- small resonant found-object/mechanical color.

Avoid making a flute/ocarina-like lead the identity.

## Cairnspire

Character:
- layered coordination;
- civic motion;
- public scale;
- controlled complexity.

Musical behavior:
- interlocking parts;
- repeating civic pulse structures;
- multiple layers that can separate after Stillness;
- metallic/wooden percussive color used structurally, not as constant bell sparkle.

## Rootmere

Character:
- flexible;
- damp;
- living;
- weight carried through organic structure.

Musical behavior:
- long breathing phrases;
- irregular but coherent pulse;
- resonant wood/low string-like families;
- water/air-informed spacing.

Avoid “mystical forest” clichés.

## Saltreach

Character:
- horizontal travel;
- tide windows;
- fog distance;
- pressure.

Musical behavior:
- broad spacing;
- rise/fall structures;
- breath/reed-like or bowed sustained color as candidates;
- rope/wood/skin-like percussion candidates;
- phrases that imply windows opening/closing rather than sea-shanty cliché.

## Emberstep

Character:
- dry heat;
- production rhythm;
- traceable making;
- uneven useful temperatures.

Musical behavior:
- ceramic/metallic percussion candidates;
- dry articulated rhythmic figures;
- deliberate gaps/cooling spaces;
- layered work patterns that need not align perfectly.

Avoid “fire level = pounding drums.”

## High Aerie

Character:
- vertical openness;
- load and wind;
- suspended relationships;
- human warmth inside exposed space.

Musical behavior:
- sustained air/line textures;
- wide registral separation;
- sparse pulses that imply suspended load;
- intimate indoor variants for kitchens/archive/community spaces.

Avoid angelic choir as default elevation shorthand.

## Mireglass

Character:
- reflection;
- interpretation;
- shallow water;
- contradictory testimony.

Musical behavior:
- paired phrases with altered continuation;
- restrained repetition;
- damped/plucked/soft sustained families;
- mirrored structure without cheap reversed-audio gimmick.

## Cairnfall

Character:
- observation;
- calibration;
- multiple legitimate readings;
- long night attention.

Musical behavior:
- repeating figures at slightly different cycles;
- measured but not sterile pulse;
- layers that can drift and still coexist;
- clear separation between local readings and Meridian correction material.

Avoid generic “space music.”

---

# 14. Leitmotif policy

Leitmotifs are allowed when they create memory rather than announce a label.

## Motif candidates that earn recurring identity

### Neris / repair-in-motion

A compact flexible musical idea associated with curiosity, work and forward action.

It should become quieter/more spacious rather than simply bigger as Neris matures.

### Vale family / workshop memory

A domestic relationship, not a sentimental “family theme” that automatically means safety.

It must survive:
- ordinary Brindle;
- loss;
- Ilyra reunion;
- Orin confrontation;
- Still-Cairn preserved workshop;
- release.

### Meridian / central reference

A strongly coherent relationship that may first sound reassuring/useful.

Later score can reveal the cost of forced agreement without turning it into a villain sting.

### Hush / Listener

Not one spooky melody.

Use incomplete continuation, overlapping alternatives, unresolved return or shared fragments from actual player memories.

### Regional themes

Every major region may earn reusable material that can survive Waking, Stillness, Hush and Unringing transformation.

### Maelor

Maelor should share technical/repair/Meridian vocabulary rather than receive a simplistic villain theme from first appearance.

His final material should reveal continuity with earlier helpful scenes.

## Motif restrictions

Do not assign:
- a jingle to every collectible;
- a melody to every mechanic;
- a character theme to every C3 NPC;
- a special motif solely because a content item is completion-bearing.

---

# 15. Dynamic music state model

Music reacts to **semantic game situations**, not raw Blueprint overlap order.

Useful high-level presentation states:

- `MUS.STATE.SETTLEMENT`;
- `MUS.STATE.EXPLORATION`;
- `MUS.STATE.DUNGEON`;
- `MUS.STATE.COMBAT_STANDARD`;
- `MUS.STATE.COMBAT_MAJOR`;
- `MUS.STATE.BOSS`;
- `MUS.STATE.HUSH`;
- `MUS.STATE.SKIFF_TRAVEL`;
- `MUS.STATE.STORY_FOCUS`;
- `MUS.STATE.POST_STILLNESS`;
- `MUS.STATE.NULL_MERIDIAN`;
- `MUS.STATE.SILENT_INTENTIONAL`.

These are presentation categories, not gameplay states.

## Transition rules

- avoid abrupt restart when a short threat ends;
- use appropriate entry/exit windows;
- allow score to stay absent after a powerful scene;
- do not restart a region theme from bar one every time the player crosses an invisible boundary;
- combat exits should preserve world tone rather than play constant victory fanfare;
- boss resolution follows encounter grammar: liberation, shutdown, coexistence and decommission do not all use the same triumph cadence.

Quartz or equivalent sample-accurate scheduling is allowed if it improves transitions.

---

# 16. Combat audio hierarchy

Combat sound must make force, timing and consequence readable without becoming a rhythm game.

Required audible categories:

## Player action
- Light action family;
- Heavy action family;
- Guard raise/stable/release where useful;
- Evade displacement/contact;
- attack whoosh/contact layers appropriate to actual weapon/body interaction;
- miss/air behavior distinct from impact.

## Defensive contact

### Guard
Ordinary Guard should communicate:
- successful frontal defensive contact;
- material/force relationship;
- consequence/Guard Reaction where applicable.

### Perfect Guard
Perfect Guard must have a clear, compact, high-priority success signature.

It must not:
- resemble item acquisition;
- imply generic enemy stun if none occurred;
- use a giant musical chord that masks follow-up action;
- be distinguishable only by pitch.

### Evade
Evade audio may reinforce movement and close threat passage, but immunity is not owned by an audio cue.

## Incoming threat

Enemy tells use:
- body/weapon/mechanism source;
- movement;
- local vocalization where appropriate;
- world interaction;
- optional supplemental off-screen communication.

Do not play generic danger stingers from enemies that have not actually committed a threat.

## Off-screen threats

`docs/55` remains authority.

Spatial audio may reinforce direction, but muted audio must not make the attack unfair.

The optional UI threat indicator carries the required visual redundancy where needed.

---

# 17. Creature / enemy audio doctrine

Creatures are animals first unless canon says otherwise.

## Ordinary fauna

Audio should communicate:
- size;
- breathing/body effort;
- locomotion surface interaction;
- territorial/predatory intent;
- anatomy.

Avoid demonizing normal animals with processed monster roars.

## Infrastructure-entangled fauna

Separate:
- biological body/vocal distress;
- imposed hardware;
- tension/pressure system.

The tragedy should be audible because two systems are interfering, not because a sad music sting says so.

## Machines

Machine threats sound like real operating functions:
- press;
- valve;
- arm;
- ring;
- thermal cycle;
- counterweight;
- correction spindle.

Avoid robot growls and creature vocal layers on non-sentient machinery.

## Hush entities

Identity comes from relationship:
- missing source;
- repeated material;
- conflicting spatial state;
- partial human/environment memory.

Avoid universal ghost whisper processing.

---

# 18. Major encounter sonic identities

## Mossjaw

- heavy wet quadruped body;
- territorial animal vocalization;
- maintenance harness hardware audible as foreign material;
- no demon roar;
- success should not automatically trigger heroic kill fanfare if encounter grammar does not support it.

## Mawhart

- monumental living body;
- deep load-bearing movement;
- foreign braces/cables clearly separable;
- release emphasizes hardware unloading and freer movement;
- no magical purification sound.

## Nine-Lung Leviathan

- respiratory/pressure openings are a core sonic identity;
- chamber forcing and animal breathing must remain distinguishable;
- no sea-dragon roar;
- liberation can sound physically easier without implying recovery from accumulated harm.

## Cinder Regent

- industrial operations are the attack vocabulary;
- thermal, press, shield and handling-arm states each need distinct machine evidence;
- shutdown settles rather than explodes by default.

## Choir of Talons

- three same-species individuals remain spatially distinguishable;
- wing/body air interaction supports attack direction;
- no magical storm-bird treatment.

## Saint Varo

- official-memory “clean” state may sound overly consistent/rehearsed;
- contradiction adds human/material irregularity rather than corruption noise;
- no undead-knight voice processing.

## Archivist Without a Face

- subtraction/simplification is central;
- room/document sounds may collapse as contradiction is erased;
- entity does not need a horror monster vocalization.

## Mirror Widow

- if voiced, all variants remain recognizably one woman;
- differences come from state/performance/context, not witch/demon layers;
- multiple historical states may overlap without declaring one “true” voice.

## Gravemoon Engine

- local instrument cycles versus central correction are independently audible;
- successful resolution leaves several valid rates continuing;
- “victory” is coordinated disagreement, not total silence.

## Echo-bound Orin

- Orin remains human;
- repeated breaths/gestures/domestic sounds may loop with preserved states;
- no possessed-father voice effect;
- release removes repetition rather than adding spectacle.

## Maelor

- human voice remains intelligible and physically present;
- technical hardware/system sound escalates around him;
- phase two does not transform him into a monster voice;
- final defeat/disconnection reduces scale rather than adding supernatural crescendo.

## Listener

- no permanent monster voice;
- sonic identity assembled from unfinished people/places/possibilities;
- player-memory material may recur where production supports it;
- release separates/ends forced overlap rather than exploding into a final choir.

---

# 19. Traversal and Line Skiff audio

## Neris traversal

Required families include:
- surface-specific footsteps;
- careful walk/run/Sprint intensity without a stamina heartbeat system;
- start/stop/pivot weight;
- jump takeoff/air/land severity;
- mantle contact;
- ledge catch/hang/shimmy/pull-up/release;
- ladder contact;
- swim surface/body/water exit;
- slope scramble/slide;
- fall/wind severity where useful;
- clothing/tool carry secondary contact.

No constant effort vocal on ordinary movement.

## Line Skiff

The Skiff is a network vehicle, not a mount and not a racing car.

Required sonic layers:
- mechanism at rest;
- wake/couple;
- acceleration/load;
- coast;
- braking;
- corridor/route-surface contact;
- lateral load/curve;
- junction/branch infrastructure;
- Roadhand Pulse interaction;
- safe stop at unavailable route;
- Switchshoe transfer;
- damage/collision/contact if gameplay retains such states;
- park/leave;
- Hush route variant where authored.

Do not default to:
- engine-rev racing language;
- boost whoosh;
- turbo charge;
- arcade drift squeal;
- speedometer warning beeps;
- fuel-low alarm.

At speed, route state and physical load matter more than numerical speed.

---

# 20. UI audio family

UI sound should be quiet, tactile and semantically consistent.

Required families:
- focus move;
- confirm;
- back;
- disabled/rejected;
- modal open/close;
- destructive warning;
- acquisition;
- journal/record update;
- save starting;
- save success;
- save failure;
- recovery/rollback notice;
- binding capture/conflict;
- settings preview where audible preview is useful;
- category/tab change;
- death/retry confirmation.

Rules:
- UI does not use bells for everything;
- `Saved` sound plays only after Save authority confirms publication;
- failure sounds do not imply data loss beyond what the save system knows;
- focus audio is supplementary to visible focus;
- Reduced Effects / audio settings may alter intensity without erasing essential text/visual state.

---

# 21. Voice / performance scope — current decision boundary

**VO scope is currently `TBD OWNER`.**

No existing authority settles whether Stillring ships with:
- full spoken dialogue;
- principal/key-scene partial VO;
- efforts/barks plus text dialogue;
- another bounded model.

This is a real product/budget/localization decision and must not be silently selected by the studio.

## Decision gate

VO scope must be selected before:
- final dialogue recording budget;
- actor contract strategy;
- final localization recording plan;
- cinematic facial/lip-sync production lock;
- exact recording schedule;
- final Dialogue volume/category commitments.

It does **not** block:
- sound effects;
- music development;
- ambience;
- human effort/breath prototype needs;
- voice-performance direction;
- pronunciation authority;
- narrative script inventory.

## Scope models for owner review later

### VO-A — Full narrative VO

Voices all authored dialogue intended to be spoken.

Production consequence:
- largest casting/recording/localization/facial burden;
- requires earlier script lock and pickup budget;
- strongest spoken performance continuity.

### VO-B — Principal/key-scene selective VO

Voices principal cinematic/critical scenes plus efforts/barks; ordinary conversation remains text-led.

Production consequence:
- medium recording burden;
- requires explicit scene classification so voiced/unvoiced transitions feel intentional.

### VO-C — Gameplay vocalization only

Human efforts, exertions, damage, short functional barks where needed; narrative dialogue remains text-led.

Production consequence:
- lowest narrative recording burden;
- performance remains driven heavily by animation/text/audio staging.

No option is selected by this document.

---

# 22. Voice performance bible

If a character is voiced under the selected scope, performance follows canonical characterization.

## Neris Vale

- 17 years old;
- direct;
- mechanically minded;
- impatient with ceremony;
- emotionally reactive without becoming quippy;
- can say unfair things;
- grows quieter/more deliberate late game rather than grander.

Avoid:
- adult action-hero register;
- breathy chosen-one reverence;
- constant sarcasm;
- exaggerated teen caricature.

## Tessa Marr

- competent;
- route-oriented;
- humor as defense;
- warmth underneath practical language;
- jokes stop when responsibility requires it.

Avoid endless sarcasm/comic-relief performance.

## Ilyra Vale

- precise;
- intelligent;
- anxious over-explanation;
- sometimes slips into parenting the six-year-old Neris she remembers;
- can lose words/mis-sequence late because return is difficult.

Do not perform her as mystical Hush oracle.

## Orin Vale

- plainspoken;
- domestic/workshop metaphors;
- dislikes abstraction;
- warmth and avoidance can coexist;
- confession should not be performed as self-exoneration.

## Maelor Renn

- controlled;
- exact;
- conclusions rehearsed internally for years;
- early usefulness must sound genuine;
- anger matters because it breaks control;
- grief does not become villain growling.

## Brother Caldrin

- careful distinctions;
- provenance/record language;
- dry humor;
- intellectual without theatrical scholar affectation.

## Sena Ash

- short process/worker language;
- impatient with guilt unsupported by action;
- authority comes from work, not shouting.

## Prefect Aven Rusk

- administrative precision;
- formal control early;
- becomes less institutionally polished as authority fails;
- never cartoon bureaucrat.

## Listener

If the Listener receives spoken output under the selected VO model:
- no demonic voice;
- no singular god-voice assumption;
- may use layered/relational treatment if intelligibility remains intact;
- the canonical question `MUST ALL ENDINGS BE CAGES?` must remain understandable through text/subtitles regardless of processing.

---

# 23. Human vocalization / bark policy

Even without full narrative VO, animation/gameplay may need human vocal performance.

Potential families:
- jump effort;
- mantle/pull strain;
- ledge catch;
- heavy impact/damage;
- severe fall/landing;
- Guard force response;
- Heavy action effort;
- swim strain only where physically justified;
- cold/heat/environment response where actual gameplay state supports it;
- short situational barks where Narrative authority approves them.

Rules:
- no grunt on every attack;
- no constant Sprint breathing soundtrack;
- no repeated bark every time the player enters a region/tool state;
- avoid exact repetition fatigue with bounded variants where needed;
- bark content cannot reveal hidden state or future story;
- incidental combat barks cannot turn Neris into a nonstop commentator.

NPC incidental chatter remains Narrative Production authority for exact writing/counts.

---

# 24. Pronunciation guide — core production vocabulary

This guide establishes a working pronunciation baseline for core recurring terms. Narrative Production may extend it to every named C3/C4 identity.

Simple phonetic notation is intentionally readable by production staff; IPA may be added in the recording package if useful.

| Term | Working pronunciation |
|---|---|
| Stillring | `STILL-ring` |
| Orra | `OR-uh` |
| Neris | `NEH-riss` |
| Vale | `VAYL` |
| Tessa | `TESS-uh` |
| Marr | `MAR` |
| Ilyra | `ih-LEER-uh` |
| Orin | `OR-in` |
| Maelor | `MAY-lor` |
| Renn | `REN` |
| Caldrin | `KAL-drin` |
| Sena | `SEE-nuh` |
| Rusk | `RUSK` |
| Brindle | `BRIN-dull` |
| Cairnspire | `KAIRN-spyre` |
| Rootmere | `ROOT-meer` |
| Saltreach | `SALT-reech` |
| Emberstep | `EM-ber-step` |
| High Aerie | `high AIR-ee` |
| Mireglass | `MYRE-glass` |
| Cairnfall | `KAIRN-fall` |
| Hush | `HUSH` |
| Meridian | `muh-RID-ee-un` |
| Waybell | `WAY-bell` |
| Cantor | `KAN-tor` |
| Palinode | `PAL-ih-node` |
| Line Skiff | `LINE skiff` |
| Null Meridian | `null muh-RID-ee-un` |

If a future cultural-language pass changes a pronunciation materially, update the guide once and propagate it to VO/localization notes. Do not let individual actors invent different pronunciations per session.

---

# 25. Music cue architecture

The companion manifest owns the cue list, but every score cue should declare:
- cue ID;
- region/story context;
- semantic trigger source;
- permitted entry/exit states;
- loop/non-loop form;
- stem/layer requirements;
- Hush/Post-Stillness relationship;
- dialogue-mix behavior;
- combat relationship;
- save/resume expectations if relevant;
- final-form provenance.

Music files do not own story completion.

A cinematic cue finishing does not commit a quest fact unless Narrative/Story authority has separately committed it.

---

# 26. Recording / source-production standards

Exact sample rate/bit depth, middleware/DAW package and mastering deliverable formats are Technical Production choices, but source production must preserve editability and provenance.

For recorded SFX / Foley / VO / music as applicable, retain:
- original high-quality source recordings;
- take/session metadata;
- performer/recordist/source rights;
- edit history or reproducible session where practical;
- semantic asset IDs;
- clean alternates when heavy processing is used;
- loop points / tempo / meter metadata for music systems;
- pronunciation/context notes for VO;
- source language for dialogue;
- license clearance for third-party libraries.

No generated/model-derived voice or music source may enter production merely because it is easy to create. Any synthetic/generative source requires explicit legal/rights/product review and must not compromise performer or IP requirements.

---

# 27. Music production deliverable expectations

Depending on cue role, deliverables may include:
- full mix;
- stems grouped by adaptive function;
- loopable sections;
- transitions/bridges;
- stingers only where semantically justified;
- no-melody / reduced-intensity variant where dialogue/readability needs it;
- Hush/Post-Stillness transformed materials;
- score/source split where a diegetic sound participates musically.

Do not require stems for every cue if the cue never adapts.

Do not compose adaptive complexity before its semantic use is known.

---

# 28. Accessibility / captions / audio settings

Critical information must remain available without hearing.

Current Microsoft accessibility guidance supports:
- subtitles for spoken content;
- captions or visual alternatives for important non-speech cues;
- speaker/source identification when unclear;
- separate volume controls for major audio categories;
- multimodal presentation for important cues.

Stillring requirements:

## Subtitle coverage

All spoken dialogue included in the final VO scope receives subtitles.

Text-led dialogue remains visible by definition.

## Caption candidates

Important non-speech cues that may require caption/visual representation include:
- committed off-screen attack reinforcement where visual world information is insufficient;
- critical mechanism state change;
- important Cantor result if world/UI alone would not communicate it;
- major environmental hazard warning;
- required story sound event occurring offscreen;
- important route/system failure at Skiff speed.

Do not caption every decorative bird, cloth flap or room creak by default.

## Separate audio controls

Prepare independent control for:
- Master;
- Music;
- Gameplay SFX;
- Ambience;
- Dialogue/VO **if VO exists**;
- UI;
- narration if screen narration later ships as a distinct audio channel.

Exact dynamic-range presets require final mix evidence.

## Spatial audio

Spatial presentation may improve orientation but cannot be the sole carrier of required information.

Mono/downmix, limited spatial hearing and muted-audio cases must preserve critical gameplay through other channels.

---

# 29. Mix / loudness / dynamic-range boundary

This document intentionally does not invent final LUFS, true-peak, bus headroom or platform mastering numbers before target platform/hardware and implementation exist.

Production requirements now:
- preserve headroom for high-priority events;
- avoid constant maximal loudness;
- maintain intelligible dialogue where VO exists;
- distinguish ambience from active gameplay SFX in settings/mix routing;
- preserve attack/transient readability during music peaks;
- design Hush silence without users needing to raise volume dangerously;
- prepare dynamic-range accessibility options if final mix testing supports useful modes.

Final mastering values are `RUNTIME / PLATFORM-GATED`.

---

# 30. Audio quality gates

## AUD-A — Written authority

Pass when:
- sonic doctrine exists;
- region ambience identities exist;
- resonance grammar exists;
- score/music identity exists;
- voice/performance direction exists;
- cue/asset manifest exists;
- VO scope is either selected or explicitly owner-gated.

## AUD-B — Source / concept prototypes

Future production gate.

Requires representative concept work for:
- Cantor/Waybell/Meridian grammar;
- one normal region ambience;
- one Hush relationship;
- one combat set;
- one Skiff route set;
- one region music identity;
- one boss identity.

No gameplay implementation claim required, but final approval still waits for runtime context.

## AUD-C — Runtime integration

Future gate.

Requires:
- authoritative state driving audio;
- mix hierarchy under real gameplay;
- spatial/occlusion behavior;
- adaptive music transitions;
- settings routing;
- caption redundancy;
- Hush reduced-effects behavior;
- performance evidence.

## AUD-D — Human mix/readability acceptance

Requires representative play with:
- music high/low/off;
- ambience high/low/off;
- mono/downmix cases;
- controller/headphones/speakers appropriate to target PC testing;
- subtitles/captions;
- Hush/combat/dialogue overlap;
- ordinary quiet exploration.

## AUD-E — Shipping/mastering

Requires target platform/product scope, final output modes, performance and platform-specific acceptance.

---

# 31. Audio System IDE / debugging requirements

Audio needs a development review surface integrated with source System IDEs rather than a parallel gameplay model.

## Inspect

Expose:
- current semantic music state request;
- active cue/stems/transition phase;
- region / Waking-Hush presentation profile;
- active ambience layers and source reason;
- critical audio priority/ducking state;
- current Cantor/resonance semantic event and audio response;
- current combat audio event and owning gameplay event ID;
- off-screen threat audio reinforcement and corresponding committed threat;
- Skiff route/vehicle semantic state and active layers;
- bus/submix/modulation state;
- user audio settings;
- caption event mapping;
- source asset/provenance ID;
- concurrency/voice stealing for critical categories;
- audio performance metrics when implementation exists.

## Exercise

Provide fixtures for:
- Cantor clear/ambiguous/blocked/no-result;
- Waybell vs Meridian vs Fault;
- Common Measure;
- ordinary Waking/Hush region pair;
- combat Light/Heavy/Guard/Perfect Guard/Evade;
- on-screen/off-screen committed threat;
- dialogue over combat/ambience if VO exists;
- Skiff acceleration/coast/brake/junction/Roadhand;
- boss resolution types;
- save success/failure UI audio;
- reduced effects;
- music off;
- ambience off;
- mono output;
- caption on/off;
- high event-density stress.

## Validate

Catch:
- audio event with no semantic owner where one is required;
- generic danger cue for noncommitted threat;
- Perfect Guard sound on failed Guard;
- Saved cue before save publication success;
- Hush ambience masking critical gameplay audio;
- critical audio with no required visual/text redundancy;
- stale music state after story/combat state ends;
- duplicate music transitions from overlapping presentation triggers;
- route unavailable sound when route is legal or vice versa;
- VO pronunciation mismatch against authority;
- missing subtitle for voiced dialogue;
- dev-only audio debug exposed in Shipping.

---

# 32. Research basis

Current production/technical research used to define the **technique envelope**, not to dictate architecture:

- Epic Games — Unreal Engine 5.8, **MetaSounds: The Next Generation Sound Sources**;
- Epic Games — Unreal Engine 5.8, **Overview of Quartz**;
- Epic Games — Unreal Engine 5.8, **Audio Modulation Overview**;
- Epic Games — Unreal Engine 5.8, **Soundscape Quick Start** — explicitly Beta / caution for shipping;
- Epic Games — Unreal Engine 5.8 release notes — current audio/MetaSound changes;
- Microsoft — Xbox Accessibility Guideline 103, multimodal visual/audio cues;
- Microsoft — Xbox Accessibility Guideline 104, subtitles/captions and important non-speech cues;
- Microsoft — Xbox Accessibility Guideline 105, independent audio-category controls.

These references inform professional practice only. They do not create an Xbox launch commitment or require the named Unreal plugins.

---

# 33. Decision rights

## LOCKED

- sound is mechanical and narrative;
- ordinary places need strong pre-crisis sonic life;
- Hush audio expresses relationship, absence, residue and contradiction rather than one global filter;
- Hush ambience cannot bury combat/tool/dialogue evidence;
- critical information cannot be audio-only;
- bell/resonance families must be semantically distinct;
- Cantor is diagnostic, not song/keycard magic;
- Meridian is centralized reference, not automatically “evil sound”;
- combat audio presents committed gameplay state rather than granting it;
- off-screen audio cannot create attack permission;
- Line Skiff sounds like network machinery, not a generic racing vehicle;
- machines sound like machines, ordinary fauna like fauna;
- Maelor/Orin are not monsterized vocally;
- Listener has no default singular demon/god voice;
- score may use silence and thematic recurrence;
- no recognizable franchise melody/earcon imitation.

## STUDIO CHOICE WITHIN BOUNDS

- exact instruments/ensemble;
- exact synthesis vs recording split;
- MetaSounds usage;
- Quartz usage;
- Audio Modulation/submix implementation;
- exact mic/recording techniques;
- source library/foley construction;
- adaptive stem architecture;
- exact reverb/spatialization implementation;
- exact music transition composition;
- exact voice casting after role requirements and VO scope are approved.

## RUNTIME / PLATFORM-GATED

- final loudness/mastering values;
- exact dynamic-range presets;
- concurrency counts;
- DSP cost;
- streaming/compression settings;
- Soundscape adoption;
- HRTF/spatialization backend;
- final ambience density;
- exact ducking/modulation values;
- final music transition timing;
- final output-device/platform behavior.

## TBD OWNER

- **VO scope** — full, selective/key-scene, gameplay-vocalization-only, or another explicit model;
- launch platforms beyond PC-first where they create platform-specific audio requirements.

## OWNER REVIEW REQUIRED FOR MATERIAL CHANGE

- changing Stillring into a music-continuous game where silence no longer functions;
- replacing region identities with a single orchestral fantasy palette;
- turning Cantor into melody/song-key gameplay;
- giving Listener/Maelor/Orin a contradictory supernatural vocal identity;
- changing the core score/sonic identity in a way that materially redefines the game.

---

# 34. Governing audio rules

1. **Sound reveals relationships before it decorates them.**
2. **A system sounds like what it physically does.**
3. **A bell is civic machinery before it is a fantasy symbol.**
4. **Cantor communicates diagnosis, not melody memory.**
5. **Meridian sounds coherent before it sounds threatening.**
6. **The Hush changes the relationship among sounds, not merely their reverb.**
7. **Silence is authored content.**
8. **Combat audio reinforces valid threats; it never creates them.**
9. **Ordinary life must be audible before its absence can matter.**
10. **The score returns to remembered material instead of replacing the world with prestige spectacle.**
11. **Voice performance preserves character contradiction rather than flattening characters into archetypes.**
12. **Critical information always has a non-audio path.**
13. **Final technical values come from runtime evidence, not middleware defaults.**

This Bible is complete only together with `docs/180_AUDIO_CUE_ASSET_AND_MUSIC_MANIFEST.md`.