# 162 — Hush Visual Production Matrix

**Status:** ACTIVE / STUDIO-HANDOFF HUSH ART PRODUCTION AUTHORITY / DOCUMENTATION-ONLY PRE-PRODUCTION  
**Updated:** 2026-09-06  
**Parent program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Gameplay-semantic authority:** `docs/70_GATE4_HUSH_SEMANTIC_LAYER_IDENTITY_ADDENDUM.md` through `docs/79_GATE4_HUSH_CUMULATIVE_SPECIFICATION.md`  
**Art authority:** `docs/154_STILLRING_ART_BIBLE.md`  
**Production framework:** `docs/156_ART_PRODUCTION_MANIFEST_FRAMEWORK.md`  
**Character authority:** `docs/158_CHARACTER_PRODUCTION_MANIFEST.md`  
**Enemy/boss authority:** `docs/159_ENEMY_BOSS_ART_MANIFEST.md`  
**Region environment/prop authority:** `docs/160_REGION_ENVIRONMENT_PROP_MANIFEST.md`  
**Regional visual scripts:** `docs/161_REGIONAL_COLOR_MATERIAL_LIGHTING_SCRIPTS.md`  
**Late-Hush narrative authority:** `docs/story/regions/09_HUSH_CAIRNSPIRE_AND_NULL_MERIDIAN.md`  
**Closes toward:** `SH-ART-007` and Hush-facing portions of `SH-ART-002`, `SH-ART-004`, `SH-ART-006`, `SH-ART-008`, and `SH-ART-009`  
**Boundary:** this file classifies authored visual-production burden. It does not define semantic world facts, transition legality, collision authority, save state, gameplay continuity, Data Layer implementation, shader cost, asset counts, memory budgets, or measured runtime performance.

---

# 1. Purpose

The Hush cannot remain a sentence in an Art Bible.

A production studio needs to know which content:

- remains visually unchanged;
- reuses geometry but changes material/light;
- reuses geometry but changes dressing/occupancy/motion;
- requires meaningful geometry-state changes;
- requires a recognizably related but substantially separate counterpart;
- exists only in the Hush;
- must preserve one semantic identity across Waking/Hush expressions;
- is actually a related-distinct entity rather than the same thing in another layer;
- carries special character, enemy, boss, route, puzzle, atmosphere, or finale burden.

This matrix supplies that production answer.

It joins two previously separate authorities:

1. Gate 4 semantic identity classes;
2. Art Production H0–H5 workload classes.

The governing rule remains:

> **One place. One history of facts. Two authored expressions—and exactly one semantic reality active at a time.**

The art team may create two expressions. It may not accidentally create two histories.

---

# 2. Two classifications that must never be confused

Every Hush-relevant content family must carry **two independent labels**.

## 2.1 Semantic relationship class — gameplay/world-state meaning

Owned by Gate 4 authority.

### SI — Shared Invariant

One semantic entity; compatible state persists; visual/physical expression may be identical or presentation-only different.

### PE — Paired Expression

One semantic identity with authored Waking and Hush expressions. Durable facts persist once; active expression changes.

### LE — Layer Exclusive

A semantic entity exists or is physically/action-authoritative only in one layer. It does not gain a duplicate counterpart merely because another layer exists.

### RD — Related Distinct

Two entities may be narratively or visually related, but they are not one shared semantic identity and do not automatically share durable gameplay state.

## 2.2 Art-production burden class — what art must build

Owned by `docs/156` and completed here.

### H0 — Unchanged

Same production asset/state is visually and semantically appropriate.

### H1 — Material / Light Variant

Geometry is shared. Material, illumination, local surface behavior, emission, reflection, or related presentation changes.

### H2 — Dressing / Occupancy / Motion Variant

Base geometry remains shared, but population, prop placement, object arrangement, ordinary motion, atmospheric dressing, or local activity changes.

### H3 — Geometry-State Variant

The same semantic place/object requires meaningful geometry relationship changes such as opened/closed, incomplete/complete, displaced, repeated, missing, locally contradictory, or alternate structural state.

### H4 — Related-Distinct Production Counterpart

The Hush expression remains recognizably derived from a Waking place/object family but requires substantial separate art production.

**Important:** H4 art burden does **not** imply Gate 4 `RelatedDistinct` semantics. A PE semantic identity may require H4 art production.

### H5 — Unique Hush-Only

Content exists only in Hush presentation/canon and requires dedicated production.

**Important:** H5 does not automatically mean supernatural creature or maximal spectacle.

---

# 3. Crosswalk rules

The semantic relationship and art burden must be authored separately.

Examples:

| Example | Semantic class | Art class | Why |
|---|---|---:|---|
| identical structural column present in both layers | SI | H0 | same identity and same art |
| one Waybell housing whose surface relation changes | PE | H1 | one semantic machine, variant presentation |
| same public square emptied/re-dressed in Hush | PE | H2 | same place/history; occupancy changes |
| same bridge with authored Hush geometry state | PE | H3 | one semantic route expression, meaningful geometry difference |
| Hush version of a recognizable Cairnspire district assembled from discarded plans | PE or RD per authored entity | H4 | substantial related production; semantics must be declared independently |
| responsive residue of a person who is not the living NPC | RD or LE | H5 | unique Hush entity, not the living person duplicated |

Forbidden shortcuts:

- `H3` does not grant art permission to invent collision or route changes;
- `H4` does not mean “alternate universe version” by default;
- `H5` does not mean “boss monster”;
- `PE` does not require duplicate meshes;
- `SI` does not require identical lighting/material if the difference remains presentation-only and authority permits it;
- Data Layer placement does not determine either classification.

---

# 4. Global Hush visual grammar — locked production rules

## 4.1 Recognition before wrongness

A Hush expression should usually be recognizable **before** the player identifies what is wrong.

Priority:

1. landmark/place recognition;
2. route/gameplay readability;
3. material/value relationship;
4. occupancy/motion contradiction;
5. geometry contradiction;
6. fine residue detail.

If the player sees “weird Hush environment” before “this is Brindle/Rootmere/Cairnspire,” the regional relationship is too weak unless the content is intentionally H5.

## 4.2 Wrong relationships, not universal corruption

The Hush is not visually defined by:

- purple color grading;
- chromatic aberration;
- black tendrils;
- floating rocks everywhere;
- generic cracks;
- VHS/glitch treatment;
- ash particles in every scene;
- inverted gravity as decoration;
- ghost transparency;
- permanent screen distortion.

Preferred wrongness:

- wear that does not match use;
- objects remembering incompatible positions;
- motion suspended selectively;
- repeated local states;
- missing ordinary repair;
- too-perfect spacing;
- lighting whose source relationship is wrong;
- reflections preserving another state;
- occupancy absent where service systems remain active;
- familiar geometry completed according to rejected plans;
- practical traces appearing before their cause.

## 4.3 Regional identity survives

Hush Brindle remains Brindle.

Hush Rootmere remains Rootmere.

Hush Saltreach remains Saltreach.

No Hush treatment may erase the regional shape/material/color scripts in `docs/161` unless a specific H4/H5 late-game content family justifies it.

## 4.4 Readability survives

Art may never use Hush atmosphere to hide required:

- traversal boundaries;
- combat silhouettes;
- attack telegraphs;
- interactables;
- puzzle evidence;
- NPC conversational staging;
- Line Skiff route information;
- seam eligibility cues;
- destination occupancy safety.

Critical distinction must not be color-only.

## 4.5 Stillness is allowed

Silence does not require visual compensation.

Reduced motion is one of the Hush's strongest tools.

Do not fill quiet audio with extra particles, flicker, shader noise, or floating debris simply to reassure the player that “the effect is on.”

## 4.6 Post-process is support only

The Hush must remain identifiable with post-process reduced or disabled.

World-space geometry, material, light, occupancy, residue and motion carry the identity first.

---

# 5. Production matrix — environment families

## 5.1 Universal structural/civic families

| Content family | Default semantic class | Default art burden | Production requirement |
|---|---|---:|---|
| stable terrain mass needed identically for navigation | SI | H0 | share asset; no gratuitous variant |
| common structural supports with unchanged relationship | SI/PE | H0 | reuse where state is honestly identical |
| Meridian-era service panels | PE | H1 | shared geometry; wear/light/mark relation may differ |
| civic warning/measurement surfaces | PE | H1/H2 | preserve local readability; Hush may show disagreement/repetition |
| ordinary movable clutter | PE or LE | H2 | controlled removal/rearrangement/repetition; no physics assumption |
| maintained repair patches | PE | H2/H3 | may disappear, predate damage, or repeat when narrative relationship supports it |
| authored doors/gates | PE | H3 only when gameplay authority declares paired state | art follows semantic/open-state authority; never invent route eligibility |
| authored bridges/spans | PE | H3/H4 when canon requires | paired geometry must preserve Gate 4 occupancy/collision authority |
| abandoned/rejected civic plan geometry | LE/RD | H4/H5 | dedicated Hush production; must remain recognizably regional |

## 5.2 Natural environment families

### Terrain / rock

Default: `SI + H0`.

Escalate only when authored Hush geometry is meaningful.

Avoid making every rock float, crack, invert or duplicate.

### Vegetation

Default: `PE + H1/H2`.

Possible differences:

- changed moisture/material response;
- selective motion suspension;
- repeated growth state;
- absent wear/path relationship;
- local old/current growth overlap.

H3/H4 is reserved for authored growth-state contradictions such as Rootmere's major living-root relationships.

### Water

Default: `PE + H1/H2`.

Water is a strong relationship carrier:

- reflection may preserve another local state;
- motion may continue while adjacent flexible systems stop;
- tide/waterline relationship may disagree with infrastructure;
- surface material may remain region-specific.

Do not assume Hush water has different gameplay physics.

### Sky / atmosphere

Default: `PE + H1/H2`.

Regional horizon and weather identity survive.

Hush sky is not automatically cosmic-space replacement.

---

# 6. Region-by-region Hush burden matrix

## 6.1 Brindle / First Circuit

**Core Hush job:** make ordinary maintenance and family memory feel incorrectly preserved.

| Family | Class | Required Hush expression |
|---|---:|---|
| hills/orchard terrain | H0/H1 | recognizable terrain; restrained atmosphere shift only |
| houses/ordinary civic shells | H0/H2 | occupancy/light/use relationships may change |
| Vale Workshop shell | H2/H3 | familiar structure; object arrangement, wear, repair and remembered placement become primary wrongness |
| workbench/tool family | H2/H3 | duplicated position, too-perfect arrangement, missing accumulated wear, repair-before-damage allowed only where authored |
| village route/flood infrastructure | H1/H2 | local markers may disagree or appear over-maintained without population activity |
| family-memory content | H4/H5 | only where story explicitly calls for preserved/imagined versions |

**Forbidden:** generic haunted tutorial village.

## 6.2 Cairnspire

**Core Hush job:** civic coordination remains locally precise while the relationship among systems becomes wrong.

| Family | Class | Required Hush expression |
|---|---:|---|
| main civic massing | H0/H2 | recognizable vertical city first |
| lifts/landings/service nodes | H2/H3 | local precision with contradictory network relation; route state follows semantic authority |
| public counters/queue systems | H2 | repeated barriers/counters without ordinary population |
| clocks/indicators | H1/H2 | disagreement between locally believable devices |
| Lower Archive ordinary shell | H2/H3 | density/record arrangement changes without generic magic-library treatment |
| unrealized civic-plan spaces | H4/H5 | recognizably Cairnspire, materially separate production |

**Forbidden:** second dark fantasy city.

## 6.3 Rootmere

**Core Hush job:** living systems preserve incompatible growth and maintenance relationships.

| Family | Class | Required Hush expression |
|---|---:|---|
| wetland terrain/water | H0/H1 | regional wet-green identity retained |
| ordinary vegetation | H1/H2 | motion/growth/wear changes selective |
| major roots/bell-oaks | H2/H3 | old/current growth states may coexist where authored |
| root bridges | H2/H3 | flexible motion may stop; geometry-state only where route authority allows |
| resin/repair wraps | H2/H3 | wrap may appear before damage or repeat an older repair relationship |
| Root Cathedral special states | H3/H4 | major authored living-structure contradiction; no corruption-goo pass |

**Forbidden:** dead gray corrupted forest.

## 6.4 Saltreach

**Core Hush job:** coast/infrastructure disagree about conditions that are normally read together.

| Family | Class | Required Hush expression |
|---|---:|---|
| coastline/cliffs | H0/H1 | geographic identity stable |
| water/tide surfaces | H1/H2 | authored tide/reflection relation may contradict infrastructure |
| docks/moorings | H2/H3 | occupancy/load/tide evidence changes; traversal remains governed by route authority |
| fog signals | H1/H2 | signal may remain locally active with no matching traffic/visibility need |
| pressure/pipe systems | H1/H3 | material/indicator/geometry state may disagree where puzzle authority requires |
| drowned industrial residues | H3/H4 | substantial paired state where regional story justifies it |

**Forbidden:** ghost pirate coast.

## 6.5 Emberstep

**Core Hush job:** traceability, heat history and maker relationships become unreliable without losing industrial logic.

| Family | Class | Required Hush expression |
|---|---:|---|
| badland geology | H0/H1 | black-glass/geothermal identity retained |
| kiln architecture | H1/H2 | heat/light/activity may persist without normal labor sequence |
| molds/castings | H2/H3 | maker marks, cooling state, or assembly relation may preserve incompatible versions |
| vents/heat machinery | H1/H3 | heat history may disagree with current state; no invented damage semantics |
| maker/provenance marks | H1/H2 | erased/preserved/duplicated relationship can carry story meaning |
| Kiln of Names special state | H3/H4 | substantial authored identity variant; avoid lava-dungeon language |

**Forbidden:** orange Hush lava level.

## 6.6 High Aerie

**Core Hush job:** a culture built around continuous wind/motion becomes selectively motionless or temporally inconsistent.

| Family | Class | Required Hush expression |
|---|---:|---|
| mountain massing | H0/H1 | horizon/drop identity stable |
| rope/lift infrastructure | H2/H3 | selective motion suspension; geometry change only when authored |
| hanging cloth/flags | H1/H2 | motion absence becomes primary cue |
| wind organs | H1/H2/H3 | locally coherent state may disagree with visible wind evidence |
| archive/monastery spaces | H2 | occupancy and record-state relationship shift |
| Tempest Belfry special states | H3/H4 | major paired production where required by region content |

**Forbidden:** replacing wind absence with constant magical VFX.

## 6.7 Mireglass

**Core Hush job:** reflection and memory disagree without making navigation dishonest.

| Family | Class | Required Hush expression |
|---|---:|---|
| marsh terrain/reeds | H0/H1 | geographic identity stable |
| water/reflection surfaces | H1/H2 | reflection may preserve another authored state; route remains visually redundant |
| raised paths/ferries | H2/H3 | occupancy/reflection relation changes; route geometry only by authority |
| homes/doors/interiors | H2/H3 | familiar contradictory domestic states rather than random surrealism |
| Palace Under Reeds | H3/H4 | substantial state burden tied to memory/reflection logic |
| responsive memory residues | H4/H5 | separate authored content, not generic ghost population |

**Forbidden:** reflection puzzle readability that depends on color or guesswork.

## 6.8 Cairnfall

**Core Hush job:** observation/calibration systems expose discarded alignments and incompatible measurement histories.

| Family | Class | Required Hush expression |
|---|---:|---|
| plateau geology | H0/H1 | broad arcs/gaps remain recognizable |
| astronomical instruments | H1/H3 | alignment positions may preserve alternate authored measurements |
| calibration marks | H1/H2 | raw/corrected history can coexist visibly |
| observation structures | H2 | occupancy/annotation relationship changes |
| Fallen Orrery | H3/H4 | major authored phase/alignment counterpart |
| seam-mode special content | H4/H5 | only where late-game mechanics/story explicitly require it |

**Forbidden:** glowing wizard observatory shorthand.

---

# 7. Hush-Cairnspire / Still-Cairn / Null Meridian matrix

These late spaces have the highest H4/H5 burden but must still derive from established Stillring language.

## 7.1 Hush-Cairnspire

Narrative identity:

- discarded civic plans;
- demolished rooms;
- unrealized routes;
- contradictory memories;
- banal possibilities;
- emotionally legible ordinary-life residue.

Production classes:

### HC-A — Recognizable civic anchor

Examples:

- Route House;
- Fourth Landing;
- Lower Archive;
- Public Bell Office.

Default: `PE + H3/H4`.

Requirement:

The player recognizes the Waking anchor before reading the alternate plan/history.

### HC-B — Rejected-plan civic geometry

Default: `LE/RD + H4/H5`.

These are substantial separate production, but use Cairnspire materials, dimensions, service logic and civic ancestry.

### HC-C — Banal residue dressing

Default: `RD/LE + H2/H5` depending implementation.

Examples:

- rejected wall colors;
- lunch/order traces;
- abandoned public-art proposals;
- route-clerk imagined life fragments;
- apprentice practice residue.

These must not all become interactable lore objects.

### HC-D — Vale family rooms that never existed

Default: `RD + H4`.

They are emotionally related spaces, not a secretly canonical alternate family home.

## 7.2 Ilyra's Workbench

Default: `PE + H3/H4`.

This is one of the game's highest-priority Hush environment/character crossover assets.

Required authored progression:

1. rigidly reset reconstruction;
2. one drawer remains open;
3. duplicated tool is tolerated;
4. space becomes less perfect;
5. Neris and Ilyra physically modify it together.

The workbench must support these changes through clear object-layout states rather than particle effects.

## 7.3 Still-Cairn

Core art rule:

> **Useful permanence must look appealing enough that release costs something emotionally.**

Do not make every preserved state obviously sinister.

Production burden:

- familiar safe streets/homes/workplaces in H3/H4 states;
- people/relationships represented only according to narrative/semantic class;
- state-release visual language that communicates ending without framing release as “destroy evil corruption.”

## 7.4 Echo-bound Orin / preserved Vale workshop

Environment burden: `H4`.

Character/entity burden: governed by `docs/158`/`159` and semantic authority.

The safe workshop must look **better in specific human ways**, not more magical:

- Ilyra present;
- young Neris present where story representation permits;
- repairs completed;
- familiar arguments never reaching catastrophe;
- ordinary family disorder preserved.

Neris rejects repetition, not the visual idea of family.

## 7.5 Null Meridian

Null Meridian combines H2–H5 production but cannot introduce a new fantasy art language solely because it is the finale.

Required ancestry:

- Cairnspire civic stone/service metal;
- Meridian brass/iron precision;
- Quiet Court technical-era forms;
- worker bypasses;
- maintenance lifts;
- pressure rooms;
- meal stations;
- shift boards;
- inspection marks;
- confiscated nonstandard tools.

The Hush distortion of Null Meridian must expose the relationship between sacred cladding and ordinary labor infrastructure.

### Finale rule

Spectacle comes from recombination and impossible relationship of familiar systems, not from suddenly importing cosmic architecture.

---

# 8. Character Hush burden matrix

## 8.1 Neris

Default semantic relation: the living Neris remains one character; layer changes do not create a second Neris.

Art burden: `H0/H1` for ordinary active-layer presentation.

Requirements:

- no ghost duplicate following the player by default;
- no permanent glowing Hush costume;
- palette/silhouette remain stable;
- local light/material response may shift;
- equipment remains readable;
- any memory/residue version of Neris is a separately declared RD/LE entity, not player-state duplication.

## 8.2 Ilyra

Highest principal-character Hush burden.

Living Ilyra after recovery and Hush-survival presentation must remain recognizably the same woman.

Art burden: `H3/H4` for authored Hush-survival state.

Required wrongness:

- garment age inconsistent with eleven Waking years;
- repeated repairs that did not progress normally;
- selective wear/stillness;
- controlled material/light contradiction;
- no translucency/ghost glow/corruption veins.

## 8.3 Orin

Ordinary Orin, glimpsed residues, preserved-state Orin and Echo-bound Orin must be explicitly distinguished.

No art team may treat all of them as one palette-swapped character mesh without checking semantic relationship.

Expected burden:

- actual Orin: H0/H1 as appropriate;
- memory/residue glimpses: RD/LE + H4/H5;
- Echo-bound/preserved encounter state: H4, governed by boss/encounter authority.

## 8.4 Maelor

Maelor remains human.

Expected burden:

- active Maelor: H0/H1;
- old Quiet Court/personal residues: RD/LE + H4/H5 when separately instantiated;
- finale system relationship: costume/material/light modification may rise to H2/H3 but must not become “evil transformation.”

## 8.5 Tessa / Caldrin / Sena / Rusk

Default: H0/H1 unless a scene explicitly requires a Hush-residue or paired expression.

Do not create expensive Hush duplicates merely because they are major characters.

## 8.6 Population

Ordinary living population is not duplicated wholesale into Hush.

Echo figures use three narrative categories:

- repeating impressions;
- responsive residues;
- emergent composites.

Production must classify each as a separate semantic/art burden rather than applying a ghost shader to C4 population meshes.

---

# 9. Enemy / boss Hush burden rules

Enemy Hush treatment follows `docs/159` and Gate 4 continuity.

## 9.1 Shared/paired enemies

When the same semantic enemy persists across a seam:

- health/death/aggro history persists;
- art may use H0–H3 depending authored expression;
- visual variant must preserve threat class and attack readability;
- target-lock transfer uses same-semantic-target authority;
- no Hush variant may visually imply a reset/respawn that gameplay does not perform.

## 9.2 Layer-exclusive enemies

Use LE + the appropriate H-class.

Their absence in one layer is a legitimate authored state, not permission to spawn a substitute enemy for visual fullness.

## 9.3 Emergent composite bosses

Mirror Widow, Saint Varo, Archivist Without a Face, Echo-bound Orin and related late-game entities may require H4/H5 production according to `docs/159`.

They remain grounded in region/history/mechanic identity.

Do not turn H5 into unrestricted creature-design scope.

## 9.4 Listener

The Listener remains a cross-discipline special presentation family.

Art burden: H5.

Required:

- incomplete possibilities becoming briefly legible;
- familiar geometry/gesture fragments;
- no permanent human body;
- no giant eye, demon, angel, cosmic monarch, or particle blob as default;
- presentation must remain compatible with Reduced Hush Effects and readable finale staging.

---

# 10. Props, interactables and puzzle machinery

Every stateful prop must carry:

- stable semantic identity if required;
- semantic relationship class;
- H0–H5 burden;
- active expression ID;
- whether material/light, dressing, geometry, or distinct counterpart changes;
- gameplay-interaction authority source;
- save/world-state dependency;
- animation/physics dependency;
- VFX/audio dependency.

## 10.1 Cantor-compatible machinery

Default Hush burden: H1–H3 depending authored puzzle.

Cantor readability must diagnose relationships without becoming a universal Hush-object outline.

## 10.2 Anchor load points

Art may change presentation only according to active legal physical load-point authority.

Do not show a visually inviting Hush load point that is not mechanically legal unless the design intentionally communicates “inactive/unavailable” through redundant cues.

## 10.3 Cross-layer causal machinery

If changing a semantic fact in one expression produces a valid consequence in another, both art expressions must visibly converge on the authoritative fact.

Art is not allowed to preserve an obsolete visual state because “the other mesh was authored separately.”

---

# 11. Routes / traversal / Line Skiff

## 11.1 Ordinary traversal

Hush art must preserve authored movement readability:

- ledges;
- ladders;
- mantle surfaces;
- hang/shimmy boundaries;
- swim exits;
- slope behavior;
- blocked/open routes.

Art classification never grants new traversal semantics.

## 11.2 Route-network relationship classes

Route expressions must use the Gate 4/Line Skiff relationship classes:

- Shared Invariant;
- Paired;
- Layer Exclusive;
- Related Distinct.

The art burden can independently be H0–H5.

## 11.3 Line Skiff seam transitions

A Waking↔Hush shift while riding is legal only where route authority already declares deterministic paired continuation and destination occupancy can be validated.

Art requirements:

- paired route expression must visually communicate continuity;
- destination route must not appear navigable when semantic route authority says otherwise;
- Hush transformation may not obscure track/route geometry under atmosphere;
- no generic spectral rails added as visual convenience without route authority.

---

# 12. Lighting matrix

Hush lighting changes relationship, not merely color temperature.

Allowed levers:

- source direction mismatches selectively;
- locally precise light without expected operator/activity;
- warm light surviving in an empty space;
- missing bounce/occupancy cues where composition remains readable;
- repeated light-state relationships;
- reflection preserving another authored state;
- reduced ordinary motion/flicker.

Forbidden defaults:

- blue moonlight everywhere;
- underlighting every face;
- constant flicker;
- crushed blacks;
- global exposure reduction that hides traversal;
- volumetric shafts in every Hush room.

Regional lighting scripts in `docs/161` remain controlling.

---

# 13. Material matrix

## H0 material

No variant required.

## H1 material

May include:

- changed roughness relationship;
- altered wear presence;
- selected reflection contradiction;
- local emissive behavior where the object already has a plausible light/technical role;
- preserved or missing maintenance marks;
- state-specific surface age.

Do not use universal animated noise.

## H2 material/dressing support

Materials should reinforce occupancy difference:

- dust/wear absent where people are absent;
- polished hand contact contradicting current vacancy;
- lighting on a work surface with no worker;
- repair markings remaining without repair activity.

## H3/H4 materials

Distinct geometry does not justify distinct material language unrelated to the source region.

Counterparts should usually inherit recognizable:

- base stone family;
- timber species/material read;
- civic metal ancestry;
- local ceramic/fiber language;
- maker/maintenance logic.

## H5 materials

Even unique Hush-only content should borrow from established world relationships when possible.

H5 does not mean “make a new magical substance.”

---

# 14. Motion / atmosphere matrix

## 14.1 Motion hierarchy

Preferred order of Hush motion design:

1. remove expected motion selectively;
2. repeat a meaningful motion state;
3. desynchronize related motions;
4. preserve one movement after its cause disappears;
5. introduce unique Hush motion only when canon requires it.

## 14.2 Particles

Particles are secondary.

Do not use continuous floating motes as proof that the player is in Hush.

Region-specific exceptions require an actual physical/narrative source.

## 14.3 Fog

Fog remains compositional:

- depth separation;
- conceal/reveal;
- scale;
- weather;
- local abnormality.

It must not erase valid routes, enemies, tools or dialogue staging.

## 14.4 Reduced Hush Effects

Every visual family must define a reduced-effects state before Q3 approval.

Reduced mode may remove/reduce:

- post-process;
- peripheral distortion;
- decorative particles;
- secondary flicker;
- nonessential reflection instability;
- high-frequency material animation.

It may **not** remove:

- layer identity;
- route distinction;
- interactable distinction;
- hazard recognition;
- puzzle state;
- combat telegraphing;
- semantic presentation necessary to understand the scene.

---

# 15. Hush production data contract

Every Hush-relevant asset/content entry in later production tracking should expose at minimum:

- `SemanticEntityId` where applicable;
- `SemanticRelationshipClass` = SI / PE / LE / RD;
- `HushArtBurden` = H0 / H1 / H2 / H3 / H4 / H5;
- `WakingExpressionId` if applicable;
- `HushExpressionId` if applicable;
- `Region`;
- `ContentFamily`;
- `SharedGeometry` yes/no;
- `MaterialVariant` yes/no;
- `DressingVariant` yes/no;
- `GeometryStateVariant` yes/no;
- `UniqueHushProduction` yes/no;
- `GameplayAuthoritySource`;
- `SaveWorldStateDependency`;
- `CollisionTraversalDependency`;
- `AnimationDependency`;
- `VFXDependency`;
- `AudioDependency`;
- `ReducedEffectsRequirement`;
- `OwnerReviewRequired` yes/no;
- `RuntimeEvidenceRequired` yes/no.

These fields are production metadata, not a required literal Unreal class schema.

---

# 16. Production review gates

## Gate H-A — Classification complete

Pass when every Hush-relevant family has:

- semantic relationship class;
- H0–H5 burden;
- authority source;
- region/content family;
- state dependency.

This document passes H-A at **family level** for current principal art content.

Asset-instance enumeration comes later during production tracking.

## Gate H-B — Visual relationship proof

Requires representative concept/paintover proof for at minimum:

- Brindle ordinary paired state;
- one Cairnspire civic paired state;
- Rootmere living-system paired state;
- Mireglass reflection/memory state;
- Ilyra Hush state;
- Hush-Cairnspire H4 space;
- Still-Cairn appealing permanence state;
- Null Meridian finale synthesis state.

Documentation does not claim this proof exists yet.

## Gate H-C — Representative runtime proof

Requires later UE representation showing:

- post-process-reduced Hush remains identifiable;
- gameplay readability survives;
- active physical authority matches semantic state;
- paired expressions converge after world-state changes;
- no duplicate gameplay truth;
- transition presentation remains independent of semantic commit;
- reduced-effects mode preserves necessary information;
- performance is measured on target hardware.

Not authorized under the current documentation-only boundary.

## Gate H-D — Production closure

Requires:

- per-asset tracking populated;
- visual keys approved;
- representative runtime evidence;
- technical budgets measured;
- accessibility evidence;
- no unresolved semantic/art classification conflicts.

---

# 17. Decision rights

## LOCKED

- semantic relationship classes remain Gate 4 authority;
- H0–H5 definitions;
- region-family default burdens in this document;
- recognition-before-wrongness;
- no universal Hush color/filter/glitch language;
- regional identity survives;
- gameplay readability survives;
- post-process is support;
- ordinary population is not wholesale ghost-duplicated;
- Ilyra/Orin/Maelor residue distinctions require semantic classification;
- Hush-Cairnspire derives from recognizable Cairnspire;
- Still-Cairn useful permanence may be visually appealing;
- Null Meridian recombines established art language;
- Listener remains non-humanoid/non-demonic/non-godlike by default;
- Reduced Hush Effects preserves semantic/gameplay readability.

## STUDIO CHOICE WITHIN BOUNDS

- exact mesh reuse implementation;
- exact material graph implementation;
- exact dressing decomposition;
- exact light-authoring technique;
- exact fog/post-process technique;
- exact LOD/Nanite/streaming solution;
- exact source-art workflow;
- specific low-level effect implementation that preserves the matrix.

## OWNER REVIEW REQUIRED

- reclassification that materially changes a principal region/character/boss visual identity;
- new H5 family that materially changes world lore or finale identity;
- alternate Listener manifestation;
- turning an H3/H4 place into an unrecognizable alternate universe;
- major departure from the locked Hush visual grammar.

## RUNTIME / TECHNICAL EVIDENCE

- exact Data Layer/sublevel/streaming representation;
- final Hush material cost;
- reflection solution/cost;
- volumetric cost;
- VFX density/overdraw;
- asset duplication memory cost;
- transition timing;
- scalability tiers;
- target-PC performance acceptance.

---

# 18. Hard failure conditions

Reject Hush art if:

- a screenshot cannot be regionally identified without UI;
- a global LUT is doing most of the work;
- gameplay-critical geometry is obscured;
- a Hush duplicate implies a second history of gameplay facts;
- art invents route/collision/puzzle eligibility;
- every asset receives a variant merely because two layers exist;
- every living NPC receives a ghost copy;
- H4/H5 content stops using Stillring's established material/shape ancestry;
- Still-Cairn is obviously evil on sight rather than emotionally tempting;
- Ilyra becomes a translucent oracle;
- Maelor becomes visually possessed;
- the Listener becomes a conventional cosmic god/monster;
- Hush-Cairnspire becomes generic surreal city art;
- Reduced Hush Effects makes the layer or gameplay state unreadable.

---

# 19. Quoteable production burden

Current written authority implies the following production burden categories:

## Broad shared production

- H0 shared geometry/assets across all regions;
- H1 material/light variants for selected civic, water, character and machinery families;
- H2 dressing/occupancy/motion variants for settlements, archives, workspaces and ordinary-life anchors.

## Targeted higher-cost production

- H3 geometry-state variants for authored roots, routes, mechanisms, homes, instruments and key social/story spaces;
- H4 related substantial counterparts for selected regional hero spaces, Ilyra's refuge, Still-Cairn states, Hush-Cairnspire civic anchors and major late-game entities;
- H5 unique content primarily concentrated in late Hush residues/composites/Listener/finale-specific content rather than distributed across every region.

Production planning should therefore **not** budget “two full copies of the game world.”

It should budget a heavily shared base with selectively increasing authored divergence.

That is the central cost-control implication of H0–H5.

---

# 20. Remaining legitimate unknowns

This matrix closes the cross-content written production grammar.

Still legitimately open:

- exact count of individual assets in each H class;
- exact mesh/material duplication cost;
- exact Hush renderer/streaming implementation;
- exact shader/post-process/reflection/fog budgets;
- exact VFX implementation and cost;
- exact transition visual timing;
- exact technical representation of H4/H5 late-game spaces;
- representative visual keys/boards;
- representative runtime/performance/accessibility proof.

These are execution/runtime questions, not permission to reinterpret the Hush.

---

# 21. Next art-workstream step

The next bounded written art deliverable is:

> **VFX Production Manifest**

It must derive effect families from gameplay/story authority and this matrix, distinguish gameplay-critical from environmental/cinematic effects, define readability/accessibility/reduced-effects burdens, and avoid using VFX as a substitute for environment/character/Hush art.

---

# 22. Governing Hush production principle

The Hush is expensive only where meaning requires divergence.

Most of Orra should remain recognizable because recognition is the point.

> **Share what is truly shared. Change what meaningfully changes. Build new content only where the Hush actually contains something new.**
