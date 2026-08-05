# Function record: Math_CopyFloat4_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e96e0` |
| **Canonical name** | `Math_CopyFloat4_Inferred` |
| **Ghidra name** | `FUN_004e96e0` |
| **Address** | `0x004e96e0` |
| **Body range** | `0x004e96e0`–`0x004e9715` (54 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared math leaf (FX / vehicle / hardpoint / AI) |
| **Completion status** | **partial** — dual A/B **accept**; CF + SSE bytes sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004e96e0_Math_CopyFloat4_Inferred.md`, `reviews/B_aa_004e96e0_Math_CopyFloat4_Inferred.md` (2026-07-29 W17-O) |
| **Last reviewed** | `2026-07-29` |

## Purpose

Copy `float[4]` from src → dst via SSE `movss` (all four components including W). Leaf. Not a normalizer, quat, or transform.

## Signature

```c
float *Math_CopyFloat4_Inferred(float *dst, const float *src);  // cdecl; EAX = dst*
```

## Algorithm

1. Load src.w, src.x, src.y, src.z into XMM regs (`movss`).
2. Store to dst.x, dst.y, dst.z, dst.w.
3. Return `dst*` in EAX (leftover from load of `[ebp+8]`).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004e96e0_FUN_004e96e0.md`
- Annotated: `docs/reconstruction/raw/aa_004e96e0_FUN_004e96e0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Math_CopyFloat4_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_004e96e0.cpp`
- Parent-seed alias: `Named_CalleeOf_CVOGPlayerVehicle_UpdateTurretAiming_004e96e0.cpp` (prefer Math name)
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004e96e0-math-copyfloat4-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none (leaf) |
| **Callers (sample)** | `CVOGPlayerVehicle_UpdateTurretAiming` (`0x004f9570`), `FUN_004b70f0`, `FUN_004b75d0`, `FUN_004fa0f0`, `FUN_004fc010`, `FUN_00500560`, `FUN_005911b0`, `FUN_005942d0`, `FUN_00595230`, `FUN_005a75f0`, `FUN_005a8650`, `FUN_005f44c0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + SSE bytes | **High** |
| Full float4 (W from src) | **High** |
| cdecl stack args + EAX=dst* | **High** |
| Not normalize | **High** |
| Product English name | **Inferred** |
| Runtime / bit-exact | Open |

## Related

- `aa_004e9530` Math_CopyFloat3ToFloat4_Inferred (xyz only; dirty W)
