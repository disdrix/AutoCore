// =============================================================================
// FUN_0077dc20
// -----------------------------------------------------------------------------
// Stable ID: aa_0077dc20
// Address:   0x0077dc20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0077dc20 @ 0x0077dc20
// Stable ID: aa_0077dc20
// Embedded strings (evidence for future rename):
//   - "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"
//   - "md != NULL"
//   - "c:\\vog\\1_code\\torquenetworklibrary\\libtomcrypt\\hashes\\sha2\\sha224.c"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0077dc20, fprintf, raise.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "md != NULL".
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

uint32_t /* width from decompiler */ FUN_0077dc20(uint32_t /* width from decompiler */ *param_1)



{

  if (param_1 == (uint32_t /* width from decompiler */ *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "md != NULL",0x29,

            "c:\\vog\\1_code\\torquenetworklibrary\\libtomcrypt\\hashes\\sha2\\sha224.c");

    raise(0x16);

  }

  param_1[10] = 0;

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = 0xc1059ed8;

  param_1[3] = 0x367cd507;

  param_1[4] = 0x3070dd17;

  param_1[5] = 0xf70e5939;

  param_1[6] = 0xffc00b31;

  param_1[7] = 0x68581511;

  param_1[8] = 0x64f98fa7;

  param_1[9] = 0xbefa4fa4;

  return 0;

}
