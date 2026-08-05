// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0077dcb0, fprintf, raise.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "md != NULL".
//  - Return sites: 1.

// =============================================================================
// Named_sha256_0077dcb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0077dcb0
// Address:   0x0077dcb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "sha256"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_sha256_0077dcb0(uint32_t /* width from decompiler */ *param_1)



{

  if (param_1 == (uint32_t /* width from decompiler */ *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "md != NULL",0xd1,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\hashes\\sha2\\sha256.c");

    raise(0x16);

  }

  param_1[10] = 0;

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = 0x6a09e667;

  param_1[3] = 0xbb67ae85;

  param_1[4] = 0x3c6ef372;

  param_1[5] = 0xa54ff53a;

  param_1[6] = 0x510e527f;

  param_1[7] = 0x9b05688c;

  param_1[8] = 0x1f83d9ab;

  param_1[9] = 0x5be0cd19;

  return 0;

}
