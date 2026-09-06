# 172 — Product / Decision-Rights Written-Handoff Audit

**Status:** ACTIVE / SCOPED HANDOFF RECONCILIATION / DOCUMENTATION-ONLY  
**Updated:** 2026-09-06  
**Parent program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Gap baseline:** `docs/152_STUDIO_HANDOFF_GAP_REGISTER.md`  
**Acceptance baseline:** `docs/153_STUDIO_HANDOFF_ACCEPTANCE_CHECKLIST.md`  
**Decision-rights authority:** `docs/170_STUDIO_DECISION_RIGHTS_MATRIX.md`  
**Product/platform authority:** `docs/171_PERFORMANCE_PLATFORM_PRODUCT_BRIEF.md`  
**Boundary:** this audit evaluates written production authority only. It does not authorize UE5.8 implementation, platform SDK work, performance testing, gameplay testing, production asset creation, certification work, or merge of any open documentation PR.

---

# 1. Purpose

The Studio Handoff Closure program identified an ordering requirement that was not fully satisfied before the art workstream advanced:

1. establish product/platform boundaries;
2. establish studio decision rights and change control;
3. then let discipline bibles/manifests operate inside those boundaries.

The art package now exists on the active documentation stack, but the project still needed one explicit authority answering:

> **What may the studio decide, what is already locked, what is runtime-gated, and what genuinely still belongs to the owner?**

`docs/170` and `docs/171` close that structural omission.

This audit reconciles their effect on the global gap and acceptance programs without falsely claiming that product decisions such as target hardware have been made.

---

# 2. Scope and precedence

For current status of:
- `SH-PROD-001` through `SH-PROD-004`;
- `SH-MGMT-004`;
- `SH-MGMT-006`;
- the Product Definition acceptance rows in `docs/153`;
- the decision-rights/change-control rows in `docs/153` Section 12;

use this audit as the scoped current-status reconciliation after the original gap definitions.

`docs/152` remains the global gap register.

`docs/153` remains the governing acceptance checklist.

`docs/170` and `docs/171` are the detailed production authorities.

This audit does not supersede unrelated discipline gaps.

---

# 3. Audit vocabulary

Use the `docs/153` status vocabulary:

- **PASS** — written authority is sufficient for the stated production-stage question;
- **PARTIAL** — meaningful authority exists but normal production still requires unbounded assumptions;
- **TBD OWNER** — a genuine owner/product decision remains;
- **RUNTIME-GATED** — representative implementation/evidence is required;
- **MISSING** — required written authority does not exist.

A row may be `PASS — CLASSIFICATION AUTHORITY` even when the product answer itself is intentionally `TBD OWNER` or `RUNTIME-GATED`, provided the repository now clearly states what remains unknown, why, when it must be decided, and what cannot be assumed meanwhile.

---

# 4. Product-gap reconciliation

| Gap | Current result | Current authority | Remaining honest closure |
|---|---|---|---|
| `SH-PROD-001` — exact target-PC performance baseline | **TBD OWNER — DECISION GATE NOW EXPLICIT** | `docs/171` Sections 5, 18, 19; `docs/170`; `docs/144` UQ-F001 | representative implementation/performance research, then owner target selection before objective Gate 5 target-performance acceptance |
| `SH-PROD-002` — launch-platform scope beyond PC-first | **TBD OWNER — DECISION GATE NOW EXPLICIT** | `docs/171` Section 4; `docs/170`; Project Charter | owner selects additional launch platforms before platform SDK/certification/final platform-specific production commitment |
| `SH-PROD-003` — commercial title/name clearance | **TBD OWNER / LATER CLEARANCE — BOUNDED** | Project Charter; `docs/171` Section 16; `docs/170` | owner naming decision + appropriate clearance before public-release branding; not a blocker for current game documentation or early PC-first implementation later |
| `SH-PROD-004` — resolution/framerate matrix | **RUNTIME-GATED / PRODUCT-CONFIRMED** | `docs/171` Sections 6 and 18 | select only after target product/hardware + representative rendering/runtime evidence; record accepted matrix before Gate 5 target-performance exit claim |

## 4.1 Why these rows are no longer ambiguous blanks

The repository now prevents an external studio from silently assuming:
- a console launch;
- Steam-only launch;
- a particular GPU/CPU tier;
- 30/60/120 fps;
- 1080p/1440p/4K;
- mandatory Lumen/Nanite/World Partition;
- low internal resolution as mandatory retro simulation;
- the current development PC as product target;
- a legally cleared final title.

Those are material production assumptions.

They are now explicitly classified instead of delegated to guesswork.

---

# 5. Production-management gap reconciliation

| Gap | Current result | Current authority | Remaining honest closure |
|---|---|---|---|
| `SH-MGMT-004` — approval/decision-rights matrix | **PASS — WRITTEN AUTHORITY** | `docs/170_STUDIO_DECISION_RIGHTS_MATRIX.md` | discipline-specific bibles must continue applying the classification; runtime-gated decisions still require future evidence |
| `SH-MGMT-006` — change-control process | **PASS — WRITTEN AUTHORITY** | `docs/170` Sections 13–15 | actual production must demonstrate use of the process; no runtime evidence is claimed |
| `SH-MGMT-001` — dependency matrix | **MISSING** | not closed by this package | later Production Dependency / Discipline Matrix |
| `SH-MGMT-002` — deliverable taxonomy | **MISSING** | not closed by this package | later production-management authority |
| `SH-MGMT-003` — region/workstream ownership model | **MISSING** | not closed by this package | later production dependency/region authority |
| `SH-MGMT-005` — outsourcing package boundaries | **PARTIAL** | `docs/170` defines outsourcing decision-rights boundary but not package inventory | later dependency/discipline package identifies concrete outsourcing-safe work packages |

The decision-rights package therefore closes its own management scope without falsely marking production management complete.

---

# 6. `docs/153` Product Definition reconciliation

| Acceptance item | Current result | Evidence / note |
|---|---|---|
| Product mode explicit | **PASS** | single-player; no live service; no base-game multiplayer ambiguity — Project Charter + `docs/171` |
| First-playthrough duration explicit | **PASS** | 20–30 hours |
| World/dungeon-scale target explicit | **PASS** | interconnected authored overworld/regional hubs; 8–10 major dungeon-scale spaces including finale |
| PC-first status explicit | **PASS** | Project Charter + `docs/171` |
| Launch-platform scope selected or `TBD OWNER` with gate | **PASS — CLASSIFICATION AUTHORITY** | `TBD OWNER`; gate explicitly defined in `docs/171` |
| Target-PC baseline selected or `TBD OWNER` with gate | **PASS — CLASSIFICATION AUTHORITY** | `TBD OWNER`; not a Gate 1 blocker; required before objective Gate 5 target-performance acceptance |
| Resolution/framerate expectations defined or gated | **PASS — CLASSIFICATION AUTHORITY** | `RUNTIME-GATED / PRODUCT-CONFIRMED`; representative evidence path defined |
| Online/backend/service requirements explicit | **PASS** | no retail live-service/AI-development dependency; optional later platform services remain downstream integrations |
| Commercial-title status explicit | **PASS — CLASSIFICATION AUTHORITY** | internal codename only; later owner choice + clearance |
| Original-IP / clean-room constraints explicit | **PASS** | Project Charter, `CLAUDE.md`, IP guardrails, art reference method |

## 6.1 Product-section result

> **PASS — WRITTEN PRODUCT-BOUNDARY AUTHORITY.**

This means a producer can scope the current product without silently inventing platform/performance/online/title assumptions.

It does not mean the target PC, additional launch platforms, final framerate/resolution matrix, storefront, language list, VO scope, or commercial title are already selected.

---

# 7. `docs/153` Decision-Rights / Production-Management reconciliation

| Acceptance item | Current result | Evidence / note |
|---|---|---|
| Studio Decision-Rights Matrix exists | **PASS** | `docs/170` |
| `LOCKED` decisions explicit | **PASS** | `docs/170` + current authority stack |
| studio-choice decisions explicit | **PASS** | `docs/170` defines bounded internal implementation/production freedom |
| prototype/human-play tuning explicit | **PASS** | `RUNTIME-GATED` class + promotion contract |
| owner-decision required items explicit | **PASS** | platform scope, target PC, VO scope if unresolved, commercial title, material product/creative changes |
| change-control path exists | **PASS** | `docs/170` Section 14 |
| production dependency/discipline matrix exists | **MISSING** | separate required closure package |
| upstream blockers vs parallel work distinguishable | **PARTIAL** | current documents identify many blockers, but no consolidated discipline matrix yet |
| outsourcing-safe packages identifiable | **PARTIAL** | generic qualification exists; concrete packages remain to be inventoried |
| production deliverable taxonomy exists | **MISSING** | later production-management authority |
| no fake staffing/headcount/budget | **PASS** | neither `docs/170` nor `docs/171` invents unsupported staffing/budget numbers |

## 7.1 Section result

> **PARTIAL — DECISION RIGHTS AND CHANGE CONTROL PASS; DEPENDENCY, DELIVERABLE, OWNERSHIP AND OUTSOURCING INVENTORY REMAIN OPEN.**

---

# 8. Adversarial fresh-studio review

Assume a studio has repository access and no chat history.

## Question: “Can we pick a 60-fps target and start optimizing for it?”

**Answer:** No final target is yet authoritative. The studio may measure development evidence later, but the product matrix is runtime/product gated and target hardware is still owner-selected.

No guess required.

## Question: “Can we just make console support part of scope?”

**Answer:** No. PC-first is locked; additional launch platforms are `TBD OWNER`.

No guess required.

## Question: “Can engineering choose how the shared dev shell is built?”

**Answer:** Yes, within the locked System IDE contract. UMG/Slate/hybrid is an implementation choice unless the choice violates controller use, provenance, shared registration, authoritative service access, or shipping exclusion.

No owner interruption required.

## Question: “Can animation root motion own combat displacement because it is easier?”

**Answer:** No. Gameplay state/locomotion/combat ownership remains authoritative. The future Animation Bible may define bounded implementation mechanisms, not transfer state ownership to presentation.

No guess required.

## Question: “Can art use Lumen/Nanite because this is Unreal?”

**Answer:** Not as an assumption. Those are evidence-gated options, not product doctrine.

No guess required.

## Question: “Can we change a locked mechanic if it lowers production cost?”

**Answer:** Not silently. A material player-facing change follows the explicit change-control path and requires authority/owner review appropriate to the class.

No guess required.

---

# 9. Negative-space audit

The new package deliberately closes several dangerous forms of vague language.

## “Studio decides”

Now invalid unless the permitted envelope is stated.

## “Tune later”

Now insufficient for material values. A runtime-gated item requires a named future fixture/evidence/promotion path.

## “PC first”

No longer permits hidden inference of storefront, target hardware, console plans, resolution, framerate, handheld support, HDR, ray tracing, or certification scope.

## “Use Unreal defaults”

Not authority for gameplay, camera, rendering features, streaming, persistence identity, or state ownership.

## “Owner should approve everything important”

Rejected. Ordinary internal implementation/craft decisions remain studio-owned inside documented bounds.

---

# 10. Cross-system consequences

The decision-rights/product package does not alter current source-system ownership.

It strengthens the integration boundary by requiring future discipline documents to state:
- what is locked;
- what their discipline owns;
- what is implementation/craft freedom;
- what depends on another discipline;
- what is runtime-gated;
- what genuinely needs owner selection;
- what is prohibited.

Future Animation, UI, Audio, Narrative, Region, Technical, QA and Production-Dependency authorities must consume this classification rather than creating their own inconsistent terminology.

---

# 11. Remaining owner decisions after this package

The current known owner/product decisions remain deliberately narrow:

1. launch-platform scope beyond PC-first;
2. target-PC performance baseline before objective Gate 5 target-performance acceptance;
3. VO scope if the Audio/Narrative production package confirms current authority does not already settle it;
4. commercial title/name after appropriate clearance when public-release planning needs it;
5. any future material change to locked product/game/story/art/platform identity.

These do not halt unrelated documentation work.

---

# 12. Next highest-value unresolved dependency

After this package, the largest currently unclosed discipline block in `docs/152` is:

> **Animation production — `SH-ANI-001` through `SH-ANI-009`.**

The next documentation package should create:
- an Animation Bible;
- an explicit animation production manifest/inventory;
- a scoped animation written-handoff audit;
- cross-links to locomotion, camera, combat, tools, Hush, Line Skiff, NPCs, enemies/bosses, cinematics, accessibility, System IDE and technical-production authority.

It must not let animation become gameplay-state authority and must keep exact feel/performance values runtime-gated where appropriate.

---

# 13. Audit conclusion

The Product / Decision-Rights package is complete at written-authority level for its scoped questions.

Current result:

> **PASS — PRODUCT BOUNDARIES, DECISION CLASSIFICATION AND CHANGE CONTROL ARE EXPLICIT.**

Global Studio Production Handoff Closure remains **IN PROGRESS** because Animation, UI/UX, Audio/Music/VO, Narrative Production, world/content production, Technical Production, Production Dependency/Discipline, QA/accessibility/localization consolidation, and final whole-game handoff/Astra-readiness audits remain incomplete.

No runtime implementation or testing is authorized.