# 192 — QA / Accessibility / Localization Production Consolidation

**Status:** ACTIVE / PRODUCTION-AUTHORITY / DOCUMENTATION-ONLY  
**Updated:** 2026-09-06  
**Parent program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Gap register:** `docs/152_STUDIO_HANDOFF_GAP_REGISTER.md`  
**Acceptance checklist:** `docs/153_STUDIO_HANDOFF_ACCEPTANCE_CHECKLIST.md`  
**Decision rights:** `docs/170_STUDIO_DECISION_RIGHTS_MATRIX.md`  
**Product/platform boundary:** `docs/171_PERFORMANCE_PLATFORM_PRODUCT_BRIEF.md`  
**UI authority:** `docs/176_UI_UX_PRODUCTION_SPECIFICATION.md`, `docs/177_UI_SCREEN_STATE_AND_ASSET_MANIFEST.md`  
**Audio authority:** `docs/179_STILLRING_AUDIO_MUSIC_VO_BIBLE.md`, `docs/180_AUDIO_CUE_ASSET_AND_MUSIC_MANIFEST.md`  
**Narrative authority:** `docs/182_STILLRING_NARRATIVE_PRODUCTION_BIBLE.md`, `docs/183_NARRATIVE_SCENE_DIALOGUE_TEXT_MANIFEST.md`  
**Technical authority:** `docs/188_TECHNICAL_PRODUCTION_BIBLE.md`, `docs/189_TECHNICAL_PRODUCTION_WRITTEN_HANDOFF_ACCEPTANCE_AUDIT.md`  
**Production-management authority:** `docs/190_PRODUCTION_DEPENDENCY_DISCIPLINE_MATRIX.md`, `docs/191_PRODUCTION_MANAGEMENT_HARD_PASS_AUDIT.md`  
**Evidence baseline:** `docs/142_RUNTIME_EVIDENCE_LEDGER_BASELINE.md`  
**Closes toward:** `SH-QA-001` through `SH-QA-005` and Section 13 of `docs/153`  
**Boundary:** this document defines production expectations and evidence contracts. It does not claim a runnable UE5.8 project, accessibility conformance, localized builds, certification, target-hardware performance, human-play acceptance, or any runtime proof.

---

# 1. Purpose

Stillring already contains accessibility, localization-readiness and verification requirements inside gameplay, UI, audio, narrative, save, tooling and technical documents.

That distributed authority is useful to specialists, but an external studio still needs one place that answers:

1. what evidence counts as proof;
2. which accessibility obligations belong to which discipline;
3. which critical information requires redundant channels;
4. how input, text, motion, audio and timing accommodations are produced without changing hidden game truth;
5. how localizable text is authored, identified, gathered, translated, integrated and regression-tested;
6. what must be checked continuously rather than at the end;
7. what remains product/platform/runtime gated;
8. what certification work may not begin until platform scope exists.

The governing rule is:

> **Accessibility, localization and QA are production inputs to every system, not cleanup departments asked to repair finished content.**

A second rule is equally important:

> **Documentation may define the test and acceptance route; only implementation and evidence may pass the runtime gate.**

---

# 2. Authority and interpretation order

When this consolidation intersects a detailed system rule, resolve authority in this order:

1. locked gameplay/story/product authority;
2. `docs/139_SYSTEM_OWNERSHIP_MAP.md` and `docs/140_CROSS_SYSTEM_CONTRACT_MATRIX.md`;
3. discipline production bibles/manifests;
4. this consolidation;
5. later implementation/test plans;
6. captured runtime evidence.

This file may strengthen the required proof route.

It may not silently change:

- movement grammar;
- combat legality;
- Hush semantics;
- save ownership;
- completion truth;
- story canon;
- Line Skiff identity;
- Null Meridian sequence;
- UI information disclosure;
- critical audio meaning;
- platform scope.

If an accommodation appears to require a semantic game-design change rather than alternate presentation/input/timing support inside current authority, classify it as a design-review item instead of burying the change inside accessibility code.

---

# 3. Decision classes used here

## LOCKED PRODUCTION REQUIREMENT

The game already requires the behavior or production condition.

Examples:
- critical information may not be audio-only;
- critical visual information may not rely on color alone;
- controller and keyboard/mouse support are first-class on PC;
- retail menus must be keyboard/mouse and controller navigable;
- player-facing localizable text uses localization-aware identity rather than display strings as canonical IDs.

## STUDIO CHOICE WITHIN BOUNDS

Implementation/testing technique may vary while preserving the requirement.

Examples:
- exact automation harness layering;
- exact localization vendor/tool interchange format;
- whether a particular accessibility regression is a Functional Test, Automation test, structured manual case or combination;
- specific contrast-measurement tooling.

## RUNTIME-GATED

The obligation is clear but final acceptance requires real runtime evidence.

Examples:
- motion comfort;
- caption timing in gameplay;
- target/threat readability;
- text scaling without clipping;
- Hush Reduced Effects legibility;
- final performance/memory/loading/save integrity.

## TBD PRODUCT / OWNER

A genuine product decision is not selected.

Current examples:
- launch platforms beyond PC-first;
- target-PC baseline;
- localization language list;
- VO scope;
- commercial title.

## PROHIBITED

Examples:
- claiming accessibility certification from paper rules;
- using display text as gameplay identity;
- making muted audio an unwinnable state;
- making color deficiency an unwinnable state;
- shipping inaccessible debug-only workarounds as the accessibility solution;
- hardcoding production dialogue in gameplay logic;
- claiming platform certification before a platform is selected.

---

# 4. QA evidence taxonomy

QA uses the evidence vocabulary in `docs/142` and the provenance rules in `docs/188`.

For production reporting, every acceptance claim should identify the strongest evidence state actually achieved.

| Code | Evidence state | Meaning |
|---|---|---|
| `Q-DESIGN` | written authority | required behavior/rule is documented |
| `Q-EXISTS` | implementation/assets exist | relevant code/assets are present |
| `Q-BUILD` | build/load proof | project/build/package can reproduce the relevant surface |
| `Q-FIXTURE` | deterministic fixture proof | repeatable test exercises authoritative services and expected assertions |
| `Q-PERSIST` | persistence/recovery proof | relevant state survives the required save/retry/exit/reload route |
| `Q-A11Y` | accessibility runtime proof | alternate input/presentation/comfort path works in representative runtime context |
| `Q-LOC` | localization runtime proof | gathered/localized/pseudo-localized content survives integration and layout/context checks |
| `Q-PERF` | measured performance proof | representative content passes approved budgets on declared hardware |
| `Q-HUMAN` | human acceptance | people accept feel/readability/comprehension/emotional or usability claim |
| `Q-PROD` | scoped production-ready proof | all evidence required for that scoped deliverable has passed |

A row at `Q-DESIGN` may be fully documented and still have zero runtime proof.

No producer may collapse these states into one vague `done` label.

---

# 5. Evidence package minimum

Every material runtime acceptance artifact later produced should contain, where applicable:

- Evidence ID using `docs/188` convention;
- repository commit SHA;
- UE version;
- build configuration;
- actual platform/OS;
- actual hardware;
- fixture/preset ID;
- map/region/checkpoint;
- source semantic IDs involved;
- settings/accessibility profile used;
- culture/locale used for localization cases;
- canonical versus session-override provenance;
- expected result;
- actual result;
- screenshot/video/log/stat references;
- tester or automation route;
- defect links if failed;
- known limitations;
- human-review status where subjective acceptance is required.

A screenshot with no build/fixture/settings context is supporting evidence, not a complete evidence package.

---

# 6. QA responsibility model

QA coordinates evidence and defect visibility.

QA does **not** become owner of gameplay truth.

## Gameplay / engineering

Owns:
- deterministic system behavior;
- authoritative service invariants;
- testable failure reasons;
- automation hooks;
- semantic fixture APIs;
- regression fixes.

## Design

Owns:
- player-facing semantic acceptance boundaries;
- whether a runtime outcome matches locked design;
- escalation of newly discovered design gaps.

## UI/UX

Owns:
- navigation/focus presentation;
- text/layout behavior;
- settings accessibility;
- subtitle/caption presentation;
- error/recovery communication.

## Art / VFX / lighting

Owns:
- visual readability;
- color-independent critical cues;
- contrast-supportive visual execution;
- Reduced Effects equivalents;
- photosensitivity-safe visual design.

## Audio

Owns:
- critical cue classification;
- mix/readability;
- captions/source labeling inputs;
- audio-setting routing;
- non-audio redundancy coordination.

## Narrative / localization

Owns:
- source text intent/context;
- semantic line/entry IDs;
- translation context;
- subtitle segmentation source intent;
- terminology/pronunciation;
- spoiler-sensitive translation context.

## Production

Owns:
- milestone evidence expectations;
- triage cadence;
- integration/retest scheduling;
- blocking-gate visibility.

## Platform/release

Future owner once selected:
- platform compliance/certification execution;
- platform-specific accessibility metadata and requirements;
- store language metadata;
- packaging/submission evidence.

---

# 7. Defect severity taxonomy

Severity describes player/project impact, not how embarrassing a bug looks.

## `S0 — BLOCKER`

Examples:
- application cannot launch or load required build;
- deterministic save corruption/data loss with no valid recovery;
- mandatory progression hardlock;
- title/settings flow cannot be navigated by a required baseline input profile;
- accessibility setting required to enter/use the game is unreachable;
- localization integration prevents boot/load on a supported culture;
- security/secrets or Shipping developer-control leak.

S0 blocks affected milestone/build acceptance.

## `S1 — CRITICAL`

Examples:
- repeatable softlock requiring major rollback/restart;
- incorrect durable world/quest/completion truth;
- save/recovery contradiction with player-visible history;
- essential gameplay information is inaccessible under a required accessibility path;
- major subtitle/caption loss in mandatory content;
- severe text clipping/hidden controls making a required screen unusable in a supported localization/text-scale case;
- serious photosensitivity/motion behavior that violates the approved accessibility envelope.

S1 normally blocks the affected feature/region from production acceptance.

## `S2 — MAJOR`

Examples:
- repeatable gameplay defect with workaround;
- significant focus/navigation inconsistency;
- translation/context error that materially changes meaning but does not block progression;
- accessibility option works inconsistently in representative contexts;
- missing caption for important but recoverable cue;
- important layout overflow in one supported configuration.

## `S3 — MINOR / POLISH`

Examples:
- cosmetic clipping with no information loss;
- minor animation/audio mismatch;
- non-critical translation style inconsistency;
- low-impact visual alignment issue;
- typo that does not change meaning.

## Severity is not priority

Priority also considers:
- release risk;
- frequency;
- regression probability;
- affected population;
- content volume;
- fix cost;
- upstream/downstream dependency.

Do not downgrade accessibility/localization defects automatically because they affect a subset of users/configurations.

---

# 8. Required QA layers

Stillring requires multiple verification layers because no single test form can judge the whole game.

## 8.1 Static/source validation

Best for:
- duplicate semantic IDs;
- missing references;
- stale completion literals;
- invalid source ownership;
- missing localization keys/context;
- source-data schema errors;
- forbidden Shipping dependencies;
- asset/path convention checks;
- unsupported content roster inconsistencies.

## 8.2 Fast Automation / unit-level verification

Best for:
- arithmetic;
- predicate evaluation;
- migration helpers;
- ID parsing;
- deterministic combat/save/progression rules;
- localization formatting helpers;
- settings persistence logic.

## 8.3 Functional/runtime fixtures

Best for:
- locomotion/camera cases;
- combat interactions;
- tool/mechanism use;
- UI navigation/focus;
- Hush transitions;
- save/reload;
- quest/region state;
- Skiff route behavior;
- Null Meridian sequence cases;
- accessibility option interaction.

## 8.4 Packaged-build smoke

Best for:
- Shipping/Development separation;
- boot/title/settings;
- package/load integrity;
- input recognition;
- localization culture selection;
- developer-tool absence;
- release configuration regressions.

## 8.5 Higher-level orchestration

Gauntlet or equivalent may be adopted when repeated packaged-session orchestration earns its cost.

It is not mandatory at Gate 1 merely because Unreal provides it.

## 8.6 Human play/usability

Required for:
- movement/camera feel;
- combat fairness/readability;
- Hush comprehension/comfort;
- puzzle comprehension;
- navigation legibility;
- accessibility usability;
- subtitle/caption readability in motion;
- localization naturalness/context;
- music/emotional impact;
- full-route pacing.

Automation may collect evidence around these questions.

It does not overrule material human failure.

---

# 9. Continuous regression families

As implementation grows, QA should maintain named suites rather than one giant all-or-nothing regression pass.

## `REG.G1.CONTROLS`

Covers:
- input actions/remaps;
- walk/run/Sprint with no stamina resource;
- jump/mantle/ledge/ladder/swim/slope/fall;
- camera collision/recenter;
- target lock;
- controller + KBM;
- accessibility input variants.

## `REG.G2.COMBAT`

Covers:
- attack/guard/Perfect Guard/evade;
- target integration;
- incoming/offscreen pressure;
- hit/death/retry;
- readability under reduced audio/effects.

## `REG.G3.TOOLS`

Covers:
- Cantor;
- Anchor;
- other tool procedures;
- mechanism resets;
- progression ownership;
- non-audio/non-color result communication.

## `REG.G4.HUSH_SAVE`

Covers:
- semantic Waking/Hush state;
- legal/illegal seams;
- paired identity;
- collision/representation readiness;
- save barriers;
- process exit/reload;
- Reduced Hush Effects;
- muted-audio/contrast/readability cases.

## `REG.CONTENT.STATE`

Covers:
- Quest/World/NPC recurrence;
- Setup/Payoff;
- Completion Ledger;
- current 36/18/24 completion rosters once reconciled;
- optional/critical path separation;
- changed-region revisits.

## `REG.SKIFF`

Covers:
- route graph;
- handling;
- junctions;
- save/resume;
- Hush route pairing;
- Trial 05;
- Drift Knots;
- route UI/readability/comfort.

## `REG.NULL_MERIDIAN`

Covers:
- S1–S6 exact dependency order;
- Story Minimum / Partial / Full / Upgrade-Stripped;
- save/retry boundaries;
- Hush/combat/tool integration;
- S6 central-disconnection proof;
- Maelor;
- Listener;
- accessibility settings carried through finale.

## `REG.UI_A11Y_LOC`

Covers:
- boot/title/settings;
- controller/keyboard/mouse navigation;
- focus restoration;
- remapping;
- text scaling;
- subtitle/caption settings;
- pseudo-localization;
- long text;
- error/recovery states;
- credits;
- device switching;
- supported-culture smoke.

---

# 10. Accessibility governing principles

## 10.1 No critical single-channel information

If information is required for fair progression or response, it may not depend only on:

- hearing;
- color;
- tiny text;
- haptic feedback;
- rapid reaction without an approved alternate support path;
- subtle camera motion;
- one inaccessible input gesture.

The alternate channel must preserve **meaning**, not merely add decoration.

## 10.2 Settings must be reachable before they are needed

Critical first-use accessibility settings must be available before the player is forced through content that depends on them.

Examples:
- subtitles;
- subtitle size/background;
- UI scale;
- camera shake/reduced effects;
- input recognition/remapping access;
- basic sensitivity/inversion;
- audio level.

## 10.3 Accessibility does not invalidate completion

Using accessibility settings/support must not silently disqualify canonical story completion or 100% accounting.

If a future optional challenge introduces special leaderboard/scoring rules, that is a separate product/design decision and may not infect base completion truth.

## 10.4 Accessibility is not debug mode

Accessibility features must exist in normal player-facing settings and use ordinary game authority.

A developer cheat that bypasses a mechanic is not an accessibility implementation unless design explicitly authorizes that player-facing support behavior.

---

# 11. Accessibility ownership matrix

| Area | Locked requirement | Primary production owners | Future proof |
|---|---|---|---|
| UI text readability | scalable, high-contrast, usable across gameplay/settings | UI + Art + QA | runtime scale/contrast/layout cases |
| Focus/navigation | deterministic visible focus; no mouse-only retail screens | UI + Engineering + QA | controller/KBM navigation fixtures |
| Input remapping | action-centric remapping; prompts update; required-action recovery | Input + UI + QA | remap matrices across device profiles |
| Digital operability | menu functions usable by digital input; sliders support digital steps | UI/Input | runtime navigation proof |
| Hold/toggle alternatives | support where feasible/authorized; avoid unnecessary prolonged/repeated input | Gameplay/Input/UI | per-action fixture + human usability |
| Simultaneous/rapid input | not baseline requirement without alternate path | Gameplay/Input | representative action audit |
| Color-independent cues | critical state not color-only | Art/VFX/UI/Gameplay | color-deficiency/monochrome review + human proof |
| Audio redundancy | critical sound has visual/text/other support | Audio/UI/Gameplay | muted/mono/downmix fixtures |
| Subtitles | all spoken final-VO content; text-led dialogue already visible | Narrative/Audio/UI | scene coverage + timing/layout review |
| Captions | important non-speech cues when meaning otherwise relies on hearing | Audio/UI/Narrative | cue coverage matrix + gameplay review |
| Motion comfort | camera shake off/reduction; Reduced Effects/Hush Effects; comfort settings as approved | Camera/VFX/UI/QA | motion-sensitive human review |
| Photosensitivity | avoid required flashing/strobing; production review of risky effects | VFX/Lighting/UI/QA | effect inventory + runtime review |
| Threat readability | scalable offscreen committed-threat indicator; audio not required | Combat/UI/VFX/Audio | Gate 2 multi-enemy fixtures |
| Cantor readability | diagnostic result non-audio and non-color-only | Tools/UI/VFX/Audio | tool fixtures |
| Hush readability | semantic distinction survives Reduced Effects and muted audio | Hush/Art/VFX/Audio/UI | Gate 4 paired-space fixtures |
| Skiff readability | route/junction state understandable at speed without audio-only cues | Skiff/UI/World/Audio | high-speed route fixtures |
| Timing support | only through owning gameplay system; cannot secretly rewrite source state | Gameplay/UI/QA | system-specific human/runtime evidence |
| Screen narration readiness | semantic labels/order/control naming authored; shipping narration not yet claimed | UI/Engineering/Localization | product/implementation-gated |
| Haptics | optional reinforcement only for critical information unless redundant | Gameplay/Platform | controller runtime proof if used |
| Tutorials/help | contextual, replayable/referenceable where useful | Design/UI/Narrative | fresh-player usability |

---

# 12. Text, contrast and scaling production tests

The UI package already establishes text scaling and contrast stress targets.

QA must test them in representative screens rather than a single typography mockup.

Required stress surfaces include:
- first-launch setup;
- title;
- playthrough/recovery;
- pause navigation;
- Map;
- Journal long-form records;
- Completion;
- rebinding/conflict modal;
- accessibility settings;
- dialogue/subtitles;
- save failure/recovery;
- death/retry;
- credits.

## Scale stress

Use at least:
- default scale;
- large supported scale;
- the UI package's 200% stress target where the surface supports it.

Pass conditions:
- no required control disappears offscreen without reachable scrolling;
- no text overlaps another required control;
- focus remains visible;
- dialogs remain dismissible;
- destructive choices remain unambiguous;
- subtitle readability remains acceptable in motion;
- long localized labels do not silently truncate meaning.

## Contrast stress

The existing UI evaluation targets remain:
- 4.5:1 for ordinary critical text where applicable;
- 3:1 for sufficiently large text/non-text critical elements where applicable.

These are production evaluation targets informed by current accessibility guidance, not a claim of legal/platform certification.

Critical focus/target/threat state must remain perceivable without color alone.

---

# 13. Input accessibility production contract

Stillring remains controller-first and keyboard/mouse first-class on PC.

Production must support:
- action-centric remapping;
- correct current-binding glyph/text everywhere;
- conflict explanation;
- required-action recovery;
- dead-zone adjustment where relevant;
- sensitivity/inversion;
- digital UI operation;
- digital slider adjustment;
- hold/toggle alternatives where appropriate;
- avoidance of unnecessary rapid-tap, prolonged-hold or simultaneous-button requirements.

When a mechanic truly depends on analog expression, the owning gameplay authority must document what information/function would be lost under digital substitution and whether an accessible alternate is feasible.

Do not let an input implementation convenience become a new physical ability requirement.

---

# 14. Motion / VFX / photosensitivity contract

## Camera

Current baseline supports:
- horizontal/vertical sensitivity;
- inversion;
- camera shake reduction/off;
- dead-zone/response settings within safe bounds.

Potential FOV, recenter-strength, camera-distance and additional comfort settings remain runtime/camera-gated because they can affect authored visibility and encounter assumptions.

## VFX

Provide:
- Reduced Effects;
- Reduced Hush Effects;
- no critical mechanic that becomes invisible when optional decorative effects are reduced;
- no required flashing/strobing presentation;
- independent world/UI confirmation for critical VFX-heavy states.

## Cinematics

Camera shake/motion comfort settings should apply consistently to cinematics where technically and artistically applicable.

A cinematic cannot become an accessibility loophole where disabled gameplay camera effects suddenly return at full intensity without review.

---

# 15. Subtitle / caption production contract

## Subtitles

All spoken content included in final VO scope receives subtitles.

Requirements already established by UI/Audio authority include:
- speaker identification when needed;
- adjustable size/background;
- strong scene-independent readability;
- semantic line breaks;
- normally no more than two lines at once;
- availability before initial story content;
- no critical information lost when non-destructive UI opens.

Narrative owns exact text/intent.

UI owns presentation.

Audio owns spoken timing/source context.

Localization owns translated text/context preservation.

QA proves coverage and runtime readability.

## Captions

Create a production caption cue registry for **important non-speech information**, not every ambient sound.

Each captionable cue should declare:
- semantic cue ID;
- source/entity if relevant;
- player-facing meaning;
- whether world visuals already communicate it;
- spatial-direction need;
- localization text/context;
- suppression/priority behavior when multiple cues occur;
- accessibility setting behavior.

Initial required cue families include:
- important offscreen committed-threat reinforcement where visuals are insufficient;
- critical mechanism state change;
- key Cantor/resonance response;
- major environmental hazard warning;
- required offscreen narrative sound event;
- important Skiff route/system failure at speed.

---

# 16. Audio accessibility tests

Representative audio accessibility passes must include:

- normal mix;
- music low/off;
- gameplay SFX low/off where settings permit;
- ambience low/off;
- dialogue/VO low/off where applicable;
- mono/downmix;
- headphones;
- ordinary speakers appropriate to target-PC testing;
- captions on;
- subtitles on/off as applicable;
- Hush silence states;
- combat overlap;
- Skiff-at-speed overlap;
- dialogue over ambience/music.

Pass condition:

> A player who cannot rely on spatial hearing or normal audio levels can still receive all information required for fair progression/response through another supported channel.

Final mix/loudness/dynamic-range numbers remain runtime/platform gated.

---

# 17. Cognitive/readability support

Stillring should not solve accessibility by replacing authored discovery with GPS/radar.

Support should instead emphasize:
- clear plain-language objectives;
- consistent UI structure;
- recent-dialogue history;
- replayable Help/reference;
- visible focus;
- explicit error/recovery explanations;
- source-appropriate failure reasons;
- progressive completion assistance only under Completion authority;
- readable distinction between observed/reported/inferred information;
- no unnecessary timed menu decisions.

Narrative prose may retain character/world complexity.

System/settings/error instructions should favor direct language.

---

# 18. Localization production model

Localization is a controlled content pipeline, not a late export of every visible string.

The project must preserve a stable relation between:

```text
semantic content identity
    -> source text + context
    -> localization identity
    -> translated text
    -> integrated runtime presentation
    -> QA evidence
```

Gameplay IDs remain language-independent.

A translation may change displayed words.

It may not change:
- quest IDs;
- objective state;
- save keys;
- item identity;
- completion IDs;
- dialogue branch predicates;
- route identity;
- Hush semantic identity.

---

# 19. Localization scope boundary

The final ship-language list is **TBD PRODUCT**.

Do not infer:
- English-only release;
- EFIGS;
- Japanese;
- CJK;
- RTL languages;
- voice-localization languages;
- subtitle-only versus dubbed language tiers.

The pipeline must remain capable of supporting a later language decision without redesigning gameplay identity or rebuilding every UI from fixed-size English assumptions.

Language selection must occur early enough to staff translation/LQA/font/input/platform metadata work before release candidate.

---

# 20. Localization source-text contract

Every player-facing production text unit should carry, where relevant:

- stable semantic entry/line ID;
- localization namespace/key or String Table key;
- source string;
- speaker/source;
- screen/scene/location;
- narrative intent;
- branch/state condition;
- grammatical variables;
- gender/number context where relevant;
- spoiler sensitivity;
- max/target presentation context if meaningful;
- subtitle/caption classification;
- pronunciation/proper-name notes;
- developer comment for ambiguous terms;
- revision/version status.

Do not ask translators to infer context from isolated exported English strings where the repository already knows the scene/state.

---

# 21. Text identity and Unreal integration

The Technical Production Bible remains authority:

- use `FText` semantics for player-facing localizable text;
- preserve namespace/key/String Table identity;
- do not convert localization identity into gameplay identity;
- avoid lossy `FText` -> `FString` -> `FText` round-trips when history matters;
- use culture-aware formatting;
- avoid sentence-fragment concatenation that assumes English grammar;
- keep production dialogue out of gameplay branching logic.

The Localization Dashboard is a valid current UE5.8 production tool for managing localization targets/gathering, but it is a tool choice rather than gameplay authority.

If the project uses imported Data Tables, deterministic text keys must be maintained so repeated import does not churn localization identity.

---

# 22. Localization content families

At minimum the eventual localization inventory must classify:

## UI/system
- title/shell;
- menus/tabs/buttons;
- settings;
- rebinding;
- errors/recovery;
- tutorials/help;
- HUD prompts;
- completion/disclosure;
- save/load;
- credits roles/headers.

## Narrative
- scene dialogue;
- ambient dialogue;
- barks;
- commitments/objectives;
- Journal clues/findings;
- 32 Records/Testimonies body text;
- story-critical documents;
- credits consequence text;
- post-credit text if any.

## World/gameplay
- item/tool names/descriptions;
- Cantor Pattern names/text;
- location/region/landmark names;
- mechanism failure reasons;
- route/Skiff prompts;
- boss/encounter labels where player-facing;
- caption cues.

## Legal/platform

Future only after product/platform/publishing scope exists:
- legal notices;
- platform terminology;
- store metadata;
- certification-required copy;
- privacy/service copy if any approved service later exists.

---

# 23. Terminology and proper-name control

Maintain one localization terminology authority for recurring world/system terms.

Initial protected recurring vocabulary includes names already established by narrative/audio authority such as:
- Stillring;
- Neris Vale;
- Tessa Marr;
- Ilyra Vale;
- Orin Vale;
- Maelor Renn;
- Waybell;
- Cantor;
- Hush;
- Line Skiff;
- Null Meridian;
- Palinode;
- region names;
- tool names;
- completion/category terminology where player-facing.

For each term, localization production should record:
- source meaning;
- translatable versus protected-name status;
- capitalization/style;
- pronunciation where voiced;
- grammatical notes;
- forbidden misleading translation if known.

A translation glossary is production authority for translation consistency, not a new canon source.

---

# 24. Pseudo-localization and text-expansion testing

Before real localization at scale, the UI/runtime pipeline should support synthetic stress cultures or equivalent test data.

Required stress behaviors include:
- expanded string length;
- accented/diacritic characters;
- mixed punctuation;
- long proper names;
- multi-line buttons/labels;
- long subtitle lines;
- record/journal paragraphs;
- variable substitution;
- missing-glyph visibility;
- intentional overflow detection.

If a selected ship language requires bidirectional/RTL layout, complex shaping, CJK-specific line breaking, IME/text input, or other script-specific handling, those become explicit hard requirements before that language's localization-production lock.

Do not claim RTL/CJK support merely because pseudo-localization passes Latin-script expansion.

---

# 25. Font/glyph production boundary

Final UI fonts remain an art/UI production choice inside readability requirements.

Before a language is accepted for shipping, font coverage must include:
- required script glyphs;
- punctuation;
- symbols;
- numerals;
- controller/keyboard prompt integration where text is adjacent;
- subtitle/caption usage;
- fallback behavior.

Missing glyph boxes in a late localized build are a production failure, not translator responsibility.

Do not bake controller glyphs into localized texture text.

---

# 26. Localization branching/context QA

LQA must test more than spelling.

Representative checks include:
- correct speaker;
- correct branch/state;
- correct gender/number/variable agreement;
- no spoiler leakage from translated undiscovered text;
- no translation that changes uncertainty into certainty;
- observed/reported/inferred distinctions preserved;
- item/tool terminology consistent;
- proper-name pronunciation/context consistent with VO plan;
- objective meaning preserved without inventing GPS precision;
- credits consequence variants display the correct state;
- save/recovery errors preserve severity and player action.

Narrative/Design review is required when a translation appears to change canon meaning.

---

# 27. Localization change-control

After translation begins, source text changes require visible impact tracking.

A material source-text change should identify:
- affected semantic IDs;
- affected locales;
- VO implications;
- subtitle/caption implications;
- UI/layout implications;
- screenshot/LQA retest needs;
- whether existing translation is stale;
- whether the change is copy-edit only or meaning-changing.

Do not silently edit English source after translation lock and leave translated packages stale.

Narrative/audio/UI/production must coordinate lock windows rather than assuming localization can absorb unlimited late churn.

---

# 28. Localization quality gates

## `LOC-A — Pipeline ready`

Pass when:
- stable localizable text identity exists;
- gathering target/path is defined;
- source context is exported/available;
- pseudo-localization route works;
- UI layouts are not fixed to one source-language length;
- terminology authority exists.

## `LOC-B — Translation ready`

Pass when:
- selected language scope exists;
- source inventory is stable enough to quote/schedule;
- glossary/style/context packages exist;
- vendor handoff passes `docs/190` outsource-readiness rules;
- VO language model is known if dubbing is involved.

## `LOC-C — Integrated localization`

Pass per locale when:
- translated resources gather/compile/load;
- font/script coverage exists;
- representative UI/narrative content displays correctly;
- variables/plurals/formatting behave correctly;
- no required source strings are unintentionally untranslated.

## `LOC-D — LQA acceptance`

Pass per locale when:
- full required route/surface sampling is complete;
- context/meaning/layout defects are triaged/fixed;
- subtitles/captions are readable;
- save/recovery/settings/errors are covered;
- credits/legal/platform text is covered where in scope.

These are future runtime/content gates.

This document does not claim any locale has passed them.

---

# 29. Accessibility quality gates

## `A11Y-A — Written coverage`

Pass when:
- each major system identifies input/visual/audio/motion/timing accessibility obligations;
- UI settings surface exists on paper;
- critical single-channel failures are blocked by design;
- production owners are assigned.

## `A11Y-B — Feature implementation`

Future gate.

Requires player-facing settings and alternate presentation/input paths to exist in runtime.

## `A11Y-C — Representative system proof`

Future gate.

Requires at minimum:
- remap/controller/KBM cases;
- large text;
- contrast/color-independent review;
- subtitles/captions;
- muted-audio critical-cue test;
- Reduced Effects/Hush Effects;
- camera shake off;
- representative timing/input alternatives;
- settings persistence.

## `A11Y-D — Human accessibility evaluation`

Future gate.

Use players/evaluators appropriate to the feature under test where practical.

Automated checks and developer review do not replace actual usability evidence.

## `A11Y-E — Platform/store accessibility claims`

Future platform/product gate.

No store accessibility tag, platform claim or certification statement is made until the exact selected platform criteria have been tested.

---

# 30. Platform certification boundary

`SH-QA-004` cannot close now.

Current product direction is PC-first.

Additional launch platforms are `TBD OWNER`.

Therefore:
- do not build a fake console certification checklist;
- do not claim Xbox/PlayStation/Nintendo submission readiness;
- do not assume platform save/storage/account behavior;
- do not pre-author platform-specific accessibility metadata as a shipping claim;
- do not let later platform selection rewrite core gameplay semantics.

When a platform is selected:
1. obtain current official certification/accessibility/submission requirements;
2. add platform-specific requirement ownership to `docs/190`;
3. map each requirement to implementation/evidence;
4. create packaged-build certification fixtures;
5. preserve per-platform evidence separately;
6. block release candidate on unresolved mandatory compliance issues.

---

# 31. Performance / memory / loading / save-integrity boundary

`SH-QA-005` remains runtime-gated.

Final acceptance requires:
- selected target PC/platform context;
- representative content;
- measured frame time;
- memory/streaming evidence;
- Hush transition evidence;
- Skiff-speed streaming evidence;
- load-time evidence;
- long-session/region-transition memory behavior;
- save write/read/recovery evidence;
- migration/corruption fixtures;
- actual build/package context.

No paper number substitutes for these measurements.

---

# 32. Milestone QA expectations

## Prototype era

Focus on:
- fast deterministic checks;
- test maps/fixtures;
- input/accessibility architecture not being blocked;
- semantic state visibility;
- no expensive content-scale claims.

## Vertical slice

Must exercise:
- full representative UI/settings flow;
- accessibility options relevant to slice systems;
- pseudo-localization;
- representative subtitles/captions if dialogue/audio is present;
- save/reload;
- packaged build;
- performance on declared evidence hardware;
- first external/fresh-player accessibility/usability review.

## Production foundations

Before region mass production:
- regression suites are stable;
- System IDEs support reproduction;
- localization pipeline can gather/integrate stress data;
- accessibility settings patterns are reusable;
- source-text/context ownership is stable;
- first-of-family content has cross-discipline acceptance.

## Alpha

Feature complete start to finish.

Accessibility/localization expectation:
- no missing architecture for selected features/languages;
- placeholders allowed only where explicitly tracked;
- all mandatory route surfaces testable.

## Beta

Content complete.

Focus shifts to:
- regressions;
- LQA;
- accessibility consistency;
- save corruption/softlocks;
- performance;
- platform-specific compliance if applicable;
- polish rather than new systems.

## Release candidate

Requires all selected-platform/language/accessibility claims to be backed by current packaged-build evidence.

---

# 33. Required production test profiles

Maintain named profiles so evidence does not depend on one developer's personal settings.

Examples:

```text
profile.default.controller
profile.default.kbm
profile.a11y.large_text
profile.a11y.subtitles_high_contrast
profile.a11y.reduced_motion
profile.a11y.reduced_effects
profile.a11y.muted_audio
profile.a11y.remap_single_press
profile.loc.pseudo_expanded
profile.loc.long_strings
```

These are production/test identities, not gameplay semantic IDs.

When actual locales/platforms are selected, add named profiles for them.

---

# 34. Required cross-discipline acceptance scenarios

At minimum the future test plan must cover these integrated scenarios.

## Scenario A — first launch without hearing

- game starts;
- accessibility setup reachable;
- subtitles/caption controls readable;
- intro/story meaning remains available;
- no audio-only progression cue.

## Scenario B — first launch with controller remap need

- settings reachable before play;
- action remap works;
- prompts update;
- required UI recovery action remains bound/recoverable.

## Scenario C — large text + long localized strings

- title/pause/settings/journal/recovery remain operable;
- no destructive option ambiguity;
- focus remains visible;
- scroll behavior preserves content access.

## Scenario D — muted combat

- enemy telegraphs remain fair;
- committed offscreen threat remains perceivable when required;
- Perfect Guard success is not audio-exclusive.

## Scenario E — reduced Hush effects

- semantic layer relation remains understandable;
- seam eligibility/rejection remains legible;
- puzzle/Cantor information remains available without a single sensory channel.

## Scenario F — save recovery in non-source locale

- error/recovery copy loads correctly;
- playthrough identity remains semantic, not translated-text keyed;
- destructive/recovery choices remain unambiguous.

## Scenario G — Null Meridian with accessibility profile

- accessibility settings persist into finale;
- no S1–S6 mechanic assumes default audio/color/effects settings;
- Maelor/Listener information remains readable;
- optional completion still does not gate canonical ending.

---

# 35. What this package does not authorize

It does not authorize:
- UE5.8 implementation;
- creating accessibility widgets/settings in-engine;
- localization vendor engagement;
- selecting ship languages;
- selecting VO scope;
- selecting consoles;
- running certification;
- claiming WCAG/XAG/platform conformance;
- performance profiling;
- human playtesting;
- localization recording;
- final subtitle timings;
- final font selection;
- final contrast measurements;
- final accessibility metadata/store claims.

---

# 36. Current unresolved gates carried forward

## Owner/product gates

- launch platforms beyond PC-first;
- target-PC baseline;
- VO scope;
- ship-language list;
- commercial title/clearance.

## Runtime gates

- Hush production representation;
- final performance budgets;
- world/module metrics;
- movement/camera/combat/Skiff tuning;
- final caption timing/priority;
- screen narration support quality if pursued;
- final motion/contrast/readability proof;
- save/load/migration integrity.

## Documentation/content-authoring gate

- `CONTENT-ROSTER-RECONCILIATION-001` for final item-level 36 Fault / 18 Shard / 24 Vault roster.

None of these may be hidden by QA status reporting.

---

# 37. Research basis

Current external references were used only to challenge production completeness, not to redefine Stillring.

Relevant current practices include:
- Microsoft Xbox Accessibility Guidelines for subtitles/captions, input, contrast, UI navigation and visual distractions/motion settings;
- WCAG 2.2 principles as an additional interface readability/keyboard/focus reference, without claiming web-standard legal conformance for the game;
- Unreal Engine 5.8 `FText`, String Table and localization tooling behavior;
- Unreal Engine 5.8 Automation/Functional Test framework and optional Gauntlet orchestration.

Stillring-specific requirements remain repository authority.

---

# 38. Production closure rule

This workstream is written-production complete when an external studio can answer from repository authority:

- what QA evidence means;
- what blocks a milestone;
- how defects are classified;
- which accessibility responsibilities belong to each discipline;
- how critical cue redundancy works;
- how localization identity/context is maintained;
- how pseudo-localization/LQA enter production;
- which platform/language/performance questions remain gated;
- what can and cannot be claimed before runtime proof exists.

Runtime accessibility, localization, certification and performance acceptance remain future evidence gates.
