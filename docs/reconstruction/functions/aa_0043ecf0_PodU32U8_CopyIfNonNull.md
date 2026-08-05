# Function record (named): PodU32U8_CopyIfNonNull

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ecf0` |
| **Canonical name** | `PodU32U8_CopyIfNonNull` (**Inferred**) |
| **Ghidra** | `FUN_0043ecf0` @ `0x0043ecf0`–`0x0043ecfe` |
| **Twin** | `FUN_0043ece0` (u32×2 store; second field dword) |
| **Family** | GuardedVector stride-2 store helpers (W31-J push pair) |
| **Dual** | W32-N 2026-07-29 — **accept** |
| **Primary record** | `docs/reconstruction/functions/aa_0043ecf0_FUN_0043ecf0.md` |

## Contract (port)

```
// Null-safe PodU32U8 store:
//   EAX = dest slot (nullable); ECX = const {u32,u8}*; RET
//   if dest: write u32 @0 + u8 @4; bytes 5–7 untouched
// Do not substitute twin FUN_0043ece0 (writes second dword).
// Null dest → no write (push still size++ in caller).
```
