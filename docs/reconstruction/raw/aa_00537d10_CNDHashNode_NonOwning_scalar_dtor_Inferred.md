# Raw capture: CNDHashNode_NonOwning_scalar_dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537d10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00537d10` |
| **Canonical name** | `CNDHashNode_NonOwning_scalar_dtor_Inferred` / `FUN_00537d10` |
| **System** | container / CNDHash |
| **Capture timestamp** | `2026-07-29` |
| **Tool** | Ghidra MCP `create_function` + `force_decompile` + `read_memory` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_00537d10(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_009cf02c;
  if ((param_2 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(param_1);
  }
  return param_1;
}
```

---

## Machine (`read_memory` @ `0x00537d10` length 32)

```
f6 44 24 04 01 56 8b f1 c7 06 2c f0 9c 00 74 09
56 e8 fc 1a f5 ff 83 c4 04 8b c6 5e c2 04 00 cc
```
