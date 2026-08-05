// =============================================================================
// FUN_0077bf00
// -----------------------------------------------------------------------------
// Stable ID: aa_0077bf00
// Address:   0x0077bf00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0077bf00 @ 0x0077bf00
// Stable ID: aa_0077bf00
// Embedded strings (evidence for future rename):
//   - "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"
//   - "keysize != NULL"
//   - "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\ciphers\\aes\\aes.c"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: FUN_0077bf00, fprintf, raise.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "keysize != NULL".
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ FUN_0077bf00(int *param_1)



{

  int iVar1;

  

  if (param_1 == (int *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "keysize != NULL",0x2e5,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\ciphers\\aes\\aes.c");

    raise(0x16);

  }

  iVar1 = *param_1;

  if (iVar1 < 0x10) {

    return 3;

  }

  if (iVar1 < 0x18) {

    *param_1 = 0x10;

    return 0;

  }

  if (iVar1 < 0x20) {

    *param_1 = 0x18;

    return 0;

  }

  *param_1 = 0x20;

  return 0;

}
