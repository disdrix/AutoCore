# Function record: FUN_005bc3c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bc3c0` |
| **Canonical name** | `Emitter_UpdateTick_Inferred` (preferred) |
| **Ghidra name** | `FUN_005bc3c0` |
| **Address** | `0x005bc3c0`–`0x005bdce6` exclusive (**6438** B / `0x1926`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client::fx / emitter |
| **Completion status** | **Sealed** — dual A/B W28-I 2026-07-29; **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

Preferred: `Emitter_UpdateTick_Inferred`.  
Legacy scaffold: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_005bc3c0` — **reject** as product claim.

## Purpose

Full per-frame emitter update for NDSpecialFX HostTick list `+0x1E0`: timers, pose refresh (object / skybox / attachment), motion integration, optional interval spawn via `Emitter_SpawnOnIntervalTick_Inferred`. Returns keep polarity for list management.

## Signature (decompiler-derived, W28-I sealed)

```c
undefined4 __thiscall FUN_005bc3c0(int *emitter, float *dt, int host_field_2c, int camera_or_world);
// ret 0x0C; 0=remove, 1=keep
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005bc3c0_FUN_005bc3c0.md`
- Annotated: `docs/reconstruction/raw/aa_005bc3c0_FUN_005bc3c0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Emitter_UpdateTick_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005bc3c0.cpp`
- Named record: `docs/reconstruction/functions/aa_005bc3c0_Emitter_UpdateTick_Inferred.md`

## Callers / callees (selected)

| Direction | Target | Notes |
|---|---|---|
| Caller (1) | `FUN_004b8ed0` @ `0x004b90ef` | `NDSpecialFX_HostTick_Inferred` |
| Callee | `FUN_005bc120` | `Emitter_SpawnOnIntervalTick_Inferred` |
| Callee | `FUN_005b83e0` | pose/ring helper |
| Callee | `FUN_005bb1f0` / `FUN_005bb1d0` | motion helpers |
| Callee | `004e88*` family | quat/basis extract |
| Callee | `FUN_007a4480` | emitter zero-pos log |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| Keep polarity / ABI ret 0x0C | **High** |
| Parameter semantic names | **Probable** (`_Inferred`) |
| Full nested type recovery | **Tentative** / open |
