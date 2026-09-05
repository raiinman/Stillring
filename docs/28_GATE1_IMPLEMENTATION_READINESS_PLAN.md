# 28 — Gate 1 Implementation Readiness Plan

**Status:** WORKING PRODUCTION PLAN / NON-CANONICAL WHERE OWNER POLICY REMAINS OPEN  
**Updated:** 2026-09-05  
**Scope:** prepares Issues #5 and #58 for implementation without allowing unresolved Camera Decisions #12–#18 to leak into code as defaults.

## Purpose
Gate 1 is now far enough specified that infrastructure can advance while the remaining camera feel decisions stay in owner review.

This plan separates:
1. work already authorized by settled authority;
2. scaffolding that can be built without choosing unresolved policy;
3. gameplay behavior that must wait for owner approval.

The governing pipeline remains:
> **CANON → PRODUCTION → IMPLEMENTATION → VERIFICATION → PLAY**

The System IDE rule remains:
> **Build the system and its in-game IDE together.**

---

## 1. Authorized now

### Unreal project bootstrap — Issue #5
Safe to implement now:
- minimal Unreal Engine 5.8 C++ project/module structure;
- Enhanced Input baseline and named input actions;
- Git/Git LFS Unreal project rules;
- reproducible Development Editor build and command-line validation entry points;
- graybox Gate 1 test map structure;
- reset/reload and transform/build/performance readout;
- representative geometry for already-settled movement/camera cases;
- target-marker/test-target actors whose behavior is data-driven and does not choose unresolved target-switch policy.

### Shared System IDE shell — Issue #58
Safe to implement now:
- development-only shell open/close and registration model;
- controller + keyboard navigation baseline;
- workbench registry/search;
- current build/commit/map/player transform/test preset display;
- canonical/session-override/staged/promoted provenance types;
- common validation result model;
- common capture/reproduction record model;
- common reset/reload/teleport service surface;
- Shipping exclusion/hard-disable;
- Locomotion IDE registration and inspect/tune/exercise/validate/capture skeleton;
- Camera/Targeting IDE registration and read-only diagnostics skeleton for Decisions #1–#11.

### Locomotion implementation
`docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` is final owner-approved. Implementation may proceed against that authority as soon as the harness exists.

### Camera implementation through Decision #11
Implementation may safely establish modular components/services for:
- exploration composition/orbit;
- soft yaw follow and manual recenter;
- collision compression/recovery;
- occlusion state/grace;
- Close Quarters Camera;
- Ceiling-Constrained Camera;
- Vertical Context Assist;
- initial target acquisition;
- exploration→lock transition;
- established single-target Relationship Frame;
- bounded manual composition nudge **as a semantic capability**, while final input partition with switching remains unresolved.

Do not bind unresolved target-switch gestures into permanent player controls yet.

---

## 2. Must remain policy-neutral until owner review

The following code may expose extension points/interfaces, but may not silently select final behavior:
- #12 target-switch gesture/directionality/debounce;
- #13 secondary-enemy camera influence;
- #14 large-boss framing profile semantics beyond generic authored bounds support;
- #15 material jump/fall/mantle camera behavior beyond preserving current camera continuity;
- #16 default camera-shake intensity/accessibility presentation;
- #17 final sensitivity defaults, response curves, inversion UI, mouse/controller mapping partition;
- #18 aim/first-person/gyro behavior.

If an engine/template supplies defaults for these, those defaults are test scaffolding only and must be visibly marked non-canonical.

---

## 3. Recommended Gate 1 C++ module boundaries

Exact class names are implementation choices, but responsibility should remain separable.

### Runtime gameplay
- Player input/request layer
- Locomotion state/service
- Traversal eligibility/service
- Camera mode coordinator
- Camera physical solver
- Camera composition solver
- Targeting candidate/lock service
- Target-relative movement frame provider
- Development-test scenario hooks behind compile/runtime guards

### Development-only
- Shared System IDE shell
- Workbench registration interface
- Locomotion workbench
- Camera/Targeting workbench
- Test-scenario registry
- Runtime tuning override store
- Validation/result store
- Evidence/capture exporter

The development shell must call authoritative gameplay services; it must not duplicate locomotion/camera logic.

---

## 4. Data/provenance model to establish early

Every live-tunable value shown in a System IDE should carry:
- stable tuning key;
- semantic display name;
- owning system;
- canonical source location/type;
- canonical value;
- effective runtime value;
- optional session override;
- optional staged value;
- dirty state;
- allowed min/max or validation rule where meaningful;
- restart/reload required flag;
- promotion/export support flag.

This is more important than choosing a pretty UI framework. If provenance is bolted on later, the shell becomes an unsafe cheat menu rather than a development IDE.

---

## 5. Gate 1 scenario registry

Create a named scenario registry instead of hardcoding teleport buttons per widget.

Each scenario should carry:
- stable scenario ID;
- human-readable name;
- map/transform or setup callback;
- required spawned actors/geometry state;
- player starting locomotion/camera state;
- optional target arrangement;
- reset callback;
- relevant authority/decision tags;
- expected invariant checks;
- whether human feel review is required.

Initial scenario families:

### Locomotion
- analog careful→run band;
- Sprint curves and hard reversal;
- Sprint→jump;
- Sprint→target-lock;
- low mantle ranges;
- ledge catch/hang/pull-up/shimmy/release;
- ladder mount/end/release;
- swim;
- slope scramble/slide;
- fall severity;
- interaction while moving;
- five-minute per-input-profile course.

### Camera / targeting
- free orbit/recenter;
- rear-wall compression/recovery;
- clutter/thin-obstacle chatter;
- cramped room;
- low ceiling/rafters/sloped roof;
- ascent/descent/drop approach;
- acquisition candidate matrix;
- lock transition from unusual exploration views;
- ordinary Relationship Frame close/medium/far;
- vertical ordinary target;
- occlusion grace/break;
- bounded manual nudge;
- placeholders for #12–#18 research tests marked `OWNER_POLICY_PENDING`.

---

## 6. Verification layers

### Machine-verifiable invariants
Examples:
- Shipping target cannot open/register System IDE shell;
- no network/model/API dependency exists in game runtime modules;
- input actions are named Enhanced Input actions, not hardcoded key polling;
- target acquisition never selects an ineligible/invalid candidate;
- failed acquisition does not change Sprint/lock/camera state;
- collision solver never resolves camera inside blocking geometry;
- blocked pitch does not accumulate hidden queued pitch;
- runtime override is visually/procedurally distinct from canonical value;
- scenario reset returns deterministic semantic state.

### Human-play authority
Machine checks do not close:
- five-minute locomotion trust;
- camera invisibility/trust;
- acceleration/turn feel;
- camera damping/lag feel;
- lock transition feel;
- readability of pair framing;
- accessibility comfort.

These require fresh human play and observation capture.

---

## 7. PR sequencing recommendation

### PR A — Unreal skeleton
Issue #5 subset:
- `.uproject`/module/build files;
- Git ignores/LFS verification;
- Enhanced Input asset/data plan;
- empty graybox test map if binary generation environment is available;
- reproducible build/editor/automation docs.

### PR B — Shared System IDE foundation
Issue #58 subset:
- shell + registry + provenance/result models;
- dev-only guards;
- one trivial sample/test workbench proving registration.

### PR C — Locomotion runtime + Locomotion IDE vertical slice
Implement a narrow already-approved locomotion subset end-to-end with its IDE instead of building the whole movement system and tooling afterward.

Suggested first slice:
**ground locomotion + analog processing + Sprint + reset/test course hooks + live state/tuning diagnostics.**

### PR D onward
Add jump/mantle/ledge/ladder/swim/slope/fall/interaction as coherent slices with corresponding IDE diagnostics and scenarios.

### Camera PRs
Begin with exploration camera + physical solver + Camera IDE inspection, then layer approved modes. Do not implement #12–#18 policy until approved.

---

## 8. Issue #5 acceptance evidence convention

Every Unreal PR should report:
- exact engine version used;
- source commit;
- files/classes added;
- binary `.uasset`/`.umap` additions/modifications explicitly listed;
- build command + result;
- editor/map-load verification;
- fast Automation/smoke command + result;
- screenshots/video only as supplementary evidence;
- System IDE impact: new workbench surface / debt introduced / none;
- unresolved owner-policy boundaries touched: yes/no with explicit list.

---

## 9. Issue #58 acceptance evidence convention

For every System IDE feature:
- which authoritative gameplay service it reads/mutates;
- inspect fields exposed;
- exercise/reset actions exposed;
- validation checks/rejection reasons;
- tunable values and provenance states;
- capture/export format;
- Shipping exclusion proof;
- no external model/API/runtime dependency proof.

---

## 10. Gate 1 implementation blockers

### Not blockers for infrastructure
Remaining Camera Decisions #12–#18 do **not** block:
- project bootstrap;
- shared IDE shell;
- scenario registry;
- locomotion implementation;
- camera #1–#11 implementation skeleton and approved semantics.

### Blockers for complete Issue #2 closure
Camera #12–#18 owner approval remains required before the camera specification can be declared fully complete.

### Environment blocker
Actual Unreal binary asset creation/build verification requires an environment with Unreal Engine 5.8 available. Repository planning/scaffolding can proceed without pretending those binary/build checks passed.

---

## 11. Highest-leverage next implementation action

Once this plan is reviewed against repository authority, the best non-owner-decision work is:

> **Bootstrap the minimal UE 5.8 C++ harness and shared System IDE shell architecture together, then implement ground locomotion + Sprint as the first end-to-end player-system/workbench slice.**

This proves the architecture before camera and traversal complexity multiply.
