# Function record: ParticleFluidPhase_CreateLiquidChild_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c1960` |
| **Canonical name** | `ParticleFluidPhase_CreateLiquidChild_Inferred` |
| **Ghidra name** | `FUN_004c1960` |
| **Address** | `0x004c1960` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / particle fluid phase / env liquid |
| **Wave** | W34-O OWN-ONLY dual |
| **Completion status** | **Reviewed** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Install the secondary liquid-environment child used by the fluid-particle phase host (`FUN_004c0640`, env+0xCC):

1. Allocate **0x40** bytes and construct via `FUN_004c1800(self, parent_phase)`.
2. Write pointer to **`phase+0xc4`**.
3. Run nested liquid filter/RT initializer `FUN_004c0fe0` (strings: `UIFluidDownsample.fx`, `UIFluidBlurHorizontal.fx`, `UIFluidBlurVertical.fx`, `UIFluidSurfaceBlend.fx`; source path `VOGEnvironmentLiquid.cpp`).
4. If `child+0x10 != 1`, activate via `FUN_0075bf40(0)` + `FUN_007567b0(child+0x38, 0)` and set the flag.

Structural name from parent dual W33-S residual (“child @ +0xc4 (0x40)”) plus liquid FX evidence in nested free. **Reject** NDRiver.fx scaffold naming.

## Signature

```c
void __fastcall ParticleFluidPhase_CreateLiquidChild_Inferred(void *phase /*ECX*/);
```

## Artifacts

See `aa_004c1960_FUN_004c1960.md` for full paths. Twin clean: `ParticleFluidPhase_CreateLiquidChild_Inferred.cpp`.

## Related

- Parent init: `ParticleFluidPhase_Init_Inferred` (`0x004c2080`, W33-S)
- Blend rebind: `FUN_004c1a10` / `Gfx_NDParticleFluidBlendNormal_004c1a10` (deletes prior +0xc4 then recreates)
- Nested free: ctor `FUN_004c1800`; liquid init `FUN_004c0fe0`; activate helpers `FUN_0075bf40` / `FUN_007567b0`
