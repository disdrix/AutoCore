// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00772190
// -----------------------------------------------------------------------------
// Stable ID: aa_00772190
// Callee of Named_CalleeOf_Named_ecc_sys
// Address:   0x00772190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, for×1, return×1.
//  - Notable callees: FUN_00770490, FUN_00772190.
//  - Return sites: 1.

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

int Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00772190(int *param_1)



{

  int *in_EAX;

  int iVar1;

  uint uVar2;

  uint uVar3;

  int iVar4;

  uint *puVar5;

  uint *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  

  if ((*param_1 <= in_EAX[1]) || (iVar1 = FUN_00770490(), iVar1 == 0)) {

    iVar1 = *param_1;

    iVar4 = *in_EAX;

    *in_EAX = iVar1;

    puVar5 = (uint *)(param_1[3] + -4 + iVar1 * 4);

    puVar6 = (uint *)(in_EAX[3] + -4 + iVar1 * 4);

    uVar2 = 0;

    if (-1 < iVar1 + -1) {

      do {

        uVar3 = uVar2 << 0x1b;

        uVar2 = *puVar5 & 1;

        *puVar6 = *puVar5 >> 1 | uVar3;

        puVar6 = puVar6 + -1;

        puVar5 = puVar5 + -1;

        iVar1 = iVar1 + -1;

      } while (iVar1 != 0);

    }

    iVar1 = *in_EAX;

    if (iVar1 < iVar4) {

      puVar7 = (uint32_t /* width from decompiler */ *)(in_EAX[3] + iVar1 * 4);

      for (iVar4 = iVar4 - iVar1; iVar4 != 0; iVar4 = iVar4 + -1) {

        *puVar7 = 0;

        puVar7 = puVar7 + 1;

      }

    }

    iVar1 = *in_EAX;

    in_EAX[2] = param_1[2];

    if (0 < iVar1) {

      do {

        if (*(int *)(in_EAX[3] + -4 + *in_EAX * 4) != 0) break;

        iVar1 = *in_EAX + -1;

        *in_EAX = iVar1;

      } while (0 < iVar1);

      iVar1 = *in_EAX;

    }

    if (iVar1 == 0) {

      in_EAX[2] = 0;

    }

    iVar1 = 0;

  }

  return iVar1;

}
