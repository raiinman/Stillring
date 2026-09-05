# Unreal project root

Project Stillring's production engine is **Unreal Engine 5.8**.

Gate 1 source bootstrap has begun. This directory now contains:
- `Stillring.uproject`;
- minimal Runtime and Editor targets;
- the authoritative `Stillring` C++ runtime module;
- a development-only `StillringDev` module;
- the first shared System IDE registry/provenance contract;
- a source-level Automation smoke test for System IDE registration;
- `BUILDING.md` with the required UE-hosted verification path.

**Important:** this source scaffold has not yet been compiled or opened in Unreal Engine 5.8 in the current authoring environment. Treat it as implementation progress, not verification evidence.

Claude is the primary implementation agent. The first executable milestone remains Gate 1 from `../ROADMAP.md`: prove movement/camera in a graybox test map while growing the in-game System IDE alongside those systems.

Do **not** generate production-scale world content yet.

Still required before Issue #5 can close:
- UE 5.8 compile/editor-load proof;
- Enhanced Input assets/mapping contexts appropriate to the approved input semantics;
- graybox movement/camera test map;
- reset/reload plus runtime coordinates/state/performance readout;
- reproducible executed Automation/smoke path;
- explicit binary asset evidence for any `.uasset`/`.umap` changes.

Authoritative gameplay/state is C++ first. Blueprints stay thin and presentation-oriented unless a scoped prototype explicitly authorizes otherwise.

Do not use the stock Third Person template as silent game design. Template assets/settings may be studied or temporarily used for bootstrapping only when they are deliberately replaced or reconciled with Stillring's specifications.

System IDE authority: `../docs/21_IN_GAME_SYSTEM_IDE_CONTRACT.md`.
Implementation boundary/readiness: `../docs/28_GATE1_IMPLEMENTATION_READINESS_PLAN.md`.
