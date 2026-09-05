# 17 — Zelda Design Lineage and Player-Control Principles

**Status:** design-lineage / reasoning authority  
**Updated:** 2026-09-04  
**Purpose:** preserve the design problems and principles Project Stillring learns from the Zelda lineage without freezing the project at 1998 controls or copying protected expression.

This document exists because:

> **Ocarina of Time is a root reference, not the 2026 control ceiling.**

Detailed implementation-facing Gate 1 locomotion behavior is **not duplicated here**. It lives in `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`. Camera behavior remains Issue #2 authority.

`docs/05_IP_GUARDRAILS.md` remains binding. Stillring does not copy exact movement speeds, animation timing, camera distances, input layouts, traversal geometry, visual indicators, enemy behavior, code, assets, music, dialogue, or other protected expression.

---

## 1. What Ocarina of Time actually contributed

The useful lesson from **The Legend of Zelda: Ocarina of Time** is not “remove the jump button because Zelda did.”

The deeper lessons are:
- reduce unnecessary friction in 3D navigation;
- let players express intention without demanding precision for ordinary biomechanics;
- give character, camera, and target a shared readable relationship during combat;
- make target-lock movement legible rather than letting character orientation, camera orientation, and attack direction fight each other;
- coordinate encounter aggression with what the player and camera can reasonably read;
- judge controls by how quickly players stop thinking about operating the character and start thinking about the world.

Nintendo's original developers described auto-jump as a deliberate response to the action difficulty of early 3D controls, and Z-targeting as a solution to alignment/camera/combat readability.

**Stillring conclusion:** preserve the problem-solving philosophy, not the obsolete hardware compromise.

---

## 2. What later Zelda games improved

### Wind Waker — free camera becomes player ownership

The move to a freely controllable exploration camera established that camera control itself can be part of player agency rather than a system the player constantly negotiates with.

**Stillring conclusion:** exploration uses modern free camera ownership. Recenter is convenience, not replacement. Exact camera behavior remains Issue #2.

### Skyward Sword — movement flow matters

Dash/scramble ideas reinforced that travel friction should exist because the world asks something meaningful, not because ordinary movement arbitrarily interrupts itself.

**Stillring conclusion:** movement flow matters. Ordinary travel Sprint therefore exists as a sustained, no-stamina locomotion state rather than a periodic resource tax or a second combat dodge.

### Breath of the Wild — terrain becomes a route decision

Expanded traversal made terrain part of player reasoning rather than only corridor boundary.

**Stillring conclusion:** players should frequently be able to see a destination, form a route hypothesis, and act on readable world geometry. Stillring does **not** need universal climbing to gain that agency.

### Tears of the Kingdom — affordance honesty

A strong modern lesson is that when the world reasonably suggests an action should work, the game should honor that expectation or communicate the exception clearly.

**Stillring conclusion:** art, geometry, collision, state, and gameplay rules must agree.

If something looks reasonably:
- mantleable,
- breakable,
- movable,
- hookable,
- climbable,
- resonant,
- traversable,
- interactable,

then either the expected action should work or the reason it does not should be understandable from the world.

Invisible arbitrary eligibility is a design failure, not “difficulty.”

---

## 3. Stillring synthesis

The governing player-control principle is:

> **Simple intention, capable character, honest world.**

The player should spend attention on:
- where to go;
- what the environment means;
- what an enemy is doing;
- which route/tool solves a problem;
- what changed in the world;

not on fighting basic character locomotion.

Ordinary biomechanics should disappear beneath intention wherever doing so does not erase meaningful traversal choices.

That means:
- stairs and tiny floor lips simply work;
- low obvious obstacles do not demand a redundant context button;
- a clearly intended reachable ledge does not demand a frame-perfect extra grab input;
- dangerous release is explicit rather than inferred from ambiguous analog correction;
- deliberate release cannot be immediately undone by the same traversal detector;
- ordinary unsupported edges obey deliberate movement intent rather than secretly auto-braking;
- interaction can flow from movement without magnetic snapping;
- animation communicates weight without delaying valid input acknowledgement;
- hardware drift is filtered before it becomes movement/traversal intent;
- target lock changes movement reference for precision but does not secretly choose combat spacing;
- a committed target-lock jump keeps a stable movement language through the air rather than reinterpreting held input when lock disappears;
- accessibility may reduce input burden without changing puzzle geography.

This is **not** the same as making traversal automatic. Important commitments remain player-owned.

---

## 4. Authored traversal progression remains central

Stillring is not trying to become Breath of the Wild, Tears of the Kingdom, or Assassin's Creed.

The world is interconnected and exploratory, but movement progression remains authored.

A desired Stillring experience is:
1. the player sees a meaningful inaccessible place;
2. the obstacle is understandable;
3. the player remembers it;
4. a later route, structure, tool, or capability changes what is possible;
5. the old place becomes newly legible;
6. returning feels like mastery rather than checklist cleanup.

Therefore:
- universal climb-everything traversal is not baseline;
- ordinary rough walls/cliffs do not become climbable merely because they look physically grippable;
- baseline ledge movement stays local rather than silently expanding into corner/gap/vertical free climbing;
- underwater free-diving is not baseline access;
- future traversal tools/capabilities may be powerful, but their movement authority must be explicit, authored, state-bounded, and visually honest;
- restrictions must still obey affordance honesty.

The modern-Zelda lesson is **player trust and agency**, not removal of authored progression.

---

## 5. Current Gate 1 locomotion authority

The full semantic movement grammar has been worked through, repository-reconciled, and **final-owner-approved** in `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`. Issue #1 records the completed design/review process; Claude is not expected to invent missing locomotion policy during implementation.

High-level locked areas now include:
- camera-relative analog ground movement with useful careful control;
- ordinary unsupported-edge commitment with no invisible cliff guard;
- unlimited explicit-request Sprint, separate from combat evade;
- predictable modest deliberate jump with limited air correction plus short baseline coyote/buffer forgiveness;
- intent-based automatic low-obstacle mantle;
- reachable ledge catch → real hang → same-handhold shimmy → valid pull-up or explicit Drop/Release;
- deliberate ledge/ladder release suppression against immediate same-attachment re-catch/remount;
- no baseline universal/free climbing;
- player-driven authored ladders with deliberate intent-based mounting, safe end exits, and explicit release;
- competent surface swimming with no stamina/breath tax and no baseline free underwater diving;
- no generic baseline crouch/stealth posture;
- ordinary/borderline/steep slope bands with limited scramble/slide behavior;
- safe ordinary traversal falls, proportional consequence above the safe envelope, and no landing-input exploit;
- interaction overlap that avoids both standstill friction and magnetic snapping;
- explicit state contracts for future traversal-tool overrides;
- radial movement-stick dead zones, drift protection, analog speed bands, Sprint hysteresis, and digital diagonal normalization;
- immediate intention acknowledgement with speed-dependent physical weight;
- target-relative lock-on locomotion with player-owned spacing and no auto-orbit/autopilot;
- stable target-relative airborne correction for target-lock jumps, including frozen last-valid frame if lock disappears before landing;
- remapping, Hold/Toggle Sprint, Digital Precision, and other locomotion-facing accessibility rules that do not change authored traversal eligibility.

This list is a **summary**, not a second implementation specification. If this file and `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` ever disagree on locomotion behavior, reconcile the files; do not let Claude select whichever wording is convenient.

---

## 6. Tuning is not design authority

The semantics are locked, but Gate 1 human play still tunes numeric/animation details such as:
- movement and Sprint speeds;
- acceleration/braking/rotation curves;
- Sprint engage/disengage magnitudes;
- jump height/arc and air influence;
- coyote and input-buffer windows;
- mantle angle/dimension calibration tied to Neris's body scale;
- ledge reach/catch/shimmy/clearance tolerances;
- same-attachment release-separation thresholds;
- ladder speed/alignment/cadence;
- swim speed/drag/turn response;
- slope angles/traction/slide authority;
- safe/damaging fall thresholds and recovery timing;
- local interaction-alignment tolerances;
- target-lock speed/directional multipliers.

Changing one of these values is legitimate tuning only while the locked behavior class remains intact.

Examples of **semantic failures**, not tuning:
- analog down releases a ledge;
- Sprint adds a jump speed boost;
- passing near a ladder mounts it;
- shoulder-height geometry silently becomes ordinary auto-mantle;
- an ordinary unsupported edge invisibly blocks deliberate walk-off;
- deliberate Drop instantly re-catches/re-mounts the released attachment;
- target-lock loss changes the meaning of held air correction mid-jump;
- target lock auto-orbits or maintains distance;
- a blocked water edge magnetically pulls Neris out;
- controller drift triggers traversal;
- repeated state transitions manufacture height/speed;
- accessibility settings increase traversal reach.

---

## 7. Animation contributes to responsiveness

Physical weight is allowed; delayed intention acknowledgement is not.

Prototype/animation work must respect:
- start/stop transitions;
- direction reversals;
- run/Sprint changes;
- jump/landing transitions;
- mantle and ledge-catch/hang transitions;
- hang/pull-up/shimmy/release transitions;
- ladder attach/dismount/release;
- swim entry/exit;
- slide/recovery;
- interaction alignment;
- Sprint→target-lock and unlock transitions.

Gameplay locomotion owns ordinary trajectory/state. Animation presents that movement and may use weight/lean/pivots/footwork to sell it, but it may not create hidden control lock or opaque root-motion delay that contradicts `docs/20_GATE1_LOCOMOTION_SPECIFICATION.md`.

---

## 8. Five-minute control test

The old insight that players should quickly stop thinking about controlling a 3D character remains a modern Stillring acceptance rule:

> **Within roughly five minutes, ordinary movement should stop being something the player consciously operates.**

`docs/20_GATE1_LOCOMOTION_SPECIFICATION.md` defines the canonical representative graybox course, five-minute-per-input-profile script, hard-fail conditions, tuning-versus-semantic-failure distinction, and required human verdict questions.

Human play is authoritative. A green build/test suite cannot overrule “this feels slippery,” “this feels magnetic,” “I am fighting the controls,” or another material owner feel failure.

The test is a regression gate after material changes to movement physics, collision, traversal detection, movement animation/root motion, Enhanced Input, target-lock movement, or route geometry.

---

## 9. Camera boundary

Locomotion authority does not silently finish camera design.

Issue #2 still owns:
- exploration camera geometry and recenter behavior;
- camera collision;
- look-stick/mouse response and camera accessibility;
- target-lock framing and target-selection presentation;
- lock-loss/reacquisition presentation;
- combat-camera readability.

Locomotion may specify when movement changes reference/state; camera authority specifies how that state is framed and controlled visually.

---

## 10. Research sources

Primary/official sources used for this design-lineage conclusion:

### Ocarina of Time — auto-jump and Z-targeting
- https://iwataasks.nintendo.com/interviews/3ds/zelda-ocarina-of-time/1/1/
- https://iwataasks.nintendo.com/interviews/3ds/zelda-ocarina-of-time/1/2/
- https://iwataasks.nintendo.com/interviews/3ds/zelda-ocarina-of-time/4/4/
- https://iwataasks.nintendo.com/interviews/3ds/zelda-ocarina-of-time/0/3/

### Wind Waker — free camera lineage
- https://iwataasks.nintendo.com/interviews/3ds/majoras-mask-3d/0/4/

### Skyward Sword — dash and movement flow
- https://iwataasks.nintendo.com/interviews/wii/zelda-skyward-sword/0/1/

### Breath of the Wild / Tears of the Kingdom — world agency and affordance honesty
- https://www.nintendo.com/jp/topics/article/c1fb9037-03c1-11e7-9aaf-063b7ac45a6d
- https://www.nintendo.com/us/whatsnew/ask-the-developer-vol-9-the-legend-of-zelda-tears-of-the-kingdom-part-3/
- https://www.nintendo.com/us/whatsnew/ask-the-developer-vol-9-the-legend-of-zelda-tears-of-the-kingdom-part-5/

Secondary movement-lineage research:
- `docs/19_ASSASSINS_CREED_MOVEMENT_LINEAGE_RESEARCH.md` — research input only, never design authority by itself.

These sources extract design problems/evolution. They are not implementation specifications for Stillring.
