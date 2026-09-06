# 118 — Issue #9 Setup/Payoff Closure Audit

**Status:** DESIGN/DOCUMENTATION CLOSURE CANDIDATE  
**Updated:** 2026-09-05  
**Issue:** #9 — Design cross-state setup and payoff framework  
**Authority set:** `docs/112` through `docs/117`

## Purpose

This audit determines whether Issue #9 is documentation-complete without confusing documentation completion with UE5.8 implementation proof.

Issue #9's goal is to make pre/post-Stillness and Waking/Hush relationships a first-class authored system rather than one-off quest scripting. The accepted design now does so through stable semantic IDs, explicit state/commit/payoff contracts, source-system fact ownership, minimal durable history, deterministic recovery, authoring validation, and a dedicated System IDE/workbench contract.

---

# Acceptance-criteria audit

## 1. Data shape documented — PASS (design authority)

Covered by:

- `docs/112_SETUP_PAYOFF_STATE_AUTHORITY_ADDENDUM.md`
- `docs/113_SETUP_PAYOFF_COMMIT_BOUNDARY_AUTHORITY_ADDENDUM.md`
- `docs/114_SETUP_PAYOFF_PAYOFF_MATERIALITY_AUTHORITY_ADDENDUM.md`
- `docs/115_SETUP_PAYOFF_PORTFOLIO_AUTHORITY_ADDENDUM.md`
- `docs/116_SETUP_PAYOFF_AUTHORING_DATA_AUTHORITY_ADDENDUM.md`

Canonical shape includes:

- one stable semantic chain ID `setup.<region>.<slug>`;
- one authored definition per chain;
- typed source-fact references with explicit owners;
- priming predicate;
- semantic commit boundary/class/event;
- supported committed variants;
- explicit non-intervention or supersession behavior;
- payoff eligibility predicate;
- exact resolution predicate/event;
- manifestation contracts with actual source owners preserved;
- schema/migration metadata;
- recovery rules;
- deterministic fixtures;
- minimal durable commit/resolution receipts rather than shadow copies of all source facts.

No Actor path, map path, display string, scene instance ID, Blueprint node name, trigger name, or coordinate is persistence identity.

## 2. Three Stillring-specific prototype examples — PASS (design authority)

Locked in `docs/117_SETUP_PAYOFF_PROTOTYPE_INSTANTIATION_AUTHORITY.md`:

1. S01 `setup.brindle.crooked_fire_bell` — physical/elective and flagship vertical-slice prototype;
2. S06 `setup.saltreach.manual_fog_code` — operational/story-mandatory and zero-choice proof;
3. S11 `setup.mireglass.personal_provenance` — epistemic/elective proof.

All three are instantiated through identity, source ownership, priming, commit, variants/non-intervention, payoff, resolution, persistence, recovery, and deterministic fixture requirements.

## 3. Failure/reload behavior defined — PASS (design authority)

Covered by Decisions #1, #2, #5, and #6.

Locked behavior includes:

- authoritative source systems restore before Setup/Payoff reconciliation;
- transient lifecycle labels are derived where possible;
- commit/resolution settlement is idempotent;
- crash/power-loss/interrupted commit converges to pre-commit or one exact committed variant;
- contradictory source/history states surface audit mismatch instead of last-boolean-wins;
- death/retry follows authoritative checkpoint/save transaction semantics rather than independently rewriting narrative history;
- temporary NPC absence does not erase physical/operational truth;
- unexpected order uses semantic predicates/defensive paths rather than presentation-trigger history;
- Superseded histories require explicit equivalent completion-valid resolution;
- map/Actor renames do not change semantic identity.

## 4. Writers can author without hardcoding node paths — PASS (design authority)

`docs/116` locks one canonical authoring source per chain, declarative predicate trees, semantic events, named deterministic provider escape hatches, and a shared authoring workbench.

Forbidden authority includes:

- level/map paths;
- Actor paths;
- Blueprint graph/node names;
- arbitrary per-chain Blueprint callbacks;
- trigger-volume identity;
- translated display strings;
- coordinates.

Presentation/debug soft references may exist only as non-authoritative convenience data.

## 5. Vertical slice contains one naturally noticeable setup/payoff — DESIGN SPEC PASS / RUNTIME PROOF OPEN

S01 Crooked Fire Bell is the canonical vertical-slice chain by Decision #4 and fully instantiated in Decision #6.

The intended natural player experience is:

ordinary Brindle familiarity -> tactile C01 repair -> semantic service commit -> Grand Ring separation -> changed-world return -> physically different bell/safety behavior -> authored resolution -> persistent historical aftermath.

This satisfies the **design contract** for a naturally noticeable vertical-slice setup/payoff.

It does **not** prove that a UE5.8 vertical slice currently implements or communicates it successfully. Human tester recognition remains a later implementation/play acceptance gate.

Issue #9 may therefore close as **design/documentation complete**, while runtime evidence remains tracked by implementation/vertical-slice work and must not be represented as complete.

---

# Locked portfolio reconciliation

Decision #4 supersedes older authored shorthand where it conflicts.

## S07 — Leviathan Pressure Release

Superseded older shorthand:

> independent bypass creates a moving deep-inlet refuge; reconnected bypass protects another dock.

Current authority:

- setup remains whether the old cistern pressure bypass stays locally independent or reconnects to central regulation;
- the primary payoff is **local-versus-central pressure control and community operational autonomy**;
- independent history lets deep-inlet crews create/use local low-water work windows and begin rescue/salvage without waiting for a master schedule;
- reconnected history better protects/serves central heavy infrastructure but removes that independent local pressure authority, producing a different later assistance/coordination problem;
- branches remain authored, meaningful, completion-valid, and asymmetrical without requiring another moving-pocket payoff.

Older `docs/11`, `docs/12`, or Saltreach regional wording that still describes S07 primarily as a moving-refuge result is **HISTORICAL / SUPERSEDED by `docs/115` and this closure audit**.

## S10 — High Aerie Distributed Copy

Older shorthand may read like:

> another copy survived because it traveled.

Current authority:

- the physical traveling copy remains the mechanism;
- the primary payoff is **distributed agency/knowledge**, not mere duplicate-file survival;
- novices/ordinary holders can question sealed archive authority and act sooner because contested knowledge was distributed rather than contained in one authoritative repository;
- changed initiative, testimony/authority relationships, and earlier independent action are the load-bearing consequence.

Any older text that reduces S10 to `backup copy survives archive failure` is subordinate shorthand and must not be used as the full implementation contract.

## S11 — Personal Provenance timing

Canonical timing is:

1. road to Cairnspire — Mireglass traveler/mirror is seeded;
2. Cairnspire civic-registration period — provenance classification is the semantic commit opportunity.

Older `First Circuit traveler` phrasing is contextual shorthand, not the commit location.

---

# Completion relationship

Completion Decision #16 remains the global weighting/reporting authority.

Setup/Payoff contributes exactly **12 canonical completion items** inside its one top-level completion bucket.

Rules:

- setup commit alone does not award the completion item;
- one valid authored payoff resolution awards one chain item;
- prerequisite contracts/tools/records do not generate bonus Setup/Payoff items;
- valid alternate/non-intervention/superseded histories remain completion-safe;
- no hidden moral branch is required;
- Completion Ledger derives satisfaction from authoritative semantic resolution, not from cached percentage or presentation state.

---

# Hush relationship

Issue #9 does not create a generic second timeline.

Hush/Waking authority remains with the Hush/World-Layer system.

- entering/exiting Hush does not implicitly commit setup history;
- Hush presentation does not overwrite committed history;
- a Hush interaction can contribute to a chain only through an explicit persistent source-owned fact and a declared semantic boundary;
- Setup/Payoff consumes Hush facts where relevant but does not duplicate Hush state ownership.

---

# Save/world-state relationship

Issue #4 / save-world-state authority remains the persistence-system owner.

Setup/Payoff defines what history it needs, not an independent save framework.

Required durable chain history is intentionally minimal:

- semantic chain identity;
- commit receipt when a commit genuinely occurred;
- resolution receipt when a payoff genuinely resolved;
- schema/migration history needed for compatibility.

Source facts remain owned/restored by their original systems.

Issue #4's repository issue state should be reconciled separately against its own acceptance criteria; Issue #9 closure does not silently close Issue #4.

---

# System IDE closure contract

Setup/Payoff is not implementation-complete until its development-only workbench exists in the shared in-game System IDE shell.

The locked workbench must support at least:

- definition inspection;
- current lifecycle explanation;
- all source predicates and owners;
- commit boundary/event/variant provenance;
- payoff eligibility explanation;
- resolution state;
- downstream manifestation/consumer tracing;
- save schema/migration visibility;
- canonical vs temporary override distinction;
- dependency graph/cycle validation;
- portfolio similarity audit;
- deterministic exercise presets;
- save/reload every lifecycle boundary;
- unexpected-order matrix;
- duplicate-event/idempotence checks;
- contradictory/orphaned fact audits;
- human-readable `Explain Current State` output.

The IDE must use the same authoritative gameplay services as runtime, not a parallel narrative model.

---

# Runtime evidence explicitly NOT claimed

Closing Issue #9 as design/documentation complete does not claim any of the following:

- UE5.8 `UPrimaryDataAsset` implementation;
- Asset Manager discovery implementation;
- semantic predicate evaluator implementation;
- semantic event/provider adapters;
- SaveGame commit/resolution receipt implementation;
- migration execution;
- source-system integration;
- Hush runtime integration;
- Completion Ledger runtime integration;
- Setup/Payoff System IDE implementation;
- deterministic fixture execution;
- playable S01 vertical-slice proof;
- tester-noticed payoff proof;
- performance proof;
- human acceptance.

These belong to later implementation/verification/play gates.

---

# Closure conclusion

**Issue #9 is documentation/design complete once Decision #6 and this closure package are merged.**

All original design acceptance criteria have explicit authority. Remaining uncertainty is implementation/runtime evidence, not missing product design policy.

The next unresolved design issue is **Issue #10 — traversal transformation/mastery loop**.

Before starting Issue #10, future work must read `docs/NEXT_CHAT_HANDOFF.md` and this audit so the project does not reopen settled Setup/Payoff questions or resurrect superseded S07/S10 behavior.
