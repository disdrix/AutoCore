# Function record: ParticleFluidPhase_InitFluidBumpChild_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c0a90` |
| **Canonical name** | `ParticleFluidPhase_InitFluidBumpChild_Inferred` |
| **Ghidra name** | `FUN_004c0a90` |
| **Address** | `0x004c0a90`–`0x004c0c41` exclusive (**433 B** / `0x1B1`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / particle fluid phase |
| **Wave** | W34-N OWN-ONLY dual |
| **Completion status** | **Dual sealed** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Phase helper: construct and wire the fluid-bump normal-map render child used by `ParticleFluidPhase_Init` before `CreateFluidParticles`.

## Signature

```c
void __fastcall ParticleFluidPhase_InitFluidBumpChild_Inferred(void *phase);
```

## Classification

worker (sole static caller = phase Init).

## Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c0a90_ParticleFluidPhase_InitFluidBumpChild_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004c0a90_ParticleFluidPhase_InitFluidBumpChild_Inferred.md` | **accept-with-gaps** |

## Related

- Parent: `ParticleFluidPhase_Init_Inferred` (`0x004c2080`, W33-S)
- Peer: `ParticleFluidPhase_CreateFluidParticles_Inferred` (`0x004c1cb0`, this dual)
- Nested: `GfxView_SetNear_Inferred` (`0x0075b3b0`, W31-O); far twin `FUN_0075b390`; child ctor residual `FUN_00968a50`
