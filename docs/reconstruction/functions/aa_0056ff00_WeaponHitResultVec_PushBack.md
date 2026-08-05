# Function record: WeaponHitResultVec_PushBack

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056ff00` |
| **Canonical name** | `WeaponHitResultVec_PushBack` (Inferred) |
| **Ghidra name** | `FUN_0056ff00` |
| **Address** | `0x0056ff00`–`0x0056ff60` (97 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | combat / weapon multi-hit staging |
| **Completion status** | **dual-sealed** W24-R 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Append one 0x20-byte hit-result POD to the weapon multi-target staging vector.

## Signature

```c
void __thiscall WeaponHitResultVec_PushBack(VecShell *vec, const void *value);
// RET 4
```

## Artifacts

See `aa_0056ff00_FUN_0056ff00.md` for full table + A/B paths.
