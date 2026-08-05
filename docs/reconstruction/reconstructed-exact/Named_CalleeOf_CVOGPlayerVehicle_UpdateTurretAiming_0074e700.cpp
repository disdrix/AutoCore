// =============================================================================
// Named_CalleeOf_CVOGPlayerVehicle_UpdateTurretAiming_0074e700
// -----------------------------------------------------------------------------
// Stable ID: aa_0074e700
// Callee of CVOGPlayerVehicle_UpdateTurretAiming
// Address:   0x0074e700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGPlayerVehicle_UpdateTurretAiming: vehicle helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0074e700.
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

void __thiscall Named_CalleeOf_CVOGPlayerVehicle_UpdateTurretAiming_0074e700(int param_1,char param_2,float param_3)



{

  if (*(char *)(param_1 + 0x56) != param_2) {

    if (param_2 == '\0') {

      *(float *)(param_1 + 0x34) =

           param_3 - (*(float *)(param_1 + 0x40) - *(float *)(param_1 + 0x34));

      *(float *)(param_1 + 0x40) = param_3;

    }

    *(char *)(param_1 + 0x56) = param_2;

  }

  return;

}
