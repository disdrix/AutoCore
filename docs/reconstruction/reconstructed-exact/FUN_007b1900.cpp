// =============================================================================
// FUN_007b1900
// -----------------------------------------------------------------------------
// Stable ID: aa_007b1900
// Address:   0x007b1900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b1900 @ 0x007b1900
// Stable ID: aa_007b1900
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_0099ed40×14, FUN_007b1900.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_007b1900(void)



{

  int iVar1;

  

  FUN_0099ed40((int)((float)DAT_00d1e81c * _DAT_00aaab30));

  FUN_0099ed40((int)((float)DAT_00d1e81c * _DAT_00aaab2c));

  iVar1 = (int)((float)DAT_00d1e81c * _DAT_00aaab28);

  if (iVar1 < 0x10) {

    iVar1 = 0xf;

  }

  FUN_0099ed40(iVar1);

  iVar1 = (int)((float)DAT_00d1e81c * _DAT_00aaab24);

  if (iVar1 < 0xf) {

    iVar1 = 0xe;

  }

  FUN_0099ed40(iVar1);

  iVar1 = (int)((float)DAT_00d1e81c * _DAT_00aaa7b0);

  if (iVar1 < 0xd) {

    iVar1 = 0xc;

  }

  FUN_0099ed40(iVar1);

  iVar1 = (int)((float)DAT_00d1e81c * _DAT_00aaab24);

  if (iVar1 < 0xf) {

    iVar1 = 0xe;

  }

  FUN_0099ed40(iVar1);

  FUN_0099ed40((int)((float)DAT_00d1e81c * _DAT_00aaab20));

  iVar1 = (int)((float)DAT_00d1e81c * _DAT_00aaab24);

  if (iVar1 < 0xf) {

    iVar1 = 0xe;

  }

  FUN_0099ed40(iVar1);

  iVar1 = (int)((float)DAT_00d1e81c * DAT_00aaa9ec);

  if (iVar1 < 0xc) {

    iVar1 = 0xb;

  }

  FUN_0099ed40(iVar1);

  FUN_0099ed40((int)((float)DAT_00d1e81c * _DAT_00aaab1c));

  FUN_0099ed40((int)((float)DAT_00d1e81c * _DAT_00aaab18));

  FUN_0099ed40((int)((float)DAT_00d1e81c * _DAT_00aaab14));

  FUN_0099ed40((int)((float)DAT_00d1e81c * _DAT_00aaab10));

  FUN_0099ed40((int)((float)DAT_00d1e81c * DAT_00a1e8b4));

  return;

}
