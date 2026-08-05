// =============================================================================
// Named_CalleeOf_CVOGPlayerVehicle_UpdateTurretAiming_004e9530
// -----------------------------------------------------------------------------
// Stable ID: aa_004e9530
// Callee of CVOGPlayerVehicle_UpdateTurretAiming
// Address:   0x004e9530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGPlayerVehicle_UpdateTurretAiming: vehicle helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004e9530.
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

void Named_CalleeOf_CVOGPlayerVehicle_UpdateTurretAiming_004e9530(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ local_14;

  

  uVar1 = param_2[1];

  uVar2 = param_2[2];

  *param_1 = *param_2;

  param_1[1] = uVar1;

  param_1[2] = uVar2;

  param_1[3] = local_14;

  return;

}
