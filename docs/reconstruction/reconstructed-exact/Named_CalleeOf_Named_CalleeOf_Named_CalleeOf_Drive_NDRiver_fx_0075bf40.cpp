// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx_0075bf40
// -----------------------------------------------------------------------------
// Stable ID: aa_0075bf40
// Callee of Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx
// Address:   0x0075bf40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx: drive/input helper. Evidence string: "DiffuseTexture". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "DiffuseTexture"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00752370, FUN_0075bf40, FUN_00970060.
//  - Strings: "DiffuseTexture".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx_0075bf40(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  int local_4;

  

  piVar1 = &local_4;

  if (*(int *)(param_1 + 0x134) == 0) {

    local_4 = -1;

  }

  else {

    local_4 = param_1;

    piVar1 = (int *)FUN_00752370(piVar1,"DiffuseTexture");

  }

  if (-1 < *piVar1) {

    FUN_00970060(*piVar1,0);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x148) = param_2;

  *(uint8_t *)(param_1 + 0x129) = 1;

  return 0;

}
