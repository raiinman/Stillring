# 153 — Studio Handoff Acceptance Checklist

**Status:** GOVERNING ACCEPTANCE CHECKLIST  
**Updated:** 2026-09-05  
**Parent:** `docs/151_STUDIO_PRODUCTION_HANDOFF_CLOSURE_CHARTER.md`  
**Gap register:** `docs/152_STUDIO_HANDOFF_GAP_REGISTER.md`  
**Current boundary:** documentation only; no testing or UE5.8 implementation yet

---

# 1. Final acceptance question

Stillring is not studio-handoff-safe merely because the game design is coherent.

The final standard is:

> **Could a competent external studio determine what to build, why it exists, what quality bar it must meet, what it depends on, and which decisions it is not authorized to make—without reconstructing owner intent from chat history?**

This checklist must be completed before the repository may be described as a complete external-studio production handoff package.

---

# 2. Status vocabulary

For each row use only:

- **PASS** — current repository authority is sufficient for external-studio execution at the stated stage.
- **PARTIAL** — useful authority exists but studio assumptions are still required.
- **TBD OWNER** — a genuine product/creative owner decision is intentionally unresolved and has a named decision gate.
- **RUNTIME-GATED** — cannot be honestly finalized before implementation/test evidence; the required future evidence is explicit.
- **MISSING** — required handoff authority does not yet exist.

`PASS` does not imply runtime implementation unless the row explicitly concerns runtime proof.

---

# 3. Product definition

- [ ] Product mode is explicit: single-player / no live service / no base-game multiplayer ambiguity.
- [ ] First-playthrough duration target is explicit.
- [ ] World/dungeon-scale target is explicit.
- [ ] PC-first status is explicit.
- [ ] Launch-platform scope is either selected or marked `TBD OWNER` with decision gate.
- [ ] Target-PC baseline is either selected or marked `TBD OWNER` with decision gate.
- [ ] Target resolution/framerate expectations are either defined or runtime/product gated.
- [ ] Online/backend/service requirements are explicit.
- [ ] Commercial-title status is explicit and does not treat the internal codename as cleared branding.
- [ ] Original-IP / clean-room constraints are explicit.

**Pass condition:** a producer can scope the product without quietly assuming platform, online, or commercial-brand decisions.

---

# 4. Core game design

- [ ] Locomotion authority is current and discoverable.
- [ ] Camera/targeting authority is current and discoverable.
- [ ] Combat authority is current and discoverable.
- [ ] Encounter/AI pressure authority is current and discoverable.
- [ ] Cantor/tool/puzzle authority is current and discoverable.
- [ ] Hush semantic authority is current and discoverable.
- [ ] Save/world-state ownership is current and discoverable.
- [ ] Completion counts/weights/thresholds are current and stale literals are blocked.
- [ ] Setup/Payoff ownership and all 12 chains are current.
- [ ] Line Skiff identity and route grammar are current.
- [ ] Null Meridian final-dungeon/finale authority is current.
- [ ] Optional-versus-critical-path dependencies are explicit.
- [ ] No current core mechanic requires chat-history reconstruction.

**Pass condition:** a gameplay/narrative team does not need to invent product rules to start its work.

---

# 5. Art production

- [ ] Art Bible exists and is linked from onboarding.
- [ ] Neris production character spec exists.
- [ ] Major named-character specs exist.
- [ ] NPC population strategy exists.
- [ ] Enemy/boss visual taxonomy exists.
- [ ] Region visual bibles exist.
- [ ] Modular-kit production rules exist.
- [ ] World scale/reference metrics exist.
- [ ] Material/texture production rules exist.
- [ ] Lighting/fog/atmosphere production rules exist.
- [ ] VFX language exists.
- [ ] Hush visual-production grammar exists.
- [ ] Traversal and combat readability requirements are integrated into art rules.
- [ ] Reusable versus unique asset policy exists.
- [ ] Region asset manifests exist.

**Pass condition:** two external environment/character teams should converge on one recognizably consistent Stillring rather than two different interpretations of “stylized low-poly fantasy.”

---

# 6. Animation production

- [ ] Animation Bible exists.
- [ ] Skeleton/rig/retargeting policy exists.
- [ ] Neris complete animation-family manifest exists.
- [ ] Traversal animation inventory exists.
- [ ] Combat animation inventory exists.
- [ ] Tool/interact animation inventory exists.
- [ ] Line Skiff animation inventory exists.
- [ ] Enemy archetype animation manifests exist.
- [ ] Boss animation requirements exist.
- [ ] NPC ambient/social animation strategy exists.
- [ ] Facial/performance scope exists.
- [ ] Cinematic animation burden is inventoried.
- [ ] Root-motion boundaries are explicit.
- [ ] IK/additive/procedural responsibilities are explicit.
- [ ] Animation events cannot silently become gameplay-state authority.

**Pass condition:** animation can be staffed and scheduled without deriving the action list from dozens of gameplay documents by hand.

---

# 7. Audio / music / VO production

- [ ] Audio/Music/VO Bible exists.
- [ ] Region ambience identity exists.
- [ ] Waking/Hush audio relationship exists.
- [ ] Silence/readability policy exists.
- [ ] Bell/resonance sonic grammar exists.
- [ ] Combat feedback hierarchy exists.
- [ ] UI/audio feedback family exists.
- [ ] Music/score philosophy is production-operational.
- [ ] Regional music identity exists.
- [ ] Dynamic music states are inventoried.
- [ ] Boss/finale music requirements exist.
- [ ] Music cue manifest exists.
- [ ] VO scope is selected or explicitly `TBD OWNER`.
- [ ] Voice/performance bible exists if VO is in scope.
- [ ] Pronunciation guide exists.
- [ ] Bark/dialogue audio burden is inventoried.
- [ ] Critical information has non-audio redundancy.

**Pass condition:** an audio director can budget and brief the game without inventing what Stillring sounds like.

---

# 8. UI/UX production

- [ ] UI/UX Production Specification exists.
- [ ] Complete screen/state inventory exists.
- [ ] Boot/title/new/load flow exists.
- [ ] HUD state matrix exists.
- [ ] Map information architecture exists.
- [ ] Quest/journal/record/dialogue-history IA exists.
- [ ] Inventory/tool/progression presentation exists.
- [ ] Cantor/pattern presentation rules exist.
- [ ] Completion/disclosure UI rules exist.
- [ ] Save/load/recovery states exist.
- [ ] Settings/accessibility IA exists.
- [ ] Remapping flow exists.
- [ ] Subtitle/caption presentation exists.
- [ ] Controller focus/navigation rules exist.
- [ ] Keyboard/mouse menu rules exist.
- [ ] Glyph policy exists.
- [ ] Error/warning/confirmation catalog exists.
- [ ] Credits requirements exist.

**Pass condition:** a UI team can enumerate its actual work before final visual styling begins.

---

# 9. Narrative production

- [ ] Narrative Production Package exists.
- [ ] Canonical story authority remains separate from production script status.
- [ ] Script-status taxonomy exists.
- [ ] Scene/cinematic inventory exists.
- [ ] Dialogue-scene inventory exists.
- [ ] Incidental NPC dialogue strategy exists.
- [ ] Bark families exist.
- [ ] Character performance bible exists.
- [ ] Pronunciation/context notes exist.
- [ ] Gameplay-versus-cinematic delivery boundary exists.
- [ ] Records/testimonies text inventory exists.
- [ ] Localization context requirements exist.
- [ ] Branch/state conditions are attached to semantic facts, not scene filenames alone.
- [ ] Credits/consequence text burden is inventoried.

**Pass condition:** narrative, cinematic, localization, and VO teams can determine what must be written/recorded/staged and what is already canonical.

---

# 10. World / content production

- [ ] Every major region has a production manifest.
- [ ] Every major dungeon has a production manifest.
- [ ] Cairnspire/hub burden is explicit.
- [ ] Hush/post-Stillness burden is explicit per region.
- [ ] Main-story production content is traceable.
- [ ] 24 Local Repair Contracts are traceable to production needs.
- [ ] 12 Setup/Payoff chains are traceable to production needs.
- [ ] 11 Refuges are traceable.
- [ ] 36 Faults are traceable.
- [ ] 18 Pulse Shards are traceable.
- [ ] 9 Cantor Patterns are traceable.
- [ ] 14 Tool Mastery Upgrades are traceable.
- [ ] 9 Skill Trials are traceable.
- [ ] 24 Micro-vaults are traceable.
- [ ] 32 Testimonies/Records are traceable.
- [ ] 12 Drift Knots are traceable.
- [ ] 8 Optional Elite Encounters are traceable.
- [ ] 6 Community Disconnection Projects are traceable.
- [ ] Unstandard Tool / Broken Standard Yard internal-stage burden is traceable.
- [ ] Line Skiff network burden is traceable.
- [ ] Null Meridian S1–S6 and capstone burden is traceable.
- [ ] Reusable content families are identified so optional content does not become bespoke-asset explosion.

**Pass condition:** production management can estimate content volume without reverse-engineering the completion/story authorities into an asset list from scratch.

---

# 11. Technical production

- [ ] Technical Production Bible exists.
- [ ] UE5.8 authority is explicit.
- [ ] C++-first / thin-Blueprint boundary is explicit.
- [ ] state ownership map is linked.
- [ ] stable semantic-ID policy is linked.
- [ ] save/version/migration policy is linked.
- [ ] System IDE contract is linked and required per major system.
- [ ] naming conventions exist.
- [ ] folder/package conventions exist.
- [ ] source-control/LFS workflow exists.
- [ ] asset-reference rules exist.
- [ ] data-authoring conventions exist.
- [ ] plugin/framework adoption process exists.
- [ ] build configuration/dev-tool stripping rules exist.
- [ ] localization-ready text policy exists.
- [ ] logging/capture/provenance standard exists.
- [ ] implementation decision rights are explicit.
- [ ] unresolved production architecture choices are clearly gated.

**Pass condition:** engineering can choose implementation details without accidentally choosing product semantics.

---

# 12. Production management / decision rights

- [ ] Studio Decision-Rights Matrix exists.
- [ ] `LOCKED` decisions are explicit.
- [ ] `STUDIO CHOICE WITHIN BOUNDS` decisions are explicit.
- [ ] `PROTOTYPE / HUMAN-PLAY TUNING` decisions are explicit.
- [ ] `OWNER DECISION REQUIRED` decisions are explicit.
- [ ] Change-control path exists for proposed departures.
- [ ] Production dependency/discipline matrix exists.
- [ ] Upstream blockers are distinguishable from parallelizable work.
- [ ] Outsourcing-safe packages can be identified.
- [ ] Production deliverable taxonomy exists.
- [ ] No fake staffing/headcount/budget is presented as authority without actual production manifests.

**Pass condition:** the studio knows when it may act and when it must escalate.

---

# 13. Accessibility / localization / QA readiness

No testing is required to complete the documentation rows below, but later evidence gates must be preserved.

- [ ] Accessibility requirements are consolidated by discipline/system.
- [ ] No critical information is audio-only.
- [ ] Color-independent cue requirements are mapped to art/VFX/UI.
- [ ] input/remapping requirements are mapped to UI/engineering.
- [ ] subtitle/caption requirements are mapped to narrative/audio/UI.
- [ ] motion/camera comfort requirements are mapped to camera/VFX/UI.
- [ ] timing/support accommodations are mapped to affected systems.
- [ ] localization-ready authoring rules exist.
- [ ] localization language scope may remain TBD but pipeline assumptions may not block localization.
- [ ] QA evidence taxonomy references deterministic, persistence, performance, accessibility, fresh-checkout, and human-play proof separately.
- [ ] platform certification remains explicitly gated by platform selection.

**Pass condition:** accessibility/localization are production inputs, not late polish assumptions.

---

# 14. Runtime-gated items that must **not** be faked on paper

The following may remain `RUNTIME-GATED` at studio handoff if the evidence path is explicit:

- exact movement speed/acceleration values;
- exact camera distance/lag/collision recovery values;
- exact combat windows/damage/balance;
- exact Hush transition duration;
- Hush production representation selection where comparative UE evidence is required;
- exact target-hardware performance budgets before target selection/runtime profiling;
- Line Skiff handling/camera values;
- exact Null Meridian room dimensions/pacing;
- final boss timings;
- final loading/memory/save performance;
- human judgments such as fun, clarity, emotional impact, musical impact.

A studio handoff package must say **how these will be decided**, not pretend they are already known.

---

# 15. Chat-history independence audit

Before final acceptance, select a reviewer/agent who has not relied on project conversation history and ask them to answer from repository authority only:

1. What is Stillring?
2. What are its hard product constraints?
3. What does the player do minute to minute?
4. What is the region/world structure?
5. What does each major production discipline need to build?
6. What content volume exists?
7. What can the studio decide without owner approval?
8. What must the studio not change?
9. What is still intentionally TBD?
10. What is runtime-gated?
11. What would they need to quote/staff the game?
12. Which files are the safe starting point for each discipline?

Any answer that depends on “I remember the owner saying in chat…” is a handoff failure.

This audit is documentation review, not gameplay testing.

---

# 16. Final status categories

The final audit should conclude with exactly one repository-wide handoff status:

## NOT HANDOFF READY

Major production disciplines still depend on hidden intent or undocumented assumptions.

## HANDOFF READY FOR PRE-PRODUCTION

Studio can safely estimate, prototype, and build vertical-slice plans, but important product/production decisions remain intentionally gated.

## HANDOFF READY FOR FULL PRODUCTION

Studio can staff and execute the full game from repository authority, with only explicitly scheduled owner decisions and runtime-tuning gates remaining.

## SHIP/PORT READY

Not applicable until actual implementation, production evidence, target platforms, and certification work exist.

The current project status at creation of this checklist is:

> **NOT YET FULL-PRODUCTION HANDOFF READY.**

The purpose of docs 151–153 and their follow-on production bibles/manifests is to change that without prematurely implementing or testing the game.
