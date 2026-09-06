# 140 — Cross-System Contract Matrix

**Status:** CANONICAL INTEGRATION / DIRECTIONAL-CONTRACT AUTHORITY  
**Updated:** 2026-09-05  
**Program:** Documentation Closure Phase 2  
**Baseline main:** `4c65b2429dbb601e9c5ba0124cc0d27dc4a31a35`

## Purpose

Stillring's biggest implementation risk is not that individual systems lack design.

It is that individually-correct systems may make contradictory assumptions at their boundaries.

This matrix answers:

> **When System A meets System B, who requests, who decides, what survives the transition, what may be derived, and what is explicitly forbidden?**

Read with:
- `docs/139_SYSTEM_OWNERSHIP_MAP.md`;
- the relevant cumulative system authorities;
- `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`.

Core rule:

> **Cross-system integration is directional. An interaction does not grant either side permission to steal the other's authority.**

---

# 1. Contract notation

`A -> B`

A requests/produces information for B.

B remains owner of B's state.

`A <- B`

A consumes B-owned state.

`A <-> B`

Both exchange information/events through explicit boundaries, but each retains its own owner domain.

`NO COPY`

The consumer may not persist a second canonical copy of the producer's fact.

`DERIVED`

The consumer's state is recomputable from more fundamental authority.

`COMMIT BOUNDARY`

Cross-system transaction must settle semantically before save/completion/downstream consequence is allowed to treat it as durable history.

---

# 2. High-risk contract summary

| Boundary | Direction | Locked contract | Forbidden integration shortcut |
|---|---|---|---|
| Input -> Locomotion | Input request -> Locomotion decides movement | Input expresses intent; locomotion owns legal movement state | Animation/UI directly setting movement state |
| Locomotion <-> Camera | Locomotion exposes state; Camera owns framing | Camera adapts without re-owning movement | Camera collision moving player as hidden locomotion rule except explicit safety contract |
| Targeting -> Combat | Targeting selects semantic target/frame; Combat acts | Combat uses target frame but owns attacks/defense | Combat AI forcing lock selection to make attack work |
| Combat -> Locomotion | Combat requests restrictions/impulses through locomotion contract | Locomotion owns movement realization | Montage root motion silently overriding gameplay state outside approved contract |
| Encounter -> Enemy AI | Encounter schedules pressure/composition; AI owns individual actions | Attack bandwidth/readability constraints govern | Encounter script directly teleporting/spawning unreadable attacks behind player |
| Tool -> Mechanism/World | Tool performs validated interaction; target owner commits durable consequence | Tool operation and world fact remain separate owners | Tool Blueprint writing quest/world booleans directly |
| Quest -> World State | Story may request world pivot/consequence | World State commits durable world fact | Duplicate quest bool and world bool as independent truth |
| World State -> Quest | Quest may observe world prerequisite | NO COPY | Quest storing private bridge/repaired duplicate because it is convenient |
| World-Layer -> Presentation | Semantic layer decides; Data Layers/Actors realize | Streaming state is subordinate | Data Layer load state treated as Hush/story truth |
| World-Layer <-> Locomotion | Hush transition must preserve/transform legal movement under Gate 4 | No free reset/cancel | Seam grants momentum reset/invulnerability or restarts jump |
| World-Layer <-> Combat | Same combat state continues where destination expression is legal | Attack/guard/evade timings do not restart | Seam as defensive cancel or attack refresh |
| World-Layer <-> Targeting | Lock may follow same semantic target to paired expression | Targeting evaluates destination eligibility | Actor pointer identity alone treated as semantic continuity |
| Save <-> Domain owners | Save snapshots/restores settled semantic records | Save orchestrates, domains own meaning | Save god object owning quest/world/inventory truth |
| Completion <- Source systems | Completion records completion consequence after source transaction settles | Totals DERIVED | Completion writes source gameplay result backwards |
| Setup/Payoff <- Source systems | Evaluates facts, writes chain-only history | Source owns facts | Copied source booleans/lifecycle becoming authority |
| Setup/Payoff -> World/NPC/etc. | Committed history may be consumed by source owners to produce consequence | Consequence remains source-owned | Setup/Payoff directly becoming world/NPC state owner |
| Hush -> Route Network | Hush owns active layer; Route derives legal paired continuation | No route = no aboard shift | Route graph silently changing semantic layer |
| World -> Route Network | World owns route/infrastructure history; route derives current legality | NO COPY | Spline visibility equals route availability |
| Player input -> Skiff | Player owns handling intent inside legal corridor | Route owns macro legality | Route automation drives complete ride |
| Skiff -> Camera | Skiff exposes speed/state; Camera owns framing | Manual camera remains available | Vehicle physics service owns camera |
| Null Meridian -> Existing systems | Sequence layer composes established owner facts | Thin progression/settlement only | Giant finale controller duplicates all mechanism/Hush/combat truth |
| System IDE -> Any system | IDE requests through real owner APIs | Shadow state forbidden | Debug bool makes test pass while gameplay service disagrees |

---

# 3. Input / Locomotion contract

## Input owns
- device/action mapping;
- processed control request as defined by input architecture;
- remap/accessibility preference through profile/settings.

## Locomotion owns
- movement-state eligibility;
- state transition;
- requested/actual movement response;
- movement transaction success/failure;
- traversal continuity.

## Contract

```text
Input action/request
    -> Locomotion validates against current gameplay state
    -> Locomotion transitions or rejects
    -> presentation/animation follows authoritative result
```

### Must survive
- remapping;
- hold/toggle accessibility behavior where approved;
- controller/keyboard parity within design intent.

### Forbidden
- Animation Blueprint decides Sprint is active because a montage is playing;
- UI widget directly sets mantle/hang state;
- input action callback writes persistent world state.

---

# 4. Locomotion / Camera contract

Camera consumes:
- player transform/orientation;
- locomotion state/mode;
- speed/velocity where useful;
- target-relative frame when locked;
- environment collision information.

Camera owns:
- framing;
- pivot/orbit behavior;
- collision response;
- recenter behavior;
- camera mode transitions.

Locomotion must not bake camera convenience into world movement semantics.

Camera must not silently reinterpret a failed traversal as successful by moving the pawn through geometry.

High-speed Skiff camera remains a camera problem consuming Skiff state, not a Skiff-physics owner.

---

# 5. Targeting / Locomotion / Combat contract

Targeting provides:
- selected semantic target;
- target-relative frame/basis;
- candidate eligibility/rejection reason.

Locomotion uses target-relative frame for approved locked movement.

Combat uses selected target/frame for attacks/defense/spacing logic.

Combat does not own target selection merely because an attack wants a target.

Targeting does not own enemy health/action state.

### Hush case

If the target's semantic entity has a valid destination expression:
- semantic target ID remains;
- physical target reference may switch to destination representation;
- Combat action timing does not restart;
- Locomotion continuity follows Gate 4.

If destination target is not valid:
- targeting resolves loss according to targeting authority;
- seam may not invent a target.

---

# 6. Combat / Locomotion contract

Combat may request:
- movement restrictions during attack/guard/recovery;
- authored impulses/knockback;
- turn/facing relationships;
- death transition.

Locomotion executes physical movement under approved combat contracts.

### Forbidden
- separate hidden `CombatMovementState` that conflicts with locomotion;
- animation-root-motion behavior that bypasses collision/locomotion authority without explicit contract;
- seam resetting combat movement commitment;
- retry reconstructing a half-swing frame.

---

# 7. Encounter / Combat / Camera contract

Encounter owns pressure/composition.

Individual AI/combat entities own their action state.

Camera/targeting authority constrains what pressure is readable/fair.

### Required directional checks

Before fresh attack pressure can commit, encounter logic must respect:
- attack bandwidth;
- meaningful source visibility/supplemental warning;
- occlusion/offscreen threat rules;
- camera framing burden;
- incompatible simultaneous defensive demands;
- authored space/collision.

### Forbidden
- `difficulty` bypasses readability contract;
- encounter teleports an attacker behind the player because pathing failed;
- camera is forced into a special angle solely to justify overcommitted encounter composition unless explicitly authored/reviewed.

---

# 8. Combat / Hush contract

Hush transition is not combat reset.

Locked continuity includes, where the paired expression remains valid:
- attack Startup/Active/Recovery timing;
- guard/perfect-guard timing;
- evade immunity timing;
- health;
- launched projectiles where supported by their world-expression contract;
- target semantic identity;
- ordinary movement momentum.

### Forbidden
- seam grants invulnerability;
- seam cancels attack commitment;
- seam refreshes evade;
- seam erases damage/projectiles automatically;
- combat blocks all seam use globally rather than applying explicit legality.

---

# 9. Tool / Puzzle / World contract

A tool interaction has at least two possible authorities:

1. Tool service owns the player's tool action and compatibility.
2. Mechanism/World owner owns durable target consequence.

Example:

```text
Glasslung validates compatible intake/discharge
    -> physical interaction occurs
    -> pressure mechanism owner settles new durable state if authored persistent
    -> Quest observes result
    -> Completion observes relevant settled source result
```

### Forbidden
- tool service owns every machine state it touches;
- level Blueprint writes quest and world facts directly from animation notify;
- puzzle mechanism duplicates tool acquisition state;
- Completion callback substitutes for source mechanism resolution.

---

# 10. Tool / Combat contract

Tools may alter combat only through explicitly authored Gate 3/combat contracts.

Combat remains core authority for:
- damage/action state;
- target/defense execution;
- hit reaction/interrupt semantics.

Tool services may own:
- compatible component/world-load interaction;
- pressure/heat/Anchor effects on approved combat targets;
- diagnostic information allowed by authority.

Cantor is not a generic combat scanner and may not reveal:
- numeric hidden enemy AI state;
- future attack selection;
- hidden weakness table;
- arbitrary `real enemy` labels outside approved relationship diagnosis.

Null Meridian S5 specifically diagnoses the room/formation relationship, then ordinary combat remains ordinary combat.

---

# 11. Quest / World-State contract

Quest/Story owns authored narrative progression.

World State owns durable physical/civic/environment facts.

### Story-caused world pivot

```text
Story reaches semantic event
    -> requests World State transaction
    -> World State commits pivot fact
    -> Quest advances if its own transition is satisfied
    -> downstream systems observe one world pivot
    -> snapshot after transaction settles
```

### World-state prerequisite

```text
World State owns fact
    -> Quest evaluates it
    -> Quest advances its own stage
```

NO COPY.

### Grand Ring

Grand Ring/Stillness is a durable World State pivot caused by story authority.

It is not:
- an implicit commit for every Setup/Payoff chain;
- Data Layer state;
- a cutscene-finished bool duplicated in Quest and World.

---

# 12. Quest / Dialogue / NPC contract

Dialogue evaluates:
- Quest/Story state;
- NPC durable recurrence/relationship facts;
- World facts;
- source records/progression where authored.

Dialogue does not own those facts.

If a conversation itself causes a durable consequence:
- the declared owner commits it;
- Dialogue presentation confirms/reacts;
- one-shot replay protection is stored by the appropriate Quest/NPC/World owner.

NPC current presence is not automatically proof of durable NPC history.

---

# 13. World-State / Hush contract

World State owns durable semantic facts.

Hush/World-Layer owns which semantic expression is active and legal layer transition.

Shared persistent fact:

```text
World semantic fact exists once
    -> Waking representation reads it
    -> Hush representation reads it
```

Layer-local durable fact:
- explicitly scoped by authority;
- still uses stable semantic identity;
- does not become duplicated merely because two Actor representations exist.

### Forbidden
- World State reads current Data Layer and infers history;
- Hush transition writes Quest stage because player crossed;
- each representation saves its own copy of a shared repaired/open fact.

---

# 14. Hush / Unreal streaming contract

Semantic flow:

```text
Hush/World-Layer authority
    -> requests/coordinates destination representation
    -> Unreal Data Layers/streaming load/activate required representation
    -> collision/visual/audio transition follows Gate 4 contract
    -> semantic transition commits only at legal boundary
```

Streaming cannot make the semantic decision by itself.

A representation unloading does not delete semantic state.

Save state remains queryable independent of Actor load state.

---

# 15. Save / all gameplay domains contract

Save Coordinator performs:
- stable snapshot request;
- serialization;
- file/slot/schema/integrity work;
- restoration dispatch;
- migration/recovery coordination.

Every gameplay domain provides/accepts its own semantic records.

### Snapshot rule

Do not snapshot a multi-owner operation halfway through its semantic transaction.

Examples:
- pickup: Inventory -> World consumed -> Completion -> settle -> snapshot;
- boss: Encounter -> World consequence -> Quest -> reward/Completion -> settle -> snapshot;
- Setup/Payoff commit: source semantic event + commit receipt converge -> settle -> snapshot.

### Restore rule

Source owners restore before derived consumers reconcile.

Recommended dependency principle:

```text
schema/header
 -> durable source owners (Progression/Inventory/Quest/World/Hush/Encounter/etc.)
 -> chain/derived consumers (SetupPayoff/Route derivation/Completion)
 -> presentation/UI/streaming realization
```

Exact runtime sequencing implementation remains Issue #4/future code work.

---

# 16. Save / Hush contract

Save only at valid semantic layer boundaries.

Do not persist:
- half-transition;
- blend percentage;
- streaming progress;
- collision handoff timeline.

Persist/reconcile:
- semantic active layer where save-stable;
- shared/layer-local durable semantic facts;
- safe checkpoint/placement context.

On restore:
- semantic truth drives representation;
- representation does not decide truth.

Issue #4 runtime acceptance requires proving this in a paired-layer save/exit/reload case.

---

# 17. Completion / source systems contract

Completion Ledger records completion-bearing consequences after source transaction settles.

It does not become source gameplay authority.

Examples:

| Category | Primary source truth | Completion action |
|---|---|---|
| Main Story | Quest/Story final canonical route resolution | satisfy story category only after valid ending state |
| Repair Contract | Quest/Story contract resolution | satisfy `contract.*` entry |
| Setup/Payoff | chain ResolutionReceipt | satisfy `setup.*` entry |
| Refuges | World/Quest refuge restored fact | satisfy refuge entry |
| Faults | Fault-resolution source service | satisfy fault entry |
| Tool upgrades | Inventory/Tool Progression ownership/acquisition | satisfy upgrade entry |
| Skill Trials | Trial authoritative qualifying clear | satisfy trial entry |
| Elite encounters | Encounter State resolution | satisfy elite entry |
| Community projects | Quest/World project resolution | satisfy project entry |

Percentages and category totals derive from semantic entries.

Accessibility/assist does not invalidate completion.

---

# 18. Setup/Payoff / source-system contract

Input direction:

```text
Quest / World / NPC / Hush / Progression / Tool / Traversal / Encounter / Record / Repair Contract
        -> Setup/Payoff predicate evaluation
```

Commit:

```text
source-owned semantic boundary/event
        -> Setup/Payoff writes one idempotent CommitReceipt
```

Payoff:

```text
commit history + current source facts
        -> source systems expose/own consequence
        -> Setup/Payoff observes exact Resolution predicate
        -> writes ResolutionReceipt
        -> Completion observes receipt
```

### Forbidden
- Setup/Payoff writes a world route/NPC service state directly as its own fact;
- copied `PayoffAvailable=true` saved as higher authority than current source facts;
- level overlap is the commit identity;
- arbitrary Blueprint callback is a source fact without named deterministic provider.

---

# 19. Setup/Payoff / Save contract

Persist only minimal irreversible chain history:
- CommitReceipt where committed;
- ResolutionReceipt where resolved;
- schema/reconciliation metadata required by authority.

Derive:
- Dormant;
- Primed;
- Payoff Available;
- Unavailable.

Restore source systems first.

Then reconcile chain state.

Contradictions fail/audit conservatively rather than last-boolean-wins.

---

# 20. World/Hush / Line Skiff Route Network contract

Locked split:

```text
Story/World State
    owns durable infrastructure/history facts

Hush/World-Layer
    owns active semantic layer

Route Network
    owns authored semantic route definitions
    derives current legal traversal/paired continuation
```

Aboard Hush shift:
- legal only when route segment declares paired destination continuation and World-Layer allows transition;
- no declaration = no shift;
- Route Network does not fabricate a road because destination Data Layer happens to be loaded.

Route availability changes are derived from source facts and route definitions.

---

# 21. Line Skiff control / Route Network contract

Route Network owns legal macro travel.

Player/Skiff control owns moment-to-moment handling:
- acceleration;
- coasting;
- braking;
- bounded lateral placement;
- junction intent;
- momentum management.

Roadhand Pulse:
- wakes/identifies compatible infrastructure;
- does not grant arbitrary route permission;
- is not a boost.

Switchshoe:
- changes legal supported junction transfer behavior;
- does not increase general top speed;
- does not permit cross-country exit.

---

# 22. Line Skiff / Save contract

Persist durable semantic facts, not frame-perfect vehicle physics.

Save/recovery should use:
- route semantic identity;
- stable resume/parking/recovery point;
- source-owned route/world facts;
- current save-stable semantic layer.

Do not persist as canonical truth:
- raw spline component pointer;
- exact wheel/contact frame;
- current lateral interpolation phase;
- arbitrary vehicle Actor instance ID.

On load, Route Network re-derives legal route expression from source facts.

---

# 23. Line Skiff / Camera contract

Skiff exposes:
- current traversal state;
- speed/acceleration/momentum context;
- route/corridor geometry needed for framing;
- junction state.

Camera owns:
- view response;
- framing;
- collision;
- manual ownership;
- target behavior where relevant.

High speed does not authorize fully automated rail camera if it breaks the camera authority.

Human-play validation is required.

---

# 24. Null Meridian / existing-system contract

Null Meridian sequence progression composes existing authorities.

It does not replace them.

### S1
- Anchor owns tool relationship;
- Vane owns traversal relation;
- mechanism/world owner owns suspended-walkway durable state if persistent;
- sequence observes settlement.

### S2
- Glasslung/Temper own tool operations;
- machine owners own operating states;
- sequence observes valid heterogeneous end state.

### S3
- Palinode diagnoses history;
- Mirror commits approved local state;
- Hush/World owns expression/history source facts;
- sequence settles when route/reveal conditions are met.

### S4
- Mirror + Hush + Locomotion + Combat keep their own state;
- sequence objective is traversal progression.

### S5
- Cantor diagnoses room/formation relationship;
- Encounter/Combat own actual current fight;
- preserved historical presentation cannot deal secret authoritative damage unless an explicit physical source owner says so.

### S6
- local mechanism owners establish valid local states;
- Common Measure coordinates one temporary operation;
- relay mechanism/world owner commits disconnected fact;
- sequence settlement observes all required source facts.

---

# 25. Null Meridian / Save contract

Each sequence gets semantic settlement/checkpoint boundaries.

Failure/retry:
- resets only its owned reversible local setup plus source systems through their approved reset APIs;
- never rewinds already-settled previous sequences without explicit authored reason;
- no finite critical resource is permanently consumed;
- no half-seam/half-combat/half-relay frame is canonical save truth.

Save/reload:
- restores source facts;
- reconciles sequence settlements;
- restores safe checkpoint/representation;
- one-time presentation does not duplicate as new history.

---

# 26. System IDE / gameplay-service contract

IDE direction is always:

```text
Developer action
    -> workbench validates/provides provenance
    -> authoritative gameplay service API
    -> canonical runtime state changes
    -> workbench re-reads resulting state
```

Never:

```text
Developer action
    -> debug bool changes
    -> UI says success
    -> gameplay service still disagrees
```

Temporary session override must be visibly distinct from canonical repository-backed value.

Promoted change must be reviewable.

---

# 27. Automation / System IDE contract

Automation should call the same semantic test/control services used by System IDEs where practical.

Benefits:
- one fixture language;
- fewer editor-only hidden paths;
- easier reproduction from human/agent reports;
- deterministic state transition testing;
- less screenshot/pixel automation.

Automation may be headless/minimal-UI, but may not bypass gameplay ownership merely for speed.

---

# 28. Accessibility cross-system contract

Accessibility may alter:
- input ergonomics;
- presentation redundancy;
- timing windows where the semantic skill does not depend on exact speed;
- camera shake/visual effects;
- assist/discovery presentation;
- hold/toggle behavior;
- sensory channel reliance.

Accessibility may not silently mutate:
- canonical world facts;
- completion legitimacy;
- source ownership;
- story outcome validity.

All major cross-system interactions must avoid single-channel mandatory communication when authority already requires redundant cues.

---

# 29. Error/recovery directionality

When a cross-system transaction fails:

1. identify the owner whose invariant failed;
2. leave other owner state uncommitted or roll back through its declared transaction boundary;
3. report human-readable reason;
4. do not create a compensating hidden bool elsewhere;
5. save only after convergence to a valid semantic state.

Examples:
- invalid Setup/Payoff commit -> no receipt;
- invalid Hush destination -> no semantic transition;
- unsafe S6 relay disconnect -> relay remains connected;
- invalid Skiff paired route -> no aboard shift;
- boss reward failure -> boss outcome/reward transaction must reconcile under defined idempotent recovery, not duplicate reward.

---

# 30. Integration validation requirements

Future System IDE/automation must include cross-system assertions for at least:
- Locomotion + Camera + lock-on transition;
- Combat + Hush seam continuity;
- Tool + persistent mechanism + Quest + Completion transaction;
- World State + Hush shared fact across unloaded representations;
- Save restore order + Setup/Payoff reconciliation + Completion reconciliation;
- Story/World pivot + route derivation;
- Skiff + Hush paired continuation + Camera;
- unique Encounter resolution + World/Quest/Completion transaction;
- Null Meridian S4 traversal/combat across Hush;
- Null Meridian S6 local services + Common Measure + relay + save/reload;
- System IDE action produces same state as equivalent normal gameplay action.

These are evidence obligations, not claims of current implementation.

---

# 31. Runtime proof boundary

This matrix is documentation/integration authority.

It does not prove:
- services/classes exist;
- event order is race-free;
- transactions are atomic in code;
- restore ordering is implemented correctly;
- engine lifetime/streaming constraints satisfy the contract;
- high-speed camera works;
- Hush/combat continuity is bug-free;
- Null Meridian is playable;
- IDE APIs exist.

Those proof gaps are tracked in `docs/142_RUNTIME_EVIDENCE_LEDGER_BASELINE.md`.
