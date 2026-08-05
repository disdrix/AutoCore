# Raw capture: FUN_008ea6f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ea6f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008ea6f0` |
| **Canonical name** | `FUN_008ea6f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_008ea6f0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009b74d7;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_00a39f94;
  local_4 = 0;
  puVar1 = param_1 + 0x14b;
  iVar2 = 4;
  do {
    if ((void *)*puVar1 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete((void *)*puVar1);
    }
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *param_1 = &PTR_FUN_00a58c6c;
  local_4 = 0xffffffff;
  FUN_00792c20();
  ExceptionList = pvStack_c;
  return;
}
```
