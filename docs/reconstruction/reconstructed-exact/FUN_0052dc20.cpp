// =============================================================================
// FUN_0052dc20
// -----------------------------------------------------------------------------
// Stable ID: aa_0052dc20
// Address:   0x0052dc20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0052dc20 @ 0x0052dc20
// Stable ID: aa_0052dc20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~121 non-empty decompiler lines.
//  - Control keywords: if×13, return×5, while×4, do×3, goto×1.
//  - Notable callees: CNDHash_LookupByKey×2, FUN_004022a0×2, __RTDynamicCast×2, CONCAT22, FUN_004294f0, FUN_00514e70, FUN_0052dc20, FUN_0053a820.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall FUN_0052dc20(int param_1,uint param_2,char param_3)



{

  int *piVar1;

  char cVar2;

  void *pvVar3;

  void *key;

  int iVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  uint32_t /* width from decompiler */ unaff_EDI;

  uint *puVar8;

  uint uVar9;

  int local_2c;

  uint32_t /* width from decompiler */ local_28;

  void *local_24;

  int local_20 [2];

  void *local_18;

  int local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a3ba0;

  local_c = ExceptionList;

  pvVar3 = *(void **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x74 + param_1);

  if ((pvVar3 == (void *)0x0) || (*(short *)(param_1 + 0x6cc) == 0)) {

    return 0;

  }

  ExceptionList = &local_c;

  pvVar3 = CNDHash_LookupByKey(pvVar3,param_2);

  if ((pvVar3 == (void *)0x0) ||

     ((local_24 = pvVar3, cVar2 = FUN_005533f0(param_1), cVar2 == '\0' && (param_3 == '\0')))) {

    ExceptionList = local_c;

    return 0;

  }

  iVar6 = 0;

  puVar8 = (uint *)((int)pvVar3 + 0x600);

  do {

    key = (void *)*puVar8;

    if (((key != (void *)0xffffffff) &&

        (key = CNDHash_LookupByKey(*(void **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x74 + param_1),

                                   (uint)key), key != (void *)0x0)) &&

       (*(short *)((int)key + 0x5f6) == 0)) {

      ExceptionList = local_c;

      return 0;

    }

    iVar6 = iVar6 + 1;

    puVar8 = puVar8 + 1;

  } while (iVar6 < 3);

  *(short *)(param_1 + 0x6cc) = *(short *)(param_1 + 0x6cc) - *(short *)((int)pvVar3 + 2);

  Skill_SetRankAndReevaluate

            (pvVar3,(void *)(CONCAT22((short)((uint)key >> 0x10),

                                      *(uint16_t *)((int)pvVar3 + 0x5f6)) + 1),(short)unaff_EDI);

  if (*(short *)((int)pvVar3 + 0x5f6) == 1) {

    uVar5 = 0;

    local_18 = (void *)0x0;

    local_14 = 0;

    local_10 = 0;

    local_4 = 0;

    iVar6 = 0;

    do {

      if (iVar6 == 0) {

        iVar7 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb4 + param_1);

LAB_0052dd5e:

        if (iVar7 != 0) {

          local_2c = 0;

          local_28 = 0;

          FUN_004294f0();

          iVar4 = FUN_004022a0(&local_28,&local_2c);

          while (iVar4 == 0) {

            if (((local_2c != 0) && (*(int *)(local_2c + 0x1c) == 1)) &&

               ((local_20[0] = __RTDynamicCast(local_2c,0,&CVOGHBBase::RTTI_Type_Descriptor,

                                               &CVOGHBSkillBase::RTTI_Type_Descriptor,0),

                local_20[0] != 0 &&

                (((*(byte *)(local_20[0] + 0x639) & 1) != 0 &&

                 (iVar4 = __RTDynamicCast(local_20[0],0,&CVOGHBSkillBase::RTTI_Type_Descriptor,

                                          &CVOGHBSkill_AddSkillLevels::RTTI_Type_Descriptor,0),

                 iVar4 != 0)))))) {

              FUN_0053a820(local_20);

            }

            iVar4 = FUN_004022a0(&local_28,&local_2c);

          }

          if (*(char *)(iVar7 + 0x28) != '\0') {

            *(uint8_t *)(iVar7 + 0x28) = 0;

            LeaveCriticalSection((LPCRITICAL_SECTION)(iVar7 + 4));

          }

        }

      }

      else if ((iVar6 == 1) && (iVar7 = *(int *)(param_1 + 0x250), iVar7 != 0)) {

        iVar7 = *(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 0xb4 + iVar7);

        goto LAB_0052dd5e;

      }

      iVar6 = iVar6 + 1;

    } while (iVar6 < 2);

    if (local_18 != (void *)0x0) {

      uVar5 = local_14 - (int)local_18 >> 2;

    }

    uVar9 = 0;

    if (uVar5 != 0) {

      do {

        piVar1 = *(int **)((int)local_18 + uVar9 * 4);

        (**(code **)(*piVar1 + 0x14))();

        (**(code **)(*piVar1 + 4))();

        uVar9 = uVar9 + 1;

      } while (uVar9 < uVar5);

    }

    local_4 = 0xffffffff;

    if (local_18 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(local_18);

    }

  }

  FUN_005536c0(param_1);

  if (param_3 == '\0') {

    FUN_00514e70(param_2);

  }

  ExceptionList = local_c;

  return 1;

}
