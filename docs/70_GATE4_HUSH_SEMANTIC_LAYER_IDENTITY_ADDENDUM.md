# 70 — Gate 4 Waking / Hush Semantic State & Paired-Entity Identity Contract

**Status:** LOCKED — scheduled-run owner delegation  
**Issue:** #126 — Gate 4 Hush-layer prototype design system  
**Decision:** #1 — semantic state ownership and paired-entity identity

## Decision

Waking and Hush are two authored **states/expressions of one semantic place**, governed by one authoritative world-layer state service. Unreal Data Layer state, sublevel visibility, Actor existence, material state, or streaming state may realize that authority, but none of those engine representations *is* the canonical Waking/Hush truth.

Core philosophy:

> **One place. One history of facts. Two ways reality can currently present and behave.**

The Hush must never drift into a second disconnected copy of a region with unrelated IDs, duplicated quest truth, and ad hoc synchronization scripts.

## Canon boundary

Narrative canon defines the Hush as an echo-layer coupled to ordinary Orra: discarded possibilities, emotional residue, incomplete states, and impressions of things no longer present. It is not an afterlife, not inherently evil, and not merely a visual filter.

Therefore the runtime model must support both:
- **shared facts/identity** — the same place, person, mechanism, route, or authored relationship can have continuity across states;
- **state-specific expression** — geometry, collision, presence, interaction, memory residue, or mechanism affordance may differ where canon/content explicitly requires it.

The engine representation must follow that semantic distinction rather than deciding it accidentally.

## Authoritative layer state

The world-layer service exposes a small explicit semantic state. For the Gate 4 prototype the minimum state family is:
- `Waking`
- `Hush`

A transition may also have transient execution states for validation/presentation, such as `TransitioningToHush` or `TransitioningToWaking`, but those are runtime process states—not new canonical realities.

The authoritative layer state must be:
- readable from C++/gameplay services;
- inspectable in the Hush / World-Layer System IDE;
- driven only through reviewed transition/state APIs;
- independent of whether the chosen Unreal representation uses Data Layers, streamed levels, Level Instances, Actor components, visibility groups, or another approved pattern;
- serializable through the persistent-world/save authority once Issue #4 defines the final schema.

## Engine state is downstream

A Runtime Data Layer being `Activated`, a streamed level being visible, or a Hush Actor being spawned may be evidence that presentation has caught up with semantic state. It must not itself answer questions such as:
- Which reality is canonically active?
- Is a quest condition satisfied?
- Is a persistent object collected/destroyed/repaired?
- Did an NPC survive?
- Which side of a cross-layer puzzle owns a lasting state change?
- What should a save reload restore?

Those answers come from semantic gameplay/world state.

This deliberately contradicts the tempting engine-first pattern of asking `IsDataLayerActive()` to determine quest truth.

## Stable semantic entity identity

Any authored entity that matters across Waking/Hush receives one stable **semantic entity ID**.

Examples of identity shape only:
- `brindle.workshop.main_bench`
- `cairnspire.archive.bridge_02`
- `rootmere.cathedral.counterweight_north`
- `hush_cairnspire.ilyra_workbench_relation`

The exact typed ID representation remains coordinated with Issue #4, but the contract is locked:
- runtime UObject path is not identity;
- Actor instance name is not identity;
- package/sublevel/Data Layer path is not identity;
- transient runtime GUID is not identity;
- spawn order is not identity.

## Paired entities

A semantic entity can have one of four Gate 4 representation relationships.

### 1. Shared invariant entity
The same semantic entity exists/behaves equivalently in both Waking and Hush, aside from presentation differences.

Examples may include the player's semantic identity, a persistent fact service, or a structure intentionally unchanged across the seam.

### 2. Paired expression entity
One semantic identity has separate authored Waking and Hush **expressions**.

Both expressions declare the same semantic entity ID plus an explicit expression role (`WakingExpression`, `HushExpression`).

Only the expression appropriate to the current layer/presentation contract is authoritative for physical presence/collision at a given moment, but both refer to the same underlying persistent semantic identity.

### 3. Layer-exclusive entity
An entity legitimately exists only in one layer.

It still receives a stable semantic ID if it matters to gameplay/save/debugging. Its absence in the other layer is explicit authored state, not a missing-pair bug.

Hush residues/impressions may use this category where canon says no ordinary Waking counterpart exists.

### 4. Related-but-not-identical entity
Two things may be narratively or spatially related without being the same persistent entity.

They must use separate semantic IDs linked by an explicit relation ID/type rather than being forced into a false pair.

This prevents “looks like the same bench” from silently meaning “shares all state.”

## Pair record

For entities that do pair, authoring must expose a reviewable pairing record sufficient to answer:
- semantic entity ID;
- Waking expression reference/ID;
- Hush expression reference/ID;
- pairing type;
- which facts are shared;
- which expression properties are layer-specific;
- collision/presence ownership class (defined further in Decision #3);
- reset/save relevance;
- optional relation to puzzle/interactable/NPC authority.

The pair record should live in reviewable semantic source/data where practical. A hand-connected Blueprint reference graph may be a runtime representation, but it may not be the only place the pairing truth exists.

## Shared facts versus layer-specific expression

A paired semantic entity separates **facts** from **expression**.

Shared/persistent facts may include:
- permanently repaired/destroyed/opened/collected state;
- authored setup/payoff facts;
- quest/world facts owned elsewhere;
- named character identity and durable relationship state;
- mechanism state specifically declared cross-layer-persistent.

Layer-specific expression may include:
- mesh/material/VFX/audio;
- geometry arrangement;
- collision or traversal availability;
- local Hush residue;
- state-specific interaction affordances;
- state-specific NPC presence where canon explicitly differs;
- presentation of a mechanism around a shared fact.

A designer must declare which category a meaningful property belongs to rather than relying on “whatever happened to the loaded Actor.”

## No automatic full-state mirroring

The system must not blindly copy every runtime property from the Waking Actor to the Hush Actor or vice versa.

Reasons:
- many expression properties should differ;
- physics/transient animation state may be meaningless across a seam;
- Hush can contain incomplete/discarded impressions rather than a literal duplicate;
- copying runtime components creates accidental persistence and synchronization bugs.

Only explicitly shared semantic facts cross the relationship.

## No automatic full-state independence

The opposite failure is equally invalid: treating Waking and Hush expressions as unrelated Actors whose shared state is maintained by bespoke level scripts.

If both expressions represent one semantic entity, shared facts come from one semantic record/service, not script-to-script copying.

## Player identity

Neris remains one semantic player across a layer transition.

Switching layer does not create a second player identity, inventory, combat resource record, tool inventory, quest actor, or completion record.

Player transform handling during transition belongs to Decision #2. Persistence belongs to Issue #4 / Decision #6. This decision locks identity continuity only.

## World position / paired spatial identity

Paired expressions should normally occupy a deliberate corresponding world-space relationship so the player experiences one place changing rather than teleporting into a disconnected level.

Gate 4 pair authoring must expose enough spatial metadata to verify:
- expected corresponding transform/anchor;
- allowed deliberate offset where Hush geometry is meaningfully displaced;
- whether a safe seam-transition landing exists;
- whether a pair is intentionally non-spatial/abstract.

Exact transition placement/collision fallback belongs to Decision #2/#3.

## Quest / objective boundary

Quest/objective systems may query semantic layer/world facts, but must not key logic directly to:
- Data Layer asset name;
- streamed sublevel loaded state;
- Actor visible/hidden state;
- material parameter;
- Hush VFX active state.

The world-layer service can expose reviewed facts such as `ActiveLayer == Hush` or a specific seam/pair state; content logic remains semantic.

## Save boundary with Issue #4

Issue #4 remains the final authority for schema shape, versioning, migration, categories, and malformed-save recovery.

Gate 4 Decision #1 contributes required semantics to that issue:
- active semantic layer is a save-relevant fact where reload-safe;
- persistent semantic entity IDs are the join key across layer expressions;
- pairing metadata is authored data, not discovered from save files;
- persistent facts save once against semantic identity, not once per Waking/Hush Actor;
- transient presentation/load states are not saved as canonical world truth.

Decision #6 will define Gate 4 reload behavior without preempting Issue #4's schema format.

## Representation-candidate implications

### World Partition + Runtime Data Layers
Epic UE5.8 Data Layers can organize Actors in the Editor and activate/deactivate runtime layers, and Epic demonstrates light/dark-world style transitions. World Partition also supplies OFPA-friendly authoring/source-control behavior. These are strong representation capabilities.

But Runtime Data Layer state remains downstream of this semantic contract.

### Explicit level / Actor layering
UE5.8 Level Streaming can asynchronously load/unload or toggle visibility of sublevels, while Level Instances provide an authoring workflow for grouped/reusable Actor arrangements. A compact Gate 4 map can therefore represent Waking/Hush without adopting World Partition solely to gain Data Layers.

Again, level visibility remains downstream.

Decision #9 will compare the two representation candidates against real Gate 4 production evidence requirements rather than treating either as already selected.

## System IDE requirements created by Decision #1

### Inspect
Expose:
- active semantic layer;
- transition process state separately;
- semantic entity ID under cursor/selection;
- pairing type;
- Waking expression ID/reference and current loaded/present state;
- Hush expression ID/reference and current loaded/present state;
- shared facts;
- layer-specific expression facts;
- engine representation state separately (Data Layer/level/Actor state);
- mismatches between semantic state and representation state.

### Validate
Catch:
- duplicate semantic entity IDs;
- paired record missing one required expression without `LayerExclusive` declaration;
- quest/world rule reading engine layer name/state as canonical truth;
- one persistent fact stored independently on both paired Actors;
- runtime-only Actor/path/GUID used as persistent pair key;
- both physical expressions claiming exclusive collision ownership simultaneously where not explicitly allowed;
- stale semantic pair reference after reset/reload;
- Data Layer/sublevel active state disagreeing with semantic layer after transition completion.

### Capture
A layer-state capture records:
semantic active layer → entity/pair IDs → shared facts → expression presence → engine representation states → mismatch/validation results.

## IP / comparative boundary

Parallel-world and state-layer mechanics are common design territory. Stillring must not copy another game's exact world-pair layouts, transition presentation, mirrored puzzle solutions, UI, color treatment, or controls.

Stillring's authored identity is its own: the Hush is a coupled echo of discarded possibilities/residue and incomplete relations, and the production architecture exists to preserve that fiction and save/test reliability.

## Locked statement

> **Waking and Hush are semantic states of one authored Orra. Persistent facts attach to stable semantic identities; Unreal layers and Actors are replaceable presentations of that truth.**

## Research basis

Primary current technical sources:
- Epic Games, UE5.8 World Partition — Data Layers documentation.
- Epic Games, UE5.8 World Partition documentation.
- Epic Games, UE5.8 One File Per Actor documentation.
- Epic Games, UE5.8 Level Streaming / Level Streaming Overview.
- Epic Games, UE5.8 Level Instancing documentation.

Repository authority:
- `docs/02_STORY_BIBLE.md`
- `docs/04_TECHNICAL_DIRECTION.md`
- `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
- `ROADMAP.md`
- Issue #4 persistent world/save requirements
- Issue #126 Gate 4 decision sequence

## Next decision

**Gate 4 Decision #2 — seam-transition eligibility / commit / cancel / camera-control contract.**
