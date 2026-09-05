# 75 — Gate 4 Hush Save / Load / Reload Contract

**Status:** LOCKED — scheduled-run owner delegation  
**Issue:** #126 — Gate 4 Hush-layer prototype design system  
**Decision:** #6 — save/load/reload contract for active layer and persistent paired facts, coordinated with Issue #4

## Decision

A save records one **stable semantic snapshot** of the playthrough. For Hush/Waking state, that means the committed semantic layer plus durable facts keyed by stable semantic IDs. Reload reconstructs semantic truth first and then materializes the appropriate Waking/Hush expressions from it.

Core philosophy:

> **Save the truth once. Rebuild the expression from the truth.**

A save file must never become a dump of whichever Actors, Data Layers, streamed levels, collision components, Behavior Trees, VFX, or transition timelines happened to be alive at the instant the disk write occurred.

## Coordination boundary with Issue #4

Issue #4 remains the final authority for the complete persistent-world/save schema, versioning/migration framework, all save categories, malformed-save recovery, and example full-playthrough fixture.

Gate 4 Decision #6 locks the Hush-specific semantics that Issue #4 must satisfy:
- active **committed semantic layer** is save-relevant where reload-safe;
- stable semantic entity IDs join paired Waking/Hush expressions;
- shared persistent facts save once per semantic identity;
- explicitly layer-local persistent facts carry layer scope;
- derived expression state is reconstructed from facts rather than redundantly trusted as authority;
- transient seam process/presentation state is not canonical save truth;
- engine representation state is not canonical save truth.

This decision does not choose the final serialized file format or schema container types.

## Stable-save boundary

The game may only commit a persistent save snapshot from a **save-stable semantic boundary**.

A save-stable boundary requires:
- one committed `ActiveSemanticLayer`;
- no unresolved semantic transition commit;
- player destination occupancy already validated/resolved;
- authoritative physical-expression handoff complete;
- persistent fact transaction(s) for the current frame settled;
- no half-applied cross-layer puzzle mutation;
- player checkpoint/transform record internally consistent with the active layer.

Visual/audio transition presentation may finish later, but if representation convergence affects safe reload/position truth, the save waits until that convergence is validated.

## Save requests during a seam

### Requested / Preparing
If a save/autosave is requested before semantic seam commit:
- do not serialize the in-flight destination as active truth;
- do not snapshot a mixed source/destination representation;
- defer the save until either the shift rejects/returns to stable source state or commits and reaches a save-stable destination state.

### Committed but not save-stable
If semantic commit occurred but physical/derived state has not yet converged enough for deterministic reload:
- the active layer is already destination semantically;
- the disk save remains deferred until the post-commit save-stable barrier is reached.

### Stable after commit
Once the save-stable barrier is reached, a new snapshot may be produced normally.

There is no save file containing `TransitioningToHush`, 43% material blend, source collision plus destination puzzle facts, or a queued reverse seam request.

## No transition process persistence

Do not persist as canonical world truth:
- `Requested`, `Preparing`, or `Presenting` seam process state;
- transition ID as an unfinished process;
- presentation blend percentage;
- VFX/material/audio timeline position;
- temporary streaming request handles;
- source/destination Data Layer activation progress;
- camera seam damping/blend progress;
- pending/held seam input;
- transient pre-commit occupancy probe result.

On reload, the world starts in one settled committed semantic layer.

## Active layer record

The save-relevant Hush record must include a semantic layer value equivalent to:
- `Waking`, or
- `Hush`.

It must not store only:
- Data Layer asset/path/name;
- streamed-level name;
- Actor visibility set;
- post-process state;
- material collection parameter;
- audio snapshot;
- debug workbench toggle.

Engine representation is reconstructed downstream from the semantic layer.

## Paired persistent facts

For a semantic entity with paired expressions, persistent facts save **once** under stable semantic identity.

Representative shape:

```text
SemanticEntityId: rootmere.cathedral.counterweight_north
Facts:
  Released: true
  RepairState: Damaged
  SharedLoadState: Unloaded
```

The Waking and Hush Actor expressions do not each receive separate copies of the same shared fact.

On reload:
1. semantic fact record restores once;
2. Waking expression derives its authored presentation/physical state from that record;
3. Hush expression derives its authored presentation/physical state from the same record;
4. only the active layer expression obtains ordinary physical authority.

## Layer-local persistent facts

A fact that is legitimately persistent but belongs only to one expression must be explicitly scoped.

Representative conceptual key:

```text
SemanticEntityId: cairnspire.archive.residue_17
LayerScope: Hush
Facts:
  ProcedureResolved: true
```

Layer scope is semantic data, not inferred from package/sublevel ownership.

A layer-local fact must not accidentally overwrite a shared fact with the same display name.

## Derived expression state

Derived expression state should normally **not** be saved independently.

Examples:
- whether a paired bridge mesh is currently visible;
- whether a destination collision component is enabled;
- current material/VFX expression;
- a mechanism visual pose derived deterministically from shared semantic state;
- currently active prompt/cursor/target ref.

Reload recomputes these from:
- committed semantic layer;
- persistent semantic facts;
- authored pair/expression data.

If future implementation evidence proves a derived cache is needed for performance, it must remain disposable/revalidatable and cannot outrank source facts.

## Snapshot consistency

A save is conceptually one immutable snapshot produced from authoritative semantic services, not an incremental walk over live Actors while gameplay continues mutating them.

The save coordinator must gather a coherent snapshot boundary including Hush-relevant categories before asynchronous disk I/O begins.

After snapshot capture:
- gameplay may continue;
- disk serialization may be asynchronous;
- changes made after capture belong to the next save, not the in-flight snapshot.

This matches Epic's recommendation to use asynchronous save operations where appropriate while keeping semantic snapshot ownership in Stillring gameplay code.

## Save transaction / fact ordering

Persistent fact changes that logically belong to one gameplay operation must settle before snapshot capture.

Examples:
- Anchor releases shared support → semantic support fact changes → puzzle invariants recompute → save snapshot may occur;
- enemy fatal hit → death fact/encounter consequences settle → save snapshot may occur;
- one-shot pickup collected → inventory/world fact transaction settles → save snapshot may occur.

The save system must not capture “item granted but pickup still uncollected” or “boss dead but alive expression still canonical” because it sampled services mid-transaction.

Exact transaction implementation remains an architectural choice for Issue #4/Gate 6.

## Reload order

A Hush-capable reload follows semantic reconstruction order rather than Actor discovery order.

Required conceptual order:
1. read save header/schema/version and validate compatibility;
2. migrate/normalize through Issue #4 policy before gameplay reconstruction;
3. restore authoritative persistent semantic facts keyed by stable IDs;
4. restore committed `ActiveSemanticLayer`;
5. prepare required world representation for that layer/area;
6. derive paired Waking/Hush expression state from semantic facts;
7. grant physical authority to the active expression set under Decision #3;
8. restore/validate player transform/checkpoint occupancy against active authoritative geometry;
9. reconstruct NPC/enemy/interactable expression state from semantic continuity facts;
10. rebuild transient runtime systems (AI presentation, prompts, camera, targeting, VFX/audio) from the reconstructed world;
11. validate semantic↔representation convergence;
12. only then release ordinary player control.

No Actor `BeginPlay` order may become the hidden persistence algorithm.

## Player position / layer-safe reload

The save must identify player location through a reviewed save/location contract compatible with Issue #4. At minimum Gate 4 requires enough semantic context to validate the position against the saved active layer.

On reload:
1. try the saved player transform in the reconstructed saved semantic layer;
2. if valid, restore there;
3. if invalid because of schema/content migration or corrupt/incompatible state, use an explicit authored safe recovery/checkpoint policy from Issue #4;
4. never silently flip to the other layer merely to make the position legal;
5. never broad-search/teleport to a puzzle solution.

A save produced at a valid save-stable boundary should normally pass step 2 without correction.

## Reload does not replay seam presentation

Loading a save recorded in Hush starts with Hush semantically active after reconstruction. It does not replay a Waking→Hush transition as though the player just pressed the seam action.

Reasons:
- reload is restoration, not gameplay history playback;
- replaying the seam could fire transition hooks twice;
- it could create false combat/interaction/puzzle effects;
- it could expose a representation half-state before control returns.

A short loading/presentation treatment may exist, but it is not the seam gameplay transaction.

## Combat/NPC/interactable reload boundary

Decision #5 continuity remains authoritative.

Save-relevant durable facts may include health/death/relationship/interactable facts when Issue #4 categorizes them as persistent.

Do not persist as canonical Hush continuity truth by default:
- target Actor pointer;
- current montage section/time;
- Behavior Tree task stack;
- overlap prompt ref;
- attack hit-volume component state;
- seam transition callback stack;
- temporary projectile Actor pointers.

If active encounter state is later made save-persistent, it must use semantic encounter/entity IDs and reviewed state, not live AI object graphs.

## Cross-layer puzzle reload

Decision #4 state classes govern persistence:
- `SharedPersistent` → save once under semantic identity;
- persistent `LayerLocal` → save with explicit semantic layer scope;
- `CrossLayerCausal` → save the authoritative causal fact(s), not both resulting Actor poses;
- `Derived` → recompute.

After reload, puzzle completion/invariants must be explainable from restored facts without replaying the player's action sequence.

## Versioning / migration obligation

Every production save schema begins versioned from v1 under Issue #4.

Gate 4 requires migrations to preserve semantic intent when Hush representation changes.

For example, migration may change:
- Waking/Hush Unreal asset organization;
- Data Layer asset names;
- sublevel split;
- Actor classes;
- mesh/component layout;
- pair-expression implementation.

A valid old save should survive those presentation refactors because its canonical keys are semantic IDs/facts.

If a semantic ID itself must change, Issue #4 migration provides an explicit old→new mapping or documented incompatible-state recovery; it may not rely on fuzzy Actor/path matching.

## Malformed / incompatible save behavior

Issue #4 owns full policy. Hush-specific validation must at minimum detect:
- invalid/unknown active semantic layer;
- duplicate shared fact records for one semantic ID;
- persistent paired fact pointing to no valid semantic entity after migration;
- layer-local fact with invalid layer scope;
- contradictory fact combinations that make both exclusive physical expressions authoritative;
- saved player location impossible in saved layer after migration;
- save claiming transient transition state as canonical layer truth.

Recovery must favor the last verified compatible snapshot/autosave or an explicit safe recovery path; it must not guess by toggling engine layers until something loads.

## Save failure behavior

If an asynchronous disk write fails:
- current gameplay/semantic state remains unchanged;
- previous valid save remains the fallback where platform/file semantics permit;
- failure is surfaced through the save system/UI/debug evidence;
- no Hush layer rollback occurs;
- no duplicate retry transaction mutates world state.

The disk write is persistence of a snapshot, not the authority that makes the snapshot's gameplay events real.

## Hush / Save System IDE requirements

### Inspect
Expose:
- current semantic layer;
- whether current state is save-stable and, if not, exact blocker;
- last captured snapshot ID/time/frame;
- snapshot semantic layer;
- persistent semantic entity/fact count;
- shared vs layer-local vs derived classification;
- pending/deferred save request reason;
- schema/version/migration result;
- saved player semantic area/transform;
- representation convergence after reload;
- differences between restored semantic facts and current expressions.

### Exercise
Provide development-only actions to:
- save in Waking/Hush stable states;
- request autosave during each seam phase and verify defer behavior;
- save after cross-layer puzzle mutation;
- save after enemy/NPC/interactable durable change;
- unload/reload both expressions before load;
- simulate old schema migration;
- inject unknown semantic ID/layer-local scope conflict;
- invalidate saved player occupancy through fixture geometry change;
- simulate disk-write failure without mutating semantic world state.

### Validate
Catch:
- save captured while semantic transition unresolved;
- engine layer/sublevel/Actor path stored as canonical active-layer identity;
- duplicate shared fact saved per expression;
- derived expression state disagreeing with source facts after load;
- player restored before active physical geometry is authoritative;
- AI/Actor `BeginPlay` resetting restored semantic facts;
- Hush save replaying seam gameplay transition on load;
- snapshot internally mixing different gameplay transaction frames;
- old save depending on renamed presentation asset path without migration;
- malformed Hush state recovered by arbitrary layer guessing.

### Capture
A save/reload evidence capture records:
semantic snapshot boundary → schema/version → active layer + fact set → disk result → teardown → load/migration → semantic reconstruction → representation derivation → physical authority → player occupancy → NPC/combat/puzzle reconstruction → validation result.

## Deterministic test matrix

At minimum:
- stable Waking save→exit→reload;
- stable Hush save→exit→reload;
- autosave requested during `Preparing`;
- autosave requested just after semantic commit before physical convergence;
- shared puzzle fact changed in Waking, save, reload Hush;
- Hush-local persistent fact save/reload;
- paired enemy at partial health/dead, save/reload if category retained by Issue #4;
- one-shot interactable used, save/reload opposite layer;
- saved Hush player location near layer-specific blocker;
- destination expression initially unloaded during load;
- renamed/moved Unreal presentation asset with stable semantic IDs;
- old schema migration;
- malformed duplicate fact record;
- disk-write failure;
- repeated save/load cycles with no semantic drift.

## Research basis

Primary current technical sources verified:
- Epic Games, **Saving and Loading Your Game in Unreal Engine 5.8** — `USaveGame`, explicit transfer of game data into/out of save objects, sync/async save/load, async save recommended for active gameplay/large data.
- Epic Games, **UGameInstance**, UE5.8 — running-game lifetime manager; useful as an implementation boundary but not persistent disk truth.
- Gate 4 Decisions #1–#5 (`docs/70`–`docs/74`).
- Issue #4 — persistent world-state/save schema authority.
- Issue #126 — Gate 4 Hush prototype design.

## Locked statement

> **A Hush save records one settled semantic reality and its durable facts. Reload restores that truth first, then rebuilds whichever Actors and layers are needed to express it.**

## Next decision

**Gate 4 Decision #7 — presentation/audio/VFX/accessibility contract.**
