// =============================================================================
// FUN_005142a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005142a0
// Address:   0x005142a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005142a0 @ 0x005142a0
// Stable ID: aa_005142a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_004f1e20, FUN_00513580, FUN_005142a0.
//  - Return sites: 2.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int __fastcall FUN_005142a0(int param_1)



{

  int iVar1;

  

  if (*(int *)(*(int *)(param_1 + 0xa8) + 0x3c) == 0) {

    FUN_004f1e20(0,1);

  }

  iVar1 = *(int *)(*(int *)(param_1 + 0xa8) + 0x3c);

  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x3b4) != 1)) {

    return 0;

  }

  iVar1 = FUN_00513580();

  iVar1 = (int)((float)(iVar1 + *(int *)(param_1 + 0xc4)) * _DAT_009ce128);

  if ((*(byte *)(param_1 + 0x17e) & 8) != 0) {

    iVar1 = (int)((float)iVar1 * DAT_00a0f298);

  }

  if (iVar1 < 1) {

    iVar1 = 1;

  }

  return iVar1;

}
