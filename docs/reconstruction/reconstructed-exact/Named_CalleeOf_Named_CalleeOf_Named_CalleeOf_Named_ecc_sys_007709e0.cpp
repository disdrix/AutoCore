// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_007709e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007709e0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_ecc_sys
// Address:   0x007709e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×12, do×4, while×4, return×2, for×1.
//  - Notable callees: __allmul×2, FUN_00770490, FUN_007709e0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_ecc_sys
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

int Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_007709e0(int *param_1,int *param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  longlong lVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  uint *puVar10;

  uint uVar11;

  uint *puVar12;

  longlong lVar13;

  int local_81c;

  uint auStack_800 [512];

  

  iVar8 = *param_1 * 2;

  if ((param_2[1] < iVar8) && (iVar5 = FUN_00770490(), iVar5 != 0)) {

    return iVar5;

  }

  uVar11 = 0;

  uVar4 = 0;

  if (0 < iVar8) {

    iVar5 = *param_1;

    iVar7 = param_1[3];

    do {

      uVar6 = iVar5 - 1;

      if ((int)uVar11 <= (int)uVar6) {

        uVar6 = uVar11;

      }

      iVar9 = uVar11 - uVar6;

      local_81c = iVar5 - iVar9;

      puVar10 = (uint *)(iVar7 + iVar9 * 4);

      puVar12 = (uint *)(iVar7 + uVar6 * 4);

      if ((int)(uVar6 + 1) <= local_81c) {

        local_81c = uVar6 + 1;

      }

      lVar2 = 0;

      lVar13 = 0;

      iVar9 = (int)((uVar6 - iVar9) + 1) >> 1;

      if (iVar9 <= local_81c) {

        local_81c = iVar9;

      }

      if (0 < local_81c) {

        do {

          lVar13 = (ulonglong)*puVar12 * (ulonglong)*puVar10 + lVar2;

          puVar12 = puVar12 + -1;

          puVar10 = puVar10 + 1;

          local_81c = local_81c + -1;

          lVar2 = lVar13;

        } while (local_81c != 0);

      }

      lVar13 = __allmul(lVar13,2,0);

      uVar3 = lVar13 + uVar4;

      if ((uVar11 & 1) == 0) {

        uVar1 = *(uint32_t /* width from decompiler */ *)(param_1[3] + ((int)uVar11 >> 1) * 4);

        lVar13 = __allmul(uVar1,0,uVar1,0);

        uVar3 = lVar13 + uVar3;

      }

      uVar4 = uVar3 >> 0x1c;

      auStack_800[uVar11] = (uint)uVar3 & 0xfffffff;

      uVar11 = uVar11 + 1;

    } while ((int)uVar11 < iVar8);

  }

  iVar5 = *param_2;

  puVar10 = (uint *)param_2[3];

  *param_2 = *param_1 * 2;

  iVar7 = 0;

  if (0 < iVar8) {

    do {

      *puVar10 = auStack_800[iVar7] & 0xfffffff;

      iVar7 = iVar7 + 1;

      puVar10 = puVar10 + 1;

    } while (iVar7 < iVar8);

  }

  if (iVar7 < iVar5) {

    for (iVar5 = iVar5 - iVar7; iVar5 != 0; iVar5 = iVar5 + -1) {

      *puVar10 = 0;

      puVar10 = puVar10 + 1;

    }

  }

  iVar8 = *param_2;

  if (0 < iVar8) {

    do {

      if (*(int *)(param_2[3] + -4 + *param_2 * 4) != 0) break;

      iVar8 = *param_2 + -1;

      *param_2 = iVar8;

    } while (0 < iVar8);

    iVar8 = *param_2;

  }

  if (iVar8 == 0) {

    param_2[2] = 0;

  }

  return 0;

}
