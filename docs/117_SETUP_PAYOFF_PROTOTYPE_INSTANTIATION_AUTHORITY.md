# 117 — Setup/Payoff Decision #6 — Prototype Instantiation Authority

**Status:** FINAL OWNER APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #9 — Design cross-state setup and payoff framework  
**Parents:** `docs/112_SETUP_PAYOFF_STATE_AUTHORITY_ADDENDUM.md`, `docs/113_SETUP_PAYOFF_COMMIT_BOUNDARY_AUTHORITY_ADDENDUM.md`, `docs/114_SETUP_PAYOFF_PAYOFF_MATERIALITY_AUTHORITY_ADDENDUM.md`, `docs/115_SETUP_PAYOFF_PORTFOLIO_AUTHORITY_ADDENDUM.md`, `docs/116_SETUP_PAYOFF_AUTHORING_DATA_AUTHORITY_ADDENDUM.md`  
**Decision:** #6 — instantiate the canonical authoring/data contract through S01, S06, and S11

## Locked prototype set

The three canonical Issue #9 prototypes are:

1. `setup.brindle.crooked_fire_bell` — physical/elective; flagship vertical-slice chain;
2. `setup.saltreach.manual_fog_code` — operational/story-mandatory; proves the framework is not synonymous with binary choice;
3. `setup.mireglass.personal_provenance` — epistemic/elective; proves a valid payoff need not be physical.

The same authored definition/state-history architecture must support all three without per-chain hidden Blueprint authority.

---

# S01 — Crooked Fire Bell

## Identity

- Chain ID: `setup.brindle.crooked_fire_bell`
- Story status: optional for main-story completion; required for canonical 100% completion
- Region: Brindle
- Portfolio question: **When is an imperfection actually part of how something works?**
- Flagship vertical-slice status: YES

## Source ownership

The chain observes but does not copy authoritative facts.

- C01 phase and resolution: Local Repair Contract authority
- chosen bell repair configuration: Local Repair Contract authority
- fire-bell service state: Infrastructure / World State authority
- Grand Ring / Stillness state: Story authority
- post-Stillness bell behavior: World State authority
- Mara Pell availability/role: NPC authority
- later consequence settlement: owning Quest/World consequence authority

Mara Pell is a presentation/social amplifier, not a hard owner of the physical payoff. Her temporary absence cannot erase the bell's historical truth or strand completion.

## Priming

The chain becomes `Primed` only after C01 has semantically reached the state where:

- the warped bracket has been diagnosed;
- both valid final repair approaches are understood/available as authored;
- the player can perform the final repair.

Hearing the bell, inspecting it, talking to Mara, entering the area, or testing a reversible intermediate configuration does not commit the chain.

## Commit boundary

Boundary ID:

`setup.brindle.crooked_fire_bell.commit.returned_to_service`

Boundary class: **Operational Commit**

Semantic source event, conceptually:

`event.brindle.fire_bell.returned_to_service`

The boundary fires only after the chosen final configuration survives the authored service-verification ring and the source infrastructure system considers the bell returned to service.

## Normal committed variants

- `standardized`
- `locally_tuned`

The variant resolver reads the authoritative C01/Infrastructure result. `ChoiceA`, `ChoiceB`, array indexes, display strings, Blueprint branches, and Actor names are forbidden semantic identities.

## Non-intervention / supersession

If the player never completes C01 before Grand Ring, there is no fabricated pre-Grand-Ring commit receipt.

Grand Ring/Stillness may make the original early setup opportunity historically impossible. In that supported history the chain becomes **Superseded**, using the source-owned fact that the fire bell entered Stillness unrepaired.

The chain must expose an authored equivalent post-Stillness resolution so 100% remains reachable without retroactively pretending that an early repair occurred.

This is the canonical example of why `Superseded` exists and why non-intervention is not always represented as a fake committed choice.

## Post-Stillness payoff manifestations

### Standardized history

The standardized configuration provides reliable warning during brief motion windows but fully phase-locks rather than sustaining the same irregular moving pocket.

The player uses predictable warning windows to traverse/reach/reconnect the affected fire-bell area.

### Locally tuned history

The asymmetric local repair produces a smaller irregular moving pocket. The player can use that pocket as part of the authored rescue/reconnection route.

### Superseded / unrepaired history

No useful repaired-bell behavior survives from C01. The player follows an authored exterior/manual route, makes the unsafe bell state legible/safe, and establishes the temporary local warning needed to settle the aftermath.

None of the three histories is a hidden moral winner. Optional early choice may alter survivor grouping, route, burden, presentation, or later testimony, but cannot implement `good choice saves child / bad choice kills child` completion clairvoyance.

## Resolution

All supported histories settle through a semantic consequence-resolution event owned by the appropriate consequence/quest/world system, conceptually:

`event.brindle.fire_bell.poststillness_consequence_resolved`

The Setup/Payoff resolution receipt preserves which historical route produced the settlement.

Each valid history contributes exactly one S01 completion item when its exact authored resolution predicate is satisfied.

## Late-arrival recovery

If world pulse advances the immediate rescue presentation before the player personally arrives, the game must preserve a reachable equivalent resolution through physical aftermath, bell behavior/evidence, survivor/community testimony where available, and authoritative world facts.

The player may arrive late. The world may not forget.

## Required S01 deterministic fixtures

At minimum:

1. reversible inspection/testing does not commit;
2. standardized service verification commits `standardized`;
3. local service verification commits `locally_tuned`;
4. Grand Ring before C01 completion creates supported Superseded history rather than a fake commit;
5. Mara temporary absence does not alter physical payoff truth;
6. standardized and locally tuned histories produce distinct later manifestations;
7. Superseded history retains equivalent completion-valid resolution;
8. all routes produce exactly one completion settlement;
9. save/load at prime, commit, Grand Ring, payoff available, and resolution boundaries converges;
10. map/Actor rename does not alter semantic identity;
11. duplicate commit/resolution events are idempotent;
12. late arrival can establish/resolve the historical consequence.

---

# S06 — Manual Fog Code

## Identity

- Chain ID: `setup.saltreach.manual_fog_code`
- Story status: story-mandatory and completion-bearing
- Region: Saltreach
- Portfolio question: **When geography changes, whose calibration is actually correct?**

This chain must preserve Saltreach's canonical argument: C10 is not tradition-versus-science. The tower can be mechanically healthy and precisely timed while its official geographic model is stale.

## Source ownership

- C10 diagnosis/resolution: Local Repair Contract authority
- tower mechanical health: Infrastructure authority
- local shoreline/water observations: Saltreach World/Navigation authority
- manual fog-code service state: Infrastructure authority
- Grand Ring / Stillness: Story authority
- central navigation frozen state: World State authority
- post-Stillness shelter route: World/Quest authority
- Vessa Mor role/availability: NPC authority

## Priming

The chain primes only after C10 has established the semantic diagnosis:

- the tower is mechanically healthy enough to perform its intended signal function;
- official direction/calibration is wrong because the coast/reference geometry has moved;
- the actual local coast has been established through physical triangulation/observation.

## Commit boundary

Boundary ID:

`setup.saltreach.manual_fog_code.commit.local_code_verified`

Boundary class: **Operational Commit**

Semantic source event, conceptually:

`event.saltreach.fog_code.returned_to_service`

Painting/repainting marks alone is insufficient. The local code becomes committed only after the authoritative navigation/infrastructure state verifies that it corresponds to the actual current coast.

## Variant structure

The one normal committed variant is:

`local_code_verified`

This chain is intentionally not a binary moral/mechanical fork. It teaches world persistence through a mandatory authored action.

## Non-intervention rule

Canonical story progression does not support a state where C10 is considered critically complete while the required local-code service step remains semantically unfinished.

Therefore:

`NonInterventionPolicy = UnsupportedByCanonicalProgression`

The validator must prove that the story cannot legally progress past the relevant gate with C10 complete but S06's required service commit absent.

Do not invent a fake optional/non-intervention branch merely to make all definitions look structurally identical.

## Post-Stillness payoff

When central navigation freezes/repeats under Stillness, the physically grounded local code remains legible.

The player can naturally discover the payoff through familiar marks and local navigation behavior, then use/assist the authored shelter route produced by those marks.

The chain's significance is operational: earlier diagnosis and service work becomes usable navigation after the shared reference fails.

Vessa's later role as a manual harbor-information hub is a supporting echo, not the sole authority for the payoff.

## Resolution

Resolution is a semantic route/consequence event owned by World/Quest authority, conceptually:

`event.saltreach.manual_fog_code.first_shelter_route_completed`

A display-name shelter, level path, Actor path, coordinate, or Blueprint node is presentation data only and cannot be the resolution identity.

## Persistent aftermath

S06 may feed later Saltreach practices such as the broader Many-Tide Harbor Accord, but later regional evolution does not overwrite the fact that this setup/payoff occurred.

## Required S06 deterministic fixtures

At minimum:

1. C10 diagnosis alone does not commit before service verification;
2. physical marks without verified current-coast relation do not commit;
3. verified local code commits one normal variant;
4. legal canonical story progression cannot bypass the mandatory commit;
5. Grand Ring preserves committed local-code history;
6. central navigation failure plus committed code produces payoff availability;
7. Vessa absence does not erase the physical navigation truth;
8. exact shelter/route presentation may move/rename without changing semantic resolution;
9. save/load at diagnosis, service commit, Grand Ring, payoff, and resolution converges;
10. duplicate events are idempotent;
11. completion is awarded on payoff resolution, not merely on the mandatory setup commit.

---

# S11 — Personal Provenance

## Identity

- Chain ID: `setup.mireglass.personal_provenance`
- Story status: optional for main-story completion; required for canonical 100%
- Region association: Mireglass; setup commit occurs through Cairnspire civic registration
- Portfolio question: **Can personal provenance preserve meaning that anonymous classification destroys?**

## Canonical timing reconciliation

Older authored material loosely associates the Mireglass traveler with the First Circuit. The final canonical sequence is:

1. **Road to Cairnspire:** the player first encounters/sees the Mireglass traveler and cracked diplomatic hand-mirror as a seed;
2. **Cairnspire registration period:** the actual provenance-classification interaction occurs and the setup can commit.

Therefore the road/First Circuit wording is seed/context shorthand, not the semantic commit location.

## Source ownership

- cracked mirror existence/item continuity: World / Item Provenance authority
- civic intake state: Record / Civic Registry authority
- provenance classification/annotation: Record / Civic Registry authority
- Palace memory-branch state: Story/Quest authority
- Palinode availability: Progression authority
- Mirror Nail availability: Progression authority
- shared mundane event established: Story/Knowledge authority

## Priming

The chain primes when:

- the cracked mirror is presented for civic intake;
- its classification remains legitimately open;
- the player has the authored opportunity to preserve named personal provenance or allow anonymous-salvage classification.

## Commit boundary

Boundary ID:

`setup.mireglass.personal_provenance.commit.registry_finalized`

Boundary class: **Social Commit**

Semantic source event, conceptually:

`event.cairnspire.civic_registry.mireglass_mirror_record_finalized`

## Committed variants

- `personal_provenance`
- `anonymous_salvage`

The system does not create separate variants for `player intentionally chose anonymous` versus `player ignored the optional request` unless later authoritative content truly distinguishes those histories.

If ordinary civic intake closes without the named provenance being preserved, that supported history may settle as `anonymous_salvage` when the source Registry authority finalizes the record.

## Later Palace payoff — personal provenance history

The named record provides an external interpretive anchor when the relevant Palace Under Reeds memory branch becomes active.

The preserved provenance identifies the person/context tied to the cracked mirror and makes the relevant mundane shared event interpretable earlier/more directly.

It does not automatically solve the entire Palace puzzle.

## Later Palace payoff — anonymous salvage history

Completion remains reachable.

Without named provenance, the player reconstructs the necessary provenance inside the Palace using existing Mireglass/progression verbs and facts, conceptually:

- Palinode exposes incompatible historical traces;
- physical crack/repair continuity identifies the same object/history across those traces;
- Mirror interaction lets the player test/compare competing local memory states;
- the shared mundane event is established without relying on the early named record.

This is a different epistemic route, not a punishment branch and not a mandatory-story lockout caused by optional early content.

## Resolution

Story/Knowledge authority settles the relevant fact, conceptually:

`shared_mundane_event_identified`

The resolution method is also preserved semantically, for example:

- `named_provenance`
- `reconstructed_provenance`

Setup/Payoff observes the authoritative settlement and writes its one resolution receipt. Either supported history can satisfy the one S11 completion item through its exact authored resolution path.

## Reconvergence

After the Palace branch resolves, the present may reconverge where production/story authority requires.

Historical truth remains distinct:

- whether the mirror retained a named record;
- whether Neris arrived already understanding its relevance;
- whether provenance had to be reconstructed;
- which later testimony/record echoes are valid.

Reconvergence may unify the present. It may not falsify the past.

## Required S11 deterministic fixtures

At minimum:

1. road encounter seeds but does not commit;
2. registry-open state primes the chain;
3. final named classification commits `personal_provenance`;
4. finalized anonymous classification commits `anonymous_salvage`;
5. level/map/registry presentation rename does not alter semantic identity;
6. personal-provenance history provides the intended Palace interpretive advantage;
7. anonymous history retains a fully authored reconstruction path;
8. optional early history never becomes mandatory main-story logic alone;
9. both supported histories resolve to one completion item;
10. history remains distinct after later reconvergence;
11. save/load across intake, finalization, Palace eligibility, and resolution converges;
12. duplicate registry/resolution events are idempotent.

---

# Decision #6 findings locked into system authority

The prototype exercise proves and therefore locks the following clarifications:

## A. NPC availability is conditional authority, not a generic hard prerequisite

NPC presence may be a hard payoff prerequisite only when the consequence itself is genuinely social and the chain's authored recovery/supersession contract makes that safe.

For physical/operational truths such as S01's bell state or S06's physical fog code, NPC absence cannot erase authoritative world truth.

## B. Zero-choice chains are valid

A canonical Setup/Payoff chain may have one normal committed variant when the meaningful design is delayed persistence rather than choice branching.

## C. Epistemic payoffs are first-class

A change in what can be established, interpreted, proven, or understood may satisfy Decision #3 materiality when it is authoritative, causal, legible, and historically persistent.

No traversal shortcut, merchant, loot reward, or physical destruction is required to validate such a chain.

## D. Superseded is not synonymous with non-intervention variant

When an early setup never semantically committed and later world progression makes the original setup impossible, the correct state may be `Superseded` plus an equivalent authored resolution, rather than fabricating a historical commit that never occurred.

## E. Optional setup may alter context/difficulty without locking completion

An optional earlier history may create a faster, clearer, safer, stranger, harder, or differently framed payoff route, provided every supported history remains authored, completion-valid, and non-clairvoyant.

## F. Presentation identity remains non-authoritative

None of the three prototype chains requires Actor paths, map paths, scene node paths, Blueprint node names, trigger-volume names, coordinates, localized strings, or quest titles for persistence or resolution truth.

## G. One data shape supports materially different experiences

S01, S06, and S11 use the same authored-definition and minimal-history architecture while producing physical, operational, and epistemic payoff experiences respectively.

This is required evidence that the framework is genuinely reusable rather than C01-specific abstraction.

---

# Runtime evidence boundary

This decision is design/documentation authority only.

It does **not** claim:

- UE5.8 Primary Data Asset implementation;
- semantic event bus/runtime implementation;
- SaveGame receipt implementation;
- source-system adapters;
- System IDE implementation;
- deterministic fixture execution;
- vertical-slice playable proof;
- human tester recognition/acceptance.

Those remain implementation/runtime evidence work and must not be inferred from documentation completion.

## Owner approval

Approved by the owner on 2026-09-05.
