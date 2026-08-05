// =============================================================================
// FUN_0077a180
// -----------------------------------------------------------------------------
// Stable ID: aa_0077a180
// Address:   0x0077a180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0077a180 @ 0x0077a180
// Stable ID: aa_0077a180
// Embedded strings (evidence for future rename):
//   - "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"
//   - "private_key != NULL"
//   - "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c"
//   - "public_key != NULL"
//   - "out != NULL"
//   - "outlen != NULL"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×13, return×5, goto×3.
//  - Notable callees: fprintf×4, raise×4, FUN_00770120×2, FUN_007715b0×2, FUN_007726e0×2, FUN_007789e0×2, FUN_00770440, FUN_007707d0.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "private_key != NULL"; "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c"; "public_key != NULL".
//  - Return sites: 5.

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

int FUN_0077a180(int *param_1,int param_2,int param_3,uint *param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint8_t local_10 [16];

  

  if (param_1 == (int *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "private_key != NULL",0x467,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c");

    raise(0x16);

  }

  if (param_2 == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "public_key != NULL",0x468,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c");

    raise(0x16);

  }

  if (param_3 == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "out != NULL",0x469,"C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c"

           );

    raise(0x16);

  }

  if (param_4 == (uint *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "outlen != NULL",0x46a,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c");

    raise(0x16);

  }

  if (*param_1 != 0) {

    return 0xf;

  }

  if (param_1[1] != *(int *)(param_2 + 4)) {

    return 0xe;

  }

  iVar1 = FUN_00778a00();

  if (iVar1 == 0) {

    return 0xd;

  }

  iVar2 = FUN_00770440();

  if (iVar2 != 0) {

    FUN_007789e0();

    iVar1 = FUN_00770120();

    return iVar1;

  }

  iVar2 = FUN_00772910(0x40);

  if (iVar2 == 0) {

    iVar2 = FUN_00779c60(param_1 + 0xe,param_2 + 8,iVar1,local_10);

    if (iVar2 != 0) goto LAB_0077a34a;

    iVar2 = FUN_007715b0();

    iVar3 = FUN_007715b0();

    if (*param_4 < (uint)(iVar3 + iVar2)) {

      iVar2 = 6;

      goto LAB_0077a34a;

    }

    *param_4 = iVar3 + iVar2;

    iVar3 = FUN_007726e0(iVar1,param_3);

    if (iVar3 == 0) {

      iVar1 = FUN_007726e0(iVar1 + 0x10,iVar2 + param_3);

      if (iVar1 == 0) {

        iVar2 = 0;

        goto LAB_0077a34a;

      }

    }

  }

  iVar2 = FUN_00770120();

LAB_0077a34a:

  FUN_007707d0();

  FUN_007789e0();

  return iVar2;

}
