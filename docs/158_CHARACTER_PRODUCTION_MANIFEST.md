# 158 — Character Production Manifest

**Status:** ACTIVE / OWNER-AUTHORIZED FINAL CHARACTER VISUAL AUTHORITY / DOCUMENTATION-ONLY PRE-PRODUCTION  
**Updated:** 2026-09-06  
**Parent program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Art authority:** `docs/154_STILLRING_ART_BIBLE.md`  
**Production framework:** `docs/156_ART_PRODUCTION_MANIFEST_FRAMEWORK.md`  
**Narrative authority:** `docs/02_STORY_BIBLE.md`, `docs/story/01_FOUNDATIONS_AND_OPENING.md`, `docs/story/06_CHARACTER_ARCS_AND_RELATIONSHIPS.md`  
**Closes toward:** `SH-ART-001`, `SH-ART-002`, and the character-facing portion of `SH-ART-003`  
**Boundary:** this file locks creative character identity. It does not authorize UE5.8 implementation, final modeling, rigging, animation production, or invented technical/performance budgets.

---

# 1. Purpose

This is the production-facing visual authority for Stillring's principal cast.

An external character team should be able to derive concept sheets, model sheets, texture/material work, rig requirements, cinematic staging, gameplay readability and state variants from this file without inventing missing fantasy conventions or reconstructing owner intent from chat history.

The governing principle is:

> **Occupation before archetype. Human history before fantasy decoration. Silhouette before surface detail.**

The principal cast is creatively defined here. Concept art is now an execution and verification stage, not permission to reopen identity from scratch.

Only facts that honestly depend on implementation remain deferred: final Unreal-world scale conversion, topology density, skeleton/rig architecture, cloth/hair simulation, material/texture budgets, facial technology and performance scalability.

---

# 2. Authority order

Resolve character-production conflicts in this order:

1. canonical story/character facts;
2. `docs/154_STILLRING_ART_BIBLE.md`;
3. this manifest;
4. `docs/156_ART_PRODUCTION_MANIFEST_FRAMEWORK.md`;
5. approved execution sheets derived from this manifest;
6. technical-production/rigging requirements;
7. runtime tuning and measured performance evidence.

Mood boards, generated images, external art, MetaHuman defaults, marketplace packs and genre convention are subordinate references only.

---

# 3. Character production classes

## C0 — Player hero

### Neris Vale

- unique U3 game-hero identity;
- highest gameplay silhouette burden;
- complete locomotion/combat/tool/traversal compatibility;
- repeated cinematic close-up use;
- progression-equipment integration;
- multiple authored state variants;
- highest hand/tool readability requirement.

## C1 — Principal recurring cinematic cast

- Tessa Marr;
- Ilyra Vale;
- Orin Vale;
- Maelor Renn.

Each receives a unique head, body proportion target, costume silhouette, F0 facial-performance burden and authored state continuity.

## C2 — Major recurring world cast

- Brother Caldrin;
- Sena Ash;
- Prefect Aven Rusk.

Each receives a unique named-character visual identity and F1 performance target. Shared technical foundations are allowed only when visible identity survives.

## C3 — Named regional recurring/support cast

Recurring named workers, ferry operators, archivists, cooks, route staff, maintenance workers, teachers, civic officials, quest owners and relationship-chain characters.

They require a named head solution, occupation-readable silhouette, regional costume assignment, continuity across revisits and explicit reuse classification.

## C4 — Population archetypes

Unnamed/lightly recurring civilians and workers use bounded variation systems. Population reuse must never make six cultures look like the same small group in recolored clothing.

---

# 4. Universal visual doctrine

## 4.1 Stylization target

Stillring humans are believable, deliberately stylized people.

Required:

- credible anatomy;
- large-form facial readability;
- expressive brows/eyes/mouth;
- authored hair mass;
- readable hands;
- simplified skin micro-detail;
- clothing shape hierarchy;
- controlled material breakup.

Reject:

- actor-scan identity;
- pore-first realism;
- doll skin;
- anime facial proportions;
- heroic-bodybuilder uniformity;
- fashion-model homogenization;
- tiny accessories as primary identity.

## 4.2 Design-reference heights and builds

These are locked **relative art anchors**. Technical production may uniformly rescale the world later but may not casually erase their relative relationships.

| Character | Design-reference height | Build read |
|---|---:|---|
| Neris | 168 cm | young woman; compact, wiry manual-work strength |
| Tessa | 174 cm | lean, long-limbed endurance build |
| Ilyra | 170 cm | lean field-engineer build |
| Orin | 178 cm | broad ordinary repair-worker build |
| Maelor | 183 cm | tall, narrow, controlled posture |
| Caldrin | 176 cm | sturdy older build, slightly soft middle |
| Sena | 173 cm | broad-shouldered powerful work build |
| Rusk | 181 cm | tall, square, institutionally upright |

## 4.3 Hands

Hands are hero-level storytelling surfaces because the fiction centers repair, tools, bells, records, casting, measurement and physical evidence.

C0/C1 hands require:

- clear finger separation;
- close-up-safe nails/knuckles without scan noise;
- occupational callus/wear;
- tool-grip compatibility;
- expressive conversational posing;
- glove states that preserve hand readability.

## 4.4 Hair

Hair identity comes from authored shape before strand technology.

- styles must make occupational sense;
- eyes must remain readable;
- gameplay silhouette cannot depend on individual strands;
- wet/wind/ash response may deform the shape but not erase it.

## 4.5 Skin

Skin uses broad tonal modeling and restrained imperfections.

- no universal grime;
- no random scar culture;
- no beauty retouching that erases age/work;
- wrinkles follow expression and life stage rather than noise maps.

## 4.6 Clothing and fasteners

Every garment needs function, closure logic and repair logic.

Favor hooks, toggles, tied closures, load-bearing buckles, stitched reinforcement, maker hardware and replacement panels.

Reject decorative strap forests, fantasy pauldrons, spikes, dangling charms and pouch clutter.

## 4.7 Repair language

Stillring characters maintain clothing instead of merely decaying into rags.

Recurring cues:

- contrast re-stitching;
- replaced cuffs;
- patched knees/elbows;
- re-oiled leather;
- reinforced tool-contact zones;
- mismatched replacement hooks;
- polished surfaces where hands repeatedly touch.

## 4.8 Footwear

Footwear is designed for actual labor and travel.

No principal character wears ornamental heels, fashion boots or oversized armored sabatons.

---

# 5. Principal palette system

Values below are authoritative concept swatches, not physically exact final shader values. Material/lighting work may tune them while preserving visible relationships.

| Character | Primary | Secondary | Neutral | Accent | Metal/technical |
|---|---|---|---|---|---|
| Neris | slate blue `#465866` | oat `#D0C4A7` | charcoal brown `#3A3834` | burnt amber `#B56E3C` | aged brass `#8A7655` |
| Tessa | storm teal `#3E5A59` | road sand `#B6A786` | dark umber `#3A302A` | route ochre `#C39243` | weathered silver `#7D7B74` |
| Ilyra | faded indigo `#4A5666` | bone `#CDC5B4` | soot slate `#353B40` | oxide rust `#8E5F46` | muted brass `#88745D` |
| Orin | moss brown `#5A5A43` | flax `#C8B992` | dark leather `#3D3027` | workshop rust `#8A5A3C` | dull iron `#73706A` |
| Maelor | graphite `#43484E` | stone `#B6B0A4` | muted midnight `#35465A` | cool bronze `#756A59` | precision brass `#8B7A60` |
| Caldrin | wind gray `#6A7477` | archive cream `#D0C9B6` | slate `#424B52` | binding ochre `#B08B4C` | oxidized iron `#6C7472` |
| Sena | kiln charcoal `#383A38` | clay `#A85F3F` | ash beige `#B9AA94` | black-glass `#252728` | ceramic sand `#D0B98F` |
| Rusk | civic blue-gray `#4D6071` | civic off-white `#D0CDC2` | charcoal `#3B4147` | standard brass `#80745D` | dark steel `#626970` |

No character is readable only by hue; shape/material redundancy is mandatory.

---

# 6. Readability tests

Every C0–C2 character must pass:

1. black silhouette test;
2. head-shape test;
3. occupation test;
4. flat-color test with 4–6 large masses;
5. hand/prop test;
6. motion test;
7. no-face test;
8. weather test;
9. Hush-state recognition test;
10. eight-character group separation test.

---

# 7. Variant taxonomy

- **V0 Base** — stable identity.
- **V1 Work/Travel** — functional configuration change.
- **V2 Crisis/Wear** — causally specific wet/ash/damage/repair state.
- **V3 Hush** — related-reality presentation; not automatically another mesh.
- **V4 Post-Stillness** — practical adaptation after midpoint catastrophe.
- **V5 Epilogue** — lived change, never prestige “final armor.”

---

# 8. Neris Vale — FINAL C0 VISUAL LOCK

**Sex/gender:** female; she/her.  
**Age:** 17.  
**Design-reference height:** 168 cm.  
**Build:** compact, wiry young woman; narrow-to-medium shoulders, modest feminine hip line, strong forearms and legs from manual work/travel; natural adolescent/young-adult musculature; no heroic V-taper and no sexualized body emphasis.  
**Production class:** C0 / U3 / Q3 target.

## 8.1 Visual thesis

> **A seventeen-year-old village bellwright apprentice who grows into a field professional through accumulated work, not destiny.**

Neris should look like a young woman who expected to repair civic machinery that morning, not like someone dressed for an epic prophecy.

Her femininity is visible in face/body proportion but is not expressed through cleavage, impractical tailoring, skirts that obstruct traversal, cosmetic armor shaping or “girl version of the hero” decoration.

## 8.2 Face

Locked direction:

- warm medium-brown skin;
- oval face with slightly high, broad cheekbones;
- softly angular jaw narrowing to a modest chin;
- straight dark eyebrows, thick enough to carry expression;
- deep amber-brown eyes with slightly heavy upper lids;
- medium-width straight nose with a small visible bridge bump inherited from Orin;
- mouth slightly wide, lower lip modestly fuller than upper;
- light sun/freckle variation across upper cheeks/nose, subtle enough not to become a logo;
- ears slightly prominent in profile;
- no facial tattoo, beauty-mark branding, heroic scar or permanent makeup treatment.

Default expression is **observant concentration**.

Facial acting must support curiosity, quick irritation, technical absorption, dry humor, disbelief, grief, anger and long silent listening.

## 8.3 Hair

Locked design:

- deep chestnut-brown;
- dense coarse-wave texture;
- jaw/ear-length practical bob with slightly longer front pieces;
- shorter nape kept clear of collar/tools;
- uneven self/household-maintained cut rather than salon symmetry;
- front pushed off the eyes with one broken forelock that can fall during motion/wetness;
- no ponytail, heroic braid, undercut, shaved symbol or color streak.

Gameplay silhouette: compact rounded wedge with one irregular front break.

## 8.4 Body/age safeguards

Neris must read as 17, not as a 25-year-old model shrunk into “teen” scale.

Required:

- youthful facial fullness;
- relatively slight ribcage/shoulder mass;
- modest chest contour under layered workwear;
- strong but not heavily defined limbs;
- relaxed, sometimes impatient posture rather than adult military bearing;
- no sexualized camera-dependent costume construction.

## 8.5 Costume — `NERIS_V0_BRINDLE_APPRENTICE`

### Base shirt

- collarless oat work shirt;
- medium-weight woven cloth;
- narrow three-loop opening at upper chest;
- full sleeves, commonly rolled one turn at the forearm during bench work.

### Bellwright jacket

- slate-blue short work jacket ending just below high hip;
- lightly asymmetric front closure from upper-left chest toward center waist;
- three visible aged-brass hook closures;
- charcoal reinforced cuffs;
- articulated under-arm gussets;
- burnt-amber re-stitched repair at left elbow;
- smaller amber reinforcement at right shoulder seam;
- shaped enough to fit her body but never corseted or tight;
- no hood, cape, shoulder armor or decorative cleavage opening.

### Lower body

- charcoal-brown straight/tapered work trousers;
- articulated knees without tactical-pad styling;
- reinforced inner-ankle patches from workshop/ladder wear;
- high enough rise for climbing coverage;
- no dangling straps.

### Belt/tool carry

- one narrow dark-brown working belt;
- right-rear Cantor cradle mount;
- left-front two-tool loop strip;
- one small flat field-journal sleeve at left rear hip;
- no wall of pouches.

### Footwear

- dark-brown mid-ankle road/work boots;
- round-to-slight-square toe;
- low layered sole with visible replaceable heel/edge pieces;
- two strap/hook closures plus short lacing section;
- flexible ankle.

### Gloves

- no permanent gloves;
- thin brown work gloves carried folded under belt loop and used only when function requires them.

## 8.6 Palette hierarchy

1. slate jacket = primary identity mass;
2. oat shirt = face/hand framing secondary mass;
3. charcoal trousers = grounding neutral;
4. burnt-amber repair stitching = warmth/family accent;
5. aged brass = technical accent.

Never shift Neris into saturated green, royal purple, pure-white, all-black or default-red protagonist shorthand.

## 8.7 Family resemblance

From Ilyra:

- eye spacing;
- straight brow line;
- cheekbone placement;
- long-fingered hands.

From Orin:

- small bridge bump in nose;
- slight ear prominence;
- chin transition;
- one-sided half-smile.

## 8.8 Cantor Key stow/use solution

Locked solution:

- Key stows at **right rear waist/upper hip** in a mechanical swivel cradle;
- cradle angles roughly 20 degrees rearward during walking;
- sprung hinge lets the device flatten toward lower back/hip for ladders, ledges and swim states;
- draw begins with right hand lifting lower grip while left releases top catch;
- re-stow reverses the operation;
- leather-backed cradle uses darkened brass/iron hardware;
- no floating attachment, magnetic glow or energy sheath.

The Key's prongs/slider/hammer remain visible enough to identify it in silhouette.

## 8.9 Progression equipment

Only meaningful selected equipment receives strong permanent silhouette priority.

- Anchor Line: compact spool/anchor assembly on left-back belt interface when equipped;
- Glasslung Reed: slim protected reed case at inner upper jacket/chest, not an air tank;
- Temper Gauntlet: functional right-hand/forearm layer replacing the ordinary work glove when active;
- Vane Cloak: short airflow mantle system ending above knee, split/controlled for ladders and ledges;
- Mirror Nail: compact rigid case at left hip, never sword-like;
- seam-mode changes alter Cantor hardware subtly rather than making it a glowing weapon.

Neris never becomes a walking inventory rack.

## 8.10 Variants

### `NERIS_V1_FIELD_TRAVEL`

- same base costume;
- charcoal weatherproof shoulder yoke covering upper back/chest and ending above elbows;
- journal moved to faster field access;
- cuffs generally down;
- lightly weathered boot edges.

### `NERIS_V2_POST_GRAND_RING`

- same jacket;
- damaged right shoulder seam repaired with neutral/amber cross-stitching;
- one patched tear in weather yoke;
- no permanent blood or generic battle grime.

### `NERIS_V3_HUSH_PRESENTATION`

- same body and silhouette;
- Hush response is material/light correspondence, not ghost anatomy;
- base colors locally desaturate according to environment relationship;
- amber repair thread remains unusually stable and recognizable.

### `NERIS_V4_LATE_TOOL_LOADOUT`

- base body/costume unchanged;
- mixed maker-replacement hardware from travel;
- wear concentrated at real attachment/contact points;
- silhouette still clearly V0 Neris.

### `NERIS_V5_EPILOGUE_TRAVELING_BELLWRIGHT`

- slate jacket sun-faded and neatly repaired;
- travel yoke becomes a slightly longer field over-yoke ending at upper thigh, still short/split for movement;
- slim cross-body document case for traveling work;
- replaced boot soles;
- Cantor cradle cleaner and more refined through Neris's own modifications;
- no ceremonial badge, crown, armor promotion or legendary-hero costume.

## 8.11 Animation burden

Art must support:

- analog locomotion and Sprint;
- jump/fall/land;
- mantle;
- ledge hang/shimmy/pull-up/release;
- ladders;
- surface swimming;
- slope scramble/slide;
- target-lock locomotion;
- combat attack/guard/evade/reaction;
- Cantor use;
- field tools;
- Line Skiff use;
- workbench repair;
- cinematic close-ups;
- environmental interactions.

## 8.12 Hard failures

Reject any Neris execution that reads primarily as:

- legendary swordswoman;
- assassin;
- mage;
- knight;
- princess/royal heir;
- anime heroine;
- photoreal actor;
- generic leather adventurer;
- sexualized teen protagonist;
- child mascot.

Neris's creative visual identity is **LOCKED** by this section.

---

# 9. Tessa Marr — FINAL C1 VISUAL LOCK

**Sex/gender:** female; she/her.  
**Visual age:** 25.  
**Design-reference height:** 174 cm.  
**Build:** lean, long-limbed endurance build; strong calves/hips from road work; relaxed shoulders.  
**Skin:** deep brown with warm undertone.  
**Eyes:** dark brown.  
**Hair:** black, tightly coiled; side/back gathered into compact low knot with short natural crown volume.

## 9.1 Face

- long oval/diamond face;
- high cheekbones;
- broad straight nose;
- mobile brows with one slightly higher resting arch;
- wide expressive mouth;
- no scar shorthand.

Default read: awake, mildly skeptical, measuring the road ahead.

## 9.2 Costume

- road-sand collarless base shirt;
- storm-teal mid-thigh courier coat with twin rear boarding/riding vents;
- three offset load-bearing front toggles;
- sleeves tapered/secured above wrist;
- dark-umber road trousers;
- ochre neck wrap, normally loose but usable against dust/wind;
- reinforced dark road boots just above ankle;
- broad cross-body courier strap from right shoulder to **left hip satchel**;
- rigid-backed weathered satchel sized for documents/compact freight;
- small route-tag loop holding only current route markers.

No hood dependency, dagger bandolier, pirate buckle language or endless hidden pockets.

## 9.3 Variants

- `TESSA_V0_COURIER` — base;
- `TESSA_V1_COAST_WEATHER` — waxed shoulder panel, neck wrap raised, satchel cover;
- `TESSA_V2_RELIEF_NETWORK` — extra ledger sleeve and emergency signal tags, no military gear;
- `TESSA_V3_LINE_SKIFF_COORDINATOR` — compact gloves and route-board folio;
- `TESSA_V5_EPILOGUE` — same coat repeatedly repaired, cleaner standardized route tags reflecting accepted civic responsibility.

## 9.4 Hard failure

Never render Tessa as thief, pirate, sexy rogue, dagger specialist, smuggler stereotype or comic-relief mascot.

---

# 10. Ilyra Vale — FINAL C1 VISUAL LOCK

**Sex/gender:** female; she/her.  
**Chronological age:** 43.  
**Physical/Hush appearance:** approximately 32–34 because eleven Waking years do not translate into ordinary physical aging in the Hush.  
**Design-reference height:** 170 cm.  
**Build:** lean field-engineer; long forearms/hands; compact shoulders.  
**Skin:** warm medium-brown, slightly deeper than Neris's tone.  
**Eyes:** deep amber-brown.  
**Hair:** dark brown, jaw-length working cut pinned back at both sides with one dull-metal comb.

## 10.1 Face

- oval-square face;
- broad cheekbones;
- straight brow line and eye spacing echoed in Neris;
- slightly longer nose than Neris;
- narrower mouth with pronounced concentration compression at corners;
- subtle line between brows from habitual focus;
- no haunted-ghost eye treatment.

## 10.2 Costume

- bone work shirt;
- faded-indigo mid-thigh field coat with side splits and four muted-brass closures;
- soot-slate trousers;
- dark service boots with shallow tread and replaceable heel blocks;
- high-waist narrow instrumentation belt with two flat measurement sleeves and fold-down note surface;
- oxide-rust reinforcement at inside elbows/one pocket edge;
- no robes, cloak, sash or mystical jewelry.

## 10.3 Hush state

- body remains opaque/physical;
- two coat seams show almost-identical repairs one layer apart, implying repeated resets rather than eleven years of rot;
- some high-contact metal remains strangely unworn while adjacent cloth shows localized wear;
- hair/cloth occasionally settles a fraction too early relative to surrounding Hush motion;
- no global glow, transparency, black veins or floating cloth.

## 10.4 Returned state

Ilyra replaces one repeated Hush repair with one unmistakably new Waking repair. That small act is the visual statement that she is participating in current time rather than restoring an old state.

## 10.5 Hard failure

Never render Ilyra as oracle, saint, witch, ghost mother, ethereal engineer or visually purified victim.

---

# 11. Orin Vale — FINAL C1 VISUAL LOCK

**Sex/gender:** male; he/him.  
**Visual age:** 46.  
**Design-reference height:** 178 cm.  
**Build:** broad ordinary repair-worker; strong hands/forearms; slight softness at waist; no warrior physique.  
**Skin:** light-medium warm olive/tan.  
**Eyes:** gray-brown.  
**Hair:** medium brown with gray at temples; rough short crop.  
**Facial hair:** practical short beard.

## 11.1 Face

- broad rectangular face;
- slightly raised/crooked nose bridge inherited by Neris;
- heavy but kind brow;
- visible smile lines rather than heroic scars;
- slightly prominent ears;
- one-sided half-smile echoed in Neris.

## 11.2 Costume

- flax work shirt with rolled sleeves;
- moss-brown sleeveless heavy-weave work vest;
- removable workshop-rust apron panel from waist to upper thigh;
- dark-brown straight work trousers;
- dark leather ankle boots with visibly replaced outer heel;
- two simple tool loops plus folding rag/hook on belt.

For First Ring, Orin brushes/cleans this same clothing and adds one simple dark neck fastening. He does not transform into ceremonial elite dress.

## 11.3 Still-Cairn state

Preserved Orin initially appears in a clean, familiar V0 workshop state—slightly too complete, every patch exactly where Neris remembers it.

As the defensive state destabilizes, repetition appears in environment and gesture relationships first. Orin never grows monster armor or corruption anatomy.

## 11.4 Epilogue

Same vest, new pocket repair, slightly more visible gray where chronology permits. Familiarity matters more than reinvention.

---

# 12. Maelor Renn — FINAL C1 VISUAL LOCK

**Sex/gender:** male; he/him.  
**Visual age:** 52.  
**Design-reference height:** 183 cm.  
**Build:** tall, narrow, upright; long hands; not frail.  
**Skin:** light bronze/olive.  
**Eyes:** gray-blue.  
**Hair:** near-black, straight-to-slight-wave, swept back; silver concentrated at temples; medium-short.  
**Facial hair:** clean-shaven.

## 12.1 Face

- long triangular/rectangular face;
- narrow jaw without gauntness;
- straight nose;
- deep-set but not sinister eyes;
- fine horizontal forehead lines;
- neutral/soft resting mouth rather than smirk;
- one slightly drooping upper eyelid suggesting fatigue, not villainy.

First impression: **competent, calm and safe to ask a technical question**.

## 12.2 Costume

- stone-gray high-neck base shirt;
- graphite mid-thigh acoustician field coat with straight front and concealed hooks;
- muted-midnight inner facing visible only when coat moves/opens;
- narrow dark trousers;
- polished but repaired field boots;
- slim precision-instrument case on left hip;
- narrow brass calibration scale integrated into a coat seam as a real tool;
- no cape, robe, medals, villain collar or luxury fabric.

His clothing is better maintained than Neris/Tessa's because of institutional access, but remains work clothing.

## 12.3 State progression

### Trusted expert

Cleanest state. Graphite/stone dominate.

### Grand Ring reveal

Same clothing; coat opened into working configuration, sleeves partially secured. The reveal is behavioral, not an “evil costume” change.

### Post-Stillness

Temporary interface clips and measurement strips appear from system maintenance. No black/red corruption pass.

### Null Meridian

Additional precision hardware is restricted to forearms/waist where encounter function requires it. His human silhouette remains intact.

### Ending/trial

Institutional equipment is removed. He appears smaller because the machinery/context is gone, not because he becomes physically broken for sympathy.

## 12.4 Hard failure

Never render Maelor as dark lord, priest, dictator, aristocratic villain, possessed scientist, anime mastermind or wild-haired mad inventor.

---

# 13. Brother Caldrin — FINAL C2 VISUAL LOCK

**Sex/gender:** male; he/him.  
**Visual age:** 63.  
**Design-reference height:** 176 cm.  
**Build:** sturdy older frame with slightly soft middle; strong hands; mountain-walking legs; not frail.  
**Skin:** medium brown with cool-neutral undertone.  
**Eyes:** dark hazel.  
**Hair:** dense short gray curls, receding naturally but not tonsured.  
**Facial hair:** short full gray beard trimmed clear of mouth.

## 13.1 Face

- broad forehead;
- softly rounded square face;
- deep smile/concern lines at eyes;
- wide nose;
- heavy brows going silver;
- default expression attentive and patient rather than holy/serene.

## 13.2 Costume

- archive-cream wrapped base shirt with practical overlap closure;
- wind-gray hip-length mountain coat with asymmetric storm flap;
- slate trousers;
- dark mountain boots with grippy segmented sole and wrapped ankle reinforcement;
- narrow archive harness around waist/ribs carrying two rigid record cases behind left hip;
- ochre binding tape/labels visible at case edges;
- oxidized-iron maintenance hook and small annotation tool case;
- no floor robe, hooded monk silhouette, prayer beads or mystical relic.

## 13.3 State progression

- `CALDRIN_V0_ARCHIVE` — clean cases, controlled labels;
- `CALDRIN_V1_HIGH_AERIE_FIELD` — storm flap closed, gloves, outer neck wrap;
- `CALDRIN_V2_AUTHORITY_BREAK` — one official seal removed/cut from case and replaced with visible handwritten provenance tags;
- `CALDRIN_V5_PUBLIC_ARCHIVE` — more varied tags and open-access case organization; same coat/body identity.

His character change is visible in **record practice**, not costume promotion.

---

# 14. Sena Ash — FINAL C2 VISUAL LOCK

**Sex/gender:** female; she/her.  
**Visual age:** 48.  
**Design-reference height:** 173 cm.  
**Build:** broad shoulders, powerful forearms/back, sturdy hips/legs; body shaped by foundry work, not fantasy warrior training.  
**Skin:** rich deep umber-brown with warm copper undertone.  
**Eyes:** near-black brown.  
**Hair:** black with visible gray; tightly braided in flat crown rows gathered into a compact protected rear knot for foundry safety.

## 14.1 Face

- broad square face;
- strong straight nose;
- full mouth;
- heavy expressive brow;
- no decorative facial scars;
- fine heat/exposure tonal variation only where plausible.

Default read: evaluating whether something is actually safe.

## 14.2 Costume

- ash-beige dense woven base shirt;
- kiln-charcoal sleeveless/short-sleeved heavy work over-jacket with high underarm mobility;
- clay-colored reinforced front/side panels;
- dark work trousers with wide stable stance and no armor shaping;
- heavy foundry boots with ceramic-capped upper toe and heat-resistant sole layers;
- removable black-glass/ceramic forearm guards for active casting, asymmetrical based on task;
- split heavy apron only in active floor state, removable for public/inspection scenes;
- maker mark stamped on replaceable apron/guard components, not tattooed as identity.

## 14.3 Wear logic

- heat discoloration at guard edges;
- ash concentrated at lower hems/boots;
- polished tool-contact zones;
- visibly replaced protection components;
- no universal soot-covered face.

## 14.4 Variants

- `SENA_V0_KILN_CAPTAIN` — full active protection;
- `SENA_V1_PUBLIC_INSPECTION` — apron/guards reduced, same core over-jacket;
- `SENA_V2_GRAND_RING_CRISIS` — emergency cloth wrap/replaced guard specific to event;
- `SENA_V4_DISTRIBUTED_PRODUCTION` — multiple visible maker tags/locally replaced parts demonstrating decentralized production;
- `SENA_V5_EPILOGUE` — cleaner traceability marks, same working silhouette.

## 14.5 Hard failure

Never render Sena as armored warrior, fantasy blacksmith cliché, barbarian, “battle mom,” or soot-and-muscle shorthand.

---

# 15. Prefect Aven Rusk — FINAL C2 VISUAL LOCK

**Sex/gender:** male; he/him.  
**Visual age:** 54.  
**Design-reference height:** 181 cm.  
**Build:** tall, square shoulders, ordinary middle-aged civic fitness; controlled posture rather than military physique.  
**Skin:** fair-to-medium tan with neutral undertone.  
**Eyes:** dark gray.  
**Hair:** ash-brown turning gray, neatly cut short with strong side part.  
**Facial hair:** none.

## 15.1 Face

- square face with broad jaw;
- straight medium nose;
- level brows;
- faint lines at mouth/forehead from restraint and concentration;
- no villain sneer or aristocratic sharpness.

## 15.2 Costume

- civic off-white high-collar shirt;
- structured civic blue-gray knee-above coat ending mid-thigh, not long enough to become ceremonial robes;
- coat uses consistent Bellwarden hidden-hook standard with one visible brass authorization tab at upper left chest;
- charcoal straight trousers;
- dark-steel-toned maintained ankle boots;
- slim document/access case at right hip;
- one standardized utility loop hidden under coat side opening for actual emergency tool access.

Authority comes from consistent construction, cleanliness and system markings—not luxury.

## 15.3 Variants

- `RUSK_V0_ADMIN` — full structured coat, authorization tab present;
- `RUSK_V1_INVESTIGATION` — coat open, document case active;
- `RUSK_V2_GRAND_RING_RESPONSE` — outer coat partially removed/secured for emergency work; sleeves fastened back; proves he can physically act;
- `RUSK_V4_POST_STILLNESS` — same coat with authorization tab deliberately left but one central-standard seal removed/replaced by local access tags;
- `RUSK_V5_TESTIMONY` — simplest institutional state, no dramatic rebel makeover.

## 15.4 Hard failure

Never render Rusk as aristocrat, fascist-uniform caricature, cartoon bureaucrat, secret villain or sudden rebel leader.

---

# 16. The Listener — FINAL SPECIAL VISUAL LOCK

**Nature:** emergent consciousness of the Hush; not human, god, demon or monster.  
**Production ownership:** character art + environment art + VFX + narrative + finale staging.

## 16.1 Core visual thesis

> **Many incomplete possibilities temporarily agreeing on where a presence should be.**

The Listener has no permanent biological body.

## 16.2 Base manifestation

The canonical final-chamber manifestation occupies a roughly **2.3–2.6 m high vertical ovoid volume**, but it is not a humanoid giant.

It consists of:

- 12–20 incomplete human-scale silhouette fragments occupying overlapping positions;
- partial shoulders, hands, profiles, backs of heads and standing gestures that never combine into one person;
- thin slices of familiar environment surfaces passing through those fragments as if different possibilities are sharing the same volume;
- a central negative-space corridor where the background appears slightly too far away rather than a glowing core;
- no stable face;
- no eyes;
- no mouth;
- no limbs extending from one coherent torso.

The viewer sometimes perceives a person for less than a second because several fragments align, then the alignment breaks.

## 16.3 Material/color behavior

- no single Listener color;
- fragments borrow restrained palette/material information from places the player knows;
- saturation remains lower than the source location but never becomes universal blue/purple;
- overlap boundaries may create a pale neutral seam line, thin and intermittent;
- the Listener does not glow like a magic entity;
- ambient light should still affect the fragments enough to anchor them in the scene.

## 16.4 Shadows and reflections

- the Listener casts several partial shadows that do not fully converge;
- reflective surfaces may show a different but related set of fragments;
- neither effect should obscure gameplay or become glitch-noise wallpaper.

## 16.5 Motion

- constituent gestures complete at different rates;
- hands may begin an ordinary action from one remembered context and finish as another incomplete gesture;
- the whole volume does not walk like a character;
- movement is mostly assembly/disassembly around a stable spatial locus;
- when the Listener directs attention toward Neris, several incomplete head/shoulder fragments orient approximately toward her without producing a single face.

## 16.6 Communication presentation

When a comprehensible idea is presented, the Listener briefly resolves one **human-scale gesture**, not one human identity: an open hand, a turned shoulder, someone stepping away, someone releasing an object. The gesture is assembled from multiple partial bodies and dissolves immediately after carrying meaning.

No lip sync is required because there is no mouth.

## 16.7 Save-state sensitivity

At least two fragment families should be allowed to draw from recognizable visual motifs associated with content the player actually completed, while a stable canonical fragment library guarantees the scene works for every save.

This is an authored substitution system, not procedural AI generation.

## 16.8 Hard failures

Never render the Listener as:

- giant humanoid god;
- masked deity;
- cosmic woman/man;
- shadow demon;
- tentacle creature;
- angel;
- giant eye;
- face in the sky;
- random particle blob;
- glitch monster.

The Listener's creative presentation is now **LOCKED**. Exact shader/VFX implementation remains technical.

---

# 17. Principal cast silhouette separation

| Character | Primary black-silhouette read |
|---|---|
| Neris | short compact jacket, youthful field-worker proportions, right-rear Cantor line |
| Tessa | long courier coat, long legs, left-hip satchel/cross-body load |
| Ilyra | longer split field coat, narrow instrumentation waist, pinned-back head shape |
| Orin | broad vest/apron workshop mass, rolled forearms |
| Maelor | tall narrow straight coat, minimal side instrument case |
| Caldrin | sturdy mountain coat, rear-left paired record cases |
| Sena | broad foundry shoulders, protected forearms/apron state |
| Rusk | square structured civic coat, clean vertical authority mass |

All eight must remain distinguishable as pure black shapes at gameplay framing.

---

# 18. Relationship-based visual echoes

## Neris / Ilyra

Shared:

- eye spacing;
- straight brow line;
- cheekbone position;
- long-fingered tool hands;
- practical field-work layering logic.

Not shared:

- exact jacket cut;
- hair shape;
- palette dominance;
- equipment arrangement.

## Neris / Orin

Shared:

- bridge bump;
- ear prominence;
- half-smile asymmetry;
- visible repair culture;
- replaceable boot/gear hardware.

## Ilyra / Maelor

Their historical collaboration is visible through restrained old-era technical hardware proportions—thin brass measurement pieces, compact instrument cases, field coats built for service access—but their silhouettes remain distinct.

## Maelor / Rusk

- Maelor = precision/technical narrowness;
- Rusk = procedural/civic squareness.

## Tessa / world routes

Tessa may accumulate **functional replacement parts** from different routes, but never souvenir clutter.

---

# 19. Damage, dirt and weather

## Wetness

Use only from swimming/rain/spray/marsh/coastal exposure. Selected cloth/hair darkens or clumps; the entire character does not become glossy.

## Ash/dust

Regional and causal only.

## Blood/injury

Only where rating/narrative authority requires it. Injury is not the visual shorthand for seriousness.

## Repair

After meaningful damage, later repair is preferred over permanent rags.

---

# 20. Facial performance tiers

## F0 — full principal performance

Neris, Tessa, Ilyra, Orin, Maelor.

Requires:

- close-up-safe deformation;
- strong brows/eyes/mouth;
- asymmetry;
- subtle listening/hesitation;
- restrained emotion, not only broad phoneme shapes.

## F1 — major recurring

Caldrin, Sena, Rusk and selected C3 leads.

Requires credible medium-close dialogue and scene-specific emotion.

## F2 — population

Readable basic dialogue/emotion may use shared systems.

Exact facial technology is downstream technical authority.

---

# 21. Body/rig reuse policy

Allowed in principle:

- common underlying humanoid skeleton where deformation supports the height/build spread;
- compatible base-topology families;
- shared facial-rig architecture;
- shared material systems;
- modular garment foundations.

Not allowed:

- identical hero bodies with head swaps;
- arbitrary mesh scaling that destroys anatomy;
- forcing Sena/Caldrin/Rusk/Tessa/Maelor/Orin into one silhouette because it is convenient.

Recommended creative grouping for technical evaluation:

- **Body Family A:** Neris / Tessa / Ilyra — related lean/mobile foundation but distinct proportions;
- **Body Family B:** Orin / Caldrin / Rusk / Maelor — adult male foundation with substantial proportion variants;
- **Body Family C:** Sena — may share skeleton architecture but should retain a distinct broader body mesh if reuse compromises silhouette.

This is an evaluation starting point, not a locked rig count.

---

# 22. C3 named-character rule

Every named regional NPC who appears in more than one meaningful state or owns a significant quest/relationship chain receives at minimum:

- one identity brief;
- one occupation silhouette;
- named face/head solution;
- region costume assignment;
- prop/work assignment;
- state-continuity notes;
- reuse classification;
- facial tier;
- post-Stillness requirement where applicable.

No recurring named character may silently use a random generic population combination if recognition across revisits matters.

---

# 23. Population variation baseline

The exact final counts are production-budget dependent, but the **minimum visual variety requirement** is locked.

Per major settled region, final population art must support at least:

- 5 visibly different adult body silhouettes;
- 2 youth silhouette families where population canon supports youth;
- 2 elder silhouette families;
- 10 recognizable head/face bases before hair/age variation;
- 8 hair/headwear families appropriate to the region;
- 4 occupation outerwear families;
- 3 footwear families;
- 3 climate/protection layers where region requires them;
- enough palette/material combination to prevent immediate clone recognition in small settlements.

These are **minimum visible-variety targets**, not necessarily unique rigs or meshes.

A close recurring named NPC may not reuse a face that is prominently visible on another named NPC.

---

# 24. Character Style Board 03

`Board 03 — Character Style Band` is still required, but its job has changed.

It now visualizes and verifies these locked designs rather than presenting identity options.

Board 03 must contain:

- final Neris front/side/back and gameplay silhouette;
- Neris face close-up and expression strip;
- all eight human principals together at reference scale;
- black-silhouette group test;
- flat-color group test;
- hand/tool close-ups;
- hair-shape examples;
- target skin-detail band;
- material hierarchy;
- gameplay-distance and cinematic-distance comparisons;
- Listener manifestation diagrams;
- do/don't examples.

If Board 03 conflicts with this file, this file wins.

---

# 25. Production gates

## Gate C-A — Canon/visual brief

**PASSED for C0–C2 and Listener.**

## Gate C-B — Creative identity lock

**PASSED at written authority level for C0–C2 and Listener.**

Execution art must still prove that the written silhouettes work.

## Gate C-C — Execution concept proof

Requires faithful front/side/back, group silhouette, material, prop and state sheets derived from this manifest.

This is no longer an open design competition. Material departures require owner review.

## Gate C-D — Representative model

Requires:

- one Neris Q2 model;
- one representative C1/C2 Q2 model;
- one representative population character;
- gameplay/cinematic lighting tests;
- deformation/attachment tests;
- measured technical evidence.

## Gate C-E — Final production

Requires final rig, material, performance, platform and production validation.

---

# 26. Decision rights

## LOCKED — do not redesign

- Neris is female, age 17, and uses the complete visual design in §8;
- all principal ages/builds/heights at concept-reference level;
- principal faces/hair directions;
- base costumes and palette relationships;
- principal equipment/carry identity;
- family resemblance relationships;
- occupation-first silhouettes;
- Tessa as courier, not rogue;
- Ilyra as engineer, not oracle;
- Orin as repairman/father, not secret master;
- Maelor visually trustworthy at first encounter;
- Caldrin as archivist-engineer, not priest archetype;
- Sena as foundry leader, not armored warrior;
- Rusk as credible administrator, not cartoon villain;
- Listener manifestation defined in §16;
- clothing must remain functional/repairable;
- named-character silhouettes remain distinct.

## STUDIO CHOICE WITHIN BOUNDS

- seam micro-layout that does not alter silhouette;
- exact stitch density;
- topology/UV implementation;
- non-identity-changing wear variation;
- physically plausible material tuning;
- hair/cloth technology;
- small deformation-driven construction adjustments.

## OWNER REVIEW REQUIRED

- any change to face shape, hair silhouette, body build, base costume silhouette, primary palette relationship, sex/gender presentation or signature prop placement;
- any character-design change that changes story read;
- any departure from Playable Fantasy Illustration character stylization;
- any materially different Listener representation.

## RUNTIME / TECHNICAL EVIDENCE

Still legitimately open:

- final centimeters-to-Unreal-world conversion if global scale changes;
- final skeleton/rig family count;
- topology density;
- material-slot/texture budgets;
- cloth/hair simulation budget;
- exact facial-rig technology;
- final attachment offsets under animation;
- scalability/performance tiers.

These are engineering/production unknowns, not missing character design.

---

# 27. Quoteable principal production burden

Known high-priority visual packages:

1. Neris;
2. Tessa;
3. Ilyra;
4. Orin;
5. Maelor;
6. Caldrin;
7. Sena;
8. Rusk;
9. Listener manifestation family.

State burdens:

- Neris — 6 authored states;
- Tessa — 5 authored states;
- Ilyra — pre-disappearance/Hush/reunion-returned states;
- Orin — opening/Still-Cairn/ending states;
- Maelor — trusted/Grand Ring/post-Stillness/finale/trial states;
- Caldrin — archive/mountain/authority-break/public-archive states;
- Sena — foundry/public/crisis/distributed-production/epilogue states;
- Rusk — admin/investigation/crisis/post-Stillness/testimony states;
- Listener — one core manifestation with controlled save-sensitive fragment substitutions.

Variants should reuse base body/costume architecture where possible.

---

# 28. Remaining open items

No principal **creative identity** item remains intentionally blank.

The remaining unknowns are only:

- technical body/skeleton reuse outcome after deformation testing;
- topology/texture/material budgets;
- exact cloth/hair/facial technology;
- final runtime scale conversion;
- exact Hush shader/VFX implementation;
- C3 regional cast enumeration in Region Production Manifests;
- final population counts above the minimum variety floor.

Agents may not treat those technical unknowns as permission to redesign the characters.

---

# 29. Final character-art test

Before production approval, ask:

1. Can this person be identified without a face?
2. Can the viewer infer what kind of work shaped them?
3. Does the clothing look wearable and repairable?
4. Does the design support the scenes/movement actually performed?
5. Is the identity specifically Stillring rather than fantasy shorthand?
6. Does the design work in a gray room without environment help?
7. Is it readable at gameplay distance?
8. Does the face support restrained emotional acting?
9. Does the design accidentally spoil a role meant to remain ambiguous?
10. Does every major detail have a job?
11. Does the Hush/state treatment preserve identity rather than applying a universal effect?
12. Can a modeler, rigger, animator and cinematic artist tell what must not change?

If not, the execution is not production-ready.

---

# 30. Governing character principle

Stillring is a story about ordinary people becoming responsible for a world previously controlled by a sacred central system.

The cast should therefore look like **ordinary people worth following**, not pre-labeled fantasy classes.

Neris is not memorable because her costume announces “hero.”

Tessa is not memorable because her costume announces “rogue.”

Maelor is not memorable because his costume announces “villain.”

Sena is not memorable because her costume announces “blacksmith.”

They become memorable because silhouette, work, material history, face, movement and story all point toward the same human being.

> **Stillring's character art should make the player believe these people had lives before the plot arrived.**
