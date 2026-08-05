# Raw capture: Vehicle_TryActivatePhysics

| Field | Value |
|---|---|
| **Stable ID** | `aa_00501420` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00501420` |
| **Canonical name** | `Vehicle_TryActivatePhysics` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall
Vehicle_TryActivatePhysics(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  float *pfVar8;
  float10 extraout_ST0;
  int iStack_160;
  float afStack_15c [5];
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  float fStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  float *pfStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined2 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  int *piStack_10c;
  int *piStack_108;
  int *piStack_104;
  undefined **ppuStack_fc;
  undefined4 uStack_f8;
  float fStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  float fStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  float fStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined2 uStack_c0;
  undefined2 uStack_be;
  undefined4 uStack_bc;
  float fStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  float afStack_90 [5];
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  float fStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &DAT_009a2e31;
  local_c = ExceptionList;
  if (((char)param_1[0xab] == '\0') && ((char)param_1[0x45] != '\0')) {
    ExceptionList = &local_c;
    cVar1 = FUN_0053e270(param_2,param_3,param_4,1);
    if ((cVar1 != '\0') && ((**(code **)(*param_1 + 0x28))(), (float10)g_flZero < extraout_ST0)) {
      if (param_1[0x96] != 0) {
        *(undefined1 *)(param_1 + 0x41) = 1;
        Vehicle_createVehicleAction();
        VehicleEntity_PushDriveAxesToController();
        if (param_1[0xb] == 0) {
          pvVar3 = operator_new(0x40);
          param_1[0xb] = (int)pvVar3;
        }
        cVar1 = FUN_004a6910();
        if (cVar1 != '\0') {
          FUN_005066c0((int)*(char *)(param_1[0x96] + 0xb0),0);
          iStack_160 = 0;
          if ('\0' < *(char *)(param_1[0x96] + 0xb0)) {
            do {
              uStack_f8 = 1;
              ppuStack_fc = &PTR_FUN_009c7bb4;
              fStack_f4 = g_flOne;
              uStack_f0 = 0;
              uStack_ec = 0;
              uStack_e8 = 0;
              fStack_e4 = g_flOne;
              uStack_e0 = 0;
              uStack_dc = 0;
              uStack_d8 = 0;
              fStack_d4 = g_flOne;
              uStack_c4 = 8;
              uStack_be = 0;
              uStack_bc = 0;
              uStack_b0 = DAT_00aaa668;
              fStack_b8 = g_flOne;
              uStack_b4 = DAT_00aaa668;
              uStack_ac = 0;
              uStack_a8 = 0;
              uStack_a4 = 0;
              uStack_a0 = 0;
              uStack_9c = 0;
              uStack_98 = 0;
              uStack_94 = *(undefined4 *)
                           (*(int *)(*(int *)(*(int *)(param_1[1] + 4) + 0xac + (int)param_1) + 0x3c
                                    ) + 0x600 + (char)iStack_160 * 4);
              uStack_38 = DAT_009c7b84;
              uStack_2c = DAT_00aaa668;
              uStack_20 = DAT_00aaa668;
              uStack_1c = DAT_00aaa668;
              uStack_14 = DAT_00aaa668;
              uStack_4 = 0;
              uStack_c8 = 0;
              uStack_cc = 0;
              uStack_d0 = 0;
              uStack_c0 = 5;
              afStack_90[0] = g_flOne;
              afStack_90[1] = 0.0;
              afStack_90[2] = 0.0;
              afStack_90[3] = 0.0;
              afStack_90[4] = g_flOne;
              uStack_7c = 0;
              uStack_78 = 0;
              uStack_74 = 0;
              fStack_70 = g_flOne;
              uStack_64 = 0;
              uStack_68 = 0;
              uStack_6c = 0;
              uStack_58 = 0;
              uStack_5c = 0;
              uStack_60 = 0;
              uStack_48 = 0;
              uStack_4c = 0;
              uStack_50 = 0;
              uStack_3c = 0;
              uStack_40 = 0;
              uStack_44 = 0;
              uStack_34 = 0;
              uStack_30 = DAT_00a10e78;
              uStack_28 = 0;
              uStack_10 = 0;
              uStack_24 = 0x80;
              uStack_54 = DAT_00aaa7ac;
              uStack_18 = 1;
              piStack_10c = (int *)0x0;
              piStack_104 = (int *)0x0;
              pfVar8 = afStack_15c;
              for (iVar6 = 0x18; iVar6 != 0; iVar6 = iVar6 + -1) {
                *pfVar8 = 0.0;
                pfVar8 = pfVar8 + 1;
              }
              pfStack_12c = (float *)0x0;
              uStack_128 = 0;
              afStack_15c[0] = g_flOne;
              afStack_15c[1] = 0.0;
              afStack_15c[2] = 0.0;
              afStack_15c[3] = 0.0;
              afStack_15c[4] = g_flOne;
              uStack_148 = 0;
              uStack_144 = 0;
              uStack_140 = 0;
              fStack_13c = g_flOne;
              uStack_130 = 0;
              uStack_134 = 0;
              uStack_138 = 0;
              uStack_124 = 0;
              uStack_11c = 0;
              uStack_118 = 0;
              uStack_120 = 0;
              uStack_114 = 0;
              piStack_108 = piStack_10c;
              uStack_110 = 1;
              uStack_4 = CONCAT31(uStack_4._1_3_,1);
              if ((piStack_104 <= piStack_10c) &&
                 ((piStack_10c == (int *)0x0 ||
                  ((uint)((int)piStack_104 - (int)piStack_10c >> 2) < 2)))) {
                piVar4 = malloc(8);
                piVar7 = piVar4;
                for (piVar5 = piStack_10c; piVar5 != piStack_108; piVar5 = piVar5 + 1) {
                  *piVar7 = *piVar5;
                  piVar7 = piVar7 + 1;
                }
                if (piStack_10c != (int *)0x0) {
                  free(piStack_10c);
                }
                piStack_104 = piVar4 + 2;
                piStack_108 = piVar4 + ((int)piStack_108 - (int)piStack_10c >> 2);
                piStack_10c = piVar4;
              }
              *piStack_108 = (int)&ppuStack_fc;
              piStack_108 = piStack_108 + 1;
              pfStack_12c = afStack_90;
              uStack_130 = 0;
              uStack_134 = 0;
              uStack_138 = 0;
              *(undefined4 *)(iStack_160 * 4 + param_1[0xe5]) = 0;
              FUN_004b4b20(iStack_160 * 4 + param_1[0xe5],afStack_15c);
              FUN_0049c640();
              iStack_160 = iStack_160 + 1;
            } while (iStack_160 < *(char *)(param_1[0x96] + 0xb0));
          }
        }
        ExceptionList = local_c;
        return 1;
      }
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  ExceptionList = local_c;
  return uVar2;
}
```
