# Stillring Unreal Gate 1 — Build / Validation Entry Points

**Status:** SOURCE SCAFFOLD ONLY — UNVERIFIED IN UNREAL ENGINE 5.8  
**Updated:** 2026-09-05

This repository now contains the initial source-only Unreal Engine 5.8 Gate 1 project scaffold. The current environment used to author this commit does **not** provide an Unreal Engine 5.8 installation, so none of the commands below have been claimed as passing yet.

## Required environment
- Unreal Engine 5.8 installed or source-built.
- Platform compiler/toolchain required by that Unreal installation.
- Git LFS available before checking out binary Unreal assets later.

Set `UE_ROOT` below to the Unreal Engine root directory containing `Engine/`.

## Generate project files
Typical platform-specific project generation should target:

```text
<UE_ROOT>/Engine/Build/BatchFiles/GenerateProjectFiles.* -project=<repo>/game/Stillring.uproject -game -engine
```

Exact script extension/shell invocation depends on the host platform and Unreal distribution.

## Development Editor build
The first required proof is a Development Editor build of the `StillringEditor` target for the host platform using Unreal Build Tool / the platform wrapper supplied by UE 5.8.

Expected target:

```text
StillringEditor Development <HostPlatform> -Project=<repo>/game/Stillring.uproject
```

Do not mark Issue #5's reproducible-build criterion complete until the exact command used on the real UE 5.8 host is captured here with its result.

## Editor load
After the editor target builds, launch the project directly from:

```text
game/Stillring.uproject
```

Current scaffold contains no production map and no Gate 1 `.umap` yet. A successful editor launch is therefore a project/module-load proof only.

## Automation smoke
The source scaffold defines this development automation test:

```text
Stillring.Gate1.SystemIDE.Registry
```

Once UE 5.8 can build the editor target, run that test through Unreal's normal Automation command-line or Session Frontend path and record the exact verified command/result here.

The test currently checks:
- a System IDE workbench can register;
- duplicate workbench IDs are rejected;
- registered workbenches are discoverable;
- unregister removes the workbench.

## Verification status

| Check | Status |
|---|---|
| `.uproject` source review | PRESENT |
| Runtime module source | PRESENT |
| Development-tool module source | PRESENT |
| Enhanced Input plugin declaration | PRESENT |
| System IDE registry source | PRESENT |
| System IDE automation smoke source | PRESENT |
| UE 5.8 target compile | **NOT RUN** |
| Editor project load | **NOT RUN** |
| Automation smoke execution | **NOT RUN** |
| Graybox `.umap` load | **NOT CREATED / NOT RUN** |
| Shipping exclusion proof | **NOT RUN** |

A later UE-hosted verification pass must fix any compile/API mismatch instead of treating this document as proof that the scaffold builds.
