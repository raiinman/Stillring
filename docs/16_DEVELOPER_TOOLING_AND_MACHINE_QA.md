# 16 — Developer Tooling and Machine QA

**Status:** production tooling contract  
**Authority:** complements `docs/03_PRODUCTION_WORKFLOW.md`, `docs/04_TECHNICAL_DIRECTION.md`, `docs/15_CANON_TO_PLAY_PIPELINE.md`, and `ROADMAP.md`.

Project Stillring is a state-heavy Unreal Engine 5.8 adventure game. Testing it by replaying from the beginning every time is unacceptable. Developer tooling is production infrastructure, not polish.

The shipped game does **not** require Claude, an AI service, API key, network model, or autonomous runtime. Machine-assisted testing described here is an offline/local development capability built on deterministic game controls and readable state.

---

## 1. Goals

The tooling layer must let a developer or Claude reproduce important game states quickly, inspect what the game believes, manipulate controlled variables, and return to a known checkpoint.

It should reduce:

- time spent walking back to a test site;
- bugs that cannot be reproduced;
- accidental dependence on undocumented story flags;
- late discovery of softlocks;
- balance changes made from memory instead of measurement;
- Claude guesswork about runtime/editor state;
- dependence on opaque Blueprint or map state when semantic facts can be exposed directly.

---

## 2. Developer console principles

The developer console must be:

- excluded from or hard-disabled in Shipping builds unless explicitly retained behind a safe developer flag;
- deterministic where practical;
- controller-accessible enough for couch testing, with keyboard shortcuts allowed for speed;
- capable of reporting the exact state changes it performs;
- safe against corrupting normal test saves accidentally;
- organized around authored IDs rather than Actor/package/Blueprint instance paths.

Developer commands should call the same authoritative C++ game-state services used by normal gameplay whenever possible. Avoid a second secret state model that only debug tools understand.

Unreal-native implementation may use a project `UCheatManager`, development-only console commands, UMG debug UI, or another bounded approach, but the semantic command contract matters more than the specific UI.

---

## 3. Minimum console capabilities

### Navigation

- teleport to region;
- teleport to named checkpoint / authored test marker;
- reload current room/area;
- return to last checkpoint;
- show current map, region, checkpoint, and coordinates;
- optionally free-fly/noclip for level-design inspection.

### Story / quest state

- inspect active main objective;
- inspect quest/contract flags;
- set an approved test-state preset;
- advance/revert specific authored state transitions where safe;
- inspect world epoch / catastrophe state;
- inspect NPC recurrence state;
- list unmet prerequisites for a blocked objective or interaction.

Direct arbitrary mutation of every internal flag is less valuable than named **state presets** representing supported test conditions.

Examples:

- `brindle.pre_crisis.clean`
- `rootmere.cathedral.pre_boss`
- `cairnspire.post_grand_ring.reunion`
- `mireglass.pre_memory_reveal`
- `null_meridian.pre_maelor`

Presets must declare the facts they establish so they remain reviewable as canon changes.

### Inventory / tools

- grant/remove a tool;
- grant/remove test items;
- inspect unique-item state;
- set safe test currency/material values if those systems exist;
- restore a canonical loadout for a milestone.

### Combat

- spawn named enemy archetype;
- spawn configured encounter set;
- clear spawned enemies;
- reset boss;
- kill current boss for progression testing;
- toggle invulnerability;
- restore health/resources;
- inspect current combat target and relevant combat state;
- display damage/hit reaction data where useful.

### Waking / Hush

- show current layer;
- force an approved layer transition;
- inspect paired persistent IDs;
- visualize layer-dependent collision/geometry where feasible;
- show relevant Data Layer/level presentation state when that representation is used;
- reload/save-test the current seam state.

### Time / environment

If these systems exist:

- set time of day;
- set weather/environment preset;
- inspect region environmental state;
- force authored ambient event state.

### Save / persistence

- save to dedicated developer slots;
- load dedicated developer slots;
- create named test snapshots where practical;
- inspect save schema version;
- dump semantic state in a human-readable form;
- validate that required persistent IDs referenced by the save still exist.

### Narrative inspection

- show current dialogue ID;
- show conditions that selected the current dialogue branch;
- show unavailable branch prerequisites in developer mode;
- inspect scene/reveal IDs tied to the current objective;
- trigger approved Sequencer/cinematic test entry points without pretending preceding story events occurred unless the preset establishes them.

### Debug visualization

Where useful:

- collision;
- navigation;
- interaction volumes;
- target-lock candidates;
- persistent IDs;
- quest/interactable markers;
- performance counters/stats;
- active gameplay state-machine/state labels;
- presentation layer/Data Layer state where applicable.

---

## 4. In-game bug and observation capture

A developer should be able to record an observation from inside a Development build without manually reconstructing context later.

Minimum captured context should include, where available:

- build/commit identifier;
- timestamp;
- map/region/checkpoint;
- player coordinates;
- current story/world-state preset or key facts;
- active objective;
- Waking/Hush state;
- recent relevant encounter/boss ID;
- optional screenshot path;
- tester-entered note;
- observation class from `docs/15_CANON_TO_PLAY_PIPELINE.md`.

This may initially write a local structured file rather than automatically creating GitHub issues. Networked issue submission is optional and should not become a dependency for ordinary development.

---

## 5. Machine-playable test surface

Stillring should expose a narrow deterministic test interface so automated scripts or local development agents can exercise the game without needing visual mouse automation.

This is **not** an AI gameplay feature for players.

A useful minimum vocabulary is conceptually equivalent to:

- `READ_STATE`
- `LOAD_PRESET`
- `MOVE`
- `LOOK`
- `INTERACT`
- `ATTACK`
- `GUARD`
- `EVADE`
- `USE_TOOL`
- `SELECT_DIALOGUE`
- `WAIT`
- `RESET_CHECKPOINT`

The exact transport may be an Unreal Automation/Functional Test harness, a local command queue/protocol, a Development-only command surface, a later Gauntlet controller, or another implementation proven during production.

Prefer Unreal-native deterministic testing before inventing a custom external protocol.

### State responses

The harness should return machine-readable facts rather than requiring screenshot interpretation for everything.

Useful facts include:

- current checkpoint;
- player transform;
- health/resources;
- inventory/tool state;
- active objective;
- nearby interactable authored IDs;
- nearby enemy IDs/types;
- current lock target;
- layer/world state;
- dialogue options and IDs when dialogue is active;
- death/failure/success state;
- relevant deterministic timers/cooldowns.

Do not expose every private implementation detail by default. Expose the semantic state needed to test player-visible contracts.

---

## 6. Unreal test layers

Use several test layers rather than forcing every problem into one harness.

### Fast C++ Automation Tests / Specs

Best for:
- semantic ID parsing/uniqueness logic;
- damage/math rules;
- quest prerequisite evaluation;
- save schema/migration helpers;
- deterministic content validation.

### Functional Tests

Best for:
- gameplay behavior in a real map;
- interaction and movement scenarios;
- spawn/reset behavior;
- state transitions;
- representative progression smoke routes.

### Content-stress / asset validation

Best for:
- loading important maps;
- catching broken references;
- validating generated/imported content;
- checking critical Blueprints/assets compile/load.

### Gauntlet / higher-level orchestration

Adopt only when the project benefits from repeated packaged-build/session orchestration. Do not add it at Gate 1 merely because it exists.

---

## 7. What automated QA should test

Machine-driven tests are strongest at exhaustive, repetitive, and deterministic checks.

High-value targets include:

### Progression / softlocks

- mandatory route remains completable;
- required objective prerequisites can be satisfied;
- consuming/using optional resources cannot destroy mandatory progression unless explicitly designed;
- boss completion opens the intended next state;
- old region revisits remain reachable when canon says they should;
- catastrophe transitions do not strand the player in invalid saves.

### Save/load

- save before and after major transitions;
- reload Waking/Hush state;
- reload boss/checkpoint state;
- reload completed optional contracts;
- verify unique pickups do not duplicate;
- verify persistent shortcuts remain correct;
- run schema fixtures through migrations when schema changes.

### Combat measurements

- damage calculations;
- hit counts for representative loadouts;
- enemy reset/death behavior;
- lock-on availability rules;
- invulnerability/recovery windows when explicitly specified;
- boss phase thresholds.

Automated results may reveal suspicious balance, but subjective balance decisions remain human design decisions.

### Completion integrity

- every counted collectible/contract/mastery item exists;
- all required completion IDs are reachable under their stated prerequisites;
- 100% counters reconcile with the canonical completion ledger;
- optional content that changes later credits/state produces its promised flag.

### Sequence probes

Test supported and suspicious orderings such as:

- optional content before/after regional catastrophe;
- revisit content before/after a reveal;
- leaving and returning during multi-step contracts;
- dying/reloading between objective steps;
- reaching an area with expected-but-not-required upgrades.

The purpose is to discover unintended assumptions about play order.

---

## 8. What automated QA must not pretend to judge

Do not let machine tests declare that:

- exploration is emotionally satisfying;
- dialogue is moving;
- a mystery is understandable at the intended moment;
- combat has good weight;
- navigation is memorable rather than merely solvable;
- a town feels alive;
- music lands correctly;
- a quiet moment has enough breathing room;
- a boss is fun.

Automation can collect evidence around these questions. Humans judge them.

---

## 9. Test presets as production assets

Named state presets are part of the testing contract and should be version-controlled in reviewable source form.

Each preset should document:

- stable ID/name;
- intended use;
- canonical milestone/state represented;
- player loadout;
- required completed facts;
- required incomplete facts;
- current region/checkpoint;
- expected Waking/Hush state;
- known limitations.

When canon changes, affected presets must be updated or invalidated deliberately.

This prevents “magic debug save #7” or a private editor-only state from becoming undocumented production infrastructure.

---

## 10. Tooling milestones

### Prototype era — minimal

Before/during Gates 1–4:

- reset/reload test map;
- movement/camera values;
- spawn test enemy;
- restore health;
- toggle Hush test layer;
- state/performance readout;
- reproducible command-line build/test entry point for Claude.

### Vertical slice — useful

By Gate 5 exit:

- teleport/checkpoint selection for slice areas;
- inventory/tool grant;
- encounter/boss reset;
- quest/objective inspection for slice content;
- dedicated test saves;
- persistent-ID inspection;
- basic state presets;
- local bug/observation capture;
- at least one automated slice smoke route;
- package/build verification.

### Production foundations — durable

By Gate 6 exit:

- named world/story presets;
- robust semantic state dump;
- reusable machine-playable test surface;
- save/load fixture automation;
- quest/reference validation;
- completion-ledger validation hooks;
- regression harness suitable for region pods;
- Unreal Automation/Functional Test conventions stable enough for repeated Claude use.

Do not defer this foundation until the world is already large.

---

## 11. Security / release boundary

Debug tooling must never create a hidden online control surface in the shipped game.

Requirements:

- no production dependency on Claude or external model APIs;
- no player API charges;
- no remote autonomous agent embedded in retail builds;
- no developer protocol listening on public network interfaces by default;
- no Shipping-build command that can trivially corrupt ordinary saves;
- secrets/API keys must never be compiled into client builds;
- editor-only test plugins/content must not become Shipping dependencies.

Offline local QA may use Claude because the player is not paying for or depending on it.

---

## 12. Definition of done

Developer tooling is successful when a tester or Claude can reproduce an important late-game state in minutes rather than hours, explain what state the game believes it is in, reset the experiment reliably, and produce enough structured evidence that the bug does not depend on memory, screenshot guesswork, or hidden editor state.