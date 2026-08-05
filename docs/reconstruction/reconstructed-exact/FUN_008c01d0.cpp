// =============================================================================
// FUN_008c01d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008c01d0
// Address:   0x008c01d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c01d0 @ 0x008c01d0
// Stable ID: aa_008c01d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×9, return×1.
//  - Notable callees: FUN_00792490, FUN_008c01d0.
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

void __fastcall FUN_008c01d0(int *param_1)



{

  DAT_00d1d8f4 = 1;

  DAT_00d1d8f5 = 0;

  if (DAT_00d1d8dc != (int *)0x0) {

    (**(code **)(*DAT_00d1d8dc + 4))(0);

  }

  (**(code **)(*param_1 + 0x3ac))();

  FUN_00792490();

  if ((void *)param_1[0x15e] != (void *)0x0) {

    operator_delete__((void *)param_1[0x15e]);

  }

  param_1[0x15e] = 0;

  if ((void *)param_1[0x15f] != (void *)0x0) {

    operator_delete__((void *)param_1[0x15f]);

  }

  param_1[0x15f] = 0;

  if ((void *)param_1[0x161] != (void *)0x0) {

    operator_delete__((void *)param_1[0x161]);

  }

  param_1[0x161] = 0;

  if ((void *)param_1[0x162] != (void *)0x0) {

    operator_delete__((void *)param_1[0x162]);

  }

  param_1[0x162] = 0;

  if ((void *)param_1[0x163] != (void *)0x0) {

    operator_delete__((void *)param_1[0x163]);

  }

  param_1[0x163] = 0;

  if ((void *)param_1[0x164] != (void *)0x0) {

    operator_delete__((void *)param_1[0x164]);

  }

  param_1[0x164] = 0;

  if ((void *)param_1[0x165] != (void *)0x0) {

    operator_delete__((void *)param_1[0x165]);

  }

  param_1[0x165] = 0;

  if ((void *)param_1[0x166] != (void *)0x0) {

    operator_delete__((void *)param_1[0x166]);

  }

  param_1[0x166] = 0;

  return;

}
