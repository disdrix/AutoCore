# Function record (named): SideHost_PushKeyFlag1_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00970b60` |
| **Canonical name** | `SideHost_PushKeyFlag1_Inferred` (**Inferred**) |
| **Ghidra** | `FUN_00970b60` @ `0x00970b60`–`0x00970b95` |
| **Twin** | `aa_00970b20` `SideHost_PushKeyFlag0_Inferred` |
| **Family** | Side-host key-event push (`host+0xAC` GuardedVector U32U8) |
| **Nested** | `aa_0043e7f0` locked push; adapter `0043e8f0` → `aa_0043ea50` store |
| **Dual** | W33-N 2026-07-29 — **accept-with-gaps** |
| **Primary record** | `docs/reconstruction/functions/aa_00970b60_FUN_00970b60.md` |

## Contract (port)

```
// Side-host record key event (flag 1):
//   ECX = keyHolder*  (key = first dword)
//   stack = host*
//   RET 0x4
//   pod = { *ecx, 1 }
//   GuardedVector_PushBackLocked_Stride2_U32U8(pod*, host+0xAC)
// Do not trust decompiler void/no-args surface.
// Do not swap with flag0 twin (00970b20).
// Sole NDResource alt-miss notifier when cache+0x6c set.
```
