# Project Stillring Roadmap

The roadmap is gate-based. Calendar estimates are secondary; evidence decides whether we advance.

## Gate 0 — Charter locked

Deliverables:
- project pillars,
- target player experience,
- original-IP boundaries,
- complete story spine,
- technical direction,
- vertical-slice definition.

Exit condition: the team can explain the game in two minutes without saying “it is basically Zelda with changed names.”

## Gate 1 — Core movement/camera prototype

Build only graybox systems:
- third-person locomotion,
- analog movement,
- camera collision,
- target lock,
- ledge/drop handling,
- interaction prompt,
- debug room.

Exit condition: moving around an empty room already feels deliberate and controllable.

## Gate 2 — Combat prototype

Add:
- light attack chain,
- heavy/committed attack,
- guard,
- dodge/evade,
- hit reactions,
- stamina/commitment model if retained after testing,
- one melee enemy,
- one ranged enemy,
- one shield/armor enemy,
- lock-on switching,
- death/retry loop.

Exit condition: ten minutes of repeated combat remains readable and satisfying without story or final art.

## Gate 3 — Puzzle/tool prototype

Prototype the **Cantor Key** and one multi-use field tool.

Exit condition: the same tool must produce at least one traversal use, one combat use, and one puzzle use.

## Gate 4 — Hush-layer prototype

Build a tiny area that can transition between ordinary Orra and the Hush.

Exit condition:
- the transition is fast,
- state ownership is understandable,
- puzzles can depend on different geometry/physics in each layer,
- save/load survives layer changes.

## Gate 5 — Vertical slice

Target: 20–30 minutes.

Content:
- Brindle village excerpt,
- short wilderness route,
- compact version of the Root Cathedral,
- three enemies,
- Mossjaw miniboss,
- Mawhart boss,
- one tool unlock,
- one Hush puzzle,
- NPC dialogue,
- one cinematic,
- save/load,
- controller support,
- representative low-poly art,
- representative sound and music,
- accessibility baseline.

Exit condition:
- new tester can finish without developer coaching,
- no progression blockers,
- stable frame pacing on target PC,
- art direction is recognizable from screenshots,
- content pipeline is fast enough to repeat,
- team chooses to continue after seeing real cost.

## Gate 6 — Production foundations

Before mass content:
- final save schema v1,
- quest/state model,
- dialogue toolchain,
- cutscene sequencing,
- enemy base components,
- boss state-machine pattern,
- interactable framework,
- inventory/tool framework,
- options/remapping,
- analytics/debug telemetry local-only if used,
- automated smoke test scene.

## Gate 7 — World production, wave A

Build full-quality:
- Brindle / Bellwright Road,
- Rootmere,
- Saltreach,
- Emberstep.

Each region ships as a complete “content pod”: overworld, town/settlement, quests, dungeon, boss, tool, secrets, narrative beat, performance pass.

## Gate 8 — World production, wave B

Build:
- High Aerie,
- Mireglass,
- Cairnfall Observatory,
- full capital hub before catastrophe.

## Gate 9 — Midgame catastrophe + Hush expansion

Build:
- Grand Ring event,
- frozen Cairnspire,
- full Hush traversal rules,
- Ilyra reveal,
- new enemy family,
- changed world-state reactions across all prior regions.

## Gate 10 — Deep Wounds

Build:
- Bone Archive,
- Tempest Belfry,
- Still-Cairn echo-city.

## Gate 11 — Finale

Build:
- Quiet Court siege,
- Null Meridian,
- Maelor confrontation,
- Listener encounter,
- final world decision,
- ending montage,
- post-credits stinger.

## Gate 12 — Alpha

Definition: feature-complete, start-to-finish playable, placeholder assets allowed.

No new foundational systems after alpha without explicit approval.

## Gate 13 — Beta

Definition: content-complete.

Focus only on:
- bugs,
- pacing,
- balance,
- onboarding,
- accessibility,
- performance,
- final art/audio,
- save migration.

## Gate 14 — Release candidate

Requirements:
- clean install,
- controller detection,
- save integrity,
- credits/licenses,
- crash-free soak tests,
- storefront assets,
- build reproducibility,
- legal/IP review,
- final backup/tag.

## Gate 15 — Launch and operations

- release,
- hotfix-only window,
- issue triage,
- patch notes,
- postmortem,
- preserve source/build toolchain,
- decide DLC/sequel only after base game is stable.
