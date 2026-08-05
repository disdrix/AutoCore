# Raw capture: Skill_GatherTargetsInArea

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058d330` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0058d330` |
| **Canonical name** | `Skill_GatherTargetsInArea` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Skill_GatherTargetsInArea — area/chain target collection (INFERRED)
   
   Called when skill flags request multi-target resolution; fills TFID list around origin. */

void Skill_GatherTargetsInArea
               (int param_1,int param_2,undefined4 param_3,int *param_4,undefined4 *param_5,
               undefined4 param_6,int param_7,int param_8,undefined4 param_9,char param_10,
               char param_11,undefined4 param_12,undefined4 param_13,char param_14,
               undefined4 param_15)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  void *pvVar7;
  int *piVar8;
  bool bVar9;
  float10 fVar10;
  int iStack_dc;
  uint uStack_d8;
  int local_d4;
  undefined4 uStack_d0;
  void *pvStack_cc;
  int *piStack_c8;
  int iStack_c4;
  int iStack_b4;
  undefined1 local_b0 [4];
  undefined4 *local_ac;
  undefined4 local_a8;
  float fStack_a4;
  undefined1 auStack_a0 [4];
  void *pvStack_9c;
  int iStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  int iStack_6c;
  float afStack_68 [2];
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  undefined1 auStack_50 [24];
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [20];
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a5795;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  local_ac = (undefined4 *)FUN_0058d9c0();
  *(undefined1 *)((int)local_ac + 0x29) = 1;
  local_ac[1] = local_ac;
  *local_ac = local_ac;
  piVar8 = (int *)0x0;
  local_ac[2] = local_ac;
  local_a8 = 0;
  local_80 = *param_5;
  local_7c = param_5[1];
  local_78 = param_5[2];
  local_74 = param_5[3];
  local_14 = 0;
  local_d4 = param_2;
  iStack_6c = (**(code **)(*param_4 + 0x1c8))();
  if (iStack_6c == 0) {
    FUN_00567ce0(&DAT_00af32a0,0x38d1b717);
    uStack_90 = uStack_d0;
    uStack_8c = pvStack_cc;
    uStack_88 = piStack_c8;
  }
  else {
    puVar2 = (undefined4 *)
             (**(code **)(*(int *)(*(int *)(*(int *)(iStack_6c + 4) + 4) + 4 + iStack_6c) + 0x1a4))
                       ();
    uStack_90 = *puVar2;
    uStack_8c = puVar2[1];
    uStack_88 = puVar2[2];
    iStack_c4 = puVar2[3];
  }
  uStack_84 = iStack_c4;
  FUN_004e8a40(&uStack_90,auStack_50);
  pvVar7 = (void *)0x0;
  pvStack_cc = (void *)0x0;
  piStack_c8 = (int *)0x0;
  iStack_c4 = 0;
  pvStack_9c = (void *)0x0;
  iStack_98 = 0;
  uStack_94 = 0;
  local_14 = CONCAT31(local_14._1_3_,2);
  uVar3 = 1;
  if (0 < param_8) {
    if (param_8 < 3) {
      uVar3 = 0x11;
    }
    else if (param_8 == 7) {
      uVar3 = 10;
    }
  }
  FUN_004ea350(param_3,param_5,param_6,auStack_a0,0,uVar3);
  uStack_d8 = 0;
  while ((pvStack_9c != (void *)0x0 && (uStack_d8 < (uint)(iStack_98 - (int)pvStack_9c >> 2)))) {
    iVar5 = *(int *)((int)pvStack_9c + uStack_d8 * 4);
    if (param_8 == 7) {
      iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x1dc))();
      bVar9 = iVar4 == 0;
LAB_0058d521:
      if (bVar9) {
LAB_0058d534:
        iVar4 = *(int *)(*(int *)(iVar5 + 4) + 4);
        if (*(int *)(iVar4 + 0xd4 + iVar5) == 0) goto LAB_0058d547;
        goto LAB_0058d55a;
      }
      iStack_dc = *(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5;
LAB_0058d55d:
      if ((pvVar7 == (void *)0x0) ||
         ((uint)(iStack_c4 - (int)pvVar7 >> 2) <= (uint)((int)piVar8 - (int)pvVar7 >> 2))) {
        FUN_004073a0(piVar8,1,&iStack_dc);
        pvVar7 = pvStack_cc;
        piVar8 = piStack_c8;
        goto LAB_0058d5a7;
      }
      *piVar8 = iStack_dc;
      piVar8 = piVar8 + 1;
      uStack_d8 = uStack_d8 + 1;
      piStack_c8 = piVar8;
    }
    else {
      if (param_8 == 10) {
        cVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x198))();
        bVar9 = cVar1 == '\0';
        goto LAB_0058d521;
      }
      if (param_8 != 6) goto LAB_0058d534;
LAB_0058d547:
      iVar4 = *(int *)(*(int *)(iVar5 + 4) + 4);
      if (*(int *)(iVar4 + 0xdc + iVar5) != 0) {
LAB_0058d55a:
        iStack_dc = iVar4 + iVar5 + 4;
        goto LAB_0058d55d;
      }
LAB_0058d5a7:
      uStack_d8 = uStack_d8 + 1;
    }
  }
  if (pvVar7 == (void *)0x0) {
    uStack_d8 = 0;
  }
  else {
    uStack_d8 = (int)piVar8 - (int)pvVar7 >> 2;
  }
  iStack_dc = 0;
  iVar5 = (**(code **)(*param_4 + 0x19c))();
  if (iVar5 != 0) {
    iVar5 = (**(code **)(*param_4 + 0x19c))();
    iStack_dc = *(int *)(iVar5 + 0x34);
  }
  iStack_b4 = 0;
  if (0 < (int)uStack_d8) {
    do {
      iVar5 = iStack_6c;
      piVar8 = *(int **)((int)pvVar7 + iStack_b4 * 4);
      if ((((param_10 == '\0') || (iStack_6c == 0)) ||
          (iVar4 = (**(code **)(*piVar8 + 0x1c8))(), iVar4 != iVar5)) &&
         (cVar1 = FUN_0058a810(piVar8,param_4,param_1,param_8,param_9,param_12,param_13,auStack_30),
         cVar1 != '\0')) {
        piVar6 = (int *)(**(code **)(*param_4 + 0x19c))();
        if (piVar6 != (int *)0x0) {
          piVar6 = (int *)(*(int *)(piVar6[1] + 4) + 4 + (int)piVar6);
        }
        if (((piVar6 != piVar8) || (param_8 == 0)) ||
           ((param_8 == 0xb || ((param_8 == 1 && (param_11 != '\0')))))) {
          iVar5 = (**(code **)(*param_4 + 0x210))(0);
          uVar3 = (**(code **)(*piVar8 + 0x1c8))(&iStack_54,param_15,iVar5 != 0);
          fVar10 = (float10)FUN_004e9aa0(&local_80,iStack_dc,param_6,uVar3);
          fStack_a4 = (float)fVar10;
          if (param_14 == '\0') {
            piVar6 = (int *)((short)local_d4 * 0x10 + param_1);
            *piVar6 = piVar8[0x58];
            piVar6[1] = piVar8[0x59];
            piVar6[2] = piVar8[0x5a];
            local_d4 = local_d4 + 1;
            piVar6[3] = piVar8[0x5b];
            if (param_10 != '\0') {
              iVar5 = (**(code **)(*piVar8 + 0x1c8))();
              if (*(int *)(iVar5 + 8) == 0) {
                puVar2 = (undefined4 *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0x84 + iVar5);
              }
              else {
                puVar2 = (undefined4 *)(*(int *)(*(int *)(iVar5 + 8) + 0x3c) + 0xb0);
              }
              local_80 = *puVar2;
              local_7c = puVar2[1];
              local_78 = puVar2[2];
              local_74 = puVar2[3];
            }
            if ((param_7 != 0) && (param_7 = param_7 + -1, param_7 < 1)) goto LAB_0058d836;
          }
          else if (g_flZero < fStack_a4) {
            iStack_60 = piVar8[0x58];
            iStack_5c = piVar8[0x59];
            iStack_58 = piVar8[0x5a];
            iStack_54 = piVar8[0x5b];
            afStack_68[0] = fStack_a4;
            FUN_0058def0(auStack_38,afStack_68);
          }
        }
        if ((short)local_d4 == 99) break;
      }
      iStack_b4 = iStack_b4 + 1;
    } while (iStack_b4 < (int)uStack_d8);
  }
  if (param_14 != '\0') {
    local_d4 = FUN_0058c7a0(param_1,local_b0,param_7,(int)(short)local_d4);
  }
LAB_0058d836:
  puVar2 = (undefined4 *)((short)local_d4 * 0x10 + param_1);
  *puVar2 = DAT_009d4d28;
  puVar2[1] = DAT_009d4d2c;
  puVar2[2] = DAT_009d4d30;
  puVar2[3] = DAT_009d4d34;
  if (pvStack_9c != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(pvStack_9c);
  }
  pvStack_9c = (void *)0x0;
  iStack_98 = 0;
  uStack_94 = 0;
  if (pvVar7 == (void *)0x0) {
    local_14 = 0xffffffff;
    FUN_0058df60(&fStack_a4,*local_ac,local_ac);
                    /* WARNING: Subroutine does not return */
    operator_delete(local_ac);
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(pvVar7);
}
```
