# 63 — Gate 3 Anchor Line Targeting / Input / Cancel / Recovery Addendum

**Status:** LOCKED — scheduled-run owner delegation  
**Issue:** #115  
**Decision:** #4

## Decision

Anchor Line uses **view-intent targeting, forgiving candidate selection, no camera snap, one stateful primary tool action, and one universal reclaim/cancel action**.

> **Aim with the camera. Commit with the tool. Get out instantly when the relationship is wrong.**

## Targeting

When Anchor Line is selected/readied, candidate acquisition uses the player's current view intent.

Priority:
1. directly viewed compatible load point;
2. compatible visible point inside a small forgiving screen-space cone;
3. otherwise no candidate.

Selection must not:
- snap the camera;
- rotate Neris automatically;
- steal combat target identity;
- choose a nearer off-axis target over the clearly viewed one;
- select through hard blocking geometry;
- use quest relevance as hidden priority.

Candidate stickiness may suppress flicker while the player is already clearly aiming at one point, but it must release quickly when view intent changes.

## Input grammar

All actions are named/remappable Enhanced Input actions or equivalent semantic actions.

### Primary Tool Action
Stateful meaning:
- **Ready + valid candidate:** latch Anchor Line.
- **Ready + no candidate:** readable dry failure; no movement/camera side effect.
- **Latched handheld line:** hold/continue Primary to take up slack and apply tension.
- **Loaded constrained relationship:** continued Primary maintains the requested tension action within target limits.

Releasing Primary stops increasing requested tension. The relationship may remain latched/slack/held according to semantic target state; release of the button is not an accidental detach.

Exact actuation thresholds/timing remain tuning.

### Set Brace
A separate named/remappable **Set Brace** action is available only when:
- one handheld Anchor relationship is valid;
- the current relationship is eligible for static bracing;
- a valid authored brace/cleat endpoint is available;
- current gameplay state permits the transfer.

Set Brace transfers source ownership from Neris to the valid brace endpoint and commits the single base static brace.

It never chooses an arbitrary nearby wall or generic surface.

### Reclaim / Cancel
A universal named/remappable **Reclaim Anchor** action:
- releases/reclaims a handheld line immediately;
- if no handheld line exists and one static brace exists, reclaims that brace;
- clears pending Anchor targeting/commit state;
- never changes combat target or camera state.

Reclaim is deliberately reliable and low-friction. It is not gated behind a long hold.

Death, retry, fixture reset, destroyed endpoints, or authoritative world unload perform equivalent forced cleanup regardless of player input.

## Obstruction behavior

Hard geometry blocks effective tension immediately.

A latched line may remain attached for a short tunable obstruction grace while effective force is zero, allowing the player to step back into a clear load path without unnecessary relatching.

If obstruction persists beyond grace, or endpoint validity is lost, the line auto-reclaims with a readable reason.

No force acts through the obstruction during grace.

No dynamic rope wrapping is inferred.

## Range behavior

- Candidate latch requires target inside authored Anchor acquisition range.
- Existing line has a separate authored working-length envelope.
- Reaching max working length does not teleport/pull harder; tension request clamps and exposes `AtLengthLimit`.
- Leaving valid range through target/world motion may enter a brief readable invalidation grace before reclaim if physically plausible.

Exact numbers remain prototype tuning.

## Combat/action-state legality

Anchor requests pass through authoritative gameplay-state legality like other actions.

The tool does not bypass Gate 2 commitment rules because the input was pressed.

A rejected Anchor request must report a semantic reason such as:
- current committed action;
- traversal ownership;
- hard stagger/death;
- incompatible target state;
- blocked load path;
- another Anchor relationship already owns the tool.

Decision #6 owns the exact combat windows where Anchor pressure is legal.

## Camera behavior

- no automatic recenter;
- no FOV punch;
- no shoulder-camera takeover;
- no aim zoom required;
- no camera steering toward latched endpoint;
- player orbit remains authoritative except existing physical camera constraints;
- target indicator remains a UI/readability layer, not a camera controller.

## Controller / mouse parity

Controller may use a modest configurable candidate forgiveness cone/stickiness because stick precision differs from mouse precision.

Mouse must not inherit artificial stick acceleration/dead-zone behavior.

Both devices operate the same semantic actions and target rules.

Accessibility may increase candidate forgiveness without moving the camera or allowing through-wall selection.

## Readability/accessibility

Candidate states distinguish:
- compatible and available;
- compatible but state-blocked;
- incompatible/ordinary scenery;
- latched;
- slack;
- loaded;
- blocked;
- at limit;
- brace-eligible;
- brace-set.

Important distinctions use shape/state/text/audio combinations, not color alone.

Reticle/candidate presentation should be restrained and appear primarily while Anchor Line is selected/readied, rather than painting tool sockets permanently across the world.

## Comparative research

Horizon Forbidden West demonstrates the usability value of a dedicated physical tool spanning grapple/manipulation. Stillring does not copy its grapple launch, targeting UI, controls, or two-mode implementation.

UE5.8 Enhanced Input supports named actions, hold/press/release trigger states, contextual mappings, and player-mappable settings. Those are implementation tools; the semantic state machine above remains Stillring authority.

## System IDE

### Inspect
Expose:
- raw target candidates and screen-space score;
- sticky candidate state;
- LOS/load-path result;
- current Anchor input action states;
- gameplay-state accept/reject result;
- latch/loaded/blocked/limit/brace state;
- obstruction grace remaining;
- auto-reclaim reason;
- active device/input mapping;
- handheld line and static brace IDs separately.

### Exercise
Fixtures:
- adjacent candidates;
- candidate behind wall;
- rapid camera sweep across targets;
- latch then obstruction/recovery;
- latch then persistent obstruction;
- max working length;
- set/reclaim static brace;
- combat-state rejection;
- death/reset with live line;
- controller and mouse candidate forgiveness.

### Validate
Catch:
- camera movement caused by candidate selection;
- combat target overwritten by Anchor target;
- force during hard obstruction grace;
- second static brace before Split Cleat;
- unreclaimable line/brace;
- candidate chosen from quest priority;
- input mapping missing remappable semantic action.

## Locked statement

> **Anchor targeting follows the player's view, not hidden priority. Primary latches and tensions; Set Brace commits one authored brace; Reclaim always gets the player cleanly out.**

## Research basis
- Epic Games — Unreal Engine 5.8 Enhanced Input and user-settings/remapping documentation.
- Guerrilla / PlayStation — Horizon Forbidden West Pullcaster design discussion as a functional comparison only.
- `docs/62_GATE3_ANCHOR_PHYSICAL_CONTRACT_ADDENDUM.md`
- locked Gate 1/2 authority.

## Next decision

**Gate 3 Decision #5 — Anchor Line traversal use contract.**
