# 87 — Persistent World-State / Save Decision #7 — Save / World-State System IDE

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #4 — Define persistent world-state and save schema  
**Decision:** #7 — complete in-game authoring, inspection, validation, fixture, migration, recovery, and capture workbench

## Decision question

What must Stillring's Save / World-State System IDE expose so persistence can be authored, understood, reproduced, validated, and evolved from inside the running development build without creating a second hidden persistence system?

## Locked philosophy

> **The save IDE explains the truth, exercises the truth, and validates the truth. It never becomes a second owner of the truth.**

The workbench calls the same authoritative domain services used by ordinary gameplay. Raw file/byte inspection is supplementary diagnostics, never the normal authoring model.

## Research basis

Fresh Unreal Engine 5.8 research confirms useful implementation primitives:
- Gameplay Debugger supports extensible real-time runtime categories, demonstrating the value of semantic runtime inspection rather than offline archaeology.
- Automation Specs and CQTest support unit/integration/functional fixture-style tests and resettable before/after state.
- Gauntlet can run Automation/functional tests in Editor and packaged client targets, useful for persistence verification outside one workstation session.
- UMG/Slate expose accessibility metadata and screen-reader support; the workbench must remain navigable and readable rather than becoming mouse-only developer UI.

Primary references:
- Epic UE5.8 — Gameplay Debugger: https://dev.epicgames.com/documentation/en-us/unreal-engine/using-the-gameplay-debugger-in-unreal-engine
- Epic UE5.8 — Automation Spec: https://dev.epicgames.com/documentation/en-us/unreal-engine/automation-spec-in-unreal-engine
- Epic UE5.8 — CQTest: https://dev.epicgames.com/documentation/unreal-engine/cqtest-test-framework-for-unreal-engine
- Epic UE5.8 — Running Gauntlet Tests: https://dev.epicgames.com/documentation/en-us/unreal-engine/running-gauntlet-tests-in-unreal-engine
- Epic UE5.8 — Supporting Screen Readers: https://dev.epicgames.com/documentation/unreal-engine/supporting-screen-readers-in-unreal-engine

Project authority reconciled:
- `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
- `docs/75_GATE4_HUSH_SAVE_RELOAD_ADDENDUM.md`
- `docs/81`–`docs/86`

## 1. Workbench identity

Registered shared-shell workbench:

`Save / World-State IDE`

Primary modes:
1. **Overview**
2. **Identity**
3. **Live State**
4. **Snapshot / Schema**
5. **Fixtures / Presets**
6. **Migration**
7. **Recovery / Generations**
8. **Validation**
9. **Capture / Diff**

The modes are one coherent workbench, not separate authority implementations.

## 2. Overview

The opening view answers, without file archaeology:
- current logical playthrough ID;
- current schema/content revision;
- active semantic checkpoint/region/layer;
- last successful snapshot/generation;
- current LKG status;
- dirty authoritative domains;
- save-stable or blocked state and exact blockers;
- queued/in-flight save request/reason;
- Retry Checkpoint Snapshot source;
- current validation health;
- migration/recovery warning state.

One developer should be able to answer “what will be saved if I press save now, and why?” immediately.

## 3. Identity mode

### Inspect
Search/browse persistent semantic IDs by:
- GUID;
- human debug name;
- domain/owner;
- current region/source authority;
- Hush/Waking pairing;
- loaded representation;
- tombstone/migration status.

For one identity show:
- canonical GUID;
- semantic owner class;
- source repository-backed authority;
- runtime registered representation(s);
- currently persisted record(s);
- layer scope;
- referenced migration/tombstone entries;
- last semantic mutation/capture where available.

### Author
Allowed controlled authoring:
- assign a new persistent GUID to a new authored persistent definition;
- deliberately pair Waking/Hush expressions to one semantic identity;
- stage debug-name/domain/source metadata changes;
- stage retirement/migration disposition for review.

Forbidden casual actions:
- random “regenerate ID” button on established production content;
- silently copy an existing GUID to unrelated content;
- reuse tombstoned GUID;
- convert runtime Actor name/path into canonical ID.

Any identity replacement displays migration consequences before promotion.

## 4. Live State mode

Show all canonical owner domains from Decision #2:
- Player Progression;
- Inventory/Tools;
- Quest/Story;
- World Facts;
- World-Layer/Hush;
- Encounter Outcomes;
- Completion;
- NPC Recurrence;
- Checkpoint/Travel.

Each fact/record shows:
- persistent ID;
- record kind/version;
- canonical value;
- authoritative owner;
- last mutation reason/source;
- current live value vs last published snapshot;
- dirty state;
- derived dependents;
- loaded representation links if any.

Derived/transient systems are clearly labeled and may be linked for context but cannot masquerade as persisted truth.

## 5. Ownership graph

A dedicated graph/table visualizes:
- persistent fact -> canonical writer;
- observer/dependent systems;
- cross-domain transaction edges;
- duplicated/conflicting ownership.

Hard-error examples:
- quest and World State both claiming the same bridge fact;
- completion percentage persisted independently from completion IDs;
- Waking/Hush expressions each claiming a shared fact;
- inventory pickup owned in both Inventory and Actor-local persistence.

The graph is generated from registered persistence declarations/authority, not manually maintained decorative documentation alone.

## 6. Snapshot / Schema mode

### Inspect current snapshot
Show:
- header fields;
- section versions/counts;
- record envelope fields;
- deterministic canonical order;
- sparse/default interpretation;
- integrity metadata;
- owner source for each record.

### Semantic export
One action generates the development-only canonical human-readable export from Decision #3.

Exports support:
- copy/save to evidence artifact;
- canonical hash/digest;
- section filtering;
- stable-ID search;
- redacted/retail-safe mode where future sensitive user/platform metadata exists.

### Binary boundary
Raw bytes/hex may be available as an advanced diagnostic view, but no production authoring action edits arbitrary bytes in-place. Semantic records remain the normal interface.

## 7. Snapshot comparison

Compare any two semantic snapshots/fixtures/generations.

Diff groups by:
- added records;
- removed records;
- changed records;
- version changes;
- owner changes;
- persistent-ID migrations;
- checkpoint/layer changes;
- completion/inventory/quest/world consequences.

The diff distinguishes:
- expected semantic mutation;
- derived/cache-only difference;
- suspicious duplicate/ownership change.

No “diff” should require comparing Actor memory addresses.

## 8. Named semantic presets

Presets are repository-backed semantic recipes, not opaque save binaries.

Each preset declares:
- stable preset ID/name;
- intended story/world/Hush/checkpoint scenario;
- prerequisite base preset/default state;
- owner-API mutations required;
- expected invariants;
- relevant System IDE links/test scenario;
- whether retail-representative or deliberately adversarial.

Examples:
- `save.new_game.clean`
- `save.pre_stillness.rootmere`
- `save.post_stillness.hush_cathedral`
- `save.boss_resolved.reward_pending_adversarial`
- `save.migration.v1_fixture`

Preset construction calls authoritative services in an ordered transaction and validates the final semantic state. It does not write private fields directly.

## 9. Preset promotion

A session-built preset can be exported/staged as reviewable structured text.

Promotion requirements:
- exact owner mutations listed;
- persistent IDs referenced explicitly;
- expected final canonical export/hash;
- no session-only object paths/pointers;
- diff reviewed before repository promotion.

A one-off “magic state” that exists only in a developer's local save is not production authority.

## 10. Exercise — saving

Actions:
- request manual save;
- trigger each autosave reason family;
- show/defer save-stable blockers;
- coalesce multiple triggers;
- inject dirty mutation during in-flight save;
- inspect candidate publication/LKG rotation;
- retry failed save;
- simulate quit-with-dirty-state.

The workbench never bypasses the Save Coordinator to call platform write functions directly as a shortcut.

## 11. Exercise — loading/reconstruction

Actions:
- load current/LKG/older development generation;
- reconstruct from named fixture;
- simulate unloaded world representation then attach semantic state;
- test Hush/Waking reconstruction;
- test valid/invalid checkpoint transform;
- compare pre-load semantic source to post-reconstruction owner state.

Loading a fixture passes through normal version/migration/validation/reconstruction services.

## 12. Migration mode

Implements Decision #4 Migration Preview.

Show:
- source/current global version;
- section/record versions;
- ordered migration chain;
- every ID Alias/Retire/Split/Merge disposition;
- records before/after;
- semantic warnings/errors;
- source content revision;
- final invariant result;
- canonical post-migration export/hash.

Actions:
- dry-run migration;
- compare two migration implementations/fixtures where relevant;
- export audit report;
- run all historical golden fixtures.

Dry run never modifies source generation.

## 13. Recovery / Generations mode

Show one logical playthrough's generations as a recovery chain:
- candidate/current;
- LKG;
- older recovery;
- quarantined/incomplete generation;
- developer-only generations.

Per generation:
- snapshot/generation ID;
- timestamp/playtime;
- integrity state;
- schema/content revision;
- migration result;
- semantic invariant state;
- recovery eligibility;
- rejection/failure class.

Actions are development-only and explicit:
- simulate load-selection algorithm;
- mark synthetic candidate incomplete;
- run corruption faults;
- compare selected LKG;
- export forensic report.

The IDE does not casually let developers mark invalid bytes “good” to force a load.

## 14. Fault injection

Development/Test only, with unmistakable visual state.

Supported deterministic faults:
- truncate serialized candidate;
- alter integrity digest;
- duplicate GUID;
- remove required section;
- unknown record kind/version;
- unknown/tombstoned ID;
- missing migration adapter;
- contradictory quest/world ownership;
- Hush shared/layer-local conflict;
- invalid checkpoint transform/area;
- storage write failure;
- crash point before/after publication step;
- dirty mutation during in-flight save.

Fault injection never mutates canonical repository authority unless an explicit artifact is promoted through review.

## 15. Validation suite

One-click `Validate Save / World-State` runs at minimum:

### Identity
- non-zero GUID;
- no duplicate unrelated ownership;
- no tombstone reuse;
- pair identity consistency;
- no forbidden runtime/path identity.

### Ownership
- one writer per canonical fact;
- no duplicate cross-section truth;
- derived values not canonical;
- domain registration complete.

### Schema
- versions present/supported;
- deterministic canonical ordering;
- stable RecordKind identity;
- no raw Actor/UObject identity;
- sparse/default rules unambiguous.

### Migration
- every supported historical version has chain;
- every retired ID has disposition;
- golden migrations deterministic;
- source fixture preserved;
- no duplicate rewards/facts.

### Recovery
- LKG exists where expected;
- invalid newest cannot outrank valid older generation;
- failure classes distinct;
- no speculative semantic repair.

### Cadence/retry
- no overlapping writes;
- unsafe save requests defer;
- death itself is not serialized;
- retry snapshot and durable disk snapshot remain distinct;
- developer slots cannot become retail LKG.

## 16. Validation result quality

Every failure includes:
- stable rule ID;
- severity;
- human explanation;
- exact persistent ID/section/record/owner where applicable;
- source authority link/path when known;
- suggested safe next investigation, not an automatic destructive fix.

Example:

`SAVE-ID-004 Duplicate semantic GUID: 8A... claimed by Rootmere.CounterweightNorth and Mossward.RefugeLift. Production persistence identities must be unique unless explicitly paired.`

## 17. Cross-workbench links

Save IDE links directly to owning workbench context where available:
- Hush / World-Layer IDE for layer/pair facts;
- Quest / Objective / World-State IDE for narrative prerequisites;
- Completion IDE/ledger view for completion IDs;
- Inventory / Tool IDE for tool/reward ownership;
- Combat / Encounter IDE for unique encounter outcomes/retry context;
- Puzzle/Mechanism IDE for persistent mechanism facts.

Cross-links are navigation/read-context. Save IDE does not duplicate those systems' gameplay rules.

## 18. Capture / reproduction artifact

`Capture Save State` produces a structured evidence package containing:
- build/commit;
- map/region/checkpoint/layer;
- playthrough/snapshot/generation IDs;
- schema/section/record versions;
- canonical semantic export or selected sections;
- validation summary;
- migration/recovery trace if involved;
- queued/in-flight save state;
- Retry Checkpoint Snapshot identity;
- named preset/test case;
- recent semantic mutation log ring buffer where implementation supports it.

This artifact is designed so a later developer can reproduce the semantic problem without the original Actor names/layout.

## 19. Mutation log

Development builds should maintain a bounded semantic mutation log for persistent owners.

Each entry:
- sequence/time;
- owner/domain;
- persistent ID;
- previous/new value summary;
- mutation reason/event;
- transaction ID where relevant;
- whether mutation is included in last/current snapshot.

The log is diagnostic only and does not become gameplay truth or an event-sourcing requirement.

## 20. Accessibility / navigation

The workbench must:
- support keyboard and controller navigation through the shared shell;
- expose accessible names/summaries for major controls/records where Unreal accessibility support permits;
- not encode validation severity by color alone;
- support searchable/filterable tables rather than requiring tiny graph manipulation;
- allow copy/export without precise mouse dragging;
- avoid rapid/timed actions for destructive test operations;
- preserve clear focus state and return path after jumping cross-workbench.

Dense expert data is acceptable; inaccessible interaction is not.

## 21. Performance boundaries

The IDE may perform expensive validation/export on explicit developer request, but ordinary hidden instrumentation must not materially distort the save behavior being measured.

Rules:
- expensive full-world ID scans can be asynchronous/deferred in Development;
- mutation logging is bounded;
- canonical export is not generated every frame;
- validation timing is shown when useful;
- Shipping excludes developer-only instrumentation/dependencies.

## 22. Shipping exclusion

Shipping requirements from `docs/21` are mandatory.

For Save IDE specifically:
- no workbench registration/UI;
- no fault-injection commands;
- no arbitrary fixture/preset mutation console;
- no migration dry-run developer UI;
- no raw forensic file browser;
- no developer-only generation selector;
- no external network control listener;
- no model/API dependency;
- no keys/secrets;
- no Shipping code path that can bypass retail save validation/slot protections.

Shared authoritative save services remain in Shipping; only development interfaces/instrumentation are excluded.

## 23. Automation linkage

The IDE's deterministic actions should have callable non-UI equivalents usable by Automation Specs/CQTest/Gauntlet where practical.

Examples:
- build preset;
- capture canonical snapshot;
- validate identity/ownership/schema;
- migrate fixture;
- inject deterministic corruption in a test buffer;
- simulate save failure;
- compare canonical exports.

The UI and automated test harness call the same semantic test services, avoiding a second test-only behavior implementation.

## 24. Deterministic fixtures

### S7-F01 — identity lookup
Search GUID/debug name and resolve correct semantic owner/representations.

### S7-F02 — preset construction
Named preset constructs via owner APIs and matches expected canonical hash.

### S7-F03 — ownership graph conflict
Synthetic duplicate writer produces explicit rule/error and linked records.

### S7-F04 — canonical snapshot compare
Two semantically identical states with different runtime insertion order produce empty semantic diff.

### S7-F05 — migration preview
Historical fixture shows exact steps/ID mappings and leaves source unchanged.

### S7-F06 — recovery chain
Bad newest + good LKG visibly selects LKG for explicit reason.

### S7-F07 — fault injection
Each supported fault produces expected failure class without contaminating canonical repository state.

### S7-F08 — Hush cross-link
Shared/layer-local fact links between Save and Hush IDE with one canonical owner.

### S7-F09 — capture/repro
Capture artifact contains enough semantic context to recreate fixture without old Actor paths.

### S7-F10 — Shipping exclusion
Shipping build cannot register/open workbench or invoke fault/preset mutation surfaces while normal save/load remains functional.

### S7-F11 — accessible navigation
Core inspect/validate/migration/recovery workflows are keyboard/controller navigable with non-color-only status.

### S7-F12 — automation parity
A representative UI exercise and Automation/CQTest call use the same semantic service and produce equivalent result.

## 25. Acceptance hard failures

Save / Persistence IDE is incomplete if:
- it only exposes raw files/bytes;
- it cannot explain fact ownership;
- persistent IDs cannot be searched/validated;
- presets mutate private fields rather than owner APIs;
- migration/recovery requires manual file archaeology;
- semantic before/after diff is unavailable;
- fault injection can leak into Shipping;
- developer overrides look canonical;
- no reusable capture artifact exists;
- core workflows are mouse-only/inaccessible;
- automated fixtures exercise different logic from the workbench.

## 26. IP boundary

This is original development infrastructure using public Unreal runtime debugging/testing/accessibility primitives and Stillring's own semantic persistence model. It does not reproduce proprietary Nintendo/Zelda developer tools, save editors, debug menus, or internal test infrastructure.

## 27. Approval

**APPROVED / LOCKED under the owner's scheduled-run delegation.**

Issue #4 Decision #7 is complete.

### Locked statement

> **Stillring's Save IDE operates on semantic identities, owners, snapshots, migrations, and recovery chains—not Actor archaeology or byte poking—and every mutation routes through the same authoritative services as gameplay.**

## Next decision

Issue #4 Decision #8 — cumulative closure:

> **Reconcile Decisions #1–#7 into one implementation-facing save/world-state specification, acceptance matrix, decision-register extension, full-playthrough fixture contract, and Issue #4 closure boundary.**
