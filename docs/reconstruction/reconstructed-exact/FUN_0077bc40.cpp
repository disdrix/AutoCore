// =============================================================================
// FUN_0077bc40
// -----------------------------------------------------------------------------
// Stable ID: aa_0077bc40
// Address:   0x0077bc40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0077bc40 @ 0x0077bc40
// Stable ID: aa_0077bc40
// Embedded strings (evidence for future rename):
//   - "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"
//   - "prng != NULL"
//   - "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\prngs\\yarrow.c"
//   - "out != NULL"
//   - "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\misc\\zeromem.c"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, for×1.
//  - Notable callees: fprintf×2, raise×2, FUN_0077bc40, FUN_00973c90, FUN_00973f70.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "prng != NULL"; "out != NULL".
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_0077bc40(int *param_1)



{

  int iVar1;

  int *piVar2;

  

  if (param_1 == (int *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "prng != NULL",0x2a,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\prngs\\yarrow.c");

    raise(0x16);

  }

  iVar1 = FUN_00973f70();

  *param_1 = iVar1;

  if (((-1 < iVar1) && (iVar1 < 0x20)) && ((&DAT_00d17a30)[iVar1 * 0x13] != 0)) {

    iVar1 = FUN_00973c90();

    param_1[1] = iVar1;

    if (((-1 < iVar1) && (iVar1 < 0x20)) && ((&DAT_00d183b0)[iVar1 * 0x19] != 0)) {

      if (param_1 + 2 == (int *)0x0) {

        fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

                "out != NULL",0x1a,

                "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\misc\\zeromem.c");

        raise(0x16);

      }

      piVar2 = param_1 + 2;

      for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {

        *piVar2 = 0;

        piVar2 = piVar2 + 1;

      }

      return 0;

    }

    return 0xb;

  }

  return 10;

}
