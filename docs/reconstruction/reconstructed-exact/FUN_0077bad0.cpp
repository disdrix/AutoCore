// =============================================================================
// FUN_0077bad0
// -----------------------------------------------------------------------------
// Stable ID: aa_0077bad0
// Address:   0x0077bad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0077bad0 @ 0x0077bad0
// Stable ID: aa_0077bad0
// Embedded strings (evidence for future rename):
//   - "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"
//   - "out != NULL"
//   - "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\prngs\\yarrow.c"
//   - "prng != NULL"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: fprintf×2, raise×2, FUN_0077bad0, FUN_00973d30, FUN_00974320.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "out != NULL"; "prng != NULL".
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

uint FUN_0077bad0(int param_1,uint param_2,int param_3)



{

  int iVar1;

  

  if (param_1 == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "out != NULL",0xcc,"C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\prngs\\yarrow.c"

           );

    raise(0x16);

  }

  if (param_3 == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "prng != NULL",0xcd,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\prngs\\yarrow.c");

    raise(0x16);

  }

  FUN_00974320();

  iVar1 = FUN_00973d30(param_1,param_1,param_2);

  return ~-(uint)(iVar1 != 0) & param_2;

}
