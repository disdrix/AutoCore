# Function record (named): GuardedVector_PushBackLocked_Stride2_U32U8

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e7f0` |
| **Canonical name** | `GuardedVector_PushBackLocked_Stride2_U32U8` (**Inferred**) |
| **Ghidra** | `FUN_0043e7f0` @ `0x0043e7f0`–`0x0043e84d` |
| **Twin** | `aa_0043c4f0` `GuardedVector_PushBackLocked` (nested dword PushBack) |
| **Family** | `GuardedVector_*` locked push wrappers |
| **Nested body** | `aa_0043e9e0` `GuardedVector_PushBack_Stride2_U32U8` (W31-J) |
| **Dual** | W32-N 2026-07-29 — **accept** |
| **Primary record** | `docs/reconstruction/functions/aa_0043e7f0_FUN_0043e7f0.md` |

## Contract (port)

```
// GuardedVector locked push_back (stride-2, dword+byte POD):
//   EDI = container; stack = const {u32,u8}*; RET 0x4
//   if lockEnable(+0x2c): EnterCS(+0x14)
//   PushBack_Stride2_U32U8(EAX=container, value)   // W31-J
//   if lockEnable: LeaveCS
// Do not substitute dword PushBackLocked (0043c4f0) or invent thiscall.
// Do not use host-level CS (DAT+0x6c) for this wrapper.
```
