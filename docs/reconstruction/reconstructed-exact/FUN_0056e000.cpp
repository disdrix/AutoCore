// =============================================================================
// FUN_0056e000 / Weapon_ApplyDamageToTargets_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0056e000
// Address:   0x0056e000  (autoassault.exe, image base 0x400000)
// Body:      0x0056e000 – 0x0056e4d1
// System:    combat / vehicle weapon
// Generated: 2026-07-29 live re-seal (faithful to Ghidra decompile)
// Exactness: Behavior-preserving; not modernization.
// ABI:       __thiscall; 2 stack args; ret 8 (C2 08 00)
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE: Per-target damage application for a hit list. Optional distance
//          falloff (1.05 - dist/range), target vtbl+0x4C damage call, crit
//          scale via CVOGReaction_RandomUnitScalar + FUN_004cf080, hit report
//          FUN_0056ff00, optional CVOGHBBase action enqueue.
// CONST:    _DAT_009d3364 = 1.05f
//
// CAVEAT: local_5c vector never filled in decompile → trailing delete path dead.
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t __thiscall FUN_0056e000(int param_1, uint param_2, int param_3)
{
  uint16_t uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  float *pfVar6;
  void *pvVar7;
  CVOGHBBase *pAction;
  void *extraout_ECX;
  uint uVar8;
  float10 fVar9;
  int iStack_90;
  float local_84;
  uint32_t uStack_6c;
  uint32_t uStack_68;
  uint8_t uStack_64;
  void *local_5c;
  int local_58;
  uint32_t local_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  uint32_t uStack_40;
  uint32_t uStack_3c;
  uint32_t uStack_38;
  uint32_t uStack_34;
  int iStack_30;
  uint8_t uStack_2b;
  uint32_t uStack_2a;
  uint16_t uStack_26;
  char cStack_24;
  char cStack_23;
  uint8_t uStack_22;
  void *local_1c;
  uint8_t *puStack_18;
  int local_14;

  puStack_18 = &LAB_009a4dfc;
  local_1c = ExceptionList;
  /* source id at weapon adjustor +0xB0 */
  iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);
  if (iVar2 == 0) {
    return 0;
  }
  local_5c = (void *)0x0;
  local_58 = 0;
  local_54 = 0;
  uVar8 = 0;
  local_14 = 0;
  ExceptionList = &local_1c;
  if (param_2 != 0) {
    do {
      if (*(int *)(param_3 + uVar8 * 4) != 0) {
        local_84 = g_flOne;
        if ((*(float *)(param_1 + 0xe0) != g_flZero) &&
            (iVar5 = (**(code **)(**(int **)(param_3 + uVar8 * 4) + 0x1c8))(), iVar5 != 0)) {
          iVar3 = *(int *)(iVar5 + 8);
          if (uVar8 == 0) {
            if (iVar3 == 0) {
              pfVar6 = (float *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0x84 + iVar5);
            } else {
              pfVar6 = (float *)(*(int *)(iVar3 + 0x3c) + 0xb0);
            }
            fStack_50 = *pfVar6;
            fStack_4c = pfVar6[1];
            fStack_48 = pfVar6[2];
          } else {
            if (iVar3 == 0) {
              pfVar6 = (float *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0x84 + iVar5);
            } else {
              pfVar6 = (float *)(*(int *)(iVar3 + 0x3c) + 0xb0);
            }
            /* scale = 1.05f - dist / this+0xE0 */
            local_84 = _DAT_009d3364 -
                       SQRT((pfVar6[2] - fStack_48) * (pfVar6[2] - fStack_48) +
                            (pfVar6[1] - fStack_4c) * (pfVar6[1] - fStack_4c) +
                            (*pfVar6 - fStack_50) * (*pfVar6 - fStack_50)) /
                       *(float *)(param_1 + 0xe0);
          }
        }
        uStack_6c = 0;
        uStack_68 = 0;
        uStack_64 = 0;
        /* target vtbl+0x4C damage/calc */
        iVar5 = (**(code **)(**(int **)(param_3 + uVar8 * 4) + 0x4c))
                          (*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1, param_1 + 0x124,
                           param_1 + 0x130, 1, 1, 1, 0, 0, &uStack_6c, 0);
        iStack_90 = (int)((float)iVar5 * local_84);
        if (iStack_90 < 1) {
          if ((uStack_68._2_1_ != '\0') || (uStack_68._3_1_ != '\0')) {
            iVar5 = *(int *)(param_3 + uVar8 * 4);
            uStack_40 = *(uint32_t *)(iVar5 + 0x160);
            uStack_3c = *(uint32_t *)(iVar5 + 0x164);
            cStack_24 = uStack_68._2_1_;
            uStack_38 = *(uint32_t *)(iVar5 + 0x168);
            uStack_34 = *(uint32_t *)(iVar5 + 0x16c);
            uStack_22 = uStack_64;
            cStack_23 = uStack_68._3_1_;
            uStack_2b = 0;
            uStack_2a = uStack_6c;
            uStack_26 = (uint16_t)uStack_68;
            iStack_30 = iStack_90;
            FUN_0056ff00(&uStack_40);
          }
        } else {
          iVar5 = CVOGReaction_RandomUnitScalar();
          if (0xfffff < *(int *)(iVar5 + 0xc)) {
            *(uint32_t *)(iVar5 + 0xc) = 0;
          }
          uVar1 = *(uint16_t *)(*(int *)(iVar5 + 8) + *(int *)(iVar5 + 0xc) * 2);
          *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + 1;
          fVar9 = (float10)FUN_004cf080(iVar2, *(uint32_t *)(param_3 + uVar8 * 4),
                                        CONCAT22((short)((uint)*(int *)(iVar5 + 8) >> 0x10), uVar1));
          bVar4 = g_flOne < (float)fVar9;
          if (bVar4) {
            iStack_90 = (int)ROUND((float)iStack_90 * (float)fVar9);
          }
          if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) != 0) {
            iVar5 = FUN_0056add0();
            if ((iVar5 == 1) || (iVar5 = FUN_0056add0(), iVar5 == 5)) {
              *(uint32_t *)(*(int *)(param_3 + uVar8 * 4) + 0xcc) = 4;
            }
            iVar5 = *(int *)(param_3 + uVar8 * 4);
            uStack_40 = *(uint32_t *)(iVar5 + 0x160);
            uStack_3c = *(uint32_t *)(iVar5 + 0x164);
            uStack_38 = *(uint32_t *)(iVar5 + 0x168);
            uStack_34 = *(uint32_t *)(iVar5 + 0x16c);
            iStack_30 = iStack_90;
            uStack_22 = uStack_64;
            cStack_24 = uStack_68._2_1_;
            cStack_23 = uStack_68._3_1_;
            uStack_2a = uStack_6c;
            uStack_26 = (uint16_t)uStack_68;
            uStack_2b = bVar4;
            FUN_0056ff00(&uStack_40);
            iVar5 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1);
            if (iVar5 == 0) {
              iVar5 = 0;
            } else {
              iVar5 = *(int *)(iVar5 + 0x3c);
            }
            if (0 < *(int *)(iVar5 + 0x52c)) {
              pvVar7 = operator_new(0x50);
              local_14._0_1_ = 1;
              if (pvVar7 == (void *)0x0) {
                pAction = (CVOGHBBase *)0x0;
              } else {
                iVar5 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1);
                if (iVar5 == 0) {
                  iVar5 = 0;
                } else {
                  iVar5 = *(int *)(iVar5 + 0x3c);
                }
                pAction = (CVOGHBBase *)
                          FUN_006335b0(param_1, 500, *(uint32_t *)(iVar5 + 0x52c), bVar4, iStack_90,
                                       iVar2, *(uint32_t *)(param_3 + uVar8 * 4));
              }
              local_14 = (uint)local_14._1_3_ << 8;
              CVOGHBList_Enqueue(
                  *(void **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xe4ec),
                  pAction);
              CVOGHBBase_Start(pAction);
            }
          }
        }
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < param_2);
    /* dead under current decompile: local_5c never non-null */
    if (local_5c != (void *)0x0) {
      iVar5 = local_58 - (int)local_5c >> 5;
      if (iVar5 != 0) {
        pvVar7 = local_5c;
        if (iVar5 == 0) {
          iVar5 = FUN_0056eb20();
          pvVar7 = extraout_ECX;
        }
        param_1 = param_1 + *(int *)(*(int *)(param_1 + 4) + 4);
        FUN_004da2e0(pvVar7, iVar5, iVar2, 1, 0, 0,
                     *(uint32_t *)(param_1 + 0x164),
                     *(uint32_t *)(param_1 + 0x168),
                     *(uint32_t *)(param_1 + 0x16c),
                     *(uint32_t *)(param_1 + 0x170), 0);
      }
      /* Ghidra falsely marks operator_delete as noreturn */
      operator_delete(local_5c);
    }
  }
  ExceptionList = local_1c;
  return 1;
}
