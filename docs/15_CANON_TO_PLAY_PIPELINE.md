# 15 — Canon-to-Play Pipeline

**Status:** production operating contract  
**Authority:** complements `CLAUDE.md`, `docs/02_STORY_BIBLE.md`, `docs/03_PRODUCTION_WORKFLOW.md`, `docs/04_TECHNICAL_DIRECTION.md`, and `ROADMAP.md`.

Project Stillring is not developed by asking an implementation agent to invent a game from a prompt. The repository describes the finished game first, then production reverse-engineers that authority into playable slices.

The permanent pipeline is:

**CANON → PRODUCTION → IMPLEMENTATION → VERIFICATION → PLAY**

Chats, prompts, agents, and implementation sessions are disposable. The repository is not.

---

## 1. CANON — describe what exists

Canonical documents describe the finished authored game as if it already exists.

Canon owns questions such as:

- what happens;
- where it happens;
- why a character acts;
- what the player can know at that moment;
- what the player can do;
- what world state is required;
- what changes afterward;
- what optional content exists;
- what 100% means;
- what must remain available after a state transition;
- what the player may reasonably misunderstand before a later reveal clarifies it.

Canon is not a brainstorm and not a wish list. A canonical statement is a production obligation until deliberately changed in every affected authority file.

### Finished-game model

When a region, quest, scene, item, NPC, boss, secret, or world-state transition reaches production, its canonical coverage should be sufficient to answer the questions a careful player guide or internal wiki would need to answer without inventing missing rules.

That does **not** require writing every ambient line or every implementation detail before coding. It does require resolving behavior that would otherwise force the implementation agent to make a creative decision that belongs to game direction.

### Canon completeness test

Before production consumes a canonical unit, ask:

1. Can we state its player-facing purpose?
2. Do we know when it exists and when it changes?
3. Do we know its prerequisites and consequences?
4. Do we know which other canonical units depend on it?
5. Do we know what completion or failure means, if applicable?
6. Can an implementer build it without inventing story, progression, or reward policy?

If not, return the uncertainty to canon instead of letting code silently decide it.

---

## 2. PRODUCTION — convert canon into complete playable slices

Production translates canonical truth into buildable units.

Prefer **player-complete vertical slices** over discipline-only piles whenever practical.

Bad production unit:

> Implement NPC dialogue system.

Better production unit:

> Make the Brindle pre-crisis village excerpt fully playable with its required NPC states, interactions, dialogue, save behavior, audio hooks, and acceptance route.

The second may depend on reusable systems, but its success can be judged in the game.

### Production contract

Every production slice should identify:

- **canonical sources** — exact files/IDs that define truth;
- **player-facing outcome** — what the player can experience when complete;
- **included states** — story/world states covered;
- **dependencies** — systems/content that must already exist;
- **non-goals** — tempting adjacent work that is explicitly excluded;
- **acceptance route** — how a human proves the slice works;
- **automated checks** — what can be validated without subjective judgment;
- **regression surface** — earlier content most likely to break;
- **evidence required** — tests, screenshots, video, save fixtures, performance evidence, or playtest notes.

A production contract may create several implementation issues. It remains the parent definition of what “done” means.

### Dependency links are real design information

If one canonical unit relies on another, record the relationship instead of assuming future context will remember it.

Examples:

- scene → reveal;
- quest → NPC world state;
- reward → traversal gate;
- catastrophe state → settlement recurrence;
- optional contract → later credits specificity;
- region pod → tool capability;
- boss → combat mechanic mastery.

The goal is not bureaucracy. The goal is to make hidden coupling visible before it becomes a bug.

---

## 3. IMPLEMENTATION — agents build, they do not silently direct

Implementation agents receive bounded work derived from production contracts.

Every implementation task must provide or resolve:

- canonical authority;
- current architecture;
- required behavior;
- constraints;
- acceptance criteria;
- relevant tests;
- prohibited scope expansion.

### Agent authority boundary

An implementation agent may choose local engineering details that satisfy the contract.

It may **not** silently decide:

- new story facts;
- new quest rewards;
- new progression dependencies;
- new character motivations;
- new completion requirements;
- permanent balance philosophy;
- new world-state transitions;
- lore explanations for implementation shortcuts;
- major presentation changes that redefine art direction.

If implementation exposes a missing design decision, record it and return it to the appropriate authority layer.

### Smallest complete change

“Smallest” means the least change that proves the requested player-facing behavior, not the least code that compiles.

Scaffolding without the contracted behavior is not completion.

---

## 4. VERIFICATION — prove behavior before interpretation

Verification separates objective failure from subjective play quality.

Use automated or deterministic checks for things such as:

- project parse/startup;
- state transitions;
- save/load persistence;
- unique IDs;
- dialogue/quest reference integrity;
- inventory grants/removals;
- boss reset behavior;
- sequence prerequisites;
- softlock probes;
- deterministic combat calculations where practical;
- performance budgets;
- controller/input routing.

Use developer tooling to enter difficult states directly rather than replaying hours of content for every test.

Passing verification means the implementation appears to satisfy its contract. It does **not** mean the game feels good.

---

## 5. PLAY — the human experience is authoritative

Every meaningful playable milestone is judged in motion by a person.

Human playtest observations should be recorded in one of these practical categories:

- **BUG** — behavior contradicts the contract or clearly fails;
- **BORING** — technically correct but low-value or tedious;
- **CONFUSING** — player cannot infer intended state, goal, navigation, or cause;
- **GOOD** — works and should generally survive iteration;
- **GREAT** — distinctive material worth protecting;
- **DON'T TOUCH THIS** — a fragile combination whose current feel should not be casually “cleaned up.”

These labels are observations, not automatic design commands. A tester can misunderstand something intentionally mysterious; a difficult encounter can be working as designed. The point is to preserve evidence and force an explicit decision.

### No explaining during first-pass onboarding tests

If a fresh tester needs verbal explanation to progress, record that as evidence. Do not repair the test by coaching them through it.

### Protect successful accidents

Iteration is capable of sanding away the thing that made a scene, route, animation, or combat exchange memorable. “GREAT” and “DON'T TOUCH THIS” exist so improvement work has a preservation target, not only a defect list.

---

## 6. The loop

A slice does not simply move left-to-right once.

Typical loop:

1. canon defines truth;
2. production defines the playable slice;
3. implementation builds it;
4. verification proves objective behavior;
5. human play exposes experiential problems;
6. findings return to the correct layer;
7. affected contracts are revised deliberately;
8. implementation follows the revised authority.

A code bug goes back to implementation.
A missing test goes back to verification.
A confusing objective may go back to production or canon.
A bad story beat goes back to canon.

Do not solve every problem by editing code.

---

## 7. Vertical-slice rule

Stillring should become playable in increasingly complete pieces.

During prototypes, discipline-specific experiments are appropriate because they are answering isolated technical risks.

Once production architecture stabilizes, favor region pods and state-complete slices that include the disciplines required to make that portion of the game actually playable.

This is why full production proceeds region-by-region rather than “all dialogue, then all enemies, then all art.”

---

## 8. Anti-feature-creep rule

AI makes implementation look cheap. Integration is not cheap.

A proposed feature must still pay for:

- design interaction with existing systems;
- UI/UX;
- save/state behavior;
- accessibility;
- test coverage;
- controller behavior;
- balance;
- content authoring cost;
- regression risk;
- documentation;
- long-term maintenance.

“An agent can code it quickly” is not sufficient justification.

After Alpha, foundational feature additions require explicit approval as already defined by the roadmap.

---

## 9. Source-of-truth hierarchy

When implementation context conflicts with repository authority:

1. current canonical contracts win over old chat context;
2. explicit production contracts win over agent assumptions;
3. tested runtime behavior reveals implementation truth but does not automatically redefine design truth;
4. playtest observations create evidence, not canon, until deliberately adopted;
5. old prompts, summaries, and remembered model context never silently override repository authority.

If two current canonical files conflict, stop treating either as safely implementable and reconcile both.

---

## 10. Definition of done for a production slice

A slice is complete only when:

- required canonical behavior exists;
- acceptance criteria pass;
- required save/state transitions survive reload;
- automated checks pass where applicable;
- debug entry points can reproduce important states;
- the slice has been played by a human at least once when it contains subjective gameplay;
- critical observations are resolved or explicitly accepted;
- known limitations are recorded;
- affected repository authority matches shipped behavior.

A green CI badge is evidence. It is not a declaration that the game is fun.