# 167 — Board 05 Gameplay Readability Source Brief

**Status:** ACTIVE / PRODUCTION REFERENCE SOURCE BRIEF / DOCUMENTATION-ONLY  
**Updated:** 2026-09-06  
**Parent art authority:** `docs/154_STILLRING_ART_BIBLE.md`  
**Reference-method authority:** `docs/155_ART_REFERENCE_METHOD_AND_BOARD_INDEX.md`  
**Locomotion authority:** `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`  
**Camera authority:** `docs/22_GATE1_CAMERA_SPECIFICATION.md` plus current supporting camera addenda where framing/target-lock detail is required  
**Player-combat authority:** `docs/48_GATE2_COMBAT_STATE_MODEL.md`  
**Encounter authority:** `docs/50_GATE2_ENCOUNTER_ATTACK_BANDWIDTH_ADDENDUM.md`, `docs/55_GATE2_OFFSCREEN_OCCLUDED_THREAT_ADDENDUM.md`, and current Gate 2 encounter addenda  
**Tool/puzzle authority:** `docs/68_GATE3_TOOL_FAILURE_READABILITY_ACCESSIBILITY_ADDENDUM.md`, `docs/69_GATE3_TOOL_SYSTEM_CUMULATIVE.md`  
**Hush authority:** `docs/79_GATE4_HUSH_CUMULATIVE_SPECIFICATION.md`, `docs/162_HUSH_VISUAL_PRODUCTION_MATRIX.md`  
**Enemy/boss art authority:** `docs/159_ENEMY_BOSS_ART_MANIFEST.md`  
**Regional visual authority:** `docs/160_REGION_ENVIRONMENT_PROP_MANIFEST.md`, `docs/161_REGIONAL_COLOR_MATERIAL_LIGHTING_SCRIPTS.md`, `docs/165_BOARD_02_REGIONAL_SHAPE_LANGUAGE_SOURCE_BRIEF.md`, `docs/166_BOARD_04_LIGHTING_ATMOSPHERE_TIME_SOURCE_BRIEF.md`  
**VFX authority:** `docs/163_VFX_PRODUCTION_MANIFEST.md`  
**Board slot:** Board 05 — Gameplay Readability  
**Boundary:** this file defines what the Board 05 execution artifact must prove visually. It does not authorize UE5.8 implementation, gameplay tuning, level-layout changes, route eligibility, collision, attack timing, target-selection logic, UI production lock, exact colors/icons, Hush semantics, VFX budgets, camera values, accessibility acceptance, runtime performance, or human-play claims.

---

# 1. Purpose

Board 05 exists to prove that **Stillring can communicate what the player may do, what is happening, and what deserves attention without turning Orra into a theme park of paint, outlines, glowing sockets, attack cones and scanner highlights**.

It is not a UI style board.

It is not a level-design rewrite.

It is not an accessibility certification artifact.

It is not permission for art to decide gameplay legality.

The board must visually test the repository's governing readability principles:

- **simple intention, capable character, honest world**;
- the world should teach traversal through consistent physical language;
- valid interaction should be observable before tool/UI confirmation where practical;
- Cantor diagnoses relationships rather than replacing observation;
- Anchor interacts with authored physical relationships rather than arbitrary glowing sockets;
- enemy threat type and attack direction must read through body/mechanism state before particles;
- encounter danger must remain attributable within the camera's actual visual bandwidth;
- target lock does not grant enemies special visual or gameplay authority;
- offscreen warning is a bounded supplement for already committed threats, not radar;
- Hush/weather/lighting may change presentation without erasing route, threat, interaction or character readability;
- critical information may not depend on color, stereo audio, haptics, bloom or dense VFX alone;
- Reduced Effects/scalability should remove richness before meaning.

The governing test is:

> **A player should understand the practical world-state from shape, placement, motion, material and value first; UI/VFX may confirm or reinforce that truth, but must not invent it.**

---

# 2. Authority order and non-reopening rule

Board 05 is subordinate to gameplay semantics.

When a visual study creates a conflict, resolve authority in this order:

1. current gameplay/world-state authority;
2. accessibility/readability requirements already locked by that authority;
3. camera/encounter presentation constraints;
4. `docs/154` Art Bible;
5. `docs/159`, `docs/162`, `docs/163` where relevant;
6. this Board 05 brief;
7. approved visual execution;
8. later technical/runtime implementation and tuning.

Board 05 may **not** redefine:

- what geometry is walkable, mantleable, catchable, climbable, swimmable or traversable;
- ledge catch/shimmy/release rules;
- ladder mount/release semantics;
- slope or fall rules;
- Anchor traversal eligibility;
- tool compatibility;
- Cantor acquisition or procedure semantics;
- combat Startup/Active/Recovery;
- Guard/Perfect Guard/Evade legality;
- attack commit permission;
- enemy weak points, armor, damage immunity or lockable parts;
- offscreen attack legality;
- target-lock rules;
- Hush semantic identity or route legality;
- hazard damage/activation state;
- puzzle solution facts;
- checkpoint/save state.

If the art suggests a gameplay permission the current gameplay authority does not grant, the art fails.

If valid gameplay requires an affordance that cannot be read from the current visual language, that is a production-readability problem to solve **inside the locked semantics**, not permission to change the semantics silently.

---

# 3. Required output package

Board 05 is a **board family**, not a single decorative collage.

Recommended repository targets once binary visual production is active:

- `docs/art/boards/05_GAMEPLAY_READABILITY_A_TRAVERSAL.png`
- `docs/art/boards/05_GAMEPLAY_READABILITY_B_TOOLS_PUZZLES.png`
- `docs/art/boards/05_GAMEPLAY_READABILITY_C_COMBAT_TARGETING.png`
- `docs/art/boards/05_GAMEPLAY_READABILITY_D_HUSH_WEATHER_REDUCED_EFFECTS.png`
- `docs/art/boards/05_GAMEPLAY_READABILITY_E_FAILURES_AND_REDUCTIONS.png`
- neighboring Markdown provenance/status note.

Minimum working resolution per sheet: **3840 × 2160** or equivalent pixel area with annotations legible at 100% display.

The board package may use additional sheets if necessary to keep gameplay-distance examples large enough to judge.

Every panel must label:

- gameplay domain;
- location/region where applicable;
- camera context;
- source authority;
- what semantic fact is being visualized;
- which channels carry that fact: shape / placement / material / value / motion / animation / VFX / UI / audio / haptics;
- which channels are primary versus supplemental;
- whether the image is external reference, Stillring study, generated exploration or approved production-reference execution;
- noncanonical details visible in external/generated imagery.

---

# 4. Comparison discipline

## 4.1 Gameplay camera first

All core Board 05 examples must be judged from a camera relationship consistent with current third-person gameplay authority.

Use:

- ordinary medium-wide exploration framing for exploration/traversal/tool examples;
- established target-lock relationship framing for combat examples where lock is relevant;
- large-boss framing only where current camera authority supports it;
- normal gameplay-distance enemy presentation for telegraph tests.

Do not use a detached cinematic camera to prove readability.

A ledge, attack, mechanism or character that only reads in a close-up concept shot has not passed Board 05.

## 4.2 Same-scene A/B comparisons

Where possible, compare the same scene with one variable changed:

- valid traversal affordance versus nearby invalid lookalike;
- tool unready versus tool-ready confirmation;
- ordinary scene versus weather;
- Waking versus Hush;
- full effects versus Reduced Effects;
- full color versus grayscale/desaturated view;
- visible threat versus committed threat transitioning offscreen.

Do not compare unrelated scenes and claim the difference proves a readable state change.

## 4.3 No invented meter values

Board 05 may use relational labels such as:

- clear / ambiguous / blocked;
- primary / secondary / background;
- visible / edge-degraded / offscreen / hard-occluded;
- committed / non-committed;
- valid affordance / invalid lookalike;
- world cue / confirmation cue / explanatory cue.

It may not invent exact:

- interaction ranges;
- mantle/ledge dimensions;
- attack windows;
- reaction times;
- target-lock screen percentages;
- indicator timing;
- VFX density budgets;
- contrast ratios;
- accessibility multipliers;
- camera distances/FOV;
- color values as gameplay truth.

Those require current tuning/technical/runtime authority.

---

# 5. Readability priority stack

When several channels compete, Board 05 should preserve this order unless a gameplay authority explicitly requires otherwise:

1. **world geometry / body / mechanism state**;
2. **silhouette and directional pose**;
3. **placement / spatial relationship**;
4. **material and value separation**;
5. **movement / animation**;
6. **restrained VFX or tool-ready confirmation**;
7. **UI explanation / directional supplement**;
8. **audio / haptic reinforcement**.

This is not a universal rule that UI is always late or weak.

It is the production test for whether Stillring's world remains understandable without converting every game fact into an overlay.

Critical gameplay facts may use multiple channels simultaneously.

---

# 6. Sheet A — Exploration / Traversal Readability

Sheet A verifies the **honest world** contract.

It must show valid affordances and nearby non-affordances without relying on universal highlight paint.

## 6.1 Required traversal comparison families

Show representative gameplay-distance studies for:

1. ordinary walkable ground / route;
2. automatic small-step/stair handling;
3. low authored mantle/scramble object;
4. valid reachable ledge/handhold;
5. same-continuous-handhold shimmy segment;
6. authored ladder;
7. low valid water exit;
8. ordinary non-climbable wall/cliff/root/masonry;
9. meaningful height gate that remains a route problem;
10. authored traversal-tool point only where current Tool authority says the relationship is valid.

These examples must demonstrate a **stable visual vocabulary**, not ten unrelated tricks.

## 6.2 Valid mantle versus decorative obstacle

The mantleable example should read through combinations of:

- plausible top surface;
- understandable edge/height relationship;
- route placement;
- construction/wear consistent with use;
- uncluttered silhouette at gameplay distance.

The nearby non-mantleable example must avoid looking like the exact same physical opportunity arbitrarily disabled.

Board 05 must not solve this by painting all mantleable objects one universal color.

## 6.3 Ledge / handhold readability

A valid authored handhold should visually support the existing ledge grammar:

- plausible reach/contact surface;
- continuous same-handhold read where shimmy is legal;
- top/side construction that explains where the hand can actually hold;
- separation from rough generic walls that are not baseline free-climb surfaces.

The sheet must include at least one **false-positive rejection study**:

> rough/grippy-looking world surface that should not accidentally advertise universal climbing.

The solution should come from shape/construction/world grammar, not a warning icon saying “cannot climb.”

## 6.4 Ladder readability

Show a ladder as an authored traversal structure that reads as mountable from a deliberate valid approach.

Do not imply:

- universal climbability of adjacent pipes/rails;
- magnetic sideways mounting;
- auto-climb cinematic sequence.

## 6.5 Water exit readability

Show:

- low credible exit that supports automatic surface-swim exit;
- nearby high/blocked edge that remains a traversal problem.

The distinction should survive water reflection, rain and night lighting where practical.

## 6.6 Route guidance without GPS paint

Show at least two exploration compositions where the world itself guides attention using:

- path alignment;
- landmark visibility;
- bridge/river/terrain flow;
- negative space;
- human activity;
- civic route infrastructure;
- selective light/value hierarchy.

Do not use an objective beam, minimap arrow or universal route stripe to rescue weak composition.

## 6.7 Traversal failure examples

Explicitly reject:

- universal yellow/white climbing paint;
- identical-looking ledges with arbitrary hidden legality;
- decorative rails that look like ladders everywhere;
- “everything rough is climbable” visual language;
- interaction decals pasted onto otherwise unreadable world geometry;
- cinematic composition that hides the playable route from the actual camera.

---

# 7. Sheet B — Tools / Puzzles / Interaction Readability

Sheet B verifies the three-layer readability contract from Gate 3:

1. **world layer first**;
2. **tool-ready confirmation second**;
3. **interface explanation when needed**.

## 7.1 World-layer mechanical causality

Show representative mechanisms where the player can see, before activating a tool:

- hinge/track/degree-of-freedom;
- load path;
- service point;
- attachment relationship;
- obstruction;
- tension/deformation;
- pressure/resonance activity;
- current material/mechanical state.

The mechanism should look understandable as a machine or maintained civic object before it looks like a puzzle prop.

## 7.2 Cantor examples

Required comparison strip:

1. ordinary scenery — no privileged scan presentation;
2. clear visible diagnostic relation;
3. ambiguous pair requiring view refinement;
4. blocked/opaque candidate;
5. not-actionable readable relation;
6. clear temporary diagnostic focus.

The strip must demonstrate:

- Cantor is deliberate and bounded;
- no room-wide treasure-radar effect;
- no through-wall objective reveal;
- no persistent outline on every future interactable;
- no single “magic cyan means solution” dependency.

Tool-ready cues may confirm current focus/response state, but they may not make the world unreadable without the tool active.

## 7.3 Anchor Line examples

Show representative authored relationships such as:

- movable load;
- track-constrained mechanism;
- detachable component;
- valid fixed traversal anchor where specifically authorized;
- fixed non-traversal load point;
- blocked direct load path;
- one active brace relationship.

The visual language must distinguish **what the object physically is** from **what the current semantic rules permit**.

Do not turn every Anchor-compatible point into a glowing socket.

Do not imply that any metal ring, hook or bolt is automatically compatible.

## 7.4 Quick semantic failure

Show at least four rejected-interaction examples paired with the practical reason:

- path blocked;
- incompatible/no purchase;
- fixed/non-movable relation;
- ambiguous relation / procedure unknown;
- active ownership conflict;
- invalid arrival state.

The world/tool presentation should fail quickly without a fake multi-second action.

Exact UI wording remains later UI/localization authority.

## 7.5 Puzzle anti-keycard panel

Include one explicit **DO / DON'T** comparison.

**DO:** visible machine relationship whose state can be diagnosed/manipulated consistently.  
**DON'T:** new-tool icon + glowing matching socket + door unlock with no physical explanation.

The panel must make clear that progression through a new capability is allowed; arbitrary item-key matching is not.

---

# 8. Sheet C — Combat / Targeting / Threat Readability

Sheet C verifies that combat danger remains attributable to embodied threats under the current camera and encounter bandwidth.

## 8.1 Enemy telegraph hierarchy

For at least three threat families, show an anticipation/telegraph sequence using:

1. body pose or mechanism state;
2. silhouette change;
3. directional movement;
4. material/value support;
5. restrained VFX;
6. optional audio/haptic redundancy noted separately.

Recommended families for contrast:

- biological melee/charge threat;
- ranged or moving-pressure threat;
- hazardous civic/industrial machine;
- large boss or Hush-pattern threat where useful.

The sequence must remain understandable with the VFX layer removed.

## 8.2 Threat type before spectacle

Enemy studies must preserve the `docs/159` rule that shape/motion communicates:

- force origin;
- locomotion class;
- threat direction/reach;
- defense/armor character where relevant;
- changing state;
- authored vulnerable/interactable feature only where gameplay authority actually provides one.

No visual study may invent a glowing weak point because the composition “needs a focus.”

## 8.3 One MajorCommit readability

Show a representative multi-enemy composition with:

- one enemy in genuine committed high-salience Telegraph;
- other enemies visibly active/repositioning/pressuring without fake identical urgent attack startups;
- enough spatial separation that the real committed threat is attributable;
- no passive waiting ring.

The purpose is not to visualize scheduler code.

The purpose is to prove the encounter can look alive while the actual immediate danger remains readable.

## 8.4 Major + Pressure overlap

Where current encounter authority permits a representative PressureCommit example, show:

- the Major threat retaining primary defensive salience;
- the pressure threat asking a distinct lower-bandwidth question;
- both sources attributable;
- no mutually unreadable VFX overlap;
- no identical urgent telegraph treatment.

Do not invent a new PressureCommit attack family merely to fill the board.

Use only an already-authorized example.

## 8.5 Target-lock relationship framing

Show a locked combat composition where:

- Neris and current target remain readable together;
- enough combat space remains visible to judge direction/footing;
- target marker/presentation, if included, is subordinate to the embodied target;
- secondary enemies do not acquire camera authority merely because they are dangerous;
- target lock is visually distinct from encounter commit permission.

Do not depict the locked target as “the only enemy allowed to attack.”

## 8.6 Offscreen committed-threat handoff

Show a three-frame sequence:

1. attack begins from meaningful visibility with readable body/world telegraph;
2. player/camera turns and source leaves meaningful frame while the already-committed threat continues;
3. bounded supplemental directional warning carries the remaining practical warning only if required by current authority.

The supplemental warning may communicate coarse direction/commit urgency.

It must not become:

- enemy radar;
- exact hidden enemy position;
- wallhack pathing;
- health/name display;
- readiness indicator for enemies that have not committed;
- camera steering.

Also include one hard-occluded rejection example showing that UI cannot make an impossible through-wall attack legal.

## 8.7 Combat clutter rejection

Reject examples where:

- impact particles cover the attacker during the next tell;
- floor effects obscure Neris's feet/evade path;
- every enemy emits the same urgent glow while only one threat is committed;
- screen-space damage/Hush effects obscure target silhouette;
- boss VFX erase body/mechanism state;
- weather particles become denser than attack information.

---

# 9. Sheet D — Hush / Weather / Lighting / Reduced Effects Stress Test

Sheet D proves readability survives presentation stress.

Use at least four matched gameplay scenes drawn from different domains:

- exploration/traversal;
- tool/puzzle;
- ordinary combat;
- boss/major encounter or Hush transition.

For each scene, compare appropriate combinations of:

1. ordinary Waking / base weather;
2. representative region weather;
3. Hush expression where canon applies;
4. Reduced Effects conceptual state;
5. grayscale or saturation-reduced review.

## 9.1 Hush recognition before wrongness

Hush panels must preserve:

- location identity;
- route readability;
- enemy silhouette/telegraph readability;
- interactable/mechanism hierarchy;
- Neris/background separation;
- seam or layer-state cues only where gameplay authority requires them.

Wrongness should come from relation:

- missing/repeated wear;
- contradictory occupancy;
- selective motion absence;
- repeated object state;
- mismatched reflection/light relation;
- authored geometry-state difference.

Do not solve Hush readability with a global purple outline pass.

## 9.2 Weather resilience

Use regional weather that actually belongs to the place.

Examples may include:

- Rootmere rain/channel mist;
- Saltreach fog/storm spray;
- Emberstep ash/dust;
- High Aerie wind/cloud/snow where appropriate;
- Mireglass mist/rain reflection breakup;
- Cairnfall dust/cloud cover.

Weather must yield around:

- traversable edges;
- committed enemy tells;
- tool focus/mechanism state;
- critical hazards;
- characters.

Decorative atmosphere is the first thing to simplify when it competes with gameplay truth.

## 9.3 Reduced Effects conceptual comparison

For at least two gameplay-critical scenes, show:

- full intended effect richness;
- reduced decorative/atmospheric richness;
- same semantic state still readable through body/shape/material/motion/value and retained critical effect primitive.

This is a conceptual production check.

It is **not** runtime validation of a future accessibility or scalability mode.

## 9.4 Color-independent review

At least one combat, one tool and one traversal/Hush example must survive:

- grayscale;
- saturation reduction;
- key color relationship removed or compressed.

Critical information must remain recoverable through another channel.

No claim of final color-vision accessibility acceptance is made by this board.

---

# 10. Sheet E — Failure Library / Reduction Tests

Sheet E is deliberately unattractive in places.

Its job is to document what production must reject.

Include side-by-side **FAIL / TARGET** examples for at least:

1. universal traversal paint versus honest construction/wear grammar;
2. glowing puzzle socket versus visible mechanism relation;
3. room-wide scanner outlines versus bounded Cantor focus;
4. tiny color-only enemy tell versus body/silhouette/directional tell;
5. particle-heavy boss phase versus readable body/mechanism state;
6. enemy-radar threat ring versus committed offscreen warning only;
7. global Hush post-process versus region-preserving relationship change;
8. over-fogged route versus atmosphere that preserves foreground play space;
9. every-interactable emissive pulse versus selective tool-ready confirmation;
10. cinematic-only readable route versus gameplay-camera readable composition.

Every FAIL example must state **why it fails authority**, not simply “looks bad.”

---

# 11. Regional distribution requirement

Board 05 must not prove every readability rule in Brindle alone.

Across the complete package, include representative examples from at least **six of the eight ordinary-world regions**, with the final package preferably touching all eight when it can do so without shrinking panels below useful review size.

Regional selection should demonstrate different problems:

- **Brindle:** ordinary traversal/workshop interaction baseline;
- **Cairnspire:** vertical route/civic-machine/target-background separation;
- **Rootmere:** organic-versus-authored traversal distinction and wet-weather readability;
- **Saltreach:** fog/water/signal hierarchy;
- **Emberstep:** heat/ash/industrial mechanism readability;
- **High Aerie:** vertical threat/route/wind-motion readability;
- **Mireglass:** reflection ambiguity without route dishonesty;
- **Cairnfall:** large instrument geometry/precision cues without magic-glow shorthand.

Late Hush/Null Meridian examples may be used only to verify established late-game grammar. They may not introduce a finale-only readability language.

---

# 12. Character/background separation

Board 05 must use actual locked character palette/silhouette logic when principal characters appear.

Minimum checks:

- Neris remains readable against Cairnspire blue-gray civic mass without recoloring her costume;
- Sena remains readable against Emberstep dark/heat material families without permanent rim-light gimmicks;
- Caldrin remains readable in High Aerie gray/sky values through silhouette/material hierarchy;
- any combat example preserves hands/weapons/tools/body direction strongly enough to interpret action.

Lighting/environment should solve separation before costume redesign.

---

# 13. Enemy/boss selection rules

Use existing enemies/bosses from `docs/159`.

Recommended coverage should include multiple production classes rather than five variants of one melee beast:

- E0/E1 biological pressure;
- E2 machine pressure;
- E3 group/air pressure;
- E4 Hush-pattern relationship;
- E5/E6 human-scale or human-preserved encounter where useful.

Board 05 may not infer:

- weak points;
- detachable parts;
- armor immunity;
- flight ability;
- lockable sub-parts;
- phase rules;
- kill/resolution state

from visual design alone.

Those must already exist in encounter/story/tool authority.

---

# 14. VFX inclusion rules

Board 05 is not a VFX showcase.

Every effect included must declare its current class from `docs/163` where applicable:

- `VFX-G` gameplay-critical;
- `VFX-S` state communication;
- `VFX-A` atmospheric;
- `VFX-C` bounded cinematic/authored spectacle;
- `VFX-D` decorative micro-effect.

The board must visibly prove:

- `G` survives reduced richness;
- `S` does not own semantic state;
- `A` yields to combat/traversal/interactions;
- `C` does not invent a new visual grammar;
- `D` can disappear with no gameplay loss.

Do not classify an effect based on how visually impressive it is.

---

# 15. Reference-source baskets

Board 05 may collect external references only by **production problem**.

Every source must follow `docs/155`:

- Reference;
- Question;
- Extracted principle;
- Stillring translation;
- Forbidden carryover.

Recommended source baskets:

## Basket A — natural route guidance
Study:
- path/terrain composition;
- landmark orientation;
- negative-space route framing;
- construction/wear signaling use.

Do not collect another game's exact climb paint, ledge markings, shrine symbols or route decals as direct targets.

## Basket B — physical machine readability
Study:
- visible hinges/tracks;
- pressure/load paths;
- service access;
- maintenance markings;
- readable industrial state.

Prefer real machinery/infrastructure reference where useful.

## Basket C — embodied combat telegraph
Study:
- pose anticipation;
- force direction;
- silhouette change;
- group spacing;
- projectile travel visibility.

Do not copy another game's enemy animation frames, boss weak-point language or combat HUD.

## Basket D — low-clutter critical VFX
Study:
- one dominant effect form;
- material-specific impact behavior;
- state communication with low particle density;
- threat separation under noisy weather.

## Basket E — fog/weather readability
Study:
- foreground/background separation;
- landmark reveal/concealment;
- wet/reflection breakup;
- windborne motion hierarchy.

## Basket F — accessibility/reduction communication
Study:
- non-color-only distinctions;
- reduced motion/effects hierarchy;
- shape/pattern redundancy;
- coarse directional threat communication.

References may help answer the production problem. They may not become a direct visual target.

---

# 16. Generated-image policy for Board 05

Generated studies are allowed for rapid comparison only.

Any generated gameplay-readability image must be annotated for accidental invention.

Common generation errors that must be marked noncanonical or corrected:

- arbitrary glowing ledges;
- random ropes/ladders implying traversal;
- invented enemy weapons/weak points;
- target markers that imply unapproved UI;
- colored puzzle sockets;
- over-signaled interaction glyphs;
- impossible camera angle;
- Hush glitch overlays;
- invented boss phases;
- incorrect Neris/character design;
- environment geometry that changes route legality accidentally.

Generated imagery cannot prove actual gameplay readability or human reaction timing.

---

# 17. Board 05 acceptance checklist

Board 05 source execution is acceptable only when all of the following are true.

## Traversal / world

- [ ] valid baseline traversal examples are visually distinguishable from nearby invalid lookalikes without universal highlight paint;
- [ ] rough world surfaces do not accidentally imply universal free climbing;
- [ ] mantle, ledge, ladder, swim-exit and authored tool-route examples remain subordinate to their gameplay rules;
- [ ] route guidance is demonstrated from gameplay camera through world composition;
- [ ] no visual example invents new traversal permission.

## Tools / puzzles

- [ ] world-layer causality appears before tool confirmation;
- [ ] Cantor clear/ambiguous/blocked/ordinary-scene states are represented without detective-vision spam;
- [ ] Anchor examples distinguish authored load relationships without glowing-socket keycard language;
- [ ] at least four semantic failure classes are visually demonstrated;
- [ ] puzzle readability does not depend on a matching tool icon revealing the solution.

## Combat / targeting

- [ ] at least three threat families communicate anticipation primarily through body/mechanism/silhouette/direction;
- [ ] one-MajorCommit group readability is demonstrated without a passive waiting ring;
- [ ] target lock remains visually separate from attack permission;
- [ ] offscreen warning appears only as bounded supplement to committed threat where needed;
- [ ] hard occlusion is shown as a legality boundary, not defeated by UI;
- [ ] VFX does not cover the next actionable tell.

## Hush / weather / accessibility stress

- [ ] Hush preserves regional/place recognition before wrongness;
- [ ] weather yields to critical gameplay information;
- [ ] at least two full-versus-Reduced-Effects conceptual comparisons preserve meaning;
- [ ] combat/tool/traversal critical examples survive grayscale or saturation reduction through redundant cues;
- [ ] no accessibility/runtime acceptance is falsely claimed.

## Production discipline

- [ ] all external/generated sources carry provenance and forbidden-carryover notes;
- [ ] actual locked character/enemy/environment identities are respected;
- [ ] failure examples explain the violated authority;
- [ ] no exact gameplay timing, camera, contrast, exposure, UI or performance values are invented;
- [ ] the final artifact is labeled according to `docs/155` and owner-review status is explicit.

---

# 18. Decision rights

## LOCKED — board execution must preserve

- honest-world affordance principle;
- no universal free climbing implication;
- no universal traversal paint/highlight requirement;
- current locomotion semantics;
- current camera/target-lock relationship;
- current combat/encounter threat/readability semantics;
- one-MajorCommit baseline and existing approved pressure rules;
- bounded offscreen committed-threat warning role;
- world-first / tool-ready / explanation readability layers;
- no scan-spam / glowing-keycard tool language;
- Hush recognition before wrongness;
- critical VFX/reduced-effects semantic preservation;
- color-independent redundancy;
- VFX does not own gameplay state.

## STUDIO CHOICE WITHIN BOUNDS

- exact Board 05 drawing/render medium;
- which approved representative regions/locations best demonstrate each rule;
- exact reference selection under `docs/155`;
- sheet layout and annotation design;
- local material/value tuning that preserves regional authority;
- exact noncanonical failure-study construction;
- exact visual form of provisional UI/VFX examples **only as studies**, pending their own production authority.

## RUNTIME / HUMAN-PLAY EVIDENCE

Still open until representative implementation exists:

- exact affordance-recognition distances;
- exact mantle/ledge/ladder visual metrics;
- final camera-space readability thresholds;
- actual attack telegraph timing/reaction sufficiency;
- actual offscreen warning timing/size/contrast;
- final combat VFX density/overdraw;
- final tool candidate forgiveness/readability;
- final weather/Hush overlap readability;
- final accessibility settings/effect reductions;
- color-vision/photosensitivity/motion-sensitivity validation;
- final HUD/UI presentation;
- target-platform performance;
- human-play proof that players infer the intended rules correctly.

## OWNER REVIEW REQUIRED

Return to owner only when a proposed visual solution materially changes locked product/art/gameplay identity, including:

- adopting universal climbing paint/highlight language;
- changing the honest-world principle;
- redefining a region or principal visual identity;
- turning Cantor into detective vision or Anchor into socket-key interaction;
- changing target-lock/combat threat philosophy through presentation;
- adopting spectacle-heavy combat/VFX language;
- adopting a global Hush readability effect that overrides regional identity;
- creating a materially new UI/iconography philosophy before UI authority exists.

Ordinary layout, source selection and execution refinement within the written bounds do not require owner approval.

---

# 19. What this brief does not prove

Completion of this document does **not** mean:

- traversal art has been built;
- players can recognize affordances in motion;
- combat attacks are fair in real time;
- tool/puzzle interactions are discoverable in play;
- Hush/weather overlap has been validated;
- Reduced Effects exists in runtime;
- accessibility is certified;
- target-lock camera works;
- any UI/VFX implementation exists;
- any performance budget has been met;
- any UE5.8 feature has been selected.

This is written production authority for what Board 05 must prove later.

---

# 20. Next art-workstream step

After Board 05 source-brief completion, the next bounded written art-production step is:

> **Board 06 — Representative Benchmark Scene Source Brief**

Board 06 may synthesize the earlier board contracts into one representative scene, but it must not be treated as runtime/performance proof or as permission to bypass unresolved world-scale/technical dependencies.
