# Raw capture: FUN_008bafa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008bafa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008bafa0` |
| **Canonical name** | `FUN_008bafa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_008bafa0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009b66e6;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_00a46a14;
  local_4 = 0;
  puVar1 = &DAT_00d17788;
  puVar2 = &DAT_00d177c8;
  do {
    iVar3 = 5;
    do {
      if ((void *)*puVar2 != (void *)0x0) {
        operator_delete__((void *)*puVar2);
      }
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    if ((void *)*puVar1 != (void *)0x0) {
      operator_delete__((void *)*puVar1);
    }
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while ((int)puVar2 < 0xd178f4);
  *param_1 = &PTR_FUN_00a58c6c;
  local_4 = 0xffffffff;
  FUN_00792c20();
  ExceptionList = pvStack_c;
  return;
}
```
