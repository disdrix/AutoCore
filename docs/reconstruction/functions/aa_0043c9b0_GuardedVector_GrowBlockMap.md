# Function record: GuardedVector_GrowBlockMap

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c9b0` |
| **Canonical name** | `GuardedVector_GrowBlockMap` (**Inferred**) |
| **Ghidra name** | `FUN_0043c9b0` |
| **Address** | `0x0043c9b0`–`0x0043cafd` |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-deque container |
| **Status** | Dual A/B sealed W28-B 2026-07-29 — **accept** |

## Purpose

Deque-style **block map** grow used by push_front (`FUN_0043ce10`) and push_back (`FUN_0043c830`) when the map cannot hold another element slot. Overflow throws MSVC `"deque<T> too long"`.

## Signature

```c
// Retail: EBX=container; stdcall min_grow; RET 0x4
void GuardedVector_GrowBlockMap(uint32_t min_grow, GuardedVectorHeader* self /*EBX*/);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043c9b0_FUN_0043c9b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043c9b0_FUN_0043c9b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_GrowBlockMap.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c9b0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043c9b0_FUN_0043c9b0.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0043c9b0_GuardedVector_GrowBlockMap.md`, `B_…` |
