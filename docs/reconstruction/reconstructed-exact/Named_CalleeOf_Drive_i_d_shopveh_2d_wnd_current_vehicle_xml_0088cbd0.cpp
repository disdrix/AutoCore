// =============================================================================
// Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_current_vehicle_xml_0088cbd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0088cbd0
// Callee of Drive_i_d_shopveh_2d_wnd_current_vehicle_xml
// Address:   0x0088cbd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_i_d_shopveh_2d_wnd_current_vehicle_xml: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0088cbd0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Drive_i_d_shopveh_2d_wnd_current_vehicle_xml
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

void __fastcall Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_current_vehicle_xml_0088cbd0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0x5bc) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x5bc) + 0x1d8))(param_2,1,1);

                    /* WARNING: Could not recover jumptable at 0x0088cbf4. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(**(int **)(unaff_ESI + 0x5bc) + 0x34c))();

    return;

  }

  return;

}
