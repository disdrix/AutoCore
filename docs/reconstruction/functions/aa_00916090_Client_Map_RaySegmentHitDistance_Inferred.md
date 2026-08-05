# Function record: Client_Map_RaySegmentHitDistance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00916090` |
| **Canonical name** | `Client_Map_RaySegmentHitDistance_Inferred` |
| **Ghidra name** | `FUN_00916090` |
| **Address** | `0x00916090` |
| **Body span** | `00916090`–`00916225` (405 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client camera / map collision query |
| **Convention** | MSVC stdcall `RET 0x18` (6 floats); ST0 return; optional ESI `int*` hitOut |
| **Completion status** | **partial** — three-rep + dual A/B sealed 2026-07-29; runtime/diff/bit-exact open |
| **Dual verdict** | **accept-with-gaps** (A+B) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Cast a world-space segment through the client map collision context and return the Euclidean distance from the segment start to the hit point (or **0** on miss). Optionally writes the hit token through ESI.

## Signature

```c
// stdcall; RET 0x18; ST0 = distance
// ESI optional: int *hitOut
float10 FUN_00916090(float sx, float sy, float sz, float ex, float ey, float ez);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00916090_FUN_00916090.md`
- Annotated: `docs/reconstruction/raw/aa_00916090_FUN_00916090.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_00916090.cpp`
- Named: `docs/reconstruction/reconstructed-exact/Client_Map_RaySegmentHitDistance_Inferred.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00916090_Client_Map_RaySegmentHitDistance_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00916090_Client_Map_RaySegmentHitDistance_Inferred.md`

## Callers / callees

| Dir | VA | Name |
|---|---|---|
| Caller | `0x009168d0` | `FUN_009168d0` (site `0x00916e3d`) |
| Caller | `0x0091b1c0` | `FUN_0091b1c0` (site `0x0091b6bd`) |
| Callee | `0x0055e530` | map cast wrapper (`*(map+0xe4a4)`) |
| Callee | `0x004e9530` | `Math_CopyFloat3ToFloat4_Inferred` |

## Confidence

| Claim | Level |
|---|---|
| CF ≡ live decompile | **High** |
| stdcall RET 0x18 / ST0 / ESI out | **High** (bytes) |
| map `DAT_00d1b644`, ctx `+0xe4a4` | **High** (bytes + terrain peer) |
| filter=7; hit fraction; hit token | **High** |
| distance = \|lerp−start\| on hit else 0 | **High** |
| Product English name | **Tentative** (`_Inferred`) |
| Filter-7 enum English | Open |

## Prior scaffold alias

`Named_CalleeOf_Named_VOG_DEBUG_STOP_00916090` — rejected as sole role label.
