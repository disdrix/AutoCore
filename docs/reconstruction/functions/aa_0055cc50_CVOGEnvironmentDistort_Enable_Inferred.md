# Function record: CVOGEnvironmentDistort_Enable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055cc50` |
| **Canonical name** | `CVOGEnvironmentDistort_Enable_Inferred` |
| **Ghidra name** | `FUN_0055cc50` |
| **Address** | `0x0055cc50` |
| **Body range** | `0x0055cc50`–`0x0055cc6a` exclusive (**26 B** / `0x1A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / VOGEnvironmentSector phases |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF/ABI/sole caller/host RTTI sealed; nested `0055ca90` product English residual |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0055cc50_CVOGEnvironmentDistort_Enable_Inferred.md`, `reviews/B_aa_0055cc50_CVOGEnvironmentDistort_Enable_Inferred.md` (2026-07-29 W33-T) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_0055cc50`
- `Named_CalleeOf_Drive_NDRiver_fx_0055cc50` (**reject** — InitPhases tail string is NDRiver; this unit is owned EnvironmentDistort enable)
- Host class RTTI: `CVOGEnvironmentDistort` (**Confirmed** via ctor vtbl COL)

## Purpose

Post-ctor **enable** for the owned **EnvironmentDistort** phase host:

1. `HostBase_EnsureAuxPtrs_Inferred(this, flag)` — ensure host aux slots (`FUN_00756320`)
2. `FUN_0055ca90(this)` — bring up particle-distort child (alloc 0x198 @ `+0x90`, load `Particle_Distort.dds` / `NDParticleDistortBlendNormal.fx`)
3. Return **0**

Factory (`PalantirEnv_InitPhases`): always `new(0xA0)` + `FUN_0055c8c0(parent)` → env`+0xC8`; then **this(1)**.

## Signature

```c
uint32_t __thiscall CVOGEnvironmentDistort_Enable_Inferred(
    CVOGEnvironmentDistort* this,
    uint32_t flag);   // factory constant 1
// ret 4; returns 0
```

## Algorithm

```
esi = this
HostBase_EnsureAuxPtrs_Inferred(this, flag)
FUN_0055ca90(this)
return 0
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0055cc50_FUN_0055cc50.md`
- Annotated: `docs/reconstruction/raw/aa_0055cc50_FUN_0055cc50.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGEnvironmentDistort_Enable_Inferred.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_0055cc50.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0055cc50_FUN_0055cc50.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0055cc50-005b39a0-w33t-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Callee | `0x00756320` | `HostBase_EnsureAuxPtrs_Inferred` |
| Callee | `0x0055ca90` | particle-distort child bring-up (residual) |
| Caller | `0x0048fc90` @ `0x0048fe20` | `PalantirEnv_InitPhases_Inferred` (sole) |
| Related | `0x0055c8c0` | host complete ctor (size 0xA0) |
| Peer enable | `0x005b39a0` | Reflect enable; `0x004c2080` third owned phase |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes + `ret 4` + return 0 | **Confirmed** |
| thiscall + 1 stack flag formal | **Confirmed** |
| Host class = `CVOGEnvironmentDistort` | **Confirmed** (RTTI via ctor) |
| Sole factory caller + alloc 0xA0 → env`+0xC8` | **Confirmed** |
| Nested `0055ca90` product English | **Open** |
| Flag product meaning | **Open** (factory 1 sealed) |
