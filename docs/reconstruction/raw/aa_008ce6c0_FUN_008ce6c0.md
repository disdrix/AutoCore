# Raw capture: FUN_008ce6c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ce6c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008ce6c0` |
| **Canonical name** | `FUN_008ce6c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int * FUN_008ce6c0(int *param_1,undefined4 param_2)

{
  char cVar1;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &DAT_009b9fe6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_008d8b90(param_1,param_2);
  local_4 = 0;
  *param_1 = (int)&PTR_FUN_00a40e1c;
  param_1[0x15e] = -1;
  param_1[0x15f] = 0;
  *(undefined1 *)(param_1 + 0x160) = 0;
  param_1[0x161] = 0;
  param_1[0x162] = 0;
  param_1[0x163] = 0;
  param_1[0x164] = 0;
  param_1[0x165] = 0;
  param_1[0x166] = 0;
  *(undefined1 *)(param_1 + 0x196) = 0;
  FUN_008cc750();
  NDUIWindow_ReloadInterface("i_d_fes.xml");
  cVar1 = (**(code **)(*param_1 + 0x3d8))();
  if (cVar1 != '\0') {
    cVar1 = (**(code **)(*param_1 + 0xd0))();
    if (cVar1 != '\0') {
      (**(code **)(*param_1 + 0xfc))(1,0x3f000000);
    }
  }
  ExceptionList = local_c;
  return param_1;
}
```
