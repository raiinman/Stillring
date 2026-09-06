# 158 — Character Production Manifest

**Status:** ACTIVE / PRE-PRODUCTION CHARACTER AUTHORITY  
**Updated:** 2026-09-05  
**Parent program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Art authority:** `docs/154_STILLRING_ART_BIBLE.md`  
**Production framework:** `docs/156_ART_PRODUCTION_MANIFEST_FRAMEWORK.md`  
**Narrative authority:** `docs/02_STORY_BIBLE.md`, `docs/story/01_FOUNDATIONS_AND_OPENING.md`, `docs/story/06_CHARACTER_ARCS_AND_RELATIONSHIPS.md`  
**Closes toward:** `SH-ART-001`, `SH-ART-002`, and the character-facing portion of `SH-ART-003`  
**Boundary:** documentation only; this file does not authorize UE5.8 implementation, final modeling, rigging, animation production, or final owner approval of faces/costumes.

---

# 1. Purpose

This document turns Stillring's character philosophy into a production package that an external character-art team can quote, concept, model, texture, rig, and hand off without reconstructing intent from chat history.

It answers:

- which characters require unique production treatment;
- what each character must communicate visually;
- what their occupations and histories imply for clothing and materials;
- what silhouette conflicts must be avoided;
- what story-state variants must be budgeted;
- what close-up/facial burden exists;
- what equipment and animation needs must be anticipated;
- what a concept artist may choose;
- what requires owner review;
- what cannot be finalized before rig/runtime evidence exists.

This is not a costume-fashion document.

Stillring characters must look like people whose bodies, clothing, tools, repairs, and posture have been shaped by ordinary work.

Core rule:

> **Occupation before archetype. Human history before fantasy decoration. Silhouette before surface detail.**

---

# 2. Authority order

Character production must resolve conflicts in this order:

1. canonical story/character facts;
2. `docs/154_STILLRING_ART_BIBLE.md`;
3. this manifest;
4. `docs/156_ART_PRODUCTION_MANIFEST_FRAMEWORK.md`;
5. approved concept sheets;
6. technical-production/rigging requirements;
7. runtime tuning and performance evidence.

Mood boards and generated images are directional only.

No external reference, Unreal default, MetaHuman preset, costume pack, fantasy convention, or artist preference may override canonical character identity.

---

# 3. Character production classes

Character production is divided into five classes.

## C0 — Player hero

### Neris Vale

Production burden:

- unique final model;
- full gameplay silhouette validation;
- complete locomotion/combat/tool/traversal compatibility;
- repeated cinematic close-up use;
- multiple progression/state variants;
- signature equipment attachment burden;
- highest rig/animation dependency;
- highest readability requirement.

Uniqueness: **U3 / game hero**.  
Final target: **Q3**, after concept and runtime dependencies are proven.

## C1 — Principal recurring cinematic cast

- Tessa Marr;
- Ilyra Vale;
- Orin Vale;
- Maelor Renn.

Production burden:

- unique head/face identity;
- unique costume silhouette;
- cinematic facial performance;
- recurring dialogue staging;
- story-state variants;
- major prop/tool interactions where applicable.

Uniqueness: **U3 or U2 depending technical reuse**, but visually unique.  
Final target: **Q3**.

## C2 — Major recurring world cast

- Brother Caldrin;
- Sena Ash;
- Prefect Aven Rusk.

Production burden:

- unique recognizable silhouette;
- named-character face;
- recurring gameplay dialogue;
- major story/civic scenes;
- region/state variants where required;
- less bespoke gameplay motion than C0/C1, but not generic population treatment.

Uniqueness: **U2/U3 visual identity**.  
Final target: **Q3**, with body/rig reuse allowed if silhouette integrity survives.

## C3 — Named regional recurring/support cast

These are recurring named people defined in regional narrative authority, quest ledgers, setup/payoff contracts, ordinary-life anchors, and world-pulse content.

Examples include regional workers, ferry operators, archivists, cooks, route staff, maintenance workers, teachers, civic officials, and quest owners.

These characters require:

- recognizable heads/silhouettes at conversational distance;
- region/occupation-specific costume treatment;
- continuity across world-state changes;
- controlled reuse rather than full bespoke hero production by default.

Final production class is assigned in the Region Production Manifest.

## C4 — Population archetypes

Unnamed or lightly recurring civilians and workers.

These use a bounded variation system:

- shared body/rig families;
- head/hair pools;
- region garment layers;
- occupational props;
- palette variation;
- age/life-stage variation;
- emergency/post-Stillness variants.

Population reuse must never make six cultures look like the same ten people wearing recolored hats.

---

# 4. Universal character art doctrine

## 4.1 Stylization band

Characters are grounded humans with controlled stylization.

The final look must preserve:

- believable anatomy;
- readable facial structure;
- clear eye/brow/mouth performance;
- strong head/hair mass;
- recognizable body silhouette;
- simplified skin treatment;
- selective detail.

Do not pursue:

- pore-first photorealism;
- scan-faithful facial noise;
- doll-smooth skin;
- anime facial proportions;
- exaggerated heroic bodybuilder anatomy;
- fashion-model uniformity;
- tiny costume clutter as identity.

The desired result should still read well in ordinary gameplay framing, not only in a portrait render.

## 4.2 Body diversity

The cast should visibly differ in:

- height;
- shoulder/hip relationship;
- build;
- posture;
- age/life-stage;
- hand size/read;
- gait implication;
- occupational wear.

Do not derive every named character from one idealized heroic base body.

Exact heights remain **TBD SCALE / OWNER-CONCEPT REVIEW** until Neris scale and camera representation are established.

Relative silhouette differences may be concepted now.

## 4.3 Hands

Hands are unusually important in Stillring because the fiction repeatedly centers on:

- repair;
- tuning;
- bells;
- tools;
- records;
- foundry work;
- route work;
- physical evidence.

Hero/principal characters require hands capable of readable close interactions.

Character art should plan for:

- useful finger separation;
- glove/no-glove logic;
- believable work wear;
- grip compatibility;
- tool contact;
- expressive hand acting in dialogue where relevant.

Hands must not become oversized cartoon forms, but may be slightly emphasized in silhouette where it benefits readability.

## 4.4 Hair

Hair is treated as authored shape before strand simulation.

Requirements:

- recognizable mass from gameplay distance;
- practical relationship to occupation/weather;
- animation-safe silhouette;
- no dependence on thousands of individual visible strands for identity;
- wet/wind/ash behavior only where production value justifies it.

Hair technology remains a studio/technical choice.

## 4.5 Skin

Skin must support facial performance and life history without becoming a photoreal material showcase.

Use:

- controlled tonal variation;
- region/labor-appropriate exposure;
- age-appropriate structure;
- restrained blemishes/scars only when character-relevant;
- readable lips/eyes/brows.

Avoid:

- excessive pore/noise maps;
- universal beauty retouching;
- universal grime;
- random scars added for "character."

## 4.6 Clothing construction

Clothes must appear wearable, repairable, and adapted to work.

Every principal costume must answer:

- what is the base layer?
- what protects against local weather/work?
- what opens/closes the garment?
- where are repeated repairs?
- what gets dirty first?
- what is replaced most often?
- where are tools carried?
- what must remain clear of hands, knees, ladders, ledges, weapons, or machinery?
- what visually communicates social role?

Avoid ornamental straps, belts, buckles, pauldrons, pouches, spikes, dangling charms, or armor plates without function.

## 4.7 Repair language

Stillring clothing should often show maintenance rather than decay.

Useful signals:

- visible re-stitching;
- replaced cuffs;
- patched knees/elbows;
- re-oiled leather;
- reinforced tool-contact points;
- mismatched but practical replacement hardware.

This is preferable to generic dirt and rips.

## 4.8 Fasteners and metalwork

Fasteners should belong to Stillring's material culture.

Favor:

- simple hooks;
- toggles;
- tied closures;
- buckles where load-bearing use explains them;
- region-specific maker hardware;
- repairable mechanical closures.

Avoid decorative "fantasy metal everywhere."

## 4.9 Footwear

Footwear is a production-critical visual and animation concern.

Neris and route-active characters need footwear that can plausibly support:

- long travel;
- ladders;
- uneven ground;
- wet surfaces;
- workshops;
- combat movement.

Regional NPCs may have more specialized footwear.

Exact sole/ankle design is concept-driven but must later validate against foot IK, slope animation, water, and traversal.

---

# 5. Character readability tests

Every C0–C2 character must pass these concept reviews before final model approval.

## 5.1 Black silhouette test

At gameplay framing, can the character be distinguished from every other principal character without face, texture, or color?

## 5.2 Head-shape test

At conversational medium shot, can the character be identified from hair/head/neck/shoulder mass without costume color?

## 5.3 Occupation test

Can a viewer infer the character does real work or belongs to a specific institution/region before being told their lore?

## 5.4 Flat-color test

Does the design survive with only 4–6 large color/material masses?

## 5.5 Hand/prop test

Does the design remain readable while holding or using its most important prop?

## 5.6 Motion test

Does the costume preserve readable limbs and center-of-mass during key animation?

## 5.7 No-face test

If the face were blurred, does the character remain identifiable?

If not, the costume/body silhouette is too generic.

---

# 6. Character palette rules

Characters should harmonize with their home culture without disappearing into the environment.

Rules:

- principal characters receive a controlled identity accent;
- no principal cast member should be identified only by one bright color;
- palette must survive night/weather/Hush shifts;
- color-critical identity requires shape/material redundancy;
- dyes should feel culturally/materially plausible;
- not every important person wears saturated hero colors;
- avoid MMO rarity-color logic.

Principal cast palette relationships are **directional**, not final hex values.

---

# 7. Shared production deliverables for C0–C2 characters

Each C0–C2 character must receive the following deliverable package before final modeling lock.

## Concept package

1. **Narrative/occupation brief** — one page.
2. **Silhouette sheet** — minimum 12 materially different silhouettes.
3. **Body/build exploration** — bounded range, not cosmetic body sliders.
4. **Head/hair exploration** — several clearly different shape directions.
5. **Costume construction sheet** — front/back/side, layer breakdown.
6. **Material callout sheet** — cloth/leather/metal/wood/ceramic/etc.
7. **Palette exploration** — minimum 3 viable controlled palettes.
8. **Prop/equipment integration sheet** — carried/worn/stowed states.
9. **Movement stress poses** — crouch substitute not required, but stride, run, climb/ladder/working poses as relevant.
10. **State/variant sheet** — story-required variants.
11. **Expression range sheet** for C0/C1 and selected C2 characters.
12. **Close-up paintover/reference frame** showing final stylization band.

## Model package

Required later at Q3:

- clean neutral body/head source;
- costume layers separated where production requires variants;
- material IDs organized by real production need;
- footwear/glove/prop attachment compatibility;
- facial topology appropriate to selected performance solution;
- deformation-sensitive areas validated with rig/animation;
- hidden geometry policy documented;
- source files and provenance retained.

## Texture/material package

Must include:

- readable base material separation;
- authored wear hierarchy;
- state-specific dirt/damage only where required;
- no random micro-detail pass as a finishing substitute;
- scalable material setup consistent with later technical budgets.

## Rig handoff package

Character art must provide:

- costume deformation notes;
- rigid/semi-rigid parts;
- secondary motion candidates;
- attachment locations;
- cloth/hair dependencies;
- facial design landmarks;
- areas where silhouette must not collapse in motion.

The Animation Bible later owns final rig/animation architecture.

---

# 8. Variant taxonomy

Variants must be planned intentionally; avoid creating a new full character mesh for every story state.

## V0 — Base identity

Default stable costume/body identity.

## V1 — Work/travel configuration

Same identity with practical changes such as:

- outer layer removed/added;
- tool roll attached;
- rain/wind protection;
- gloves/apron;
- courier load;
- foundry protection.

## V2 — Crisis/wear state

Only when story requires:

- dirt;
- wetness;
- ash;
- damaged garment;
- improvised repair;
- bandage.

This must be causally specific.

## V3 — Hush state

Not automatically a separate model.

Possible burden:

- material/light relationship;
- repeated/incorrect detail;
- altered wear;
- silhouette/presentation changes;
- unique state pieces where canon requires.

The Hush matrix later classifies each character's exact burden.

## V4 — Post-Stillness adaptation

Visible consequence or practical adaptation after the midpoint catastrophe.

## V5 — Epilogue

Used only when the ending genuinely needs a changed visual state.

The epilogue should generally communicate lived change through practical modification, not "final armor."

---

# 9. Neris Vale — C0 player hero manifest

**Production class:** C0 / U3 / Q3 final target  
**Status:** CANON REQUIREMENT / DIRECTIONALLY BOUNDED / FINAL FACE-COSTUME OWNER REVIEW REQUIRED  
**Canonical identity:** seventeen-year-old apprentice bellwright from Brindle; mechanically gifted; practical; curious about regional repair practice; not chosen, royal, prophesied, reincarnated, or secretly magical.

## 9.1 Visual thesis

> **A village apprentice who grows into a traveling field bellwright without ever visually turning into a chosen-one warrior.**

Neris should initially look like someone who expected to spend the day repairing civic machinery, not fighting monsters.

By late game, progression should read as accumulated practical capability and travel history rather than prestige armor escalation.

## 9.2 Primary silhouette

Required:

- compact, mobile workwear silhouette;
- hands and forearms visually available for tool interaction;
- legs/knees unobscured enough for traversal animation;
- no floor-length coat or cape in base identity;
- no oversized shoulder armor;
- no royal/chosen iconography;
- no assassin-hood silhouette;
- no giant weapon profile dominating the body;
- Cantor Key must integrate as a recognizable but not magical-totem attachment.

Directional concept target:

- practical upper layer ending around upper thigh or shorter;
- asymmetry may come from tool carry or repair layering, not ornamental fantasy design;
- one strong diagonal or side-mounted equipment line may help identify Neris in motion;
- silhouette should remain youthful without making Neris childlike.

## 9.3 Body/build direction

Locked outcome:

- physically credible for climbing, swimming, running, tool use, and combat;
- not bodybuilder heroic;
- not frail waif coding;
- age 17 must remain visually believable;
- body should suggest active manual work without impossible combat conditioning.

Exact build requires owner-approved concept.

## 9.4 Face direction

Required:

- readable curiosity, irritation, concentration, grief, humor, and silence;
- age-appropriate features;
- strong brow/eye communication;
- no idealized fantasy-prince/princess beauty template;
- no resemblance-dependent identity borrowed from an actor or famous game character.

Final face is **OWNER REVIEW**.

## 9.5 Hair direction

Required:

- practical around workshop/tools;
- strong shape from gameplay framing;
- animation-safe;
- can become wet/disordered without requiring a completely different groom.

Exact cut/color is owner review after concept exploration.

## 9.6 Costume construction logic

Base costume must visibly support bellwright work.

Required functions:

- durable base shirt/undershirt;
- work outer layer or reinforced overshirt/jacket;
- lower-body garment allowing full stride and ladder movement;
- tool-compatible belt/harness solution;
- durable travel footwear;
- optional removable work gloves rather than mandatory permanent gloves;
- at least one visible repair/replacement that implies ordinary maintenance.

Concept should explore workwear-derived silhouettes rather than armor-derived silhouettes.

Strong concept lane:

- short practical jacket/overshirt;
- reinforced forearm/cuff treatment;
- small utility/tool side rather than a belt covered in pouches;
- sturdy trousers with region-neutral enough construction to travel;
- boots designed for workshop and road;
- subdued cloth/leather/metal mix.

This lane is directional, not a final garment lock.

## 9.7 Palette direction

Neris must remain readable across all six regions.

Recommended relationship:

- grounded neutral base;
- one warmer human accent inherited from Brindle/workshop life;
- restrained cool/metal detail around technical equipment;
- progression accents come from tools and repairs, not rainbow costume swaps.

Avoid:

- heroic pure white;
- royal purple coding;
- permanent black assassin palette;
- saturated franchise-like green hero shorthand;
- red-as-main-character by default.

Exact palette is owner concept review.

## 9.8 Cantor Key integration

The Key is a U3 signature prop and requires a dedicated joint concept package with Neris.

Must define:

- neutral stowed location;
- draw/use path;
- two-hand/one-hand states if applicable;
- collision-safe relationship to mantle/ledge/ladder animation;
- swim/travel handling;
- cinematic hand contact;
- readable prong/weight/hammer silhouette;
- later mode additions without turning it into a glowing fantasy weapon.

The Key must look engineered, repairable, and used.

## 9.9 Progression visual philosophy

Neris does not receive a sequence of rarity costumes.

New capabilities may add or replace functional components:

- Anchor Line carry solution;
- Glasslung-related travel hardware;
- Temper Gauntlet;
- Vane Cloak;
- Mirror Nail;
- seam-mode/late Key changes;
- other canonical tools.

Rules:

- additions must not destroy the original recognizable silhouette;
- attachment clutter must be managed;
- some tools may be context-stowed rather than permanently visible;
- late-game Neris should look traveled and equipped, not transformed into a different genre archetype.

## 9.10 Animation burden

Neris character art must support:

- analog locomotion;
- Sprint;
- jump/fall/land;
- mantle;
- ledge hang/shimmy/pull-up/release;
- ladders;
- surface swimming;
- slope scramble/slide;
- target-lock locomotion;
- combat attacks/guard/evade/reactions;
- Cantor interactions;
- field-tool interactions;
- Line Skiff use;
- cinematic close-ups;
- workbench/repair animation;
- environmental interactions.

No garment, hair mass, rigid prop, or attachment may be approved without stress-testing these categories conceptually.

## 9.11 Required variants

Minimum anticipated burden:

- `NERIS_V0_BRINDLE_APPRENTICE` — base opening identity;
- `NERIS_V1_FIELD_TRAVEL` — practical field configuration;
- `NERIS_V2_POST_GRAND_RING` — story-specific wear/adaptation, not generic battle damage;
- `NERIS_V3_HUSH_PRESENTATION` — exact representation TBD Hush matrix;
- `NERIS_V4_LATE_TOOL_LOADOUT` — functional accumulated capability;
- `NERIS_V5_EPILOGUE_TRAVELING_BELLWRIGHT` — changed but recognizably the same person.

These may share the same body/base costume architecture. They are production states, not necessarily separate meshes.

## 9.12 Hard failures

Reject any Neris concept that reads primarily as:

- legendary swordsman;
- assassin;
- prince/princess;
- mage;
- knight;
- anime protagonist;
- generic leather RPG adventurer;
- miniature adult;
- photoreal actor scan.

## 9.13 Owner-review package

Before final Neris model approval, owner must see:

- 12+ black silhouettes;
- 3 narrowed body/build directions;
- 3 distinct head/hair directions;
- 3 costume construction directions;
- 3 palette directions;
- Cantor stow/use integration;
- traversal stress poses;
- one representative gameplay-distance render;
- one representative cinematic close-up.

Owner approval chooses identity; technical review then validates feasibility.

---

# 10. Tessa Marr — C1 principal recurring manifest

**Canonical role:** route courier; closest ally; knows roads, smugglers, old signal towers, cheap inns, old route infrastructure; later accepts durable civic responsibility.  
**Production class:** C1 / visually unique / Q3 target.

## 10.1 Visual thesis

> **A person built by distance, weather, shortcuts, and carrying things for other people.**

Tessa should read as a working courier before reading as a rogue.

Do not turn "sharp-tongued courier with forged-manifest history" into a fantasy smuggler cliché.

## 10.2 Silhouette

Required:

- travel-forward body/costume massing;
- asymmetric load/carry logic is appropriate;
- clear leg movement;
- outerwear designed for road weather;
- recognizably different from Neris's workbench/tool silhouette;
- should plausibly board/use route infrastructure and Line Skiff.

Avoid:

- hooded thief silhouette;
- dagger-bandolier cliché;
- excessive hidden pockets as personality;
- pirate styling unless regionally justified by actual route culture.

## 10.3 Costume logic

Must visibly solve:

- weather changes;
- long travel;
- carrying documents/small freight;
- quick access to route tools;
- repeated repair;
- sitting/riding/boarding;
- cheap practical replacement rather than prestige tailoring.

Useful concept elements:

- layered weatherproof outer piece;
- route bag/satchel with believable load points;
- scarf/wrap or neck protection where useful;
- reinforced footwear;
- route markers/tags only if grounded in courier practice.

## 10.4 Palette

Tessa may carry a stronger travel/route accent than Neris, but avoid "rogue red" cliché.

Palette should remain readable in Saltreach weather, road dust, and changed-world rescue scenes.

## 10.5 State burden

Anticipate:

- ordinary courier state;
- Saltreach/travel weather state;
- post-Grand-Ring relief-network state;
- Line Skiff/route coordination configuration;
- epilogue civic-responsibility continuation.

Her later responsibility should change practical equipment/organization more than fashion status.

## 10.6 Face/performance

Tessa needs strong conversational performance because humor, avoidance, confession, frustration, and durable loyalty all matter.

Avoid permanently smirking "sarcastic sidekick" face design.

## 10.7 Hard failure

Reject if she reads primarily as:

- thief;
- pirate;
- sexy rogue;
- comic-relief mascot;
- leather-clad adventurer with no courier function.

---

# 11. Ilyra Vale — C1 principal recurring manifest

**Canonical role:** brilliant field bellwright; Neris's mother; Quiet Court collaborator; Mercy Window author; trapped in Hush for eleven years; returns with disrupted temporal/emotional continuity.  
**Production class:** C1 / U3 visual identity / Q3 target.

## 11.1 Visual thesis

> **A field engineer whose competence survives eleven years of wrong time.**

Ilyra must not visually become a mystical Hush oracle.

Her identity is engineering first.

## 11.2 Silhouette

Required:

- mature working bellwright silhouette;
- distinct from Neris while allowing believable family resemblance if final face direction supports it;
- practical tool/work posture;
- Hush state must preserve recognition;
- no robes-of-the-wise-woman transformation.

## 11.3 Costume logic

Pre-disappearance clothing should plausibly support:

- field measurement;
- mechanism access;
- tool carry;
- climbing/service spaces;
- technical note work;
- weather exposure.

Hush survival must not automatically produce eleven years of ordinary physical garment decay if canon/representation does not support it. The Hush state should be authored according to its own material logic.

## 11.4 Hush burden

Ilyra is one of the highest-priority Hush character studies.

Concept must explore wrongness through controlled relationships such as:

- repairs that repeat rather than progress;
- garment state inconsistent with elapsed Waking time;
- selective wear/stillness;
- subtle mismatch between remembered and current self-presentation;
- lighting/material behavior that does not turn her into a ghost.

Do not use:

- translucent ghost body;
- generic blue glow;
- black corruption veins;
- floating magical cloth by default.

## 11.5 Face/performance

Ilyra needs one of the strongest facial-performance designs in the game.

Must support:

- seeing Neris as the child she remembers;
- recognition delay;
- shame;
- technical concentration;
- restrained affection;
- uncertainty;
- direct admission without melodramatic villain guilt.

## 11.6 State burden

- pre-disappearance archival/flashback state where required;
- Hush survival state;
- reunion state;
- Cairnfall working collaboration state;
- returned/epilogue state showing difficulty rather than magical recovery.

## 11.7 Hard failure

Reject if she reads primarily as:

- mystical mother;
- saint;
- witch;
- ethereal chosen engineer;
- innocent victim visually purified by the Hush.

---

# 12. Orin Vale — C1 principal recurring manifest

**Canonical role:** practical village repairman; Neris's father; loving but secretive; taken through the Brindle seam; later preserved inside Still-Cairn defensive states.  
**Production class:** C1 / unique head and silhouette / Q3 target.

## 12.1 Visual thesis

> **The person who taught Neris ordinary repair, not a hidden mastermind or warrior.**

Orin must establish the Vale workshop as a lived family/work space.

## 12.2 Silhouette

Required:

- grounded village repairman;
- visibly older/more settled work silhouette than Neris;
- practical hands/forearms/tool posture;
- no secret-master visual coding;
- clear family relation may come through selected facial/material echoes, not matching costumes.

## 12.3 Costume logic

Must support:

- workshop work;
- village service/repair calls;
- First Ring opening ceremony context without becoming ceremonial elite dress;
- later Still-Cairn recognition.

His clothing should be familiar enough that preserved variants carry emotional weight.

## 12.4 Still-Cairn burden

Orin's late-game visual production must distinguish:

- the actual Orin;
- preserved/safe-state presentation;
- workshop memories or repeated arena-state logic.

The design must preserve humanity rather than turning him into a boss-monster aesthetic unless encounter authority explicitly requires a gameplay-driven state.

## 12.5 Hard failure

Reject if he reads as:

- secret knight;
- master wizard-engineer;
- conspirator;
- martyr-saint;
- obvious doomed-father cliché built entirely from visual sentimentality.

---

# 13. Maelor Renn — C1 principal recurring manifest

**Canonical role:** chief acoustician; engineer; Quiet Court founder; antagonist; calm, useful, competent, grief-driven, coercive; not a ruler seeking power.  
**Production class:** C1 / U3 principal antagonist / Q3 target.

## 13.1 Visual thesis

> **The most dangerous engineer in the story should initially look like someone whose advice you would trust.**

Maelor must not be visually spoiled as "the villain" on first sight.

## 13.2 Silhouette

Required:

- controlled, precise, mature professional silhouette;
- visually distinct from Rusk's administrative authority and Caldrin's archival/monastic identity;
- no spiked, black, demonic, or villain-coded costume massing;
- deliberate restraint;
- should look capable of field/technical work even if his current role is senior.

## 13.3 Costume logic

His clothing should suggest:

- technical authority earned through work;
- long association with Meridian infrastructure;
- precision;
- maintenance/measurement familiarity;
- institutional proximity without reducing him to uniform bureaucracy.

Avoid luxury as a shorthand for villainy.

## 13.4 Palette

Use calm, controlled values.

Do not make the antagonist the only person wearing black/red.

If a late Stillring-state palette changes, it should express the engineered system and his narrowing doctrine—not "evil mode."

## 13.5 Face/performance

Critical expressions:

- attentive listening;
- precise explanation;
- genuine concern;
- fatigue;
- grief held under control;
- anger that matters because it is rare;
- certainty becoming coercion;
- final loss without instant redemption.

Do not design a perpetual villain smirk, dead eyes, or predatory facial shorthand.

## 13.6 State burden

- Act One trusted expert;
- Grand Ring reveal/confrontation;
- post-Stillness system-maintenance state;
- Null Meridian final confrontation;
- trial/ending representation where shown.

The visual throughline must remain the same human being.

## 13.7 Hard failure

Reject if he reads primarily as:

- dark lord;
- evil priest;
- dictator;
- aristocrat;
- possessed scientist;
- anime mastermind;
- disheveled mad inventor.

---

# 14. Brother Caldrin — C2 major recurring manifest

**Canonical role:** High Aerie archivist; gentle but stubborn monk-engineer; decades spent preserving damaged bell records; learns to preserve provenance and contradiction rather than one authorized master copy.  
**Production class:** C2 / unique named identity / Q3 target.

## 14.1 Visual thesis

> **A working archivist-engineer whose monastic identity is practical stewardship, not fantasy priesthood.**

## 14.2 Silhouette

Required:

- readable archive/monastery identity;
- weather/adaptation to High Aerie;
- hands capable of handling records/tools;
- clear separation from Maelor's technical authority and Rusk's civic administration;
- age/life-stage should support "decades" of work without forcing frailty.

## 14.3 Costume logic

Combine:

- practical mountain layering;
- archive protection/storage;
- maintenance/technical work;
- institutional/monastic signifiers kept restrained.

Avoid generic hooded monk robe if it would interfere with the working-engineer identity.

## 14.4 Prop language

Possible signature burden should derive from canon:

- record cases;
- repair bindings;
- annotation tools;
- archival seals/provenance tags;
- technical measuring aids if justified by scenes.

Do not invent mystical relics.

## 14.5 State burden

- Cairnspire/archive appearances;
- High Aerie regional work;
- institutional fracture/authority-seal break;
- later public provenance archive state.

His later visual change should show changed practice, not superhero promotion.

---

# 15. Sena Ash — C2 major recurring manifest

**Canonical role:** veteran Emberstep foundry leader/kiln captain; trained caster; coordinates safety/production; strong advocate for traceable maker responsibility.  
**Production class:** C2 / regional hero identity / Q3 target.

## 15.1 Visual thesis

> **A foundry leader who looks credible standing beside dangerous heat and telling everyone else exactly what is unsafe.**

## 15.2 Silhouette

Required:

- physically grounded working-leader silhouette;
- foundry protection integrated into identity;
- strong readable stance without fantasy-warrior armor;
- clearly different from Neris's light field mobility;
- veteran competence should come from posture/material choices, not scars and muscles alone.

## 15.3 Costume logic

Must visibly address:

- radiant heat;
- sparks;
- heavy tools;
- dust/ash;
- production-floor authority;
- inspection/public scenes.

Potential materials:

- heavy woven cloth;
- treated leather where functional;
- ceramic/metal heat guards where plausible;
- removable work protection.

Do not cover her in ornamental forge armor.

## 15.4 Wear logic

Emberstep wear should be specific:

- heat discoloration;
- ash;
- polished tool-contact areas;
- replaced protection;
- maker marks.

Avoid universal soot-face treatment.

## 15.5 State burden

- active kiln-captain work state;
- public/investigation scenes;
- Grand Ring crisis;
- changed-world distributed production;
- epilogue maker-name/traceability role.

---

# 16. Prefect Aven Rusk — C2 major recurring manifest

**Canonical role:** Bellwarden administrator; believes standards, controlled access, and public confidence prevent harm; participates in secrecy; later chooses people over procedure when the system becomes dangerous.  
**Production class:** C2 / unique institutional identity / Q3 target.

## 16.1 Visual thesis

> **A competent public administrator whose authority is understandable before its limits become clear.**

Rusk must not look like a cartoon bureaucratic villain.

## 16.2 Silhouette

Required:

- structured institutional silhouette;
- less field-work clutter than Neris/Maelor;
- controlled posture;
- recognizable authority without aristocratic luxury;
- silhouette must remain practical enough for emergency action during the Grand Ring.

## 16.3 Costume logic

Should communicate:

- public office;
- Bellwarden standardization;
- document/access authority;
- civic duty;
- enough practical familiarity with infrastructure that emergency action is believable.

Institutional markings should be systematic and reproducible across Bellwarden population costumes.

## 16.4 Palette

Rusk may embody the Bellwarden institutional palette, but should not monopolize it.

Authority should come through cut, construction, insignia placement, and maintenance quality—not only saturated color.

## 16.5 State burden

- Cairnspire administrative state;
- investigation/restricted-access scenes;
- Grand Ring emergency response;
- changed-world cooperation outside old legitimacy;
- trial/testimony/ending state where shown.

His later appearance should not become visually "liberated rebel Rusk." He remains recognizably institution-shaped while changing behavior.

---

# 17. The Listener — special character/entity presentation

**Canonical role:** emergent consciousness of the Hush; not god, demon, villain, or human personality; contains unfinished possibilities; final desire involves release from forced singularity.  
**Production class:** SPECIAL / cross-owned by character art, environment art, VFX, narrative, and finale production.

## 17.1 Visual thesis

> **The Listener should feel like many incomplete possibilities becoming briefly legible, not a monster waiting behind reality.**

## 17.2 Prohibitions

Do not default to:

- giant humanoid god;
- masked deity;
- cosmic woman/man;
- black shadow demon;
- tentacle entity;
- glowing angel;
- giant eye;
- evil face in the sky;
- abstract particle blob with no authored meaning.

## 17.3 Production approach

The Listener may be represented through combinations of:

- borrowed/echoed spatial forms;
- incomplete human-scale gestures;
- preserved memories;
- environment relationships;
- controlled material contradictions;
- silhouette fragments;
- voice/subtitle/presentation systems;
- save-state-sensitive familiar imagery where canon calls for it.

The final representation requires dedicated owner review because it materially affects Stillring's ending identity.

The Listener is not closed by this manifest.

---

# 18. Principal cast silhouette separation matrix

| Character | Primary visual read | Must not overlap with |
|---|---|---|
| Neris | mobile apprentice field-worker + compact tool carry | Tessa rogue/courier silhouette; Maelor technical authority |
| Tessa | weathered route courier + travel load | assassin/thief; Neris tool-worker |
| Ilyra | mature field bellwright + Hush continuity | mystical oracle; Neris duplicate |
| Orin | settled village repairman | secret master; Maelor engineer-leader |
| Maelor | restrained senior acoustician/engineer | dark lord; Rusk bureaucrat; Caldrin monk |
| Caldrin | mountain archivist-engineer | generic priest; Maelor scholar |
| Sena | foundry captain / heat-work authority | armored warrior; generic blacksmith NPC |
| Rusk | structured civic administrator | aristocrat; villain official; Maelor technical silhouette |

Concept review should display all eight as flat black silhouettes on one sheet.

If two are hard to distinguish at that stage, revise before detail work.

---

# 19. Relationship-based visual echoes

Visual relationships may use subtle shared language, but must never become costume uniforms for thematic ideas.

## Neris / Ilyra

Possible echoes:

- hand/tool posture;
- one facial structural relationship;
- workwear construction logic;
- a repeated practical habit in equipment arrangement.

Do not make them matching outfits.

## Neris / Orin

Possible echoes:

- repair patches;
- workshop material language;
- footwear/tool storage tradition;
- small family-made component.

## Ilyra / Maelor

Their past collaboration may be visible through shared technical-era design language or instrument culture, but current silhouettes must communicate divergence.

## Maelor / Rusk

Both have institutional proximity but should split clearly:

- Maelor = technical precision;
- Rusk = procedural/civic structure.

## Tessa / regional routes

Tessa may accumulate regionally sourced repairs or practical substitutions over time, visually supporting how widely she travels.

This must remain controlled; she should not become a walking souvenir rack.

---

# 20. Costume state-change philosophy

Major story change should not automatically trigger a wardrobe change.

A new costume or visible modification requires one of:

- new functional burden;
- changed occupation/responsibility;
- environmental necessity;
- damaged/repaired garment caused by a specific event;
- time/epilogue passage;
- Hush-state requirement;
- strong narrative reason.

Do not use new outfits simply to mark acts.

Stillring's people should often keep and repair the same things.

That continuity helps places and relationships feel real.

---

# 21. Character damage, dirt, and weather

Damage states must remain specific.

## Wetness

Use when:

- swimming;
- rain;
- spray;
- marsh/coastal exposure.

Wetness should affect selected cloth/hair/material response, not automatically turn the whole character glossy.

## Ash/dust

Use regionally and causally.

Do not apply universal adventure grime after every combat encounter.

## Blood/injury

Only where narrative/gameplay rating and final art direction authorize it.

Do not make injury the primary visual shorthand for seriousness.

## Repair

After important damage, later visible repair may be more Stillring-specific than leaving permanent torn clothing.

---

# 22. Facial performance production tiers

## F0 — Player/principal performance

Neris, Tessa, Ilyra, Orin, Maelor.

Requires:

- full dialogue facial rig target;
- close-up-safe deformation;
- strong brows/eyes/mouth;
- asymmetry capability;
- subtle listening/hesitation;
- restrained emotion, not only broad phoneme performance.

## F1 — Major recurring performance

Caldrin, Sena, Rusk and selected regional leads.

Requires:

- credible dialogue;
- medium-close staging;
- emotion range appropriate to scenes;
- reduced bespoke facial burden relative to F0 where necessary.

## F2 — Population dialogue

Requires readable basic speech/emotion but may use shared systems.

Exact facial technology belongs to the Animation Bible/Technical Production Bible.

---

# 23. Body/rig reuse policy

Reuse is encouraged when it does not erase identity.

Allowed in principle:

- common underlying skeleton;
- compatible base topology families;
- shared material systems;
- shared garment construction components;
- shared facial rig architecture;
- retargeting where deformation remains acceptable.

Not allowed:

- same body proportions for all major characters because it is convenient;
- head swaps on identical hero bodies when silhouette needs differ;
- forcing Sena, Caldrin, Rusk, Tessa, Maelor, and Orin into one costume-compatible body if it damages identity;
- shrinking/stretching a base mesh until anatomy becomes visibly wrong.

The Animation Bible will select final rig families.

---

# 24. Named regional cast production rule

The full region manifests will enumerate every recurring named character.

Until then, the following rule is binding:

Any named regional NPC who appears in more than one meaningful story/world state or owns a significant quest/relationship chain must receive at minimum:

- identity brief;
- silhouette/occupation concept;
- named face/head solution;
- region costume assignment;
- prop/work assignment;
- state continuity notes;
- reuse classification;
- dialogue/facial tier;
- post-Stillness requirement where applicable.

A recurring named character may not silently use a random generic population combination if doing so undermines recognition across revisits.

---

# 25. Population variation strategy — preliminary authority

This section partially closes `SH-ART-003` without pretending final counts exist.

## 25.1 Shared human foundation

Orra's regions are culturally distinct human populations, not six visual species.

Use controlled shared production systems with regional differentiation.

## 25.2 Variation axes

Population should vary across:

- body build;
- height range;
- age/life stage;
- face shape;
- skin tone;
- hair texture/style;
- garment layer combinations;
- occupational gear;
- regional palette;
- repair/wear state;
- weather protection;
- post-Stillness adaptation.

## 25.3 Region identity

Regional differentiation should rely strongly on:

- construction methods;
- climate adaptation;
- labor equipment;
- material availability;
- local fasteners;
- footwear;
- outerwear;
- civic markings;
- occupational props.

Avoid costume caricature.

## 25.4 Reuse rule

A body/head may recur across distant background population only when:

- wardrobe/hair/palette changes are sufficient;
- the same face is not repeatedly visible in close recurring scenes;
- named NPC recognition is protected;
- crowd repetition does not become obvious in small settlements.

Exact pool counts remain `TBD PRODUCTION / REGION MANIFEST`.

---

# 26. Character concept-board requirement

`Board 03 — Character Style Band` remains required.

It should not merely show attractive portraits.

It must include:

- Neris body/face/costume options;
- all C1/C2 silhouettes together;
- stylization band examples from too realistic → target → too stylized;
- hand/tool readability;
- hair-shape treatment;
- skin-detail treatment;
- costume material hierarchy;
- gameplay-distance comparisons;
- cinematic close-up comparisons;
- do/don't examples.

The board is subordinate to this document.

---

# 27. Character production acceptance gates

## Gate C-A — Canon brief complete

Pass when:

- role;
- occupation;
- states;
- relationships;
- prohibitions;
- production class

are documented.

All C0–C2 characters pass this documentation gate under this manifest.

## Gate C-B — Silhouette approval

Requires:

- group silhouette sheet;
- occupation read;
- no major confusion;
- owner review for Neris and materially identity-defining principal directions.

Not yet passed.

## Gate C-C — Concept approval

Requires:

- selected head/body/costume;
- material sheet;
- palette;
- props;
- state variants;
- gameplay stress poses.

Not yet passed.

## Gate C-D — Representative model

Requires:

- one Neris Q2 model;
- representative principal NPC Q2 model;
- representative population character;
- gameplay/cinematic lighting tests;
- animation deformation test;
- technical/performance evidence.

Runtime gate; not authorized yet.

## Gate C-E — Final production

Requires final concept, rig, material, performance, platform, and production approval.

Not authorized under current documentation-only boundary.

---

# 28. Decision-rights matrix

## LOCKED

- grounded controlled stylization;
- occupation-before-archetype principle;
- Neris is a 17-year-old apprentice, not chosen/royal/mystical;
- Tessa reads as courier, not rogue cliché;
- Ilyra reads as engineer, not oracle;
- Orin reads as repairman/father, not secret master;
- Maelor must initially remain visually trustworthy and human;
- Caldrin is archivist-engineer, not generic priest;
- Sena is foundry leader, not armored warrior;
- Rusk is credible administrator, not cartoon villain;
- Listener is not default humanoid god/demon;
- clothing must be functional and repairable;
- named-character silhouettes must remain distinct;
- final art cannot rely on photoreal surface detail for identity.

## STUDIO CHOICE WITHIN BOUNDS

- exact garment seam layout;
- fastener details;
- topology;
- UV/material implementation;
- hair technology;
- cloth simulation technology;
- body/rig sharing architecture;
- palette values within approved relationships;
- subtle scars/blemishes where non-canonical and non-identity-changing;
- ordinary wear placement consistent with work.

## OWNER REVIEW

- final Neris face;
- final Neris body/build;
- final Neris base costume;
- final Neris primary palette;
- final principal cast concepts when materially different identity directions exist;
- Listener final visible presentation;
- any major departure from grounded stylization;
- any concept that materially changes story identity.

## RUNTIME / ANIMATION / TECHNICAL EVIDENCE

- final character scale in centimeters;
- exact rig/skeleton families;
- cloth/hair simulation budget;
- material slot/texture budgets;
- topology density;
- deformation limits;
- facial technology;
- final attachment placements under animation;
- performance scalability.

---

# 29. Quoteable production burden — current minimum

The studio should currently budget, at minimum:

## Unique principal identity work

- 1 C0 player hero: Neris;
- 4 C1 principal recurring characters: Tessa, Ilyra, Orin, Maelor;
- 3 C2 major recurring characters: Caldrin, Sena, Rusk;
- 1 special Listener presentation family;
- named C3 regional characters to be counted in Region Production Manifests;
- C4 population systems per regional culture.

## Required concept packages

Minimum unique high-priority concept packages now known:

- Neris;
- Tessa;
- Ilyra;
- Orin;
- Maelor;
- Caldrin;
- Sena;
- Rusk;
- Listener presentation exploration.

This is **nine visual-development packages**, not nine guaranteed unique technical body rigs.

## Required state burden

At least several principals require multiple authored states:

- Neris — opening, field, post-catastrophe, late-tool, Hush presentation, epilogue;
- Tessa — courier, relief-network/Skiff, later civic responsibility;
- Ilyra — pre-disappearance/Hush/reunion/returned;
- Orin — opening/Still-Cairn/preserved-state/ending;
- Maelor — trusted expert/Grand Ring/post-Stillness/finale/trial if shown;
- Caldrin — archive/High Aerie/authority-break/later archive;
- Sena — foundry/crisis/distributed-production;
- Rusk — administrative/crisis/later accountability.

The exact number of separate meshes/material variants is not yet locked.

---

# 30. What remains genuinely open

This manifest deliberately does **not** pretend the following are settled:

- Neris final face;
- Neris final hair;
- Neris exact body build;
- Neris exact costume;
- Neris exact palette;
- exact adult cast ages where canon does not specify them;
- exact heights;
- exact ethnic/facial casting directions;
- final C1/C2 faces;
- final costume silhouettes after concept exploration;
- final Listener manifestation;
- exact population pool counts;
- exact rig count;
- exact topology/texture/material budgets;
- exact facial animation technology;
- exact cloth/hair technology;
- exact Hush character representation method.

These unknowns are visible production gates, not permission for silent assumptions.

---

# 31. Next required character-art work

Documentation sequence after this file:

1. create **Board 03 — Character Style Band** using this manifest;
2. create a **Neris Concept Review Package** with materially different options rather than one polished assumption;
3. enumerate C3 named recurring characters inside each Region Production Manifest;
4. define regional population archetype pools and reuse limits;
5. reconcile the selected Neris concept with the future Animation Bible and world-scale sheet;
6. define character Hush burden in the Hush Visual Production Matrix;
7. only after owner-approved concept and representative runtime evidence may `SH-ART-001` be fully closed.

---

# 32. Final character-art test

Before a principal character is approved, ask:

1. Can I identify this person without seeing the face?
2. Can I infer what kind of work shaped them?
3. Does their clothing look wearable and repairable?
4. Does the design support the scenes and movement they actually perform?
5. Is the fantasy identity coming from Stillring rather than genre costume shorthand?
6. Could this character stand in a plain gray room and still be recognizable?
7. Does the design remain readable at gameplay distance?
8. Does the face support restrained emotional acting?
9. Does the concept accidentally spoil a narrative role that should remain ambiguous?
10. Does any detail exist merely because fantasy concept art usually includes it?
11. Is the Hush/state variant expressing character/story logic rather than a universal effect?
12. Would an external modeler, rigger, animator, and cinematic artist understand what must be preserved?

If not, the character is not production-ready.

---

# 33. Governing character principle

Stillring is a story about ordinary people becoming responsible for a world previously controlled by a sacred central system.

The cast should therefore look like **ordinary people worth following**, not a collection of pre-labeled fantasy classes.

Neris is not memorable because the costume announces "hero."

Tessa is not memorable because the costume announces "rogue."

Maelor is not memorable because the costume announces "villain."

Sena is not memorable because the costume announces "blacksmith."

They become memorable because silhouette, work, material history, face, movement, and story all point toward the same human being.

> **Stillring's character art should make the player believe these people had lives before the plot arrived.**
