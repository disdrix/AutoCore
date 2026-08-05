# Annotated low-level: FUN_009c3de0 / atexit_NetClassRep_rpcMsgGuaranteedOrdered

| Field | Value |
|---|---|
| Stable ID | `aa_009c3de0` |
| VA | `0x009c3de0` |
| Body | `0x009c3de0`–`0x009c3de9` (10 B) |
| System | networking / TNL ClassRep CRT |
| Date | 2026-07-29 (W25-I dual seal) |
| Ghidra | `FUN_009c3de0` |
| Canonical (Inferred) | `atexit_NetClassRep_rpcMsgGuaranteedOrdered` |

## Machine-level notes

- **Role:** CRT **`atexit`** destructor thunk for the static `TNL::NetClassRepInstance<RPC_TNLConnection_rpcMsgGuaranteedOrdered>` at `DAT_00b04f40`.
- **Pattern:** classic MSVC static-object exit thunk: **`mov ecx, &static_obj; jmp dtor`** (no stack frame, no `ret` of its own — dtor returns to atexit).
- **Decompiler hazard:** Ghidra shows `FUN_005a2470(); return;` which loses the baked `this` pointer and the **tail jmp**. Prefer bytes.
- **Identity of storage:** `0x00b04f40` is the same ClassRep returned by `RPC_rpcMsgGuaranteedOrdered_Method1` / getClassRep (`0x0059e1c0`) — sealed High in sibling dual `aa_0059e1c0`.
- **Registration:** CRT static init region `0x009c0eb0` constructs via `FUN_005a2410` then `atexit(this unit)`.
- **Not** a general-purpose dtor; hard-wires one BSS object.

## Pseudocode (annotated; bytes-faithful)

```c
// atexit callback — no args
void atexit_NetClassRep_rpcMsgGuaranteedOrdered(void)
{
  // ECX = &g_rpcMsgGuaranteedOrdered_ClassRep  (0x00b04f40)
  // tail-call ClassRep instance dtor FUN_005a2470
  FUN_005a2470(/* this = 0x00b04f40 */);
}
```

## Related VAs (context; not dual-owned here)

| VA | Role |
|---|---|
| `0x00b04f40` | static NetClassRepInstance storage (span 0x38) |
| `0x005a2470` | ClassRep dtor (free name, restore base vtbl) |
| `0x005a2410` | ClassRep ctor (CRT static init) |
| `0x009c0eb0` | CRT static constructor + atexit registration |
| `0x009d80cc` | class name C-string |
| `0x0059e1c0` | getClassRep Method1 (returns &storage) |

## Open / residual

- Product English for atexit symbol (compiler-generated; Inferred name only).
- Runtime process-exit observation open (static analysis sufficient for thunk CF).
