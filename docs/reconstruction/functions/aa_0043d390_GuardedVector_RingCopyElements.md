# Function record: GuardedVector_RingCopyElements

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d390` |
| **Canonical name** | `GuardedVector_RingCopyElements` (**Inferred**) |
| **Ghidra name** | `FUN_0043d390` |
| **Address** | `0x0043d390`–`0x0043d411` (130 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / guarded ring container |
| **Completion status** | **Sealed** W28-A dual A/B 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Shared leaf that copies dword elements between ring/deque-like map-of-blocks containers and updates the destination iterator pair. Used by assign and erase-forward paths among others.

## Signature

```c
void GuardedVector_RingCopyElements(
    RingIterPair* outPair,
    GuardedRingContainer* srcCont, uint32_t srcIdx,
    GuardedRingContainer* srcEndCont, uint32_t srcEndIdx,
    GuardedRingContainer* dstCont, uint32_t dstIdx);
```

## Evidence

- Live Ghidra decompile 2026-07-29 ≡ raw 2026-07-23
- 130 B body sealed via `read_memory`; 7 cdecl stack formals
- Dual A/B **accept**

## Artifacts

See `aa_0043d390_FUN_0043d390.md` for full artifact table.
