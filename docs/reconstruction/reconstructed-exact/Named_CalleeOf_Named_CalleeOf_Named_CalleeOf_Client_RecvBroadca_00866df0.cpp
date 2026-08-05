// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvBroadca_00866df0
// -----------------------------------------------------------------------------
// Stable ID: aa_00866df0
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast
// Address:   0x00866df0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_00866df0.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvBroadca_00866df0(void)



{

  char cVar1;

  int unaff_ESI;

  

  if ((*(int *)(unaff_ESI + 0x530) != 0) &&

     (cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x530) + 0xd0))(), cVar1 != '\0')) {

    return 1;

  }

  if ((*(int *)(unaff_ESI + 0x534) != 0) &&

     (cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x534) + 0xd0))(), cVar1 != '\0')) {

    return 1;

  }

  if ((*(int *)(unaff_ESI + 0x538) != 0) &&

     (cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x538) + 0xd0))(), cVar1 != '\0')) {

    return 1;

  }

  return 0;

}
