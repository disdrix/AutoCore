# Function record: ParticleFluidPhase_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c0640` |
| **Canonical name** | `ParticleFluidPhase_Ctor_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_004c0640` |
| **Address** | `0x004c0640`–`0x004c0706` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / particle fluid phase |
| **Wave** | W34-M OWN-ONLY dual |
| **Completion status** | **Reviewed** — dual A/B **accept** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Ctor for the fluid-particle phase object (`new(0xC8)`, env+0xCC). Structural name from peer `ParticleFluidPhase_Init_Inferred` (W33-S) and InitPhases wiring.

## Signature

```c
void* __thiscall ParticleFluidPhase_Ctor_Inferred(void *self, void *parent);
```

## Artifacts

See `aa_004c0640_FUN_004c0640.md` for full paths. Twin clean: `ParticleFluidPhase_Ctor_Inferred.cpp`.

## Related

- Base: `HostBase_DefaultCtor_Inferred` (`0x007560d0`, W32-O)
- Init method: `ParticleFluidPhase_Init_Inferred` (`0x004c2080`, W33-S)
- Parent orchestrator: `PalantirEnv_InitPhases_Inferred` (`0x0048fc90`, W31-P)
- Ensure path: `HostBase_EnsureAuxPtrs_Inferred` (`0x00756320`, W32-Q)
- Global: `DAT_00b03790`
