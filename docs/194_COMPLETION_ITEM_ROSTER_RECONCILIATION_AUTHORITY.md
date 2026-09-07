# 194 — Completion Item Roster Reconciliation Authority

**Status:** CANONICAL / STUDIO-HANDOFF CLOSURE / DOCUMENTATION-ONLY  
**Updated:** 2026-09-07  
**Parent program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Closes:** `CONTENT-ROSTER-RECONCILIATION-001` and the item-level portion of `SH-CONT-005`  
**Count authority:** `docs/90`, `docs/91`, `docs/93`, `docs/104`  
**Legacy item source:** `docs/11_QUEST_AND_COMPLETION_LEDGER.md`  
**Boundary:** no UE5.8 implementation, map placement, production art, balance, runtime migration proof, or human-play evidence is authorized or claimed.

---

# 1. Purpose

Completion Decision #16 locked the shipping totals at:

- **36 Resonance Faults**;
- **18 Pulse Shards**;
- **24 Micro-vaults**.

The older item ledger still enumerated the pre-reduction rosters.

That left one dangerous production ambiguity:

> **Which semantic IDs actually survive into the shipping content plan?**

A studio cannot safely author regional completion content, build registries, estimate remaining burden, or create migration fixtures while the count says 36/18/24 but the item ledger still names the old candidates.

This document closes that ambiguity.

It does not merely repeat the new totals. It identifies every retained semantic ID, every retired legacy ID, and the one late Fault reclassification required to make the locked regional allocations internally consistent.

---

# 2. Governing selection rules

The reconciliation follows the already-locked category authorities rather than preserving old entries by inertia.

## Resonance Fault rules

From `docs/90`:
- a Fault is a local world defect worth diagnosing;
- shipping count is 36;
- regional allocation is 6 / 5 / 5 / 5 / 4 / 4 / 4 / 3;
- fewer, more varied Faults are preferred to a cleanup track;
- duplicate quest/fault premises and repeated templates should be cut;
- Faults should cover materially different mechanical/state families.

## Pulse Shard rules

From `docs/91`:
- shipping count is 18;
- regional allocation is 3 / 3 / 3 / 3 / 2 / 2 / 1 / 1;
- Shards are rewards, not a separate puzzle grammar;
- redundant Shard rewards should be removed from content that already has a stronger bespoke reward;
- all major regions retain at least one reinforcement opportunity.

## Micro-vault rules

From `docs/93`:
- shipping count is 24;
- regional allocation is 5 / 4 / 3 / 3 / 3 / 2 / 2 / 2;
- each Vault must justify one compact 1–5 minute authored idea;
- weak cache-like spaces and duplicate nearby templates should be cut;
- discovery and rewards cannot be the only reason the space exists.

## Reconciliation rule

A removed reward placement does **not** delete the associated Contract, Trial, Refuge, story beat, or region content unless another authority separately says so.

A removed Fault or Vault ID means that specific completion-bearing obligation is retired. Its useful geometry, clue, prop, or narrative premise may still be absorbed into another authored activity without retaining a second completion ID.

---

# 3. Resonance Fault shipping roster — 36

## 3.1 Brindle / Cairnspire / First Circuit — 6

| Semantic ID | Short name | Disposition reason |
|---|---|---|
| `fault.brindle.bell_shed_eave` | Bell-Shed Double Ring | retain — early acoustic/diagnostic identity |
| `fault.brindle.old_mill_tailrace` | Tailrace Tension Hum | retain — remembered Anchor revisit |
| `fault.graymile.toll_chime` | Toll Chime Aftertone | retain — compact base-language example |
| `fault.cairnspire.late_warning_duct` | Late Warning Echo | retain — capital infrastructure identity |
| `fault.viaduct.refuge_spandrel` | Spandrel Counterpull | retain — structural/load family |
| `fault.circuit.old_route_marker` | Moving Route Marker | retain — changed-world + Line Skiff family |

### Retired First Circuit Faults

- `fault.graymile.bypass_joint` — retired as a separate Fault because Graymile already carries C03 / S02 authored bypass history; keep useful Palinode evidence inside that content rather than double-counting the same place.
- `fault.cairnspire.pressure_lift` — retired as a separate Fault because Fourth Landing / C05 already owns the pressure-lift human and mechanical premise.

---

## 3.2 Rootmere — 5

| Semantic ID | Short name | Disposition reason |
|---|---|---|
| `fault.rootmere.cathedral_seed_gallery` | Seed Gallery Residue | retain — post-dungeon regional residue |
| `fault.rootmere.floodgate_crown` | Floodgate Crown Strain | retain — Anchor/load family |
| `fault.rootmere.deep_sluice` | Deep Sluice Bubble | retain — pressure/fluid family |
| `fault.rootmere.resin_brace` | Resin-Brace Heat Memory | retain — thermal/material family |
| `fault.rootmere.hush_bell_oak` | Bell-Oak Seam | retain — Waking/Hush shared semantic family |

### Retired Rootmere Faults

- `fault.rootmere.ferry_rootfork` — retired as a separate Fault because C07 Widow's Ferrygate already owns the ferry-gate load problem.
- `fault.rootmere.remembered_orchard` — retired as a separate Fault because C08 and Rootmere's orchard history already carry the seasonal/two-state premise; Mirror evidence can remain without a second completion obligation.

---

## 3.3 Saltreach — 5

| Semantic ID | Short name | Disposition reason |
|---|---|---|
| `fault.saltreach.foundry_catwalk` | Catwalk Pressure Ring | retain — Tide Foundry aftermath |
| `fault.saltreach.ballast_pipe` | Ballast Pipe Tension | retain — structural/pressure relationship |
| `fault.saltreach.boiler_hulk` | Cold Boiler Heatprint | retain — thermal/material family |
| `fault.saltreach.unbuilt_pier` | Unbuilt Pier Reflection | retain — Mirror/history family |
| `fault.saltreach.deep_tide_seam` | Deep Tide Seam | retain — late seam family |

### Retired Saltreach Faults

- `fault.saltreach.fog_tower_foot` — retired as a separate Fault because C10 already owns the false-direction fog-tower problem.
- `fault.saltreach.lowwater_cistern` — retired to reduce pressure/fluid repetition; Saltreach already retains foundry, ballast and other pressure content.

---

## 3.4 Emberstep — 5

| Semantic ID | Short name | Disposition reason |
|---|---|---|
| `fault.emberstep.slag_canal` | Slag Canal Overtone | retain — early regional acoustic/material identity |
| `fault.emberstep.hanging_mold` | Hanging Mold Counterpull | retain — Anchor/load family |
| `fault.emberstep.quench_manifold` | Quench Manifold Backpulse | retain — pressure/thermal interaction |
| `fault.emberstep.erased_maker_wall` | Erased Maker Chorus | retain — Palinode/history family |
| `fault.emberstep.ghost_casting_floor` | Casting Floor Double State | retain — Mirror/state family |

### Retired Emberstep Faults

- `fault.emberstep.kiln_lift` — retired because the post-Kiln lift-delay premise is weaker than the retained cross-tool regional set and competes with dungeon aftermath content.
- `fault.emberstep.cold_forge` — retired because C15 Cold Kiln already owns the strongest uneven-heat / useful-variance premise.

---

## 3.5 High Aerie — 4

| Semantic ID | Short name | Disposition reason |
|---|---|---|
| `fault.highaerie.updraft_gallery` | Broken Updraft Loop | retain — Vane traversal family |
| `fault.highaerie.archive_false_shelf` | False Shelf History | retain — Palinode/archive family |
| `fault.highaerie.varo_memorial` | Heroic Reset | retain — Mirror/official-memory contradiction |
| `fault.highaerie.storm_seam` | Storm Blind Seam | retain — seam family |

### Retired High Aerie Faults

- `fault.highaerie.chainhouse_lower` — retired because C19 already gives suspension-chain diagnosis a stronger human/work context.
- `fault.highaerie.tempest_rod` — retired to prevent the region's optional ledger from over-weighting wind/timing variants after Vane acquisition.

---

## 3.6 Mireglass — 4

| Semantic ID | Short name | Disposition reason |
|---|---|---|
| `fault.mireglass.diplomat_cistern` | Diplomat Cistern Voice | retain — pressure/voice-history relationship |
| `fault.mireglass.mirror_hall` | Mirror Hall Contradiction | retain — Palinode contradiction family |
| `fault.mireglass.false_veranda` | Veranda With No House | retain — Mirror spatial-history family |
| `fault.mireglass.buried_seam` | Reed-Bed Seam | retain — seam family |

### Retired Mireglass Faults

- `fault.mireglass.reed_causeway` — retired as the least differentiated general movement/echo premise in a region already dense with memory-state content.
- `fault.mireglass.widow_chamber` — retired as a separate completion ID because the Mirror Widow encounter already owns the strongest shared-memory chamber burden.

---

## 3.7 Cairnfall — 4

| Semantic ID | Short name | Disposition reason |
|---|---|---|
| `fault.cairnfall.outer_lenswalk` | Lenswalk Crosswind Error | retain — Vane/crosswind family |
| `fault.cairnfall.starweight` | Starweight Tension Drift | retain — Anchor/load family |
| `fault.cairnfall.abandoned_prediction` | Prediction Made Physical | retain — Mirror/prediction-history family |
| `fault.cairnfall.null_well` | Null Observation Well | retain — seam/null-observation family |

### Retired Cairnfall Fault

- `fault.cairnfall.correction_ring` — retired as a separate Fault because the Gravemoon Engine already owns the region's central correction-versus-local-rate argument; the optional track should not repeat the boss thesis as a smaller completion item.

---

## 3.8 Still-Cairn / Null Meridian — 3

| Semantic ID | Short name | Source / disposition |
|---|---|---|
| `fault.stillcairn.unbuilt_station` | Station That Almost Opened | retain from legacy Fault roster |
| `fault.stillcairn.unreleased_room` | Unreleased Room | **reclassified from the legacy authored activity behind `pulse.stillcairn.unreleased_room`**; the deliberate-release puzzle is a better Fault grammar than a generic survivability reward placement |
| `fault.nullmeridian.worker_bypass` | Court Worker Bypass | retain from legacy Fault roster; ordinary labor/service-world identity |

### Reclassification rule

`fault.stillcairn.unreleased_room` is a new canonical completion ID for an already-existing authored late-game premise: the optional deliberate-release room named in the legacy Pulse Shard ledger.

It is not an invented fourth late activity.

The old reward ID `pulse.stillcairn.unreleased_room` is retired in Section 4 because the activity now has a stronger category identity.

---

# 4. Pulse Shard shipping roster — 18

## Brindle / Cairnspire / First Circuit — 3

- `pulse.brindle.kite_roof`
- `pulse.brindle.crooked_fire_bell`
- `pulse.circuit.viaduct_trial`

Retired reward placements:
- `pulse.circuit.lantern_inn` — C04 already has a stronger service/world payoff.
- `pulse.cairnspire.public_lift` — C05 already has Refuge/access and upgrade-component rewards; do not stack a generic survivability reward onto it.

## Rootmere — 3

- `pulse.rootmere.ferrygate`
- `pulse.rootmere.cathedral_side`
- `pulse.rootmere.memory_hollow`

Retired:
- `pulse.rootmere.split_orchard` — C08 already has a Pattern/Fault-information payoff; remove redundant Shard reward.

## Saltreach — 3

- `pulse.saltreach.dry_dock`
- `pulse.saltreach.kelp_funeral`
- `pulse.saltreach.fog_trial`

Retired:
- `pulse.saltreach.unbuilt_pier` — the same location remains more valuable as the retained Mirror/history Fault; do not double-reward the same premise with a Shard.

## Emberstep — 3

- `pulse.emberstep.foreman_cup`
- `pulse.emberstep.slag_trial`
- `pulse.emberstep.erased_name`

Retired:
- `pulse.emberstep.cold_kiln` — C15 already carries a stronger Temper/component/service payoff.

## High Aerie — 2

- `pulse.highaerie.cut_rope`
- `pulse.highaerie.storm_blind`

Retired:
- `pulse.highaerie.archive_weight` — C18 already carries Refuge/record consequences and should not receive a generic extra survivability reward by default.

## Mireglass — 2

- `pulse.mireglass.remembered_door`
- `pulse.mireglass.reedwater`

Retired:
- `pulse.mireglass.sunken_witness` — keep the Vault/testimony content without also making its reward a required Shard placement.

## Cairnfall — 1

- `pulse.cairnfall.disagreeing_scope`

Retired:
- `pulse.cairnfall.night_survey` — Refuge calibration remains useful content without a second permanent-stat reward.

## Still-Cairn / Null Meridian — 1

- `pulse.stillcairn.family_stair`

Retired/reclassified:
- `pulse.stillcairn.unreleased_room` — retired as a Shard ID; its authored deliberate-release activity is now `fault.stillcairn.unreleased_room`.

---

# 5. Legacy Pulse count discrepancy

The old ledger declared **28 Pulse Shards** but the enumerated item table in `docs/11` contains only **27 semantic Pulse IDs**:

- First Circuit 5;
- Rootmere 4;
- Saltreach 4;
- Emberstep 4;
- High Aerie 3;
- Mireglass 3;
- Cairnfall 2;
- Still-Cairn 2;
- total enumerated = 27.

This reconciliation does **not** invent a missing 28th legacy Shard merely to make the stale planning count self-consistent.

The canonical shipping roster is the 18 IDs in Section 4.

Any future migration/validation tool should treat “legacy Pulse #28” as **never assigned**, not as a tombstoned semantic ID.

---

# 6. Micro-vault shipping roster — 24

## Brindle / Cairnspire / First Circuit — 5

- `vault.brindle.mill_tailbox`
- `vault.cairnspire.pressure_lift_pocket`
- `vault.viaduct.rope_cage`
- `vault.circuit.tollhouse_echo_niche`
- `vault.circuit.culvert_seam_box`

Retired:
- `vault.graymile.drain_bell` — the weakest cache-like/base-observation premise in the six-entry First Circuit set; useful record/currency material can move into ordinary exploration without a completion-bearing Vault ID.

## Rootmere — 4

- `vault.rootmere.floodgate_cheek`
- `vault.rootmere.silt_choir_shaft`
- `vault.rootmere.resin_lockbox`
- `vault.rootmere.memory_root_hollow`

No cuts required by the locked regional allocation.

## Saltreach — 3

- `vault.saltreach.ballast_tube`
- `vault.saltreach.boiler_shell`
- `vault.saltreach.drowned_ledger_booth`

Retired:
- `vault.saltreach.dry_cistern_lip` — lower distinctiveness after retained Saltreach pressure/Fault content; material/Fault clues can remain in ordinary exploration.

## Emberstep — 3

- `vault.emberstep.suspended_mold_cage`
- `vault.emberstep.quench_throat`
- `vault.emberstep.erased_name_vault`

Retired:
- `vault.emberstep.slag_chute` — material/currency-only reward profile is the weakest match for the one-strong-idea Vault rule.

## High Aerie — 3

- `vault.highaerie.counterweight_loft`
- `vault.highaerie.silent_draft_duct`
- `vault.highaerie.storm_anchor_cell`

No cuts required.

## Mireglass — 2

- `vault.mireglass.reflection_annex`
- `vault.mireglass.sunken_witness_room`

Retired:
- `vault.mireglass.reed_cellar` — material/record premise is least differentiated from ordinary exploration and regional record content.

## Cairnfall — 2

- `vault.cairnfall.starweight_ring`
- `vault.cairnfall.null_observation_pocket`

Retired:
- `vault.cairnfall.correction_well` — too close to the region's central correction-system language and Gravemoon burden; avoid a smaller duplicate of the same idea.

## Still-Cairn / Null Meridian — 2

- `vault.stillcairn.demolished_clockroom`
- `vault.nullmeridian.court_test_cell`

Retired:
- `vault.stillcairn.unbuilt_civic_stair` — overlaps the retained `pulse.stillcairn.family_stair` route/reward family and the late unbuilt-route language; keep one clear completion identity per authored proposition.

---

# 7. Exact count check

| Category | First Circuit | Rootmere | Saltreach | Emberstep | High Aerie | Mireglass | Cairnfall | Late | Total |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| Resonance Faults | 6 | 5 | 5 | 5 | 4 | 4 | 4 | 3 | **36** |
| Pulse Shards | 3 | 3 | 3 | 3 | 2 | 2 | 1 | 1 | **18** |
| Micro-vaults | 5 | 4 | 3 | 3 | 3 | 2 | 2 | 2 | **24** |

These exactly match `docs/90`, `docs/91`, `docs/93`, and `docs/104`.

---

# 8. Retirement / migration disposition

Stillring has no released save schema or retail save population at this boundary.

Therefore these dispositions are **content-authority retirement rules**, not claims that a shipped migration exists.

## Retained IDs

Retained IDs remain stable and should be used by future registries, Save fixtures, Completion Ledger entries, System IDE views, and region manifests.

## Retired IDs

Retired IDs must:
- not be created as shipping completion records;
- remain in the legacy/tombstone audit list so future stale references fail validation;
- not be silently reused for a different activity;
- not count toward regional or global totals;
- be removed or explicitly retired in future development fixtures if those fixtures are authored from old planning docs.

## Reclassified activity

`pulse.stillcairn.unreleased_room` is retired.

The underlying authored activity survives under:

`fault.stillcairn.unreleased_room`

This is an intentional category reclassification before runtime implementation exists, not a released-save migration.

If a future internal prototype happens to create the legacy Pulse ID before this authority is integrated, that prototype fixture must be updated explicitly rather than treating the old Pulse as equivalent completion credit in both categories.

---

# 9. Legacy IDs retired by this authority

## Fault tombstones — 13

- `fault.graymile.bypass_joint`
- `fault.cairnspire.pressure_lift`
- `fault.rootmere.ferry_rootfork`
- `fault.rootmere.remembered_orchard`
- `fault.saltreach.fog_tower_foot`
- `fault.saltreach.lowwater_cistern`
- `fault.emberstep.kiln_lift`
- `fault.emberstep.cold_forge`
- `fault.highaerie.chainhouse_lower`
- `fault.highaerie.tempest_rod`
- `fault.mireglass.reed_causeway`
- `fault.mireglass.widow_chamber`
- `fault.cairnfall.correction_ring`

## Pulse tombstones — 9 assigned legacy IDs

- `pulse.circuit.lantern_inn`
- `pulse.cairnspire.public_lift`
- `pulse.rootmere.split_orchard`
- `pulse.saltreach.unbuilt_pier`
- `pulse.emberstep.cold_kiln`
- `pulse.highaerie.archive_weight`
- `pulse.mireglass.sunken_witness`
- `pulse.cairnfall.night_survey`
- `pulse.stillcairn.unreleased_room`

There is no tenth assigned tombstone because the stale 28-Shard budget only enumerated 27 actual IDs.

## Vault tombstones — 6

- `vault.graymile.drain_bell`
- `vault.saltreach.dry_cistern_lip`
- `vault.emberstep.slag_chute`
- `vault.mireglass.reed_cellar`
- `vault.cairnfall.correction_well`
- `vault.stillcairn.unbuilt_civic_stair`

---

# 10. Validation requirements for later implementation

Future content/Completion validation must fail if:
- the shipping registry contains anything other than 36 Fault IDs, 18 Pulse IDs, or 24 Vault IDs;
- any retired ID is registered as an active completion item;
- the old 48/28/30 regional allocation is imported from `docs/11`;
- a missing hypothetical 28th legacy Pulse ID is fabricated;
- `pulse.stillcairn.unreleased_room` and `fault.stillcairn.unreleased_room` both count;
- category totals are derived from Actor/map paths rather than semantic IDs;
- regional totals differ from the table in Section 7.

The Completion/System IDE should expose the retained/tombstone/reclassified status for audit fixtures.

---

# 11. Handoff closure effect

Before this authority, `SH-CONT-005` was correctly **PARTIAL** because production knew the totals but not the exact retained semantic roster.

After this authority:

> **`SH-CONT-005` = PASS at written production-authority / inventory level.**

The remaining work is execution:
- exact placement/blockout;
- final puzzle geometry;
- reward tuning;
- art/audio/VFX implementation;
- persistence and migration code;
- accessibility/runtime proof;
- human play and pacing.

Those are not missing item-roster authority.

---

# 12. Final locked statement

> **Stillring's completion-bearing production roster is now exactly 36 Resonance Faults, 18 Pulse Shards, and 24 Micro-vaults with explicit retained semantic IDs. Thirteen old Fault IDs, nine assigned old Pulse IDs, and six old Vault IDs are retired; the stale 28-Pulse budget never actually enumerated a 28th ID; and the existing Still-Cairn deliberate-release activity is reclassified from a retired Pulse reward into `fault.stillcairn.unreleased_room` so the locked late-game Fault allocation reaches three without inventing a new activity.**
