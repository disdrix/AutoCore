// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00561580
// -----------------------------------------------------------------------------
// Stable ID: aa_00561580
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00561580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×11, do×4, while×4, goto×1, return×1.
//  - Notable callees: FUN_005614f0, FUN_00561580, FUN_005b3370, FUN_00628f10, FUN_006292a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00561580(int param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  int iVar8;

  int unaff_ESI;

  int local_28;

  uint8_t auStack_24 [16];

  int local_14;

  int local_10;

  int local_c;

  int iStack_8;

  int iStack_4;

  

  piVar2 = *(int **)(param_2 + 0x44);

  iVar8 = 0;

  iVar5 = param_2;

  local_28 = param_1;

  if (0 < piVar2[0x17]) {

    do {

      iVar4 = (**(code **)(**(int **)(piVar2[0x16] + iVar8 * 4) + 0x20))();

      if (iVar4 != 0xb) {

        piVar1 = (int *)(piVar2[0x16] + iVar8 * 4);

        iVar4 = *piVar1;

        if (((*(int *)(iVar4 + 0xc) == iVar5) && (*(char *)(*(int *)(iVar4 + 0x10) + 0x40) != '\0'))

           || ((*(int *)(iVar4 + 0x10) == iVar5 && (*(char *)(*(int *)(iVar4 + 0xc) + 0x40) != '\0')

               ))) {

          piVar1 = (int *)*piVar1;

          piVar2[0x17] = piVar2[0x17] + -1;

          iVar5 = iVar8;

          if (iVar8 < piVar2[0x17]) {

            do {

              iVar4 = iVar5 + 1;

              *(uint32_t /* width from decompiler */ *)(piVar2[0x16] + iVar5 * 4) =

                   *(uint32_t /* width from decompiler */ *)(piVar2[0x16] + 4 + iVar5 * 4);

              iVar5 = iVar4;

            } while (iVar4 < piVar2[0x17]);

          }

          (**(code **)(*piVar1 + 0x28))(auStack_24);

          (**(code **)(*piVar2 + 0xc))(piVar1,&local_28);

          iVar5 = *(int *)(unaff_ESI + 0x2c);

          iVar4 = unaff_ESI;

          if (*(uint *)(iVar5 + 0x5c) == (*(uint *)(iVar5 + 0x60) & 0x7fffffff)) {

            FUN_005b3370((int *)(iVar5 + 0x58),4);

            iVar4 = unaff_ESI;

          }

          *(int **)(*(int *)(iVar5 + 0x58) + *(int *)(iVar5 + 0x5c) * 4) = piVar1;

          *(int *)(iVar5 + 0x5c) = *(int *)(iVar5 + 0x5c) + 1;

          unaff_ESI = iVar4;

          (**(code **)(**(int **)(iVar4 + 0x2c) + 8))(piVar1,&stack0xffffffd0);

          piVar1[5] = *(int *)(iVar4 + 0x2c);

          iVar8 = iVar8 + -1;

          iVar5 = param_2;

        }

      }

      iVar8 = iVar8 + 1;

    } while (iVar8 < piVar2[0x17]);

  }

  piVar1 = DAT_00b05060;

  iVar8 = 0;

  local_14 = 0;

  local_10 = 0;

  local_c = 0x80000000;

  piVar2 = DAT_00b05060 + 3;

  if (*piVar2 < 0x40) {

    local_14 = (**(code **)(*DAT_00b05060 + 0x24))(0x40);

  }

  else {

    local_14 = DAT_00b05060[2];

    DAT_00b05060[2] = local_14 + 0x40;

    piVar1[3] = *piVar2 + -0x40;

  }

  local_c = -0x7ffffff0;

  iStack_4 = 0x10;

  iStack_8 = local_14;

  if (0 < *(int *)(iVar5 + 0x98)) {

    do {

      (**(code **)(**(int **)(*(int *)(iVar5 + 0x94) + iVar8 * 4) + 0x18))(&local_14);

      iVar4 = local_28;

      iVar6 = 0;

      if (0 < local_10) {

        do {

          iVar3 = *(int *)(local_14 + iVar6 * 4);

          if ((*(char *)(iVar3 + 0x40) == '\0') && (iVar3 != iVar5)) goto LAB_0056173b;

          iVar6 = iVar6 + 1;

        } while (iVar6 < local_10);

      }

      FUN_006292a0(*(uint32_t /* width from decompiler */ *)(*(int *)(iVar5 + 0x94) + iVar8 * 4));

      FUN_00628f10(*(uint32_t /* width from decompiler */ *)(*(int *)(iVar5 + 0x94) + iVar8 * 4));

      *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar5 + 0x94) + iVar8 * 4) + 0x10) =

           *(uint32_t /* width from decompiler */ *)(iVar4 + 0x2c);

LAB_0056173b:

      iVar8 = iVar8 + 1;

    } while (iVar8 < *(int *)(iVar5 + 0x98));

  }

  FUN_005614f0(&param_2,iVar5);

  piVar2 = DAT_00b05060;

  uVar7 = iStack_4 * 4 + 0xfU & 0xfffffff0;

  if ((uVar7 == 0) || ((iStack_8 != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {

    DAT_00b05060[2] = DAT_00b05060[2] - uVar7;

    piVar2[3] = piVar2[3] + uVar7;

  }

  else {

    (**(code **)(*DAT_00b05060 + 0x28))(iStack_8,uVar7);

  }

  if (-1 < local_c) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_14);

  }

  return;

}
