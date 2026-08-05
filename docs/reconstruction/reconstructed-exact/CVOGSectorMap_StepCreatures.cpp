// =============================================================================
// CVOGSectorMap_StepCreatures
// -----------------------------------------------------------------------------
// Stable ID: aa_004d4da0
// Address:   0x004d4da0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Domain alias CVOGSectorMap_StepCreatures for FUN_004d4da0 @ 0x004d4da0
// Stable ID: aa_004d4da0
// Embedded strings (evidence for future rename):
//   - "CVOGSectorMap::StepCreatures"
//   - "Autodeleting Creature %I64d %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, while×2, return×2.
//  - Notable callees: CONCAT31, FUN_004c2f40, FUN_004d4790, CVOGSectorMap_StepCreatures, FUN_004e54a0, FUN_004e9530, FUN_0076cef0, FUN_0076cf00.
//  - Strings: "CVOGSectorMap::StepCreatures"; "Autodeleting Creature %I64d %d".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "CVOGSectorMap::StepCreatures"
 * Domain alias of FUN_004d4da0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall CVOGSectorMap_StepCreatures(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int local_48;

  uint32_t /* width from decompiler */ local_44;

  int *local_3c;

  int *local_38;

  uint32_t /* width from decompiler */ local_34;

  uint8_t local_30 [20];

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a20dc;

  pvStack_1c = ExceptionList;

  local_44 = DAT_00d1f040;

  ExceptionList = &pvStack_1c;

  FUN_0076cf00("CVOGSectorMap::StepCreatures");

  local_14 = 0;

  FUN_004e9530(local_30,*(int *)(param_1 + 0xe898) + 0x8c);

  local_3c = (int *)0x0;

  local_38 = (int *)0x0;

  local_34 = 0;

  piVar5 = *(int **)(param_1 + 0xe720);

  local_14 = CONCAT31(local_14._1_3_,1);

  if (piVar5 != *(int **)(param_1 + 0xe724)) {

    do {

      iVar1 = *piVar5;

      iVar3 = *(int *)(iVar1 + 8);

      local_48 = iVar1;

      if ((iVar3 != 0) && ((*(char *)(iVar3 + 0x40) == '\0' || (*(int *)(iVar3 + 8) == 0)))) {

        if ((*(char *)(param_1 + 0x7e) == '\0') &&

           ((iVar3 = *(int *)(*(int *)(iVar1 + 4) + 4),

            (*(uint *)(iVar3 + 0x180 + iVar1) >> 1 & 1) == 0 &&

            (*(int *)(*(int *)(*(int *)(iVar3 + iVar1 + 0xac) + 0x3c) + 0x4e0) != 1)))) {

          piVar2 = *(int **)(param_1 + 0xe8a0);

          iVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x1dc))();

          iVar4 = (**(code **)(*piVar2 + 0x1dc))();

          if ((iVar3 != iVar4) &&

             (((0x77a1 < g_dwClientTickMs - *(int *)(iVar1 + 0x14) &&

               (*(char *)(iVar1 + 0x10) != '\0')) &&

              (*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x18 + iVar1) == 0)))) {

            FUN_004e54a0(&local_48);

          }

        }

        if (((*(int *)(iVar1 + 8) == 0) ||

            (iVar3 = (**(code **)(**(int **)(*(int *)(iVar1 + 8) + 0x3c) + 0x18))(), iVar3 != 6)) ||

           (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xac + iVar1) + 0x3c) +

                    0x4e0) == 1)) {

          FUN_004c2f40(param_2);

        }

      }

      piVar5 = piVar5 + 1;

    } while (piVar5 != *(int **)(param_1 + 0xe724));

    if (local_3c != (int *)0x0) {

      local_48 = (int)local_38 - (int)local_3c >> 2;

      if ((local_48 != 0) && (piVar5 = local_3c, local_3c != local_38)) {

        do {

          iVar3 = *piVar5;

          iVar4 = *(int *)(*(int *)(iVar3 + 4) + 4);

          iVar1 = iVar4 + iVar3;

          FUN_007a4480(0,"Autodeleting Creature %I64d %d",*(uint32_t /* width from decompiler */ *)(iVar1 + 0x164),

                       *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168),

                       *(uint32_t /* width from decompiler */ *)(*(int *)(iVar4 + 0xac + iVar3) + 0x34));

          *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar3 + 4) + 4) + iVar3 + 0xd0) = 0;

          FUN_004d4790(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3);

          piVar5 = piVar5 + 1;

        } while (piVar5 != local_38);

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(local_3c);

    }

  }

  local_14 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = pvStack_1c;

  return;

}
