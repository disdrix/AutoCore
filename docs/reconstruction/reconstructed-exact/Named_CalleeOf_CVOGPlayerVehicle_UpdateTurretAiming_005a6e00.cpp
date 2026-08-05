// =============================================================================
// Named_CalleeOf_CVOGPlayerVehicle_UpdateTurretAiming_005a6e00
// -----------------------------------------------------------------------------
// Stable ID: aa_005a6e00
// Callee of CVOGPlayerVehicle_UpdateTurretAiming
// Address:   0x005a6e00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGPlayerVehicle_UpdateTurretAiming: vehicle helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005a6e00.
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

int __thiscall Named_CalleeOf_CVOGPlayerVehicle_UpdateTurretAiming_005a6e00(int param_1,char param_2)



{

  if (((*(int *)(param_1 + 0xe8) != 0) && (-1 < param_2)) && (param_2 < *(char *)(param_1 + 0xb0)))

  {

    return *(int *)(param_1 + 0xe8) + param_2 * 0x14c;

  }

  return 0;

}
