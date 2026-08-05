// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00771920
// -----------------------------------------------------------------------------
// Stable ID: aa_00771920
// Callee of Named_CalleeOf_Named_ecc_sys
// Address:   0x00771920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, for×1, return×1.
//  - Notable callees: FUN_00770490, FUN_00771920, __allmul.
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

int Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00771920(int *param_1,uint32_t /* width from decompiler */ param_2,int *param_3)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint uVar5;

  uint *puVar6;

  longlong lVar7;

  

  if ((*param_1 + 1 <= param_3[1]) || (iVar1 = FUN_00770490(), iVar1 == 0)) {

    iVar1 = *param_3;

    param_3[2] = param_1[2];

    puVar4 = (uint32_t /* width from decompiler */ *)param_1[3];

    puVar6 = (uint *)param_3[3];

    iVar3 = 0;

    uVar5 = 0;

    if (0 < *param_1) {

      do {

        lVar7 = __allmul(*puVar4,0,param_2,0);

        uVar2 = (uint)(lVar7 + (ulonglong)uVar5);

        uVar5 = uVar2 >> 0x1c | (int)(lVar7 + (ulonglong)uVar5 >> 0x20) * 0x10;

        *puVar6 = uVar2 & 0xfffffff;

        iVar3 = iVar3 + 1;

        puVar4 = puVar4 + 1;

        puVar6 = puVar6 + 1;

      } while (iVar3 < *param_1);

    }

    *puVar6 = uVar5;

    if (iVar3 + 1 < iVar1) {

      for (iVar1 = iVar1 - (iVar3 + 1); puVar6 = puVar6 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {

        *puVar6 = 0;

      }

    }

    iVar1 = *param_1;

    *param_3 = iVar1 + 1;

    if (0 < iVar1 + 1) {

      do {

        if (*(int *)(param_3[3] + -4 + *param_3 * 4) != 0) break;

        iVar1 = *param_3 + -1;

        *param_3 = iVar1;

      } while (0 < iVar1);

    }

    if (*param_3 == 0) {

      param_3[2] = 0;

    }

    iVar1 = 0;

  }

  return iVar1;

}
