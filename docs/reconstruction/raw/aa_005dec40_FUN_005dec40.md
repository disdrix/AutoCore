# Raw capture: FUN_005dec40

| Field | Value |
|---|---|
| **Stable ID** | `aa_005dec40` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005dec40` |
| **Canonical name** | `FUN_005dec40` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_005dec40(undefined4 *param_1,byte param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = param_1[6];
  *param_1 = &PTR_LAB_009db9e0;
  while (iVar1 != 0) {
    puVar2 = (undefined4 *)param_1[6];
    param_1[6] = *puVar2;
    (*(code *)PTR__aligned_free_00af3bd0)(puVar2);
    iVar1 = param_1[6];
  }
  *param_1 = &PTR_LAB_009db9b4;
  if ((param_2 & 1) == 0) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(param_1);
}
```
