// =============================================================================
// Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_008d3e20
// -----------------------------------------------------------------------------
// Stable ID: aa_008d3e20
// Callee of Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_Anoth
// Address:   0x008d3e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_008d3a70, FUN_008d3b30, FUN_008d3c90, FUN_008d3e20.
//  - Return sites: 4.

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

void Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_008d3e20(void)



{

  int iVar1;

  int in_EAX;

  

  iVar1 = *(int *)(in_EAX + 0x568);

  if (iVar1 == 0) {

    FUN_008d3a70();

    return;

  }

  if (iVar1 != 1) {

    if (iVar1 == 2) {

      FUN_008d3b30();

      return;

    }

    return;

  }

  FUN_008d3c90();

  return;

}
