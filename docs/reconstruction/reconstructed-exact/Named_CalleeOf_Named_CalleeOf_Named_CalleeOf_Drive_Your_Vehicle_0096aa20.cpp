// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_0096aa20
// -----------------------------------------------------------------------------
// Stable ID: aa_0096aa20
// Callee of Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invali
// Address:   0x0096aa20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invali: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_0096aa20.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invali
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

int __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_0096aa20(uint32_t /* width from decompiler */ param_1,int param_2,int param_3)



{

  int iVar1;

  int *piVar2;

  

  piVar2 = *(int **)(param_2 + 0xc);

  iVar1 = 0;

  while( true ) {

    if (piVar2 == *(int **)(param_2 + 0x10)) {

      return -1;

    }

    if (*(int *)(*(int *)(*piVar2 + 0xf4) + 8) == param_3) break;

    piVar2 = piVar2 + 1;

    iVar1 = iVar1 + 1;

  }

  return iVar1;

}
