# Function record: VOGEnvironmentLiquid_InitFilterPipeline_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c0fe0` |
| **Canonical name** | `VOGEnvironmentLiquid_InitFilterPipeline_Inferred` |
| **Ghidra name** | `FUN_004c0fe0` |
| **Address** | `0x004c0fe0` |
| **Body range** | `0x004c0fe0`–`0x004c16cf` inclusive (**1776 B** / `0x6F0`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / VOGEnvironmentLiquid |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** (W37-F) |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | A/B reviews under `docs/reconstruction/reviews/` |
| **Last reviewed** | `2026-08-04` |

## Purpose

Post-ctor initializer for the particle-fluid **liquid child** (`0x40`): build the UIFluid filter effect chain and cascaded render-target pyramid used by `VOGEnvironmentLiquid` presentation.

## Signature

```c
uint32_t __thiscall VOGEnvironmentLiquid_InitFilterPipeline_Inferred(void* liquid_child);
// returns 0
```

## Lifecycle position

```
ParticleFluidPhase_CreateLiquidChild (0x004c1960)
  new(0x40) → FUN_004c1800(phase)
  phase+0xc4 = child
  → VOGEnvironmentLiquid_InitFilterPipeline_Inferred(child)   // this unit
  → activate if child+0x10 != 1
```

## Artifacts

See scaffold record `aa_004c0fe0_FUN_004c0fe0.md` for full paths.
