# 161 — Regional Color / Material / Lighting Scripts

**Status:** ACTIVE / STUDIO-HANDOFF VISUAL PRODUCTION AUTHORITY / DOCUMENTATION-ONLY PRE-PRODUCTION  
**Updated:** 2026-09-06  
**Parent program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Art authority:** `docs/154_STILLRING_ART_BIBLE.md`  
**Production framework:** `docs/156_ART_PRODUCTION_MANIFEST_FRAMEWORK.md`  
**Character authority:** `docs/158_CHARACTER_PRODUCTION_MANIFEST.md`  
**Enemy/boss authority:** `docs/159_ENEMY_BOSS_ART_MANIFEST.md`  
**Region environment/prop authority:** `docs/160_REGION_ENVIRONMENT_PROP_MANIFEST.md`  
**Narrative authority:** `docs/story/regions/00_REGIONAL_STORY_INDEX.md` and `docs/story/regions/01`–`09`  
**Closes toward:** `SH-ART-006` and region-facing portions of `SH-ART-007`/`SH-ART-009`  
**Boundary:** this file locks regional visual relationships, not renderer technology, exposure values, lumen counts, texture budgets, shader complexity, fog cost, light counts, or measured performance.

---

# 1. Purpose

This document converts Stillring's regional art direction into production-ready color, material, lighting and atmosphere scripts.

A region is not visually defined by a hex palette alone.

Each region must be recognizable through the relationship among:

- dominant value structure;
- environmental color family;
- structural/material family;
- civic and occupational accents;
- human light;
- weather;
- night behavior;
- Hush transformation;
- post-Stillness adaptation;
- gameplay-critical contrast.

The governing rule is:

> **A player should recognize the region after the color is desaturated, the weather changes, and half the lights go out.**

Color supports identity. Shape, material, value and light complete it.

---

# 2. Authority and decision rights

## LOCKED

- regional palette relationships in this file;
- material hierarchy and weathering logic;
- lighting intent and focal hierarchy;
- night identity;
- weather identity;
- Hush transformation principles;
- post-Stillness visual consequences;
- prohibition against one global Hush grade;
- prohibition against generic grimdark/desaturated catastrophe treatment;
- gameplay readability outranking photographic realism.

## STUDIO CHOICE WITHIN BOUNDS

- exact physically based material implementation;
- source texture/sculpt method;
- exact shader graph architecture;
- exact light-authoring workflow;
- local color values that preserve the written relationships;
- exact sky/fog implementation;
- exact material roughness ranges;
- exact reflection solution;
- exact day/night authoring technology.

## RUNTIME / TECHNICAL EVIDENCE

Not locked here:

- exposure values;
- lumen/candela values;
- GI solution;
- shadow solution;
- Lumen/Nanite/fallback decisions;
- volumetric resolution;
- fog density budgets;
- VFX overdraw limits;
- reflection cost;
- material instruction budgets;
- texture resolution/memory;
- platform scalability.

Those require later representative implementation and target-platform evidence.

---

# 3. Global color and value rules

## 3.1 Value hierarchy

Stillring scenes should usually resolve into three broad value layers before fine lighting detail:

1. **navigation / playable foreground** — readable local contrast;
2. **identity-bearing midground** — architecture, landmark, machinery, population;
3. **atmospheric background** — depth-separated, quieter detail.

Do not flatten every surface into the same mid-value realism.

## 3.2 Saturation hierarchy

Highest saturation belongs selectively to:

- human-made civic accents;
- living/work activity;
- important local material identity;
- controlled gameplay cues;
- rare story-state emphasis.

Background terrain and structural masses should generally be more restrained.

Stillring must not look like every object was individually color-picked for maximum visual interest.

## 3.3 Human light

Ordinary inhabited light is important to Stillring.

Warm human light should often communicate:

- food;
- work;
- shelter;
- maintenance;
- community;
- continued life.

After catastrophe, the disappearance or fragmentation of those pools matters because the player remembers them.

## 3.4 Danger

Danger cannot be represented only by red.

Use redundant cues:

- value break;
- motion;
- silhouette;
- material state;
- local light behavior;
- sound/VFX where applicable.

## 3.5 Hush

The Hush preserves each region's identity while changing relationships.

Never apply one universal blue/purple LUT and call the work finished.

## 3.6 Accessibility

Critical interaction/traversal/hazard information must remain legible under reduced color discrimination.

Color coding requires at least one additional signal:

- shape;
- icon/mark;
- material;
- pattern;
- motion;
- position;
- light/value.

---

# 4. Material doctrine shared across regions

## 4.1 Material read before microdetail

At gameplay distance, the player should distinguish:

- wood;
- stone;
- metal;
- ceramic;
- cloth;
- glass;
- water;
- living plant/root material;

without requiring close inspection.

## 4.2 Weathering is causal

Weathering belongs where process explains it.

Examples:

- Saltreach metal corrodes along exposure and runoff paths;
- Emberstep surfaces discolor near actual heat;
- Rootmere timber darkens where persistent moisture reaches it;
- High Aerie edges polish or abrade where ropes/loads repeatedly contact them;
- Cairnfall instrument surfaces show hand calibration, grit and exposure at moving joints;
- Mireglass structures show waterline, reed and reflection-related wear rather than generic moss everywhere.

## 4.3 Repair beats decay

Stillring is full of maintained things.

Prefer:

- patches;
- replaced plates;
- restitched coverings;
- new pins in old mechanisms;
- locally sourced substitutes;
- maker stamps;
- hand-written corrections;

instead of universal ruin grime.

## 4.4 Civic ancestry

Meridian-linked civic infrastructure should share a recognizable old engineering ancestry across Orra:

- restrained brass/bronze/iron families;
- deliberate service seams;
- removable panels;
- measurement marks;
- standardized geometry where historical centralization explains it.

Regional people may repair or adapt those systems with local materials.

---

# 5. Brindle / First Circuit script

## 5.1 Emotional job

Brindle must be worth missing.

It is the visual baseline for ordinary repair, family memory and small comprehensible systems.

The opening should not grade Brindle as a doomed place waiting to be destroyed.

## 5.2 Color relationship

**Dominant environment:** muted hill greens, dry grass olive, orchard green.  
**Earth/stone:** warm gray-brown and dusty ochre.  
**Architecture:** weathered warm timber, lime/plaster off-white, local gray stone.  
**Civic/work accent:** aged brass and practical painted amber/orange markers.  
**Human light:** warm amber, strongest at inn/workshop/relay gathering areas.  
**Danger contrast:** cold seam-cyan/blue-white against familiar warm workshop values; use sparingly.

Concept swatches, directional only:

- orchard olive `#697052`
- dry hill grass `#958D63`
- plaster flax `#C9BE9D`
- warm timber `#745C45`
- local stone `#77746A`
- repair amber `#B87942`
- resonance pale-cyan `#8FB8B5`

## 5.3 Material identity

Primary:

- maintained timber;
- rough local stone;
- lime/plaster;
- dark iron;
- aged brass;
- woven agricultural cloth;
- glazed utility ceramic.

Wear:

- hand-polished workbench edges;
- replaced hinges;
- patched plaster;
- water marks at flood channels;
- dust on road-facing surfaces;
- tool marks where repair actually occurs.

Avoid picturesque over-aging. Brindle is functioning.

## 5.4 Day lighting

Default ordinary Brindle favors:

- warm directional daylight;
- clear readable shadow shapes;
- moderate atmospheric softness;
- visible contrast between exterior sun and workshop/inn shade;
- bright but not bleached agricultural openness.

The Vale Workshop should have a legible work-light hierarchy even in daytime: window light, task area, deeper storage.

## 5.5 Night lighting

Night should remain intimate rather than blue-black.

Use:

- small warm windows;
- relay lanterns;
- inn light;
- workshop spill;
- sparse road markers.

Do not illuminate every path edge like a theme park.

## 5.6 Weather

Rain:

- deepens soil/timber;
- increases stone value separation;
- makes drainage/flood systems visually relevant;
- keeps human light warm and attractive.

Dry weather:

- dustier roads;
- softer vegetation saturation;
- stronger warm/cool evening contrast.

## 5.7 Hush relationship

Brindle Hush states should feel wrong because ordinary maintenance relationships fail or repeat:

- a repair patch missing while the damage remains;
- a gate reset to an older position;
- workshop objects arranged too perfectly;
- warm light present without believable occupant activity;
- familiar materials lacking normal accumulated wear.

Do not turn Brindle purple.

## 5.8 Post-Stillness / Unringing

The region should gain visual evidence of local coordination:

- handwritten cards;
- multiple small signal points;
- mismatched repaired bells;
- human light in isolated active pockets;
- visible manual operation.

The palette stays recognizably Brindle. The change is organizational, not a new color scheme.

---

# 6. Cairnspire script

## 6.1 Emotional job

Cairnspire must first look like a city whose central coordination genuinely accomplishes useful things.

Its later failure matters only if the player understands why people trusted it.

## 6.2 Color relationship

**Dominant environment:** cool stone neutrals and hazed blue-gray depth.  
**Architecture:** pale gray limestone/plaster, dark service iron, desaturated blue-gray civic paint.  
**Civic accent:** controlled brass/bronze and muted blue.  
**Human/service accent:** food-stall ochres, cloth reds/oranges used locally rather than institutionally.  
**Human light:** warm ivory/amber islands inside cooler vertical city masses.  
**Danger contrast:** institutional warning white/cyan and deep desaturated red used only where systems actually signal danger.

Directional swatches:

- civic stone `#969A98`
- pale masonry `#C3C2B8`
- service iron `#41484D`
- civic blue-gray `#536979`
- standard brass `#88795E`
- human ochre `#B5844A`
- warning pale-cyan `#99BCBD`

## 6.3 Material identity

Primary:

- old civic stone;
- plaster/repaired masonry;
- dark iron structural/service work;
- brass/bronze mechanisms;
- glass instrument covers;
- painted wood in ordinary housing/service areas;
- paper/board/signage surfaces.

Important distinction:

Cairnspire's monumental fronts may appear standardized, but service layers must reveal accumulated repair, replacement, worker annotation and local improvisation.

## 6.4 Day lighting

Verticality must remain legible.

Use:

- strong top-light separation between terraces;
- reflected light in service lanes;
- atmospheric depth to distinguish stacked districts;
- landmark illumination through open sky rather than glow effects;
- readable interior counters and route spaces.

## 6.5 Night lighting

Cairnspire night identity is a distributed civic network:

- route boards;
- lift landings;
- public counters;
- food stalls;
- service windows;
- maintenance corridors.

The city should look coordinated, not simply densely lit.

## 6.6 Weather

Rain should reveal:

- runoff systems;
- service gutters;
- darker old stone;
- reflective routes without turning the whole city mirror-glossy.

Haze should increase vertical depth separation, not erase landmarks.

## 6.7 Hush relationship

Hush Cairnspire preserves civic geometry but disrupts coordination:

- clocks disagree while each remains locally precise;
- one lift landing is perfectly lit while adjacent service circulation is absent;
- maintenance wear disappears from selected panels;
- repeated queue barriers or counters appear without people;
- far terraces may align too perfectly or fail expected parallax relationships.

Regional palette remains stone/blue-gray/brass; wrongness comes from relation and occupancy.

## 6.8 Post-Stillness / Unringing

After central failure:

- fewer continuous institutional lights;
- warm local-service islands;
- paper maps and handwritten corrections become visually important;
- local mechanical indicators replace synchronized displays;
- repaired civic materials become less uniform.

Unringing should feel more varied but not anarchic.

---

# 7. Rootmere script

## 7.1 Emotional job

Rootmere is a living engineered landscape, not a mystical forest opposed to technology.

## 7.2 Color relationship

**Dominant environment:** deep wet greens and dark teal shadows.  
**Living structure:** bark umber, root gray-brown, moss/lichen olive.  
**Architecture:** warm aged timber and woven plant fiber.  
**Civic accent:** resin amber and muted copper/brass.  
**Human light:** fungal/warm lantern light ranging amber to pale green-gold, never neon.  
**Water:** dark green-brown with controlled sky reflections.  
**Danger contrast:** pale sap/pressure marks, desaturated violet only when canonically justified by Hush/stress.

Directional swatches:

- canopy deep green `#314C3B`
- wet fern `#55715A`
- root umber `#57483D`
- living bark gray `#6C6557`
- resin amber `#B7844B`
- lantern green-gold `#B7B66F`
- dark water `#354B45`

## 7.3 Material identity

Primary:

- living bark/root;
- wet timber;
- woven fiber;
- resin seals;
- iron/brass hardware used selectively;
- clay/ceramic where moisture isolation matters;
- damp stone.

Living materials must not look like generic fantasy organic goo.

They should show:

- growth direction;
- trained/trimmed surfaces;
- repair wrapping;
- grafts;
- tension marks;
- deliberate human accommodation.

## 7.4 Day lighting

Rootmere uses layered canopy light:

- broad soft ambient green;
- controlled warm shafts where canopy opens;
- high local contrast around inhabited clearings;
- water reflections used to support depth, not create visual noise.

Human spaces must remain visually warm enough to separate from wet vegetation.

## 7.5 Night lighting

Night identity relies on sparse inhabited pockets:

- fungal lamps;
- cooking light;
- ferry markers;
- low water reflections.

Do not turn every plant emissive.

## 7.6 Weather

Rain is ordinary here.

Rain treatment should emphasize:

- runoff;
- leaf weight;
- water-channel activity;
- darker bark;
- resin/waxed surfaces behaving differently from untreated fiber.

Fog should hug channels/low ground rather than become an even forest volume.

## 7.7 Hush relationship

Rootmere Hush wrongness should target living relationships:

- one root holds an old growth state beside current growth;
- flexible span motion stops while water continues;
- repair wraps appear before the damage they address;
- fungal light remains while biological surrounding cues are absent;
- bark wear fails to match foot traffic.

Avoid dead-gray “corrupted forest.”

## 7.8 Post-Stillness / Unringing

Stillness must visibly distinguish living and rigid systems.

Unringing emphasizes locally observed states:

- water-height markers;
- root-tension tags;
- ferry condition signals;
- orchard pressure records.

Color remains wet green/amber; the visual story is multiplicity of observation.

---

# 8. Saltreach script

## 8.1 Emotional job

Saltreach must feel exposed, practical and dependent on conditions that never hold still.

It is maritime, but not pirate-coded.

## 8.2 Color relationship

**Dominant environment:** cool sea gray, muted teal, fog blue.  
**Architecture:** salt-bleached timber, dark tarred wood, weathered stone.  
**Industrial material:** iron/bronze with region-specific corrosion.  
**Civic/navigation accent:** fog-signal ochre/orange and chalk/paint white.  
**Human light:** warm low amber behind weather protection.  
**Danger contrast:** pressure red-brown, sharp white spray/fog breaks, dark flooded voids.

Directional swatches:

- sea gray `#61777B`
- fog blue `#8E9FA0`
- muted teal `#456969`
- salt timber `#9A927F`
- tar wood `#3F3B35`
- signal ochre `#C08A3D`
- pressure rust `#8A4F3B`

## 8.3 Material identity

Primary:

- salt-weathered timber;
- tarred/protected wood;
- corroded iron;
- bronze/brass where maintenance allows;
- rope/hemp;
- canvas/oiled cloth;
- wet stone;
- shell/kelp/mineral shoreline surfaces.

Corrosion must follow exposure:

- windward edges;
- joints;
- drainage paths;
- splash zones;
- dissimilar-metal contacts where visually useful.

Do not uniformly rust every metal object.

## 8.4 Day lighting

Saltreach should alternate between:

- high diffuse fog;
- hard broken coastal light;
- bright water/spray highlights;
- dark protected interiors.

Visibility changes should affect composition without making navigation dishonest.

## 8.5 Night lighting

Night identity:

- vertical fog signals;
- harbor condition lamps;
- low tavern/workshop light;
- reflected marker points in water;
- dark stretches between useful signals.

A clear harbor should not glow like a modern port.

## 8.6 Weather

Fog is structural, not a beauty filter.

It should:

- hide/reveal known vertical markers;
- compress horizon depth;
- make local sound/signal infrastructure meaningful;
- preserve foreground route contrast.

Storm states:

- stronger value flattening in distance;
- sharper near-field spray;
- wet materials differentiated by protection/exposure.

## 8.7 Hush relationship

Saltreach Hush may show impossible condition disagreement:

- low-tide architecture exposed beside high-water reflections;
- fog signals active with no fog or absent during dense fog;
- wetness states not matching water contact;
- pressure gauges holding precise but mutually incompatible readings.

Do not replace the sea with glowing void water by default.

## 8.8 Post-Stillness / Unringing

Stillness creates trapped surface states and isolated pressure movement.

Unringing becomes visually richer in local condition markings:

- painted codes;
- chamber-state boards;
- multiple signal authorities;
- practical repairs using mismatched coastal materials.

---

# 9. Emberstep script

## 9.1 Emotional job

Emberstep is about skilled control of dangerous uneven heat, not “lava level.”

## 9.2 Color relationship

**Dominant environment:** black-glass charcoal, warm stone, dusty ash beige.  
**Architecture:** dark mineral/ceramic masses.  
**Heat/foundry:** controlled orange-gold and dull red at real hot zones only.  
**Civic/maker accent:** clay red, stamped light ceramic, traceability marks.  
**Human light:** furnace/reflected warmth and shaded cool interiors.  
**Danger contrast:** white-hot/yellow near extreme heat, deep red-brown warning states; never every furnace neon orange.

Directional swatches:

- black glass `#292B2A`
- warm basalt `#4C4640`
- ash beige `#A79B86`
- clay red `#A85F3F`
- kiln orange `#C7773E`
- hot ceramic `#D2AE7A`
- cooled metal blue-gray `#5B6667`

## 9.3 Material identity

Primary:

- black volcanic glass;
- basalt/heat-fractured stone;
- fired ceramic;
- heavy woven cloth;
- treated leather;
- iron/steel;
- bronze;
- ash/mineral deposits.

Heat wear must be specific:

- color change near exposure;
- glaze shifts;
- oxide bands;
- replaced insulation;
- polished tool contact;
- cracked refractory material where thermal cycling explains it.

## 9.4 Day lighting

Exterior Emberstep:

- hard highland sun;
- deep architectural shade;
- clear dark-ground/light-sky separation;
- controlled heat shimmer only where useful and readable.

Interior foundries:

- warm source pools;
- cool/dark rest zones;
- readable worker silhouettes;
- high contrast without clipping every hot surface to white.

## 9.5 Night lighting

Night should reveal industrial geography:

- vent glow where real;
- kiln doors;
- cooling yards;
- worker lamps;
- dark inactive masses.

The entire city must not become one orange glow.

## 9.6 Weather

Ash/dust:

- collects in low areas and sheltered seams;
- softens distant contrast;
- should not uniformly gray every surface.

Rare wetness should visibly transform ash/glass/ceramic differently and therefore feel notable.

## 9.7 Hush relationship

Emberstep Hush should break heat/time relationships:

- hot color without expected radiant response;
- cooling material retaining old color state;
- maker marks repeating incorrectly;
- one kiln wall simultaneously showing before/after firing material states;
- ash suspended where local motion semantics justify it.

Avoid “purple cursed forge.”

## 9.8 Post-Stillness / Unringing

Post-Stillness emphasizes isolated heat pockets and locally managed production.

Unringing should increase visible provenance:

- maker tags;
- replaced components;
- different local ceramic batches;
- condition boards;
- mixed-state repair materials.

The region becomes less standardized, not less competent.

---

# 10. High Aerie script

## 10.1 Emotional job

High Aerie is defined by exposure, distance, moving air and disciplined adaptation to height.

Its Stillness state must hurt because the ordinary world previously moved.

## 10.2 Color relationship

**Dominant environment:** cold mountain gray, desaturated blue, pale sky.  
**Architecture:** warm gray stone, weathered timber, rope/fiber tans.  
**Civic/monastic accent:** oxidized metal green-gray, archive ochre, restrained warm cloth.  
**Human light:** compact gold/amber interior pockets.  
**Wind/navigation accent:** pale cloth markers and dark rope lines.  
**Danger contrast:** storm slate, sharp white cloud/snow/air breaks, muted warning ochre.

Directional swatches:

- mountain blue-gray `#64747C`
- pale sky `#AAB7B9`
- warm stone `#858078`
- rope tan `#9A8768`
- oxidized metal `#657B75`
- archive ochre `#AF894C`
- human gold `#C49B59`

## 10.3 Material identity

Primary:

- mountain stone;
- weathered timber;
- rope/hemp/fiber;
- canvas/wool;
- iron/bronze hardware;
- wind-worn plaster;
- glass/instrument surfaces in protected areas.

Wear:

- rope polish;
- anchor abrasion;
- windward bleaching;
- ice/water runoff where climate allows;
- repeatedly replaced lashings;
- protected leeward surfaces remaining darker.

## 10.4 Day lighting

High Aerie requires large sky participation.

Use:

- strong atmospheric depth;
- bright sky separation;
- moving cloud shadow where appropriate;
- readable cliff silhouettes;
- warm interior thresholds against cool exterior exposure.

Do not bury the region in permanent storm gloom.

## 10.5 Night lighting

Night:

- sparse cliff settlements;
- wind-kitchen and monastery warmth;
- lift/route markers;
- large dark sky;
- occasional distant civic lights emphasizing scale.

## 10.6 Weather

Wind must be visible through coherent response:

- cloth;
- rope;
- vegetation;
- dust/snow where appropriate;
- cloud movement;
- hanging equipment.

Not every object should flutter independently.

Storm states increase motion and depth compression but preserve route silhouettes.

## 10.7 Hush relationship

High Aerie Hush wrongness is particularly powerful through **absence of expected movement**:

- wind markers still while clouds move;
- rope spans perfectly straight despite load;
- one cloth strip repeats the same bend;
- distant cloud shadow does not correspond to cloud position;
- archive pages remain unnaturally fixed while nearby loose elements move.

## 10.8 Post-Stillness / Unringing

Stillness should visibly remove normal wind behavior from selected systems.

Unringing restores local responsiveness without requiring synchronized motion:

- different wind markers disagree honestly;
- local forecast boards proliferate;
- lift routes publish condition windows;
- repaired ropes/materials become more visibly varied.

---

# 11. Mireglass script

## 11.1 Emotional job

Mireglass uses reflection and memory to create uncertainty without lying to the player about valid routes.

## 11.2 Color relationship

**Dominant environment:** muted reed green, silver-gray water, cool clay.  
**Architecture:** pale reed/fiber, dark wet timber, washed plaster/clay.  
**Civic/domestic accent:** muted rose/rust, amber lanterns, pale painted route marks.  
**Human light:** reflected amber pools rather than broad illumination.  
**Danger contrast:** dark mirror-black water/void values, pale reflected mismatch, restrained violet-gray only where story state needs it.

Directional swatches:

- reed green `#66745E`
- silver water `#87908D`
- wet timber `#4B4940`
- pale fiber `#B9AF94`
- washed clay `#A58F78`
- lantern amber `#BE8C4B`
- mirror dark `#323A39`

## 11.3 Material identity

Primary:

- reeds/fiber matting;
- dark wet timber;
- shallow water;
- clay/plaster;
- glass/mirror surfaces used selectively;
- painted navigation marks;
- light metal/wood ferry hardware.

Reflection surfaces must not all behave alike.

Differentiate:

- clear shallow water;
- disturbed water;
- dark deep water;
- polished intentional mirror surface;
- wet wood;
- actual glass.

## 11.4 Day lighting

Mireglass favors soft directional light with strong horizon/reflection composition.

Use:

- broad sky reflection;
- low horizontal value bands;
- selective warm inhabited interruptions;
- enough directional cue that route geometry remains honest.

## 11.5 Night lighting

Night:

- ferry lamps;
- domestic lantern reflections;
- dark channels;
- sparse raised-path markers.

Reflection may double light composition, but should not double gameplay cues into confusion.

## 11.6 Weather

Mist should create layered horizontal depth.

Rain should break reflection symmetry and therefore visually clarify some spaces rather than only reducing visibility.

Wind should produce local ripple patterns that help reveal real water planes.

## 11.7 Hush relationship

Mireglass Hush can exploit contradictory reflections more than any other region, but must remain authored:

- reflection shows an earlier object arrangement;
- reflected occupant absent/present contrary to Waking surface;
- one house facade reflects a repaired state before repair exists;
- horizon lines repeat at impossible but controlled heights;
- mirror pools retain remembered motion after the surface becomes still.

Never use random kaleidoscope distortion.

## 11.8 Post-Stillness / Unringing

Stillness may make reflections unnaturally stable in selected areas.

Unringing should show civic memory becoming explicit rather than perfect:

- marked safe-memory spaces;
- labeled reflection records;
- local route marks that admit disagreement;
- repaired homes carrying old and new material states visibly together.

---

# 12. Cairnfall script

## 12.1 Emotional job

Cairnfall is a place of observation, measurement and inherited precision machinery—not an empty wizard astronomy ruin.

## 12.2 Color relationship

**Dominant environment:** dry plateau ochre-gray, cool high-altitude shadow, desaturated scrub.  
**Ancient machinery:** pale stone, dark aged metal, oxidized bronze, limited glass.  
**Working civic accent:** chalk white, survey ochre, faded indigo/blue marks.  
**Human light:** warm low lamps in observation/work spaces.  
**Sky:** large clean blue by day, deep dark blue-black at night with strong celestial separation.  
**Danger contrast:** pale cyan precision/resonance cues and dark void gaps, used sparingly.

Directional swatches:

- plateau ochre-gray `#8B806C`
- pale instrument stone `#B6B0A0`
- aged metal `#51565A`
- oxidized bronze `#66776B`
- survey ochre `#B28A4A`
- faded indigo `#55667A`
- precision cyan `#91B6B6`

## 12.3 Material identity

Primary:

- dry plateau stone;
- old precision-cut stone;
- bronze/iron mechanisms;
- glass/lens surfaces;
- chalk/paint survey marks;
- canvas/weather covers;
- timber service pieces.

Wear should emphasize:

- grit in tracks;
- polished calibration points;
- hand contact;
- replacement bearings/pins;
- weather covers protecting sensitive surfaces;
- generations of repurposed components.

## 12.4 Day lighting

Daylight is clear and spatially honest:

- strong sky;
- long instrument shadows;
- broad plateau visibility;
- distant haze separating broken landforms;
- bright exposed surfaces balanced against dark mechanism interiors.

## 12.5 Night lighting

Night is one of Cairnfall's identity states, not merely a darker daytime level.

Use:

- restrained work lamps;
- readable silhouettes against sky;
- astronomical instruments visible through shape and rim/value rather than glow;
- celestial field with enough clarity to justify public observation culture.

No magical star projector aesthetic by default.

## 12.6 Weather

Dust:

- reveals wind direction;
- settles in instrument seams/tracks;
- softens distant plateau edges.

Cloud cover should materially change observation lighting and social behavior without erasing the region's instrument silhouettes.

## 12.7 Hush relationship

Cairnfall Hush should disrupt measurement relationships:

- shadows indicate a celestial angle inconsistent with visible sky;
- instrument rings align to different valid historical states;
- chalk calibration marks appear in mutually exclusive positions;
- one lens reflects a sky condition not presently visible;
- repeated arcs imply more than one observation axis.

Avoid generic cosmic nebula effects.

## 12.8 Post-Stillness / Unringing

Post-Stillness should show manual observation regaining importance.

Unringing visual language:

- layered raw readings;
- local annotation;
- multiple calibration marks preserved instead of erased;
- practical covers/repairs from distributed teams;
- public observation spaces active again.

---

# 13. Hush Cairnspire / Still-Cairn / Null Meridian late-state script

This section defines continuity only. The full Hush Visual Production Matrix remains a later work item.

## 13.1 Principle

Late spaces must remain related to the world the player already knows.

They may become stranger, but they cannot abandon Stillring's material language for an unrelated abstract “final level.”

## 13.2 Hush Cairnspire

Carry forward:

- Cairnspire stone/blue-gray/brass ancestry;
- civic geometry;
- familiar service architecture.

Transform through:

- impossible correspondence;
- missing occupancy;
- preserved older wear states;
- contradictory lighting directions;
- selectively repeated civic modules;
- local warm memory fragments that do not behave like ordinary active rooms.

## 13.3 Still-Cairn

Still-Cairn must feel like preservation becoming imprisonment.

Use:

- unnaturally complete material states;
- repaired/familiar spaces lacking ordinary change;
- light held too stable;
- absence of dust/motion where Waking life would create it;
- emotional familiarity rather than “corrupted dungeon” treatment.

## 13.4 Null Meridian

Null Meridian should synthesize game-wide material ancestry:

- civic stone;
- precision metal;
- brass/bronze resonance hardware;
- service access;
- old repairs;
- regional interventions visible where canon brings them together.

The finale may become visually severe, but should not default to black void + neon magic.

The final visual conflict is **forced singular order versus living plurality**, not light versus darkness.

---

# 14. Character/environment separation rules

Character palettes from `docs/158` are designed to remain readable across regions.

Environment/lighting must preserve principal-character readability by value/material separation, not spotlighting every dialogue scene.

Examples:

- Neris's slate-blue jacket must not disappear into Cairnspire blue-gray; preserve local value/edge separation.
- Tessa's storm teal must remain distinct in Saltreach through material/value and route-ochre accents.
- Sena's kiln-charcoal/clay palette must separate from Emberstep backgrounds using skin, ceramic protection, silhouette and controlled rim/source light.
- Caldrin's wind gray requires archive cream/ochre and silhouette support in High Aerie.

Do not recolor principal costumes region by region merely to solve poor environment hierarchy.

---

# 15. Enemy/boss separation rules

Enemy/boss art from `docs/159` must remain readable without forcing every hostile element into one danger color.

Environment lighting must preserve:

- attack silhouette;
- weak-point readability where canon requires;
- locomotion direction;
- scale;
- state transition;
- boss/arena separation.

Boss arenas inherit regional scripts unless the encounter contract explicitly requires a bounded override.

A boss does not get a generic red-violet “boss LUT.”

---

# 16. Before / after comparison requirements

Each major region must receive production frames for at least:

1. ordinary Waking daytime;
2. ordinary inhabited evening/night;
3. representative weather;
4. Grand Ring/Stillness consequence;
5. changed-world active pocket;
6. Unringing or epilogue state;
7. Hush pairing where canon requires it.

The comparison should make specific changes readable while retaining location identity.

Reject a changed-state treatment if a screenshot could be mistaken for another region.

---

# 17. Required regional visual-development package

For each region, concept/lighting production must eventually deliver:

- one palette/value script sheet;
- one material family sheet;
- one ordinary-life lighting key;
- one night key;
- one representative weather key;
- one Stillness/change key;
- one Unringing/epilogue key;
- one Hush key where required;
- one gameplay-readability reduction showing traversal/interaction contrast without UI;
- one landmark thumbnail comparison under at least three states.

These are execution artifacts derived from this authority. They do not reopen the scripts.

---

# 18. Acceptance gate — Regional Visual Script A

This documentation gate passes when every major region has a stated:

- dominant environment family;
- structural/material family;
- civic/work accent;
- human-light identity;
- daylight hierarchy;
- night identity;
- weather behavior;
- Hush transformation principle;
- post-Stillness/Unringing behavior;
- explicit failure mode.

Under this file:

- Brindle — **PASS**;
- Cairnspire — **PASS**;
- Rootmere — **PASS**;
- Saltreach — **PASS**;
- Emberstep — **PASS**;
- High Aerie — **PASS**;
- Mireglass — **PASS**;
- Cairnfall — **PASS**;
- late Hush/Still-Cairn/Null continuity — **PASS AT DIRECTION LEVEL**.

This closes the missing **written regional color/material/lighting script authority**.

It does not constitute rendered proof.

---

# 19. What remains open after this document

Legitimate remaining dependencies:

- Hush H0–H5 production matrix across content families;
- VFX production manifest;
- rendered Board 02/04/05/06 execution artifacts;
- exact exposure/light/fog values;
- exact material/shader implementation;
- target-platform material/lighting budgets;
- representative runtime readability proof;
- performance evidence;
- final scalability tiers.

The studio may tune implementation to satisfy measured runtime constraints later.

It may not replace these regional identities with generic presets because that is cheaper.

---

# 20. Governing test

For any regional lighting/material/color decision, ask:

1. Would the region still be recognizable in grayscale?
2. Does weathering follow real use/exposure?
3. Is human life visible before catastrophe?
4. Is night a regional identity rather than “day scene with exposure lowered”?
5. Does the Hush preserve place identity while changing relationships?
6. Does post-Stillness treatment show specific consequences rather than generic destruction?
7. Are traversal, hazards, characters and interactables readable without spectacle lighting?
8. Are we using color to support information rather than replace shape/value information?
9. Does the material system look maintained as well as aged?
10. Would this still look like Stillring if the engine's fanciest rendering feature were disabled?

If not, the visual treatment is not production-ready.
