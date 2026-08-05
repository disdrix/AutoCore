# Raw capture: FUN_005f3ae0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005f3ae0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005f3ae0` |
| **Canonical name** | `FUN_005f3ae0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_005f3ae0(float *param_1,float param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined1 auStack_f8 [8];
  float local_f0;
  float local_ec;
  float local_e8;
  undefined4 *local_e4;
  int iStack_dc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  float fStack_ac;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  float fStack_48;
  undefined1 uStack_34;
  void *pvStack_2c;
  undefined4 uStack_24;
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0xffffffff;
  puStack_18 = &LAB_009a7978;
  pvStack_1c = ExceptionList;
  local_e8 = param_1[2] * DAT_00a0f298;
  local_ec = param_1[1] * DAT_00a0f298;
  local_f0 = *param_1 * DAT_00a0f298;
  local_e4 = (undefined4 *)0x0;
  ExceptionList = &pvStack_1c;
  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0x20,0x22);
  *(undefined2 *)(iVar1 + 4) = 0x20;
  pvStack_1c = (void *)0x0;
  puVar2 = (undefined4 *)FUN_006c7970(auStack_f8,DAT_00af58a0);
  pvStack_1c = (void *)0xffffffff;
  FUN_005e1c80();
  pvStack_1c = (void *)0x1;
  if (param_2 == 0.0) {
    uStack_34 = 7;
  }
  else {
    fStack_48 = param_2;
    uStack_148 = 0;
    uStack_144 = 0;
    uStack_12c = 0;
    uStack_130 = 0;
    uStack_134 = 0;
    uStack_138 = 0;
    uStack_11c = 0;
    uStack_120 = 0;
    uStack_124 = 0;
    uStack_128 = 0;
    uStack_10c = 0;
    uStack_110 = 0;
    uStack_114 = 0;
    uStack_118 = 0;
    uStack_fc = 0;
    uStack_100 = 0;
    uStack_104 = 0;
    uStack_108 = 0;
    FUN_005ee750(auStack_f8,param_2,&uStack_148);
    uStack_88 = uStack_128;
    uStack_84 = uStack_124;
    uStack_80 = uStack_120;
    uStack_7c = uStack_11c;
    uStack_78 = uStack_118;
    uStack_74 = uStack_114;
    uStack_70 = uStack_110;
    uStack_6c = uStack_10c;
    uStack_68 = uStack_108;
    uStack_64 = uStack_104;
    uStack_60 = uStack_100;
    uStack_5c = uStack_fc;
    uStack_34 = 4;
  }
  uStack_b0 = 0;
  uStack_b4 = 0;
  uStack_b8 = 0;
  fStack_ac = g_flOne;
  uStack_c8 = *param_3;
  uStack_c4 = param_3[1];
  uStack_c0 = param_3[2];
  uStack_bc = param_3[3];
  local_e4 = puVar2;
  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0xa0,0x28);
  *(undefined2 *)(iVar1 + 4) = 0xa0;
  uStack_24._0_1_ = 2;
  uVar3 = FUN_005d4240(&local_f0);
  *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;
  uStack_24 = CONCAT31(uStack_24._1_3_,1);
  if (*(short *)((int)puVar2 + 6) == 0) {
    (**(code **)*puVar2)(1);
  }
  uStack_24 = 0xffffffff;
  if (-1 < iStack_dc) {
    (**(code **)(*DAT_00b05060 + 0x14))(local_e4,iStack_dc * 8,0x12);
  }
  ExceptionList = pvStack_2c;
  return uVar3;
}
```
