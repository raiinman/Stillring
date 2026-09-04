# 01 — Game Vision

## High concept

A young bellwright crosses a fantasy world whose ancient resonance network is failing. The ordinary world is slowly separating from a soundless echo-reality called **the Hush**. By restoring regional Waybells, mastering the multi-purpose **Cantor Key**, and confronting the movement that wants to freeze existence in a perfect unchanging moment, the player learns that the world was never meant to be held together by one sacred machine.

## Camera and movement

Detailed lineage and Gate 1 control principles live in `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md`.

The governing idea is:

> **Simple intention, capable character, honest world.**

Stillring studies the full evolution of authored 3D Zelda controls rather than freezing the design at Ocarina of Time's 1998 hardware constraints.

Locked movement/camera principles:
- Third-person trailing exploration camera with modern free right-stick / mouse camera control.
- Recenter is a convenience, not a substitute for camera ownership.
- Player retains steering authority during ordinary movement.
- Lock-on changes camera and movement grammar into deliberate combat framing.
- Camera collision must never shove through walls or hide the player for long.
- Controller movement preserves useful analog range for careful positioning through confident full-speed travel.
- Neris has a sustained sprint available from the beginning for faster ground travel; sprint is separate from the eventual combat evade.
- Ordinary sprint has **no stamina or other resource cost** and may be sustained indefinitely during normal traversal.
- Sprint supports **Hold** and **Toggle** input modes; Hold is the default and Toggle is an accessibility/control preference.
- A future combat or special-traversal resource may not be silently reused to throttle ordinary sprint.
- Sprint must not replace useful analog walk/run control or become a second dodge.
- Full sprint remains highly steerable; ordinary curves/corners stay responsive, while hard reversals briefly shed momentum instead of snapping instantly at full speed or forcing a large turning circle.
- Jumping from sprint preserves existing horizontal sprint momentum; jumping does not add bonus speed, and landing continues/returns to sprint when sprint is still requested and no higher-priority movement state overrides it.
- Acquiring target lock while sprinting ends the exploration sprint state, but does **not** instantly erase velocity: Neris transitions through a short natural deceleration/pivot into precise target-relative combat locomotion.
- Full exploration sprint is unavailable while target-locked.
- Stairs, small steps, minor floor lips, and ordinary uneven ground are handled automatically rather than becoming accidental platforming challenges.
- Neris has an always-available, modest, deliberate jump for intentional vertical movement and small gaps.
- Obviously low obstacles use a small authored mantle/scramble response rather than forcing awkward collision fighting.
- Major cliffs and meaningful height gates remain authored traversal problems solved by routes, tools, or later capabilities rather than by making Neris a universal parkour character.
- The world must communicate traversal affordances honestly: if something reasonably looks traversable/interactable, the expected action should work or the exception should be visibly understandable.
- Ledges, ladders, narrow beams, swimming, and broader climbing remain intentionally designed capabilities rather than an assumed universal parkour/climb-everything system.
- Authored traversal progression remains central: later tools/capabilities should make remembered spaces newly understandable.
- Animation transitions are part of responsiveness; physical weight must not mean delayed acknowledgement of player intent.

The first locomotion specification must resolve remaining physical-capability questions one at a time with owner review rather than inheriting Unreal template defaults.

Human target for Gate 1:

> **Within roughly five minutes, ordinary movement should stop being something the player consciously fights.**

## Combat language

Core actions:
- move,
- lock/unlock target,
- light attack,
- committed/heavy attack,
- guard,
- evade,
- context action,
- tool action,
- item/quick-use.

Combat principles:
- Target lock is a tactical mode, not mandatory for every enemy.
- Defensive play must be viable.
- Attack animations have readable commitment.
- Enemies telegraph through silhouette + motion + sound.
- Contact feedback matters: hitstop, sound, reaction, sparks/debris, controller feedback where available.
- Bosses test learned mechanics rather than merely having huge health bars.
- Multi-enemy aggression must respect what the player and camera can reasonably read; encounter design participates in lock-on clarity.

## The Cantor Key

The protagonist's signature device is a fold-out bellwright's instrument with resonant prongs, a sliding weight, and a small striking hammer.

It does **not** function like an ocarina or flute.

Core uses:
- sample environmental tones,
- retune mechanisms,
- reveal resonant seams,
- trigger certain civic machines,
- disrupt Hush entities,
- synchronize paired objects,
- eventually shift the player between Orra and the Hush at valid seams.

The player learns short **resonance patterns**, represented visually as relationships between tones rather than copied musical melodies.

## World structure

The world is interconnected but not fully open from the start.

### Hub: Cairnspire
A vertical capital built around the dormant central bell tower.

### Region 1: Rootmere
Wet woodland, root bridges, old bell-oaks, fungal lanterns.

### Region 2: Saltreach
Wind-beaten fishing coast, tidal caves, drowned industrial ruins.

### Region 3: Emberstep
Black-glass badlands, geothermal vents, kiln-cities, ash caravans.

### Region 4: High Aerie
Mountain terraces, rope lifts, wind organs, cliff monasteries.

### Region 5: Mireglass
Reflective marsh, reed palaces, mirrored pools, deceptive horizons.

### Region 6: Cairnfall
Ancient astronomical works sunk into a broken plateau.

After the midpoint catastrophe, every region gains Hush-state changes, altered NPCs, shortcuts, optional secrets, and at least one consequence quest.

## Visual direction

The target is **N64-era readability filtered through modern production discipline**:

- strong low-poly silhouettes,
- small deliberate texture sets,
- painted/vertex-color shading where useful,
- limited material complexity,
- expressive baked or simple dynamic lighting,
- fog used compositionally,
- restrained particles,
- clear color scripting by region,
- chunky readable props,
- avoid modern photoreal PBR clutter.

Internal rendering may target a low base resolution (for example 320×240 or 640×480) with carefully selected scaling. This is a prototype decision, not a dogma; UI readability and accessibility win over nostalgia.

## UI

- Minimal HUD during exploration.
- Health/resources readable at a glance.
- Tool state shown only when relevant.
- Map favors landmarks and routes over icon spam.
- Quest log records commitments and clues, not GPS instructions.
- Dialogue is fast to advance and can be reviewed in a recent-text log.

## Audio

Sound is mechanical and narrative.

- Bells, resonances, room tone, and silence are gameplay communication.
- Hush transitions should dramatically alter ambience rather than simply applying a visual filter.
- Music must be original.
- No imitation of recognizable melodies from existing franchises.

## Accessibility baseline

- remappable controls,
- subtitle size/background options,
- color-independent puzzle cues,
- camera sensitivity and inversion,
- camera shake slider,
- hold/toggle options where feasible,
- combat assistance options tested later without changing canonical balance data,
- no critical information conveyed by audio alone.
