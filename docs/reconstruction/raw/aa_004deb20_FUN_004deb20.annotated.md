# Annotated low-level: FUN_004deb20

| Field | Value |
|---|---|
| Stable ID | `aa_004deb20` |
| VA | `0x004deb20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004deb20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Type propagation algorithm not settling */

undefined4 __thiscall
FUN_004deb20(void *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  LONG *pLVar1;
  LONG LVar2;
  char cVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  uint *puVar7;
  uint uVar8;
  char *pcVar9;
  LONG *pLVar10;
  int iVar11;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  int iVar12;
  LONG *pLVar13;
  undefined4 *puVar14;
  LONG *pLVar15;
  undefined4 *puVar16;
  undefined1 uVar17;
  uint local_e54;
  undefined1 auStack_e50 [3];
  undefined1 local_e4d;
  int iStack_e4c;
  uint uStack_e48;
  uint uStack_e44;
  int iStack_e40;
  int local_e3c;
  uint uStack_e38;
  undefined4 local_e34;
  int local_e30;
  undefined4 local_e2c;
  uint uStack_e28;
  int iStack_e20;
  int iStack_e1c;
  int local_e18;
  int *local_e14;
  int iStack_e10;
  uint auStack_e0c [36];
  int local_d7c;
  int local_d78;
  undefined4 local_d74 [15];
  uint local_d38;
  LARGE_INTEGER local_d34;
  uint uStack_d2c;
  LARGE_INTEGER local_d28;
  undefined4 uStack_d20;
  undefined4 uStack_d1c;
  undefined4 uStack_d18;
  undefined4 uStack_d14;
  uint auStack_d10 [16];
  LARGE_INTEGER local_cd0 [33];
  char acStack_bc4 [263];
  undefined1 auStack_abd [3];
  char acStack_aba [1026];
  undefined **ppuStack_6b8;
  undefined1 uStack_6b3;
  undefined1 uStack_6b2;
  int *piStack_24;
  void *pvStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a245b;
  local_1c = ExceptionList;
  if (*(int *)((int)param_1 + 0xe4f8) != 0) {
    ExceptionList = &local_1c;
    if (*(int *)((int)param_1 + 0xe50c) != 0) {
      ExceptionList = &local_1c;
      FUN_005aa890();
    }
    *(undefined1 *)((int)param_1 + 0x40) = 0;
    FUN_004e2880(*(undefined4 *)(*(int *)((int)param_1 + 0x38) + 4));
    *(int *)(*(int *)((int)param_1 + 0x38) + 4) = *(int *)((int)param_1 + 0x38);
    auStack_e0c[1] = 0;
    auStack_e0c[0x10] = 0;
    auStack_e0c[2] = 0;
    auStack_e0c[0x11] = 0;
    *(undefined4 *)((int)param_1 + 0x3c) = 0;
    *(undefined4 *)*(undefined4 *)((int)param_1 + 0x38) = *(undefined4 *)((int)param_1 + 0x38);
    auStack_d10[1] = 0;
    auStack_d10[2] = 0;
    auStack_e0c[3] = 0;
    auStack_d10[3] = 0;
    auStack_e0c[0x12] = 0;
    auStack_e0c[4] = 0;
    auStack_d10[4] = 0;
    auStack_e0c[0x13] = 0;
    auStack_e0c[5] = 0;
    auStack_d10[5] = 0;
    auStack_e0c[0x14] = 0;
    auStack_e0c[6] = 0;
    auStack_d10[6] = 0;
    auStack_e0c[0x15] = 0;
    auStack_e0c[7] = 0;
    auStack_d10[7] = 0;
    auStack_e0c[0x16] = 0;
    auStack_e0c[8] = 0;
    auStack_d10[8] = 0;
    auStack_e0c[0x17] = 0;
    auStack_e0c[9] = 0;
    auStack_d10[9] = 0;
    auStack_e0c[0x18] = 0;
    auStack_e0c[10] = 0;
    auStack_d10[10] = 0;
    auStack_e0c[0x19] = 0;
    auStack_e0c[0xb] = 0;
    auStack_d10[0xb] = 0;
    auStack_e0c[0x1a] = 0;
    auStack_e0c[0xc] = 0;
    auStack_d10[0xc] = 0;
    auStack_e0c[0x1b] = 0;
    auStack_e0c[0xd] = 0;
    auStack_d10[0xd] = 0;
    auStack_e0c[0x1c] = 0;
    auStack_e0c[0xe] = 0;
    auStack_d10[0xe] = 0;
    auStack_e0c[0x1d] = 0;
    *(int *)(*(int *)((int)param_1 + 0x38) + 8) = *(int *)((int)param_1 + 0x38);
    auStack_e0c[0xf] = 0;
    auStack_d10[0xf] = 0;
    auStack_e0c[0x1e] = 0;
    iVar12 = 0;
    do {
      local_e14 = operator_new(0x30);
      local_14 = 0;
      if (local_e14 == (void *)0x0) {
        uVar4 = 0;
      }
      else {
        uVar4 = FUN_0076c500(10000);
      }
      *(undefined4 *)((int)local_d74 + iVar12) = uVar4;
      iVar12 = iVar12 + 4;
      local_14 = 0xffffffff;
    } while (iVar12 < 0x3c);
    local_e30 = 0;
    FUN_0076c4d0();
    FUN_0076c4d0();
    FUN_004ce020(param_2);
    *(undefined1 *)(*(int *)((int)param_1 + 0xe894) + 0x8b) = 1;
    QueryPerformanceFrequency(local_cd0);
    QueryPerformanceCounter(&local_d28);
    *(undefined4 **)((int)param_1 + 0xe504) = param_4;
    FUN_005126f0();
    piVar5 = (int *)FUN_004ddcc0(&local_d7c,&local_d78,&local_d38,&local_e18);
    if (piVar5 != (int *)0x0) {
      auStack_e0c[0x1f] = 0;
      auStack_e0c[0x20] = 0;
      auStack_e0c[0x21] = 0;
      auStack_e0c[0x22] = 0;
      local_e3c = 0;
      local_e54 = 0;
      *(uint *)((int)param_1 + 0xe6d8) = local_d38 + 1;
      *(DWORD *)((int)param_1 + 0xe6dc) = local_d34.s.LowPart + (0xfffffffe < local_d38);
      local_e2c = 0;
      local_e34 = 0;
      uVar17 = (undefined1)((uint)unaff_ESI >> 0x18);
      local_e14 = piVar5;
      if (0 < local_e18) {
        do {
          local_e4d = 0;
          if (4 < *(int *)((int)param_1 + 0x8c)) {
            (**(code **)(*piVar5 + 0x14))();
          }
          uVar4 = 4;
          piVar6 = &iStack_e4c;
          (**(code **)(*piVar5 + 0x14))();
          FUN_00513880(piVar5,auStack_e50,piVar6,uVar4);
          (**(code **)(*piVar5 + 0x14))(&uStack_e48,4);
          piVar6 = (int *)CVOGReaction_GiveItemByCbid(iStack_e4c);
          if (piVar6 == (int *)0x0) {
LAB_004df108:
            iStack_e1c = iStack_e4c >> 0x1f;
            iStack_e20 = iStack_e4c;
            uStack_e38 = uStack_e48;
            cVar3 = FUN_004cd3c0(piVar5,&uStack_e38,&iStack_e20,iStack_e40,piVar6,local_e2c,
                                 local_e3c);
            if (cVar3 == '\0') {
              (**(code **)*piVar5)(1);
              ExceptionList = pvStack_20;
              return 0;
            }
          }
          else {
            uStack_e38 = (**(code **)(*piVar6 + 8))(iStack_e4c,param_1,1);
            if (((int)uStack_e38 < 0) ||
               (uStack_e48 = __RTDynamicCast(piVar6,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                             &CVOGMapModulePlacement::RTTI_Type_Descriptor,0),
               uStack_e48 == 0)) {
              (**(code **)*piVar6)(1);
              goto LAB_004df108;
            }
            *(undefined1 *)(piVar6 + 0x5e) = uVar17;
            (**(code **)(*piVar6 + 0x218))(param_1);
            FUN_00512160(unaff_EBX,local_e54,0);
            if (*(char *)((int)param_1 + 0x7d) == '\0') {
              if (*(char *)((int)param_1 + 0x7e) == '\0') {
LAB_004def89:
                cVar3 = (**(code **)(*piVar6 + 0xa4))
                                  (piVar5,*(undefined4 *)((int)param_1 + 0x8c),auStack_e0c + 0x1b,0)
                ;
                if (cVar3 == '\0') {
                  (**(code **)*piVar6)(1);
                }
                else {
                  (**(code **)(*piVar6 + 0xb4))();
                  if ((int)local_e54 < (int)(uint)*(ushort *)((int)param_1 + 0x940)) {
                    puVar7 = (uint *)((int)param_1 + local_e54 * 0x18 + 0x950);
                    while ((*puVar7 != uStack_e48 || (puVar7[1] != uStack_e44))) {
                      if (((int)uStack_e44 < (int)puVar7[1]) ||
                         (((int)uStack_e44 <= (int)puVar7[1] && (uStack_e48 <= *puVar7))))
                      goto LAB_004df147;
                      local_e54 = local_e54 + 1;
                      puVar7 = puVar7 + 6;
                      if ((int)(uint)*(ushort *)((int)param_1 + 0x940) <= (int)local_e54)
                      goto LAB_004df147;
                    }
                    uStack_e38 = FUN_004e53a0(*(undefined4 *)
                                               ((int)param_1 + (local_e54 * 3 + 300) * 8));
                    if (uStack_e38 != 0) {
                      *(undefined4 *)((int)param_1 + 0xe6d8) =
                           *(undefined4 *)((int)param_1 + local_e54 * 0x18 + 0x958);
                      *(undefined4 *)((int)param_1 + 0xe6dc) =
                           *(undefined4 *)((int)param_1 + local_e54 * 0x18 + 0x95c);
                      FUN_004db820();
                      iVar12 = *(int *)(*(int *)(local_e3c + 4) + 4);
                      uStack_d20 = *(undefined4 *)(iVar12 + 0x84 + local_e3c);
                      uStack_d1c = *(undefined4 *)(iVar12 + 0x88 + local_e3c);
                      uStack_d18 = *(undefined4 *)(iVar12 + 0x8c + local_e3c);
                      uStack_d14 = *(undefined4 *)(iVar12 + 0x90 + local_e3c);
                      uStack_e28 = CONCAT31(uStack_e28._1_3_,(char)piVar6[0x5e]);
                      FUN_005ea300(param_1,&uStack_d20,uStack_e28);
                    }
                    local_e54 = local_e54 + 1;
                  }
                }
              }
              else {
                (**(code **)(*piVar6 + 0xa4))
                          (piVar5,*(undefined4 *)((int)param_1 + 0x8c),auStack_e0c + 0x1b,0);
                FUN_004de350(local_e3c);
              }
            }
            else {
              if (param_4 == (undefined4 *)0x0) goto LAB_004def89;
              cVar3 = (**(code **)*param_4)(piVar6);
              if (cVar3 == '\0') {
                (**(code **)*piVar6)(1);
                iVar12 = (**(code **)(*piVar5 + 4))(unaff_EBX,1);
                if (iVar12 == -1) goto LAB_004df695;
              }
              else {
                (*(code *)((undefined4 *)*piVar6)[0x29])
                          (piVar5,*(undefined4 *)((int)param_1 + 0x8c),auStack_e0c + 0x1a,0);
                if (((uint)piVar6[0x5f] >> 9 & 1) == 0) {
                  CVOGReaction_RemoveObject(param_1,piVar6[0x58],piVar6[0x59],'\0');
                }
                else {
                  (**(code **)(*piVar6 + 0xb4))();
                }
              }
            }
          }
LAB_004df147:
          local_e34 = local_e34 + 1;
        } while ((int)local_e34 < local_e18);
      }
      FUN_0076c4a0();
      iVar12 = FUN_0076c3c0();
      auStack_e0c[2] = auStack_e0c[2] + iVar12;
      FUN_0076c4d0();
      local_e34 = 0;
      if (*(void **)((int)param_1 + 0xe7fc) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        operator_delete(*(void **)((int)param_1 + 0xe7fc));
      }
      uStack_e28 = local_d7c + local_d78;
      *(undefined4 *)((int)param_1 + 0xe7fc) = 0;
      *(undefined4 *)((int)param_1 + 0xe800) = 0;
      *(undefined4 *)((int)param_1 + 0xe804) = 0;
      local_e54 = 0;
      if (uStack_e28 != 0) {
        do {
          FUN_0076c4a0();
          iVar12 = FUN_0076c3c0();
          auStack_e0c[3] = auStack_e0c[3] + iVar12;
          uVar8 = FUN_0076c3c0();
          if (auStack_e0c[0x12] <= uVar8) {
            auStack_e0c[0x12] = FUN_0076c3c0();
          }
          local_e30 = local_e30 + 1;
          FUN_0076c4d0();
          FUN_0076c4d0();
          local_e4d = 0;
          if (4 < *(int *)((int)param_1 + 0x8c)) {
            (**(code **)(*piVar5 + 0x14))();
          }
          uVar4 = 4;
          piVar6 = &iStack_e4c;
          (**(code **)(*piVar5 + 0x14))();
          FUN_00513880(piVar5,auStack_e50,piVar6,uVar4);
          (**(code **)(*piVar5 + 0x14))(&uStack_e48,4);
          FUN_0076c4a0();
          iVar12 = FUN_0076c3c0();
          auStack_e0c[4] = auStack_e0c[4] + iVar12;
          uVar8 = FUN_0076c3c0();
          if (auStack_e0c[0x13] <= uVar8) {
            auStack_e0c[0x13] = FUN_0076c3c0();
          }
          FUN_0076c4d0();
          piVar6 = (int *)CVOGReaction_GiveItemByCbid(iStack_e4c);
          FUN_0076c4a0();
          iVar12 = FUN_0076c3c0();
          auStack_e0c[5] = auStack_e0c[5] + iVar12;
          uVar8 = FUN_0076c3c0();
          if (auStack_e0c[0x14] <= uVar8) {
            auStack_e0c[0x14] = FUN_0076c3c0();
          }
          FUN_0076c4d0();
          if (piVar6 == (int *)0x0) {
LAB_004df6de:
            auStack_e0c[0] = iStack_e4c >> 0x1f;
            iStack_e10 = iStack_e4c;
            uStack_e38 = uStack_e48;
            cVar3 = FUN_004cd3c0(piVar5,&uStack_e38,&iStack_e10,iStack_e40,piVar6,local_e2c,
                                 local_e3c);
            if (cVar3 == '\0') {
              (**(code **)*piVar5)(1);
              ExceptionList = pvStack_20;
              return 0;
            }
          }
          else {
            uStack_e38 = (**(code **)(*piVar6 + 8))(iStack_e4c,param_1,1);
            if ((int)uStack_e38 < 0) {
              (**(code **)*piVar6)(1);
              goto LAB_004df6de;
            }
            *(undefined1 *)(piVar6 + 0x5e) = uVar17;
            if (*(int *)(piVar6[0x2a] + 0x38) == 1) {
              iStack_e40 = iStack_e40 + 1;
            }
            FUN_0076c4a0();
            iVar12 = FUN_0076c3c0();
            auStack_e0c[3] = auStack_e0c[3] + iVar12;
            uVar8 = FUN_0076c3c0();
            if (auStack_e0c[0x12] <= uVar8) {
              auStack_e0c[0x12] = FUN_0076c3c0();
            }
            (**(code **)(*piVar6 + 0x218))(param_1);
            if (-1 < (int)uStack_e44) {
              FUN_00512160(uStack_e48,uStack_e44,0);
              iVar12 = *(int *)(piVar6[0x2a] + 0x3c);
              if (((*(short *)(iVar12 + 0x3f4) == 0xd) || (*(short *)(iVar12 + 0x3f4) == 0xe)) ||
                 (*(short *)(iVar12 + 0x3f4) == 0xf)) {
                iStack_e20 = piVar6[0x58];
                iStack_e1c = piVar6[0x59];
                FUN_00418d70(&iStack_e20);
              }
              if (param_4 == (undefined4 *)0x0) {
                FUN_007a4480();
              }
              else {
                iVar12 = FUN_004e23d0(uStack_e48,uStack_e44,&uStack_e38);
                if ((iVar12 == 0) || (*(int *)(iVar12 + 0xc) == 0)) {
                  FUN_0076c4d0();
                  cVar3 = (**(code **)(*piVar6 + 0xa4))
                                    (piVar5,*(undefined4 *)((int)param_1 + 0x8c),auStack_e0c + 0x1f,
                                     0);
                  if (cVar3 == '\0') {
                    (**(code **)*piVar6)(1);
                  }
                  else {
                    pcVar9 = (char *)FUN_005d6870((int)&local_e34 + 3);
                    if (*pcVar9 == '\0') {
                      FUN_007a4480(1,
                                   "Invalid load position for %I64d - %I32d. Moved To 30,900,30 - please fix immediately"
                                   ,unaff_EBX,local_e54,unaff_ESI);
                      iVar11 = DAT_00a0f694;
                      iVar12 = DAT_009cca58;
                      piVar6[0x20] = DAT_00a0f694;
                      piVar6[0x22] = iVar11;
                      piVar6[0x23] = 0;
                      piVar6[0x21] = iVar12;
                      piVar6[0x27] = 0;
                      piVar6[0x26] = 0;
                      piVar6[0x25] = 0;
                      piVar6[0x24] = 0;
                      piVar6[0x27] = (int)g_flOne;
                    }
                    (**(code **)*param_4)(piVar6);
                    FUN_0076c4a0();
                    iVar12 = FUN_0076c3c0();
                    auStack_e0c[2] = auStack_e0c[2] + iVar12;
                    uVar8 = FUN_0076c3c0();
                    if (auStack_e0c[0x11] <= uVar8) {
                      auStack_e0c[0x11] = FUN_0076c3c0();
                    }
                    FUN_0076c4d0();
                    (**(code **)(*piVar6 + 0xb4))();
                    FUN_0076c4a0();
                    iVar12 = FUN_0076c3c0();
                    auStack_e0c[8] = auStack_e0c[8] + iVar12;
                    uVar8 = FUN_0076c3c0();
                    if (auStack_e0c[0x17] <= uVar8) {
                      auStack_e0c[0x17] = FUN_0076c3c0();
                    }
                    FUN_0076c4d0();
                    if (((uint)piVar6[0x5f] >> 9 & 1) == 0) {
                      CVOGReaction_RemoveObject(param_1,piVar6[0x58],piVar6[0x59],'\0');
                    }
                    if (*(int *)(piVar6[0x2a] + 0x38) == 3) {
                      *(byte *)((int)piVar6 + 0x17d) = *(byte *)((int)piVar6 + 0x17d) | 0x10;
                    }
                    FUN_0076c4a0();
                    iVar12 = FUN_0076c3c0();
                    auStack_e0c[9] = auStack_e0c[9] + iVar12;
                    uVar8 = FUN_0076c3c0();
                    piVar5 = local_e14;
                    if (auStack_e0c[0x18] <= uVar8) {
                      auStack_e0c[0x18] = FUN_0076c3c0();
                      piVar5 = local_e14;
                    }
                  }
                }
                else {
                  (**(code **)*piVar6)(1);
                  iVar12 = (**(code **)(*piVar5 + 4))(uStack_e44);
                  if (iVar12 == -1) {
LAB_004df695:
                    FUN_007a4480(1,"Seek error, seeking %li bytes from current",iStack_e40);
                    (**(code **)*piVar5)(1);
                    ExceptionList = local_1c;
                    return 0;
                  }
                }
              }
            }
          }
          local_e54 = local_e54 + 1;
        } while (local_e54 < uStack_e28);
      }
      FUN_0076c4a0();
      iVar12 = FUN_0076c3c0();
      auStack_e0c[3] = auStack_e0c[3] + iVar12;
      uVar8 = FUN_0076c3c0();
      if (auStack_e0c[0x12] <= uVar8) {
        auStack_e0c[0x12] = FUN_0076c3c0();
      }
      local_e30 = local_e30 + 1;
      FUN_0076c4d0();
      FUN_0076c4a0();
      iVar12 = FUN_0076c3c0();
      auStack_e0c[10] = auStack_e0c[10] + iVar12;
      uVar8 = FUN_0076c3c0();
      if (auStack_e0c[0x19] <= uVar8) {
        auStack_e0c[0x19] = FUN_0076c3c0();
      }
      FUN_0076c4d0();
      FUN_0076c4a0();
      iVar12 = FUN_0076c3c0();
      auStack_e0c[0xb] = auStack_e0c[0xb] + iVar12;
      uVar8 = FUN_0076c3c0();
      if (auStack_e0c[0x1a] <= uVar8) {
        auStack_e0c[0x1a] = FUN_0076c3c0();
      }
      FUN_0076c4d0();
      FUN_0076c4a0();
      iVar12 = FUN_0076c3c0();
      auStack_e0c[0xc] = auStack_e0c[0xc] + iVar12;
      uVar8 = FUN_0076c3c0();
      if (auStack_e0c[0x1b] <= uVar8) {
        auStack_e0c[0x1b] = FUN_0076c3c0();
      }
      FUN_0076c4d0();
      if (0x2a < *(int *)((int)param_1 + 0x8c)) {
        (**(code **)(*piVar5 + 0x14))();
      }
      *(undefined4 *)((int)param_1 + 0xe504) = 0;
      FUN_004dc1c0();
      if (*(int *)((int)param_1 + 0x8c) < 0x26) {
        FUN_004cd9a0(piVar5);
      }
      if (0x29 < *(int *)((int)param_1 + 0x8c)) {
        FUN_004d6ff0();
      }
      FUN_00497c80();
      if (0x1d < *(int *)((int)param_1 + 0x8c)) {
        FUN_0079ce60();
        ppuStack_6b8 = &PTR_FUN_009cc008;
        uStack_6b3 = 1;
        uStack_6b2 = 0;
        local_14 = 1;
        piStack_24 = piVar5;
        FUN_00497d60(&ppuStack_6b8);
        FUN_00498380();
        FUN_00497690((int)param_1 + 0xe198);
        local_14 = 0xffffffff;
        ppuStack_6b8 = &PTR_LAB_009cbf98;
      }
      FUN_004d73c0(piVar5);
      (**(code **)*piVar5)(1);
      FUN_004ce8d0();
      FUN_004ce860();
      FUN_005abba0();
      FUN_0076c4a0();
      iVar12 = FUN_0076c3c0();
      auStack_e0c[0xc] = auStack_e0c[0xc] + iVar12;
      uVar8 = FUN_0076c3c0();
      if (auStack_e0c[0x1b] <= uVar8) {
        auStack_e0c[0x1b] = FUN_0076c3c0();
      }
      FUN_0076c4a0();
      iVar12 = 0;
      do {
        iVar11 = iVar12 + 4;
        *(uint *)((int)auStack_d10 + iVar12) = *(uint *)((int)auStack_e0c + iVar12) / local_e34;
        iVar12 = iVar11;
      } while (iVar11 < 0x3c);
      pcVar9 = "!!!!!!!!!!!!!!!@@@@@@@@\nTotal:";
      puVar14 = (undefined4 *)(auStack_abd + 1);
      for (iVar12 = 7; iVar12 != 0; iVar12 = iVar12 + -1) {
        *puVar14 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        puVar14 = puVar14 + 1;
      }
      *(undefined2 *)puVar14 = *(undefined2 *)pcVar9;
      *(char *)((int)puVar14 + 2) = pcVar9[2];
      iVar12 = 0;
      do {
        sprintf((char *)&local_cd0[0].s.HighPart,"(%d)%d ",iVar12);
        pLVar1 = &local_cd0[0].s.HighPart;
        pLVar10 = pLVar1;
        do {
          LVar2 = *pLVar10;
          pLVar10 = (LONG *)((int)pLVar10 + 1);
        } while ((char)LVar2 != '\0');
        pLVar15 = (LONG *)auStack_abd;
        do {
          pcVar9 = (char *)((int)pLVar15 + 1);
          pLVar15 = (LONG *)((int)pLVar15 + 1);
        } while (*pcVar9 != '\0');
        pLVar13 = pLVar1;
        for (uVar8 = (uint)((int)pLVar10 - (int)pLVar1) >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
          *pLVar15 = *pLVar13;
          pLVar13 = pLVar13 + 1;
          pLVar15 = pLVar15 + 1;
        }
        iVar12 = iVar12 + 1;
        for (uVar8 = (int)pLVar10 - (int)pLVar1 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
          *(char *)pLVar15 = (char)*pLVar13;
          pLVar13 = (LONG *)((int)pLVar13 + 1);
          pLVar15 = (LONG *)((int)pLVar15 + 1);
        }
      } while (iVar12 < 0xf);
      puVar14 = (undefined4 *)auStack_abd;
      do {
        puVar16 = puVar14;
        puVar14 = (undefined4 *)((int)puVar16 + 1);
      } while (*(char *)((int)puVar16 + 1) != '\0');
      *(undefined4 *)((int)puVar16 + 1) = DAT_009cca30;
      *(undefined2 *)((int)puVar16 + 5) = DAT_009cca34;
      iVar12 = 0;
      do {
        sprintf((char *)&local_cd0[0].s.HighPart,"(%d)%d ",iVar12);
        pLVar1 = &local_cd0[0].s.HighPart;
        pLVar10 = pLVar1;
        do {
          LVar2 = *pLVar10;
          pLVar10 = (LONG *)((int)pLVar10 + 1);
        } while ((char)LVar2 != '\0');
        pLVar15 = (LONG *)auStack_abd;
        do {
          pcVar9 = (char *)((int)pLVar15 + 1);
          pLVar15 = (LONG *)((int)pLVar15 + 1);
        } while (*pcVar9 != '\0');
        pLVar13 = pLVar1;
        for (uVar8 = (uint)((int)pLVar10 - (int)pLVar1) >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
          *pLVar15 = *pLVar13;
          pLVar13 = pLVar13 + 1;
          pLVar15 = pLVar15 + 1;
        }
        iVar12 = iVar12 + 1;
        for (uVar8 = (int)pLVar10 - (int)pLVar1 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
          *(char *)pLVar15 = (char)*pLVar13;
          pLVar13 = (LONG *)((int)pLVar13 + 1);
          pLVar15 = (LONG *)((int)pLVar15 + 1);
        }
      } while (iVar12 < 0xf);
      puVar14 = (undefined4 *)auStack_abd;
      do {
        puVar16 = puVar14;
        puVar14 = (undefined4 *)((int)puVar16 + 1);
      } while (*(char *)((int)puVar16 + 1) != '\0');
      *(undefined4 *)((int)puVar16 + 1) = DAT_009cca28;
      *(undefined2 *)((int)puVar16 + 5) = DAT_009cca2c;
      iVar12 = 0;
      do {
        sprintf((char *)&local_cd0[0].s.HighPart,"(%d)%d ",iVar12);
        pLVar1 = &local_cd0[0].s.HighPart;
        pLVar10 = pLVar1;
        do {
          LVar2 = *pLVar10;
          pLVar10 = (LONG *)((int)pLVar10 + 1);
        } while ((char)LVar2 != '\0');
        pLVar15 = (LONG *)auStack_abd;
        do {
          pcVar9 = (char *)((int)pLVar15 + 1);
          pLVar15 = (LONG *)((int)pLVar15 + 1);
        } while (*pcVar9 != '\0');
        pLVar13 = pLVar1;
        for (uVar8 = (uint)((int)pLVar10 - (int)pLVar1) >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
          *pLVar15 = *pLVar13;
          pLVar13 = pLVar13 + 1;
          pLVar15 = pLVar15 + 1;
        }
        iVar12 = iVar12 + 1;
        for (uVar8 = (int)pLVar10 - (int)pLVar1 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
          *(char *)pLVar15 = (char)*pLVar13;
          pLVar13 = (LONG *)((int)pLVar13 + 1);
          pLVar15 = (LONG *)((int)pLVar15 + 1);
        }
      } while (iVar12 < 0xf);
      sprintf((char *)&local_cd0[0].s.HighPart,"\nNumGfx:%d \n");
      pLVar1 = &local_cd0[0].s.HighPart;
      pLVar10 = pLVar1;
      do {
        LVar2 = *pLVar10;
        pLVar10 = (LONG *)((int)pLVar10 + 1);
      } while ((char)LVar2 != '\0');
      pLVar15 = (LONG *)auStack_abd;
      do {
        pcVar9 = (char *)((int)pLVar15 + 1);
        pLVar15 = (LONG *)((int)pLVar15 + 1);
      } while (*pcVar9 != '\0');
      pLVar13 = pLVar1;
      for (uVar8 = (uint)((int)pLVar10 - (int)pLVar1) >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pLVar15 = *pLVar13;
        pLVar13 = pLVar13 + 1;
        pLVar15 = pLVar15 + 1;
      }
      for (uVar8 = (int)pLVar10 - (int)pLVar1 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(char *)pLVar15 = (char)*pLVar13;
        pLVar13 = (LONG *)((int)pLVar13 + 1);
        pLVar15 = (LONG *)((int)pLVar15 + 1);
      }
      OutputDebugStringA(auStack_abd + 1);
      QueryPerformanceCounter(&local_d34);
      local_e14 = (int *)(local_d34.s.LowPart - uStack_d2c);
      iStack_e10 = (local_d34.s.HighPart - local_d28._0_4_) -
                   (uint)(local_d34.s.LowPart < uStack_d2c);
      sprintf(acStack_bc4,"******* Map (%s) loaded in: (%f) sec.\n",(int)param_1 + 0xb4,
              (double)CONCAT44(iStack_e10,local_e14) /
              (double)CONCAT44(local_cd0[0].s.LowPart,auStack_d10[0xf]));
      OutputDebugStringA(acStack_bc4);
      ExceptionList = pvStack_20;
      return 1;
    }
  }
  ExceptionList = local_1c;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
