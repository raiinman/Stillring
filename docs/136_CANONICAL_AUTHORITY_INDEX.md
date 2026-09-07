# 136 — Canonical Authority Index

**Status:** CANONICAL NAVIGATION AUTHORITY  
**Updated:** 2026-09-07  
**Active program:** Studio Production Handoff Closure — Final Reconciliation / Acceptance  
**Current operational entrypoint:** `docs/NEXT_CHAT_HANDOFF.md`  
**Current cross-program production map:** `docs/195_STUDIO_HANDOFF_CROSS_PROGRAM_RECONCILIATION.md`

---

# 1. Purpose

This index answers:

> **If you are about to design, author, estimate, implement, tune, test, outsource, or review something in Stillring, which repository authority should you read first?**

This is navigation and precedence authority.

It does not replace detailed system or production documents.

A detailed document does not imply implementation, runtime verification, performance proof, accessibility proof or human-play acceptance.

Chats and remembered context are not authority.

---

# 2. Current operational precedence

For current project work, read in this order:

1. `docs/NEXT_CHAT_HANDOFF.md` — current operating boundary and immediate next task;
2. `docs/195_STUDIO_HANDOFF_CROSS_PROGRAM_RECONCILIATION.md` — current production-handoff status and open-decision queue;
3. `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md` — governing handoff program;
4. `docs/153_STUDIO_HANDOFF_ACCEPTANCE_CHECKLIST.md` — final handoff acceptance questions;
5. this index — topic routing;
6. `docs/137_SUPERSESSION_GRAPH.md` — scoped precedence/supersession;
7. `docs/138_TERMINOLOGY_GLOSSARY_AND_ONBOARDING.md` — terminology;
8. relevant system/story/production authority.

Important historical boundaries:

- `docs/149_DOCUMENTATION_CLOSURE_COMPLETENESS_AUDIT.md` is the earlier engineering/documentation closure audit, not the current full-production-handoff verdict.
- `docs/150_IMPLEMENTATION_OWNER_REVIEW_PACKAGE.md` is historical and explicitly **not** current authorization.

Current owner boundary remains **documentation only**.

---

# 3. Project-level authority

| Domain | Current authority | Current status |
|---|---|---|
| Project charter / product identity | `docs/00_PROJECT_CHARTER.md`, `docs/01_GAME_VISION.md` | canonical |
| Roadmap / gate order | `ROADMAP.md` | canonical sequencing |
| Production workflow | `docs/03_PRODUCTION_WORKFLOW.md` | canonical process |
| Technical direction | `docs/04_TECHNICAL_DIRECTION.md` plus `docs/188` | canonical direction / production consolidation |
| IP / clean-room guardrails | `docs/05_IP_GUARDRAILS.md` | canonical |
| Canon-to-play | `docs/15_CANON_TO_PLAY_PIPELINE.md` | canonical |
| Developer tooling / machine QA | `docs/16_DEVELOPER_TOOLING_AND_MACHINE_QA.md` | canonical design; runtime absent |
| Zelda design-lineage principles | `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md` | reference discipline |
| Project decision register | `docs/18_PROJECT_DECISION_REGISTER.md` + later scoped authorities | canonical decisions |
| Shared System IDE | `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`, `docs/141` | design complete; Issue #58 runtime open |
| Documentation closure framework | `docs/135`–`docs/150` | historical/current as individually marked |
| Studio handoff closure | `docs/151`–`docs/195` | active current program |
| Current handoff | `docs/NEXT_CHAT_HANDOFF.md` | operational entrypoint |

---

# 4. Authority / ownership / evidence infrastructure

| Topic | Authority |
|---|---|
| Canonical topic navigation | `docs/136_CANONICAL_AUTHORITY_INDEX.md` |
| Supersession / precedence | `docs/137_SUPERSESSION_GRAPH.md` |
| Terminology / onboarding | `docs/138_TERMINOLOGY_GLOSSARY_AND_ONBOARDING.md` |
| System ownership | `docs/139_SYSTEM_OWNERSHIP_MAP.md` |
| Cross-system contracts | `docs/140_CROSS_SYSTEM_CONTRACT_MATRIX.md` |
| System IDE coverage | `docs/141_SYSTEM_IDE_COVERAGE_MATRIX.md` |
| Runtime evidence baseline | `docs/142_RUNTIME_EVIDENCE_LEDGER_BASELINE.md` |
| Open implementation/tuning unknowns | `docs/144_UNANSWERED_QUESTION_REGISTER.md`; current owner queue scoped by `docs/195` |
| Implementation-readiness gaps | `docs/145_IMPLEMENTATION_READINESS_GAP_REGISTER.md` |
| Content traceability | `docs/146_CONTENT_TRACEABILITY_MATRIX.md` |
| Stale literal/reference audit | `docs/147_STALE_LITERAL_REFERENCE_AUDIT.md` |
| Studio handoff current gap statuses | `docs/152_STUDIO_HANDOFF_GAP_REGISTER.md` |
| Studio handoff acceptance checklist | `docs/153_STUDIO_HANDOFF_ACCEPTANCE_CHECKLIST.md` |
| Decision rights | `docs/170_STUDIO_DECISION_RIGHTS_MATRIX.md` |
| Production dependencies/change control | `docs/190_PRODUCTION_DEPENDENCY_DISCIPLINE_MATRIX.md` |
| Cross-program reconciliation | `docs/195_STUDIO_HANDOFF_CROSS_PROGRAM_RECONCILIATION.md` |

---

# 5. Story / world / narrative canon

The story contracts remain direct canon.

Read in the repository order required by `CLAUDE.md` when work touches story, quests, NPCs, progression or regions.

Primary sources:

- `docs/02_STORY_BIBLE.md`;
- `docs/story/06_CHARACTER_ARCS_AND_RELATIONSHIPS.md`;
- `docs/story/07_SCENE_BEAT_LEDGER.md`;
- `docs/story/08_REVEAL_AND_FORESHADOW_LEDGER.md`;
- `docs/story/09_MAIN_QUEST_OBJECTIVE_FLOW.md`;
- `docs/story/10_DIALOGUE_ANCHORS.md`;
- `docs/story/12_WORLD_PULSE_LEDGER.md`;
- `docs/story/13_EMOTIONAL_PACING_MAP.md`;
- `docs/story/14_QUIET_MOMENTS_AND_TRAVEL_BEATS.md`;
- `docs/story/17_SIDE_INTERACTION_REBALANCE.md`;
- relevant files under `docs/story/regions/`.

Null Meridian exact final-dungeon scene/order authority is further scoped by `docs/127`–`docs/134`, especially `docs/134_NULL_MERIDIAN_SCENE_ORDER_PRECEDENCE_ADDENDUM.md`.

Narrative production execution authority is `docs/182`–`docs/184`.

---

# 6. Gate 1 locomotion

Current cumulative authority:

- `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`.

Locked examples include:
- analog low-speed through full-speed intention;
- sustained Sprint from the beginning;
- **no ordinary traversal stamina/resource cost**;
- modest always-available jump;
- authored low-obstacle mantle/scramble;
- no universal/free climbing;
- same-handhold ledge shimmy only;
- explicit ledge release;
- slopes/stairs/falls/landings governed by the specification.

Runtime status: **unimplemented/unverified**.

Issue #5 remains open.

---

# 7. Gate 1 camera / targeting

Primary authority:

- `docs/22_GATE1_CAMERA_SPECIFICATION.md`;
- supporting camera decisions `docs/23`–`docs/36`.

The package governs free camera, recenter, collision/compression, target lock, target switching, framing, occlusion, large/high/low targets and camera-facing accessibility.

Runtime/human feel remains unverified.

---

# 8. Gate 2 combat / encounter

## Player combat

Primary authority:

- `docs/48_GATE2_COMBAT_STATE_MODEL.md`;
- supporting decisions `docs/37`–`docs/49`.

Gameplay owns combat legality/state.

Animation is presentation and may not become a contradictory gameplay state machine.

## Enemy / encounter pressure

Primary authority:

- `docs/50`–`docs/59`;
- closure/fixture boundary: `docs/59_GATE2_ENCOUNTER_FIXTURE_CLOSURE.md`.

Encounter pressure/readability and individual-AI behavior are separate ownership domains.

Runtime balance/AI/fairness remains unverified.

---

# 9. Gate 3 Cantor / tools / puzzle mechanisms

Current cumulative authority:

- `docs/69_GATE3_TOOL_SYSTEM_CUMULATIVE.md`;
- supporting decisions `docs/60`–`docs/68`;
- authored tool/pattern/upgrade catalog: `docs/13_CANTOR_AND_UPGRADE_CATALOG.md`.

Canonical filename is `69_GATE3_TOOL_SYSTEM_CUMULATIVE.md`.

Do not resurrect the stale `69_GATE3_TOOL_PUZZLE_CUMULATIVE_SPECIFICATION.md` reference.

Cantor diagnoses relationships; it is not generic detective vision.

Anchor is physical/load-path traversal/combat-pressure/puzzle grammar, not universal grappling.

Runtime/tool feel remains unverified.

---

# 10. Gate 4 Hush / world-layer

Current cumulative semantic authority:

- `docs/79_GATE4_HUSH_CUMULATIVE_SPECIFICATION.md`;
- supporting decisions `docs/70`–`docs/78`;
- prototype/closure context `docs/80_GATE4_ISSUE_227_CLOSURE_AND_PROTOTYPE_PLAN.md`.

Hard boundary:

> **Waking/Hush semantic truth is not Unreal Data Layer/streaming representation state.**

Production representation remains runtime-gated.

Technical comparison requirements are in `docs/188`/`docs/189`.

---

# 11. Save / World-State

Cumulative authority:

- `docs/88_SAVE_WORLD_STATE_CUMULATIVE_SPECIFICATION.md`;
- detailed subcontracts `docs/81`–`docs/87`.

Key rules:
- stable semantic IDs;
- no Actor/package/runtime identity as save truth;
- explicit schema/version/migration;
- coherent snapshot barriers;
- source owners restore before derived consumers reconcile;
- half-transition Hush state is not valid save authority.

Issue #4 remains open until real paired-layer save -> exit -> reopen -> load proof exists.

---

# 12. Completion / 100%

Numeric/count/weight authority:

- `docs/104_COMPLETION_LEDGER_RECONCILIATION_AUTHORITY_ADDENDUM.md`.

Exact current 36 Fault / 18 Pulse / 24 Vault semantic roster authority:

- `docs/194_COMPLETION_ITEM_ROSTER_RECONCILIATION_AUTHORITY.md`.

Category authorities:

- `docs/89`–`docs/103`.

Stale-literal blocking:

- `docs/105`–`docs/111`;
- especially `docs/109_COMPLETION_LEGACY_LITERAL_BLOCKLIST.md` and `docs/147_STALE_LITERAL_REFERENCE_AUDIT.md`.

Locked top-level counts:

- Main Story — 1 route;
- Local Repair Contracts — 24;
- Setup/Payoff — 12;
- Refuges — 11;
- Faults — 36;
- Pulse Shards — 18;
- Patterns — 9;
- Tool Mastery Upgrades — 14;
- Skill Trials — 9;
- Micro-vaults — 24;
- Records — 32;
- Unstandard Tool — 1 global / 12 internal stages;
- Drift Knots — 12;
- Optional Elites — 8;
- Community Projects — 6;
- Broken Standard Yard — 1 global / 7 internal commissions.

Do not use stale 48/28/30/30-Fault/13-Fault literals.

The old 28-Pulse ledger enumerated only 27 IDs; do not invent a missing legacy ID.

---

# 13. Setup / Payoff

Current authority:

- `docs/112`–`docs/119`.

Core rule:

> **Source systems own facts. Setup/Payoff evaluates them; it does not copy them.**

All 12 chains are design/documentation complete.

Runtime persistence/reconciliation/human legibility remains unverified.

---

# 14. Line Skiff

Current authority:

- `docs/120`–`docs/126`.

Core identity:

> **The Line Skiff is a supported route-network vehicle, not a summon-anywhere/free-roam mount.**

No ordinary fuel/stamina tax.

Route truth is semantic and independent of spline visibility.

Runtime handling/camera/streaming/save/Hush continuation remains unverified.

---

# 15. Null Meridian / finale

Current authority:

- `docs/127`–`docs/134`.

S1–S6 sequence and exact scene-order precedence are locked at design authority.

Optional completion cannot gate the canonical ending.

Null Meridian introduces no hidden mandatory finale-only core verb.

Blockout, Maelor, Listener, pacing, save/retry, accessibility and human emotional proof remain runtime work.

---

# 16. Studio production authority by discipline

## Art

- Art Bible / reference / manifest framework: `docs/154`–`docs/156`;
- workstream status: `docs/157`;
- character manifest: `docs/158`;
- enemy/boss manifest: `docs/159`;
- regional environment/prop manifest: `docs/160`;
- color/material/lighting scripts: `docs/161`;
- Hush visual matrix: `docs/162`;
- VFX manifest: `docs/163`;
- visual-board source briefs: `docs/164`–`docs/168`;
- art handoff audit: `docs/169`.

## Product / decision rights

- `docs/170`–`docs/172`.

## Animation

- `docs/173`–`docs/175`.

## UI/UX

- `docs/176`–`docs/178`.

## Audio / Music / VO

- `docs/179`–`docs/181`.

## Narrative Production

- `docs/182`–`docs/184`.

## Region / World / Content

- `docs/185`–`docs/187`;
- exact reduced completion-item roster: `docs/194`.

## Technical Production

- `docs/188`–`docs/189`.

## Production Management / outsourcing / change control

- `docs/190`–`docs/191`.

## QA / Accessibility / Localization

- `docs/192`–`docs/193`.

## Cross-program reconciliation

- `docs/195`.

---

# 17. Current studio-handoff status source

Do not derive current discipline status from the age of a gap row.

Use:

1. `docs/195` for cross-program status;
2. `docs/152` for current SH-* status rows;
3. each scoped acceptance audit for detailed reasoning;
4. `docs/153` for final acceptance questions.

No known production discipline is currently `MISSING` after the 2026-09-07 reconciliation.

Remaining non-PASS items are explicitly owner/product decisions or runtime gates.

The final repository-wide handoff verdict still requires the Final Studio Handoff Acceptance Audit.

---

# 18. Current owner/product decision queue

Current scoped authority: `docs/195`.

1. Broad UE5.8 implementation authorization — **NOT GRANTED**.
2. Launch platforms beyond PC-first — **TBD OWNER**.
3. Target-PC hardware/performance baseline — **TBD OWNER**.
4. VO scope — **TBD OWNER**.
5. Commercial title/name — **TBD OWNER / LATER CLEARANCE**.
6. Localization ship-language list — **TBD PRODUCT**.
7. Any material future change to locked game/story/art/product/platform identity.

Do not turn internal engineering or tuning choices into fake owner questions.

---

# 19. Runtime proof boundary

At this index revision:

- `game/` remains skeletal;
- no accepted `.uproject` runtime exists;
- no major gameplay system is implemented/proven;
- no System IDE runtime exists;
- no target-PC performance proof exists;
- no accessibility runtime conformance exists;
- no localized build/LQA exists;
- no platform certification exists;
- no human feel/fun/emotional claim is proven.

Open runtime issues #4, #5 and #58 remain open.

---

# 20. Fast read order by production discipline

## External producer / studio lead

1. `NEXT_CHAT_HANDOFF`;
2. `docs/195`;
3. `docs/151`–`docs/153`;
4. `docs/170`–`docs/172`;
5. `docs/190`–`docs/191`;
6. relevant discipline package;
7. `docs/192`–`docs/193` for QA/accessibility/localization obligations.

## Gameplay engineering

1. current handoff / docs 195;
2. docs 136–145 as relevant;
3. system cumulative authority;
4. docs 188–189;
5. docs 21/141 for System IDE;
6. open implementation issue acceptance criteria.

Implementation is not currently authorized.

## Art / animation / VFX

1. current handoff / docs 195;
2. docs 154–169;
3. docs 173–175 for animation;
4. gameplay/system authority affecting readability/contact/timing;
5. docs 190–193 for handoff/evidence/accessibility.

## UI / UX

1. current handoff / docs 195;
2. docs 176–178;
3. owning gameplay/save/completion authorities;
4. docs 192–193.

## Audio / VO / music

1. current handoff / docs 195;
2. docs 179–181;
3. docs 182–184 for line/scene/performance context;
4. docs 192–193.

## Narrative / cinematic / localization

1. current handoff / docs 195;
2. story canon in required `CLAUDE.md` order;
3. docs 182–184;
4. docs 176–181 where UI/audio delivery matters;
5. docs 192–193.

## World / level / content production

1. current handoff / docs 195;
2. docs 185–187;
3. docs 194 for active Fault/Pulse/Vault semantic IDs;
4. relevant story/system authorities;
5. docs 154–163 for visual burden;
6. docs 190–193 for dependency/evidence/accessibility.

---

# 21. Current final rule

> **Use the repository to determine what Stillring is. Use later runtime evidence to determine whether its implementation works. Never use an Unreal default, studio habit, old planning literal, chat memory or prototype convenience to silently redefine project authority.**
