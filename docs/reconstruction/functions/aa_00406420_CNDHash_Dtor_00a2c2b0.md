# Function record: CNDHash_Dtor_00a2c2b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406420` |
| **Canonical name** | `CNDHash_Dtor_00a2c2b0` |
| **Ghidra name** | `FUN_00406420` |
| **Address** | `0x00406420`–`0x0040649a` (**123 B** / `0x7B`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_00406420_CNDHash_Dtor_00a2c2b0.md`, `B_aa_00406420_CNDHash_Dtor_00a2c2b0.md` |
| **Last reviewed** | `2026-08-04` (WQ9H-D OWN-ONLY) |

## Alias

- `FUN_00406420`
- Rejected scaffold: `Named_VOG_DEBUG_STOP_00406420`

## Purpose

Host-family CNDHash (**vtbl `00a2c2b0`**) complete destructor body. Re-stamps vtbl; if traversal lock `@+0x1d` is set, logs **`HashError:Destructor, already locked for traversal`** + **`VOG_DEBUG_STOP`** (non-fatal); calls `CNDHash_DestroyBucketTable_00a2c2e4` (EAX=this); tears down freelist slab vector at `this+0x20` via `FUN_00416e80`. Invoked only from scalar-deleting dtor `FUN_00406520` (vtbl slot 0).

## Signature (sealed)

```c
// __thiscall; ECX = hash*; bare ret
void CNDHash_Dtor_00a2c2b0(void *self /*ECX*/);
```

## Algorithm

1. SEH frame; re-stamp vtbl.
2. If lock@+0x1d: log HashError + VOG_DEBUG_STOP (continue).
3. DestroyBucketTable (EAX ABI).
4. Freelist vector dtor at +0x20.
5. Bare ret.

## Related

- Twin ctor: `aa_004063a0` `CNDHash_Ctor_00a2c2b0`
- Destroy: `aa_00406fc0` `CNDHash_DestroyBucketTable_00a2c2e4` (WQ9G-J)
- Scalar deleting wrapper: `FUN_00406520` (vtbl[0]; not OWN)
- Parallel: `CNDHash_Dtor_009cfa7c`, `SkillCNDHash_CompleteDtor_Inferred`

## Artifacts

- Raw / annotated / clean / dual A/B — see FUN twin record + agent report
