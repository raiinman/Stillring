# 94 — Completion Decision #6 — Testimony / Field-Record Authority

**Status:** FINAL OWNER-DELEGATED APPROVAL  
**Updated:** 2026-09-05  
**Issue:** #8 — Define 100% completion taxonomy and persistence contract  
**Decision:** #6 — record count, set structure, acquisition/read semantics, payoff, accessibility, persistence, auditability, IDE, and anti-lore-clutter constraints

## Decision question

Are 32 completion-bearing Testimonies / Field Records justified, and how do we keep them from becoming thirty-two exposition notes the player picks up solely for a percentage tick?

## Fresh research conclusion

**Keep the current target of 32 records organized into the existing eight authored sets.**

The record ledger already passes a test the other oversized categories did not: the 32 items are not isolated collectibles. Each belongs to a named set with a distinct interpretive payoff — Ilyra's technical position, incident corrections, erased maker attribution, route-worker evidence, Saltreach shipping, High Aerie contradictions, Mireglass witness disagreement, or Quiet Court ideological history.

The eight-set structure is therefore the authority, not the raw number 32. A record that does not strengthen its set should be cut or replaced rather than preserved to defend the count.

Current Xbox accessibility guidance reinforces the implementation requirement that menu/journal text be readable, scalable, high-contrast, and compatible with narration; spoken testimony needs subtitle/caption support with speaker identification and scalable presentation. Those are treated here as production constraints, not optional polish.

## Locked philosophy

> **A record should change what the player can understand, not merely prove they searched the shelf.**

## Shipping target — 32 in eight sets

The existing target is **CONFIRMED**:

| Set | Count | Set purpose |
|---|---:|---|
| A — Ilyra's Margins | 5 | reconstruct Ilyra's evolving technical objections rather than one prophetic warning |
| B — Bellwarden Incident Corrections | 5 | build an annotated public incident chronology from corrected/contested records |
| C — Maker Names | 4 | restore erased worker/maker attribution |
| D — Route Workers | 4 | expose labor/routing knowledge and support Tessa's independent network |
| E — Saltreach Shipping | 4 | trace Quiet Court logistics and later archive access |
| F — High Aerie Contradictions | 4 | preserve contradictory accounts side by side instead of flattening them into one truth-text |
| G — Mireglass Witness Pairs | 3 | support contextual resolution of conflicting memory/witness evidence |
| H — Quiet Court Letters | 3 | show accountability politics hardening into coercive continuity ideology |
| **Total** | **32** | |

## What qualifies as a completion-bearing record

A record must satisfy all of:
1. stable semantic identity;
2. authored source/provenance in the world;
3. meaningful content that changes interpretation, context, evidence, relationship, or later affordance;
4. membership in one of the eight sets;
5. a clear acquisition event;
6. accessible journal presentation after acquisition;
7. no dependence on random drop/spawn behavior.

A decorative memo, repeated lore paragraph, joke note, ordinary sign, ambient newspaper, flavor-only book, or NPC line does **not** become 100%-bearing merely because it can be stored in the journal.

## Acquisition versus reading

**100% requires acquisition, not forcing the player to open/read every record UI page.**

When a record is acquired:
- its completion obligation is satisfied;
- the journal marks it new/unread until viewed where appropriate;
- set progress updates;
- any authored set-level recomputation may occur once the relevant records are present.

Reading-state is a personal UX/history fact, **not completion authority**.

Why: requiring "open every entry" creates meaningless menu chores and accessibility problems. The player should be rewarded for finding evidence, not for clearing unread badges.

## Acquisition grammars

Records need not all be paper notes. Valid authored forms include:
- maintenance plate / machine inscription copied into the journal;
- physical ledger, manifest, service card, correction notice, worker stamp;
- testimony given by a person and transcribed/recorded;
- paired/contradictory witness accounts;
- Hush residue or recovered impression made legible through an approved tool/state;
- archive object whose relevant excerpt is deliberately captured;
- field annotation authored by Neris from a discovered evidence combination.

The player-facing journal normalizes access without pretending every source was literally a collectible letter.

## Set payoff rule

Every set must produce a meaningful payoff when complete. Valid payoff types:
- recontextualized journal synthesis;
- changed public label/archive presentation;
- new evidence in a later contract/community project;
- a route/search/completion-assist improvement;
- optional archive/space access;
- credits/world acknowledgement;
- changed dialogue grounded in acquired evidence.

A set payoff may be narrative/systemic, but it may not hide a mandatory critical-path verb or essential combat power behind full lore collection.

Set completion is derived from its member record IDs. The set itself is not a 33rd collectible.

## Information-design rules

Records should add information in one of four ways:
- **new fact** — something the player could not otherwise know;
- **contradiction** — materially challenges an existing account;
- **specificity** — turns an abstract institution/event into named people/work/material consequences;
- **connection** — links previously separate facts into a usable interpretation.

Reject a record whose only contribution is a longer restatement of information already delivered clearly elsewhere.

### Length discipline

No fixed word count is canonical, but production should favor concise authored extracts over lore essays. Long source documents may exist fictionally while the journal presents the relevant excerpt/context and allows optional deeper text only where worthwhile.

The main story cannot require reading a multi-page optional record to understand a critical objective.

## Missability and world change

Completion-bearing records should normally remain recoverable after major story changes.

Allowed strategies:
- physical source persists;
- changed-world source moves to an archive/refuge;
- Caldrin/Tessa/community recovery preserves a previously available record;
- Hush representation exposes the same semantic record through a changed form;
- pre-lock warning exists for a rare intentionally missable record, but intentional permanent missability requires explicit review.

Streaming/destruction/state changes may not accidentally brick 100%.

## Accessibility / readable journal

The journal and record viewer must support the project's accessibility baseline and, at minimum:
- scalable readable text rather than tiny diegetic-only print;
- high-contrast/background options;
- a less-stylized readable font option;
- mixed-case body text;
- screen-reader / narration compatibility for navigable journal text where platform/implementation permits;
- subtitles/captions for spoken testimony, with speaker identification and adjustable presentation;
- text equivalents for meaningful audio-only testimony/evidence;
- no critical distinction encoded by color alone.

Decorative original handwriting/plates can be shown visually, but the **canonical readable transcription** must be available separately.

## Late auditability

Early:
- sets can reveal themselves naturally as the player acquires the first relevant record;
- undiscovered records do not need exact map icons.

Mid/late:
- journal exposes per-set acquired/total counts;
- regional provenance can help narrow missing entries;
- specialists/archives can provide contextual hints for missing records;
- stronger accessibility/completion assist may escalate to subregion or explicit source-area guidance;
- a 31/32 player must not need an external checklist to identify the missing semantic record.

## Persistence ownership

The durable acquired-record fact belongs to **Completion / Collectible Ledger** under the locked save taxonomy, with Quest/Story/World systems owning any downstream consequences triggered by that acquisition.

Rules:
- stable `record.<set>.<slug>` semantic ID;
- acquisition is one-shot/idempotent;
- source object/path/location is representation, not identity;
- acquired state and read/unread state are separate;
- set completion is derived;
- downstream world/quest changes settle through their authoritative owners;
- save/load/retry cannot duplicate set rewards or re-acquire the same record;
- migration handles renamed/merged/split/retired records explicitly.

## Record / Completion System IDE

The development workbench must expose:
- semantic record ID;
- set membership;
- source type/provenance and region;
- acquired / unread state;
- Completion Ledger state;
- downstream references/payoff consumers;
- set acquired/total/complete derived state;
- accessible transcription presence;
- spoken-content subtitle/caption coverage;
- duplicate information/provenance review tags;
- orphan/missing/duplicate ID validation.

Required fixtures:
1. physical found record acquisition;
2. NPC testimony transcription;
3. Hush-derived record;
4. record acquired but never opened still counts;
5. set becomes complete and triggers only one payoff transaction;
6. save/load with unread state preserved independently;
7. changed-world recovery source;
8. screen-readable transcription of stylized source;
9. contradictory pair displayed together without flattening either account;
10. 31/32 late-audit fixture identifying the missing record.

## Red-team / rejection conditions

Reject a record if:
- it exists only for a collectible count;
- it repeats a fact already communicated more effectively elsewhere;
- it requires unreadable tiny diegetic text with no transcription;
- it is a generic lore dump unconnected to a set payoff;
- acquiring it depends on random drop/spawn luck;
- a world-state change accidentally makes it permanently unavailable;
- completion requires opening/scrolling the record after acquisition;
- its set's full payoff is mandatory critical-path power;
- the same meaningful information could be delivered better through an ordinary scene/NPC/world detail without loss.

## Approval

**APPROVED / LOCKED under the owner's scheduled-run delegation.**

### Final locked statement

> **Stillring keeps 32 Testimonies / Field Records because they form eight authored evidence sets with real interpretive or systemic payoffs. Completion counts acquisition, never menu-reading chores; every record needs stable provenance, accessible transcription, recoverability, and a reason to change what the player understands.**

## Next decision

Completion Decision #7 — **Bellwright Refuge authority: validate the 11-refuge target, discovery+activation semantics, service identity, regional placement, completion persistence, and anti-checkpoint-clutter rules.**
