# 91 — Completion Decision #3 — Pulse Shard Survivability Authority

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #8 — Define 100% completion taxonomy and persistence contract  
**Decision:** #3 — Pulse Shard target count, survivability meaning, installation cadence, distribution, IP distinction, persistence, accessibility, IDE, and anti-power-creep constraints

## Decision question

What does a Pulse Shard actually do, how many should exist, and how do we keep this optional survivability track useful without making it a disguised Heart Piece / Health Container system or forcing 100% cleanup for ordinary difficulty?

## Fresh research conclusion

The current 28-Shard target is too large for a permanent survivability track. **Stillring ships 18 Pulse Shards.**

Each Pulse Shard is a complete field-harness reinforcement insert. It is **not a fragment**, is **not combined in fixed groups**, and does **not** get exchanged for a separate container.

The mechanical effect is a small permanent increase to Neris's **maximum Field Harness Integrity** — Stillring's ordinary damage-survivability ceiling. This is a direct, readable improvement, but the game is balanced so a normal critical-path player does not need anything close to all 18.

Comparative research informed two boundaries:
- Metroid Dread demonstrates the clarity of direct health-capacity upgrades while separately offering difficulty/accessibility adjustments; optional survivability can be useful without becoming the only difficulty control.
- Breath of the Wild's shrine-orb exchange into Heart Containers/Stamina Vessels is a recognizable Zelda expression. Stillring explicitly rejects fixed fragment groups, shrine-like exchange structure, heart iconography, and health-vs-stamina purchase choice.

## Locked philosophy

> **Every Shard is a complete reinforcement, not one quarter of permission to survive.**

## Shipping target — 18

The former 28 target is **SUPERSEDED** by this addendum.

Canonical regional allocation:

| Region / phase | Pulse Shards |
|---|---:|
| Brindle / Cairnspire / First Circuit | 3 |
| Rootmere | 3 |
| Saltreach | 3 |
| Emberstep | 3 |
| High Aerie | 2 |
| Mireglass | 2 |
| Cairnfall | 1 |
| Still-Cairn / Null Meridian | 1 |
| **Total** | **18** |

Rationale:
- survivability help is front/mid-loaded rather than hidden mostly in late cleanup;
- all major regions retain at least one authored reinforcement opportunity;
- late regions stop showering the player with raw survivability once combat mastery and broader systems are already mature;
- fewer Shards allow each source to remain memorable and avoid making permanent-stat pickups a default reward for unrelated side content.

## Mechanical meaning

### Field Harness Integrity
Pulse Shards increase the maximum integrity of Neris's field harness — the canonical player damage-survivability ceiling used by combat/environmental damage systems.

This is conceptually ordinary maximum health, but its fiction/presentation belongs to Neris's repairable field harness rather than anatomy, hearts, souls, or magical life pieces.

Rules:
- every installed Shard contributes immediately;
- there is no collect-four / collect-N conversion step;
- there is no health-versus-stamina purchase choice;
- Shards do not increase attack damage, Guard quality, evade windows, Sprint duration, tool power, or traversal eligibility;
- Shards do not create a separate regenerating shield meter unless a future explicit system decision adds one;
- current integrity and maximum integrity remain distinct state; installing a Shard may restore only the newly added capacity, not silently full-heal the player.

Exact per-Shard numeric gain remains balance tuning. The design target is that **18/18 should produce a meaningful but bounded survivability advantage, not double or triple the baseline durability.**

Prototype target band for human balance testing: full collection should land roughly in the **+30% to +40% maximum-integrity range** relative to zero optional Shards. This band is a tuning hypothesis, not a shipped constant.

## Critical-path balance rule

Stillring may not balance ordinary mandatory encounters around 18/18 Shards.

Difficulty/balance assumptions:
- critical-path encounters must remain reasonably beatable with only naturally encountered / low-exploration Shards;
- optional Shards provide forgiveness and exploration reward, not a hidden mandatory grind tax;
- late bosses may acknowledge a range of integrity values but may not require a completionist maximum;
- accessibility/difficulty tuning remains independent of Shard collection and must not tell struggling players to scour the map for permanent HP before they can proceed.

Human combat balance should test at minimum:
1. zero optional Shards beyond unavoidable story acquisition, if any;
2. plausible critical-path incidental count;
3. roughly half collection;
4. 18/18.

## Acquisition / installation flow

A Shard is obtained as a unique authored reward or discovered object and becomes owned immediately.

Installation occurs automatically at the next valid **Bellwright Refuge service interaction** unless the player chooses an explicit immediate-install interaction where fiction supports it. The purpose of refuge installation is world coherence and readable feedback, not resource gating.

Installation requires:
- no currency;
- no random material;
- no duplicate farmable component;
- no fixed-size bundle of Shards;
- no mutually exclusive upgrade choice.

If a Shard is owned but not installed, the UI/journal must make that state obvious. Save/load cannot lose or duplicate the pending installation.

## Source quality rules

Pulse Shards are rewards, not a standalone puzzle grammar. Their source must come from another authored activity or a meaningful exploration promise.

Valid source families include:
- Repair Contract resolution;
- Skill Trial mastery;
- authored route/exploration discovery;
- Micro-vault reward;
- refuge service challenge;
- later cross-state payoff where the Shard makes narrative/mechanical sense.

Hard rule: **not every side activity gets a Pulse Shard.** The existing side-interaction rebalance authority remains intact.

When the 28→18 budget is reconciled, cuts should remove redundant Shard rewards from content that already has a stronger bespoke reward rather than deleting good quests/spaces merely to preserve old reward placement.

## IP / visual-language distinction

Forbidden Pulse Shard expression:
- heart-shaped collectible;
- quarter-heart / fixed fragment-group math;
- heart-container presentation;
- shrine token exchange structure;
- health-or-stamina purchase choice;
- Zelda-like fanfare/presentation cadence;
- HUD heart row.

Required Stillring expression:
- ceramic/metallic reinforcement geometry consistent with bellwright craft;
- visible mounting/contact features that imply it fits the field harness;
- refuge bench/service animation built around inspection/fitting/calibration;
- integrity presentation using project-owned gauge/segment/industrial instrumentation language;
- audio/visual feedback grounded in tension, resonance, fastening, calibration, and stable load.

Generic permanent health upgrades are a common game mechanic. The project distinction comes from fiction, acquisition grammar, object form, installation, UI, sound, counts, and progression cadence.

## Persistence ownership

- Shard ownership / installed reinforcement belongs to **Inventory & Tool Progression / Player Progression** under the locked save taxonomy.
- Completion Ledger derives satisfaction of `pulse.<region>.<slug>` from the settled unique acquisition fact.
- Pending-owned-versus-installed state is explicit if installation is deferred.
- semantic Shard identity is stable and never keyed by Actor/package/path/location;
- acquisition is one-shot and idempotent;
- save/reload/retry cannot duplicate the permanent increase or reward;
- migration from the old 28 planning taxonomy must explicitly retire/remap removed IDs before released save compatibility exists.

## Accessibility / readability

Pulse Shard progression must remain readable without requiring color, haptics, or tiny HUD comparison.

Player-facing status should provide:
- total installed integrity reinforcement in plain numeric/gauge terms;
- owned-but-not-installed notice when applicable;
- regional completion count once completion-assist policy unlocks it;
- optional stronger completion hints late game;
- no requirement to infer current/max integrity solely from color.

Damage/accessibility settings operate independently from collection state.

## Completion / Progression IDE requirements

The shared System IDE needs a Pulse Shard view exposing:
- semantic Shard ID;
- source activity / region;
- acquired state;
- installed state;
- owning progression fact;
- resulting max-integrity contribution;
- canonical versus effective tuned contribution;
- one-shot acquisition transaction status;
- Completion Ledger reconciliation;
- duplicate/missing/retired ID validation;
- current total reinforcement and test baseline.

Required fixtures:
1. no Shards;
2. acquired but pending refuge installation;
3. install one Shard and verify only new capacity is added, not a free full heal;
4. save/load before installation;
5. save/load after installation;
6. duplicate acquisition attempt rejected/idempotent;
7. critical-path low-Shard combat balance fixture;
8. 18/18 maximum collection;
9. taxonomy migration with one retired old Shard ID;
10. accessibility display without color/haptic dependency.

## Red-team / rejection conditions

Reject implementation/design that:
- converts Shards into collect-four fragments;
- makes Shards a mandatory damage-check gate;
- gives every quest a Shard because bespoke rewards are harder to design;
- lets full collection massively multiply Neris's survivability;
- ties installation to random/currency grind;
- allows retry/save exploits to duplicate max integrity;
- mixes Tool Mastery Upgrade authority into Pulse Shards;
- changes Sprint/stamina/traversal rules through Shard collection;
- makes difficulty/accessibility settings depend on completion collection;
- uses heart iconography or a heart-container-style UI.

## Documentation reconciliation debt

`docs/10`, `docs/11`, and `docs/12` still contain the superseded **28** planning count. `docs/91` is immediate detailed authority for the Pulse Shard count and semantics. Issue #8 cumulative reconciliation must update all affected completion documents together and choose which 18 of the current 28 authored IDs survive, preserving the strongest source/reward distribution.

No implementation should create 28 production Shard records simply because the older ledgers still list them.

## Approval

**APPROVED / LOCKED under the owner's scheduled-run delegation.**

### Final locked statement

> **Stillring ships 18 complete Pulse Shard reinforcements. Each permanently increases Field Harness Integrity a little, every Shard matters immediately, none are combined into fixed groups, and ordinary game balance never assumes completionist collection. The category is a bounded exploration-for-forgiveness track, not a renamed heart-piece system or mandatory survivability grind.**

## Next decision

Completion Decision #4 — **Local Repair Contract authority: validate the 24-contract target, critical-path/optional split, resolution semantics, density, reward discipline, and completion persistence.**
