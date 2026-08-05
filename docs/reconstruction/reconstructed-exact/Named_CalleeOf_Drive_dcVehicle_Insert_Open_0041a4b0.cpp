// =============================================================================
// Named_CalleeOf_Drive_dcVehicle_Insert_Open_0041a4b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0041a4b0
// Callee of Drive_dcVehicle_Insert_Open
// Address:   0x0041a4b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_dcVehicle_Insert_Open: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0041a4b0, FUN_0041b740, FUN_00423170.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Drive_dcVehicle_Insert_Open
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

void Named_CalleeOf_Drive_dcVehicle_Insert_Open_0041a4b0(int param_1)



{

  int *piVar1;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bd828;

  pvStack_c = ExceptionList;

  local_4 = 0;

  if (param_1 == 0) {

    piVar1 = (int *)0x0;

  }

  else {

    piVar1 = (int *)(param_1 + 0x10);

  }

  ExceptionList = &pvStack_c;

  FUN_00423170();

  piVar1 = (int *)*piVar1;

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 8))(piVar1);

  }

  FUN_0041b740();

  ExceptionList = pvStack_c;

  return;

}
