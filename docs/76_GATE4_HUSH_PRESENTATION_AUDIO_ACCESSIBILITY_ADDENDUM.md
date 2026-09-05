# 76 — Gate 4 Hush Presentation / Audio / VFX / Accessibility Contract

**Status:** LOCKED — scheduled-run owner delegation  
**Issue:** #126 — Gate 4 Hush-layer prototype design system  
**Decision:** #7 — presentation/audio/VFX/accessibility contract

## Decision

The Hush must read as an **authored alternate expression of the same place**, not a full-screen horror filter. Its identity comes primarily from world-space changes—presence/absence, incomplete geometry, altered material/lighting relationships, residue, motion, sound behavior, and authored environmental evidence—while post-process, particles, distortion, audio processing, and haptics remain supporting layers.

Core philosophy:

> **The Hush should change what the place means before it changes what the screen looks like.**

A player with reduced visual effects enabled must still be able to tell which layer is active, what geometry is physical, what changed, what threatens them, and what can be interacted with.

## Canon presentation boundary

Narrative authority defines the Hush as an echo-layer containing:
- discarded possibilities;
- emotional residue;
- incomplete states;
- impressions of things no longer present.

It is:
- coupled to ordinary Orra;
- not an afterlife;
- not inherently evil;
- not simply “the spooky version” of every room;
- not merely a rendering filter.

Presentation therefore needs to express **relationship, absence, incompleteness, and residue** rather than defaulting to generic corruption imagery.

## Presentation hierarchy

Hush readability follows this priority order:

1. **World-space authored expression** — geometry, object presence, route state, silhouettes, material state, local lighting relationships, residues, environmental motion.
2. **Semantic/local cues** — localized visual/audio behavior attached to meaningful entities/areas.
3. **Layer ambience** — broader lighting, atmospheric, soundscape, and mix changes.
4. **Screen-space post-process** — restrained support only.
5. **Transition flourish** — brief optional accent, never required for understanding.

If the Hush stops being understandable when post-process is disabled, the presentation design has failed.

## Visual identity pillars

### Correspondence
The player should recognize the same authored place across layers.

Preserve enough stable landmarks, scale, orientation, and composition that the seam feels like reality changing in place rather than loading a disconnected level.

### Absence / incompleteness
Missing or incomplete structures should leave readable evidence rather than visual noise. Examples include:
- interrupted architectural rhythm;
- partial surfaces or exposed underlying relationships;
- negative space where a familiar mass should be;
- incomplete maintenance/mechanical relationships;
- residue indicating something was once or might have been present.

### Residue
Residue is local and authored, not blanket particle wallpaper. It may express memory, emotional pressure, discarded relation, or instability through restrained motion/material/audio behavior.

### Functional clarity
Active walkable/blocking geometry, enemies, interactables, Cantor/Anchor affordances, and dangerous space must remain visually separable from decorative residue.

## Not a generic desaturation mode

Global color grading may support the Hush, but the final visual identity cannot be reduced to:
- lower saturation;
- blue/green tint;
- crushed blacks;
- vignette;
- chromatic aberration;
- film grain/noise;
- blur;
- “spooky fog.”

These can be restrained ingredients if they survive readability/accessibility/performance testing, but none is the semantic layer cue.

Epic's current color-grading tools operate in scene-referred linear space and are more display-consistent than relying on a baked LUT alone. That is useful implementation guidance, not art-direction authority.

## Post-process contract

Post-process is subordinate to gameplay readability.

Allowed candidate uses:
- modest scene-referred color/contrast shift;
- very restrained local/global exposure relation adjustment;
- bounded material-space or screen-space treatment supporting residue/incompleteness;
- subtle distortion around explicitly authored local seam/residue events where it does not affect aiming/navigation.

Rejected defaults:
- persistent heavy chromatic aberration;
- persistent depth/scene blur;
- strong fisheye/lens warp;
- strong vignette obscuring peripheral threats;
- noisy animated grain required to identify Hush state;
- full-screen pulse on every semantic event;
- screen-space effect that makes collision boundaries hard to judge.

Post-process passes have real GPU cost; each added pass must justify itself on target hardware rather than accumulating because the engine supports it.

## Transition visual contract

Decision #2 owns control/commit. Presentation follows it.

A normal seam transition should:
- begin immediately enough to confirm accepted input;
- preserve player camera control;
- communicate the commit without hiding footing/threats;
- visually converge quickly to the destination expression;
- avoid a black-frame cut, whiteout, or long opaque overlay;
- avoid camera shake/head movement as a required transition signal;
- avoid a full-screen flash/strobe.

The seam may show source and destination expression overlap/morph briefly as presentation, but Decision #3 remains physical authority: decorative/source imagery cannot become physical merely because visible.

Exact timings/intensity remain prototype tuning.

## Photosensitivity baseline

The design goal is to avoid hazardous flashing by default rather than rely on a warning or an accessibility toggle.

Gate 4 Hush effects must avoid:
- repeated high-contrast full-screen flashes;
- rapid luminance flashing around the seam;
- repeated saturated-red flash treatment;
- large high-contrast alternating spatial patterns;
- prolonged rhythmic pulsing necessary to understand a puzzle or hazard.

Current Xbox Accessibility Guideline 118 identifies frequent flashes around greater than three per second and sufficiently large/high-contrast flashing regions as risk conditions, and recommends eliminating/reducing such content. Stillring should design below that problem rather than tune against a maximum threshold.

All representative transition/puzzle/combat captures require automated/manual photosensitivity review before production approval.

## Reduced Hush Effects setting

Provide a player-facing **Reduced Hush Effects** setting (exact menu naming may evolve) that preserves game rules and semantic information while reducing sensory load.

Reduced mode should substantially reduce/disable as applicable:
- screen-space distortion;
- animated grain/noise;
- peripheral pulsing;
- nonessential particles;
- nonessential residue motion amplitude/rate;
- strong color/contrast excursions;
- transition overlay intensity;
- optional Hush-specific camera shake, if any later exists;
- nonessential haptic intensity.

Reduced mode must **not**:
- change collision;
- change puzzle state/eligibility;
- change targetability;
- change enemy AI/combat timing;
- reveal/hide solutions;
- make physical active-layer geometry ambiguous;
- eliminate the player's ability to identify Waking vs Hush.

Where useful, finer-grained options may exist later (distortion, shake, haptics, motion, flashing), but one practical reduced-effects preset is required.

## Color and contrast accessibility

No critical Hush gameplay distinction may rely only on hue.

Layer/affordance/threat distinctions should combine appropriate channels such as:
- shape/silhouette;
- material/texture pattern;
- spatial presence/absence;
- motion behavior;
- icon/text where UI is appropriate;
- local audio;
- optional haptics.

Microsoft accessibility guidance explicitly recommends alternatives to color-only critical information. Full-screen palette filters are not a substitute for designing semantic cues with multiple affordances.

Critical UI/reticles/prompts must maintain usable contrast over both Waking and Hush backgrounds.

## Audio identity

The Hush has an authored **sound relationship** to the same place, not simply “more reverb.”

Audio may express:
- changed environmental presence/absence;
- altered decay or resonance of familiar spaces;
- missing sources leaving intentional negative space;
- local residue/impression sounds tied to semantic entities;
- shifted spectral emphasis on ambience;
- changed distance/room response where geometry differs;
- selective paired motifs that make correspondence recognizable.

Unreal's Sound Classes, Audio Modulation, submix routing, filters, and reverb are implementation tools capable of layer-responsive mixes. They do not own semantic Hush state.

## Audio gameplay hierarchy

Hush ambience/mix processing must not bury gameplay-critical audio.

Priority remains:
1. immediate combat/damage/threat information;
2. interaction/tool feedback;
3. required puzzle/mechanism evidence;
4. dialogue/important authored voice;
5. layer ambience/residue texture.

A Hush mix may alter ambience heavily while keeping critical SFX intelligible.

Do not solve Hush identity by applying a master low-pass/reverb effect that makes footsteps, attack tells, Cantor/Anchor feedback, or dialogue unreadable.

## Multimodal critical cues

Critical information should be available through more than one sensory path when reasonable.

Examples:
- seam accepted/rejected: local visual + audio, optionally haptic;
- target becomes unavailable after shift: normal lock visual + audio cue;
- critical cross-layer mechanism changed: world-space change plus mechanism sound/Cantor-readable state;
- dangerous active geometry/attack: ordinary combat visual/audio authority remains intact.

Haptics are supplementary because players may disable them or use devices without them.

## Haptics

Hush/seam haptics may add tactile confirmation but may not be the only confirmation channel.

Rules:
- no mandatory prolonged rumble merely because Hush is active;
- seam pulse should be brief/bounded if used;
- combat haptics remain Gate 2 authority and should not become confused with layer ambience;
- global haptic reduction/off remains respected;
- Reduced Hush Effects reduces/removes nonessential layer haptics.

## Dialogue / captions / environmental audio

If Hush-specific voices, residues, whispers, radio-like sources, or narrative audio carry meaningful content:
- spoken content follows project subtitle/caption requirements;
- source/speaker identity/direction should be communicated where relevant;
- meaningful non-speech audio cues need accessible supplemental representation where gameplay would otherwise depend on hearing alone;
- ambience-only flavor need not become intrusive HUD spam.

The Hush is not permission to make important information deliberately unintelligible.

## Motion / camera comfort

Decision #2 and Gate 1 camera authority remain controlling.

Hush presentation may not add:
- forced camera sway;
- head bob;
- automatic orbit;
- persistent horizon roll;
- arbitrary FOV oscillation;
- camera jitter tied to ambience;
- screen-space motion that makes player camera input hard to parse.

Microsoft XAG 117 specifically recommends player control over nonessential camera/screen movement. Stillring's stronger default is to avoid such Hush camera motion unless a later concrete need earns it.

## UI treatment

The HUD should not transform into a second visual language so aggressively that controls/status become unfamiliar.

Allowed:
- restrained layer-state indicator if testing proves the world alone is insufficient in edge cases;
- local semantic tool/interaction feedback already owned by systems;
- optional accessibility/status text.

Avoid:
- permanently tinted entire HUD;
- animated/glitching text required to read status;
- hiding normal health/target/interaction information for atmosphere;
- using a Hush-specific font distortion that reduces legibility.

## Performance/scalability

Hush identity cannot depend on effects that collapse at reasonable scalability levels.

Prototype evidence must measure:
- post-process GPU cost;
- Niagara particle cost/overdraw;
- transparency/distortion cost;
- lighting/exposure cost;
- audio DSP/submix cost;
- memory/residency cost of paired expressions;
- transition hitching.

Scalability reductions should remove decoration before semantic world cues.

Niagara, post-process, and audio systems offer many flexible layers, but capability is not permission to make the Hush expensive by default.

## Presentation provenance

Meaningful Hush presentation values exposed for tuning should have semantic names and provenance through the System IDE rather than raw CVars only.

Examples:
- transition visual intensity;
- residue particle density;
- local distortion intensity;
- Hush ambience mix amount;
- optional layer contrast shift;
- nonessential haptic scale;
- Reduced Effects multipliers.

Exact numeric values remain implementation/human-play tuning.

## Hush / World-Layer IDE requirements created by Decision #7

### Inspect
Expose:
- active semantic layer separately from presentation state;
- active presentation profile/region overrides;
- transition presentation phase/intensity;
- post-process contributions and their semantic owner;
- Hush-specific Niagara systems/importance class;
- current ambience/submix/modulation state;
- gameplay-critical audio ducking/priority state;
- haptic event/category;
- Reduced Hush Effects and other relevant accessibility settings;
- current scalability quality;
- semantic cues suppressed by a setting, if any (should validate as error for critical cues).

### Author/Tune
Allow reviewed session tuning of:
- non-semantic visual intensity ranges;
- transition blend/intensity;
- residue density/motion;
- ambience/modulation mix;
- optional haptic scale;
- reduced-effects values.

Tuning may not change semantic layer, collision, puzzle truth, targetability, or save state.

### Exercise
Fixtures:
- ordinary Waking↔Hush seam in bright/dark/interior/exterior scenes;
- combat during seam;
- locked target during seam;
- Cantor/Anchor interaction in Hush;
- geometry appearing/disappearing across seam;
- important cross-layer puzzle state change;
- dialogue/residue audio;
- Reduced Hush Effects;
- haptics off;
- color-vision simulation/contrast review;
- lowest approved scalability profile;
- repeated seam transitions/photosensitivity capture.

### Validate
Catch:
- Hush identity disappearing when post-process is off/reduced;
- critical cue conveyed only by color;
- critical cue conveyed only by non-captioned/non-supplemented audio;
- inactive decorative geometry visually indistinguishable from active blocking geometry;
- transition effect obscuring player footing/attack tells;
- Hush ambience masking combat/tool/dialogue signals;
- forbidden camera/FOV motion caused by presentation;
- photosensitivity-risk effect profile;
- Reduced Effects changing gameplay state;
- low scalability removing required semantic cues;
- post-process/audio state disagreeing with semantic layer after transition completion.

### Capture
A presentation evidence capture records:
semantic layer → authored expression/profile → visual/audio/haptic contributions → accessibility/scalability settings → transition frame sequence → gameplay-cue readability checks → performance metrics → validation result.

## Representative test matrix

At minimum:
- Waking/Hush side-by-side same landmark recognition;
- post-process disabled entirely;
- Reduced Hush Effects;
- color-vision-deficiency simulations;
- HDR and SDR display review;
- bright exterior / dark interior / fog / cramped room;
- moving combatants/projectiles during seam;
- low ceiling/camera compression during seam;
- critical layer-specific route;
- puzzle state only one layer expresses physically;
- dialogue and combat competing with Hush ambience;
- rapid repeated player seam requests at legal cadence;
- low/high frame rate;
- lowest approved VFX scalability;
- performance capture on target-class hardware;
- photosensitivity analysis of transition and high-intensity Hush encounters.

## Research basis

Primary current technical sources verified:
- Epic Games, **Post Process Materials in Unreal Engine 5.8** — pass/blending capabilities and explicit rendering cost considerations.
- Epic Games, **Color Grading and the Filmic Tonemapper**, UE5.8 — scene-referred linear color correction/HDR consistency.
- Epic Games, **Audio Engine Overview / Audio Mixer / Sound Classes / Audio Modulation**, UE5.8 — semantic sound grouping, modulation, routing, submix/DSP capabilities.
- Epic Games, **Niagara Overview**, UE5.8 — parameterized effect systems; implementation capability only.
- Microsoft, **Xbox Accessibility Guideline 102/103/117/118** (current 2026 guidance) — contrast, multimodal/color alternatives, motion controls, photosensitivity.
- `docs/02_STORY_BIBLE.md` — canonical Hush identity.
- Gate 1 camera, Gate 2 combat, Gate 3 tool/puzzle, and Gate 4 Decisions #1–#6.

## Locked statement

> **The Hush is a different expression of the world, not a filter over the screen. World-space meaning survives reduced effects; atmosphere may intensify it, never replace it.**

## Next decision

**Gate 4 Decision #8 — Hush / World-Layer System IDE inspect/force/reset/validate/capture contract.**
