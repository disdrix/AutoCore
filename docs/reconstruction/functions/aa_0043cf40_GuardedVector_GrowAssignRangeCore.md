# Function record: GuardedVector_GrowAssignRangeCore

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043cf40` |
| **Canonical name** | `GuardedVector_GrowAssignRangeCore` (**Inferred**) |
| **Ghidra name** | `FUN_0043cf40` |
| **Address** | `0x0043cf40`–`0x0043d2f6` |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-deque container |
| **Status** | Dual A/B sealed W28-B 2026-07-29 — **accept-with-gaps** |

## Purpose

Core of `GuardedVector_GrowAssignRange` / grow path of `GuardedVector_CopyAssign` when source range requires dest growth and residual construct/destroy. Closes nested residual left open by W27-C trampoline dual.

## Signature

```c
// Retail: stdcall 8 args; RET 0x20
void GuardedVector_GrowAssignRangeCore(
    int dest, uint32_t p2, uint dest_bound, int source, uint src_begin,
    int p6, uint src_end, uint32_t dest_again);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043cf40_FUN_0043cf40.md` |
| Annotated | `docs/reconstruction/raw/aa_0043cf40_FUN_0043cf40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_GrowAssignRangeCore.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043cf40.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043cf40_FUN_0043cf40.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0043cf40_GuardedVector_GrowAssignRangeCore.md`, `B_…` |
