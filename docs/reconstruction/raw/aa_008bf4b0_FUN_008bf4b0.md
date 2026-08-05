# Raw capture: FUN_008bf4b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008bf4b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008bf4b0` |
| **Canonical name** | `FUN_008bf4b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int * FUN_008bf4b0(int *param_1,undefined4 param_2)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b68f7;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0087b890(param_1,param_2);
  *param_1 = (int)&PTR_FUN_00a44f04;
  param_1[0x14b] = 0;
  param_1[0x14c] = 0;
  param_1[0x14d] = 0;
  local_4 = 1;
  param_1[0x13f] = 0;
  param_1[0x140] = 2;
  FUN_008bebc0();
  NDUIWindow_ReloadInterface("i_d_inv_loot_queue.xml");
  (**(code **)(*param_1 + 0x448))();
  (**(code **)(*param_1 + 0x34c))();
  *(undefined1 *)((int)param_1 + 0xc5) = 1;
  *(undefined1 *)(param_1 + 0x31) = 0;
  param_1[0x149] = 0;
  ExceptionList = local_c;
  return param_1;
}
```
