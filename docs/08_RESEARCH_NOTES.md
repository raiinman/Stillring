# 08 — Production Research Notes

Research dates: 2026-09-03 through 2026-09-04.

## What “developing a game” actually entails

A useful production model separates work into pre-production, production, post-production/polish, and post-release operations. Unity's production-cycle training describes pre-production as planning/prototyping/pipeline setup and the point where a design document becomes a shared source of truth; production covers creation of the interactive product and its assets; post-production emphasizes QA, testing, bug fixing and polish; operations covers the released product.

Sources:
- https://learn.unity.com/tutorial/explore-the-production-cycle?version=2022.3
- https://learn.unity.com/tutorial/the-real-time-production-cycle?version=2020.3

## Why Project Stillring uses a vertical slice

A vertical slice is a small playable portion demonstrating the major systems, features, and representative art of the whole game. This is different from a throwaway mechanic prototype: it tests whether the **production pipeline** can produce finished-feeling gameplay at a sustainable cost.

Sources:
- https://learn.unity.com/course/welcome-to-the-course/tutorial/explore-out-of-circulation?version=2022.3
- https://learn.unity.com/course/2d-roguelike-tutorial/tutorial/set-up-your-project?version=6.3
- https://unity.com/blog/how-playside-studios-built-kill-knight-visual-identity

## Why milestones are gate-based

Unity's production-planning material explicitly uses milestones such as an MVP/prototype, refinement milestones, and a final polish milestone, and recommends planning the work rather than treating all features as one undifferentiated build.

Source:
- https://learn.unity.com/tutorial/create-your-production-plan?version=2022.3

## Engine decision history

### Initial baseline — Godot 4.7.2

Godot was initially selected before technical prototyping because it offered a lightweight, open, VCS-friendly, text-heavy workflow well suited to AI-assisted coding.

That decision was **superseded before Gate 1 implementation**. The only committed engine artifact was a skeletal `project.godot` stub with no gameplay implementation, so the migration carried essentially no gameplay-code sunk cost.

The original Godot rationale is retained here as decision history rather than current direction.

Historical sources:
- https://godotengine.org/download/archive/4.7.2-stable/
- https://docs.godotengine.org/en/stable/tutorials/best_practices/version_control_systems.html

### Production baseline — Unreal Engine 5.8

On 2026-09-04, Project Stillring switched to **Unreal Engine 5.8** before Gate 1.

Epic released Unreal Engine 5.8 on 2026-06-23 and describes it as the last planned major UE5 release on the current roadmap while UE5 continues receiving bug/regression support.

Source:
- https://www.unrealengine.com/news/unreal-engine-5-8-is-now-available

## Why Unreal now fits Stillring better

Stillring's design matured from a concept into a substantial authored 20–30 hour third-person 3D action-adventure with:
- lock-on melee combat;
- multiple animated characters and bosses;
- large amounts of authored environment content;
- cinematics and dialogue;
- layered Waking/Hush states;
- before/after regional state;
- complex save/progression semantics;
- extensive developer tooling;
- machine-assisted regression needs.

At that scale, production tooling for 3D world building, animation, cinematics, editor workflows, and automated game testing outweighs Godot's advantage in text-only simplicity.

The migration does **not** authorize generic Unreal design. `docs/04_TECHNICAL_DIRECTION.md` requires a C++-first architecture, thin Blueprints, explicit binary-asset discipline, and opt-in use of heavyweight engine systems.

## Unreal world-state research

Unreal Engine 5.8's World Partition system provides automatic world data/streaming management and integrates with One File Per Actor, Data Layers, Level Instancing, and HLOD.

Source:
- https://dev.epicgames.com/documentation/en-us/unreal-engine/world-partition-in-unreal-engine

Runtime Data Layers can organize and toggle Actors at runtime and are a plausible candidate for some Waking/Hush or catastrophe presentation when using World Partition.

Source:
- https://dev.epicgames.com/documentation/unreal-engine/world-partition---data-layers-in-unreal-engine

Important Stillring conclusion:
- Data Layers are a **presentation/world-organization candidate**, not canonical quest/world-state authority.
- World Partition is **not automatically required**; Gate 4 must compare it against a simpler non-World-Partition representation if that better fits authored regions.

## Unreal automated QA research

Unreal Engine 5.8 includes an Automation Test Framework for unit/API checks, feature tests, smoke tests, content-stress tests, and screenshot comparison.

Source:
- https://dev.epicgames.com/documentation/unreal-engine/automation-test-framework-in-unreal-engine?lang=en-US

Epic's test documentation supports running tests from the editor/Session Frontend, and the project should establish command-line/reproducible automation entry points for Claude during Gate 1.

Sources:
- https://dev.epicgames.com/documentation/en-us/unreal-engine/automation-system-user-guide-in-unreal-engine
- https://dev.epicgames.com/documentation/en-us/unreal-engine/run-automation-tests-in-unreal-engine

Unreal Automation Specs provide a BDD-style C++ test form suitable for self-documenting functional/integration expectations where useful.

Source:
- https://dev.epicgames.com/documentation/unreal-engine/automation-spec-in-unreal-engine?lang=en-US

## Git and binary assets

GitHub's documentation explains that Git LFS stores pointer files in Git while large objects live in LFS storage.

Source:
- https://docs.github.com/en/repositories/working-with-files/managing-large-files/about-git-large-file-storage

Unreal's `.uasset` and `.umap` files are binary. Therefore Project Stillring deliberately separates:
- C++/config/docs/structured source data — normal Git and human/Claude-reviewable diffs;
- Unreal binary assets/maps and large source assets — Git LFS plus explicit PR evidence.

This is a central architectural constraint, not repository housekeeping.

## Zelda design-lineage research

Stillring's Zelda inspiration must be treated as a **series design lineage**, not as a frozen Ocarina of Time control specification.

Detailed project conclusions are recorded in `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md`. The research basis is summarized here.

### Ocarina of Time — simplify early 3D control problems

Nintendo's developers described early explicit jumping being replaced by auto-jump and described Z-targeting as a response to alignment, camera, combat-orientation, and multi-enemy readability problems in early 3D action.

Stillring research conclusion:
- the durable lesson is reducing unnecessary control friction and creating readable player/camera/target relationships;
- auto-jump itself is not sacred and should not be preserved just because it was effective on Nintendo 64 hardware.

Sources:
- https://iwataasks.nintendo.com/interviews/3ds/zelda-ocarina-of-time/1/1/
- https://iwataasks.nintendo.com/interviews/3ds/zelda-ocarina-of-time/1/2/
- https://iwataasks.nintendo.com/interviews/3ds/zelda-ocarina-of-time/4/4/
- https://iwataasks.nintendo.com/interviews/3ds/zelda-ocarina-of-time/0/3/

### Wind Waker — free camera ownership

Aonuma later identified **The Wind Waker** as the first Zelda to integrate a freely controllable camera and recalled how good that freedom felt.

Stillring research conclusion:
- modern free camera is the exploration baseline;
- recenter remains useful but no longer substitutes for direct camera control.

Source:
- https://iwataasks.nintendo.com/interviews/3ds/majoras-mask-3d/0/4/

### Skyward Sword — preserve movement flow

Nintendo described adding dash and allowing rapid movement up small cliffs/slopes partly to keep movement from being interrupted.

Stillring research conclusion:
- sprint/dash deserves a Gate 1 prototype;
- stamina/resource cost is a separate design question and should not be inherited automatically.

Source:
- https://iwataasks.nintendo.com/interviews/wii/zelda-skyward-sword/0/1/

### Breath of the Wild / Tears of the Kingdom — route agency and affordance honesty

Breath of the Wild expanded terrain traversal and player route choice. Tears of the Kingdom developers later articulated an especially useful principle: enable actions players reasonably believe should work, and visually communicate intentional exceptions.

Stillring research conclusion:
- world geometry should support player reasoning;
- readable affordances should be trustworthy;
- Stillring can preserve authored progression and tool-gated recontextualization without adopting universal climb-everything traversal.

Sources:
- https://www.nintendo.com/jp/topics/article/c1fb9037-03c1-11e7-9aaf-063b7ac45a6d
- https://www.nintendo.com/us/whatsnew/ask-the-developer-vol-9-the-legend-of-zelda-tears-of-the-kingdom-part-3/
- https://www.nintendo.com/us/whatsnew/ask-the-developer-vol-9-the-legend-of-zelda-tears-of-the-kingdom-part-5/

### Overall control-lineage conclusion

Stillring should feel as though the **classic authored 3D adventure philosophy kept learning through modern control and world-design expectations**, not as though a 1998 control scheme was rebuilt in Unreal.

The project-level synthesis is:

> **Simple intention, capable character, honest world.**

Exact Nintendo control values, animations, UI, camera distances, geometry, and protected expression remain outside the implementation input under `docs/05_IP_GUARDRAILS.md`.

## Claude development conclusion

Claude is the primary implementation agent, but the project is structured so Claude does not need to infer the game from opaque editor state.

The working rule is:

```text
CANON
  ↓
PRODUCTION CONTRACT
  ↓
C++ / REVIEWABLE SOURCE AUTHORITY
  ↓
UNREAL PRESENTATION + BINARY ASSETS
  ↓
AUTOMATED VERIFICATION
  ↓
HUMAN PLAY
```

Blueprint/editor convenience cannot bypass that chain.

## Production conclusion

The project follows this sequence:

```mermaid
flowchart LR
    A[Charter + IP rules] --> B[Pre-production + canon]
    B --> C[Unreal graybox prototypes]
    C --> D[Vertical slice]
    D -->|greenlight| E[Production architecture lock]
    D -->|not good/costly| B
    E --> F[Region production pods]
    F --> G[Alpha: feature complete]
    G --> H[Beta: content complete]
    H --> I[Release candidate]
    I --> J[Launch + operations]
```

The critical policy remains simple: **uncertainty gets tested before expensive content is multiplied.**
