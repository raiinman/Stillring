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

### 4.4 Deliberate jump and low-obstacle mantle

Neris has an **always-available, modest, deliberate jump**.

The jump exists for intentional vertical movement and ordinary small gaps. It is not a high, floaty platformer jump and is not intended to erase authored traversal gates.

The baseline grammar is:

```text
tiny step / stair / minor floor lip   → automatic terrain handling
small gap / intentional vertical move → deliberate jump
obviously low obstacle                → jump + small mantle/scramble response
major cliff / meaningful height gate  → route, tool, or later traversal capability
```

The exact jump height, arc, air control, animation, and mantle threshold remain prototype tuning questions, but **the existence of deliberate jump and small low-obstacle mantle/scramble is locked**.

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
- a hard 180-degree reversal uses a quick planted reversal and then re-accelerates into sprint rather than snapping instantly at full speed.

The exact turn-rate curve, speed-loss amount, animation timing, and re-acceleration values remain Gate 1 tuning questions. The **feel rule** is locked: responsive steering with brief momentum loss only for genuinely hard reversals.

Still pending owner review:
- sprint-to-jump retention;
- target-lock/combat entry behavior while sprinting;
- exact acceleration and top speed.

### 4.6 Lock-on remains a tactical movement mode

Target lock is still valuable because it solves a real third-person combat problem.

While locked:
- movement becomes target-relative where appropriate;
- camera framing preserves both Neris and the relevant threat;
- target switching must be understandable;
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

The exact speed thresholds, turn curves, reversal speed loss, and re-acceleration values remain tuning questions.

---

## 7. Physical capabilities still requiring owner review

Issue #1 must continue through these **one decision at a time** before they become final locomotion authority:

- sprint-to-jump retention;
- target-lock/combat entry behavior while sprinting;
- exact mantle/scramble thresholds and control timing;
- ledge grab/hang behavior;
- deliberate drop behavior;
- climbing scope;
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
