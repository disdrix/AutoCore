// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_emissionsPerSecond_0049c000
// -----------------------------------------------------------------------------
// Stable ID: aa_0049c000
// Callee of Named_CalleeOf_Mission_emissionsPerSecond
// Address:   0x0049c000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_emissionsPerSecond: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0049baa0, FUN_0049c000.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_emissionsPerSecond
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

float * __fastcall Named_CalleeOf_Named_CalleeOf_Mission_emissionsPerSecond_0049c000(float *param_1)



{

  float fVar1;

  float fVar2;

  

  FUN_0049baa0(1);

  fVar2 = DAT_00a0f704;

  fVar1 = g_flOne;

  *param_1 = g_flOne;

  param_1[4] = fVar1;

  param_1[8] = fVar1;

  param_1[1] = 0.0;

  param_1[2] = 0.0;

  param_1[3] = 0.0;

  param_1[5] = 0.0;

  param_1[6] = 0.0;

  param_1[7] = 0.0;

  param_1[0xb] = 0.0;

  param_1[10] = 0.0;

  param_1[9] = 0.0;

  param_1[0xc] = 0.0;

  param_1[0xe] = 0.0;

  param_1[0xd] = 1.4013e-45;

  param_1[0xf] = 1.4013e-45;

  param_1[0x10] = fVar2;

  param_1[0x11] = fVar2;

  param_1[0x14] = 0.0;

  param_1[0x13] = 0.0;

  param_1[0x12] = 0.0;

  param_1[0x16] = fVar1;

  fVar1 = DAT_00aaa7ac;

  param_1[0x1a] = 0.0;

  param_1[0x1b] = 0.0;

  param_1[0x15] = 0.0;

  param_1[0x17] = fVar1;

  param_1[0x18] = 0.0;

  param_1[0x19] = 3.50325e-44;

  return param_1;

}
