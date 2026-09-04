# Project Stillring Roadmap

The roadmap is gate-based. Calendar estimates are secondary; evidence decides whether we advance.

## Gate 0 — Charter and narrative locked

**Status:** narrative/design foundation complete for production entry.

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
- technical direction;
- vertical-slice definition.

Exit condition: the team can explain the game in two minutes without saying “it is basically Zelda with changed names,” and implementation agents have one non-conflicting narrative authority chain.

---

## Gate 1 — Core movement/camera prototype

Build only graybox systems:
- third-person locomotion;
- analog movement;
- camera collision;
- target lock;
- ledge/drop handling;
- interaction prompt;
- debug room.

Exit condition: moving around an empty room already feels deliberate and controllable.

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
- death/retry loop.

Exit condition: ten minutes of repeated combat remains readable and satisfying without story or final art.

## Gate 3 — Puzzle/tool prototype

Prototype the **Cantor Key** and one multi-use field tool.

Exit condition: the same tool produces at least one traversal use, one combat/pressure use, and one puzzle use.

## Gate 4 — Hush-layer prototype

Build a tiny area that can transition between ordinary Orra and the Hush.

Exit condition:
- transition is fast;
- state ownership is understandable;
- puzzles can depend on different geometry/state in each layer;
- save/load survives layer changes.

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
- one cinematic;
- save/load;
- controller support;
- representative low-poly art;
- representative sound/music;
- accessibility baseline.

Exit condition:
- new tester finishes without developer coaching;
- no progression blockers;
- stable frame pacing on target PC;
- art direction is recognizable from screenshots;
- content pipeline is fast enough to repeat;
- team chooses to continue after seeing real production cost.

## Gate 6 — Production foundations

Before mass content:
- save schema v1;
- deterministic quest/world-state model;
- dialogue toolchain;
- cutscene sequencing;
- NPC recurrence/state support;
- enemy base components;
- boss state-machine pattern;
- interactable framework;
- inventory/tool framework;
- options/remapping;
- local-only debug/telemetry if used;
- automated smoke-test scene.

World-state architecture must support characters and settlements changing while Neris is absent.

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

Exit condition: complete story route and legitimate non-100% ending work; 100% changes specificity/preparedness rather than ending validity.

---

## Gate 11 — Alpha

Definition: feature-complete, start-to-finish playable, placeholder assets allowed.

No new foundational systems after alpha without explicit approval.

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
- final backup/tag.

## Gate 14 — Launch and operations

- release;
- hotfix-only window;
- issue triage;
- patch notes;
- postmortem;
- preserve source/build toolchain;
- decide DLC/sequel only after base game is stable.