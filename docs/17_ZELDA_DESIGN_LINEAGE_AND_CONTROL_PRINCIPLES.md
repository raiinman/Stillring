# 17 — Zelda Design Lineage and Player-Control Principles

**Status:** design-lineage authority and Gate 1 input  
**Purpose:** preserve the specific lessons Project Stillring is taking from the Zelda series without freezing the project at 1998 controls or copying protected expression.

This document exists because **Ocarina of Time is a root reference, not a ceiling**.

Project Stillring is inspired by the design lineage of authored 3D Zelda games, especially the way Nintendo repeatedly simplified player intention, improved camera control, expanded traversal agency, and made world affordances more readable over time. Stillring should learn from that accumulated evolution through 2026 rather than preserving limitations that existed because of Nintendo 64 hardware or a one-stick controller.

This document does **not** authorize copying exact movement speeds, animation timing, camera distances, input layouts, traversal geometry, visual indicators, enemy behavior, or other protected expression. `docs/05_IP_GUARDRAILS.md` remains binding.

---

## 1. What Ocarina of Time actually contributed

The useful lesson from **The Legend of Zelda: Ocarina of Time** is not “remove the jump button because Zelda did.”

The deeper lessons are:

- reduce unnecessary friction in 3D navigation;
- let the player express intention without demanding precision for ordinary biomechanics;
- give the character, camera, and target a shared relationship during combat;
- make target-lock movement legible rather than letting character orientation, camera orientation, and attack direction fight each other;
- coordinate enemy aggression with the combat camera so multi-enemy encounters stay readable;
- judge controls by how quickly players stop thinking about operating the character and start thinking about the world.

Nintendo's original developers described auto-jump as a deliberate response to the action difficulty of early 3D controls. They also described Z-targeting as a solution to alignment, camera, and one-versus-many combat readability.

**Stillring conclusion:** preserve the problem-solving philosophy, not the obsolete hardware compromise.

---

## 2. What later Zelda games improved

### Wind Waker — free camera becomes part of player ownership

Nintendo introduced a freely controllable camera to 3D Zelda with **The Wind Waker**. Aonuma later specifically recalled how good that freedom felt.

**Stillring conclusion:** exploration uses a modern free right-stick camera as the default. Recenter is a convenience, not a substitute for camera control.

### Skyward Sword — movement flow matters

Nintendo deliberately added a dash action in **Skyward Sword** and discussed avoiding movement interruptions. Dash also supported quickly scrambling up small cliffs/slopes.

**Stillring conclusion:** movement should preserve flow. Neris therefore has a sustained sprint state from the beginning for faster ground travel. Sprint is **not** the combat evade and must not become a second dodge. Ordinary traversal sprint has **no stamina or other resource cost** because a periodic forced slowdown would add friction without creating a meaningful Stillring decision.

### Breath of the Wild — terrain becomes a route choice

**Breath of the Wild** greatly expanded traversal agency through climbing, gliding, surfing, riding, and systemic interaction. The important lesson for Stillring is that terrain should invite reasoning rather than merely function as corridor walls.

**Stillring conclusion:** players should frequently be able to see a destination, form a route hypothesis, and act on world geometry. Stillring does not need universal climbing to learn this lesson.

### Tears of the Kingdom — affordance honesty

Nintendo's developers described a strong rule during **Tears of the Kingdom** development: if players reasonably think an object or action should work, the game should try to honor that expectation; when something intentionally cannot behave that way, the world should communicate the exception.

**Stillring conclusion:** visible affordances must be trustworthy.

If something looks:
- mantleable,
- breakable,
- movable,
- hookable,
- climbable,
- resonant,
- traversable,
- interactable,

then either the expected action should work or the art/geometry/state should clearly communicate why it does not.

Invisible arbitrary rules are a failure of world communication.

---

## 3. Stillring synthesis

The intended control philosophy is:

> **Simple intention, capable character, honest world.**

The player should spend attention on:
- where to go;
- what the environment means;
- what an enemy is doing;
- which tool or route solves a problem;
- what changed in the world;

not on fighting basic character locomotion.

Ordinary biomechanics should disappear beneath the player's intention wherever doing so does not erase meaningful traversal decisions.

Examples:
- stairs should simply work;
- tiny floor lips should not snag Neris;
- ordinary small steps should not require a jump input;
- ordinary sprint should not be periodically disabled by an empty stamina bar;
- obvious low obstacles should not require a separate “mantle” command after the player has already expressed the intention to cross them;
- a clearly reachable ledge should not demand a frame-perfect extra “grab” input after the player has already committed to the jump;
- a hanging Neris should not require a redundant climb button after the player continues pressing toward a valid top surface;
- a hanging Neris should be able to correct laterally along the same continuous handhold without that correction silently becoming universal free climbing;
- a hanging Neris should not fall because ordinary analog correction was misread as “let go”; dangerous release requires a distinct deliberate action;
- ordinary walls and cliffs should not silently become free-climbable and erase route or puzzle meaning;
- camera collision should solve itself without punishing the player;
- the player should not need pixel-perfect alignment to perform an obvious everyday traversal action.

This is not the same as making traversal automatic. Important movement choices remain player-owned.

---

## 4. 2026 baseline rules

These are **locked design principles** unless deliberately revised in repository authority.

### 4.1 Free camera

- Exploration camera is freely controllable with the right stick / equivalent mouse input.
- Recenter is an optional convenience action.
- The camera may assist composition/collision but must not constantly wrest steering authority away from the player.
- Lock-on intentionally changes camera grammar into combat framing.

### 4.2 Analog movement

- Controller movement must preserve useful analog range rather than behaving like eight-way digital movement.
- Low-speed movement should support careful positioning in towns, mechanisms, narrow spaces, and near edges.
- Full input should produce confident travel without excessive delay.
- Exact acceleration/deceleration curves remain a prototype tuning question.

### 4.3 Ordinary terrain handling

- stairs, small steps, curb-scale obstacles, and minor uneven ground are handled automatically;
- ordinary terrain should not create accidental platforming difficulty;
- traversal friction must come from intentional geometry, mechanics, hazards, or player decisions.

### 4.4 Deliberate jump and automatic low-obstacle mantle

Neris has an **always-available, modest, deliberate jump**.

The jump exists for intentional vertical movement and ordinary small gaps. It is not a high, floaty platformer jump and is not intended to erase authored traversal gates.

Low-obstacle mantle/scramble is **automatic from clear movement or jump intent**. There is no separate mantle button.

The baseline grammar is:

```text
tiny step / stair / minor floor lip   → automatic terrain handling
small gap / intentional vertical move → deliberate jump
knee → waist obstacle                 → fluent automatic step/vault/mantle
waist → lower-chest obstacle          → deliberate direct approach/jump + automatic mantle
shoulder-height and above             → not baseline auto-mantle; real traversal problem
major cliff / meaningful height gate  → route, tool, or later traversal capability
```

Automatic mantle must only trigger when the player's intention is clear and the path is valid. Required safeguards:
- sustained directional intent toward the obstacle or a jump trajectory clearly carrying Neris into it;
- an obstacle within the authored baseline-mantle class;
- a reachable, valid top/landing surface;
- an approach angle appropriate to the move;
- enough clearance and standing space to complete the traversal;
- no conflicting higher-priority movement/combat/action state;
- no trigger merely because Neris passes near, brushes past, or moves parallel to mantle geometry.

The system must never feel magnetic. The player should feel that Neris understood an already-expressed traversal intention, not that the game seized control.

#### Body-relative mantle scope

Baseline mantle scope is defined against **Neris's body**, not a permanent arbitrary Unreal-unit number:

- **knee through waist height:** ordinary traversal; forward movement intent should be enough for a fluent step/vault/mantle response;
- **waist through lower-chest height:** still baseline-mantleable, but it should read as intentional traversal and require a clearly direct approach or jump into the valid mantle path;
- **shoulder height and above:** not ordinary automatic mantle territory. This becomes a meaningful ledge/traversal interaction, route, tool, later capability, or intentionally inaccessible geometry.

This body-relative scope is locked. Exact centimeter thresholds, approach-angle tolerances, detection volumes, animation selection, and timings are Gate 1 tuning values tied to Neris's actual prototype scale. Tuning those values may refine feel but may not silently expand baseline mantle into shoulder-height-plus parkour.

#### Automatic reachable-ledge catch

Above the ordinary mantle band, Neris may **automatically catch and enter a hang on a valid reachable ledge** when the player's jump/fall trajectory and directional intent clearly communicate the attempt. There is no dedicated ledge-grab button.

A ledge catch is not a free extension of baseline mantle. It is a distinct traversal state: ordinary locomotion stops when Neris catches the ledge.

The catch requires:
- a ledge that is physically reachable from Neris's actual jump/fall trajectory;
- clear orientation/directional intent toward the ledge;
- a valid handhold/edge and enough local clearance to form the hang state;
- no conflicting higher-priority state;
- a catch window that is forgiving enough to honor clear intent but not so large that nearby geometry becomes magnetic.

The catch must **not** occur merely because Neris:
- runs or falls parallel to a wall;
- passes sideways near an edge;
- brushes incidental geometry;
- is outside a plausible reach envelope;
- falls past arbitrary cliff geometry with no clear grab intent.

A ledge catch is allowed to save a well-aimed jump from becoming a frame-perfect input test. It is **not** a universal last-second rescue system.

#### Ledge-hang continuation and pull-up

A successful catch always settles Neris into the **hang state first**. Catching a ledge does not immediately force a pull-up animation or carry her onto the top surface.

While hanging:
- neutral movement input leaves Neris hanging;
- continued movement **toward/up onto the ledge** communicates the player's intent to climb onto the surface;
- there is **no separate pull-up/climb button** for this ordinary continuation;
- pull-up may begin only when the top/landing surface is valid, standable, and has enough clearance for Neris to finish safely;
- if the top is blocked, invalid, too small, or otherwise unsafe for a normal completion, Neris remains hanging rather than clipping or being forced onto bad geometry;
- a higher-priority action/state may block the pull-up when explicitly designed to do so.

This preserves a meaningful hang beat: the player can catch, stop, look, and decide whether to continue instead of being automatically carried onto the top. At the same time, once the player clearly continues toward a valid top, no redundant context-button press is required.

#### Same-handhold lateral shimmy

While hanging, Neris may move sideways with left/right movement input **along the same continuous valid handhold**.

Locked boundaries:
- releasing lateral input leaves Neris hanging at the current valid position;
- shimmy may correct a slightly imperfect catch or move Neris toward a valid pull-up location;
- the baseline shimmy does **not** wrap around a corner;
- it does **not** cross a physical gap in the handhold;
- it does **not** transfer onto a different wall or ledge;
- it does **not** perform a lateral jump between separate ledges;
- it does **not** climb upward or downward between handholds;
- when the continuous valid handhold ends, Neris stops rather than inventing a traversal continuation.

A corner, gap, different wall/ledge, or higher/lower handhold is therefore a separate authored traversal problem. This gives the hang state useful correction and local agency without silently creating a broader parkour/free-climbing system.

Exact shimmy speed, acceleration, animation cadence, hand spacing, ledge-follow tolerances, and visual hand placement remain Gate 1 tuning questions. Tuning may improve feel but may not broaden the locked traversal grammar.

#### Deliberate ledge release / drop

While hanging, Neris releases the handhold only when the player presses a **distinct deliberate Drop/Release action**.

Locked boundaries:
- ordinary analog movement alone never releases the ledge;
- down, away-from-wall, diagonal-down, partial-stick input, stick drift, and dead-zone noise remain non-release movement input;
- a deliberate Drop/Release press acts promptly and does not require a hold-to-confirm delay;
- the exact physical controller/keyboard binding is **not** locked by this rule and remains remappable control-layout/accessibility policy;
- this deliberate release does not itself authorize lateral transfers, vertical climbing, corner traversal, or a broader parkour system.

The intent distinction is deliberate: ordinary continuation/correction may be forgiving, but a potentially dangerous commitment must not be inferred from ambiguous analog direction.

#### Broader climbing scope

Neris has **no baseline free-climbing capability** beyond the locked ledge grammar above.

Locked boundaries:
- ordinary rough walls, cliffs, masonry, roots, rock faces, and similar surfaces do not become climbable merely because they appear physically grippable;
- the catch → hang → same-handhold shimmy → pull-up/drop grammar does not chain upward, wrap corners, or turn into an implicit free-climbing system;
- broader climbing may exist only on **explicitly authored traversal structures, tools, or later capabilities**;
- any such climbing must use a consistent visible world language rather than hidden per-surface flags that make equivalent-looking geometry behave differently;
- this rule exists to preserve authored traversal puzzles, route memory, and progression. A wall or cliff that blocks the player must stay meaningful until the intended route, structure, tool, or capability resolves it;
- specific forms such as ladders, ropes, vines, chains, climbable masonry, lateral transfers, vertical handhold chains, and corner traversal are not automatically granted by this rule and remain separate design decisions if/when needed.

This is a deliberate rejection of universal surface solvability, not a rejection of climbing as a future verb. Stillring may add authored climbing where it strengthens a puzzle, route, place, or progression reward, but baseline movement must not erase those problems before they matter.

The exact jump height, arc, air control, mantle/ledge detection volumes, reach envelope, catch tolerances, hang settle timing, pull-up input threshold, clearance tests, shimmy speed/acceleration/tolerances, drop animation timing, animation, and traversal timing remain Gate 1 tuning questions. **The existence of deliberate jump, automatic low-obstacle mantle/scramble, the no-separate-mantle-button rule, the body-relative mantle scope, automatic intent-based reachable-ledge catch with no grab button, deliberate hang-to-pull-up continuation with no separate climb button, same-continuous-handhold lateral shimmy with no corners/gaps/transfers/vertical climbing, explicit immediate Drop/Release with no analog-direction release, and no baseline free-climbing beyond explicitly authored structures/tools/later capabilities are locked.**

### 4.5 Sustained sprint

Neris has a **sustained sprint available from the beginning**.

Sprint is a travel-speed state for:
- roads;
- fields;
- backtracking;
- larger authored spaces;
- other situations where ordinary running would become needless friction.

Sprint is **separate from the eventual combat evade**. It should not become a short burst-dodge, invulnerability move, or replacement for combat spacing rules.

Locked:
- sprint exists from the beginning;
- sprint is sustained rather than a one-shot dash;
- ordinary traversal sprint has **no stamina/resource cost**;
- the player may sustain ordinary sprint indefinitely;
- sprint supports **Hold** and **Toggle** input modes;
- **Hold is the default** sprint input behavior;
- Toggle is available through controls/accessibility settings rather than changing gameplay rules;
- normal analog walk/run remains useful below sprint;
- sprint's role is faster travel, not a second evade;
- a future combat or special-traversal resource may not be silently reused to throttle ordinary sprint;
- full sprint remains **highly steerable** for ordinary curves and corners;
- sprint does **not** use a large turning circle, tank steering, or require a full stop merely to redirect;
- very sharp direction changes naturally shed some speed so Neris retains believable physical weight;
- a hard 180-degree reversal uses a quick planted reversal and then re-accelerates into sprint rather than snapping instantly at full speed;
- jumping while sprinting preserves the horizontal sprint momentum Neris already has rather than automatically dropping her to ordinary run speed;
- sprint-jumping does **not** grant an extra speed boost beyond the momentum already carried into the jump;
- after landing, Neris returns to/continues sprint when sprint is still being requested and no other movement state overrides it;
- acquiring target lock while sprinting **ends the exploration sprint state**;
- lock-on does **not** hard-stop Neris instantly: existing momentum decays quickly and naturally through a short deceleration/pivot transition;
- after that transition, precise target-relative combat locomotion owns movement;
- full exploration sprint is **not available while target-locked**.

The exact turn-rate curve, speed-loss amount, animation timing, re-acceleration values, jump arc, air-control values, and sprint-to-lock blend timing remain Gate 1 tuning questions. The **feel rules** are locked: responsive steering, brief momentum loss only for genuinely hard reversals, no invisible braking merely because the player jumped, and no jarring hard stop when sprint turns into combat locomotion.

Still pending owner review:
- exact acceleration and top speed.

### 4.6 Lock-on remains a tactical movement mode

Target lock is still valuable because it solves a real third-person combat problem.

Entering target lock from sprint follows this locked transition:

```text
exploration sprint
      ↓ acquire target lock
short natural deceleration / pivot
      ↓
target-relative combat locomotion
```

While locked:
- movement becomes target-relative where appropriate;
- camera framing preserves both Neris and the relevant threat;
- target switching must be understandable;
- full exploration sprint is unavailable;
- enemy encounter logic must participate in readability rather than allowing every nearby enemy to attack without regard for visual/combat bandwidth.

Stillring will design its own targeting indicator, switching rules, camera geometry, aggression model, and animation language.

### 4.7 Animation contributes to responsiveness

Responsiveness is not only movement acceleration.

The prototype and later animation work must consider:
- start transitions;
- stop transitions;
- direction reversals;
- turn-in-place behavior if retained;
- run/sprint transitions;
- run-to-interaction transitions;
- jump/landing transitions;
- mantle/scramble transitions;
- ledge-catch/hang transitions;
- hang-to-pull-up transitions;
- hang-shimmy transitions and stop-at-boundary behavior;
- hang-to-drop release transitions;
- sprint-to-lock transitions;
- lock/unlock transitions;
- weapon-state locomotion transitions.

A physically weighted character can still feel responsive if the requested action is acknowledged immediately and the transition communicates clearly.

### 4.8 Affordance honesty

Level design, art, collision, and gameplay rules must agree about what the player can do.

Do not rely on:
- arbitrary invisible walls where geometry implies a route;
- identical-looking objects with unexplained different behavior;
- waist-high barriers that are inexplicably impassable if equivalent barriers are traversable elsewhere;
- fake tool targets that visually match real ones;
- climbable-looking surfaces that differ only because a designer forgot to support them.

When a restriction is intentional, communicate it through fiction, material, shape, damage, obstruction, state, or another consistent visual/gameplay rule.

---

## 5. Authored progression remains central

Stillring is **not** trying to become Breath of the Wild or Tears of the Kingdom.

The world is interconnected and exploratory, but important traversal verbs are authored progression rewards.

A desired Stillring experience is:

1. the player sees a meaningful inaccessible place;
2. the world makes the obstacle understandable;
3. the player remembers it;
4. a later tool or capability changes their movement vocabulary;
5. the old place becomes newly legible;
6. returning feels like mastery rather than checklist cleanup.

Therefore:
- universal climb-everything traversal is **not** the assumed baseline;
- every cliff does not need to be scalable;
- progression tools must continue to change how earlier spaces are understood;
- restrictions must still obey affordance honesty.

The modern-Zelda lesson is **player trust and agency**, not removal of authored progression.

---

## 6. Gate 1 movement rules still requiring tuning

### Analog walk → run → sprint

Gate 1 must preserve three readable movement bands:
- careful analog walk / low-speed movement;
- confident ordinary run;
- player-requested unlimited sustained sprint.

Sprint should improve travel flow without destroying careful analog control or making the ordinary run feel intentionally bad.

At full sprint, normal curves/corners should remain responsive. Only hard direction changes should visibly trade a small amount of momentum for physical weight. A 180-degree reversal should read as a quick planted change of direction, not an instant velocity flip and not a lumbering semicircle.

When sprint transitions into a jump, horizontal sprint momentum carries through the jump. Jumping is not a brake and is not a hidden speed exploit: it preserves existing travel momentum without adding more. If sprint is still requested on landing and no other movement state takes priority, Neris continues sprinting rather than being arbitrarily reset to run.

When sprint transitions into target-lock combat, sprint authority ends immediately as a state but **velocity does not disappear instantly**. Gate 1 should tune a short natural deceleration/pivot that settles rapidly into precise target-relative movement. The transition should feel intentional and physical, never like an invisible wall and never like Neris keeps using full exploration sprint around the target.

For low obstacles, Gate 1 should tune automatic mantle detection so normal traversal feels fluent without magnetic false positives. The test must include head-on approaches, shallow angles, parallel passes, jump-into-mantle cases, invalid landing tops, low ceilings, nearby-but-not-intended obstacles, and representative knee/waist/lower-chest/shoulder-height geometry. Shoulder-height-plus test pieces must prove they do **not** silently become baseline auto-mantles.

For ledge catch, Gate 1 must include deliberate jump catches, short-fall catches with clear forward intent, near misses outside plausible reach, sideways/parallel passes, incidental geometry, invalid handholds, low-clearance hangs, and large-cliff fall cases. The test succeeds when clearly intended reachable catches feel generous while non-intended geometry never feels magnetic.

For hang-to-pull-up, Gate 1 must test that every valid catch visibly settles into hang before any climb continuation, neutral input holds the hang, continued toward/up input produces a prompt pull-up on valid tops, and blocked/invalid tops leave Neris hanging without clipping or forced placement. The pull-up continuation should feel intentional without requiring a separate context button.

For ledge shimmy, Gate 1 must test continuous straight handholds, handholds that end, corners, physical gaps, adjacent-but-separate ledges, new-wall transitions, higher/lower nearby handholds, blocked pull-up areas, and movement toward a later valid pull-up spot. Left/right intent should feel responsive along the same continuous valid handhold, releasing input should hold position, and reaching a prohibited boundary must stop cleanly rather than snapping, wrapping, transferring, or inventing free climbing.

For deliberate ledge drop, Gate 1 must verify that down/away/diagonal analog input, partial stick input, dead-zone edge cases, and stick drift never release the handhold. The explicit Drop/Release action must release promptly without a hold-to-confirm delay, and remapping the physical binding must not alter the gameplay rule.

For the climbing boundary, Gate 1 must include rough walls, cliffs, masonry, roots, and other plausible-looking surfaces beside deliberately supported traversal structures. Ordinary surfaces must not become climbable from proximity or directional input, while any authored climb structure must communicate its supported behavior consistently enough that players do not need to guess which visually equivalent surface has a hidden climb flag.

The exact speed thresholds, turn curves, reversal speed loss, re-acceleration values, jump arc, air-control values, sprint-to-lock transition timing, body-relative mantle calibration, approach-angle tolerance, mantle timing, ledge reach envelope, catch tolerance, hang settle timing, pull-up input threshold, clearance tests, shimmy speed/acceleration/hand spacing/ledge-follow tolerances, drop animation timing, and catch/pull-up/shimmy animation timing remain tuning questions.

---

## 7. Physical capabilities still requiring owner review

Issue #1 must continue through these **one decision at a time** before they become final locomotion authority:

- ladders;
- swimming;
- crouch/stealth posture if any;
- slope scrambling/sliding;
- fall damage or recovery rules;
- jump arc / air control;
- interaction while moving;
- traversal-tool overrides.

Do not let Claude infer permanent answers for unresolved entries from Unreal defaults, template code, or another game's control scheme.

---

## 8. The five-minute control test

A useful Ocarina-era observation was that players could quickly stop thinking about the difficulty of controlling a 3D character.

Stillring keeps that test in modern form:

> **Within roughly five minutes, ordinary movement should stop being something the player consciously operates.**

The player should already be thinking about:
- the room;
- the route;
- a landmark;
- an enemy;
- an interaction;
- a curiosity.

Failure examples:
- repeatedly correcting the camera;
- fighting acceleration to stop where intended;
- snagging on stairs;
- being forced into repetitive sprint-wait-sprint cycles during ordinary travel;
- sprint steering feeling like a vehicle or tank;
- instant full-speed 180-degree snaps making Neris feel weightless;
- jump input acting like an invisible brake during a running jump;
- target-lock instantly zeroing sprint velocity and feeling like a collision;
- target-lock allowing full exploration sprint circles that undermine precise combat spacing;
- auto-mantle pulling Neris onto geometry she was merely passing;
- obvious valid low obstacles failing because the player did not press a redundant context button;
- shoulder-height-plus geometry being swallowed by baseline auto-mantle and erasing authored traversal distinctions;
- a clearly intended reachable ledge failing because the player missed a redundant grab button or tiny timing window;
- ledge catch magnetically rescuing sideways/incidental falls that the player did not intend;
- a ledge catch immediately auto-pulling Neris up before the player can inhabit or assess the hang state;
- clear continued toward/up input failing to pull Neris onto an obviously valid top because the game expects a redundant climb button;
- an invalid or blocked top forcing a pull-up that clips or places Neris unsafely;
- same-handhold shimmy feeling sluggish, sticky, or over-precise when the player only wants to correct position;
- shimmy automatically wrapping a corner, crossing a gap, changing walls, or climbing vertically and thereby erasing an authored traversal distinction;
- ordinary down/away analog input accidentally releasing a ledge;
- an explicit Drop/Release press feeling delayed because the game waits for a hold confirmation or long uninterruptible pre-drop animation;
- ordinary walls or cliffs unexpectedly accepting free-climb input and bypassing an authored route/puzzle;
- two visually equivalent surfaces behaving differently only because one has a hidden climbable flag;
- guessing which small obstacles are passable;
- accidentally falling because edge behavior is unclear;
- needing instructions for ordinary movement;
- losing targets because camera/lock grammar is unpredictable.

Gate 1 is not complete because movement values exist. It is complete when human play says the controls have become trustworthy enough to disappear beneath play.

---

## 9. Research sources

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

These sources are used to extract design problems and evolution. They are **not** implementation specifications for Stillring.