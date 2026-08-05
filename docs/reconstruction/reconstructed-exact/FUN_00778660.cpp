// =============================================================================
// FUN_00778660
// -----------------------------------------------------------------------------
// Stable ID: aa_00778660
// Address:   0x00778660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00778660 @ 0x00778660
// Stable ID: aa_00778660
// Embedded strings (evidence for future rename):
//   - "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"
//   - "md != NULL"
//   - "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\hashes\\md5.c"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00778660, fprintf, raise.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "md != NULL"; "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\hashes\\md5.c".
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

uint32_t /* width from decompiler */ FUN_00778660(uint32_t /* width from decompiler */ *param_1)



{

  if (param_1 == (uint32_t /* width from decompiler */ *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "md != NULL",0xec,"C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\hashes\\md5.c");

    raise(0x16);

  }

  param_1[2] = 0x67452301;

  param_1[3] = 0xefcdab89;

  param_1[4] = 0x98badcfe;

  param_1[5] = 0x10325476;

  param_1[6] = 0;

  *param_1 = 0;

  param_1[1] = 0;

  return 0;

}
