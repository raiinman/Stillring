# 163 — VFX Production Manifest

**Status:** ACTIVE / STUDIO-HANDOFF VFX PRODUCTION AUTHORITY / DOCUMENTATION-ONLY PRE-PRODUCTION  
**Updated:** 2026-09-06  
**Parent program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Art authority:** `docs/154_STILLRING_ART_BIBLE.md`  
**Production framework:** `docs/156_ART_PRODUCTION_MANIFEST_FRAMEWORK.md`  
**Character authority:** `docs/158_CHARACTER_PRODUCTION_MANIFEST.md`  
**Enemy/boss authority:** `docs/159_ENEMY_BOSS_ART_MANIFEST.md`  
**Region environment/prop authority:** `docs/160_REGION_ENVIRONMENT_PROP_MANIFEST.md`  
**Regional visual-script authority:** `docs/161_REGIONAL_COLOR_MATERIAL_LIGHTING_SCRIPTS.md`  
**Hush production authority:** `docs/162_HUSH_VISUAL_PRODUCTION_MATRIX.md`  
**Gameplay-semantic authority:** current locomotion, combat, Cantor/tool/puzzle, Hush, Save/World-State, Line Skiff and Null Meridian authorities  
**Closes toward:** `SH-ART-008` and VFX-facing portions of `SH-ART-004`, `SH-ART-006`, `SH-ART-007`, `SH-ART-009`, accessibility, combat-readability and production-dependency closure  
**Boundary:** this file defines VFX language, families, semantic ownership, production burden, readability, accessibility and review requirements. It does not authorize UE5.8 implementation, Niagara architecture, shader budgets, overdraw targets, timing values, combat tuning, damage values, collision, semantic state ownership, audio timing, platform scalability tiers or measured runtime performance.

---

# 1. Purpose

Stillring cannot hand VFX production a sentence that says “readable and restrained” and expect consistent results across combat, tools, bosses, weather, the Hush, region machinery and the finale.

This document turns the visual doctrine into a production contract.

It answers:

- what kinds of effects exist;
- which system owns the state being presented;
- which effects are mandatory versus decorative;
- what visual information each family is allowed to communicate;
- what each family must still communicate when particle density is reduced;
- how combat telegraphs survive weather, Hush and noisy environments;
- how Cantor/resonance effects remain mechanical rather than magical;
- how regional effects differ without becoming eight unrelated VFX styles;
- how Hush effects reinforce wrong relationships rather than generic distortion;
- how bosses receive authored effects without becoming particle spectacles;
- how reduced-effects/accessibility modes preserve semantic truth;
- which implementation decisions remain technical/runtime work.

The governing rule is:

> **VFX presents gameplay truth. VFX does not own gameplay truth.**

If an effect disappears, the underlying state must still exist correctly.

If a particle changes color, gameplay state must not change unless the owning gameplay system changed it first.

If VFX contradicts the owning system, VFX is wrong.

---

# 2. Authority order

Resolve VFX conflicts in this order:

1. source gameplay/world-state authority;
2. accessibility/readability requirements;
3. combat/encounter/tool/Hush semantic contracts;
4. `docs/154_STILLRING_ART_BIBLE.md`;
5. `docs/159_ENEMY_BOSS_ART_MANIFEST.md` and `docs/162_HUSH_VISUAL_PRODUCTION_MATRIX.md` where relevant;
6. this VFX manifest;
7. approved effect keyframes/styleframes;
8. technical-production implementation;
9. measured runtime/performance tuning.

An effect artist may improve presentation.

An effect artist may not redefine:

- attack timing;
- attack direction;
- vulnerability;
- damage state;
- traversal eligibility;
- Cantor eligibility;
- puzzle solution state;
- Hush semantic class;
- door/bridge collision state;
- save persistence;
- boss phase logic;
- Line Skiff route legality;
- completion state.

---

# 3. VFX production classes

Every effect family must carry one of these classes.

## VFX-G — Gameplay-critical

The effect contributes to information the player must understand to play correctly.

Examples:

- attack direction/readiness support;
- hazard active/inactive support;
- Cantor target/state support;
- puzzle-state support;
- seam-state support;
- boss component/state support;
- route/mechanism activation support.

Requirements:

- must survive reduced particle quality;
- must survive Reduced Effects accessibility mode;
- must not rely on hue alone;
- must not require bloom to read;
- must preserve the actor/mechanism silhouette;
- must be redundant with shape, motion, material/value, animation, audio or haptics where appropriate;
- must have a declared semantic owner.

## VFX-S — State-communication

The effect communicates meaningful world/system state but is not the sole carrier of immediate action timing.

Examples:

- Waybell operating state;
- machine pressure/heat state;
- local resonance relationship;
- Hush seam presentation;
- post-Stillness system activity;
- route infrastructure status.

Requirements:

- state must remain readable without full particle density;
- state cannot exist only inside the effect component;
- visual relationship must remain coherent with regional material/light authority.

## VFX-A — Atmospheric / environmental

The effect supports weather, place identity, work, scale or mood.

Examples:

- spray;
- ash;
- pollen;
- distant dust;
- insects;
- suspended moisture;
- smoke;
- drifting leaves;
- localized debris.

Requirements:

- may be aggressively reduced or culled;
- may never hide gameplay-critical silhouettes or routes;
- does not imply danger unless a gameplay system separately declares danger;
- must be regionally motivated.

## VFX-C — Cinematic / authored spectacle

Used for bounded story moments, major machinery events, boss transitions or finale presentation.

Requirements:

- must still obey established Stillring visual language;
- cannot introduce a new “finale magic” grammar unsupported by the rest of the game;
- cannot make an unplayable cinematic shot the only readable version of an effect needed during play;
- should reuse established effect primitives where possible.

## VFX-D — Decorative micro-effect

Small support effects with no semantic burden.

Examples:

- tiny dust releases from a workbench;
- occasional ember escape;
- low-priority water drips;
- small cloth/fiber motes where justified.

Requirements:

- first to disappear under scalability pressure;
- never attached to every interactable by default;
- no UI-like pulsing to attract attention.

---

# 4. Mandatory effect manifest fields

Every production VFX family must declare:

- effect ID/family name;
- VFX class (`G`, `S`, `A`, `C`, `D`);
- owning gameplay/world system;
- triggering fact/event;
- what the effect communicates;
- what the effect explicitly does **not** communicate;
- world-space versus screen-space use;
- expected scale category;
- expected visibility relationship rather than invented meter value;
- duration class: instant / brief / sustained / loop / authored sequence;
- silhouette-obscuration risk;
- color-independent cue;
- audio/haptic redundancy where applicable;
- Hush relationship;
- Reduced Effects behavior;
- low-scalability behavior;
- multiplayer/network requirement: none under current single-player scope unless product scope changes;
- semantic-state owner;
- animation dependency;
- material dependency;
- environment/lighting dependency;
- technical budget classification: later runtime evidence;
- source/provenance record.

No production effect is approved from a pretty flipbook alone.

---

# 5. Stillring effect-shape language

Stillring VFX should be designed with the same discipline as its geometry.

## 5.1 Favor physical cause

Effects should usually appear to come from something understandable:

- pressure escapes through a valve;
- heat blooms from a chamber;
- metal dust falls from contact;
- resonance travels along an authored machine relation;
- spray follows water impact;
- ash rises where hot air actually rises;
- Hush wrongness appears around a contradictory relationship;
- a tool response originates at the tool/target relation.

Avoid free-floating “magic energy” without a causal source.

## 5.2 Shape families

Preferred readable effect forms include:

- rings/arcs when mechanically or acoustically justified;
- traveling lines/pulses along real connections;
- pressure jets with clear origin/direction;
- compact impact bursts;
- thin dust/spray sheets following surface direction;
- localized resonance ripples;
- bounded volumetric pockets;
- falling/drifting particulate tied to gravity/wind;
- repeated/incomplete Hush traces tied to known forms.

Avoid using the same radial burst for every interaction.

## 5.3 Density hierarchy

Large effects should usually have:

1. one dominant readable form;
2. one secondary motion layer;
3. sparse tertiary detail.

If tertiary particles are doing the semantic work, the effect is backwards.

## 5.4 Edges and softness

Gameplay-critical effects favor controlled edges/value separation over indistinct bloom clouds.

Atmospheric effects may be softer but must yield around important silhouettes.

---

# 6. Color language

Stillring has no universal “magic color.”

VFX color follows the owning material/region/system first.

## 6.1 Resonance / precision

Pale cool/cyan relationships may be used as a restrained precision signal where already supported by art authority, but never as an omnipresent supernatural glow.

Use alongside:

- shape change;
- rhythmic motion;
- material response;
- mechanical movement;
- audio/haptic redundancy.

## 6.2 Danger

Danger does not equal red particles.

Danger may use:

- directional movement;
- hotter/brighter value;
- unstable contrast;
- expanding/contracting form;
- mechanical posture;
- local material state;
- region-appropriate heat/pressure/electrical/resonant behavior.

## 6.3 Hush

No global purple/blue VFX palette.

Hush effect color derives from the region/object being contradicted.

Hush differentiation should rely heavily on:

- repetition;
- phase offset;
- motion absence;
- incomplete relationship;
- material/value mismatch;
- light-source contradiction;
- controlled residue;
- selective temporal behavior.

## 6.4 Color-blind safety

Gameplay-critical distinction must preserve at least one non-hue cue such as:

- form;
- direction;
- frequency;
- scale;
- material pattern;
- animation;
- outline/mass relationship where art-authorized;
- sound/haptic redundancy.

---

# 7. Screen-space policy

Screen-space effects are high-risk because they can overwhelm camera readability.

## Allowed, bounded uses

- brief restrained camera-local droplets after water exposure;
- minimal heat/refraction where it does not obscure threat read;
- bounded authored transition support;
- accessibility-safe damage/state support only where gameplay authority requires it;
- cinematic-only treatment that is not needed for playable state recognition.

## Prohibited defaults

- permanent chromatic aberration for Hush;
- VHS/glitch overlays;
- large full-screen bloom pulses;
- heavy lens dirt;
- constant vignette as danger language;
- full-screen color wash as the only layer-state cue;
- repeated distortion every time Cantor is used;
- camera-covering boss phase effects;
- screen-space noise that hides reticle/target/player/environment edges.

Reduced Effects should be able to remove most optional screen-space treatment without semantic loss.

---

# 8. Combat VFX language

Combat visual effects support the actor and animation; they do not replace them.

## 8.1 Attack anticipation

Primary carrier:

- pose/mechanism state;
- silhouette;
- directional motion.

VFX may add:

- restrained local charge/pressure/heat/resonance support;
- contact-point dust/air movement;
- region/material-specific preparation cues.

VFX may not add a generic glowing “attack is coming” halo to every enemy.

## 8.2 Attack travel

Where an attack has a traveling world-space phenomenon, the effect must show:

- origin;
- direction;
- width/occupied space relationship;
- temporal movement;
- termination/contact behavior.

Avoid ambiguous giant cones that cover the attacker and floor.

## 8.3 Impacts

Impacts must reflect material and force.

Families:

- flesh/fur/keratin;
- wood/root;
- stone;
- cast metal;
- ceramic;
- water;
- glass/black-glass;
- Hush relationship.

Do not use one sparks-plus-smoke hit effect for all surfaces.

Hit effects should remain shorter/smaller than the body motion unless the attack itself is an authored environmental event.

## 8.4 Guard / deflection

Guard feedback must emphasize contact direction and material interaction.

Do not use a giant circular shield flash if no literal or semantic shield exists.

## 8.5 Evade

No mandatory invulnerability glow or trail unless combat authority later requires a readable invulnerability state.

Movement remains the primary cue.

## 8.6 Damage states

Persistent damage is not represented through escalating generic smoke/fire on every enemy.

Persistent visual damage requires:

- authored state ownership;
- material/geometry justification;
- clear relationship to encounter mechanics;
- accessibility-safe redundancy.

---

# 9. Cantor Key / resonance VFX language

The Cantor Key is an engineered diagnostic/tuning instrument, not a wand.

## 9.1 Core visual principle

> **The Key reveals relationships; it does not cast spells.**

Effects should originate from:

- moving prongs/weights/hammer components;
- contact or alignment points;
- linked machinery;
- surfaces being compared;
- local seam relationship.

Avoid firing free-floating bolts from Neris’s hands.

## 9.2 Diagnostic response

Default class: `VFX-G/S`.

Must communicate the result already owned by Cantor/tool gameplay authority.

Preferred presentation:

- thin bounded pulse along actual relation;
- local material/value response on compared surfaces;
- restrained concentric/arc response around the measured object;
- mechanical response on the Key;
- clearly terminating rather than persistent fantasy aura.

Must not imply:

- target eligibility that gameplay has not granted;
- puzzle solution before source systems expose it;
- weak point status;
- permanent ownership of state.

## 9.3 Successful local accord / tuning

Avoid “green success explosion.”

Success may use:

- mechanical settling;
- convergence of previously disagreeing pulses;
- reduction of unstable motion;
- synchronized local material response;
- quiet cessation of unnecessary particles.

Stillring should sometimes communicate success by **less effect**, not more.

## 9.4 Incorrect / incompatible relation

Avoid “red error sparks.”

Use:

- misaligned rhythm;
- pulse termination at the mismatch;
- directional disagreement;
- local value separation;
- non-destructive mechanical chatter where authority supports it.

## 9.5 Seam mode

Seam presentation is governed by Gate 4 and `docs/162`.

A seam is not a universal glowing portal.

VFX may reveal:

- boundary instability;
- related-state residue;
- local correspondence lines;
- controlled depth/value discontinuity.

VFX may not grant transition legality.

---

# 10. Tool-family VFX

Tool effects must follow the tool’s physical/mechanical identity.

## 10.1 Anchor Line

Primary cue is line geometry/attachment and actor motion.

VFX support:

- contact dust/fiber response;
- tension vibration;
- small mechanical lock response;
- region-appropriate debris at attachment.

No magical tether beam.

## 10.2 Glasslung

Effects should emphasize:

- air/water relationship;
- condensation;
- pressure equalization;
- localized bubbles where physical context supports them.

No generic underwater aura.

## 10.3 Temper Gauntlet

Effects derive from:

- heat transfer;
- material temperature;
- contact state;
- cooling/heating process.

Use visible thermal consequence rather than fireball language.

## 10.4 Vane Cloak

Primary read is cloth/body relation to airflow.

VFX support:

- sparse wind streaks only where necessary;
- dust/leaves/snow/ash revealing flow;
- local pressure sheets.

Do not paint permanent glowing wind highways through the world.

## 10.5 Mirror Nail

Effects derive from reflection/alignment relationship.

Use:

- bounded reflected image mismatch;
- local specular/value relation;
- directional alignment cue.

Avoid hologram-tech language.

---

# 11. Traversal / movement VFX

Traversal effects are secondary feedback.

Allowed families:

- landing dust/splash tied to material and force;
- footstep displacement where readable/appropriate;
- mantle debris/contact dust;
- ladder contact dust/rust only when material supports it;
- swim wake/splash;
- slope slide debris;
- Line Skiff wake/wind/route machinery effects.

Rules:

- no speed-line anime overlay for Sprint;
- no permanent glow trail behind Neris;
- no VFX indicating climbability where traversal authority has not granted it;
- no “ledge sparkle” system;
- material response should scale with actual surface, not player importance.

---

# 12. Puzzle / interactable VFX

Puzzle readability begins with world design and machinery state.

VFX may support:

- active power/pressure/resonance path;
- local mechanism readiness;
- authored target state;
- successful relation;
- unsafe/overloaded condition;
- Hush/Waking paired expression.

VFX must not turn every interactable into a glowing collectible.

## 12.1 Default inactive state

No effect is required merely because an object is interactable.

## 12.2 Player-relevant active state

Use the smallest sufficient world-space response.

## 12.3 Completion

Prefer machinery settling, physical motion and state change over celebratory particle bursts.

---

# 13. Region environmental VFX scripts

These families implement `docs/161`; they do not replace its lighting/material authority.

## 13.1 Brindle

Core VFX identity:

- restrained pollen/dust in useful light;
- chimney/workshop smoke from actual sources;
- orchard leaf movement;
- rain/runoff/flood response where weather/state requires;
- small metallic work sparks only at actual work events.

Hush:

- fewer ordinary motes;
- selective motion suspension;
- repeated dust fall or impossible persistence only in bounded authored locations;
- Vale Workshop wrongness comes primarily from object/material relationship, not a room full of particles.

Forbidden:

- dreamy fairy-pollen tutorial treatment.

## 13.2 Cairnspire

Core VFX identity:

- service steam/pressure release;
- lift/cable dust and brake particulate;
- civic workshop sparks at actual maintenance;
- rain runoff between vertical levels;
- restrained atmospheric depth between city layers.

Hush:

- locally precise pressure releases occurring against absent occupancy;
- repeated service-cycle traces;
- disagreement between linked machine pulses.

Forbidden:

- cyberpunk steam-everywhere wall of haze.

## 13.3 Rootmere

Core VFX identity:

- wet-canopy drips;
- insects in inhabited warm pockets;
- spores/pollen only from actual biological sources;
- ferry/wet-ground splash;
- root/resin work particulate.

Hush:

- suspended droplets in selected authored pockets;
- repeated biological release cycles;
- reduced ordinary insect motion;
- contradictory water/vegetation motion relationships.

Forbidden:

- glowing fantasy spores coating the whole biome.

## 13.4 Saltreach

Core VFX identity:

- sea spray;
- fog banks;
- wind-driven salt/rain;
- pressure venting;
- dock splash;
- signal smoke/light atmosphere where infrastructure owns it.

Hush:

- fog may preserve wrong sightline relationships;
- spray may continue while nearby flexible material motion pauses;
- pressure traces may repeat without human operation.

Forbidden:

- constant storm spectacle that makes ordinary coast unreadable.

## 13.5 Emberstep

Core VFX identity:

- geothermal steam;
- heat shimmer used selectively;
- kiln smoke with source-specific density;
- sparks/scale during active casting;
- ash/dust tied to wind and work;
- cooling vapor.

Hush/Post-Stillness:

- heat and particulate cycles may disagree;
- furnace effects can become locally too stable or repeat;
- changed production uses smaller distributed source effects rather than one giant citywide furnace spectacle.

Forbidden:

- permanent orange ember storm;
- omnipresent heavy refraction.

## 13.6 High Aerie

Core VFX identity:

- wind expressed through environment first;
- sparse snow/dust/cloud moisture where weather supports it;
- rope/cloth particulate minimal;
- pressure condensation around selected wind machinery.

Stillness/Hush:

- **absence of expected wind VFX is itself a primary state signal**;
- particles should reduce rather than increase when the environment stops moving;
- moving windows use clear local airflow evidence without turning into glowing corridors.

Forbidden:

- permanent white wind ribbons.

## 13.7 Mireglass

Core VFX identity:

- marsh mist;
- insects;
- reed pollen/seed release;
- shallow-water disturbance;
- reflection-linked light/surface response.

Hush:

- mismatched surface disturbance/reflection timing;
- selective absent ripple;
- locally repeated moisture traces;
- restrained residue around memory/reflection relationships.

Forbidden:

- full-screen dream blur;
- glitter on every reflective surface.

## 13.8 Cairnfall

Core VFX identity:

- dry plateau dust;
- high-altitude thin cloud/moisture;
- mechanical bearing dust;
- restrained optical/measurement effects tied to real instruments;
- occasional old-machine particulate during motion.

Hush:

- alignment pulses disagree across instruments;
- dust/motion may preserve abandoned measurement cycles;
- seam-mode effects remain local and instrument-related.

Forbidden:

- wizard observatory star-particle wallpaper.

---

# 14. Hush VFX production grammar

`docs/162` remains authoritative for H0–H5 production burden and semantic/art separation.

VFX adds the following locked rules.

## 14.1 Hush effect stack priority

Prefer, in order:

1. world/material relationship;
2. occupancy/motion absence;
3. local light contradiction;
4. authored geometry relation;
5. restrained residue VFX;
6. optional post-process support.

VFX is intentionally late in the stack.

## 14.2 Repetition

When repetition is used, repeat a **meaningful local event or trace**, not random particles.

Examples:

- the same dust release occurs from one drawer each cycle;
- one pressure vent repeats without the worker who should trigger it;
- a reflected splash repeats while the water remains still;
- one falling fragment reaches a point and returns because the authored local relation is preserved.

Do not loop everything.

## 14.3 Residue

Residue should be specific enough that the player can relate it to a known person/object/action.

Avoid generic ghost silhouettes wandering everywhere.

## 14.4 Transition support

Layer transitions may receive bounded authored VFX, but transition legality and occupancy safety belong to Hush gameplay authority.

Reduced Effects must preserve transition readability without full distortion/particles.

## 14.5 Reduced Hush Effects

When Hush effects are reduced:

- remove optional particles first;
- remove most screen-space distortion;
- reduce repeated micro-residue;
- preserve material/value relationship;
- preserve essential geometry/state difference;
- preserve critical seam/transition cue through non-color world-space language;
- preserve character/enemy recognition.

Reduced Hush Effects is not “Hush off.”

---

# 15. Enemy / boss VFX matrix

The enemy/boss visual identity in `docs/159` remains primary.

## 15.1 Mossjaw

VFX burden: low.

Use:

- wet-ground displacement;
- root/leaf/debris response;
- harness contact dust/fiber;
- compact impact material response.

Do not add glowing weak points or corruption aura.

## 15.2 Mawhart

VFX burden: moderate and component-focused.

Use:

- stressed wood/resin particulate;
- brace tension response;
- bell-oak biological/material release;
- restrained resonance at actual infrastructure contact.

Liberation should visually end in **reduced mechanical stress**, not a victory explosion.

## 15.3 Nine-Lung Leviathan

VFX burden: high environmental/pressure relation.

Use:

- water displacement;
- pressure venting;
- bubbles/cavitation where physically plausible;
- hardware leak/strain response;
- fog/spray integration.

Do not turn the creature into a bioluminescent raid boss.

## 15.4 Cinder Regent

VFX burden: high industrial readability.

Use:

- heat state;
- molten/casting process response where canon supports it;
- pressure/steam;
- scale/spark release;
- cooling-state transitions.

Effects must identify dangerous operation through machine posture + local process, not giant fire cones alone.

## 15.5 Choir of Talons

VFX burden: low-to-moderate.

Use:

- wind/feather/dust response;
- dive-direction environmental cue where needed;
- contact debris.

Do not give ordinary predators magical wing trails.

## 15.6 Saint Varo

VFX burden: high Hush relational.

Use:

- inconsistent preserved traces;
- official-memory repetition;
- controlled spatial residue tied to contradictory evidence.

Do not use saintly holy-light spectacle.

## 15.7 Archivist Without a Face

VFX burden: high relationship/state simplification.

Use:

- removal/suppression of contradictory record traces;
- flattening or cessation of selected visual state;
- restrained repeated annotation/record residue.

Do not make a black glitch cloud.

## 15.8 Mirror Widow

VFX burden: high reflection/state relationship.

Use:

- mismatched reflection timing;
- incompatible silhouette residue;
- selective reflected motion continuing after body motion stops.

Do not rely on mirror-shard particle spam.

## 15.9 Gravemoon Engine

VFX burden: high machine/alignment readability.

Use:

- alignment traces along actual instrument axes;
- correction-state pulses;
- bearing dust/mechanical friction;
- restrained optical effect tied to measurement.

Do not produce giant galaxy effects detached from machine geometry.

## 15.10 Echo-bound Orin

VFX burden: high environmental state, low body spectacle.

Orin remains visually human.

Use:

- preserved safe-state relationships in arena/environment;
- repeated useful-state traces;
- bounded Hush residue around the preserved relation.

Do not outline Orin with boss aura or monsterize him.

## 15.11 Maelor

VFX burden: high system integration, restrained body treatment.

Use:

- Meridian/Stillring machine relationships;
- controlled field/alignment/pressure effects;
- escalating environmental system behavior.

Maelor himself does not gain demonic aura, energy wings or giant transformation.

## 15.12 Listener

VFX burden: special / cross-discipline.

The Listener is not a particle character.

VFX may contribute:

- incomplete spatial traces;
- restrained overlap of incompatible familiar states;
- localized residue connecting preserved possibilities;
- disappearance/release behavior during decommission.

The experience must still work if the particle layer is reduced heavily.

---

# 16. Machinery VFX language

Civic machinery should look engineered and maintainable.

Common families:

## Pressure

- steam/mist jets;
- gauge/material response;
- condensation;
- leak traces;
- pressure-release bursts.

## Heat

- localized shimmer;
- surface temperature response;
- sparks/scale from actual work;
- cooling vapor.

## Resonance

- restrained local pulses;
- material vibration response;
- dust/water reaction where useful;
- connection-line response along actual structures.

## Friction / motion

- bearing dust;
- brake dust;
- small spark only where metal contact plausibly produces it;
- rope/fiber release;
- debris from real mechanical wear.

A machine should not look “powered” merely because an emissive shader and particle system are active.

---

# 17. Weather interaction policy

Weather effects must coexist with combat and tool VFX.

Rules:

- weather density yields around critical combat staging when necessary;
- fog cannot erase target silhouettes or attack direction;
- rain/snow/ash may reduce locally around camera only through technically justified readability controls, not visibly artificial bubbles;
- gameplay-critical effects must survive the strongest authored weather;
- weather color/value must not cause two critical effect states to collapse into the same read;
- wetness/splash is surface-contextual, not a universal material layer.

Representative validation later requires combat/tool tests in each region’s worst ordinary weather condition.

---

# 18. Character VFX policy

Principal characters should not carry permanent “hero aura.”

Allowed:

- tool-origin effects;
- wetness/spray/dust response;
- bounded injury/state presentation if later gameplay/narrative authority requires it;
- Hush relation effects when a specific state requires them;
- contact/work effects.

Avoid:

- permanent rim glow;
- glowing footsteps;
- idle magical motes;
- rarity-style equipment particles;
- cinematic beauty particles around faces;
- gender-coded glitter/soft glow.

Neris’s readability comes from design and motion, not VFX branding.

---

# 19. Lighting interaction

Effects may contribute local light only where the physical/semantic source justifies it.

Use restraint with emissive contribution.

Gameplay-critical information must not disappear when dynamic-light scalability is reduced.

Examples:

- kiln flame/heat may illuminate nearby surfaces;
- a pressure spark may produce a brief local flash;
- resonance may create restrained local material/light response;
- Hush contradiction may alter local light relation where `docs/161/162` support it.

Avoid using point lights on every particle merely to make effects look expensive.

---

# 20. Audio / haptic dependency

VFX is one carrier in a multisensory system.

For gameplay-critical effects, the effect manifest should identify expected redundancy such as:

- attack audio;
- mechanism click/pressure release;
- Cantor tone;
- controller pulse;
- environmental change;
- animation contact.

However:

- VFX cannot assume audio is always heard;
- audio cannot assume VFX is always at full quality;
- haptics cannot be the only warning;
- accessibility may disable/reduce any one carrier.

The future Audio Bible owns final sound language and timing.

---

# 21. Accessibility / Reduced Effects contract

Stillring requires a Reduced Effects path that preserves gameplay truth.

## 21.1 Reduction order

When reducing effect intensity, remove/reduce in this order:

1. decorative micro-particles;
2. screen-space overlays/distortion;
3. tertiary atmospheric particles;
4. secondary trails/ribbons;
5. non-semantic bloom/emission;
6. redundant state-communication particles;
7. only then simplify gameplay-critical particles while preserving their primary shape/direction/state cue.

## 21.2 Never remove

Reduced Effects may not remove the last readable carrier of:

- attack direction/readiness;
- hazard state;
- seam/transition state;
- puzzle-active relation;
- boss component state;
- Line Skiff route/mechanism state;
- required environmental danger.

If removing particles destroys understanding, the effect was over-owning gameplay information.

## 21.3 Photosensitivity risk

Avoid, especially in repeatable gameplay:

- rapid full-screen flashes;
- high-contrast strobing;
- repeated alternating full-screen color;
- large high-frequency flicker fields;
- dense uncontrolled emissive noise.

Exact accessibility acceptance criteria and platform guidance must be verified later through dedicated accessibility/technical authority and human testing.

## 21.4 Motion sensitivity

Reduced Effects should remove or reduce:

- heavy camera-local distortion;
- high-speed screen-space streaking;
- persistent peripheral motion;
- unnecessary particle fields moving against camera motion.

World-space semantic cues remain.

---

# 22. Scalability philosophy

This document does not invent numeric VFX budgets.

Later technical production must measure:

- GPU simulation cost;
- CPU emitter cost;
- translucency overdraw;
- material complexity;
- light contribution;
- memory;
- spawn count;
- collision/query cost;
- bounds/culling behavior;
- worst-case combat/weather/Hush overlap.

Current production rule:

> **Scalability removes richness before it removes meaning.**

Every `VFX-G` family needs an explicit low-quality version that remains semantically legible.

Every `VFX-A` and `VFX-D` family may have aggressive culling/reduction.

---

# 23. VFX reuse architecture — visual, not technical

The studio should build reusable visual families rather than bespoke systems for every event.

Recommended production families:

- material impact library;
- water interaction library;
- dust/debris library;
- pressure/steam library;
- heat/cooling library;
- resonance pulse/relationship library;
- Hush residue/repetition primitives;
- wind-reveal library;
- environmental atmospheric families per region;
- machinery motion/contact library;
- boss-specific authored extensions built on shared primitives.

Reuse must not flatten regional identity.

A Saltreach pressure release and an Emberstep cooling vent may share technical primitives later while differing in moisture, density, material response, color/value and surrounding context.

---

# 24. Production uniqueness tiers

## FX-U0 — Shared primitive

Examples:

- generic dust kernel;
- common impact spark component;
- base droplet/splash primitive;
- generic pressure-sheet primitive.

Not visible as a final identity by itself.

## FX-U1 — Regional family

Examples:

- Rootmere wet biological particulate;
- Saltreach spray/fog family;
- Emberstep heat/ash family;
- High Aerie wind-reveal family.

## FX-U2 — Gameplay/system family

Examples:

- Cantor diagnostic relation;
- seam-state support;
- common boss-component state support;
- Line Skiff operational family.

## FX-U3 — Hero encounter / narrative

Examples:

- Grand Ring authored sequence;
- Ilyra reunion Hush relationship;
- Gravemoon correction-state sequence;
- Maelor/Null Meridian system escalation.

## FX-U4 — Finale-special

Reserved for Listener/decommission content that cannot be produced honestly through U0–U3 reuse.

Requires explicit production rationale.

---

# 25. Major authored-sequence burden

Current narrative/art authority implies at least these high-priority authored VFX sequences:

- First Ring failure / Brindle breach;
- first meaningful Cantor/Hush relation reveal;
- regional Waybell repair/resolution events;
- Grand Ring activation/failure;
- Stillness transition consequences;
- Line Skiff activation/route-operation support;
- Ilyra Hush reunion presentation;
- High Aerie moving-window/Stillness contrast;
- Mireglass reflection-state encounter support;
- Cairnfall / Gravemoon alignment correction;
- Still-Cairn / Echo-bound Orin preservation states;
- Null Meridian S1–S6 synthesis spaces;
- Maelor final system escalation;
- Listener legibility/release;
- Meridian heart decommission / Unringing.

These are production burdens, not permission to invent new cinematic events.

Each sequence must be decomposed later into reusable families plus justified bespoke elements.

---

# 26. VFX naming / handoff requirements

Exact UE package naming belongs to the Technical Production Bible.

The production manifest must nevertheless preserve semantic clarity.

Each effect entry should include a stable human-readable production ID pattern such as:

`FX_<SYSTEM>_<FAMILY>_<STATE>`

Examples of conceptual naming only:

- `FX_CANTOR_DIAGNOSTIC_COMPARE`;
- `FX_HUSH_SEAM_ELIGIBLE`;
- `FX_EMBERSTEP_KILN_PRESSURE_RELEASE`;
- `FX_BOSS_GRAVEMOON_CORRECTION_ACTIVE`.

These are not canonical runtime IDs and must not be persisted as gameplay identity merely because they exist in art production.

---

# 27. Review gates

## Gate FX-A — Semantic ownership

Pass when:

- triggering system is named;
- state owner is named;
- effect does not invent gameplay state;
- what the effect does **not** communicate is explicit.

## Gate FX-B — Readability keyframe

Pass when:

- dominant shape is clear;
- direction/state reads without bloom;
- color-independent redundancy exists;
- actor/player/environment silhouette remains readable.

## Gate FX-C — Reduced Effects design

Pass when:

- low-intensity version is designed, not improvised later;
- semantic read survives;
- optional screen-space/particle layers can be removed.

## Gate FX-D — Cross-condition proof

Later representative runtime only.

Requires testing under:

- strongest authored weather;
- Hush;
- combat overlap;
- bright daylight;
- dark interior/night;
- representative camera distance;
- Reduced Effects;
- lower scalability.

## Gate FX-E — Performance proof

Later technical/runtime evidence.

Requires measured budgets on selected target hardware/product baseline.

## Gate FX-F — Final production acceptance

Requires:

- semantic correctness;
- art-direction compliance;
- accessibility compliance;
- performance compliance;
- source/provenance retention;
- no regression to spectacle-over-readability.

---

# 28. Hard failures

Reject an effect or effect language if:

- it becomes the only owner of gameplay truth;
- color is the only critical distinction;
- bloom is required to understand it;
- it hides attack/player silhouettes;
- it makes every interaction glow;
- it makes all Hush content purple/blue;
- it turns Cantor into spellcasting;
- it turns ordinary fauna into glowing fantasy monsters;
- it gives Maelor a dark-lord aura;
- it turns Listener into a particle creature;
- it uses full-screen distortion as identity;
- it creates constant particle motion because quiet space “felt empty”;
- it introduces a visual grammar unique to the finale without precedent;
- it cannot be meaningfully reduced for accessibility/scalability;
- it implies a traversal, weak-point, puzzle or damage state that the owning system does not grant.

---

# 29. Decision rights

## LOCKED — implement, do not redefine

- VFX presents state; source systems own state;
- classes `VFX-G`, `VFX-S`, `VFX-A`, `VFX-C`, `VFX-D`;
- gameplay-critical information requires non-color redundancy;
- VFX is subordinate to silhouette/animation/mechanism state in combat telegraphs;
- Cantor effects remain diagnostic/mechanical rather than spellcasting;
- no universal interaction glow;
- no universal Hush color/filter/glitch language;
- region environmental effect identities in §13;
- boss effect boundaries in §15;
- no permanent hero aura;
- Reduced Effects reduction order and semantic-preservation rules;
- scalability removes richness before meaning;
- Listener is not a particle character;
- High Aerie Stillness may communicate through absence of particles/motion;
- success/resolution may be communicated through reduction/cessation rather than more spectacle.

## STUDIO CHOICE WITHIN BOUNDS

- exact sprite/mesh/ribbon/volume composition;
- emitter decomposition;
- authoring software;
- flipbook design;
- simulation method;
- material-node architecture;
- local effect timing polish that does not alter gameplay timing;
- exact particle shapes within locked dominant-form requirements;
- exact environmental culling strategy;
- exact implementation of Reduced Effects variants;
- effect LOD implementation.

## RUNTIME / TECHNICAL EVIDENCE

- Niagara or alternate implementation architecture;
- GPU versus CPU simulation choices;
- spawn counts;
- translucency budgets;
- overdraw limits;
- light counts;
- memory budgets;
- effect bounds;
- collision/query use;
- exact scalability tiers;
- exact timing values tied to gameplay animation;
- final screen-space intensity;
- representative target-hardware acceptance.

## OWNER REVIEW REQUIRED

- material redefinition of the overall VFX language;
- moving toward spectacle-heavy magic effects as a game-wide identity;
- changing Cantor from engineered diagnostic presentation into supernatural casting;
- changing Hush into a global color/filter/glitch style;
- changing Listener into a singular creature/entity body;
- introducing new finale-only visual grammar that materially changes Stillring’s identity.

---

# 30. Quoteable production burden

At written-authority level, a studio should plan for:

- one shared material-impact family with region/material variants;
- one shared water-interaction family;
- one shared pressure/steam family;
- one shared heat/cooling family;
- one shared wind-reveal family;
- one Cantor/resonance system family;
- one Hush residue/repetition primitive family;
- eight regional environmental effect packages;
- tool-specific support families for Anchor Line, Glasslung, Temper Gauntlet, Vane Cloak and Mirror Nail;
- traversal/contact families;
- machinery operational families;
- gameplay-critical combat telegraph support;
- bespoke/extended boss packages for the encounters identified in §15;
- authored sequence packages identified in §25;
- Reduced Effects/scalability variants for every gameplay-critical family.

This is a production-family inventory, not an exact emitter count.

Emitter counts, material counts, memory, staffing estimates and schedule duration belong to later production planning and technical evidence.

---

# 31. What remains genuinely open

The following are intentionally dependency-bound rather than creatively blank:

- numeric particle/emitter budgets;
- overdraw targets;
- memory targets;
- Niagara architecture;
- GPU/CPU simulation split;
- exact screen-space distortion limits;
- exact VFX scalability tiers;
- exact effect timing synchronized to final animation;
- exact lighting contribution budgets;
- final platform-specific accessibility implementation;
- final render-target/volume/shader techniques;
- representative runtime proof under worst-case overlaps.

Those are not permissions to redesign the effect language.

---

# 32. VFX handoff acceptance test

An external VFX lead should be able to answer from repository authority:

1. What state does this effect present?
2. Which gameplay/world system owns that state?
3. Is the effect gameplay-critical, state-communication, atmospheric, cinematic or decorative?
4. What is the dominant readable form?
5. What remains if particle density is reduced?
6. What remains if hue distinction is unavailable?
7. Can the actor/player/environment silhouette still be read?
8. Does the effect belong to the region/material/system that caused it?
9. Does it accidentally imply a weak point, route, puzzle target or danger that does not exist?
10. Does it remain coherent in Hush without becoming a generic glitch effect?
11. Does Reduced Effects preserve semantic truth?
12. Can the effect be scaled technically without deleting meaning?
13. Is bespoke production genuinely justified, or can a shared family express it?
14. Does the effect introduce a genre shorthand that Stillring has intentionally rejected?

If those questions cannot be answered, the effect is not production-ready.

---

# 33. Governing principle

> **Stillring should use effects to make causes and relationships easier to understand—not to prove how many particles the engine can draw.**

A great Stillring effect may be a pressure valve exhaling at exactly the right moment.

It may be a thin diagnostic pulse showing two machines disagree.

It may be rain revealing wind direction.

It may be a Hush room becoming disturbing because one expected motion stops.

It may be a boss resolution becoming powerful because the noise and effects finally cease.

The highest-quality VFX choice is the one that leaves the player understanding more and seeing the game more clearly.