// =============================================================================
// Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_current_vehicle_xml_0076e5e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076e5e0
// Callee of Drive_i_d_shopveh_2d_wnd_current_vehicle_xml
// Address:   0x0076e5e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_i_d_shopveh_2d_wnd_current_vehicle_xml: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_0040d450, FUN_0076e5e0, SQRT.
//  - Return sites: 3.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float * Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_current_vehicle_xml_0076e5e0(float *param_1,float *param_2)



{

  char cVar1;

  float fVar2;

  

  fVar2 = *param_2 * *param_2 + param_2[1] * param_2[1] + param_2[2] * param_2[2] +

          param_2[3] * param_2[3];

  if ((fVar2 < _DAT_00a240ec) && (DAT_00aaa640 < fVar2)) {

    return param_1;

  }

  cVar1 = FUN_0040d450(fVar2,0x3f800000,0x358637bd,0x358637bd);

  if (cVar1 == '\0') {

    fVar2 = g_flOne / SQRT(fVar2);

    *param_1 = fVar2 * *param_1;

    param_1[1] = fVar2 * param_1[1];

    param_1[2] = fVar2 * param_1[2];

    param_1[3] = fVar2 * param_1[3];

  }

  else if (param_1 != param_2) {

    *param_1 = *param_2;

    param_1[1] = param_2[1];

    param_1[2] = param_2[2];

    param_1[3] = param_2[3];

    return param_1;

  }

  return param_1;

}
