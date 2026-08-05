# Raw capture: FUN_008ac3f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ac3f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008ac3f0` |
| **Canonical name** | `FUN_008ac3f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int * FUN_008ac3f0(int *param_1)

{
  float fVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b645d;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0087b890(param_1,0);
  fVar1 = g_flOne;
  *param_1 = (int)&PTR_FUN_00a4a51c;
  param_1[0x161] = 0;
  param_1[0x162] = 0;
  param_1[0x163] = 0;
  param_1[0x164] = (int)fVar1;
  param_1[0x165] = 0;
  param_1[0x166] = 0;
  param_1[0x167] = 0;
  param_1[0x168] = (int)fVar1;
  param_1[0x169] = 0;
  param_1[0x16a] = 0;
  param_1[0x16b] = 0;
  param_1[0x16c] = (int)fVar1;
  param_1[0x1cb] = 0;
  param_1[0x1cc] = 0;
  param_1[0x1cd] = 0;
  param_1[0x1cf] = 0;
  param_1[0x1d0] = 0;
  param_1[0x1d1] = 0;
  local_4 = 2;
  param_1[0x13f] = 0xc;
  param_1[0x140] = 1;
  param_1[0x192] = 0;
  param_1[0x143] = 0;
  param_1[399] = 1;
  param_1[400] = 1;
  param_1[0x145] = 0;
  *(undefined1 *)(param_1 + 0x160) = 0;
  param_1[0x1c1] = 0;
  param_1[0x170] = 0;
  param_1[0x16f] = 0;
  FUN_008ab0a0();
  NDUIWindow_ReloadInterface("i_d_npc.xml");
  FUN_008ac110();
  (**(code **)(*param_1 + 0x34c))();
  ExceptionList = local_c;
  return param_1;
}
```
