# 81 — Persistent World-State Stable Semantic ID Contract

**Status:** LOCKED — scheduled-run owner delegation  
**Issue:** #4 — Define persistent world-state and save schema  
**Decision:** #1 — persistent ID format, ownership, and forbidden-key contract

## Decision

Stillring persistent state is keyed by **authored stable semantic IDs** that name the game-world concept being remembered—not the Unreal object currently expressing it.

Core philosophy:

> **Save what the thing means, not where Unreal happens to keep it.**

A persistent semantic ID survives ordinary refactors of Actor class, map/sublevel/Data Layer organization, asset path, instance packaging, One File Per Actor external package, Blueprint→C++ migration, and representation strategy where the underlying authored game-world identity has not changed.

## Canonical ID shape

The canonical serialized form is a lowercase ASCII dotted identifier:

```text
<scope>.<domain>.<entity>
```

Optional additional semantic hierarchy is allowed when it improves uniqueness/readability:

```text
<scope>.<domain>.<subdomain>.<entity>
```

Examples:

```text
rootmere.world.bell_oak_north
rootmere.shortcut.mill_sluice_gate
cairnspire.npc.tessa
cairnspire.quest.freight_failure
saltreach.collectible.bellwright_record_03
emberstep.boss.kiln_warden
rootmere.hush.counterweight_north
player.tool.cantor_key
player.tool.anchor_line
world.catastrophe.long_hush_break
```

The hierarchy is semantic rather than a direct mirror of folders/maps.

`scope` normally identifies a durable world/player/global namespace such as a region, `player`, or `world`. `domain` identifies the semantic category. More exact category rules are owned by later Issue #4 decisions.

## Serialized type vs runtime type

The persistent serialized identity is conceptually a stable UTF-8 string.

Implementation may wrap it in a C++ value type and may internally use `FName`/hashed lookup for efficient runtime comparison, provided:
- serialization preserves the canonical semantic string;
- equality is defined on the canonical semantic ID;
- no runtime hash/object pointer becomes the durable save key;
- diagnostics can always print the human-readable semantic ID.

Exact C++ type name is an implementation choice.

## Syntax rules

Canonical IDs:
- lowercase ASCII only;
- segments separated by `.`;
- each segment begins with `a-z` and then uses `a-z`, `0-9`, or `_`;
- no spaces;
- no localized text;
- no slashes/backslashes;
- no package/class prefixes;
- no generated GUID string by default;
- must be globally unique inside the semantic registry;
- must be stable once any shipped/save-compatible content may reference the ID.

Display names are separate localized/user-facing data and may change freely without changing semantic ID.

## Authorship and ownership

Every persistent ID has one explicit semantic owner record in repository-backed authored data/code.

Ownership means:
- one canonical declaration establishes the ID;
- systems may reference that ID but may not independently recreate competing definitions;
- the declaration identifies semantic category/scope and expected persistence behavior;
- tooling validates global uniqueness;
- paired Waking/Hush expressions point to the same ID when they represent one persistent semantic entity;
- runtime-spawned objects that require persistence obtain identity from an approved durable spawn/instance contract, not from `SpawnActor` order.

The exact registry/data representation remains an implementation decision, but it must be reviewable in source control wherever practical.

## Immutable after persistence boundary

Once an ID has been used by a released build, durable test fixture intended to survive migrations, or production save schema, it is treated as immutable public persistence API.

Do **not** rename it merely because:
- a folder moved;
- an Actor/Blueprint/class was renamed;
- prose/canon display terminology improved;
- a region's internal level topology changed;
- the implementation changed from sublevels to Data Layers;
- designers prefer a tidier identifier.

If the semantic identity itself genuinely changes, migration owns the old→new relationship. Never silently reuse the old ID for a different meaning.

## Retirement / tombstones

Deleting content does not immediately make its semantic ID reusable.

Retired IDs remain reserved through a tombstone/retired-ID record for as long as compatible saves may contain them.

A retired record should preserve enough information for migration/recovery diagnostics to answer:
- what ID existed;
- when/why it was retired;
- whether it redirects to another semantic ID;
- whether its persisted fact may be safely dropped;
- whether loading a save containing it should warn/fail/migrate.

The final tombstone schema belongs to the migration decision.

## Redirect / migration boundary

An ID redirect is an explicit save migration rule, not fuzzy matching.

Allowed conceptual operation:

```text
old: rootmere.shortcut.old_mill_gate
new: rootmere.shortcut.mill_sluice_gate
```

Migration is versioned and reviewed. Runtime gameplay should not carry an ever-growing hidden alias soup as its normal identity model.

Epic's Asset Manager supports Primary Asset ID/name/type redirects for asset lookup, which demonstrates a useful migration pattern, but Stillring semantic-ID migrations are project gameplay/save authority and do not depend on Asset Manager redirects. citeturn516868search1

## Explicitly forbidden canonical persistence keys

The following may be useful as transient representation/debug identifiers but are **forbidden as the sole canonical save identity**:

- Actor pointer/object pointer;
- Actor memory address;
- runtime spawn index/order;
- `GetName()` / generated Actor instance name;
- Actor label/display label;
- Blueprint class name;
- UObject/Actor package path;
- soft object path by itself;
- map/sublevel name;
- World Partition cell;
- Data Layer asset/name/state;
- One File Per Actor external package filename;
- component name/path;
- transform/location as identity;
- array index;
- Gameplay Tag by itself unless that tag is explicitly declared as the semantic entity ID in a later approved contract;
- `FPrimaryAssetId` by itself;
- transient engine/network GUID;
- editor-only Actor GUID/runtime GUID by itself;
- quest objective display text/localization key.

These values may be recorded as secondary diagnostics/representation references where useful, but a save remains reconstructable from semantic identity after reasonable presentation/asset refactors.

## Why `FPrimaryAssetId` is not the world-state ID

UE5.8 Asset Manager Primary Asset IDs identify **assets** by a Primary Asset Type + name and are designed for discovery/loading; Epic also provides redirect mechanisms when asset identity changes. citeturn516868search1

Stillring persistent semantic IDs identify **game-world meaning** such as “this shortcut,” “this NPC,” or “this boss defeat.”

A semantic entity may:
- have multiple assets/Actors;
- change asset class;
- have Waking/Hush paired expressions;
- be represented by no active Actor at load time;
- survive removal/renaming of one presentation asset.

Therefore Asset Manager identity may be referenced by semantic authored data for representation loading, but it cannot own persistent world truth.

## Why Actor identity is not enough

Actors are runtime/level gameplay objects that can be spawned and destroyed; their existence is representation lifecycle, not automatically durable world identity. citeturn516868search5

Gate 4 already locked the same boundary for paired Hush expressions. Issue #4 generalizes it across the whole game.

A persistent fact must still be meaningful when its Actor is:
- unloaded;
- destroyed as presentation;
- respawned/reconstructed after load;
- moved to another level/Data Layer;
- replaced by another implementation class.

## Runtime-spawned persistent instances

Most authored persistent world entities should use authored IDs.

If Stillring later needs genuinely dynamic multiple persistent instances—e.g. a system that creates player-owned placed objects—those instances require a separate approved durable-instance identity contract that includes deterministic/recorded creation identity and lifecycle/migration rules.

Do not preemptively assign random GUID persistence to every Actor “just in case.” That creates opaque saves and weakens authored-state review.

## Collections / repeated authored items

Repeated collectibles/fixtures receive individual semantic IDs when their individual collected/changed state matters.

Good:

```text
rootmere.collectible.bell_shard_01
rootmere.collectible.bell_shard_02
```

Bad:

```text
rootmere.collectible[17]
```

Array/list ordering may change during content editing; identity may not.

## Paired Waking/Hush identity

Gate 4 remains authoritative:
- same semantic entity across Waking/Hush → one persistent semantic ID;
- layer-local persistent fact → same entity ID plus explicit semantic layer scope/fact rule where applicable;
- related-but-distinct entities → distinct IDs;
- Data Layer/Actor expression refs are downstream representation.

This keeps saves stable if Hush representation changes later.

## Quest / narrative fact boundary

A semantic ID identifies the entity/fact owner, not the truth value itself.

Example:

```text
EntityId: cairnspire.npc.tessa
Fact: trust_state = guarded
```

rather than encoding mutable state into identity:

```text
cairnspire.npc.tessa_guarded
```

Likewise, do not create a new semantic entity ID for each transient quest step unless those are genuinely distinct authored persistent entities. Later Issue #4 category/schema decisions define how facts are represented.

## Validation requirements

Repository/editor/save validation must catch at minimum:
- duplicate canonical semantic IDs;
- malformed ID syntax;
- unauthorized reuse of a retired ID;
- persistent record with no registered semantic owner after migration;
- paired expressions with contradictory semantic IDs;
- same semantic ID declared with conflicting categories;
- canonical persistence record keyed only by Actor/path/Data Layer/runtime identifier;
- mutable display name embedded as identity;
- new production persistent entity missing an explicit ID.

Warnings should also flag suspicious IDs that mirror package/folder names so closely that a refactor may accidentally encourage renaming them.

## Save / Persistence System IDE requirements created by Decision #1

### Inspect
Expose:
- semantic ID;
- semantic category/scope;
- owner declaration/source;
- active representation refs separately;
- persistence classification when later defined;
- retired/redirect/migration status;
- current save records referencing the ID;
- validation state.

### Search
Allow fast search by:
- exact semantic ID;
- prefix/scope/domain;
- display name;
- current Actor/asset representation;
- retired/redirected ID.

The search result must visually distinguish semantic identity from representation path.

### Validate
Provide:
- full-registry uniqueness scan;
- malformed syntax scan;
- representation-as-ID scan;
- retired-ID reuse detection;
- missing-owner detection;
- paired-layer ID mismatch detection;
- fixture/save unknown-ID scan.

### Exercise
Development fixtures:
- rename/move Actor without changing semantic ID;
- move entity between sublevels/Data Layers;
- Blueprint→different class representation;
- paired Hush representation swap;
- retired ID + explicit migration;
- deliberately duplicated/malformed ID validation failure.

### Capture
A persistence-ID capture records semantic ID → owner source → category/scope → representation refs → save facts → migration/retirement state → validation results.

## Deterministic acceptance fixtures

### S1-F01 — Actor rename/move
Persist a fact, rename/move the Actor/asset, reload through same semantic ID. Fact survives.

### S1-F02 — Representation replacement
Persist a fact, replace Blueprint/Actor class with a different presentation implementation linked to the same semantic ID. Fact survives.

### S1-F03 — Waking/Hush pair
Both expressions share one ID; saving in either layer produces one persistent entity fact record.

### S1-F04 — duplicate ID
Two authored declarations claim same ID. Validation hard-fails before acceptance.

### S1-F05 — retired ID
Old save contains a retired ID. Versioned migration/tombstone logic reports deterministic outcome; ID is never reassigned silently.

### S1-F06 — index/order edit
Reorder repeated collectible authoring. Individual collected state remains bound to semantic IDs rather than indices.

## Research basis

Primary current sources verified:
- Epic Games, **Saving and Loading Your Game in Unreal Engine 5.8** — projects define custom `USaveGame` data and explicitly transfer game data into/out of the save object rather than receiving automatic universal world persistence. citeturn516868search0
- Epic Games, **Asset Management in Unreal Engine 5.8** — Primary Asset IDs are Asset Manager identities (type + asset name) with redirects/loading behavior, useful for representation lookup but distinct from gameplay semantic identity. citeturn516868search1
- Epic Games, **Actors in Unreal Engine 5.8** — Actors are placed/spawned/destroyed gameplay objects, reinforcing the separation between runtime representation and authored persistence identity. citeturn516868search5
- `docs/75_GATE4_HUSH_SAVE_RELOAD_ADDENDUM.md` and `docs/79_GATE4_HUSH_CUMULATIVE_SPECIFICATION.md`.
- Issue #4.

## Locked statement

> **Every durable Stillring fact belongs to a stable authored semantic identity. Unreal objects may express that identity; they never replace it.**

## Next decision

**Save / Persistent World-State Decision #2 — define persistence categories and ownership boundaries: player, inventory/tools, quest, world, boss/encounter, shortcut, collectible, catastrophe, Hush, and explicitly transient runtime state.**
