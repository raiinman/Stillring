# 07 — Initial Backlog

These are the first issues to create after the repository exists on GitHub. Do not skip directly to world-content production.

## P0 — Pre-production closure

### Issue 1 — Lock player locomotion specification
**Outcome:** Written movement behavior for walk/run/turn/acceleration/slopes/steps/ledges.

Acceptance:
- controller axes defined,
- camera-relative movement defined,
- target-lock movement differences defined,
- accessibility considerations recorded.

### Issue 2 — Lock camera specification
**Outcome:** Camera behavior matrix for exploration, lock-on combat, cramped rooms, vertical spaces, and bosses.

### Issue 3 — Define combat frame/state model
**Outcome:** State diagram for attacks, guard, evade, hit reactions, interrupts, recovery, invulnerability if any.

### Issue 4 — Define persistent world-state schema
**Outcome:** Stable IDs and save categories proven on paper before content depends on them.

## P1 — Gate 1 prototype

### Issue 5 — Bootstrap Godot 4.7.2 project
- project opens cleanly,
- input map added,
- base test scene,
- headless parse/check command documented.

### Issue 6 — Third-person locomotion prototype
- analog movement,
- camera-relative steering,
- slopes/stairs,
- grounded transitions,
- debug values exposed.

### Issue 7 — Exploration camera prototype
- orbit,
- recenter,
- collision handling,
- sensitivity/inversion options,
- no wall clipping in test room.

### Issue 8 — Target-lock prototype
- acquire target,
- drop target,
- cycle targets,
- lock-on locomotion,
- clear visual indicator using original UI language.

## P2 — Gate 2 combat prototype

### Issue 9 — Damage/hitbox foundation
### Issue 10 — Player light/heavy attacks
### Issue 11 — Guard + evade
### Issue 12 — Enemy melee archetype
### Issue 13 — Enemy ranged archetype
### Issue 14 — Enemy armor/guard archetype
### Issue 15 — Death/retry loop

## P3 — Gate 3 tools

### Issue 16 — Cantor Key resonance laboratory
### Issue 17 — Anchor Line traversal/puzzle/combat prototype

## P4 — Gate 4 Hush

### Issue 18 — Persistent paired-layer test scene
### Issue 19 — Seam transition prototype
### Issue 20 — Save/load across Waking/Hush state

## P5 — Vertical slice

Create separate issues for:
- Brindle slice graybox,
- Rootmere trail graybox,
- Root Cathedral graybox,
- Mossjaw miniboss,
- Mawhart boss,
- NPC/dialogue system,
- cinematic sequencer,
- representative environment kit,
- representative character/enemy kit,
- audio identity pass,
- options/accessibility baseline,
- vertical-slice external playtest,
- vertical-slice production-cost review.

## Backlog rule

If an agent discovers work outside the current issue, record a new backlog item rather than silently expanding the active implementation.
