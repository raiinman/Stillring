# 157 — Art Workstream Closure Status

**Status:** ACTIVE / STUDIO HANDOFF CLOSURE TRACKING  
**Updated:** 2026-09-06  
**Parent program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Art authority:** `docs/154_STILLRING_ART_BIBLE.md`  
**Supporting method:** `docs/155_ART_REFERENCE_METHOD_AND_BOARD_INDEX.md`  
**Production framework:** `docs/156_ART_PRODUCTION_MANIFEST_FRAMEWORK.md`  
**Character production authority:** `docs/158_CHARACTER_PRODUCTION_MANIFEST.md`

---

# 1. Purpose

This file records what the current art package actually settles, what remains dependency-bound, and what an external studio is or is not allowed to invent.

A mood board is never closure by itself.

---

# 2. Direction now settled

## 2.1 Final visual identity

Stillring's visual doctrine is **Playable Fantasy Illustration**:

- believable physical world;
- intentionally stylized composition;
- exaggerated geography where it serves memory/gameplay;
- strong silhouettes;
- landmark-first spatial identity;
- restrained selective detail;
- controlled materials;
- painterly decision-making in color/value/composition without requiring a painterly filter;
- grounded stylized humans;
- mature fantasy without blanket grimdark treatment.

## 2.2 Relationship to N64 lineage

Stillring retains N64/OoT-era strengths:

- silhouette clarity;
- visual hierarchy;
- fog/composition discipline;
- controlled materials;
- regional color identity;
- minimal clutter.

It does **not** require literal 1998 rendering limits, low-poly geometry, tiny textures, retro framebuffer resolution or period-accurate animation/lighting.

## 2.3 Environment direction

Major locations are recognized through shape, landmark, palette relationship, architecture, atmosphere and route composition. Settlements visibly respond to terrain, climate, labor, transport, resources and civic machinery.

## 2.4 Character direction — now creatively locked

`docs/158_CHARACTER_PRODUCTION_MANIFEST.md` is the specific production authority that completes the character placeholders anticipated by the Art Bible.

Principal character creative identity is now locked:

- **Neris Vale is female, she/her, age 17**;
- Neris has a defined face, hair, body/build target, costume construction, palette, Cantor carry solution, progression-equipment rules and six state variants;
- Tessa, Ilyra, Orin, Maelor, Caldrin, Sena and Rusk each have defined age/build, face, hair, costume, palette and state identity;
- principal reference heights and silhouette relationships are defined;
- family resemblance/relationship echoes are defined;
- the Listener's visible manifestation is defined rather than left as an abstract “special entity” placeholder;
- principal characters read through occupation and human history before fantasy archetype.

Board 03 is now a **visual verification board**, not a new design competition.

## 2.5 Hush direction

The Hush is a world-state/art relationship, not a universal filter or glitch pass. Regional and character identity must survive transformation.

## 2.6 Readability direction

Gameplay readability outranks spectacle. Art must honestly communicate traversal, interaction and threat states without default universal highlight paint.

---

# 3. SH-ART gap status

| Gap | Current status | Evidence | Remaining closure |
|---|---|---|---|
| `SH-ART-001` Neris production spec | **CREATIVELY CLOSED / TECHNICALLY DEPENDENCY-BOUND** | `docs/154` §18 + `docs/158` §8 | Board 03 faithful execution proof; representative Q2 model; rig/scale/performance evidence |
| `SH-ART-002` named-character visual bible | **CREATIVELY CLOSED FOR PRINCIPAL CAST** | `docs/158` §§8–18 | C3 regional recurring cast enumeration; Q2/Q3 execution sheets/models |
| `SH-ART-003` NPC population strategy | **SUBSTANTIALLY CLOSED AT STRATEGY LEVEL** | `docs/154` §19, `docs/156` §7, `docs/158` §§22–23 | region-specific C3/C4 manifests and final production counts above locked variety floor |
| `SH-ART-004` enemy/boss visual taxonomy | **PARTIALLY CLOSED** | `docs/154` §20, `docs/156` §8 | full enemy/boss manifest mapped to encounter authority |
| `SH-ART-005` modular environment standards | **PARTIALLY CLOSED** | `docs/156` §§9–10 | numeric scale/grid after Neris/camera/traversal representation; kit manifests |
| `SH-ART-006` region color/material/lighting bibles | **PARTIALLY CLOSED** | `docs/154` §§10–13, `docs/156` §11 | detailed per-region scripts/state variants |
| `SH-ART-007` Hush visual grammar | **SUBSTANTIALLY CLOSED AT DOCTRINE LEVEL** | `docs/154` §15, `docs/156` §14, `docs/158` state rules | H0–H5 content-family matrix and runtime proof |
| `SH-ART-008` VFX language | **SUBSTANTIALLY CLOSED AT DOCTRINE LEVEL** | `docs/154` §23, `docs/156` §15 | full effect manifest and performance/accessibility evidence |
| `SH-ART-009` region asset manifests | **OPEN / STARTER CREATED** | `docs/156` §11 | detailed quoteable manifests per region |
| `SH-ART-010` world scale/reference metrics | **INTENTIONALLY OPEN / DEPENDENCY-BOUND** | `docs/156` §10, `docs/158` reference heights | convert reference dimensions into tested world/camera/traversal metrics after representative implementation |

“Creatively closed” means the studio may execute the identity but may not redesign it. It does not mean a final production model has been built or tested.

---

# 4. Art decision rights

## LOCKED — implement, do not redefine

- Playable Fantasy Illustration;
- readability over spectacle;
- landmark/navigation priority;
- region-specific shape language;
- settlements grow from environment/practical life;
- selective detail/material hierarchy;
- no blanket photoreal clutter;
- no generic grimdark language;
- Hush is not a universal recolor/filter;
- pre-catastrophe places must be worth caring about;
- authored traversal remains visually honest;
- clean-room reference rules;
- full principal-character creative designs in `docs/158`;
- Neris is female, age 17, and visually a working apprentice/field bellwright—not royal, chosen, mystical, assassin-coded or sexualized;
- Tessa is courier, not rogue;
- Ilyra is field engineer, not oracle;
- Orin is repairman/father, not hidden master;
- Maelor initially remains visually trustworthy/human;
- Caldrin is archivist-engineer, not fantasy priest;
- Sena is foundry captain, not armored warrior;
- Rusk is credible administrator, not cartoon villain;
- Listener manifestation follows `docs/158` §16.

## STUDIO CHOICE WITHIN BOUNDS

Subject to later technical authority:

- topology;
- UV/material organization;
- modeling/sculpting software;
- shader implementation;
- hair technology;
- cloth technology;
- skeleton/retarget architecture that preserves silhouette;
- small seam/stitch/deformation adjustments that do not alter identity;
- Nanite/LOD/fallback choices;
- foliage and environment authoring workflow;
- source-art organization.

## PROTOTYPE / RUNTIME EVIDENCE

Requires representative implementation:

- final internal rendering resolution/scalability;
- geometry/material/texture budgets;
- foliage density;
- shadow/GI cost envelope;
- VFX overdraw/density;
- Hush runtime representation architecture;
- final world-scale conversion;
- final skeleton/rig family count;
- hair/cloth simulation budget;
- facial-animation technology;
- final attachment offsets under animation.

## OWNER REVIEW REQUIRED

Owner review is no longer a request to invent principal character identity from options. It is required for:

- any material departure from the locked designs in `docs/158`;
- any change to Neris's face/hair/body/costume/palette/gender presentation;
- any principal redesign that changes story read;
- any materially different Listener manifestation;
- any shift toward photoreal, anime, cartoon, cel-shaded, retro-low-poly or grimdark character treatment;
- major branding/iconography redefinition.

---

# 5. Engine technology boundary

UE5.8 is the engine authority, but no renderer feature is art direction by itself.

Stillring may use modern rendering capability without allowing modern rendering capability to define visual identity.

Do not infer mandatory photogrammetry, MetaHumans, maximum texture resolution, maximum vegetation density or every renderer feature enabled.

Technical production must later turn target hardware/platform requirements into measured budgets.

---

# 6. Reference-board state

## Existing

**Board 01 — Master Art Direction / North Star**

Directional companion to written authority. It does not override repository text.

## Required

- Board 02 — Regional Shape Language;
- Board 03 — Character Style Band / locked-design verification;
- Board 04 — Lighting / Atmosphere / Time;
- Board 05 — Gameplay Readability;
- Board 06 — Representative Benchmark Scene.

Board 03 must now visualize `docs/158` faithfully, including:

- Neris front/side/back;
- Neris face/expression target;
- all eight human principals at reference scale;
- black-silhouette test;
- flat-color test;
- hand/tool treatment;
- skin/hair/material target band;
- Listener manifestation diagram.

---

# 7. Next art-workstream sequence

1. produce the **Enemy / Boss Art Manifest** from encounter/combat authority;
2. build **Region Environment / Prop Manifests**, including C3 named-character enumeration;
3. produce **Regional Color / Material / Lighting Scripts**;
4. produce the **Hush Visual Production Matrix**;
5. produce the **VFX Production Manifest**;
6. create Board 03 as faithful visualization of the locked principal designs;
7. create the remaining board set alongside the matching written contracts;
8. defer numeric performance/scale budgets until representative implementation exists;
9. update global authority/onboarding indexes after art-package review;
10. mark remaining `SH-ART-*` rows closed only when their actual deliverables exist.

---

# 8. Art-workstream acceptance condition

The art handoff is safe when an external art director can answer from repository authority:

- what Stillring looks like and why;
- how every region differs;
- how principal characters look and why;
- how Neris is built visually and how her equipment evolves;
- how named/population reuse works;
- how Hush transformation works;
- how gameplay readability remains honest;
- what asset families exist;
- what is reusable versus unique;
- what quality each stage requires;
- what the studio may choose;
- what requires owner review;
- what requires runtime evidence;
- what references may not be copied;
- what production volume must be staffed.

The principal-character creative package now answers its portion of that acceptance test. Enemy/boss, region-manifest, lighting/material, Hush-production, VFX and final scale/performance work remain intentionally visible rather than hidden in chat history.
