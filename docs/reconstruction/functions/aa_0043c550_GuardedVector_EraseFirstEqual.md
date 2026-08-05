# Function record: GuardedVector_EraseFirstEqual

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c550` |
| **Canonical name** | `GuardedVector_EraseFirstEqual` (**Inferred**) |
| **Ghidra name** | `FUN_0043c550` |
| **Address** | `0x0043c550`–`0x0043c5e1` |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-vector container |
| **Status** | Dual A/B sealed W28-C 2026-07-29 — **accept-with-gaps** |

## Purpose

Optional critical-section linear scan for the first ring element equal to `*key`, then single-element erase via `GuardedVector_EraseRange`. Used by `assManager` resolver removal (`assManager.cpp`).

## Signature

```c
// Retail: ESI=container; stdcall 1 stack arg; RET 4; AL=bool
uint8_t GuardedVector_EraseFirstEqual(int* key, GuardedVectorHeader* container /*ESI*/);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043c550_FUN_0043c550.md` |
| Annotated | `docs/reconstruction/raw/aa_0043c550_FUN_0043c550.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_EraseFirstEqual.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c550.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043c550_FUN_0043c550.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0043c550_GuardedVector_EraseFirstEqual.md`, `B_…` |
