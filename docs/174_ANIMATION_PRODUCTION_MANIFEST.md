# 174 — Animation Production Manifest

**Status:** ACTIVE / STUDIO-HANDOFF PRODUCTION INVENTORY / DOCUMENTATION-ONLY  
**Updated:** 2026-09-06  
**Parent:** `docs/173_STILLRING_ANIMATION_BIBLE.md`  
**Art inputs:** `docs/158_CHARACTER_PRODUCTION_MANIFEST.md`, `docs/159_ENEMY_BOSS_ART_MANIFEST.md`, `docs/160_REGION_ENVIRONMENT_PROP_MANIFEST.md`  
**Gameplay inputs:** `docs/20`, `docs/48`, `docs/69`, `docs/79`, docs `120`–`126`, docs `127`–`134`  
**Decision rights:** `docs/170_STUDIO_DECISION_RIGHTS_MATRIX.md`  
**Closes toward:** `SH-ANI-001` through `SH-ANI-009`  
**Boundary:** this manifest inventories required animation families and production burden. It does not claim final clip counts, final rigs, final root-motion values, final facial technology, final performance budgets, implementation, or human-play acceptance.

---

# 1. Purpose

This manifest answers:

> **What animation work must actually be produced for Stillring?**

A studio should not receive a design document saying “Neris can mantle, fight, use tools, ride the Skiff, talk to people and appear in cinematics” and then be expected to infer the animation package.

This document therefore inventories motion by **semantic family**.

It deliberately distinguishes:
- required unique authored motion;
- shared/reusable motion foundations;
- procedural/IK support;
- additive/state layers;
- cinematic bespoke burden;
- runtime-gated source-clip multiplicity.

---

# 2. How to count this manifest

A **family row** is a production requirement, not necessarily one Animation Sequence.

For example:
- `Neris / target-lock locomotion` is one required family but may be realized by several directional clips, pose warping, a blend space, motion matching, or a hybrid;
- `Mawhart / liberation resolution` is a required bespoke sequence family even if multiple clips are later needed for camera/arena continuity;
- `Cairnspire / archive work` is one reusable NPC occupation family that may contain several loop/transition variants.

The studio must estimate source clips after selecting representative rig/animation techniques.

The family itself may not be deleted merely because a technique reduces clip count.

---

# 3. Animation production classes

| Class | Purpose | Typical reuse |
|---|---|---|
| `A0` | Neris/player gameplay-critical | unique hero coverage |
| `A1` | principal character performance | unique/character-specific layers on shared foundations |
| `A2` | shared humanoid foundation | reuse/retarget with cleanup by context |
| `A3` | regional occupation/population | reuse within region/occupation; controlled cross-region sharing |
| `A4` | ordinary enemy/fauna family | reuse within compatible morphology/family |
| `A5` | boss/major-pressure bespoke | unique or heavily specialized |
| `A6` | machine/mechanism animation | reuse only where mechanism ancestry genuinely matches |
| `A7` | Hush relational animation | bespoke semantic relationship; may be skeletal/environmental/procedural |
| `A8` | cinematic bespoke | scene-specific performance where gameplay/shared coverage is insufficient |
| `A9` | additive/procedural support | reusable technical layer, never state authority |

---

# 4. Neris — A0 core locomotion inventory

The following are **required semantic families**.

## 4.1 Ground / free exploration

| ID | Required family | Coverage requirement | Reuse / implementation boundary |
|---|---|---|---|
| `ANI-NER-LCO-001` | neutral standing | stable idle; subtle work/travel body; no constant hero fidget | may share breathing/additives with other states |
| `ANI-NER-LCO-002` | careful low-speed movement | controlled low-speed step cadence; responsive analog direction | exact clip count runtime-gated |
| `ANI-NER-LCO-003` | ordinary run | readable main exploration travel | gameplay displacement owns speed |
| `ANI-NER-LCO-004` | Sprint | stronger sustained travel posture distinct from evade/panic | no stamina/exhaustion loop implying a resource tax |
| `ANI-NER-LCO-005` | starts | low-speed/run/Sprint start response | Distance Matching candidate; exact variants runtime-gated |
| `ANI-NER-LCO-006` | stops | ordinary and brisk stops | gameplay stop distance remains authority |
| `ANI-NER-LCO-007` | direction change/pivot | ordinary directional pivots | orientation warping/variants allowed |
| `ANI-NER-LCO-008` | hard reversal plant | visible plant/shedding of momentum | cannot delay input beyond locomotion authority |
| `ANI-NER-LCO-009` | slope/stair support | ordinary terrain adaptation | primarily A9 procedural support; no special state unless gameplay says so |

## 4.2 Jump / fall / landing

| ID | Required family | Coverage requirement |
|---|---|---|
| `ANI-NER-AIR-001` | jump takeoff | immediate accepted jump; momentum-consistent |
| `ANI-NER-AIR-002` | rising/airborne | readable airborne state without hover language |
| `ANI-NER-AIR-003` | apex/fall transition | support predictable arc read |
| `ANI-NER-AIR-004` | falling | ordinary fall body response; no free-dive language |
| `ANI-NER-LAND-001` | safe landing | fluent return to requested locomotion |
| `ANI-NER-LAND-002` | firm upper-safe landing | stronger contact without damage implication beyond gameplay state |
| `ANI-NER-LAND-003` | moderate damaging landing/recovery | proportionate recovery |
| `ANI-NER-LAND-004` | severe landing/recovery | near-collapse/major consequence |
| `ANI-NER-LAND-005` | lethal handoff | death presentation compatible with Combat/Death authority |

## 4.3 Slope-special states

| ID | Required family | Coverage requirement |
|---|---|---|
| `ANI-NER-SLP-001` | borderline uphill scramble | brief traction-driven uphill effort |
| `ANI-NER-SLP-002` | blocked/failed scramble | clean stop/lose-progress response without ratcheting |
| `ANI-NER-SLP-003` | committed downhill slide | readable downhill commitment + limited correction |
| `ANI-NER-SLP-004` | slide exit | return to grounded locomotion without hidden speed reset |

---

# 5. Neris — A0 ledge / ladder / water inventory

## 5.1 Mantle / ledge

| ID | Required family | Coverage requirement |
|---|---|---|
| `ANI-NER-MAN-001` | low fluent mantle | knee→waist obstacle family |
| `ANI-NER-MAN-002` | deliberate higher mantle | waist→lower-chest family; clear direct effort |
| `ANI-NER-LED-001` | ledge catch/contact | **must visibly enter real hang** |
| `ANI-NER-LED-002` | stable hang | neutral hold |
| `ANI-NER-LED-003` | same-handhold shimmy left/right | continuous handhold only |
| `ANI-NER-LED-004` | pull-up | only after gameplay validates standable top |
| `ANI-NER-LED-005` | blocked pull-up continuation | remains hanging; readable failed top availability |
| `ANI-NER-LED-006` | deliberate Drop/Release | prompt release; no immediate visual regrab |
| `ANI-NER-LED-007` | fall-from-hang handoff | joins ordinary fall family |

**Explicit non-inventory:** no baseline corner-wrap, ledge gap-transfer, lateral ledge jump or vertical handhold climb animation family.

## 5.2 Ladder

| ID | Required family |
|---|---|
| `ANI-NER-LAD-001` approach/attach |
| `ANI-NER-LAD-002` climb up |
| `ANI-NER-LAD-003` climb down |
| `ANI-NER-LAD-004` neutral hold |
| `ANI-NER-LAD-005` top exit |
| `ANI-NER-LAD-006` bottom exit |
| `ANI-NER-LAD-007` deliberate Drop/Release |
| `ANI-NER-LAD-008` fall/recovery handoff |

Exact rung cadence/contact solution is runtime-gated to final tested ladder metrics.

## 5.3 Surface swimming

| ID | Required family |
|---|---|
| `ANI-NER-SWM-001` deep-water entry |
| `ANI-NER-SWM-002` surface travel |
| `ANI-NER-SWM-003` neutral tread |
| `ANI-NER-SWM-004` directional turn/steer |
| `ANI-NER-SWM-005` low valid water exit |
| `ANI-NER-SWM-006` blocked/high-edge continuation |
| `ANI-NER-SWM-007` water hit/reaction/death where gameplay requires |

**Explicit non-inventory:** no baseline underwater free-dive locomotion family.

---

# 6. Neris — target-lock locomotion inventory

Target-lock must receive explicit motion coverage rather than reusing free-run presentation blindly.

| ID | Required family | Notes |
|---|---|---|
| `ANI-NER-TGT-001` | target-lock neutral | combat-ready but not constant attack pose |
| `ANI-NER-TGT-002` | target-relative forward/back | readable distance intention |
| `ANI-NER-TGT-003` | target-relative lateral | stable feet/body target relationship |
| `ANI-NER-TGT-004` | target-relative diagonals | may derive through blending/warping if clean |
| `ANI-NER-TGT-005` | enter target-lock from travel | short natural decel/pivot |
| `ANI-NER-TGT-006` | exit/loss target-lock | no abrupt body snap |
| `ANI-NER-TGT-007` | target-lock jump/air support | preserves target-relative air frame |
| `ANI-NER-TGT-008` | target-switch body response | bounded; camera/target system remains owner |

Exact directional source count is runtime-gated.

---

# 7. Neris — A0 combat inventory

## 7.1 Attacks

| ID | Required family | Unique burden |
|---|---|---|
| `ANI-NER-CMB-L01` | Light 1 | unique authored strike line |
| `ANI-NER-CMB-L02` | Light 2 | unique continuation/standalone accepted-entry presentation |
| `ANI-NER-CMB-L03` | Light 3 | unique chain conclusion; **no Light 4** |
| `ANI-NER-CMB-H01` | Heavy | unique commitment family distinct from Light chain |
| `ANI-NER-CMB-MISS` | miss/recovery support | required where Heavy/other committed actions need readable miss consequence |

## 7.2 Defense

| ID | Required family |
|---|---|
| `ANI-NER-GRD-001` guard enter/hold |
| `ANI-NER-GRD-002` guarded locomotion support |
| `ANI-NER-GRD-003` ordinary Guard Reaction |
| `ANI-NER-GRD-004` Perfect Guard contact/advantage response |
| `ANI-NER-GRD-005` guard release/return |
| `ANI-NER-EVD-001` Evade action family |
| `ANI-NER-EVD-002` Evade collision/blocked presentation support if gameplay requires distinct feedback |
| `ANI-NER-EVD-003` Evade recovery |

Exact Evade physical form and directional multiplicity are runtime/human-play gated.

## 7.3 Hit / reaction / death

| ID | Required family | Notes |
|---|---|---|
| `ANI-NER-HIT-001` | DamageOnly cosmetic response | may be additive/subtle; must not interrupt authority |
| `ANI-NER-HIT-002` | LightReact | directional variants as needed |
| `ANI-NER-HIT-003` | Interrupt | stronger clear action break |
| `ANI-NER-HIT-004` | HardStagger | strong controlled loss of posture |
| `ANI-NER-HIT-005` | GuardReaction | maps to authoritative guard result |
| `ANI-NER-HIT-006` | knock/fall recovery if retained by encounter authority | only where a real gameplay state exists |
| `ANI-NER-DTH-001` | combat death family | exact variant count later; terminal cleanup remains gameplay-owned |

Hit-direction variant count should be the smallest set that preserves force readability at gameplay distance.

---

# 8. Neris — Cantor / tool animation inventory

## 8.1 Cantor Key

| ID | Required family |
|---|---|
| `ANI-NER-CAN-001` draw from right-rear swivel cradle |
| `ANI-NER-CAN-002` ready/listen posture |
| `ANI-NER-CAN-003` view-directed diagnostic adjustment |
| `ANI-NER-CAN-004` hammer/prong sample action |
| `ANI-NER-CAN-005` slider/tuning manipulation |
| `ANI-NER-CAN-006` procedure application base handling |
| `ANI-NER-CAN-007` re-measure/confirm relationship |
| `ANI-NER-CAN-008` not-actionable/blocked physical response |
| `ANI-NER-CAN-009` stow to swivel cradle |
| `ANI-NER-CAN-010` interruption/cancel handoff |

No universal “magic cast” animation may replace these functional actions.

## 8.2 Anchor Line

| ID | Required family |
|---|---|
| `ANI-NER-ANC-001` equip/ready |
| `ANI-NER-ANC-002` target/latch action |
| `ANI-NER-ANC-003` tension/reel pull |
| `ANI-NER-ANC-004` static brace establish |
| `ANI-NER-ANC-005` brace hold/strain |
| `ANI-NER-ANC-006` reclaim/release |
| `ANI-NER-ANC-007` traversal pull start |
| `ANI-NER-ANC-008` traversal body travel/brace |
| `ANI-NER-ANC-009` traversal arrival/landing |
| `ANI-NER-ANC-010` combat component pull |
| `ANI-NER-ANC-011` mechanism/puzzle load manipulation |
| `ANI-NER-ANC-012` blocked/failed tension |
| `ANI-NER-ANC-013` interruption by hit/cancel |

## 8.3 Glasslung Reed

Required families:
- draw/open protected case;
- source/intake handling;
- pressure/flow control posture;
- sustained operation;
- blocked/invalid response;
- release/close/stow;
- traversal/combat/puzzle-specific body variants where authoritative use requires different force/contact.

## 8.4 Temper Gauntlet

Required families:
- equip/activate gauntlet state;
- inspect/contact material;
- controlled thermal application;
- sustained brace/hold;
- release/cooldown presentation;
- blocked/unsafe response;
- combat-pressure use where authored;
- puzzle/mechanism contact;
- return to ordinary hand state.

## 8.5 Vane Cloak

Required families:
- deploy/ready;
- authored airflow capture;
- controlled traversal body state;
- steering/correction within tool authority;
- landing/release;
- blocked/collapse/failure recovery;
- ladder/ledge/tool stow compatibility;
- wind/environment additive response.

No free-flight family may be created without separate gameplay authority.

## 8.6 Mirror Nail

Required families:
- draw/prepare;
- place/commit local echo target;
- inspect/confirm state;
- maintain/revisit local commitment where visible;
- reclaim/end if authored;
- invalid-target response;
- Hush-specific interaction presentation without generic “reality casting.”

## 8.7 Line Skiff / Roadhand Pulse

See Section 10.

---

# 9. Neris — ordinary interaction inventory

Shared interaction foundations must cover at minimum:

| ID | Family |
|---|---|
| `ANI-NER-INT-001` low hand-operated control |
| `ANI-NER-INT-002` waist/chest control/lever |
| `ANI-NER-INT-003` two-hand heavy control |
| `ANI-NER-INT-004` push/pull short mechanism contact |
| `ANI-NER-INT-005` pick up small object |
| `ANI-NER-INT-006` receive/give small object |
| `ANI-NER-INT-007` inspect/read held object |
| `ANI-NER-INT-008` seated/rest interaction where authored |
| `ANI-NER-INT-009` door/gate/service latch family |
| `ANI-NER-INT-010` workbench/tool adjustment |
| `ANI-NER-INT-011` contextual planted interaction start/stop |

These are foundations, not permission to force all hero interactions onto identical hand heights/props.

Hero mechanisms/cinematics receive bespoke cleanup where needed.

---

# 10. Line Skiff animation inventory

The Skiff is a route-network traversal vehicle.

## 10.1 Neris rider

| ID | Required family |
|---|---|
| `ANI-NER-SKF-001` board/couple |
| `ANI-NER-SKF-002` neutral rider stance |
| `ANI-NER-SKF-003` acceleration lean/settle |
| `ANI-NER-SKF-004` coast posture |
| `ANI-NER-SKF-005` brake/bracing |
| `ANI-NER-SKF-006` lateral corridor weight shift |
| `ANI-NER-SKF-007` standard junction intent response |
| `ANI-NER-SKF-008` Roadhand Pulse while riding |
| `ANI-NER-SKF-009` dormant-route stop/recovery |
| `ANI-NER-SKF-010` park/disembark |
| `ANI-NER-SKF-011` Switchshoe transfer body response |
| `ANI-NER-SKF-012` rough-contact/stumble recovery if gameplay allows continued ride |
| `ANI-NER-SKF-013` forced safe dismount/failure family if authored |
| `ANI-NER-SKF-014` Hush paired-route seam continuity support |

## 10.2 Tessa

Tessa requires a **character-specific experienced route-worker/courier rider set** sufficient to visually demonstrate the fantasy before Neris masters it.

At minimum:
- confident arrival/ride posture;
- braking/parking;
- dismount;
- practical Skiff handling/body economy;
- conversation/route-work handoff around the machine.

Do not simply play Neris’s beginner rider set on Tessa.

## 10.3 Vehicle/mechanism

Skiff mechanical animation must cover:
- wake/couple;
- drive/rolling/hovering mechanism according to final design without inventing generic hovercraft behavior;
- acceleration/braking mechanical response;
- junction/guide response;
- Roadhand wake response;
- Switchshoe transfer hardware response;
- park/idle;
- disabled/unavailable-route state;
- Hush paired-route expression where authored.

Exact mechanism solution follows final Skiff art/technical design.

---

# 11. Neris — Hush / state-transition animation inventory

| ID | Required family | Rule |
|---|---|---|
| `ANI-NER-HSH-001` | legal seam request/commit presentation | must preserve gameplay state continuity |
| `ANI-NER-HSH-002` | seam rejected/blocked | side-effect-free failure; no false teleport start |
| `ANI-NER-HSH-003` | ordinary locomotion continuity across seam | destination pose rebind without movement restart |
| `ANI-NER-HSH-004` | combat continuity across seam | no action/immunity restart |
| `ANI-NER-HSH-005` | tool continuity across seam | only for tools whose semantic state persists |
| `ANI-NER-HSH-006` | Skiff continuity across legal paired-route seam | rider/vehicle state continues |

Do not create one universal “Neris Hush locomotion set” unless later semantic authority gives her body a truly different movement relationship.

---

# 12. Neris — additive/state-support inventory

Reusable A9 layers should include only those justified by source state:

- breathing baseline;
- exertion tier(s) driven by actual action context, **not stamina meter**;
- injury presentation tiers if Health/Combat authorizes persistent visual injury state;
- wet response where region/weather state requires;
- ash/dust response;
- wind bracing/cloth support;
- tool tension/bracing;
- head/eye attention;
- conversation listening/response;
- fatigue/strain for authored cinematics/late encounter state.

Exact layer count remains production planning.

---

# 13. Principal cast — A1 performance burden

## 13.1 Neris

Beyond gameplay inventory:
- F0 facial system;
- dialogue listening/speaking;
- silent technical concentration;
- irritation/dry humor;
- disbelief;
- grief;
- anger;
- long listening/processing;
- family-specific interaction with Ilyra/Orin;
- physically exhausted but non-heroic recovery;
- finale/decommission performance;
- epilogue/credits state.

These are **performance states**, not one canned emotion clip each.

## 13.2 Tessa Marr — C1 / F0

Requires:
- own locomotion posture overlay;
- courier/route-worker work loops;
- experienced Skiff handling;
- practical gear handling;
- F0 dialogue/performance;
- crisis/changed-world variants;
- recurring reunion/departure staging;
- finale/epilogue burden where canonical scenes require.

## 13.3 Ilyra Vale — C1 / F0

Requires:
- field-engineer/tool/measurement hand language;
- family interaction with Neris/Orin;
- focused diagnostic work;
- dialogue/listening performance;
- state-specific story/cinematic burden;
- Hush/memory representation only as canonical story requires.

## 13.4 Orin Vale — C1 / F0

Requires:
- broad repair-worker body mechanics;
- workshop/tool handling;
- family interaction;
- familiar one-sided half-smile/body-response language;
- ordinary dialogue;
- Echo-bound encounter repetition states;
- preserved gesture loop variants;
- human release/recognition performance;
- no monster/boss locomotion package.

## 13.5 Maelor Renn — C1 / F0 / A5 finale burden

Requires:
- controlled technical posture;
- precise Cantor/acoustician/mechanism handling;
- restrained dialogue/listening;
- ordinary recurring-character locomotion;
- combat Phase 1 human technical action set;
- combat Phase 2 infrastructure-coupled action set;
- increasing fatigue/strain additives;
- hit/reaction/defeat/disconnection;
- finale performance/cinematics;
- **no transformation/monster locomotion family**.

## 13.6 Caldrin — C2 / F1

Requires:
- archive/record handling;
- older sturdy-body locomotion variance;
- teaching/explanation gestures;
- dialogue/listening;
- High Aerie archive/state recurrence.

## 13.7 Sena Ash — C2 / F1

Requires:
- powerful work-body mechanics;
- Emberstep material/kiln/tool handling;
- dialogue/listening;
- crisis/changed-world operation variants;
- major regional-scene burden.

## 13.8 Prefect Aven Rusk — C2 / F1

Requires:
- institutional upright posture;
- civic/record/meeting interaction;
- dialogue/listening;
- controlled gesture language distinct from Maelor;
- state changes that remain human rather than “bureaucrat villain” caricature.

---

# 14. C3 / C3+ named recurring-character minimum

Every named C3 from `docs/160` requires:

1. shared compatible humanoid locomotion foundation;
2. body/build-appropriate retarget cleanup;
3. one occupation-readable signature loop or interaction family;
4. one dialogue/listening gesture family;
5. one state-specific reaction/operation family where story recurrence changes their ordinary work;
6. prop contact package where signature occupation requires it;
7. facial tier assignment (normally F1/F2 depending narrative burden).

Every `C3+` additionally requires:
- bespoke recognizable posture/gesture trait;
- at least one state-continuity performance across ordinary → changed-world/Unringing or another major recurrence;
- closer camera/contact cleanup where the character owns a major contract or emotional beat.

## 14.1 Named regional recurring inventory reference

### Brindle / First Circuit
Mara Pell, Dori Senn, Jo Ren, Eli Ren, Hara Quill, Kest Lorn, Eda Vell (C3+), Rinn Valeo.

### Cairnspire
Pellon Vey (C3+), Jeren Coil (C3+), Nia Tern (C3+), Lessa Har, Siv Orrel (C3+).

### Rootmere
Amsa Wren (C3+), Olo Wren, Lio Fen (C3+), Nemi Tal (C3+), Bram Ko, Tavin Ro (C3+), Sera Pell.

### Saltreach
Vessa Mor (C3+), Pell Aro (C3+), Tali Marao, Captain Rell Dava (C3+), Captain Imi Sorn (C3+), Dalen Or, Sori Keff (C3+).

### Emberstep
Varo Neel (C3+), Ressa Pai (C3+), Ko Marn (C3+), Alsa Rue (C3+), Daro Fen, Mera Sol (C3+).

### High Aerie
Sal Em (C3+), Pera Dinn (C3+), Prior Selen Voss (C3+), Ila Dinn, Jaro Pell, Mevi Pell (C3+).

### Mireglass
Senae Pell (C3+), Iven Marr (C3+), Sol Marr (C3+), Oren Tal (C3+), Neve Or (C3+), Daro Keel, Jessa Moor, Tovin Marr (C3+).

### Cairnfall
Hett Vara (C3+), Pell Dain (C3+), Riva Sol (C3+), Marek Tann (C3+), Aro Venn (C3+), Mar Dain, Leto Marr.

The list is a production reference, not a replacement for `docs/160` narrative/art specifics.

---

# 15. A2 shared humanoid foundation inventory

The shared humanoid library should provide a reusable basis for compatible C1–C4 characters.

## Locomotion foundations
- idle;
- walk;
- faster walk/run as NPC context requires;
- starts/stops;
- turns;
- stairs/slope support;
- sit/stand;
- basic enter/exit door/seat/workstation interactions.

## Conversation foundations
- neutral listen;
- speak neutral;
- explain/show;
- disagree;
- acknowledge;
- concerned attention;
- call/wave;
- give/receive object;
- point/indicate nearby object;
- seated conversation.

## Ordinary-life foundations
- carry small object;
- carry two-hand load;
- set down/pick up;
- sweep/clean;
- simple hand-tool work;
- write/read;
- eat/drink;
- rest/lean;
- inspect mechanism;
- open/close service panel.

Named characters receive personality/prop cleanup rather than being defined by the base library.

---

# 16. A3 regional occupation inventory

Each regional package must include enough reusable motion to make ordinary life visibly different.

## Brindle / First Circuit

Required families:
- farm/orchard pruning/harvest/water check;
- carpentry/repair bench;
- mill/tailbox control;
- courier load/route-board work;
- inn table/food service;
- pump/flywheel operation;
- local timing-card/manual signal use.

## Cairnspire

Required families:
- route clerk/dispatcher board work;
- lift mechanic/service-panel work;
- archive filing/copy/provenance handling;
- kitchen/service preparation;
- public counter/registration exchange;
- manual pressure/repair team work;
- paper-route correction after Stillness.

## Rootmere

Required families:
- ferry rope/gate operation;
- orchard tending;
- rootweaving/flexible-joint repair;
- flood-height/water observation;
- flood-hall cooking/record keeping;
- bell-oak safe maintenance;
- living-span inspection.

## Saltreach

Required families:
- dock/mooring/line handling;
- net making/repair;
- shipwright/dry-dock tool work;
- pressure-gauge/chamber operation;
- fog-code painting/signaling;
- lowwater market moving/setup;
- salvage/memorial handling.

## Emberstep

Required families:
- mold preparation/casting support;
- kiln load/unload;
- quench control;
- maker-mark/provenance work;
- heavy-haul operation;
- clinic sterilizer/brace work;
- manual heat/availability-board operation.

## High Aerie

Required families:
- rope/chain rigging;
- lift/cargo work;
- wind-ribbon/vane observation;
- archive/copy work;
- Wind Kitchen food/service work;
- bridge-load inspection;
- novice teaching/practice;
- weather logging.

## Mireglass

Required families:
- reed harvest/paper production;
- shallow ferry handling;
- document copy/case handling;
- Three Tables mediation/record placement;
- map overlay work;
- wetland path/marker maintenance;
- reflection-cover/lamp handling.

## Cairnfall

Required families:
- survey tripod/marker setup;
- lens/instrument adjustment;
- raw/corrected board notation;
- public astronomy teaching;
- calibration screw/clock work;
- night observation;
- supply/cistern work.

Regional occupation clips may share underlying mechanics only after material posture/prop differences remain readable.

---

# 17. NPC social / population loop rules

Every occupied settlement needs a mix of:
- solitary work;
- paired work;
- three-person/social group behavior;
- seated/resting behavior;
- meal/service behavior;
- route arrivals/departures;
- brief greetings/exchanges;
- state-change reactions.

Production must provide loop-offset/random-entry support so visible crowds do not synchronize.

Animation randomization may change presentation order only; it may not create procedural story facts.

---

# 18. Ordinary enemy A4 family inventory

Each ordinary enemy family needs a **minimum semantic package**, adjusted for morphology:

- neutral/idle;
- locomotion modes used in combat;
- turn/reorientation;
- threat/aggro enter;
- primary attack anticipation/action/recovery;
- secondary attack family if encounter authority grants one;
- hit reaction tiers compatible with enemy-combat authority;
- stagger/guard-break where authored;
- disengage/retreat where ecology allows;
- death/resolution;
- terrain/environment movement special family if role requires it;
- Hush/state variant only where semantically justified.

## 18.1 Regional starter-family burden

### Rootmere
- Root burrower;
- Flood-stalker;
- Harnessed root-beast variants.

### Saltreach
- Tide crawler;
- Pressure eel/fish predator;
- Dock scavenger flock.

### Emberstep
- Ash runner;
- Kiln vermin / ceramic-shell scavenger;
- Hazard-machine family.

### High Aerie
- Talons species variants;
- Cliff stalker;
- Wind scavenger.

### Mireglass
- Reed ambusher;
- Shallow-water pursuit fauna;
- Hush residue/pattern family.

### Cairnfall
- Plateau runner;
- Instrument-nesting scavenger;
- Correction-linked machine hazards.

### Hush-Cairnspire / Null Meridian
- Repeating impressions — mostly environmental/non-hostile; not a generic enemy set;
- Responsive residues;
- rare emergent composites;
- Meridian service hazards.

Exact retail archetype split is a later region/encounter-content task; these families establish animation quote burden now.

---

# 19. Boss / major-pressure A5–A7 inventory

Every row below is a required bespoke production package unless explicitly stated otherwise.

## 19.1 Mossjaw

Required:
- quadruped idle/territorial read;
- walk/turn/run/charge locomotion;
- rooting/head-force threat;
- attack anticipation/action/recovery families required by encounter design;
- hit/stagger/death where combat authority supports;
- harness drag/secondary relationship;
- detachable harness component response;
- post-component-change behavior;
- restrained ordinary-animal resolution/death.

Reuse: compatible root-beast foundation may inform ordinary variants; boss readability requires bespoke cleanup.

## 19.2 Mawhart

Required:
- monumental browser locomotion;
- brace/lean/contact with giant roots;
- defensive threat families;
- foreign-band/tension-cable constraint motion;
- component exposure/reaction;
- brace release sequence(s);
- progressively freer motion state;
- liberation/escape resolution;
- later ordinary woodland distant motion.

No death spectacle package is the default resolution.

## 19.3 Nine-Lung Leviathan

Required:
- large-body water movement;
- low-frequency propulsion/tail cycle;
- tactile sensory-fin response;
- nine-opening biological respiratory cycle;
- externally forced pressure-cycle variant;
- chamber-locked/active/released response;
- distress/weakness states;
- encounter defensive/pressure actions;
- hardware release sequence(s);
- weak post-liberation escape/asymmetric swimming;
- no miraculous healed victory swim.

This is high-cost bespoke creature animation and should be estimated accordingly.

## 19.4 Cinder Regent

Required A6 machine states:
- neutral/service idle;
- floor-leg index/rotation where authored;
- sweeping mold-arm operation;
- clamp/press cycle;
- thermal shield open/close/rotate;
- inspection/probe operation;
- counterweight preparation;
- thermal vent/casting danger cycle;
- interrupt/safe-state transition;
- disabled asymmetric settle;
- accessible control-state resolution.

No humanoid attack set.

## 19.5 Choir of Talons

One species foundation plus three readable individual condition variants.

Required:
- perch/idle;
- takeoff;
- level flight;
- banking/turn;
- dive anticipation/dive/recovery;
- close attack/grab/sweep as encounter authority requires;
- landing/perch;
- hit/reaction;
- death/retreat;
- wind-window response;
- old/torn-vane asymmetry for the identified older predator.

## 19.6 Saint Varo

Required A7 package:
- monumental official-memory neutral;
- historical worker/rescuer human-motion fragments;
- heroic reset pose/state;
- contradiction entering body/space;
- clean/damaged costume-state motion continuity;
- fatigue/asymmetry return;
- encounter attack/pressure actions as final combat design specifies;
- loop reset behavior;
- coexistence/resolution state where failure/courage remain together.

Do not animate as undead knight.

## 19.7 Archivist Without a Face

Required relational package:
- traversal through archive spaces;
- hands materialize only for reorder/remove work;
- room/record simplification synchronized with movement;
- contradiction response;
- Palinode resistance/reversal relationship;
- pressure-state escalation;
- resolution where simplification stops.

A conventional `Hit/Death` library is not the production model unless later encounter authority explicitly requires one.

## 19.8 Mirror Widow

Required:
- base human diplomatic locomotion/gesture set;
- 4–5 incompatible authored self-state performance variants from art authority;
- version transition/overwrite presentation;
- shared human identity anchors across variants;
- negotiation-success posture;
- breakdown/wet/exhausted state;
- accusation/institutional posture;
- worker-assistance practical state;
- public-retelling simplified state;
- encounter pressure/action families as authored;
- shared mundane gesture/mark convergence;
- layered stable resolution.

Do not create simultaneous-clone combat animations unless encounter authority later explicitly supports clones.

## 19.9 Gravemoon Engine

Required A6 room-mechanism package:
- independent ring/local instrument movement;
- correction spindle engagement;
- forced alignment cycle;
- counterweight motion;
- instrument-pylon response;
- correction hazard states;
- disconnect action/reaction;
- post-resolution local rings moving at deliberately different rates;
- no generic explosion/death.

## 19.10 Echo-bound Orin

Reuse Orin C1 human foundation plus bespoke A7 relationship work:
- repeated final gestures;
- hand returning to safe position;
- garment/repair state reset cues;
- increasingly continuous human motion as preserved states end;
- recognition/release performance;
- environment-preservation loops synchronized around him.

No monster locomotion, attack-transformation or giant-boss death package.

## 19.11 Maelor

Required A1/A5 package:
- normal recurring Maelor movement/dialogue;
- Phase 1 technical combat idle/stance;
- Light/Heavy/defensive/evade-equivalent actions only as final boss combat authority grants;
- compact technical-tool handling;
- delayed-echo/preserved-object action presentation;
- false-diagnostic history interaction;
- hit/reaction/stagger/defeat;
- Phase 2 mechanism-coupling enter;
- infrastructure-linked technical actions;
- increasing physical strain/fatigue layers;
- disconnect/collapse/defeat state;
- post-boss human-scale performance.

No demon/dark-lord transformation animation.

## 19.12 Listener

The Listener has **no conventional skeletal animation inventory**.

Required A7/A8 relational animation burden:
- repeated Brindle ordinary-life motion loops;
- repeated ferry-water/wake motion;
- Wind Kitchen ordinary loops;
- quay meal/social loop;
- Emberstep work-bracket/ordinary work memory;
- Cairnfall observation-night loops;
- player-specific ordinary-memory loops where production supports them;
- exact-repeat/reset behavior that initially reads natural;
- incomplete overlapping silhouette transitions;
- release/decommission motion where repetitions cease/separate/pass out of view.

This package depends heavily on environment/NPC/VFX/cinematic coordination and should be estimated as cross-discipline animation, not “one boss rig.”

---

# 20. Machine / mechanism A6 library

Beyond named bosses, repeated civic/puzzle machinery needs explicit animation support.

Shared families include:
- Waybell resonance/mechanical motion;
- service hatch/inspection movement;
- pressure gate/valve;
- counterweight;
- pulley/lift;
- flood/tide gate;
- kiln/mold/casting mechanism;
- rope/chain load system;
- observatory instrument;
- Line Skiff station/coupling;
- puzzle constraints/track movement;
- manual fallback mechanisms;
- Hush paired expression where actual geometry/state differs.

Mechanism animation must follow source-owned mechanism state, not arbitrary timeline playback.

---

# 21. Hush A7 relational burden by content type

## Paired ordinary world object

Usually no bespoke skeletal animation. Rebind presentation from same semantic state.

## State-local object

May use distinct animation only if the local state actually differs.

## NPC recurrence

Use preserved/missing/contradictory motion where story authority requires; no global Hush idle.

## Hush puzzle

Animate mechanism consequences from explicit semantic facts.

## Hush combatant

Preserve health/action/aggro continuity; destination expression may use mapped animation state without restart.

## Hush composite boss

Use bespoke relationship packages from Section 19.

---

# 22. Facial animation production inventory

## F0

Subjects:
- Neris;
- Tessa;
- Ilyra;
- Orin;
- Maelor.

Required system coverage:
- neutral/listening;
- speech;
- eye aim/attention;
- blink/lid;
- brow/cheek/mouth asymmetry;
- controlled smile/humor;
- irritation;
- concern/fear;
- grief;
- anger;
- exhaustion/strain;
- silent processing;
- breath/swallow/settle where close performance requires;
- localization-compatible speech solution.

These are rig/performance capabilities, not necessarily pre-baked emotion clips.

## F1

Subjects:
- Caldrin;
- Sena;
- Rusk;
- selected C3+ story owners.

Required:
- readable speech;
- eyes/brows;
- clear emotion presets/curves;
- medium-shot dialogue viability;
- limited bespoke close performance for authored scenes.

## F2

Population/light dialogue:
- basic speech/jaw;
- blink/eye focus;
- coarse emotion/attention;
- scalable cost.

Final facial technology and source count remain runtime/production-gated.

---

# 23. Cinematic A8 inventory method

The Narrative/Cinematic Production Package will later enumerate exact scenes.

Animation must classify every cinematic beat into one of:

- `CIN-GAMEPLAY-REUSE` — gameplay animation adequate;
- `CIN-GAMEPLAY-CLEANUP` — gameplay foundation with bespoke hand/contact/facial cleanup;
- `CIN-BESPOKE-BODY` — scene-specific body performance;
- `CIN-BESPOKE-FACE` — scene-specific facial performance;
- `CIN-CROWD` — background/group staging;
- `CIN-MECHANISM` — major machine/environment animation;
- `CIN-HUSH-RELATION` — bespoke semantic Hush staging.

Every cinematic inventory row must state actors, costume/state, props, camera distance, dialogue/VO dependency, entry/exit state, skip behavior and reuse class.

Until the cinematic inventory exists, `SH-ANI-008` can be closed only at **method/authority**, not exact scene count.

---

# 24. Audio/VFX animation-marker burden

Every production animation may declare presentation markers for:
- footstep/material contact;
- hand/prop contact;
- weapon/tool impact;
- cloth/gear accent;
- mechanism latch/release;
- safe VFX spawn;
- camera impulse request;
- facial/dialogue beat.

Gameplay-affecting marker use requires the owning system’s validated boundary.

No production tracker may label a notify `Quest Complete`, `Damage On`, `Invulnerable`, `Hush Active`, or equivalent as sole authority.

---

# 25. Animation source/provenance manifest fields

Every authored source animation entry should carry:

- semantic animation ID;
- subject/rig family;
- production class;
- gameplay/narrative owner link;
- source state;
- destination state;
- displacement class;
- root-motion/warping eligibility;
- contact points;
- interruption routes;
- prop/equipment dependency;
- Hush/state variant relationship;
- facial tier;
- audio/VFX marker needs;
- reuse/retarget classification;
- source DCC/provenance;
- review status;
- runtime-gated variables;
- fixture/test link.

This prevents `.uasset` animation files from becoming undocumented production truth.

---

# 26. Minimum test galleries / fixtures

The future animation review workbench must provide at least:

## Neris
- free locomotion loop;
- starts/stops/pivots/reversal;
- jump/fall/landing severity;
- mantle/ledge/ladder;
- swim;
- target-lock movement;
- every combat action/reaction;
- Cantor;
- Anchor;
- one fixture for each later tool;
- Skiff board/ride/disembark;
- Hush transition continuity;
- equipment traversal clearance.

## Humanoids
- body/proportion retarget gallery;
- C1/C2 personality posture comparison;
- C3 occupation loops;
- C4 crowd loop-offset test;
- F0/F1/F2 facial comparison.

## Enemies/bosses
- black-silhouette telegraph gallery;
- ordinary enemy family locomotion/attack/reaction;
- boss anticipation/recovery;
- component/load interaction;
- machine state gallery;
- Hush composite state gallery;
- every boss resolution state.

## Technical
- foot/hand IK stress cases;
- warp envelope failures;
- root-motion rejection/interruption;
- animation LOD/significance test;
- save/reload/reset secondary-motion stability.

---

# 27. Production burden summary

At current written-authority level, animation production must plan for at minimum:

- **1 complete C0 player gameplay package** covering ground, air, slopes, ledges, ladders, surface swim, target-lock, combat, Cantor, Anchor, later tools, Hush, interactions and Line Skiff;
- **5 F0 principal facial/performance subjects** — Neris, Tessa, Ilyra, Orin, Maelor;
- **3 C2/F1 major recurring character packages** — Caldrin, Sena, Rusk;
- **the full C3/C3+ named recurring roster enumerated in `docs/160` and Section 14**, each with occupation/dialogue/state-continuity burden;
- **8 regional occupation-animation packages** — Brindle, Cairnspire, Rootmere, Saltreach, Emberstep, High Aerie, Mireglass, Cairnfall;
- **shared A2 humanoid locomotion/conversation/ordinary-life foundations**;
- **at least 18 ordinary regional enemy starter families** across the six ordinary non-Brindle combat regions, plus Hush-Cairnspire/Null special pressure families as later region content resolves exact archetypes;
- **12 named boss/major-pressure bespoke packages** — Mossjaw, Mawhart, Nine-Lung Leviathan, Cinder Regent, Choir of Talons, Saint Varo, Archivist Without a Face, Mirror Widow, Gravemoon Engine, Echo-bound Orin, Maelor, Listener;
- **shared civic/mechanism animation libraries**;
- **Hush relational/state animation burden** across paired world content;
- **cinematic animation burden** to be enumerated scene-by-scene by the Narrative/Cinematic package;
- **A9 procedural/additive support** for foot/hand contact, aim, tool tension, slope, rider stance, secondary motion and facial attention;
- **animation review/System IDE tooling and fixtures**.

This is sufficient for a studio to recognize the scale and categories of animation work.

It is not a final source-clip count or staffing estimate.

---

# 28. Explicit runtime-gated counts

The following must **not** be invented now:

- exact directional locomotion clip count;
- exact target-lock blend-space population;
- exact Evade directional variants;
- exact hit-reaction directional count;
- exact IK solve frequency;
- exact facial blendshape/bone/control count;
- exact dialogue gesture library size;
- exact crowd loop count per body family;
- exact animation-memory MB budget;
- exact compression settings;
- exact tick-rate LOD thresholds;
- exact runtime retarget versus baked-retarget ratio;
- exact boss attack animation count before encounter behavior is fully production-authored;
- exact cinematic bespoke-clip count before the cinematic inventory exists.

Each of these has an identified downstream evidence/production dependency.

---

# 29. Prohibited production shortcuts

Do not reduce this burden by:
- deleting a gameplay state from animation because it is difficult;
- using one universal interaction clip for all tool/mechanism work;
- retargeting Neris’s movement personality onto every NPC;
- reusing one “animal attack” across incompatible morphologies;
- treating every boss resolution as death;
- giving Hush characters a universal floating/glitch loop;
- replacing occupation loops with generic tavern idles;
- using a montage notify as the only gameplay state transition;
- using animation warping to compensate for invalid traversal geometry;
- hiding missing motion with VFX.

---

# 30. Acceptance result

This manifest establishes the **required animation-production surface** without pretending that final clip multiplicity is knowable before representative rig/runtime/cinematic evidence.

Current result:

> **PASS — ANIMATION FAMILIES AND PRODUCTION BURDEN ARE EXPLICIT AT WRITTEN-HANDOFF LEVEL.**

The remaining animation work is execution, exact clip decomposition, cinematic scene enumeration, runtime integration, tuning, performance, accessibility/readability validation and human acceptance.