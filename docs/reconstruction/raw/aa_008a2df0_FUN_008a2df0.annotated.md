# Annotated low-level: FUN_008a2df0

| Field | Value |
|---|---|
| Stable ID | `aa_008a2df0` |
| VA | `0x008a2df0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008a2df0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008a2df0(int *param_1)

{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  void *pvVar7;
  void *unaff_EBP;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  void *pvStack_90;
  undefined1 auStack_8c [4];
  void *pvStack_88;
  int *piStack_84;
  int iStack_80;
  undefined1 auStack_7c [4];
  int *piStack_78;
  undefined4 *puStack_74;
  int iStack_70;
  uint uStack_6c;
  int iStack_68;
  undefined1 auStack_64 [4];
  int *piStack_60;
  int iStack_5c;
  undefined4 auStack_58 [2];
  int iStack_50;
  uint auStack_4c [2];
  undefined1 auStack_44 [4];
  undefined1 auStack_40 [16];
  undefined1 auStack_30 [4];
  undefined1 auStack_2c [32];
  void *local_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  puStack_8 = &LAB_009ad270;
  local_c = ExceptionList;
  pvVar7 = (void *)0x0;
  if (((param_1[0x156] != 0) &&
      (ExceptionList = &local_c, cVar2 = (**(code **)(*param_1 + 0x3d8))(), cVar2 != '\0')) &&
     (DAT_00d1b6d8 != 0)) {
    piVar3 = (int *)(**(code **)(*(int *)param_1[0x156] + 0x140))(&uStack_6c,1);
    param_1[0x14f] = *piVar3;
    param_1[0x150] = 0;
    param_1[0x149] = 0;
    FUN_008a2670();
    pvStack_88 = (void *)0x0;
    bVar1 = false;
    piStack_84 = (int *)0x0;
    iStack_80 = 0;
    piStack_60 = (int *)0x0;
    iStack_5c = 0;
    auStack_58[0] = 0;
    piStack_78 = (int *)0x0;
    puStack_74 = (undefined4 *)0x0;
    iStack_70 = 0;
    iStack_4 = 2;
    for (uVar8 = 0; (param_1[0x16d] != 0 && (uVar8 < (uint)(param_1[0x16e] - param_1[0x16d] >> 2)));
        uVar8 = uVar8 + 1) {
      FUN_00411180();
    }
    uVar8 = 0;
    while ((iVar11 = param_1[0x169], iVar11 != 0 && (uVar8 < (uint)(param_1[0x16a] - iVar11 >> 2))))
    {
      puVar5 = (undefined4 *)(iVar11 + uVar8 * 4);
      if ((piStack_78 == (int *)0x0) ||
         ((uint)(iStack_70 - (int)piStack_78 >> 2) <= (uint)((int)puStack_74 - (int)piStack_78 >> 2)
         )) {
        FUN_00419880(auStack_7c,puStack_74,puVar5);
        uVar8 = uVar8 + 1;
      }
      else {
        *puStack_74 = *puVar5;
        puStack_74 = puStack_74 + 1;
        uVar8 = uVar8 + 1;
      }
    }
    FUN_008a2410(param_1,auStack_7c);
    FUN_008a20b0(auStack_64);
    piVar3 = piStack_60;
    piVar9 = piStack_60;
    for (uStack_6c = 0; (piVar3 != (int *)0x0 && (uStack_6c < (uint)(iStack_5c - (int)piVar3 >> 2)))
        ; uStack_6c = uStack_6c + 1) {
      if (*piVar9 != 0) {
        if ((pvVar7 == (void *)0x0) ||
           ((uint)(iStack_80 - (int)pvVar7 >> 2) <= (uint)((int)piStack_84 - (int)pvVar7 >> 2))) {
          FUN_00419880(auStack_8c,piStack_84,piVar9);
          pvVar7 = pvStack_88;
        }
        else {
          *piStack_84 = *piVar9;
          piStack_84 = piStack_84 + 1;
        }
        auStack_4c[0] = 0;
        piVar10 = piStack_78;
        while ((piVar3 = piStack_60, piStack_78 != (int *)0x0 &&
               (auStack_4c[0] < (uint)((int)puStack_74 - (int)piStack_78 >> 2)))) {
          iVar11 = *(int *)(*piVar10 + 0x504);
          if (iVar11 == 0) {
LAB_008a30fe:
            auStack_4c[0] = auStack_4c[0] + 1;
            piVar10 = piVar10 + 1;
          }
          else {
            if (param_1[0x143] == 0) {
              iVar11 = *(int *)(*piVar9 + 0x110);
              iVar4 = FUN_0059db80(DAT_00d1b6d8);
            }
            else {
              iVar4 = *(int *)(iVar11 + 0x120);
              if ((iVar4 == -1) &&
                 ((*(int *)(iVar11 + 0x14c) == 0 ||
                  (iVar4 = *(int *)(*(int *)(iVar11 + 0x14c) + 0xfc), iVar4 == -1))))
              goto LAB_008a30fe;
              iVar11 = *(int *)(*piVar9 + 0x110);
            }
            if (iVar4 != iVar11) goto LAB_008a30fe;
            piVar3 = *(int **)param_1[0x171];
            if (piVar3 != (int *)param_1[0x171]) {
              do {
                if (piVar3[2] == iVar11) {
                  (**(code **)(*(int *)*piVar10 + 0xcc))(0);
                  (**(code **)(*(int *)*piVar10 + 0x34c))();
                  goto LAB_008a30fe;
                }
                piVar3 = (int *)*piVar3;
              } while (piVar3 != (int *)param_1[0x171]);
            }
            if ((pvVar7 == (void *)0x0) ||
               ((uint)(iStack_80 - (int)pvVar7 >> 2) <= (uint)((int)piStack_84 - (int)pvVar7 >> 2)))
            {
              FUN_00419880(auStack_8c,piStack_84,piVar10);
              auStack_4c[0] = auStack_4c[0] + 1;
              piVar10 = piVar10 + 1;
              pvVar7 = pvStack_88;
            }
            else {
              *piStack_84 = *piVar10;
              piStack_84 = piStack_84 + 1;
              auStack_4c[0] = auStack_4c[0] + 1;
              piVar10 = piVar10 + 1;
            }
          }
        }
      }
      piVar9 = piVar9 + 1;
    }
    pvStack_90 = pvVar7;
    if (pvVar7 != (void *)0x0) {
      pvStack_90 = (void *)((int)piStack_84 - (int)pvVar7 >> 2);
    }
    if ((int)pvStack_90 <= param_1[0x147]) {
      param_1[0x147] = (int)pvStack_90 - 1U & ((int)((int)pvStack_90 - 1U) < 1) - 1;
    }
    iVar11 = 0;
    if (0 < param_1[0x147]) {
      do {
        piVar3 = *(int **)((int)pvVar7 + iVar11 * 4);
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 0xcc))(0);
          (**(code **)(**(int **)((int)pvVar7 + iVar11 * 4) + 0x34c))();
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < param_1[0x147]);
    }
    for (iVar11 = param_1[0x147]; iVar11 < (int)pvStack_90; iVar11 = iVar11 + 1) {
      if (*(int *)((int)pvVar7 + iVar11 * 4) != 0) {
        if (bVar1) {
LAB_008a329d:
          (**(code **)(**(int **)((int)pvVar7 + iVar11 * 4) + 0xcc))(0);
          (**(code **)(**(int **)((int)pvVar7 + iVar11 * 4) + 0x118))(auStack_58);
        }
        else {
          puVar5 = (undefined4 *)(**(code **)(*(int *)param_1[0x156] + 0x120))(auStack_4c,1,0);
          piStack_60 = (int *)*puVar5;
          if (iVar11 == param_1[0x147]) {
            iVar4 = (**(code **)(*(int *)param_1[0x156] + 0x120))(auStack_30);
            iStack_68 = *(int *)(iVar4 + 4);
          }
          else {
            piVar3 = *(int **)((int)pvVar7 + iVar11 * 4 + -4);
            iVar4 = (**(code **)(*piVar3 + 0x120))(auStack_40,1,0);
            iVar4 = *(int *)(iVar4 + 4);
            iVar6 = (**(code **)(*piVar3 + 0x140))(&iStack_5c,1);
            iStack_68 = *(int *)(iVar6 + 4) + param_1[0x14e] + iVar4;
            pvVar7 = unaff_EBP;
          }
          piVar3 = *(int **)((int)pvVar7 + iVar11 * 4);
          (**(code **)(*(int *)param_1[0x156] + 0x120))(auStack_2c,1,0);
          (**(code **)(*(int *)param_1[0x156] + 0x140))(auStack_40,1);
          iVar4 = (**(code **)(*piVar3 + 0x140))(auStack_58,1);
          pvVar7 = pvStack_88;
          if ((int)uStack_6c < *(int *)(iVar4 + 4) + iStack_50) {
            bVar1 = true;
            goto LAB_008a329d;
          }
          param_1[0x149] = param_1[0x149] + 1;
          (**(code **)(**(int **)((int)pvStack_88 + iVar11 * 4) + 0xcc))(1);
          FUN_00829fa0();
          (**(code **)(**(int **)((int)pvVar7 + iVar11 * 4) + 0x118))(auStack_58);
          pvVar7 = pvStack_90;
        }
        (**(code **)(**(int **)((int)pvVar7 + iVar11 * 4) + 0x34c))();
        iVar4 = (**(code **)(**(int **)((int)pvVar7 + iVar11 * 4) + 0x140))(auStack_44,1);
        param_1[0x150] = param_1[0x150] + *(int *)(iVar4 + 4);
      }
    }
    if ((int *)param_1[0x15a] != (int *)0x0) {
      iVar11 = param_1[0x148];
      iVar4 = param_1[0x149];
      iVar6 = *(int *)param_1[0x15a];
      if (iVar11 - iVar4 == 0) {
        (**(code **)(iVar6 + 0x460))(0x3f800000);
        (**(code **)(*(int *)param_1[0x15a] + 0xd4))(0);
      }
      else {
        (**(code **)(iVar6 + 0xd4))(1);
        (**(code **)(*(int *)param_1[0x15a] + 0x460))(g_flOne / (float)(iVar11 - iVar4));
      }
    }
    iStack_4 = CONCAT31(iStack_4._1_3_,1);
    if (piStack_78 != (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(piStack_78);
    }
    piStack_78 = (int *)0x0;
    puStack_74 = (undefined4 *)0x0;
    iStack_70 = 0;
    iStack_4 = (uint)iStack_4._1_3_ << 8;
    if (piStack_60 != (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(piStack_60);
    }
    piStack_60 = (int *)0x0;
    iStack_5c = 0;
    auStack_58[0] = 0;
    iStack_4 = 0xffffffff;
    if (pvVar7 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar7);
    }
  }
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
