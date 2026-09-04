# Project Stillring

**Working title:** Project Stillring  
**Genre:** Third-person fantasy action-adventure  
**Engine:** Godot 4.7.2 stable  
**Target feel:** A late-1990s 3D adventure remembered through modern eyes: readable low-poly forms, deliberate fog, compact textures, strong silhouettes, tactile lock-on combat, puzzle-heavy dungeons, memorable towns, and a complete authored story.

Project Stillring is an **original IP**. It may study the design principles of classic 3D action-adventure games, but it must not reproduce Nintendo characters, story, maps, music, dialogue, item designs, textures, code, ROM data, trademarks, or other protected expression.

## What we are making

A 20–30 hour single-player adventure set in **Orra**, a world held together by a network of ancient civic bells. When the central bell is silenced, reality begins separating into the ordinary world and a soundless echo-layer called **the Hush**. The player, **Neris Vale**, is a young bellwright who survives the first catastrophe and becomes able to cross between those layers.

The game is built around five pillars:

1. **Explore a coherent world** — towns, roads, wilderness, ruins, shortcuts, secrets.
2. **Read and master enemies** — lock-on melee combat, defense, spacing, counters, tools.
3. **Solve physical spaces** — dungeons are machines, not hallways full of filler.
4. **Gain verbs, not stat clutter** — every major tool changes combat, traversal, or puzzle language.
5. **Finish the story** — every region, dungeon, ally, and mechanic serves a complete beginning-to-end narrative.

## Repository map

- `CLAUDE.md` — operating instructions for Claude/Codex-style coding agents.
- `ROADMAP.md` — milestone gates from concept to release.
- `docs/00_PROJECT_CHARTER.md` — scope and non-negotiables.
- `docs/01_GAME_VISION.md` — gameplay, visual, camera, combat, progression, accessibility.
- `docs/02_STORY_BIBLE.md` — complete story from opening scene through ending and post-credits.
- `docs/03_PRODUCTION_WORKFLOW.md` — actual game-development workflow and definition-of-done gates.
- `docs/04_TECHNICAL_DIRECTION.md` — Godot architecture, folders, save/state, testing, performance.
- `docs/05_IP_GUARDRAILS.md` — clean-room/IP rules.
- `docs/06_CONTENT_MATRIX.md` — regions, dungeons, bosses, tools, narrative purpose.
- `docs/07_INITIAL_BACKLOG.md` — first GitHub issues in dependency order.
- `docs/08_RESEARCH_NOTES.md` — production research and source links.
- `game/` — Godot project root.

## Production rule

**Do not build the whole game before proving one vertical slice.**

The first playable target is a 20–30 minute slice containing:

- one village exterior,
- one wilderness route,
- one compact dungeon,
- three enemy archetypes,
- one miniboss,
- one boss,
- lock-on combat,
- one traversal/tool unlock,
- one Hush-layer puzzle,
- dialogue/cutscene support,
- save/load,
- N64-inspired final-ish art direction,
- music/SFX placeholders,
- controller support.

If that slice is not fun, readable, stable, and fast to produce, full production does not begin.

## Current status

**Phase 0 — Project charter / pre-production.**

No production-scale content should be created until the story bible, game pillars, technical prototype, and vertical-slice acceptance criteria are accepted.
