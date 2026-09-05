# 95 — Completion Decision #7 — Bellwright Refuge Authority

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #8 — Define 100% completion taxonomy and persistence contract  
**Decision:** #7 — refuge count, placement, activation semantics, service identity, travel/save boundaries, persistence, accessibility, IDE, and anti-checkpoint-clutter constraints

## Decision question

Do the planned 11 Bellwright Refuges earn completion-bearing status, and what keeps them from becoming eleven interchangeable checkpoint huts or renamed fast-travel shrines?

## Fresh research conclusion

**Keep all 11 planned Bellwright Refuges.**

The current ledger already gives every refuge a different reason to exist: independent workshop and Common Measure teaching, flood-service locker, municipal repair commons, living-material station, pressure-service cache, thermal rest chamber, suspension workshop, weather station, memory workshop, survey/calibration hut, and Ilyra's Hush workbench.

That distinction is the reason the count survives. Eleven is not a density target; it is the number of currently justified specialist/service/history nodes.

Comparative study reinforces the boundary between a useful service hub and generic convenience infrastructure. Nintendo's current Tears of the Kingdom guidance highlights returning to a changing service hub such as Lookout Landing and separately treats portable fast travel as a convenience tool. Stillring should keep those roles separated: a Refuge is valuable because of local people, craft, history, services, and records — not merely because it shortens travel.

## Locked philosophy

> **A Refuge is useful because somebody made this place work.**

## Shipping target — 11

The existing 11-refuge target is **CONFIRMED**:

1. `refuge.circuit.old_viaduct` — Old Viaduct Refuge;
2. `refuge.brindle.east_culvert` — East Culvert Shed;
3. `refuge.cairnspire.fourth_landing` — Fourth Landing Commons;
4. `refuge.rootmere.reed_screw_house` — Reed-Screw House;
5. `refuge.saltreach.lowwater_locker` — Lowwater Locker;
6. `refuge.emberstep.ashbreak_room` — Ashbreak Room;
7. `refuge.highaerie.chainhouse_seven` — Chainhouse Seven;
8. `refuge.highaerie.storm_blind` — Storm Blind;
9. `refuge.mireglass.reed_chapel_shop` — Reed-Chapel Workshop;
10. `refuge.cairnfall.night_survey_hut` — Night Survey Hut;
11. `refuge.hush.ilyras_workbench` — Ilyra's Workbench.

No numerical regional symmetry is required. High Aerie has two because they serve materially different suspension and weather functions; the Hush workbench is a narrative/service anchor rather than an ordinary physical shop.

## Completion predicate — discover + activate/resolution

Walking near a Refuge, revealing its icon, or entering its trigger volume **does not** satisfy completion.

Each Refuge has:
- `Unknown`;
- `Discovered`;
- `AvailableForActivation` where needed;
- `Activated/Resolved`;
- optional later service/history evolution states.

100% counts the Refuge when its **unique one-time activation/service/lesson/record obligation is resolved**.

Examples:
- Old Viaduct requires actually establishing the independent workshop relationship / Common Measure service state;
- a service locker may require restoring access, calibrating equipment, or resolving its local service problem;
- Ilyra's Workbench requires its authored Hush anchor/service reconstruction, not merely reaching the coordinates.

Once activated, repeat visits/services do not create additional completion obligations.

## Refuge versus checkpoint / save point / fast travel

A Refuge is **not defined by saving, respawning, or warping**.

Locked boundaries:
- autosave/manual-save cadence remains Issue #4 save authority and may occur away from Refuges;
- retry checkpoints remain authored retry-state authority and do not require a Refuge;
- Line Skiff and other approved traversal systems remain world-travel authority;
- discovering a Refuge does not automatically create universal point-to-point teleportation;
- implementation may later connect selected Refuges to a separately approved travel/service network, but travel convenience is not their completion predicate and must not erase authored world traversal.

A player should still care about a Refuge even if fast travel were disabled.

## Required unique service identity

Every Refuge needs at least **two** meaningful identity pillars, one of which must be region/history/person-specific:
- specialist tool or harness service;
- unique calibration/diagnostic function;
- Pulse Shard installation/fitting capability;
- record/archive access;
- completion-assist/network information;
- locally useful staging/support service;
- pattern/upgrade teaching;
- relationship/prestige progression;
- unique world-state or Hush function;
- region-specific environmental support.

Generic shared facilities may exist, but shared functionality cannot be the entire reason a Refuge exists.

## Pulse Shard relationship

Decision #3 allows owned Pulse Shards to install automatically at the next valid Bellwright Refuge service interaction.

Rules:
- **not every Refuge must be a full harness workshop**; valid installation support may be present through standardized fitting hardware or a bellwright with the required capability;
- the player may not be stranded indefinitely with an owned Shard because the next several Refuges lack installation capability;
- installation has no currency/random-material cost;
- Refuge completion and Shard installation are separate semantic facts — installing a Shard at an already activated Refuge does not re-complete it.

## Completion-assistance network

Refuges are natural in-world hosts for progressive completion assistance because they are local repair/record infrastructure.

Early:
- local rumors, records, and known unresolved work can be surfaced contextually;
- no omniscient full-region checklist is required.

Mid/late:
- activated Refuges may contribute to regional known/unresolved summaries;
- specialist records can point toward Faults, Vaults, Contracts, or Records without becoming a universal radar;
- Unringing can strengthen the network into exact regional counts and progressively more explicit hints under later UI/assist authority.

The network may use only information the project's completion-assist rules authorize; Refuges do not magically know undiscovered facts simply because the player wants 100%.

## Placement and world-design rules

A Refuge should feel like infrastructure someone would actually maintain.

Required placement rationale may include:
- old transport/service route;
- maintenance access near dangerous machinery;
- worker rest/repair need;
- environmental calibration point;
- unofficial/community workspace near institutional gaps;
- Hush anchor justified by story/history.

Reject placement chosen solely to make map spacing uniform.

Each Refuge should be useful before anything catastrophic happens in its region where chronology permits, preserving the project's major-location rule: places should earn attachment before disaster/recontextualization.

## Persistence ownership

World State / Quest-State owns the Refuge's semantic discovered/activated/evolved facts according to the locked save taxonomy; Completion Ledger derives the completion obligation from `Activated/Resolved`.

Rules:
- stable `refuge.<region>.<slug>` ID;
- icon/map marker is representation, not identity;
- service availability reconstructs from semantic state after load;
- one-time activation/reward cannot duplicate;
- downstream service upgrades remain separate facts from base completion;
- Hush/Waking representation follows the locked shared-world-state rules rather than duplicating one Refuge into two completion IDs unless explicitly authored as separate facts.

## Accessibility / wayfinding

Refuges should be discoverable through multiple readable channels appropriate to place:
- architecture/silhouette;
- lighting/material/workshop cues;
- route signage/physical infrastructure;
- dialogue/journal clue;
- optional map/hint escalation later.

Critical discovery/activation information may not rely solely on color, audio pitch, tiny signage, or vibration.

Service menus use the accessible UI standards already required by the project: scalable text, high contrast, non-color-only state, controller/keyboard parity, and clear feedback for installed/pending services.

## Refuge / Completion System IDE

The development workbench must expose:
- Refuge semantic ID / region/layer;
- discovered / activation-eligible / activated state;
- unique service identity tags;
- current available services;
- Pulse-install capability/state;
- completion-assist contribution;
- owning world/quest facts;
- Completion Ledger reconciliation;
- one-time activation/reward transaction;
- map/representation binding diagnostics;
- duplicate/generic-service validation.

Required fixtures:
1. undiscovered Refuge;
2. discovered but unresolved Refuge that does not count;
3. activation transaction and completion settlement;
4. activated Refuge save/load reconstruction;
5. Pulse installation at already activated Refuge without duplicate completion;
6. Refuge whose local service changes after story state;
7. Hush Ilyra workbench reconstruction;
8. no-fast-travel test proving service identity still matters;
9. accessible activation/service UI;
10. 10/11 late-audit fixture.

## Red-team / rejection conditions

Reject a Refuge if:
- its only purpose is save/respawn/fast travel;
- it is an identical service hut with a different biome skin;
- walking close enough silently counts completion;
- no believable worker/infrastructure/history reason explains its location;
- universal travel convenience trivializes authored traversal;
- the player must activate all Refuges to make ordinary critical-path travel tolerable;
- it duplicates another Refuge's local identity with no meaningful distinction;
- service state can duplicate/drop after save/load;
- its existence is justified only by making the count equal 11.

## Approval

**APPROVED / LOCKED under the owner's scheduled-run delegation.**

### Final locked statement

> **Stillring keeps 11 Bellwright Refuges because all eleven are distinct specialist/history/service nodes. Completion requires resolving each Refuge's unique activation obligation, not walking past a checkpoint. Saving, retry, and fast travel remain separate systems; a Refuge must be worth finding because somebody made that place useful.**

## Next decision

Completion Decision #8 — **Cantor Pattern completion authority: validate the 9-pattern catalog as a completion category, mandatory/optional split, acquisition semantics, completion counting, accessibility, persistence, and overlap with critical-path verbs/tool mastery.**
