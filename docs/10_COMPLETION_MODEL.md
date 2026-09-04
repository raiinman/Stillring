# 10 — Stillring 100% Completion Model

**Status:** design proposal  
**Related:** Issue #6, `docs/reference/OOT_100_PERCENT_ANATOMY.md`

## Goal

Stillring should support a satisfying, auditable **100% playthrough** without turning the world into an icon vacuum.

Completion content must do at least one of these jobs:

1. teach or retest a game verb;
2. reveal character/world information;
3. make an old place newly useful;
4. improve a capability the player already understands;
5. create a cross-region dependency;
6. visibly affect a community or ending-state montage;
7. provide a mastery challenge worth doing for its own sake.

If content does none of those things, it is probably filler.

---

# Completion philosophy

## Rule C1 — 100% is planned from the beginning

Every region gets its completion inventory during graybox planning. Do not finish the critical path and then scatter collectibles into empty corners.

## Rule C2 — Completion unlocks in waves

Every major verb opens a curated set of old-world opportunities. The player should periodically think:

> I know three places where this might work.

The game should not need to tell them with a dozen new map markers.

## Rule C3 — Visible promises beat invisible chores

Whenever practical, locked optional content should be foreshadowed before it becomes reachable: a strange seam behind bars, an unreachable maintenance hatch, a frozen testimony, a pressure door, an anomalous bell tone.

## Rule C4 — Rewards arrive throughout the game

A global collectible whose only meaningful reward is at 100% is poor pacing. Threshold rewards should improve the player's current journey.

## Rule C5 — No single save file should require external knowledge for basic completion tracking

A player pursuing 100% should be able to determine what categories remain from in-game records. Exact secret locations do not need to be revealed automatically, but category and regional counts should be visible after an appropriate discovery/upgrade.

## Rule C6 — Completion percentage is not the presentation

Internally we can calculate a percentage. The normal UI should present diegetic records: work orders completed, faults reconciled, field notes, refuge stamps, recovered testimonies, etc. A plain percentage may exist on the save-select/status screen for completionists.

---

# Proposed completion taxonomy

Names/counts below are **provisional production targets**, not story canon. Counts should move if playtesting shows bad density.

| Category | Proposed count | Mandatory subset | Primary purpose |
|---|---:|---:|---|
| Main progression movements | 16 | 16 | Complete story |
| Resonance Faults | 48 | 0 | Global verb-gated exploration collectible |
| Pulse Shards | 28 | 0 | Distributed survivability progression |
| Bellwright Refuges | 11 | 2–3 | Ability/capacity upgrades, healing, lore |
| Local Repair Contracts | 24 | 4–6 | NPC/world-state side quests |
| Cross-state Echo Setups | 12 | 3–4 | Pre/post-Stillness causality |
| Cantor Patterns | 9 | 4–5 | Reusable world/system verbs |
| Tool Mastery Upgrades | 14 | 0 | Optional capacity/quality improvements |
| Skill Trials / minigame mastery marks | 9 | 0 | Mechanical mastery |
| Micro-vaults / maintenance cavities | 30 | 0 | World density and verb-reading |
| Testimonies / field records | 32 | 0 | Optional lore with systemic payoff |
| Prestige side quest stages | 10–14 stages | 0 | World-spanning relational quest |
| Traversal hunt targets | 12 | 0 | Combine traversal + combat/perception |
| Optional elite encounters | 8 | 0 | Combat mastery and rare upgrades |
| Community disconnection projects | 6 | 0–2 | Late-game world/ending-state change |
| Mastery complex | 1 multi-room activity | 0 | Endgame synthesis challenge |

The final shipping counts should be selected from observed traversal time and region density, not from a desire to resemble another game's numbers.

---

# Category specifications

## 1. Resonance Faults — global collectible

### Fantasy

Small, persistent synchronization defects left where the centralized bell network forced local reality into alignment. Neris can hear/feel them before fully understanding them.

### Why this fits Stillring

They are directly about the game's central conflict: centralized synchronization versus local imperfection. Collecting/reconciling them can mean **making each fault safe without erasing its difference**, reinforcing the ending thematically.

### Access grammar

The 48-target draft should intentionally span multiple gates:

- base Cantor Key;
- Anchor Line;
- Glasslung Reed;
- Temper Gauntlet;
- Vane Cloak;
- Mirror Nail;
- seam mode;
- pre/post-Stillness state;
- environmental schedule/weather;
- multi-tool combinations.

No region should contain all of its Faults on the first visit.

### Staged rewards — provisional

Do not copy another game's exact threshold structure. Proposed cadence:

- **6:** fault-listening range improvement;
- **13:** field kit slot or equivalent utility expansion;
- **21:** map notebook gains regional unresolved-fault counts;
- **30:** Cantor Key recovery/cooldown quality upgrade;
- **39:** rare optional tool modifier or defensive utility;
- **48:** narrative completion reward + cosmetic/utility recognition, not an infinite-money joke.

Threshold numbers are deliberately irregular and may change.

### Completion UI

After the first Bellwright refuge teaches fault notation, the field journal shows:

`Rootmere faults: 4 reconciled / ? observed`

After the regional-count upgrade, it can show exact totals.

---

## 2. Pulse Shards — survivability track

**Working name only.** Avoid heart-shaped art or four-pieces-make-a-heart presentation.

### Proposed mechanical form

Pulse Shards are components used at refuges to reinforce Neris's field harness / resonance tolerance.

A possible curve:
- every **2 shards** grants one small resilience segment for the first few upgrades;
- later tiers may require **3 shards** or a refuge service component;
- cap survivability so mastery still matters.

This deliberately avoids copying a four-pieces-equals-heart structure.

### Distribution

Pulse Shards should come from:
- exploration;
- local quest chains;
- skill trials;
- micro-vaults;
- elite encounters;
- cross-state payoffs.

Do not make every reward chest-shaped.

---

## 3. Bellwright Refuges

Small infrastructure sanctuaries maintained by independent/local bellwright traditions.

### Functions

- repair/heal;
- capacity upgrades;
- teach optional Cantor patterns;
- offer world-history fragments from outside the Quiet Court narrative;
- become fast-travel or route-support nodes only if doing so helps pacing;
- change after Stillness based on whether local communities maintained them.

### Mandatory rule

At most a few should be mandatory. Most are discovery rewards.

### Presentation rule

They must not be cave rooms containing a giant magical benefactor. Each refuge should feel like an authored workshop, emergency station, buried relay room, cliff maintenance shelter, or community bell-house.

---

## 4. Local Repair Contracts

### Purpose

These are the backbone of character-driven optional content. A repair contract is not automatically 'fetch three materials.' Each should be written around a person/community problem that a bellwright can affect.

### Contract archetypes

- diagnose a fault from physical symptoms;
- choose between technically ideal and socially workable repairs;
- trace a bad repair through several owners;
- reopen a service route;
- mediate incompatible local systems;
- recover a worker/testimony;
- repair an object whose emotional meaning matters more than its network value;
- undo a Quiet Court standardization that harmed a local practice.

### Completion quality tiers

Do **not** grade morality with red/green points. A contract may record consequential choices, but 100% means the contract reached a resolved state, not that the player chose the designer's preferred answer.

---

## 5. Cross-state Echo Setups

Twelve authored chains are proposed, roughly 1–2 per major region.

### Required structure

`setup before/early state -> remembered clue -> post-Stillness/Hush consequence -> payoff`

At least half should be optional.

### Good rewards

- new route;
- surviving NPC or preserved testimony;
- rare repair component;
- alternate resolution to a local contract;
- world-state visual change;
- field journal insight;
- unique tool modifier.

### Bad rewards

- 20 currency for remembering to press a button ten hours ago.

---

## 6. Cantor Patterns

Patterns are reusable operational sequences for the Cantor Key, not melodies copied from a musical-instrument adventure.

### Proposed design domains

Patterns can affect:
- resonance stabilization;
- wake/sleep state of old machinery;
- local pressure release;
- echo-memory playback;
- material oscillation;
- weather-sensitive chimes/air routes;
- locating certain faults;
- Hush seam behavior;
- community bell synchronization/de-synchronization.

### Requirement

Every pattern must have at least **three authored uses** outside the scene where it is acquired.

A pattern that only opens one story door is a keycard wearing lore.

---

## 7. Tool Mastery Upgrades

Major verbs are acquired through the critical path; optional play improves them.

Examples of upgrade dimensions:

### Anchor Line
- faster recovery;
- second anchor point for authored two-point rigs;
- increased valid-object mass class.

### Glasslung Reed
- pressure tolerance;
- recovery efficiency;
- secondary pulse function.

### Temper Gauntlet
- heat buffer;
- longer state hold;
- controlled quench radius.

### Vane Cloak
- stability window;
- lateral correction;
- one advanced updraft interaction.

### Mirror Nail
- longer pinned echo;
- second compatible state class;
- fault-visibility interaction.

### Cantor Key
- pattern memory capacity only if capacity matters meaningfully;
- recovery/tuning precision;
- diagnostic range.

Upgrades should change feel or possibility, not merely display +5%.

---

## 8. Skill Trials / minigames

Nine mastery marks are enough to create variety without a carnival of disconnected interfaces.

Candidate activities:
- Anchor Line load-balancing course;
- pressure-routing race;
- kiln timing/shape challenge;
- Vane route trial;
- acoustic fault diagnosis under time pressure;
- repair bench assembly challenge using known interaction rules;
- traversal vehicle/rig obstacle route;
- combat target-selection drill;
- Hush seam navigation trial.

### Reward rule

First meaningful completion grants a capability/capacity/lore reward. Repeated high scores can grant cosmetics, records, or currency without becoming mandatory for 100% unless a clear top-tier threshold is specified.

---

## 9. Micro-vaults / maintenance cavities

Thirty provisional micro-spaces provide exploration density.

### Opening grammar

Use a small readable vocabulary:
- fractured resonance plate;
- tension hatch;
- pressure lock;
- heat-warped housing;
- updraft vent;
- echo-only entrance;
- seam-overlap cavity;
- ordinary hidden route found by observation.

### Interior templates

A micro-vault should generally contain one strong idea in 1–5 minutes:
- quick traversal problem;
- one enemy composition;
- tiny state puzzle;
- lore scene;
- resource cache;
- Fault/Pulse Shard;
- shortcut.

Do not generate thirty near-identical caves.

---

## 10. Testimonies / field records

Optional narrative collection should not be a pile of encyclopedia entries.

### Sources

- worker notes;
- maintenance stamps;
- unauthorized recordings;
- local oral-history transcriptions;
- Quiet Court directives;
- Ilyra/Maelor research remnants;
- Hush memories that contradict physical documents.

### Systemic payoff

Some testimony sets can:
- reveal a secret's clue;
- alter Neris's diagnosis language;
- unlock an alternate contract solution;
- contextualize the final political outcome;
- provide exact regional fault counts after a research milestone.

100% lore collection should create understanding, not merely fill a menu.

---

## 11. Prestige side quest — working concept: The Unstandard Tool

This is Stillring's world-spanning relational quest, inspired only by the **structural role** of long trade sequences.

### Premise

A legendary independent bellwright tool was never one object. Its design survives as incompatible components, shop practices, oral measurements, and grudges spread across Orra because the Quiet Court suppressed non-standard repair methods.

Neris gradually reconstructs a new tool/weapon stance from living specialists rather than passing arbitrary items from NPC to NPC.

### Stage grammar

1. discover a broken non-standard component;
2. find who can identify its origin;
3. earn access to a specialist through a local problem;
4. transport a temperature/pressure-sensitive part using learned traversal;
5. choose a material treatment in Emberstep;
6. recover a lost measurement from a Hush testimony;
7. reconcile two incompatible craft traditions;
8. perform a timed field calibration because the component drifts once removed from its jig;
9. defeat or bypass an elite encounter guarding old workshop stock;
10. complete the tool with a final specialist who refuses Quiet Court certification.

### Reward

A distinct optional combat/repair stance or secondary implement with tradeoffs—not simply a stronger version of Neris's default weapon.

### Anti-copy rule

No sequence of named trade items should mirror another game's chain. The stages must arise from Stillring's craft, physics, relationships, and travel systems.

---

## 12. Traversal hunt

Twelve moving/escaping anomalies are proposed after the player's major traversal transformation.

### Design purpose

Combine:
- route knowledge;
- vehicle/rig/mobility skill;
- ranged or Anchor/diagnostic interaction;
- time-of-day/weather/Hush conditions in a subset of hunts.

The target should be an Orra-native resonance phenomenon, machine, or echo—not ghosts shot from horseback.

### Reward

A field-kit expansion or unique diagnostic capability after all targets, with meaningful intermediate rewards.

---

## 13. Optional elite encounters

Eight bespoke or semi-bespoke encounters should test combinations the critical path does not demand.

Examples:
- heavy enemy plus mobile pressure attacker requiring target-priority discipline;
- echo-state opponent that must be committed with Mirror Nail before core combat works;
- aerial enemy group where Vane positioning and attack-turn readability matter;
- heated armored machine where Temper creates windows rather than dealing direct damage.

Rewards should include rare mastery upgrades, tool modifiers, or prestige quest components.

---

## 14. Community disconnection projects

After Cairnfall, each major region can choose/execute a local method of leaving the centralized synchronization system.

### Six proposed projects

One per major region, each using that region's physical/social language.

Possible consequences:
- visible post-project environment change;
- new local travel service;
- shop/refuge behavior change;
- different NPC presence before finale;
- unique ending-montage shot;
- modest gameplay convenience reward.

### Completion rule

The main ending remains the same. Side completion changes how prepared each community is and what the credits show, not whether Neris is 'allowed' to reject Maelor.

---

## 15. Mastery complex

A late optional multi-room activity tests the full combat/traversal toolkit without pretending to be a lore-critical dungeon.

### Rooms should test combinations

- target prioritization;
- environmental combat;
- traversal under pressure;
- tool switching;
- Hush-state reading;
- resource discipline only if resource systems remain fun in testing.

### Reward

A mechanically unusual optional tool modifier, cosmetic recognition, or alternate stance. Avoid introducing a mandatory verb this late.

---

# Region completion template

Every major region must ship with this ledger completed.

```text
REGION:
Critical-path movements:
Major dungeon / domain:
Major verb taught:

REVISIT WAVES
- base kit:
- Anchor Line:
- Glasslung Reed:
- Temper Gauntlet:
- post-Stillness:
- Vane Cloak:
- Mirror Nail:
- seam mode:

OPTIONAL INVENTORY
- Resonance Faults:
- Pulse Shards:
- Bellwright Refuges:
- Repair Contracts:
- Cross-state setups:
- Cantor Patterns:
- Tool upgrades:
- Skill Trial:
- Micro-vaults:
- Testimonies:
- Elite encounter:
- Community project:

STATE CHECKS
- first visit state:
- post-major-dungeon state:
- post-Stillness state:
- post-disconnection state:
- pre-finale state:
- postgame/ending representation:
```

No region reaches production-complete status with blank revisit waves.

---

# 100% definition

A save is **100% complete** when all shipping categories explicitly marked as completion-bearing have been resolved. At current proposal level that means:

- main story completed;
- all Resonance Faults reconciled;
- all Pulse Shards recovered/processed;
- all Bellwright Refuges discovered and their unique services resolved;
- all Local Repair Contracts resolved;
- all Cross-state Echo Setups paid off;
- all Cantor Patterns learned;
- all Tool Mastery Upgrades earned;
- all mastery marks earned at the defined completion threshold;
- all Micro-vaults discovered/resolved;
- all Testimonies/field records recovered;
- prestige side quest completed;
- all traversal-hunt targets resolved;
- all optional elite encounters cleared;
- all community disconnection projects completed;
- mastery complex completion reward earned.

Repeatable high scores, currency totals, random drops, cosmetics with no authored acquisition record, and post-completion grinding do **not** count toward 100%.

---

# Save-data requirements

Issue #4 should account for completion from the beginning.

Every completion-bearing authored object needs a stable semantic ID, for example:

```text
fault.rootmere.low_ferry_01
pulse.cairnspire.old_service_roof
contract.saltreach.pumpwright_sela
vault.emberstep.quench_culvert
record.mireglass.worker_testimony_07
trial.high_aerie.crosswind_mastery
community.cairnfall.local_disconnect
```

Do not use node paths, scene-tree instance IDs, or display names as canonical save keys.

### Suggested completion record

```json
{
  "schema_version": 1,
  "completion": {
    "resolved_ids": [],
    "observed_ids": [],
    "category_totals": {},
    "region_totals": {}
  }
}
```

Actual schema belongs to Issue #4 and may differ.

---

# Map and hint policy

## Default

- no automatic icon explosion;
- discovered services can be marked;
- player can place a limited/unlimited personal note marker depending UI prototype;
- observed-but-unsolved faults can enter the journal;
- regional completion counts unlock through play/research.

## Accessibility / anti-frustration option

After the finale or after a late optional diagnostic upgrade, allow a **completion assist** that narrows unresolved content to subregions or emits a diagnostic pulse near eligible secrets.

This respects players who want a blind exploratory first run and players who want to finish 100% without opening a browser for twelve hours.

---

# Reward economy rules

1. Core verbs: critical-path discovery/repair/story.
2. Capacity/quality upgrades: optional mastery and exploration.
3. Health/resilience: distributed across multiple content types.
4. Currency: maintenance, consumables, convenience, some services.
5. Lore: often paired with another practical or clue reward.
6. Cosmetics: suitable for repeat mastery and late completion.
7. 100% reward: recognition and a useful/fun postgame affordance, **not** a required ending or a reward that would only have mattered twenty hours earlier.

---

# Vertical-slice completion test

The vertical slice should prove the completion model at miniature scale.

Include:
- 3 Resonance Faults, with only 2 reachable on first pass;
- 2 Pulse Shards from different content types;
- 1 Bellwright refuge;
- 2 local repair contracts;
- 1 pre/post-state setup-payoff simulation;
- 1 optional Cantor pattern or secondary use;
- 1 tool mastery reward;
- 2 micro-vaults with different opening grammar;
- 2 testimonies, one of which provides a practical clue;
- 1 mastery challenge;
- a journal page showing observed/resolved counts.

The slice passes only if testers naturally notice at least one 'I should come back here later' promise **without** being told by a developer.

---

# Anti-filler review

Before accepting any optional content issue, answer:

1. What game verb does this use or teach?
2. Why is this content in this specific place?
3. What does the player learn about a person/place/system?
4. What reward track does it feed?
5. Does it reopen old knowledge or create future anticipation?
6. Could this content be moved to another region without changing anything?

If #6 is yes and the other answers are weak, redesign or cut it.

**A smaller world full of authored relationships beats a large world full of glowing chores.**