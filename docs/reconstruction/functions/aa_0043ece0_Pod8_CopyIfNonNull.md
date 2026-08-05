# Function record: Pod8_CopyIfNonNull

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ece0` |
| **Canonical name** | `Pod8_CopyIfNonNull` |
| **Ghidra name** | `FUN_0043ece0` |
| **Address** | `0x0043ece0`–`0x0043ecee` (**15 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | POD store / GuardedVector stride-2 helpers |
| **Completion status** | **partial** — dual A/B **accept** (W32-M 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Null-safe 8-byte (two-u32) POD copy used by stride-2 push_back when the destination slot pointer may be null.

## Signature

```c
void Pod8_CopyIfNonNull(PodU32x2* dest /*EAX*/, const PodU32x2* src /*ECX*/);
// bare RET
```

## Artifacts

- Scaffold record: `docs/reconstruction/functions/aa_0043ece0_FUN_0043ece0.md`
- Clean: `docs/reconstruction/reconstructed-exact/Pod8_CopyIfNonNull.cpp`
- Raw / annotated / A/B / report: see scaffold record
