// =============================================================================
// Named_CalleeOf_Client_CreateVehicleObjectApply_00404a00
// -----------------------------------------------------------------------------
// Stable ID: aa_00404a00
// Callee of Client_CreateVehicleObjectApply
// Address:   0x00404a00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_CreateVehicleObjectApply: vehicle/entity helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00404a00.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_CreateVehicleObjectApply
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

int Named_CalleeOf_Client_CreateVehicleObjectApply_00404a00(void)



{

  int in_EAX;

  

  if (*(int *)(in_EAX + 0x124) == 0) {

    return 0;

  }

  return *(int *)(in_EAX + 0x128) - *(int *)(in_EAX + 0x124) >> 2;

}
