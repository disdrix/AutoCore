# Function record: Object_SurfaceDistance3D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053e510` |
| **Canonical name** | `Object_SurfaceDistance3D_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0053e510` |
| **Address** | `0x0053e510` |
| **Body range** | `0x0053e510`–`0x0053e5ad` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared-object-pose / AI-range |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + pos paths + radii sealed; product name open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0053e510_Object_SurfaceDistance3D_Inferred.md`, `reviews/B_aa_0053e510_Object_SurfaceDistance3D_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W25-H) |

## Alias

- `FUN_0053e510` (Ghidra / scaffold)
- `Named_CalleeOf_CVOGHBAIFollowVehicle_FireWeapons_0053e510` (legacy parent-seed)

## Purpose

**Surface-to-surface 3D distance** between two objects: resolve each world position via physics `rb+0xb0` or entity `+0x84` (same dual as `Object_GetWorldPositionPtr`), compute Euclidean center distance, subtract both objects' `+0x34` radius fields.

## Signature

```c
// Machine: __thiscall, ECX=objA, stack objB, ret 4; result in ST0/float10
// Ghidra: float10 __thiscall FUN_0053e510(int param_1, int param_2)
float10 __thiscall Object_SurfaceDistance3D_Inferred(int objA, int objB);
```

## Offsets (sealed)

| Offset / path | Role | Conf |
|---|---|---|
| `obj+0x08` | physics host gate | **High** |
| `*(*(obj+8)+0x3c)+0xb0` | rb world position XYZ | **High** |
| `*(*(obj+4)+4)+obj+0x84` | entity-embedded pose XYZ | **High** |
| `obj+0x34` | float radius (subtracted) | **High** (role); product English open |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0053e510_FUN_0053e510.md` (+ W25-H append)
- Annotated: `docs/reconstruction/raw/aa_0053e510_FUN_0053e510.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_SurfaceDistance3D_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0053e510.cpp`
- Legacy alias: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_CVOGHBAIFollowVehicle_FireWeapons_0053e510.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0053e510_FUN_0053e510.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0053e510-0053b900-w25h-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callers** | `DoCreaturePursue`, `DoVehiclePursue`, `CVOGHBAIFollowVehicle_FireWeapons`, `FUN_00535c60`, `FUN_0052eb90`, `FUN_005cc680`/`7f0`, `FUN_005d5cc0`, `FUN_0061ba80`, … (11+ CALL sites) |
| **Callees** | none (inline fsqrt) |

## Confidence

| Claim | Level |
|---|---|
| thiscall + ret 4 + float result | **High** |
| Dual world-pos paths ≡ `00404c90` | **High** |
| 3D Euclidean − rA − rB | **High** |
| Product symbol name | **Open** |
| Runtime / bit-exact | Open |

## Related

- `aa_00404c90` Object_GetWorldPositionPtr
- `aa_004e9aa0` CVOGPhysicsUtils_FindDistanceToTarget (heavier util)
- physics map: `rb+0xb0` world position
