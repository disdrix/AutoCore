// =============================================================================
// FUN_0077f960
// -----------------------------------------------------------------------------
// Stable ID: aa_0077f960
// Address:   0x0077f960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0077f960 @ 0x0077f960
// Stable ID: aa_0077f960
// Embedded strings (evidence for future rename):
//   - "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"
//   - "md != NULL"
//   - "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\hashes\\sha2\\sha256.c"
//   - "out != NULL"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×4, while×2, return×2.
//  - Notable callees: FUN_0077dd40×2, fprintf×2, raise×2, CARRY4, FUN_0077f960.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "md != NULL"; "out != NULL".
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

uint32_t /* width from decompiler */ FUN_0077f960(uint *param_1,uint8_t *param_2)



{

  uint uVar1;

  uint uVar2;

  

  if (param_1 == (uint *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "md != NULL",0xf3,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\hashes\\sha2\\sha256.c");

    raise(0x16);

  }

  if (param_2 == (uint8_t *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "out != NULL",0xf4,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\hashes\\sha2\\sha256.c");

    raise(0x16);

  }

  uVar2 = param_1[10];

  if (uVar2 < 0x40) {

    uVar1 = *param_1;

    *param_1 = *param_1 + uVar2 * 8;

    param_1[1] = param_1[1] + (uint)CARRY4(uVar1,uVar2 * 8);

    *(uint8_t *)(uVar2 + 0x2c + (int)param_1) = 0x80;

    param_1[10] = param_1[10] + 1;

    uVar2 = param_1[10];

    if (0x38 < uVar2) {

      while (uVar2 < 0x40) {

        *(uint8_t *)(uVar2 + 0x2c + (int)param_1) = 0;

        param_1[10] = param_1[10] + 1;

        uVar2 = param_1[10];

      }

      FUN_0077dd40(param_1);

      param_1[10] = 0;

    }

    uVar2 = param_1[10];

    while (uVar2 < 0x38) {

      *(uint8_t *)(param_1[10] + 0x2c + (int)param_1) = 0;

      param_1[10] = param_1[10] + 1;

      uVar2 = param_1[10];

    }

    *(uint8_t *)(param_1 + 0x19) = *(uint8_t *)((int)param_1 + 7);

    *(uint8_t *)((int)param_1 + 0x65) = *(uint8_t *)((int)param_1 + 6);

    *(uint8_t *)((int)param_1 + 0x66) = *(uint8_t *)((int)param_1 + 5);

    *(char *)((int)param_1 + 0x67) = (char)param_1[1];

    *(uint8_t *)(param_1 + 0x1a) = *(uint8_t *)((int)param_1 + 3);

    *(uint8_t *)((int)param_1 + 0x69) = *(uint8_t *)((int)param_1 + 2);

    *(uint8_t *)((int)param_1 + 0x6a) = *(uint8_t *)((int)param_1 + 1);

    *(char *)((int)param_1 + 0x6b) = (char)*param_1;

    FUN_0077dd40(param_1);

    *param_2 = *(uint8_t *)((int)param_1 + 0xb);

    param_2[1] = *(uint8_t *)((int)param_1 + 10);

    param_2[2] = *(uint8_t *)((int)param_1 + 9);

    param_2[3] = (char)param_1[2];

    param_2[4] = *(uint8_t *)((int)param_1 + 0xf);

    param_2[5] = *(uint8_t *)((int)param_1 + 0xe);

    param_2[6] = *(uint8_t *)((int)param_1 + 0xd);

    param_2[7] = (char)param_1[3];

    param_2[8] = *(uint8_t *)((int)param_1 + 0x13);

    param_2[9] = *(uint8_t *)((int)param_1 + 0x12);

    param_2[10] = *(uint8_t *)((int)param_1 + 0x11);

    param_2[0xb] = (char)param_1[4];

    param_2[0xc] = *(uint8_t *)((int)param_1 + 0x17);

    param_2[0xd] = *(uint8_t *)((int)param_1 + 0x16);

    param_2[0xe] = *(uint8_t *)((int)param_1 + 0x15);

    param_2[0xf] = (char)param_1[5];

    param_2[0x10] = *(uint8_t *)((int)param_1 + 0x1b);

    param_2[0x11] = *(uint8_t *)((int)param_1 + 0x1a);

    param_2[0x12] = *(uint8_t *)((int)param_1 + 0x19);

    param_2[0x13] = (char)param_1[6];

    param_2[0x14] = *(uint8_t *)((int)param_1 + 0x1f);

    param_2[0x15] = *(uint8_t *)((int)param_1 + 0x1e);

    param_2[0x16] = *(uint8_t *)((int)param_1 + 0x1d);

    param_2[0x17] = (char)param_1[7];

    param_2[0x18] = *(uint8_t *)((int)param_1 + 0x23);

    param_2[0x19] = *(uint8_t *)((int)param_1 + 0x22);

    param_2[0x1a] = *(uint8_t *)((int)param_1 + 0x21);

    param_2[0x1b] = (char)param_1[8];

    param_2[0x1c] = *(uint8_t *)((int)param_1 + 0x27);

    param_2[0x1d] = *(uint8_t *)((int)param_1 + 0x26);

    param_2[0x1e] = *(uint8_t *)((int)param_1 + 0x25);

    param_2[0x1f] = (char)param_1[9];

    return 0;

  }

  return 0x10;

}
