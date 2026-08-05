// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: fprintf×2, raise×2, FUN_0077b940.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "in != NULL"; "prng != NULL".
//  - Return sites: 2.

// =============================================================================
// Named_yarrow_0077b940
// -----------------------------------------------------------------------------
// Stable ID: aa_0077b940
// Address:   0x0077b940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "yarrow"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int Named_yarrow_0077b940(int param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  int iVar1;

  uint8_t local_110 [272];

  

  if (param_1 == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "in != NULL",0x81,"C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\prngs\\yarrow.c")

    ;

    raise(0x16);

  }

  if (param_3 == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "prng != NULL",0x82,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\prngs\\yarrow.c");

    raise(0x16);

  }

  iVar1 = *(int *)(param_3 + 4);

  if (((-1 < iVar1) && (iVar1 < 0x20)) && ((&DAT_00d183b0)[iVar1 * 0x19] != 0)) {

    iVar1 = (**(code **)(&DAT_00d18404 + iVar1 * 100))(local_110);

    if (iVar1 == 0) {

      iVar1 = (**(code **)(&DAT_00d18408 + *(int *)(param_3 + 4) * 100))

                        (local_110,param_3 + 8,

                         *(uint32_t /* width from decompiler */ *)(&DAT_00d183b8 + *(int *)(param_3 + 4) * 100));

      if (iVar1 == 0) {

        iVar1 = (**(code **)(&DAT_00d18408 + *(int *)(param_3 + 4) * 100))

                          (local_110,param_1,param_2);

        if (iVar1 == 0) {

          iVar1 = (**(code **)(&DAT_00d1840c + *(int *)(param_3 + 4) * 100))(local_110,param_3 + 8);

        }

      }

    }

    return iVar1;

  }

  return 0xb;

}
