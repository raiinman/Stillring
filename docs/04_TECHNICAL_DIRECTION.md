# 04 — Technical Direction

## Engine

**Godot 4.7.2 stable** for the initial production baseline.

Do not move to preview/dev engine builds during production unless a specific blocker justifies it and migration is tested on a branch.

## Scripting

Start with **GDScript** unless profiling or integration demonstrates a concrete reason for C# or native code.

Reasons:
- fast iteration,
- compact agent-readable diffs,
- excellent engine integration,
- lower build/toolchain friction for a small team.

## Project organization

Godot is scene-oriented, so organize primarily by gameplay domain/feature rather than one giant global `textures/`, `scripts/`, `models/` dump.

Suggested `game/` structure:

```text
game/
  project.godot
  core/
    app/
    save/
    input/
    audio/
    debug/
  player/
  combat/
  tools/
    cantor_key/
    anchor_line/
    glasslung/
    temper_gauntlet/
    vane_cloak/
    mirror_nail/
  enemies/
  ui/
  narrative/
    dialogue/
    cutscenes/
    quests/
  world/
    brindle/
    cairnspire/
    rootmere/
    saltreach/
    emberstep/
    high_aerie/
    mireglass/
    cairnfall/
    hush/
    null_meridian/
  shared/
    materials/
    shaders/
    props/
    vfx/
    audio/
  tests/
```

## Scene identity

Any persistent/interactable world object that matters to save data needs a stable authored ID.

Never key important save state only by:
- node path,
- scene instance order,
- transient runtime instance ID.

Examples of persistent IDs:
- `rootmere.cathedral.gate_03`
- `saltreach.foundry.chest_pressure_room`
- `cairnspire.npc.tessa.midgame`

## Save model

Save semantic state, not entire scene trees.

Categories:
- player state,
- inventory/tools,
- quest flags,
- world facts,
- defeated bosses,
- opened permanent shortcuts,
- collected unique items,
- regional catastrophe state,
- current Waking/Hush state only where reload-safe.

Version the save schema from the beginning.

Provide migrations for released save versions.

## Waking/Hush architecture

Do not maintain two completely independent copies of the whole game if avoidable.

Preferred model:
- shared semantic entity IDs,
- layer-aware presentation/geometry components,
- explicit state overrides,
- authored seam transitions,
- one authoritative quest/world-state service.

Prototype multiple approaches before locking it.

## Combat architecture

Keep responsibilities separable:
- target selection,
- locomotion,
- attack state,
- hit detection,
- hurtbox/damage receiver,
- health/posture if used,
- enemy decision logic,
- animation presentation,
- audio/VFX feedback.

Avoid one monolithic `Player.gd` that owns the entire game.

## Data-driven content

Use Resources or another transparent data representation for:
- enemy definitions,
- damage values,
- tool tuning,
- item metadata,
- dialogue references,
- quest definitions where appropriate.

Do not move behavior that needs code into giant untyped dictionaries merely to call it “data driven.”

## Input

Use named actions, never hard-coded key assumptions.

Controller is primary design target.
Keyboard/mouse remains first-class.

## Rendering target

Prototype two modes:

1. low internal resolution with nearest/integer-aware scaling where practical;
2. standard modern output using deliberately low-detail assets and retro post-processing.

Pick the one that preserves the style without harming UI readability.

## Performance

Set budgets during vertical slice, including:
- frame-time target,
- visible triangles/draw calls as practical monitoring metrics,
- particle limits,
- dynamic light limits,
- shader complexity,
- memory growth during region transitions,
- Hush transition stall budget.

Do not wait for beta to discover that the dual-world system doubles every expensive scene.

## Git / LFS

Track source code and text resources in normal Git.

Use Git LFS for large binary content such as:
- `.blend`,
- large `.glb/.gltf` binaries,
- high-resolution source textures,
- `.wav/.flac`,
- large cinematic source files.

Do not commit generated Godot cache data.

## Automated validation

At minimum, create scripts/CI checks for:
- project parses/opens headlessly,
- required data IDs are unique,
- broken resource paths,
- dialogue IDs referenced by quests exist,
- save schema test fixture loads,
- no forbidden oversized non-LFS files,
- no accidentally committed `.godot/` cache.

## Debug tooling

Build debug tools early:
- teleport to region,
- set quest state,
- grant tool,
- toggle Waking/Hush,
- spawn enemy,
- kill boss/reset boss,
- inspect persistent ID,
- save/load test slot,
- show performance counters.

A content-heavy adventure becomes miserable to test without them.
