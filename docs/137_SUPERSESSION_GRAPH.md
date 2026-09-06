# 137 — Supersession Graph

**Status:** CANONICAL PRECEDENCE / NAVIGATION AUTHORITY  
**Updated:** 2026-09-05  
**Program:** Documentation Closure Phase 1

## Purpose

Stillring intentionally preserves historical design documents.

That is useful only if a future contributor can tell when an older document is still current, partially current, or explicitly superseded.

This graph records **scoped precedence**.

It is not a rule that "higher document number always wins."

Core rule:

> **Newer authority supersedes older material only within the scope explicitly resolved by the newer authority. Unaffected material remains valid.**

If a conflict is not listed here or clearly resolved inside the authority files themselves, do not guess. Register it for closure review.

---

# 1. Graph notation

```text
A  --->  B
```

means:

**A supersedes or governs B for the stated scope.**

```text
A  -X->  B
```

means:

**B is historical/reverted and must not be treated as current authority for that scope.**

```text
A  --->  B [numeric only]
```

means B remains useful except for numeric literals controlled by A.

---

# 2. Top-level process precedence

```text
docs/135_DOCUMENTATION_CLOSURE_PROGRAM_CHARTER.md
        ---> closure-process assumptions in older handoffs/chat-derived notes

docs/136_CANONICAL_AUTHORITY_INDEX.md
        ---> ad-hoc guesses about which file to read first

docs/137_SUPERSESSION_GRAPH.md
        ---> date/filename-number-only precedence guesses

docs/NEXT_CHAT_HANDOFF.md
        ---> previous versions of NEXT_CHAT_HANDOFF.md
```

`NEXT_CHAT_HANDOFF.md` is operational navigation, not gameplay design authority. It points to authority; it does not replace it.

---

# 3. Locomotion precedence

Current cumulative locomotion authority:

```text
docs/20_GATE1_LOCOMOTION_SPECIFICATION.md
        ---> earlier individual locomotion decision drafts/notes for incorporated topics
```

Important locked scoped precedence includes:
- no ordinary traversal stamina/resource cost;
- deliberate jump remains available;
- low-obstacle mantle/scramble remains authored/bounded;
- no universal/free climbing;
- same-continuous-handhold shimmy only;
- no corner wrapping/gap transfers/lateral jumps/vertical handhold climbing by baseline shimmy;
- explicit Drop/Release required; analog drift/down/away does not silently release.

A future prototype may tune values but may not use "prototype feel" as authority to silently remove these locks.

---

# 4. Camera precedence

```text
docs/22_GATE1_CAMERA_SPECIFICATION.md
        ---> incorporated individual camera decisions in docs/23–36 where cumulative text conflicts
```

Supporting camera addenda remain useful for exact edge-case rationale and fixtures unless the cumulative specification or a later explicit reconciliation says otherwise.

No stock Unreal Third Person camera value and no copied Zelda camera value supersedes Stillring authority merely because it is convenient.

---

# 5. Combat / encounter precedence

Player combat:

```text
docs/48_GATE2_COMBAT_STATE_MODEL.md
        ---> earlier Gate 2 player-combat drafts for incorporated state-model topics
```

Enemy/encounter:

```text
docs/59_GATE2_ENCOUNTER_FIXTURE_CLOSURE.md
        ---> incomplete fixture assumptions inside earlier encounter drafts
```

Docs 50–58 remain scoped authority for their individual encounter topics unless explicitly reconciled by later closure/cumulative authority.

Combat/encounter implementation may not override camera readability/targeting authority by simply spawning or scheduling more simultaneous threats.

---

# 6. Gate 3 filename/reference precedence

Canonical cumulative Gate 3 tool-system document:

```text
docs/69_GATE3_TOOL_SYSTEM_CUMULATIVE.md
```

Stale/nonexistent reference:

```text
docs/69_GATE3_TOOL_PUZZLE_CUMULATIVE_SPECIFICATION.md
```

Therefore:

```text
docs/69_GATE3_TOOL_SYSTEM_CUMULATIVE.md
        -X-> docs/69_GATE3_TOOL_PUZZLE_CUMULATIVE_SPECIFICATION.md [filename/reference only]
```

The stale filename is not a historical design fork; it is a broken reference.

Any document linking the nonexistent filename should be repaired to the actual cumulative file.

---

# 7. Gate 4 / Hush precedence

```text
docs/79_GATE4_HUSH_CUMULATIVE_SPECIFICATION.md
        ---> docs/70–78 for incorporated cumulative topics
```

Docs 70–78 remain useful detailed authority where consistent.

Production-architecture caution:

```text
Gate 4 prototype direction (World Partition + Runtime Data Layers, spatial streaming disabled)
        DOES NOT ---> production architecture proof
```

The prototype does not supersede the requirement to compare real authoring/source-control/performance/save behavior before production lock.

Data Layer loaded state never supersedes semantic world-state authority.

---

# 8. Save / World-State precedence

```text
docs/88_SAVE_WORLD_STATE_CUMULATIVE_SPECIFICATION.md
        ---> docs/81–87 for incorporated cumulative behavior
```

Docs 81–87 remain detailed subcontracts.

Runtime proof boundary:

```text
docs/81–88 design package
        DOES NOT ---> GitHub Issue #4 runtime verification requirement
```

Issue #4 remains open until paired-layer save/exit/reload reproduction is proven in runtime.

Stable semantic IDs supersede:
- actor paths;
- runtime instance IDs;
- display strings;
- map coordinates;
- transient Data Layer load state;
- trigger occupancy;

as canonical persistence identity.

---

# 9. Completion numeric precedence

This is one of the most implementation-dangerous precedence areas.

## Governing numeric authority

```text
docs/104_COMPLETION_LEDGER_RECONCILIATION_AUTHORITY_ADDENDUM.md
        ---> docs/10_COMPLETION_MODEL.md [where numeric model differs]
        ---> docs/11_QUEST_AND_COMPLETION_LEDGER.md [numeric counts/thresholds only]
        ---> docs/12_100_PERCENT_ROUTE.md [numeric counts/thresholds only]
        ---> docs/13_CANTOR_AND_UPGRADE_CATALOG.md [completion thresholds only]
        ---> docs/14_PRESTIGE_AND_MASTERY_CONTENT.md [global weighting/count interpretation only]
        ---> older completion planning documents [numeric counts/weights]
```

Those older files remain narrative/content authorities for unaffected descriptions.

## Canonical replacements

```text
48 Resonance Faults   ---> 36 Resonance Faults
28 Pulse Shards       ---> 18 Pulse Shards
30 Micro-vaults       ---> 24 Micro-vaults
K02 at 30 Faults      ---> K02 at 24 reconciled Faults
Drift unlock at 13    ---> 10 reconciled Faults + existing story/Line Skiff prerequisites
12 prestige stages as 12 global items
                       ---> 1 global Unstandard Tool item / 12 internal stages
7 Yard commissions as 7 global items
                       ---> 1 global Broken Standard Yard item / 7 internal commissions
```

## Blocklist

`docs/109_COMPLETION_LEGACY_LITERAL_BLOCKLIST.md` explicitly protects implementation from stale literals.

Therefore:

```text
docs/104 + docs/109
        ---> any stale hard-coded completion literal in older content docs
```

Do not perform blind global numeric replacements. Preserve narrative prose and repair scoped stale values deliberately.

---

# 10. Setup/Payoff precedence

Issue #9 authority layers:

```text
docs/112 state authority
   -> docs/113 commit boundaries
   -> docs/114 payoff materiality
   -> docs/115 portfolio
   -> docs/116 authoring/data contract
   -> docs/117 canonical prototype instantiation
   -> docs/118 closure audit
   -> docs/119 navigation register
```

These are additive scoped authorities, not a simple replacement chain.

## Core ownership precedence

```text
source-system facts
        ---> copied Setup/Payoff shadow facts
```

Meaning:

**Source systems own facts. Setup/Payoff evaluates them. It does not copy them.**

## Portfolio precedence

Doc 115 supersedes older portfolio wording where it conflicts, including:

### S07 Pressure Release

Older interpretations that turn S07 into another refuge/moving-pocket payoff are superseded.

Current payoff focuses on **operational autonomy/control/labor**:
- independent deep-inlet crews retain manual pressure authority and can create their own low-water work/rescue/salvage windows;
- reconnected route improves main-dock pressure resilience/heavy service but removes independent deep-inlet control and requires coordinated assistance.

### S10 Distributed Copy

Older interpretations that reduce S10 to "backup copy survives" are superseded.

Current payoff is **distributed agency/knowledge**:
- ordinary people/novices can possess/challenge/act on knowledge before archive authority returns;
- may affect recognition, action, standing, triage/rescue timing;
- not simply duplicate-record survival.

### S11 timing

Doc 117 clarifies:
- seed/encounter may begin on road toward Cairnspire;
- the meaningful provenance classification commit occurs through Cairnspire civic registration.

Older shorthand implying the commit itself belongs to First Circuit is subordinate.

---

# 11. Traversal Transformation precedence

Issue #10 authority:

```text
docs/120 selection
   + docs/121 route grammar
   + docs/122 world-layer route state
   + docs/123 acquisition/mastery
   + docs/124 network integration
        ---> older vague "horse/mount" or free-roam traversal assumptions
```

Core precedence:

```text
Line Skiff = network vehicle
        ---> mount/free-roam/horse analogue assumptions
```

Therefore older/current prose cannot be interpreted to authorize:
- summon anywhere;
- cross-country driving;
- ordinary mounted combat;
- fuel/stamina/ticket tax on normal use;
- Roadhand Pulse as speed boost;
- Switchshoe as raw speed percentage;
- arbitrary Hush shift where no paired route continuation exists;
- twelve bespoke racetracks justified only by Drift Knot count.

## Drift prerequisite precedence

```text
docs/104 completion reconciliation
        ---> older traversal/content references to 13-Fault Drift Knot threshold
```

Current threshold is 10 reconciled Faults plus existing story/Line Skiff prerequisites.

---

# 12. Null Meridian precedence

Issue #11 exact authority:

```text
docs/127 six-sequence architecture
   + docs/128 one governing dungeon idea
   + docs/129 first-half adventure flow
   + docs/130 second-half escalation
   + docs/131 Take It Off the Bell
   + docs/134 scene-order precedence
        ---> older generic M16 paired-trials shorthand where conflicting
```

## Exact scene-order precedence

Older `docs/story/07_SCENE_BEAT_LEDGER.md` shorthand:

```text
Independent Signals
 -> Paired Mechanic Trials
 -> Quiet Court Archive
 -> Maelor
```

is superseded for exact adjacency.

Current flow:

```text
Entry
 -> S1/S2
 -> worker maintenance descent
 -> S3
 -> Quiet Court Archive
 -> Maelor deliberate correction
 -> S4
 -> S5
 -> Maelor personal workspace
 -> S6
 -> Maelor
 -> Listener
 -> final decommission
```

The scene ledger remains canonical for unaffected story facts.

## Systems-heavy S1/S2 sketches

Early proposed but unapproved concepts such as:
- complex structural phase-lag puzzle modeling;
- thermally remapped pressure-network topology;

are **not** authority.

Docs 128–129 lock the simpler player-facing forms:
- S1: forced-together walkways must be allowed to move separately;
- S2: unlike machines must be returned to their own valid operating conditions.

## S6 precedence

Doc 131 refines Decision #1's provisional `No Master Pulse` slot.

Current S6 is **Take It Off the Bell**:
- local service authority first;
- mandatory Common Measure for one temporary operation;
- physical master-relay disconnection;
- local continuation at different rhythms.

Older generic "multi-system capstone" descriptions are subordinate where they imply six regional switches, a new master frequency, or mandatory Local Accord.

---

# 13. Story countertone/checklist precedence

Current story authority explicitly rejects presenting Motion / Memory / Ending as an upfront collectible checklist.

```text
current story/reveal/progression authority
        ---> older shorthand that frames "three Countertones" as fetch items
```

Locked principle:
- each relation emerges through play/story need;
- the player follows practical evidence/leads;
- only after the relevant discoveries can the learned set be summarized as Motion / Memory / Ending;
- no `collect the three Countertones` quest structure.

Do not reintroduce the removed checklist through objectives, UI, achievement text, or implementation data naming visible to players.

---

# 14. Cleanup PR history precedence

Known repository cleanup history:

```text
later restored/accepted cleanup authority
        -X-> PR #78 / PR #80 effects that were reverted/superseded
        -X-> PR #79 (closed / not merged)
```

PR #81/#82 restored the intended workflow after the earlier cleanup attempts.

When investigating historical Git state, do not assume an old merged PR remains current if it was later reverted.

Current `main` content and explicit authority documents outrank historical merge status.

---

# 15. System IDE precedence

```text
docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md
        ---> ad-hoc one-off debug menus as system iteration architecture
```

System-specific IDE addenda refine doc 21.

A system-specific workbench may add controls/fixtures but may not create a second authoritative state model.

Runtime authority remains with gameplay services.

Issue #58 remains open until the shared shell is actually implemented/proven.

---

# 16. Blueprint / presentation precedence

Project architecture:

```text
authoritative C++ gameplay/state services
        ---> presentation-only Blueprint state when they conflict
```

Blueprints may:
- present state;
- assemble content;
- drive scoped presentation;
- host thin authored hooks where approved.

They may not silently become:
- canonical save owner;
- hidden quest state owner;
- duplicate combat state owner;
- duplicate Hush truth owner;
- per-chain Setup/Payoff authority;
- scene-order-only persistence logic.

---

# 17. Runtime evidence precedence

A document saying `LOCKED`, `COMPLETE`, or `CLOSED` at the design layer does not supersede runtime evidence requirements.

```text
actual UE5.8 deterministic/runtime/human evidence
        ---> assumptions based solely on design completion
```

But runtime evidence also does not automatically supersede locked design.

If runtime testing shows a design performs poorly:
- document the evidence;
- propose a scoped design revision;
- obtain required owner approval;
- then change authority.

Do not silently mutate canon in code because a prototype was inconvenient.

---

# 18. Current known stale-reference hazards

## Confirmed

1. `docs/82_SAVE_STATE_TAXONOMY_OWNERSHIP_ADDENDUM.md`
   - stale link: `docs/69_GATE3_TOOL_PUZZLE_CUMULATIVE_SPECIFICATION.md`
   - correct: `docs/69_GATE3_TOOL_SYSTEM_CUMULATIVE.md`

2. Older completion literals protected by docs 104/109:
   - 48 Fault;
   - 28 Pulse;
   - 30 Vault;
   - K02=30;
   - Drift=13;
   - prestige stage/global-item confusion;
   - Yard commission/global-item confusion.

3. Older Null Meridian M16 adjacency:
   - use doc 134.

4. Older Setup/Payoff S07/S10 interpretations:
   - use docs 115/117.

## Closure action

The program will continue scanning for:
- dead filenames;
- obsolete IDs;
- stale thresholds;
- old system names;
- invalid actor/map path assumptions;
- contradictory scene ordering;
- references to superseded implementation architecture.

New findings belong in later stale-reference/content-traceability outputs.

---

# 19. Precedence decision procedure

When two documents appear to conflict:

1. identify the **exact fact** in conflict;
2. find the most specific owner-approved authority for that fact;
3. check this graph for scoped precedence;
4. check a relevant cumulative specification/closure audit;
5. preserve unaffected content from the older file;
6. if the conflict is still unresolved, do not improvise;
7. add it to the Unanswered-Question Register with classification `F — owner decision required` or the appropriate category.

Never resolve precedence by:
- higher filename number alone;
- newer Git timestamp alone;
- whichever document is shorter;
- whichever choice is easiest to implement;
- whichever value resembles another game's design.
