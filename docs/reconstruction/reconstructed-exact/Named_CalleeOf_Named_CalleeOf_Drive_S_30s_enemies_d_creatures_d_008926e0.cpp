// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_S_30s_enemies_d_creatures_d_008926e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008926e0
// Callee of Named_CalleeOf_Drive_S_30s_enemies_d_creatures_d_vehicles_d
// Address:   0x008926e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_S_30s_enemies_d_creatures_d_vehicles_d: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_008908c0, FUN_00891f10, FUN_00892430, FUN_008926e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_S_30s_enemies_d_creatures_d_vehicles_d
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

void Named_CalleeOf_Named_CalleeOf_Drive_S_30s_enemies_d_creatures_d_008926e0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8)



{

  char cVar1;

  int *unaff_ESI;

  

  FUN_00892430(unaff_ESI,param_1,param_2,1);

  FUN_00891f10(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);

  cVar1 = (**(code **)(*unaff_ESI + 0x3d8))();

  if (cVar1 != '\0') {

    FUN_008908c0(unaff_ESI);

  }

  return;

}
