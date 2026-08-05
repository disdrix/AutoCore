// =============================================================================
// Named_CalleeOf_CVOGVehicle_GetWeaponSlotTransform_00567ce0
// -----------------------------------------------------------------------------
// Stable ID: aa_00567ce0
// Callee of CVOGVehicle_GetWeaponSlotTransform (+2 other named callers)
// Address:   0x00567ce0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGVehicle_GetWeaponSlotTransform: vehicle helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. CVOGVehicle_GetWeaponSlotTransform (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00567ce0, fcos, fsin.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGVehicle_GetWeaponSlotTransform (+2 other named callers)
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

void __thiscall Named_CalleeOf_CVOGVehicle_GetWeaponSlotTransform_00567ce0(float *param_1,float *param_2,float param_3)



{

  float10 fVar1;

  float10 fVar2;

  

  fVar2 = (float10)DAT_00a0f298;

  fVar1 = (float10)fsin((float10)param_3 * fVar2);

  *param_1 = (float)(fVar1 * (float10)*param_2);

  param_1[1] = (float)(fVar1 * (float10)param_2[1]);

  param_1[2] = (float)(fVar1 * (float10)param_2[2]);

  param_1[3] = (float)(fVar1 * (float10)param_2[3]);

  fVar2 = (float10)fcos((float10)param_3 * fVar2);

  param_1[3] = (float)fVar2;

  return;

}
