# 168 — Board 06 Representative Benchmark Scene Source Brief

**Status:** ACTIVE / PRODUCTION REFERENCE SOURCE BRIEF / DOCUMENTATION-ONLY  
**Updated:** 2026-09-06  
**Parent art authority:** `docs/154_STILLRING_ART_BIBLE.md`  
**Reference-method authority:** `docs/155_ART_REFERENCE_METHOD_AND_BOARD_INDEX.md`  
**Production framework:** `docs/156_ART_PRODUCTION_MANIFEST_FRAMEWORK.md`  
**Art-workstream tracker:** `docs/157_ART_WORKSTREAM_CLOSURE_STATUS.md`  
**Character authority:** `docs/158_CHARACTER_PRODUCTION_MANIFEST.md` and Board 03 source authority `docs/164_BOARD_03_CHARACTER_STYLE_BAND_SOURCE_BRIEF.md`  
**Enemy/boss authority:** `docs/159_ENEMY_BOSS_ART_MANIFEST.md`  
**Region environment/prop authority:** `docs/160_REGION_ENVIRONMENT_PROP_MANIFEST.md`  
**Regional visual-script authority:** `docs/161_REGIONAL_COLOR_MATERIAL_LIGHTING_SCRIPTS.md`  
**Hush production authority:** `docs/162_HUSH_VISUAL_PRODUCTION_MATRIX.md`  
**VFX authority:** `docs/163_VFX_PRODUCTION_MANIFEST.md`  
**Board 02 source authority:** `docs/165_BOARD_02_REGIONAL_SHAPE_LANGUAGE_SOURCE_BRIEF.md`  
**Board 04 source authority:** `docs/166_BOARD_04_LIGHTING_ATMOSPHERE_TIME_SOURCE_BRIEF.md`  
**Board 05 source authority:** `docs/167_BOARD_05_GAMEPLAY_READABILITY_SOURCE_BRIEF.md`  
**Narrative location authority:** `docs/story/regions/01_BRINDLE_AND_FIRST_CIRCUIT.md` and `docs/story/07_SCENE_BEAT_LEDGER.md`  
**Selected benchmark anchor:** **Brindle — Relay Square / local Waybell relay**  
**Board slot:** Board 06 — Representative Benchmark Scene  
**Boundary:** this file defines the integrated visual-production benchmark that a future Board 06 execution must prove. It does not authorize UE5.8 implementation, a vertical-slice build, final level layout, exact map topology, collision, traversal dimensions, gameplay tuning, final camera values, final character models, final lighting values, renderer technology, UI production identity, VFX budgets, animation timing, audio timing, runtime performance claims, accessibility acceptance, or final Q3 asset approval.

---

# 1. Purpose

Boards 02–05 isolate Stillring's major art questions:

- regional shape and massing;
- character style and identity;
- lighting / atmosphere / time;
- gameplay readability.

Board 06 exists to answer the next production question:

> **Do those rules still look like one game when they have to coexist inside the same playable-looking scene?**

A studio can make individually attractive character, environment, lighting and VFX sheets that fail when combined.

Board 06 is therefore an **integration benchmark**.

It must show one representative Stillring place where:

- Neris looks like the same character specified by the character package;
- the region is recognizable from shape before surface decoration;
- ordinary people and work make the location worth caring about;
- architecture and props look useful rather than fantasy-set dressing;
- a regional landmark organizes composition without becoming a theme-park icon;
- the gameplay camera can read the space;
- traversal affordances remain honest;
- material hierarchy survives final-direction lighting;
- atmosphere supports depth without hiding the route;
- VFX supports physical cause and state rather than spectacle;
- a matched Hush treatment remains recognizably the same place;
- Reduced Effects / reduced-color checks preserve meaning;
- no single discipline rescues a failure created by another discipline.

The governing test is:

> **If an external studio received only this benchmark package plus the written authorities it cites, could it understand the intended integrated quality bar without mistaking concept polish for runtime proof?**

Board 06 is a production comparison target.

It is **not** evidence that Stillring has already achieved that target in-engine.

---

# 2. Why Brindle Relay Square is the benchmark anchor

The benchmark anchor is **Brindle Relay Square**, centered on the practical local Waybell relay and its ordinary market / civic-service use.

This is selected from existing canon rather than invented as a new showcase location.

`docs/story/regions/01_BRINDLE_AND_FIRST_CIRCUIT.md` establishes that:

- Brindle is where Stillring proves the world is worth caring about before asking the player to save it;
- Relay Square is used for markets most days and First Ring once a year;
- the local Waybell relay is practical infrastructure before it is symbolism;
- Brindle is a working hill settlement where agriculture, repair work and courier traffic overlap.

`docs/story/07_SCENE_BEAT_LEDGER.md` establishes Brindle Relay Square as the place for M00-S05 — **The Bell That Does Not Ring**.

That makes Relay Square unusually useful as an integration benchmark because it naturally carries:

- Neris's home-region identity;
- ordinary residents and work;
- a signature civic machine;
- a regional landmark;
- market/service props;
- route/courier context;
- First Ring ceremonial use without requiring palace or sacred architecture;
- ordinary Waking life before catastrophe;
- later Brindle Hush/Stillness comparison burden;
- the central Stillring theme that infrastructure is understandable because people maintain it.

## 2.1 What the benchmark selection does **not** mean

Selecting Relay Square does not mean:

- Brindle is visually more important than every later region;
- the final vertical slice must be set in Brindle;
- the final level layout is now locked;
- Relay Square must contain every gameplay verb;
- every region should reuse Brindle's palette, architecture or density;
- all production quality should be judged by rural materials only;
- the exact M00-S05 camera, blocking, crowd arrangement or time of day is locked by this file;
- the canonical M00-S07 first Hush sight is declared to occur in Relay Square.

The Hush counterpart required by Board 06 is a **matched production-comparison study of Relay Square** derived from Brindle Hush authority.

It is not a new narrative claim about the exact geography of Neris's first Hush crossing.

## 2.2 Why the benchmark is not Cairnspire or a finale space

Cairnspire and Null Meridian carry important later production burdens, but they are poor first integrated benchmarks for the whole art package because their scale, density and narrative escalation can hide whether Stillring's ordinary visual grammar works.

The first benchmark should prove:

- ordinary life;
- comprehensible repair culture;
- human-scale materials;
- readable civic infrastructure;
- Neris at home scale;
- regional identity without spectacle;
- Hush wrongness without relying on finale abstraction.

If Stillring cannot look coherent in Brindle, a more spectacular capital or finale image is not evidence that the art direction is healthy.

---

# 3. Benchmark authority class

Board 06 is intended to define a **Q2 Representative Production Direction** target under `docs/156`.

It may visually demonstrate:

- final-direction shape language;
- representative material treatment;
- representative texture/detail density;
- lighting interaction;
- state readability;
- a scalable-looking production approach;
- character/environment integration;
- regional kit reuse versus hero-asset distinction;
- Waking/Hush production relationship.

It may **not** claim the Q2 runtime obligations that require an actual playable implementation, including:

- verified collision/interaction behavior;
- measured camera readability under movement;
- measured asset scalability;
- target-hardware cost;
- streaming behavior;
- runtime lighting cost;
- runtime VFX cost;
- animation/IK/contact performance;
- real traversal tuning;
- human-play acceptance.

Therefore:

> **Board 06 may be a Q2 visual target before a Q2 playable implementation exists. It must be labeled visual-production reference, not vertical-slice completion.**

Q3 final-production approval remains later and requires the technical/runtime obligations in `docs/156` plus future production review.

---

# 4. Required output package

Board 06 is one benchmark scene expressed through a **matched sheet family**, not unrelated beauty shots.

Recommended repository targets once binary visual production is active:

- `docs/art/boards/06_BENCHMARK_A_WAKING_HERO.png`
- `docs/art/boards/06_BENCHMARK_B_HUSH_MATCHED.png`
- `docs/art/boards/06_BENCHMARK_C_ASSET_MATERIAL_BREAKDOWN.png`
- `docs/art/boards/06_BENCHMARK_D_GAMEPLAY_READABILITY_REDUCTIONS.png`
- `docs/art/boards/06_BENCHMARK_E_PRODUCTION_FAILURES.png`
- neighboring Markdown provenance/status note.

Minimum working resolution per sheet: **3840 × 2160** or equivalent pixel area with annotations legible at 100% display.

The package may split a sheet if readability requires it.

It may not replace matched comparison with five unrelated portfolio frames.

Every sheet must label:

- benchmark scene name;
- Waking / Hush / reduction state;
- camera type used for the study;
- authoritative source documents;
- asset uniqueness/quality class where relevant;
- canonical versus benchmark-only placement;
- provisional versus locked detail;
- reference provenance;
- generated-image noncanonical details;
- what the frame proves;
- what it explicitly does not prove.

---

# 5. Canonical scene ingredients versus benchmark composition

Board 06 must distinguish **canonical content ingredients** from **benchmark composition choices**.

## 5.1 Canonical / written-authority ingredients

The benchmark may rely on these as established production facts:

### Location identity

- Brindle sits on a sloped agricultural shelf above two flood channels and an old bell road;
- agriculture, repair/fabrication and courier traffic overlap;
- Relay Square is market space and First Ring space;
- local Waybell relay is practical infrastructure;
- Brindle uses repaired, maintained construction rather than pristine fantasy-village architecture.

### Regional kits / materials

From `docs/160` and `docs/161`:

- hill terrace / orchard / service-road families;
- workshop-home / market / relay-square family;
- maintained warm timber;
- rough local stone;
- lime/plaster off-white;
- dark iron;
- aged brass;
- agricultural cloth;
- utility ceramic;
- practical painted amber/orange civic/work accents;
- flood / irrigation / route-service relationships;
- repair benches, tool racks, replacement brackets and hinges;
- route fittings and courier arrival lanterns;
- local timing cards and small practical bells.

### Character identity

Neris must use the final written C0 identity in `docs/158`:

- female, she/her, age 17;
- 168 cm design-reference height;
- compact wiry manual-work strength;
- apprentice bellwright / field-repair visual thesis;
- slate-blue / oat / charcoal-brown / burnt-amber / aged-brass relationship;
- practical work clothing;
- no chosen-one, knight, assassin, mage or modern-tactical read.

Board 06 does not create an alternate Neris.

### Ordinary-life population

Relay Square may include Brindle C4 population families and region-appropriate workers/couriers/market users.

Named C3 characters may appear only when their presence is consistent with current narrative/location authority or the panel is explicitly labeled an illustrative production composition rather than canonical scene blocking.

### Regional lighting / atmosphere

Brindle uses:

- warm readable ordinary daylight;
- clear shadow shapes;
- moderate atmospheric softness;
- human light tied to work / shelter / gathering;
- intimate rather than blue-black night treatment;
- rain/runoff where weather is shown;
- dustier roads and softer vegetation saturation in dry conditions.

### Brindle environmental VFX

From `docs/163`:

- restrained pollen/dust in useful light;
- chimney/workshop smoke from actual sources;
- orchard leaf movement;
- rain/runoff/flood response when weather supports it;
- small work sparks only at real work events.

No dreamy fairy-pollen tutorial treatment.

### Hush production relationship

From `docs/161` and `docs/162`:

- Brindle remains recognizable;
- ordinary maintenance and family/civic memory become incorrectly preserved;
- occupancy/light/use relations may change;
- route/flood markers may disagree or look over-maintained without ordinary activity;
- familiar wear may disappear;
- repeated/too-perfect object state may appear where authored;
- Hush uses fewer ordinary motes and selective motion suspension rather than particle spectacle.

## 5.2 Benchmark-only composition choices

The execution team may choose for visual study:

- exact gameplay-compatible camera position;
- exact Relay Square composition;
- exact placement of market tables / benches / route fixtures;
- exact background visibility of orchard, road, flood infrastructure or neighboring roofs;
- exact number and placement of illustrative civilians;
- exact sun direction or weather condition inside `docs/161` bounds;
- exact low service platform / stair / route-edge geometry used to test Board 05 readability;
- exact non-gameplay annotation overlays;
- exact Hush comparison arrangement within `docs/162` bounds.

These are **not automatically canonical map topology or story blocking**.

The sheet must mark them as benchmark composition until level design / narrative staging / gameplay implementation later validates or replaces them.

---

# 6. Sheet A — Waking hero frame

Sheet A is the primary integrated benchmark.

It should read first as:

> **A functioning Brindle civic/work square that Neris belongs to.**

Only after that should the viewer notice production detail.

## 6.1 Required composition hierarchy

The hero frame must establish five readable layers:

1. **Neris / immediate playable foreground**;
2. **ordinary route and work activity**;
3. **Relay Square / local Waybell identity-bearing midground**;
4. **Brindle agricultural / road-service context**;
5. **quiet atmospheric background**.

The Waybell relay should organize the composition but must not read as a glowing holy monument.

Neris must remain clearly readable without a spotlight or outline.

## 6.2 Ordinary life before crisis

The frame must contain enough ordinary use that the viewer can answer:

- Who works here?
- What is being maintained?
- How do people move goods or messages?
- Which objects are touched every day?
- Where would someone wait, repair, sell, carry or check something?
- Why would residents care if the relay stopped working?

Useful production ingredients include:

- market/service tables;
- route fittings;
- repair bench or tool station;
- courier arrival/condition fixture;
- handwritten timing/service card;
- worn hand-contact surfaces;
- practical small bells/chimes;
- ordinary containers/cloth/ceramic;
- one visible repair or replacement that clearly solved a real problem.

Do not fill the square with decorative barrels/crates merely to increase prop count.

## 6.3 Neris integration

Neris should be shown at a gameplay-compatible distance and scale.

The frame must prove:

- silhouette separation from Brindle timber/stone values;
- readable hands/tool/work posture if a work action is depicted;
- costume material contrast without neon hero-color treatment;
- age and body identity survive environment lighting;
- Neris belongs to the same material culture as the square while remaining a unique C0 hero;
- no giant fantasy weapon, cape, armor silhouette or prestige outfit is introduced.

If Neris's face is only readable because the camera is cinematic-close, the gameplay integration check has failed.

## 6.4 Regional kit versus hero asset

The frame must visibly distinguish:

- repeatable Brindle kit language;
- Relay Square / local Waybell hero burden;
- U0 shared construction logic where appropriate;
- region-specific U1/R1 modules;
- R2/U2 hero features that should not be tiled everywhere.

A viewer should be able to infer what could plausibly be reused across Brindle without making Relay Square feel generated from one repeated module.

## 6.5 Detail hierarchy

Use `docs/154` Tier A–E logic:

- strongest detail on Neris, Waybell/service machinery and story/work-critical props;
- gameplay-relevant structures read clearly;
- regional kit supports identity without every object demanding inspection;
- background support is quiet;
- distant silhouette exists for shape, not microtexture.

Reject the frame if every plank, stone, pot, sign and garment has equal texture/noise priority.

---

# 7. First Ring relationship without over-canonizing staging

Relay Square's First Ring use is canonical, but Board 06 is an art benchmark rather than the final M00-S05 cinematic/gameplay staging document.

The Waking hero frame may be presented as either:

1. **ordinary market / First Ring preparation**, or
2. **First Ring gathering before the failure**, if narrative production later confirms the chosen staging is compatible.

The sheet must not invent canonical dialogue blocking, exact festival choreography, exact number of participants, exact bell timing or exact camera cuts.

If First Ring is depicted:

- civic belonging and practical system-testing should coexist;
- ceremony grows out of working infrastructure;
- decoration remains restrained and locally maintained;
- the local Waybell remains a machine people use, not a fantasy altar;
- Brindle must not be graded as visibly doomed.

The future M00-S05 execution remains subordinate to narrative/cinematic production authority.

---

# 8. Traversal / gameplay-readability integration

Board 06 must prove that a visually rich scene can still preserve Board 05's honest-world rules.

It does **not** need to demonstrate every locomotion verb.

The main benchmark should include enough route structure to test:

- ordinary walkable ground / lane;
- stairs or small-step handling;
- one plausible low service/loading change in elevation where an approved mantle-like read can be studied if useful;
- one nearby non-traversal surface that does not accidentally advertise universal climbing;
- clear edge / drop / flood-channel relationship where visible;
- landmark and route orientation without an objective beam.

## 8.1 Benchmark traversal fixture rule

Any mantle/ledge/route geometry created specifically for the art study is a **benchmark fixture**, not a newly canonical Brindle route.

It must:

- use only current locomotion semantics;
- be clearly labeled provisional layout;
- avoid assigning exact height/angle values;
- avoid claiming collision validation;
- avoid implying that every similar Brindle object is traversable.

Board 06 may prove visual vocabulary.

Only later gameplay implementation can prove actual traversal behavior.

## 8.2 Camera relationship

Primary readability review uses a camera composition compatible with the current medium-wide, slightly elevated, full-body exploration philosophy.

Board 06 must not use a detached high cinematic camera as its only proof.

The frame should allow a reviewer to see simultaneously:

- Neris's footing;
- immediate route;
- the Relay Square landmark/service destination;
- enough surrounding world to understand Brindle's context.

Exact camera boom/FOV/pitch values remain runtime tuning.

---

# 9. Lighting / atmosphere integration

Board 06 must demonstrate `docs/161` and Board 04 together with actual materials and population.

## 9.1 Default benchmark condition

The primary Waking hero frame should use an **ordinary inhabited Brindle condition** rather than catastrophe lighting.

The execution team may choose a daylight, late-day or early-evening condition inside the written Brindle script depending on which best exposes:

- material hierarchy;
- human work light;
- route readability;
- Neris/environment separation;
- Waybell/market identity.

The chosen clock condition is a **board execution choice**, not newly locked story time.

## 9.2 Required lighting relationships

The scene should preserve:

- warm directional or locally believable Brindle light;
- readable shadow shapes;
- restrained depth atmosphere;
- clear material separation;
- human light associated with work/gathering where visible;
- quieter background than playable/midground hierarchy;
- no blanket orange nostalgia grade;
- no blue-black night solution;
- no exposure trick that hides route edges or Neris's silhouette.

## 9.3 Weather stress inset

One inset may show rain or dry-weather variation using the same composition.

Its job is to verify:

- wet timber/stone/soil separate by material;
- drainage/flood infrastructure gains visual relevance;
- route and character remain readable;
- atmosphere changes depth rather than erasing the location.

Weather inset is optional for the hero sheet if fully covered in the matched reduction sheet.

---

# 10. VFX integration

Board 06 should show the **smallest sufficient amount of VFX** needed to make the scene feel alive and stateful.

## 10.1 Ordinary Waking VFX

Appropriate examples from `docs/163` include:

- restrained dust/pollen only where light/season/source justify it;
- chimney/workshop smoke from visible source;
- orchard/cloth/foliage movement tied to coherent wind;
- runoff if rain is shown;
- small work sparks only if actual metal work is occurring.

The square must still work if all decorative micro-effects are removed.

## 10.2 Waybell / resonance presentation

If the local Waybell operating state includes visual resonance support, it must obey the global VFX rules:

- mechanism/material state remains primary;
- effect originates from understandable machinery relation;
- cool/pale resonance accents remain restrained;
- no generic magic aura;
- no beam to the sky merely to announce importance;
- no particles becoming the sole proof that the machine is active.

Exact effect timing, emitter structure, intensity and runtime cost remain future execution/runtime decisions.

## 10.3 Density test

The main frame should visibly reserve quiet areas.

Reject if:

- dust, smoke, pollen, sparks and resonance all compete simultaneously;
- every moving object has equal visual priority;
- atmospheric particles obscure route/character edges;
- the Waybell is readable only because it glows brighter than everything else.

---

# 11. Sheet B — matched Hush benchmark

Sheet B must use a **recognizably matched Relay Square composition**.

It should be possible to place the Waking and Hush images side-by-side and identify the same place before reading annotations.

## 11.1 Hush job

The Hush version must communicate:

> **ordinary maintenance and civic use preserved incorrectly.**

Use Brindle-specific wrong relationships such as:

- a repair surface lacking the wear created by its known use;
- a local marker or timing card in a plausible but contradictory state;
- a bench/tool arrangement too orderly for its work history;
- a replaced fitting appearing as if it had never been replaced;
- warm inhabited light present without believable occupant activity;
- a route/flood-service signal locally precise but socially disconnected;
- selected motion suspended while another nearby causal system continues;
- repeated dust fall or residue only in a bounded authored spot.

These are examples inside established Hush authority, not a requirement to use every one at once.

## 11.2 What must remain stable

Preserve:

- Brindle hill / road-service identity;
- Relay Square recognition;
- local Waybell ancestry;
- route readability;
- Neris recognition if Neris is included in the matched frame;
- major material families;
- gameplay-significant geometry unless source gameplay authority says otherwise.

## 11.3 What must not happen

Reject:

- global purple/blue LUT;
- black tendrils;
- floating rocks without authored cause;
- ghost village population;
- every object duplicated;
- screen-space glitch treatment;
- generic fog increase hiding the square;
- glowing cracks across every surface;
- Hush route changes invented by concept art;
- a completely different dark-fantasy version of Brindle.

## 11.4 Narrative non-claim

The Hush Relay Square benchmark is a production study.

It does **not** declare that M00-S07's canonical first Hush sight occurs in Relay Square or that the exact benchmark contradiction appears in the shipped story.

Narrative staging remains governed by current story authority.

---

# 12. Sheet C — asset / material / production breakdown

Sheet C exists so an external art producer can look past the hero painting and understand how the scene would be built.

It must identify representative scene ingredients by production role.

## 12.1 Character

- Neris — C0 / U3 / final Q3 target; Board 06 uses current written design as visual benchmark input.
- optional C4 Brindle population examples — reusable bounded population system.
- any named C3 presence — identify by name/class and label illustrative versus canonical staging.

## 12.2 Environment

Label examples of:

- R1/U1 Brindle architecture modules;
- R1 natural/terrain kit;
- R1/R3 civic/work family;
- R2/U2 Relay Square / Waybell hero burden;
- U0 shared construction/support elements where visible.

## 12.3 Props

At least one example each where naturally supported:

- work/repair prop;
- route/courier prop;
- civic indicator/marking;
- domestic/market ordinary-life prop;
- region-specific small bell/chime/relay element.

## 12.4 Materials

Show the major material family separated from lighting:

- warm maintained timber;
- local rough stone;
- lime/plaster;
- dark iron;
- aged brass;
- cloth;
- utility ceramic;
- soil/road surface;
- foliage.

The sheet should demonstrate that material identity survives a neutralized lighting/material-ball-style comparison without becoming a photoreal texture showcase.

## 12.5 Hush burden tags

For representative shared assets, note intended burden class from `docs/162` where applicable:

- H0/H1 terrain;
- H0/H2 ordinary shells;
- H1/H2 route/flood infrastructure;
- H2/H3 work/repair relationships where authored.

Do not classify a benchmark prop into H3/H4 merely because a concept artist wants a more dramatic alternate.

---

# 13. Sheet D — gameplay / reduction checks

Sheet D converts the hero scene into production checks.

It must use the **same scene** rather than unrelated examples.

Required comparisons:

1. normal full-color Waking frame;
2. grayscale/value reduction;
3. saturation-reduced frame;
4. Reduced Effects conceptual frame;
5. Waking/Hush thumbnail pair;
6. gameplay-camera crop emphasizing Neris + route + Waybell relation;
7. clutter-off / tertiary-detail reduction study.

## 13.1 Grayscale test

Pass if a reviewer can still identify:

- Neris;
- main route / playable ground;
- Relay Square landmark/service focus;
- foreground / midground / background hierarchy;
- important large material/structure masses.

Fail if the scene collapses when amber/green/blue distinctions disappear.

## 13.2 Reduced Effects test

Remove or substantially reduce:

- decorative dust/pollen;
- low-priority smoke/motes;
- optional resonance richness;
- tertiary environmental motion cues.

Preserve:

- machine state through mechanism/material relation;
- route readability;
- Neris readability;
- Hush/Waking distinction through world-space relationships;
- any gameplay-critical state carried by non-VFX channels.

This is conceptual art verification only.

It does not prove the runtime Reduced Effects setting exists or is accessible/performance-valid.

## 13.3 Detail-reduction test

Temporarily remove tertiary dressing.

If Relay Square loses identity, the scene depended too heavily on prop clutter.

If the scene becomes clearer while losing no identity, some detail should remain removed in the final target.

---

# 14. Sheet E — explicit production failures

Board 06 must include controlled failure examples so the studio knows what **not** to optimize toward.

At minimum compare the target against these failure families.

## 14.1 Generic fantasy tutorial village

Failure traits:

- picturesque cottages with no work logic;
- barrels/crates everywhere;
- fantasy bunting/runes with no institutional owner;
- oversized glowing shrine bell;
- villagers used only as decorative crowd mass;
- no flood/road/repair/service evidence.

## 14.2 Photoreal detail-first village

Failure traits:

- equal microdetail everywhere;
- texture noise destroying value hierarchy;
- Neris disappearing into plausible but uncontrolled background values;
- every material trying to demonstrate high-frequency realism;
- route readability rescued by UI.

## 14.3 Retro imitation

Failure traits:

- literal N64 polygon/texture imitation used as the production target;
- period-resolution artifacts treated as style requirements;
- reduced geometry because nostalgia says so rather than because shape hierarchy benefits.

Stillring keeps N64-era readability lineage, not 1998 technical limits.

## 14.4 Theme-park affordance village

Failure traits:

- yellow/white climb paint;
- glowing mantle edges;
- every usable object outlined;
- route arrows painted onto the world;
- ladder language copied onto decorative rails and pipes.

## 14.5 Hush as filter

Failure traits:

- same scene plus purple grade;
- generic glitch overlays;
- particle increase used as wrongness;
- no change to occupancy/use/wear relationships;
- regional identity weakened.

## 14.6 Cinematic-only success

Failure traits:

- beautiful composition from a camera the game will not use;
- playable camera crop reveals cluttered route and weak character separation;
- Waybell landmark only works from one hero angle;
- Hush difference disappears at gameplay distance.

## 14.7 Over-spectacle resonance

Failure traits:

- Waybell emits giant magic beam;
- bloom or particles become the machine identity;
- Neris reduced to spectator silhouette;
- ordinary civic function becomes mystical set piece before the story earns escalation.

---

# 15. Reference-acquisition brief

Board 06 may use external reference only through the `docs/155` extraction protocol:

1. Reference;
2. Question;
3. Extracted principle;
4. Stillring translation;
5. Forbidden carryover.

Because Board 06 is an integrated scene, source acquisition should be separated by production problem rather than searching for a single image that already “looks like Stillring.”

## 15.1 Useful source baskets

### Working rural civic squares / market-service spaces

Study:

- how work, market and circulation coexist;
- how public infrastructure sits inside ordinary life;
- how repair/storage areas remain legible without looking staged.

Do not copy a specific village plan, landmark or facade.

### Small-scale mechanical infrastructure

Study:

- service access;
- wear at hand/tool contact;
- replaceable parts;
- public-facing controls/indicators;
- repair visibility.

Do not turn a real machine into a one-to-one fantasy prop.

### Terraced agricultural settlements / road-service settlements

Study:

- how routes meet slopes;
- how retaining/drainage structures affect settlement shape;
- how agriculture remains visible near civic space.

Do not copy one photographed settlement's skyline or street plan.

### Warm ordinary-life lighting

Study:

- work-light hierarchy;
- warm/cool depth separation;
- dusk/day transitions;
- readable faces/bodies without theatrical key light.

Do not copy a film still's exact composition, grading or lighting setup.

### Material maintenance / repair reference

Study:

- patches;
- replacement hardware;
- hand polish;
- tool marks;
- causal weathering;
- mixed-age components.

Avoid “old = dirty” surface language.

### Gameplay readability reference

Games may be studied only for abstract issues such as:

- third-person composition;
- landmark persistence;
- affordance consistency;
- character-background separation;
- density control.

Do not use another game's village as a direct benchmark target.

`docs/05_IP_GUARDRAILS.md` remains binding.

---

# 16. Generated-image policy

Generated imagery may be used for exploratory composition or controlled comparison, but Board 06 is especially high-risk because a generated image can silently invent many disciplines at once.

Every generated Board 06 candidate must record:

- which written rule it demonstrates;
- which visible details are accidental/noncanonical;
- whether Relay Square layout is benchmark-only;
- whether any traversal surface is benchmark-only;
- whether any NPC presence is illustrative rather than canonical staging;
- whether any symbol/sign/mark is provisional;
- whether any Waybell mechanism detail is provisional;
- whether any VFX is provisional;
- whether any Hush contradiction is authorized by `docs/162`;
- whether protected-work resemblance is too close;
- what a production artist must redesign.

Generated imagery may **not** establish:

- final Neris face/body/costume deviation;
- final Relay Square topology;
- final Waybell engineering;
- final traversal route;
- final Hush geometry;
- final signage language;
- final UI;
- final VFX timing;
- final lighting values;
- runtime feasibility.

A generated “beautiful shot” that conflicts with written authority is discarded or corrected.

---

# 17. Production dependency gate for rendered Board 06

This source brief may exist now because Boards 02–05 have stable written contracts.

However, a rendered Board 06 artifact must carry a truthful status.

## 17.1 DIRECTIONAL execution may begin when binary visual production is authorized

A directional execution may use:

- current written Neris authority;
- current written Brindle environment/prop authority;
- current written lighting/Hush/VFX/readability authority;
- provisional benchmark composition.

It must be labeled **DIRECTIONAL** if the upstream visual executions have not yet received owner/art-package review.

## 17.2 PRODUCTION REFERENCE promotion requires upstream visual reconciliation

Before Board 06 is promoted to **PRODUCTION REFERENCE**, confirm that it does not contradict the approved visual executions for:

- Board 02 regional shape;
- Board 03 Neris / character style;
- Board 04 lighting / atmosphere;
- Board 05 gameplay readability.

If Board 06 reveals a conflict among those visual executions, the conflict must be reconciled against written authority.

Do not allow the prettiest integrated image to silently supersede a written rule.

## 17.3 Runtime remains separate

Even a fully owner-reviewed production-reference Board 06 does not prove:

- final UE5 fidelity;
- performance;
- streaming;
- collision;
- traversal feel;
- animation contact;
- crowd performance;
- lighting scalability;
- Hush runtime architecture;
- VFX scalability;
- accessibility;
- human-play quality.

Those remain future implementation/test evidence.

---

# 18. Decision rights

## LOCKED / implement visually without redefining

- Brindle Relay Square is the Board 06 benchmark anchor;
- the benchmark's job is integration verification, not new game design;
- Neris uses `docs/158` identity;
- Brindle regional identity uses `docs/160`/`161`;
- Hush uses `docs/162` relationship grammar;
- VFX uses `docs/163` hierarchy and physical-cause rules;
- gameplay-readability checks use `docs/167` without inventing mechanics;
- gameplay-compatible camera relationship is required for the primary review;
- ordinary life must be visible before crisis treatment;
- the Waybell relay must read as practical civic infrastructure before symbolism;
- Hush comparison must remain recognizably Relay Square;
- reduced-color / Reduced Effects conceptual checks are required;
- protected-work copying is prohibited.

## STUDIO CHOICE WITHIN BOUNDS

- exact drawing/render medium;
- exact benchmark camera pose inside current camera philosophy;
- exact ordinary Waking time/weather condition inside Brindle script;
- exact provisional placement of market/work props;
- exact illustrative C4 population arrangement;
- exact local material values preserving written relationships;
- exact Hush contradiction selected from authorized Brindle grammar;
- exact sheet layout and annotation design;
- exact reference sources under provenance/IP rules.

## OWNER / ART-PACKAGE REVIEW

Return for review if execution proposes:

- changing the benchmark anchor to another region/location;
- materially changing Neris's locked identity;
- making Relay Square a mystical/shrine-centered space;
- changing Brindle's locked palette/material/shape relationship;
- replacing practical Waybell identity with spectacle-first design;
- adopting universal highlight/climbing paint language;
- using a Hush treatment that overrides regional identity;
- promoting a Board 06 visual contradiction into new gameplay/story canon;
- shifting the overall visual style toward photoreal, anime, cartoon, cel-shaded, retro-low-poly or grimdark treatment.

## RUNTIME / TECHNICAL EVIDENCE

Only later implementation may settle:

- final world scale conversion;
- exact camera values;
- exact traversal dimensions;
- collision;
- topology/texture/material budgets;
- LOD/Nanite/streaming implementation;
- exact lighting/exposure/GI/shadow solution;
- VFX budgets and Reduced Effects implementation;
- crowd density/performance;
- animation/IK/contact quality;
- runtime Hush representation;
- final accessibility validation;
- target-hardware performance;
- human-play readability.

---

# 19. Acceptance checklist — Board 06 source brief

The **written source brief** passes only when all are true:

- [ ] benchmark location is selected from existing canon rather than invented;
- [ ] selection rationale is explicit;
- [ ] benchmark does not silently become final level topology;
- [ ] exact narrative staging remains outside art-board authority;
- [ ] Neris source authority is explicit;
- [ ] Brindle region/environment/prop source authority is explicit;
- [ ] lighting/material source authority is explicit;
- [ ] Hush source authority is explicit;
- [ ] VFX source authority is explicit;
- [ ] gameplay-readability source authority is explicit;
- [ ] Q2 visual-target versus runtime-proof distinction is explicit;
- [ ] Waking hero-frame obligations are explicit;
- [ ] ordinary-life burden is explicit;
- [ ] regional kit versus hero-asset burden is explicit;
- [ ] gameplay-camera review obligation is explicit;
- [ ] traversal benchmark fixtures are labeled noncanonical layout;
- [ ] matched Hush comparison is required;
- [ ] Hush benchmark is explicitly not a claim about M00-S07 location;
- [ ] asset/material breakdown is required;
- [ ] grayscale/saturation/Reduced Effects/detail reductions are required;
- [ ] failure examples are required;
- [ ] generated-image accidental detail is noncanonical;
- [ ] provenance/IP extraction protocol is required;
- [ ] rendered artifact promotion gate is explicit;
- [ ] runtime/performance/accessibility/human-play claims are prohibited without evidence;
- [ ] decision rights are explicit.

---

# 20. Acceptance checklist — future rendered Board 06

A future Board 06 visual execution may be promoted to **PRODUCTION REFERENCE** only if review confirms:

## Scene identity

- [ ] the scene reads as Brindle before text labels are read;
- [ ] Relay Square / local Waybell reads as useful civic infrastructure;
- [ ] ordinary work / market / route use is visible;
- [ ] the location feels worth caring about before catastrophe;
- [ ] the hero vista is not built entirely from one repeated module.

## Character

- [ ] Neris matches current Board 03 / `docs/158` identity;
- [ ] Neris remains readable at gameplay-compatible distance;
- [ ] Neris belongs to Brindle while remaining C0-distinct;
- [ ] no costume redesign is smuggled in through benchmark art.

## Environment / materials

- [ ] large-form hierarchy is clear before surface detail;
- [ ] Brindle material families are distinguishable;
- [ ] weathering/repair is causal;
- [ ] repair beats generic decay;
- [ ] kit reuse is visible without clone repetition;
- [ ] hero assets retain special burden.

## Lighting / atmosphere

- [ ] Waking frame is not doom-graded;
- [ ] light supports route, character and region hierarchy;
- [ ] atmosphere separates depth without erasing landmarks;
- [ ] human light reads as work/shelter/community where used;
- [ ] scene survives grayscale/saturation reduction.

## Gameplay readability

- [ ] primary route reads from current gameplay-camera relationship;
- [ ] Neris's footing is understandable;
- [ ] any shown traversal affordance is visually honest;
- [ ] nearby non-affordances do not advertise identical hidden permissions;
- [ ] no universal climb/interaction paint is required;
- [ ] landmark guidance works without objective beam/minimap rescue.

## VFX

- [ ] ordinary environmental VFX come from physical causes;
- [ ] decorative effects can be removed without semantic loss;
- [ ] Waybell/resonance presentation remains restrained;
- [ ] no effect obscures route/character/mechanism silhouette;
- [ ] Reduced Effects conceptual comparison preserves meaning.

## Hush

- [ ] Hush frame is recognizably the same Relay Square;
- [ ] wrongness comes from relationships, occupancy, wear, material/light or bounded motion contradiction;
- [ ] Brindle palette/shape identity survives;
- [ ] Hush is not a global filter;
- [ ] concept art does not invent route/collision semantics;
- [ ] the Hush frame remains readable with post-process richness reduced.

## Production truthfulness

- [ ] artifact status is accurate: Directional or Production Reference;
- [ ] provisional map/layout details are labeled;
- [ ] external/generated references have provenance;
- [ ] protected-work expression has not been copied;
- [ ] no runtime/performance claim is attached to the board;
- [ ] unresolved implementation decisions remain labeled runtime/technical.

---

# 21. Rejection conditions

Reject Board 06 execution if any of the following are true:

- it looks like a generic fantasy tutorial village;
- it depends on cinematic framing that contradicts gameplay-camera composition;
- Neris is visually redesigned;
- the Waybell becomes a magic shrine;
- the square has no credible work / market / service logic;
- every surface is equally detailed;
- environment detail overwhelms Neris or route readability;
- universal climbing/highlight paint is used to rescue weak affordances;
- VFX provides the only readable machine state;
- the Hush version is merely recolored;
- the Hush version becomes a different dark-fantasy location;
- generated artifacts silently establish signage, topology, costume or mechanism canon;
- the benchmark is described as implemented, playable, performant or accessibility-validated without evidence;
- the board is treated as Q3 final-production approval merely because it is highly rendered.

---

# 22. What Board 06 proves

When the **source brief** exists, the repository proves that an integrated benchmark has a bounded production contract.

When a future **rendered Board 06** passes review, it may prove:

- the written art rules can coexist visually in one representative scene;
- Brindle can carry Stillring's character/environment/material/light/VFX/readability identity at integrated concept-production quality;
- Waking/Hush relationship can survive matched composition;
- the studio has a common visual comparison target for representative production direction;
- independent discipline outputs have been reconciled at art-direction level.

---

# 23. What Board 06 does **not** prove

Neither this source brief nor a rendered art board proves:

- UE5.8 project existence;
- a playable vertical slice;
- final map layout;
- final collision;
- final traversal feel;
- final camera feel;
- final combat/tool/Hush gameplay behavior;
- final animation quality;
- final audio;
- final UI;
- final lighting/rendering technology;
- final VFX implementation;
- target-platform performance;
- memory/streaming budgets;
- accessibility compliance;
- human-play quality;
- shipping readiness.

Those remain separate future evidence obligations.

---

# 24. Art-workstream consequence

With this source brief, the written Board 02–06 visual-development suite has a production-executable contract:

- Board 02 — Regional Shape Language;
- Board 03 — Character Style Band;
- Board 04 — Lighting / Atmosphere / Time;
- Board 05 — Gameplay Readability;
- Board 06 — Representative Benchmark Scene.

The next art-workstream need is **not another source brief** unless review discovers a genuine gap.

Remaining art closure depends on:

1. visual execution / owner-art-package review when binary art production is active;
2. representative model/environment/VFX production proof;
3. numeric scale and technical budgets only after implementation evidence;
4. runtime readability / accessibility / performance proof;
5. reconciliation into global onboarding/authority indexes after the art package is reviewed.

No UE5.8 implementation or testing is authorized by this document.
