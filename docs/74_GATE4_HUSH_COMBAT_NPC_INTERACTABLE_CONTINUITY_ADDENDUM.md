# 74 — Gate 4 Hush Combat / NPC / Interactable Continuity Contract

**Status:** LOCKED — scheduled-run owner delegation  
**Issue:** #126 — Gate 4 Hush-layer prototype design system  
**Decision:** #5 — combat/NPC/interactable continuity across a layer transition

## Decision

A Waking↔Hush shift changes the active **expression** of the world; it does not erase semantic combat, NPC, or interactable history. Durable facts stay attached to stable semantic identity, while physical presence and action continuity follow explicit authored compatibility rules.

Core philosophy:

> **Change the expression, not the history.**

The seam must never become a free disengage, health reset, aggro wipe, attack cancel, target roulette, NPC state reset, or duplicate-interaction exploit.

## Continuity classes

Every meaningful combatant/NPC/interactable that can matter across a seam must declare one of four continuity relationships:

1. **SharedInvariantContinuity** — one semantic entity and one compatible runtime/gameplay state persists through both layers; expression differences are presentation-only or physically invariant.
2. **PairedContinuity** — one semantic identity has distinct Waking/Hush expressions, while declared durable facts and compatible gameplay state survive expression handoff.
3. **LayerExclusiveContinuity** — semantic entity exists/has authority only in one layer; durable facts remain semantic, but its physical/action state becomes inactive/dormant while that layer is inactive.
4. **RelatedDistinct** — two entities may be related but do not share combat/NPC/interactable identity or durable state.

These classes extend Decision #1 rather than replacing its paired-identity types.

## Player combat state

The player's authoritative Gate 2 combat state does **not** reset merely because a seam commits.

If Decision #2 accepts the seam request, then across commit:
- current Light/Heavy/Guard/Evade/Reaction state remains authoritative;
- current Startup/Active/Recovery timing is not restarted;
- Evade immunity does not restart or extend;
- Guard/Perfect Guard timing does not refresh;
- Heavy commitment does not disappear;
- one pending combat intent is not duplicated or automatically requeued;
- health/resources are unchanged;
- facing/velocity rules remain under Gate 1/2 authority.

A seam therefore cannot be used as a universal animation cancel, recovery skip, invulnerability refresh, or resource restoration.

If the current player state cannot legally survive the destination's occupancy/traversal contract, Decision #2 rejects before commit rather than silently resetting combat state.

## Hit-resolution ordering at commit

The semantic commit is also an explicit combat-query boundary.

Before commit:
- source-layer authoritative collision/hit volumes resolve under source physical authority.

At/after commit:
- destination-layer authoritative collision/hit volumes resolve under destination physical authority.

The same logical attack/contact must not resolve twice because both expressions were loaded/presented.

No seam-specific grace invulnerability is granted unless a later explicit combat decision earns it; Gate 4 assumes none.

## Target-lock continuity

Target lock follows **semantic target identity**, not Actor instance survival.

At seam commit:

### Paired compatible target
If the current target's semantic entity has a valid destination combat expression and remains target-eligible:
- lock remains on the same semantic target ID;
- physical target reference swaps to the destination expression;
- this is a continuity handoff, not a new acquisition;
- no automatic acquisition camera transition or candidate competition reruns;
- current manual composition/target-relative rules continue under Gate 1 authority.

### No valid destination target expression
If the same semantic target has no valid destination physical expression:
- lock breaks once with an explicit semantic reason such as `TargetUnavailableInDestinationLayer`;
- no other enemy is silently selected;
- camera returns through ordinary approved lock-break behavior;
- the old target does not auto-relock merely because the player later returns to its layer.

### Related-distinct target
A narratively related destination entity is never treated as the same lock target merely because it occupies a similar position or shares visual motifs.

## Committed attacks and target loss

A seam does not rewrite the meaning of an already committed attack.

If target continuity fails during a committed player attack:
- the attack continues under existing combat facing/commitment authority;
- it does not snap to a replacement target;
- it does not gain translation/magnetism toward a destination enemy;
- damage resolves only against currently authoritative physical targets.

If a new Light-chain entry later samples a target, it uses ordinary Gate 2 targeting rules at that new action boundary.

## Enemy durable combat facts

For one semantic combatant with paired expressions, durable combat facts live once against semantic identity.

Representative durable facts:
- alive/dead;
- health/current damage;
- permanently broken armor/component state;
- encounter participation ID;
- authored one-shot phase transitions;
- persistent wounds/status only where combat design explicitly retains them.

They do **not** exist as independent Waking/Hush copies that can be exploited by shifting.

A player cannot damage a Waking expression, shift, and encounter a fresh full-health Hush copy of the same semantic enemy unless canon explicitly defines two distinct entities.

## Enemy transient action continuity

Transient combat action state is preserved only when the destination expression declares compatibility.

### Paired compatible combat expression
For the same semantic combatant with compatible locomotion/combat grammar:
- current action/state family and timers continue through handoff where physically valid;
- cooldowns, reaction protection, aggression state, attack bandwidth claims, and one-shot action facts do not reset;
- animation presentation may rebind to the destination expression, but gameplay timing remains semantic authority.

### Incompatible or layer-exclusive combat expression
If no compatible destination action expression exists:
- source physical action becomes inactive when source layer loses authority;
- the semantic combatant enters an explicit layer-dormant/unavailable continuity state rather than “dying” or resetting;
- durable health/encounter facts remain;
- any later reactivation resumes from an authored safe continuation state, never a fresh spawn baseline by accident.

The exact safe reactivation state is enemy-family data, but it cannot restore health, one-shot attacks, armor, or cleared cooldowns unless explicitly authored.

## Aggro / encounter continuity

A seam transition by itself is **not** disengagement.

Gate 2 encounter authority remains:
- brief LOS/path loss does not reset combat;
- leaving a fight must not create a one-step aggro-radius exploit;
- reset occurs only when encounter disengagement criteria are genuinely satisfied.

Therefore:
- seam commit does not clear aggro;
- seam commit does not release encounter attack-bandwidth state by default;
- seam commit does not restore health or reset enemy positions;
- layer-exclusive enemies becoming physically unavailable are tracked semantically rather than treated as defeated/reset;
- returning immediately to the original layer must not produce a fresh encounter simply because Actors were reactivated.

For short seam absences, semantic alert/encounter state should normally persist. Longer decay/disengage may occur only through the same reviewed encounter-time/credibility rules that would apply without a seam.

## Enemy projectiles / spawned combat objects

Spawned combat objects receive explicit layer scope.

Default:
- a projectile/hazard belongs to the active semantic layer in which it was spawned;
- shifting Neris does not teleport/rebind that projectile into the destination layer;
- while its owning layer is inactive, it cannot hit/block Neris through inactive physical authority;
- its lifetime may continue semantically or expire according to its normal reviewed lifetime policy;
- returning to the source layer does not duplicate it.

A true cross-layer projectile/hazard would require a separate explicit authored capability; none is assumed in Gate 4.

## NPC continuity

Narrative NPC continuity follows stable semantic identity, not Actor lifecycle.

For paired NPCs:
- durable relationship/story/world facts remain single-source semantic facts;
- current alive/present/absent status follows authored layer expression;
- seam transition cannot rewind dialogue, duplicate rewards, restore one-shot interactions, or forget relationship changes;
- current conversational/interaction ownership determines whether the seam is legal under Decision #2.

A committed dialogue/cinematic interaction that cannot preserve continuity may reject seam requests until it releases ownership.

A noncommitted proximity prompt simply reevaluates against the destination expression after commit; it does not auto-fire in the new layer.

## Interactable continuity

For paired interactables, durable facts such as opened/collected/repaired/destroyed live once by semantic ID when declared shared.

Examples:
- a chest/fixture collected once cannot be recollected from a paired expression;
- a repaired shared mechanism remains repaired in both expressions according to Decision #4 derivation;
- a one-shot switch does not regain availability because its source Actor unloaded;
- layer-local interactables remain legitimately independent only when their identity class says so.

Interaction prompts/target refs are ephemeral and must be rebound/revalidated after commit rather than persisted by Actor pointer.

## Interaction during seam

Decision #2's ownership result remains authoritative:
- `TransitionCompatible` — interaction can preserve its semantic action through handoff;
- `TransitionCompletesBeforeCommit` — only if the semantic interaction fact is already atomically complete;
- `TransitionRejects` — seam cannot commit until ownership ends.

Gate 4 does not invent generic forced cancel behavior for dialogue, mechanisms, Anchor, Cantor, pickups, attacks, or traversal.

## Actor lifecycle is not continuity authority

UE Actor loading/unloading, `BeginPlay`/`EndPlay`, streaming resurrection, Blueprint construction, AIController possession, or Behavior Tree restart may occur as representation consequences.

None of them may silently answer:
- whether an enemy is full health;
- whether it remembers aggro;
- whether an NPC reward was claimed;
- whether an interactable was used;
- whether target lock should transfer;
- whether an encounter reset.

Those answers come from semantic gameplay state.

This is especially important because Unreal streaming can end Actor play and later recreate/reuse representation state; representation lifecycle is not a safe gameplay-persistence contract.

## AI runtime state boundary

AIController/Behavior Tree/Blackboard state may represent current decision-making, but semantic continuity must be reconstructable independently of transient AI runtime objects.

If a paired enemy expression changes:
- semantic enemy/encounter facts persist;
- the active AI representation is rebound/reconstructed from those facts;
- stale source-layer Behavior Tree tasks cannot continue issuing physical actions after authority is lost;
- destination AI does not receive a default “fresh spawn” state unless authored.

Exact AI architecture remains implementation choice; semantic continuity is locked.

## Death continuity

Dead semantic entities do not resurrect because the player crosses a seam.

For a paired combatant/NPC whose death is shared:
- death fact is stored once;
- destination expression resolves as dead/absent/remains according to authored presentation;
- no active AI/combat authority returns;
- corpse/ragdoll expression may differ by layer but cannot create a second living identity.

Layer-specific death exceptions require explicit canon/semantic identity separation; they cannot be inferred from separate Actors.

## Save/reload boundary

Decision #6/Issue #4 will own save mechanics, but Decision #5 requires save-relevant semantic continuity for:
- durable health/death where retained by save authority;
- shared interactable facts;
- persistent NPC/relationship facts;
- active encounter state only if Issue #4 later declares it reload-relevant;
- semantic layer and pairing identity.

Transient animation montage positions, Actor pointers, Behavior Tree node stacks, overlap prompt refs, and camera blend progress are not assumed durable save truth.

## Accessibility / readability

Seam-related continuity outcomes must be explainable without requiring the player to infer invisible resets.

Requirements:
- if target lock breaks because target is unavailable in the destination, provide the normal readable lock-break cue;
- paired target continuity should not create a fake new-target flash or camera snap;
- enemy/NPC state differences must have world-readable evidence where gameplay meaning depends on them;
- no critical continuity status relies only on color/VFX;
- reduced transition effects must preserve target/interaction readability immediately after commit.

## Hush / Combat / Encounter IDE requirements

### Inspect
Expose:
- selected semantic entity ID and continuity class;
- Waking/Hush physical expression refs/presence;
- health/alive/dead/shared durable facts;
- current combat/action state and timer ownership;
- target semantic ID vs physical target ref;
- lock transfer/break result and reason;
- aggro/encounter participation state;
- attack-bandwidth claim/token state where applicable;
- layer-dormant status;
- AI representation/controller/BT state separately from semantic state;
- interactable one-shot/shared facts;
- last seam transition ID affecting the entity.

### Exercise
Provide fixtures for:
- paired enemy same health across shift;
- target-lock transfer to same semantic target;
- target unavailable → explicit lock break/no replacement;
- shift during each player combat phase;
- enemy mid-attack paired-compatible handoff;
- layer-exclusive enemy dormant/reactivate;
- projectile/hazard remaining layer-scoped;
- dialogue/committed interaction seam rejection;
- shared pickup/one-shot interactable across layers;
- enemy death then shift/return;
- rapid seam toggles during combat without encounter reset.

### Validate
Catch:
- seam resetting player action/recovery/immunity;
- seam clearing aggro without disengage authority;
- paired enemy health/death duplicated per Actor;
- lock automatically selecting a different semantic enemy;
- destination expression restarting cooldown/one-shot attack without authority;
- inactive-layer AI issuing physical actions;
- inactive projectile damaging active-layer player;
- one-shot interactable collectible twice through pairing;
- dead paired entity resurrecting on expression load;
- Actor/AI lifecycle event being used as semantic reset authority.

### Capture
Record:
seam request → pre-commit player/target/enemy/NPC/interactable semantic state → physical-expression handoff → target continuity result → player/enemy action continuation → aggro/encounter state → projectiles/interactions → post-commit validation.

## Representative test matrix

At minimum:
- idle enemy paired across both layers;
- enemy at 50% health shift/return;
- enemy dead shift/return;
- target locked paired enemy;
- locked target layer-exclusive;
- Light Startup/Active/Recovery seam;
- Heavy Startup/Active/Recovery seam;
- Guard/Perfect Guard/Evade phases seam;
- incoming hit exactly around commit boundary;
- enemy attack exactly around commit boundary;
- ranged projectile in source layer while player shifts;
- multiple enemies / attack-bandwidth state;
- brief shift-away and immediate return (anti-reset exploit);
- dialogue prompt vs committed dialogue;
- pickup used in Waking then visited in Hush;
- mechanism interaction compatible/rejecting;
- low-frame-rate/streaming Actor recreation stress.

## Comparative design lineage

Problem-study only:
- **Titanfall 2 — Effect and Cause:** allowing rapid state shifts during combat demonstrates why combat state and spatial expression must remain coherent; the useful lesson is preserving player agency without making state change a free reset.
- **Dishonored 2 — A Crack in the Slab:** NPC/world consequences across related states demonstrate the need for identity and causal continuity rather than duplicate Actors as truth.
- **Legacy of Kain: Soul Reaver:** entities can have different presence rules across coupled realms while world identity remains understandable.

Stillring copies none of their fiction, controls, encounter layouts, transition presentation, or exact mechanics.

## Research basis

Primary current technical sources verified:
- Epic Games, **Actor Lifecycle**, Unreal Engine 5.8 — spawning, BeginPlay/EndPlay, streaming/unload lifecycle; representation lifecycle is distinct from semantic persistence.
- Epic Games, **Gameplay Framework**, UE5.8 — Controller/Pawn/GameInstance responsibility boundaries.
- Epic Games, **AI Controllers** and **Behavior Trees**, UE5.8 — transient AI decision/runtime structures.
- Epic Games, **Gameplay Ability System Component/Attributes** docs, used only for the general architecture lesson that durable gameplay state can be separated from Pawn/Actor presentation; Stillring does not thereby adopt GAS.
- Gate 2 combat/encounter authority `docs/37`–`docs/59`.
- Gate 4 Decisions #1–#4 `docs/70`–`docs/73`.
- Issue #126.

## Locked statement

> **A seam changes expression, not history: health, death, aggro, interaction facts, and committed player state do not reset; target continuity follows semantic identity, never replacement roulette.**

## Next decision

**Gate 4 Decision #6 — save/load/reload contract for active layer and persistent paired facts, coordinated with Issue #4.**
