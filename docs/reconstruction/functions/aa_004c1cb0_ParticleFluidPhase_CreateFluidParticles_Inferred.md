# Function record: ParticleFluidPhase_CreateFluidParticles_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c1cb0` |
| **Canonical name** | `ParticleFluidPhase_CreateFluidParticles_Inferred` |
| **Ghidra name** | `FUN_004c1cb0` |
| **Address** | `0x004c1cb0`–`0x004c207c` exclusive (**972 B** / `0x3CC`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / particle fluid phase |
| **Wave** | W34-N OWN-ONLY dual |
| **Completion status** | **Dual sealed** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Product `CreateFluidParticles(capacity)` on the fluid phase host: particle buffer + FX/mesh bring-up for the env fluid particle system.

## Signature

```c
void __thiscall ParticleFluidPhase_CreateFluidParticles_Inferred(void *phase, int capacity);
```

## Classification

worker (sole static caller = phase Init with capacity 0x7FFF).

## Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c1cb0_ParticleFluidPhase_CreateFluidParticles_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004c1cb0_ParticleFluidPhase_CreateFluidParticles_Inferred.md` | **accept-with-gaps** |

## Related

- Parent: `ParticleFluidPhase_Init_Inferred` (`0x004c2080`, W33-S)
- Peer: `ParticleFluidPhase_InitFluidBumpChild_Inferred` (`0x004c0a90`, this dual) — supplies `+0x94` normal map
- Secondary child residual: `FUN_004c1960` (W34-O)
