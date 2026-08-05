// =============================================================================
// Named_CalleeOf_Inv_switched_vehicles_and_no_room_for_old_vehicl_004f4f00
// -----------------------------------------------------------------------------
// Stable ID: aa_004f4f00
// Callee of Inv_switched_vehicles_and_no_room_for_old_vehicle_in
// Address:   0x004f4f00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Inv_switched_vehicles_and_no_room_for_old_vehicl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_004f4f00, FUN_0056a260.
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

void __fastcall Named_CalleeOf_Inv_switched_vehicles_and_no_room_for_old_vehicl_004f4f00(int param_1)



{

  int *piVar1;

  int iVar2;

  

  iVar2 = 0;

  do {

    if (*(int *)(iVar2 + *(int *)(param_1 + 0x260)) != 0) {

      FUN_0056a260(0);

      piVar1 = *(int **)(iVar2 + *(int *)(param_1 + 0x260));

      if (piVar1[2] == 0) {

        (**(code **)*piVar1)(1,0,0,0,0,0,0,g_flOne,0);

      }

      else {

        (**(code **)(*piVar1 + 0x18))(1);

      }

    }

    iVar2 = iVar2 + 4;

  } while (iVar2 < 0xc);

  return;

}
