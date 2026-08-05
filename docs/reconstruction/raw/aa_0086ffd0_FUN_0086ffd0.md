# Raw capture: FUN_0086ffd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0086ffd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0086ffd0` |
| **Canonical name** | `FUN_0086ffd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * FUN_0086ffd0(undefined4 *param_1)

{
  undefined4 uVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b8c7f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0087b890(param_1,0);
  local_4 = 0;
  *param_1 = &PTR_FUN_00a5d3ec;
  uVar1 = FUN_0040fb90();
  param_1[0x146] = uVar1;
  param_1[0x147] = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  param_1[0x13f] = 0xf;
  param_1[0x140] = 1;
  FUN_0086e840();
  *(undefined1 *)(param_1 + 0x144) = 0;
  param_1[0x143] = 0;
  NDUIWindow_ReloadInterface("i_d_arena/i_d_arena_selection.xml");
  ExceptionList = local_c;
  return param_1;
}
```
