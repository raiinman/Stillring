# 137 — Supersession Graph

**Status:** CANONICAL PRECEDENCE / NAVIGATION AUTHORITY  
**Updated:** 2026-09-07  
**Active program:** Studio Production Handoff Closure — Final Reconciliation / Acceptance  
**Current operational entrypoint:** `docs/NEXT_CHAT_HANDOFF.md`  
**Cross-program status authority:** `docs/195_STUDIO_HANDOFF_CROSS_PROGRAM_RECONCILIATION.md`

---

# 1. Purpose

Stillring deliberately preserves older design, audit and planning documents for provenance.

That is useful only when a future contributor can tell whether an older statement is:

- still current;
- current only outside a newer scoped decision;
- numeric/historical context only;
- or explicitly superseded.

Core rule:

> **A newer document supersedes older material only for the exact scope it resolves. Unaffected older material remains valid.**

Do not infer precedence from document number, timestamp, Unreal convenience, studio habit, or chat memory.

---

# 2. Notation

```text
A ---> B
```

A governs or supersedes B for the stated scope.

```text
A -X-> B
```

B is historical/reverted/non-current for that scope.

```text
A ---> B [numeric only]
```

B remains useful except for the named numeric facts.

```text
A DOES NOT ---> B
```

A must not be misread as proof/authority for B.

---

# 3. Current operational precedence

```text
docs/NEXT_CHAT_HANDOFF.md
        ---> previous versions of NEXT_CHAT_HANDOFF.md [operational direction]

docs/195_STUDIO_HANDOFF_CROSS_PROGRAM_RECONCILIATION.md
        ---> pre-reconciliation summaries of current discipline status / owner queue

docs/152_STUDIO_HANDOFF_GAP_REGISTER.md [2026-09-07 current-status revision]
        ---> older literal reading that Animation/UI/Audio/etc. are still broadly missing

docs/136_CANONICAL_AUTHORITY_INDEX.md [2026-09-07 revision]
        ---> older navigation that stops before production docs 154–195
```

`NEXT_CHAT_HANDOFF.md` is operational navigation. It does not replace detailed gameplay/story authority.

`docs/195` is current cross-program status and owner/product-decision authority. It does not replace the detailed discipline bibles/manifests it reconciles.

---

# 4. Documentation-closure versus Studio-Handoff precedence

The earlier Documentation Closure program established engineering-safe authority through docs 135–150.

The later Studio Production Handoff Closure program adds discipline-complete production authority through docs 151–195.

Therefore:

```text
docs/151–195 Studio Production Handoff Closure
        ---> docs/149 engineering/documentation closure verdict [full-production-handoff status only]
```

`docs/149_DOCUMENTATION_CLOSURE_COMPLETENESS_AUDIT.md` remains valid historical evidence that core design/ownership/implementation-readiness documentation was coherent at that earlier boundary.

It is not the final external-studio handoff verdict.

## Historical implementation recommendation

```text
current owner boundary in NEXT_CHAT_HANDOFF + docs/195
        -X-> docs/150 recommendation to begin UE5.8 implementation [authorization only]
```

`docs/150_IMPLEMENTATION_OWNER_REVIEW_PACKAGE.md` is now explicitly marked historical/superseded as current operational direction.

Its technical sequencing advice may remain useful **if implementation is later authorized**.

Its old recommendation is **not authorization**.

Current rule:

> **Broad UE5.8 implementation remains unauthorized.**

---

# 5. Locomotion precedence

Current cumulative locomotion authority:

```text
docs/20_GATE1_LOCOMOTION_SPECIFICATION.md
        ---> earlier incorporated locomotion decision drafts/notes
```

Locked scoped precedence includes:
- no ordinary traversal stamina/resource tax;
- sustained Sprint is available;
- modest deliberate jump remains available;
- authored low-obstacle mantle/scramble;
- no universal/free climbing;
- same-continuous-handhold ledge shimmy only;
- no baseline corner-wrap/gap-transfer/lateral-jump/vertical handhold climbing;
- explicit Drop/Release rather than silent analog-drift release.

Runtime tuning may refine values but cannot silently change the behavior class.

---

# 6. Camera / targeting precedence

```text
docs/22_GATE1_CAMERA_SPECIFICATION.md
        ---> incorporated docs/23–36 where cumulative text conflicts
```

Supporting camera addenda remain detailed rationale/fixture authority where consistent.

No stock Unreal camera value and no Zelda camera value becomes Stillring authority by convenience.

---

# 7. Combat / encounter precedence

Player combat:

```text
docs/48_GATE2_COMBAT_STATE_MODEL.md
        ---> earlier Gate 2 player-combat drafts for incorporated state topics
```

Encounter/pressure:

```text
docs/59_GATE2_ENCOUNTER_FIXTURE_CLOSURE.md
        ---> incomplete fixture assumptions in earlier encounter drafts
```

Docs 50–58 remain scoped encounter authority where consistent.

Animation presentation cannot supersede Combat gameplay ownership.

Encounter pressure cannot silently supersede Camera/Targeting readability authority.

---

# 8. Gate 3 filename/reference precedence

Canonical cumulative tool-system file:

```text
docs/69_GATE3_TOOL_SYSTEM_CUMULATIVE.md
```

Stale/nonexistent filename:

```text
docs/69_GATE3_TOOL_PUZZLE_CUMULATIVE_SPECIFICATION.md
```

Therefore:

```text
docs/69_GATE3_TOOL_SYSTEM_CUMULATIVE.md
        -X-> docs/69_GATE3_TOOL_PUZZLE_CUMULATIVE_SPECIFICATION.md [filename/reference only]
```

The stale filename is not an alternate design branch.

---

# 9. Hush / world-layer precedence

```text
docs/79_GATE4_HUSH_CUMULATIVE_SPECIFICATION.md
        ---> docs/70–78 for incorporated semantic behavior
```

Docs 70–78 remain detailed supporting authority where consistent.

Hard representation boundary:

```text
World Partition / Runtime Data Layer prototype direction
        DOES NOT ---> production architecture selection
```

Production representation remains runtime-gated by `docs/188`–`docs/189`.

Data Layer loaded state, sublevel state, Actor existence, streaming state or visualization state never supersedes semantic Waking/Hush authority.

---

# 10. Save / World-State precedence

```text
docs/88_SAVE_WORLD_STATE_CUMULATIVE_SPECIFICATION.md
        ---> docs/81–87 for incorporated cumulative behavior
```

Docs 81–87 remain detailed subcontracts.

```text
docs/81–88 design package
        DOES NOT ---> Issue #4 runtime verification closure
```

Issue #4 remains open until paired Waking/Hush save -> process exit -> reopen -> load proof exists.

Stable semantic identity supersedes:
- Actor paths;
- UObject/package paths;
- runtime instance IDs;
- display strings;
- coordinates;
- transient Data Layer/load state;
- trigger occupancy;

as canonical persistence identity.

---

# 11. Completion numeric precedence

Governing numeric authority:

```text
docs/104_COMPLETION_LEDGER_RECONCILIATION_AUTHORITY_ADDENDUM.md
        ---> docs/10_COMPLETION_MODEL.md [numeric counts/weights/thresholds]
        ---> docs/11_QUEST_AND_COMPLETION_LEDGER.md [numeric counts/thresholds]
        ---> docs/12_100_PERCENT_ROUTE.md [numeric counts/thresholds]
        ---> docs/13_CANTOR_AND_UPGRADE_CATALOG.md [completion thresholds]
        ---> docs/14_PRESTIGE_AND_MASTERY_CONTENT.md [global-count/threshold interpretation]
        ---> older completion planning values
```

Canonical numeric replacements:

```text
48 Resonance Faults ---> 36
28 Pulse Shards ---> 18
30 Micro-vaults ---> 24
K02 at 30 Faults ---> 24 reconciled Faults
Drift unlock at 13 Faults ---> 10 reconciled Faults + existing story/Line Skiff prerequisites
12 Unstandard stages as 12 global items ---> 1 global item / 12 internal stages
7 Yard commissions as 7 global items ---> 1 global item / 7 internal commissions
```

`docs/109_COMPLETION_LEGACY_LITERAL_BLOCKLIST.md` and `docs/147_STALE_LITERAL_REFERENCE_AUDIT.md` prevent stale implementation literals.

Do not blind-replace narrative prose when only the numeric interpretation is stale.

---

# 12. Completion item-roster precedence

The old `docs/11_QUEST_AND_COMPLETION_LEDGER.md` still preserves pre-reduction Fault/Pulse/Vault candidate lists for historical context.

Exact active shipping semantic-ID authority is now:

```text
docs/194_COMPLETION_ITEM_ROSTER_RECONCILIATION_AUTHORITY.md
        ---> docs/11 old 48-Fault item roster [active/tombstone disposition]
        ---> docs/11 old Pulse item roster [active/tombstone disposition]
        ---> docs/11 old 30-Vault item roster [active/tombstone disposition]
```

Current active rosters are exactly:
- 36 Fault IDs;
- 18 Pulse IDs;
- 24 Vault IDs.

Important forensic precedence:

```text
old stated Pulse budget = 28
old enumerated Pulse semantic IDs = 27
```

No 28th legacy Pulse ID was ever assigned.

Therefore:

```text
docs/194
        -X-> any attempt to invent a phantom legacy Pulse #28
```

## Still-Cairn reclassification

The already-authored optional deliberate-release-room premise was reclassified before runtime implementation:

```text
fault.stillcairn.unreleased_room
        ---> pulse.stillcairn.unreleased_room [completion-category identity]
```

The Pulse ID is retired.

The underlying authored activity survives as the Fault.

Both may not count.

---

# 13. Setup / Payoff precedence

Issue #9 authority is additive:

```text
docs/112 state authority
 + docs/113 commit boundary
 + docs/114 materiality
 + docs/115 portfolio
 + docs/116 authoring/data
 + docs/117 canonical instantiation
 + docs/118 closure audit
 + docs/119 navigation register
```

Core ownership precedence:

```text
source-system facts
        ---> copied Setup/Payoff shadow facts
```

Source systems own facts. Setup/Payoff evaluates them.

## S07 Pressure Release

Docs 115/117 supersede interpretations that turn S07 into another refuge/moving-pocket payoff.

Current focus is operational autonomy/control/labor.

## S10 Distributed Copy

Docs 115/117 supersede “backup copy survives” as the complete payoff meaning.

Current focus is distributed agency/knowledge.

## S11 timing

Doc 117 clarifies that road encounter/seed and Cairnspire civic-registration commit are not the same boundary.

---

# 14. Line Skiff precedence

Issue #10 authority:

```text
docs/120 + docs/121 + docs/122 + docs/123 + docs/124
        ---> vague mount/free-roam traversal assumptions
```

Core identity:

```text
Line Skiff = supported route-network vehicle
        ---> horse/mount/summon-anywhere/free-roam assumptions
```

No ordinary fuel/stamina/ticket tax.

Roadhand Pulse is not a generic speed boost.

Switchshoe is not a raw speed percentage.

Hush transitions aboard require authored paired continuation.

The Drift threshold is governed by docs 104/194-era reconciliation, not stale 13-Fault prose.

---

# 15. Null Meridian precedence

Current synthesis/finale authority:

```text
docs/127 six-sequence architecture
 + docs/128 one governing dungeon idea
 + docs/129 first-half adventure flow
 + docs/130 second-half escalation
 + docs/131 Take It Off the Bell
 + docs/134 exact scene-order precedence
        ---> older generic M16 paired-trials shorthand where conflicting
```

Exact current adjacency:

```text
Entry
 -> S1/S2
 -> worker maintenance descent
 -> S3
 -> Quiet Court Archive
 -> Maelor deliberate correction
 -> S4
 -> S5
 -> Maelor personal workspace
 -> S6 Take It Off the Bell
 -> Maelor
 -> Listener
 -> final decommission
```

The older Scene Beat Ledger remains canonical for unaffected story facts.

## S1/S2 simplification

Unapproved systems-heavy sketches are not authority.

Docs 128–129 lock the player-readable forms:
- S1: forced-together walkways must be allowed to move separately;
- S2: unlike machines return to their own valid operating conditions.

## S6

Doc 131 supersedes a vague `No Master Pulse`/generic multi-system capstone interpretation.

Current S6 requires:
- local service authority first;
- temporary Common Measure operation;
- physical master-relay disconnection;
- local continuation at different rhythms.

No six-region-switch exam and no mandatory Local Accord.

---

# 16. Story countertone/checklist precedence

Current story/reveal/progression authority supersedes any shorthand that presents Motion / Memory / Ending as an upfront fetch checklist.

```text
current story/reveal/progression authority
        ---> "collect the three Countertones" quest framing
```

The relationships are discovered through ordinary story needs and named afterward.

Do not reintroduce the removed checklist through UI, objectives, achievements or player-visible data naming.

---

# 17. System IDE precedence

```text
docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md
 + docs/141_SYSTEM_IDE_COVERAGE_MATRIX.md
        ---> ad-hoc one-off debug menus as production iteration architecture
```

System-specific workbenches refine the shared contract.

They may not create shadow gameplay truth.

Issue #58 remains open until runtime implementation/proof exists.

---

# 18. Technical production precedence

Current technical production consolidation:

```text
docs/188_TECHNICAL_PRODUCTION_BIBLE.md
 + docs/189_TECHNICAL_PRODUCTION_WRITTEN_HANDOFF_ACCEPTANCE_AUDIT.md
        ---> scattered assumptions about naming/data/LFS/plugin/build/localization conventions
```

This does not erase detailed system ownership documents.

It operationalizes them for an external studio.

C++ authoritative gameplay/state supersedes conflicting presentation-only Blueprint state.

A `.uasset`/`.umap` path never supersedes a required semantic persistent ID.

A bundled/popular Unreal framework never becomes mandatory by availability alone.

Hush representation and final performance budgets remain runtime-gated.

---

# 19. Production-management / decision-rights precedence

Decision rights:

```text
docs/170_STUDIO_DECISION_RIGHTS_MATRIX.md
        ---> informal assumptions about what the studio may decide
```

Dependencies/change control:

```text
docs/190_PRODUCTION_DEPENDENCY_DISCIPLINE_MATRIX.md
 + docs/191_PRODUCTION_MANAGEMENT_HARD_PASS_AUDIT.md
        ---> ad-hoc staffing/parallelization/outsourcing/change-control guesses
```

A region pod cannot fork shared systems because local production is inconvenient.

A vendor delivery is not integrated acceptance merely because files were delivered.

Schedule pressure does not convert LOCKED authority into studio choice.

---

# 20. Discipline-package status precedence

`docs/152` originally recorded missing production packages before the packages existed.

Current status is governed by the 2026-09-07 revision of `docs/152`, scoped audits, and `docs/195`.

Therefore:

```text
current docs/152 + docs/195 + scoped discipline audits
        ---> older literal wording that a completed discipline package is still missing
```

Key resolved dependencies include:
- Animation cinematic burden: former PARTIAL closed by Narrative's 113-entry scene inventory in `docs/183`;
- World/content completion roster: former PARTIAL closed by `docs/194`;
- Art C3/C4 exact production pool decomposition: bounded production planning, not an unbounded creative gap;
- UI/Narrative broad production inventories: written authority complete;
- Production Management: HARD PASS at written authority.

Non-PASS rows that remain are owner/product or runtime gates, not hidden studio assumptions.

---

# 21. QA / accessibility / localization precedence

```text
docs/192_QA_ACCESSIBILITY_LOCALIZATION_PRODUCTION_CONSOLIDATION.md
 + docs/193_QA_ACCESSIBILITY_LOCALIZATION_WRITTEN_HANDOFF_ACCEPTANCE_AUDIT.md
        ---> scattered accessibility/localization/QA production assumptions
```

These documents define production obligations and evidence classes.

They do **not** prove runtime accessibility, localized-build quality, certification or performance.

Platform certification scope remains downstream of platform selection.

---

# 22. Blueprint / presentation precedence

Project architecture rule:

```text
authoritative C++ gameplay/state service or approved source-owner data
        ---> conflicting presentation-only Blueprint/AnimBP/UI/Sequencer state
```

Blueprints/animation/UI/audio/cinematics may present and request.

They may not silently become:
- canonical Save owner;
- hidden Quest/World State owner;
- duplicate Combat owner;
- duplicate Hush truth owner;
- Completion database;
- per-chain Setup/Payoff truth;
- scene-filename-only persistence logic.

---

# 23. Runtime evidence precedence

Detailed design documentation does not supersede proof obligations.

```text
LOCKED / PASS / CLOSED at documentation layer
        DOES NOT ---> IMPLEMENTED / RUNTIME VERIFIED / HUMAN ACCEPTED / PRODUCTION READY
```

Actual UE5.8 evidence is required for runtime claims.

But runtime inconvenience also does not silently supersede locked design.

If a prototype demonstrates a design problem:
1. capture evidence;
2. classify the issue;
3. propose a scoped authority change;
4. obtain required approval;
5. update repository authority;
6. then change implementation.

---

# 24. Current known stale-reference hazards

## Blocked implementation-dangerous values

Use docs 104/109/147/194, not legacy planning prose, for:
- 36 Faults, not 48;
- 18 Pulse Shards, not 28;
- 24 Micro-vaults, not 30;
- K02 at 24 reconciled Faults, not 30;
- Drift eligibility at 10 reconciled Faults + existing story/Skiff gates, not 13;
- Unstandard Tool = one global item / 12 internal stages;
- Broken Standard Yard = one global item / 7 internal commissions;
- active Fault/Pulse/Vault semantic IDs from doc 194 only.

## Gate 3 dead filename

Use:

`docs/69_GATE3_TOOL_SYSTEM_CUMULATIVE.md`

not the stale nonexistent alternate filename.

## Null Meridian order

Use doc 134.

## Setup/Payoff S07/S10

Use docs 115/117.

## Old implementation recommendation

Do not treat doc 150 as authorization.

## Old Studio Handoff gap wording

Do not treat pre-package “missing” descriptions as current status; use current docs 152/195/scoped audits.

---

# 25. Precedence decision procedure

When two sources appear to conflict:

1. identify the exact fact in conflict;
2. find its explicit source owner;
3. check `docs/136` for current topic routing;
4. check this graph for scoped supersession;
5. check the relevant cumulative/system/production authority;
6. check `docs/195` if the disagreement is about current handoff status or owner/product queue;
7. preserve unaffected older content;
8. if still unresolved, classify the unknown rather than improvising.

Never resolve precedence by:
- higher file number alone;
- newer Git timestamp alone;
- shortest document;
- easiest Unreal implementation;
- studio convention;
- another game's precedent;
- chat memory.

---

# 26. Current final precedence statement

> **Current repository authority is a layered system: gameplay/story canon owns what the game means; production bibles/manifests own how disciplines execute that meaning; decision-rights/dependency documents bound studio freedom; runtime evidence proves whether implementation works; and current handoff/reconciliation documents control operational status. Historical plans remain provenance, not silent authority.**
