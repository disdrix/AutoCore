// =============================================================================
// FUN_007783f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007783f0
// Address:   0x007783f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007783f0 @ 0x007783f0
// Stable ID: aa_007783f0
// Embedded strings (evidence for future rename):
//   - "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"
//   - "md != NULL"
//   - "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\hashes\\md5.c"
//   - "out != NULL"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, while×2.
//  - Notable callees: FUN_00777d60×2, fprintf×2, raise×2, CARRY4, FUN_007783f0.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "md != NULL"; "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\hashes\\md5.c"; "out != NULL".
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

uint32_t /* width from decompiler */ FUN_007783f0(uint *param_1,uint *param_2)



{

  uint uVar1;

  uint uVar2;

  

  if (param_1 == (uint *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "md != NULL",0x109,"C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\hashes\\md5.c");

    raise(0x16);

  }

  if (param_2 == (uint *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "out != NULL",0x10a,"C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\hashes\\md5.c")

    ;

    raise(0x16);

  }

  uVar2 = param_1[6];

  if (0x3f < uVar2) {

    return 0x10;

  }

  uVar1 = *param_1;

  *param_1 = *param_1 + uVar2 * 8;

  param_1[1] = param_1[1] + (uint)CARRY4(uVar1,uVar2 * 8);

  *(uint8_t *)(uVar2 + 0x1c + (int)param_1) = 0x80;

  param_1[6] = param_1[6] + 1;

  uVar2 = param_1[6];

  if (0x38 < uVar2) {

    while (uVar2 < 0x40) {

      *(uint8_t *)(uVar2 + 0x1c + (int)param_1) = 0;

      param_1[6] = param_1[6] + 1;

      uVar2 = param_1[6];

    }

    FUN_00777d60(param_1);

    param_1[6] = 0;

  }

  uVar2 = param_1[6];

  while (uVar2 < 0x38) {

    *(uint8_t *)(param_1[6] + 0x1c + (int)param_1) = 0;

    param_1[6] = param_1[6] + 1;

    uVar2 = param_1[6];

  }

  *(uint8_t *)((int)param_1 + 0x5b) = *(uint8_t *)((int)param_1 + 7);

  *(uint8_t *)((int)param_1 + 0x5a) = *(uint8_t *)((int)param_1 + 6);

  *(uint8_t *)((int)param_1 + 0x59) = *(uint8_t *)((int)param_1 + 5);

  *(char *)(param_1 + 0x16) = (char)param_1[1];

  *(uint8_t *)((int)param_1 + 0x57) = *(uint8_t *)((int)param_1 + 3);

  *(uint8_t *)((int)param_1 + 0x56) = *(uint8_t *)((int)param_1 + 2);

  *(uint8_t *)((int)param_1 + 0x55) = *(uint8_t *)((int)param_1 + 1);

  *(char *)(param_1 + 0x15) = (char)*param_1;

  FUN_00777d60(param_1);

  *param_2 = param_1[2];

  param_2[1] = param_1[3];

  param_2[2] = param_1[4];

  param_2[3] = param_1[5];

  return 0;

}
