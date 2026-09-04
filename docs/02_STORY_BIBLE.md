# 02 — Story Bible

This is the canonical beginning-to-end narrative for Project Stillring.

The complete story is intentionally split into reviewable chapters so narrative changes produce smaller diffs and coding agents do not have to load a thousand-line monolith for every content task.

## Core story — read in this order

1. [`story/01_FOUNDATIONS_AND_OPENING.md`](story/01_FOUNDATIONS_AND_OPENING.md) — story promise, ancient history, Quiet Court, Mercy Window, main cast, Brindle opening, inciting catastrophe.
2. [`story/02_ACT_ONE_WAYBELLS.md`](story/02_ACT_ONE_WAYBELLS.md) — Cairnspire arrival, the First Circuit exploration phase, Rootmere/Saltreach/Emberstep tuning crises, and Maelor's three-point Grand Ring betrayal.
3. [`story/03_MIDPOINT_AND_DEEP_WOUNDS.md`](story/03_MIDPOINT_AND_DEEP_WOUNDS.md) — Grand Ring catastrophe, Ilyra reunion, changed-world traversal, High Aerie/Mireglass/Cairnfall, the Countertones, Still-Cairn, and the Unringing.
4. [`story/04_FINALE_AND_ENDING.md`](story/04_FINALE_AND_ENDING.md) — Null Meridian, Maelor confrontation, the Listener, destruction of the centralized bell system, and Neris's ending.
5. [`story/05_CREDITS_AND_THEMATIC_RULES.md`](story/05_CREDITS_AND_THEMATIC_RULES.md) — credits montage, post-credits hook, and thematic rules for future writers.
6. [`story/06_CHARACTER_ARCS_AND_RELATIONSHIPS.md`](story/06_CHARACTER_ARCS_AND_RELATIONSHIPS.md) — canonical character motivations, culpability, relationship fractures, rebuilds, and dialogue continuity.

For exact spoiler timing across the critical path and optional 100% story, also read [`12_100_PERCENT_ROUTE.md`](12_100_PERCENT_ROUTE.md).

## Production story contracts

Once the core story is understood, use these documents when writing or implementing scenes:

1. [`story/07_SCENE_BEAT_LEDGER.md`](story/07_SCENE_BEAT_LEDGER.md) — stable scene/sequence IDs, participants, player-control state, physical action, scene wants, state transitions, and downstream payoffs.
2. [`story/08_REVEAL_AND_FORESHADOW_LEDGER.md`](story/08_REVEAL_AND_FORESHADOW_LEDGER.md) — authoritative seed → evidence → pressure → reveal → payoff timing for the game's major mysteries.
3. [`story/09_MAIN_QUEST_OBJECTIVE_FLOW.md`](story/09_MAIN_QUEST_OBJECTIVE_FLOW.md) — player-facing main objectives and the narrative/world-state gates that advance them.
4. [`story/10_DIALOGUE_ANCHORS.md`](story/10_DIALOGUE_ANCHORS.md) — dialogue lines and conversational intents that future script passes must preserve or deliberately revise with their callbacks.
5. [`story/regions/00_REGIONAL_STORY_INDEX.md`](story/regions/00_REGIONAL_STORY_INDEX.md) — regional community authority: ordinary life, social spaces, recurring residents, internal disagreement, pre/post-Stillness states, Unringing roles, and earned credits recurrence.

These are not redundant summaries. They answer different production questions:

- **Story Bible:** what happens and why?
- **Character arcs:** what changes inside the people involved?
- **100% route:** when can the player encounter each critical/optional story beat?
- **Scene ledger:** what is physically happening while a scene delivers story?
- **Reveal ledger:** what is the player allowed to know yet?
- **Objective flow:** what does Neris currently intend to do?
- **Dialogue anchors:** which wording or conversational function carries a later payoff?
- **Regional bibles:** who lives in each place when Neris is not looking, and why should the player care about returning?

A future narrative change that affects more than one of those questions must update every affected contract together.

## Regional story rule

**Every major location must be worth visiting before anything bad happens there.**

For each normal-world region, the pre-crisis state must contain ordinary life, at least one memorable social space, recurring people, humor/tenderness, work rhythms, sensory identity, and at least one reason to return that is not loot or completion percentage.

If a location only becomes interesting after its dungeon crisis or the Grand Ring, the pre-crisis version is unfinished.

For Hush-Cairnspire and Null Meridian, which are encountered after the catastrophe, this rule is paid for by establishing recognizable living Cairnspire anchors before the Grand Ring and by allowing the Hush itself moments of beauty, banality, and humor rather than making every echo tragic exposition.

## Canonical spine

Neris Vale, a seventeen-year-old apprentice bellwright from Brindle, inherits the unfinished Cantor Key after a silent catastrophe pulls Orin Vale into the Hush. Neris travels with courier Tessa Marr to Cairnspire, where respected acoustician Maelor Renn appears to be one of the few officials willing to help.

Eleven years earlier, Neris's mother **Ilyra Vale** willingly joined Maelor's private research circle, the Quiet Court, because the Meridian network was genuinely failing and the Bellwardens were concealing fatal accidents. During a route-collapse rescue, Ilyra designed **Mercy Window**, a brief local phase hold meant to stop structural motion for seconds while workers escaped. It saved lives. When one mortally injured worker was held beyond the intended interval, consciousness began repeating and new memory stopped advancing normally. Ilyra concluded that release had to remain part of the design. Maelor instead saw proof that physical loss could be delayed by engineering. That split becomes the technical and moral ancestor of Stillring.

Ilyra later developed the prototype Cantor Key to study local Waking/Hush relationships without forcing every anomaly through Meridian reference. When Maelor's experiments began treating permanent hold as the objective rather than rescue as the objective, Ilyra tried to expose the work and fell through an unstable seam into the Hush. The Bellwardens declared her dead in a field accident. Orin knew the official story was false and hid her research involvement from Neris, but he did not know she survived.

In the present, Maelor says Orra's six regional Waybells have fallen out of phase and commissions Neris to stabilize the three most urgent reference regions: **Rootmere, Saltreach, and Emberstep**. Before beginning those repairs, Neris completes a First Circuit through Cairnspire's surrounding roads and communities, learning that Orra's bell network is practical civic infrastructure and that local people have lived for generations with the costs of central standardization.

Each of the three regional crises awards a major field verb and exposes another part of the lie behind the Meridian system. Rootmere reveals that earlier Bellwardens knowingly damaged local living infrastructure. Saltreach connects Tessa to old Quiet Court logistics and forces her to admit that refusing to ask questions never truly kept her uninvolved. Emberstep proves Ilyra and Maelor collaborated, exposes the forbidden three-point phase-reference experiment, and plants the unexplained phrase **MERCY WINDOW — I. VALE LEAD**.

Neris realizes too late that Maelor chose those three regions deliberately. Three geographically separated stable signals are enough for the Meridian Bell's old emergency entrainment system to calculate a continent-scale reference and forcibly seize the remaining Waybells. Neris's successful repairs therefore become the trigger Maelor needs rather than six sacred objects in a collection ritual.

Maelor activates the **Grand Ring**. Cairnspire and then Orra enter **Stillness**, a forced phase-lock that preserves people and infrastructure in a repeating resonance relation. Neris escapes into the Hush and finds Ilyra alive after eleven missing years.

Ilyra explains that the Meridian Bell did not cure an invading evil centuries ago. It compressed the naturally occurring Hush—an echo-layer of abandoned possibilities, memories, and unchosen states—and imprisoned its emergent consciousness, the **Listener**. Maelor, broken by the deaths of his wife and son, has taken the same central machinery to its logical extreme: if change causes loss, he will stop change.

The reunion does not make Ilyra an innocent exposition figure. She admits joining Quiet Court and helping create precursor technology but initially controls the sequence of painful truth, repeating Orin's mistake in a different form. The full Mercy Window history emerges over High Aerie, Bone Archive, and Mireglass. Neris eventually learns that Maelor did not steal the foundational phase-hold concept from an innocent Ilyra; he extrapolated monstrously from work that she herself designed and once believed was worth doing. Ilyra remains responsible for her work without becoming responsible for Maelor's later coercive choice.

The changed-world act is not another sequence of ordinary Waybell repairs. Neris learns to survive temporary moving pockets and reunites with Tessa, who restores an obsolete **Line Skiff** for travel along old bell-road reinforcement lines. Early optional choices can now alter routes, shelters, survivor scenes, and local repair burdens without feeding a hidden morality meter.

At **High Aerie**, the Monastery of Updraft and Tempest Belfry form one regional campaign about intermittent motion, wind, public history, and the cost of preserving a heroic myth. Neris earns the **Vane Cloak** and learns the Countertone of **Motion**: systems can coordinate while continuing to change. Caldrin breaks with the idea that one master archive should decide which contradictory records survive; Tessa begins turning improvised courier relief into an actual civic responsibility.

A compact interlude in the ancient **Bone Archive** teaches the **Palinode Pattern**, allowing Neris to perceive incompatible resonance histories without forcing one to become the official truth. It also exposes the older rescue relation that inspired Mercy Window, forcing Ilyra to admit she designed the local hold rather than merely observing Maelor's work.

That prepares **Mireglass**, where the Palace Under Reeds overlaps contradictory memories. Neris completes the **Mirror Nail**, a tool that temporarily commits one local echo-state, defeats the Mirror Widow without selecting one perfect history, and learns the Countertone of **Memory**: the past can remain knowable without being physically recreated. A stable Hush memory finally reveals the complete Mercy Window incident and marks the emotional low point between Neris and Ilyra.

At **Cairnfall Observatory**, Maelor's phase-correction machinery is shortening every moving pocket across Orra. Neris and Ilyra finally complete the Cantor Key's controlled **seam mode**, limited to authored places where reality is already thin. This is their first successful adult collaboration after the full truth is known; it is cooperation without automatic forgiveness. Neris disconnects Cairnfall from Meridian correction, allowing communities to remain active long enough to begin separating their own local systems from the central network.

The final Countertone lies inside **Still-Cairn**, the impossible Hush accumulation of every Cairnspire that could have existed. There Neris finds Orin trapped inside a repeating reconstruction of the night Ilyra disappeared. Freeing him requires deliberately allowing useful temporary states to end rather than preserving every advantage. Neris learns **Ending**: what is over can be released without erasing that it happened. Orin then admits he knew Ilyra's official death story was false and had hidden her involvement with Maelor's research to control what life Neris would pursue. Ilyra and Orin likewise learn truths the other withheld; neither gets to edit Neris's future for protection anymore.

With Motion, Memory, and Ending learned, and Cairnfall no longer correcting every local deviation, the **Unringing** begins. Rootmere, Saltreach, Emberstep, High Aerie, Mireglass, and Cairnfall each develop local ways to survive and disconnect. Optional repair contracts, testimonies, mastery challenges, tool upgrades, anomaly hunts, the Freehand Frame prestige quest, and community projects can deepen those outcomes, but the world does not wait passively for Neris to complete a checklist before acting.

Independent local signals create temporary routes into the **Null Meridian**, where Maelor has moved the central machine partly into the Hush. The final dungeon recombines the game's accumulated verbs rather than introducing a new mandatory language. Neris defeats Maelor, but he opens the Listener's prison rather than accept disconnection.

The final conflict reveals that the ancient bellwrights and Maelor made opposite versions of the same mistake: both tried to defeat time. The ancients imprisoned endings; Maelor tried to imprison beginnings.

The final act is not to repair the sacred machine. Neris deliberately destroys the Meridian Bell's central heart. The Hush settles into many small natural seams, the Listener is released from forced singular existence, Maelor survives to face public trial, and Orra replaces centralized sacred infrastructure with imperfect local responsibility.

Ilyra returns physically but is changed by eleven years in the Hush; her relationship with Neris must be built anew. Orin begins repairing trust by giving up protective secrecy. Tessa organizes an independent courier network. Caldrin opens the archives to provenance and contradiction. Sena helps cast decentralized civic bells bearing their makers' names. Rusk can participate in exposing Bellwarden cover-ups rather than being magically transformed into an uncomplicated reform hero.

Neris eventually leaves Brindle as a traveling bellwright carrying a repaired but permanently cracked Cantor Key. The post-credits scene establishes that a different bell is ringing beneath an ocean far beyond Orra.

## Narrative authority rule

The individual chapter files are authoritative for scene-level story details. This index is the authoritative high-level spine.

Additional authority is divided deliberately:

- `story/06_CHARACTER_ARCS_AND_RELATIONSHIPS.md` — motivation and relationship continuity.
- `12_100_PERCENT_ROUTE.md` — spoiler timing and optional-story sequencing.
- `story/07_SCENE_BEAT_LEDGER.md` — mandatory scene staging and state transitions.
- `story/08_REVEAL_AND_FORESHADOW_LEDGER.md` — mystery/reveal timing.
- `story/09_MAIN_QUEST_OBJECTIVE_FLOW.md` — player-facing critical-path intent and objective gates.
- `story/10_DIALOGUE_ANCHORS.md` — locked/strong dialogue setup and callback obligations.
- `story/regions/00_REGIONAL_STORY_INDEX.md` and its linked bibles — regional ordinary life, recurring cast, local continuity, and community-state authority.

Any change that contradicts the spine or another authority contract must update every affected canonical document in the same pull request.

## Structural rule

Stillring may study the **design jobs** performed by classic adventure games—teaching order, revisit cadence, side-content braiding, spatial recontextualization, and final synthesis—but the actual fiction, quest logic, geometry, interactions, characters, presentation, and implementation must remain Stillring's own.

The Grand Ring's placement after three regional tuning crises is a pacing decision, not an instruction to imitate any other game's early/late dungeon count.
