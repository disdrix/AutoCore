# Function record: GuardedVector_RingCopyRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ce90` |
| **Canonical name** | `GuardedVector_RingCopyRange` |
| **Ghidra name** | `FUN_0043ce90` |
| **Address** | `0x0043ce90`–`0x0043cebe` (47 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / guarded container |
| **Completion status** | **Sealed** W27-B dual A/B 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Shim used by `GuardedVector_CopyAssign` to invoke ring element copy (`FUN_0043d390`) on both fit and grow paths; returns the out-cursor pair pointer.

## Signature

```c
// ESI = outPair; parent 6 stack args; returns outPair in EAX
void* GuardedVector_RingCopyRange(int* outPair /*ESI*/, /* + parent stack */);
```

## Evidence

- Live Ghidra decompile 2026-07-29 ≡ raw 2026-07-23
- Parent dual W26-G sealed fit/grow call sites
- Dual A/B accept-with-gaps

## Artifacts

See `aa_0043ce90_FUN_0043ce90.md` for full artifact table.
