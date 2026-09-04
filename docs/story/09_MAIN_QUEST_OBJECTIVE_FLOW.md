# Project Stillring — Main Quest Objective Flow

**Status:** canonical player-facing critical-path flow  
**Related:** Issue #16, `docs/story/07_SCENE_BEAT_LEDGER.md`, `docs/story/08_REVEAL_AND_FORESHADOW_LEDGER.md`

This document owns the **main quest objective chain**: what the player is asked to do, what state unlocks the objective, and what must be true before the next objective can begin.

It is intentionally not a quest-script implementation. Scene-tree paths, trigger volumes, dialogue resource IDs, and save serialization belong in implementation docs later.

## Objective design rules

1. Player-facing objectives describe **what Neris intends**, not hidden developer logic.
2. Do not expose twist logic in objective text before Neris knows it.
3. Mandatory objectives should usually point toward a place/person/problem, not give exact puzzle solutions.
4. Optional content may interrupt travel but must not silently advance mandatory state.
5. A save/reload at any objective boundary must reconstruct a coherent world state.

---

# ACT 0 — BRINDLE

## MQ00.01 — Finish First Ring Repairs

**Display text:** `Help Orin finish the village repairs before First Ring.`

**Starts:** game start after `M00-S01`.

**Required tasks:**
- mill signal repair;
- basic delivery/interaction tutorial;
- return required component to Orin.

**Optional during state:** C01 and village conversations.

**Completes when:** core morning tasks done.

**Next:** MQ00.02.

---

## MQ00.02 — Meet Tessa

**Display text:** `Meet Tessa at the practice yard.`

**Starts:** morning work complete.

**Completes when:** combat tutorial `M00-S03` completed.

**Next:** MQ00.03.

---

## MQ00.03 — Return for First Ring

**Display text:** `Return to the workshop before the ceremony.`

**Starts:** spar complete.

**Required state:** allows `M00-S04` Orin almost-confession.

**Completes when:** player enters festival staging state.

**Next:** MQ00.04.

---

## MQ00.04 — Get Back to the Workshop

**Display text:** `Stay with Orin. Get back to the workshop.`

**Starts:** First Ring failure begins.

**Control:** crisis route.

**Completes when:** floor-compartment sequence begins.

**Next:** MQ00.05.

---

## MQ00.05 — Reach Orin

**Display text:** `Follow Orin through the seam.`

**Starts:** Orin pulled into Hush.

**Completes when:** Cantor Key overload returns Neris to Waking Brindle.

**Next:** MQ01.01.

---

# ACT I — ROAD / CAIRNSPIRE

## MQ01.01 — Reach Cairnspire

**Display text:** `Reach Cairnspire. Find out what happened to Orin.`

**Starts:** after first Hush ejection.

**Required travel beats:** damaged flood relay + ridge vista.

**Completes when:** Neris enters Cairnspire route ward.

**Next:** MQ02.01.

---

## MQ02.01 — Register Ilyra's Cantor Key

**Display text:** `Get the Cantor Key registered before the Bellwardens take it.`

**Starts:** after Rusk/Maelor encounter.

**Sub-objectives:**
1. `Repair the late warning chime.`
2. `Help Tessa audit the Route House timestamps.`
3. `Find Ilyra's field certification in the Lower Archive.`
4. `Meet Maelor for calibration.`

**Completes when:** Key gains provisional field authorization.

**World output:** three regional commissions become visible as main objectives.

**Next:** MQ03.01.

---

## MQ03.01 — Learn the First Circuit

**Display text:** `Travel the outer circuit before taking a regional commission.`

**Starts:** after Maelor issues Rootmere/Saltreach/Emberstep work.

**Minimum completion condition:**
- reach Old Viaduct Refuge;
- complete Eda's local calibration;
- visit all three regional approaches/roadheads.

**Optional:** most early completion systems.

**Completes when:** player has enough route familiarity to choose a region.

**Next:** three commissions unlock, but canonical authored route expects Rootmere first for teaching order.

---

# ACT II — THREE TUNING CRISES

## MQ04.01 — Diagnose Rootmere's Waybell

**Display text:** `Find why Rootmere's bell-oak is losing phase.`

**Starts:** first Rootmere entry.

**Sub-objective:** `Prove whether the failure is in the tree or the old repair network.`

**Completes when:** old Bellwarden braces identified.

**Next:** MQ04.02.

---

## MQ04.02 — Release the Root Cathedral Load

**Display text:** `Enter Root Cathedral and remove the forced load from the bell-oak.`

**Starts:** C06 critical diagnosis complete.

**Internal mandatory gates:**
- acquire Anchor Line;
- clear structural route;
- defeat/resolve Mawhart encounter.

**Completes when:** Waybell stabilizes locally.

**Next:** MQ04.03.

---

## MQ04.03 — Read Ilyra's Warning

**Display text:** `Inspect the old maintenance plate.`

**Starts:** post-Mawhart.

**Completes when:** Neris reads phase-load warning and talks to Maelor.

**Next:** MQ05.01.

**Optional revisit window:** Anchor wave opens before Saltreach.

---

## MQ05.01 — Find a Safe Route Through Saltreach

**Display text:** `Restore a trustworthy harbor signal and reach Tide Foundry.`

**Starts:** Saltreach arrival.

**Required:** C10 diagnostic critical portion.

**Completes when:** route to foundry opens.

**Next:** MQ05.02.

---

## MQ05.02 — Break Tide Foundry's Pressure Cycle

**Display text:** `Stop the foundry from forcing the harbor through the same pressure cycle.`

**Required gates:**
- acquire Glasslung Reed;
- learn pressure state;
- resolve Nine-Lung Leviathan encounter.

**Completes when:** Leviathan escapes and foundry stabilizes.

**Next:** MQ05.03.

---

## MQ05.03 — Trace the Quiet Court Shipment

**Display text:** `Search the foundry freight records.`

**Starts:** boss resolution.

**Completes when:** Tessa's manifest and Maelor/Ilyra marks are found; Tessa confesses; Maelor acknowledges unsanctioned research.

**Next:** MQ06.01.

**Optional revisit window:** Glasslung wave.

---

## MQ06.01 — Clear Emberstep's Name

**Display text:** `Prove whether recent Emberstep castings caused the failures.`

**Starts:** Sena denies Waybell access.

**Required:** critical portion of C14.

**Completes when:** evidence distributed publicly and Sena grants access.

**Next:** MQ06.02.

---

## MQ06.02 — Enter the Kiln of Names

**Display text:** `Stabilize Emberstep's Waybell and recover the sealed casting records.`

**Required gates:**
- acquire Temper Gauntlet;
- resolve Cinder Regent;
- reach restricted archive.

**Completes when:** three-point phase-reference document and Mercy Window seed found.

**Next:** MQ07.01 immediately.

**Urgency rule:** no mandatory detour. Optional post-dungeon content remains available but UI/story presentation emphasizes return to Cairnspire.

---

# ACT III — GRAND RING

## MQ07.01 — Reach Maelor Before He Uses the Three References

**Display text:** `Take the Emberstep records to Cairnspire. Stop the phase-reference test.`

**Starts:** sealed log discovered.

**Completes when:** confrontation `M07-S02` begins.

**Next:** MQ07.02.

---

## MQ07.02 — Stop the Grand Ring

**Display text:** `Reach the Meridian controls.`

**Starts:** Maelor admits entrainment plan.

**Gameplay:** crisis traversal, civilian assistance, manual locks, failed attempt to reach central striker.

**Completes when:** Stillness becomes unavoidable and Key/Hush escape becomes available.

**Next:** MQ07.03.

---

## MQ07.03 — Cross Before Stillness Takes You

**Display text:** `Use the Cantor Key. Cross into the Hush.`

**Completes when:** Hush-Cairnspire world state loaded and Neris stabilizes.

**Next:** MQ08.01.

---

# ACT IV — HUSH / CHANGED ORRA

## MQ08.01 — Find the Workbench Signal

**Display text:** `Follow the familiar tuning pattern through Hush-Cairnspire.`

**Starts:** first full-Hush free movement.

**Completes when:** Ilyra found.

**Next:** MQ08.02.

---

## MQ08.02 — Learn What Stillring Did

**Display text:** `Help Ilyra stabilize the Key and understand the phase-lock.`

**Gameplay:** workbench repair + local relation demonstration.

**Completes when:** Motion/Memory/Ending need established and Brindle re-entry method learned.

**Next:** MQ09.01.

---

## MQ09.01 — Return to Brindle

**Display text:** `Use the Brindle seam to return to the Waking World.`

**Completes when:** changed Brindle entered.

**Next:** MQ09.02.

---

## MQ09.02 — Find Tessa

**Display text:** `Reach the Vale workshop and look for surviving route traffic.`

**Completes when:** Tessa arrives on Line Skiff and Ilyra speaks through seam.

**Next:** MQ09.03.

---

## MQ09.03 — Learn the Line Skiff

**Display text:** `Follow Tessa through the next Stillness wave.`

**Required:** Roadhand Pulse + Skiff tutorial route.

**Completes when:** highland route network opens.

**Next:** MQ10.01.

---

# ACT V — MOTION / PALINODE / MEMORY

## MQ10.01 — Keep High Aerie From Falling

**Display text:** `Restart local airflow before the suspended districts drop.`

**Starts:** High Aerie arrival.

**Required early beat:** archive triage / Caldrin return.

**Completes when:** route through Monastery of Updraft opens and Vane capability obtained.

**Next:** MQ10.02.

---

## MQ10.02 — Reach Tempest Belfry

**Display text:** `Follow the released storm to the upper belfry.`

**Required gates:** Vane mastery basics + Choir of Talons.

**Completes when:** Saint Varo arena reached.

**Next:** MQ10.03.

---

## MQ10.03 — Let the Story Move

**Display text:** `Stop the Varo memory from resetting the belfry.`

**Player-facing wording deliberately avoids telling solution.**

**Completes when:** Motion learned.

**Next:** MQ10.04.

---

## MQ10.04 — Follow the Forbidden Records

**Display text:** `Use High Aerie's records to locate the Bone Archive.`

**Completes when:** archive coordinates/route obtained after Caldrin breaks seal.

**Next:** MQ11.01.

---

## MQ11.01 — Enter the Bone Archive

**Display text:** `Find the pre-Meridian rescue records beneath Rootmere.`

**Completes when:** Palinode acquired and original local-hold relation reached.

**Next:** MQ11.02.

---

## MQ11.02 — Hear Both Histories

**Display text:** `Use Palinode to preserve the conflicting rescue accounts.`

**Completes when:** Ilyra admits she designed Mercy Window.

**Next:** MQ12.01.

---

## MQ12.01 — Reach Mireglass Before Its Memories Collapse

**Display text:** `Travel to Mireglass and find the Deep Wound of Memory.`

**Completes when:** Palace Under Reeds route established.

**Next:** MQ12.02.

---

## MQ12.02 — Finish the Mirror Nail

**Display text:** `Use Palinode to complete Ilyra's local state anchor.`

**Completes when:** Mirror Nail operational.

**Next:** MQ12.03.

---

## MQ12.03 — Stop the Palace From Choosing One Past

**Display text:** `Reach the shared memory at the center of the Palace Under Reeds.`

**Completes when:** Mirror Widow resolved and Memory learned.

**Next:** MQ12.04.

---

## MQ12.04 — Witness Mercy Window

**Display text:** `Stabilize the surviving experiment records.`

**Completes when:** full Mercy Window event reconstructed and Neris/Ilyra fracture lands.

**Next:** MQ13.01.

**Optional revisit window:** largest Mirror/Palinode completion wave.

---

# ACT VI — CAIRNFALL / ENDING

## MQ13.01 — Reach Cairnfall Before the Moving Pockets Collapse

**Display text:** `Find the observatory and stop Meridian's correction signal.`

**Completes when:** telescope disagreement tutorial and observatory entrance complete.

**Next:** MQ13.02.

---

## MQ13.02 — Finish the Cantor Key

**Display text:** `Recover Ilyra's focusing lens and build controlled seam mode.`

**Required:** cross-layer Neris/Ilyra calibration.

**Completes when:** seam mode operational.

**Next:** MQ13.03.

---

## MQ13.03 — Disconnect Gravemoon

**Display text:** `Break Meridian's correction loop without destroying Cairnfall's local instruments.`

**Completes when:** Gravemoon Engine disconnected.

**Next:** MQ13.04.

---

## MQ13.04 — Let Cairnfall Disagree

**Display text:** `Help the survey crew establish a local reference protocol.`

**Completes when:** Local Accord path opens and Ilyra locates Still-Cairn/Ending.

**Next:** MQ14.01.

---

## MQ14.01 — Enter Still-Cairn

**Display text:** `Open the deepest Cairnspire seam and follow Orin's workshop signal.`

**Completes when:** Echo-bound Orin encountered.

**Next:** MQ14.02.

---

## MQ14.02 — Reach Orin Without Preserving the Cage

**Display text:** `Break the repeating workshop loop.`

**Internal rule:** player must release useful temporary states; objective text must not spell this out too early.

**Completes when:** perfect workshop reached.

**Next:** MQ14.03.

---

## MQ14.03 — Let the Workshop End

**Display text:** `Choose what can remain a memory.`

**Completes when:** player performs release, learns Ending, wakes Orin.

**Next:** MQ14.04.

---

## MQ14.04 — Hear Orin's Truth

**Display text:** `Talk to Orin.`

**Completes when:** full secrecy confession and Ilyra/Orin acknowledgement scene ends.

**Next:** MQ15.01.

---

# ACT VII — UNRINGING / FINALE

## MQ15.01 — Open a Route Without Meridian

**Display text:** `Help Orra establish enough independent signals to reach the central tower.`

**Starts:** return from Still-Cairn.

**Minimum critical-path requirement:** authored subset of regional cooperation sufficient to open the Null Meridian approach.

**100% path:** all six community projects and all remaining world content can be completed before moving on.

**Completes when:** local-signal convergence creates final route.

**Next:** MQ16.01.

---

## MQ16.01 — Enter Null Meridian

**Display text:** `Follow the independent signals into the central phase structure.`

**Point-of-no-return warning:** show unresolved completion categories before confirmation.

**Completes when:** final dungeon begins.

**Next:** MQ16.02.

---

## MQ16.02 — Reach the Meridian Bell

**Display text:** `Use everything you've learned to reach the central chamber.`

**Internal:** paired-mechanic synthesis trials; no new mandatory verb.

**Completes when:** Quiet Court archive + Maelor chamber reached.

**Next:** MQ16.03.

---

## MQ16.03 — Disconnect Maelor

**Display text:** `Stop Stillring.`

**Includes:** Maelor dialogue, phase one, phase two.

**Completes when:** Maelor opens Listener prison.

**Next:** MQ17.01.

---

## MQ17.01 — Find a Future That Moves

**Display text:** `Escape the preserved possibilities.`

**Starts:** Listener alternate-world sequence.

**Completes when:** player returns from repeating good-world states and Listener asks its question.

**Next:** MQ17.02.

---

## MQ17.02 — End the Meridian Hold

**Display text:** `Use Memory, Motion, and Ending.`

**Completes when:** player shatters Meridian central heart and controlled release succeeds.

**Next:** Epilogue.

---

# EPILOGUE

## MQ18.01 — One Last Walk Through Brindle

**Display text:** `Visit the workshop when you're ready to leave.`

**Control:** playable epilogue.

**Optional:** talk to returned/changed villagers; credits-state hooks.

**Completes when:** Neris visits Ilyra and Orin scenes, then approaches road.

**Next:** MQ18.02.

---

## MQ18.02 — Take the Road

**Display text:** `Meet Tessa on the hill road.`

**Completes when:** player walks the final steps after “Yeah. I heard something cracked.”

**Outputs:** credits, post-credits, story-complete flag.

---

# Objective-flow state summary

| Phase | Main objective count | New critical verb/relation | Main emotional transition |
|---|---:|---|---|
| Brindle | 5 | base Key glimpse | family certainty breaks |
| Road/Cairnspire | 2 + subchain | calibrated Key | Maelor becomes trusted/useful |
| First Circuit | 1 | Common Measure optional seed | world becomes personally known |
| Rootmere | 3 | Anchor Line | good repair can mean removing bad repair |
| Saltreach | 3 | Glasslung | Tessa's deliberate ignorance exposed |
| Emberstep | 2 | Temper | Maelor selection / Ilyra culpability seed |
| Grand Ring | 3 | full Hush transition | Neris's repairs become complicity without intent |
| Hush/Brindle | 5 | phase envelope, Line Skiff | Ilyra alive; reunion fractures expectations |
| High Aerie | 4 | Vane + Motion | history can hold failure and courage |
| Bone/Mireglass | 6 | Palinode + Mirror + Memory | full Mercy Window truth |
| Cairnfall | 4 | seam mode + Local Accord | Neris/Ilyra cooperate without absolution |
| Still-Cairn | 4 | Ending | Orin's protection logic released |
| Unringing | 1 | regional cooperation | communities act without one master |
| Null/Listener | 4 | synthesis | final repair becomes decommissioning |
| Epilogue | 2 | none | relationships restart instead of reset |

---

# Quest implementation safety rules

## Objective text may not spoil hidden state

Bad before Emberstep:

> `Repair Maelor's three phase-reference nodes.`

Correct:

> `Stabilize Rootmere's Waybell.`

## Objective completion and narrative completion are separate

Example: defeating Mawhart does not complete Rootmere story state until Ilyra's maintenance plate is inspected and the relay conversation with Maelor resolves.

## Optional content acknowledgements do not become blockers

If the player completed a relevant setup/record, mandatory dialogue may branch to acknowledge it. The mandatory objective must still resolve coherently if the flag is absent.

## Point-of-no-return behavior

Entering Null Meridian must:

1. autosave a recoverable pre-finale checkpoint;
2. display unresolved completion categories if any;
3. allow cancellation;
4. never imply 100% is required for the valid ending.
