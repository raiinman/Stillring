# 135 — Documentation Closure Program Charter

**Status:** ACTIVE / GOVERNING CLOSURE PROCESS  
**Updated:** 2026-09-05  
**Baseline main:** `f3874de569e7e791c1f34fee093539bc34970fb4`  
**Scope:** repository-wide design/documentation closure before broad UE5.8 implementation authorization

## Purpose

Stillring now has a large amount of owner-approved design authority across locomotion, camera, combat, encounter behavior, tools, Hush/world layers, save/world-state, completion, Setup/Payoff, Line Skiff traversal, story/content, and Null Meridian.

The remaining risk is no longer primarily "we have not designed enough."

The risk is:
- an implementation agent reads an older document and treats superseded shorthand as current truth;
- two systems both assume they own the same state;
- a design-complete document is mistaken for UE5.8 proof;
- stale counts or filenames become implementation constants;
- a runtime unknown is silently guessed instead of recorded;
- System IDE obligations are forgotten until systems are expensive to debug;
- onboarding requires reading more than one hundred historical documents before knowing what is current.

The Documentation Closure Program exists to remove those risks **before** broad implementation is authorized.

Core maxim:

> **Unknowns are allowed. Hidden unknowns are not. Historical documents are allowed. Unclear authority is not.**

---

# 1. Closure does not mean implementation

This program is documentation/reconciliation work.

It may:
- index existing authority;
- add precedence/supersession notes;
- repair stale references;
- identify unresolved implementation questions;
- map source ownership;
- define cross-system contracts already implied by locked design;
- document required System IDE surfaces;
- build evidence/readiness registers;
- identify exact future UE5.8 proof obligations;
- create an implementation-order recommendation for owner review.

It does **not** by itself authorize:
- broad UE5.8 gameplay implementation;
- changing locked design because implementation would be easier;
- closing runtime-dependent GitHub issues without their runtime evidence;
- declaring a prototype fun, readable, performant, accessible, or stable without human/runtime proof;
- replacing authoritative gameplay services with test-only shadow state.

Any closure discovery that genuinely requires a new owner design decision must be surfaced as an explicit unresolved question rather than silently resolved through documentation cleanup.

---

# 2. Current open-issue boundary

At program start, the only open GitHub issues are:

## Issue #4 — persistent world-state and save schema

Design authority exists in `docs/81`–`88`.

The issue remains open because its verification criterion requires a paired-layer runtime prototype that can save, exit, reload, and reproduce the intended semantic world state using stable IDs.

Documentation closure may reconcile its design acceptance criteria, but **must not close #4 until runtime verification exists**.

## Issue #5 — Gate 1 UE5.8 C++ prototype harness

This is an implementation/infrastructure issue.

It requires a real UE5.8 project, reproducible build/open flow, Enhanced Input, graybox test course, runtime readouts, Automation/smoke checks, Git LFS-safe binary asset handling, and fresh-checkout verification.

It remains open.

## Issue #58 — shared in-game System IDE framework

Detailed design authority exists in `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md` and many system-specific IDE addenda.

The issue remains open because the shared shell and first workbenches are not yet runtime-proven.

It remains open.

These open issues are not documentation defects. They are intentional implementation/runtime boundaries.

---

# 3. Program outputs

The closure program must produce, at minimum:

1. **Canonical Authority Index**
   - current governing document(s) per major system/content domain;
   - design status;
   - implementation/runtime status;
   - related open issue where applicable.

2. **Supersession Graph**
   - explicit new -> old precedence;
   - reverted/closed historical work;
   - scoped precedence instead of "newer date always wins";
   - known stale literals/reference traps.

3. **Terminology / Glossary**
   - canonical technical and fiction/system terms;
   - distinctions that implementation must preserve;
   - banned/ambiguous shorthand where dangerous.

4. **System Ownership Map**
   - authoritative state owner;
   - consumers/observers;
   - persistence owner;
   - forbidden duplication.

5. **Cross-System Contract Matrix**
   - directional dependencies among locomotion, camera, combat, encounter, tools, Hush, save, quest/world-state, Setup/Payoff, Skiff, completion, and finale systems;
   - transition/recovery rules where multiple systems meet.

6. **Unanswered-Question Register**
   - architecture blockers;
   - tuning questions;
   - content questions;
   - owner decisions;
   - prototype-required questions;
   - human-play questions.

7. **Implementation-Readiness Gap Register**
   - design exists / runtime absent;
   - dependency order;
   - proof obligations;
   - recommended vertical slices.

8. **System IDE Coverage Matrix**
   - required workbench per major system;
   - Inspect / Author-Tune / Exercise / Validate / Capture-Promote obligations;
   - current design status;
   - runtime implementation status.

9. **Runtime Evidence Ledger**
   - documentation/design evidence separated from UE5.8 evidence;
   - deterministic fixtures;
   - save/reload;
   - performance;
   - accessibility;
   - human-play acceptance.

10. **Content Traceability Matrix**
    - story beats, regions, tools, contracts, setup/payoff, completion categories, upgrades, trials, Hush states, and finale dependencies;
    - stale content references identified rather than silently inherited.

11. **Safe Onboarding / Read Order**
    - one path for engineers/agents;
    - one path for writers/content designers;
    - one path for system-specific implementation;
    - historical detail available without being required to know current truth.

12. **Final Owner Review Package**
    - concise locked-state summary;
    - unresolved decisions/unknowns;
    - implementation risks;
    - recommended UE5.8 implementation order;
    - explicit authorization boundary.

---

# 4. Planned closure phases

## Phase 1 — Authority and language

Deliver:
- this charter;
- Canonical Authority Index;
- Supersession Graph;
- Terminology / Glossary + onboarding path;
- safe direct repair of obvious stale document references where no design change is involved.

Goal:

> A new contributor can determine what is current before they implement anything.

## Phase 2 — Ownership and interfaces

Deliver:
- System Ownership Map;
- Cross-System Contract Matrix;
- System IDE Coverage Matrix;
- Runtime Evidence Ledger baseline.

Goal:

> Every major state has one owner, every consumer knows its boundary, and every system has an explicit runtime proof/workbench obligation.

## Phase 3 — Readiness and traceability

Deliver:
- Unanswered-Question Register;
- Implementation-Readiness Gap Register;
- Content Traceability Matrix;
- stale literal/reference audit;
- targeted safe fixes/addenda.

Goal:

> Implementation can distinguish architecture decisions from tuning questions and can trace player-facing content back to current authority.

## Phase 4 — Final closure / owner authorization package

Deliver:
- closure completeness audit;
- final implementation-order recommendation;
- owner-review summary;
- refreshed `NEXT_CHAT_HANDOFF.md` with exact final main SHA and authorization state.

Goal:

> The owner can make one informed decision about whether broad UE5.8 implementation may begin.

---

# 5. Authority model during closure

Documentation numbers are not themselves authority ranking.

Use scoped authority:

1. explicit owner-approved authority/addendum for the exact topic;
2. cumulative specification that incorporates the relevant locked decisions;
3. decision register/closure audit for navigation and status;
4. canonical story/content bible for unaffected narrative facts;
5. older foundation/backlog/research documents as history/context only where newer authority exists.

A later document does not automatically supersede an earlier one outside its stated scope.

If documents conflict and no explicit precedence exists:
- do not guess;
- record the conflict;
- determine whether existing owner approval resolves it;
- otherwise put it in the Unanswered-Question Register.

---

# 6. State-of-proof vocabulary

The following status terms are mandatory in closure documents.

## LOCKED DESIGN

Owner-approved behavior/data contract exists.

Does **not** imply code exists.

## DOCUMENTATION COMPLETE

The scoped documentation acceptance criteria are reconciled and current authority is identified.

Does **not** imply code exists.

## IMPLEMENTED

Relevant code/assets exist in the target UE5.8 project.

Does not by itself imply verified behavior.

## DETERMINISTICALLY VERIFIED

Machine-repeatable fixture/test evidence exists against authoritative runtime services.

## HUMAN-PLAY VERIFIED

A human has exercised the behavior in the intended playable context and accepted feel/readability/pacing for the scoped claim.

## PRODUCTION-READY

Only use when the scoped system has the required design, implementation, deterministic verification, performance/accessibility evidence, persistence/recovery evidence where relevant, System IDE support, and human acceptance.

Never collapse these states into a single `done` flag.

---

# 7. Source-of-truth rules

Every substantial system must identify:
- its authoritative runtime owner;
- stable semantic identity for persisted/content-addressed facts;
- its save/persistence contract where relevant;
- its consumers;
- its System IDE surface;
- its deterministic fixtures;
- its human-play acceptance needs.

Forbidden patterns:
- two systems each storing their own authoritative copy of the same fact;
- actor paths/display strings/map coordinates as canonical persistence identity;
- presentation state outranking semantic state;
- System IDE-only shadow state;
- hard-coded completion counts from stale content docs;
- Blueprint callback order as story/persistence authority;
- scene order as the only representation of a semantic prerequisite.

---

# 8. Unknown classification

Every unresolved item must be classified.

## A — architecture blocker

Must be resolved before affected implementation starts.

## B — implementation choice within locked design

Engineer may choose/recommend, but choice must preserve authority and be documented.

## C — tuning / feel

Must be prototyped and human-tested; documentation should define boundaries, not fake final numbers.

## D — content production detail

Can be authored later within locked systemic/narrative constraints.

## E — runtime evidence requirement

Design answer exists; only implementation/testing remains.

## F — owner decision required

Cannot be inferred from existing authority.

This classification will be used by the Unanswered-Question Register.

---

# 9. System IDE closure rule

Every major system that is expensive to inspect, author, tune, reproduce, or validate through ordinary play must have a dedicated workbench registered into the shared in-game developer shell.

The workbench must use the **real authoritative gameplay services**.

It must not maintain a second hidden state model.

Each major workbench should define useful forms of:
- **Inspect**;
- **Author / Tune**;
- **Exercise**;
- **Validate**;
- **Capture / Promote**.

Closure must not accept a major system as production-ready while its required IDE surface is absent.

---

# 10. Stale-reference policy

Closure may directly repair a stale filename/link/literal when all of the following are true:
- the intended current authority is unambiguous;
- the change does not alter gameplay/story design;
- the replacement is already owner-approved authority;
- a diff clearly shows the repair.

Example already identified at program start:

`docs/82_SAVE_STATE_TAXONOMY_OWNERSHIP_ADDENDUM.md` references a nonexistent:

`docs/69_GATE3_TOOL_PUZZLE_CUMULATIVE_SPECIFICATION.md`

The actual canonical file is:

`docs/69_GATE3_TOOL_SYSTEM_CUMULATIVE.md`

That is a safe reference repair, not a new design decision.

When a stale value could alter game behavior—completion counts, thresholds, route prerequisites, story order—prefer an explicit supersession/blocklist record and targeted correction rather than a casual global replacement.

---

# 11. Human-play boundary

Documentation and deterministic tests can prove consistency.

They cannot prove:
- movement feels good;
- camera feels good;
- combat is fair/fun;
- a puzzle is understandable;
- the Skiff is enjoyable;
- Hush transitions are comfortable/readable;
- a story beat lands emotionally;
- Null Meridian pacing works;
- a finale moment is memorable rather than exhausting.

Those claims require human play.

Closure must list those evidence obligations rather than pretending they are solved on paper.

---

# 12. Completion condition for this program

The Documentation Closure Program is complete only when:
- all required closure outputs exist;
- known precedence conflicts are resolved or explicitly registered as owner questions;
- known stale implementation-dangerous literals/references are corrected or blocklisted;
- every major runtime state has an identified owner;
- cross-system dependencies are directional and reviewable;
- every major system's System IDE obligation is accounted for;
- runtime evidence gaps are explicit;
- implementation blockers are distinct from tuning unknowns;
- onboarding no longer depends on reading historical documents in chronological order;
- the final owner-review package is complete;
- the owner explicitly reviews the implementation authorization boundary.

Until then:

> **Broad UE5.8 implementation remains unauthorized by the closure program.**
