// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_005961f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005961f0
// Callee of Named_CalleeOf_Named_SkyBoxParticles
// Address:   0x005961f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_SkyBoxParticles: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005d68f0×2, FUN_005961f0, SQRT.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_SkyBoxParticles
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_005961f0(int *param_1,int param_2,int param_3,int *param_4,int *param_5)



{

  float local_30;

  float local_2c;

  float local_28;

  float local_20;

  float local_1c;

  float local_18;

  

  *param_1 = param_2;

  param_1[1] = param_3;

  param_1[4] = *param_4;

  param_1[5] = param_4[1];

  param_1[6] = param_4[2];

  param_1[7] = param_4[3];

  param_1[8] = *param_5;

  param_1[9] = param_5[1];

  param_1[10] = param_5[2];

  param_1[0xb] = param_5[3];

  FUN_005d68f0(*(int *)(param_2 + 0x3c) + 0x80,param_4);

  FUN_005d68f0(*(int *)(param_3 + 0x3c) + 0x80,param_5);

  param_1[0xc] = (int)SQRT((local_30 - local_20) * (local_30 - local_20) +

                           (local_2c - local_1c) * (local_2c - local_1c) +

                           (local_28 - local_18) * (local_28 - local_18));

  return;

}
