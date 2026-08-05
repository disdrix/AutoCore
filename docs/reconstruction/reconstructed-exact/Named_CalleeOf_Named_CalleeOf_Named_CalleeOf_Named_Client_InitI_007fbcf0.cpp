// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI_007fbcf0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fbcf0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance
// Address:   0x007fbcf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: CONCAT22, FUN_007fbcf0.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI_007fbcf0(void)



{

  int iVar1;

  

  if (DAT_00d1b252 == 1) {

    return 0x4b;

  }

  iVar1 = DAT_00d1b252 - 2;

  if (iVar1 != 0) {

    return CONCAT22((short)((uint)iVar1 >> 0x10),100);

  }

  return 0x32;

}
