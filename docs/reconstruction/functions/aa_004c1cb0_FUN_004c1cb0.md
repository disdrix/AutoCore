# Function record: FUN_004c1cb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c1cb0` |
| **Canonical name** | `FUN_004c1cb0` |
| **Named** | `ParticleFluidPhase_CreateFluidParticles_Inferred` |
| **Address** | `0x004c1cb0`–`0x004c207c` exclusive (**972 B** / `0x3CC`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / particle fluid phase |
| **Completion status** | **Dual sealed W34-N** — trio + A/B present |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `ParticleFluidPhase_CreateFluidParticles_Inferred` (**primary named**; product log stem)
- `Gfx_NDParticleFluid` (registry / FX plate)

## Alias_prev

- `Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx_004c1cb0` — **reject**

## Purpose

`CreateFluidParticles(capacity)`: allocate particle array, view/mesh children, bind `NDParticleFluid.fx` / `Particles.dds`, build VB/IB for fluid particle rendering. Factory capacity **32767** (`0x7FFF`).

## Signature

```c
void __thiscall FUN_004c1cb0(void *phase, int capacity); // RET 4
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004c1cb0_FUN_004c1cb0.md`
- Annotated: `docs/reconstruction/raw/aa_004c1cb0_FUN_004c1cb0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/ParticleFluidPhase_CreateFluidParticles_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004c1cb0.cpp`
- Function named: `docs/reconstruction/functions/aa_004c1cb0_ParticleFluidPhase_CreateFluidParticles_Inferred.md`
- A/B: `docs/reconstruction/reviews/A_aa_004c1cb0_ParticleFluidPhase_CreateFluidParticles_Inferred.md`, `B_aa_004c1cb0_ParticleFluidPhase_CreateFluidParticles_Inferred.md`

## Callers / callees

| Role | Targets |
|---|---|
| Callers (1) | `FUN_004c2080` (`ParticleFluidPhase_Init_Inferred`) @ `0x004c209b` (`push 0x7fff`) |
| Callees | see annotated / analyze_function_complete (alloc, view/mesh ctors, FX bind, VB/IB, log) |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ live | **High** |
| thiscall + capacity stack + RET 4 | **High** (bytes) |
| Product CreateFluidParticles name | **High** (log strings) |
| Nested mesh/view product English | **Low** / residual |
| Capacity product tunability | **Medium** (factory hardcode only sealed) |
