# Function record (named): GuardedVector_PushBack_Stride2_U32U8

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e9e0` |
| **Canonical name** | `GuardedVector_PushBack_Stride2_U32U8` (**Inferred**) |
| **Ghidra** | `FUN_0043e9e0` @ `0x0043e9e0`–`0x0043ea4d` |
| **Twin** | `aa_0043e970` `GuardedVector_PushBack_Stride2_U32x2` (store helper differs) |
| **Family** | `GuardedVector_*` — locked wrapper sibling likely `FUN_0043e7f0` |
| **Dual** | W31-J 2026-07-29 — **accept** |
| **Primary record** | `docs/reconstruction/functions/aa_0043e9e0_FUN_0043e9e0.md` |

## Contract (port)

```
// EAX = container; stack = const {u32,u8}*; RET 0x4
// may GrowBlockMap_Stride2(1) with EBX=container
// write dword+byte at begin+size (8-byte slot stride); size++; begin unchanged
// Do not substitute U32x2 store helper or dword PushBack (>>2).
```
