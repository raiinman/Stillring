# 177 — UI Screen / State / Asset Production Manifest

**Status:** ACTIVE / STUDIO-HANDOFF UI PRODUCTION INVENTORY / DOCUMENTATION-ONLY  
**Updated:** 2026-09-06  
**Parent:** `docs/176_UI_UX_PRODUCTION_SPECIFICATION.md`  
**Program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Decision rights:** `docs/170_STUDIO_DECISION_RIGHTS_MATRIX.md`  
**Product boundary:** `docs/171_PERFORMANCE_PLATFORM_PRODUCT_BRIEF.md`  
**Closes toward:** `SH-UI-001`–`SH-UI-010`  
**Boundary:** this file inventories UI production burden and source-state dependencies. It does not authorize UMG/Slate/CommonUI implementation, final graphic design, final fonts, final pixel metrics, platform-certification UI, runtime accessibility claims, or invented gameplay state.

---

# 1. Purpose

`docs/176` defines what Stillring's player-facing interface is allowed to do.

This manifest answers the production question that remains:

> **Exactly which retail UI surfaces, state variants, reusable components, icons, glyphs, text roles, error states and validation fixtures must a studio design and build?**

It prevents several common scope failures:

- budgeting “HUD + menus” as though that were one screen;
- discovering save recovery, remapping or accessibility states late;
- building only happy-path screens;
- creating controller flow after mouse layouts are already finished;
- letting every gameplay system commission unrelated prompt/icon language;
- hiding localization and large-text burden until final QA;
- treating System IDE/debug surfaces as retail UI.

The governing production rule is:

> **A screen is not one asset. A production screen is a family of data states, navigation states, error states and responsive-layout states.**

---

# 2. Manifest vocabulary

## UI surface

A distinct player-facing screen, HUD cluster, overlay, modal or shell surface with its own information/action contract.

## State variant

A meaningfully different presentation state driven by authoritative source data.

Examples:
- no save exists;
- save valid;
- save unavailable during combat;
- recovery available;
- controller disconnected;
- Cantor result ambiguous.

State variants are not automatically separate widgets or art files.

## Layout family

A shared compositional system that may serve multiple surfaces.

Examples:
- title/shell menu;
- tabbed pause content;
- long-form reading panel;
- confirmation modal;
- HUD toast.

## Data owner

The authoritative system from which UI derives displayed state or to which it sends a validated request.

UI never becomes a second owner.

## Focus entry

The element that should receive primary controller/keyboard focus when the surface opens in the named state.

## Exit/return target

The surface or initiating control that receives focus/context after Close/Back/Cancel.

## Asset burden

The authored visual/text/icon/glyph/motion/sound-support package required to present the surface.

---

# 3. Surface ID convention

Production-facing IDs use:

`UI.<Domain>.<Surface>`

Examples:
- `UI.Shell.Title`
- `UI.Pause.Map`
- `UI.HUD.Combat`
- `UI.Save.Recovery`

State IDs may append:

`UI.<Domain>.<Surface>.<State>`

Examples:
- `UI.Save.Manual.BlockedCombat`
- `UI.Input.Rebind.Conflict`
- `UI.Cantor.Listen.Ambiguous`

These are repository production identifiers, not a requirement for exact future C++/Blueprint class names.

---

# 4. Global source-owner rules

| Displayed/requested state | Authoritative source / requester target | UI rule |
|---|---|---|
| Playthrough/save validity | Save Coordinator / Save authority | never infer from slot card existence |
| Player health | Player health/progression owner | presentation only |
| Target lock | Camera/Targeting | marker follows source target identity |
| Enemy attack warning | Encounter/attack/threat communication source under doc 55 | committed threats only |
| Inventory/tool ownership | Inventory & Tool Progression | no UI-only ownership |
| Cantor diagnostic state | Cantor service | no hidden solution metadata |
| Anchor state | Anchor/Tool + target mechanism owner | physical relationship presentation only |
| Hush semantic layer/seam legality | Hush/World-Layer | no duplicate Hush truth |
| Quest/objective state | Quest/Story | journal presents source facts |
| Records/testimonies | Record/Quest/World source as authored | no fabricated provenance |
| Completion | Completion Ledger | all totals derived |
| Skiff route legality | Route Network consuming World/Hush facts | no spline/UI-owned route truth |
| Settings/remapping | Profile/Settings/Input/Camera/Audio owners | separate from playthrough state |
| Localization text | localization-ready authored text source | no baked critical text |

---

# 5. Retail surface inventory — overview

The minimum known retail production inventory consists of these **surface families**:

1. startup / accessibility setup;
2. title shell;
3. playthrough management;
4. loading / transition / recovery;
5. pause hub;
6. map;
7. journal / records / dialogue history;
8. Tools & Gear;
9. Completion;
10. Save;
11. Settings;
12. Controls / remapping;
13. accessibility;
14. display / graphics;
15. audio;
16. gameplay / camera options;
17. dialogue / choice;
18. subtitles / captions;
19. exploration HUD;
20. combat / target / threat HUD;
21. interaction prompts;
22. Cantor / tool overlays;
23. Hush contextual UI;
24. Line Skiff contextual HUD;
25. tutorial / acquisition surfaces;
26. death / retry;
27. confirmations / errors;
28. credits / post-credits;
29. controller-disconnect / device-change UX;
30. help/reference;
31. development-only UI review surface, excluded from Shipping.

This is a production minimum, not a promise of 31 unrelated visual styles.

---

# 6. Startup / first-launch surfaces

## `UI.Shell.Boot`

**Layer:** L6 Shell  
**Owner:** product/platform initialization + profile/settings  
**Purpose:** safe application startup before title.

### Required states
- normal startup;
- storage/profile initialization;
- initialization failure requiring action;
- legal/publisher sequence only if later product scope requires it.

### Production burden
- restrained loading treatment;
- accessibility entry affordance before long sequences;
- localized error treatment;
- device-independent prompt treatment.

### Hard failure
Do not trap accessibility settings behind an unskippable decorative boot sequence.

---

## `UI.Shell.FirstLaunchQuickSetup`

**Layer:** L6  
**Owner:** profile/settings/input/camera/audio  
**Focus entry:** first required/recommended setting or `Continue` according to final layout.

### Required controls
- subtitles/dialogue text visibility;
- text/UI scale preview;
- subtitle background/contrast;
- camera inversion/sensitivity basics;
- camera shake / Reduced Effects baseline;
- master audio;
- detected input device;
- `Full Settings`;
- `Continue`;
- `Skip` where layout separates it from Continue.

### Required states
- controller detected;
- keyboard/mouse active;
- changed setting preview;
- reset-to-default;
- oversized text stress state.

### Asset burden
- live sample subtitle;
- live focus/selection sample;
- live UI-scale preview area;
- simple camera-setting explanation graphics only if useful.

No questionnaire/profile archetype system is authorized.

---

# 7. Title shell

## `UI.Shell.Title`

**Layer:** L6  
**Data:** Save validity/recent playthrough, Profile settings  
**Primary focus:** `Continue` if valid; otherwise `Playthroughs/New Journey`.

### Required actions
- Continue;
- Playthroughs;
- Settings;
- Credits;
- Quit to Desktop on PC.

### Required states
- no playthrough;
- valid recent playthrough;
- newest save invalid / recovery required;
- controller/KBM device swap;
- storage unavailable;
- localized long-label stress.

### Forbidden content
- store;
- news carousel;
- multiplayer;
- battle pass;
- account-login gate;
- daily reward;
- AI-content feed.

### Asset burden
- title logotype treatment remains working-title-safe until commercial clearance;
- menu focus language;
- restrained background/scene treatment;
- save/recovery status affordance;
- version/build text if production requires it.

---

# 8. Playthrough management

## `UI.Save.PlaythroughList`

**Layer:** L6  
**Owner:** Save  
**Purpose:** select/manage independent journeys.

### Each entry derives
- display slot/label;
- checkpoint/region description;
- playtime;
- last successful save timestamp;
- spoiler-safe story descriptor;
- completion summary only when authorized by Completion presentation.

### Required states
- empty;
- one playthrough;
- multiple playthroughs;
- selected valid;
- selected recovery-required;
- selected incompatible;
- selected corrupt/no recovery;
- storage read failure.

### Navigation burden
- controller list traversal;
- keyboard list traversal;
- pointer selection;
- deterministic focus after deletion/cancel;
- long-label/pseudo-localized entry.

### Asset burden
- playthrough card/list component;
- metadata icon/text roles;
- status badge family;
- destructive-action affordance.

---

## `UI.Save.NewJourney`

**Owner:** Save + New Game source owners  
**Actions:** create journey; cancel; replace only if later finite storage model demands it.

### Required states
- capacity available;
- replacement required only if future finite limit exists;
- initialization in progress;
- initialization failure.

No character creator/class-selection screen is authorized.

---

## `UI.Save.DeleteJourneyConfirm`

**Layer:** L5 Modal  
**Focus:** safe cancel/non-destructive choice by default.

Required:
- exact journey identification;
- destructive consequence text;
- Confirm Delete;
- Cancel.

---

# 9. Loading / transition surfaces

## `UI.Shell.Loading`

**Owner:** loading/travel/save reconstruction pipeline  
**Purpose:** communicate necessary wait without inventing progress precision.

### States
- new-game transition;
- playthrough load;
- travel/map load if visible wait exists;
- save migration/reconstruction if player-facing delay is material;
- failed reconstruction routed to error/recovery.

### Rule
Do not show fake percentage progress unless the runtime can report meaningful progress.

### Optional content
- spoiler-safe gameplay/help tip already learned by the player;
- accessibility reminder;
- region art only when it does not reveal undiscovered content.

---

# 10. Pause hub

## `UI.Pause.Root`

**Layer:** L4  
**Default categories:** Map / Journal / Tools & Gear / Completion / Save / Settings  
**Secondary:** Resume / Return to Title.

### Required states
- all categories available;
- category disabled only when source has explicit reason;
- large-text category overflow;
- controller/keyboard/mouse navigation;
- return focus from nested modal.

### Asset burden
- category navigation framework;
- active category treatment;
- player/context summary only if it provides useful orientation;
- Back/Resume affordance.

Pause root does not own gameplay pause semantics for every overlay; individual surfaces state whether gameplay is paused.

---

# 11. Map surfaces

## `UI.Pause.Map.World`

**Owner:** map knowledge + World/Quest/Route/Completion derived disclosures  
**Purpose:** orientation and remembered geography.

### Required layers of information
- known region/landform outline;
- known settlements/landmarks;
- discovered Waybells/stations;
- known Line Skiff segments/state;
- known major civic/quest places;
- player position only if later runtime navigation decision retains it;
- bounded player markers only if runtime UX approves them;
- Completion-assist disclosures only when eligible.

### Required states
- early sparse knowledge;
- midgame multiple regions;
- post-Stillness changed route facts;
- Skiff network discovered/partially unavailable;
- Hush-related known annotations;
- completion-assist tier variations;
- undiscovered content hidden;
- player-position treatment on/off if option exists.

### Navigation
- controller pan/zoom;
- keyboard pan/zoom;
- mouse pan/zoom;
- focus known landmark list if included;
- reset/recenter map view;
- no mouse-only drag requirement.

### Asset burden
- world map/base cartography family;
- region labels;
- landmark family;
- Waybell/station family;
- Skiff route states;
- player marker candidate family if approved later;
- player marker placement/selection family if approved;
- completion-disclosure overlay family;
- unknown/blocked/unavailable variants.

### Forbidden
- universal quest exclamation marks;
- every enemy;
- all collectibles by default;
- GPS optimal path;
- duplicated universal Hush map.

---

## `UI.Pause.Map.RegionDetail`

Optional compositional state of the map system rather than mandatory separate screen implementation.

Must support:
- dense local labels without overlap;
- known route states;
- long localized place names;
- access by controller and pointer;
- return to previous world-map view/focus.

---

# 12. Journal surfaces

## `UI.Pause.Journal.Commitments`

**Owner:** Quest/Story  
**Data:** current/resolved commitments, known places/people/facts.

### Required states
- active main commitment;
- multiple optional commitments;
- completed/resolved;
- no optional commitments;
- newly updated;
- state with only vague location knowledge;
- exact known-location knowledge;
- long localized objective.

### Each entry may present
- title;
- current plain-language commitment;
- relevant region/place;
- people;
- known facts/clues;
- recent update;
- resolution state.

No internal quest enum or raw condition tree is exposed.

---

## `UI.Pause.Journal.Clues`

**Owner:** Story/Quest/Record/World according to authored fact.

Must preserve distinction among:
- observed fact;
- testimony/reported fact;
- diagnostic/inferred relationship.

### States
- single finding;
- conflicting findings;
- later reconciled understanding;
- unknown relationship;
- spoiler-hidden entry.

UI cannot declare one testimony true merely for cleaner sorting.

---

## `UI.Pause.Journal.Records`

**Owner:** acquired Records/Testimonies  
**Purpose:** long-form reading.

### Required capabilities
- list/filter by discovered categories only;
- provenance/source when known;
- discovery context where authored;
- scrollable body text;
- related entries only after relationship is known;
- unread/new state;
- discovered count under Completion disclosure rules.

### Stress states
- very long title;
- long body;
- 200% text;
- pseudo-localized expansion;
- mixed punctuation/diacritics;
- no image/illustration;
- optional image/diagram if an authored record requires one.

---

## `UI.Pause.Journal.DialogueHistory`

**Owner:** transient/bounded presentation history + speaker source  
**Purpose:** recover missed recent conversation.

### Requirements
- speaker label;
- chronological text;
- newest easy to reach;
- scroll state;
- no assumption of infinite history;
- durable quest meaning remains in Journal facts.

---

# 13. Tools & Gear surfaces

## `UI.Pause.Tools.Root`

**Owner:** Inventory & Tool Progression.

### Required categories
- Cantor;
- field tools;
- owned upgrades/capabilities;
- quick-use/items only if source system retains them.

### Required states
- early Cantor-only/limited tool set;
- newly acquired tool;
- upgrade acquired;
- no optional upgrades;
- complete tool set;
- stripped/minimum progression fixture for finale validation.

### Each tool entry
- player-language function;
- mapped input;
- known procedures/uses;
- owned upgrades;
- equipped/configuration state only if a real choice exists;
- no undiscovered use spoilers.

### Forbidden visual grammar
- rarity color;
- item score;
- DPS comparison;
- random affix table;
- crafting tree;
- encumbrance.

---

## `UI.Pause.Tools.CantorPatterns`

**Owner:** learned Cantor patterns/procedures.

Must present:
- pattern name;
- relationship notation;
- known usage explanation;
- acquired state;
- undiscovered handling without song-note imitation.

No copied ocarina/song-staff UI.

---

# 14. Completion surfaces

## `UI.Pause.Completion.Root`

**Owner:** Completion Ledger.

### Required current top-level model
- 16 equal categories;
- current canonical names/counts from Completion authority;
- derived overall percentage;
- category progress;
- no stale legacy literals.

### Required states
- early game;
- partial category;
- category complete;
- hidden-member category;
- assist disclosure tier changes;
- 100%;
- postgame without 100%;
- migration/alias fixture state for developer validation, not retail technical exposure.

### Asset burden
- category icon family;
- progress treatment;
- hidden/undiscovered treatment;
- disclosure/hint treatment;
- category-complete state;
- overall progress presentation.

### Hard rules
- 100% is not a `true ending` gate;
- UI percentage never owns completion truth;
- hidden item identities remain hidden until disclosure permits them.

---

# 15. Save surfaces

## `UI.Pause.Save.Manual`

**Owner:** Save Coordinator  
**Purpose:** request safe manual save and communicate result.

### States
- available;
- saving;
- saved;
- failed;
- blocked active hostile combat;
- blocked in-flight Hush seam;
- blocked unsafe traversal microstate;
- blocked unsettled transaction;
- blocked map/load transition;
- blocked another save/load operation;
- deferred where Save authority supports deferral.

### Required information
- action availability;
- reason unavailable/deferred;
- last successful save summary where useful;
- current `Saving…` / `Saved` / `Save Failed` state.

Do not display success until Save authority reports publication success.

---

## `UI.Save.Recovery`

**Layer:** L6 or L5 depending entry path  
**Owner:** Save integrity/recovery.

### Required recovery cases
1. newest generation invalid + valid LKG;
2. corrupt newest + no valid recovery;
3. newer-version incompatible;
4. unsupported historical/migration failure;
5. storage/read failure;
6. representation reconstruction failure.

### With valid recovery, show
- newest could not be used;
- recovery point timestamp/playtime/checkpoint summary;
- recent progress may be lost;
- Continue with recovery;
- Back/other journey where valid.

### Forbidden
- silent rollback;
- implying corrupted state was successfully repaired when it was not;
- exposing raw internal generation IDs as the primary player explanation.

---

# 16. Settings root

## `UI.Settings.Root`

**Owner:** Profile/Settings services.

### Categories
- Controls;
- Camera;
- Accessibility;
- Audio;
- Display / Graphics;
- Gameplay;
- Language only when ship-language options exist.

### Global states
- current values;
- changed from default;
- reset category;
- reset all;
- apply immediately;
- apply-restart-required only if a future technical setting genuinely requires it;
- unsaved settings should not exist as hidden shadow state if the UX claims immediate application.

---

# 17. Controls / remapping surfaces

## `UI.Settings.Controls.List`

**Owner:** Input/Profile.

### Required categories
Exact action grouping follows implemented semantic action registry, but the UI must support:
- gameplay movement/actions;
- camera/targeting;
- combat;
- interaction;
- tools;
- Skiff;
- menu/navigation.

### Every row may need
- semantic action name;
- primary/secondary binding slot;
- controller binding;
- KBM binding;
- hold/toggle behavior where relevant;
- conflict state;
- unbound state;
- reset state.

---

## `UI.Input.Rebind.Listen`

**Layer:** L5 modal/contained capture  
**Owner:** Input.

### States
- listening;
- valid input captured;
- reserved/unsupported;
- conflict;
- duplicate allowed;
- cancel;
- timeout only if implementation uses one and it is accessible.

---

## `UI.Input.Rebind.Conflict`

Must identify:
- new requested binding;
- existing conflicting semantic action;
- Replace;
- Swap where valid;
- Cancel;
- Duplicate only where intentionally supported.

No silent unbind.

---

## `UI.Input.RequiredActionRepair`

Appears if a required action becomes unbound or invalid.

Must offer:
- bind now;
- restore required default;
- restore category defaults;
- safe cancel only if interface remains recoverable.

---

# 18. Camera settings surface

## `UI.Settings.Camera`

**Owner:** Camera/Profile.

### Required currently authorized controls
- horizontal sensitivity;
- vertical sensitivity where separate authority supports it;
- invert Y;
- invert X where supported;
- camera shake;
- look dead-zone/response settings within safe bounds;
- reset defaults.

### Runtime-gated candidate controls
- FOV;
- recenter strength;
- camera distance;
- additional comfort values.

Do not expose a setting merely because Unreal has a console variable.

---

# 19. Accessibility surface

## `UI.Settings.Accessibility`

**Owners:** Profile + affected source systems.

### Required sections

#### Text
- subtitle/dialogue visibility;
- subtitle size;
- subtitle background/contrast;
- speaker labels;
- UI text scale;
- caption controls once Audio cue inventory exists.

#### Motion / visual effects
- camera shake reduction/off;
- Reduced Effects;
- Reduced Hush Effects;
- promoted camera comfort options.

#### Input
- shortcut to remapping;
- Hold/Toggle options;
- dead-zone adjustment;
- sensitivity;
- supported timing accommodations.

#### Visual information
- threat-indicator size/contrast/mode;
- non-color-only cue policy realized by design;
- UI scale/readability controls.

#### Audio substitution
- captions/visual redundancy once final cue taxonomy exists.

### Screen narration
Prepare semantic labels/order for future narration support, but do not label full retail narration as shipped until implementation/QA proves it.

---

# 20. Audio settings surface

## `UI.Settings.Audio`

**Owner:** Audio/Profile.

Prepare production slots for:
- Master;
- Music;
- SFX / gameplay;
- Ambience;
- Dialogue/VO **only if VO exists**;
- UI;
- dynamic-range/mix accessibility controls if Audio authority creates them.

Dead controls are prohibited.

---

# 21. Display / graphics surface

## `UI.Settings.DisplayGraphics`

**Owner:** Technical renderer/settings + Profile.

### Known generic categories
- display mode;
- resolution;
- refresh/frame cap where supported;
- VSync/latency where supported;
- quality/scalability tiers;
- brightness/gamma;
- UI scale separate from render resolution.

### Explicitly deferred until technical selection
- Lumen toggle;
- Nanite toggle;
- ray tracing;
- upscaler brand/mode;
- frame generation;
- HDR;
- advanced renderer settings.

No empty template rows.

### Required safe-revert state
Any display change capable of making the UI unusable needs a timed/explicit Keep/Revert flow if the underlying platform/runtime requires it.

---

# 22. Gameplay settings surface

## `UI.Settings.Gameplay`

**Owner:** affected gameplay systems/Profile.

Known possible items only where current authority supports them:
- target/facing assistance mode;
- off-screen threat indicator mode;
- timing/access assists;
- Hold/Toggle alternatives if grouped here instead of Controls;
- tutorials/hints presentation.

No global difficulty screen is authorized yet.

---

# 23. Language surface

## `UI.Settings.Language`

**Status:** CONDITIONAL ON FINAL SHIP-LANGUAGE SCOPE.

Prepare for:
- text language;
- VO language only if multilingual VO exists;
- subtitle language behavior if it may differ from VO;
- locale-safe name of each language;
- confirmation/reload only if technically required.

Do not invent a language list now.

---

# 24. Dialogue surfaces

## `UI.Dialogue.Standard`

**Owner:** Dialogue service consuming story/world/NPC state.

### Elements
- speaker label where needed;
- dialogue text;
- continue/advance affordance;
- subtitle presentation;
- optional portrait **not assumed**;
- recent-text access.

### States
- player-controlled advance;
- auto-timed/voice-timed only if narrative/audio implementation later requires;
- interruption/transition;
- skip/advance;
- large text;
- long localization.

---

## `UI.Dialogue.Choice`

Only exists when Narrative authority creates a real choice.

### Requirements
- clear focus;
- explicit confirm;
- no movement-input bleed auto-select;
- long option wrapping;
- disabled option only when the player can understand why it is disabled, if such choices exist;
- consequences are not previewed unless narrative authority intentionally exposes them.

No generic moral wheel.

---

# 25. Subtitle / caption surfaces

## `UI.HUD.Subtitles`

**Owner:** Dialogue/Narrative + Profile settings.

### Required states
- single speaker;
- ambiguous multi-speaker context requiring labels;
- cinematic dialogue;
- gameplay dialogue;
- large text;
- background on/off/strength states;
- overlapping gameplay UI;
- Hush bright/dark background stress.

### Layout target
Normally no more than two subtitle lines at once unless accessibility/localization testing approves a controlled exception.

---

## `UI.HUD.Captions`

**Owner:** future Audio semantic cue inventory.

Known future cue families may include:
- committed off-screen threat reinforcement;
- critical mechanism state;
- Cantor/resonance result;
- major hazard warning;
- required narrative sound event.

Exact caption inventory is dependency-bound to Audio production authority.

---

# 26. Exploration HUD cluster inventory

The exploration HUD is a **composed state**, not a single always-on frame.

## `UI.HUD.PlayerStatus`

**Owner:** Player health/resource source.

States:
- ordinary healthy exploration;
- recent damage;
- heal;
- low health;
- combat;
- dangerous environment;
- context fade/always-visible setting if retained.

No stamina meter without an actual source resource.

---

## `UI.HUD.InteractionPrompt`

**Owner:** Interaction/Tool/Traversal source.

States:
- no candidate;
- valid candidate;
- prompt binding changed;
- hold/toggle variation;
- transient failure reason;
- candidate invalidated while visible;
- movement-compatible interaction;
- planted interaction.

Assets:
- action glyph container;
- short verb text;
- target label treatment;
- concise reason treatment.

---

## `UI.HUD.Toast`

Reusable transient family for:
- item acquired;
- tool acquired;
- pattern learned;
- objective/commitment updated;
- record discovered;
- route updated;
- save result;
- tutorial cue;
- nonmodal error.

Each semantic class may use iconography but must share one restrained hierarchy.

Toast queueing must not hide urgent combat information.

---

# 27. Combat HUD cluster inventory

## `UI.HUD.TargetLock`

**Owner:** Targeting.

States:
- no lock;
- acquiring only if source exposes a useful presentation state;
- locked;
- occluded-but-valid if Targeting retains lock;
- paired Hush expression transfer;
- lock break/loss.

Asset burden:
- target marker;
- selected/active treatment;
- large-target accommodation;
- reduced-effects variation.

---

## `UI.HUD.OffscreenCommittedThreat`

**Owner:** committed threat communication under `docs/55`.

### States
- no warning;
- left/right/rear/coarse direction;
- urgency stage only if later validated;
- multiple threats within allowed encounter bandwidth;
- warning handoff from body/world evidence;
- indicator Reduced/Off accessibility mode;
- color-vision/contrast stress.

### Asset burden
- direction shape family;
- optional urgency animation family;
- non-color distinction;
- scalable size/contrast.

### Forbidden
- presence radar;
- exact hidden enemy location;
- enemy identity;
- health;
- distance number;
- pathing.

---

## `UI.HUD.EnemyVitality`

**Status:** RUNTIME-GATED.

Production must prototype at least:
- target-only vitality treatment;
- minimal/local vitality candidate;
- no ordinary bar candidate using embodied reaction;
- boss/major-pressure treatment.

Do not commission a universal bar set as locked canon yet.

---

## `UI.HUD.BossPressure`

A family, not one universal bar.

Possible state modules:
- actual health;
- mechanical component progress;
- pressure/alignment;
- release/disconnection;
- contradiction/preservation;
- simple current goal text.

Per-encounter final surface derives from boss grammar, not UI convention.

Listener receives no fake health bar.

---

# 28. Cantor production surfaces

## `UI.Cantor.Listen`

**Owner:** Cantor.

### State inventory
- idle/inactive;
- request initiated;
- no candidate;
- clear;
- ambiguous;
- not actionable;
- blocked;
- diagnostic focus;
- known procedure available;
- procedure selected;
- result;
- remeasure recommended/available.

### Asset burden
- bounded focus mark;
- relationship notation family;
- tone/pattern non-audio representation;
- ambiguity treatment;
- blocked/not-actionable treatment;
- known procedure list/selector if needed;
- non-color semantics.

### Hard failures
- objective scan overlay;
- collectible radar;
- through-wall solution outline;
- “correct target” gold highlight;
- song staff copied from another franchise.

---

# 29. Anchor production surfaces

## `UI.Tool.Anchor`

**Owner:** Anchor + target mechanism/world owner.

### States
- none;
- candidate;
- incompatible;
- latched;
- load path clear;
- load path blocked;
- tension/load band;
- brace available;
- brace already owned;
- traversal eligible;
- traversal invalid;
- reclaim/release;
- component/mechanism result where source exposes it.

### Assets
- candidate mark;
- line/load relationship treatment;
- blocked relation treatment;
- tension/load-state treatment;
- brace state;
- traversal availability treatment.

No grappling-hook crosshair convention is assumed.

---

# 30. Other tool UI packages

Every later major tool requires a manifest row before production with:
- `ToolId`;
- source owner;
- active/inactive state;
- target family;
- valid/incompatible/blocked states;
- release/cancel;
- accessibility redundancy;
- icon/glyph requirement;
- tutorial/reference requirement;
- prohibited hidden-solution information.

The common UI family may be reused, but physical semantics may not be flattened into one generic magic mode.

---

# 31. Hush contextual UI

## `UI.Hush.Seam`

**Owner:** Hush/World-Layer.

States:
- no seam;
- seam visible/known through world only;
- valid transition prompt;
- invalid transition + useful reason;
- preparing;
- committed transition feedback;
- presentation settling;
- stable destination;
- save deferred due transition;
- target/tool prompt rebound to destination expression.

### Asset burden
- seam prompt/state language;
- brief commit feedback;
- invalid/deferred reason treatment;
- Reduced Hush Effects equivalent.

No permanent `HUSH MODE` banner.

---

# 32. Line Skiff contextual UI

## `UI.Skiff.RouteHUD`

**Owner:** Route Network + Skiff traversal + Hush/World route facts.

### States
- uncoupled/no Skiff HUD;
- boarded/coupled;
- compatible active route;
- dormant wakeable segment;
- route blocked/unavailable;
- standard junction approaching;
- selected junction intent where source exposes it;
- Switchshoe transfer eligible/ineligible;
- legal/illegal aboard Hush transition;
- parking/recovery;
- Trial 05 relay mechanical-window state;
- Drift Knot route context only where completion authority allows it.

### Assets
- route state cue;
- junction/branch cue;
- Roadhand Pulse cue;
- Switchshoe transfer cue;
- blocked reason;
- trial relay-state module.

### Runtime-gated candidates
- speedometer;
- additional handling instrumentation.

No fuel, stamina, boost or racing-line HUD by default.

---

# 33. Tutorial / acquisition surfaces

## `UI.Help.ContextTutorial`

Reusable for one immediately useful concept.

States:
- first presentation;
- dismissed;
- remapped input update;
- reviewed later from Help;
- large text;
- controller/KBM alternate glyph.

### Required authored tutorial families
Exact tutorial count is content production work, but the system must support at minimum concepts from:
- basic movement/camera;
- target lock;
- guard/evade/Perfect Guard where taught;
- Cantor;
- Anchor;
- Hush seam;
- Skiff acquisition/Roadhand;
- save/manual save;
- map/journal discovery;
- accessibility reminder where useful.

Do not count each as a modal page by default.

---

## `UI.Help.Reference`

Persistent review surface for learned controls/system relationships.

Must not reveal unlearned capabilities.

---

# 34. Death / retry

## `UI.Death.Retry`

**Owner:** Combat death + Checkpoint/Travel/Save retry authority.

### Actions
- Retry;
- Load / Playthroughs secondary path;
- Settings;
- Return to Title.

### States
- routine retry available;
- retry restore in progress;
- retry reconstruction failure routed to load/recovery;
- input device disconnect while on death screen.

### Hard language rule
Do not label Retry as `Load Last Save` unless it actually loads the durable disk save.

---

# 35. Confirmation modal family

## `UI.Modal.Confirm`

Reusable visual/layout family with semantic copy.

Required specific content instances:
- delete playthrough;
- reset controls category;
- reset all settings;
- destructive replace/overwrite if future finite-slot model creates one;
- display Keep/Revert if runtime needs it;
- Return to Title only when a real unsaved-risk contract warrants confirmation.

### Focus
Safe/non-destructive option is default when accidental confirmation could cause loss.

Copy names the thing being changed/deleted.

---

# 36. Error / warning modal family

## `UI.Modal.Error`

Every instance must provide:
1. what happened;
2. consequence;
3. next action.

### Required catalog

#### Save/storage
- save failed;
- load failed;
- recovery used/available;
- no recovery;
- newer-version save;
- migration/unsupported historical save;
- storage unavailable/write failure.

#### Input
- controller disconnected;
- binding conflict;
- required action unbound;
- unsupported/reserved binding.

#### Display/settings
- unsafe setting revert;
- unsupported combination only if technical production defines one.

#### Gameplay context
- save unavailable/deferred;
- route unavailable;
- tool/interaction blocked where useful;
- seam unavailable.

Do not author network-service errors for a base game that has no network service requirement.

---

# 37. Controller disconnect / device change

## `UI.Input.ControllerDisconnected`

**Layer:** L5  
**Owner:** Input/Profile.

Required:
- identify loss of active controller;
- request reconnect or alternate input;
- allow keyboard/mouse takeover on PC;
- preserve prior valid UI/game context;
- never convert disconnect into a gameplay release/confirm action.

## `UI.Input.DeviceChanged`

Usually nonmodal.

States:
- controller → KBM;
- KBM → controller;
- controller family changed;
- unrecognized gamepad fallback.

Updates glyphs after debounced deliberate modality change.

---

# 38. Credits / post-credits

## `UI.Shell.Credits`

Must support:
- controller scroll/skip as authorized;
- KBM scroll/skip;
- text scaling;
- localized headings;
- branch/completion-specific authored inserts only from Narrative/Finale authority.

## `UI.Shell.PostCredits`

**Status:** NARRATIVE/CINEMATIC DEPENDENCY.

Needs explicit final contract for:
- return to title vs postgame play;
- save/epilogue state;
- completion summary or acknowledgments;
- credits replay.

Do not invent now.

---

# 39. Typography role manifest

Final font family remains production choice within readability/licensing/localization bounds.

Required roles:

| Role ID | Use |
|---|---|
| `TYPE.Display.Title` | game/shell title |
| `TYPE.Heading.Primary` | major screen title |
| `TYPE.Heading.Secondary` | section heading |
| `TYPE.Body.Standard` | ordinary menu/journal text |
| `TYPE.Body.Longform` | records/testimonies/dialogue history |
| `TYPE.Label.Control` | buttons/tabs/actions |
| `TYPE.Label.Metadata` | timestamps/region/playtime/context |
| `TYPE.HUD.Primary` | urgent player/game state |
| `TYPE.HUD.Secondary` | contextual prompt/state |
| `TYPE.Subtitle.Dialogue` | spoken dialogue subtitles |
| `TYPE.Caption.Audio` | semantic non-speech captions |
| `TYPE.Number.Tabular` | changing counts/timers only when useful |
| `TYPE.Error` | warning/error message hierarchy |

Requirements:
- mixed-case body copy;
- strong diacritics/punctuation;
- localizable character coverage;
- readable at ordinary PC distance;
- no critical text baked into textures.

---

# 40. Icon family manifest

Icons are semantic support, not the only critical channel.

## `ICON.System`
- Map;
- Journal;
- Tools;
- Completion;
- Save;
- Settings;
- Help;
- Back/Close only where a symbol improves text.

## `ICON.Tool`
- Cantor Key;
- Anchor Line;
- Glasslung Reed;
- Temper Gauntlet;
- Vane Cloak;
- Mirror Nail;
- Line Skiff where UI representation requires;
- Unstandard Tool where owned.

Use Stillring-specific silhouette logic.

## `ICON.CantorPattern`
Nine current canonical pattern/procedure slots as needed by the catalog, using relationship notation rather than musical-song notation.

## `ICON.CompletionCategory`
Sixteen top-level category icons if the final Completion visual direction retains category icons.

These must be generated from current category authority, not old count docs.

## `ICON.Map`
- settlement;
- landmark;
- Waybell;
- refuge;
- Skiff station/route node;
- known quest place;
- player marker only if runtime approves;
- custom player marker only if runtime approves;
- bounded completion hint.

## `ICON.Status`
- new/unread;
- complete/resolved;
- unavailable/blocked;
- save status;
- warning;
- recovery/rollback;
- settings changed/reset.

## `ICON.Combat`
- target lock;
- committed off-screen threat directional shape;
- attack-class marker only if combat authority later creates a semantic need.

No icon may silently invent new attack semantics.

---

# 41. Controller / keyboard glyph manifest

Production requires a glyph system, not individual baked images scattered through widgets.

## Required families
- generic gamepad fallback;
- current detected gamepad family where mappings are reliable;
- keyboard keys;
- mouse buttons/wheel;
- directional/stick/mouse-look concepts where a tutorial needs them.

## Requirements
- driven by current mapped binding;
- remap refresh is immediate;
- glyph + text combination survives large text;
- unknown controller does not lie by displaying the wrong branded face-button symbols;
- no critical tutorial has glyph baked into a screenshot.

Platform-specific branded glyphs are added only after platform scope is authorized and licensed requirements are known.

---

# 42. Layout family manifest

Reusable layout systems should include at minimum:

## `LAYOUT.ShellMenu`
Title / Credits entry / Playthrough navigation.

## `LAYOUT.PauseTab`
Map / Journal / Tools / Completion / Save / Settings root.

## `LAYOUT.ListDetail`
Journal records, commitments, tools, completion categories, playthroughs.

## `LAYOUT.LongformReader`
Records/testimonies/dialogue history/help.

## `LAYOUT.SettingsList`
Option rows, values, sliders, toggles, dropdown/cycle controls.

## `LAYOUT.Rebind`
Action row + binding capture/conflict resolution.

## `LAYOUT.Modal`
Confirm/error/recovery/controller-disconnect.

## `LAYOUT.HUDAnchor`
World/HUD contextual attachment with safe-screen rules.

## `LAYOUT.Toast`
Short transient messages.

## `LAYOUT.SubtitleCaption`
Dialogue/caption placement with background and scale options.

Do not force every surface into one card template when information type differs.

---

# 43. UI visual-state primitives

The UI art team must define reusable state language for:
- focus;
- hover;
- pressed;
- selected;
- active;
- unavailable/disabled;
- blocked with explanation;
- destructive;
- warning;
- error;
- success;
- new/unread;
- completed;
- loading/in progress;
- recovery/rollback;
- source-state stale/mismatch **developer only**, not retail.

Critical distinctions use shape/value/text/motion redundancy, not hue alone.

---

# 44. UI motion package

Required reusable motion families:
- focus acquisition;
- panel/tab transition;
- modal enter/exit;
- toast enter/exit;
- save in-progress/result;
- committed threat urgency if retained;
- acquisition/learned update;
- map/route state change;
- Hush seam UI feedback;
- reduced-effects alternatives.

No screen should depend on animation finishing before an action becomes semantically valid unless source authority requires the wait.

---

# 45. UI audio/haptic handoff package

The final Audio Bible owns actual cues.

UI needs semantic cue requests for:
- focus move;
- confirm;
- back/cancel;
- unavailable action;
- destructive confirm;
- error;
- save success/failure;
- acquisition;
- category/tab transition;
- binding captured/conflict;
- threat indicator reinforcement if approved;
- Hush/Skiff mode state only when Audio authority assigns it.

All have visual/text redundancy where information is critical.

---

# 46. Responsive / localization state matrix

Every major surface must be reviewed in at least these presentation conditions:

1. default text scale;
2. 200% text-scale stress;
3. pseudo-localized +30–40% expansion;
4. long German/Finnish-style compound stress strings or equivalent expansion fixture;
5. diacritics/accented Latin;
6. right-to-left feasibility fixture if a selected target language later needs it;
7. 16:9;
8. wider-than-16:9 desktop aspect ratio;
9. minimum supported PC window/resolution once product/technical scope defines it;
10. controller glyphs;
11. keyboard glyphs;
12. mouse pointer/focus coexistence.

The exact retail supported aspect/resolution list is Technical/Product authority, not invented here.

---

# 47. Empty / loading / error-state rule

Every data-backed surface must define all applicable states:

- loading;
- loaded with content;
- valid empty;
- filtered empty;
- source unavailable;
- operation in progress;
- operation failed;
- incompatible source data routed to recovery/error;
- stale UI detection in developer builds.

Examples:
- Journal has no optional commitments yet → valid empty, not error;
- Playthrough list storage read failed → error, not empty;
- Completion category undiscovered → intentionally hidden, not missing;
- Cantor finds no candidate → valid gameplay state, not failure dialog.

---

# 48. Focus/return-state matrix

Every modal/nested screen must record:
- `EntryFocus`;
- `BackTarget`;
- `ConfirmTarget`;
- `CancelTarget`;
- `PostMutationFocus`;
- `EmptyStateFocus`;
- `DeviceSwitchFocusPolicy`.

Minimum required behavior:
- child closes → initiating/nearest valid parent;
- deleted list row → nearest surviving row or New Journey;
- modal closes → initiating action unless no longer valid;
- category switch → retained previous valid selection or first meaningful row;
- pointer selection → controller focus becomes recoverable;
- no focus behind modal.

---

# 49. Screen narration semantic-preparation manifest

Even if full narration remains runtime/product-gated, production UI must provide semantic metadata for:
- screen title;
- control role;
- accessible name;
- current value;
- state/disabled reason;
- list position where useful;
- description/help text;
- error text;
- live/status change such as save result;
- focus order/reading order.

Decorative assets should not contaminate reading order.

---

# 50. Required UI test gallery

Before visual-production approval, static/wireframe galleries should include at minimum:

## Shell
- no save;
- valid save;
- recovery required;
- first-launch accessibility setup.

## Pause
- Map early/mid/changed-world;
- Journal active/completed/conflicting clues;
- long Record;
- Tools early/full;
- Completion early/late/assist/100%;
- Manual Save available/blocked/failed;
- Settings root.

## HUD
- ordinary exploration;
- low health;
- combat lock;
- committed off-screen threat;
- interaction;
- Cantor clear/ambiguous/blocked;
- Anchor latched/blocked;
- Hush seam valid/invalid;
- Skiff route/junction/Roadhand/blocked.

## Modal/error
- rebind conflict;
- delete playthrough;
- controller disconnect;
- save rollback;
- corrupt no recovery;
- newer-version save;
- display revert.

## Accessibility/localization
- 200% text;
- pseudo-localization;
- subtitles on bright and dark/Hush scenes;
- Reduced Effects;
- high-contrast focus;
- keyboard-only;
- controller-only;
- pointer/device switching.

---

# 51. Runtime fixture obligations

Later UE5.8 implementation must exercise real source services rather than UI mocks for acceptance.

Minimum semantic fixture groups:

- `UIF.Shell.NoSave`
- `UIF.Shell.ValidSave`
- `UIF.Save.RecoveryLKG`
- `UIF.Save.NoRecovery`
- `UIF.Save.DeferredCombat`
- `UIF.Input.RebindConflict`
- `UIF.Input.ControllerDisconnect`
- `UIF.HUD.Exploration`
- `UIF.HUD.CombatLock`
- `UIF.HUD.OffscreenCommit`
- `UIF.Cantor.Clear`
- `UIF.Cantor.Ambiguous`
- `UIF.Anchor.Blocked`
- `UIF.Hush.SeamPreparing`
- `UIF.Skiff.Junction`
- `UIF.Completion.HiddenAssist`
- `UIF.Localization.PseudoLong`
- `UIF.Access.Text200`
- `UIF.Access.ReducedEffects`
- `UIF.Focus.AllModals`

These fixtures become runtime evidence only after implementation.

---

# 52. Production asset source requirements

For each final UI visual asset, track:
- asset semantic ID;
- source editable file location;
- exported runtime target;
- licensed font/icon dependencies;
- localization/text baking status;
- light/dark/world-backdrop behavior;
- accessibility state variants;
- high-DPI/vector/raster source expectations as appropriate;
- owning surface family;
- reuse class;
- deprecated/replaced state.

Do not leave critical interface artwork recoverable only from a flattened runtime texture.

---

# 53. UI uniqueness / reuse classes

## `UI-R0` — primitive

Examples:
- focus frame;
- button background;
- divider;
- scroll treatment;
- basic status badge.

## `UI-R1` — reusable component

Examples:
- list row;
- tab;
- slider;
- setting row;
- icon + label prompt;
- toast;
- modal shell.

## `UI-R2` — domain-specific reusable

Examples:
- playthrough card;
- Journal entry;
- Completion category row;
- Cantor result treatment;
- Skiff route cue;
- threat indicator.

## `UI-R3` — hero/unique interface presentation

Reserve for rare high-identity surfaces justified by the game, such as:
- title treatment;
- major acquisition presentation;
- carefully authored finale/credits interface states if Narrative authority calls for them.

Do not make every menu `UI-R3`.

---

# 54. Quoteable current production burden

At written-authority level, a studio can now estimate for:

- one shell/title system;
- one first-launch accessibility setup;
- one playthrough management/recovery system;
- one pause navigation framework;
- one world/region map system with discovery/state layers;
- one Journal system with Commitments, Clues, Records and Dialogue History;
- one Tools & Gear system including Cantor pattern reference;
- one Completion system based on 16 current categories;
- one Save/manual/recovery UX family;
- six current settings category families plus conditional Language;
- one complete remapping/conflict-repair flow;
- one dialogue/choice family;
- one subtitle/caption family;
- one contextual exploration HUD composition;
- one combat target/threat composition;
- Cantor, Anchor, Hush and Skiff contextual HUD packages;
- one tutorial/help/reference framework;
- one death/retry flow;
- one shared confirmation/error/modal family;
- one credits surface plus dependency-bound post-credits flow;
- one semantic icon family system;
- one dynamic controller/KBM glyph system;
- typography roles;
- reusable focus/selection/status/motion primitives;
- accessibility, localization and responsive-layout variants across every major surface.

This is estimateable without pretending exact widget count, texture count, implementation framework or final pixel dimensions are already known.

---

# 55. Runtime / dependency-gated production details

Do **not** fake-close the following on paper:

- exact ordinary enemy vitality presentation;
- exact map player marker/compass treatment;
- exact HUD fade timings;
- exact threat-indicator timing/urgency treatment;
- exact Skiff instrumentation;
- final graphics-options list;
- final platform glyph/certification flows beyond PC-first;
- screen narration shipping support;
- exact safe-zone/minimum resolution behavior before target display support is defined;
- exact font family before licensing/localization verification;
- caption cue inventory before Audio Bible;
- post-credits flow before Narrative/Cinematic authority;
- ship-language list;
- VO-language controls before VO scope.

These are not permission for the UI team to invent product decisions.

---

# 56. Decision rights

## LOCKED

- surface families and source-ownership boundaries defined here;
- controller + KBM usability for every retail interactive surface;
- complete remapping/conflict repair;
- save/recovery truthfulness;
- completion derives source truth;
- map/journal spoiler discipline;
- bounded committed-threat warning rather than radar;
- no generic live-service/store shell;
- no stamina/boost/fuel UI without source systems;
- no universal boss health bar;
- no baked physical-input glyphs;
- critical states not color/audio/haptics-only;
- dev UI excluded from retail.

## STUDIO CHOICE WITHIN BOUNDS

- exact widget decomposition;
- layout composition within semantic categories;
- UMG/Slate/CommonUI choice;
- vector/raster implementation;
- exact icon illustration treatment;
- typeface candidate;
- spacing/grid system;
- panel ornamentation;
- animation/easing;
- grouping of settings rows without hiding required access.

## RUNTIME-GATED

Items listed in §55 plus all actual focus/performance/accessibility acceptance.

## OWNER / PRODUCT LATER

- launch-platform UI scope beyond PC;
- commercial title/branding;
- ship-language list;
- VO scope where it changes product-facing controls/subtitle model.

---

# 57. Acceptance condition

This manifest is complete at written production-inventory level when a producer/UI lead can answer:

1. Which retail surfaces exist?
2. Which source system owns every displayed value?
3. Which states must every surface support beyond the happy path?
4. Which controller/KBM focus transitions need implementation?
5. Which assets are shared versus domain-specific?
6. Which icons/glyphs/type roles must be produced?
7. Which screens carry accessibility/localization stress burden?
8. Which states depend on Audio/Narrative/Technical/runtime evidence?
9. Which apparently common UI patterns are explicitly forbidden in Stillring?
10. What can be quoted now without inventing final runtime values?

The answer is now present in `docs/176` + this manifest.

No runtime or visual-execution claim is made.
