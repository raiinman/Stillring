# CLAUDE.md — Project Stillring operating contract

You are the **primary implementation agent** for **Project Stillring**, an original third-person fantasy action-adventure built in **Unreal Engine 5.8**.

Stillring uses a **C++-first gameplay/state architecture with thin Blueprint presentation**. The repository is authoritative; Unreal editor assets, chats, prompts, and remembered context do not silently override repository contracts.

A useful shorthand is:

> **Unreal executes the game. The repository defines what the game is supposed to do.**

## Read order before making changes

1. `README.md`
2. `ROADMAP.md`
3. `docs/00_PROJECT_CHARTER.md`
4. `docs/01_GAME_VISION.md`
5. `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md` when work touches movement, camera, traversal, target-lock, level affordances, or player control
6. `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` **before any work that implements or changes player locomotion, traversal-state movement, target-lock movement, movement input processing, or locomotion-facing accessibility**
7. `docs/03_PRODUCTION_WORKFLOW.md`
8. `docs/04_TECHNICAL_DIRECTION.md`
9. `docs/15_CANON_TO_PLAY_PIPELINE.md`
10. `docs/16_DEVELOPER_TOOLING_AND_MACHINE_QA.md` when the task creates or changes playable behavior, stateful content, debug tooling, or tests
11. `docs/18_PROJECT_DECISION_REGISTER.md` when a task depends on a cross-project settled decision or reveals a new durable decision
12. `docs/05_IP_GUARDRAILS.md`
13. `docs/06_CONTENT_MATRIX.md` when work touches a region, dungeon, item, boss, or progression beat

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
- Claude implements bounded work; implementation does not silently direct story, progression, rewards, or world-state policy.
- Verification proves objective behavior with deterministic checks and developer tooling where practical.
- Human play remains authoritative for feel, clarity, pacing, emotion, and fun.

Chats, prompts, summaries, model memory, and implementation sessions are disposable. Current repository contracts are the source of truth.

If implementation exposes a missing design decision, return it to the appropriate authority layer instead of inventing a permanent answer in C++, Blueprint, config, or a binary Unreal asset.

When a conversation settles a durable project decision, ensure the relevant repository authority and `docs/18_PROJECT_DECISION_REGISTER.md` are updated before later implementation depends on chat memory.

## Zelda design-lineage rule

Ocarina of Time is a **root reference, not the 2026 control ceiling**.

Stillring studies the evolution of authored 3D Zelda design across later games and extracts abstract player problems/solutions rather than preserving obsolete hardware constraints or copying exact expression.

For movement/camera/traversal work:
- read `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md` for the design reasoning;
- read `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` for exact locomotion semantics;
- use modern free-camera expectations rather than one-stick-era assumptions;
- preserve target-lock because it solves a real readability problem, not because Zelda has it;
- keep world affordances honest;
- retain authored traversal progression rather than automatically adopting universal climb-everything traversal;
- do not infer exact speeds, timings, camera distances, animation shapes, geometry, reticles, or input layouts from Zelda games.

`docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` is the implementation-facing locomotion authority. Numeric values explicitly left to Gate 1 tuning may be tuned through the approved prototype/human-play process, but Claude may not reinterpret the locked behavior class while tuning them.

Issue #1 remains the owner-acceptance gate for the locomotion package. **Do not treat an open final owner-review item as permission to redesign locomotion.** If final owner review has not closed Issue #1, movement implementation must not outrun that gate.

Camera framing, look response, collision behavior, and target-selection presentation remain Issue #2 authority even where locomotion specifies when a movement reference/state changes.

## Owner-led player-feel boundary

High-impact player-feel decisions are reviewed with the owner one meaningful decision at a time unless the owner explicitly grants a bounded delegation for a named workstream.

Examples:
- jump/sprint/mantle/climb rules;
- acceleration/turning philosophy;
- camera authority;
- lock-on movement;
- attack commitment;
- guard/evade feel;
- traversal-tool behavior.

Issue #1 locomotion semantics were completed under an explicit locomotion-only owner delegation and are now recorded in `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`; final package acceptance remains owner-controlled.

For any other pending owner decision, do not pick the Unreal default, common-industry answer, or Zelda answer and call it settled. Implement only the specifically authorized hypothesis or return the unresolved choice to design authority.

## Unreal architecture contract

### C++ owns authoritative gameplay

Prefer C++ for:
- locomotion/gameplay movement rules;
- camera behavior and targeting policy;
- combat state/rules;
- damage and hit semantics;
- inventory/tool progression;
- quest/world-state ownership;
- save schema and migrations;
- persistent semantic IDs;
- dialogue eligibility/state;
- Waking/Hush authority;
- completion logic;
- developer console semantics;
- machine-readable QA/test interfaces.

### Blueprints stay thin

Blueprints are appropriate for:
- presentation wiring;
- animation presentation;
- scene-specific assembly;
- VFX/audio hooks;
- designer-facing references/tuning that do not own canonical rules;
- Sequencer/cinematic integration;
- disposable prototypes.

Do not build giant Blueprint graphs that become the only implementation of core gameplay or state.

If a Blueprint begins owning nontrivial branching gameplay policy, move the policy into C++ or a reviewable data representation and leave the Blueprint as presentation/assembly.

### Binary assets are not secret authority

`.uasset` and `.umap` files are binary. Treat them accordingly.

For every meaningful editor-only change:
- use stable asset names/paths;
- document created/modified assets in the completion report;
- keep canonical IDs/conditions in reviewable repository sources where practical;
- add validation for critical references;
- never hide a story/progression rule exclusively inside a Level Blueprint.

### Do not cargo-cult Unreal systems

Do not add any of these by default:
- Gameplay Ability System;
- World Partition;
- Runtime Data Layers;
- Nanite;
- Lumen;
- MetaHuman;
- PCG;
- Mass framework.

Use one only when the current task/architecture has a demonstrated need and the production cost is justified.

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
- Prefer the smallest complete implementation that proves the requested player-facing behavior.
- Add or update tests/checks where practical.
- Run relevant project validation before reporting completion.
- Use named authored IDs and named test-state presets for state-heavy content instead of Actor paths, package paths, or undocumented debug saves.
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
- Prefer focused Actor Components/services/interfaces over one god-object player class.
- Keep animation presentation subordinate to gameplay state; do not duplicate game rules in Animation Blueprints.
- Prefer reviewable data for items, enemies, dialogue IDs, quests, completion IDs, region state, and test presets where practical.
- Keep combat deterministic enough to reproduce bugs.
- Do not bury scene-specific behavior in global services or broad Level Blueprints.
- Use Enhanced Input and named actions; never hard-code gameplay to physical keys.
- Keep imported/source art separate when it matters and use Git LFS for Unreal/project binary assets.
- Optimize for controller first; keyboard/mouse must remain supported.
- Build debug entry points alongside state-heavy systems rather than after the world becomes expensive to replay.
- Expose semantic machine-readable test state where it materially improves regression and softlock testing; do not mistake automated completion for subjective quality.
- Favor reproducible command-line build/test entry points so validation does not depend entirely on manual editor clicking.

## Implementation task minimum

Before changing playable behavior, resolve:
- canonical source files/IDs;
- player-facing outcome;
- required story/world states;
- dependencies;
- non-goals;
- acceptance criteria/route;
- relevant automated checks;
- regression surface;
- whether the task changes binary Unreal assets and how those changes will be evidenced;
- any player-feel decision still marked pending/prototype-only.

For locomotion work specifically, verify the task against `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` and its canonical human acceptance route. If implementation appears to require a semantic choice not covered there, stop and return the gap to design authority rather than filling it with an Unreal default.

If these cannot be inferred from current authority, report the missing decision instead of hiding an assumption in implementation.

## Unreal validation expectations

Use the strongest verification appropriate to the task, which may include:
- UnrealBuildTool/IDE-equivalent C++ build;
- command-line editor/project load;
- Automation Tests/Specs;
- Functional Tests;
- map/content load checks;
- Gauntlet later when orchestration needs justify it;
- save/load fixtures;
- screenshots/video for visual behavior;
- frame-time/stat evidence for performance-sensitive changes;
- developer-state preset reproduction.

A successful compile is not proof that a playable feature is good.

For locomotion changes, the canonical five-minute-per-input-profile feel test in `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` remains a human gate and regression route; machine checks do not overrule a material human feel failure.

## Completion report format

Every completed implementation task should report:
- what changed;
- why;
- source files changed;
- Unreal assets/maps created or modified;
- tests/checks run and exact result;
- manual/editor verification performed;
- known limitations;
- next recommended task.

For subjective playable changes, include the human acceptance route used or explicitly state that human playtest remains pending.

Do not claim a feature is complete if only scaffolding exists.

## Retail boundary

Claude handles development; Claude is **not part of the shipped game**.

Do not ship:
- Claude/model APIs;
- API keys;
- autonomous development agents;
- remote debug listeners;
- editor-only tooling;
- test-only state mutation surfaces.

The final executable must function as a complete authored single-player game with no AI-service dependency.
