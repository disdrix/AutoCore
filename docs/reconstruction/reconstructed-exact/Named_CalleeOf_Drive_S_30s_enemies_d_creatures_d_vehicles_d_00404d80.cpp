// =============================================================================
// Named_CalleeOf_Drive_S_30s_enemies_d_creatures_d_vehicles_d_00404d80
// -----------------------------------------------------------------------------
// Stable ID: aa_00404d80
// Callee of Drive_S_30s_enemies_d_creatures_d_vehicles_d
// Address:   0x00404d80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_S_30s_enemies_d_creatures_d_vehicles_d: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_00404d80.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Drive_S_30s_enemies_d_creatures_d_vehicles_d
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

void Named_CalleeOf_Drive_S_30s_enemies_d_creatures_d_vehicles_d_00404d80(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int param_3,code *param_4)



{

  if (-1 < param_3 + -1) {

    do {

      (*param_4)();

      param_3 = param_3 + -1;

    } while (param_3 != 0);

  }

  return;

}
