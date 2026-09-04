# 19 — Assassin's Creed Movement Lineage Research

**Status:** RESEARCH INPUT — NOT DESIGN AUTHORITY  
**Date:** 2026-09-04  
**Purpose:** extract movement/traversal lessons from the Assassin's Creed franchise that are relevant to Project Stillring's unresolved locomotion decisions without importing Assassin's Creed's full parkour grammar, exact controls, animation, level geometry, or protected expression.

This file does **not** supersede `docs/17_ZELDA_DESIGN_LINEAGE_AND_CONTROL_PRINCIPLES.md`, Issue #1, or the decision register. It is a reference study only. Any Stillring policy still requires explicit owner review and repository migration through the normal one-decision-at-a-time process.

Stillring's governing control principle remains:

> **Simple intention, capable character, honest world.**

The useful question is not "should Stillring move like Assassin's Creed?" It should not. The useful question is:

> What did Assassin's Creed learn, across nearly two decades, about translating directional intent into fluent traversal without creating accidental actions or stripping the player of meaningful control?

---

## 1. The recurring design tension

Across the series, Assassin's Creed repeatedly oscillates between three priorities:

1. **Low-friction intention recognition** — point toward a traversable route and let the character solve ordinary biomechanics.
2. **Player expression / explicit control** — let skilled players choose jumps, ejects, ascent/descent lines, and risky actions.
3. **Safety / predictability** — prevent accidental deadly leaps, unwanted descents, or context guesses the player did not intend.

No era solved all three perfectly. That history is useful because Stillring is presently making exactly the boundary decisions where those goals collide.

The key lesson for Stillring is therefore not "more parkour." It is to separate **ordinary continuation**, **directional correction**, **dangerous commitment**, and **special traversal capability** clearly enough that Neris feels capable without becoming an automatic free-climbing character.

---

## 2. Assassin's Creed (2007): intention compression and authored highways

The original Assassin's Creed made open-world free-running viable by compressing complex body actions into relatively small player inputs. Altaïr was deliberately "sticky": when the player sustained traversal input and pointed him toward a valid route, he could automatically make precise jumps, swing from bars, and grab ledges. Ubisoft's retrospective also emphasizes deliberately placed "parkour starters" and connected architectural "highways" that made apparently organic cities contain readable movement routes.

### What worked

- The character solved routine biomechanics after the player expressed a direction.
- The world was authored to support the movement system rather than relying on movement code alone.
- Repeated architectural language taught players what a fast route looked like.
- Ledge catches reduced frame-perfect failure.
- Expert moves such as side/back ejects existed above the basic locomotion layer.

### What Stillring should learn

**A capable character is not the same thing as an automatic character.** Stillring already follows this logic in automatic low mantle and automatic reachable-ledge catch.

**Traversal readability belongs to level design.** Gate 1 and later production maps must include authored movement lines that remain reliable after art, collision, enemies, and props are added. A technically correct movement component cannot rescue unreadable geometry.

### What Stillring should not import

- generic stickiness to most nearby geometry;
- universal climbing as the default relationship with architecture;
- a single traversal modifier that causes the system to continuously select actions beyond the player's immediate intent.

---

## 3. Ezio era (2009–2011): progression can change movement vocabulary

The Ezio games expanded movement with climb leaps, environmental corner-swing elements, rope lifts, ziplines, the Hookblade, and other traversal-specific additions. Importantly, these capabilities changed where routes could lead and how quickly players could solve familiar vertical problems.

This is unusually relevant to Stillring because Stillring already treats traversal verbs as authored progression rewards.

### What worked

- New capabilities made existing spaces newly legible.
- Movement progression was often qualitative rather than merely a speed/stat increase.
- Environmental devices created authored shortcuts without requiring every wall to be universally traversable.

### Stillring application

This strongly supports the existing rule that **major height gates remain route/tool/later-capability problems**. Stillring can gain much of the pleasure of an evolving traversal system without baseline free climbing.

A future traversal tool should preferably answer a previously recognizable world problem rather than simply making Neris climb 15% faster.

### Boundary

This research does not authorize corner swings, wall ejects, rope travel, ziplines, or climbing tools. Those remain design choices only if and when Stillring's canon/progression requires them.

---

## 4. AC III / Black Flag / Rogue (2012–2014): streamlining reduced accidents but also reduced expression

With Assassin's Creed III, Ubisoft streamlined free-running so players could generally hold one button to run/climb, specifically reducing accidental leaps and back-ejects. The era also expanded traversal from cities into wilderness using branches, trunks, logs, boulders, and other natural-route elements.

### Useful lesson

When a movement system causes frequent catastrophic mistakes, simplifying the input grammar is a valid response. But every simplification also removes some explicit player expression.

That trade is directly relevant to Stillring's upcoming **deliberate drop** decision.

A dangerous action should not happen because the analog stick wandered slightly into a contextual interpretation. If "let go" has serious consequences, it should be a deliberate command distinct from ordinary hang correction.

### Environment lesson

AC III's wilderness work also shows that traversal grammar must be authored for the environment in which it operates. A movement system designed around urban façades cannot simply be dropped into forests and expected to feel coherent.

For Stillring this means Rootmere, Saltreach, Emberstep, High Aerie, Mireglass, and Cairnfall may use the same core locomotion state machine while presenting different **authored traversal opportunities**. The answer is not necessarily to give Neris new baseline biomechanics in every biome.

---

## 5. Unity (2014): explicit vertical intention, expressive animation, and the danger of interpretation mismatch

Unity is one of the most useful AC case studies because it is both heavily praised and heavily criticized.

It separated **parkour up**, **parkour down**, and horizontal free-running. Paris's large 1:1-scale buildings made controlled descent especially important. This is a strong conceptual move: ascent and descent are different intentions and deserve different outcomes.

Unity also used a very rich animation-driven traversal presentation. Ubisoft later described Assassin's Creed up through Syndicate as animation-driven: an interrupted action often finished its animation before the next requested action began.

### What worked

- Up/down intent reduced ambiguity in vertical navigation.
- Descending became an intentional traversal mode rather than "jump and hope."
- Animation strongly sold character competence and physical grace.
- Skilled players could produce highly expressive lines.

### What did not fully work

Community discussion remains split even in 2026. Many players admire Unity's visual flow but report that Arno can choose an unintended object, transition, or trajectory. Experienced players can learn the system, but its deeper behavior is not always self-explanatory.

This distinction matters:

> A movement system can have a high skill ceiling while still having a poor intention-to-result mapping for ordinary players.

Stillring should not require players to memorize obscure context rules just to reliably move Neris through ordinary space.

### Stillring application

- Preserve immediate acknowledgement of input.
- Use animation to sell weight and competence, but do not let animation completion routinely override a new player request.
- Distinguish dangerous descent/drop intent from lateral correction and pull-up intent.
- Do not confuse "looks amazing in a mastery video" with "is trustworthy in ordinary play."

---

## 6. Syndicate (2015): safety barriers can prevent frustration — and also remove agency

Syndicate added safety behavior that prevented jumps/ejects when the result would be deadly or lacked a valid landing/handhold.

That clearly reduces accidental deaths. It also demonstrates the opposite risk: if the game refuses too many intentional risks, the player stops feeling fully responsible for movement.

### Stillring application

Stillring should use **safety where the player's intention is ambiguous**, not as a blanket prohibition against player-owned risk.

A useful rule for future decisions:

- ambiguous input near danger → favor safety/predictability;
- explicit dangerous action → allow the authored consequence, subject to the game's fall rules.

This is likely a better fit for Stillring than either "down stick instantly drops you" or "the game never lets you make a dangerous traversal choice."

---

## 7. Origins / Odyssey / Valhalla (2017–2020): responsiveness rose while authored route meaning declined

Ubisoft's animation history identifies Origins as a major transition from animation-driven to more input-driven gameplay. Animations could be cut short so controls felt more immediately responsive.

At the same time, the RPG-era games greatly expanded surface climbing. Origins let Bayek climb most cliffs, walls, and structures with few explicit handhold requirements. This increased geographic freedom but reduced the importance of reading authored climbing routes.

### What Stillring should take

**Input responsiveness:** Neris should acknowledge a new movement request quickly even if the animation system must blend/cancel intelligently.

This matches the already locked principle that physical weight must not mean delayed acknowledgement.

### What Stillring should reject

**Universal vertical solvability.** If nearly every cliff can be climbed, the shape/material/route meaning of cliffs becomes less important. Stillring's progression model depends on inaccessible places being memorable and later becoming newly solvable.

This era therefore strengthens, rather than weakens, Stillring's existing refusal to treat every plausible vertical surface as baseline traversal.

---

## 8. Mirage (2023–2025 updates): reliable highways require production ownership

Mirage deliberately returned to dense urban traversal highways. Ubisoft Bordeaux described connecting important Baghdad locations through unmarked but clear parkour routes and later dedicating a team after beta specifically to polish those routes because players expect them to be reliable. Playtest movement heatmaps were used to discover paths that were unexpectedly slow or unclear.

Later updates added optional Free Jump and freer side/back eject behavior while retaining safer modes for players who preferred guided traversal.

### Stillring application

This produces two important rules for production:

1. **Traversal routes need regression ownership.** Art passes, prop placement, collision changes, encounter dressing, and level revisions can silently break movement flow.
2. **A safe baseline plus optional expressive controls can work, but only if the extra behavior is understandable and discoverable.** Hidden settings that dramatically change movement are a weak substitute for a coherent default.

For Gate 1, Stillring should test traversal geometry as paths, not isolated mechanic props.

---

## 9. Shadows (2025–2026): separating stance, descent, risk, and expert freedom

Shadows is especially relevant because Ubisoft explicitly revisited accidental action problems.

The control mapping separates stance switching from parkour behavior so crouching/prone changes do not accidentally send the player off a rooftop. Parkour Up and Parkour Down encode different traversal intentions. Parkour Down attempts to choose the lowest safe point; very high descent situations can transition into a ledge hang and require additional input before dropping farther.

Shadows also moved back toward **physical handhold requirements** on some surfaces, giving level designers more control over where characters can and cannot climb.

Post-launch, Ubisoft responded to parkour-player feedback by adding a direct vertical jump/grab interaction, preserving sprint through traversal transitions, improving ejects, and later adding an Advanced Parkour option that removes some safety barriers for experienced players.

### Stillring lessons

This is highly relevant to the next several owner decisions:

- **Deliberate drop:** use an explicit action, not accidental analog interpretation.
- **Broader climbing:** physical handholds / readable authored affordances are preferable to arbitrary invisible "climbable" flags or universal surface scaling.
- **Sprint/traversal flow:** movement state transitions should not gratuitously cancel requested momentum.
- **Expert expression:** extra risk/expression can exist later without compromising a trustworthy default, but Stillring should not hide foundational movement quality behind an advanced-mode setting.

### Important caution

Stillring should not copy Shadows' exact Parkour Up/Down controls, button mapping, ledge safety implementation, handhold geometry, or grappling behavior. The lesson is only the **separation of intentions**.

---

## 10. Black Flag Resynced (2026): modern retrospective evidence

Black Flag Resynced is especially valuable because Ubisoft is explicitly rebuilding an older AC movement foundation using lessons from the franchise's later systems.

The 2026 design goals described by Ubisoft include:

- making Edward's movement snappier and more deliberate;
- prioritizing responsiveness and player choice;
- refining landings so recovery is faster and movement remains continuous;
- preserving pace through traversal transitions;
- supporting manual jump for direct decision-making;
- offering advanced parkour with freer eject behavior for experienced players while allowing a more guided approach for others;
- iterating responsiveness and pace through community playtests.

### Stillring application

The strongest lesson is that **flow is not one mechanic**. It is the accumulated result of:

- input latency/acknowledgement;
- recovery timing;
- animation interruption/blending;
- momentum continuity;
- predictable affordance selection;
- route geometry;
- explicit risky actions;
- good failure/recovery behavior.

This supports Stillring's Gate 1 approach: graybox movement must be judged as a complete lived sequence, not as isolated features that each technically work.

---

## 11. Community evidence: why Unity is a warning as well as an inspiration

Assassin's Creed community discussion repeatedly praises Unity's animations and expressive ceiling while also reporting difficulty predicting some outcomes. More recent discussion around Shadows' Advanced Parkour similarly shows a discoverability problem: some players want unrestricted expert controls by default, while others point out that advanced moves must be taught clearly or they recreate old accidental-input problems.

Community evidence is not design authority, but it reinforces one useful distinction:

> **Depth is good; opacity is not.**

Stillring can support skilled expression only when the player can understand why Neris did what she did.

---

## 12. Stillring-specific conclusions

The Assassin's Creed lineage does **not** justify expanding Neris into a universal parkour protagonist.

It does support these research conclusions for upcoming owner review:

### A. Distinguish continuation from commitment

Already-approved ordinary continuation:
- toward/up from hang → pull up when valid;
- left/right along same continuous handhold → shimmy.

A dangerous commitment such as letting go should be more explicit than ordinary analog correction.

### B. Prefer player-intent categories over context soup

The control system should be able to explain, in simple terms, why Neris performed an action.

Bad grammar:

```text
stick vaguely toward geometry + context + animation state + proximity
→ maybe mantle / climb / drop / transfer / jump
```

Better grammar:

```text
clear forward traversal intent + low valid obstacle → mantle
clear jump/fall intent + reachable valid ledge       → catch
hang + toward/up                                     → pull up
hang + lateral                                       → same-ledge shimmy
explicit drop command                                → deliberate release
```

The final drop line remains pending owner approval.

### C. Authored traversal geometry is part of movement design

Every region should contain readable, reliable traversal language. Production must regression-test routes after art and gameplay dressing. A movement system cannot compensate for inconsistent route geometry.

### D. Animation serves control, not the reverse

Neris can look physically weighted and handcrafted without forcing the player to wait for long animation completion before the game acknowledges a new movement decision.

### E. Universal climbing would damage Stillring's progression model

The Origins/Odyssey-style ability to scale most surfaces solves open-world freedom but weakens Stillring's desired pattern of seeing a blocked place, remembering it, gaining a meaningful traversal verb, and returning with new understanding.

### F. Safety belongs at ambiguous boundaries

The game should protect against accidental catastrophic actions caused by ambiguous ordinary input. Explicitly chosen danger may remain player-owned once fall/recovery rules are defined.

### G. Optional expert expression is a later possibility, not a Gate 1 excuse

Mirage, Shadows, and Black Flag Resynced show the value of offering freer behavior to expert players while retaining safer defaults. Stillring may consider such options later only if the base movement grammar is already trustworthy and the extra controls serve the game's identity. It is not permission to postpone solving the default controls.

---

## 13. Direct impact on the remaining Issue #1 sequence

This research should sharpen — but **must not decide** — the remaining owner choices:

1. **Deliberate drop behavior**  
   Strong research signal: dangerous release should be explicit and should not be triggered accidentally by ordinary analog movement.

2. **Broader climbing scope**  
   Strong research signal: prefer authored/readable handholds and route logic over universal climb-everything behavior if Stillring wants progression geography to remain meaningful.

3. **Ladders**  
   Research signal: treat ladder use as a clear movement state/continuation, not context ambiguity.

4. **Swimming**  
   Research signal: preserve immediate control acknowledgement and clearly defined transition states.

5. **Crouch / stealth posture**  
   Research signal: stance changes should not accidentally trigger traversal actions.

6. **Slope scrambling/sliding**  
   Research signal: intentional ascent/descent categories and readable geometry matter more than adding flashy animations.

7. **Fall damage / recovery**  
   Research signal: recovery, safety, and explicit risk are coupled decisions; fall rules should not create hidden traversal friction.

8. **Jump arc / air control**  
   Research signal: manual jump increases player ownership only if targeting/landing rules remain predictable.

9. **Interaction while moving**  
   Research signal: preserve flow where the requested interaction is clear; do not let animation lockout make ordinary transitions feel delayed.

10. **Traversal-tool overrides**  
    Research signal: tools are strongest when they create new authored route vocabulary rather than merely automating existing movement.

---

## 14. Current recommendation boundary

The research is strong enough to influence how the next question is framed, but **not strong enough to skip owner review**.

For the immediate next decision — deliberate drop while hanging — the most defensible Stillring-specific hypothesis to present to the owner is:

> Require an explicit drop/release action while hanging. Ordinary down/away analog movement alone should not cause Neris to let go. The action should be immediate once deliberately requested, with no hold-to-confirm delay unless human testing proves accidental presses are a real problem.

This remains a **recommendation only** until owner-approved and migrated into authority.

---

## Sources

Primary / first-party:

- Ubisoft, "The Evolution of Assassin's Creed's Parkour" (2024): https://news.ubisoft.com/fr-fr/article/7tPPFQdG9mmV7yCiUmkO1K/the-evolution-of-assassins-creeds-parkour
- Ubisoft, "Looking Back on 10 Years of Assassin's Creed" (2017): https://news.ubisoft.com/en-us/article/6P2OoMbx17TavKwwHev2eT/looking-back-on-10-years-of-assassins-creed
- Ubisoft, "Bringing Emotion into Action: A History of Animation at Ubisoft" (2021): https://news.ubisoft.com/en-gb/article/34p0AE9BiBlHg1w300ZfS8/bringing-emotion-into-action-a-history-of-animation-at-ubisoft
- Ubisoft, "How Assassin's Creed Mirage Grew from DLC to Full Game" (GDC 2024 postmortem interview): https://news.ubisoft.com/es-mx/article/7eOzoQpAyuvsN3U0kqJiyR/how-assassins-creed-mirage-grew-from-dlc-to-full-game
- Ubisoft, "Assassin's Creed Shadows — Parkour System Overview" (2025): https://www.ubisoft.com/en-us/game/assassins-creed/news/4TA6gKaTvtOC1mOjZIxCZd
- Ubisoft, "AC Shadows Title Update 1.0.5" (2025): https://www.ubisoft.com/en-us/game/assassins-creed/news/3hJ2jNQEK4AXQGMg79pm2h
- Ubisoft, "AC Shadows Title Update 1.1.4" (Advanced Parkour, 2025): https://www.ubisoft.com/en-us/game/assassins-creed/news/7ccXrsadD0tpX8HYhmXvIb/ac-shadows-title-update-114-release-notes
- Ubisoft, "AC Mirage Title Update 1.1.0" (Free Jump / Free eject option, 2025): https://www.ubisoft.com/en-us/game/assassins-creed/news/1MJugDnnhNpzaXZBkAQbXt
- Ubisoft, "Assassin's Creed Black Flag Resynced — Deep Dive into Parkour, Stealth & Combat" (2026): https://news.ubisoft.com/en-au/article/2SslOS0ZO4iBLFKpTJgpzo/assassins-creed-black-flag-resynced-deep-dive-into-parkour-stealth-combat

Community sanity-check sources used only for player-sentiment contrast:

- r/assassinscreed discussions on Unity's visual quality versus predictability/control complexity;
- r/assassinscreed / r/AssassinsCreedShadows discussions on Advanced Parkour discoverability and whether unrestricted controls should be default.

Community opinion is not authority and is not used to derive exact mechanics or values.
