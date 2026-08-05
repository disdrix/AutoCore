// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI_00782b40
// -----------------------------------------------------------------------------
// Stable ID: aa_00782b40
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance
// Address:   0x00782b40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×6, goto×1, return×1.
//  - Notable callees: FUN_00782b40.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI_00782b40(void)



{

  int iVar1;

  int *unaff_EBX;

  int *unaff_ESI;

  int unaff_EDI;

  

  unaff_ESI[4] = *(int *)(unaff_EDI + 0x10);

  if (unaff_EDI == unaff_EBX[1]) {

    unaff_EBX[1] = (int)unaff_ESI;

  }

  else {

    iVar1 = *(int *)(unaff_EDI + 0x10);

    if (*(int *)(iVar1 + 0xc) == unaff_EDI) {

      *(int **)(iVar1 + 0xc) = unaff_ESI;

    }

    else if (*(int *)(iVar1 + 8) == unaff_EDI) {

      *(int **)(iVar1 + 8) = unaff_ESI;

    }

  }

  *(int **)(unaff_EDI + 0x10) = unaff_ESI;

  iVar1 = (**(code **)(*unaff_ESI + 4))(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x14));

  if (iVar1 < 1) {

    if (-1 < iVar1) goto LAB_00782ba2;

    unaff_ESI[2] = unaff_EDI;

    unaff_ESI[3] = *(int *)(unaff_EDI + 0xc);

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc) = 0;

    iVar1 = unaff_ESI[3];

  }

  else {

    unaff_ESI[3] = unaff_EDI;

    unaff_ESI[2] = *(int *)(unaff_EDI + 8);

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8) = 0;

    iVar1 = unaff_ESI[2];

  }

  if (iVar1 != 0) {

    *(int **)(iVar1 + 0x10) = unaff_ESI;

  }

LAB_00782ba2:

  *unaff_EBX = *unaff_EBX + 1;

  return 1;

}
