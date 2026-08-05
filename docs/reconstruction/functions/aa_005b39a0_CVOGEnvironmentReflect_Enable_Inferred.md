# Function record: CVOGEnvironmentReflect_Enable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b39a0` |
| **Canonical name** | `CVOGEnvironmentReflect_Enable_Inferred` |
| **Ghidra name** | `FUN_005b39a0` |
| **Address** | `0x005b39a0` |
| **Body range** | `0x005b39a0`–`0x005b39c1` exclusive (**33 B** / `0x21`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / VOGEnvironmentSector phases |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF/ABI/sole caller/host RTTI sealed; nested resolve/alloc product English residual |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005b39a0_CVOGEnvironmentReflect_Enable_Inferred.md`, `reviews/B_aa_005b39a0_CVOGEnvironmentReflect_Enable_Inferred.md` (2026-07-29 W33-T) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_005b39a0`
- `Named_CalleeOf_Drive_NDRiver_fx_005b39a0` (**reject** — InitPhases tail string is NDRiver; this unit is owned EnvironmentReflect enable)
- Host class RTTI: `CVOGEnvironmentReflect` (**Confirmed** W32-T)

## Purpose

Post-ctor **enable** for the owned **EnvironmentReflect** phase host:

1. `HostBase_EnsureAuxPtrs_Inferred(this, flag)`
2. `FUN_005b3520(this)` — resolve nested fog/light slots into `+0x150`/`+0x154` when empty
3. `FUN_005b3420(this)` — alloc/bind fog child host @ `+0x158` (size 0x198)
4. Return **0**

Factory (`PalantirEnv_InitPhases`): always `new(0x170)` + `CVOGEnvironmentReflect_ctor(parent@+0xB8)` → env`+0xC4`; then **this(1)**.

## Signature

```c
uint32_t __thiscall CVOGEnvironmentReflect_Enable_Inferred(
    CVOGEnvironmentReflect* this,
    uint32_t flag);   // factory constant 1
// ret 4; returns 0
```

## Algorithm

```
esi = this
HostBase_EnsureAuxPtrs_Inferred(this, flag)
FUN_005b3520(this)
FUN_005b3420(this)
return 0
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005b39a0_FUN_005b39a0.md`
- Annotated: `docs/reconstruction/raw/aa_005b39a0_FUN_005b39a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGEnvironmentReflect_Enable_Inferred.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_005b39a0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_005b39a0_FUN_005b39a0.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0055cc50-005b39a0-w33t-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Callee | `0x00756320` | `HostBase_EnsureAuxPtrs_Inferred` |
| Callee | `0x005b3520` | nested fog slot resolve (residual) |
| Callee | `0x005b3420` | fog child alloc @ `+0x158` (residual) |
| Caller | `0x0048fc90` @ `0x0048fdde` | `PalantirEnv_InitPhases_Inferred` (sole) |
| Related | `0x005b35a0` | host complete ctor (size 0x170, W32-T) |
| Related | `0x005b36f0` | apply vtbl[1] (`Env_ApplyFogShaderAndReflect_Inferred`, W29-I) |
| Peer enable | `0x0055cc50` | Distort enable; `0x004c2080` third owned phase |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes + `ret 4` + return 0 | **Confirmed** |
| thiscall + 1 stack flag formal | **Confirmed** |
| Host class = `CVOGEnvironmentReflect` | **Confirmed** |
| Sole factory caller + alloc 0x170 → env`+0xC4` | **Confirmed** |
| Nested workers product English | **Open** |
| Flag product meaning | **Open** (factory 1 sealed) |
