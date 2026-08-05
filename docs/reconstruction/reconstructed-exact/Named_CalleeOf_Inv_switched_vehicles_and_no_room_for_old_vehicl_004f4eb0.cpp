// =============================================================================
// Named_CalleeOf_Inv_switched_vehicles_and_no_room_for_old_vehicl_004f4eb0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f4eb0
// Callee of Inv_switched_vehicles_and_no_room_for_old_vehicle_in
// Address:   0x004f4eb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Inv_switched_vehicles_and_no_room_for_old_vehicl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: do×1, if×1, while×1, return×1.
//  - Notable callees: FUN_004f4eb0, FUN_0056a260, FUN_0056b400.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Inv_switched_vehicles_and_no_room_for_old_vehicle_in
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

void __fastcall Named_CalleeOf_Inv_switched_vehicles_and_no_room_for_old_vehicl_004f4eb0(int param_1)



{

  int iVar1;

  

  iVar1 = 0;

  do {

    if (*(int *)(iVar1 + *(int *)(param_1 + 0x260)) != 0) {

      FUN_0056a260(0);

      FUN_0056b400(0);

      (**(code **)(**(int **)(iVar1 + *(int *)(param_1 + 0x260)) + 0x18))(0);

    }

    iVar1 = iVar1 + 4;

  } while (iVar1 < 0xc);

  return;

}
