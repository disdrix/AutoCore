// =============================================================================
// Named_CalleeOf_Client_OnVehicleSwitchFailure_0085e970
// -----------------------------------------------------------------------------
// Stable ID: aa_0085e970
// Callee of Client_OnVehicleSwitchFailure
// Address:   0x0085e970  (autoassault.exe, image base 0x400000)
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
//  - Notable callees: FUN_0085e970.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall Named_CalleeOf_Client_OnVehicleSwitchFailure_0085e970(int param_1)



{

  int in_EAX;

  

  *(int *)(param_1 + 0x56c) = in_EAX;

  if (in_EAX != 0) {

    *(int *)(param_1 + 0x50c) = (int)((float)DAT_00d1e818 * (float)_DAT_00d1e50c * DAT_00aaa67c);

    *(int *)(param_1 + 0x510) = (int)((float)DAT_00d1e81c * (float)_DAT_00d1e510 * DAT_00aaa678);

  }

  return;

}
