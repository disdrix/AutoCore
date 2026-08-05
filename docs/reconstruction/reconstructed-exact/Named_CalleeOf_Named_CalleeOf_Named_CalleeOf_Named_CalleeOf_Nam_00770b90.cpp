// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00770b90
// -----------------------------------------------------------------------------
// Stable ID: aa_00770b90
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys
// Address:   0x00770b90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×10, do×3, while×3, for×2, return×1.
//  - Notable callees: FUN_00770490, FUN_00770b90.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys
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

int Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00770b90(int *param_1,int *param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  ulonglong uVar4;

  int *in_EAX;

  int iVar5;

  int iVar6;

  uint uVar7;

  uint uVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  uint *puVar12;

  uint *puVar13;

  uint *puVar14;

  uint auStack_800 [512];

  

  if ((*param_1 + *in_EAX <= param_2[1]) || (iVar5 = FUN_00770490(), iVar5 == 0)) {

    iVar5 = *param_1;

    iVar6 = iVar5 + *in_EAX;

    uVar7 = 0;

    uVar4 = 0;

    iVar11 = param_3;

    if (param_3 < iVar6) {

      iVar2 = param_1[3];

      iVar3 = in_EAX[3];

      iVar1 = *in_EAX + -1;

      do {

        iVar9 = iVar1;

        if (iVar11 <= iVar1) {

          iVar9 = iVar11;

        }

        puVar12 = (uint *)(iVar2 + (iVar11 - iVar9) * 4);

        puVar13 = (uint *)(iVar3 + iVar9 * 4);

        iVar10 = iVar5 - (iVar11 - iVar9);

        if (iVar9 + 1 <= iVar10) {

          iVar10 = iVar9 + 1;

        }

        if (0 < iVar10) {

          do {

            uVar4 = (ulonglong)*puVar13 * (ulonglong)*puVar12 + uVar4;

            puVar13 = puVar13 + -1;

            puVar12 = puVar12 + 1;

            iVar10 = iVar10 + -1;

          } while (iVar10 != 0);

        }

        uVar8 = (uint)uVar4;

        uVar4 = uVar4 >> 0x1c;

        uVar7 = (uint)uVar4;

        auStack_800[iVar11] = uVar8 & 0xfffffff;

        iVar11 = iVar11 + 1;

      } while (iVar11 < iVar6);

    }

    auStack_800[iVar11] = uVar7 & 0xfffffff;

    iVar5 = *param_2;

    puVar12 = (uint *)(param_2[3] + param_3 * 4);

    *param_2 = iVar6;

    if (param_3 <= iVar6) {

      iVar6 = (iVar6 - param_3) + 1;

      puVar13 = auStack_800 + param_3;

      puVar14 = puVar12;

      for (iVar11 = iVar6; iVar11 != 0; iVar11 = iVar11 + -1) {

        *puVar14 = *puVar13;

        puVar13 = puVar13 + 1;

        puVar14 = puVar14 + 1;

      }

      param_3 = param_3 + iVar6;

      puVar12 = puVar12 + iVar6;

    }

    if (param_3 < iVar5) {

      for (iVar5 = iVar5 - param_3; iVar5 != 0; iVar5 = iVar5 + -1) {

        *puVar12 = 0;

        puVar12 = puVar12 + 1;

      }

    }

    iVar5 = *param_2;

    if (0 < iVar5) {

      do {

        if (*(int *)(param_2[3] + -4 + *param_2 * 4) != 0) break;

        iVar5 = *param_2 + -1;

        *param_2 = iVar5;

      } while (0 < iVar5);

      iVar5 = *param_2;

    }

    if (iVar5 == 0) {

      param_2[2] = 0;

    }

    iVar5 = 0;

  }

  return iVar5;

}
