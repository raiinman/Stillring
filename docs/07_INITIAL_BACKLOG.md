# 07 — Initial Backlog

These are the first issues to create after the repository exists on GitHub. Do not skip directly to world-content production.

All implementation work follows `docs/15_CANON_TO_PLAY_PIPELINE.md`. Developer tooling and automated regression requirements follow `docs/16_DEVELOPER_TOOLING_AND_MACHINE_QA.md`.

The production engine is **Unreal Engine 5.8**. Claude is the primary implementation agent. Authoritative gameplay/state is C++ first; Blueprint is thin presentation/assembly unless a scoped prototype explicitly says otherwise.

Movement/camera work must also follow `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md`. Project-wide settled decisions are indexed in `docs/18_PROJECT_DECISION_REGISTER.md`.

## P0 — Pre-production closure

### Issue 1 — Lock player locomotion specification
**Outcome:** Written physical movement vocabulary and movement-feel rules that Claude can prototype without inheriting Unreal defaults or obsolete 1998 control assumptions.

Acceptance:
- controller axes/dead-zone philosophy defined;
- camera-relative exploration movement defined;
- target-lock movement differences defined;
- analog low-speed/full-speed behavior defined;
- acceleration/deceleration/turn philosophy defined;
- stairs/small-step/minor-terrain handling defined;
- always-available modest deliberate jump locked;
- small low-obstacle mantle/scramble response locked;
- major cliffs/meaningful height gates preserved as authored traversal gates;
- sprint/dash prototype hypothesis reviewed;
- ledge/drop behavior defined;
- climbing/swimming/crouch/air-control/fall rules either defined or explicitly marked out-of-scope/pending;
- accessibility implications recorded;
- every still-unresolved player-feel choice is explicitly marked **PENDING OWNER REVIEW** rather than left to Claude/Unreal defaults.

Owner review proceeds one meaningful physical capability at a time.

### Issue 2 — Lock camera specification
**Outcome:** Camera behavior matrix for modern free exploration camera, recenter convenience, lock-on combat, cramped rooms, vertical spaces, and bosses.

Acceptance:
- right-stick/mouse free exploration camera grammar defined;
- recenter behavior defined as a convenience rather than the primary camera-control model;
- lock-on camera transition/framing defined;
- target switching camera response defined;
- collision/occlusion priorities defined;
- cramped-space/low-ceiling behavior defined;
- vertical-space/boss behavior defined;
- sensitivity/inversion/camera-shake accessibility defined;
- failure cases/test-room requirements defined;
- no Ocarina-era one-stick limitation is preserved merely because Ocarina is a design reference.

### Issue 3 — Define combat frame/state model
**Outcome:** State diagram for attacks, guard, evade, hit reactions, interrupts, recovery, invulnerability if any.

### Issue 4 — Define persistent world-state schema
**Outcome:** Stable IDs and save categories proven on paper before content depends on them.

### Pre-production production-contract check
Before a playable slice enters implementation, ensure its task/parent issue identifies:
- canonical source files/IDs,
- player-facing outcome,
- required states,
- dependencies,
- non-goals,
- acceptance route,
- automated checks,
- regression surface,
- evidence required,
- expected C++ versus Unreal binary-asset changes,
- any player-feel decision still marked prototype-only or pending owner review.

If Claude would need to invent story, progression, reward, world-state policy, or unresolved core player-feel policy to proceed, the task is not ready.

## P1 — Gate 1 Unreal prototype

### Issue 5 — Bootstrap Unreal Engine 5.8 C++ project
- create minimal `game/Stillring.uproject` C++ project;
- project opens cleanly in Unreal Engine 5.8;
- establish the smallest practical C++ module structure;
- configure Enhanced Input baseline;
- create a Gate 1 graybox test map with floor, slopes, stairs, narrow passage, low ceiling, ledges, low mantle geometry, affordance comparison geometry, meaningful height-gate geometry, and target markers;
- add minimal runtime state/performance readout;
- establish Git/LFS-safe Unreal ignore rules and project binary policy;
- document reproducible command-line build/editor-load/automation entry points;
- no production world content or final art.

### Issue 6 — Third-person locomotion prototype
- implement gameplay movement behavior in C++ from Issue #1;
- analog low-speed through full-speed movement;
- camera-relative steering;
- slopes/stairs/small-step handling;
- grounded transitions;
- always-available modest deliberate jump;
- small low-obstacle mantle/scramble response;
- meaningful height gates not bypassable by baseline jump/mantle;
- approved sprint/dash experiment;
- ledge/drop behavior per Issue #1;
- tuning values exposed deliberately;
- debug values visible;
- Blueprint/animation work presentation-only;
- locked movement vocabulary may be tuned through play but not silently removed or expanded.

### Issue 7 — Exploration camera prototype
- C++ camera policy/controller logic;
- modern free orbit;
- recenter convenience;
- collision handling;
- cramped-room/low-ceiling handling;
- sensitivity/inversion options;
- no wall clipping in test room;
- debug camera state readout;
- no stock template or legacy Zelda camera behavior treated as design authority.

### Issue 8 — Target-lock prototype
- acquire target;
- drop target;
- cycle targets;
- lock-on locomotion;
- multi-target edge cases;
- clear visual indicator using original UI language;
- authoritative target-selection policy in C++;
- combat-framing evidence sufficient to inform later enemy-aggression/readability rules.

### Gate 1 developer-tooling minimum
- reset/reload test map;
- current map/coordinates readout;
- movement/camera tuning readout;
- frame/performance counters;
- command-line build/test path Claude can run without manual editor-only validation.

### Gate 1 human acceptance
The prototype does not pass because it compiles.

Required human questions:
- within roughly five minutes, does ordinary movement stop demanding conscious correction?
- do stairs and minor ground irregularities disappear beneath player intention?
- does the deliberate jump feel useful without encouraging constant meaningless bunny-hopping?
- do obviously low obstacles mantle/scramble consistently and naturally?
- do major height gates remain readable and intact?
- does the free camera feel owned by the player without constant babysitting?
- do obvious traversal affordances work consistently or communicate their restriction?
- does the sprint/dash hypothesis improve the game, or should it be rejected/revised before combat depends on it?

## P2 — Gate 2 combat prototype

### Issue 9 — Damage/hitbox foundation
### Issue 10 — Player light/heavy attacks
### Issue 11 — Guard + evade
### Issue 12 — Enemy melee archetype
### Issue 13 — Enemy ranged archetype
### Issue 14 — Enemy armor/guard archetype
### Issue 15 — Death/retry loop

Combat authority remains C++ first. Animation Blueprints may present state but may not become the sole owner of combat rules.

Lock-on readability is partly an encounter-design problem. Enemy aggression/composition must eventually account for what the player and camera can reasonably read rather than assuming every nearby enemy attacks without coordination.

Required combat-test controls by Gate 2 exit:
- spawn configured test enemy;
- clear/reset encounter;
- restore player health/resources;
- inspect target/combat state needed to reproduce bugs.

## P3 — Gate 3 tools

### Issue 16 — Cantor Key resonance laboratory
### Issue 17 — Anchor Line traversal/puzzle/combat prototype

## P4 — Gate 4 Hush

### Issue 18 — Persistent paired-layer test world
Prototype at least two credible Unreal representations before locking the final region pattern, including:
- a World Partition + Runtime Data Layer candidate where appropriate;
- a non-World-Partition explicit level/Actor layering candidate.

Do not use Data Layers as quest-state authority.

### Issue 19 — Seam transition prototype
### Issue 20 — Save/load across Waking/Hush state

Required Hush-test controls by Gate 4 exit:
- force the approved test transition;
- inspect paired persistent IDs;
- show current layer/state;
- reload/save-test the seam state;
- compare authoring/source-control/performance cost of the candidate representations.

## P5 — Vertical slice

Create separate issues for:
- Brindle slice graybox;
- Rootmere trail graybox;
- Root Cathedral graybox;
- Mossjaw miniboss;
- Mawhart boss;
- NPC/dialogue system;
- Sequencer/cinematic plumbing;
- representative environment kit;
- representative character/enemy kit;
- animation/Control Rig production experiment where useful;
- audio identity pass;
- options/accessibility baseline;
- Unreal rendering identity pass;
- vertical-slice external playtest;
- vertical-slice production-cost review.

### Required vertical-slice tooling issues
Also create scoped work for:
- slice teleport/checkpoint selector;
- named slice state presets;
- inventory/tool test loadouts;
- encounter/boss reset controls;
- quest/objective/persistent-ID inspector;
- dedicated developer save slots;
- structured local bug/observation capture;
- automated representative smoke route;
- package/build reproducibility.

These are part of the slice acceptance boundary, not optional cleanup after the slice.

## P6 — Production-foundation tooling

Before mass region production, create/close scoped issues for:
- durable local developer console;
- named story/world-state preset system;
- semantic machine-readable state dump;
- Unreal Automation/Functional Test integration;
- local machine-playable test driver/harness;
- save/load fixture automation;
- quest/dialogue/reference integrity validation;
- completion-ledger validation hooks;
- reusable region-pod regression harness;
- Gauntlet adoption only if build/session orchestration justifies it;
- binary asset/reference validation and evidence conventions.

The retail game must not depend on Claude, external model APIs, remote agents, or player-funded AI usage. Machine-assisted QA is offline/local development infrastructure.

## Unreal dependency rule

Do not add Gameplay Ability System, World Partition, Runtime Data Layers, Nanite, Lumen, MetaHuman, PCG, or another major Unreal framework merely because it exists.

A scoped issue must demonstrate why the dependency reduces Stillring's total production cost or risk.

## Backlog rule

If Claude discovers work outside the current issue, record a new backlog item rather than silently expanding the active implementation.

“Claude can code it quickly” is not sufficient reason to add a feature. New features still incur design, integration, save-state, UI, accessibility, testing, balance, regression, binary-asset, and maintenance cost.
