# 73 — Gate 4 Hush Cross-Layer Puzzle State Contract

**Status:** LOCKED — scheduled-run owner delegation  
**Issue:** #126 — Gate 4 Hush-layer prototype design system  
**Decision:** #4 — Hush puzzle cross-layer state-change rules compatible with Gate 3

## Decision

A Hush puzzle is one observable mechanism whose semantic facts may have different Waking/Hush expressions. Cross-layer effects occur only when a reviewed semantic fact is declared shared, causal, or derived across the pair. The layer shift itself never solves a puzzle, copies arbitrary Actor state, or activates hidden objective flags.

Core philosophy:

> **Change the fact, then let both realities express the consequence.**

Gate 3 remains authoritative: puzzles are machines, not keyholes; Cantor explains relationships; Anchor changes load; synthesis happens through honest shared world state.

## State classes

Each meaningful puzzle/mechanism property must be authored as one of four classes:

1. **Shared persistent fact** — one semantic fact applies to both expressions, e.g. permanently repaired, broken, opened, released, calibrated.
2. **Layer-local expression state** — meaningful only in one expression, e.g. a Hush-only residue orientation or Waking-only debris position.
3. **Cross-layer causal fact** — an action in one layer changes a named semantic fact whose authored consequence is expressed differently in the other layer.
4. **Derived expression state** — recomputed from shared facts plus current layer; never independently persisted.

No property may silently migrate between these classes based on which Actor happened to receive an event.

## Shared fact ownership

Shared persistent and cross-layer causal facts live once against stable semantic identity from Decision #1.

Examples:
- `mechanism.counterweight_north.released = true`;
- `archive_bridge.support_load = Unloaded`;
- `maintenance_ring.alignment = Stable`;
- `service_latch.state = Broken`.

The exact storage/schema belongs to Issue #4, but the meaning is locked: paired Actors do not keep competing copies of the same fact.

## Cross-layer causality must be authored

A Waking action affects Hush only when the pair definition explicitly declares the causal relation.

Valid pattern:
1. player changes an observable mechanism/load/relation in active layer;
2. authoritative semantic fact changes;
3. inactive-layer expression is marked dirty/derivable;
4. when Hush becomes active, its authored expression resolves from that same fact;
5. player can observe the consequence and understand the relationship.

Invalid pattern:
- script says `if player pulled correct lever in Waking, set HushDoorSolved = true` without a world relation explaining why;
- copying every transform/physics property between paired Actors;
- using the destination Actor's current hidden state as the source of truth;
- quest objective metadata deciding which cross-layer consequence is allowed.

## Layer-local state

Not everything should synchronize.

Hush may legitimately contain:
- residue that has no Waking physical counterpart;
- incomplete/discarded geometry;
- a local mechanism expression whose transient pose differs;
- a relationship that can be diagnosed but not physically manipulated from Waking.

Layer-local state remains local unless an authored semantic fact links it to the paired world.

This preserves the Hush as an echo with distinct expression rather than a mirrored duplicate.

## Gate 3 Anchor compatibility

Anchor operates only on currently active compatible physical load points under `docs/62`–`docs/66`.

Anchor may cause a cross-layer change only by changing a semantic mechanical fact it already legitimately owns.

Example family:
- Waking Anchor releases a shared support brace;
- semantic `SupportReleased` becomes true;
- Hush expression resolves with a collapsed/shifted echo support;
- a route or diagnostic relationship changes there.

Anchor does not directly pull an inactive-layer Actor, target ghost geometry, or receive a special “Hush puzzle” force rule.

## Gate 3 Cantor compatibility

Cantor may diagnose relationships that canonically have Hush significance, but it does not reveal privileged solution metadata.

Valid:
- Cantor identifies that two paired expressions share one unstable relation;
- player later shifts and observes the other expression;
- a known procedure changes a semantic relation that both expressions legitimately derive from.

Invalid:
- Cantor highlights the exact object to manipulate in the other layer because the objective needs it;
- Cantor reads unloaded Actor internals as hidden puzzle truth;
- Hush mode turns Cantor into omnidirectional cross-layer radar.

## No layer-shift-as-key

Changing `ActiveSemanticLayer` alone cannot satisfy a puzzle completion condition unless “being in this layer” is itself the explicit authored condition of a mechanism/route.

A puzzle may require the player to shift to access different geometry or evidence, but the thought process should be:
> “This reality exposes a different part/state of the same problem.”

not:
> “The Hush button is the blue key for this door.”

Repeated toggling without observation/reasoning should not be the intended base solution grammar.

## Causal direction

Cross-layer relationships may be:
- bidirectional shared fact;
- Waking→Hush causal only;
- Hush→Waking causal only;
- two distinct facts with an explicit derived relation.

Direction must be authored and visible in IDE data.

Do not assume every Hush action rewrites Waking or vice versa. That would flatten narrative meaning and make state debugging impossible.

## Persistent vs reversible mechanism changes

A semantic fact declares persistence/reversibility independently from layer.

Examples:
- permanently severed support: persistent shared fact;
- temporarily braced load: shared runtime fact that may revert when brace is reclaimed;
- local rotating platform pose: layer-local transient expression;
- calibrated relation: persistent or session state according to authored mechanism contract.

Layer transition does not reset reversible state unless the mechanism's own law says it should.

## Completion conditions

Puzzle completion is derived from explicit semantic invariants, not a hidden correct-sequence flag.

A cross-layer puzzle completion condition may combine facts such as:
- shared support released;
- Hush-only alignment stable;
- Waking route physically open;
- Cantor-known relation within tolerance;
- Anchor brace reclaimed/committed according to mechanism rules.

The IDE must be able to explain exactly why completion is true/false from current facts.

## Alternate valid solutions

If a different action order reaches the same declared semantic invariants without violating tool/world rules, the puzzle should accept it.

Cross-layer authoring must not reject a valid state merely because the designer expected Waking→Hush→Waking in one exact order.

This remains bounded systemic design: authors define legal states/causal relationships, not unrestricted simulation.

## Failure and reset

Cross-layer failure remains local and recoverable where possible.

Rules:
- wrong manipulation changes observable mechanism state;
- shifting layers does not magically restore a failed mechanism;
- reset restores only the named puzzle fixture facts/expressions;
- reset uses semantic IDs and declared baseline, not Actor respawn order;
- reset must converge both layer expressions to one consistent semantic baseline;
- unrelated quest/world choices remain untouched.

A deadlock without an explicit recovery/reset path is invalid.

## Transition timing boundary

Decision #2 owns the seam commit. Cross-layer facts do not “half apply” during presentation.

At semantic commit:
- destination expression reads already-authoritative shared facts;
- no puzzle fact changes merely because the layer changed;
- destination derived state must converge before player interaction resumes if it affects immediate physical legality;
- presentation lag may continue visually, but gameplay queries use committed semantic/physical authority.

## Save/reload boundary

Decision #6 and Issue #4 will define save format/reload timing, but Decision #4 requires:
- shared persistent facts save once by semantic ID;
- layer-local persistent facts, if any, include explicit layer scope;
- derived expression state is rebuilt, not redundantly saved unless later schema evidence requires it;
- puzzle completion can be recomputed from authoritative facts;
- save files never depend on hidden Actor visibility/transform copies as canonical puzzle truth.

## Accessibility/readability

Cross-layer reasoning must not depend on remembering tiny visual differences.

Required design support:
- important state changes have multimodal world evidence where appropriate;
- reduced VFX mode still makes active-layer mechanism state legible;
- Cantor-known facts may be reviewable without revealing the solution;
- no color-only cross-layer correspondence;
- no rapid alternating seam timing as the only solution unless an accessibility-equivalent timing option exists;
- reset/retry is fast.

## Hush / Tool-Puzzle IDE requirements

### Inspect
Expose:
- puzzle/fixture ID;
- semantic mechanism IDs;
- each fact's state class (`Shared`, `LayerLocal`, `CrossLayerCausal`, `Derived`);
- causal direction/source;
- current authoritative value;
- Waking expression value/derived result;
- Hush expression value/derived result;
- last system/action that changed a fact;
- completion invariants and current truth;
- Cantor/Anchor eligibility separately;
- persistence/reset scope.

### Author/Tune
Allow reviewed editing of:
- relation declarations;
- fact class and causal direction;
- derived-expression mappings;
- mechanism tolerances/timing already permitted by Gate 3;
- reset baselines.

Reject generic “when layer toggles, fire arbitrary Blueprint event chain” as the production authoring model.

### Exercise
Fixtures:
- shared latch state visible differently in both layers;
- Waking action causing Hush route change;
- Hush action causing Waking mechanism change;
- layer-local state that intentionally does not synchronize;
- Anchor shared-load manipulation;
- Cantor diagnose→shift→verify;
- valid alternate order;
- wrong order/recoverable state;
- reset while inactive expression is unloaded;
- repeated layer shifts with no state mutation.

### Validate
Catch:
- same shared fact stored independently on paired Actors;
- cross-layer change with no authored relation;
- layer shift directly setting puzzle solved;
- completion depending only on objective metadata;
- derived state persisted inconsistently with source facts;
- Anchor/Cantor receiving special puzzle-only behavior;
- inactive Actor mutation used as hidden truth;
- reset leaving Waking/Hush expressions divergent;
- critical correspondence communicated only by color/VFX.

### Capture
Record causal timeline:
active layer → player/tool request → semantic fact change → affected relations → seam commit if any → destination expression derivation → invariant/completion result → reset/reload result.

## Comparative design lineage

Useful problem-study references:
- **Dishonored 2 — A Crack in the Slab:** actions in one temporal state can create understandable consequences in another because the location and causal relationship remain coherent.
- **Titanfall 2 — Effect and Cause:** alternate-state traversal is strongest when the player can reason spatially about corresponding versions rather than treating switching as an arbitrary key.
- **Portal / Zelda systemic puzzle lineage:** complexity grows from stable reusable rules and observable state, not one-off solution scripts.

Stillring does not copy time-travel fiction, layouts, controls, UI, visual transitions, or exact puzzle solutions.

## Research basis

Primary current technical sources verified:
- Epic Games, **Gameplay Tags in Unreal Engine 5.8** — explicit semantic labels/queries suitable as implementation primitives.
- Epic Games, **Data Registries in Unreal Engine 5.8** — read-only authored data/IDs; explicitly not a substitute for changing story/progress state.
- Epic Games, **Saving and Loading Your Game**, UE5.8 — persistent state belongs in explicit SaveGame data rather than engine presentation state.
- Gate 3 authority `docs/61`–`docs/69`.
- Gate 4 Decisions #1–#3 (`docs/70`–`docs/72`).
- Issue #126.

## Locked statement

> **Cross-layer puzzles share authored facts and causes, not arbitrary Actor state. The player changes a real relationship; each reality then shows what that means.**

## Next decision

**Gate 4 Decision #5 — combat/NPC/interactable continuity across a layer transition.**
