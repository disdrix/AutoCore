// =============================================================================
// FUN_0077bb70
// -----------------------------------------------------------------------------
// Stable ID: aa_0077bb70
// Address:   0x0077bb70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0077bb70 @ 0x0077bb70
// Stable ID: aa_0077bb70
// Embedded strings (evidence for future rename):
//   - "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"
//   - "prng != NULL"
//   - "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\prngs\\yarrow.c"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_0077bb70, FUN_00973b50, fprintf, raise.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "prng != NULL".
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

int FUN_0077bb70(int *param_1)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  

  piVar2 = param_1;

  if (param_1 == (int *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "prng != NULL",0xa9,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\prngs\\yarrow.c");

    raise(0x16);

  }

  iVar3 = piVar2[1];

  if (((-1 < iVar3) && (iVar3 < 0x20)) && ((&DAT_00d183b0)[iVar3 * 0x19] != 0)) {

    iVar1 = *piVar2;

    if (((-1 < iVar1) && (iVar1 < 0x20)) && ((&DAT_00d17a30)[iVar1 * 0x13] != 0)) {

      param_1 = *(int **)(&DAT_00d183b8 + iVar3 * 100);

      iVar3 = (**(code **)(&DAT_00d17a5c + iVar1 * 0x4c))(&param_1);

      if (iVar3 == 0) {

        iVar3 = FUN_00973b50(*piVar2,piVar2 + 2,piVar2 + 2,param_1,0);

      }

      return iVar3;

    }

    return 10;

  }

  return 0xb;

}
