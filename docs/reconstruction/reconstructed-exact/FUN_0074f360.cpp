// =============================================================================
// FUN_0074f360
// -----------------------------------------------------------------------------
// Stable ID: aa_0074f360
// Address:   0x0074f360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074f360 @ 0x0074f360
// Stable ID: aa_0074f360
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×3, goto×1, return×1.
//  - Notable callees: FUN_0074f360.
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

void __fastcall FUN_0074f360(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x28);

  if (-1 < *(int *)(&DAT_00afe00c + iVar1 * 0xc)) {

    if (*(int *)(param_1 + 0xc) == 0) goto LAB_0074f39f;

    (**(code **)(**(int **)(param_1 + 0xc) + 0x108))(*(int **)(param_1 + 0xc));

  }

  if (*(int *)(param_1 + 0xc) != 0) {

    (**(code **)(**(int **)(param_1 + 0xc) + 0x10c))(*(int **)(param_1 + 0xc));

  }

LAB_0074f39f:

  *(uint32_t /* width from decompiler */ *)(&DAT_00afe00c + iVar1 * 0xc) = 0xffffffff;

  (&DAT_00afe010)[iVar1 * 3] = 0;

  *(uint32_t /* width from decompiler */ *)(&DAT_00afe014 + iVar1 * 0xc) = 0;

  return;

}
