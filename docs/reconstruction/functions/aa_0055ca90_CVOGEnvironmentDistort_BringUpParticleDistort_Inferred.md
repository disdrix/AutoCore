# Function record: CVOGEnvironmentDistort_BringUpParticleDistort_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055ca90` |
| **Canonical name** | `CVOGEnvironmentDistort_BringUpParticleDistort_Inferred` |
| **Address** | `0x0055ca90`–`0x0055cc42` (**434 B** / `0x1B2`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / VOGEnvironmentSector / CVOGEnvironmentDistort |
| **Completion status** | **Dual A/B present** (2026-08-04 W37-J) — accept-with-gaps |
| **Name status** | Host RTTI + product strings; `_Inferred` method English |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|---|---|
| `FUN_0055ca90` | Ghidra scaffold |
| `Gfx_NDParticleDistortBlendNormal` | **Reject** as sole id (incomplete) |
| `Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx_0055ca90` | **Reject** |

## Purpose

Bring up the particle-distort child under `CVOGEnvironmentDistort`: allocate 0x198 particle object at host`+0x90`, set 0.2f/500.f/color params, vcall init, bind `Particle_Distort.dds` + `NDParticleDistortBlendNormal.fx` + `NormalMapTexture`.

## Signature

```c
void __thiscall CVOGEnvironmentDistort_BringUpParticleDistort_Inferred(
    CVOGEnvironmentDistort *this); // SEH; plain ret
```

## Callers / callees

| Direction | Symbol | VA / note |
|---|---|---|
| Caller | `CVOGEnvironmentDistort_Enable_Inferred` | `0x0055cc5f` (sole) |
| Callee | `operator_new` / `FUN_00968a50` | 0x198 particle |
| Callee | `FUN_0075b3b0` / `0075b390` / `0075bf40` / `0075b450` | params |
| Callee | `FUN_0096ef70`…`0096efd0` + `00989e00` | tex/fx bind |
| Callee | child vtbl[+0x18] | snapshot init |

## Family

| Sibling | Role |
|---|---|
| `CVOGEnvironmentDistort_Enable_Inferred` `0x0055cc50` | enable wrapper (W33-T) |
| ctor `FUN_0055c8c0` | host size 0xA0 |
| `FUN_005b3420` | Reflect peer child bring-up |
| `FUN_00968a50` | particle ctor (W37-I) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0055ca90_FUN_0055ca90.md`
- Annotated: `docs/reconstruction/raw/aa_0055ca90_FUN_0055ca90.annotated.md`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_0055ca90.cpp`
- Clean named: `docs/reconstruction/reconstructed-exact/CVOGEnvironmentDistort_BringUpParticleDistort_Inferred.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0055ca90_CVOGEnvironmentDistort_BringUpParticleDistort_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0055ca90_CVOGEnvironmentDistort_BringUpParticleDistort_Inferred.md`
- FUN_ record: `docs/reconstruction/functions/aa_0055ca90_FUN_0055ca90.md`
- Dual report: `docs/agents/task-dual-ab-004e2bd0-0055ca90-w37j-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF alloc/params/FX/mirror | **Confirmed** |
| `__thiscall` void SEH | **Confirmed** |
| Product strings | **Confirmed** |
| Sole Enable caller | **Confirmed** |
| Host class CVOGEnvironmentDistort | **High** (via enable/ctor RTTI) |
| Child class product English | **Open** |
| Runtime / bit-exact / diff | **Open** |
