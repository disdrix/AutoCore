// =============================================================================
// Named_CalleeOf_CVOGPlayerVehicle_UpdateTurretAiming_004e8b60
// -----------------------------------------------------------------------------
// Stable ID: aa_004e8b60
// Callee of CVOGPlayerVehicle_UpdateTurretAiming
// Address:   0x004e8b60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGPlayerVehicle_UpdateTurretAiming: vehicle helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004e8b60.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGPlayerVehicle_UpdateTurretAiming
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

void Named_CalleeOf_CVOGPlayerVehicle_UpdateTurretAiming_004e8b60(float *param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  

  fVar6 = g_flLevelUpUiBase_Inferred;

  fVar1 = *param_1;

  fVar2 = param_1[2];

  fVar3 = param_1[1];

  fVar4 = param_1[3];

  *param_2 = (fVar1 * fVar3 - fVar2 * fVar4) * g_flLevelUpUiBase_Inferred;

  fVar5 = g_flOne;

  param_2[2] = (fVar2 * fVar3 + fVar1 * fVar4) * fVar6;

  param_2[1] = fVar5 - (fVar2 * fVar2 + fVar1 * fVar1) * fVar6;

  param_2[3] = 0.0;

  return;

}
