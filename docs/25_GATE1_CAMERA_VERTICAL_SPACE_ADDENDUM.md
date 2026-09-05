# 25 — Gate 1 Camera Vertical-Space Addendum

**Status:** FINAL OWNER APPROVED / RECONCILED INTO `docs/22`  
**Updated:** 2026-09-05  
**Scope:** Camera Decision #9 provenance record for Issue #2. The cumulative implementation-facing authority now lives in `docs/22_GATE1_CAMERA_SPECIFICATION.md`; this file preserves the decision-specific owner-approved record.

## Authority
Camera Decision #9 is locked. Claude may not replace this behavior with a stock vertical-follow camera, automatic puzzle-directed pitch, constant slope-following, cinematic shaft framing, or any other unstated vertical-space policy.

> **The player should look at Orra, not babysit the camera.**

> **Simple intention, capable character, honest world.**

---

## Camera Decision #9 — vertical-space behavior — LOCKED

### Core rule
Stillring uses **Vertical Context Assist** for grounded exploration: sustained meaningful elevation change may alter screen-space composition and may apply a very weak, bounded pitch assist only when vertical route readability would otherwise degrade.

The camera makes room for the vertical space without choosing what the player should look at.

Vertical Context Assist is not a special cinematic camera mode and is not triggered merely because a room is tall.

### Screen-space composition first
The first response to meaningful vertical travel is a small screen-space framing bias rather than automatic camera rotation.

- sustained ascent may place Neris somewhat lower in frame to reveal more route/geometry above and ahead;
- sustained descent may place Neris somewhat higher in frame to reveal more route/geometry below and ahead;
- exact screen-space offset, dead-zone/soft-zone size, transition rate, and persistence remain Gate 1 tuning;
- shallow slopes, ordinary stairs, and small terrain undulations should remain inside a generous vertical dead zone and should not cause continuous visible camera bobbing;
- composition bias does not rotate Neris or alter locomotion authority.

### Sustained vertical-travel classification
Vertical Context Assist may classify grounded exploration into tuning-defined states such as flat/ordinary terrain, sustained ascent, sustained descent, drop approach, and recovery toward canonical framing.

Classification must use recent/sustained player movement and nearby immediately relevant traversable/supporting geometry rather than one-frame height noise. Hysteresis/stability prevents repeated state changes on stair treads, rubble, small ramps, or sawtooth terrain.

### Drop approach
Approaching a meaningful drop may justify modest additional below-footing context, but proximity alone is insufficient.

- the player must actually be moving toward the drop/edge;
- moving parallel to a cliff does not cause a downward bias merely because the cliff is nearby;
- a pit or cliff behind Neris does not pull the camera downward;
- standing near an edge without approach intent does not trigger an automatic look-down;
- exact edge-distance, approach-vector, persistence, and severity thresholds remain tuning.

The purpose is immediate footing/drop readability, not dramatic presentation of danger.

### Tall rooms, shafts, and atriums
A tall space does not itself grant the camera permission to tour the environment.

- standing in a shaft, atrium, tower interior, or tall chamber leaves ordinary camera ownership with the player;
- the camera does not automatically look up because important geometry exists above;
- it does not automatically look down because depth exists below;
- manual pitch remains the primary inspection tool when vertical travel intent is not established;
- Vertical Context Assist matters when the player's actual grounded route meaningfully gains or loses elevation.

### Weak conditional soft-pitch assist
Stillring permits a **very weak, bounded automatic pitch assist** only after screen-space composition alone is insufficient to preserve useful route readability during sustained vertical travel.

The assist may begin only when all relevant conditions are true:
- Neris is in sustained grounded movement with meaningful elevation change;
- route-relevant geometry in the current travel corridor is drifting outside the approved vertical readability envelope;
- the player is not actively manipulating the camera;
- a tuning-defined grace period after the last manual camera input has expired;
- no higher-priority camera state owns presentation.

The assist is slow, small, capped, never snaps, immediately yields to manual input, does not change yaw, does not alter Neris movement/facing, and does not change FOV merely because the route is steep. Exact thresholds/timing remain tuning.

### Manual camera authority
Manual camera input always wins.

- while the player manipulates the camera, automatic vertical pitch assist is fully suppressed;
- new deliberate input immediately cancels any active pitch correction;
- releasing manual input preserves the chosen pitch for a grace period rather than immediately steering toward route direction;
- the player may deliberately look downhill while moving uphill, uphill while descending, or inspect a side wall while on stairs;
- the camera must accept that choice rather than treating it as an error;
- non-rotational screen-space composition bias may remain active where useful.

### Accessibility / preference boundary
Final camera settings must permit reducing or fully disabling ordinary automatic vertical pitch assistance, including an **Off/Never** behavior. Disabling pitch assist does not disable manual pitch, vertical screen-space composition bias, collision safety, or separately approved behavior. Exact settings presentation belongs to Decision #17.

### The camera must not know the puzzle solution
Vertical Context Assist may use only player-facing physical context required to understand current movement, such as sustained Neris movement direction, recent elevation trend, nearby immediately relevant traversable/supporting geometry, current footing/drop relationship, and physically visible route geometry in the local travel corridor.

It may **not** use privileged solution/gameplay metadata to decide where to aim or bias the camera, including quest objectives, hidden interaction targets, puzzle-solution metadata, designer-authored solution look points, undiscovered routes/secret entrances, treasure locations, hidden enemies, or the preferred/correct branch through a multi-route puzzle.

If several possible vertical routes exist, the camera does not reveal the intended answer. The player explores and interprets the space.

### Recenter interaction
Decision #4 manual recenter remains an explicit player recovery command. During valid vertical context, recenter may use the nearest contextually useful exploration framing already allowed by #9 instead of blindly restoring flat-ground pitch that hides the route. It may not bypass Decisions #5/#7/#8, manual input still cancels it, and it never uses puzzle/quest metadata to choose a vertical direction.

### Interaction with low ceilings / cramped spaces
Decision #9 requests readability; Decisions #5, #7, and #8 determine where the camera may physically exist. A steep descent under a low roof can request more below-route context while #8 limits legal height/pitch; rear-wall obstruction invokes #5; severe compression invokes #7. #9 never authorizes clipping, teleportation, or a new emergency camera mode.

### Jump / fall / mantle boundary
Decision #9 owns **grounded exploration verticality only**. Once Neris enters jump, fall, mantle, or another airborne/transition presentation, Decision #15 owns the material camera behavior. #9 therefore does not decide airborne vertical follow, landing framing, mantle offsets, airborne pitch assistance, or vertical launch/fall lag.

### Lock-on / combat boundary
Decision #9 does not use enemy position to drive ordinary vertical pitch assistance. A target above/below does not become #9 authority merely because it is vertically separated. Lock-on acquisition/transition and combat framing remain Decisions #10–#14; physical legality from #5/#7/#8 still applies later.

### Explicitly rejected behavior
Ordinary vertical-space handling does **not** automatically yaw toward stairs/shafts/cliffs, constantly pitch with every slope change, look toward the highest/lowest point in a room, widen FOV because a shaft is tall, zoom out merely to show full architecture height, add decorative roll, use objective/puzzle/secret/treasure/hidden-route data to direct view, or become cinematic merely because the environment is dramatic.

### System IDE requirement
The Camera / Targeting IDE must expose at minimum:
- Vertical Context Assist active/inactive;
- current vertical-travel classification and reason;
- measured recent elevation trend / travel-vector evidence;
- persistence/hysteresis state and timers;
- canonical Neris screen-space Y versus resolved screen-space Y;
- active vertical composition bias;
- dead / soft / hard vertical framing zones drawn on screen;
- player-requested pitch;
- automatic pitch-assist contribution;
- final resolved pitch;
- manual-input suppression / grace state;
- pitch-assist activation/rejection reason;
- drop-approach state and supporting approach evidence;
- current higher-priority constraint/state limiting requested composition;
- whether automatic vertical pitch assistance is enabled/reduced/off.

The IDE must make clear **why** a vertical adjustment occurred rather than requiring tuning by superstition.

### Representative test cases
The Gate 1 camera workbench/test space must include at minimum:
- long gentle and steep uphill routes;
- long gentle and steep downhill routes;
- switchback stairs;
- repeated shallow steps / sawtooth terrain;
- tall shaft entered but not climbed;
- tall atrium crossed horizontally;
- cliff approached head-on;
- cliff traversed parallel to the edge;
- drop behind Neris while moving away;
- standing still at a cliff;
- steep descent beneath a low ceiling;
- ascent with rear-wall compression;
- multi-route vertical puzzle chamber;
- moving uphill while deliberately looking downhill;
- moving downhill while deliberately looking uphill;
- manually inspecting a side wall while vertical travel continues.

### Research basis / boundary
This decision is informed by Nintendo's discussion of verticality as an exploration/readability problem, modern camera systems that separate screen-space framing/dead zones from physical camera rotation, third-person camera practice using free-move/dead zones and delayed following to avoid excessive camera reaction, and Stillring's locked rule that deliberate manual camera input outranks assistance.

Research supports screen-space composition first, bounded conditional pitch assistance second, and player ownership throughout. It does not justify copying another game's exact screen offset, dead-zone dimensions, pitch timing, acceleration, or environmental metadata model.

### Player-facing acceptance
Vertical-space behavior passes when:
1. steep routes gain useful context without constant right-stick babysitting;
2. ordinary stairs/shallow slopes do not visibly bob the camera;
3. approaching a meaningful drop improves footing/drop readability without every nearby cliff becoming an automatic look-down;
4. parallel/away movement near a drop does not trigger inappropriate downward framing;
5. tall rooms do not steal the camera merely because architecture exists above/below;
6. manual camera input always overrides pitch assistance immediately;
7. deliberate looking opposite the route remains stable and respected;
8. pitch assistance is weak, capped, delayed, and independently disableable;
9. vertical assistance never reveals puzzle solutions, hidden routes, objectives, treasure, or unseen enemies;
10. recenter respects current valid vertical context without inventing authority;
11. low ceilings/collision/cramped spaces obey Decisions #5/#7/#8;
12. jump/fall/mantle and lock-on presentation remain reserved for later decisions.

Philosophy:
> **Make room for the height. Never aim on the player's behalf.**

---

## Reconciliation note
Decision #9 has been folded into `docs/22_GATE1_CAMERA_SPECIFICATION.md`. `docs/22` is the cumulative implementation-facing camera authority; this addendum remains the owner-approved decision-specific provenance record. The two files must stay semantically consistent.

## Next owner decision
**Camera Decision #10 — lock-on acquisition transition.**

Research it first. Do not infer lock-on entry timing, camera rotation, target snap strength, movement-facing transition, failure/no-target behavior, or manual-camera authority from Zelda lineage, Unreal defaults, or later framing decisions.
