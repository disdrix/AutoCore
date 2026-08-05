// =============================================================================
// FUN_00794140
// -----------------------------------------------------------------------------
// Stable ID: aa_00794140
// Address:   0x00794140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00794140 @ 0x00794140
// Stable ID: aa_00794140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00794140.
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

int __fastcall FUN_00794140(int *param_1)



{

  int iVar1;

  uint8_t *puVar2;

  

  if ((void *)param_1[0x126] != (void *)0x0) {

    operator_delete__((void *)param_1[0x126]);

  }

  param_1[0x126] = 0;

  if (param_1[0x83] != 0) {

    iVar1 = (**(code **)(*param_1 + 0x274))();

    param_1[0x126] = iVar1;

  }

  if (param_1[0x126] == 0) {

    puVar2 = operator_new__(1);

    param_1[0x126] = (int)puVar2;

    *puVar2 = 0;

  }

  return param_1[0x126];

}
