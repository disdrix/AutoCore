# Function record: Client_Camera_DefaultModeUpdate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009168d0` |
| **Canonical name** | `Client_Camera_DefaultModeUpdate_Inferred` |
| **Ghidra name** | `FUN_009168d0` |
| **Address** | `0x009168d0` |
| **Body span** | `009168d0`–`00917603` (**3379** B / `0xD33`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client camera / default mode update |
| **Convention** | MSVC stdcall `RET 0x14` (5 stack dwords) |
| **Completion status** | **partial** — three-rep + dual A/B sealed 2026-07-29; runtime/diff open |
| **Dual verdict** | **accept-with-gaps** (A+B) |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|------|--------|
| `FUN_009168d0` | Ghidra auto / prior scaffold |
| `Client_Camera_DefaultModeUpdate_Inferred` | **Canonical** (this dual) |

## Purpose

**Default camera-mode** world update: place the chase/orbit eye relative to a focus point using yaw (`cam+0xcc8`) and range args, optional look-yaw integration, construct a look basis, **collision-pull** the eye using eight map segment probes (`Client_Map_RaySegmentHitDistance_Inferred`), commit eye position to the camera bus (`DAT_00d17944+0x228..`), and write a look direction (gamepad path or basis/globals fallback).

Sole caller is `FUN_0091ce80` **default** arm of the mode switch (modes 1/2/3/5/7/8 go elsewhere).

## Signature

```c
// stdcall; RET 0x14
void Client_Camera_DefaultModeUpdate_Inferred(
    int *cam,
    float *focus_xyz,
    float range_a,
    float range_b,
    float dt_or_scale);
```

## Algorithm (summary)

```
aim = focus + yawBasis(cam) * ranges
optional: accumulate look-yaw into cam+0x538
build orthonormal look basis (normalize + cross)
eye0 = focus + yaw * cam+0x530 * basis
loop:
  for i in 0..7:
    p = probeOffset(cam, i)           // FUN_00915ad0
    d = MapRaySegmentHitDistance(eye, p)  // FUN_00916090
    track best pull
  if no improvement: break
  step eye toward focus by (pull - eps)
commit eye to DAT_00d17944+0x228.. (integrate or snap)
optional ground Y tweak on focus
write look dir to client look slot (+0x170) via gamepad or basis/globals
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_009168d0_FUN_009168d0.md`
- Annotated: `docs/reconstruction/raw/aa_009168d0_FUN_009168d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_009168d0.cpp`
- Named: `docs/reconstruction/reconstructed-exact/Client_Camera_DefaultModeUpdate_Inferred.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_009168d0_FUN_009168d0.md`
- Review A: `docs/reconstruction/reviews/A_aa_009168d0_Client_Camera_DefaultModeUpdate_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_009168d0_Client_Camera_DefaultModeUpdate_Inferred.md`
- Report: `docs/agents/task-dual-ab-own-w24d-009168d0-004b7030-report.md`
- Collision helper dual: `aa_00916090_Client_Map_RaySegmentHitDistance_Inferred` (W23-O)

## Callers / callees

| Dir | VA | Name |
|---|---|---|
| Caller | `0x0091ce80` | camera mode dispatcher (default arm) |
| Callee | `0x00916090` | `Client_Map_RaySegmentHitDistance_Inferred` |
| Callee | `0x00915ad0` | 8-way probe offset builder |
| Callee | `0x0076f5f0` | normalize float3 |
| Callee | `0x004e8a40` | `Math_QuatExtractForwardZ` |
| Callee | `0x004e8ad0` | quat basis extract |
| Callee | `0x004e88e0` | float3 helper/copy |

## Confidence

| Claim | Level |
|---|---|
| Body span + `ret 0x14` stdcall | **Confirmed** (bytes) |
| Sole caller default mode arm | **High** |
| Orbit aim + basis + 8-probe pull CF | **High** |
| Uses dualed map hit-distance helper | **Confirmed** |
| Eye commit to `DAT_00d17944+0x228..` | **High** |
| Product method / mode enum English | **Tentative** |
| All gate-byte English | Open |
| `param_5` exact semantic | Tentative |
| Runtime / bit-exact | Open |
