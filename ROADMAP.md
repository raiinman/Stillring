# Project Stillring Roadmap

The roadmap is gate-based. Calendar estimates are secondary; evidence decides whether we advance.

All gates operate under `docs/15_CANON_TO_PLAY_PIPELINE.md`: **CANON → PRODUCTION → IMPLEMENTATION → VERIFICATION → PLAY**.

**Production engine:** Unreal Engine 5.8  
**Primary implementation agent:** Claude  
**Gameplay/state architecture:** C++ first; thin Blueprint presentation/assembly.

## Gate 0 — Charter and narrative locked

**Status:** narrative/design foundation complete for production entry; Unreal Engine migration completed before Gate 1 implementation.

Locked deliverables:
- project pillars;
- target player experience;
- original-IP boundaries;
- complete beginning-to-end story spine;
- final character arcs/culpability;
- final scene beat ledger;
- final reveal/foreshadow timing;
- final main-quest objective flow;
- final dialogue anchors;
- final 100% narrative route;
- regional community bibles;
- world-pulse / emotional pacing / quiet-moment rules;
- completion taxonomy and authored side-content ledger;
- Unreal Engine 5.8 technical direction and C++/Blueprint authority boundary;
- vertical-slice definition;
- canon-to-play production contract;
- developer-tooling / machine-QA contract;
- modern Zelda design-lineage / player-control principles;
- project decision register and conversation-to-repository capture rule.

Exit condition: the team can explain the game in two minutes without saying “it is basically Zelda with changed names,” Claude has one non-conflicting authority chain, and production has an explicit method for turning that authority into playable slices without implementation improvisation or chat-memory dependency.

---

## Gate 1 — Core movement/camera prototype

Before implementation, complete the owner-led locomotion and camera specifications in Issues #1 and #2.

Movement/camera decisions must follow `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md`: Ocarina of Time is a root reference rather than the 2026 ceiling, later Zelda improvements matter, and exact Nintendo expression is not copied.

Bootstrap the minimum Unreal Engine 5.8 C++ project needed to test graybox movement/camera.

Build only:
- minimal C++ project/module structure;
- Enhanced Input baseline;
- graybox movement/camera test map;
- third-person locomotion;
- useful analog low-speed through full-speed movement;
- always-available modest deliberate jump;
- small authored mantle/scramble response for obviously low obstacles;
- approved sprint/dash prototype hypothesis;
- automatic stairs/small-step/minor-terrain handling;
- meaningful height gates that remain blocked until a route/tool/later traversal capability solves them;
- free exploration camera;
- recenter convenience;
- camera collision;
- target lock;
- ledge/drop handling per the final Issue #1 decisions;
- interaction prompt;
- affordance-honesty test geometry;
- minimal runtime state/performance readout;
- reproducible command-line build/editor-load/Automation entry point.

Do not let stock Third Person template defaults, Ocarina-era hardware constraints, or another Zelda game's exact control values silently become Stillring's movement/camera specification.

The existence of deliberate jump and low-obstacle mantle/scramble is now locked. Gate 1 still tunes their exact arc, thresholds, animation response, and air-control details through human play. Sprint/dash remains a prototype hypothesis and may still be rejected or revised.

Exit condition:
- moving around an ugly gray room already feels deliberate and controllable;
- ordinary movement stops demanding conscious correction within roughly the first five minutes of a fresh playtest;
- stairs/small terrain do not create accidental friction;
- deliberate jump feels useful without turning ordinary traversal into constant bunny-hopping;
- low obvious obstacles mantle/scramble consistently;
- meaningful height gates remain readable rather than accidentally bypassable;
- camera behavior is trustworthy enough that the player looks at the room rather than fighting the view;
- obvious traversal affordances behave consistently or communicate their restriction;
- Claude can build/validate the prototype reproducibly without depending entirely on manual editor clicking.

## Gate 2 — Combat prototype

Add:
- light attack chain;
- heavy/committed attack;
- guard;
- dodge/evade;
- hit reactions;
- stamina/commitment model if retained after testing;
- one melee enemy;
- one ranged enemy;
- one shield/armor enemy;
- lock-on switching;
- encounter aggression/readability rules compatible with the camera's practical visual bandwidth;
- death/retry loop;
- test enemy spawn/reset and health/resource restore controls.

Authoritative combat rules remain C++ first; Animation Blueprints present gameplay state rather than owning a contradictory combat model.

Exit condition: ten minutes of repeated combat remains readable and satisfying without story or final art.

## Gate 3 — Puzzle/tool prototype

Prototype the **Cantor Key** and one multi-use field tool.

Exit condition: the same tool produces at least one traversal use, one combat/pressure use, and one puzzle use.

## Gate 4 — Hush-layer prototype

Build a tiny area that can transition between ordinary Orra and the Hush.

Compare at least two credible Unreal representations before locking the production architecture, including:
- World Partition + Runtime Data Layers where appropriate;
- a non-World-Partition explicit level/Actor layering approach.

Data Layers/presentation state must not become canonical quest/world-state authority.

Exit condition:
- transition is fast;
- state ownership is understandable;
- puzzles can depend on different geometry/state in each layer;
- save/load survives layer changes;
- developer controls can force the approved test transition and inspect paired persistent IDs;
- the chosen architecture is justified by authoring clarity, source-control cost, performance, and save reliability.

## Gate 5 — Vertical slice

Target: 20–30 minutes.

Content:
- Brindle village excerpt;
- short wilderness route;
- compact Root Cathedral;
- three enemies;
- Mossjaw pressure encounter;
- Mawhart boss;
- Anchor Line unlock;
- one Hush puzzle;
- NPC dialogue;
- one Sequencer-supported cinematic;
- save/load;
- controller support;
- representative low-poly art;
- representative sound/music;
- accessibility baseline;
- representative Stillring rendering configuration rather than generic Unreal defaults.

Required testing/tooling for the slice:
- teleport/checkpoint selection for slice areas;
- inventory/tool grant/remove for test loadouts;
- encounter and boss reset;
- quest/objective inspection for slice content;
- dedicated developer save slots;
- persistent-ID inspection;
- named state presets for important slice states;
- local bug/observation capture;
- at least one automated smoke route through a representative slice path;
- reproducible package/build verification.

Exit condition:
- new tester finishes without developer coaching;
- no progression blockers;
- stable frame pacing on target PC;
- art direction is recognizable from screenshots and does not read as a default Unreal project;
- content pipeline is fast enough to repeat;
- important slice states can be reproduced in minutes rather than by replaying the entire route;
- automated smoke route and save/load checks pass;
- package/build process is reproducible;
- team chooses to continue after seeing real production cost.

## Gate 6 — Production foundations

Before mass content:
- save schema v1;
- deterministic quest/world-state model;
- dialogue toolchain;
- Sequencer/cutscene state-entry conventions;
- NPC recurrence/state support;
- enemy base components;
- boss state-machine pattern;
- interactable framework;
- inventory/tool framework;
- options/remapping;
- durable local developer console;
- named world/story test-state presets;
- semantic machine-readable state dump;
- Unreal Automation/Functional Test conventions;
- reusable local machine-playable QA surface;
- save/load fixture automation;
- quest/dialogue/reference validation;
- completion-ledger validation hooks;
- structured local bug/observation capture;
- automated smoke-test map/harness;
- binary Unreal asset/reference validation and PR evidence convention;
- Gauntlet adoption only if packaged-session orchestration now justifies it.

World-state architecture must support characters and settlements changing while Neris is absent.

The machine-QA surface is development infrastructure only. Retail builds must not require Claude/model APIs, remote agents, network control surfaces, or player-funded AI usage.

Exit condition:
- the architecture is stable enough to build region pods without programmer surgery;
- important story/world states can be created with named, reviewable presets;
- regressions can exercise semantic game actions and read semantic state without relying on screenshot automation;
- binary `.uasset`/`.umap` state is not the only place critical gameplay rules can be understood;
- a tester or Claude can reproduce a late/state-heavy scenario quickly and produce structured evidence.

---

# Gate 7 — World production wave A / the world before Grand Ring

Build the full playable first half plus the normal-life anchors required for later recontextualization.

### Full-quality critical-path areas
- Brindle;
- bell road to Cairnspire;
- Cairnspire public/route/archive areas;
- Old Viaduct / First Circuit route network;
- Rootmere + Root Cathedral;
- Saltreach + Tide Foundry;
- Emberstep + Kiln of Names.

### Required pre-Grand-Ring postcard areas
Build the ordinary-life slices that will later become parts of the full changed-world regions:
- High Aerie lower cargo lift / Wind Kitchen / normal wind span;
- Mireglass Reedwater Exchange / Lantern Ferry / reflection-game area;
- Cairnfall South Steps / public observation area;
- Graymile Line Skiff shed.

Do **not** build full High Aerie/Mireglass/Cairnfall campaigns as if they happen before Grand Ring. Only their before-memory spaces belong in this wave.

Each production pod must have canonical sources, a player-facing acceptance route, named test presets for important states, and regression coverage for affected earlier content.

Exit condition: a start-to-Grand-Ring playthrough makes all six regions recognizable and the three crisis regions production-complete.

---

# Gate 8 — Grand Ring + changed-world foundation

Build:
- Emberstep-to-Cairnspire urgency return;
- three-point confrontation;
- playable Grand Ring crisis;
- before-memory catastrophe montage;
- Hush-Cairnspire reunion area;
- Ilyra wrong-workbench sequence;
- changed Brindle;
- setup/payoff state transitions;
- Line Skiff acquisition/tutorial;
- moving-pocket rules;
- post-Grand-Ring route-state framework.

Required verification includes save/reload across the pivot, setup/payoff state combinations, recurrence changes, and regression against pre-Grand-Ring presets.

Exit condition: the world-state pivot is fully playable and old choices visibly alter changed-world routes/social states without breaking saves.

---

# Gate 9 — World production wave B / changed Orra

Build full-quality:
- High Aerie Monastery of Updraft / Tempest Belfry;
- Bone Archive interlude;
- Mireglass / Palace Under Reeds;
- Cairnfall / Fallen Orrery;
- Still-Cairn;
- Mirror/Palinode/seam revisit content across old regions.

Each region must preserve continuity with its Gate 7 before-memory rather than feeling like a new unrelated level.

Required story outcomes:
- Motion discovered through High Aerie play;
- Ilyra admits Mercy Window authorship in Bone Archive;
- Memory + full Mercy Window truth in Mireglass;
- seam mode + Orin signal in Cairnfall;
- Ending + Orin confession in Still-Cairn.

Exit condition: changed-world critical path and major revisit waves are playable end-to-end through Orin's recovery.

---

# Gate 10 — Unringing + finale

Build:
- six community disconnection projects;
- late completion convergence;
- Broken Standard Yard;
- final prestige/hunt/elite content;
- Null Meridian approach;
- paired-mechanic final dungeon;
- Quiet Court archive;
- Maelor encounter;
- save-state-sensitive Listener memory system where feasible;
- Meridian decommissioning;
- playable Brindle epilogue;
- credits-state variations;
- post-credits stinger.

Required verification includes completion-ledger reconciliation, sequence probes around optional Unringing work, and save-state-sensitive credits/epilogue checks.

Exit condition: complete story route and legitimate non-100% ending work; 100% changes specificity/preparedness rather than ending validity.

---

## Gate 11 — Alpha

Definition: feature-complete, start-to-finish playable, placeholder assets allowed.

No new foundational systems after alpha without explicit approval.

Automated progression, save/load, completion-integrity, and representative region regression suites must be running before Alpha exit.

## Gate 12 — Beta

Definition: content-complete.

Focus only on:
- bugs;
- pacing;
- balance;
- onboarding;
- accessibility;
- performance;
- final art/audio;
- save migration;
- narrative continuity/recurrence regression.

## Gate 13 — Release candidate

Requirements:
- clean install;
- controller detection;
- save integrity;
- credits/licenses;
- crash-free soak tests;
- storefront assets;
- build reproducibility;
- legal/IP review;
- final backup/tag;
- Shipping build proven free of Claude/model runtime, development-only remote control, editor-only, and test-only dependencies.

## Gate 14 — Launch and operations

- release;
- hotfix-only window;
- issue triage;
- patch notes;
- postmortem;
- preserve source/build toolchain;
- decide DLC/sequel only after base game is stable.
