# Raw capture: FUN_008dec60

| Field | Value |
|---|---|
| **Stable ID** | `aa_008dec60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008dec60` |
| **Canonical name** | `FUN_008dec60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * FUN_008dec60(undefined4 *param_1,undefined4 param_2)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b71ef;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0087b890(param_1,param_2);
  local_4 = 0;
  *param_1 = &PTR_FUN_00a3c6bc;
  param_1[0x13f] = 5;
  param_1[0x140] = 1;
  FUN_008de9f0();
  NDUIWindow_ReloadInterface("i_d_e.xml");
  ExceptionList = local_c;
  return param_1;
}
```
