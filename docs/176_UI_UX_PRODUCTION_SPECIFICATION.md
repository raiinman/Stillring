# 176 — Stillring UI / UX Production Specification

**Status:** ACTIVE / PRODUCTION-AUTHORITY / DOCUMENTATION-ONLY  
**Updated:** 2026-09-06  
**Parent program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Decision rights:** `docs/170_STUDIO_DECISION_RIGHTS_MATRIX.md`  
**Product boundary:** `docs/171_PERFORMANCE_PLATFORM_PRODUCT_BRIEF.md`  
**Core sources:** `docs/00_PROJECT_CHARTER.md`, `docs/01_GAME_VISION.md`, `docs/20`, `docs/34`, `docs/48`, `docs/55`, `docs/69`, `docs/79`, `docs/88`, docs `89`–`109`, docs `120`–`126`, docs `127`–`134`  
**Art authority:** `docs/154_STILLRING_ART_BIBLE.md`  
**Companion manifest:** `docs/177_UI_SCREEN_STATE_AND_ASSET_MANIFEST.md`  
**Closes toward:** `SH-UI-001` through `SH-UI-010`  
**Boundary:** this file specifies player-facing UI/UX behavior and production requirements. It does not authorize UMG/Slate/CommonUI implementation, final pixel metrics, final fonts, final rendering settings, runtime accessibility certification, platform certification, or gameplay implementation.

---

# 1. Purpose

Stillring’s existing UI philosophy is concise but not production-complete:

- minimal HUD during exploration;
- health and relevant resources readable at a glance;
- tool state shown when relevant;
- map favors landmarks/routes over icon spam;
- quest log records commitments and clues rather than GPS instructions;
- dialogue is fast to advance and recent text can be reviewed;
- controls are remappable;
- accessibility settings are baseline requirements.

This specification turns those principles into a complete interface contract so an external UI/UX team does not invent:
- a generic AAA HUD;
- a Zelda copy;
- a quest-marker checklist;
- an enemy-radar ring;
- a live-service shell;
- a save menu that contradicts semantic persistence;
- a controller-only or mouse-only navigation dead end;
- accessibility added after the interface is already fixed.

The governing principle is:

> **Show the player what they need to understand the game, not everything the game knows.**

---

# 2. UI authority boundary

UI is a **derived presentation consumer**.

It may:
- query authoritative source systems;
- present facts, state, warnings, clues and derived summaries;
- request validated actions;
- cache transient presentation state such as focus, animation or open tab;
- expose settings through their owning profile/input/camera/audio/accessibility services.

UI may not become canonical owner of:
- quest stage;
- world facts;
- inventory ownership;
- Hush semantic state;
- completion counts;
- save truth;
- enemy attack permission;
- target-lock identity;
- puzzle solution state;
- Line Skiff route legality;
- narrative branch truth.

A percentage, icon, highlighted button or displayed objective is not a second gameplay database.

If UI and source state disagree, the UI is wrong unless the source owner is proven wrong through its own contract.

---

# 3. Experience principles

## 3.1 Context over permanence

Stillring should not cover the world with permanent instrumentation.

Persistent elements are justified only when they answer a frequent, time-sensitive player question.

Contextual elements appear when their information becomes relevant and then leave cleanly.

## 3.2 World first

The world should communicate:
- Hush identity;
- traversal affordances;
- mechanism state;
- danger direction;
- landmarks;
- ordinary-life context.

UI may reinforce those truths.

It should not replace world readability with labels, outlines or floating objectives.

## 3.3 No false precision

Do not display exact numeric information where the game does not semantically expose it.

Examples:
- off-screen threat indicators give coarse direction, not exact hidden position;
- map routes show known route state, not an invisible optimal path;
- Cantor presents diagnostic relationships, not hidden solution metadata;
- save recovery communicates rollback meaning, not raw internal generation implementation unless a diagnostic surface requires it.

## 3.4 Fast, reversible navigation

The player should always know:
- where focus is;
- how to go back;
- what action will occur;
- whether an action is destructive;
- whether a change applies immediately;
- how to restore a safe default.

## 3.5 No platform assumption disguised as UX

PC-first is locked.

UI must support controller and keyboard/mouse from the start.

Console certification glyphs, platform-account screens, cloud-conflict screens and platform-store flows are added only if later platform/product authority requires them.

---

# 4. Implementation freedom

The studio may use:
- UMG;
- Slate;
- CommonUI;
- CommonUI + selected Enhanced Input integration;
- another Unreal-supported internal composition;

provided the player-facing contract in this specification is met.

Epic’s UE5.8 CommonUI framework is a valid candidate because it provides layered UI, input routing and controller-navigation support.

It is **not mandatory** simply because the project is controller-first.

Selection must consider:
- navigation/focus reliability;
- remapping integration;
- controller/KBM coexistence;
- localization/text scaling;
- maintainability;
- plugin/framework dependency cost.

Internal framework selection is **STUDIO CHOICE WITHIN BOUNDS**.

---

# 5. UI layer model

The interface uses a small set of semantic layers.

## `L0_WORLD`

Gameplay world and diegetic presentation.

Not technically a UI layer, but the primary information surface.

## `L1_HUD`

Non-modal gameplay HUD:
- health/current critical player state;
- contextual interaction prompt;
- target-lock/threat communication;
- tool/Cantor/Skiff context;
- lightweight save/status toast;
- contextual warnings.

Gameplay input remains active.

## `L2_TRANSIENT`

Short non-modal informational surfaces:
- item/tool acquisition;
- objective/commitment update;
- record discovered;
- route update;
- save result;
- tutorial cue;
- error that does not require a decision.

Must not block control longer than necessary.

## `L3_GAMEPLAY_OVERLAY`

A bounded overlay that may reduce or temporarily pause direct gameplay input depending on the screen contract:
- quick tool selection if later implementation needs it;
- map/journal invoked from gameplay;
- recent-dialogue history;
- expanded Cantor reference/pattern library where authorized.

Whether time pauses is defined per screen, not globally assumed.

## `L4_PAUSE_MENU`

Primary paused interface:
- resume;
- map;
- journal/records;
- inventory/tools/progression;
- save;
- settings/accessibility/controls;
- return to title.

## `L5_MODAL`

Decision/confirmation/error dialog.

Focus is trapped inside the modal until resolved.

## `L6_SHELL`

Boot/title/playthrough/credits/recovery surfaces before or outside active play.

## `L7_DEV_ONLY`

System IDE/debug UI.

Never part of retail player UX and excluded or hard-disabled in Shipping.

---

# 6. Boot and first-launch flow

Canonical shell flow:

```text
Application start
  ↓
platform/storage initialization if required
  ↓
first-launch quick accessibility/input setup OR existing profile settings
  ↓
Title
  ↓
Continue / Playthroughs / Settings / Credits / Quit(PC)
```

## 6.1 First-launch quick setup

On first launch, before the player is forced through story/gameplay, provide quick access to:
- subtitle/dialogue text visibility;
- text/UI scale preview;
- subtitle background/contrast;
- controller/KBM recognition;
- camera inversion/sensitivity basic setup;
- camera shake / reduced-effects baseline;
- audio master level;
- accessibility/settings full menu.

The setup is skippable and reversible.

It is not a questionnaire gate.

It must not ask the player to understand systems they have not encountered.

## 6.2 Logo/legal screens

If later publishing/legal requirements need them:
- keep duration short;
- allow skip where legally/contractually permitted;
- do not hide accessibility access behind a long unskippable sequence.

Exact legal/publisher screens are product-dependent and not currently authored.

---

# 7. Title screen

Required top-level actions:

1. **Continue** — loads the most recently used valid playthrough through Save authority;
2. **Playthroughs** — create/select/manage independent journeys;
3. **Settings** — includes Accessibility and Controls as first-class categories;
4. **Credits**;
5. **Quit to Desktop** on PC.

No base-game shell contains:
- multiplayer;
- battle pass;
- store carousel;
- daily challenges;
- news feed;
- account login gate;
- AI-generated-content panel.

## 7.1 Continue behavior

If no valid playthrough exists:
- Continue is unavailable with a clear reason or omitted according to final shell presentation;
- Playthroughs/New Journey receives initial focus.

If the newest generation cannot load but a valid Last Known Good generation exists:
- Continue routes through the recovery UX rather than silently rolling back history.

---

# 8. Playthrough selection and management

Stillring supports multiple independent playthroughs.

The UI displays **playthroughs**, not internal recovery generations.

Each playthrough card/list entry should derive and display at minimum:
- playthrough display label/index;
- last valid checkpoint/region description;
- accumulated playtime;
- last successful save time;
- story-progress descriptor that does not spoil unreached content;
- completion summary only from authoritative Completion Ledger, if the player has access to that presentation.

Internal `SnapshotId`, raw schema internals, LKG rotation or storage paths remain diagnostic unless recovery needs to explain a specific choice.

## 8.1 New playthrough

Flow:
1. choose New Journey;
2. if a finite slot/storage limit later exists, select replace/new location as appropriate;
3. confirm only if an existing journey would be destroyed;
4. initialize canonical new-game state through owning systems;
5. begin opening flow.

Do not invent a character creator, class selection or difficulty choice unless separate authority creates one.

If difficulty/access support is available at game start, it may be selected before play but remains changeable later according to its own authority.

## 8.2 Delete playthrough

Destructive action requires:
- explicit selection of the exact playthrough;
- a confirmation dialog naming/identifying that playthrough;
- a separate confirm action from the initial Delete command;
- clear statement that the journey will be removed.

Do not use a long hold as the only accessible confirmation mechanism.

Platform storage behavior may later impose additional requirements.

---

# 9. Pause menu information architecture

Default primary categories:

- **Map**
- **Journal**
- **Tools & Gear**
- **Completion**
- **Save**
- **Settings**

Secondary actions:
- Resume;
- Return to Title.

The exact visual arrangement may be tabbed, rail-based or another controller-safe structure.

The semantic categories are production authority.

Do not add:
- crafting;
- loot rarity management;
- skill tree;
- multiplayer/social;
- codex categories that have no authored content.

---

# 10. Exploration HUD

## 10.1 Baseline

Exploration HUD should remain sparse.

Required available information:
- compact player health/status presentation;
- currently relevant quick-use/item state where such a resource exists;
- contextual interaction prompt when a valid interaction candidate is present;
- selected/equipped tool state only when relevant;
- transient objective/record/save notifications;
- critical hazard/state warnings.

There is **no universal stamina meter** because no universal locomotion/combat stamina resource exists.

UI may not invent one for animation/exertion flavor.

## 10.2 Health visibility

Player health is critical state.

Default production rule:
- health is visible during combat, danger, damage/heal transitions and other states where immediate reading matters;
- exploration may use a compact persistent treatment or a validated context-fade treatment;
- if context fading is used, the player must be able to reveal/read health predictably and low-health danger cannot disappear.

Exact fade timing/always-visible option is **RUNTIME/ACCESSIBILITY-GATED**, not permission to make health unavailable.

## 10.3 Resources

Only real source-owned resources receive meters/counts.

Examples may include:
- health;
- item counts;
- tool-specific bounded state where the system actually owns one.

Do not create generic “mana,” “energy,” “integrity” or “tool charge” merely to fill HUD space.

---

# 11. Combat HUD

Combat HUD adds only information needed for fair tactical reading.

Required states:
- player health/critical state;
- target-lock identity marker;
- current targeted enemy read where combat production determines it is useful;
- off-screen committed-threat warning under `docs/55`;
- contextual unblockable/attack-class warning only if combat authority later defines such a player-visible class;
- boss/major-pressure presentation appropriate to the actual encounter grammar.

## 11.1 Target lock

Target-lock indicator must:
- clearly identify the currently locked semantic target;
- survive ordinary camera motion without excessive jitter;
- break promptly when target-lock authority ends;
- transfer across a valid Hush paired expression only when the same semantic target remains valid;
- never auto-select a replacement simply because the UI needs a marker.

A target marker is presentation of Targeting state.

It does not own target selection.

## 11.2 Enemy vitality display

Stillring does **not** currently require one universal enemy-health-bar rule.

Classification: **RUNTIME-GATED / COMBAT-READABILITY DECISION WITHIN BOUNDS**.

Evaluate in Gate 2 with representative ordinary enemies, shields, ranged enemies, multi-enemy encounters and bosses.

Allowed outcomes include:
- target-only vitality;
- compact local vitality;
- no ordinary enemy numeric/bar vitality where embodied reaction gives sufficient information;
- encounter-specific treatment.

Acceptance criteria:
- player can understand progress/consequence without UI noise;
- target switching remains readable;
- health presentation does not teach the player to ignore body/armor/mechanism state;
- non-health-bar encounters are not forced into fake health semantics;
- accessibility does not depend on subtle body damage alone if progress information is necessary.

Whatever passes is promoted into Combat/UI tuning authority.

## 11.3 Off-screen committed threat indicator

This system is **LOCKED** by `docs/55`.

It may communicate:
- coarse direction around the player/screen edge;
- that a threat is already committed;
- broad urgency only if human testing proves direction alone insufficient;
- a small response-relevant class only if separately authorized.

It may not reveal by default:
- exact enemy position;
- identity/name;
- enemy health;
- exact distance;
- path around walls;
- noncommitted enemies;
- scheduler scores;
- objective relevance.

No urgent indicator appears for mere enemy presence/readiness/repositioning.

If several simultaneous indicators become common, encounter bandwidth has failed; UI must not normalize radar clutter.

Accessibility may strengthen size/contrast/timing or substitute stricter attack eligibility when indicator presentation is disabled.

## 11.4 Boss / major-pressure HUD

Boss presentation follows encounter grammar.

Possible information families:
- health/vitality when actual combat health is the progress model;
- machine-state progress;
- component release state;
- pressure/alignment state;
- contradiction/preservation state;
- objective text for a non-health-bar resolution.

Hard rule:

> **Do not put a health bar on an encounter whose canonical resolution is not health depletion merely because bosses usually have bars.**

Listener is explicitly not presented as a third conventional health-bar boss.

---

# 12. Interaction prompts

A prompt answers:

> **What deliberate action is available right now?**

It should include:
- current mapped action glyph/text;
- concise verb/action label where needed;
- target/object label only when knowledge/clarity warrants it;
- hold/toggle semantics if the active setting changes the input behavior.

Prompt rules:
- proximity alone does not imply action if gameplay says target is invalid;
- prompt disappears/rebinds when interaction eligibility changes;
- no delayed “ghost prompt” after movement leaves the candidate;
- planted interaction alignment is not hidden by a prompt that appears before local alignment is valid;
- invalid state may provide a short reason only when useful, not constant nag text.

Examples of useful failure text:
- `Blocked`;
- `No clear load path`;
- `Route dormant`;
- `Cannot save during combat`.

Failure text must match semantic source reason codes rather than guessing from presentation.

---

# 13. Cantor UI

Cantor is diagnostic/procedural, not detective vision.

UI must preserve that distinction.

Required presentation states:
- Listen invoked;
- candidate relationship clear;
- ambiguous;
- not actionable;
- none;
- blocked;
- temporary diagnostic focus;
- known applicable procedures;
- procedure result;
- re-measure state.

The UI may show:
- bounded local focus;
- relationship/tone-pattern visualization;
- procedure choices the player actually knows;
- source-owned failure reason.

It may not show:
- through-wall objectives;
- hidden collectibles;
- privileged puzzle solution metadata;
- “correct target” gold outline;
- map-wide scan results;
- generic enemy weakness list unless another system explicitly grants that knowledge.

Tone/pattern relationships must have non-audio and non-color-only representation.

---

# 14. Anchor Line UI

The Anchor interface should explain a physical load relationship rather than behave like a grappling reticle.

Relevant contextual states:
- no candidate;
- candidate;
- incompatible candidate;
- latched;
- load path clear/blocked;
- tension/load band;
- static brace owned/available;
- traversal eligible/ineligible;
- reclaim/release;
- component/mechanism state when already exposed by world/gameplay.

No UI marker may make arbitrary fixed geometry look Anchor-compatible when gameplay says it is not.

No quest metadata may make one visually identical Anchor target glow as “the puzzle solution.”

---

# 15. Other tool UI

Each later tool receives the same production test:

1. what state is source-owned?;
2. what does the player need to know now?;
3. what may be learned through world form/audio before UI?;
4. what failure reason is useful?;
5. what would become a cheat/solution overlay if exposed?;
6. what accessibility redundancy is required?

Tool interfaces must share visual grammar while preserving distinct physical semantics.

Do not reuse one generic spell-reticle/state wheel for every tool.

---

# 16. Hush UI

Hush identity is primarily world-space visual/audio/semantic presentation.

UI does not need to label the entire screen `HUSH` continuously.

Required UI responsibilities:
- seam interaction prompt/state where a valid transition is available;
- rejected transition reason when useful;
- brief committed transition feedback;
- rebind target/tool/prompts to destination semantic expressions;
- preserve save-deferred explanation during in-flight seam;
- map/journal annotations only where the player has authored knowledge of a Hush relation.

No separate universal “Hush map” becomes a duplicate world database.

Reduced Hush Effects must preserve semantic UI cues.

---

# 17. Line Skiff HUD

The Skiff HUD communicates route operation, not racing statistics.

Required contextual information:
- coupled/boarded state;
- current compatible route/segment status;
- upcoming known junction/branch state when world visibility alone is insufficient at Skiff speed;
- dormant/wakeable route cue for Roadhand Pulse;
- unavailable/blocked route reason;
- route transfer cue after Switchshoe is owned;
- trial/relay-specific mechanical-window state where the Trial contract requires it.

Do not add by default:
- leaderboard timer;
- permanent speedometer unless human testing proves it materially improves handling;
- minimap racing line;
- boost meter;
- fuel/stamina meter;
- summon/mount UI.

Exact handling instrumentation is **RUNTIME-GATED** against the acquisition/mastery course.

Fast should read as route fluency, not dashboard complexity.

---

# 18. Map philosophy

The map is an orientation and memory tool.

It is not an optimization layer.

Governing rule:

> **Show the world the player has learned, not every task the database can enumerate.**

## 18.1 Map content families

May include:
- region/major landform boundaries;
- named settlements and major landmarks once known;
- Waybells/stations once discovered;
- Line Skiff network segments and known route state;
- known entrances/refuges/major civic sites;
- quest-relevant named places the player has actually learned about;
- player-authored or bounded player markers if later UX testing justifies them;
- completion-assist disclosures only under Completion authority.

Do not show by default:
- every enemy;
- all unopened collectibles;
- all side quests as exclamation marks;
- optimal path lines;
- exact hidden puzzle targets;
- all Hush variants as a duplicated second map;
- future region content before discovery.

## 18.2 Objective location grammar

Objectives should point to **known places/relationships**, not GPS truth.

Examples:
- `Ask at the Tide Foundry`;
- `Return to Dori at the Road Inn`;
- `Follow the old reinforcement route past Graymile`.

When the player has legitimately learned an exact location, a marker may represent that knowledge.

Do not convert vague story knowledge into an exact pin simply because the quest system has coordinates.

## 18.3 Player position / compass decision

Exact baseline player-marker and compass treatment remains **RUNTIME-GATED NAVIGATION UX**.

Evaluate:
- landmark recognition;
- region scale;
- route density;
- indoor/dungeon clarity;
- accessibility/spatial-orientation needs.

Any selected treatment must:
- support orientation without becoming constant GPS routing;
- preserve landmark-reading design;
- have clear world/map correspondence;
- be adjustable where appropriate.

## 18.4 Completion assistance

Completion UI may reveal progressively more help only according to the completion/disclosure policy in current Completion authority.

The map itself never becomes a universal spoiler switch that exposes every remaining object.

---

# 19. Journal information architecture

The Journal records what Neris has learned and committed to.

Primary information families:

## Commitments

Main/side commitments currently accepted or active.

Each entry may include:
- title;
- current plain-language objective/commitment;
- known region/place;
- relevant people;
- key discovered facts/clues;
- recent update;
- completed/resolved state.

No internal quest-state enum is shown to the player.

## Clues / Findings

For investigative/systemic information that matters across more than one line of dialogue.

Must distinguish:
- observed fact;
- reported/testimony fact;
- inferred/diagnostic relationship where authored.

Do not automatically mark one conflicting testimony “true” before the narrative does.

## Records / Testimonies

Player-acquired authored documents and testimony entries.

Requirements:
- original title/source/provenance when known;
- discovery context;
- readable body text;
- spoiler-safe undiscovered handling;
- localization-ready layout;
- related-entry links only when the player has actually learned the relationship.

## Recent dialogue

Provide a reviewable recent-text history sufficient to recover from missed/advanced dialogue.

This is **presentation history**, not canonical quest-state truth.

Rules:
- speaker identified;
- newest entries easy to reach;
- long sessions may use bounded history according to technical limits;
- critical quest meaning must also be reflected in durable journal/quest facts rather than requiring an infinitely persistent transcript;
- cinematic/dialogue skip must not erase already-committed journal facts.

## Completed history

Resolved commitments remain reviewable unless narrative secrecy requires a bounded presentation exception.

---

# 20. Spoiler control

UI must distinguish **unknown** from **missing**.

Undiscovered content should not reveal names/descriptions merely because completion has a canonical total.

Allowed disclosure styles:
- `Undiscovered`;
- category progress count without item identity;
- silhouette/question-mark slot only when the category UI intentionally exposes capacity;
- region-level hints only after their disclosure condition is met.

Do not expose:
- boss names before discovery;
- secret region labels;
- future character outcomes;
- Hush relation details;
- finale sequence names;
- optional completion rewards before the game would naturally explain them.

Completion assistance may become more explicit late/postgame only under its own authority.

---

# 21. Tools & Gear screen

This screen presents owned capabilities and functional equipment.

Required sections:
- Cantor Key and known patterns/procedures;
- owned field tools;
- owned upgrades/capabilities;
- quick-use items/resources if the game retains them;
- equipped/current relevant configuration where an actual choice exists.

Do not create:
- loot rarity colors;
- item-score treadmill;
- gear-stat comparison grid without authored stat system;
- crafting tree;
- random affix display;
- inventory encumbrance if no source system owns it.

Each tool entry should answer:
- what it does in player language;
- how it is used;
- what procedures/upgrade capabilities are known;
- relevant mapped input;
- newly learned use without spoiling undiscovered uses.

---

# 22. Completion screen

Completion is derived from the authoritative Completion Ledger.

UI must never persist its own completion truth.

Requirements:
- use current canonical category names/counts/weights from Completion authority;
- use current canonical total of **16 equal completion categories** unless a newer authority supersedes it;
- show category-level progress in a way that survives localization and large text;
- no stale literal counts from superseded drafts;
- completion percentage is derived, not saved as a second database;
- optional completion does not imply a “true ending” gate;
- completion rewards/disclosures follow their actual prerequisite authority.

If a category has hidden members, show only the amount of identity/hint information permitted by spoiler/disclosure rules.

---

# 23. Save UX

Save UI follows `docs/88`.

## 23.1 Manual Save

Available from ordinary controllable gameplay at a safe semantic boundary.

If currently unavailable, the command is either temporarily disabled with a clear reason or accepts a deferred request only where Save authority explicitly supports that behavior.

Blocked/deferred reasons include:
- active hostile combat;
- in-flight Hush seam;
- unsafe traversal microstate;
- unsettled cross-domain transaction;
- map/load transition;
- another save/load operation.

Do not simply gray out Save with no explanation.

## 23.2 Save status

Required transient states:
- `Saving…`
- `Saved`
- `Save Failed`

`Saved` appears only after the storage publication result required by Save authority.

A spinner is not proof of success.

## 23.3 Autosave

Autosave should use a restrained indicator that confirms meaningful storage activity without training the player to wait for every minor action.

Do not show an icon continuously if no save is in progress.

## 23.4 Recovery

When newest data fails but a valid recovery generation exists, tell the player:
- the newest save could not be used;
- an earlier verified recovery point is available/was selected according to recovery policy;
- its timestamp/playtime/checkpoint summary;
- that some recent progress may be rolled back.

Do not silently pretend the earlier state was the newest save.

## 23.5 Failure categories

Player-facing messages must distinguish at least:
- storage/write failure;
- corrupt/invalid newest generation with recovery available;
- corruption with no valid recovery;
- save created by newer unsupported game version;
- unsupported historical version/migration failure;
- representation reconstruction failure where the game cannot safely continue.

Raw internal error codes may be available in diagnostics but player copy must explain the actionable consequence.

---

# 24. Death / retry UX

Death state is not a disk-save event.

Required death/retry screen actions:
- **Retry** — restore the dedicated Retry Checkpoint Snapshot through authoritative recovery flow;
- **Load / Playthroughs** — optional secondary path for the player who wants a durable save generation instead;
- **Settings** — accessibility/input changes remain available;
- **Return to Title**.

Retry must not be labeled `Load Last Save` unless it actually does that—which canonical authority says it normally does not.

The screen should communicate loss/retry quickly rather than requiring multiple menus after routine failure.

No monetized revive, consumable revive prompt or score penalty is assumed.

---

# 25. Settings information architecture

Settings/profile persistence is separate from playthrough world state.

Primary categories:

1. **Controls**
2. **Camera**
3. **Accessibility**
4. **Audio**
5. **Display / Graphics**
6. **Gameplay**
7. **Language** when localization options exist

Exact visual grouping may combine categories on smaller menus without hiding them.

---

# 26. Controls settings

Required:
- action-centric remapping;
- separate controller and keyboard/mouse bindings where appropriate;
- controller dead-zone settings within safe bounds where authorized;
- look sensitivity;
- movement/input accessibility Hold/Toggle options;
- reset category/defaults;
- current glyph previews;
- conflict detection.

No gameplay rule depends on a hard-coded physical key.

## 26.1 Rebinding flow

```text
Select semantic action
  ↓
Choose binding slot/device if needed
  ↓
Listening state
  ↓
Receive physical input
  ↓
Validate reserved/unsupported/conflicting input
  ↓
Apply / Swap / Replace / Cancel
  ↓
Refresh prompts immediately
```

## 26.2 Conflict behavior

When a new binding conflicts:
- show the conflicting action;
- offer a clear replacement/swap resolution where technically valid;
- allow Cancel;
- do not silently unbind a required action.

If duplicates are semantically safe and intentionally supported, label that behavior clearly.

## 26.3 Required-action safety

The player must not leave Controls in a state that makes core menu/gameplay recovery impossible without a clear repair path.

Provide:
- Restore Defaults;
- restore required/unbound actions;
- an always-recoverable navigation path appropriate to PC/controller platform behavior.

Do not use “you cannot remap this” broadly as the cheap fix.

---

# 27. Controller navigation / focus contract

Every retail interactive screen must be fully usable without a mouse.

## Focus rules

- exactly one primary focus target when a screen/modal opens, unless the screen is intentionally pointer-only—which retail screens are not;
- focused element has visible non-color-only treatment;
- directional movement follows spatial/list order predictably;
- no hidden focus on disabled/invisible elements;
- closing a child/modal returns focus to the initiating or nearest valid parent control;
- tab/category changes set focus to a sensible retained/default element;
- scroll containers keep focused content visible;
- lists/grids have deterministic boundary behavior;
- long text provides clear scroll position and a reliable way back to controls;
- modal focus cannot escape behind the dialog;
- destructive confirm is not the default focused choice when accidental activation is plausible.

## Navigation input

Primary UI navigation uses non-simultaneous inputs.

Do not require:
- holding one modifier while selecting another command;
- rapid repeated presses;
- analog precision to reach a menu item;
- mouse-only drag interactions.

Where sliders exist, provide digital step adjustment.

---

# 28. Keyboard / mouse parity

Every retail screen must be usable with keyboard and mouse on PC.

Required behavior:
- pointer hover/click;
- visible keyboard focus;
- wheel scrolling where expected;
- keyboard navigation through lists/grids;
- page/home/end or equivalent support for long lists where useful;
- text fields only when product actually needs text input;
- no controller glyph embedded permanently into texture art.

## Pointer / focus coexistence

Input modality may switch between mouse and controller/keyboard.

Rules:
- switching device updates prompt glyphs after a small anti-flicker/debounce policy;
- incidental mouse jitter should not steal focus continuously from controller use;
- a deliberate mouse hover/click may establish pointer target/focus;
- returning to controller/keyboard restores a clear focus state;
- there is never a frame where the user cannot tell what Confirm will activate.

Exact device-switch debounce is runtime/UI tuning.

---

# 29. Camera settings

Current baseline requires:
- horizontal/vertical look sensitivity as supported by Camera authority;
- invert Y;
- invert X where Camera authority supports it;
- camera shake control;
- controller look dead-zone/response settings within safe bounds;
- reset defaults.

Potential FOV, auto-recenter strength, camera-distance or other comfort controls require Camera/runtime evaluation so they do not silently alter encounter/traversal visibility assumptions.

Where permitted, expose them with safe bounded ranges and clear effects.

---

# 30. Accessibility settings

Accessibility is a production baseline, not a post-launch submenu.

Required current categories include:

## Text / subtitles
- dialogue/subtitle visibility as applicable;
- subtitle size;
- subtitle background/contrast;
- speaker identification;
- caption support for critical non-speech audio when the final Audio package defines cue inventory;
- UI text scaling;
- readable focus/selection contrast.

## Motion
- camera shake reduction/off;
- Reduced Effects;
- Reduced Hush Effects;
- avoid required flashing/strobing;
- motion-comfort controls promoted by Camera authority.

## Input
- remapping;
- Hold/Toggle alternatives where feasible/authorized;
- dead-zone adjustment;
- sensitivity;
- avoid rapid/repeated/simultaneous input requirements as the only path for baseline actions;
- timing accommodations where the owning gameplay system explicitly supports them.

## Visual information
- critical cues non-color-only;
- scalable off-screen threat indicator;
- readable target/focus state;
- UI text scale;
- reduced decorative VFX that obscure gameplay.

## Audio substitution

Critical gameplay information may not be audio-only.

The final Audio/Accessibility package must identify critical cue classes requiring captions/text/visual support.

## Screen narration

Semantic labels, reading order and control naming should be authored so a future screen-reader/narration implementation is technically possible.

Whether full retail screen narration ships is **PRODUCT/ACCESSIBILITY IMPLEMENTATION-GATED** until target platforms, UI framework and accessibility QA define support quality.

Do not fake a narration claim before tested output exists.

---

# 31. Subtitle and caption presentation

## Dialogue subtitles

Requirements:
- speaker identified when ambiguity matters;
- high contrast against scene;
- player-adjustable size/background;
- semantic line breaks;
- avoid excessive characters/line density;
- normally no more than two subtitle lines at once unless accessibility/localization testing proves a controlled exception;
- remain readable in bright/dark/Hush scenes;
- no critical dialogue lost because the player opened another non-destructive interface.

## Captions

The Audio package will determine exact caption cue families.

Minimum future coverage includes significant gameplay-relevant non-speech cues that otherwise rely on hearing, such as:
- off-screen committed threat reinforcement where needed;
- critical mechanism state change;
- key Cantor/resonance response;
- major environmental hazard warning;
- required narrative sound event.

Captions should convey meaning/source, not dump every ambient sound into text.

---

# 32. Audio settings UI

Prepare categories for:
- Master;
- Music;
- SFX/gameplay;
- Ambience;
- Dialogue/VO if VO exists;
- UI;
- dynamic-range/mix accessibility options if the final Audio Bible supports them.

If VO is not part of the final product, do not show a dead Dialogue Volume control merely because the UI template has one.

---

# 33. Display / graphics settings

Exact rendering options depend on Technical Production and target PC.

The UI must be able to represent later:
- display mode;
- resolution;
- refresh/frame cap where supported;
- VSync/latency options where supported;
- quality/scalability tiers;
- selected renderer feature toggles only if the technical stack exposes meaningful user choices;
- brightness/gamma calibration;
- UI scale independent of 3D render resolution.

Do not pre-populate settings for Lumen, Nanite, upscalers, frame generation, ray tracing or HDR until those product/technical decisions exist.

---

# 34. Gameplay settings

This category presents player-facing options actually authorized by system design, such as:
- target/facing assistance mode where Combat authority supports Standard / Reduced / Off;
- off-screen threat indicator presentation mode;
- timing/access assists when authoritative gameplay systems define them;
- hold/toggle input options;
- tutorials/hints presentation where allowed.

Do not invent a global difficulty slider until the Difficulty/QA production authority defines what it changes.

If difficulty modes later exist, the screen must explain actual semantic effects rather than vague `Easy / Normal / Hard` adjectives alone.

---

# 35. Tutorial / help UX

Tutorials teach one immediately useful relationship at a time.

Presentation may use:
- short contextual prompt;
- small diagram;
- journal/help entry after discovery;
- safe practice area;
- System-specific retry/hint.

Do not:
- dump full controller diagrams before the player needs them;
- pause every new interaction with multi-page text;
- make tutorial dismissal permanently erase critical help;
- reveal future tool uses or puzzle solutions.

Every tutorial concept should be reviewable later in a Help/Controls reference if it remains relevant.

---

# 36. Dialogue UX

Dialogue should be fast to read/advance and visually subordinate to character/world performance.

Required:
- speaker name where needed;
- dialogue text;
- advance/continue prompt when player-driven;
- choice presentation only when narrative authority creates a real player choice;
- recent-text review;
- subtitle/accessibility settings;
- skip/advance behavior aligned with cinematic/narrative state commits.

Do not manufacture dialogue wheels or fake moral choices where story authority does not define them.

Choice list navigation:
- one clear focus;
- explicit confirmation;
- no accidental auto-selection from a held movement input crossing into dialogue;
- choices localize/scale cleanly.

---

# 37. Error and warning philosophy

Every error should answer:

1. **What happened?**
2. **What does it mean for me?**
3. **What can I do now?**

Avoid generic `Something went wrong` when the system knows the class.

Avoid technical jargon unless a details panel is deliberately offered for diagnostics.

Error UI may not promise recovery the source system cannot guarantee.

---

# 38. Required error/warning catalog

At minimum retail UX must define presentation for:

## Save / storage
- save in progress;
- save deferred + reason;
- save failed;
- load failed;
- corrupt newest with recovery available;
- corrupt/no valid recovery;
- newer-version incompatible save;
- unsupported historical/migration failure;
- insufficient/write-protected storage where platform exposes it;
- destructive playthrough delete.

## Input
- controller disconnect;
- active device changed;
- binding conflict;
- required action unbound;
- unsupported/reserved key;
- reset-controls confirmation.

## Display/settings
- settings change requiring confirmation/revert where a bad display mode could make UI unusable;
- restore defaults;
- unsupported setting combination if technical production has one.

## Gameplay-context
- manual save unavailable/deferred;
- route unavailable;
- interaction/tool blocked reason where useful;
- seam unavailable;
- inventory/resource full only if an actual bounded inventory/resource system creates that state.

## Content/version
- required content unavailable/incompatible if future patch/DLC architecture ever creates that state;
- do not display online-service errors in the base product unless such a service actually exists.

---

# 39. Confirmation policy

Require confirmation for destructive or hard-to-reverse player actions such as:
- delete playthrough;
- reset all settings/controls;
- return to title only when doing so can lose uncommitted presentation/work according to actual save state;
- overwrite/replace data if a later finite-slot model requires it.

Do **not** require confirmation for:
- Resume;
- opening Map/Journal;
- ordinary settings sliders with preview/revert;
- routine Retry after death;
- ordinary save request.

Confirmation copy names the affected thing, not just `Are you sure?`.

---

# 40. Credits / post-credits UX

Credits presentation must support:
- controller and KBM scroll/skip controls;
- pause/continue according to final cinematic authority;
- readable role/name text at UI-scale settings;
- localized headings where appropriate;
- completion-specific or branch-specific credits vignettes/text only from canonical finale/credits authority;
- post-credits transition without corrupting save/epilogue state.

Exact credit inventory and postgame return behavior remain Narrative/Cinematic production dependencies.

---

# 41. Typography requirements

The UI art manifest defines role categories, not a final font family yet.

Requirements:
- readable body text at ordinary PC viewing distance;
- mixed-case body copy;
- sufficient distinction among heading/body/caption/number roles;
- tabular numerals where rapidly changing counts benefit;
- clear punctuation and diacritics;
- broad Latin/extended-character support at minimum during prototyping;
- final font licensing/localization coverage checked before production lock;
- no lore-display typeface used for long body text if it reduces legibility;
- no critical text baked into images.

Final font selection is **UI ART / LOCALIZATION PRODUCTION CHOICE WITHIN BOUNDS**.

---

# 42. Text scale and layout resilience

Layouts must be designed for:
- UI text scale increase;
- subtitle scale increase;
- long localized strings;
- multi-line buttons where necessary;
- right-to-left/bidirectional feasibility if selected languages require it;
- different aspect ratios without placing critical controls outside safe view;
- controller glyph/text expansion.

Production target:
- interfaces should remain functional at **200% text scale** as an accessibility stress test, even if the exact retail slider maximum is finalized through UI/accessibility validation.

This is a layout robustness requirement, not a promise that every decorative element doubles identically.

---

# 43. Contrast / focus readability

Use current accessibility guidance as a minimum design target for text/focus legibility rather than a legal certification claim.

For production evaluation:
- ordinary text should aim for at least 4.5:1 contrast against its effective background where feasible;
- large text may use the standard lower 3:1 threshold;
- interactive focus/selection must be visible through shape/border/motion/value, not hue alone;
- text over world imagery uses backing/shadow/plate treatment sufficient to preserve readability.

Where artistic treatment conflicts with gameplay/UI readability, readability wins.

---

# 44. Icon and glyph semantics

Icons communicate semantic action/state, not franchise convention.

Required rules:
- every gameplay-critical icon has a text/shape/context equivalent where needed;
- no color-only category distinction;
- tool icons derive from Stillring’s own tool silhouettes/mechanisms;
- Cantor patterns use relationship notation, not copied musical-note/song UI;
- controller prompts render the currently mapped physical binding;
- keyboard/mouse prompts render current mapped key/button;
- unknown/unrecognized gamepad falls back to a generic readable gamepad glyph set rather than lying about ABXY/shape labels;
- do not bake controller legends into textures.

---

# 45. Localization text pipeline boundary

All player-facing production text must be localization-ready.

Use Unreal-localizable text representation (`FText` or the later Technical Production equivalent) rather than hard-coded display strings in gameplay logic.

Each significant line/entry should be able to carry:
- stable text ID;
- speaker/source;
- UI context;
- character/length constraint where real;
- variable placeholders;
- plural/gender/pronoun context where needed;
- spoiler/state notes;
- pronunciation/performance note for VO where relevant.

UI may display derived values; grammar around those values must localize correctly.

---

# 46. UI animation / motion

UI motion should explain hierarchy/state change, not perform constantly.

Allowed purposes:
- focus transition;
- panel enter/exit;
- save/status feedback;
- target/threat urgency;
- acquisition significance;
- category change;
- modal depth.

Avoid:
- long blocking menu flourishes;
- constant pulsing every button;
- large parallax/sway tied to mouse/stick by default;
- Hush-specific UI glitching that harms text;
- motion that makes focused item difficult to read.

Reduced Effects must simplify nonessential UI motion without removing state/focus information.

---

# 47. UI sound / haptics boundary

UI audio/haptics reinforce:
- focus/confirm/back;
- error;
- acquisition;
- save result;
- meaningful mode/state transition.

They cannot be the only signal for:
- failed save;
- destructive selection;
- target/threat state;
- settings change;
- focus location.

The Audio Bible will define final cue families/mix priority.

---

# 48. Persistence of UI/profile state

Settings/profile persistence is separate from playthrough state.

Persist as profile/user settings where supported:
- remappings;
- subtitle/caption settings;
- UI text scale;
- camera sensitivity/inversion;
- shake/reduced-effects choices;
- audio settings;
- display/graphics settings appropriate to machine/user scope.

Do not persist as canonical playthrough world truth:
- open pause tab;
- selected journal row;
- hover/focus;
- target marker state;
- current HUD fade;
- dialogue scroll position;
- transient toast queue.

Per-machine versus per-user storage scope is a Technical/Product implementation detail.

---

# 49. Controller disconnect

If active controller disconnects:
- gameplay pauses or enters a safe input-held state where the owning gameplay context allows;
- present a clear reconnect/switch-input dialog;
- keyboard/mouse can take over on PC without forcing restart;
- dialog is keyboard/controller navigable;
- reconnect returns to the prior valid context without duplicating input requests.

Do not interpret disconnect as gameplay action release/confirmation in a way that drops Neris from a ledge or confirms a menu action.

Exact pause behavior in online/network contexts is irrelevant because base game is single-player/offline-authored.

---

# 50. UI quality gates

## UI-A — wireframe / state authority

Requires:
- full screen/state inventory;
- data owner for every displayed value;
- controller and KBM flow;
- modal/return focus rules;
- empty/loading/error states;
- localization stress strings.

## UI-B — visual prototype

Requires:
- typography hierarchy;
- focus/selection system;
- icon/glyph family;
- exploration/combat HUD mockups;
- map/journal prototype;
- save/recovery prototype;
- subtitle/accessibility prototype.

No runtime proof implied.

## UI-C — interactive UE5.8 implementation

Future runtime gate.

Requires:
- controller + KBM complete traversal;
- remapping updates prompts;
- authoritative source-state binding;
- no focus traps;
- large-text/localization stress;
- save/recovery real integration;
- combat/threat/Cantor/Skiff context transitions.

## UI-D — accessibility/localization validation

Future runtime/human gate.

Requires:
- contrast/text scale;
- subtitle/caption readability;
- motion/reduced-effects;
- remap recovery;
- controller disconnect;
- color-independent states;
- pseudo-localization;
- representative assist modes.

## UI-E — shipping validation

Requires selected target platform/hardware, packaging, platform-specific glyph/certification behavior if any, and final performance/accessibility evidence.

---

# 51. UI System IDE / debug support

The retail UI has no independent shadow IDE.

Development UI diagnostics should integrate with source System IDEs and a UI review surface.

## Inspect

Expose:
- current UI layer stack;
- focus owner/current focus;
- active input device/context;
- semantic action→physical binding resolution;
- displayed data source/owner;
- last source update;
- prompt candidate/reason;
- HUD visibility reasons;
- subtitle/caption current cue;
- map/journal entry unlock source;
- save-status source;
- localization key/text context;
- UI scale/aspect ratio;
- accessibility modes.

## Exercise

Provide presets for:
- controller-only menu traversal;
- keyboard-only traversal;
- mouse/controller switching;
- all major HUD states;
- off-screen threat warning;
- Cantor/Anchor states;
- Skiff route states;
- Hush seam states;
- save/deferred/fail/recovery;
- long quest/record text;
- subtitle/caption overlap;
- 200% text scale;
- pseudo-localization;
- low contrast/color-vision simulation;
- controller disconnect;
- every modal/error state.

## Validate

Detect:
- no focusable control in an active modal;
- hidden focus;
- focus behind modal;
- unmapped required action;
- prompt glyph != active binding;
- UI value diverging from source owner;
- stale target/threat prompt;
- save success shown before source confirmation;
- non-localizable display string;
- clipping/overlap under stress strings/text scale;
- critical state encoded only by color/audio/haptic;
- dev-only UI exposed in Shipping.

---

# 52. Research basis

Current external guidance was used only to establish professional production/accessibility practice, not to create a platform commitment.

## Epic Games — Unreal Engine 5.8

- CommonUI documentation: layered UI/input routing/controller-navigation candidate framework.
- CommonUI input/navigation guidance: explicit desired focus and predictable navigation.
- Text Localization: user-facing localized text through Unreal localization (`FText`).
- UE5.8 release notes: current CommonUI/text-scale and input improvements.

## Microsoft Game Accessibility Guidelines

Used as cross-platform design guidance, **not an Xbox launch commitment**:
- XAG 107 — input/remapping and avoiding unnecessary complex input requirements;
- XAG 112 — predictable UI navigation/focus;
- XAG 104 — subtitle/caption customization and critical audio representation;
- XAG 101/102 — readable text and contrast.

## W3C WCAG 2.2

Used as a general interface-legibility stress reference:
- text contrast guidance;
- focus visibility;
- text resizing/layout robustness.

No certification conformance claim is made by this documentation.

---

# 53. Decision rights

## LOCKED

- minimal/contextual HUD philosophy;
- UI is derived presentation, not gameplay-state owner;
- map favors landmarks/routes over icon spam;
- journal records commitments/clues, not GPS truth;
- controller-first with full KBM support;
- remappable gameplay input;
- save/retry/recovery semantics from Save authority;
- off-screen committed-threat indicator limits from `docs/55`;
- critical information not color/audio/haptics-only;
- Hush UI cannot become a duplicate world-state system;
- Completion UI derives current authoritative completion facts;
- no live-service/store/multiplayer shell;
- dev System IDE UI not retail.

## STUDIO CHOICE WITHIN BOUNDS

- UMG/Slate/CommonUI implementation;
- panel/tab visual arrangement;
- exact animation/easing;
- final icon drawing style within UI art grammar;
- final typeface after readability/licensing/localization review;
- exact focus ornament treatment;
- exact internal widget architecture.

## RUNTIME-GATED

- exact HUD fade timings;
- ordinary enemy vitality presentation;
- exact player-map-marker/compass treatment;
- exact UI scale range beyond the 200% stress test;
- exact threat-indicator blend/timing;
- exact Skiff handling instrumentation;
- exact focus/device-switch debounce;
- final camera comfort controls/ranges;
- final contrast/backplate tuning in representative scenes;
- actual screen narration shipping support;
- final PC graphics settings list.

## TBD PRODUCT / OWNER LATER

- platform-specific UI/certification scope beyond PC-first;
- ship-language list;
- VO scope, which affects subtitle/lip-sync/audio controls but not the need for text accessibility;
- commercial title/branding.

---

# 54. Governing UI rules

1. **Show what the player needs, not everything the database knows.**
2. **UI reflects source truth; it never becomes source truth.**
3. **The world carries identity; HUD carries urgent clarity.**
4. **A map is for orientation, not checklist optimization.**
5. **A journal records knowledge, not internal quest enums.**
6. **An off-screen warning is not radar.**
7. **A boss UI reflects its actual resolution grammar.**
8. **Save UI must tell the truth about save, rollback and retry.**
9. **Every screen works with controller and keyboard/mouse.**
10. **Focus is visible, deterministic and recoverable.**
11. **Accessibility changes ergonomics/presentation without creating hidden shadow gameplay.**
12. **Localization is an authoring input, not a final export step.**
13. **Exact runtime values are promoted from evidence, not template defaults.**

This specification is complete only together with the screen/state/asset manifest.