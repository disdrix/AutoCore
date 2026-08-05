# Function record: GuardedVector_PushFront

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ce10` |
| **Canonical name** | `GuardedVector_PushFront` (**Inferred**) |
| **Ghidra name** | `FUN_0043ce10` |
| **Address** | `0x0043ce10`–`0x0043ce85` |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-deque container |
| **Status** | Dual A/B sealed W29-B 2026-07-29 — **accept-with-gaps** |

## Purpose

Push one dword onto the **front** of the GuardedVector ring-deque. Grows the block map when the front index is page-aligned and capacity is tight; wraps `begin` through `capacity*4` when at 0; lazily allocates a 16-byte (4-dword) page; stores `*value`; increments `size` and commits the new `begin`.

## Signature

```c
// Retail: EAX=container; stdcall 1; RET 0x4
void GuardedVector_PushFront(GuardedVectorHeader* container /*EAX*/,
                             const uint32_t* value /*stack*/);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043ce10_FUN_0043ce10.md` |
| Annotated | `docs/reconstruction/raw/aa_0043ce10_FUN_0043ce10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PushFront.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043ce10.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043ce10_FUN_0043ce10.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0043ce10_GuardedVector_PushFront.md`, `B_…` |
