# Raw capture: FUN_004e0ad0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e0ad0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004e0ad0` |
| **Canonical name** | `FUN_004e0ad0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004e0ad0(void *param_1)

{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int *extraout_EAX;
  undefined4 uVar5;
  uint uVar6;
  int *unaff_EDI;
  float fVar7;
  float fVar8;
  undefined4 local_70 [6];
  float fStack_58;
  undefined1 auStack_54 [4];
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  
  if (((*(int *)((int)param_1 + 0xe4e8) != 0) && (*(int *)((int)param_1 + 0xe64c) != 0)) &&
     (0 < *(int *)(*(int *)((int)param_1 + 0xe64c) + 0xc))) {
    if ((*(char *)((int)param_1 + 0x7e) != '\0') &&
       (SQRT(*(float *)((int)param_1 + 0x120) * *(float *)((int)param_1 + 0x120) +
             *(float *)((int)param_1 + 0x118) * *(float *)((int)param_1 + 0x118)) < g_flOne)) {
      FUN_004d5110(0,0,0,&local_50,local_70,0);
      *(undefined4 *)((int)param_1 + 0x118) = local_50;
      *(undefined4 *)((int)param_1 + 0x120) = local_48;
    }
    FUN_0076c500(1000);
    piVar3 = (int *)FUN_0040b020();
    while (piVar3 != (int *)0x0) {
      FUN_004bc180(piVar3);
      uVar6 = piVar3[0x5f];
      if (((uVar6 >> 9 & 1) == 0) && ((uVar6 >> 0xe & 1) == 0)) {
        CVOGReaction_RemoveObject(param_1,piVar3[0x58],piVar3[0x59],'\0');
        goto LAB_004e0e59;
      }
      iVar4 = *(int *)(piVar3[0x2a] + 0x38);
      if ((((iVar4 == 0x36) || (iVar4 == 0x3a)) || (iVar4 == 0x38)) ||
         (((uVar6 >> 0xe & 1) != 0 || (*(short *)(*(int *)(piVar3[0x2a] + 0x3c) + 0x3f4) == 0xc))))
      {
LAB_004e0c2a:
        bVar1 = false;
      }
      else {
        iVar4 = (**(code **)(*piVar3 + 0x1cc))();
        if (iVar4 != 0) {
          (**(code **)(*piVar3 + 0x1cc))();
          cVar2 = FUN_00581dd0();
          if (cVar2 == '\0') goto LAB_004e0c2a;
        }
        bVar1 = true;
      }
      iVar4 = piVar3[0x2a];
      if (*(short *)(*(int *)(iVar4 + 0x3c) + 0x3f4) == 3) {
        if (iVar4 == 0) {
          local_70[0] = 0xffffffff;
        }
        else {
          local_70[0] = *(undefined4 *)(iVar4 + 0x34);
        }
        Map_LowerBoundFindByIntKey((void *)((int)param_1 + 0xe8f8),auStack_54,local_70,unaff_EDI);
        if (*extraout_EAX != *(int *)((int)param_1 + 0xe8fc)) goto LAB_004e0d03;
        if (iVar4 == 0) {
          local_50 = 0xffffffff;
        }
        else {
          local_50 = *(undefined4 *)(iVar4 + 0x34);
        }
        uStack_4c = 1;
        FUN_0041b1e0(local_70,&local_50);
LAB_004e0ca6:
        iVar4 = (**(code **)(*piVar3 + 0x1cc))();
        if (iVar4 == 0) {
          FUN_004f1c70();
          (**(code **)(*piVar3 + 0xb4))();
        }
        else {
          iVar4 = (**(code **)(*piVar3 + 0x1cc))();
          uVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 300))();
          (**(code **)(*piVar3 + 0x1cc))(uVar5);
          FUN_005815a0(uVar5);
          uVar5 = (**(code **)(*piVar3 + 0x1cc))();
          FUN_004bfa80(uVar5);
        }
        uVar6 = FUN_0076c3c0();
        if (99 < uVar6) break;
      }
      else {
LAB_004e0d03:
        if (!bVar1) goto LAB_004e0ca6;
        fVar7 = (float)piVar3[0x20] - *(float *)((int)param_1 + 0x118);
        fVar8 = (float)piVar3[0x22] - *(float *)((int)param_1 + 0x120);
        fStack_58 = fVar8 * fVar8 + fVar7 * fVar7;
        fVar7 = (float)s__T_JDynamic_culling_009c7a04._0_4_;
        if (((uint)piVar3[0x5f] >> 0x12 & 1) == 0) {
          fVar7 = DAT_00a0f6f4;
        }
        if (0 < piVar3[0x45]) {
          fVar7 = DAT_00aaaafc;
        }
        if (((*(char *)((int)param_1 + 0x7e) == '\0') &&
            (iVar4 = (**(code **)(*piVar3 + 0x1d0))(), iVar4 != 0)) &&
           ((*(char *)((int)param_1 + 0xf5) == '\0' &&
            (((*(byte *)(*(int *)(piVar3[0x2a] + 0x3c) + 0x3f2) >> 1 & 1) == 0 &&
             (*(float *)(*(int *)(piVar3[0x2a] + 0x3c) + 0x3e4) != g_flZero)))))) {
          uVar5 = 0;
          (**(code **)(*piVar3 + 0x1cc))(0);
          FUN_005815a0(uVar5);
        }
        else {
          if (fStack_58 <= fVar7) goto LAB_004e0ca6;
          iVar4 = (**(code **)(*piVar3 + 0x1cc))();
          if (iVar4 != 0) {
            iVar4 = (**(code **)(*piVar3 + 0x1cc))();
            uVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 300))();
            (**(code **)(*piVar3 + 0x1cc))(uVar5);
            FUN_005815a0(uVar5);
            piVar3 = (int *)(**(code **)(*piVar3 + 0x1cc))();
            (**(code **)(*piVar3 + 0x18))(1);
          }
        }
      }
LAB_004e0e59:
      piVar3 = (int *)FUN_0040b020();
    }
    if (*(int *)(*(int *)((int)param_1 + 0xe64c) + 0xc) < 1) {
      FUN_004e09e0();
    }
  }
  return;
}
```
