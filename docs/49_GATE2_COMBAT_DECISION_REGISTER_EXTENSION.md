# 49 — Gate 2 Combat Decision Register Extension

**Status:** TEMPORARY REGISTER EXTENSION / LOCKED AUTHORITY INDEX  
**Updated:** 2026-09-05  
**Purpose:** Records the completed Gate 2 player-combat Decisions #1–#11 without replacing the large root `docs/18_PROJECT_DECISION_REGISTER.md` through the connector. When a normal git workspace is available, fold these rows into `docs/18` mechanically and retire this extension.

| ID | Status | Decision | Authority |
|---|---|---|---|
| C-001 | LOCKED | Accepted attacks use authoritative Startup → Active → Recovery with explicit source-phase→destination cancel permissions. Gameplay owns legality; animation presents/timestamps it and cannot extend lockout by clip length. | `docs/37_GATE2_COMBAT_COMMITMENT_CANCEL_ADDENDUM.md` |
| C-002 | LOCKED | Representative Light uses three authored entries, one press→one strike, explicit continuation windows, at most one near-window continuation, no hold-auto-combo/FIFO, and target changes only affect future entries. | `docs/38_GATE2_COMBAT_LIGHT_CHAIN_ADDENDUM.md` |
| C-003 | LOCKED | Representative Heavy is a separate fixed press-to-commit action family with greater commitment, stricter cancellation, reduced late facing correction, authored movement, and meaningful miss/recovery consequence; it does not assume stamina/posture/hyper armor. | `docs/39_GATE2_COMBAT_HEAVY_COMMITMENT_ADDENDUM.md` |
| C-004 | LOCKED | Ordinary Guard is a directional front-sector defensive state, Hold by default with equivalent Toggle accessibility, reliable for eligible frontal guardable hits, with Guard Reaction/reduced movement as its baseline cost and no passive stamina/posture drain. | `docs/40_GATE2_COMBAT_GUARD_MODEL_ADDENDUM.md` |
| C-005 | LOCKED | Evade is a one-press position-first committed displacement with collision-honest movement, vulnerable entry/recovery, and a short central combat-immunity forgiveness interval; it is separate from Sprint and has no stamina tax or evade-chain loophole. | `docs/41_GATE2_COMBAT_EVADE_MODEL_ADDENDUM.md` |
| C-006 | LOCKED | Incoming damage and reaction are resolved separately through explicit `ReactionForce`/result classes; stronger reactions can interrupt/escalate, equal/lower repeated hits cannot indefinitely reset control loss, and Death is highest priority. | `docs/42_GATE2_COMBAT_HIT_INTERRUPT_ADDENDUM.md` |
| C-007 | LOCKED | Perfect Guard is a fresh precision-timed Guard layer above viable ordinary Guard: success skips ordinary Guard Reaction and preserves tempo but does not auto-counter, generically stun, reflect all projectiles, slow time, or spend a resource. | `docs/43_GATE2_COMBAT_PERFECT_GUARD_ADDENDUM.md` |
| C-008 | LOCKED | Input buffering is a short transition-specific pre-open aid with one global pending combat intent maximum, deterministic replacement, no FIFO/mash extension, revalidation at execution, and aggressive clearing on interrupt/death/context invalidation. | `docs/44_GATE2_COMBAT_INPUT_BUFFER_ADDENDUM.md` |
| C-009 | LOCKED | Attack-facing assistance is bounded gameplay authority: modest early correction for Light, stricter acceptance/early correction for Heavy, no Active tracking, rear 180° snap, translation/vacuum/orbit/reach extension, or root-motion authority leakage; Standard/Reduced/Off preserve legality. | `docs/45_GATE2_COMBAT_ATTACK_FACING_ADDENDUM.md` |
| C-010 | LOCKED | Gate 2 core combat has no universal player stamina/posture/integrity meter gating Light, Heavy, Guard, Perfect Guard, Evade, Sprint, or Jump; future resources must be earned by concrete verbs or observed degeneracy rather than genre convention. | `docs/46_GATE2_COMBAT_RESOURCE_MODEL_ADDENDUM.md` |
| C-011 | LOCKED | Death is the highest-priority authoritative player-combat terminal state, immediately clearing all transient combat state/lock/pending input/immunity; retry restores a fresh combat-local baseline through external checkpoint/save/world-state authority rather than acting as a combat rewind. | `docs/47_GATE2_COMBAT_DEATH_RETRY_ADDENDUM.md` |
| C-012 | LOCKED | The cumulative player combat state model and legal/conditional/illegal transition matrix are reconciled in `docs/48`; Issue #3 acceptance criteria are satisfied without final balance, final animation, or enemy-AI policy. | `docs/48_GATE2_COMBAT_STATE_MODEL.md` |

## Mechanical consolidation debt

When a normal git workspace is available:
1. fold C-001 through C-012 into `docs/18_PROJECT_DECISION_REGISTER.md` in order;
2. verify every row against `docs/37`–`docs/48`;
3. retire this extension;
4. do not reopen combat policy merely because the register is being mechanically consolidated.
