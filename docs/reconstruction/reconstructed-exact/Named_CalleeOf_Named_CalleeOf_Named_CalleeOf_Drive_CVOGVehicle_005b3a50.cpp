// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_CVOGVehicle_005b3a50
// -----------------------------------------------------------------------------
// Stable ID: aa_005b3a50
// Callee of Named_CalleeOf_Named_CalleeOf_Drive_CVOGVehicle_UpdateWaterFX
// Address:   0x005b3a50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Drive_CVOGVehicle_UpdateWaterFX: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×6, if×5, switch×1.
//  - Notable callees: FUN_005b3a50.
//  - Return sites: 6.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Drive_CVOGVehicle_UpdateWaterFX
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_CVOGVehicle_005b3a50(int param_1)



{

  if (param_1 < 0x247) {

    if (0x244 < param_1) {

      return 3;

    }

    switch(param_1) {

    case 0x23c:

    case 0x23d:

      return 0;

    case 0x243:

    case 0x244:

      return 2;

    }

  }

  else if (param_1 < 0x374) {

    if (0x371 < param_1) {

      return 1;

    }

    if ((0x248 < param_1) && (param_1 < 0x24b)) {

      return 4;

    }

  }

  return 0xffffffff;

}
