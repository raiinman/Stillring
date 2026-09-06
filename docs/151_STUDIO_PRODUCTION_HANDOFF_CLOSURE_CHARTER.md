# 151 — Studio Production Handoff Closure Charter

**Status:** ACTIVE / DOCUMENTATION-ONLY PRE-PRODUCTION CLOSURE  
**Updated:** 2026-09-05  
**Baseline main:** `aa80c1f295d3c194c9fe5189ec2056d77db64221`  
**Owner boundary:** **NO TESTING / NO UE5.8 IMPLEMENTATION YET**  
**Purpose:** raise Stillring from an engineering-safe design package to a studio-handoff-safe production package

---

# 1. Why this program exists

The Documentation Closure Program made Stillring substantially safer for implementation:

- current authority is indexed;
- superseded design is mapped;
- major state ownership is explicit;
- cross-system contracts are directional;
- runtime proof is separated from paper design;
- unresolved questions are classified;
- System IDE obligations are documented;
- core gameplay, story, progression, traversal, Hush, save, completion, Setup/Payoff, Line Skiff, and Null Meridian authority are documented.

That is enough for a competent engineering/gameplay team to begin scoped prototype work without silently inventing Stillring's core mechanics.

It is **not yet enough** for the stronger handoff standard:

> **Give a competent external studio the repository and let them staff, estimate, schedule, author, build, polish, and ship the intended game without repeatedly asking the owner to reconstruct creative or production intent from chat history.**

The remaining gap is not primarily more gameplay-system theory.

The remaining gap is **discipline-complete production authority**.

Core maxim:

> **A studio should know what to build, why it exists, what quality bar it must meet, what it depends on, what it may choose, and what it is not authorized to redefine.**

---

# 2. Current studio-handoff assessment

## 2.1 What is already strong enough

A studio can already determine with high confidence:

- the product's high concept and adventure identity;
- the single-player / PC-first / controller-first scope direction;
- the 20–30 hour first-playthrough target;
- the authored-world rather than checklist-open-world philosophy;
- the story spine and major regions;
- the six-region structure and post-Stillness transformation intent;
- core locomotion grammar;
- camera and target-lock grammar;
- player combat and encounter philosophy;
- Cantor / field-tool role;
- Hush semantic rules;
- save/world-state ownership and persistence identity;
- completion counts, weighting, thresholds, and ownership;
- Setup/Payoff architecture and all 12 chains;
- Line Skiff identity, acquisition, route grammar, mastery, and completion integration;
- Null Meridian's six-sequence finale structure and thematic/mechanical argument;
- major System IDE/workbench requirements;
- clean-room / original-IP constraints;
- major accessibility principles;
- broad gate/implementation order.

A studio should **not** need owner clarification to decide whether Stillring has universal climbing, traversal stamina, a generic mount, a morality meter, a loot treadmill, a procedurally generated story, a finale-only core verb, or a hidden second debug-state model. Those decisions are already closed.

## 2.2 What is not yet strong enough

A studio cannot yet reliably determine the complete production burden for:

- final character art and visual production;
- environment/prop production;
- animation inventory and animation technology boundaries;
- audio/music/VO production;
- complete UI/UX screen and state coverage;
- cinematic/dialogue production deliverables;
- region-by-region asset/content counts;
- staffing and discipline dependencies;
- launch-platform scope;
- target-PC performance baseline;
- localization/certification scope;
- complete production quality bars for every discipline.

Those gaps are sufficient to make a full-game production quote, staffing plan, or outsourcing package rely on studio assumptions.

That is unacceptable under the desired handoff standard.

---

# 3. Program boundary

This program is **documentation and production-definition work only**.

It may:

- define art, animation, audio, UI/UX, narrative-production, technical-production, and content-production bibles;
- create region/character/system asset manifests;
- create deliverable inventories and dependency maps;
- define production quality bars and approval boundaries;
- identify owner decisions that genuinely remain open;
- identify studio-owned implementation choices that do not require owner approval;
- define staffing/discipline dependencies without inventing a fake dollar budget;
- establish naming, source-control, folder, asset, and content-authoring conventions where they can be decided without runtime evidence;
- record platform/performance decisions as explicit `TBD OWNER` where they remain genuinely undecided;
- build a final studio-handoff acceptance audit.

It does **not** authorize:

- UE5.8 implementation;
- gameplay testing;
- human play acceptance;
- production art creation;
- final animation production;
- recording VO;
- composing final score;
- runtime profiling;
- certification submissions;
- closing runtime-dependent issues #4, #5, or #58;
- changing locked game design merely to simplify a studio estimate.

---

# 4. Studio-handoff definition of done

The repository is studio-handoff-safe only when a competent external studio can answer all of the following from repository authority:

1. **What are we building?**
2. **What is the player experience supposed to feel like?**
3. **What systems/content are mandatory?**
4. **What systems/content are optional?**
5. **What is the scope per region, character, encounter family, dungeon, UI surface, audio family, and cinematic family?**
6. **What are the expected deliverables by discipline?**
7. **What technical decisions are locked?**
8. **What technical decisions may the studio choose?**
9. **What decisions must return to the owner?**
10. **What quality bars must be demonstrated before a deliverable is accepted?**
11. **What dependencies prevent one discipline from working safely before another?**
12. **What is historical/superseded and must not be implemented?**
13. **What remains intentionally TBD?**
14. **What is not yet runtime-proven?**
15. **What may not be inferred from chat history, genre convention, Unreal defaults, or another game's implementation?**

If a studio must reconstruct one of those answers from conversation history, the handoff is not closed.

---

# 5. Required closure outputs

The Studio Production Handoff Closure must produce the following repository artifacts.

## 5.1 Art Bible

Must define production-facing visual authority for:

- Neris;
- major named characters;
- NPC population language;
- enemy visual families;
- bosses;
- regional architecture;
- regional environmental shape language;
- props and civic machinery;
- Waybells / resonance infrastructure;
- Cantor Key and major tools;
- Waking versus Hush visual relationship;
- Stillness/catastrophe states;
- Null Meridian;
- materials/textures;
- lighting;
- fog/atmosphere;
- VFX;
- decals/signage/inspection marks;
- silhouette/readability rules;
- world-scale reference metrics;
- approved visual-reference methodology under IP guardrails.

It must distinguish:

- visual philosophy;
- production rules;
- per-asset quality requirements;
- prototype-allowed simplifications;
- final-production expectations.

## 5.2 Character / Environment / Prop Production Manifests

Must identify, at minimum:

- hero characters;
- recurring named NPCs;
- population archetypes;
- enemy archetypes;
- boss/miniboss assets;
- region modular kits;
- hero structures;
- landmark assets;
- reusable civic machinery;
- puzzle/mechanism families;
- traversal structures;
- Skiff infrastructure;
- Hush variants/paired representation burden;
- Null Meridian unique asset burden;
- completion-content asset families;
- reusable versus unique assets.

The purpose is not to freeze every mesh count prematurely.

The purpose is to make production scale estimateable.

## 5.3 Animation Bible + Animation Manifest

Must define:

- skeleton/rig strategy boundaries;
- retargeting policy;
- locomotion animation families;
- start/stop/pivot/turn expectations;
- jump/fall/land;
- mantle/ledge/ladder/swim;
- target-lock locomotion;
- combat attacks;
- Guard / Perfect Guard / Evade;
- hit reactions / death;
- tool interactions;
- world interactions;
- Line Skiff boarding/riding/parking;
- Hush transitions;
- NPC ambient behavior;
- enemy/boss families;
- cinematic animation;
- facial/performance approach;
- IK/additive/procedural responsibilities;
- root-motion versus gameplay-authority boundaries;
- animation-event ownership restrictions;
- required animation debug/IDE visibility.

Every major player verb must map to an animation-production family.

## 5.4 Audio / Music / VO Bible

Must define:

- region ambience identity;
- Waking/Hush sound relationship;
- silence as gameplay communication;
- bell/resonance vocabulary;
- Cantor diagnostic feedback hierarchy;
- combat audio hierarchy;
- UI feedback family;
- traversal/Skiff audio;
- creature/enemy audio;
- environmental machinery;
- score philosophy;
- regional musical identity;
- leitmotif policy;
- dynamic/adaptive music states;
- boss/finale music requirements;
- VO scope;
- performance direction;
- bark strategy;
- pronunciation guide;
- subtitle/caption dependency;
- localization implications;
- mix/readability rules where critical information cannot rely on audio alone.

The studio must not be left to invent the sound of Stillring from the sentence "bells matter."

## 5.5 UI/UX Production Specification

Must cover the complete player-facing flow, including at minimum:

- boot/title;
- new game/load;
- save-slot states;
- pause;
- HUD;
- health/resources;
- tool state;
- map;
- quest/objective/journal;
- testimony/record reading;
- inventory/tool/progression surfaces;
- Cantor/pattern presentation;
- completion tracking;
- settings;
- accessibility;
- control remapping;
- subtitles/captions;
- death/retry;
- warnings/errors/recovery states;
- credits;
- controller focus/navigation;
- keyboard/mouse navigation;
- glyph policy;
- text hierarchy;
- recent-dialogue log;
- spoiler/disclosure rules;
- Hush/state-specific UI restrictions;
- debug versus retail UI separation.

The specification must define what screens/states exist even where final visual styling remains an art-production task.

## 5.6 Narrative Production Package

Must translate canonical story into production-facing deliverables:

- final script-status taxonomy;
- scene/cinematic list;
- dialogue scene list;
- incidental NPC conversation families;
- bark matrices;
- branch/variant conditions;
- quiet/travel beats;
- character performance bible;
- voice/personality notes;
- pronunciation guide;
- staging intent;
- cinematic versus gameplay delivery boundary;
- localization context;
- subtitle/caption requirements;
- record/testimony text inventory;
- final text ownership/review process;
- spoiler-sensitive authoring constraints.

Canonical story beats alone are insufficient for VO and cinematic scheduling.

## 5.7 Technical Production Bible

Must consolidate implementation-facing constraints across disciplines without inventing runtime proof.

At minimum:

- UE5.8 authority;
- C++-first gameplay/state boundary;
- thin Blueprint policy;
- stable semantic IDs;
- source-of-truth ownership;
- Save Coordinator boundary;
- System IDE architecture requirements;
- development-only tool stripping/hard-disable;
- Enhanced Input expectations;
- content/data authoring conventions;
- naming conventions;
- folder/package conventions;
- source-control/LFS rules;
- asset-reference policy;
- plugin/framework adoption policy;
- performance-budget placeholders/TBDs;
- platform-conditional boundaries;
- build configurations;
- logging/capture/provenance expectations;
- localization-ready text handling;
- test/fixture naming conventions;
- migration/versioning boundaries;
- implementation choices a studio may make without owner approval;
- implementation choices requiring design review.

## 5.8 Performance / Platform Product Brief

Must explicitly record:

- PC-first remains current product direction;
- exact target-PC baseline: `TBD OWNER` until selected;
- intended launch platform scope: `TBD OWNER` until selected;
- controller/keyboard/mouse baseline;
- target resolutions / framerate goals once selected;
- accessibility/platform dependencies;
- save/storage assumptions;
- online/service assumptions;
- certification implications where platforms are later selected;
- performance evidence requirements by production gate.

Unknown is acceptable.

Silent assumption is not.

## 5.9 Production Dependency / Discipline Matrix

Must show which disciplines/features depend on which upstream decisions/assets.

Examples:

- final animation production depends on character rig standards;
- VO recording depends on script lock and pronunciation/performance direction;
- Hush environment production depends on representation-production architecture selection;
- final VFX depend on readability rules and accessibility redundancy;
- region mass production depends on modular-kit rules and vertical-slice proof;
- Skiff route production depends on route graph/runtime representation;
- Null Meridian production depends on all prerequisite gameplay systems functioning;
- completion UI depends on completion registry semantics and disclosure rules.

The matrix should be useful for staffing/scheduling even before exact dates are assigned.

## 5.10 Region-by-Region Production Manifest

For every major region and finale space, record expected production families:

- environments;
- landmarks;
- reusable kits;
- hero props;
- NPCs;
- enemies;
- bosses;
- mechanisms;
- quests/contracts;
- setup/payoff content;
- Hush changes;
- optional content;
- records/testimonies;
- music/ambience;
- cinematics/dialogue;
- VFX;
- UI/map requirements;
- save/checkpoint/state requirements;
- System IDE fixtures;
- unique technical risks.

The goal is to make each region quoteable and staffable without reducing the game to raw asset-count spreadsheets.

## 5.11 Studio Decision-Rights Matrix

Every meaningful decision type must be classified as one of:

### LOCKED — studio implements, does not redefine

Examples:
- core movement grammar;
- no ordinary traversal stamina tax;
- Hush semantic authority;
- completion counts;
- Line Skiff network-vehicle identity;
- Null Meridian governing idea;
- Setup/Payoff source-fact ownership.

### STUDIO CHOICE WITHIN BOUNDS

Examples:
- exact C++ class decomposition;
- specific editor utility implementation;
- asset modularization details;
- internal technical representation where authority permits alternatives;
- animation toolchain choice that preserves gameplay-authority rules.

### PROTOTYPE / HUMAN-PLAY TUNING

Examples:
- movement speed;
- camera lag;
- combat timing;
- Hush transition duration;
- Skiff acceleration;
- room dimensions.

### OWNER DECISION REQUIRED

Examples currently known:
- launch-platform scope;
- target-PC performance baseline;
- future genuine product-scope changes;
- major visual-direction redefinition;
- changes to locked story/gameplay canon.

## 5.12 Final Studio Handoff Acceptance Audit

Must answer the final question:

> **Could a competent external studio build the intended Stillring from repository authority without reconstructing owner intent from chat history?**

The answer must be evidence-based by discipline, not aspirational.

---

# 6. Quality of documentation required

Studio-handoff documents must be:

- implementation-aware but not implementation-fiction;
- specific enough to quote and staff;
- explicit about reusable versus unique production burden;
- explicit about optional versus critical-path content;
- explicit about ownership and decision rights;
- explicit about unresolved owner choices;
- cross-linked to existing canonical gameplay/story authority;
- free of stale superseded counts;
- free of undefined internal shorthand;
- usable by a person who was not present for the original conversations.

Avoid documents that merely restate mood words.

For example:

Bad:
> Rootmere should feel mystical and wet.

Better:
> Rootmere requires a reusable wet-woodland modular kit, root-bridge traversal family, bell-oak hero assets, fungal-light prop family, water-edge collision/readability rules, Waking/Hush paired-state burden, region-specific ambience identity, and the named quest/mechanism content already mapped by canonical story/completion authority.

---

# 7. Studio handoff versus production lock

Studio-handoff-safe does **not** mean every production asset is locked.

It means the studio understands:

- what is intentionally final;
- what is intentionally provisional;
- who gets to decide the provisional part;
- what evidence closes it;
- what downstream work depends on that closure.

A production package may say:

`TARGET PC = TBD OWNER BEFORE GATE 5`

That is acceptable.

It may not omit the topic and let the studio assume one.

---

# 8. Relationship to docs 135–150

`docs/135`–`docs/150` remain valid authority for documentation closure, engineering readiness, ownership, runtime evidence, and implementation boundaries.

This program adds a stricter production-handoff layer.

`docs/150_IMPLEMENTATION_OWNER_REVIEW_PACKAGE.md` recommended beginning UE5.8 implementation after documentation closure.

The owner has since chosen:

> **NO TESTING YET. DOCUMENT THE STUDIO-HANDOFF GAPS FIRST.**

Therefore the current operational boundary is:

- implementation remains on hold;
- testing remains on hold;
- Studio Production Handoff Closure is the active pre-production task;
- no previous locked gameplay/story decision is reopened merely because production documentation is incomplete.

---

# 9. Completion condition

This program is complete only when:

- every required output in Section 5 exists;
- every major production discipline has a usable bible/specification;
- every major region has a production manifest;
- every major character/enemy/system has an identifiable production burden;
- studio decision rights are explicit;
- platform/performance unknowns are either decided or explicitly gated;
- final-game quote/staffing assumptions no longer depend on chat history;
- the final acceptance audit finds no owner-intent reconstruction requirement for normal production work;
- genuine remaining owner decisions are few, explicit, and scheduled at appropriate gates.

Until then:

> **Stillring is design-rich and engineering-readable, but not yet a complete external-studio production handoff package.**
