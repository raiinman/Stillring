# 154 — Stillring Art Bible

**Status:** ACTIVE / OWNER-APPROVED VISUAL DIRECTION / DOCUMENTATION-ONLY PRE-PRODUCTION  
**Updated:** 2026-09-05  
**Parent program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Closes toward:** `SH-ART-001`–`SH-ART-010` in `docs/152_STUDIO_HANDOFF_GAP_REGISTER.md`  
**Runtime boundary:** no UE5.8 implementation, art production, performance proof, or final asset-budget lock is authorized by this document.

---

# 1. Authority and relationship to earlier visual notes

This document is the production-facing visual authority for Stillring.

The repository remains the source of truth. Chat history, generated images, external artwork, mood boards, model memory, and Unreal editor experiments do not override this file.

`docs/01_GAME_VISION.md` remains authoritative for the high-level goal of **N64-era readability filtered through modern production discipline**. This document clarifies what that phrase means for final art direction:

> **N64-era readability is a design-lineage target, not a requirement to reproduce 1998 rendering limits.**

Therefore:

- strong silhouettes remain required;
- controlled texture/material complexity remains required;
- compositional fog remains useful;
- regional color scripting remains required;
- visual clutter remains prohibited;
- literal low-poly geometry, tiny textures, deliberately low internal resolution, retro filtering, or period-accurate material limits are **not** automatically final-production requirements.

Where an older visual shorthand can be read as requiring literal retro rendering, this Art Bible controls production interpretation.

The visual target is:

# PLAYABLE FANTASY ILLUSTRATION

A believable three-dimensional fantasy world composed with the selectivity, shape control, atmosphere, color hierarchy, and landmark discipline of strong fantasy illustration.

Stillring should feel painted in its **decisions**, not filtered to look like a painting.

---

# 2. Core visual thesis

Stillring is not trying to prove that Unreal Engine can reproduce reality.

It is trying to make places the player can:

1. read;
2. navigate;
3. remember;
4. care about;
5. recognize after they change.

Every major visual decision should answer:

> **What should the player notice, understand, remember, or feel here?**

Graphical fidelity is subordinate to that answer.

Stillring is:

- grounded enough that materials and structures feel physically credible;
- stylized enough that silhouette, color, scale, and composition can override strict realism;
- mature without defaulting to grimdark;
- beautiful before it becomes damaged or melancholy;
- visually rich without becoming visually noisy;
- cinematic in composition without becoming a movie that happens to be interactive.

Stillring is **not**:

- photoreal medieval simulation;
- cel-shaded or anime-coded by default;
- a cartoon aesthetic;
- a generic Unreal dark-fantasy demo;
- a Zelda visual reskin;
- a permanent mud/gray/brown palette;
- a material-scan showcase;
- an excuse for every surface to contain maximal micro-detail;
- a particle-effects showcase.

---

# 3. Priority stack

When visual priorities conflict, use this order:

1. **Gameplay readability**
2. **Emotional intent**
3. **Location identity**
4. **Composition and navigation**
5. **Silhouette**
6. **Lighting**
7. **Color hierarchy**
8. **Animation/readable motion**
9. **Material treatment**
10. **Fine surface detail**

A technically impressive lower-priority treatment must be simplified when it damages a higher-priority goal.

Examples:

- physically correct exposure loses to readable traversal;
- extra geometric detail loses to landmark silhouette;
- photoreal grime loses to material hierarchy;
- decorative VFX loses to attack/puzzle readability;
- dense foliage loses to navigable route composition.

---

# 4. The Stillring recognition test

A major location is not visually approved merely because it is attractive.

A major region, settlement, dungeon, or landmark must survive at least four recognition reductions:

## 4.1 Silhouette test
Could the location still be distinguished when reduced to major dark/light masses?

## 4.2 Thumbnail test
Could a player identify the place from a small screenshot without UI text?

## 4.3 Palette test
Does the region retain a recognizable dominant color relationship without relying on one prop or costume?

## 4.4 Landmark test
Can the player describe the location with one strong spatial idea?

Examples of acceptable one-sentence identities:

- a village threaded through colossal living roots;
- a coast organized around fog signals and drowned machinery;
- a kiln culture built into black-glass geothermal terraces;
- a mountain society connected by lifts, wind spans, and vertical monasteries;
- a reflective marsh whose architecture and horizon lines deliberately confuse depth;
- an astronomical plateau broken around monumental fallen instruments.

If the only description is “fantasy forest,” “medieval town,” or “ancient ruins,” the visual identity is not production-ready.

---

# 5. Shape before surface

Large forms define Stillring before texture detail does.

Every region requires a documented shape language covering:

- dominant directional lines;
- vertical versus horizontal emphasis;
- large natural forms;
- architectural massing;
- path/bridge/threshold rhythm;
- skyline profile;
- negative-space behavior;
- repeated civic/mechanical forms;
- Waking/Hush relationship.

Surface detail cannot rescue weak massing.

A region that looks distinct only because its textures changed has failed art direction.

---

# 6. Geography: believable, then intentionally exaggerated

Stillring uses believable geography as a base and bends scale when it serves memory, navigation, gameplay, or emotional effect.

Acceptable exaggerations include:

- trees much larger than ordinary species;
- unusually deep valleys;
- dominant waterfalls;
- oversized natural arches;
- monumental cliffs;
- improbable but legible mountain profiles;
- unusual celestial scale;
- dramatic elevation layering;
- architecture built into natural structures at scales that create clear visual identity.

Exaggeration must have a job.

A large form should ideally do at least two of the following:

- orient the player;
- create anticipation;
- define a region;
- hide/reveal a route;
- host traversal;
- frame architecture;
- show cultural adaptation;
- provide a story-state comparison before/after catastrophe.

“Because it looks epic” is not enough on its own.

---

# 7. Settlement doctrine — fantasy with roots

Settlements must appear to have grown from their environment rather than having a generic medieval kit dropped onto a biome.

For every settlement, production must answer:

1. Why did people build here?
2. What local resource or route made the location useful?
3. What local danger shaped construction?
4. What weather problem shaped roofs, paths, drainage, heating, or shelter?
5. How do people move goods through the place?
6. What civic machinery exists here?
7. What visual feature would a resident use when giving directions?
8. How does ordinary life visibly continue when the player is not solving a quest?

Architecture should show consequences of place.

Examples:

- Rootmere construction may bridge roots, lift walkways above wet ground, reuse living wood carefully, and cluster around bell-oak infrastructure.
- Saltreach structures may organize around tide height, wind, corrosion, fog signaling, mooring, and pressure machinery.
- Emberstep construction may privilege shade, heat control, ceramics, metalwork, vents, and traceable maker culture.
- High Aerie must visibly solve vertical movement, wind exposure, rope/lift maintenance, food storage, and cliff access.
- Mireglass should use reflected sightlines, raised access, reeds, shallow-water structures, and visual depth uncertainty without making navigation dishonest.
- Cairnfall should incorporate fallen astronomical works into present-day practical life rather than treating the entire region as an empty archaeology set.

---

# 8. Architecture must function

Fantasy is not permission for nonfunctional architecture.

Buildings should generally imply credible:

- entrances;
- structure/support;
- roof/drainage behavior;
- storage;
- heat/fire control;
- water access;
- food preparation;
- work areas;
- service access;
- public/private space;
- circulation between major levels.

Not every wall requires engineering simulation. The objective is **inhabited logic**.

The player should feel that people live and work here, not that an environment artist assembled a photograph backdrop.

---

# 9. Detail hierarchy

Stillring uses selective detail.

## Tier A — Hero / story-critical

Highest authored detail and strongest material specificity.

Examples:
- Cantor Key;
- named character signature props;
- Waybell mechanisms;
- central monuments;
- story-critical machinery;
- boss-specific structures;
- finale objects.

## Tier B — Gameplay-critical

Clear shape and contrast, moderate detail, strong state readability.

Examples:
- traversable structures;
- puzzle mechanisms;
- interactable machinery;
- danger surfaces;
- tool targets;
- route-changing devices.

## Tier C — Regional identity

Reusable but distinctive kit elements that establish culture and place.

Examples:
- doors/windows;
- civic fixtures;
- bridges;
- railings;
- lanterns;
- carts;
- workbenches;
- storage families;
- region-specific construction joints.

## Tier D — Background support

Quiet texture/material treatment. Supports depth without demanding attention.

## Tier E — Distant silhouette

Shape first. Fine surface detail should not be the reason the asset exists.

Rule:

> **Detail rewards attention; it does not demand attention.**

---

# 10. Materials

Materials must be believable without becoming photographic demonstrations.

Stone should read as stone, wood as wood, metal as metal, cloth as cloth, glass as glass, water as water.

However, final material treatment should use deliberate simplification and hierarchy.

Avoid automatic accumulation of:

- scratches;
- grime decals;
- high-frequency roughness noise;
- edge wear;
- fingerprints;
- meaningless cracks;
- excessive normal-map chatter;
- repeated dirt overlays.

Weathering must tell a production or world story:

- water runoff belongs where water runs;
- corrosion belongs where salt or chemistry creates it;
- polish belongs where hands/tools repeatedly touch;
- soot belongs near relevant combustion;
- damage belongs where an event or work process explains it.

Do not use “more weathered” as a synonym for “more finished.”

---

# 11. Color scripting

Stillring does not surrender color in exchange for maturity.

Each region requires a controlled color script with:

- dominant environment family;
- secondary structural family;
- material neutrals;
- civic/identity accent;
- danger accent;
- Hush transformation behavior;
- night behavior;
- weather behavior;
- gameplay-critical exceptions.

Vision-level emotional relationships:

- **safety / lived settlement:** warm amber and human light;
- **mystery:** emerald, teal, or region-specific cool depth;
- **sacred / precise resonance:** pale cyan or other restrained cool signal;
- **danger:** desaturated violet, dark crimson, or intentionally unstable warm/cool contrast;
- **travel at dusk:** warm gold against deep blue;
- **Hush:** not one global purple/blue filter; see Section 15.

Color cannot be the only carrier of critical gameplay information.

---

# 12. Lighting

Stillring uses believable lighting behavior but does not treat photographic correctness as the final authority.

Lighting must serve:

- focal hierarchy;
- route readability;
- emotional state;
- character readability;
- region identity;
- before/after comparison;
- gameplay affordances.

Intentional exaggeration is allowed where useful:

- warmer firelight;
- cooler moonlight;
- stronger shafts through canopy;
- visible atmospheric separation;
- controlled interior pools of light;
- shaped shadow masses;
- stronger foreground/background value separation.

A physically correct scene that obscures valid traversal or important combat information is visually incorrect.

Exact renderer choice, GI method, shadow method, Nanite use, Lumen use, baked/dynamic mixture, and platform-specific scalability are **technical-production choices not locked by this Art Bible**. They must preserve this visual doctrine and later platform/performance authority.

---

# 13. Fog and atmosphere

Fog is compositional, not decorative wallpaper.

Use atmosphere to:

- separate depth layers;
- hide information deliberately;
- reveal landmarks;
- change perceived scale;
- reinforce weather;
- establish quiet;
- distinguish normal and abnormal states.

Atmospheric elements may include:

- mist;
- dust;
- ash;
- pollen;
- smoke;
- rain;
- drifting leaves;
- insects;
- cloud shadow;
- wind-driven debris.

Do not place continuous particles in every scene merely because the engine can render them.

Stillness is a valid atmospheric choice.

---

# 14. Environmental motion

The world should feel alive through layered, coherent movement.

Prefer broad environmental motion over universal independent simulation.

Examples:

- coordinated waves through grass;
- canopy movement with smaller branch response;
- hanging cloth and signs reacting to region wind;
- water and spray near actual flow;
- distant birds or work activity;
- mechanical cycles tied to civic function.

Avoid a scene where every plant, cloth strip, particle, lantern, prop, and effect moves at the same visual priority.

Motion must preserve readable focal hierarchy.

---

# 15. Waking / Hush visual grammar

The Hush is not a post-process preset.

It is a related reality whose production must preserve semantic relationship while making absence, repetition, compression, and unfinished possibility visually legible.

Rules:

1. **Maintain correspondence where story/gameplay requires recognition.** A player should often know what place they are seeing.
2. **Do not merely recolor Waking geometry.** Material, light, atmosphere, motion, occupancy, geometry state, and spatial relationships may all participate.
3. **Do not destroy gameplay readability.** Valid routes and hazards remain legible through redundant shape/motion/value cues.
4. **Avoid one global Hush color.** Regional identity must survive the transition.
5. **Silence and reduced motion are part of the Hush aesthetic.** Visual effects do not need to compensate for quieter audio.
6. **Repetition may appear spatially or materially but must not become generic glitch art.**
7. **The Hush should feel wrong because relationships are wrong, not because every surface is covered in distortion.**

Potential production levers:

- missing ordinary wear or incomplete wear;
- suspended motion;
- repeated object states;
- impossible but controlled spacing;
- shifted light direction;
- absent population activity;
- selectively preserved traces;
- locally contradictory material state;
- incomplete reflections/shadows where semantically justified;
- visible seams only where the world/game rules justify them.

Exact Hush runtime representation remains an architecture/performance question outside this document.

---

# 16. Stillness / post-catastrophe state

The midpoint catastrophe must not flatten the whole game into permanent visual misery.

Changed regions should show specific consequences rather than generic “destroyed version” treatment.

Possible changes include:

- altered population density;
- rerouted foot traffic;
- emergency repairs;
- improvised bridges;
- new warning marks;
- different lighting behavior;
- stalled machinery;
- moving pockets of ordinary motion;
- altered vegetation response;
- new social use of existing structures;
- local adaptation rather than only damage.

A place matters after catastrophe because the player remembers what it was like before.

Therefore pre-catastrophe beauty and ordinary usefulness are production-critical, not optional polish.

---

# 17. Character visual doctrine

Characters are grounded humans with controlled stylization.

The target is not a numeric percentage of realism. The practical boundary is:

- anatomically believable overall proportion;
- simplified rather than scan-faithful skin detail;
- expressive eyes without anime proportion;
- readable nose/jaw/brow silhouettes;
- strong hair masses rather than strand-showcase dependence;
- hands readable in tool/work interactions;
- costume silhouettes recognizable at gameplay camera distance;
- facial performance prioritized over pore fidelity.

Avoid:

- generic MetaHuman default appearance;
- photoreal skin micro-detail as the character identity;
- doll-like faces;
- fashion-model homogeneity;
- excessive fantasy armor clutter;
- silhouette dependence on tiny accessories.

Characters should look like people who belong to their work and region.

---

# 18. Neris visual requirements

Narrative authority defines Neris as a **seventeen-year-old apprentice bellwright from Brindle**, mechanically gifted, practical, and not chosen by prophecy, royalty, or sacred bloodline.

Art must communicate that before dialogue does.

Locked production requirements:

- Neris must read as a working apprentice/field repairer, not a prince, knight, assassin, mage, or predestined champion.
- The silhouette must accommodate visible practical relationship to the Cantor Key and field work.
- Clothing must support climbing/mantling/ladder/swim/combat animation without looking like modern tactical gear.
- Equipment evolution should read as accumulated work capability, not loot-rarity escalation.
- Neris must remain recognizable without relying on one bright color accent.
- Damage/dirt/state variants must preserve age and identity rather than “hardening” Neris into a generic grim warrior.
- Later-game authority comes from competence and experience; costume escalation must not imply royal/chosen-one transformation.

Not yet locked by owner visual review:

- final face;
- exact hair design;
- exact body dimensions;
- exact palette;
- final garment construction;
- exact Cantor holster/attachment solution.

Those belong in the Character Production Manifest and concept review, not agent invention.

---

# 19. NPC population language

Population art must make regions culturally legible without turning them into costume theme parks.

NPC variation should come from layered systems such as:

- occupation;
- age/build;
- region materials;
- climate adaptations;
- social role;
- repair/wear state;
- personal accessories;
- hair/headwear families;
- changed-world state.

Do not make every NPC unique from scratch.

Do not make every NPC a palette swap.

Named recurring characters require stronger silhouette and prop identity than background population, but they must still look as though they belong to the same society.

---

# 20. Enemy and boss readability

Enemies obey the same “shape before surface” rule.

At gameplay distance, silhouette and motion should communicate:

- approximate size;
- locomotion class;
- reach/threat direction;
- defense/armor character;
- attack readiness;
- unusual state;
- vulnerable or interactable feature where applicable.

Bosses must be unique enough to carry regional memory without becoming unrelated spectacle imports.

Boss visual design should emerge from:

- region ecology;
- local machinery;
- local history;
- Hush/Stillness effect;
- the encounter mechanic being tested.

Do not use visual complexity to substitute for encounter identity.

---

# 21. Props, tools, and civic machinery

Stillring's world is full of work.

Props should show how people:

- maintain infrastructure;
- travel;
- measure;
- cook;
- store goods;
- repair;
- communicate;
- document;
- move freight;
- respond to weather;
- live around bell/resonance systems.

Civic machinery must look maintainable rather than magical by default.

Waybells, resonance infrastructure, route hardware, foundry systems, lifts, signal equipment, and related mechanisms should expose understandable joints, service access, wear, repairs, or operating logic where practical.

The Cantor Key is a signature tool, not a wand.

Its visual language should remain mechanical, fold-out, tactile, and field-serviceable, consistent with `docs/01_GAME_VISION.md`.

---

# 22. Traversal and interaction readability

Stillring rejects both extremes:

- invisible interactions that require random button testing;
- universal yellow paint / glowing outline language.

Affordances should be taught through consistent combinations of:

- shape;
- material;
- construction;
- placement;
- wear;
- lighting;
- repeated world grammar;
- animation;
- context.

This is bound by the “honest world” rule in locomotion authority.

If a surface reasonably looks like a valid authored traversal affordance, expected player action should work or the exception must be visually understandable.

Art may not imply universal free climbing where gameplay does not permit it.

---

# 23. VFX

VFX must be readable, restrained, and semantically organized.

Three classes:

## Gameplay-critical
Must remain readable under combat, weather, Hush, accessibility settings, and reduced particle quality.

## State-communication
Shows resonance, tool state, seam state, machinery condition, or world transition.

## Decorative
Supports atmosphere but may never obscure critical information.

Avoid:

- excessive bloom;
- constant screen-space distortion;
- giant particle cones hiding attack silhouettes;
- full-screen color washes as primary state communication;
- decorative effects at every interactable;
- magic colors that collapse into one undifferentiated “fantasy energy” palette.

Critical information must have color-independent redundancy.

---

# 24. Camera/composition obligations for art

Camera is gameplay authority, but environment art must compose for the approved third-person camera rather than for detached concept-art viewpoints.

Production spaces should intentionally provide:

- foreground framing;
- layered depth;
- readable skyline;
- controlled landmark reveals;
- elevation-driven vistas;
- paths/bridges/rivers that guide the eye;
- visual reorientation after enclosed spaces;
- readable combat floors;
- sufficient separation between player silhouette and background.

A beautiful shot that only works from a cinematic camera is not proof that the playable environment works.

---

# 25. Landmark navigation

Stillring should frequently be navigable by the world itself.

Landmarks may include:

- towers;
- giant trees;
- smoke;
- mountain forms;
- waterfalls;
- wind structures;
- large ruins;
- celestial references;
- route infrastructure;
- lit civic machines.

Important landmarks should appear from multiple routes when practical.

The desired player thought is:

> **I know where that is.**

not:

> **The minimap says turn left.**

---

# 26. Signage, markings, and decals

World markings must belong to institutions and cultures.

Use:

- maintenance marks;
- inspection seals;
- maker stamps;
- route symbols;
- hazard conventions;
- freight notation;
- civic labels;
- hand repairs and local annotations.

Do not turn every gameplay affordance into universal game-design paint.

A marking system must answer who placed it, why, and whether local people would understand it.

---

# 27. Production-quality bands

This Art Bible distinguishes production intent from implementation maturity.

## Documentation / concept phase

Allowed:
- paintovers;
- loose concept art;
- value studies;
- silhouette sheets;
- palette studies;
- rough 3D massing references.

Not acceptable as final authority:
- unexplained mood art;
- copied artist style;
- asset-pack screenshots presented as final identity.

## Prototype / graybox phase

May simplify:
- materials;
- final topology;
- foliage density;
- prop density;
- VFX finish;
- character final model;
- lighting fidelity.

Must still prove:
- scale;
- silhouette;
- navigation;
- camera readability;
- traversal honesty;
- landmark placement.

## Representative vertical slice

Must prove:
- final-direction materials;
- final-direction lighting;
- representative character treatment;
- representative regional kit;
- representative Waking/Hush relationship;
- gameplay VFX readability;
- performance feasibility on selected target evidence;
- sustainable production cost.

## Full production

Must preserve approved visual rules while allowing studio-owned technical solutions inside performance/platform boundaries.

---

# 28. Renderer and technology neutrality

This Art Bible does not mandate a rendering feature merely because UE5.8 provides it.

Do not cargo-cult:

- Nanite;
- Lumen;
- Virtual Shadow Maps;
- PCG;
- MetaHuman;
- high-resolution scans;
- a specific upscaler;
- one global material architecture.

Current Epic documentation confirms that features such as Nanite can radically increase geometric capacity, but material complexity, output resolution, instance counts, hardware, and performance still matter. Engine capability is not permission to abandon art hierarchy.

The Technical Production Bible and later performance evidence choose rendering technology. This Art Bible defines what those choices must preserve.

---

# 29. External reference / artist firewall

External art is used to extract principles, not expression.

Allowed extraction:

- readable massing;
- exaggerated scale;
- landmark hierarchy;
- settlement/nature integration;
- composition;
- atmospheric depth;
- restrained detail;
- palette relationships;
- architectural plausibility;
- traversal-friendly spatial structure.

Forbidden:

- direct style imitation instructions;
- traced composition;
- copied structure silhouette;
- copied costume;
- copied prop design;
- copied symbol/iconography;
- direct derivative prompt such as “make Stillring exactly in Artist X's style.”

`docs/05_IP_GUARDRAILS.md` remains binding.

---

# 30. Stillring visual acceptance questions

Before approving a major art decision, answer:

1. Can the player read it at gameplay distance?
2. Can the player remember it later?
3. Does it belong specifically to Stillring?
4. Does it support the gameplay verb used there?
5. Does it support the emotional purpose of the location?
6. Is the dominant landmark/spatial idea obvious enough?
7. Is there unnecessary surface, prop, foliage, light, or VFX noise?
8. Does the place look inhabited where people live?
9. Does the art honestly communicate traversal/interactions?
10. Would the scene still have identity if expensive rendering features were removed?
11. Does Waking/Hush treatment preserve region identity?
12. Is the work original under `docs/05_IP_GUARDRAILS.md`?

If those answers are weak, higher fidelity is not the fix.

---

# 31. Final principle

> **The world must look worth remembering before the story asks the player to care about what happens to it.**

Stillring should not look impressive because the engine is powerful.

It should look memorable because every major visual decision has a reason.