# Function record: GuardedVector_PushBack_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d670` |
| **Canonical name** | `GuardedVector_PushBack_Thiscall` (**Inferred**) |
| **Ghidra name** | `FUN_0043d670` |
| **Address** | `0x0043d670`–`0x0043d6e6` |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-deque container |
| **Status** | Dual A/B sealed W31-I 2026-07-29 — **accept** |

## Purpose

Push one dword onto the **back** of the GuardedVector ring-deque under **thiscall** ABI. Grows the block map via `GuardedVector_GrowBlockMap_Thiscall` when the end index is page-aligned and capacity is tight; wraps the page by capacity; lazily allocates a 16-byte page; stores `*value` via `FUN_0043d420` at absolute `begin+size`; increments `size` only.

## Signature

```c
// Retail: ECX=container; stdcall 1; RET 0x4
void GuardedVector_PushBack_Thiscall(GuardedVectorHeader* container /*ECX*/,
                                     const uint32_t* value /*stack*/);
```

## Relationship

- Twin of W29-B `GuardedVector_PushBack` (`0x0043c830`, EAX + EBX grow).
- Nested grow sealed W30-A `GuardedVector_GrowBlockMap_Thiscall` (`0x0043d990`).
- Sibling front polarity: `GuardedVector_PushFront_Thiscall` (`0x0043e3d0`).

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043d670_FUN_0043d670.md` |
| Annotated | `docs/reconstruction/raw/aa_0043d670_FUN_0043d670.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PushBack_Thiscall.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d670.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043d670_FUN_0043d670.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0043d670_GuardedVector_PushBack_Thiscall.md`, `B_…` |
