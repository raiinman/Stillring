# 78 — Gate 4 Hush Representation Candidate Comparison / Prototype Recommendation

**Status:** LOCKED DESIGN DECISION / PROVISIONAL IMPLEMENTATION RECOMMENDATION — scheduled-run owner delegation  
**Issue:** #126 — Gate 4 Hush-layer prototype design system  
**Decision:** #9 — compare UE5.8 representation candidates and define prototype evidence matrix/provisional implementation recommendation

## Decision

For the first real Gate 4 Hush prototype, Stillring should **prototype World Partition + Runtime Data Layers first**, with spatial grid streaming **disabled for the tiny paired-layer test area** unless measurement demonstrates a reason to enable it.

The semantic Hush service from Decisions #1–#8 remains the sole gameplay authority. Runtime Data Layers are the preferred **representation adapter**, not the saved/canonical world state.

The explicit non-World-Partition persistent-level + streamed-sublevel/Actor-group approach remains the required fallback comparator and should be retained conceptually until real UE5.8 prototype evidence closes the architecture choice.

Core recommendation:

> **Use Data Layers to express the two realities, not to define them. Start with World Partition's authoring model without taking on distance-streaming complexity until the game actually needs it.**

This is an implementation direction to test, not a fabricated claim that performance/source-control/save behavior has already been proven in a real UE5.8 build.

## Why this comparison exists

Stillring has two unusual requirements at once:
1. Waking and Hush frequently occupy the **same authored coordinates** with shared landmarks and paired differences;
2. the semantic state must remain independent of engine loading/presentation so saves, puzzles, combat, and future refactors stay reliable.

The engine representation should therefore make overlapping authored versions easy without becoming gameplay truth.

## Candidate A — World Partition + Runtime Data Layers

### Proposed Gate 4 layout

One World Partition test map containing semantic/authoring groups equivalent to:
- `Shared` — geometry/Actors intentionally invariant across Waking/Hush;
- `Waking` Runtime Data Layer — Waking-exclusive/paired expression Actors;
- `Hush` Runtime Data Layer — Hush-exclusive/paired expression Actors;
- optional presentation-only organizational layers where useful, never semantic authority.

For the tiny Gate 4 fixture:
- World Partition enabled;
- **Enable Streaming disabled initially** so distance-cell streaming does not contaminate seam measurements;
- both relevant expression sets may be prepared/loaded as needed;
- semantic layer service requests Data Layer runtime states through a representation adapter;
- physical authority still follows Decision #3 rather than assuming `Activated == gameplay truth`;
- stable pair/semantic IDs remain external to Data Layer names/Actor paths.

### Why disabling spatial streaming initially matters

Epic documents that World Partition can exist with streaming disabled. This lets Gate 4 evaluate:
- Data Layer authoring;
- overlapping expression management;
- One File Per Actor workflow;
- semantic↔representation handoff;
- save reconstruction;

without simultaneously testing distance-cell residency, HLOD, streaming-source tuning, and large-world load behavior.

That is cleaner science. Spatial streaming can be enabled later for production regions when region scale actually requires it.

## Candidate A strengths

### 1. Direct match for overlapping realities
Epic's own Valley of the Ancient sample uses Data Layers for overlapping light/dark versions of the same space, with common geometry remaining shared. That is extremely close to Stillring's representation problem at the engine-workflow level.

This is not authority for Stillring's mechanics or art; it is evidence that the tool is intended to organize runtime alternate expressions occupying the same level space.

### 2. Runtime state model already distinguishes residency/presentation
UE5.8 `EDataLayerRuntimeState` explicitly provides:
- `Unloaded`;
- `Loaded` — loaded but not visible;
- `Activated` — loaded and visible.

That aligns well with Decision #3's stronger semantic split between loaded, presented, and physically authoritative. Stillring still owns the physical-authority layer, but the engine already provides useful representation states for preparation.

### 3. One File Per Actor authoring
World Partition enables One File Per Actor by default. Epic positions OFPA as reducing main-level checkout contention by storing Actor instances in external packages.

For a content-heavy interconnected game with paired expressions, this is attractive because changing one Hush prop/fixture does not inherently require rewriting one giant level package.

Caveat: Git/GitHub still sees binary Unreal assets poorly, and external Actor filenames can be opaque outside the Editor. OFPA is not magic text-diffable content.

### 4. Future region scaling path
Stillring's world is interconnected and eventually every region gains Hush-state changes. World Partition provides a credible later path to:
- spatial cell streaming;
- HLOD;
- Data Layer organization;
- Level Instances;
- large-region editor loading.

Starting on that authoring model reduces the risk of building Gate 4 around sublevel conventions that later fight regional scale.

### 5. Editor context for overlapping content
Data Layers and Actor Editor Context allow authors to make a layer current while editing actors. For two overlapping realities, explicit current context reduces accidental placement into the wrong expression.

### 6. Runtime API surface
UE5.8 exposes `UDataLayerManager::SetDataLayerInstanceRuntimeState` / related Data Layer runtime-state APIs and state-change signals. That is sufficient for a clean adapter beneath the semantic transition service.

## Candidate A weaknesses / risks

### 1. More engine machinery than Gate 4 strictly needs
World Partition brings concepts such as grids, streaming sources, external actors, HLODs, builder commandlets, editor regions, and runtime cell behavior. If adopted carelessly, a tiny seam prototype becomes a large-world-engine project.

Mitigation: disable spatial streaming for the first fixture and prohibit HLOD/region complexity from entering the seam acceptance path.

### 2. Representation callbacks can tempt authority leakage
Data Layer state-change callbacks make it easy to accidentally write:
> “when Hush Data Layer activates, set gameplay IsHush = true.”

That is explicitly backwards under Decision #1/#2. Semantic commit must request/observe representation, not be derived from it.

### 3. Source-control opacity
OFPA improves concurrent editing granularity, but external Actor packages remain Unreal binary assets. Epic's richer changelist interpretation is Perforce-oriented; Stillring's GitHub/Git-LFS workflow needs its own discipline/evidence for binary changes.

### 4. Runtime Data Layer behavior still requires real validation
Documentation proving APIs exist is not evidence that the exact paired fixture meets Stillring's hitch, memory, collision, save, and authoring targets.

## Candidate B — non-World-Partition persistent map + explicit sublevels/Actor groups

### Proposed fallback layout

One ordinary persistent map plus explicit representations such as:
- persistent/shared level;
- Waking sublevel;
- Hush sublevel;
- semantic pairing registry/service external to the levels;
- controlled level streaming/visibility and explicit collision/physics ownership;
- optional Actor components/groups for presentation where a separate sublevel is unnecessary.

UE5.8 Level Streaming supports asynchronous load/unload and visibility control without World Partition.

## Candidate B strengths

### 1. Conceptually explicit
The runtime mental model is straightforward:
- shared persistent world;
- Waking level;
- Hush level;
- load/show/hide under semantic adapter.

There are fewer World Partition systems to diagnose during an early prototype.

### 2. Direct loading control
Manual level streaming can make it easy to reason about exactly when a sublevel load request begins/completes and can provide a simple benchmark against Data Layer preparation.

### 3. Strong isolation for tiny fixtures
For one room or tiny area, separate sublevels can be easy to inspect and reset.

### 4. Fewer WP-specific commandlets/build concerns
No spatial cell/HLOD/build pipeline is required just to author paired content.

## Candidate B weaknesses / risks

### 1. Manual world subdivision grows with content
Epic explicitly describes traditional large-world level streaming as requiring manual division into sublevels and notes the collaboration/context problems that motivated World Partition.

Stillring is not a giant seamless open world, but it is interconnected and expects Hush changes across six regions plus the hub. Manual sublevel strategy can become organizational debt once every area needs paired/shared sets.

### 2. Binary level contention
Traditional sublevel workflows concentrate many Actor changes into `.umap` packages unless external-actor workflows are also introduced. That can make Git-based collaboration/Claude-assisted binary asset evidence harder.

### 3. Paired authoring can become folder/sublevel archaeology
As content grows, authors must manually ensure the correct shared/Waking/Hush sublevel is current, correctly loaded, and consistently paired.

### 4. Future migration risk
If production later needs World Partition for regional authoring/streaming, a manual sublevel Hush architecture may require conversion/reconciliation while content is already large.

### 5. Level visibility is still not semantic truth
Candidate B does not magically simplify Decisions #1–#6. The same semantic adapter/save/pair identity layer is required, so some apparent simplicity is only representation-level simplicity.

## Level Instances are complementary, not Candidate C

UE5.8 Level Instances are useful for repeated buildings/assemblies and in-context editing. Outside a World Partition main world, Epic notes they do not automatically gain a streaming strategy.

Stillring may use Level Instances within either broader representation approach for reusable authored structures, but they do not replace the Waking/Hush semantic/representation decision.

## One File Per Actor note

Epic UE5.8 documents OFPA as enabled by default with World Partition and also available for non-partitioned levels through external Actors.

Therefore OFPA alone is not sufficient reason to choose Candidate A.

However Candidate A has the more standard integrated path among:
- World Partition;
- Data Layers;
- OFPA;
- Level Instancing;
- future large-region management.

Stillring's Git workflow must still explicitly validate binary-asset review/merge behavior either way.

## Provisional evidence matrix

Scores below are **design/research expectations**, not measured prototype results. `5` means strongest expected fit for Stillring; `1` weakest.

| Criterion | A: WP + Runtime Data Layers | B: Explicit levels/Actor layering | Why |
|---|---:|---:|---|
| Same-space Waking/Hush authoring clarity | **5** | 4 | Data Layers are built for overlapping runtime groupings; Epic sample demonstrates light/dark overlap. |
| Shared invariant content | **5** | 4 | Shared Actors sit naturally outside Waking/Hush Data Layers. Persistent level also works. |
| Semantic-authority independence | 5 | 5 | Both can be clean adapters if Stillring follows Decisions #1–#6. |
| Prepare-before-commit support | **5** | 5 | Data Layers have Loaded/Activated; sublevels have load/visibility controls. |
| Tiny prototype simplicity | 3 | **5** | Manual levels have fewer systems; WP streaming-disabled mitigates complexity. |
| Future interconnected-region scaling | **5** | 3 | WP is Epic's current large-world management path. |
| Paired-content organization at production scale | **5** | 3 | Data Layer + editor context model fits many overlapping expression sets. |
| Source-control edit granularity | **4** | 2–4 | WP+OFPA strong by default; non-WP can also use external Actors but needs explicit workflow. Git binary review remains a risk for both. |
| Runtime debugging/IDE visibility | **5** | 4 | Data Layer runtime state is directly inspectable; both remain workable. |
| Save reliability under semantic IDs | 5 | 5 | Save authority is independent of representation. |
| Representation refactor tolerance | 5 | 5 | Stable semantic IDs prevent asset/layout paths becoming save truth. |
| Initial engine learning/complexity | 3 | **5** | B is simpler mechanically. |
| Evidence available from Epic production samples | **5** | 4 | Valley of the Ancient explicitly demonstrates overlapping alternate worlds via Data Layers. |

### Research verdict
Candidate A has the stronger **production trajectory**, while Candidate B has the stronger **minimum-mechanism prototype simplicity**.

Because World Partition spatial streaming can be disabled, Candidate A can remove much of Candidate B's simplicity advantage while preserving the Data Layer authoring model and production path.

That makes **A-with-streaming-disabled** the best first prototype candidate.

## Provisional Gate 4 implementation recommendation

### Build first
**World Partition map + Runtime Data Layers, spatial streaming disabled.**

Recommended conceptual organization:

```text
Semantic World-Layer Service (authoritative)
        |
        v
Hush Representation Adapter (replaceable)
        |
        +--> Shared expression set
        +--> Waking Runtime Data Layer(s)
        +--> Hush Runtime Data Layer(s)
        +--> presentation/audio adapters
```

Rules:
- semantic service knows semantic IDs and semantic layer, not “Data Layer == truth”;
- representation adapter maps semantic expression IDs to Data Layer assets/Actor refs;
- Data Layer names/asset paths never become save keys;
- Data Layer callbacks report readiness/convergence only;
- physical collision/query authority remains explicit per Decision #3;
- cross-layer facts remain semantic data;
- the IDE displays both semantic and Data Layer state;
- test map starts with cell streaming disabled.

### Do not build yet
Do not add during Gate 4 representation proof unless specifically required by evidence:
- HLOD;
- complex runtime grid tuning;
- multiple streaming sources;
- production-scale region partitioning;
- PCG/world-generation dependencies;
- network replication architecture;
- multiplayer Data Layer policy;
- final regional map topology.

Those would pollute the question being tested.

## Required fallback comparator

Candidate B does not need an equally polished second production implementation before Gate 4 can continue, but the architecture must remain adapter-replaceable and the evidence harness must be capable of constructing a small B comparator if Candidate A fails any hard condition.

Immediately prototype B if Candidate A shows any of these hard failures:
- seam preparation/activation causes unacceptable hitching that cannot be removed without loading both worlds prohibitively;
- collision/physics authority cannot be made deterministic under the semantic commit contract;
- save/reload convergence depends on Data Layer state in a fragile way;
- editor/Data Layer/OFPA workflow produces unacceptable Git/LFS merge/review failure modes;
- inactive expression memory cost becomes unacceptable and manual sublevel residency materially improves it;
- Data Layer callbacks/order prove too opaque to satisfy deterministic test/capture requirements;
- UE5.8 API/runtime behavior materially differs from documentation in a way that breaks the adapter model.

## Real-engine evidence matrix required before final architecture acceptance

The selected prototype must record actual measurements for the same named fixtures.

### Transition correctness
- request→prepare duration;
- prepare→commit duration;
- commit→physical convergence duration;
- commit→presentation completion duration;
- number of semantic commits;
- Data Layer/sublevel state at each boundary;
- repeated input behavior;
- destination-not-ready failure.

### Frame/performance
- worst frame time around transition;
- game/render/RHI thread timing where available;
- GPU frame cost around transition;
- transition hitch count/magnitude;
- post-process/Niagara differential;
- lowest target hardware evidence when available.

### Memory/residency
- source-only memory;
- source + destination preloaded memory;
- destination-only memory;
- paired-expression Actor/component counts;
- streaming-disabled versus enabled data if later tested.

### Physical correctness
- inactive blocking/overlap/physics count = zero;
- camera/tool/projectile query fixtures;
- player occupancy handoff;
- dynamic mechanism/physics handoff;
- enemy/target continuity.

### Save/reload
- Waking save/reload;
- Hush save/reload;
- shared fact convergence;
- layer-local fact convergence;
- renamed/moved representation asset while semantic IDs remain stable;
- save requested mid-transition.

### Authoring workflow
Record actual developer steps/time/errors for:
- create paired entity;
- move/edit Waking-only geometry;
- move/edit Hush-only geometry;
- edit shared geometry;
- inspect both realities in context;
- detect accidental wrong-layer placement;
- rename/move expression asset;
- create/resolve source-control change with overlapping content;
- reset fixture from the in-game IDE.

### Source-control evidence
For Git/Git LFS specifically capture:
- files changed for representative one-Actor Waking edit;
- files changed for paired edit;
- `.umap` churn where applicable;
- external Actor package churn;
- merge-conflict/rebase behavior in a controlled two-branch edit fixture;
- whether humans/Claude can identify the changed semantic content from repository evidence without guessing.

## Architecture acceptance gates

Candidate A becomes the production baseline only after:
1. real UE5.8 build/editor verification passes;
2. named seam correctness fixtures pass;
3. save/reload semantic convergence passes;
4. inactive physical authority validations pass;
5. source-control authoring fixture is tolerable under Stillring's Git workflow;
6. transition performance/memory is acceptable for the target-class machine after human/technical review;
7. the Hush IDE can explain state without Data Layer archaeology;
8. no locked gameplay rule had to bend to accommodate the representation.

If the representation requires changing semantic rules to make the engine happy, the representation loses.

## Decision #9 approval boundary

What is approved now:
- Candidate A is the **first implementation/prototype direction**;
- spatial streaming stays disabled for the tiny Gate 4 fixture initially;
- Runtime Data Layers are representation only;
- Candidate B remains the fallback comparator;
- real evidence above is mandatory before declaring final production architecture proven.

What is **not** claimed now:
- no measured performance result;
- no real UE5.8 compile/editor verification;
- no Git/LFS binary-merge proof;
- no final region partition/grid/HLOD strategy;
- no claim that Candidate B has been empirically beaten.

This preserves honest verification while still giving implementation a concrete direction.

## Hush / World-Layer IDE additions from Decision #9

The IDE compare surface must expose:
- representation strategy ID;
- World Partition enabled yes/no;
- spatial streaming enabled yes/no;
- Data Layer/sublevel runtime states;
- active semantic layer separately;
- pair/expression count;
- load/preparation timings;
- memory/residency measurements;
- transition hitch metrics;
- source-control fixture metadata where captured;
- save/reload convergence;
- all hard acceptance validations.

A capture must identify exact Unreal Engine version/build and source commit.

## Research basis

Primary current technical sources verified:
- Epic Games, **World Partition in Unreal Engine 5.8** — automatic grid streaming, optional `Enable Streaming`, integration with OFPA/Data Layers/Level Instancing/HLOD, conversion tooling.
- Epic Games, **EDataLayerRuntimeState**, UE5.8 — `Unloaded`, `Loaded`, `Activated` semantics.
- Epic Games, **UDataLayerManager::SetDataLayerInstanceRuntimeState**, UE5.8 — runtime Data Layer state control.
- Epic Games, **Valley of the Ancient Sample**, current UE5.8 documentation — overlapping light/dark world representation using Data Layers and shared common reference content.
- Epic Games, **One File Per Actor**, UE5.8 — external Actor packages, source-control granularity and workflow caveats.
- Epic Games, **Level Streaming**, UE5.8 — manual async level load/unload/visibility and recommendation of World Partition for modern large-world streaming.
- Epic Games, **Level Instancing**, UE5.8 — reusable in-context level assemblies; not a standalone streaming strategy outside a WP main world.
- Epic Games, **Actor Editor Context**, UE5.8 — current Level/Data Layer/Level Instance authoring context.
- Gate 4 Decisions #1–#8.

## Locked statement

> **Prototype the Hush with World Partition + Runtime Data Layers first, but keep World Partition's spatial streaming out of the tiny test until it earns its place. Data Layers express the realities; Stillring's semantic state defines them.**

## Next decision

**Gate 4 Decision #10 — deterministic paired-layer fixture matrix, cumulative Gate 4 design closure, and explicit implementation-evidence boundary.**
