# 82 — Persistent World-State / Save Decision #2 — State Taxonomy and Ownership

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #4 — Define persistent world-state and save schema  
**Decision:** #2 — persistent state categories, authoritative owners, and non-persistent derived/transient state

## Decision question

Which game-state categories belong in a playthrough save, which system owns each category, and which runtime states must be reconstructed instead of serialized?

## Locked philosophy

> **Persist meaning. Reconstruct presentation. One truth has one owner.**

A save is a coherent snapshot of authoritative gameplay facts. It is not a memory dump of Actors, components, animation, AI tasks, streaming representation, UI, or presentation state.

## Research basis

Fresh Unreal Engine 5.8 research confirms:
- `USaveGame` is a user-defined data container; Unreal does not decide the game's semantic ownership model.
- Epic recommends asynchronous save operations where appropriate, but the project still owns the coherent snapshot that is handed to disk I/O.
- `UGameInstance` / `UGameInstanceSubsystem` have a lifetime that spans world/map transitions, making them credible hosts for a save coordinator or playthrough-state service, but lifetime is not the same thing as semantic authority.
- Gameplay Tags are hierarchical labels useful for authored concepts and queries, but a tag's presence alone should not become a substitute for typed, owned persistence records.

Primary references:
- Epic UE5.8 — Saving and Loading Your Game: https://dev.epicgames.com/documentation/unreal-engine/saving-and-loading-your-game-in-unreal-engine
- Epic UE5.8 — `UGameInstance`: https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Engine/UGameInstance
- Epic UE5.8 — `UGameInstanceSubsystem`: https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Engine/UGameInstanceSubsystem
- Epic UE5.8 — Programming Subsystems: https://dev.epicgames.com/documentation/en-us/unreal-engine/programming-subsystems-in-unreal-engine
- Epic UE5.8 — Gameplay Tags: https://dev.epicgames.com/documentation/en-us/unreal-engine/using-gameplay-tags-in-unreal-engine

Project authority reconciled:
- `docs/10_COMPLETION_MODEL.md`
- `docs/11_QUEST_AND_COMPLETION_LEDGER.md`
- `docs/12_100_PERCENT_ROUTE.md`
- `docs/19_WORLD_PRODUCTION_CONTRACT.md`
- `docs/48_GATE2_COMBAT_STATE_MODEL.md`
- `docs/69_GATE3_TOOL_PUZZLE_CUMULATIVE_SPECIFICATION.md`
- `docs/75_GATE4_HUSH_SAVE_RELOAD_ADDENDUM.md`
- `docs/79_GATE4_HUSH_CUMULATIVE_SPECIFICATION.md`
- `docs/81_SAVE_PERSISTENT_IDENTITY_ADDENDUM.md`

## 1. Single-writer rule

Every canonical persistent fact has exactly one authoritative gameplay owner.

Other systems may:
- observe;
- cache;
- present;
- derive consequences;
- request a change through the owner.

They may not independently persist contradictory copies of the same truth.

The Save Coordinator owns **snapshot orchestration and serialization**, not gameplay truth. It asks each authoritative domain for a stable snapshot and later dispatches restored records back to the correct domain.

## 2. Persistent playthrough categories

### A. Save header / compatibility metadata
**Owner:** Save Coordinator / Save Schema service.

Persistent:
- schema version;
- build/content compatibility metadata required by later migration policy;
- playthrough/slot semantic ID;
- snapshot timestamp/playtime where useful;
- checkpoint/location context required to restore safely;
- integrity/check metadata selected by later decisions.

Not gameplay authority:
- quest/world facts themselves;
- raw Actor lists.

### B. Player progression and durable capability state
**Owner:** Player Progression service.

Persistent:
- durable health-capacity/progression upgrades if retained by progression design;
- permanently unlocked traversal/gameplay capabilities;
- learned/authorized player progression states not represented as inventory items;
- durable progression counters only where authored as progression.

Not persistent here:
- current velocity;
- movement state machine node;
- Sprint state;
- mantle/hang/ladder state;
- current animation;
- camera blend;
- temporary hit reaction;
- transient buffs unless a later specific mechanic explicitly requires save persistence.

### C. Inventory / tools / currencies / owned upgrades
**Owner:** Inventory & Tool Progression service.

Persistent:
- owned unique tools;
- owned tool upgrades;
- stack/count of currencies/materials that canonically survive save/load;
- durable consumable counts where the game design retains them;
- equipped/default loadout preference when meaningful and safe to restore.

For Cantor/Anchor:
- acquired patterns/upgrades belong to inventory/tool progression;
- current beam/line candidate, tension solve, preview, attach transaction, transient tool mode, and targeting traces do not.

### D. Quest / objective / authored narrative progression
**Owner:** Quest / Story State service.

Persistent:
- semantic quest IDs;
- explicit authored stage/resolution states;
- branch/choice facts that alter later content;
- objective completion/activation states where needed to resume coherently;
- one-shot narrative events that must not replay.

A quest may reference world facts, but it must not duplicate them as private contradictory booleans. If a bridge's repaired state is a world fact, the quest reads that fact or stores only its own semantic consequence.

### E. World facts / persistent environment state
**Owner:** World State service.

Persistent examples:
- repaired/broken/opened/disabled authored mechanisms;
- shortcut state;
- authored cross-state setup/payoff facts;
- permanent environmental changes;
- catastrophe/global pivot facts;
- settlement/community persistent consequences;
- semantic recurring-NPC/world facts not owned by quest state;
- Hush/Waking shared or layer-local persistent facts when the World-Layer service declares them durable.

All are keyed by Decision #1 semantic IDs.

### F. Hush / Waking semantic layer state
**Owner:** World-Layer/Hush service; snapshot coordinated through World State.

Persistent:
- one committed `ActiveSemanticLayer` when save-stable;
- shared persistent facts once per semantic identity;
- explicitly layer-local persistent facts with semantic layer scope;
- cross-layer causal facts required by Gate 4.

Not persistent:
- Data Layer activation progress;
- visual blend amount;
- seam request/prepare/presentation state;
- collision handoff process;
- transition audio/VFX/camera state.

`docs/75` remains authoritative for save-stable boundaries.

### G. Boss and unique encounter outcome state
**Owner:** Encounter State service, with world consequences exported as World Facts where appropriate.

Persistent:
- unique boss defeated/not-defeated outcome;
- authored encounter resolution state;
- persistent unique-enemy death only when specifically designed as durable;
- encounter-specific one-shot reward claimed state if not owned by inventory/completion.

Ordinary encounter moment-to-moment combat is **not** persisted by default:
- current AI target;
- exact enemy transforms for ordinary combat;
- montage section/time;
- Behavior Tree task stack;
- attack cooldown timers;
- temporary stagger;
- projectiles;
- hit volumes;
- attack tokens/pressure queue.

Reload returns to an authored safe encounter state/checkpoint rather than reconstructing a half-swing combat frame.

### H. Shortcuts / persistent interactables
**Owner:** World State service, unless the object is specifically a quest-only semantic state.

Persistent examples:
- door permanently unlocked/opened when authored durable;
- lift activated;
- bridge deployed;
- refuge restored;
- one-shot chest/container consumed;
- authored machine repair state.

Momentary presentation/physics is derived from the semantic fact.

### I. Collectibles / completion ledger
**Owner:** Completion Ledger service.

Persistent:
- canonical authored completion IDs from docs 10–14;
- resolved status/variant where the category requires it;
- counted threshold progress derived from canonical item/entry completion where possible;
- prestige/hunt/mastery resolution records;
- field-record/testimony acquisition;
- regional completion facts used for 100% reconciliation.

Do not persist a second independent percentage as canonical truth when it can be recomputed from completed semantic IDs. Cached percentages may exist but are disposable.

### J. Catastrophe / region/world-pivot state
**Owner:** World State service, requested by Story/Quest authority where the narrative event causes it.

Persistent:
- Grand Ring / Stillness and other major irreversible world pivots;
- changed-region phase/state;
- community consequences that transform recurrence/available content;
- setup/payoff outcomes.

Narrative sequencing and world expression must converge on one canonical pivot fact rather than separate quest/world booleans that can disagree.

### K. NPC recurrence / durable relationship-state facts
**Owner:** World State or dedicated NPC Recurrence service if/when Gate 6 promotes one. Until then, World State is canonical.

Persistent when authored:
- alive/dead/absent/relocated status for persistent named NPCs;
- resolved authored relationship/knowledge/recurrence facts;
- one-shot conversation consequences required for future recurrence;
- community role changes.

Not persistent:
- current nav path;
- locomotion animation;
- current behavior-tree task;
- incidental local transform unless an authored resume contract requires it.

### L. Player location / checkpoint state
**Owner:** Checkpoint/Travel service, coordinated by Save Coordinator.

Persistent:
- semantic checkpoint/area ID;
- reviewed player transform only when captured at a save-stable boundary;
- active semantic Hush/Waking layer context;
- any minimal authored spawn/recovery context required to validate placement.

The checkpoint semantic identity outranks raw coordinates for recovery. Raw transform is a requested restoration location, not sufficient identity by itself.

## 3. Separate profile/settings data

Player settings are **not playthrough world-state**.

Examples:
- graphics;
- audio volume;
- control remaps;
- sensitivity/inversion;
- subtitles;
- camera-shake accessibility preference;
- hold/toggle accessibility settings.

They belong to a separate user/profile/settings persistence channel (`UGameUserSettings`, Enhanced Input user settings, or Stillring profile service as appropriate), not duplicated into every playthrough save unless platform/product requirements later demand a reviewed subset.

Settings may affect presentation/input ergonomics but never mutate canonical world facts or completion legality.

## 4. Explicitly transient / derived state

Do **not** serialize as canonical truth by default:

### Player/locomotion
- velocity/acceleration;
- movement mode phase;
- coyote/buffer timers;
- current mantle/ledge/ladder transaction;
- Sprint held/toggled active state;
- air-control frame;
- knockback/hit-reaction phase.

### Camera/targeting
- camera transform as authoritative world state;
- target Actor pointer;
- lock candidate list;
- lock transition blend;
- occlusion grace timer;
- shake instance;
- camera collision compression state.

### Combat
- attack startup/active/recovery phase;
- buffered input;
- guard/perfect-guard timing window;
- evade i-frame window;
- active projectile pointers;
- AI Behavior Tree stack;
- temporary encounter pressure/attack-token queue.

### Tool/puzzle presentation
- current Cantor scan trace;
- candidate highlighting;
- Anchor aim preview/line solver intermediate state;
- animation state;
- particles/audio cues;
- derived mechanism pose when reconstructable from facts.

### Hush representation
- Data Layer load/activation handles;
- seam presentation percentage;
- collision handoff timeline;
- source/destination streaming progress;
- post-process/material/audio transition timeline.

### UI/developer state
- open menu/widget;
- cursor/highlight;
- debug overlays;
- System IDE open panels;
- temporary session overrides;
- fault-injection state.

## 5. Derived-versus-persistent test

A value should be **derived**, not persisted, when all are true:
1. the authoritative inputs are already persisted;
2. reconstruction is deterministic enough for gameplay correctness;
3. saving it would create a second copy that could disagree;
4. it is not itself an authored historical fact.

A value should be persistent when at least one is true:
- it records an irreversible/meaningful authored player action or world consequence;
- it cannot be reconstructed from more fundamental persistent facts without losing player intent/history;
- it represents durable ownership/progression/completion;
- it is explicitly needed to resume at a reviewed safe point.

## 6. Fact transaction rule

One gameplay operation may touch multiple domain owners, but the save snapshot may occur only after the semantic transaction settles.

Examples:

### One-shot pickup
1. Inventory grants item/currency.
2. World State marks pickup consumed if durable.
3. Completion Ledger marks completion ID if completion-bearing.
4. transaction settles;
5. save may snapshot.

### Boss death
1. Encounter State commits defeated outcome.
2. World State commits authored world consequence.
3. Quest/Story advances only through its own state transition if applicable.
4. Completion Ledger records optional elite/boss completion where relevant.
5. reward transaction settles.
6. save may snapshot.

No system writes another owner's state directly just to make saving convenient.

## 7. Reset / new game / developer preset boundaries

### New game
Creates a new playthrough-state aggregate from canonical defaults. Profile/settings remain separate.

### Checkpoint retry/death retry
Restores only categories explicitly governed by the death/retry contract. It is **not automatically equivalent to loading the last disk save**.

### Developer named preset
A preset is an authored request to construct a valid semantic state through authoritative owner APIs. It must not mutate raw private fields or become an undocumented magic save.

### System IDE reset
Scoped reset identifies exactly which domain/category it changes and uses the authoritative owner transaction path.

## 8. Ownership conflict validation

The Save / World-State IDE and validation tooling must detect:
- two domains claiming canonical write ownership of one persistent ID/fact;
- same semantic fact serialized in two sections with differing values;
- quest-local duplicate of a world fact where both claim authority;
- completion percentage disagreeing with underlying completion IDs;
- Hush/Waking paired shared fact duplicated once per representation;
- inventory ownership disagreeing with persistent pickup-consumed state;
- boss defeated state disagreeing with world/quest consequence after transaction settle;
- persistent field with no declared owner;
- derived/transient field incorrectly marked canonical.

## 9. Save / World-State System IDE

### Inspect
Show per persisted record:
- persistent ID;
- category/domain;
- authoritative owner;
- current value/state;
- source of last mutation;
- whether canonical / derived / transient;
- whether dirty since last snapshot;
- snapshot value versus live value.

### Exercise
- construct a named semantic state through owner APIs;
- run cross-owner pickup/boss/quest transactions;
- request snapshot at stable and intentionally unstable points;
- simulate unload/reload;
- recompute derived completion/representation and compare.

### Validate
Provide a single **ownership graph** view showing every persisted category and its writer. Any cycle or duplicate canonical owner is a hard design/implementation error.

## 10. Deterministic fixtures

### S2-F01 — pickup atomicity
Item granted + pickup consumed + optional completion fact settle together before snapshot.

### S2-F02 — boss transaction
Boss outcome, world consequence, quest consequence, reward/completion converge without duplicate authority.

### S2-F03 — Hush shared fact
One shared persistent fact reconstructs both layer expressions; no duplicate layer copy.

### S2-F04 — derived completion
Completion percentage/count recomputes from semantic entries and matches expected totals.

### S2-F05 — settings separation
Changing camera accessibility/remap does not modify playthrough world-state snapshot.

### S2-F06 — transient combat rejection
Attempt to snapshot attack phase/BT task/projectile pointer as canonical state fails schema validation.

### S2-F07 — checkpoint recovery
Saved semantic checkpoint + transform restores safely; invalid migrated transform falls back through later recovery policy without inventing world facts.

### S2-F08 — named dev preset
Preset constructs a late story/Hush/tool state only through declared owner APIs and passes invariant validation.

### S2-F09 — duplicate ownership
Quest and World State intentionally attempt to own same fact; validation rejects the schema/registration.

### S2-F10 — unload independence
Persistent world fact remains queryable while its Actor representation is unloaded.

## 11. Accessibility / player-facing implications

- Accessibility settings persist independently from playthrough state and never change completion validity.
- Save/load must not lose remapping/subtitle/shake preferences merely because a playthrough slot changes.
- Derived UI may present state differently but cannot create a second progression truth.
- Recovery messaging should speak in human terms; diagnostics keep stable IDs/category ownership.

## 12. IP boundary

This is an original state-ownership architecture using public Unreal persistence/subsystem concepts and generic software design principles. It does not reproduce Nintendo/Zelda save flags, proprietary category layouts, reverse-engineered schemas, or platform-specific data.

## 13. Rejected alternatives

### One giant bag of booleans
Rejected: destroys ownership, migration clarity, validation, tooling, and causal understanding.

### Every Actor saves itself
Rejected: unloaded Actors disappear from authority; Actor lifecycle/order becomes the hidden database; cross-system transactions become incoherent.

### Save Coordinator owns all gameplay state
Rejected: serialization infrastructure should coordinate, not become a god object that duplicates combat/quest/world/inventory rules.

### Save everything visible/runtime-active
Rejected: creates brittle Actor-graph snapshots and persists huge amounts of meaningless transient state.

### Persist only quest flags
Rejected: world, inventory, completion, Hush, encounter, and recurrence have durable state that cannot safely be hidden behind quest implementation details.

## 14. Approval

**APPROVED / LOCKED under the owner's scheduled-run delegation.**

Issue #4 Decision #2 is complete.

### Locked statement

> **Each durable fact has one gameplay owner; the save system snapshots those owners. Runtime presentation is rebuilt, not promoted into truth.**

## Next decision

Issue #4 Decision #3:

> **What is Save Schema v1's top-level structure and canonical record shape?**
