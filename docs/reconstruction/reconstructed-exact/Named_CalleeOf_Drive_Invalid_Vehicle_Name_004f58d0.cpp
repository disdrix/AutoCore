// =============================================================================
// Named_CalleeOf_Drive_Invalid_Vehicle_Name_004f58d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f58d0
// Callee of Drive_Invalid_Vehicle_Name
// Address:   0x004f58d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_Invalid_Vehicle_Name: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_004f58d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Drive_Invalid_Vehicle_Name
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

void Named_CalleeOf_Drive_Invalid_Vehicle_Name_004f58d0(void)



{

  int iVar1;

  

  iVar1 = 8;

  do {

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  return;

}
