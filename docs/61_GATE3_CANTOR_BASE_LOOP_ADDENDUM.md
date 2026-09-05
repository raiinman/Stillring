# 61 — Gate 3 Cantor Base Interaction / Diagnostic Loop Addendum

**Status:** LOCKED — scheduled-run owner delegation  
**Issue:** #115 — Gate 3 Cantor Key and field-tool prototype system  
**Decision:** #2 — Cantor Key base interaction / targeting / diagnostic loop

## Decision

The Cantor Key uses a **deliberate point-and-listen diagnostic loop**, not an omnidirectional scan pulse, permanent detective-vision mode, treasure radar, or automatic solution highlighter.

Core philosophy:

> **Ask the world a question. Do not ask the interface for the answer.**

The player deliberately presents the Key toward a visible object or local field, receives an honest resonant response, stabilizes that response into a focused diagnostic target when useful, and only then proceeds to pattern selection/tuning on compatible authored relationships.

## Base loop

### 1. Present / Listen
A dedicated remappable Cantor input invokes a short **Listen** request using the player's current camera/view intention.

Listen samples a bounded forward diagnostic region rather than the entire room. It may consider:
- a directly viewed discrete diagnostic target;
- a small cluster of visible compatible candidates near the view focus;
- a local authored resonance field when there is no single object to select.

Listen must not reveal unseen objects through ordinary opaque world geometry merely because they are nearby.

### 2. Response
The Key returns one of a small number of semantic results:
- **clear compatible response** — one candidate can be focused;
- **ambiguous response** — multiple plausible relations are present and the player must refine view/position or use later patterns/records;
- **readable but not currently actionable** — the Key detects a relation but Neris lacks the applicable pattern/tool/state;
- **no meaningful response** — no authored diagnostic relationship is present;
- **blocked/invalid request** — current gameplay state does not allow a diagnostic action.

These results must be communicated through combined visual/audio/haptic language where applicable, never color alone.

### 3. Focus
When a clear candidate exists, the Key establishes a temporary **diagnostic focus** on that object/field.

Focus is not combat target lock and must not silently change:
- Neris locomotion basis;
- combat target identity;
- camera lock-on state;
- enemy aggression;
- world simulation;
- quest state.

Diagnostic focus is an inspection relationship only.

The player may continue moving and looking unless a later specific tuning interaction explicitly owns input for a short period.

### 4. Inspect relationship
With a focused target, the Key exposes only information the current Key/pattern/history can legitimately establish.

The base Key may communicate things such as:
- that a resonant relationship exists;
- whether the response is stable, drifting, absent, conflicting, or outside known tolerance language;
- which known Cantor Patterns are semantically applicable, if any;
- why an attempted pattern is incompatible when that fact would be apparent to Neris as a trained repairer.

It must not disclose:
- hidden treasure identity;
- quest-solution metadata;
- unseen enemy information;
- the correct puzzle sequence merely because the object is involved in a puzzle;
- privileged future-state truth;
- moral/factual truth beyond the capability of the current pattern.

### 5. Pattern handoff
From a valid diagnostic focus, the existing Cantor wheel / quick pattern selector may be opened.

Known patterns are shown by semantic applicability:
- applicable;
- known but incompatible here;
- unavailable because required observable precondition is missing.

The selector does not invent a solution. It provides the set of procedures Neris actually knows.

Exact selector controls and per-pattern tuning gestures remain later content/tuning authority unless a future focused decision requires them.

### 6. Exit / recover
Diagnostic focus clears immediately when:
- the player cancels;
- the focused relationship becomes invalid;
- range/physical visibility exceeds the authored diagnostic tolerance;
- another higher-priority gameplay state explicitly takes ownership;
- the interaction completes.

Loss of focus is quiet and fast. No long animation or modal exit tax.

## Candidate resolution

### View intent first
Candidate resolution prioritizes what the player is actually looking toward, not nearest-object roulette.

A practical implementation may combine:
- a primary camera/view trace;
- a narrow secondary cone or screen-space neighborhood for forgiving selection;
- explicit diagnostic capability interfaces/tags;
- honest line-of-sight / obstruction tests;
- authored local-field membership.

Exact scoring weights remain implementation tuning, but the semantic order is locked:
1. direct visible view intent;
2. compatible visible candidate near that intent;
3. local field at the intended sample point;
4. otherwise no clear focus.

Distance alone may not make an off-axis object beat the object the player is clearly inspecting.

### No hidden wall scanning
Ordinary opaque world geometry blocks discrete diagnostic acquisition unless a specific later Cantor Pattern explicitly measures through/within structure as its authored function (for example Hollow Measure). That later capability is pattern authority, not a base scanner exception.

### Local fields
A local field is not a magic volume that reveals puzzle state. It represents an authored measurable condition in the immediate world: pressure relation, resonance drift, competing histories, etc.

Field diagnostics must expose observable semantic measurements and stable IDs in the Tool/Puzzle IDE.

## Input and camera boundary

Unreal Engine 5.8 Enhanced Input supports contextual mapping, remapping, triggers, and priority. Stillring may use those facilities to layer Cantor interaction safely, but the engine mapping system does not decide the design.

Locked input principles:
- Cantor Listen is a named remappable action;
- invoking Listen does not automatically halt movement;
- camera remains player-owned during ordinary diagnosis;
- entering diagnostic focus does not recenter or snap the camera;
- combat lock and diagnostic focus are separate identities even if they temporarily refer to the same Actor;
- a combat state may reject or restrict deep tuning later, but ordinary diagnostic request rejection must be explicit rather than silently eating input;
- no precision motion-control gesture is required.

## Combat boundary

The Cantor Key is not a combat scanner that exposes numeric health, hidden weakness tables, future attack selection, or enemy AI state to the retail player.

If a known authored Cantor interaction later applies to combat pressure, it must obey Gate 2 action legality and encounter readability.

Diagnostic focus may coexist with a combat target only when the specific action remains readable and does not create target-lock ambiguity. Exact combat-tool integration belongs to later Gate 3 decisions.

## Accessibility / readability

Required:
- compatible response has shape/audio/state cues in addition to color;
- captions/text equivalents exist for meaningful audio-only diagnostic distinctions where practical;
- haptic feedback is supplemental, never required;
- response duration is long enough to perceive without requiring reflex timing;
- no repeated rapid scan cadence is necessary to retain ordinary information;
- pattern names and diagnostic states use plain semantic labels rather than waveform-only UI;
- camera effects remain restrained and reducible;
- failure reason is surfaced when the player reasonably expected a response.

## Anti-radar rules

The base Cantor Key must not:
- paint every interactable in a room;
- pulse icons through walls;
- continuously outline all future-use objects;
- reveal completion collectibles by proximity;
- auto-tag the correct object because it advances the current objective;
- keep a permanent minimap/database marker merely because Listen touched something;
- require routine scan-spam every few seconds while traversing.

A successful environment should remain legible without the Key. The Key deepens understanding of authored relationships; it does not compensate for unreadable art/level design.

## Comparative design research

### Metroid Prime — useful lesson, bounded adoption
Nintendo's current *Metroid Prime Remastered* material describes the Scan Visor as a selectable interface for investigating objects/enemies and interacting with world information. That demonstrates the value of **deliberate analytical attention**: the player chooses to inspect something rather than receiving all information passively.

Stillring does not copy the first-person visor presentation, scan cursor, scan duration, database/logbook structure, enemy-weakness behavior, or controls.

### Modern terrain scanners — explicit rejection
Sony's current *Death Stranding 2* guide describes a terrain scanner that pings routes, hazards, and enemy-carried cargo. That is useful for traversal readability in its own game, but it highlights the exact failure mode Stillring wants to avoid: a broad utility ping becoming the routine way to discover what matters.

Cantor therefore narrows diagnostic scope to deliberate view intent and authored relationships.

## Engine feasibility boundary

Current UE5.8 primitives support the implementation without owning the policy:
- Enhanced Input for named/remappable/contextual actions;
- collision traces for view-intent sampling;
- Gameplay Tags or equivalent explicit semantic capability data;
- C++ interfaces/services for authoritative diagnostic compatibility and rejection reasons.

A raw trace hit is never sufficient authority for "this is a Cantor target." Collision response, render visibility, or an Actor class name may support candidate discovery, but semantic compatibility must come from authoritative gameplay data.

## Tool / Puzzle System IDE contract created by Decision #2

### Inspect
Expose:
- raw Listen request time/source;
- camera/view origin and intended sample direction;
- primary trace result;
- nearby diagnostic candidates considered;
- candidate compatibility tags/interfaces;
- visibility/obstruction state;
- candidate score/reason hierarchy;
- selected diagnostic focus ID;
- local field ID if any;
- semantic response state;
- currently applicable known patterns;
- rejection reason;
- current combat target separately from diagnostic focus.

### Exercise
Named fixtures:
- one obvious discrete target;
- two adjacent compatible targets requiring view refinement;
- compatible target behind opaque wall;
- local field with no discrete target;
- readable-but-not-actionable target;
- empty ordinary scenery;
- combat target that is also diagnostically readable;
- camera-compressed/cramped diagnostic case.

### Validate
Catch:
- through-wall base acquisition;
- objective metadata influencing candidate score;
- color-only response state;
- diagnostic focus mutating combat target;
- stale focus after target destruction/reset;
- unknown pattern shown as known/applicable;
- hidden retail information leaking from IDE/debug state.

### Capture
Record one deterministic Listen transaction: request → candidates → rejection/selection reasoning → focus → pattern applicability → exit.

## IP boundary

No exact scan UI, visor presentation, controller mapping, sounds, scan timing, target-reticle graphics, database language, or puzzle interaction from another game is adopted.

The protected Stillring expression is the Cantor Key as a repairer's instrument that **measures resonant relationships and applies learned operational procedures**.

## Locked statement

> **The Cantor Key is point-and-listen diagnosis: deliberate view intent produces an honest local resonant response, temporary diagnostic focus, and access to procedures Neris actually knows—never omnidirectional detective vision or solution radar.**

## Research basis

Primary/current technical sources:
- Epic Games — Unreal Engine 5.8 Enhanced Input documentation.
- Epic Games — Unreal Engine 5.8 Line Trace by Channel documentation.
- Epic Games — Unreal Engine 5.8 Gameplay Tags documentation.

Comparative shipped-game sources:
- Nintendo official *Metroid Prime Remastered* material describing deliberate Scan Visor investigation.
- PlayStation official *Death Stranding 2: On the Beach* guide describing broad terrain-scanner ping utility; used as a contrast case.

Repository authority:
- `docs/13_CANTOR_AND_UPGRADE_CATALOG.md`
- `docs/09_STILLRING_PROGRESSION_BLUEPRINT.md`
- `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`
- `docs/60_GATE3_TOOL_SELECTION_ADDENDUM.md`
- Gate 1 movement/camera authority
- Gate 2 player/enemy/encounter authority

## Next decision

**Gate 3 Decision #3 — Anchor Line base physical verb and compatible-target contract.**
