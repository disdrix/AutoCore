# Raw capture: FUN_005a1aa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a1aa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005a1aa0` |
| **Canonical name** | `FUN_005a1aa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005a1aa0(undefined4 *param_1)

{
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009a620f;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_009d7fcc;
  local_4 = 1;
  if ((int *)param_1[0x2c] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x2c] + 4))(1);
  }
  param_1[0x2c] = 0;
  local_4 = local_4 & 0xffffff00;
  FUN_005a4c30(local_10,*(undefined4 *)param_1[0x2f],(undefined4 *)param_1[0x2f]);
                    /* WARNING: Subroutine does not return */
  operator_delete((void *)param_1[0x2f]);
}
```
