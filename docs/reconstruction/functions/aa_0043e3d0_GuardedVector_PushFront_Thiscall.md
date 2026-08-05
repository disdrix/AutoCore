# Function record: GuardedVector_PushFront_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e3d0` |
| **Canonical name** | `GuardedVector_PushFront_Thiscall` (**Inferred**) |
| **Ghidra name** | `FUN_0043e3d0` |
| **Address** | `0x0043e3d0`–`0x0043e447` |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-deque container |
| **Status** | Dual A/B sealed W31-I 2026-07-29 — **accept** |

## Purpose

Push one dword onto the **front** of the GuardedVector ring-deque under **thiscall** ABI. Grows the block map via `GuardedVector_GrowBlockMap_Thiscall` when begin is page-aligned and capacity is tight; wraps `begin==0` through `capacity*4`; lazily allocates a 16-byte page; stores `*value` via `FUN_0043d420`; commits `size++` and `begin=new_begin`.

## Signature

```c
// Retail: ECX=container; stdcall 1; RET 0x4
void GuardedVector_PushFront_Thiscall(GuardedVectorHeader* container /*ECX*/,
                                      const uint32_t* value /*stack*/);
```

## Relationship

- Twin of W29-B `GuardedVector_PushFront` (`0x0043ce10`, EAX + EBX grow).
- Nested grow sealed W30-A `GuardedVector_GrowBlockMap_Thiscall` (`0x0043d990`).
- Sibling back polarity: `GuardedVector_PushBack_Thiscall` (`0x0043d670`).

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043e3d0_FUN_0043e3d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043e3d0_FUN_0043e3d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PushFront_Thiscall.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e3d0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043e3d0_FUN_0043e3d0.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0043e3d0_GuardedVector_PushFront_Thiscall.md`, `B_…` |
