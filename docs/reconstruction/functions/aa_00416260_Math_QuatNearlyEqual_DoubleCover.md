# Function record: Math_QuatNearlyEqual_DoubleCover

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416260` |
| **Canonical name** | `Math_QuatNearlyEqual_DoubleCover` |
| **Ghidra name** | `FUN_00416260` |
| **Address** | `0x00416260`–`0x0041634e` (239 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | math / quaternion compare |
| **Completion status** | **Sealed** W26-A dual A/B 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Quaternion abs+rel nearness with double-cover (`b≈a` or `b≈-a`). Nested callee of `Math_FloatNearlyEqual_AbsRel`.

## Signature

```c
uint32_t Math_QuatNearlyEqual_DoubleCover(const float a[4], const float b[4],
                                          float relTol, float absTol);
// machine: ESI=a, EDI=b, RET 8
```

## Evidence

- Live Ghidra decompile 2026-07-29 ≡ raw 2026-07-23
- `read_memory` 239 B; caller site confirms register pointers + 0.002f tols

## Artifacts

See `aa_00416260_FUN_00416260.md` for full artifact table.
