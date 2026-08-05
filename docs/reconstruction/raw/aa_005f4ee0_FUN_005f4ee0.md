# Raw capture: FUN_005f4ee0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005f4ee0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005f4ee0` |
| **Canonical name** | `FUN_005f4ee0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_005f4ee0(undefined4 param_1,float param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_e8 [8];
  undefined1 local_e0 [4];
  undefined4 local_dc;
  int iStack_d4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  float local_a4;
  float local_40;
  undefined1 local_2c;
  void *pvStack_24;
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a7ac7;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  FUN_005e1c80();
  local_14 = 0;
  if (param_2 == 0.0) {
    local_2c = 7;
  }
  else {
    local_40 = param_2;
    FUN_005f2900(param_1,param_2,local_e0);
  }
  local_a8 = 0;
  local_ac = 0;
  local_b0 = 0;
  local_a4 = g_flOne;
  local_c0 = *param_3;
  local_bc = param_3[1];
  local_b8 = param_3[2];
  local_b4 = param_3[3];
  local_dc = param_1;
  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0xa0,0x28);
  *(undefined2 *)(iVar1 + 4) = 0xa0;
  pvStack_1c = (void *)CONCAT31(pvStack_1c._1_3_,1);
  uVar2 = FUN_005d4240(auStack_e8);
  pvStack_1c = (void *)0xffffffff;
  if (-1 < iStack_d4) {
    (**(code **)(*DAT_00b05060 + 0x14))(local_dc,iStack_d4 * 8,0x12);
  }
  ExceptionList = pvStack_24;
  return uVar2;
}
```
