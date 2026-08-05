// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_G_005d69a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005d69a0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x
// Address:   0x005d69a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005d69a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_G_005d69a0(float *param_1,float *param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  

  fVar2 = param_3[1] - param_2[0xd];

  fVar3 = param_3[2] - param_2[0xe];

  fVar1 = *param_3 - param_2[0xc];

  *param_1 = param_2[2] * fVar3 + param_2[1] * fVar2 + *param_2 * fVar1;

  param_1[1] = param_2[6] * fVar3 + param_2[5] * fVar2 + param_2[4] * fVar1;

  param_1[2] = param_2[10] * fVar3 + param_2[9] * fVar2 + param_2[8] * fVar1;

  return;

}
