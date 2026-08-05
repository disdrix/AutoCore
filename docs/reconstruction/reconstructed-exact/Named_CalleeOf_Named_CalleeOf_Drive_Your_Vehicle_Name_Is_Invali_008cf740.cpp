// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invali_008cf740
// -----------------------------------------------------------------------------
// Stable ID: aa_008cf740
// Callee of Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose
// Address:   0x008cf740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_008cf3b0×2, FUN_008cf510×2, FUN_008cf740.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose
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

void Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invali_008cf740(void)



{

  int iVar1;

  int unaff_ESI;

  

  iVar1 = *(int *)(unaff_ESI + 0x568);

  if (-1 < iVar1) {

    if (iVar1 < 2) {

      FUN_008cf510(1);

      FUN_008cf3b0(0);

    }

    else if (iVar1 == 2) {

      FUN_008cf510(0);

      FUN_008cf3b0(1);

      return;

    }

  }

  return;

}
