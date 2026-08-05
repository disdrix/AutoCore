// =============================================================================
// Named_Invalid_spawn_I64d_map
// -----------------------------------------------------------------------------
// Stable ID: aa_00566490
// Address:   0x00566490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Invalid_spawn_I64d_map @ 0x00566490
// Stable ID: aa_00566490
// Embedded strings (evidence for future rename):
//   - "Invalid AI %d in spawn %I64d, on map %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~261 non-empty decompiler lines.
//  - Control keywords: if×39, return×7, goto×6, while×5, do×4, for×2.
//  - Notable callees: CVOGReaction_RandomUnitScalar×3, FUN_005635e0×3, FUN_004022a0×2, FUN_00567bf0×2, CONCAT31, CVOGCharacter_WeaponAllowsKillXpBonus, CVOGReaction_FailMissionNotify, FUN_004294f0.
//  - Strings: "Invalid AI %d in spawn %I64d, on map %s".
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Invalid AI %d in spawn %I64d, on map %s"
 * Domain alias of FUN_00566490 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_Invalid_spawn_I64d_map(int *param_1,char param_2,uint32_t /* width from decompiler */ param_3,uint param_4)



{

  byte bVar1;

  ushort uVar2;

  uint uVar3;

  bool bVar4;

  char cVar5;

  int iVar6;

  int *piVar7;

  int *piVar8;

  uint uVar9;

  int iVar10;

  int iVar11;

  uint uVar12;

  uint uVar13;

  int *piVar14;

  void *pvVar15;

  uint local_70;

  int *local_6c;

  int iStack_68;

  uint uStack_64;

  int iStack_60;

  void *pvStack_58;

  int iStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  void *pvStack_48;

  int iStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  int local_3c [12];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a4b79;

  local_c = ExceptionList;

  if (DAT_00b04781 != '\0') {

    return;

  }

  if (*(char *)(*(int *)(*(int *)(param_1[1] + 4) + 0xa8 + (int)param_1) + 0x7e) == '\0') {

    return;

  }

  if ((*(byte *)((int)param_1 + *(int *)(param_1[1] + 4) + 0x181) & 2) == 0) {

    return;

  }

  ExceptionList = &local_c;

  if (param_2 == '\0') {

    ExceptionList = &local_c;

    iVar6 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar6 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar6 + 0xc) = 0;

    }

    uVar2 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);

    *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;

    if (((uint)*(byte *)((int)param_1 + 0xb2) < (uint)uVar2 % 100) &&

       ((float)param_1[0x21] != g_flZero)) {

      FUN_005635e0(0xffffffff,0);

      ExceptionList = local_c;

      return;

    }

    if (((*(char *)((int)param_1 + 0xaa) != '\0') && ((float)param_1[0x21] == DAT_00aaa668)) &&

       (param_1[0x2b] == 0)) goto LAB_00566a32;

  }

  local_70 = 0;

  FUN_004294f0();

  piVar14 = local_3c;

  for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {

    *piVar14 = 0;

    piVar14 = piVar14 + 1;

  }

  iVar6 = FUN_004022a0(&local_70,&local_6c);

  piVar14 = local_6c;

  while (iVar6 == 0) {

    iVar6 = 0;

    piVar8 = param_1 + 0x3c;

    local_6c = piVar14;

    do {

      if ((*(char *)((int)piVar8 + -3) != '\0') && (iVar11 = *piVar8, iVar11 != -1)) {

        if (*(int *)(piVar14[0x2a] + 0x38) == 0xe) {

          if (*(char *)((int)piVar8 + 5) == '\0') goto LAB_0056660c;

          (**(code **)(*piVar14 + 0x1d4))();

          piVar7 = (int *)FUN_005001f0();

          iVar11 = *piVar8;

          if (*piVar7 != iVar11) goto LAB_00566606;

LAB_0056661d:

          local_3c[iVar6] = local_3c[iVar6] + 1;

        }

        else {

LAB_00566606:

          if (*(char *)((int)piVar8 + 5) == '\0') {

LAB_0056660c:

            if ((*(int *)(piVar14[0x2a] + 0x38) != 0xe) &&

               (*(int *)(piVar14[0x2a] + 0x34) == iVar11)) goto LAB_0056661d;

          }

        }

      }

      iVar6 = iVar6 + 1;

      piVar8 = piVar8 + 3;

    } while (iVar6 < 0xc);

    iVar6 = FUN_004022a0(&local_70,&local_6c);

    piVar14 = local_6c;

  }

  if ((char)param_1[0x37] != '\0') {

    *(uint8_t *)(param_1 + 0x37) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2e));

  }

  pvStack_48 = (void *)0x0;

  iStack_44 = 0;

  uStack_40 = 0;

  uStack_4 = 0;

  local_6c = (int *)0x0;

  do {

    piVar14 = local_6c;

    if (((*(char *)((int)param_1 + (int)local_6c * 0xc + 0xed) != '\0') &&

        (local_3c[(int)local_6c] <= (int)(uint)*(byte *)(param_1 + (int)local_6c * 3 + 0x3b))) &&

       (param_1[(int)local_6c * 3 + 0x3c] != -1)) {

      CVOGReaction_FailMissionNotify(&local_6c);

    }

    local_6c = (int *)((int)piVar14 + 1);

  } while ((int)local_6c < 0xc);

  if (((param_2 != '\0') || (param_1[0x36] == 0)) || (param_1[0x2b] != 0)) {

    pvStack_58 = (void *)0x0;

    iStack_54 = 0;

    uStack_50 = 0;

    uStack_4 = CONCAT31(uStack_4._1_3_,1);

    if ((int)param_4 < 0) {

      for (uVar12 = 0;

          (pvStack_48 != (void *)0x0 && (uVar12 < (uint)(iStack_44 - (int)pvStack_48 >> 2)));

          uVar12 = uVar12 + 1) {

        uVar3 = *(uint *)((int)pvStack_48 + uVar12 * 4);

        uVar13 = (uint)*(byte *)(param_1 + uVar3 * 3 + 0x3b);

        if (9 < *(byte *)(param_1 + uVar3 * 3 + 0x3b)) {

          uVar13 = 10;

        }

        bVar1 = *(byte *)((int)param_1 + uVar3 * 0xc + 0xed);

        if (bVar1 < 10) {

          uVar9 = (uint)bVar1;

          if (uVar9 != 0) goto LAB_0056682a;

        }

        else {

          uVar9 = 10;

LAB_0056682a:

          if (param_1[uVar3 * 3 + 0x3c] != -1) {

            iVar6 = (uVar9 - uVar13) + 1;

            if (iVar6 < 1) {

              iVar6 = 1;

            }

            iVar11 = CVOGReaction_RandomUnitScalar();

            if (0xfffff < *(int *)(iVar11 + 0xc)) {

              *(uint32_t /* width from decompiler */ *)(iVar11 + 0xc) = 0;

            }

            uVar2 = *(ushort *)(*(int *)(iVar11 + 8) + *(int *)(iVar11 + 0xc) * 2);

            *(int *)(iVar11 + 0xc) = *(int *)(iVar11 + 0xc) + 1;

            iVar11 = local_3c[uVar3];

            if (0 < (int)(((int)((longlong)(ulonglong)uVar2 % (longlong)iVar6) - iVar11) + uVar13))

            {

              iVar10 = CVOGReaction_RandomUnitScalar();

              if (0xfffff < *(int *)(iVar10 + 0xc)) {

                *(uint32_t /* width from decompiler */ *)(iVar10 + 0xc) = 0;

              }

              uVar2 = *(ushort *)(*(int *)(iVar10 + 8) + *(int *)(iVar10 + 0xc) * 2);

              *(int *)(iVar10 + 0xc) = *(int *)(iVar10 + 0xc) + 1;

              iVar6 = ((int)((longlong)(ulonglong)uVar2 % (longlong)iVar6) - iVar11) + uVar13;

              if (0 < iVar6) {

                uStack_64 = uVar3;

                iStack_60 = iVar6;

                FUN_00567bf0(&uStack_64);

              }

            }

          }

        }

      }

    }

    else {

      uStack_64 = param_4;

      iStack_60 = 1;

      FUN_00567bf0(&uStack_64);

    }

    pvVar15 = pvStack_58;

    if ((pvStack_58 == (void *)0x0) ||

       (uStack_64 = iStack_54 - (int)pvStack_58 >> 3, uStack_64 == 0)) {

      FUN_005635e0(0xffffffff,0);

    }

    else {

      local_6c = (int *)0x0;

      param_4 = 0;

      local_70 = 0;

      if (uStack_64 != 0) {

        do {

          if ((param_1[0x2b] != 0) && (param_1[0x2b] <= (int)param_4)) break;

          iVar6 = *(int *)((int)pvStack_58 + local_70 * 8);

          iVar11 = *(int *)((int)pvStack_58 + local_70 * 8 + 4);

          bVar4 = false;

          if (iVar11 < 1) {

LAB_005669c0:

            param_4 = param_4 + 1;

          }

          else {

            piVar14 = param_1 + iVar6 * 3 + 0x3c;

            iStack_68 = iVar11;

            do {

              if (*(char *)((int)param_1 + iVar6 * 0xc + 0xf5) == '\0') {

                piVar8 = (int *)CVOGSpawnPoint_CreateCreature

                                          (*piVar14,(int)(char)param_1[iVar6 * 3 + 0x3d],1);

              }

              else {

                piVar8 = (int *)CVOGSpawnPoint_CreateTemplateVehicle

                                          (*piVar14,(int)(char)param_1[iVar6 * 3 + 0x3d],1);

              }

              if ((piVar8 == (int *)0x0) ||

                 (iVar11 = (**(code **)(*piVar8 + 0x27c))(), iVar11 == 999999)) {

                iVar11 = *(int *)(param_1[1] + 4);

                FUN_007a4480(0,"Invalid AI %d in spawn %I64d, on map %s",*piVar14,

                             *(uint32_t /* width from decompiler */ *)((int)param_1 + iVar11 + 0x164),

                             *(uint32_t /* width from decompiler */ *)((int)param_1 + iVar11 + 0x168),

                             *(int *)(iVar11 + 0xa8 + (int)param_1) + 0xb4);

                bVar4 = true;

              }

              if (piVar8 != (int *)0x0) {

                (**(code **)(*param_1 + 0x4c))(piVar8);

                cVar5 = CVOGCharacter_WeaponAllowsKillXpBonus();

                if ((cVar5 != '\0') && (iVar11 = (**(code **)(*piVar8 + 0x1d4))(), iVar11 == 0)) {

                  FUN_004cf3b0(piVar8,0,*(uint32_t /* width from decompiler */ *)

                                         (*(int *)(*(int *)(param_1[1] + 4) + 0xa8 + (int)param_1) +

                                         0xe818));

                }

              }

              iStack_68 = iStack_68 + -1;

            } while (iStack_68 != 0);

            iStack_68 = 0;

            if (!bVar4) goto LAB_005669c0;

            local_6c = (int *)((int)local_6c + 1);

          }

          local_70 = local_70 + 1;

        } while (local_70 < uStack_64);

      }

      piVar14 = local_6c;

      if (0 < param_1[0x2b]) {

        piVar14 = (int *)-param_4;

      }

      iVar6 = param_1[0x2b] + (int)piVar14;

      param_1[0x2b] = iVar6;

      pvVar15 = pvStack_58;

      if (0 < iVar6) {

        FUN_005635e0(5000,1);

        pvVar15 = pvStack_58;

      }

    }

    if (pvVar15 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar15);

    }

  }

  if (pvStack_48 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvStack_48);

  }

LAB_00566a32:

  *(uint8_t *)((int)param_1 + 0xaa) = 1;

  ExceptionList = local_c;

  return;

}
