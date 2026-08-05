# Function record: Object_WriteComposedMatrix

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044b5c0` |
| **Canonical name** | `Object_WriteComposedMatrix` |
| **Ghidra name** | `FUN_0044b5c0` |
| **Address** | `0x0044b5c0`–`0x0044b60f` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | graphics / xform |
| **Completion status** | **Dual A/B complete** (2026-07-29 W22-C) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Produce the world/composed matrix used by bounds accumulation: primary matrix slot `@+0x40` combined with companion object transform into an out buffer.

## Signature (image-sealed)

```c
float *Object_WriteComposedMatrix(ObjectLike *primary /*ECX*/,
                                  float *out /*stack*/,
                                  ObjectLike *companion /*EDI*/);
// cdecl ret; returns out
```

## Artifacts

| Role | Path |
|---|---|
| Raw + W22-C | `docs/reconstruction/raw/aa_0044b5c0_FUN_0044b5c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0044b5c0_FUN_0044b5c0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Object_WriteComposedMatrix.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0044b5c0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0044b5c0_Object_WriteComposedMatrix.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0044b5c0_Object_WriteComposedMatrix.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0044b5c0_FUN_0044b5c0.md` |

## Offsets (body-backed)

| Rel | Role |
|---:|---|
| `obj+0x40` | cached 4×4 matrix |
| `obj+0xbc` bit1 | primary matrix dirty |
| `obj+0xbc` bit0 | companion full-transform dirty |

## Open questions

- Product/PDB name.
- `FUN_00412d80` multiply order (not owned).
- Full ObjectLike field map beyond flags/matrix.
