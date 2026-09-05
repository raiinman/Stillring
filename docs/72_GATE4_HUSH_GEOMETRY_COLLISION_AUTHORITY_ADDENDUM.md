# 72 — Gate 4 Hush Paired Geometry / Presence / Collision Authority Contract

**Status:** LOCKED — scheduled-run owner delegation  
**Issue:** #126 — Gate 4 Hush-layer prototype design system  
**Decision:** #3 — paired geometry/Actor presence and collision-authority rules

## Decision

Waking and Hush expressions may both be loaded for transition readiness, debugging, or representation efficiency, but **only reviewed semantic ownership decides what is physically authoritative**. Visual presence, Actor existence, streaming state, and collision authority are separate concepts.

Core philosophy:

> **Both realities may exist in memory. Only the active authored reality gets to push back.**

No player, enemy, projectile, tool trace, camera probe, or mechanism may collide with “the wrong layer” merely because its Actors happen to be loaded.

## Three independent state axes

Every meaningful paired expression is reasoned about across three independent axes:

1. **Loaded / available** — whether the representation exists in memory and can be prepared quickly.
2. **Presented** — whether the expression is intentionally visible/audible for the current transition/presentation state.
3. **Physically authoritative** — whether it participates in collision, gameplay traces, navigation/occupancy, physics simulation, interactable targeting, and other reviewed gameplay queries.

These axes must never be collapsed into one `Visible == GameplayActive` assumption.

## Default ownership rule

For an ordinary paired-expression entity:
- current semantic layer expression owns gameplay collision/queries;
- inactive-layer expression owns **no** player-blocking collision;
- inactive-layer expression owns **no** ordinary interactable/tool target collision;
- inactive-layer expression owns **no** camera collision;
- inactive-layer expression owns **no** projectile/hit collision;
- inactive-layer expression owns **no** physics simulation capable of affecting active-layer gameplay;
- inactive-layer expression may remain loaded and may be briefly presented during transition effects.

Layer-exclusive entities follow the same rule: they are physically authoritative only when their owning semantic layer is active unless a specific cross-layer mechanic explicitly declares otherwise.

## Shared invariant entities

Entities declared `SharedInvariant` in Decision #1 may remain physically authoritative across both layers if and only if their collision/behavior is intentionally identical.

Examples may include:
- a permanent load-bearing floor intentionally unchanged across the seam;
- a world-boundary collider shared by both authored expressions;
- a semantic fixture whose physical state is genuinely invariant.

Shared invariant status must be explicit. It cannot be inferred because two meshes happen to overlap.

## Paired expression entities

For `PairedExpression` entities, one semantic identity may have distinct Waking and Hush physical expressions.

The pairing record must declare a collision/presence class such as:
- `ExclusivePhysicalOwner` — exactly one layer expression owns collision at a time;
- `SharedPhysicalInvariant` — reviewed identical physical truth across both;
- `CrossLayerQueryOnly` — inactive expression may answer a narrowly defined semantic query but cannot block/simulate;
- `PresentationOnlyInactive` — inactive expression may render during transition but has no gameplay authority.

Exact enum/class names are implementation details; explicit authored intent is locked.

## Collision handoff at seam commit

Decision #2 owns the semantic commit point. Decision #3 locks how physical authority changes around it.

Before commit:
- source layer retains collision authority;
- destination layer may load/present but must not block or affect gameplay as active geometry.

At commit:
- destination collision/query ownership becomes authoritative in one deterministic handoff;
- source collision/query ownership relinquishes authority in the same transaction/order boundary;
- player occupancy is validated against the destination authoritative collision set;
- camera immediately resolves against destination collision via Gate 1 rules;
- no frame may intentionally expose the player to both mutually exclusive blocking worlds at once.

After commit:
- source expression may linger visually for blend/presentation but remains non-authoritative physically;
- any remaining source physics simulation capable of affecting gameplay is invalid unless explicitly cross-layer-authored.

## No dual-blocking transitional frame

A transition must not solve visual continuity by temporarily enabling both worlds' blocking collision.

That causes:
- invisible wedges where paired walls overlap differently;
- character capsule pinning;
- duplicate overlap/hit events;
- camera compression against disappearing geometry;
- projectile impacts on the wrong expression;
- physics bodies receiving contradictory contacts;
- nondeterministic safe-placement failures.

The semantic commit boundary is also the ordinary physical-authority handoff boundary.

## Destination occupancy contract

Before commit, the transition service performs an occupancy validation against the destination authoritative collision shape relevant to Neris.

The preferred outcome order is:
1. same world transform is valid → commit exactly there;
2. a **small authored seam-resolution offset** within a reviewed local safe volume is valid → apply the smallest deterministic correction and commit;
3. no valid local solution → reject before commit.

The system does **not** search arbitrarily large nearby space, teleport to a designer convenience marker across the room, move Neris to a puzzle solution, or silently climb/drop through geometry.

Any seam requiring a larger positional discontinuity is not an ordinary seam shift; it needs a separate authored transition contract.

## Safe seam-resolution volumes

Where paired geometry differs enough that same-transform occupancy is routinely unsafe, content may author a narrow `SeamSafeVolume`/equivalent relationship.

Such a volume must declare:
- semantic area/pair ID;
- source and destination layer applicability;
- allowed correction bounds;
- deterministic correction policy;
- whether grounded, airborne, traversal, combat states are allowed;
- validation fixtures.

It cannot encode a hidden objective path or broad auto-navigation solution.

## Geometry differences and affordance honesty

A path may exist in one layer and be blocked in the other. That is a core Hush use case, but physical differences must be readable enough that the player understands why movement changed.

Rules:
- no invisible blocking wall whose visual expression belongs only to the inactive layer;
- no visible floor in the active layer that lacks collision unless deliberately non-solid and clearly communicated;
- no decorative inactive-layer ghost geometry blocking tools/camera/player;
- no hidden “puzzle collision” that contradicts visible active geometry;
- collision simplification may be approximate, but it must preserve traversal affordance honesty from Gate 1.

## Camera collision

Camera collision follows **active physical expression authority**, not visual blend dominance.

During transition presentation:
- before commit, source authoritative geometry blocks/compresses camera;
- after commit, destination authoritative geometry blocks/compresses camera;
- inactive-layer ghost/presentation meshes must not compress the camera;
- camera-only blockers may exist where already permitted by Gate 1, but they must themselves have explicit layer ownership.

This avoids the camera being pushed by a wall that the player can walk through.

## Tool traces / targeting

Cantor and Anchor targeting must query semantically appropriate channels rather than generic visibility collision.

Default:
- ordinary physical/tool traces ignore inactive-layer physical expressions;
- a later cross-layer diagnostic affordance may use a dedicated reviewed query channel/service to inspect inactive semantic relationships without granting generic collision;
- Anchor cannot latch to inactive-layer presentation geometry merely because it is rendered during a transition;
- Cantor cannot treat raw Actor presence as semantic evidence.

Decision #4 owns puzzle-specific cross-layer state relationships.

## Combat and projectiles

Decision #5 will define combat continuity, but physical authority is already constrained:
- attack traces/hit volumes collide only with currently authoritative target expressions unless a specific attack is intentionally cross-layer;
- projectiles do not strike inactive-layer geometry;
- inactive enemies do not physically shove/block the player merely because preloaded;
- ragdolls/physics debris from the inactive expression cannot interfere with active gameplay;
- seam transition itself creates no duplicate hit window through overlapping representations.

## Physics simulation

Physics objects require special care because simulation state can continue even when rendering is hidden.

For paired physics-capable entities:
- only the authoritative expression may run gameplay-affecting simulation by default;
- source simulation must be quiesced or made non-authoritative before/at handoff;
- destination persistent physical fact is reconstructed from semantic state, not blindly copied from transient transforms;
- transient velocity/impulse mirroring is not automatic;
- if a puzzle intentionally preserves a physical mechanism state across layers, Decision #4 must define the semantic state being shared.

## Overlap / trigger ownership

Inactive expressions must not generate ordinary overlap/hit events.

Otherwise a player could:
- trigger both layer-specific doors;
- activate hidden quest volumes;
- satisfy two puzzle sensors;
- receive duplicate damage/status events;
- fire level scripting from a reality that is not active.

Any cross-layer trigger is an explicit semantic system, not an accidental overlap from a loaded Actor.

## Navigation / AI occupancy

Gate 4 design does not select final navmesh representation, but semantic rules are locked:
- AI pathing/occupancy must correspond to the active physical expression for that actor/system;
- inactive-layer obstacles must not contaminate active-layer path decisions merely because loaded;
- AI must never infer semantic layer from navmesh presence alone;
- transition continuity must explicitly revalidate any path/position assumptions after commit.

Decision #5 defines NPC/enemy continuity behavior.

## Persistent destruction / changed geometry

If a semantic entity has a persistent destroyed/repaired/open state shared across layers, that fact lives on semantic identity per Decision #1.

Each expression derives its active geometry/collision from that fact according to authored rules.

Do not:
- persist separate Waking and Hush destruction booleans for one shared fact;
- infer persistent destruction because a source Actor was destroyed/unloaded;
- respawn collision from default asset state after layer shift if semantic fact says otherwise.

## Representation independence

### Runtime Data Layers
Epic UE5.8 distinguishes `Loaded` from `Activated`; this maps naturally to the separation between memory readiness and presentation/gameplay activation, but Stillring still needs its own semantic physical-authority contract.

### Explicit level/Actor layering
A streamed/hidden level or Actor group can also separate loaded state from visible/active physical components, but `SetActorHiddenInGame` or sublevel visibility alone is not sufficient collision authority.

Decision #9 will compare implementation candidates. Neither candidate may bypass this contract.

## Accessibility / readability

Physical layer differences must be communicated multimodally where player understanding depends on them.

At minimum:
- collision/traversability changes cannot rely only on subtle color grading;
- critical layer-specific routes require shape/material/motion/audio/environmental differentiation as appropriate;
- reduced VFX settings must not erase knowledge of which geometry is physically active;
- transition effects must not obscure the immediate post-commit footing long enough to make movement unsafe;
- no photosensitivity-heavy strobe is required to understand collision handoff.

Decision #7 owns final presentation policy.

## Hush / World-Layer IDE requirements created by Decision #3

### Inspect
Expose for selected paired entities:
- semantic entity ID;
- pairing class;
- source/destination expression refs;
- loaded state;
- presented state;
- physical-authority state;
- collision enabled mode;
- collision object/profile/channels;
- physics-simulation authority;
- overlap generation;
- current semantic layer;
- safe seam volume/correction metadata;
- last ownership handoff transition ID.

### Exercise
Provide development-only controls to:
- visualize active vs inactive collision;
- force both expressions loaded while preserving only one authority;
- pause immediately before/after handoff;
- inject an invalid destination blocker;
- test same-transform and safe-offset occupancy;
- spawn representative projectile/tool/camera/physics queries across a seam.

### Validate
Catch:
- inactive-layer blocking collision;
- inactive-layer overlap generation;
- both exclusive expressions owning collision simultaneously;
- neither expression owning collision where semantic pair requires one;
- camera blocker belonging to inactive layer;
- tool/projectile trace striking inactive expression;
- gameplay-affecting physics simulation in inactive expression;
- destination occupancy invalid at semantic commit;
- seam correction outside authored bound;
- visible active walkable surface with contradictory collision;
- persistent physical fact duplicated independently across paired Actors.

### Capture
A physical-layer capture records semantic layer → paired entity IDs → loaded/presented/physical states → collision profiles → physics/overlap authority → occupancy result → correction → transition handoff frame → validation findings.

## Representative test matrix

Test at minimum:
- identical paired room;
- doorway open in Waking / wall in Hush;
- floor present only in one layer;
- low ceiling differences;
- stairs/ledge differences;
- same-space paired dynamic mechanism;
- source and destination both loaded;
- source visually lingering after commit;
- player standing flush against destination wall;
- player airborne toward destination-only blocker;
- camera between mismatched walls;
- Anchor trace through inactive geometry;
- projectile through inactive geometry;
- enemy/ragdoll preloaded in inactive layer;
- persistent destroyed/open mechanism across shift;
- low frame rate at collision handoff.

## Comparative design lineage

Problem-study references:
- **Titanfall 2 — Effect and Cause:** aligned alternate spaces demonstrate the value of spatial correspondence and fluid switching, while also showing why paired geometry requires careful authored tuning.
- **Legacy of Kain: Soul Reaver:** material/spectral geometry can share place identity while obeying distinct physical laws; the useful lesson is rule clarity, not its specific morphing expression.
- **Dishonored 2 — A Crack in the Slab:** state differences remain legible because each timeline behaves as a coherent physical version of one location.

Stillring does not copy their layout pairings, visuals, controls, fiction, or transition solutions.

## Research basis

Primary current technical sources verified for this decision:
- Epic Games, **Collision in Unreal Engine — Overview**, UE5.8.
- Epic Games, **Collision Response Reference**, UE5.8 — `No Collision`, `Query Only`, `Physics Only`, `Collision Enabled` semantics.
- Epic Games, **Setting Up Collisions With Static Meshes**, UE5.8 — affordance/collision mismatch risks.
- Epic Games, **Physics Bodies Reference** and **Physics in Unreal Engine**, UE5.8.
- Epic Games, **World Partition — Data Layers**, UE5.8 — loaded vs activated runtime states.
- Epic Games, **World Partition**, UE5.8 — spatial loading implications.

Repository authority:
- Gate 1 locomotion/camera authority;
- Gate 2 combat/encounter authority;
- Gate 3 tool/puzzle authority;
- `docs/70_GATE4_HUSH_SEMANTIC_STATE_IDENTITY_ADDENDUM.md`;
- `docs/71_GATE4_HUSH_SEAM_TRANSITION_ADDENDUM.md`;
- `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`;
- Issue #126.

## Locked statement

> **Loaded is not active, visible is not physical, and only the active semantic expression may own ordinary collision.**

## Next decision

**Gate 4 Decision #4 — Hush puzzle cross-layer state-change rules compatible with Gate 3.**
