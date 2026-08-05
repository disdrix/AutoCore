// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00770850
// -----------------------------------------------------------------------------
// Stable ID: aa_00770850
// Callee of Named_CalleeOf_Named_ecc_sys
// Address:   0x00770850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×9, return×2, do×2, while×2, for×1.
//  - Notable callees: FUN_00770490, FUN_00770850, FUN_00771600.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_ecc_sys
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

int Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00770850(uint param_1,int *param_2)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int *unaff_EBX;

  uint *puVar4;

  

  if ((*unaff_EBX + 1 <= param_2[1]) || (iVar1 = FUN_00770490(), iVar1 == 0)) {

    iVar1 = 1;

    if ((unaff_EBX[2] == 1) && ((1 < *unaff_EBX || (param_1 <= *(uint *)unaff_EBX[3])))) {

      unaff_EBX[2] = 0;

      iVar1 = FUN_00771600();

      param_2[2] = 1;

      unaff_EBX[2] = 1;

      return iVar1;

    }

    iVar3 = *param_2;

    param_2[2] = 0;

    piVar2 = (int *)unaff_EBX[3];

    puVar4 = (uint *)param_2[3];

    if (unaff_EBX[2] == 0) {

      param_1 = *piVar2 + param_1;

      *puVar4 = param_1;

      *puVar4 = param_1 & 0xfffffff;

      iVar1 = 1;

      param_1 = param_1 >> 0x1c;

      puVar4 = puVar4 + 1;

      if (1 < *unaff_EBX) {

        do {

          piVar2 = piVar2 + 1;

          param_1 = *piVar2 + param_1;

          *puVar4 = param_1;

          *puVar4 = param_1 & 0xfffffff;

          iVar1 = iVar1 + 1;

          param_1 = param_1 >> 0x1c;

          puVar4 = puVar4 + 1;

        } while (iVar1 < *unaff_EBX);

      }

      *puVar4 = param_1;

      iVar1 = iVar1 + 1;

      *param_2 = *unaff_EBX + 1;

    }

    else {

      *param_2 = 1;

      if (*unaff_EBX == 1) {

        param_1 = param_1 - *(int *)unaff_EBX[3];

      }

      *puVar4 = param_1;

    }

    if (iVar1 < iVar3) {

      for (iVar3 = iVar3 - iVar1; puVar4 = puVar4 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {

        *puVar4 = 0;

      }

    }

    iVar1 = *param_2;

    if (0 < iVar1) {

      do {

        if (*(int *)(param_2[3] + -4 + *param_2 * 4) != 0) break;

        iVar1 = *param_2 + -1;

        *param_2 = iVar1;

      } while (0 < iVar1);

      iVar1 = *param_2;

    }

    if (iVar1 == 0) {

      param_2[2] = 0;

    }

    iVar1 = 0;

  }

  return iVar1;

}
