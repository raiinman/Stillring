# CLAUDE.md — Project Stillring operating contract

You are contributing to **Project Stillring**, an original third-person fantasy action-adventure built in Godot 4.7.2 stable.

## Read order before making changes

1. `README.md`
2. `ROADMAP.md`
3. `docs/00_PROJECT_CHARTER.md`
4. `docs/01_GAME_VISION.md`
5. `docs/03_PRODUCTION_WORKFLOW.md`
6. `docs/04_TECHNICAL_DIRECTION.md`
7. `docs/15_CANON_TO_PLAY_PIPELINE.md`
8. `docs/16_DEVELOPER_TOOLING_AND_MACHINE_QA.md` when the task creates or changes playable behavior, stateful content, debug tooling, or tests
9. `docs/05_IP_GUARDRAILS.md`
10. `docs/06_CONTENT_MATRIX.md` when work touches a region, dungeon, item, boss, or progression beat

### If the task touches narrative, quests, NPCs, regions, dialogue, world state, or progression
Read these **in order** before authoring or implementing content:

1. `docs/02_STORY_BIBLE.md`
2. `docs/story/06_CHARACTER_ARCS_AND_RELATIONSHIPS.md`
3. `docs/story/07_SCENE_BEAT_LEDGER.md`
4. `docs/story/08_REVEAL_AND_FORESHADOW_LEDGER.md`
5. `docs/story/09_MAIN_QUEST_OBJECTIVE_FLOW.md`
6. `docs/story/10_DIALOGUE_ANCHORS.md`
7. `docs/12_100_PERCENT_ROUTE.md`
8. the relevant file under `docs/story/regions/`
9. `docs/story/12_WORLD_PULSE_LEDGER.md`, `13_EMOTIONAL_PACING_MAP.md`, `14_QUIET_MOMENTS_AND_TRAVEL_BEATS.md`, and `17_SIDE_INTERACTION_REBALANCE.md` when the task affects recurrence, travel, optional interactions, or regional state

The story contracts above are direct canonical authority. There is **no patch/supersession layer**. If a proposed change conflicts with another canonical story contract, update every affected contract together instead of silently overriding one file.

## Canon-to-play authority

Stillring is produced through **CANON → PRODUCTION → IMPLEMENTATION → VERIFICATION → PLAY**.

- Canon describes what exists in the finished authored game.
- Production converts canon into player-complete slices and explicit acceptance routes.
- Implementation agents build bounded work; they do not silently direct story, progression, rewards, or world-state policy.
- Verification proves objective behavior with deterministic checks and developer tooling where practical.
- Human play remains authoritative for feel, clarity, pacing, emotion, and fun.

Chats, prompts, summaries, and remembered model context are disposable. Current repository contracts are the source of truth.

If implementation exposes a missing design decision, return it to the appropriate authority layer instead of inventing a permanent answer in code.

## Non-negotiable narrative behavior

- Every major normal-world location must be worth visiting before anything bad happens there.
- Keep the main quest understandable as a chain of human motivations, not named systems or collectible metaphysics.
- Do not reintroduce Motion / Memory / Ending as an upfront three-item checklist; they are discovered through play and named afterward.
- Do not make Neris chosen by prophecy, bloodline, reincarnation, the Listener, or a sentient Cantor Key. Neris's field-operability is an accident of the Brindle calibration event.
- Maelor must remain technically competent, causally responsible, understandable, and unexcused.
- Ilyra must remain loving and culpable; do not rewrite Mercy Window as innocent work stolen by Maelor.
- Tessa's old freight failure is deliberate incuriosity, not secret Stillring knowledge and not simple tax evasion.
- Rusk has legitimate safety arguments and institutional culpability; do not flatten him into a cartoon bureaucrat or reform savior.
- Optional completion may deepen consequences and credits specificity, but there is one valid canonical ending.
- The world must change while Neris is elsewhere.
- Not every side interaction should restate the central thesis. Preserve life-bearing material with no reward when appropriate.

## Non-negotiable project behavior

- Work from an issue or a clearly scoped task.
- Do not silently broaden scope.
- Prefer the smallest shippable implementation that proves the requested behavior.
- Add or update tests/checks where practical.
- Run relevant project validation before reporting completion.
- Use named authored IDs and named test-state presets for state-heavy content instead of relying on fragile scene paths or undocumented debug saves.
- Keep developer tooling local/offline by default; the retail game must not depend on external model APIs or autonomous agents.
- Never import or derive from commercial game ROMs, decompilations, leaked code, ripped assets, extracted maps, copied dialogue, copied music, or trademarked branding.
- Do not create a suspiciously close substitute for a Nintendo character, enemy, dungeon, UI, musical motif, logo, map, scene sequence, or quest dependency.
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
- Build debug entry points alongside state-heavy systems rather than after the world becomes expensive to replay.
- Expose semantic machine-readable test state where it materially improves regression and softlock testing; do not mistake automated completion for subjective quality.

## Implementation task minimum

Before changing playable behavior, resolve:

- canonical source files/IDs;
- player-facing outcome;
- required story/world states;
- dependencies;
- non-goals;
- acceptance criteria/route;
- relevant automated checks;
- regression surface.

If these cannot be inferred from current authority, report the missing decision instead of hiding an assumption in implementation.

## Completion report format

Every completed coding task should report:

- what changed,
- why,
- files changed,
- tests/checks run,
- known limitations,
- next recommended task.

For subjective playable changes, include the human acceptance route used or explicitly state that human playtest remains pending.

Do not claim a feature is complete if only scaffolding exists.