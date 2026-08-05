// =============================================================================
// FUN_00973b50
// -----------------------------------------------------------------------------
// Stable ID: aa_00973b50
// Address:   0x00973b50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00973b50 @ 0x00973b50
// Stable ID: aa_00973b50
// Embedded strings (evidence for future rename):
//   - "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"
//   - "count != NULL"
//   - "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\modes\\ctr\\ctr_start.c"
//   - "key != NULL"
//   - "ctr != NULL"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, while×1.
//  - Notable callees: fprintf×3, raise×3, FUN_00973b50.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "count != NULL"; "key != NULL"; "ctr != NULL".
//  - Return sites: 2.

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

int FUN_00973b50(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5)



{

  int *in_EAX;

  int iVar1;

  

  if (param_2 == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "count != NULL",0x24,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\modes\\ctr\\ctr_start.c");

    raise(0x16);

  }

  if (param_3 == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "key != NULL",0x25,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\modes\\ctr\\ctr_start.c");

    raise(0x16);

  }

  if (in_EAX == (int *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "ctr != NULL",0x26,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\modes\\ctr\\ctr_start.c");

    raise(0x16);

  }

  if (((-1 < param_1) && (param_1 < 0x20)) && ((&DAT_00d17a30)[param_1 * 0x13] != 0)) {

    iVar1 = (**(code **)(&DAT_00d17a48 + param_1 * 0x4c))(param_3,param_4,param_5,in_EAX + 0x44);

    if (iVar1 == 0) {

      in_EAX[1] = *(int *)(&DAT_00d17a40 + param_1 * 0x4c);

      iVar1 = 0;

      *in_EAX = param_1;

      in_EAX[2] = 0;

      in_EAX[3] = 0;

      if (0 < in_EAX[1]) {

        do {

          *(uint8_t *)((int)in_EAX + iVar1 + 0x10) = *(uint8_t *)(iVar1 + param_2);

          iVar1 = iVar1 + 1;

        } while (iVar1 < in_EAX[1]);

      }

      (**(code **)(&DAT_00d17a4c + *in_EAX * 0x4c))(in_EAX + 4,in_EAX + 0x24,in_EAX + 0x44);

      iVar1 = 0;

    }

    return iVar1;

  }

  return 10;

}
