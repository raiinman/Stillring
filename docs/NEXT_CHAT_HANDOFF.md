# Stillring — Next Chat Handoff

**Updated:** 2026-09-05  
**Repository:** `raiinman/Stillring`  
**Status:** Gate 1 locomotion/camera, Gate 2 combat/encounter, Gate 3 Tool-Puzzle, Gate 4 Waking/Hush, and Issue #4 persistent world-state/save **design** are COMPLETE / LOCKED. Issue #8 Completion Decision #1 is now LOCKED. Runtime Unreal implementation, platform durability proof, packaged Shipping exclusion, and human acceptance remain UNVERIFIED.

## Read first
1. `docs/89_COMPLETION_CATEGORY_AUTHORITY_ADDENDUM.md`
2. `docs/88_SAVE_WORLD_STATE_CUMULATIVE_SPECIFICATION.md`
3. `docs/10_COMPLETION_MODEL.md`
4. `docs/11_QUEST_AND_COMPLETION_LEDGER.md`
5. `docs/12_100_PERCENT_ROUTE.md`
6. `docs/09_STILLRING_PROGRESSION_BLUEPRINT.md`
7. `docs/18_PROJECT_DECISION_REGISTER.md`
8. `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
9. `ROADMAP.md`
10. GitHub Issue #8 — `Define 100% completion taxonomy and persistence contract`

Always re-check exact current `main` before repository writes.

## Required method
Fresh focused research for exactly one decision → reconcile locked authority/IP/accessibility/failure cases/System IDE/tests → coherent package → scheduled-run approval only when complete → document → inspect exact diff → merge with expected head → only then next decision.

**Work for as long as productively possible in every scheduled wake. Never batch unresolved decisions.**

## Issue #4 save/world-state design — CLOSED AUTHORITY
Detailed decisions:
- `docs/81` stable semantic GUID identity;
- `docs/82` one-owner state taxonomy;
- `docs/83` Save Schema v1;
- `docs/84` migration/versioning;
- `docs/85` integrity/LKG/recovery;
- `docs/86` slots/cadence/retry snapshot;
- `docs/87` Save / World-State System IDE;
- `docs/88` cumulative implementation-facing specification and acceptance matrix.

Final principle:
> **Stillring saves a versioned snapshot of semantic game truth: stable identities, one owner per durable fact, explicit migrations, preserved recovery generations, authored retry checkpoints, and reconstructable world presentation.**

Important boundary: Issue #4 design closure does **not** claim the paired-layer prototype save/exit/reload verification has executed. That remains implementation evidence.

## Issue #8 completion taxonomy

### Completion Decision #1 — completion-bearing category authority — LOCKED
Authority: `docs/89_COMPLETION_CATEGORY_AUTHORITY_ADDENDUM.md`.

Locked philosophy:
> **100% counts authored meaning, not map debris.**

The existing sixteen finite authored shipping categories remain completion-bearing, but each now has an explicit semantic completion measure: resolution, acquisition, discovery+activation, authored outcome, or mastery threshold. Raw POIs, currency/material accumulation, random drops, repeatable score optimization, dialogue exhaustion, and mutually exclusive branch perfection are non-bearing. Regional/global progress are derived views over one Completion Ledger and never duplicate canonical truth.

This decision **does not** lock the current proposed counts, percentage weighting, exact reward thresholds, or final UI formula.

### Completion Decision #2 — Resonance Fault authority — NEXT
Freshly research and decide **Resonance Faults only**:
- whether 48 remains justified for a roughly 20–30 hour authored game;
- regional density and pacing across the current allocation;
- what makes a Fault materially different from a Vault, contract, or generic collectible;
- access-gate/revisit-wave rules;
- staged reward cadence without making Faults compulsory power grind;
- deterministic ID/persistence behavior under Completion Ledger + World State ownership;
- late-game unresolved-count/hint assistance;
- accessibility and anti-frustration requirements;
- Completion IDE Fault diagnostics/fixtures;
- red-team for repetition, icon-vacuum behavior, map cleanup fatigue, and over-weighting.

Do **not** decide Pulse Shards, contract counts, Vault density, records, percentage weighting, or final rewards in the same pass.

## Open design issues after #8
Repository-open design work also includes:
- #9 cross-state setup/payoff framework;
- #10 traversal transformation/mastery loop;
- #11 Null Meridian synthesis trial matrix.

Infrastructure issues #5 and #58 remain implementation tracks and must not displace the methodical design pass simply because they are older issue numbers.

## Governing constraints
- Unreal Engine 5.8.
- C++ first for gameplay/state authority; thin Blueprint presentation.
- System IDE remains first-class production infrastructure.
- No retail runtime AI/model/API dependency.
- Human play is final authority for feel/readability.
- Clean-room IP rules apply.
- Save/world-state semantic ownership is locked and must not be bypassed by completion implementation.

Movement: **Simple intention, capable character, honest world.**  
Camera: **The player should look at Orra, not babysit the camera.**  
Tools: **Cantor explains the relationship. Anchor changes the load.**  
Hush: **One place. One history of facts. Two authored expressions.**  
Save/world-state: **Persist meaning, reconstruct presentation.**  
Completion: **100% counts authored meaning, not map debris.**  
System IDE: **Build the system and its in-game IDE together.**
