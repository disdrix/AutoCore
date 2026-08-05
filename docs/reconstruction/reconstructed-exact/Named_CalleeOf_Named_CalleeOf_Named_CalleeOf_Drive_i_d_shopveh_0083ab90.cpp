// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_i_d_shopveh_0083ab90
// -----------------------------------------------------------------------------
// Stable ID: aa_0083ab90
// Callee of Named_CalleeOf_Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_veh
// Address:   0x0083ab90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_veh: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_004fcd80, FUN_004fd970, FUN_00833680, FUN_00833a90, FUN_00833e30, FUN_0083a880, FUN_0083ab90.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_veh
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_i_d_shopveh_0083ab90(int param_1)



{

  int in_EAX;

  

  if ((param_1 != 0) && (in_EAX != 0)) {

    if ((*(int *)(param_1 + 0x508) == 0) || (*(int *)(param_1 + 0x50c) != in_EAX)) {

      FUN_00833e30(in_EAX);

      if (*(int *)(param_1 + 0x508) != 0) {

        FUN_004fd970(0);

        FUN_004fcd80(0);

      }

      FUN_00833680();

    }

    FUN_00833a90(0);

    FUN_0083a880(1);

  }

  return;

}
