# 01 — Game Vision

## High concept

A young bellwright crosses a fantasy world whose ancient resonance network is failing. The ordinary world is slowly separating from a soundless echo-reality called **the Hush**. By restoring regional Waybells, mastering the multi-purpose **Cantor Key**, and confronting the movement that wants to freeze existence in a perfect unchanging moment, the player learns that the world was never meant to be held together by one sacred machine.

## Camera and movement

Design-lineage reasoning lives in `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md`.

The detailed, implementation-facing Gate 1 locomotion contract lives in:

- `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`

Issue #1 tracks final locomotion owner acceptance. Camera-specific authority remains Issue #2.

The governing idea is:

> **Simple intention, capable character, honest world.**

Stillring studies the evolution of authored 3D Zelda controls rather than freezing the design at Ocarina of Time's 1998 hardware constraints. It preserves the deeper lessons—clear intention, readable target-relative combat movement, trustworthy world affordances, and authored traversal progression—while inventing its own control expression.

Vision-level movement commitments:
- exploration movement is camera-relative and preserves a useful analog range from careful positioning through ordinary run;
- Neris has an always-available modest deliberate jump and an unlimited ordinary-travel Sprint with no stamina/resource tax;
- Sprint is separate from combat evade, supports Hold/Toggle, remains highly steerable, and carries believable extra momentum only where it helps physical weight;
- ordinary stairs, small steps, floor lips, and minor terrain should disappear beneath movement rather than create accidental platforming;
- low-obstacle mantle, reachable-ledge catch, authored ladders, surface swimming, slope response, fall consequence, and target-lock locomotion use the explicit intent/state rules in `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`;
- Neris does **not** have universal/free climbing, baseline underwater free-diving, or a generic baseline crouch/stealth posture;
- broader traversal comes from clearly authored structures, tools, or later capabilities with a consistent visible world language;
- meaningful cliffs, height gates, submerged spaces, and route obstacles remain part of puzzle/progression geography instead of being erased by universal traversal;
- animation sells weight but does not own ordinary locomotion timing or delay acknowledgement of valid player intent;
- movement input/accessibility may change ergonomics—remapping, dead-zone tolerance, Hold/Toggle, digital precision—but does not secretly expand authored traversal eligibility;
- target lock changes movement into precise target-relative positioning without auto-orbit, auto-distance maintenance, or hidden combat autopilot;
- the world must communicate traversal affordances honestly: if something reasonably looks traversable/interactable, the expected action should work or the exception should be visibly understandable.

Exact speeds, acceleration values, angles, reach envelopes, coyote/buffer windows, fall thresholds, animation cadence, and related numeric values remain Gate 1 tuning unless `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` explicitly states otherwise. Tuning may refine feel; it may not silently change the locked movement grammar.

Human target for Gate 1:

> **Within roughly five minutes, ordinary movement should stop being something the player consciously fights.**

The canonical human acceptance course/script and hard-fail conditions are defined in `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`. Human feel is authoritative even when automated checks pass.

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
- locomotion-facing requirements from `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`,
- combat assistance options tested later without changing canonical balance data,
- no critical information conveyed by audio alone.
