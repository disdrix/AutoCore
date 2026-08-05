# Function record: Math_FloatNearlyEqual_AbsRel

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d450` |
| **Canonical name** | `Math_FloatNearlyEqual_AbsRel` |
| **Ghidra name** | `FUN_0040d450` |
| **Address** | `0x0040d450`–`0x0040d4ac` (93 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | math / float compare |
| **Completion status** | **Sealed** W25-T dual A/B 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Absolute+relative float nearness gate used by vec3/quat helpers and quaternion normalize skip.

## Signature

```c
// cdecl
uint32_t Math_FloatNearlyEqual_AbsRel(float a, float b, float relTol, float absTol);
// return 1 if |a-b|<=absTol OR |a-b|<=max(|a|,|b|)*relTol else 0
```

## Evidence

- Live Ghidra decompile 2026-07-29 ≡ raw 2026-07-23
- `read_memory` full 93 B body; epilogue `POP ECX; RET`
- Callers confirm float pair + dual tolerance roles (vec3, quat, lenSq≈1)

## Artifacts

See `aa_0040d450_FUN_0040d450.md` for full artifact table.
