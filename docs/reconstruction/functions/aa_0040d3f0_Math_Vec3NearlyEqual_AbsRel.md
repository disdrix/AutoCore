# Function record: Math_Vec3NearlyEqual_AbsRel

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d3f0` |
| **Canonical name** | `Math_Vec3NearlyEqual_AbsRel` |
| **Ghidra name** | `FUN_0040d3f0` |
| **Address** | `0x0040d3f0`–`0x0040d44a` (91 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | math / vec3 compare |
| **Completion status** | **Sealed** W26-A dual A/B 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Vec3 component-wise abs+rel nearness (nested callee of `Math_FloatNearlyEqual_AbsRel`).

## Signature

```c
uint32_t Math_Vec3NearlyEqual_AbsRel(const float a[3], const float b[3],
                                     float relTol, float absTol);
// machine: ESI=a, EDI=b, RET 8
```

## Evidence

- Live Ghidra decompile 2026-07-29 ≡ raw 2026-07-23
- `read_memory` 91 B; caller site confirms register pointers + 1e-6 tols

## Artifacts

See `aa_0040d3f0_FUN_0040d3f0.md` for full artifact table.
