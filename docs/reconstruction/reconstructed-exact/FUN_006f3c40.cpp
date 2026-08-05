// =============================================================================
// FUN_006f3c40
// -----------------------------------------------------------------------------
// Stable ID: aa_006f3c40
// Address:   0x006f3c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f3c40 @ 0x006f3c40
// Stable ID: aa_006f3c40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_006f3900×5, FUN_006f3c40.
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

void __thiscall FUN_006f3c40(int param_1,uint8_t param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  

  *(char *)((*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc)) + -1 + *(int *)(param_1 + 0x10)) =

       (char)param_3;

  iVar1 = *(int *)(param_1 + 0xc) + 1;

  *(int *)(param_1 + 0xc) = iVar1;

  if (*(int *)(param_1 + 8) <= iVar1) {

    FUN_006f3900();

  }

  *(char *)((*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc)) + -1 + *(int *)(param_1 + 0x10)) =

       (char)((uint)param_3 >> 8);

  iVar1 = *(int *)(param_1 + 0xc) + 1;

  *(int *)(param_1 + 0xc) = iVar1;

  if (*(int *)(param_1 + 8) <= iVar1) {

    FUN_006f3900();

  }

  *(char *)((*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc)) + -1 + *(int *)(param_1 + 0x10)) =

       (char)((uint)param_3 >> 0x10);

  iVar1 = *(int *)(param_1 + 0xc) + 1;

  *(int *)(param_1 + 0xc) = iVar1;

  if (*(int *)(param_1 + 8) <= iVar1) {

    FUN_006f3900();

  }

  *(char *)((*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc)) + -1 + *(int *)(param_1 + 0x10)) =

       (char)((uint)param_3 >> 0x18);

  iVar1 = *(int *)(param_1 + 0xc) + 1;

  *(int *)(param_1 + 0xc) = iVar1;

  if (*(int *)(param_1 + 8) <= iVar1) {

    FUN_006f3900();

  }

  *(uint8_t *)((*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc)) + -1 + *(int *)(param_1 + 0x10))

       = param_2;

  iVar1 = *(int *)(param_1 + 0xc) + 1;

  *(int *)(param_1 + 0xc) = iVar1;

  if (*(int *)(param_1 + 8) <= iVar1) {

    FUN_006f3900();

  }

  return;

}
