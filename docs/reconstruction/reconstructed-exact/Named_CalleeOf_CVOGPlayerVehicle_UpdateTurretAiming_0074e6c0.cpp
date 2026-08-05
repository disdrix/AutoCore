// =============================================================================
// Named_CalleeOf_CVOGPlayerVehicle_UpdateTurretAiming_0074e6c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0074e6c0
// Callee of CVOGPlayerVehicle_UpdateTurretAiming
// Address:   0x0074e6c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGPlayerVehicle_UpdateTurretAiming: vehicle helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0074e6c0.
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

void __thiscall Named_CalleeOf_CVOGPlayerVehicle_UpdateTurretAiming_0074e6c0(int param_1,float param_2)



{

  if (param_2 != g_flZero) {

    *(float *)(param_1 + 0x3c) = param_2;

    *(float *)(param_1 + 0x34) = *(float *)(param_1 + 0x40) - *(float *)(param_1 + 0x44) / param_2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = 0;

  }

  return;

}
