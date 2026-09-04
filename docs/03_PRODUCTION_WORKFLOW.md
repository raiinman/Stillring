# 03 — Production Workflow

## Why this workflow exists

A game is not a screenplay with code attached. It is a coupled production of:

- interaction design,
- software systems,
- level design,
- narrative,
- 3D art,
- animation,
- UI/UX,
- audio,
- tools/pipeline,
- testing,
- performance,
- packaging/release.

Changes in one discipline can invalidate work in several others. The workflow therefore reduces uncertainty in the cheapest order possible.

Project Stillring uses Unreal Engine 5.8 with Claude as the primary implementation agent. Engine/editor convenience does not replace the source-of-truth and evidence rules in this workflow.

---

# Phase 0 — Charter / legal cleanliness

Deliver:
- project pitch,
- audience,
- scope boundaries,
- original-IP firewall,
- working title policy,
- repository rules.

Questions to answer:
- What exact feeling are we trying to create?
- What are we deliberately not making?
- What would make us cancel or radically rescope?

Do not produce final-scale art or levels here.

---

# Phase 1 — Pre-production

Deliver:
- game pillars,
- complete story spine,
- mechanic inventory,
- region/dungeon matrix,
- reference moodboards using lawful reference material,
- initial technical architecture,
- input map,
- save-state model draft,
- target hardware,
- accessibility baseline.

### Risk list

Rank risks by **unknown × cost**.

For Project Stillring, the major early risks are:

1. third-person camera quality,
2. lock-on combat feel,
3. Hush/Waking dual-state level architecture,
4. content-production speed,
5. retro visual style remaining readable rather than merely ugly,
6. save-state complexity across changing world layers,
7. AI-generated coding drift creating inconsistent architecture,
8. Unreal binary/editor asset state drifting away from repository authority.

The next phase attacks these risks directly.

---

# Phase 2 — Technical prototypes

Use gray boxes and placeholder audio.

Prototype separately:

## A. Locomotion + camera room
- slopes,
- stairs,
- narrow hallway,
- low ceiling,
- wall collision,
- target lock,
- multiple enemies.

## B. Combat arena
- attack commitment,
- guard,
- evade,
- hit reaction,
- target switching,
- enemy tells,
- death/reset.

## C. Tool laboratory
- Anchor Line interaction,
- Cantor Key resonance,
- one environmental mechanism,
- one combat use.

## D. Hush laboratory
- Waking/Hush world relationship,
- persistent object IDs,
- state changes,
- transition time,
- save/reload,
- at least two credible Unreal representation approaches before architecture lock.

Prototype authoritative gameplay/state in C++ unless an issue explicitly authorizes a disposable Blueprint-only experiment.

Do not merge a prototype into production simply because it works. Rewrite ugly experimental code/Blueprints when the mechanic is proven.

---

# Phase 3 — Vertical slice design

Choose one slice that crosses disciplines.

Project Stillring slice:

**Brindle outskirts → Rootmere trail → compact Root Cathedral → Mawhart.**

The slice must include representative:
- gameplay,
- art,
- lighting,
- animation,
- sound,
- dialogue,
- UI,
- save/load,
- controller input,
- performance,
- build/package pipeline.

Why: a vertical slice tests the **pipeline**, not merely the idea.

---

# Phase 4 — Vertical slice production

Work in weekly issue-sized increments.

Recommended ordering:

1. graybox route,
2. player movement/camera,
3. enemies,
4. core combat,
5. dungeon mechanism,
6. tool unlock,
7. boss prototype,
8. save/state,
9. dialogue/cinematic plumbing,
10. first art pass,
11. audio pass,
12. lighting/fog/composition,
13. accessibility/options,
14. controller QA,
15. external playtest,
16. fix critical observations,
17. production-cost review.

### Vertical slice greenlight questions

- Is basic traversal pleasant?
- Is the camera trustworthy?
- Do players understand enemy tells?
- Does the dungeon teach then remix its central mechanic?
- Does the boss test mastery?
- Can an artist/content author add a room without programmer surgery?
- Can Claude implement and verify systemic changes without depending on opaque Blueprint graphs?
- Can a new build be made reproducibly?
- Can a saved game survive content iteration?
- Does a screenshot look like *our* game rather than generic Unreal defaults?
- How long did one minute of finished gameplay take to build?

If the cost curve is absurd, cut scope now.

---

# Phase 5 — Production architecture lock

Only after vertical-slice approval:

- normalize Unreal project/folder/module structure,
- stabilize save schema,
- stabilize content IDs,
- build dialogue/cutscene authoring workflow,
- build enemy composition pattern,
- build boss state-machine conventions,
- harden debug tooling,
- harden Automation/Functional Test coverage,
- establish LFS/binary-asset patterns,
- create reusable region template/pattern,
- document import/export/package settings,
- document binary-asset authority/evidence conventions.

This is where prototype hacks become maintainable systems.

---

# Phase 6 — Full production in content pods

Do not make all overworlds, then all dungeons, then all bosses.

Finish one **region pod** at a time.

A region pod contains:

- traversal route,
- regional landmarking,
- settlement/NPC layer,
- enemies,
- side content,
- major dungeon,
- region boss,
- new tool/mechanic,
- story beat,
- music/ambience,
- secrets,
- performance pass,
- regression checklist.

Advantages:
- the game becomes progressively playable,
- later regions benefit from lessons learned earlier,
- unfinished systems cannot hide behind mountains of art assets.

---

# Phase 7 — Internal playtest cadence

Every playable milestone gets three kinds of testing:

## Developer test
Does the feature technically work?

## Fresh-player test
Can someone understand it without explanation?

## Regression test
Did the new feature break older content?

Record:
- where the tester looked,
- where they stopped,
- what they misunderstood,
- deaths/retries,
- navigation errors,
- whether they used the intended mechanic,
- direct quotes only as secondary evidence.

Do not “explain away” failed onboarding during the test.

---

# Phase 8 — Alpha

Alpha means **feature complete and playable start to finish**.

Allowed:
- placeholders,
- rough animation,
- incomplete polish,
- balance problems,
- known bugs.

Not allowed:
- missing core mechanics,
- missing mandatory story chapters,
- entire dungeons represented by TODOs.

After alpha, foundational feature additions require explicit approval.

---

# Phase 9 — Beta

Beta means **content complete**.

No new regions.
No new major tools.
No surprise crafting system.
No “wouldn't it be cool if...” mechanics.

Work categories:
- blockers,
- crashes,
- softlocks,
- save corruption,
- quest-state bugs,
- combat balance,
- camera failures,
- performance,
- accessibility,
- art/audio polish,
- text editing,
- sequence breaks,
- controller edge cases.

---

# Phase 10 — Release candidate

A release candidate is a build we are willing to ship unchanged if no blocking issues are found.

Checklist:
- clean machine install,
- first-run configuration,
- all supported controllers,
- save path and permissions,
- corrupt-save handling,
- version displayed,
- credits,
- third-party licenses,
- original-IP/legal review,
- performance targets,
- long-session soak,
- final ending/credits verification,
- package reproducibility,
- release build proven free of development-only AI/debug dependencies,
- repository tag and archived build artifacts.

---

# Phase 11 — Launch / operations

First patch window:
- crashers,
- progression blockers,
- severe hardware compatibility,
- save issues.

Avoid balance thrashing from the loudest first-day comments.

After stabilization, conduct a postmortem:
- what took longer than expected,
- which tools saved time,
- which architecture hurt,
- which content was cut,
- what players actually valued,
- what should never be repeated.

---

# GitHub / Claude workflow

## One issue = one outcome

Every implementation issue should contain:
- player-facing goal,
- scope,
- acceptance criteria,
- non-goals,
- test steps,
- affected milestone.

## Branching

Suggested:
- `main` — always known-good,
- `feat/<issue>-short-name`,
- `fix/<issue>-short-name`,
- `docs/<issue>-short-name`.

## Claude cycle

Claude should:

1. read `CLAUDE.md`,
2. read the issue,
3. inspect existing C++/Unreal architecture and relevant binary-asset context,
4. state assumptions in the PR description,
5. implement the smallest complete change,
6. run reproducible validation,
7. update docs/contracts when behavior changes,
8. enumerate created/modified Unreal binary assets,
9. open PR,
10. report limitations honestly.

Claude may handle the complete implementation workflow, but it does not get authority to redefine canon or waive human playtest gates.

## Merge gate

Do not merge because “the code looks plausible” or because Unreal Editor saved an asset successfully.

Require evidence appropriate to the change:
- C++ build/compile evidence,
- Automation/Functional Tests where applicable,
- reproducible manual/editor steps,
- screenshots/video for visual behavior,
- explicit list of modified `.uasset`/`.umap` files,
- save/load test for stateful features,
- frame-time evidence for performance-sensitive changes.

Binary asset changes that cannot be meaningfully diffed require **more evidence**, not less.

## Scope control

If a task reveals a new requirement:
- finish the current issue if still valid,
- open/record a follow-up,
- do not secretly fold a second system into the first PR.

This protects the project from Claude-driven architecture drift and Unreal-editor convenience creep.