# Raw capture: FUN_008b8bd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008b8bd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008b8bd0` |
| **Canonical name** | `FUN_008b8bd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int * FUN_008b8bd0(int *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b66a1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0087b890(param_1,0);
  local_4 = 0;
  *param_1 = (int)&PTR_FUN_00a47174;
  param_1[0x13f] = 5;
  param_1[0x140] = 1;
  param_1[0x143] = 0;
  param_1[0x144] = 1;
  *(undefined1 *)(param_1 + 0x148) = 1;
  FUN_008b8020();
  *(undefined1 *)(param_1 + 0x124) = 0;
  NDUIWindow_ReloadInterface("i_d_mail.xml");
  (**(code **)(*param_1 + 0x34c))();
  ExceptionList = local_c;
  return param_1;
}
```
