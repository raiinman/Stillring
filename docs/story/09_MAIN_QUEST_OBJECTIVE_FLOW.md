# Project Stillring — Final Main Quest Objective Flow

**Status:** final canonical player-facing critical-path flow  
**Related:** `docs/story/07_SCENE_BEAT_LEDGER.md`, `docs/story/08_REVEAL_AND_FORESHADOW_LEDGER.md`, `docs/12_100_PERCENT_ROUTE.md`

This document owns what Neris is trying to do next, what world state permits it, and what closes each mandatory objective.

It intentionally does **not** expose hidden developer logic or puzzle solutions.

## Objective design rules

1. Objective text states Neris's current intent, not the design system beneath it.
2. Hidden twists stay hidden until Neris knows them.
3. Mandatory text usually points toward a person, place, or problem rather than a solution.
4. Optional content may interrupt travel but cannot silently advance mandatory state.
5. Narrative urgency outranks cleanup efficiency.
6. A save/reload at any objective boundary must reconstruct a coherent world state.
7. If the player could reasonably ask “why am I going there?”, the handoff is not finished.

---

# ACT 0 — BRINDLE

## MQ00.01 — Finish First Ring Repairs
**Display:** `Help Orin finish the village repairs before First Ring.`

**Starts:** game start after `M00-S01`.

**Required:** morning tutorial work from `M00-S02`.

**Optional:** C01 Crooked Fire Bell and ordinary Brindle interactions.

**Completes:** core morning tasks done.

**Next:** MQ00.02.

## MQ00.02 — Meet Tessa
**Display:** `Meet Tessa at the practice yard.`

**Completes:** `M00-S03` spar ends.

**Next:** MQ00.03.

## MQ00.03 — Return for First Ring
**Display:** `Return to the workshop before the ceremony.`

**Completes:** `M00-S04` finishes and festival staging begins.

**Next:** MQ00.04.

## MQ00.04 — Get Back to the Workshop
**Display:** `Stay with Orin. Get back to the workshop.`

**Starts:** `M00-S05` failure.

**Completes:** floor-compartment sequence begins.

**Next:** MQ00.05.

## MQ00.05 — Reach Orin
**Display:** `Follow Orin through the seam.`

**Completes:** Key overload returns Neris to Waking Brindle after `M00-S07`.

**Next:** MQ01.01.

---

# ACT I — ROAD / CAIRNSPIRE

## MQ01.01 — Reach Cairnspire
**Display:** `Reach Cairnspire. Find out what happened to Orin.`

**Required travel beats:** flood relay and Meridian ridge.

**Completes:** Neris enters Cairnspire route ward.

**Next:** MQ02.01.

## MQ02.01 — Register Ilyra's Cantor Key
**Display:** `Get the Cantor Key registered before the Bellwardens take it.`

**Sub-objectives:**
1. `Repair the late warning chime.`
2. `Help Tessa audit the Route House timestamps.`
3. `Find Ilyra's field certification in the Lower Archive.`
4. `Meet Maelor for calibration.`

**Completes:** Key receives provisional field authorization and Maelor issues three crisis commissions.

**Next:** MQ03.01.

## MQ03.01 — Calibrate the Key Beyond Meridian
**Display:** `Calibrate the Cantor Key against independent regional baselines.`

**Why Neris wants this:** a bad central calibration could point away from Orin or misdiagnose the regions entirely.

**Required:**
- Old Viaduct Refuge / Eda Vell;
- ordinary-life baseline in Rootmere;
- ordinary-life baseline in Saltreach;
- ordinary-life baseline in Emberstep;
- ordinary-life baseline in High Aerie;
- ordinary-life baseline in Mireglass;
- ordinary-life baseline in Cairnfall;
- compare all six in `M03-S11`.

**Pacing:** these are compact social/calibration visits, not six proto-dungeons.

**Completes:** Key can separate healthy regional variance from true crisis drift.

**Next:** MQ04.01.

---

# ACT II — THREE CRISIS REGIONS

## MQ04.01 — Diagnose Rootmere's Waybell
**Display:** `Find why Rootmere's bell-oak is losing phase.`

**Completes:** old Bellwarden bracing is identified as the harmful load path.

**Next:** MQ04.02.

## MQ04.02 — Release the Root Cathedral Load
**Display:** `Enter Root Cathedral and remove the forced load from the bell-oak.`

**Required internal gates:** Anchor Line, Mossjaw route, Mawhart resolution.

**Completes:** Waybell stabilizes locally and Mawhart retreats.

**Next:** MQ04.03.

## MQ04.03 — Read the Old Warning
**Display:** `Inspect Ilyra's maintenance plate.`

**Completes:** Neris reads the central-phase warning and resolves the Maelor relay conversation.

**Next:** MQ05.01.

**Optional window:** Anchor revisit content opens, but presentation allows Rootmere evening to breathe first.

---

## MQ05.01 — Restore a Trustworthy Harbor Signal
**Display:** `Find a safe route through Saltreach and reach Tide Foundry.`

**Required:** critical portion of Fog Tower diagnostic.

**Completes:** route to Tide Foundry opens.

**Next:** MQ05.02.

## MQ05.02 — Break the Foundry Pressure Cycle
**Display:** `Stop Tide Foundry from forcing the harbor through one pressure cycle.`

**Required gates:** Glasslung Reed and Leviathan encounter.

**Completes:** coercive pressure system is disabled and Leviathan escapes.

**Next:** MQ05.03.

## MQ05.03 — Trace the Restricted Freight
**Display:** `Search the foundry freight records.`

**Completes:** manifest links Tessa's old route to restricted Maelor/Ilyra research and Tessa confesses deliberate incuriosity.

**Next:** MQ06.01.

**Quiet handoff:** Leviathan death news may arrive during travel; do not convert it into another mandatory objective.

---

## MQ06.01 — Clear Emberstep's Name
**Display:** `Prove whether Emberstep's recent castings caused the failures.`

**Completes:** maker evidence shows the accusation is false and Sena grants access.

**Next:** MQ06.02.

## MQ06.02 — Enter the Kiln of Names
**Display:** `Stabilize Emberstep's Waybell and recover the sealed casting records.`

**Required gates:** Temper Gauntlet and Cinder Regent.

**Completes:** three-point records and Mercy Window mark are recovered.

**Next:** MQ07.01 immediately.

**Urgency rule:** optional content remains technically available but UI/story presentation emphasizes Cairnspire.

---

# ACT III — GRAND RING

## MQ07.01 — Reach Maelor Before Entrainment Begins
**Display:** `Take the Emberstep records to Cairnspire. Stop the three-reference activation.`

**Starts:** `M06-S05` evidence.

**Completes:** Neris's group reaches Meridian sub-chamber and confrontation begins.

**Next:** MQ07.02.

## MQ07.02 — Stop the Grand Ring
**Display:** `Reach the Meridian controls.`

**Gameplay:** crisis traversal, civilian assistance, manual overrides, failed attempt to stop activation.

**Completes:** phase-lock becomes unavoidable and the Key/Hush escape is available.

**Next:** MQ07.03.

## MQ07.03 — Cross Before Stillness Takes You
**Display:** `Use the Cantor Key. Cross into the Hush.`

**Completes:** Hush-Cairnspire state stabilizes around Neris.

**Next:** MQ08.01.

---

# ACT IV — ILYRA / CHANGED BRINDLE

## MQ08.01 — Follow the Workbench Signal
**Display:** `Follow the familiar tuning pattern through Hush-Cairnspire.`

**Completes:** Ilyra is found in `M08-S01`.

**Next:** MQ08.02.

## MQ08.02 — Help Ilyra Stabilize the Key
**Display:** `Help Ilyra stabilize the Cantor Key.`

**Gameplay:** wrong-workbench repair and local Stillring demonstration.

**Completes:** Neris understands enough to re-enter at Brindle and High Aerie is identified as the strongest moving relation.

**Next:** MQ08.03.

## MQ08.03 — Return to Brindle
**Display:** `Return to Brindle. Find Tessa.`

**Completes:** changed Brindle entered and Tessa returns on the seeded Line Skiff.

**Next:** MQ09.01.

## MQ09.01 — Learn Roadhand Pulse
**Display:** `Learn Roadhand Pulse and reach High Aerie.`

**Completes:** Skiff tutorial and first fast-road stretch are finished; highland network opens.

**Next:** MQ10.01.

---

# ACT V — MOTION / BONE ARCHIVE / MEMORY

## MQ10.01 — Keep High Aerie From Falling
**Display:** `Restart local airflow before the suspended districts drop.`

**Starts:** changed High Aerie arrival.

**Required early beat:** Weight of the Archive / Caldrin return.

**Completes:** route through the Monastery of Updraft opens and Vane Cloak is operational.

**Next:** MQ10.02.

## MQ10.02 — Reach Tempest Belfry
**Display:** `Follow the released wind to the upper belfry.`

**Required:** Vane basics and Choir of Talons.

**Completes:** Saint Varo arena reached.

**Next:** MQ10.03.

## MQ10.03 — Break the Repeating Belfry
**Display:** `Break Saint Varo's repeating belfry state.`

**Completes:** Varo resolution; relation is named **Motion** afterward.

**Next:** MQ10.04.

## MQ10.04 — Follow the Old Rescue Records
**Display:** `Follow the old rescue records beneath Rootmere.`

**Completes:** Bone Archive route is opened.

**Next:** MQ11.01.

---

## MQ11.01 — Enter the Bone Archive
**Display:** `Find the pre-Meridian rescue records.`

**Completes:** Palinode Pattern acquired and older local-hold history reached.

**Next:** MQ11.02.

## MQ11.02 — Hear the Conflicting Rescue Histories
**Display:** `Hear the conflicting rescue histories.`

**Completes:** Ilyra admits she designed Mercy Window.

**Next:** MQ12.01.

**Pacing:** no “next collectible” prompt during the silent road beat.

---

## MQ12.01 — Follow the Contradictory Resonance Into Mireglass
**Display:** `Follow the contradictory resonance into Mireglass.`

**Completes:** route to Palace Under Reeds established.

**Next:** MQ12.02.

## MQ12.02 — Finish the Mirror Nail
**Display:** `Use Palinode to finish Ilyra's local state anchor.`

**Completes:** Mirror Nail operational.

**Next:** MQ12.03.

## MQ12.03 — Stop the Palace From Choosing One Past
**Display:** `Reach the shared memory at the center of the Palace Under Reeds.`

**Completes:** Mirror Widow resolved; relation named **Memory** afterward.

**Next:** MQ12.04.

## MQ12.04 — Witness Mercy Window
**Display:** `Stabilize the surviving experiment record.`

**Completes:** full Mercy Window history reconstructed and Neris/Ilyra fracture lands.

**Next:** MQ13.01.

**Pacing:** biggest Mirror/Palinode revisit wave becomes available, but the game does not nag the player toward cleanup after the reveal.

---

# ACT VI — CAIRNFALL / ORIN / ENDING

## MQ13.01 — Reach Cairnfall Before the Moving Pockets Collapse
**Display:** `Reach Cairnfall and stop Meridian's correction signal.`

**Completes:** observatory disagreement tutorial and Fallen Orrery entrance.

**Next:** MQ13.02.

## MQ13.02 — Finish Seam Mode
**Display:** `Recover the focusing lens and finish controlled seam mode.`

**Required:** Neris/Ilyra cross-layer calibration.

**Completes:** seam mode operational.

**Next:** MQ13.03.

## MQ13.03 — Disconnect Gravemoon
**Display:** `Break Meridian's correction loop without destroying Cairnfall's local instruments.`

**Completes:** Gravemoon disconnected; moving pockets lengthen across Orra.

**Next:** MQ13.04.

## MQ13.04 — Trace Orin's Workshop Signal
**Display:** `Trace Orin's repeating workshop signal.`

**Completes:** uncorrected Cairnfall observation identifies the deep Still-Cairn seam.

**Next:** MQ14.01.

---

## MQ14.01 — Enter Still-Cairn
**Display:** `Open the deepest Cairnspire seam and follow Orin's workshop signal.`

**Completes:** Echo-bound Orin encountered.

**Next:** MQ14.02.

## MQ14.02 — Reach Orin Without Preserving the Cage
**Display:** `Break the repeating workshop loop.`

**Internal rule:** useful temporary states must be released; objective text does not explain the solution early.

**Completes:** perfect Vale workshop reached.

**Next:** MQ14.03.

## MQ14.03 — Let the Workshop End
**Display:** `Choose what can remain a memory.`

**Completes:** perfect workshop is released and relation is named **Ending**.

**Next:** MQ14.04.

## MQ14.04 — Hear Orin's Truth
**Display:** `Talk to Orin.`

**Completes:** full secrecy confession and family acknowledgement scene ends.

**Next:** MQ15.01.

---

# ACT VII — UNRINGING / FINALE

## MQ15.01 — Open a Route Without Meridian
**Display:** `Help Orra establish enough independent signals to reach the central tower.`

**World state:** communities have already begun attempts after Cairnfall. Neris is helping, not inventing all six systems alone.

**Minimum critical-path requirement:** authored subset of regional cooperation sufficient to open Null Meridian route.

**100% path:** all six community projects and remaining completion content may be resolved before finale.

**Completes:** independent local signals overlap into final approach.

**Next:** MQ16.01.

## MQ16.01 — Enter Null Meridian
**Display:** `Follow the independent signals into Null Meridian.`

**Before confirmation:**
- create recoverable pre-finale save;
- display unresolved completion categories;
- allow cancellation;
- never imply 100% is needed for the valid ending.

**Completes:** final dungeon begins.

**Next:** MQ16.02.

## MQ16.02 — Reach the Meridian Bell
**Display:** `Use everything you've learned to reach the central chamber.`

**Internal:** paired-mechanic synthesis; no new mandatory verb.

**Completes:** Quiet Court archive and Maelor chamber reached.

**Next:** MQ16.03.

## MQ16.03 — Disconnect Maelor
**Display:** `Stop Stillring.`

**Includes:** Maelor phase one and phase two.

**Completes:** Maelor is defeated and opens Listener containment.

**Next:** MQ17.01.

## MQ17.01 — Find a Future That Moves
**Display:** `Escape the preserved possibilities.`

**Completes:** player recognizes the beloved worlds cannot continue into anything new and reaches the Listener's question.

**Next:** MQ17.02.

## MQ17.02 — End the Meridian Hold
**Display:** `Use Motion, Memory, and Ending.`

**Note:** this is the first late objective where all three names are legitimately available to Neris and the player.

**Completes:** Neris shatters Meridian's central heart and controlled release succeeds.

**Next:** Epilogue.

---

# EPILOGUE

## MQ18.01 — Walk Through Brindle
**Display:** `Visit the workshop when you're ready to leave.`

**Control:** playable epilogue.

**Optional:** talk to returned/changed residents and inspect credits-state hooks.

**Completes:** Ilyra and Orin scenes resolved and Neris approaches the road.

**Next:** MQ18.02.

## MQ18.02 — Take the Road
**Display:** `Meet Tessa on the hill road.`

**Completes:** player walks final steps after:

> **“Yeah. I heard something cracked.”**

**Outputs:** story-complete flag, credits, post-credits scene.

---

# Critical-path motivation chain

The main quest must remain understandable in ordinary language:

1. Orin is taken, so Neris goes to the people who understand the network.
2. The only useful Key cannot yet be trusted, so Neris calibrates it against the world.
3. The strongest crises reveal both a path toward Orin and evidence of deliberate manipulation.
4. Neris tries to stop Maelor and fails.
5. Ilyra helps Neris survive the altered world, and a region that is still moving becomes the next practical lead.
6. High Aerie's records lead to the older rescue relation; that contradiction leads to Mireglass and the complete family truth.
7. Cairnfall's raw observation finds Orin's repeating signal.
8. Freeing Orin teaches the missing release relation.
9. Communities begin disconnecting, producing the final route.
10. Neris dismantles the central hold instead of restoring it.

If an implementation changes that into “collect named things because the quest log says so,” the implementation has broken the story.