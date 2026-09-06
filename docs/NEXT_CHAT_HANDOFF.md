# Stillring — Next Chat Handoff

**Updated:** 2026-09-05  
**Repository:** `raiinman/Stillring`  
**Current reviewed main:** `aa80c1f295d3c194c9fe5189ec2056d77db64221`  
**Active program:** Studio Production Handoff Closure  
**Operational boundary:** **DOCUMENTATION ONLY — NO TESTING / NO UE5.8 IMPLEMENTATION YET**

---

# Read first

1. `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`
2. `docs/152_STUDIO_HANDOFF_GAP_REGISTER.md`
3. `docs/153_STUDIO_HANDOFF_ACCEPTANCE_CHECKLIST.md`
4. `docs/150_IMPLEMENTATION_OWNER_REVIEW_PACKAGE.md`
5. `docs/149_DOCUMENTATION_CLOSURE_COMPLETENESS_AUDIT.md`
6. `docs/145_IMPLEMENTATION_READINESS_GAP_REGISTER.md`
7. `docs/144_UNANSWERED_QUESTION_REGISTER.md`
8. `docs/146_CONTENT_TRACEABILITY_MATRIX.md`
9. `docs/147_STALE_LITERAL_REFERENCE_AUDIT.md`
10. `docs/136_CANONICAL_AUTHORITY_INDEX.md`
11. `docs/137_SUPERSESSION_GRAPH.md`
12. `docs/138_TERMINOLOGY_GLOSSARY_AND_ONBOARDING.md`
13. `docs/139_SYSTEM_OWNERSHIP_MAP.md`
14. `docs/140_CROSS_SYSTEM_CONTRACT_MATRIX.md`
15. `docs/141_SYSTEM_IDE_COVERAGE_MATRIX.md`
16. `docs/142_RUNTIME_EVIDENCE_LEDGER_BASELINE.md`
17. `ROADMAP.md`
18. `AGENTS.md` / repository-local agent instructions

Always re-check exact current `main` before repository writes.

---

# Current project truth

## What is already strong

Stillring has substantial locked/current authority for:

- story/world/content foundation;
- Gate 1 locomotion and camera/targeting;
- Gate 2 combat and encounter behavior;
- Gate 3 Cantor/tools/puzzles;
- Gate 4 Hush/world-layer semantics;
- Save/World-State design;
- Completion Decision #16 and all 16 completion categories;
- Issue #9 Setup/Payoff;
- Issue #10 Line Skiff traversal transformation;
- Issue #11 Null Meridian synthesis/finale;
- shared in-game System IDE contract;
- authority/supersession/terminology;
- system ownership and cross-system contracts;
- content traceability;
- stale-literal containment;
- runtime/readiness/unknown classification.

A competent gameplay/engineering team should not need to invent Stillring's core identity or mechanics to begin scoped implementation later.

## What is not yet strong enough

The repository is **not yet a complete external-studio full-production handoff package**.

Major production disciplines still require concrete production bibles/manifests for:

- character/environment/prop art;
- animation;
- audio/music/VO;
- UI/UX;
- narrative scripting/cinematics/dialogue production;
- region-by-region asset/content burden;
- technical production conventions;
- production dependencies/staffing boundaries;
- platform/performance product decisions;
- studio decision rights and change control.

The active goal is to close those gaps **without implementing or testing the game yet**.

---

# Owner boundary — current

Previous `docs/150_IMPLEMENTATION_OWNER_REVIEW_PACKAGE.md` recommended beginning the UE5.8 Gate 1 implementation after Documentation Closure.

The owner has now explicitly chosen a different immediate boundary:

> **NO TESTING YET. DOCUMENT THE COMPLETE STUDIO-HANDOFF GAPS FIRST.**

Therefore:

- do **not** start Issue #5 implementation;
- do **not** start Issue #58 runtime work;
- do **not** create a `.uproject` yet under this active boundary;
- do **not** run gameplay tests;
- do **not** claim runtime proof;
- do **not** reopen locked gameplay/story decisions merely because production documentation is incomplete.

The active work is Studio Production Handoff Closure only.

---

# Studio Production Handoff Closure goal

The repository should eventually pass this test:

> **Could a competent external studio determine what to build, why it exists, what quality bar it must meet, what it depends on, and which decisions it is not authorized to make—without reconstructing owner intent from chat history?**

This is stricter than the previous engineering-readiness standard.

The desired eventual state is not merely:

> “A studio understands the game.”

It is:

> **“A studio can quote, staff, schedule, author, build, and polish the intended game from repository authority, with only explicitly scheduled owner decisions and runtime-tuning gates remaining.”**

---

# Required Studio Handoff outputs

Per `docs/151`, the closure program must produce at minimum:

1. **Art Bible**
2. **Character / Environment / Prop Production Manifests**
3. **Animation Bible + Animation Manifest**
4. **Audio / Music / VO Bible**
5. **UI/UX Production Specification**
6. **Narrative Production Package**
7. **Technical Production Bible**
8. **Performance / Platform Product Brief**
9. **Production Dependency / Discipline Matrix**
10. **Region-by-Region Production Manifest**
11. **Studio Decision-Rights Matrix**
12. **Final Studio Handoff Acceptance Audit**

Do not collapse these into vague mood documents. They must be useful to actual external production disciplines.

---

# Current major studio-handoff gaps

`docs/152_STUDIO_HANDOFF_GAP_REGISTER.md` is the authority.

High-level gaps include:

- target-PC baseline — `TBD OWNER` before later objective performance acceptance;
- launch-platform scope beyond PC-first — `TBD OWNER` before platform-specific commitments;
- production-operational character/environment/Hush/VFX art rules;
- asset manifests and reusable-vs-unique production burden;
- complete animation-family inventory and rig/IK/root-motion boundaries;
- audio/score/VO production scope and manifests;
- complete UI screen/state flow;
- dialogue/cinematic/VO/localization production inventories;
- region/dungeon production manifests;
- technical naming/package/data/source-control conventions;
- production dependency and studio decision-rights matrices.

Do not use “good judgment” as the closure answer for any of these.

---

# Genuine owner decisions currently visible

Keep these few and explicit.

## Definitely still owner/product decisions

- intended launch-platform scope;
- target-PC performance baseline;
- VO scope if not already settled by current narrative authority;
- commercial title/name after clearance when needed;
- any material change to locked game/story/art/product scope.

## Not owner decisions

Do not ask the owner to choose:

- C++ class names;
- Slate versus UMG merely as an internal technical preference;
- mesh decomposition;
- ordinary source-control implementation details;
- exact movement/camera/combat tuning that belongs to later prototype/human play;
- implementation choices that preserve locked authority.

---

# Current runtime truth

`game/` remains intentionally skeletal.

No runtime claim should be inferred from the amount of documentation.

Still unproven:

- UE5.8 project/bootstrap;
- locomotion/camera feel;
- combat/encounter runtime;
- tool/puzzle runtime;
- Hush production representation/performance;
- save/load;
- completion registry/math;
- Setup/Payoff runtime;
- Line Skiff;
- Null Meridian;
- System IDE runtime shell/workbenches;
- performance/accessibility/human-play acceptance.

Issues #4, #5, and #58 intentionally remain open.

---

# Completion constants — do not regress

Canonical authority remains `docs/104_COMPLETION_LEDGER_RECONCILIATION_AUTHORITY_ADDENDUM.md`.

- 16 equal top-level categories = 6.25% each;
- Resonance Faults = 36;
- Pulse Shards = 18;
- Micro-vaults = 24;
- K02 = 24 reconciled Faults;
- Drift Knot eligibility = 10 reconciled Faults + existing story/Line Skiff prerequisites;
- Unstandard Tool = 1 global item / 12 internal stages;
- Broken Standard Yard = 1 global item / 7 commissions.

Stale 48/28/30/30-Fault/13-Fault literals must not become production constants.

---

# Critical system boundaries

- Source systems own facts; Setup/Payoff evaluates them.
- Save Coordinator orchestrates snapshots; it does not own all gameplay truth.
- Hush/Waking semantic state is not Data Layer state.
- Actor/map/node/runtime IDs are not canonical persistence identity.
- Completion owns completion consequences, not every gameplay fact.
- Line Skiff is a network vehicle, not a free-roam mount.
- ordinary traversal has no stamina/fuel/ticket tax.
- System IDEs use authoritative gameplay services; no hidden shadow state.
- Null Meridian order is governed by docs 127–134.
- optional completion does not gate the canonical ending.
- clean-room IP rules remain binding across art/audio/UI/animation production.

---

# Recommended Studio Handoff documentation order

Per `docs/152`:

1. Studio Decision-Rights Matrix + Product/Platform Brief skeleton
2. Art Bible + scale/material/lighting/Hush production rules
3. Character/Environment/Prop Production Manifests
4. Animation Bible + animation manifest
5. UI/UX Production Specification
6. Audio/Music/VO Bible
7. Narrative Production Package
8. Region-by-Region Production Manifest
9. Technical Production Bible
10. Production Dependency/Discipline Matrix
11. QA/accessibility/localization production consolidation
12. Final Studio Handoff Acceptance Audit

Research before locking production rules where external/current production practice materially matters.

Preserve existing authority rather than duplicating or silently superseding it.

---

# Final studio-handoff acceptance

Use `docs/153_STUDIO_HANDOFF_ACCEPTANCE_CHECKLIST.md`.

A final reviewer who does not rely on chat history should be able to determine from the repository:

- what Stillring is;
- what each discipline needs to build;
- what volume of content exists;
- what is locked;
- what the studio may choose;
- what must return to the owner;
- what remains runtime-gated;
- what is intentionally TBD;
- where each discipline starts reading.

Any normal production answer that depends on “the owner said in chat…” is a handoff failure.

This is a **documentation review**, not gameplay testing.

---

# Method

For Studio Production Handoff Closure:

**read current canonical authority -> research the production discipline where useful -> derive production-facing rules/manifests without reopening locked gameplay -> classify decision rights -> cross-link dependencies -> exact diff/review -> merge -> next production discipline.**

Do not implement or test under the current owner boundary.
