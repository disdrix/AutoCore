# Raw capture (named): InventoryGrid_SortAndRepack_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00572730` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00572730` |
| **Ghidra name** | `FUN_00572730` |
| **Canonical name** | `InventoryGrid_SortAndRepack_Inferred` |
| **System** | `inventory-transfer` |
| **Capture** | 2026-07-29 W20-S (live decompile ≡ 2026-07-23 scaffold raw) |
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` |
| **Integrity** | Named mirror of scaffold raw; scaffold body remains authoritative under `aa_00572730_FUN_00572730.md` |

Authoritative pseudocode: see `docs/reconstruction/raw/aa_00572730_FUN_00572730.md`.

## ABI seal

```
__thiscall InventoryGrid_SortAndRepack_Inferred(
    InventoryGrid *this,   // ECX
    bool (*compareFn)(void *ctx, Item *a, Item *b),  // stack0
    void *compareCtx                                  // stack1
);
// ret 8; returns 1 success / 0 fail
// adjusted-null this==0xFFFFFFD4 → 0
```
