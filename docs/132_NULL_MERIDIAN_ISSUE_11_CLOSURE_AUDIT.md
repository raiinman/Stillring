# 132 — Null Meridian / Issue #11 Closure Audit

**Status:** DESIGN / DOCUMENTATION COMPLETE — RUNTIME UNVERIFIED  
**Updated:** 2026-09-05  
**Issue:** #11 — Define Null Meridian synthesis trial matrix  
**Repository boundary reviewed:** through `d69d02df093b922787aae21c3847bbf3e7aa56a5`

## Closure purpose

This document audits the owner-approved Null Meridian design against every requirement and acceptance criterion in GitHub Issue #11.

It does **not** claim UE5.8 runtime completion.

The closure question is:

> Has the final dungeon's design been specified tightly enough that implementation can proceed later without inventing a new finale language, guessing at critical-path requirements, or contradicting story/combat/Hush/save/System IDE authority?

**Answer:** yes, at the documentation/design layer.

---

# 1. Authority set

Null Meridian Issue #11 authority is:

1. `docs/127_NULL_MERIDIAN_DECISION_1_SYNTHESIS_ARCHITECTURE.md`
   - six-sequence architecture;
   - guaranteed Story Minimum boundary;
   - no new mandatory verb;
   - Maelor/Listener separation;
   - debug-loadout requirements.
2. `docs/128_NULL_MERIDIAN_DECISION_2_ONE_GOVERNING_DUNGEON_IDEA.md`
   - one governing dungeon idea;
   - one-sentence player mental-model rule;
   - finale simplicity / no hidden systems-model rule.
3. `docs/129_NULL_MERIDIAN_DECISION_3_FIRST_HALF_ADVENTURE_FLOW.md`
   - monument -> machine -> workplace -> buried history;
   - S1 Hanging Walk;
   - S2 Equal House;
   - S3 The Door That Was There;
   - Quiet Court midpoint entry.
4. `docs/130_NULL_MERIDIAN_DECISION_4_SECOND_HALF_ESCALATION.md`
   - Maelor's indirect deliberate opposition;
   - S4 Corrected Passage;
   - S5 Battle That Won't End;
   - Maelor personal-workspace quiet beat;
   - Quiet Court scene-order precedence correction.
5. `docs/131_NULL_MERIDIAN_DECISION_5_TAKE_IT_OFF_THE_BELL.md`
   - S6 Take It Off the Bell;
   - local-control handoff;
   - Common Measure temporary shared operation;
   - master-relay disconnection;
   - mechanical pre-Maelor refutation of central-dependency necessity.

Existing supporting authority remains in force unless explicitly superseded:

- `docs/story/04_FINALE_AND_ENDING.md`;
- `docs/story/07_SCENE_BEAT_LEDGER.md`, subject to the Null Meridian scene-order precedence addendum created with this closure package;
- `docs/story/08_REVEAL_AND_FORESHADOW_LEDGER.md`;
- `docs/story/09_MAIN_QUEST_OBJECTIVE_FLOW.md`;
- `docs/story/13_EMOTIONAL_PACING_MAP.md`;
- `docs/story/regions/09_HUSH_CAIRNSPIRE_AND_NULL_MERIDIAN.md`;
- `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`;
- `docs/22_GATE1_CAMERA_SPECIFICATION.md`;
- Gate 2 combat cumulative/decision authority;
- `docs/69_GATE3_TOOL_SYSTEM_CUMULATIVE.md`;
- `docs/79_GATE4_HUSH_CUMULATIVE_SPECIFICATION.md`;
- `docs/88_SAVE_WORLD_STATE_CUMULATIVE_SPECIFICATION.md`;
- `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`;
- completion authority `docs/104_COMPLETION_LEDGER_RECONCILIATION_AUTHORITY_ADDENDUM.md`.

---

# 2. Issue goal audit

Issue goal:

> Design the final dungeon as a cumulative exam of Stillring's own verbs rather than a new-mechanic dump or a renamed version of another game's finale.

**Satisfied.**

The approved dungeon is not a one-tool-per-room recall test.

It has one governing player-facing idea:

> **Meridian keeps forcing distinct local things toward one authoritative state. Neris progresses by allowing legitimate local difference, preserving contradiction where needed, letting past states become past, and finally removing central command without destroying coordination.**

The six sequences deepen that same idea:

1. physical motion;
2. machine operation;
3. historical record;
4. Waking/Hush route expression;
5. preserved combat history;
6. infrastructure coordination after central disconnection.

This is cumulative story/mechanical synthesis rather than a renamed regional-barrier structure.

---

# 3. Required verb-family coverage

Issue required:
- Anchor Line;
- Glasslung Reed;
- Temper Gauntlet;
- Vane Cloak;
- Mirror Nail;
- Cantor patterns;
- Hush seam mode;
- core lock-on combat.

Coverage:

| Required family | Canonical Null Meridian use |
|---|---|
| Anchor Line | S1 Hanging Walk; optional/short S6 service handoff where authored |
| Vane Cloak | S1 Hanging Walk traversal consequence |
| Glasslung Reed | S2 Equal House; possible short S6 local-service handoff |
| Temper Gauntlet | S2 Equal House; possible short S6 local-service handoff |
| Mirror Nail | S3 The Door That Was There; S4 Corrected Passage |
| Cantor / Palinode | S3 historical disagreement; S5 room/formation diagnosis; S6 Common Measure |
| Hush seam mode | S4 Corrected Passage under traversal/combat continuity |
| core lock-on combat | S4 route pressure; S5 ordinary combat remains authoritative; Maelor encounter remains core-combat centered |

**Satisfied.**

No required verb exists only as decorative token use.

---

# 4. Rule audit — 5–7 compact concepts

Issue required 5–7 compact synthesis concepts.

**Satisfied with six.**

The six are:

1. `null_meridian.s1.hanging_walk` — working semantic name to be finalized in implementation schema;
2. `null_meridian.s2.equal_house`;
3. `null_meridian.s3.door_that_was_there`;
4. `null_meridian.s4.corrected_passage`;
5. `null_meridian.s5.battle_that_wont_end`;
6. `null_meridian.s6.take_it_off_the_bell`.

Exact final semantic IDs may be normalized during schema implementation, but must remain stable once persistence compatibility matters.

The retail game need not display numbered trial labels.

---

# 5. Rule audit — no one-room-per-region formula

**Satisfied.**

The approved design explicitly rejects:
- Rootmere room;
- Saltreach room;
- Emberstep room;
- High Aerie room;
- Mireglass room;
- Cairnfall room;
- six regional barriers;
- six regional beams;
- six regional switches.

Regional knowledge may appear because workers from across Orra built and maintained Meridian, but room identity is functional/thematic rather than geographic nostalgia.

S6 specifically uses ordinary Meridian service branches rather than six regional callbacks.

---

# 6. Rule audit — every sequence combines prior mechanics

**Satisfied.**

S1:
- established Anchor physical relationship;
- established Vane traversal;
- existing moving-structure/airflow understanding.

S2:
- established Glasslung pressure relation;
- established Temper thermal/material relation;
- prior lesson that unlike systems need not share one target state.

S3:
- Palinode historical disagreement;
- Mirror local-state commitment;
- spatial traversal through a preserved historical doorway.

S4:
- Mirror commitment;
- Hush seam traversal;
- ordinary movement/combat continuity;
- route state under deliberate correction pressure.

S5:
- Cantor/Palinode-style diagnosis at room/formation level;
- preserved historical state;
- ordinary lock-on combat.

S6:
- source-owned local machinery states;
- Common Measure temporary coordination;
- physical relay disconnection;
- existing local-control concepts from Unringing/Cairnspire service authority.

No sequence is authorized to teach a new mandatory core verb.

---

# 7. Rule audit — traversal + combat

Issue requires at least one traversal + combat sequence.

**Satisfied by S4 — The Corrected Passage.**

The objective is route traversal, not extermination.

Combat creates pressure while:
- Mirror preserves a useful local route state;
- Waking/Hush seam transitions remain subject to existing Gate 4 legality;
- target/combat continuity remains authoritative;
- seams grant no invulnerability, action reset, or target roulette.

The sequence may permit avoidance, fighting for room, or route use according to authored encounter geometry.

No `ENEMIES REMAINING: 0` gate is required merely to advance.

---

# 8. Rule audit — perception / state commitment

Issue requires at least one perception/state-commitment sequence.

**Satisfied by S3 and reinforced by S4.**

S3:
- Palinode exposes incompatible official/worker histories;
- Mirror temporarily commits the historically documented worker-door state;
- the player traverses it;
- the other history is not erased.

This directly embodies Stillring's established distinction between:
- recognizing contradiction;
- committing one useful local state;
- declaring one universal truth.

---

# 9. Rule audit — Maelor / Listener thematic resolution through mechanics

Issue requires the final Maelor/Listener sequence to resolve the thematic problem through mechanics as well as cutscenes.

**Satisfied at the design-authority layer by combined existing finale authority + Decisions #1–#5.**

Before Maelor:
- S6 physically proves local continuation after central disconnection.

Maelor:
- existing canonical fight remains a playable core-combat confrontation;
- phase-one behavior uses established combat/system relationships such as silenced/redundant tells, delayed echoes, preserved objects, pressure/air relationships, and false diagnostic histories;
- Decision #1 explicitly forbids turning him into six inventory locks or introducing a new mandatory boss-only verb;
- S5 pre-teaches preserved combat-history pressure so Maelor escalates known language rather than inventing it.

Listener:
- is not a third health-bar boss;
- preserved desirable world states become playable spaces/experiences;
- their inability to progress becomes mechanically legible;
- final resolution is a **player-performed decommission/release action**, not merely a cinematic choice;
- Motion, Memory, and Ending function as learned relationships, not collectible spells;
- the Meridian central heart is deliberately ended rather than taken over.

No additional owner decision is required merely to restate the already locked Maelor/Listener contract.

Exact arena geometry, attack timings, tuning, animation, and implementation remain runtime work and human-play validation.

---

# 10. Acceptance criterion — trial dependency matrix exists

**Satisfied.**

Canonical dependency shape:

```text
ENTRY / CEREMONIAL SHELL
        |
        +------ S1 HANGING WALK
        |
        +------ S2 EQUAL HOUSE
                 |
                 v
        WORKER MAINTENANCE DESCENT
                 |
                 v
        S3 THE DOOR THAT WAS THERE
                 |
                 v
           QUIET COURT ARCHIVE
                 |
                 v
        MAELOR DELIBERATE CORRECTION
                 |
                 v
        S4 CORRECTED PASSAGE
                 |
                 v
        S5 BATTLE THAT WON'T END
                 |
                 v
        MAELOR PERSONAL WORKSPACE
                 |
                 v
        S6 TAKE IT OFF THE BELL
                 |
                 v
              MAELOR
                 |
              LISTENER
                 |
        FINAL DECOMMISSION
```

S1/S2 may be order-flexible.

S3 requires both first-half service problems settled sufficiently to restore worker access.

S4/S5 follow Quiet Court midpoint discovery and Maelor's deliberate correction turn.

S6 follows S5 and the quiet workspace beat.

Maelor follows S6.

Listener follows Maelor.

---

# 11. Acceptance criterion — prerequisites and failure/recovery documented

**Satisfied.**

Decision #1 establishes Story Minimum and general local-reset authority.

Decisions #3–#5 define the individual sequence failure/recovery expectations.

Common locked rules:
- no finite critical resource consumption;
- failure never replays the entire final dungeon;
- settled prior sequence facts remain settled;
- retries restore deterministic valid local baselines;
- temporary Mirror/seam/tool states reconcile through their owners;
- no half-transition save authority;
- duplicate settlement/reward is forbidden;
- abandoning/re-entering converges to a valid authored state;
- failure cause must be explainable through world/system feedback;
- accessibility accommodations do not invalidate completion.

S4 additionally preserves combat/seam continuity authority.

S6 prevents irreversible relay disconnection before required local-safety predicates.

---

# 12. Acceptance criterion — no new mandatory core verb

**Satisfied and hard-locked.**

Null Meridian may create:
- new combinations;
- new spatial arrangements;
- new pressure conditions;
- new narrative contexts;
- new causal relationships between already-understood systems.

It may not create a new mandatory:
- input;
- meter;
- movement grammar;
- tool mode;
- physics rule;
- seam rule;
- combat rule;
- Cantor operating grammar;
- finale-only state language.

Decision #2 adds the plain-language test:

> If a major sequence cannot be explained in one ordinary sentence without internal systems jargon, simplify it.

---

# 13. Acceptance criterion — debug loadouts before full narrative content

**Satisfied at the design contract layer.**

The Null Meridian System IDE must provide at minimum:

- Story Minimum fixture;
- Representative Partial fixture;
- Full Completion fixture;
- Upgrade-Stripped Audit fixture;
- sequence-direct loading;
- prior dependency settlement controls;
- local reset;
- save/reload at semantic boundaries;
- death/retry;
- Hush legal/illegal seam cases;
- combat pressure on/off where valid;
- optional capability present/absent matrices;
- accessibility presets;
- human-readable `Explain Current State` output.

S6 specifically requires Local Accord absent/present fixtures to prove it is not a gate.

The workbench must use authoritative gameplay services and may not maintain a second hidden finale state model.

---

# 14. Guaranteed Story Minimum audit

Mandatory Null Meridian completion may not depend on:
- any of the six optional Cantor Patterns;
- any of the fourteen optional Tool Mastery Upgrades;
- all six community projects;
- Freehand Frame;
- completion percentage;
- optional setup/payoff branches;
- prestige optimization.

Optional content may provide:
- shorter/elegant routes;
- safer handling;
- extra evidence;
- alternate worker access;
- additional acknowledgement;
- richer final/credits specificity.

It does not produce a different valid/invalid ending hierarchy.

`pattern.local_accord` remains explicitly optional.

Story Minimum uses mandatory Common Measure for S6.

---

# 15. Narrative-pacing audit

The approved finale now has a deliberate emotional/mechanical waveform:

1. **dread / awe** — monumental entry;
2. **competence** — S1/S2 simple physical/operational repair understanding;
3. **humanization** — worker architecture exposed;
4. **institutional unease** — S3 enters Quiet Court through erased worker history;
5. **confrontational turn** — Maelor begins deliberately correcting the world against Neris;
6. **pressure** — S4 traversal/combat;
7. **preservation horror** — S5 old fight cannot become past;
8. **quiet human beat** — Maelor's small workspace;
9. **mastery / proof** — S6 disconnects central relay without killing local services;
10. **confrontation** — Maelor;
11. **wonder / temptation / sorrow** — Listener;
12. **release** — final decommission.

This matches the established emotional target:

> dread -> mastery -> confrontation

followed by:

> wonder -> temptation -> sorrow -> release.

---

# 16. OoT-derived discipline audit

The project uses Ocarina of Time as a design-principle reference, not a content template.

The final-dungeon discipline now preserves the intended useful lessons:
- one readable place identity;
- previously learned verbs reused rather than replaced;
- mechanics serve fiction/place identity;
- player-facing mental models remain simple;
- final challenges escalate known language;
- emotional/narrative momentum accelerates toward the confrontation.

It explicitly rejects copying:
- six elemental barriers;
- one room per prior region/temple;
- item-token callback locks;
- a disguised Ganon's Castle structure.

Clean-room IP discipline remains mandatory.

---

# 17. Save/world-state audit

Design authority is compatible with Save/World-State rules:
- stable semantic facts outrank actor/map paths;
- no half-transition saves;
- source systems own local machine/combat/Hush facts;
- Null Meridian sequence settlement observes those facts rather than stealing ownership;
- settled sequence history is idempotent;
- reload converges to authored valid states;
- temporary presentation state is not persistence authority;
- contradictions are surfaced in System IDE/save audit.

Actual save/load behavior remains unverified until UE5.8 implementation.

---

# 18. Accessibility audit

Critical progression may not rely only on:
- pitch discrimination;
- rhythm discrimination;
- color;
- vibration;
- tiny gauges;
- rapid reaction timing unrelated to the semantic skill.

Required design approach:
- redundant visual/mechanical/audio feedback;
- readable interaction affordances;
- adjustable timing where appropriate;
- combat telegraphs remain redundant;
- seam/Hush transitions remain perceivable;
- accessibility settings do not invalidate canonical completion.

Runtime verification remains future work.

---

# 19. Production / implementation boundary

Issue #11 is **not** runtime-complete.

Still unverified:
- UE5.8 Null Meridian blockout;
- exact geometry;
- sequence scripting;
- authoritative C++ services;
- Primary/DataAsset schemas where applicable;
- World Partition/Data Layer behavior;
- Hush transitions in final geometry;
- combat encounter tuning;
- Maelor boss timing/AI;
- Listener playable-state realization;
- save/reload;
- performance;
- accessibility behavior;
- System IDE implementation;
- deterministic fixture execution;
- human comprehension;
- emotional pacing;
- player memory/clarity;
- final-dungeon duration.

No document may convert design completion into runtime proof.

---

# 20. Scene-ledger reconciliation

The older `docs/story/07_SCENE_BEAT_LEDGER.md` M16 shorthand predates Decisions #1–#5 and places:

`paired mechanic trials -> Quiet Court Archive -> Maelor`

as if Quiet Court immediately precedes the boss.

That ordering is superseded.

The closure package includes:

`docs/134_NULL_MERIDIAN_SCENE_ORDER_PRECEDENCE_ADDENDUM.md`

which establishes the approved M16 sequence without requiring a risky wholesale rewrite of the long canonical ledger during this scoped closure.

The ledger remains authoritative for broader mandatory story beats, but its old M16 adjacency is subordinate to docs 127–134.

---

# 21. Closure result

All Issue #11 acceptance criteria are **design/documentation satisfied**.

No unresolved owner design choice is required to close Issue #11.

Therefore Issue #11 should be closed as:

> **Completed — design/documentation authority locked; UE5.8 runtime proof remains future work.**

---

# 22. Next project phase

Issue #11 was the final planned design issue before the project's comprehensive documentation closure phase.

The next phase is the **Documentation Closure Program**, not immediate implementation.

Required program work includes:
- authority index;
- supersession graph;
- terminology/glossary;
- system ownership map;
- cross-system contract matrix;
- unanswered-question register;
- implementation-readiness gaps;
- content traceability;
- System IDE coverage matrix;
- runtime-evidence ledger;
- onboarding/read-order path;
- stale-document audit;
- final owner review package.

Only after that final owner review should UE5.8 implementation authorization be considered.
