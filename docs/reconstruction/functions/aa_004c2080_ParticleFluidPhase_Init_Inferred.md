# Function record: ParticleFluidPhase_Init_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c2080` |
| **Canonical name** | `ParticleFluidPhase_Init_Inferred` |
| **Ghidra name** | `FUN_004c2080` |
| **Address** | `0x004c2080` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / particle fluid phase |
| **Wave** | W33-S OWN-ONLY dual |
| **Completion status** | **Reviewed** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Enable/init method for the fluid-particle phase object (`FUN_004c0640`, size 0xC8, env+0xCC). Structural name from nested `CreateFluidParticles` / `NDParticleFluid*.fx` evidence and InitPhases wiring pattern shared with `FUN_0055cc50` / `FUN_005b39a0`.

## Signature

```c
uint32_t __thiscall ParticleFluidPhase_Init_Inferred(void *phase, uint32_t flags);
```

## Artifacts

See `aa_004c2080_FUN_004c2080.md` for full paths. Twin clean: `ParticleFluidPhase_Init_Inferred.cpp`.

## Related

- Ctor: `FUN_004c0640` (HostBase via `FUN_007560d0`, vtbl `PTR_FUN_009cb62c`)
- Parent orchestrator: `PalantirEnv_InitPhases_Inferred` (`0x0048fc90`, W31-P)
- Ensure: `HostBase_EnsureAuxPtrs_Inferred` (`0x00756320`, W32-Q)
- Small aux ctor: `HostAux14_Ctor_Inferred` (`0x00442c80`, this dual) via Ensure path
- Sibling enables: `FUN_0055cc50`, `FUN_005b39a0` (W33-T)
