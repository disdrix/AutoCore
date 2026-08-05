# Function record: Math_QuatInverseRotateDelta_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e8590` |
| **Canonical name** | `Math_QuatInverseRotateDelta_Inferred` |
| **Ghidra name** | `FUN_004e8590` |
| **Address** | `0x004e8590` |
| **Body span** | `004e8590`–`004e87ce` (575 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | pure math / transform |
| **Convention** | MSVC cdecl; 4×`float*`; leaf; `ret` |
| **Completion status** | **partial** — three-rep + dual A/B sealed 2026-07-29; runtime/diff/bit-exact open |
| **Dual verdict** | **accept-with-gaps** (A+B) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Inverse-rotate a world-space delta by a unit quaternion:

```
out.xyz = R(q)^T * (point.xyz - origin.xyz)
```

Leaf sibling of `Math_QuatTransformPoint_Inferred` (`0x004e8bf0`, forward `pos + R·v`).

## Signature

```c
void FUN_004e8590(float *origin, float *quat_xyzw, float *world_point, float *out_local);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004e8590_FUN_004e8590.md`
- Annotated: `docs/reconstruction/raw/aa_004e8590_FUN_004e8590.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004e8590.cpp`
- Named: `docs/reconstruction/reconstructed-exact/Math_QuatInverseRotateDelta_Inferred.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004e8590_Math_QuatInverseRotateDelta_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004e8590_Math_QuatInverseRotateDelta_Inferred.md`

## Callers / callees

| Dir | VA | Name |
|---|---|---|
| Caller | `0x004b1100` | `FUN_004b1100` (site `0x004b12ea`) |
| Callees | — | leaf |

## Confidence

| Claim | Level |
|---|---|
| CF ≡ live decompile ≡ constants | **High / Confirmed** |
| `out = R^T*(p3−p1)` closed form | **High** |
| XYZW quat layout (family) | **High** |
| cdecl leaf / W unwritten | **High** |
| Product English name | **Tentative** (`_Inferred`) |
| Sole-caller domain English | Partial |

## Prior scaffold alias

`Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004e8590` — rejected as role label (too narrow).
