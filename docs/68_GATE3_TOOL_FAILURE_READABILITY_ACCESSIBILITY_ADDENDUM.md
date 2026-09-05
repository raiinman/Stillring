# 68 — Gate 3 Tool Failure / Readability / Accessibility / Anti-Keycard Contract

**Status:** LOCKED — scheduled-run owner delegation  
**Issue:** #115  
**Decision:** #9

## Decision

Gate 3 tools must fail **quickly, semantically, recoverably, and without hiding the reason**, while preserving the world's need to be read rather than converted into scanner outlines and glowing keyholes.

> **Failure should teach the relationship, not punish the input.**

## Semantic failure classes

Cantor and Anchor requests resolve into explicit classes rather than generic “nothing happened.”

Representative classes:
- no candidate / ordinary scenery;
- compatible but out of range;
- compatible but obstructed;
- compatible but current state blocks action;
- incompatible response family;
- missing known procedure/precondition;
- ambiguous diagnostic relation;
- load direction invalid;
- mechanism at constraint/length limit;
- active tool ownership conflict;
- traversal arrival invalid;
- combat action state rejects request;
- world/reset invalidated the endpoint.

Retail presentation need not expose programmer enum names, but the player-facing response and System IDE must map to the same authoritative cause.

## Fast failure

Invalid requests must avoid expensive fake commitment.

Defaults:
- no long firing/retraction animation for an obviously invalid Anchor target;
- no multi-second Cantor scan on ordinary scenery;
- no resource loss for a request rejected before meaningful action begins;
- no camera snap, movement change, or combat-target change on failure;
- Reclaim/Cancel stays immediate when cleanup is safe;
- local puzzle reset is available where authored machinery can genuinely deadlock.

A meaningful committed action can still have consequence. “Recoverable” does not mean every mistake is instantly rewound; it means the player can understand and re-enter the problem without unrelated replay tax.

## Readability layers

Tool readability uses three layers.

### World layer — first
The environment itself should communicate:
- maintenance/load hardware;
- moving constraints/tracks/hinges;
- tension and deformation;
- component attachment;
- resonant/mechanical activity;
- obvious physical obstruction.

### Tool-ready layer — confirmation
When the relevant tool is selected/readied, restrained cues may confirm:
- eligible candidate;
- state-blocked candidate;
- active focus/latch;
- load/diagnostic status;
- brace/traversal eligibility.

These cues should not permanently paint every future interaction across the room.

### Interface explanation layer — when needed
For ambiguous/rejected interactions, concise accessible feedback may state practical reasons such as:
- “Path blocked.”
- “No purchase.”
- “Load fixed.”
- “Cannot hold another brace.”
- “Relation unclear.”
- “Procedure unknown.”

Exact copy is localization/UI work; the semantic reason is locked.

## Multimodal communication

Critical tool states cannot rely on color alone.

Use combinations of:
- shape/icon state;
- line/reticle geometry;
- motion/pulse pattern;
- audio texture/pitch/rhythm where appropriate;
- optional haptics;
- concise text/caption equivalent for important diagnostic distinctions.

Haptics and stereo/spatial audio are supplemental. Their absence cannot block understanding.

## Input accessibility

Current Microsoft/Xbox accessibility guidance explicitly flags rapid sequences, simultaneous combinations, long holds, and incomplete remapping as barriers. Gate 3 adopts the underlying accessibility principles without making platform certification language itself game design authority.

Required:
- all gameplay tool actions are remappable;
- no mandatory simultaneous button chord for Cantor/Anchor synthesis;
- no QTE-style repeated rapid presses for reeling, tuning, or release;
- no precision motion gesture required;
- sustained digital holds used for meaningful tool actions must have an optional toggle/press-based alternative where practical;
- remapped action labels propagate to prompts/tutorials;
- controller and mouse/keyboard receive equivalent semantic actions, not one “real” implementation plus a crippled fallback.

Analog nuance may improve feel, but core success cannot require pressure-sensitive trigger precision unless a digital alternative exists.

## Candidate assistance

Accessibility may increase:
- screen-space candidate forgiveness;
- target stickiness stability;
- cue scale/contrast;
- response dwell duration;
- puzzle timing windows;
- explanatory feedback detail.

It may not:
- select through walls;
- make an incompatible target compatible;
- reveal objective/solution metadata;
- create additional Anchor braces;
- bypass combat action legality;
- change physical puzzle invariants.

Assistance reduces input/perception barriers; it does not solve the reasoning problem.

## Timing accessibility

Base puzzles should not depend on tight timing. Where a physically legible timed mechanism is justified:
- timing can be lengthened through accessibility settings or difficulty/tuning policy;
- mechanism causality remains the same;
- failure is quick to retry;
- no single tiny reaction window gates critical progression unless an equivalent alternative exists.

Combat remains real-time under Gate 2; Tool usage within combat must respect that authority rather than pausing the world by default.

## Anti-keycard rules

A production review must reject tool content whose essential logic is any of the following:
- “this socket accepts Anchor because it is the Anchor socket”; 
- “this object responds to Cantor because the quest says it is important”; 
- “use the newly acquired tool on the matching icon to open the door”; 
- “all interactables glow until cleared”; 
- “scan until the UI marks the right object”; 
- “correct item/tool combination bypasses an otherwise unexplained mechanism.”

A valid tool gate instead requires a semantic capability the player can understand:
- a load can now be tensioned/braced/released;
- a relation can now be measured/procedurally adjusted;
- a fixed traversal load point enables a short route;
- an exposed component can now be physically manipulated.

Tool-gated progression is allowed. Arbitrary item-key matching is not.

## Anti-scan-spam rules

Cantor must remain useful without becoming a compulsive room ping.

Production review should flag:
- progression-critical objects visually indistinguishable from clutter unless scanned;
- repeated Listen needed just to retain ordinary target information;
- collectible/objective radar disguised as resonance;
- broad through-wall acquisition not owned by a specific Pattern;
- environments designed unreadably because “the player can scan.”

The Key answers deliberate questions. It does not replace observation.

## Cognitive readability

The system should build a small stable vocabulary and reuse it.

Prefer:
- consistent state terms;
- consistent cue families;
- visible mechanical causality;
- short explanations tied to the player's current request;
- reviewable known Cantor procedures.

Avoid:
- dozens of one-off socket symbols;
- hidden recipe permutations;
- undocumented tool pairings;
- arbitrary exceptions to already-learned load/diagnostic rules.

## Failure persistence / reset

On Death/retry/world reset:
- handheld Anchor relationships clear;
- static brace restoration follows authoritative checkpoint/world state rather than stale runtime ownership;
- Cantor diagnostic focus clears;
- temporary tuning/session action state clears;
- persistent puzzle/world changes restore exactly according to save/world-state authority;
- no tool subsystem retains stale references to destroyed/restored actors.

Fixture-local reset may restore a test/puzzle baseline without touching unrelated story state.

## Accessibility test profiles

Gate 3 human/IDE verification must include at minimum:
- controller default;
- mouse/keyboard;
- fully remapped actions;
- reduced candidate precision requirement;
- toggle/press alternative for sustained tool hold where enabled;
- color-vision-independent cue review;
- audio reduced/off review for visually communicated critical states;
- haptics off;
- expanded puzzle timing;
- camera assistance reduced/off where relevant.

Passing default controls alone is not sufficient.

## Comparative research boundary

Portal 2's official description explicitly frames advanced physics as enabling a broader range of challenges rather than simply harder input execution. Stillring takes the generic lesson that systemic puzzle complexity should come from reasoning, not increasingly awkward control demands.

No Portal presentation, chamber language, mechanics, or control scheme is copied.

## Tool / Puzzle System IDE

### Inspect
Expose:
- last request;
- authoritative failure/rejection code;
- player-facing semantic feedback key;
- candidate assistance settings affecting selection;
- active input mapping/device;
- hold/toggle mode;
- cue channels currently active;
- timing accessibility multiplier/mode where applicable;
- reset ownership/baseline.

### Validate
Automated/data validation should catch:
- missing failure reason for rejectable action;
- critical cue marked color-only/audio-only/haptic-only;
- non-remappable required tool action;
- mandatory simultaneous combo chord;
- repeated-mash mechanic;
- puzzle solution keyed directly to objective metadata;
- identical semantic targets with unexplained divergent compatibility;
- through-wall base Cantor acquisition;
- accessibility assistance altering semantic compatibility;
- stale tool state across reset/death.

### Capture
Every failed interaction capture should contain:
request → candidate/context → authoritative rejection reason → presented feedback channels → recovery/next valid state.

## Locked statement

> **Stillring's tools may be demanding to understand, but they must not be demanding because the input is inaccessible, the feedback is vague, or the world is a disguised set of colored keyholes.**

## Research basis
- Microsoft/Xbox Accessibility Guideline 107 and current accessibility feature criteria for remapping, digital alternatives, holds, input speed, and simultaneous-input barriers.
- Portal 2 official product description as a generic reasoning-over-input-complexity comparison.
- `docs/60`–`docs/67` Gate 3 authority.
- `docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`.

## Next decision

**Gate 3 Decision #10 — Tool/Puzzle IDE fixture, reset, capture, and cumulative Gate 3 closure.**
