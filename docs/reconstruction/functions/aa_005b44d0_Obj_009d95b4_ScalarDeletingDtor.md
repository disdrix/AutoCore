# Function record (named): Obj_009d95b4_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b44d0` |
| **Semantic name** | `Obj_009d95b4_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_005b44d0` |
| **Address** | `0x005b44d0`–`0x005b44ee` exclusive (**30 B** / `0x1E`) |
| **Naming basis** | MSVC scalar-deleting dtor = **vtbl[0]** of `PTR_FUN_009d95b4` (`0x009d95b4` → `0x005b44d0`); always calls body `Obj_BodyDtor_SetVtbl_DestroyStdListAt10` (`FUN_005b3b20`); product demangle open — vtbl suffix disambiguates; pairs with W28-N body dual |
| **Status** | Dual sealed W30-N (**accept**) |

**Decision:** promote **`Obj_009d95b4_ScalarDeletingDtor`**. Do **not** treat as complete-object body (that is `0x005b3b20`) or invent a product class English name from shader-adjacent rdata.

See `aa_005b44d0_FUN_005b44d0.md` for full signature, callers, confidence.
