// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_00782e60
// -----------------------------------------------------------------------------
// Stable ID: aa_00782e60
// Callee of Named_CalleeOf_Named_Client_InitInstance
// Address:   0x00782e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×2, for×2, while×2.
//  - Notable callees: FUN_00782e60×3, FUN_00782890×2, FUN_00782a90×2, FUN_00782b40×2.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Client_InitInstance
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

int Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_00782e60(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  if (param_1 == 0) {

    return 0;

  }

  iVar2 = FUN_00782a90();

  iVar3 = FUN_00782a90();

  iVar2 = iVar2 - iVar3;

  if (iVar2 < 2) {

    if ((iVar2 < -1) && (iVar3 = -(iVar2 / 2), 0 < iVar3)) {

      do {

        piVar1 = (int *)(param_1 + 8);

        param_1 = *piVar1;

        for (iVar2 = *(int *)(*piVar1 + 0xc); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {

          param_1 = iVar2;

        }

        FUN_00782890();

        FUN_00782b40();

        iVar3 = iVar3 + -1;

      } while (iVar3 != 0);

    }

  }

  else {

    iVar2 = iVar2 / 2;

    if (0 < iVar2) {

      do {

        piVar1 = (int *)(param_1 + 0xc);

        param_1 = *piVar1;

        for (iVar3 = *(int *)(*piVar1 + 8); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {

          param_1 = iVar3;

        }

        FUN_00782890();

        FUN_00782b40();

        iVar2 = iVar2 + -1;

      } while (iVar2 != 0);

    }

  }

  if (*(int *)(param_1 + 0xc) != 0) {

    uVar4 = Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_00782e60(*(int *)(param_1 + 0xc));

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = uVar4;

  }

  if (*(int *)(param_1 + 8) != 0) {

    uVar4 = Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_00782e60(*(int *)(param_1 + 8));

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

  }

  return param_1;

}
