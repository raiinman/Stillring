# Project Stillring

**Working title:** Project Stillring  
**Genre:** Third-person fantasy action-adventure  
**Engine:** Unreal Engine 5.8  
**Primary implementation:** C++ core with thin Blueprint presentation  
**Primary implementation agent:** Claude  
**Target feel:** A late-1990s 3D adventure remembered through modern eyes: readable low-poly forms, deliberate fog, compact textures, strong silhouettes, tactile lock-on combat, puzzle-heavy dungeons, memorable towns, and a complete authored story.

Project Stillring is an **original IP**. It may study the design principles and evolution of classic-to-modern 3D action-adventure games, including the Zelda lineage, but it must not reproduce Nintendo characters, story, maps, music, dialogue, item designs, textures, code, ROM data, trademarks, exact control expression, or other protected expression.

## What we are making

A 20–30 hour single-player adventure set in **Orra**, a world held together by a network of ancient civic bells. When the central bell is silenced, reality begins separating into the ordinary world and a soundless echo-layer called **the Hush**. The player, **Neris Vale**, is a young bellwright who survives the first catastrophe and becomes able to cross between those layers.

The game is built around five pillars:

1. **Explore a coherent world** — towns, roads, wilderness, ruins, shortcuts, secrets.
2. **Read and master enemies** — lock-on melee combat, defense, spacing, counters, tools.
3. **Solve physical spaces** — dungeons are machines, not hallways full of filler.
4. **Gain verbs, not stat clutter** — every major tool changes combat, traversal, or puzzle language.
5. **Finish the story** — every region, dungeon, ally, and mechanic serves a complete beginning-to-end narrative.

## Repository map

- `CLAUDE.md` — authoritative operating contract for Claude.
- `ROADMAP.md` — evidence-gated milestones from concept to release.
- `docs/00_PROJECT_CHARTER.md` — scope and non-negotiables.
- `docs/01_GAME_VISION.md` — gameplay, visual, camera, combat, progression, accessibility.
- `docs/02_STORY_BIBLE.md` — canonical narrative index and authority chain.
- `docs/03_PRODUCTION_WORKFLOW.md` — actual game-development workflow, owner-review rules, conversation-to-repository capture, and definition-of-done gates.
- `docs/04_TECHNICAL_DIRECTION.md` — Unreal/C++ architecture, source-of-truth boundaries, save/state, testing, rendering, and performance.
- `docs/05_IP_GUARDRAILS.md` — clean-room/IP rules.
- `docs/06_CONTENT_MATRIX.md` — regions, dungeons, bosses, tools, narrative purpose.
- `docs/07_INITIAL_BACKLOG.md` — first implementation work in dependency order.
- `docs/08_RESEARCH_NOTES.md` — production, engine, and design-lineage research with source links.
- `docs/10_COMPLETION_MODEL.md` through `docs/14_PRESTIGE_AND_MASTERY_CONTENT.md` — completion, authored optional content, 100% route, upgrades, and mastery authority.
- `docs/15_CANON_TO_PLAY_PIPELINE.md` — source-of-truth pipeline: **CANON → PRODUCTION → IMPLEMENTATION → VERIFICATION → PLAY**.
- `docs/16_DEVELOPER_TOOLING_AND_MACHINE_QA.md` — developer console, named state presets, structured bug capture, and offline machine-assisted QA contract.
- `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md` — player-control lineage/reasoning: the problems Stillring learns from Zelda without copying expression.
- `docs/18_PROJECT_DECISION_REGISTER.md` — living index proving where durable project decisions are recorded so chat history is never required as authority.
- `docs/19_ASSASSINS_CREED_MOVEMENT_LINEAGE_RESEARCH.md` — secondary traversal research input; not design authority.
- `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` — final-owner-approved Gate 1 locomotion behavior, accessibility implications, tuning boundaries, and canonical human feel test.
- `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md` — shared in-game developer shell + per-system IDE/workbench contract so Stillring can be authored, tuned, inspected, validated, reset, and iterated while the game is running.
- `docs/story/` — final scene, reveal, objective, dialogue, character, regional, pacing, recurrence, and side-interaction narrative contracts.
- `game/` — Unreal project root; intentionally skeletal until Gate 1 bootstrap.

## Inspiration policy

**Ocarina of Time is a root reference, not the 2026 control ceiling.**

Stillring studies what Nintendo learned across later 3D Zelda games—free camera ownership, movement flow, route agency, readable affordances, target-lock evolution—then invents its own implementation for an authored Stillring world.

The governing player-control idea is:

> **Simple intention, capable character, honest world.**

Stillring keeps authored progression and meaningful traversal verbs rather than automatically adopting universal climb-everything traversal. If the world visually implies an action should work, gameplay should support it or clearly communicate the exception.

## Engine policy

Stillring uses Unreal because the project is now clearly a substantial authored 3D action-adventure with heavy animation, cinematics, combat, world-state, and content-production demands.

That does **not** mean accepting Unreal defaults as the design.

- C++ owns authoritative gameplay and state.
- Blueprints remain thin where practical.
- Canon remains in repository contracts, not hidden in binary assets.
- Gameplay Ability System, World Partition, Data Layers, Nanite, Lumen, MetaHuman, and PCG are opt-in tools rather than automatic dependencies.
- Rendering must serve Stillring's deliberate low-poly/retro-modern identity, not generic Unreal presentation.
- Claude and all development automation are development infrastructure only; the shipped game has no model/API dependency.

A useful shorthand is:

> **Unreal executes the game. The repository defines what the game is supposed to do.**

## Production rule

**Do not build the whole game before proving one vertical slice.**

The first playable target is a 20–30 minute slice containing:

- one village exterior;
- one wilderness route;
- one compact dungeon;
- three enemy archetypes;
- one miniboss;
- one boss;
- lock-on combat;
- one traversal/tool unlock;
- one Hush-layer puzzle;
- dialogue/cutscene support;
- save/load;
- Stillring's representative low-poly final-ish art direction;
- music/SFX placeholders;
- controller support;
- state presets/debug entry points sufficient to reproduce important slice states;
- at least one automated representative smoke route.

If that slice is not fun, readable, stable, testable, and fast to produce, full production does not begin.

A second production rule is equally binding:

> **Build the system and its in-game IDE together.**

Major gameplay/content systems that require repeated tuning, authoring, state inspection, reproduction, or validation must receive a dedicated development-only System IDE workbench registered into the shared in-game developer shell. IDE debt counts as feature debt; it is not deferred debug polish. Exact authority: `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md` and Issue #58.

## How the game gets built

Stillring is specified from the finished-game side backward. Canon describes what exists; production contracts convert that authority into playable slices; Claude implements bounded work; deterministic verification proves objective behavior; humans play the result and decide whether it actually works as a game.

The repository is authoritative. Chats and implementation sessions are temporary working context.

When a conversation settles a durable project decision, that decision is migrated into the appropriate repository authority before later work depends on it. `docs/18_PROJECT_DECISION_REGISTER.md` is the audit index for those decisions.

## Current status

**Gate 0 — narrative/design foundation complete; engine migrated to Unreal Engine 5.8 before Gate 1.**

The beginning-to-end story, scene/reveal/objective/dialogue contracts, regional living-world material, completion model, canon-to-play process, developer QA contract, Unreal technical direction, modern player-control lineage, and decision-capture workflow are established.

**Issue #1 locomotion is fully specified, repository-reconciled, and FINAL OWNER APPROVED.** The exact contract and canonical five-minute-per-input-profile feel/regression gate live in `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`.

The in-game **System IDE architecture is also locked** in `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`; Gate 1 establishes the shared developer-shell pattern with the Locomotion IDE, and later systems must plug into the same architecture as they are built.

The next player-feel design work is **Issue #2 camera specification**, followed by Claude's Gate 1 Unreal bootstrap once camera authority is similarly complete. Production-scale world construction remains blocked until the graybox control foundation proves itself through human play.
