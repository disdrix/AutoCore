# Function record: GuardedVector_PushBack

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c830` |
| **Canonical name** | `GuardedVector_PushBack` (**Inferred**) |
| **Ghidra name** | `FUN_0043c830` |
| **Address** | `0x0043c830`–`0x0043c8a2` |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-deque container |
| **Status** | Dual A/B sealed W29-B 2026-07-29 — **accept-with-gaps** |

## Purpose

Push one dword onto the **back** of the GuardedVector ring-deque. Grows the block map when the end index is page-aligned and capacity is tight; wraps the page by capacity; lazily allocates a 16-byte page; stores `*value` at absolute `begin+size`; increments `size` only.

## Signature

```c
// Retail: EAX=container; stdcall 1; RET 0x4
void GuardedVector_PushBack(GuardedVectorHeader* container /*EAX*/,
                            const uint32_t* value /*stack*/);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043c830_FUN_0043c830.md` |
| Annotated | `docs/reconstruction/raw/aa_0043c830_FUN_0043c830.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PushBack.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c830.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043c830_FUN_0043c830.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0043c830_GuardedVector_PushBack.md`, `B_…` |
