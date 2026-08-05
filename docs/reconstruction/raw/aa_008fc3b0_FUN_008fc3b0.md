# Raw capture: FUN_008fc3b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008fc3b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008fc3b0` |
| **Canonical name** | `FUN_008fc3b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int * FUN_008fc3b0(int *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b7b39;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0087b890(param_1,0);
  local_4 = 0;
  *param_1 = (int)&PTR_FUN_00a34fec;
  param_1[0x13f] = 0xf;
  param_1[0x140] = 1;
  param_1[0x199] = 3;
  FUN_008fb880();
  NDUIWindow_ReloadInterface("i_d_bug.xml");
  (**(code **)(*param_1 + 0x448))();
  (**(code **)(*param_1 + 0x34c))();
  ExceptionList = local_c;
  return param_1;
}
```
