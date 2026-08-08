# Function record: Client_FrameTick_EnvDayCycleAndSystems_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00942e20` |
| **Canonical name** | `Client_FrameTick_EnvDayCycleAndSystems_Inferred` |
| **Ghidra symbol** | `FUN_00942e20` |
| **Address** | `0x00942e20`–`0x009430f0` exclusive (**720 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client frame / environment day-cycle parent |
| **Completion status** | **Dual sealed (WQ9H-G)** — accept-with-gaps; Terminal false |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Main-client per-frame tick (sole callee of `FUN_0094b520` under profile bucket 1). Clamps frame dt to 0.2f, applies dualed env day-cycle sky blend when `host+0xe04` world root is live (ECX = env at worldRoot`+0xe894`), then runs fog material push, system helpers, pending-list drain, primary-object tick, and a one-shot `"All load time"` debug print.

## Signature

```c
// EDI = client/session host (register this); no stack args; bare RET
uint32_t Client_FrameTick_EnvDayCycleAndSystems_Inferred(void);
// returns 0 success; 1 if gate FUN_0092e510 fails
```

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00942e20_FUN_00942e20.md`
- Annotated: `docs/reconstruction/raw/aa_00942e20_FUN_00942e20.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Client_FrameTick_EnvDayCycleAndSystems_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00942e20.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00942e20_Client_FrameTick_EnvDayCycleAndSystems_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00942e20_Client_FrameTick_EnvDayCycleAndSystems_Inferred.md`
- Scaffold alias: `docs/reconstruction/functions/aa_00942e20_FUN_00942e20.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller (1) | `FUN_0094b520` @ `0x0094b865` | main frame path |
| Callee | `Env_DayCycle_ApplySkyBlendAndLight_Inferred` (`0x004912c0`) | dualed WQ9G-F; ECX=env; push dt |
| Callee | `FUN_00942840`, `FUN_00931a50`, `FUN_007a2e50`, `FUN_009307b0`, … | undualed system ticks |
| Callee | `FUN_00442640` | `fFogHeight` material param |
| Callee | sprintf / OutputDebugStringA | load-time one-shot |

## Constants

| Symbol | Value |
|---|---|
| `DAT_00a0f70c` | 0.2f dt clamp |
| `DAT_00af9120` | 0.01f fog height scale |
| `DAT_00af911c` | 1.0f fFogHeight |

## Confidence

| Claim | Level |
|---|---|
| Body size + bare RET + EDI=host | **Confirmed** (bytes + disasm) |
| Parent of dualed sky blend at `004912c0` | **Confirmed** |
| dt clamp 0.2f; fog scale 0.01f | **Confirmed** (read_memory) |
| Product host class English | **Tentative** (`_Inferred`) |
| Undualed helper semantics | **Open** |
