# 157 — Art Workstream Closure Status

**Status:** ACTIVE / STUDIO HANDOFF CLOSURE TRACKING  
**Updated:** 2026-09-05  
**Parent program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Art authority:** `docs/154_STILLRING_ART_BIBLE.md`  
**Supporting method:** `docs/155_ART_REFERENCE_METHOD_AND_BOARD_INDEX.md`  
**Production framework:** `docs/156_ART_PRODUCTION_MANIFEST_FRAMEWORK.md`

---

# 1. Purpose

This file prevents the existence of an Art Bible from being mistaken for completion of the entire art-production handoff.

It records:

- what the current documentation now answers;
- what remains open;
- which unknowns are legitimate;
- which unknowns would be unsafe studio assumptions;
- the next required art documents.

---

# 2. Direction now settled

The following are current owner-approved visual direction and should not be silently reinterpreted by an agent, contractor, or implementation team:

## 2.1 Final-direction identity

Stillring's visual doctrine is **Playable Fantasy Illustration**.

This means:

- believable physical world;
- intentionally stylized composition;
- exaggerated geography where it serves memory/gameplay;
- strong silhouettes;
- landmark-first spatial identity;
- restrained, selective detail;
- controlled materials;
- painterly decision-making in color/value/composition without requiring a literal painterly shader;
- grounded lightly stylized characters;
- mature fantasy without blanket grimdark treatment.

## 2.2 Relationship to N64 lineage

Stillring retains the strengths previously described as N64-era readability:

- silhouette clarity;
- visual hierarchy;
- fog/composition discipline;
- controlled materials;
- region color identity;
- minimal clutter.

It does **not** currently lock final production to:

- literal low-poly asset limits;
- tiny textures;
- retro framebuffer resolution;
- nearest-neighbor/pixel filtering;
- period-accurate lighting;
- N64-style animation limits.

Those older constraints are inspiration/history unless separately selected later for a bounded artistic or performance reason.

## 2.3 Environment direction

Major locations must be recognizable by:

- shape;
- landmark;
- palette relationship;
- architecture;
- atmosphere;
- route composition.

Settlements must respond visibly to terrain, weather, labor, transport, resources, and civic machinery.

## 2.4 Character direction

Characters are grounded and deliberately stylized, not photoreal scans or exaggerated anime forms.

Neris must visually read as a working seventeen-year-old apprentice bellwright rather than a chosen-one fantasy archetype.

## 2.5 Hush direction

The Hush is a world-state/art relationship, not a one-button color filter or generic glitch effect.

Regional identity and gameplay readability must survive Hush transformation.

## 2.6 Readability direction

Gameplay readability outranks graphical spectacle.

Art must participate in honest traversal/interactions rather than relying on universal highlight paint or hidden affordances.

---

# 3. SH-ART gap status

| Gap | Current status | Evidence | Remaining closure |
|---|---|---|---|
| `SH-ART-001` Neris production spec | **PARTIALLY CLOSED** | `docs/154` §18, `docs/156` §6 | final face/body/costume concept and owner visual approval; scale/rig dependencies |
| `SH-ART-002` named-character visual bible | **OPEN / FRAMEWORK READY** | `docs/154` §17, `docs/156` §5 | per-character manifests derived from canonical arcs and region/social role |
| `SH-ART-003` NPC population strategy | **PARTIALLY CLOSED** | `docs/154` §19, `docs/156` §7 | per-region archetype pools, reuse bounds, body/head/clothing strategy |
| `SH-ART-004` enemy/boss visual taxonomy | **PARTIALLY CLOSED** | `docs/154` §20, `docs/156` §8 | full enemy/boss manifest mapped to encounter authority |
| `SH-ART-005` modular environment standards | **PARTIALLY CLOSED** | `docs/156` §§9–10 | numeric scale/grid after honest character/camera/traversal representation; kit-specific manifests |
| `SH-ART-006` region color/material/lighting bibles | **PARTIALLY CLOSED** | `docs/154` §§10–13; `docs/156` §11 | detailed per-region scripts and state variants |
| `SH-ART-007` Hush visual grammar | **SUBSTANTIALLY CLOSED AT DOCTRINE LEVEL** | `docs/154` §15; `docs/156` §14 | H0–H5 content-family matrix and later runtime representation proof |
| `SH-ART-008` VFX language | **SUBSTANTIALLY CLOSED AT DOCTRINE LEVEL** | `docs/154` §23; `docs/156` §15 | full effect manifest and later performance/accessibility evidence |
| `SH-ART-009` region asset manifests | **OPEN / STARTER CREATED** | `docs/156` §11 | detailed quoteable asset/content manifests per region |
| `SH-ART-010` world scale/reference metrics | **INTENTIONALLY OPEN / DEPENDENCY-BOUND** | `docs/156` §10 | requires Neris scale + camera/traversal representation and later human/runtime evidence |

No row should be marked closed merely because a mood board exists.

---

# 4. Studio decision-rights for art

## LOCKED — implement, do not redefine

- Playable Fantasy Illustration doctrine.
- readability over graphical spectacle;
- landmark/navigation priority;
- each region requires distinct shape language;
- settlements grow from environment and practical life;
- selective detail/material hierarchy;
- no blanket photoreal clutter;
- no generic grimdark visual language;
- Hush cannot be a universal recolor/filter;
- pre-catastrophe places must be visually worth caring about;
- art must honestly communicate authored traversal;
- clean-room reference rules.

## STUDIO CHOICE WITHIN BOUNDS

Subject to later Technical Production Bible and performance/platform authority:

- topology strategy;
- sculpting/modeling package;
- texture-authoring package;
- exact shader implementation;
- exact material graph architecture;
- Nanite use per compatible asset;
- LOD/fallback implementation;
- foliage authoring workflow;
- modular mesh decomposition;
- light authoring workflow;
- source-art organization;
- procedural support tools;
- how the written doctrine is achieved technically.

These choices may not redefine the visible result.

## PROTOTYPE / RUNTIME EVIDENCE

Requires representative implementation before final lock:

- exact internal rendering resolution;
- target scalability tiers;
- triangle budgets where still relevant;
- material complexity budgets;
- texture resolution/memory budgets;
- foliage density;
- shadow/GI cost envelope;
- VFX overdraw/density budgets;
- final fog/atmosphere cost envelope;
- final Hush representation architecture;
- camera-sensitive scale refinements.

## OWNER REVIEW REQUIRED

- material redefinition of the game's overall visual style;
- final Neris appearance;
- major named-character identity if concept work creates materially different directions;
- substantial change from grounded stylization toward photoreal, cartoon, anime, retro-low-poly, cel-shaded, or grimdark aesthetics;
- major branding/iconography direction;
- any proposed visual solution that changes locked story/gameplay identity rather than merely expressing it.

---

# 5. Engine technology boundary

UE5.8 is the engine authority, but no rendering feature is art direction by itself.

Current Epic 5.8 documentation describes Nanite as capable of extremely high geometry detail and automatic fine-grained LOD, while also noting practical performance limits still depend on material complexity, instance counts, output resolution, hardware, and content choices.

Therefore:

> **Stillring may use modern rendering capability without allowing modern rendering capability to define its visual identity.**

A studio must not infer that “modern Unreal game” means mandatory photogrammetry, MetaHumans, maximum texture resolution, maximal vegetation, or every supported renderer feature enabled.

Relevant current reference:

- Epic Games, *Nanite Virtualized Geometry in Unreal Engine 5.8*: `https://dev.epicgames.com/documentation/unreal-engine/nanite-virtualized-geometry-in-unreal-engine`
- Epic Games, *Scalability and the Developer for Unreal Engine 5.8*: `https://dev.epicgames.com/documentation/unreal-engine/scalability-and-the-developer-for-unreal-engine`

Technical-production authority must later turn the selected target hardware/platform into measured budgets.

---

# 6. Reference-board state

## Existing

**Board 01 — Master Art Direction / North Star**

Current concept board exists as a generated visual artifact from the owner/assistant art-direction session.

The board illustrates:

- playable fantasy illustration;
- exaggerated but believable world scale;
- forest settlement integration;
- waterfall/geographic landmark thinking;
- monumental ruins;
- quiet sacred-space treatment;
- character stylization direction;
- material/readability hierarchy.

The board is **DIRECTIONAL**, not independent canon.

A repository binary copy remains pending because current GitHub text actions do not provide a safe binary-image commit path in this work session.

The absence of the image from the repository does not make chat authoritative; `docs/154` records the durable decisions in text.

## Still required

- Board 02 — Regional Shape Language;
- Board 03 — Character Style Band;
- Board 04 — Lighting / Atmosphere / Time;
- Board 05 — Gameplay Readability;
- Board 06 — Representative Benchmark Scene.

See `docs/155_ART_REFERENCE_METHOD_AND_BOARD_INDEX.md`.

---

# 7. Next documentation sequence

Recommended continuation of the art workstream:

1. read all major named-character canon and produce the **Character Production Manifest**;
2. read combat/encounter/boss authority and produce the **Enemy / Boss Art Manifest**;
3. build detailed **Region Environment / Prop Manifests** from canonical region files;
4. produce **Regional Color / Material / Lighting Scripts**;
5. produce the **Hush Visual Production Matrix**;
6. produce the **VFX Production Manifest**;
7. create the visual board set in parallel with those written contracts;
8. defer exact numeric scale/performance budgets until the dependencies are real;
9. update global authority/supersession/onboarding indexes once the art package is reviewed as a complete closure unit;
10. only then mark relevant `SH-ART-*` rows closed.

---

# 8. Art-workstream acceptance condition

The art workstream is studio-handoff-safe when an external art director/lead can answer from repository authority:

- what Stillring should look like;
- why it looks that way;
- how each region differs;
- how characters are stylized;
- how Neris must read;
- how Hush transformation works visually;
- how gameplay affordances remain honest;
- what asset families exist;
- which assets are reusable versus unique;
- what quality is expected at each production stage;
- which decisions are theirs;
- which decisions require owner review;
- which decisions require runtime evidence;
- what references may and may not be copied;
- what volume of art work must be staffed.

The current package materially improves the first eleven questions but does **not** yet close the full volume/manifests requirement.

That remaining work is visible and bounded rather than hidden in chat history.