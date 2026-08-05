// =============================================================================
// Named_CalleeOf_Client_OnVehicleSwitchFailure_00513e30
// -----------------------------------------------------------------------------
// Stable ID: aa_00513e30
// Callee of Client_OnVehicleSwitchFailure
// Address:   0x00513e30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_OnVehicleSwitchFailure: vehicle/entity helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00512670, FUN_00513e30.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_OnVehicleSwitchFailure
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

void __thiscall Named_CalleeOf_Client_OnVehicleSwitchFailure_00513e30(int param_1,byte param_2)



{

  int extraout_ECX;

  

  if ((*(uint *)(param_1 + 0x17c) >> 0x14 & 1) != (uint)param_2) {

    FUN_00512670();

    param_1 = extraout_ECX;

  }

  *(uint *)(param_1 + 0x17c) =

       *(uint *)(param_1 + 0x17c) ^ ((uint)param_2 << 0x14 ^ *(uint *)(param_1 + 0x17c)) & 0x100000;

  return;

}
