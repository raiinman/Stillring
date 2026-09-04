# 18 — Project Decision Register

**Status:** living authority index  
**Audit date:** 2026-09-04  
**Purpose:** ensure settled Project Stillring decisions do not exist only in chat history, model memory, or editor state.

This file is an **index**, not a supersession layer. Detailed authority remains in the linked source documents. If this register and a detailed authority file ever disagree, fix the inconsistency instead of treating this register as a patch.

---

## Decision-state vocabulary

- **LOCKED** — accepted project direction. Do not silently change during implementation.
- **PROTOTYPE HYPOTHESIS** — deliberately approved to test, but human play may reject or revise it.
- **PENDING OWNER REVIEW** — a stated owner decision/review is still outstanding. Claude must not treat it as resolved.
- **HISTORICAL / SUPERSEDED** — retained only to explain why current direction changed.

---

## Core identity and scope

| ID | Status | Decision | Detailed authority |
|---|---|---|---|
| D-001 | LOCKED | Stillring is an original third-person fantasy action-adventure, not a Zelda clone or reskin. | `README.md`, `docs/00_PROJECT_CHARTER.md`, `docs/05_IP_GUARDRAILS.md` |
| D-002 | LOCKED | Target scope is a complete authored roughly 20–30 hour single-player game. | `README.md`, `docs/00_PROJECT_CHARTER.md` |
| D-003 | LOCKED | Core production principle: gain meaningful verbs rather than stat clutter; tools change traversal, combat, or puzzle language. | `README.md`, `docs/01_GAME_VISION.md`, `docs/09_STILLRING_PROGRESSION_BLUEPRINT.md` |
| D-004 | LOCKED | Full production does not begin before a representative vertical slice proves fun, readability, stability, testability, and sustainable production cost. | `README.md`, `ROADMAP.md`, `docs/03_PRODUCTION_WORKFLOW.md` |

---

## Narrative / world authority

| ID | Status | Decision | Detailed authority |
|---|---|---|---|
| D-010 | LOCKED | The beginning-to-end story is specified through canonical scene/reveal/objective/dialogue/region/100% contracts rather than a loose outline. | `docs/02_STORY_BIBLE.md`, `docs/story/`, `docs/12_100_PERCENT_ROUTE.md` |
| D-011 | LOCKED | Every major normal-world location must be worth visiting before anything bad happens there. Ordinary work, social texture, useful places, and reasons to care precede catastrophe/recontextualization. | `docs/02_STORY_BIBLE.md`, `docs/story/regions/00_REGIONAL_STORY_INDEX.md`, `CLAUDE.md` |
| D-012 | LOCKED | Neris is not chosen by prophecy, bloodline, reincarnation, the Listener, or a sentient Cantor Key. Field operability begins with the Brindle calibration accident. | `CLAUDE.md`, canonical story contracts |
| D-013 | LOCKED | Maelor remains competent, causally responsible, understandable, and unexcused. | `CLAUDE.md`, `docs/story/06_CHARACTER_ARCS_AND_RELATIONSHIPS.md` |
| D-014 | LOCKED | Ilyra remains loving and culpable; Mercy Window is not rewritten into innocent work simply stolen by Maelor. | `CLAUDE.md`, canonical story contracts |
| D-015 | LOCKED | Tessa's old freight failure is deliberate incuriosity, not secret Stillring knowledge and not simple tax evasion. | `CLAUDE.md`, canonical story contracts |
| D-016 | LOCKED | Rusk has legitimate safety arguments and institutional culpability; he is neither a cartoon bureaucrat nor a clean reform savior. | `CLAUDE.md`, canonical story contracts |
| D-017 | LOCKED | Motion / Memory / Ending are discoveries through play and later naming, not an upfront three-item quest checklist. | `CLAUDE.md`, scene/reveal/objective ledgers |
| D-018 | LOCKED | There is one valid canonical ending. Optional completion changes preparedness, consequences, specificity, and credits detail rather than making the non-100% ending invalid. | `CLAUDE.md`, `docs/10_COMPLETION_MODEL.md`, `docs/12_100_PERCENT_ROUTE.md` |
| D-019 | LOCKED | The world changes while Neris is elsewhere; NPCs and settlements are not frozen waiting for the player. | `CLAUDE.md`, `docs/story/12_WORLD_PULSE_LEDGER.md` |
| D-020 | LOCKED | Side interactions do not all restate the central thesis or require extrinsic rewards; ordinary life-bearing material may exist because the world should feel lived in. | `CLAUDE.md`, `docs/story/17_SIDE_INTERACTION_REBALANCE.md` |

---

## Inspiration / Zelda lineage

| ID | Status | Decision | Detailed authority |
|---|---|---|---|
| D-030 | LOCKED | Zelda is studied at the level of design problems and principles, not copied expression, assets, maps, dialogue, music, code, or exact mechanics. | `docs/05_IP_GUARDRAILS.md` |
| D-031 | LOCKED | Ocarina of Time is a root reference, **not the 2026 control ceiling**. Later Zelda improvements are part of the reference lineage. Obsolete hardware compromises are not sacred. | `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md` |
| D-032 | LOCKED | Modern exploration uses a freely controllable camera; recenter is convenience rather than replacement for camera ownership. Lock-on deliberately changes camera grammar. Exact camera behavior remains Issue #2 authority. | `docs/01_GAME_VISION.md`, `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md`, Issue #2 |
| D-033 | LOCKED | World affordances should be honest: if geometry/art makes an action look reasonably possible, gameplay should either support it or clearly communicate the exception. | `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md` |
| D-034 | LOCKED | Stillring keeps authored traversal progression. It is not assuming universal climb-everything traversal; new verbs should recontextualize remembered spaces. | `docs/01_GAME_VISION.md`, `docs/09_STILLRING_PROGRESSION_BLUEPRINT.md`, `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md` |
| D-035 | LOCKED | Target-lock readability includes encounter behavior: enemy aggression and combat composition must respect what the player/camera can reasonably read. | `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md`, future combat specification |

---

## Gate 1 player-control status

`docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` is the detailed implementation-facing authority for the rows below. This register intentionally summarizes rather than re-specifies exact movement mechanics.

| ID | Status | Decision | Detailed authority |
|---|---|---|---|
| D-040 | LOCKED | Analog low-speed through full-speed control remains useful even with Sprint. Ordinary stairs/small steps/minor terrain are handled automatically. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`, Issue #1 |
| D-041 | LOCKED | Neris has an always-available modest deliberate jump. Its semantic arc/air-control rules are locked; exact numeric arc/height/influence remain Gate 1 tuning. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`, Issue #1 |
| D-042 | LOCKED | Neris has sustained Sprint from the beginning for faster ground travel. Sprint is separate from the eventual combat evade. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`, Issue #1 |
| D-043 | LOCKED | Ordinary Sprint has no stamina/resource cost and may be maintained indefinitely during normal traversal. Future combat/special-traversal resources may not silently throttle ordinary Sprint. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`, Issue #1 |
| D-044 | LOCKED | Obviously low obstacles use an intent-based authored mantle/scramble response rather than waist-high-wall friction or universal parkour. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`, Issue #1 |
| D-045 | HISTORICAL / SUPERSEDED | This row originally tracked the unresolved traversal bundle. Those questions were subsequently resolved one at a time; the current authority is `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` and the later D-049* rows below. | Issue #1, `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` |
| D-046 | LOCKED | Gate 1 human target: within roughly five minutes, ordinary movement should stop being something the player consciously fights. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`, `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md`, `ROADMAP.md` |
| D-047 | LOCKED | Major cliffs/meaningful height gates remain authored traversal problems solved by route, authored structure, tool, or later capability rather than baseline jump/mantle/free climbing. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` |
| D-048 | LOCKED | Sprint supports Hold and Toggle. Hold is default; Toggle is a controls/accessibility preference without changing Sprint gameplay rules. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` |
| D-049 | LOCKED | Sprint remains highly steerable on ordinary curves. Hard reversals briefly shed momentum and use a quick planted redirect/re-acceleration rather than an instant full-speed flip or vehicle-like arc. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` |
| D-049A | LOCKED | Sprint→jump preserves existing horizontal Sprint momentum, adds no bonus speed, and landing resumes requested Sprint when no higher-priority state overrides it. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` |
| D-049B | LOCKED | Sprint→target-lock ends exploration Sprint without hard-zeroing velocity; a short natural deceleration/pivot settles into precise target-relative locomotion. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` |
| D-049C | LOCKED | Low-obstacle mantle/scramble triggers automatically from clear movement/jump intent when geometry/path/clearance are valid; passing nearby/parallel never triggers it. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` |
| D-049D | LOCKED | Mantle scope is body-relative: knee→waist fluent; waist→lower chest deliberate/direct; shoulder-height+ not baseline auto-mantle. Exact dimensions/angles remain tuning tied to Neris. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` |
| D-049E | LOCKED | Clear reachable ledge attempts may auto-catch without a grab button; incidental/sideways/implausible rescue cases do not. Catch always enters a real hang first. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` |
| D-049F | LOCKED | Neutral hang stays hanging; toward/up requests pull-up with no separate climb button; only a valid clear standable top completes. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` |
| D-049G | LOCKED | Hang shimmy is limited to the same continuous handhold; no corner wrapping, gaps, transfers, lateral jumps, or vertical handhold climbing. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` |
| D-049H | LOCKED | Ledge release requires explicit Drop/Release. Analog down/away/diagonal/drift never releases; the explicit press acts promptly and remains remappable. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` |
| D-049I | LOCKED | Neris has no baseline universal/free climbing. Broader climbing exists only through explicit authored structures/tools/later capabilities with consistent visible world language. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` |
| D-049J | LOCKED | Authored ladder traversal is player-driven: up/down climb, neutral holds, camera remains player-controlled; entry does not auto-complete the climb. Mount/end-exit/release details are also fully specified in `docs/20`. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` |
| D-049K | LOCKED | The remaining baseline traversal grammar is resolved: deliberate-intent ladder mount + safe directional end exits + explicit release; competent surface swimming with no stamina/breath tax and no baseline free dive; no generic baseline crouch; authored slope scramble/slide bands; proportional fall consequences; predictable jump/air-control/coyote/buffer semantics; and interaction-while-moving continuity. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` |
| D-049L | LOCKED | Future traversal tools/capabilities may override movement only through explicit authored affordances and complete state contracts; ownership/equipping never passively universalizes movement or creates state-churn exploits. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` |
| D-049M | LOCKED | Movement input uses radial dead-zone semantics, drift protection, normalized digital diagonals, continuous analog careful→run strength, explicit-request Sprint upper band with hysteresis, and responsive speed-dependent acceleration/deceleration/turning. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` |
| D-049N | LOCKED | Target-lock locomotion is target-relative with player-owned spacing: forward/back radial movement, left/right strafe/orbit, no auto-orbit/distance autopilot, no exploration Sprint, and Jump remains Jump rather than a hidden contextual evade. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` |
| D-049O | LOCKED | Locomotion accessibility includes remapping, Hold/Toggle Sprint, configurable movement dead zones/outer saturation, no mashing/QTE locomotion, and a Digital Precision option for digital input. These change input ergonomics, not authored traversal eligibility. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` |
| D-049P | LOCKED | Gate 1 locomotion uses a canonical representative five-minute **per input profile** human feel test with hard semantic-fail conditions. Human feel may reject locomotion even when automated checks pass, and the test is a regression gate after material movement/traversal/input/animation/route changes. | `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` |
| D-049Q | PENDING OWNER REVIEW | Final owner acceptance of the reconciled Gate 1 locomotion package remains pending. This does **not** reopen the individually locked locomotion rules above; Issue #1 remains open until the owner completes the package review. | Issue #1, `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` |

---

## Production / source-of-truth workflow

| ID | Status | Decision | Detailed authority |
|---|---|---|---|
| D-050 | LOCKED | Permanent production pipeline: **CANON → PRODUCTION → IMPLEMENTATION → VERIFICATION → PLAY**. | `docs/15_CANON_TO_PLAY_PIPELINE.md` |
| D-051 | LOCKED | Chats, prompts, agent sessions, and remembered model context are disposable. The repository owns durable project truth. | `CLAUDE.md`, `docs/15_CANON_TO_PLAY_PIPELINE.md` |
| D-052 | LOCKED | Work backward from the fictional finished game: canon specifies what exists, production contracts turn it into playable slices, implementation does not invent missing story/progression/reward policy. | `docs/15_CANON_TO_PLAY_PIPELINE.md` |
| D-053 | LOCKED | Human play is authoritative for fun, feel, pacing, clarity, emotion, atmosphere, and whether a location feels alive. Automated QA may gather evidence but may not declare those qualities successful. | `docs/15_CANON_TO_PLAY_PIPELINE.md`, `docs/16_DEVELOPER_TOOLING_AND_MACHINE_QA.md` |
| D-054 | LOCKED | Human playtest observation classes include `BUG`, `BORING`, `CONFUSING`, `GOOD`, `GREAT`, and `DON'T TOUCH THIS`; successful accidents can be protected rather than normalized away. | `docs/15_CANON_TO_PLAY_PIPELINE.md` |
| D-055 | LOCKED | Developer tooling is production infrastructure and must grow alongside the game instead of being deferred until content becomes expensive to replay. | `docs/16_DEVELOPER_TOOLING_AND_MACHINE_QA.md`, `ROADMAP.md` |
| D-056 | LOCKED | Important state-heavy scenarios use named, version-controlled test presets rather than undocumented magic saves or arbitrary flag mutation. | `docs/16_DEVELOPER_TOOLING_AND_MACHINE_QA.md` |
| D-057 | LOCKED | Feature creep receives its full integration cost: UI, save, accessibility, controller, tests, balance, content, regression, docs, binary assets, and maintenance. “Claude can code it quickly” is not enough. | `docs/15_CANON_TO_PLAY_PIPELINE.md`, `docs/07_INITIAL_BACKLOG.md` |

---

## Engine / implementation authority

| ID | Status | Decision | Detailed authority |
|---|---|---|---|
| D-060 | HISTORICAL / SUPERSEDED | Godot 4.7.2 was the initial pre-Gate-1 engine baseline. It was replaced before gameplay implementation; only a skeletal project stub existed. | `docs/08_RESEARCH_NOTES.md` |
| D-061 | LOCKED | Production engine is **Unreal Engine 5.8**. | `README.md`, `ROADMAP.md`, `docs/04_TECHNICAL_DIRECTION.md` |
| D-062 | LOCKED | Claude is the primary implementation agent and may handle the implementation workflow end to end, subject to repository authority and human play gates. | `CLAUDE.md`, `docs/03_PRODUCTION_WORKFLOW.md` |
| D-063 | LOCKED | Authoritative gameplay/state is C++ first. Blueprints are thin presentation/assembly, designer references, cinematic/animation wiring, or deliberately disposable prototypes. | `CLAUDE.md`, `docs/04_TECHNICAL_DIRECTION.md` |
| D-064 | LOCKED | Unreal executes the game; repository contracts define what the game is supposed to do. Binary editor assets must not become secret narrative/progression authority. | `CLAUDE.md`, `docs/04_TECHNICAL_DIRECTION.md`, `docs/15_CANON_TO_PLAY_PIPELINE.md` |
| D-065 | LOCKED | Unreal heavyweight systems are opt-in rather than cargo-cult defaults. GAS, World Partition, Runtime Data Layers, Nanite, Lumen, MetaHuman, PCG, Mass, etc. require demonstrated project value. | `CLAUDE.md`, `docs/04_TECHNICAL_DIRECTION.md`, `docs/07_INITIAL_BACKLOG.md` |
| D-066 | LOCKED | Hush/world representation must compare credible Unreal approaches before architecture lock; Data Layers/presentation never become semantic quest/world-state authority. | `ROADMAP.md`, `docs/04_TECHNICAL_DIRECTION.md`, `docs/07_INITIAL_BACKLOG.md` |
| D-067 | LOCKED | Unreal `.uasset` / `.umap` binaries use explicit LFS/evidence discipline; opaque editor state receives more verification, not less. | `.gitattributes`, `CLAUDE.md`, `docs/03_PRODUCTION_WORKFLOW.md`, `docs/04_TECHNICAL_DIRECTION.md` |

---

## AI / runtime boundary

| ID | Status | Decision | Detailed authority |
|---|---|---|---|
| D-070 | LOCKED | Stillring does **not** ship an AI gimmick, model service, autonomous agent, API key, or player-funded token/API dependency. | `CLAUDE.md`, `docs/16_DEVELOPER_TOOLING_AND_MACHINE_QA.md`, `ROADMAP.md` |
| D-071 | LOCKED | Claude and machine assistance are development tools only. Offline/local agents may use deterministic developer interfaces for QA, but retail gameplay never depends on them. | `CLAUDE.md`, `docs/16_DEVELOPER_TOOLING_AND_MACHINE_QA.md` |
| D-072 | LOCKED | Machine QA gets a narrow semantic action/state surface and is strongest at progression, save/load, completion integrity, sequence probes, combat measurements, and softlock regression. | `docs/16_DEVELOPER_TOOLING_AND_MACHINE_QA.md` |

---

## Owner-review / conversation capture protocol

| ID | Status | Decision | Detailed authority |
|---|---|---|---|
| D-080 | LOCKED | High-impact player-feel choices are walked through with the owner **one meaningful decision at a time** rather than hidden inside a large implementation dump. A specifically delegated bounded workstream may proceed without repeated pauses when the owner explicitly grants that authority, but final review requirements remain binding. | `docs/03_PRODUCTION_WORKFLOW.md`, Issues #1/#2 and later feel-spec issues |
| D-081 | LOCKED | A conversational suggestion does not become permanent design merely because it was proposed. Accepted rules, prototype hypotheses, and unresolved questions are labeled distinctly. | this register, `docs/03_PRODUCTION_WORKFLOW.md` |
| D-082 | LOCKED | When a conversation settles a durable project decision, the same workstream should migrate it into the repository before proceeding far enough that future work could depend on chat memory. | `docs/03_PRODUCTION_WORKFLOW.md` |

---

# Audit coverage — 2026-09-04

The 2026-09-04 audit/reconciliation checked the major project decisions against repository authority, including:
- story red-team/final canonical scene, reveal, objective, dialogue, regional, recurrence, side-interaction, and 100% contracts;
- the “every major location is worth visiting before catastrophe” rule;
- rejection of runtime AI/API-credit gameplay gimmicks;
- the finished-game-backward production model;
- CANON → PRODUCTION → IMPLEMENTATION → VERIFICATION → PLAY;
- bounded implementation-agent authority;
- human versus machine QA boundaries;
- developer console/named test-state/machine-action requirements;
- vertical-slice-first production;
- Unreal Engine 5.8 migration;
- Claude as primary implementation agent;
- C++-first / thin-Blueprint architecture;
- Unreal binary authority and heavy-system opt-in rules;
- modern Zelda design-lineage conclusions for movement/camera/traversal;
- the complete Gate 1 locomotion semantic package and canonical five-minute human feel gate in `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`;
- the owner-review/conversation-to-repository capture protocol.

At this reconciliation boundary, **locomotion semantics no longer depend on chat memory or stale unresolved lists**. The only remaining Issue #1 owner item is final review/acceptance of the reconciled package. Camera remains a separate Issue #2 workstream.

---

# Maintenance rule

Before relying on remembered conversation context for a durable project choice:
1. search this register and the linked authority files;
2. if the decision is absent but has actually been settled, update the appropriate authority file and this register;
3. if it is still unresolved, mark it **PENDING OWNER REVIEW** rather than guessing;
4. never create a second contradictory “patch document” instead of updating the true authority.

**The project should remain reconstructable from the repository even if every chat transcript disappears.**
