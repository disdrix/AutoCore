// =============================================================================
// Named_CalleeOf_CVOGPlayerVehicle_UpdateTurretAiming_0040d0a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d0a0
// Callee of CVOGPlayerVehicle_UpdateTurretAiming
// Address:   0x0040d0a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGPlayerVehicle_UpdateTurretAiming: vehicle helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: ABS, FUN_0040d0a0, _CIacos.
//  - Return sites: 2.

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

float10 Named_CalleeOf_CVOGPlayerVehicle_UpdateTurretAiming_0040d0a0(float param_1)



{

  float10 fVar1;

  float fVar2;

  

  if (g_flOne <= ABS(param_1)) {

    fVar2 = 0.0;

    if (param_1 <= 0.0) {

      fVar2 = DAT_00a27c3c;

    }

    return (float10)fVar2;

  }

  fVar1 = (float10)_CIacos();

  return fVar1;

}
