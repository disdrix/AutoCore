// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_dcVehicle_Insert_Open_0041b740
// -----------------------------------------------------------------------------
// Stable ID: aa_0041b740
// Callee of Named_CalleeOf_Drive_dcVehicle_Insert_Open
// Address:   0x0041b740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_dcVehicle_Insert_Open: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0041b740.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_dcVehicle_Insert_Open
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

void Named_CalleeOf_Named_CalleeOf_Drive_dcVehicle_Insert_Open_0041b740(void)



{

  int in_EAX;

  

  if (*(int *)(in_EAX + 0xc) != 0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(*(int *)(in_EAX + 0xc) + 0xc));

  }

  return;

}
