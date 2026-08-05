# Annotated low-level: Host_ResetHashQueuesVectors_Inferred (FUN_004bbeb0)

| Field | Value |
|---|---|
| Stable ID | `aa_004bbeb0` |
| VA | `0x004bbeb0`–`0x004bbf18` exclusive (**104 B** / `0x68`) |
| Canonical name | `Host_ResetHashQueuesVectors_Inferred` |
| Ghidra name | `FUN_004bbeb0` |
| System | host table reset (CNDHash + locked queues + dword vectors) |
| Date | 2026-07-29 (W31-N re-verify; scaffold 2026-07-23) |

## Machine-level notes

- **Bytes win** over decompiler for ECX targets on every callee.
- Entry: `PUSH ESI; MOV ESI,ECX` — thiscall.
- `FUN_004bcce0` = sealed `CNDHash_Recreate_009cb450` (W30-G): always **log2=5** here (N=32, mask 31). ECX = **`*(this+0x18)`** (pointer to hash), not embedded.
- `FUN_004bc580` ×3: CS-guarded drain of owned list (head `+0x1c`, scalar-delete `vtbl[0](1)`); throw if traversal flag `+0x28`. Targets **`*(this+0x1c/20/24)`**.
- `FUN_00410420` ×3: dword vector resize; always **(size=0, fill=0)** → clear. Embedded at **`this+0x48`, `+0x28`, `+0x38`** (`LEA`).
- Flag `+0x0c` → **CALL** `(*(this+4))->vtbl[+4]`.
- Flag `+0x0d` → **tail JMP** `(*(this+8))->vtbl[+4]` (`FF 62 04` after `POP ESI`) — not a jumptable.
- Reject scaffold plate `Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update_*`.

## Pseudocode (byte-corrected)

```c
// ECX = host; bare RET; void
void __fastcall Host_ResetHashQueuesVectors_Inferred(Host_ResetTables* self)
{
  CNDHash_Recreate_009cb450(self->pHashAt18, /*log2*/ 5); // FUN_004bcce0
  FUN_004bc580(self->pQueue1c);
  FUN_004bc580(self->pQueue20);
  FUN_004bc580(self->pQueue24);
  StdVector_Resize_Dword(&self->vec48, 0, /*fill*/ 0); // FUN_00410420
  StdVector_Resize_Dword(&self->vec28, 0, 0);
  StdVector_Resize_Dword(&self->vec38, 0, 0);
  if (self->flag0c)
    self->pIface04->vtbl[1](); // +4
  if (self->flag0d)
    /*tail*/ self->pIface08->vtbl[1]();
}
```

## Layout (host)

| Off | Role |
|---|---|
| +0x04 | iface* (optional vtbl[+4] if flag+0x0c) |
| +0x08 | iface* (optional tail vtbl[+4] if flag+0x0d) |
| +0x0c | char flag → call iface04 |
| +0x0d | char flag → tail iface08 |
| +0x18 | CNDHash* (009cb450 family) |
| +0x1c / +0x20 / +0x24 | locked-list host* (FUN_004bc580) |
| +0x28 / +0x38 / +0x48 | embedded dword vectors |

## Callers

| Caller | Site | Role (structural) |
|---|---|---|
| `FUN_004d98f0` | `0x004d9a61` | post object-sweep cleanup |
| `FUN_00943b80` | `0x00943d72` | client/host teardown after dual `FUN_004bae00` sweeps |

## Open questions

- Product class English / global singleton identity for `this` at call sites.
- Product names for the three locked-list hosts and three vectors.
- Product meaning of dual iface vtbl[+4] methods.
- Runtime / bit-exact.
