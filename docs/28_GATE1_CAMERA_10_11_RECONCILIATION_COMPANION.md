# 28 — Gate 1 Camera Decisions #10–#11 Reconciliation Companion

**Status:** CUMULATIVE CAMERA AUTHORITY / TEMPORARY COMPANION TO `docs/22`  
**Updated:** 2026-09-05  
**Scope:** ordered reconciliation of already-owner-approved Camera Decisions #10 and #11. This file introduces no new camera policy.

## Why this companion exists
`docs/22_GATE1_CAMERA_SPECIFICATION.md` is the implementation-facing cumulative camera specification through Decision #9. Decisions #10 and #11 were subsequently locked in `docs/26_GATE1_CAMERA_LOCK_ACQUISITION_ADDENDUM.md` and `docs/27_GATE1_CAMERA_LOCK_FRAMING_ADDENDUM.md`.

The current connector can safely create/review a narrow text companion but cannot safely patch sections into the very large `docs/22` without replacing the entire file. To avoid corrupting or truncating settled camera authority, this document performs the ordered reconciliation as a temporary cumulative extension.

Implementation-facing cumulative authority is therefore, in order:
1. `docs/22_GATE1_CAMERA_SPECIFICATION.md` — Decisions #1–#9;
2. this file — reconciled Decisions #10–#11 summary and ordering;
3. `docs/26_GATE1_CAMERA_LOCK_ACQUISITION_ADDENDUM.md` — full Decision #10 provenance/detail;
4. `docs/27_GATE1_CAMERA_LOCK_FRAMING_ADDENDUM.md` — full Decision #11 provenance/detail.

When a normal git workspace is available, fold the two sections below into `docs/22` mechanically and retire this companion. Until then, this file is cumulative authority and the provenance addenda remain authoritative for full detail.

---

## 10. Lock-on acquisition transition — LOCKED

Stillring uses **immediate target commitment with deliberate camera convergence**.

- one lock request evaluates the current candidate set once;
- candidate order is eligibility → honest current visibility → camera/screen intent → distance refinement → deterministic tie-break;
- camera/view intent normally outranks character facing or simple nearest-enemy selection;
- initial acquisition does not select a hard-cover target or surprise the player with an extreme behind-the-view lock;
- once a valid target wins, target identity and target-relative locomotion commit immediately;
- active Sprint exits through the already-approved natural deceleration/pivot rather than hard-zeroing;
- camera convergence begins from the exact current valid camera pose with no hidden recenter;
- the camera uses one fast, bounded, eased transition toward the valid established-lock composition;
- no hard snap, slow cinematic pan, freeze, slowdown, FOV punch, micro-cutscene, or facing-animation gate;
- a failed request has no camera, movement, Sprint, or pending-search side effects;
- target invalidation/cancel aborts cleanly from the current camera pose;
- once committed, another candidate never silently steals the lock;
- Decisions #5/#6/#7/#8 remain physical/occlusion authority throughout.

Philosophy:
> **Lock the target instantly. Move the camera deliberately.**

Full provenance, IDE requirements, test matrix, rejection cases, and tuning boundaries remain in `docs/26_GATE1_CAMERA_LOCK_ACQUISITION_ADDENDUM.md`.

---

## 11. Lock-on framing distance / offset philosophy — LOCKED

Established ordinary lock-on uses a **dual-subject Relationship Frame**.

- frame Neris, the locked target, and useful combat space between them;
- do not hard-center the target or convert ordinary lock-on to a permanent shooter shoulder;
- Neris and target use tuning-defined ideal/dead/soft/hard screen-space regions so tiny motion does not move the camera;
- ordinary lock uses a canonical medium combat distance with modest, capped separation-driven dolly;
- distance changes use dead band, damping, and hysteresis to prevent accordion breathing;
- ordinary combat FOV remains essentially stable;
- camera adaptation is visual only and never maintains player↔target gameplay spacing;
- moderate target-above/below relationships may recompose/pitch while preserving Neris and footing readability;
- noisy skeletal animation is not automatically camera-worthy;
- while locked, the player retains bounded manual composition nudge, but not full exploration free orbit;
- exact coexistence between manual nudge and target switching is explicitly owned by Decision #12/#17;
- Decisions #5/#6/#7/#8 remain physical/occlusion authority;
- secondary-enemy framing remains #13 and large-boss framing remains #14.

Philosophy:
> **Frame the relationship, not the reticle.**

Practical test:
> **Show Neris. Show the threat. Show the space between them.**

Full provenance, IDE requirements, test matrix, rejection cases, and tuning boundaries remain in `docs/27_GATE1_CAMERA_LOCK_FRAMING_ADDENDUM.md`.

---

## Reconciliation result
Camera Decisions #1–#11 are now cumulatively ordered and implementation-readable without changing any approved semantics.

Decision #12 may now be researched and, after its own complete research/approval pass, documented as the next camera authority.
