# CLAUDE.md — Project Stillring operating contract

You are contributing to **Project Stillring**, an original third-person fantasy action-adventure built in Godot 4.7.2 stable.

## Read order before making changes

1. `README.md`
2. `ROADMAP.md`
3. `docs/00_PROJECT_CHARTER.md`
4. `docs/01_GAME_VISION.md`
5. `docs/02_STORY_BIBLE.md` when work touches narrative/content
6. `docs/03_PRODUCTION_WORKFLOW.md`
7. `docs/04_TECHNICAL_DIRECTION.md`
8. `docs/05_IP_GUARDRAILS.md`
9. `docs/06_CONTENT_MATRIX.md` when work touches a region/dungeon/item/boss

## Non-negotiable behavior

- Work from an issue or a clearly scoped task.
- Do not silently broaden scope.
- Prefer the smallest shippable implementation that proves the requested behavior.
- Add or update tests/checks where practical.
- Run the relevant project validation before reporting completion.
- Never import or derive from commercial game ROMs, decompilations, leaked code, ripped assets, extracted maps, copied dialogue, copied music, or trademarked branding.
- Do not create a suspiciously close substitute for a Nintendo character, enemy, dungeon, UI, musical motif, logo, or map.
- When inspiration is requested, extract the **design problem** first, then invent a new solution.

## Design firewall

For every feature inspired by an older adventure game, answer internally:

1. What player problem is this solving?
2. What abstract mechanic solves it?
3. What does Project Stillring do differently in fiction, geometry, art, audio, controls, pacing, and implementation?

If the answer is merely “same thing with different names/colors,” stop and redesign it.

## Engineering principles

- Use composition over giant inheritance trees.
- Keep game-state ownership explicit.
- Prefer data-driven content definitions for items, enemies, dialogue IDs, quests, and region state.
- Avoid autoload/global singletons unless the responsibility is truly global.
- Keep combat code deterministic enough to reproduce bugs.
- Do not bury scene-specific behavior in global managers.
- Keep imported/source art separate when it matters, and use Git LFS for large binary assets.
- Optimize for controller first; keyboard/mouse must remain supported.

## Completion report format

Every completed coding task should report:

- what changed,
- why,
- files changed,
- tests/checks run,
- known limitations,
- next recommended task.

Do not claim a feature is complete if only scaffolding exists.
