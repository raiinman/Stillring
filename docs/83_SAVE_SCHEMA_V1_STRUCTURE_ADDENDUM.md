# 83 — Persistent World-State / Save Decision #3 — Save Schema v1 Structure

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #4 — Define persistent world-state and save schema  
**Decision:** #3 — top-level v1 structure, record envelopes, deterministic canonicalization, and example fixture

## Decision question

What is the explicit semantic structure of Stillring Save Schema v1 before migration/recovery policy is decided?

## Locked philosophy

> **The schema records stable game meaning in typed sections. Disk encoding is an implementation detail; semantic shape is not.**

Save v1 must be auditable from source, testable without loading a full map, and independent of live UObject/Actor graphs.

## Research basis

Fresh Unreal Engine 5.8 research confirms:
- `USaveGame` can hold project-defined variables and be serialized through Unreal's save APIs.
- `SaveGameToMemory`/slot APIs produce binary representations, but Stillring remains responsible for the data model handed to those APIs.
- `FArchive` and `FStructuredArchive` support explicit custom/structured serialization.
- `FInstancedStruct` can hold heterogeneous USTRUCT data in memory, but reflected struct paths/types must not silently become Stillring's permanent semantic record discriminator.

Primary references:
- Epic UE5.8 — Saving and Loading Your Game: https://dev.epicgames.com/documentation/unreal-engine/saving-and-loading-your-game-in-unreal-engine
- Epic UE5.8 — `FArchive`: https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Core/FArchive
- Epic UE5.8 — `FStructuredArchive`: https://dev.epicgames.com/documentation/unreal-engine/API/Runtime/Core/FStructuredArchive/__ctor
- Epic UE5.8 — `UScriptStruct::Serialize`: https://dev.epicgames.com/documentation/unreal-engine/API/Runtime/CoreUObject/UScriptStruct/Serialize
- Epic UE5.8 — `FInstancedStruct`: https://dev.epicgames.com/documentation/unreal-engine/API/Runtime/CoreUObject/FInstancedStruct

Project authority reconciled:
- `docs/75_GATE4_HUSH_SAVE_RELOAD_ADDENDUM.md`
- `docs/81_SAVE_PERSISTENT_IDENTITY_ADDENDUM.md`
- `docs/82_SAVE_STATE_TAXONOMY_OWNERSHIP_ADDENDUM.md`

## 1. Canonical top-level semantic shape

Schema v1 is conceptually:

```text
FStillringSaveV1
  Header
  Checkpoint
  PlayerProgression
  Inventory
  QuestState
  WorldState
  HushState
  EncounterState
  CompletionState
  NpcRecurrenceState
```

These are semantic sections, not necessarily separate disk files.

The runtime implementation may serialize this aggregate using `USaveGame`, `FArchive`, `FStructuredArchive`, or another reviewed local Unreal mechanism as long as the semantic shape and invariants remain unchanged.

## 2. Header v1

Required fields:

```text
SchemaVersion = 1
PlaythroughId : FGuid
SnapshotId : FGuid
CapturedAtUtc : timestamp
AccumulatedPlayTimeSeconds : uint64
ContentRevision : stable project/build compatibility string or integer
SaveReason : enum { Manual, Auto, Checkpoint, Developer }
```

Optional diagnostics:
- source build commit/version;
- platform family;
- development-only capture metadata.

Header metadata must never be used as gameplay truth.

## 3. Section contract

Each section has:

```text
SectionId        : stable enum / project-owned identifier
SectionVersion   : uint32, starts at 1
Records          : typed ordered collection
```

`SectionVersion` exists so later migration can be scoped without pretending every domain changes together. Decision #4 will define migration policy; this decision only locks the presence of explicit version metadata.

## 4. Stable record envelope

Persistent records use an envelope equivalent to:

```text
RecordId        : FStillringPersistentId
RecordKind      : stable project-owned semantic kind
RecordVersion   : uint32
LayerScope      : optional { Shared, Waking, Hush }
Payload         : kind-specific typed semantic fields
```

Rules:
- `RecordId` is Decision #1 semantic identity.
- `RecordKind` is **not** a UObject class path, Blueprint path, package path, Actor class name, or reflected struct path.
- `RecordVersion` begins at 1 for each record kind.
- `LayerScope` exists only where the domain legitimately needs it.
- payload shape is owned by the authoritative domain from Decision #2.

## 5. Record-kind identity

Record kinds must be stable across code/content refactors.

Recommended project-owned representation:
- a native enum for closed v1 record families where practical; or
- a project-owned stable semantic identifier registry when extensibility is required.

Human-readable debug labels may accompany a kind but are not the discriminator.

Renaming a C++ struct or moving Blueprint assets must not change on-disk semantic kind.

## 6. Typed payload rule

Do not reduce the entire save to `Map<String, Variant>` or arbitrary property bags.

Each record kind defines reviewed fields with explicit semantics.

Examples:

### World boolean fact
```text
RecordId: <semantic GUID>
RecordKind: WorldBooleanFact
RecordVersion: 1
Value: true
```

### Durable interactable state
```text
RecordId: <semantic GUID>
RecordKind: InteractableState
RecordVersion: 1
State: Opened
```

### Quest progression
```text
RecordId: <quest semantic GUID>
RecordKind: QuestState
RecordVersion: 1
Stage: 4
Resolution: InProgress
ChoiceFacts: [stable semantic IDs]
```

### Completion entry
```text
RecordId: <completion semantic GUID>
RecordKind: CompletionEntry
RecordVersion: 1
Resolution: Complete
Variant: optional authored enum
```

The exact C++ in-memory representation may use normal USTRUCTs or a reviewed tagged/variant wrapper, but serialization must map through stable `RecordKind`, not type paths.

## 7. Section-specific shapes

### Checkpoint
Single typed record, not an arbitrary array:

```text
CheckpointId : FStillringPersistentId
AreaId : stable semantic area ID
SavedTransform : transform
ActiveSemanticLayer : Waking | Hush
RecoveryContext : optional authored enum/ID
```

Raw transform is subordinate to semantic checkpoint/area identity.

### PlayerProgression
Typed durable capability/progression fields plus stable upgrade IDs. Avoid duplicating inventory-owned tools/upgrades.

### Inventory
Canonical entries sorted by item semantic ID:

```text
ItemId
Count
DurableVariant/UpgradeState if item-owned
```

Zero-count entries are omitted unless zero itself carries authored history.

### QuestState
One record per touched/active/resolved semantic quest/objective group as defined by quest authority. Untouched quests may be absent where absence explicitly means canonical initial state.

### WorldState
Stable persistent fact/interactable/world-pivot records keyed by semantic ID. Hush shared/layer-local facts may be referenced/coordinated here but are not duplicated with contradictory values.

### HushState
Contains the committed semantic active layer and Hush-domain records that belong specifically to World-Layer authority.

### EncounterState
Stores durable unique encounter/boss outcomes only, not active combat simulation.

### CompletionState
Stores canonical completed/resolved semantic completion entries. Percentages/count summaries are derived caches, not canonical records.

### NpcRecurrenceState
Stores authored durable recurrence/relationship/location-phase facts for named persistent NPCs where not already owned as world/quest facts.

## 8. Sparse/default omission policy

Schema v1 is sparse where absence has an explicit, stable meaning.

Allowed omission examples:
- untouched quest = authored initial state;
- uncollected completion item = absent;
- default closed shortcut = absent if canonical default is defined in authored data;
- zero ordinary currency count = absent;
- unresolved optional encounter = absent if canonical initial state is unambiguous.

Do **not** use absence when it could mean multiple things such as:
- unknown vs false;
- not-yet-migrated vs default;
- deleted content vs never touched;
- intentionally cleared vs absent.

For those cases, store an explicit state.

## 9. Canonical deterministic ordering

Even if runtime containers are maps/sets, canonical serialization/testing order is deterministic.

Required order:
1. top-level sections in schema-defined order;
2. within a section, records sorted by canonical persistent GUID byte/hex ordering;
3. secondary arrays of stable IDs sorted unless gameplay semantics explicitly depend on authored order;
4. map-like entries canonicalized by stable key.

Benefits:
- reproducible golden fixtures;
- clean diffs for text/debug exports;
- deterministic hashes/checks later;
- easier migration tests;
- less false churn in QA evidence.

Gameplay order-sensitive lists, such as an authored ordered quest sequence, may preserve explicit sequence order because order is semantic data rather than container accident.

## 10. Unknown-field and unknown-record posture

Decision #4 will define compatibility/migration outcomes, but v1 must be structured so unknown data can be detected rather than misinterpreted.

Required:
- every section/record declares version/kind;
- loaders distinguish `UnknownRecordKind`, `UnsupportedRecordVersion`, and `UnknownPersistentId`;
- an unknown field/record may not silently become a default known value if that changes gameplay meaning;
- diagnostic tooling must retain enough context to identify the offending section/record.

Whether unsupported data is ignored, migrated, quarantined, or rejects load is Decision #4.

## 11. No raw object graph serialization

Schema v1 explicitly forbids canonical save fields containing:
- UObject pointer/reference as persistent identity;
- Actor pointer/reference;
- component pointer/reference;
- soft object path as gameplay identity;
- Behavior Tree task graph/state;
- animation instance/state machine graph;
- Data Layer runtime instance handles;
- streaming handles/cell IDs;
- UI widget state;
- arbitrary reflected property walk of live Actors.

Asset references may exist only where a domain explicitly needs a stable authored asset/config reference and that reference is not being used as world identity. Such references require migration review if renamed/moved.

## 12. Runtime binary vs diagnostic text

The production save may be binary for size/speed/platform compatibility.

Stillring must also support a development-only canonical semantic export in human-readable structured text (JSON-like is acceptable) generated from the same in-memory snapshot.

The diagnostic export is used for:
- golden fixtures;
- PR evidence;
- migration tests;
- bug capture;
- schema inspection.

It is not automatically the shipping save file format.

## 13. Example v1 semantic fixture

Illustrative canonical debug export:

```json
{
  "header": {
    "schemaVersion": 1,
    "playthroughId": "11111111-1111-1111-1111-111111111111",
    "snapshotId": "22222222-2222-2222-2222-222222222222",
    "capturedAtUtc": "2026-09-05T15:00:00Z",
    "accumulatedPlayTimeSeconds": 9421,
    "contentRevision": "vertical-slice-v1",
    "saveReason": "Checkpoint"
  },
  "checkpoint": {
    "sectionVersion": 1,
    "checkpointId": "30000000-0000-0000-0000-000000000001",
    "areaId": "rootmere.cathedral",
    "activeSemanticLayer": "Hush",
    "transform": { "x": 120.0, "y": -48.0, "z": 312.0, "yaw": 90.0 }
  },
  "inventory": {
    "sectionVersion": 1,
    "records": [
      {
        "recordId": "40000000-0000-0000-0000-000000000001",
        "recordKind": "ToolOwnership",
        "recordVersion": 1,
        "owned": true
      }
    ]
  },
  "questState": {
    "sectionVersion": 1,
    "records": [
      {
        "recordId": "50000000-0000-0000-0000-000000000001",
        "recordKind": "QuestState",
        "recordVersion": 1,
        "stage": 3,
        "resolution": "InProgress"
      }
    ]
  },
  "worldState": {
    "sectionVersion": 1,
    "records": [
      {
        "recordId": "60000000-0000-0000-0000-000000000001",
        "recordKind": "InteractableState",
        "recordVersion": 1,
        "layerScope": "Shared",
        "state": "Released"
      }
    ]
  },
  "hushState": {
    "sectionVersion": 1,
    "activeSemanticLayer": "Hush",
    "records": []
  },
  "encounterState": { "sectionVersion": 1, "records": [] },
  "completionState": { "sectionVersion": 1, "records": [] },
  "npcRecurrenceState": { "sectionVersion": 1, "records": [] }
}
```

This fixture demonstrates shape only; IDs and values are synthetic test data.

## 14. Snapshot construction

The Save Coordinator constructs `FStillringSaveV1` from already-settled owner snapshots.

Required sequence:
1. reach save-stable semantic barrier;
2. request immutable snapshots from each owner;
3. validate cross-owner invariants;
4. assemble/canonicalize v1 aggregate;
5. produce optional debug export/hash;
6. hand immutable snapshot to async/sync disk serialization;
7. gameplay may continue after capture; later mutations belong to the next snapshot.

The serializer does not query live Actors while writing bytes.

## 15. System IDE requirements

### Inspect
- current schema version;
- section versions;
- record counts;
- canonical ordering;
- record kind/version/owner;
- sparse/default interpretation;
- unknown/unsupported records;
- raw semantic debug export.

### Exercise
- capture snapshot twice with unchanged semantic state and compare canonical export;
- shuffle runtime container insertion order and prove identical canonical output;
- add/remove default-state records and prove normalized equivalence where omission is legal;
- inject unknown record kind/version for compatibility testing;
- round-trip serialize/deserialize without a loaded gameplay map where practical.

### Validate
Hard fail on:
- missing `SchemaVersion`;
- zero/duplicate persistent IDs where forbidden;
- unknown section ownership;
- raw UObject/Actor reference marked canonical;
- duplicate canonical fact in multiple sections;
- non-deterministic canonical export;
- record kind whose serialized identity depends on UObject/class/package path.

## 16. Deterministic fixtures

### S3-F01 — empty new game
Create canonical v1 default snapshot; sparse sections normalize deterministically.

### S3-F02 — ordering independence
Insert same records in randomized runtime order; serialized semantic export is byte-for-byte identical after canonicalization.

### S3-F03 — binary round trip
Semantic v1 snapshot -> runtime serialization -> load -> canonical debug export equals source semantic snapshot.

### S3-F04 — sparse equivalence
Explicit default and legal omission normalize to one canonical semantic result.

### S3-F05 — unknown kind
Unknown `RecordKind` is identified precisely and not interpreted as a known default.

### S3-F06 — unsupported record version
Known kind with unsupported version reports section/ID/kind/version explicitly.

### S3-F07 — refactor immunity
Rename C++ payload struct / move asset representation while stable record kind + semantic ID remain; fixture still resolves through reviewed serializer adapter.

### S3-F08 — Hush checkpoint
Fixture with Hush active, shared fact, and safe checkpoint reconstructs semantic state without serialized Data Layer process state.

### S3-F09 — no object graph
Schema scan proves no canonical record embeds runtime Actor/UObject identity.

### S3-F10 — golden fixture
Repository-stored canonical debug fixture remains stable unless schema/semantic authority deliberately changes.

## 17. Accessibility / player-facing implications

Schema shape is invisible during healthy play, but deterministic explicit state improves recovery and prevents accessibility/profile choices from being tangled with playthrough data. Diagnostic exports use stable human-readable field labels while GUIDs remain authoritative identity.

## 18. IP boundary

This is an original semantic schema built from public Unreal serialization primitives and generic versioned-data design. It does not reproduce proprietary Zelda/Nintendo save formats, flag tables, byte layouts, or reverse-engineered identifiers.

## 19. Rejected alternatives

### Serialize all `SaveGame`-marked/live Actor properties automatically
Rejected: representation leakage and unclear ownership.

### One untyped key/value dictionary
Rejected: weak validation, silent type drift, poor migrations.

### UObject/class path as record discriminator
Rejected: refactor-hostile and violates semantic identity rules.

### Store canonical completion percentage
Rejected when it can be derived from canonical completion records.

### JSON as mandatory shipping format
Rejected: human-readable diagnostic export is required, but shipping encoding remains an implementation/platform decision.

## 20. Approval

**APPROVED / LOCKED under the owner's scheduled-run delegation.**

Issue #4 Decision #3 is complete.

### Locked statement

> **Save v1 is an explicit, versioned, typed semantic aggregate with deterministic ordering and stable IDs. Unreal serializes it; Unreal does not define its meaning.**

## Next decision

Issue #4 Decision #4:

> **What is the schema/version migration policy from v1 onward, including content-ID retirement and compatibility guarantees?**
