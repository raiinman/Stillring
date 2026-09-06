# 156 — Art Production Manifest Framework

**Status:** ACTIVE / PRE-PRODUCTION FRAMEWORK  
**Parent:** `docs/154_STILLRING_ART_BIBLE.md`  
**Purpose:** translate visual doctrine into estimateable character, environment, prop, VFX, and region production work without inventing runtime budgets or unapproved final designs.

---

# 1. Why this file exists

An Art Bible can explain what Stillring should look like and still leave a studio unable to quote the work.

This framework defines the production inventory structure required to turn visual authority into staffable deliverables.

It directly addresses the art-production gaps listed in `docs/152_STUDIO_HANDOFF_GAP_REGISTER.md`:

- `SH-ART-001` Neris production specification;
- `SH-ART-002` named-character visual bible;
- `SH-ART-003` NPC population strategy;
- `SH-ART-004` enemy/boss visual taxonomy;
- `SH-ART-005` modular environment standards;
- `SH-ART-006` regional color/material/lighting bibles;
- `SH-ART-007` Hush production grammar;
- `SH-ART-008` VFX language;
- `SH-ART-009` region asset manifests;
- `SH-ART-010` world-scale/reference metric sheet.

This file is a framework, not permission for an agent or studio to invent missing owner-facing final character designs.

---

# 2. Production status vocabulary

Every art deliverable must carry one status:

- **CANON REQUIREMENT** — the asset/content need is mandatory because current game/story authority requires it.
- **DIRECTIONAL** — visual solution is bounded but not final.
- **CONCEPT REQUIRED** — design question needs concept work before production modeling.
- **PROTOTYPE SUBSTITUTE ALLOWED** — final art may be temporarily represented by graybox/proxy content.
- **FINAL PRODUCTION** — approved for final-quality creation after relevant gates.
- **TBD OWNER** — genuine visual/product decision requires owner review.
- **TBD RUNTIME** — cannot be finalized honestly before representative runtime/performance evidence.
- **HISTORICAL / SUPERSEDED** — do not produce from this entry.

---

# 3. Asset uniqueness classes

To prevent uncontrolled bespoke production, every asset family must be classified.

## U0 — Shared universal

Reusable broadly across the game.

Examples:

- generic fastening/joinery families;
- common neutral debris where culturally appropriate;
- base interaction readability components;
- shared technical helper meshes not visually identity-bearing.

## U1 — Regional kit

Reusable across one major region/culture.

Examples:

- wall/roof/floor modules;
- region doors/windows;
- bridge pieces;
- civic furniture;
- storage/work props;
- route markers;
- region foliage/rock families.

## U2 — Regional hero

Unique or near-unique high-identity assets that define a region or major space.

Examples:

- dominant landmark;
- named civic machine;
- dungeon entrance;
- hero bridge/lift;
- major social-space centerpiece.

## U3 — Game hero

Signature game-wide asset.

Examples:

- Neris;
- Cantor Key;
- critical named character signature kit;
- major Waybell forms;
- Line Skiff hero vehicle;
- unique finale machinery.

## U4 — One-off narrative / finale

Bespoke content justified by canonical narrative or mechanical importance.

Requires explicit production rationale because these assets have low reuse.

---

# 4. Quality tiers

Uniqueness and quality are separate.

Use these quality tiers:

## Q0 — Proxy / graybox

Purpose:

- prove scale;
- route;
- gameplay readability;
- camera;
- interaction placement.

May use primitive geometry and neutral materials.

## Q1 — Directional blockout

Adds:

- recognizable silhouette;
- basic material family;
- regional proportion;
- rough color hierarchy.

Still disposable.

## Q2 — Representative production direction

Used for vertical-slice proof.

Must demonstrate:

- final-direction shape language;
- believable material treatment;
- representative texture/detail density;
- lighting interaction;
- state readability;
- appropriate collision/interaction boundaries;
- scalable production approach.

## Q3 — Final production target

Requires:

- approved concept/design;
- final source asset organization;
- final material/texture treatment within later technical budgets;
- collision/interaction validation;
- LOD/Nanite/streaming solution as selected by technical production;
- naming/package compliance;
- Waking/Hush variants where required;
- accessibility/readability checks;
- final provenance/source records.

No file is Q3 merely because it is high resolution.

---

# 5. Character manifest schema

Every hero or recurring named character entry must contain:

## Identity

- canonical name;
- narrative role;
- age range where canon defines it;
- home/region;
- occupation;
- recurring locations/states;
- Waking/Hush/post-Stillness burden.

## Silhouette

- primary read at gameplay distance;
- body/build direction;
- costume massing;
- hair/head shape;
- signature carried/worn object;
- forbidden silhouette confusion with another major character.

## Costume construction

- garment layers;
- practical purpose;
- climate response;
- occupation response;
- closures/fasteners;
- footwear;
- work protection;
- social-status cues;
- repair/wear logic.

## Material palette

- primary materials;
- secondary materials;
- limited accents;
- state/weather behavior;
- contamination/damage limits.

## Gameplay requirements

- animation range;
- hand/tool contact needs;
- swimming/traversal requirements where relevant;
- equipment attachment points;
- cinematic close-up expectation;
- gameplay readability distance.

## Variants

- pre/post catastrophe;
- travel/work state;
- injury/dirt state where canon requires;
- Hush state where required;
- epilogue state where required.

## Decision rights

For every unresolved visual detail label:

- LOCKED;
- STUDIO CHOICE WITHIN BOUNDS;
- OWNER REVIEW;
- RUNTIME/TUNING.

---

# 6. Neris production manifest — current bounded authority

**Status:** CANON REQUIREMENT / CONCEPT REQUIRED BEFORE FINAL MODEL

Canonical facts already available:

- seventeen-year-old apprentice bellwright;
- from Brindle;
- mechanically gifted;
- practical field identity;
- not royal, chosen, prophesied, reincarnated, or secret magical nobility;
- signature relationship to the Cantor Key comes through field work/calibration circumstance;
- full locomotion/traversal/combat/tool animation burden is substantial;
- equipment growth reflects learned capability rather than loot-tier fashion escalation.

Required visual outcomes:

- reads as a working apprentice before reading as an action hero;
- silhouette accommodates climbing, mantle, ladder, surface swim, combat, tool use, and later traversal equipment;
- clothing supports physical work and repeated repair;
- no ornamental crown/royal/prophecy coding;
- no generic leather-armored fantasy assassin silhouette;
- no oversized anime weapon language;
- no photoreal scan dependency;
- hands/tool relationship remain readable;
- Cantor carry/holster solution must be visually credible and animation-safe;
- later progression adds functional layers/gear rather than replacing identity with a final-form costume.

Still unresolved and requiring concept/owner review before final production:

- face;
- hair;
- exact body build;
- exact palette;
- specific garments;
- footwear design;
- Brindle apprentice marks/signage if any;
- final Cantor attachment/holster.

No agent may close those by genre convention.

---

# 7. NPC population manifest schema

Each region must define population families rather than only named characters.

Required population categories:

- labor/work roles;
- civic/administrative roles;
- transport/route roles;
- food/service roles;
- youth/elder representation where story population supports it;
- travelers/outsiders;
- emergency/post-Stillness states.

Variation system must identify:

- shared body/skeleton strategy subject to Animation Bible;
- head/face variation approach;
- hair/headwear families;
- garment layer pool;
- palette family;
- occupational props;
- wear/repair variants;
- region-specific pieces;
- reuse limits across regions.

Rule:

> Region identity comes from coherent systems, not six completely separate human species of costume design.

---

# 8. Enemy / boss manifest schema

Every enemy family entry must define:

- region/ecological/mechanical origin;
- silhouette class;
- locomotion class;
- attack reach/readability;
- defense/armor read;
- Hush relationship;
- gameplay-critical VFX;
- material family;
- damage/read state;
- reuse/variant plan;
- animation burden;
- audio dependency;
- encounter regions;
- optional elite relation.

Boss entries additionally require:

- one-sentence visual identity;
- scale relative to Neris;
- arena/region relationship;
- region mechanic represented visually;
- unique geometry/material burden;
- bespoke VFX burden;
- cinematic close-up requirement;
- transition/state variants;
- reuse prohibition or justified reuse plan.

Bosses may not become disconnected monster-design portfolio pieces.

---

# 9. Environment kit manifest schema

Every major region requires a modular environment manifest containing:

## Natural kit

- terrain/ground families;
- rock/geology families;
- foliage families;
- water/shoreline families;
- atmospheric support assets.

## Architecture kit

- structural module families;
- floor/roof/wall supports;
- doors/windows;
- stairs/ramps;
- bridges/walkways;
- railings/barriers;
- columns/arches where culturally appropriate;
- trim/joint language;
- damage/repair variants.

## Civic kit

- lighting fixtures;
- signs/markers;
- storage;
- seating;
- cooking/heating;
- maintenance;
- tools;
- freight;
- route infrastructure;
- local machinery.

## Gameplay kit

- traversal affordance structures;
- ladders;
- ledge/handhold language where authored;
- puzzle mounts;
- Cantor-compatible machinery;
- hazards;
- destructible/reactive elements where canon requires.

## Hero assets

- dominant landmark;
- major social space;
- dungeon/domain identity pieces;
- Waybell/critical civic machine;
- region-specific story assets.

## State variants

- Waking;
- Hush;
- post-Grand-Ring/Stillness;
- post-local-resolution where required;
- epilogue/Unringing where required.

---

# 10. Modular production rules

Exact metric grid dimensions are not yet locked because final character dimensions, camera, traversal tuning, and technical production evidence remain dependencies.

However, modular kits must obey these rules now:

- snap logic must be predictable;
- modules must support authored traversal rather than accidentally implying free climbing;
- repeated pieces must not produce obvious copy-paste rhythm in hero views;
- kit boundaries should align with believable construction joints;
- modularity may not erase region-specific silhouette;
- hero structures may break the kit when identity justifies it;
- collision proxy intent must be planned during blockout, not after art completion;
- path widths, doorway clearances, stairs, ledges, ladders, and interactable reach must ultimately derive from gameplay authority and tested Neris scale, not arbitrary environment-art tradition.

Numeric scale sheet remains `TBD RUNTIME / CHARACTER SCALE` until the relevant representation exists.

---

# 11. Regional production manifest starter

The following entries establish required art-production families without pretending final asset counts are known.

## Brindle

Core role:

- Neris's ordinary home;
- apprentice bellwright identity;
- emotional before-memory;
- opening breach;
- later return/change;
- epilogue closure.

Required art families:

- village residential/work kit;
- bellwright workshop/shed hero kit;
- local Waybell/resonance infrastructure;
- ordinary road/agricultural/utility props as canon supports;
- Vale-family domestic objects;
- pre-crisis warm lived state;
- breach/Hush consequences;
- later adaptation state;
- epilogue repair state.

Art failure to avoid:

Brindle must not look like a disposable tutorial village. It must visually justify why returning matters.

## Cairnspire

Core visual premise:

- vertical capital built around dormant central bell infrastructure;
- institutional density;
- old public systems still embedded in daily life;
- social and archival spaces rather than only monumental government architecture.

Required families:

- vertical civic kit;
- Bellwarden/Public Bell Office identity;
- Route House;
- Lower Archive;
- central tower/Waybell landmark views;
- maintenance/service circulation;
- pre/post Grand Ring state;
- Hush-Cairnspire relation;
- Still-Cairn/late unique burden handled separately.

## Rootmere

Core visual premise:

- wet woodland;
- root bridges;
- old bell-oaks;
- fungal lanterns;
- human life integrated with living root systems.

Shape language:

- vertical trunks;
- large curved roots;
- enclosed canopy;
- warm inhabited pockets;
- layered wet ground/water channels.

Required families:

- giant-root natural kit;
- wet woodland kit;
- root-bridge traversal kit;
- ferry infrastructure;
- bell-oak hero assets;
- fungal light family;
- Root Cathedral identity;
- water-routing mechanisms;
- Waking/Hush paired burden;
- post-resolution changes.

## Saltreach

Core visual premise:

- wind-beaten fishing coast;
- tidal caves;
- drowned industrial history;
- working fog-signal culture.

Shape language:

- long horizontal coastlines interrupted by vertical signals;
- tide-height bands;
- exposed wind profiles;
- heavy machinery meeting water.

Required families:

- coastal settlement kit;
- docks/moorings;
- fog signals;
- tidal cave geology;
- drowned industrial machinery;
- pressure/pipe families;
- Tide Foundry hero kit;
- corrosion/weather treatment;
- Hush/water-state variants.

## Emberstep

Core visual premise:

- black-glass badlands;
- geothermal vents;
- kiln-cities;
- ash caravans;
- visible maker culture.

Shape language:

- diagonals and terraces;
- hard sunlight;
- vent columns;
- kiln masses;
- dark ground against controlled furnace warmth.

Required families:

- black-glass/geothermal geology;
- kiln-city structural kit;
- foundry work props;
- maker marks;
- molds/cooling/heat mechanisms;
- caravan/route assets;
- Kiln of Names hero kit;
- heat-state material/VFX families;
- Hush/post-Stillness state.

## High Aerie

Core visual premise:

- mountain terraces;
- rope lifts;
- wind organs;
- cliff monasteries;
- life adapted to exposure and vertical travel.

Shape language:

- strong diagonals;
- long vertical drops;
- suspended lines;
- sparse exposed silhouettes;
- monumental sky/background share.

Required families:

- mountain geology;
- terrace kit;
- lift/rope infrastructure;
- wind span/bridge kit;
- Wind Kitchen ordinary-life space;
- wind organ machinery;
- monastery kit;
- Tempest Belfry hero assets;
- post-Stillness changed familiar state;
- wind VFX/readability family.

## Mireglass

Core visual premise:

- reflective marsh;
- reed palaces;
- mirrored pools;
- deceptive horizons;
- memory/reflection themes expressed spatially without dishonest gameplay.

Shape language:

- low horizontals;
- reflection symmetry;
- interrupted vertical reeds;
- raised paths;
- controlled sightline ambiguity.

Required families:

- marsh/water/reed kit;
- raised walkways/ferries;
- Lantern Ferry identity;
- reed-palace structural kit;
- mirrored-pool materials/lighting;
- Palace Under Reeds hero assets;
- reflection-state gameplay readability support;
- Hush/memory-related variants.

## Cairnfall

Core visual premise:

- ancient astronomical works sunk into a broken plateau;
- public observation culture before catastrophe;
- old precision machinery repurposed across generations.

Shape language:

- broken circles/arcs;
- monumental instrument silhouettes;
- plateau gaps;
- long sightlines;
- fallen alignment axes.

Required families:

- plateau geology;
- astronomical-mechanism kit;
- public observation structures;
- repurposed ancient machinery;
- Fallen Orrery hero kit;
- phase/alignment mechanism family;
- Hush/seam-mode burden;
- late-game changed-state variants.

## Null Meridian

Core visual premise:

- finale synthesis space;
- central authority made physical;
- must feel like the culmination of Stillring's own visual grammar rather than a separate fantasy universe.

Required families:

- Quiet Court identity;
- Meridian Bell/central machinery;
- paired/synthesis spaces for S1–S6;
- worker layer;
- archive space;
- Maelor confrontation space;
- Listener-related presentation;
- final decommission state.

Rule:

No new decorative art language should appear solely because it is the finale. Finale spectacle must recombine established Stillring forms, materials, resonance logic, and state relationships.

---

# 12. Prop manifest schema

Every prop family should identify:

- owner/user;
- purpose;
- region;
- material family;
- size class;
- interaction state;
- animation need;
- physics need;
- destruction need;
- Waking/Hush variant;
- damage/wear variants;
- uniqueness class;
- quality tier;
- audio/VFX dependency;
- semantic ID need if gameplay/stateful.

Decorative props do not require semantic identity unless gameplay/save/world-state authority needs it.

---

# 13. Signage / inspection / maker-mark manifest

Stillring requires coherent world markings because repair, maintenance, route work, records, and institutional history matter.

Families to define:

- Bellwarden inspection language;
- local maker marks;
- route/freight marks;
- hazard marks;
- maintenance annotations;
- archive labeling;
- foundry traceability;
- emergency/post-Stillness markings;
- local informal modifications.

Each family must define:

- who uses it;
- where;
- purpose;
- visual complexity;
- whether literacy is required;
- whether it carries gameplay information;
- accessibility redundancy when gameplay-critical.

Do not invent decorative runes simply to make surfaces look fantasy-like.

---

# 14. Hush variant burden classification

Every environment/prop family must classify Hush production burden as one of:

- **H0 — unchanged:** same production asset/state is semantically correct;
- **H1 — material/light variant:** geometry remains shared but state changes materially;
- **H2 — dressing/occupancy variant:** base geometry shared; placement/props/population/motion change;
- **H3 — geometry-state variant:** meaningful geometry relationship changes;
- **H4 — related-distinct:** Hush counterpart is recognizably related but requires substantial separate production;
- **H5 — unique Hush-only:** justified by canonical content.

The goal is to make paired-world production burden estimateable without assuming every asset needs a duplicate.

---

# 15. VFX manifest schema

Every VFX family must declare:

- class: gameplay-critical / state-communication / decorative;
- triggering system;
- duration/lifetime;
- visibility distance;
- overdraw/density concern for later technical review;
- color-independent cue;
- audio/controller redundancy where applicable;
- Hush variant;
- reduced-effects accessibility/scalability behavior;
- whether effect can obscure combat/player silhouette;
- ownership of semantic state.

VFX presents state; it must not silently become the only owner of gameplay state.

---

# 16. Art review gates

## Gate A — Doctrine compliance

Question:

Does the concept clearly belong inside `docs/154_STILLRING_ART_BIBLE.md`?

## Gate B — Silhouette / massing

Question:

Does it work before textures and polish?

## Gate C — Gameplay integration

Question:

Does it support camera, movement, interaction, combat, puzzle, and accessibility requirements?

## Gate D — Production feasibility

Question:

Can the approach be reproduced across required volume without hero-asset treatment everywhere?

## Gate E — Representative runtime evidence

Later only.

Question:

Can the approved direction hit target hardware/performance while preserving visual priorities?

## Gate F — Final art acceptance

Later only.

Question:

Does the finished asset preserve doctrine, state burden, quality target, provenance, and technical constraints?

Human review remains authoritative for visual quality and emotional effect.

---

# 17. Current unresolved art decisions

The following are intentionally not invented in this framework:

- final Neris face/body/costume palette;
- final named-character visual designs;
- exact NPC body/head reuse counts;
- final texture-resolution families;
- final polygon/triangle targets;
- final material-slot budgets;
- Nanite/Lumen/renderer mandate;
- exact modular grid dimensions;
- exact prop counts by region;
- final foliage density;
- final VFX performance budgets;
- final render resolution/framerate matrix.

These are split between future owner concept review, animation/technical dependencies, studio-choice implementation, and later runtime/performance evidence.

Unknown is acceptable.

Silent assumption is not.

---

# 18. Next art-production documents

To finish the Art workstream under the Studio Handoff Closure program, create and review:

1. **Character Production Manifest** — Neris + named cast + NPC population families.
2. **Enemy / Boss Art Manifest** — all enemy families, elites, bosses, regional distribution.
3. **Regional Environment / Prop Manifest** — one detailed section per major region and finale space.
4. **Scale and Readability Sheet** — after Neris/camera/traversal representation provides honest metrics.
5. **Regional Color / Material / Lighting Scripts** — detailed palette/state rules.
6. **Hush Visual Production Matrix** — H0–H5 classifications by region/content family.
7. **VFX Production Manifest** — tied to gameplay/state/a11y requirements.
8. **Visual Board Set 02–06** from `docs/155_ART_REFERENCE_METHOD_AND_BOARD_INDEX.md`.

Do not begin mass art production merely because this framework exists.

---

# 19. Final production maxim

> **Build a world from reusable rules; spend uniqueness where memory, gameplay, and story justify it.**