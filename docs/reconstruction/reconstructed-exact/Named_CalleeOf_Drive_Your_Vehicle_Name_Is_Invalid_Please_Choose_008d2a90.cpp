// =============================================================================
// Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_008d2a90
// -----------------------------------------------------------------------------
// Stable ID: aa_008d2a90
// Callee of Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_Anoth
// Address:   0x008d2a90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: switch×1, return×1.
//  - Notable callees: FUN_008d1370, FUN_008d2840, FUN_008d2a90.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_Anoth
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

void Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_008d2a90(void)



{

  uint32_t /* width from decompiler */ in_EAX;

  int unaff_ESI;

  

  switch(in_EAX) {

  case 0:

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x5ac) = 0;

    break;

  case 1:

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x5ac) = 1;

    break;

  case 2:

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x5ac) = 2;

    break;

  case 3:

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x5ac) = 3;

  }

  FUN_008d1370();

  FUN_008d2840(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x5a8),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x5ac),

               *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x5a4));

  return;

}
