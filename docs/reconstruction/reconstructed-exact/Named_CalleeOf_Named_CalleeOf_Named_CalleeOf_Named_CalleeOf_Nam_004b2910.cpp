// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004b2910
// -----------------------------------------------------------------------------
// Stable ID: aa_004b2910
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x004b2910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: ROUND×3, FUN_004b2910.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004b2910(float param_1,char *param_2,byte *param_3,byte *param_4)



{

  byte *pbVar1;

  

  pbVar1 = param_4;

  param_4._0_1_ = (char)(int)ROUND((float)(int)((uint)param_4[2] - (uint)param_3[2]) * param_1);

  param_2[2] = param_3[2] + (char)param_4;

  param_4._0_1_ = (char)(int)ROUND((float)(int)((uint)pbVar1[1] - (uint)param_3[1]) * param_1);

  param_2[1] = param_3[1] + (char)param_4;

  param_4._0_1_ = (char)(int)ROUND((float)(int)((uint)*pbVar1 - (uint)*param_3) * param_1);

  *param_2 = *param_3 + (char)param_4;

  return;

}
