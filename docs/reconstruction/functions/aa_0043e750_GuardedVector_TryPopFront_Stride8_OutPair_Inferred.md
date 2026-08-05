# Function record: GuardedVector_TryPopFront_Stride8_OutPair_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e750` |
| **Canonical name** | `GuardedVector_TryPopFront_Stride8_OutPair_Inferred` |
| **Ghidra name** | `FUN_0043e750` |
| **Address** | `0x0043e750` |
| **Body range** | `0x0043e750`–`0x0043e7e2` exclusive (**146** B / `0x92`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | GuardedVector ring-deque try pop_front (stride 8, optional CS) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `reviews/A_aa_0043e750_GuardedVector_TryPopFront_Stride8_OutPair_Inferred.md`, `reviews/B_aa_0043e750_GuardedVector_TryPopFront_Stride8_OutPair_Inferred.md` |
| **Last reviewed** | `2026-08-04` (W38-A) |

## Purpose

Optional-CS try pop_front of stride-8 element into out pair; AL success flag.

## Signature

```c
uint8_t GuardedVector_TryPopFront_Stride8_OutPair_Inferred(
    GuardedVectorHeader* container /*ESI*/,
    uint32_t out[2] /*EDI*/);
// plain RET
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043e750_FUN_0043e750.md` |
| Annotated | `docs/reconstruction/raw/aa_0043e750_FUN_0043e750.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_TryPopFront_Stride8_OutPair_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0043e750.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043e750_FUN_0043e750.md` |
| Review A/B | as above |

## See also

Primary record: `docs/reconstruction/functions/aa_0043e750_FUN_0043e750.md`
