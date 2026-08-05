// =============================================================================
// Named_CalleeOf_Drive_Loading_Vehicles_00833120
// -----------------------------------------------------------------------------
// Stable ID: aa_00833120
// Callee of Drive_Loading_Vehicles
// Address:   0x00833120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_Loading_Vehicles: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004fcd80, FUN_004fd970, FUN_00833120.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Drive_Loading_Vehicles
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

void Named_CalleeOf_Drive_Loading_Vehicles_00833120(void)



{

  uint32_t /* width from decompiler */ in_EAX;

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0x508) != 0) {

    FUN_004fd970(in_EAX);

    FUN_004fcd80(0);

  }

  return;

}
