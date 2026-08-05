// =============================================================================
// Named_CalleeOf_Client_CreateVehicleObjectApply_009972a0
// -----------------------------------------------------------------------------
// Stable ID: aa_009972a0
// Callee of Client_CreateVehicleObjectApply
// Address:   0x009972a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_CreateVehicleObjectApply: vehicle/entity helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00401380, FUN_004608a0, FUN_00996ff0, FUN_009972a0.
//  - Return sites: 1.

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

void Named_CalleeOf_Client_CreateVehicleObjectApply_009972a0(void)



{

  int *piVar1;

  int in_EAX;

  

  if ((9 < *(uint *)(in_EAX + 0x158)) &&

     (piVar1 = *(int **)(in_EAX + 0x154), piVar1 != (int *)*piVar1)) {

    FUN_004608a0();

    FUN_00996ff0(piVar1[4],piVar1[5]);

  }

  FUN_00401380();

  return;

}
