# 182 — Stillring Narrative Production Bible

**Status:** ACTIVE / STUDIO-HANDOFF NARRATIVE PRODUCTION AUTHORITY / DOCUMENTATION-ONLY  
**Updated:** 2026-09-06  
**Parent program:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Decision rights:** `docs/170_STUDIO_DECISION_RIGHTS_MATRIX.md`  
**Canonical story authority:** `docs/02_STORY_BIBLE.md`, `docs/story/01_FOUNDATIONS_AND_OPENING.md` through `docs/story/12_WORLD_PULSE_LEDGER.md`, regional story bibles, `docs/12_100_PERCENT_ROUTE.md`  
**Dialogue-intent authority:** `docs/story/10_DIALOGUE_ANCHORS.md`  
**Audio/performance dependency:** `docs/179_STILLRING_AUDIO_MUSIC_VO_BIBLE.md`, `docs/180_AUDIO_CUE_ASSET_AND_MUSIC_MANIFEST.md`  
**Animation dependency:** `docs/173_STILLRING_ANIMATION_BIBLE.md`, `docs/174_ANIMATION_PRODUCTION_MANIFEST.md`  
**UI/localization dependency:** `docs/176_UI_UX_PRODUCTION_SPECIFICATION.md`, `docs/177_UI_SCREEN_STATE_AND_ASSET_MANIFEST.md`  
**Companion production manifest:** `docs/183_NARRATIVE_SCENE_DIALOGUE_TEXT_MANIFEST.md`  
**Closes toward:** `SH-NAR-001` through `SH-NAR-009`  
**Boundary:** this document defines narrative production authority, script states, delivery classes, writing/performance requirements, text metadata and approval boundaries. It does not authorize UE5.8 implementation, final VO scope, recording, cinematic animation, final dialogue-copy lock, localization vendor selection, or runtime evidence.

---

# 1. Purpose

Stillring already has unusually strong story canon.

That is not the same thing as a production script.

A studio must be able to determine:
- which story facts are immutable canon;
- which scene beats are mandatory;
- which lines have locked wording;
- which lines preserve intent but require final script writing;
- which scenes must remain playable;
- which scenes may use cinematic staging;
- which optional/world-pulse conversations must exist;
- what records/testimonies require authored final text;
- what metadata localization, VO, animation, UI and implementation need;
- which narrative decisions are not available to a cinematic or dialogue team simply because a preferred pipeline would be easier.

The governing principle is:

> **Canon tells production what must remain true. The production script decides how human beings actually say and perform it without changing that truth.**

---

# 2. Authority hierarchy

When narrative sources disagree, resolve in this order unless a later explicit supersession says otherwise:

1. final canonical story/finale/character facts;
2. `docs/story/07_SCENE_BEAT_LEDGER.md` for mandatory scene order and control form;
3. `docs/story/08_REVEAL_AND_FORESHADOW_LEDGER.md` for reveal timing;
4. `docs/story/09_MAIN_QUEST_OBJECTIVE_FLOW.md` for player motivation/objective continuity;
5. `docs/story/10_DIALOGUE_ANCHORS.md` for protected line wording/intent;
6. `docs/story/12_WORLD_PULSE_LEDGER.md` for offscreen/living-world changes;
7. regional story bibles and current completion/Setup-Payoff authorities for optional/state-specific content;
8. this Bible and `docs/183` for production classification and workflow;
9. final approved scripts derived from those authorities;
10. Sequencer, animation, audio, UI and implementation assets as representation only.

If a final script draft seems to require changing a higher-order fact, stop and reconcile. Do not let a scene asset quietly become a new canon source.

---

# 3. Canon is not screenplay prose

Stillring intentionally separates:

## Canonical fact
What happened, who knows it, when it becomes knowable, what changes, and what it means to the character/world.

## Canonical scene beat
The required dramatic/gameplay event and control relationship.

## Dialogue anchor
A protected line, shape or conversational function.

## Production script
The actual spoken/written text, pauses, interruptions, performance notes, local staging, optional variants and implementation metadata.

## Representation
The Level Sequence, dialogue asset, trigger, subtitle row, localized text resource, animation, camera track, audio file or Blueprint/C++ consumer.

Representation never outranks meaning.

---

# 4. Script-status taxonomy — LOCKED

Every production text/scene record uses one explicit status.

## `CANON_FACT_LOCKED`

Meaning is fixed and may not be rewritten by production.

Examples:
- Ilyra designed Mercy Window;
- Maelor deliberately disabled one First Ring damping layer;
- Tessa knowingly avoided learning more about restricted freight but did not know Stillring;
- Orin knew the official death account was false but did not know Ilyra remained alive;
- the Listener is emergent Hush possibility, not a god/possessor.

## `SCENE_BEAT_LOCKED`

The scene's dramatic function, order, objective transition and control relationship are current authority. Final wording/staging may still be authored inside bounds.

All 113 mandatory scene beats in `docs/story/07` begin here unless a stronger line-level status applies.

## `LINE_LOCKED`

Exact wording is current story identity under `docs/story/10`.

It may change only through deliberate narrative continuity review, not routine copy editing.

## `LINE_STRONG`

Speaker, meaning and emotional shape are locked. Copy editing/performance-naturalization is allowed if it preserves all three.

## `LINE_INTENT`

Conversational function and speaker truth are locked; quoted draft language is illustrative and should normally be rewritten into final performed prose.

## `DRAFT_REQUIRED`

The production need is known, but final player-facing copy has not yet been authored.

This is not permission to invent new canon. The draft must cite its governing scene/fact sources.

## `INCIDENTAL_REQUIRED`

A bounded family of ordinary-life, work, rumor, traversal or world-state lines is required; individual lines are production writing.

## `FINAL_COPY_APPROVED`

Line/document has passed narrative continuity, performance-read, localization-context and spoiler review and may proceed to recording/localization/final integration according to VO scope.

## `LOCALIZATION_LOCK`

Source copy and metadata are frozen for a localization milestone. Later changes require change-control because they create translation/recording churn.

## `SUPERSEDED`

Historical draft. Must not ship or be used as production authority.

No team may use ambiguous labels such as `final-ish`, `temp maybe`, `approved?`, or `cinematic version` as status authority.

---

# 5. Mandatory scene identity

The critical-path production map contains **113 mandatory scene beats** across Movements `M00` through `M18`.

Canonical scene IDs such as:

`M07-S02`

are semantic narrative identifiers.

They survive:
- scene asset renames;
- Level Sequence decomposition;
- camera-shot changes;
- Blueprint/C++ refactors;
- map/package movement;
- dialogue asset changes;
- subtitle/localization pipeline changes.

A Sequencer asset path is not a narrative state key.

A scene may be split into several technical assets or assembled without a Level Sequence at all while remaining one semantic scene beat.

---

# 6. Delivery classes

The existing `PLAYABLE`, `HYBRID`, `WALK/TALK`, and `CINEMATIC` labels remain canonical. Production uses the following operational classes without changing those labels.

## `NP-A — EMBODIED PLAYABLE`

Story is delivered primarily through player action/world response.

Use for:
- exploration;
- diagnosis;
- puzzle/mechanism work;
- combat/boss resolution;
- environmental evidence;
- ordinary social spaces where control matters.

Requirement:
- do not remove control merely to make dialogue/camera production easier.

## `NP-B — PLAYABLE PERFORMANCE`

Ordinary player control remains while authored dialogue/performance carries meaningful narrative work.

Use bounded delivery aids only where necessary:
- proximity staging;
- movement-speed expectations;
- conversation restart/rebind logic;
- local camera framing that does not seize control.

## `NP-C — WALK/TALK / WORK-TALK`

Movement/work remains meaningful but is constrained enough for reliable conversation performance.

The player should feel like they are traveling/searching/working with someone, not waiting for an audio log.

## `NP-D — HYBRID STAGING`

Control is bounded, temporarily redirected or paused around a committed story beat, then returned cleanly.

Use for:
- confrontations;
- evidence reveals;
- reunion beats;
- crisis commits;
- short controlled transitions.

Hybrid does not mean “make a cutscene if convenient.”

## `NP-E — FULL CINEMATIC`

Control is intentionally removed because authored timing/composition is itself necessary.

Current mandatory story uses this sparingly.

Cinematic treatment must justify why the player cannot carry the beat through ordinary interaction.

## `NP-F — QUIET / FREE AFTERMATH`

Low-pressure player-controlled space following major events.

Quiet is a production requirement, not missing content.

Do not fill every aftermath with objective chatter, score, quips or forced exposition.

## `NP-G — CREDITS / MONTAGE`

Branch-aware consequence presentation derived from canonical facts and completion state.

No shot may invent a “best ending” branch outside authority.

---

# 7. Gameplay versus cinematic boundary — LOCKED

The scene ledger already states:

> A scene may be gameplay, hybrid staging, walk-and-talk, or cinematic. It is not synonymous with “cutscene.”

Production must preserve these rules:

1. A gameplay verb learned through action stays in action.
2. Boss/major-pressure resolution stays playable where canon says playable.
3. Investigation evidence should be discovered/assembled through player work before anyone summarizes it.
4. Quiet ordinary-life scenes stay ordinary; they are not exposition dumping grounds.
5. Major emotional admissions may use bounded staging, but the game should not steal control earlier than necessary or return it later than necessary.
6. The final thematic answer is player action at `M17-S05`, not a replacement monologue.
7. Grand Ring's remembered-world freeze montage is intentionally cinematic because simultaneous distant before-memories are the point.
8. Opening memory and selected transitions may use cinematic fragments while preserving rapid return to play.

No cinematic department may upgrade `PLAYABLE` to `CINEMATIC` for polish without narrative/gameplay owner review.

---

# 8. Sequencer / cinematic technology boundary

Unreal Engine 5.8 Sequencer supports Level Sequences, Sub-Sequences, Shots and Takes and is a valid real-time cinematic implementation tool.

Stillring's rule is:

> **Sequencer organizes presentation; it does not own story truth.**

Allowed:
- a semantic scene represented by one or several Level Sequences;
- Sub-Sequences for independent production ownership;
- Shots/Takes for camera/performance iteration;
- gameplay-triggered sequence fragments where state authority remains outside Sequencer;
- reusable conversation staging where appropriate.

Forbidden:
- quest state existing only as a sequence completion frame;
- durable branch truth encoded only in camera-track selection;
- dialogue availability derived from asset path/name;
- cutscene event tracks silently awarding items/setting world facts without authoritative gameplay transactions;
- save identity keyed to sequence/shot/take names.

Current Epic UE5.8 references:
- `https://dev.epicgames.com/documentation/unreal-engine/cinematics-and-movie-making-in-unreal-engine`
- `https://dev.epicgames.com/documentation/unreal-engine/sequences-shots-and-takes-in-unreal-engine`

Framework use is implementation choice; semantic boundaries are locked.

---

# 9. Scene production record

Every scene entering script/staging production receives a record with at least:

```text
SceneId
Movement
DisplayWorkingTitle
CanonAuthority
NarrativeStatus
ControlLabel
ProductionDeliveryClass
Place / Region
WorldState
RequiredParticipants
OptionalParticipants
EntrySemanticConditions
ExitSemanticCommit
ObjectiveIn
ObjectiveOut
RevealIds / ForeshadowIds
DialogueAnchorIds
Record / Prop Dependencies
GameplayDependencies
AnimationBurden
Audio / MusicBurden
UI / SubtitleBurden
VOStatus
LocalizationContext
SpoilerClass
BranchVariantPolicy
SkipPolicy
Retry / Re-entry Policy
Credits / LaterConsequences
Owner / Writer
ReviewStatus
```

A blank field is either:
- intentionally `NONE`;
- explicitly `TBD` with owner/dependency;
- a production blocker.

It is never silently “whatever the cinematic designer does.”

---

# 10. Entry/exit state ownership

Narrative scenes consume and request semantic state; they do not own the underlying databases.

Examples:
- a scene may become eligible because a quest fact is true;
- a conversation may request a quest/world transaction when a player commits a choice;
- a record pickup may request the authoritative record acquisition transaction;
- a scene may derive different dialogue from Setup/Payoff facts;
- a credits vignette may derive from completion/world facts.

Do not persist `watched_cutscene=true` as a substitute for the actual semantic fact when the fact is what matters.

If presentation interruption occurs after the semantic commit, replay behavior follows the committed truth rather than trying to undo history because the camera sequence did not finish.

---

# 11. Dialogue doctrine

Stillring dialogue is written for people who work, remember badly, interrupt one another and sometimes do not have a thesis-ready answer.

Locked dialogue rules from current canon:
- allow silence;
- technical language usually emerges from work;
- humor is character behavior, not tension-canceling quips;
- not everyone speaks in polished thematic aphorisms;
- Neris is young enough to say unfair things;
- adults may say `I don't know`;
- no prophecy language except when criticized;
- do not make all major characters restate the same theme in different metaphors;
- do not explain a mechanic after the player already demonstrated it;
- do not immediately banter away grief;
- allow unfinished sentences, wrong assumptions and interruption;
- ordinary talk about food, weather, tools, routes, work and petty annoyances is structural worldbuilding.

If a line sounds like a design document, rewrite it for the speaker.

---

# 12. Principal performance bible

These directions reconcile current character/story and Audio Bible authority.

## Neris Vale

**Speech:** direct; mechanical/craft metaphors; impatient with ceremony.  
**Range:** technical absorption, curiosity, dry humor, defensiveness, unfair anger, fear, grief, exhausted restraint, late-game quiet confidence.  
**Trajectory:** does not become grander or more heroic in diction; becomes more willing to let silence stand.  
**Avoid:** chosen-one confidence, precocious adult polish, constant sass, generic inspirational speeches.

## Tessa Marr

**Speech:** route/work vocabulary; practical observation; humor as defense.  
**Range:** ease, teasing, evasiveness, guilt without self-pity, crisis command, reluctant civic responsibility.  
**Avoid:** endless sarcasm, comic-relief reset button, flirty sidekick flattening.

## Ilyra Vale

**Speech:** precise; anxious over-explanation; dry humor; sometimes speaks to the six-year-old Neris she remembers and catches herself.  
**Range:** technical certainty, memory dislocation, guilt, withheld truth, tenderness, defensiveness, admission without absolution.  
**Avoid:** omniscient lore narrator, saintly lost mother, melodramatic confession voice.

## Orin Vale

**Speech:** plainspoken; domestic/craft metaphors; uncomfortable with abstraction.  
**Range:** ordinary warmth, avoidance, fear, protective control, shame, direct answer.  
**Trajectory:** growth appears as shorter and more honest answers.  
**Avoid:** bumbling dad, secret mastermind, redemption speech.

## Maelor Renn

**Speech:** controlled, exact, conclusions repeated internally for years.  
**Range:** genuine technical usefulness, restrained warmth/history, withheld scope, rare anger, strain, ideological certainty, loss.  
**Avoid:** sinister whispering, villain sermon cadence, possession, sadistic pleasure, last-minute absolution.

## Brother Caldrin

**Speech:** careful distinctions; provenance language; dry humor.  
**Range:** institutional confidence, discomfort, moral triage, decisive rupture, public uncertainty.  
**Avoid:** walking citation machine, mystical archivist.

## Sena Ash

**Speech:** short process/worker language; little patience for guilt without action.  
**Range:** suspicion, competence, public anger, practical solidarity, mentorship.  
**Avoid:** fiery warrior stereotype, one-note anti-capital rhetoric.

## Prefect Aven Rusk

**Speech:** administrative precision; formality erodes as the institutional frame fails.  
**Range:** reasonable authority, defensive control, fear of uncoordinated harm, reluctant admission, useful expertise outside authority.  
**Avoid:** corrupt bureaucrat caricature, instant reform convert.

## Listener

Not ordinary conversational performance.

Its language is sparse, composite and sincere. It is not horror-whisper villain speech.

`MUST ALL ENDINGS BE CAGES?` remains locked.

---

# 13. Supporting named-character voice method

C3/C3+ characters already enumerated in `docs/160_REGION_ENVIRONMENT_PROP_MANIFEST.md` receive a production voice card before final dialogue writing.

Each card includes:
- occupation;
- region;
- age/life-stage read where canon supplies it;
- relationship to local infrastructure;
- relationship to Neris;
- speech tempo/length tendency;
- vocabulary domain;
- humor/anger habits;
- what the character refuses to say directly;
- ordinary-life subject;
- changed-world pressure;
- prohibited stereotype;
- pronunciation notes;
- VO class after VO scope decision.

A named character may not be differentiated only by accent.

---

# 14. Accent and vocal-identity boundary

Orra's cultures may have coherent vocal communities, but region identity is not `one fantasy accent per biome`.

Do not assign real-world accents as shorthand for:
- intelligence;
- class;
- trustworthiness;
- criminality;
- mysticism;
- rural simplicity;
- institutional authority.

Casting/performance may use varied natural accents while preserving family/community plausibility.

Final casting dialect policy is a later production choice inside these bounds.

---

# 15. Pronunciation authority

The core pronunciation guide in `docs/179` is inherited.

Narrative production expands it into a living lexicon covering:
- principal names;
- C3/C3+ names;
- regions/settlements;
- civic institutions;
- Waybell/Meridian/Cantor terminology;
- Hush terms;
- tools/patterns;
- historical names;
- record-specific technical terms.

Each entry records:

```text
Written form
Preferred pronunciation
IPA or production phonetic rendering where useful
Stress
Speaker/community variants if canonically intentional
Do-not-use variants
Context / meaning
```

Pronunciation is production metadata, not buried in an actor note or chat message.

---

# 16. Dialogue-choice boundary

Stillring does not manufacture dialogue wheels merely because a dialogue system supports them.

Use player choices only when narrative/gameplay authority defines a real commitment, interpretation or response.

Choice rules:
- no fake choices that immediately converge with no expressive function;
- no hidden morality score;
- no designer-approved moral answer required for 100%;
- branch consequences attach to semantic facts;
- choice text states what Neris is choosing, not opaque mood labels;
- timed dialogue choices are not a default requirement;
- silence/declining to answer may be a choice only when specifically authored.

---

# 17. Ambient conversation and bark doctrine

Ambient writing is not filler.

Its jobs are:
- prove ordinary life;
- show change while Neris is elsewhere;
- provide rumor and disagreement;
- reveal work rhythms;
- make named and unnamed residents feel locally competent;
- give catastrophe a before/after comparison;
- acknowledge optional consequences without a global announcer.

Production families:

## `AMB-WORK`
Task coordination, mistakes, materials, repairs, schedules, food breaks.

## `AMB-SOCIAL`
Family, gossip, jokes, complaints, local arguments, children, meals.

## `AMB-ROUTE`
Travel conditions, ferry/lift/road/Skiff windows, courier exchanges.

## `AMB-INSTITUTION`
Clerks, notices, inspections, records, disputes over authority/procedure.

## `AMB-RUMOR`
Multiple incompatible interpretations of current events. Rumors may be wrong.

## `AMB-CRISIS`
Short actionable changed-world communication; no lore speeches during danger.

## `AMB-RECOVERY`
Repair/adaptation after local resolution or Stillness.

## `AMB-UNRINGING`
Coordination without one master reference; local disagreement remains visible.

## `AMB-CREDITS-ECHO`
Small lines/actions that pay off known ordinary-life details in epilogue/credits.

Each region/state package in `docs/183` specifies required families.

---

# 18. World-pulse dialogue authority

`docs/story/12_WORLD_PULSE_LEDGER.md` is mandatory production input.

At every global pulse A–J, narrative production must review:
- who moved;
- what work changed;
- what notice/sign/document changed;
- what rumor exists;
- which service changed;
- which named NPC has a new opinion or problem;
- which old line becomes stale and must no longer play.

A region with 0% optional completion still changes.

A 100% region gets denser, more specific acknowledgment—not the only valid future.

---

# 19. Repetition / exhaustion rules

Ambient systems must avoid the `same two NPCs repeat the same sentence forever` failure.

Production should support:
- multiple variants per high-frequency semantic family;
- cooldowns or one-shot flags appropriate to presentation, not durable world-state duplication;
- state invalidation after milestones;
- interrupted/partial lines that do not restart obnoxiously every time the player crosses a trigger;
- distance-aware priority;
- important dialogue outranking flavor chatter;
- no overlapping crowd wall of subtitles.

Exact variant counts are production-budget choices after scene/region workload estimation. Do not invent fixed counts now.

---

# 20. Story-critical document classes

Written narrative content is classified as:

## `DOC-LOCKED-EVIDENCE`
Exact wording/format is canonically important.

Examples:
- Ilyra's central phase-load warning;
- Mercy Window project mark;
- Listener locked question where represented as text.

## `DOC-RECORD-COLLECTIBLE`
One of the 32 Testimonies / Field Records.

## `DOC-SCENE-EVIDENCE`
Document/plate/manifest needed by a mandatory scene but not necessarily a completion collectible.

## `DOC-WORLD-NOTICE`
Public boards, handwritten corrections, schedules, route notices, maker/provenance signs.

## `DOC-ARCHIVE`
Longer contextual material in Bone Archive / Quiet Court / civic archives.

## `DOC-UI-JOURNAL-DERIVED`
Journal summary generated from known semantic facts. It is not source evidence itself.

Each document requires provenance and discovery context; anonymous lore text is the exception, not default.

---

# 21. Records / testimony writing rule

The 32-record inventory in `docs/11_QUEST_AND_COMPLETION_LEDGER.md` remains useful for record identities/titles/sets, but that older document contains stale counts for other completion categories.

Narrative production may import **only the still-current 32 record IDs/set structure** after reconciliation with current `docs/104`/`docs/146` authority.

Do not re-import stale 48-Fault, 28-Pulse or 30-vault literals from that file.

Every record final text must answer:
- who created it?;
- why?;
- for whom?;
- when?;
- what did the creator know?;
- what did they misunderstand/omit?;
- how did it survive?;
- what new fact/texture does the player gain?;
- does the writing sound like its artifact type?;
- does it duplicate a reveal already better delivered through play/dialogue?;
- what localization/performance burden exists?;
- what spoiler boundary applies?

A maintenance note should read like a maintenance note, not a lore essay wearing a date stamp.

---

# 22. Journal-summary boundary

The journal may summarize what Neris knows, but it may not silently resolve ambiguity the story has not resolved.

Required distinctions where relevant:
- observed physical fact;
- testimony;
- official claim;
- inferred diagnostic relation;
- unresolved contradiction;
- later confirmed history.

Do not mark one witness `TRUE` merely because the quest designer knows the later answer.

---

# 23. Spoiler classes

Every narrative text entry receives one:

- `SP0` — safe from start;
- `SP1` — safe after first regional introduction;
- `SP2` — Act-One/reveal-sensitive;
- `SP3` — Grand Ring / Ilyra survival sensitive;
- `SP4` — Mercy Window / family-truth sensitive;
- `SP5` — Still-Cairn / finale sensitive;
- `SP6` — postgame/credits only.

File names, debug labels, localization keys, achievement-like UI and audio asset names should avoid casually exposing high-class spoilers where reasonable.

Internal semantic IDs may be descriptive enough for developers, but retail-facing diagnostic exposure must be controlled.

---

# 24. Localization context contract

Every player-facing narrative entry must be localization-ready from first production draft.

Required metadata:

```text
TextId
SourceSceneOrRecordId
Speaker / Source
Addressee where relevant
WorldState
LineIntent
PerformanceIntent
Locked/Strong/Intent/Draft status
PreviousLine / NextLine context
Variables and grammatical meaning
Plural/gender/pronoun context where relevant
On-screen/off-screen/radio/residue/document/UI medium
Character limit only when truly constrained
Subtitle segmentation notes
Pronunciation notes
SpoilerClass
BranchCondition
VOStatus
```

Do not hand translators disconnected spreadsheet strings with no speaker, state or intent.

Unreal Engine's localizable `FText` model uses namespace/key/source identity and supports culture-aware rebuilding. String Tables are available where production finds them useful. Technical Production will choose the concrete asset/data organization, but user-facing narrative text must preserve localization identity.

Current Epic UE5.8 reference:
`https://dev.epicgames.com/documentation/unreal-engine/text-localization-in-unreal-engine`

---

# 25. Variables and grammar

Dynamic text must not be assembled by English-only string concatenation.

If a line contains:
- numbers;
- item names;
- character names;
- region names;
- pronouns;
- grammatical gender/number;
- dates/times;
- player-selected labels;

production text specifies the semantic variable and provides localization context.

Prefer complete localizable phrases over stitched fragments.

---

# 26. Subtitle / performance segmentation

Narrative script and subtitle segmentation are related but not identical.

Production script should mark:
- performance sentence/beat;
- subtitle segmentation points;
- interruptible boundaries;
- noninterruptible locked phrase where needed;
- overlap/crosstalk intention;
- speaker attribution requirements;
- off-screen/source direction where relevant.

UI authority controls final subtitle presentation. Narrative controls meaning and segmentation intent.

---

# 27. VO scope boundary

VO scope remains `TBD OWNER` under `docs/179`.

Narrative production therefore marks every spoken line/scene with a **VO class**, not an assumption that it will or will not be recorded.

## `VO-P0`
Principal critical performance; highest recording value if any selective VO model is chosen.

## `VO-P1`
Major recurring character/critical-path scene.

## `VO-P2`
Named support / significant optional or world-state line.

## `VO-P3`
Ambient/incidental population dialogue.

## `VO-EFFORT`
Combat/traversal/effort/vocalization; governed with Audio/Animation.

## `VO-NONE`
Written document/UI/system text not intended as spoken content unless later presentation changes.

After the scene/text manifest exists, the owner can compare:
- full narrative VO;
- principal/key-scene selective VO;
- gameplay vocalization only.

No writer may preempt that product decision by writing scenes that only function if every line is voiced.

---

# 28. Skip / interruption / replay policy

Final implementation specifics remain runtime work, but narrative production must tag each scene.

Rules:
- player cannot skip past an uncommitted semantic choice and have the game guess the choice;
- skipping presentation after a committed story transaction does not undo the fact;
- mandatory information must reach Journal/objective/world state even if a cinematic is skipped where appropriate;
- locked performance moments may delay skip until a safe boundary if necessary, but unskippable length must be justified;
- interrupted WALK/TALK content must either resume, rebind, safely summarize, or be noncritical flavor;
- replaying presentation cannot duplicate rewards/world facts;
- death/retry does not accidentally replay already-committed one-shot narrative state.

---

# 29. Records of uncertainty

Stillring's story frequently contains conflicting claims.

Production must distinguish:
- deliberate character lie;
- omission;
- honest misunderstanding;
- stale official record;
- technically correct but contextually wrong statement;
- rumor;
- Hush possibility;
- unresolved uncertainty.

Do not flatten all contradiction into `someone lied`.

This distinction should be available to writers/localizers/actors as context even when the player does not know it yet.

---

# 30. Credits production doctrine

Credits are a continuation-of-life accounting, not a victory checklist.

Core credits authority in `docs/story/05_CREDITS_AND_THEMATIC_RULES.md` requires recognizable consequence units for:
- Brindle;
- Rootmere;
- Saltreach;
- Emberstep;
- High Aerie;
- Mireglass;
- Cairnfall;
- Cairnspire;
- Maelor's ongoing public trial.

Optional completion modifies:
- specific faces;
- visible project maturity;
- props/signage/routes;
- who participates;
- small dialogue/text acknowledgements;
- density of consequence.

It does not determine whether the ending is morally valid.

There is no `100% true ending` text branch.

Post-credits remote-island bell remains unexplained.

---

# 31. Final-text approval path

A narrative item reaches `FINAL_COPY_APPROVED` only after:

1. canon/fact check;
2. reveal-timing check;
3. character-voice check;
4. gameplay/control check;
5. repetition/exposition check;
6. dialogue-anchor check;
7. state/branch check;
8. UI/subtitle readability check;
9. localization-context metadata check;
10. VO/performance note check where applicable;
11. spoiler classification;
12. cross-discipline dependency check.

A line can be grammatically polished and still fail because it reveals something six hours too early.

---

# 32. Change-control classes

## Copy edit — studio allowed

Allowed on `LINE_STRONG`, `LINE_INTENT`, `DRAFT_REQUIRED`, incidental/record copy when meaning/reveal/voice remain unchanged.

## Performance naturalization — studio allowed within bounds

Actors/director may suggest contraction, breath, interruption, small word-order changes, provided locked meaning and reveal timing remain intact and the revised line returns through script review.

## Continuity change — narrative lead review required

Any change to:
- who knows what;
- when truth is revealed;
- scene order;
- objective motivation;
- branch consequence;
- canonical document meaning;
- character culpability;
- credits consequence.

## Owner review required

Material changes to:
- ending/finale meaning;
- principal character arcs;
- Maelor/Ilyra/Orin culpability boundaries;
- Listener nature;
- optional-completion moral validity;
- major product scope/VO model where owner authority applies.

---

# 33. Narrative technical data expectations

Final Technical Production Bible chooses concrete data structures, but narrative content must support:
- stable semantic scene/text/document IDs;
- source-controlled text;
- diffable review where practical;
- localization extraction;
- speaker/scene/state metadata;
- branch conditions referencing semantic facts;
- subtitle and VO references;
- record provenance;
- validation for missing text/context;
- no required production dialogue hardcoded as arbitrary Blueprint literals;
- no canonical truth stored only in Level Sequence tracks.

---

# 34. Narrative validation / IDE support

Development tooling should eventually let narrative/QA inspect:
- current semantic story facts;
- current eligible scene/dialogue IDs;
- why a scene/line is eligible or blocked;
- current reveal/spoiler state;
- active world pulse;
- selected dialogue variant and source condition;
- record acquisition/provenance;
- subtitle/localization text ID;
- current VO/audio reference;
- scene semantic commit state separately from presentation playback state;
- credits consequence sources.

Useful development exercises:
- jump to canonical scene baseline through safe fixtures;
- compare critical-path versus selected Setup/Payoff states;
- test interrupted walk/talk;
- skip before/after semantic commit;
- pseudo-localize a full scene;
- mute VO and confirm text delivery remains coherent;
- force world-pulse variants without mutating shadow canon;
- verify record sets and journal summaries.

Shipping does not expose arbitrary narrative-state mutation.

---

# 35. Production quality failures

Reject narrative production that:
- turns all 113 beats into cutscenes;
- makes Neris a passive audience for explanations she should discover through work;
- makes every character speak in thesis statements;
- uses optional lore as mandatory explanation;
- lets ambient NPCs freeze in one prequest state forever;
- turns rumors into automatic quest truth;
- makes Hush voices spooky by default rather than semantically grounded;
- adds fake morality scoring;
- makes 100% required for the valid ending;
- rewrites Maelor as possessed/secretly evil from the start;
- rewrites Ilyra as secretly innocent;
- rewrites Orin as knowing Ilyra was alive;
- makes Tessa knowingly understand Stillring freight;
- turns the Listener into a final villain monologue;
- stores durable story state only in scene assets;
- ships untranslated hardcoded strings because they were `temporary`;
- records VO before line/reveal/state context is stable enough to avoid obvious churn.

---

# 36. Decision rights

## LOCKED

- canonical story facts/arcs/reveal order;
- 113 mandatory scene-beat identity/order unless deliberately revised;
- scene-ledger control labels;
- Dialogue Anchor LOCKED/STRONG/INTENT semantics;
- final answer through player action;
- world-pulse living-world requirement;
- optional completion does not gate valid ending;
- branch truth uses semantic facts, not scene asset identity;
- localization context is required from production draft stage;
- no runtime/generated AI dialogue requirement.

## STUDIO CHOICE WITHIN BOUNDS

- exact final prose for `DRAFT_REQUIRED`/`LINE_INTENT` material;
- copy editing of `LINE_STRONG` within meaning/voice bounds;
- precise camera blocking inside allowed scene control class;
- number of technical Level Sequences/Shots/Takes;
- dialogue-data implementation shape;
- ambient variant counts after budgeting;
- casting/dialect detail within character/cultural bounds;
- exact subtitle line segmentation with UI/localization review.

## PRODUCTION / RUNTIME-GATED

- final cinematic shot lengths;
- exact walk/talk interruption thresholds;
- skip input/timing;
- final subtitle pacing;
- final lip-sync technology;
- exact incidental line frequency;
- final branch/re-entry UX tuning.

## TBD OWNER / PRODUCT

- final VO scope model;
- ship-language list;
- material change to principal canon/product scope.

---

# 37. Governing narrative production principles

> **The player should usually learn the world by doing work in it, not by being told what the Story Bible says.**

> **A scene ID is narrative identity. A cinematic asset is representation.**

> **Characters are allowed to be incomplete, wrong, interrupted, funny, ordinary and silent.**

> **Optional content deepens the accounting; it never buys the only valid future.**

> **The final script must sound like people living through Stillring, not like Stillring explaining itself.**
