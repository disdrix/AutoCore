// =============================================================================
// Named_CalleeOf_Drive_S_30s_enemies_d_creatures_d_vehicles_d_004c6710
// -----------------------------------------------------------------------------
// Stable ID: aa_004c6710
// Callee of Drive_S_30s_enemies_d_creatures_d_vehicles_d
// Address:   0x004c6710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_S_30s_enemies_d_creatures_d_vehicles_d: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~6 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004c4e80, FUN_004c6710.
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

void __thiscall Named_CalleeOf_Drive_S_30s_enemies_d_creatures_d_vehicles_d_004c6710(int param_1,uint32_t /* width from decompiler */ param_2)



{

  *(uint32_t /* width from decompiler */ *)(param_1 + 500) = param_2;

  FUN_004c4e80();

  return;

}
