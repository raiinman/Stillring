# 65 — Gate 3 Anchor Line Combat / Pressure Use Contract

**Status:** LOCKED — scheduled-run owner delegation  
**Issue:** #115  
**Decision:** #6 — combat / pressure use contract

## Decision

Anchor Line combat use is **deliberate load pressure on explicit combat-compatible components and objects**, not direct ranged damage, universal enemy dragging, generic stun, or automatic weak-point exploitation.

> **Anchor changes the fight by changing what is under load. It does not become another weapon.**

## Core combat role

The Anchor Line may create tactical pressure by:
- latching an explicit detachable/releasable enemy component;
- applying maintained tension toward that component's authored release condition;
- pulling an approved loose/movable encounter object into a new position;
- holding one approved encounter mechanism/load in a temporary state;
- using already-approved traversal anchors for repositioning under Decision #5.

The tool itself does not deal ordinary health damage merely because tension is applied.

A component release may alter an enemy's capabilities, protection, attack set, movement, or encounter geometry because that component's own authored state changed. That consequence belongs to the enemy/component contract, not a hidden Anchor damage table.

## Enemy compatibility

An enemy body is not Anchor-compatible by default.

Combat Anchor targets must be explicit load points such as:
- attached maintenance harness/foreign brace;
- detachable armor or shield hardware where canon/design explicitly supports removal;
- exposed equipment or carried component with a real load relationship;
- temporary combat mechanism connected to the encounter space.

A visually prominent body part is not automatically a weak point.

Compatibility must remain readable in-world and inspectable in the Tool/Combat IDE.

## Pressure and commitment

Maintaining combat tension is a **committed pressure action**.

While actively reeling against a resisting combat component:
- Neris retains player camera control;
- movement may remain available within a reduced/bounded handling envelope where the source action permits it;
- the action does not grant Guard or Evade immunity;
- incoming hits resolve through Gate 2 normally;
- forced Interrupt/HardStagger/Death terminates the handheld Anchor relationship unless a later authored brace state owns it;
- Reclaim remains available whenever the current state allows immediate cleanup.

Exact combat-state entry/cancel windows use Gate 2 transition authority and prototype tuning. Anchor does not add a parallel cancel system.

## Release condition

Detachable combat components own explicit release semantics.

A release may require some combination of:
- a valid pull direction/cone;
- sustained semantic load for an authored duration/window;
- target being in an exposed/unlatched state;
- another combat/world precondition already made observable;
- resistance state not exceeding the current Anchor capability.

Release is deterministic and explainable. It is not decided by random physics spikes.

The player is never expected to read a hidden numeric force meter. Feedback communicates practical bands such as:
- no purchase;
- loaded;
- resisting;
- near release;
- released;
- state-blocked.

## No universal crowd control

Base Anchor Line does not:
- yank ordinary enemies bodily toward Neris;
- pin any enemy to any wall;
- suspend enemies indefinitely;
- interrupt every attack on latch;
- auto-stagger on successful tension;
- create a generic trip mechanic;
- steal weapons from all humanoids;
- turn bosses into physics puppets.

If a specific enemy/component later reacts to a released load with `LightReact`, `Interrupt`, or `HardStagger`, that result must be explicitly authored under Gate 2 reaction-force authority and justified by the actual component/state change.

Latch alone produces no free stun.

## Mossjaw / Mawhart canon compatibility

Root Cathedral canon already requires:
- Mossjaw to teach target choice/component removal through accidental maintenance harness armor;
- Mawhart to resolve through removal of harmful foreign load relationships rather than killing the creature.

This contract supports those beats without making their exact encounter scripts universal policy.

Mossjaw can expose a detachable harness/load point whose removal changes protection/behavior. Mawhart can expose foreign braces/load points whose release changes the infrastructure relationship. The Anchor verb remains the same in both: **establish load, apply tension, release an authored relationship**.

## Combat target lock interaction

Combat target lock and Anchor candidate/focus remain separate.

Rules:
- locking an enemy may increase readability of its visible compatible Anchor points but cannot automatically select one;
- Anchor view-intent targeting remains authoritative for which load point is requested;
- latching a component does not change the combat target identity;
- target switching does not silently move an existing Anchor line to a new enemy;
- if the combat target leaves but the Anchor endpoint remains valid/visible, the line follows its endpoint contract, not lock identity;
- camera Relationship Frame remains governed by camera authority.

## Encounter bandwidth

Anchor use must fit Gate 2 encounter readability.

Because maintained tension occupies player attention, encounters must not demand prolonged Anchor manipulation while unrelated offscreen high-salience attacks saturate the player.

Production may:
- create brief pressure windows after an enemy attack/recovery;
- expose components through readable enemy actions;
- coordinate other enemies so the manipulation is risky but legible;
- let the player abandon the Anchor immediately rather than trapping them in a long minigame.

Production may not solve an unreadable encounter by giving Anchor hidden slow-motion, auto-defense, or global enemy pause.

## Environmental combat pressure

The same base verb can affect encounter objects when they are ordinary Anchor-compatible world loads:
- pull approved cover or obstruction along a track;
- release a hanging counterweight;
- hold/open a mechanism while under pressure;
- move a loose service object where its physics/constraint contract permits.

These are world interactions usable during combat, not combat-only magic versions of the tool.

## Damage boundary

Anchor Line has no base direct-damage stat.

Damage may occur only when a separately-authored world/combat event legitimately causes it, for example:
- a released heavy object collides under ordinary hazard rules;
- an enemy loses protective hardware and is then struck by normal combat;
- a component removal itself has an explicitly authored damage consequence.

The Tool system must not secretly multiply damage because the player used Anchor.

## Accessibility / readability

Required:
- combat-compatible load points readable without color alone;
- state-blocked versus mechanically incompatible distinguishable;
- maintained-tension progress conveyed with more than tiny UI bars where practical;
- Reclaim/cancel remains simple and remappable;
- no rapid repeated mashing requirement for release;
- no motion-control gesture requirement;
- haptic resistance is supplemental;
- Reduced/Off combat assistance must not alter component legality.

## Comparative research boundary

Horizon demonstrates that componentized enemies can produce tactical fights where equipment/armor materially changes what an enemy can do. Stillring uses only the generic problem-solving lesson: **changing an enemy's equipment state can be more interesting than adding raw damage**. It does not copy Horizon's tear-damage system, elemental taxonomy, component rewards, Focus highlighting, weapon behavior, UI, or enemy designs.

Epic UE5.8 Gameplay Tags and the Gameplay Targeting System can represent/filter explicit semantic target capabilities and provide useful debug data. These are implementation options only; Stillring's combat-component legality remains authoritative gameplay data.

## Tool / Combat System IDE

### Inspect
Expose:
- current combat target;
- Anchor endpoint/component ID separately;
- component response/release family;
- current target combat state/action phase;
- Anchor request legality/rejection reason;
- pull direction validity;
- semantic load/resistance band;
- exposure/release preconditions;
- current reaction-force result if release causes one;
- line termination reason;
- encounter attack-bandwidth context while manipulation is active.

### Exercise
Fixtures:
- exposed detachable harness;
- state-blocked component;
- wrong pull direction;
- resisting component that becomes exposed;
- successful release with no reaction;
- successful release with explicitly authored reaction;
- incoming hit during maintained tension;
- hard stagger/death cleanup;
- target switch while latched;
- environmental movable load during combat;
- boss-scale invalid body target with one valid brace/component.

### Validate
Catch:
- latch causing generic stun;
- Anchor dealing base health damage;
- whole enemy pulled without explicit authority;
- component selected from hidden weakness/quest metadata;
- combat target overwritten by Anchor point;
- release bypassing authored exposure/direction condition;
- reaction class invented by the Tool system;
- stale Anchor line after interrupt/death/reset;
- encounter requiring uninterruptible long manipulation under unreadable pressure.

## Locked statement

> **In combat, Anchor Line manipulates explicit load-bearing components and world loads. It creates openings by changing equipment or structure, never by becoming a universal damage/stun beam.**

## Research basis
- `docs/48_GATE2_COMBAT_STATE_MODEL.md` — authoritative player combat transition/reaction/resource boundary.
- `docs/story/02_ACT_ONE_WAYBELLS.md` — canonical Mossjaw/Mawhart Anchor use.
- `docs/62`–`docs/64` — locked Anchor physical/input/traversal authority.
- Epic Games — Unreal Engine 5.8 Gameplay Tags and Gameplay Targeting System documentation.
- PlayStation / Guerrilla — Horizon machine/component design used only as a generic tactical-component comparison.

## Next decision

**Gate 3 Decision #7 — Anchor Line puzzle / mechanism use contract.**
