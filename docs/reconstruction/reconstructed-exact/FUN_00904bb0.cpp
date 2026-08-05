// =============================================================================
// FUN_00904bb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00904bb0
// Address:   0x00904bb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00904bb0 @ 0x00904bb0
// Stable ID: aa_00904bb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×13, return×1.
//  - Notable callees: FUN_00792490, FUN_00904bb0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall FUN_00904bb0(int *param_1)



{

  DAT_00d1d8f4 = 1;

  DAT_00d1d8f5 = 0;

  if (DAT_00d1d8dc != (int *)0x0) {

    (**(code **)(*DAT_00d1d8dc + 4))(0);

  }

  (**(code **)(*param_1 + 0x3ac))();

  FUN_00792490();

  if ((void *)param_1[0x14e] != (void *)0x0) {

    operator_delete__((void *)param_1[0x14e]);

  }

  param_1[0x14e] = 0;

  if ((void *)param_1[0x152] != (void *)0x0) {

    operator_delete__((void *)param_1[0x152]);

  }

  param_1[0x152] = 0;

  if ((void *)param_1[0x153] != (void *)0x0) {

    operator_delete__((void *)param_1[0x153]);

  }

  param_1[0x153] = 0;

  if ((void *)param_1[0x154] != (void *)0x0) {

    operator_delete__((void *)param_1[0x154]);

  }

  param_1[0x154] = 0;

  if ((void *)param_1[0x155] != (void *)0x0) {

    operator_delete__((void *)param_1[0x155]);

  }

  param_1[0x155] = 0;

  if ((void *)param_1[0x156] != (void *)0x0) {

    operator_delete__((void *)param_1[0x156]);

  }

  param_1[0x156] = 0;

  if ((void *)param_1[0x158] != (void *)0x0) {

    operator_delete__((void *)param_1[0x158]);

  }

  param_1[0x158] = 0;

  if ((void *)param_1[0x159] != (void *)0x0) {

    operator_delete__((void *)param_1[0x159]);

  }

  param_1[0x159] = 0;

  if ((void *)param_1[0x15a] != (void *)0x0) {

    operator_delete__((void *)param_1[0x15a]);

  }

  param_1[0x15a] = 0;

  if ((void *)param_1[0x15b] != (void *)0x0) {

    operator_delete__((void *)param_1[0x15b]);

  }

  param_1[0x15b] = 0;

  if ((void *)param_1[0x14f] != (void *)0x0) {

    operator_delete__((void *)param_1[0x14f]);

  }

  param_1[0x14f] = 0;

  if ((void *)param_1[0x150] != (void *)0x0) {

    operator_delete__((void *)param_1[0x150]);

  }

  param_1[0x150] = 0;

  return;

}
