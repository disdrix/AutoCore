# Function record (named): GuardedVector_PushBack_Stride2_U32x2

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e970` |
| **Canonical name** | `GuardedVector_PushBack_Stride2_U32x2` (**Inferred**) |
| **Ghidra** | `FUN_0043e970` @ `0x0043e970`–`0x0043e9dd` |
| **Twin** | `aa_0043e9e0` `GuardedVector_PushBack_Stride2_U32U8` (store helper differs) |
| **Family** | `GuardedVector_*` — PushBack (W29-B dword), GrowBlockMap_Stride2 (W30-A) |
| **Dual** | W31-J 2026-07-29 — **accept** |
| **Primary record** | `docs/reconstruction/functions/aa_0043e970_FUN_0043e970.md` |

## Contract (port)

```
// EAX = container; stack = const {u32,u32}*; RET 0x4
// may GrowBlockMap_Stride2(1) with EBX=container
// write 8-byte POD at begin+size with >>1 page wrap; size++; begin unchanged
// Do not use dword PushBack (>>2 / &3) or thiscall ECX for this body.
```
