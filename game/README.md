# Unreal project root

This directory is intentionally skeletal until Gate 1 bootstrap.

Project Stillring's production engine is **Unreal Engine 5.8**.

Claude is the primary implementation agent. The first executable milestone is Gate 1 from `../ROADMAP.md`: bootstrap the minimal C++ Unreal project and prove movement/camera in a graybox test map.

Do **not** generate production-scale world content yet.

The bootstrap should create only what Gate 1 requires, including:
- `Stillring.uproject`;
- minimal C++ module/target files;
- Enhanced Input baseline;
- graybox movement/camera test map;
- minimal debug/performance readout;
- reproducible build/editor-load/Automation entry points.

Authoritative gameplay/state is C++ first. Blueprints stay thin and presentation-oriented unless a scoped prototype explicitly authorizes otherwise.

Do not use the stock Third Person template as silent game design. Template assets/settings may be studied or temporarily used for bootstrapping only when they are deliberately replaced or reconciled with Stillring's specifications.