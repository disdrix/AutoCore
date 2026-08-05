// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_DebugDumpEn_00424b50
// -----------------------------------------------------------------------------
// Stable ID: aa_00424b50
// Callee of Named_CalleeOf_Named_CalleeOf_Client_DebugDumpEntityCombatStats
// Address:   0x00424b50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_DebugDumpEntityCombatStats: combat/reward helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00424b50, SQRT.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_DebugDumpEntityCombatStats
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_DebugDumpEn_00424b50(float *param_1,float *param_2,float *param_3)



{

  float fVar1;

  

  fVar1 = SQRT(*param_2 * *param_2 + *param_3 * *param_3 + *param_1 * *param_1);

  if (fVar1 != g_flZero) {

    fVar1 = g_flOne / fVar1;

    *param_1 = *param_1 * fVar1;

    *param_2 = *param_2 * fVar1;

    *param_3 = *param_3 * fVar1;

  }

  return;

}
