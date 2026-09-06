# 147 — Stale Literal / Reference Audit

**Status:** DOCUMENTATION CLOSURE PHASE 3 — ACTIVE BLOCKLIST / AUDIT  
**Updated:** 2026-09-05  
**Baseline main:** `22b4074e3d08358b302fd7a518773803f303990f`

## Purpose

This audit records known repository text that remains useful as historical/design context but must not be consumed literally by implementation.

It complements:

- `docs/104_COMPLETION_LEDGER_RECONCILIATION_AUTHORITY_ADDENDUM.md`;
- `docs/105_COMPLETION_DECISION_16_CLEANUP_AUDIT.md`;
- `docs/109_COMPLETION_LEGACY_LITERAL_BLOCKLIST.md`;
- `docs/134_NULL_MERIDIAN_SCENE_ORDER_PRECEDENCE_ADDENDUM.md`;
- `docs/137_SUPERSESSION_GRAPH.md`.

Core rule:

> **A stale sentence may remain for provenance. A stale implementation constant may not.**

---

# 1. Confirmed repaired reference

`docs/82_SAVE_STATE_TAXONOMY_OWNERSHIP_ADDENDUM.md` previously referenced the nonexistent:

`docs/69_GATE3_TOOL_PUZZLE_CUMULATIVE_SPECIFICATION.md`

It has been repaired to the real canonical file:

`docs/69_GATE3_TOOL_SYSTEM_CUMULATIVE.md`

This was a safe filename repair only; no gameplay design changed.

---

# 2. Completion literals — hard blocklist

The following are forbidden as active implementation authority:

| Stale literal / interpretation | Canonical replacement | Authority |
|---|---|---|
| 48 Resonance Faults | **36** | docs 90/104 |
| 28 Pulse Shards | **18** | docs 91/104 |
| 30 Micro-vaults | **24** | docs 93/104 |
| K02 Fine Fork at 30 Faults | **24 reconciled Faults** | doc 104 |
| Drift Knot eligibility at 13 Faults | **10 reconciled Faults + existing story/Line Skiff prereqs** | docs 100/104 |
| 12 Unstandard Tool stages = 12 global completion items | **1 global item / 12 internal stages** | doc 104 |
| 7 Broken Standard Yard commissions = 7 global completion items | **1 global item / 7 internal commissions** | doc 104 |
| raw-ID global weighting | **16 equal top-level categories, each 6.25%** | doc 104 |

Any code/data/fixture/registry using the stale side of this table is wrong even if an older document still contains it.

---

# 3. Known active documents containing historical/stale completion prose

These files remain useful but are not safe standalone numeric authority.

| File | Known risk | Safe consumption rule |
|---|---|---|
| `docs/10_COMPLETION_MODEL.md` | old 48-Fault language remains in portions of the file | use for conceptual completion rhythm only; numeric authority = doc 104 |
| `docs/11_QUEST_AND_COMPLETION_LEDGER.md` | legacy count/allocation tables remain | semantic content may be reused; counts/weights/thresholds subordinate to docs 89–104 |
| `docs/12_100_PERCENT_ROUTE.md` | old summary totals remain in route table/prose | route logic may be useful; numeric totals subordinate to doc 104 |
| `docs/13_CANTOR_AND_UPGRADE_CATALOG.md` | K02 source still reflects older Fault threshold | upgrade content remains useful; K02 threshold = 24 reconciled Faults |
| `docs/14_PRESTIGE_AND_MASTERY_CONTENT.md` | old 13-Fault Drift unlock | content catalog remains useful; eligibility = current doc 104 rule |

### Why these are not blindly rewritten here

These are broad authored planning/content documents. Mechanical global replacement can corrupt historical explanation, prose context, or unrelated numeric references.

Until a fidelity-safe full-file reconciliation is performed, the explicit precedence/blocklist is the safer authority boundary.

No implementation agent should parse these files for counts without first applying doc 104/109 precedence.

---

# 4. Null Meridian scene-order stale shorthand

Older story ledgers may summarize the M16 finale in an earlier ordering such as paired trials / archive / Maelor shorthand.

Exact current finale order is governed by:

- docs 127–133 for the locked Null Meridian decisions;
- **doc 134 for exact scene-order precedence**.

Any older M16 shorthand that conflicts with the approved S1–S6 sequence is historical/superseded for exact ordering.

Do not rewrite semantic story facts that are unaffected by the order correction.

---

# 5. Setup/Payoff stale interpretations

## S07 Pressure Release

Superseded interpretation:

- another moving-refuge / moving-pocket payoff.

Current authority:

- the setup still concerns independent old pressure bypass versus central reconnect;
- the payoff is primarily **operational autonomy/control/labor**;
- independent deep-inlet crews retain manual pressure authority and can create their own low-water work/rescue/salvage windows;
- reconnected main dock gains better pressure resilience/heavy-service capacity, while deep-inlet crews lose independent control and need coordinated assistance.

Authority: `docs/115_SETUP_PAYOFF_PORTFOLIO_AUTHORITY_ADDENDUM.md`.

## S10 Distributed Copy

Dangerous simplification:

- “a duplicate record survives.”

Current authority:

- payoff is distributed **agency/knowledge**;
- ordinary people/novices can challenge or act before archive authority returns;
- consequences may affect recognition, action, testimony standing, rescue/triage timing.

A mere backup-copy survival beat is insufficient.

Authority: doc 115.

## S11 Personal Provenance

Older “First Circuit traveler” wording may describe seed/context.

Current semantic classification commit occurs during the Cairnspire civic-registration period under the prototype authority.

Authority: docs 117/119.

---

# 6. Gate 1 camera deferred-language trap

Some early camera/combat documents say later topics are “deferred.”

A keyword search for `deferred` is not enough to determine current status.

Example:

- earlier camera authority deferred generic first-person/precision aim/gyro;
- `docs/35_GATE1_CAMERA_AIM_MODE_BOUNDARY_ADDENDUM.md` later resolved the policy as an **explicit absence for Gate 1** unless a concrete future verb earns a new contract.

Therefore this is not an open Gate 1 TODO.

Similarly, older combat docs may say Perfect Guard is deferred; later combat authority resolves it.

Rule:

> Always check the cumulative/later scoped authority before promoting an old “deferred” sentence into the current question queue.

---

# 7. Hush prototype-architecture trap

Dangerous inference:

> “World Partition + Runtime Data Layers appeared in the prototype, therefore production architecture is already chosen.”

Current truth:

- semantic Hush/Waking authority is locked;
- WP/RDL is a prototype direction;
- production representation requires evidence and comparison against another credible approach;
- Data Layer activation is presentation/streaming state, never canonical quest/world truth.

Do not let a prototype implementation detail become authority merely through reuse.

---

# 8. Blueprint / Actor-path traps

The following must never become canonical identity/authority simply because they are convenient during prototyping:

- Blueprint class names as persistent semantic IDs;
- Actor object paths;
- map package paths;
- runtime instance IDs;
- display strings;
- raw coordinates;
- overlap/callback order;
- Data Layer activation state;
- current UI state;
- animation state.

Stable project-owned semantic IDs and declared gameplay owners remain authority.

---

# 9. System IDE trap

Dangerous implementation shortcut:

> “The IDE can just keep its own debug copy of the state so we can manipulate it easily.”

Forbidden.

System IDE workbenches must use the same authoritative gameplay services used by normal play.

Session overrides may exist for tuning, but their provenance must be explicit and they may not become a second hidden rules engine.

Authority: `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`, Issue #58, docs 139–141.

---

# 10. Stale-reference validation to add during implementation

Repository/runtime validation should eventually catch at least:

- forbidden completion literals in active data registries/config;
- semantic IDs missing from current registries;
- Actor/map/node path used as persistence identity;
- duplicate owner registration for one durable fact;
- Setup/Payoff definition relying on arbitrary Blueprint callback authority;
- completion registry count mismatch against canonical category totals;
- Route Listener unlocked before 12/12 Drift Knots;
- Drift eligibility using 13 instead of 10 reconciled Faults;
- K02 threshold using 30 instead of 24;
- Null Meridian fixture/order using stale M16 sequence;
- Hush implementation treating Data Layer state as semantic truth;
- System IDE-only shadow state.

These should become machine checks where practical rather than permanent reliance on human memory.

---

# 11. Safe rewrite policy after implementation begins

Direct cleanup of old broad documents is allowed later when:

1. the whole file can be read/reconciled with high fidelity;
2. historical discussion is preserved or clearly marked;
3. unrelated numbers are not mechanically changed;
4. authored quest/story/content is not deleted to satisfy a count change;
5. the diff is reviewed against current authority;
6. runtime/data registries already use canonical values so documentation cleanup cannot change game behavior unexpectedly.

Until then, explicit scoped precedence is safer than pretending every historical document has been physically normalized.

---

# 12. Audit conclusion

The known stale items are currently **contained** by explicit authority/blocklists, with the confirmed dead Gate 3 filename repaired.

No additional gameplay design decision is required to interpret the known stale completion counts, Setup/Payoff interpretations, Hush ownership, Gate 1 aim boundary, or Null Meridian order.

The remaining risk is implementation discipline:

> **implementation must consume the authority index and blocklists rather than whichever older file happens to contain the easiest literal to copy.**