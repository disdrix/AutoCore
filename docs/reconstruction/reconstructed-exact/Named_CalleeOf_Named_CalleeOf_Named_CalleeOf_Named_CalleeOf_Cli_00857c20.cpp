// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00857c20
// -----------------------------------------------------------------------------
// Stable ID: aa_00857c20
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvCreateC
// Address:   0x00857c20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvCreateC: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: FUN_00857b90×3, FUN_00857c20.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvCreateC
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00857c20(void)



{

  int in_EAX;

  int iVar1;

  

  if (((*(char *)(in_EAX + 0x5b9) == '\0') || (DAT_00d1b644 == 0)) ||

     (iVar1 = *(int *)(DAT_00d1b644 + 0xe4f8), iVar1 == 0)) {

    return;

  }

  if (*(int *)(iVar1 + 0x10) < *(int *)(iVar1 + 0x14)) {

    iVar1 = *(int *)(iVar1 + 0x10);

  }

  else {

    iVar1 = *(int *)(iVar1 + 0x14);

  }

  if (iVar1 < 0x101) {

    FUN_00857b90();

    return;

  }

  if (iVar1 < 0x201) {

    FUN_00857b90();

    return;

  }

  FUN_00857b90();

  return;

}
