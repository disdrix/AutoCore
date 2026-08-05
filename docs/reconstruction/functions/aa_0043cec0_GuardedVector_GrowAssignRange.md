# Function record: GuardedVector_GrowAssignRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043cec0` |
| **Canonical name** | `GuardedVector_GrowAssignRange` (**Inferred**) |
| **Ghidra name** | `FUN_0043cec0` |
| **Address** | `0x0043cec0`–`0x0043ceef` |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-vector container |
| **Status** | Dual A/B sealed W27-C 2026-07-29 — **accept** |

## Purpose

Grow-path entry used by `GuardedVector_CopyAssign` when `source.size > dest.size`. Thin wrapper over `FUN_0043cf40`.

## Signature

```c
// stdcall 7 args; RET 0x1c
void GuardedVector_GrowAssignRange(uint32_t p1, uint32_t p2, uint32_t p3,
                                   uint32_t p4, uint32_t p5, uint32_t p6,
                                   uint32_t p7);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043cec0_FUN_0043cec0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043cec0_FUN_0043cec0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_GrowAssignRange.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043cec0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043cec0_FUN_0043cec0.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0043cec0_GuardedVector_GrowAssignRange.md`, `B_…` |
