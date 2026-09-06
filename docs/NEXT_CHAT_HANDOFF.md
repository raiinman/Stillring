# Stillring — Next Chat Handoff

**Updated:** 2026-09-05  
**Repository:** `raiinman/Stillring`  
**Operational status:** Core design through Save/World-State and Completion is locked. Issue #9 Setup/Payoff is design/documentation complete pending merge/closure of the current closure package. UE5.8 runtime implementation, System IDE implementation, deterministic fixture execution, and human play acceptance remain UNVERIFIED unless a later authority explicitly proves them.

## Read first

1. `docs/118_SETUP_PAYOFF_ISSUE_9_CLOSURE_AUDIT.md`
2. `docs/119_SETUP_PAYOFF_DECISION_REGISTER_ADDENDUM.md`
3. `docs/117_SETUP_PAYOFF_PROTOTYPE_INSTANTIATION_AUTHORITY.md`
4. `docs/116_SETUP_PAYOFF_AUTHORING_DATA_AUTHORITY_ADDENDUM.md`
5. `docs/115_SETUP_PAYOFF_PORTFOLIO_AUTHORITY_ADDENDUM.md`
6. `docs/114_SETUP_PAYOFF_PAYOFF_MATERIALITY_AUTHORITY_ADDENDUM.md`
7. `docs/113_SETUP_PAYOFF_COMMIT_BOUNDARY_AUTHORITY_ADDENDUM.md`
8. `docs/112_SETUP_PAYOFF_STATE_AUTHORITY_ADDENDUM.md`
9. `docs/104_COMPLETION_LEDGER_RECONCILIATION_AUTHORITY_ADDENDUM.md`
10. `docs/105_COMPLETION_DECISION_16_CLEANUP_AUDIT.md`
11. `docs/109_COMPLETION_LEGACY_LITERAL_BLOCKLIST.md`
12. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
13. `docs/18_PROJECT_DECISION_REGISTER.md`
14. `docs/11_QUEST_AND_COMPLETION_LEDGER.md` — older authored content source; newer addenda control conflicting Setup/Payoff or completion literals
15. `docs/12_100_PERCENT_ROUTE.md` — older authored route source; newer addenda control conflicting Setup/Payoff or completion literals
16. GitHub Issue #9
17. GitHub Issue #10

Always re-check exact current `main` before repository writes.

## Required method

For unresolved design work:

fresh research -> reconcile existing authority, IP, accessibility, failure/recovery, save semantics, System IDE, deterministic fixtures, and human-play implications -> owner approval -> document -> exact diff/review -> expected-head merge -> next decision.

Do not silently reopen a locked decision merely because an older authored document still contains shorthand. Use the authority/supersession chain.

## Completion status

Completion Decision #16 is LOCKED in `docs/104_COMPLETION_LEDGER_RECONCILIATION_AUTHORITY_ADDENDUM.md`.

Canonical top-level completion remains 16 equal 6.25% buckets. Setup/Payoff is one bucket containing exactly 12 canonical chain items. Global weighting is category-based, not raw-ID weighted. Old 48 Fault / 28 Pulse / 30 Vault / K02=30 / Drift=13 literals are superseded where conflicting.

Issue #8 is design complete. Runtime Completion Ledger / Save / IDE evidence remains future work.

## Issue #9 Setup/Payoff — locked decisions

### Decision #1 — semantic state authority — `docs/112`

- stable ID `setup.<region>.<slug>`;
- source systems own facts; Setup/Payoff evaluates rather than shadow-copies them;
- lifecycle: Dormant -> Primed -> Committed -> Payoff Available -> Resolved;
- exceptional classifications: Unavailable and Superseded;
- valid choices/non-intervention cannot silently make 100% impossible;
- save/load reconciles from semantic identity, source facts, legitimate chain-owned history, and migration;
- dedicated Setup/Payoff System IDE/workbench is required.

### Decision #2 — commit boundaries — `docs/113`

- commit is an explicit semantic physical/social/operational/catastrophe boundary;
- save/autosave, map unload, dialogue/cutscene end, checkpoint, Hush entry/exit, and generic story phases are never implicit generic commits;
- commit/recovery must be atomic and idempotent;
- death/retry follows authoritative checkpoint/save semantics;
- committed history is not casually rewritten by later present-day changes.

### Decision #3 — payoff materiality — `docs/114`

- canonical payoff requires at least one meaningful player-perceivable downstream difference in authoritative game state;
- consequence strength is qualitative, not a fixed number of surfaces/systems;
- spatial, operational, social, epistemic, relationship, decision-space, prevention, negative, or other authored consequences may qualify;
- rewards/dialogue/presentation cannot substitute for genuine underlying state change;
- reconvergence may unify the present but cannot falsify the past.

### Decision #4 — twelve-chain portfolio — `docs/115`

Regional allocation remains 3/2/2/2/1/1/1 across Brindle/Circuit, Rootmere, Saltreach, Emberstep, High Aerie, Mireglass, Cairnfall.

Story structure remains 3 mandatory / 9 optional-for-story, all 12 completion-bearing.

Mandatory chains:
- S03 Common Measure
- S06 Manual Fog Code
- S08 Maker Marks

Key reconciliations:
- S07 primary payoff = local-vs-central pressure control/community operational autonomy, NOT another moving deep-inlet refuge as the main result;
- S10 primary payoff = distributed agency/knowledge, not merely a backup copy surviving;
- S01 Crooked Fire Bell = flagship vertical-slice chain;
- prototype set = S01, S06, S11.

### Decision #5 — authoring/data authority — `docs/116`

- one canonical semantic-ID authored definition per chain, intended as UE5.8 Primary Data Asset architecture;
- authored definition and runtime/save history are separate;
- transient lifecycle truth is derived where possible rather than blindly persisted;
- durable chain history is minimal commit/resolution receipt state plus migration provenance;
- predicates are declarative/typed with named deterministic source-owned provider escape hatches;
- arbitrary per-chain Blueprint authority, Actor/map-path authority, hidden callbacks, and duplicate hand-maintained registries of truth are forbidden;
- shared System IDE provides authoring validation, dependency tracing, variant exercise, save/reload matrices, unexpected-order testing, and Explain Current State.

### Decision #6 — prototype instantiation — `docs/117`

S01 Crooked Fire Bell:
- elective physical chain;
- commit when final repair returns to service after verification;
- standardized and locally tuned normal variants;
- skipped pre-Grand-Ring C01 can become Superseded rather than a fabricated commit;
- equivalent post-Stillness resolution remains completion-valid;
- Mara availability cannot erase physical truth.

S06 Manual Fog Code:
- mandatory operational chain with one normal committed variant;
- proves Setup/Payoff does not require binary choice;
- commit only after local code is verified against actual current coast;
- canonical story progression cannot claim C10 complete while required setup service remains unfinished.

S11 Personal Provenance:
- road-to-Cairnspire mirror/traveler = seed;
- Cairnspire civic registration = semantic commit opportunity;
- variants personal_provenance / anonymous_salvage;
- named provenance gives an interpretive advantage later; anonymous history retains authored Palinode/Mirror reconstruction path;
- both remain completion-valid and may later reconverge without erasing history.

## Issue #9 closure

`docs/118_SETUP_PAYOFF_ISSUE_9_CLOSURE_AUDIT.md` maps every original Issue #9 acceptance criterion.

Design/documentation acceptance is satisfied after the closure package merges:
- data shape documented;
- 3 Stillring-specific prototypes written;
- failure/reload behavior defined;
- writers can author without node-path hardcoding;
- S01 is the canonical naturally noticeable vertical-slice design.

The vertical-slice **runtime/player proof is NOT complete** merely because its design is complete.

Once the closure PR merges, close Issue #9 as **completed — design/documentation complete, runtime evidence pending implementation/verification tracks**.

## NEXT unresolved design issue

**Issue #10 — traversal transformation/mastery loop.**

Do not start by inventing mechanics in isolation. First read Issue #10 plus progression/tool/traversal authorities and research comparable modern adventure traversal mastery systems. Preserve Stillring's existing rules:

- authored traversal progression;
- new verbs reopen remembered places;
- ordinary Sprint has no stamina tax;
- no baseline universal free climbing;
- tools/capabilities do not silently universalize traversal;
- Zelda lineage is a design-problem reference, not copied expression;
- Assassin's Creed movement may inform locomotion feel only where it does not swallow puzzle/traversal authorship;
- every repeatedly tuned/stateful major traversal system needs its own System IDE/workbench and deterministic fixtures.

Issue #11 Null Meridian synthesis trial matrix follows Issue #10.

## Repository truth / stale-document rule

Older authored docs remain valuable for content, but newer authority addenda control conflicts.

In particular:
- `docs/104` controls completion counts/weighting over older `docs/10`–`docs/14` literals;
- `docs/112`–`docs/118` control Setup/Payoff state, commit, payoff, portfolio, authoring, prototypes, and closure over older shorthand in `docs/11`, `docs/12`, or regional story files;
- `docs/119` is the compact Setup/Payoff decision-register addendum.

Do not mechanically rewrite long authored docs merely to remove every historical literal unless a scoped cleanup plan proves the rewrite is safe. Prefer explicit authority/supersession unless the old text creates an actual implementation hazard.

## Governing constraints

- Unreal Engine 5.8 target
- C++ first; thin Blueprints
- System IDE first-class: build the system and its in-game workbench together
- no retail AI/API dependency
- clean-room IP discipline
- authored world over procedural duplication
- no hidden morality meter
- no ordinary traversal stamina tax
- save/world facts use stable semantic IDs
- human play is final authority for feel, clarity, pacing, emotional impact, and whether a payoff is naturally noticed

**Build the system and its in-game IDE together.**
