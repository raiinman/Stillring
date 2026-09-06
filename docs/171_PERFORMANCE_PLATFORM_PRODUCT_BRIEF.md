# 171 — Performance / Platform Product Brief

**Status:** ACTIVE / PRODUCT-BOUNDARY AUTHORITY / DOCUMENTATION-ONLY  
**Updated:** 2026-09-06  
**Parent program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Decision rights:** `docs/170_STUDIO_DECISION_RIGHTS_MATRIX.md`  
**Product sources:** `docs/00_PROJECT_CHARTER.md`, `docs/01_GAME_VISION.md`, `ROADMAP.md`, `docs/04_TECHNICAL_DIRECTION.md`, `CLAUDE.md`  
**Runtime evidence:** `docs/142_RUNTIME_EVIDENCE_LEDGER_BASELINE.md`  
**Unknowns:** `docs/144_UNANSWERED_QUESTION_REGISTER.md`  
**Boundary:** this brief defines current product assumptions, explicit owner decisions, and future evidence gates. It does not claim a target hardware profile, framerate, resolution, platform certification result, runtime performance, or packaged game exists.

---

# 1. Purpose

Stillring cannot be quoted or performance-planned responsibly if a studio silently assumes:

- a console launch;
- a specific PC baseline;
- 30/60/120 fps as already promised;
- 1080p/1440p/4K as already promised;
- Lumen/Nanite/World Partition as required;
- online services as required;
- a final commercial title;
- platform certification work that has never been authorized.

This brief separates what is already product authority from what genuinely remains open.

The governing rule is:

> **Do not turn an undecided product target into an implementation default, and do not turn missing runtime evidence into a fake specification.**

---

# 2. Current product definition

| Product dimension | Current status | Authority |
|---|---|---|
| Core mode | **LOCKED** | single-player authored action-adventure |
| Base-game multiplayer | **PROHIBITED / OUT OF SCOPE** | no multiplayer during base-game production |
| Live service | **PROHIBITED / OUT OF SCOPE** | no live service |
| Procedural story | **PROHIBITED / OUT OF SCOPE** | authored story/world only |
| Loot-rarity treadmill | **PROHIBITED / OUT OF SCOPE** | no rarity treadmill |
| First production platform direction | **LOCKED** | PC first |
| Controller design priority | **LOCKED** | controller first |
| Keyboard/mouse | **LOCKED SUPPORT REQUIREMENT** | first-class supported input; no hard-coded physical-key gameplay rules |
| First-playthrough target | **LOCKED** | 20–30 hours |
| Major dungeon-scale spaces | **LOCKED TARGET** | 8–10 including finale |
| World structure | **LOCKED** | interconnected authored overworld with regional hubs; not checklist-open-world production |
| Engine | **LOCKED** | Unreal Engine 5.8 production baseline |
| Gameplay/state implementation direction | **LOCKED** | C++ first, thin Blueprint presentation/assembly |
| Retail AI/API dependency | **PROHIBITED** | final executable must not require model APIs, API keys, autonomous development agents, or player-funded AI usage |
| Commercial title | **TBD OWNER / LATER CLEARANCE** | `Project Stillring` is internal codename |

---

# 3. PC-first does not mean “every PC assumption is settled”

`PC first` locks production order.

It does not yet lock:
- minimum/recommended hardware;
- CPU/GPU generation or performance tier;
- system RAM target;
- VRAM target;
- Windows-version support matrix;
- Steam/Epic/GOG/storefront commitment;
- handheld-PC support commitment;
- ultrawide support promise;
- HDR promise;
- ray-tracing promise;
- frame-generation/upscaler promise;
- exact resolution/framerate targets.

A studio must not infer those from common industry defaults.

They become product authority only after the appropriate product/evidence gate.

---

# 4. Launch-platform scope

## Current authority

**PC first.**

No current authority commits the project to PlayStation, Xbox, Nintendo hardware, macOS, Linux, Steam Deck certification, or another platform.

## Classification

**TBD OWNER.**

## Decision gate

The owner must select launch-platform scope before:
- platform-specific certification planning;
- platform SDK integration;
- console memory/performance budgets are treated as requirements;
- platform-specific save/user/account behavior is made authoritative;
- platform-specific UI glyph/certification work is staffed as final production;
- porting scope is represented as committed schedule/budget.

## What may proceed before the decision

Documentation and later PC-first implementation may proceed without assuming additional launch platforms.

Cross-platform-hostile choices should still be avoided when a neutral solution is cheap and consistent with existing authority.

That does not create a hidden console commitment.

---

# 5. Target-PC hardware baseline

## Current authority

A target PC is required before Gate 5 can make objective performance-exit claims.

No approved target hardware specification exists yet.

The available development machine may later be used to gather development evidence, but it must not silently become the target product baseline.

## Classification

**TBD OWNER, informed by implementation/performance research.**

## Not a Gate 1 blocker

Gate 1 may later bootstrap and run on available development hardware when implementation is authorized.

Every performance capture before target selection must record the actual evidence machine and must be labeled development evidence, not shipping-target proof.

## Required decision package before owner selection

The future proposal should include at minimum:
- intended market/performance tier options;
- representative CPU/GPU/RAM/VRAM configurations;
- expected visual-quality implications;
- expected content/streaming implications;
- expected optimization burden;
- impact on Hush paired-state production;
- impact on crowd/NPC density where relevant;
- impact on VFX/lighting/scalability;
- likely support burden;
- measured representative prototype evidence rather than vendor-spec arithmetic alone.

The owner should choose a product target from evidence, not from an arbitrary enthusiast PC or a lowest-common-denominator guess.

---

# 6. Resolution and framerate matrix

## Current status

**RUNTIME-GATED / PRODUCT-CONFIRMED LATER.**

The repository does not currently promise:
- 30 fps;
- 60 fps;
- 120 fps;
- 1080p;
- 1440p;
- 4K;
- internal 320×240 or 640×480 as a mandatory production renderer;
- a specific upscaler or frame-generation technology.

`docs/01_GAME_VISION.md` permits low internal rendering experiments as a visual-direction option, explicitly subordinate to UI readability/accessibility rather than dogma.

## Why paper cannot close this honestly

Final targets depend on:
- selected target hardware/platform scope;
- representative art materials/lighting;
- real character/animation burden;
- VFX density;
- representative Hush paired-state burden;
- region/world streaming behavior;
- UI readability;
- accessibility;
- final renderer/scalability choices.

## Future evaluation

Use at least:
- representative Gate 5-quality character;
- representative environment kit/hero asset;
- representative VFX;
- representative UI;
- representative combat/encounter scene;
- representative Hush transition/paired area where architecture exists;
- representative streaming/travel case.

Capture:
- frame time rather than only average fps;
- CPU/GPU split where available;
- memory/VRAM;
- hitches/stalls;
- loading/streaming behavior;
- visual-quality changes by scalability tier;
- UI readability at each evaluated presentation mode.

Promote the winning target only after the target-PC/product baseline is selected and the evidence is reviewed.

---

# 7. Rendering-feature policy

Unreal features are options, not product promises.

| Feature / approach | Current status | Rule |
|---|---|---|
| Lumen | **RUNTIME-GATED / OPT-IN** | use only if visual benefit and target performance justify it; do not inherit generic Unreal lighting by default |
| Nanite | **RUNTIME-GATED / OPT-IN** | use only where asset/production/performance evidence justifies it; visual doctrine does not require high-poly assets |
| World Partition | **RUNTIME-GATED BY USE CASE** | not automatic for authored regions; Hush architecture requires explicit comparison |
| Runtime Data Layers | **PRESENTATION CANDIDATE ONLY** | never canonical world/quest/Hush semantic truth |
| MetaHuman | **NOT DEFAULT PIPELINE** | not assumed for Stillring characters |
| PCG | **NOT A SUBSTITUTE FOR AUTHORED WORLD DESIGN** | may only solve scoped production problems without replacing authored intent |
| Gameplay Ability System | **NOT DEFAULT DEPENDENCY** | adopt only if demonstrated to simplify required gameplay architecture |
| Upscalers / frame generation | **UNSELECTED** | may be evaluated later; cannot replace acceptable base frame pacing on target assumptions unless future product authority explicitly allows that model |

---

# 8. Performance philosophy

Performance is a player-experience and production constraint, not a final polish task.

Stillring's production rules therefore require:
- stable and explainable frame pacing;
- predictable input/camera response;
- no gameplay-critical cue lost to aggressive scalability;
- Hush transitions that remain legible and reliable under representative production burden;
- no asset/lighting/VFX technique accepted merely because the editor can display it;
- no “cinematic” visual effect allowed to make combat/traversal/puzzle readability materially worse;
- accessibility settings such as Reduced Effects to preserve semantics rather than disabling required information.

Exact numeric budgets remain runtime-gated until product targets and representative content exist.

---

# 9. Loading and streaming

## Locked experience intent

The authored world should feel coherent and navigable rather than like a collection of unrelated menu-selected levels.

Line Skiff later creates higher-speed route traversal and therefore raises streaming/collision demands.

Hush may require paired representations and fast transitions.

## Current technical status

No production streaming architecture is yet proven.

World Partition is not automatically required.

## Classification

**RUNTIME-GATED.**

Future evaluation must include:
- ordinary on-foot regional traversal;
- dense settlement/interior transitions;
- Hush paired-state transition/reconstruction;
- Line Skiff representative high-speed routes;
- checkpoint/save reload;
- return visits after world-state changes.

A loading strategy passes only if it preserves semantic state, traversal reliability, camera/collision correctness and acceptable presentation on the selected product target.

---

# 10. Memory and content-residency policy

No final RAM/VRAM budget is currently authoritative.

The production requirement is instead:
- art manifests must classify reuse/uniqueness and Hush burden;
- content must not assume every Waking/Hush variation is permanently resident;
- named characters/enemies/bosses must remain readable under future scalable production constraints;
- streaming architecture must preserve semantic IDs and source-owned facts independently of loaded Actors;
- asset production must support future profiling without requiring creative identity to be rebuilt from scratch.

Final memory/VRAM budgets are **RUNTIME-GATED** by target hardware and representative production content.

---

# 11. Input-device product assumptions

## Controller

**LOCKED PRIMARY DESIGN TARGET.**

This means:
- gameplay must feel complete on controller;
- UI navigation must be complete on controller;
- all major actions require named remappable actions rather than hard-coded keys;
- future glyph presentation must identify device context without changing semantic action names.

## Keyboard and mouse

**LOCKED FIRST-CLASS SUPPORT.**

This means:
- gameplay parity inside intended control semantics;
- menu pointer/focus behavior will be documented in the UI/UX Production Specification;
- no design may assume analog-only input when a documented keyboard accommodation is required;
- camera/mouse behavior must be validated separately from controller stick behavior.

## Additional devices

Touch, gyro, handheld-specific controls, adaptive trigger features, and platform-specific controller features are not currently product commitments unless a later platform/input authority adds them.

---

# 12. Online, backend and account assumptions

Stillring's base product is not a live service.

The shipped game must not depend on:
- project-owned always-online gameplay services;
- an AI/model API;
- development agents;
- remote debug control;
- player-funded inference;
- online procedural story generation.

Later platform/store services such as achievements, cloud save, crash reporting, or platform account integration may be evaluated if the selected distribution/platform requires or benefits from them.

If adopted:
- they remain downstream integrations;
- they may not become canonical gameplay-state owners;
- campaign play must not be redesigned around live-service assumptions;
- local save semantics remain governed by Save/World-State authority.

Exact distribution/store service scope is not yet locked.

---

# 13. Save/product platform boundary

Save semantics are already strongly documented.

Platform-specific storage APIs are not.

The distinction is:

## LOCKED
- semantic stable IDs;
- schema/version/migration/integrity/recovery rules;
- source-system ownership;
- checkpoint/retry semantics;
- no Actor/path identity as persistence truth.

## STUDIO / PLATFORM IMPLEMENTATION
- exact file API;
- user-storage container;
- atomic-write mechanics;
- cloud synchronization integration if later selected;
- platform-specific quota/error handling.

## RUNTIME / PLATFORM GATED
- actual corruption/recovery behavior;
- file-system edge cases;
- cloud conflict handling if cloud support exists;
- platform suspend/resume behavior where applicable.

---

# 14. Accessibility and platform product boundary

Accessibility is not deferred until platform selection.

Current baseline already requires:
- remappable controls;
- subtitle size/background options;
- color-independent puzzle cues;
- camera sensitivity/inversion;
- camera shake control;
- hold/toggle support where feasible and specifically required;
- no critical information conveyed only by audio;
- combat/camera/movement accommodations to be validated later.

Platform selection may add certification-specific requirements.

It may not reduce the project baseline.

---

# 15. Localization product boundary

The exact ship-language list is not yet selected.

That is not permission to author a localization-hostile game.

Before implementation/production at scale, Stillring must preserve:
- stable text IDs;
- context metadata;
- variable/plural/gender/pronoun context where relevant;
- subtitle/caption timing data;
- UI layouts tolerant of text expansion;
- no production dialogue hardcoded inside gameplay branching logic;
- pronunciation/performance context for VO if VO is selected;
- pseudo-localization capability in the later QA/localization production package.

Language count is a later product decision.

Localization readiness is a current production requirement.

---

# 16. Commercial-title boundary

`Project Stillring` is an internal codename.

The studio may use it internally for production identifiers and documentation until a later naming transition is authorized.

It must not be represented as legally cleared public branding merely because the repository uses the name extensively.

A future commercial naming package requires:
- owner selection;
- appropriate clearance/trademark research;
- repository-wide naming migration plan where needed;
- store/marketing/UI/title-art implications;
- save/config/package identifier review where technical identifiers are affected.

This is not a blocker for current documentation or future early implementation.

---

# 17. Build-configuration product expectations

The Technical Production Bible will define exact configuration conventions.

Current product boundaries already require:
- development tools available in development/test contexts where useful;
- System IDEs clearly labeled development-only;
- shipping build exclusion or hard-disable of System IDE/developer mutation surfaces;
- no API keys or development-agent dependencies in retail;
- reproducible build/open/test entry points as implementation proceeds;
- binary Unreal assets handled through reviewable source-control/LFS discipline.

Exact package/store signing/deployment mechanics remain platform-dependent.

---

# 18. Performance evidence ladder

Performance claims must advance through explicit evidence stages.

## P0 — no runtime

Current state.

No performance claim beyond documentation intent.

## P1 — development-machine prototype evidence

Record:
- exact hardware;
- build/commit;
- map/fixture;
- settings;
- frame-time capture;
- known nonrepresentative content.

Useful for detecting obvious problems.

Not target proof.

## P2 — representative vertical-slice evidence

Representative character/environment/VFX/UI/audio/AI/Hush burden begins to matter.

Use for product-target research and scalability decisions.

## P3 — selected target-PC acceptance evidence

After owner target selection, run the defined target matrix.

This is the earliest stage where Gate 5 target-performance claims may be objectively accepted.

## P4 — full-production stress evidence

Representative worst-normal cases across regions, bosses, settlements, Skiff, Hush and finale.

## P5 — release/platform evidence

Final packaged builds, selected platforms, loading/save integrity, certification-specific performance requirements and release settings.

No earlier stage may be relabeled as a later one.

---

# 19. Future target-PC selection checklist

Before presenting target-PC options to the owner, production should be able to answer:

1. What does the representative vertical slice cost on the evidence machine?
2. Which systems are CPU-bound versus GPU-bound?
3. What is the memory/VRAM residency pattern?
4. What changes materially between visual-quality tiers?
5. What does Hush paired-state content cost?
6. What does a representative multi-enemy encounter cost?
7. What does a representative settlement cost?
8. What does Line Skiff speed do to streaming/collision/CPU pressure once available?
9. Which features are optional presentation luxuries versus identity-critical?
10. What target tier best preserves Stillring's intended quality while keeping production/optimization reasonable?

The owner should not be asked to pick a GPU model before evidence makes the choice meaningful.

---

# 20. Prohibited product assumptions

Until authority changes, the studio may not assume:
- console launch because “most games ship on console”;
- Steam-only launch because PC-first is locked;
- mandatory always-online services;
- full VO;
- a 60-fps promise;
- a 4K promise;
- Lumen/Nanite/World Partition as mandatory production architecture;
- low internal resolution as mandatory retro simulation;
- final target hardware equal to the developer's current machine;
- a commercial title is cleared;
- certification obligations for an unselected platform;
- that accessibility can be postponed until after content lock.

---

# 21. Current decision summary

| Decision | Status | Required before |
|---|---|---|
| PC first | **LOCKED** | already current |
| launch platforms beyond PC | **TBD OWNER** | platform-specific production/certification commitment |
| target-PC hardware baseline | **TBD OWNER** | objective Gate 5 target-performance acceptance |
| final resolution/framerate matrix | **RUNTIME-GATED / PRODUCT-CONFIRMED** | Gate 5 exit claim |
| renderer feature stack | **RUNTIME-GATED / STUDIO RECOMMENDATION** | production rendering lock |
| Hush representation | **RUNTIME-GATED** | broad Hush content production |
| distribution/storefront | **UNSELECTED PRODUCT/PUBLISHING DETAIL** | release/store integration commitment |
| commercial title | **TBD OWNER / LATER CLEARANCE** | public-release branding |
| localization language list | **TBD PRODUCT LATER** | localization staffing/ship scope |
| VO scope | **TBD OWNER unless later authority resolves it** | casting/recording commitment |

---

# 22. Acceptance result

At written-authority level, this brief closes the dangerous ambiguity around what `PC first` and `performance target` currently mean.

It deliberately does not fake values that require product selection or runtime proof.

Current result:

> **PASS — PRODUCT/PLATFORM BOUNDARIES ARE EXPLICIT; TARGET HARDWARE, LAUNCH-PLATFORM EXPANSION, FINAL RESOLUTION/FRAMERATE, VO SCOPE, LANGUAGE LIST AND COMMERCIAL TITLE REMAIN EXPLICITLY GATED.**

No UE5.8 implementation or performance evidence is authorized or claimed.