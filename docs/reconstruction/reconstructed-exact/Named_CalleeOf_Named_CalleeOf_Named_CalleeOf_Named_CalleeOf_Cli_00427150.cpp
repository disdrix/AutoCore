// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00427150
// -----------------------------------------------------------------------------
// Stable ID: aa_00427150
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvBroadca
// Address:   0x00427150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvBroadca: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, goto×1, return×1.
//  - Notable callees: FUN_00427150, FUN_004272b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvBroadca
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

int * Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00427150(int *param_1,int param_2)



{

  int iVar1;

  int unaff_EDI;

  

  iVar1 = *(int *)(unaff_EDI + 4);

  if (iVar1 != 0) {

    if ((*(int *)(unaff_EDI + 8) - iVar1) / 0x60 != 0) {

      iVar1 = (param_2 - iVar1) / 0x60;

      goto LAB_00427197;

    }

  }

  iVar1 = 0;

LAB_00427197:

  FUN_004272b0(unaff_EDI,param_2);

  *param_1 = iVar1 * 0x60 + *(int *)(unaff_EDI + 4);

  return param_1;

}
