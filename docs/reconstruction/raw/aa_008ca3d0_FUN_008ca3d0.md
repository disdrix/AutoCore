# Raw capture: FUN_008ca3d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ca3d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008ca3d0` |
| **Canonical name** | `FUN_008ca3d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * FUN_008ca3d0(undefined4 *param_1,undefined4 param_2)

{
  undefined1 extraout_DL;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &DAT_009b6d20;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0087b890(param_1,param_2);
  local_4 = 0;
  *param_1 = &PTR_FUN_00a4211c;
  param_1[0x13f] = 0xf;
  param_1[0x140] = 0;
  FUN_008c91b0();
  param_1[0x154] = 0;
  *(undefined1 *)((int)param_1 + 0xbf) = extraout_DL;
  NDUIWindow_ReloadInterface("i_d_fet.xml");
  ExceptionList = local_c;
  return param_1;
}
```
