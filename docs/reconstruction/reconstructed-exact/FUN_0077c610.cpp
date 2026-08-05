// =============================================================================
// FUN_0077c610
// -----------------------------------------------------------------------------
// Stable ID: aa_0077c610
// Address:   0x0077c610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0077c610 @ 0x0077c610
// Stable ID: aa_0077c610
// Embedded strings (evidence for future rename):
//   - "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"
//   - "pt != NULL"
//   - "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\ciphers\\aes\\aes.c"
//   - "ct != NULL"
//   - "skey != NULL"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~125 non-empty decompiler lines.
//  - Control keywords: if×4, while×1, return×1.
//  - Notable callees: CONCAT11×4, CONCAT21×4, CONCAT31×4, fprintf×3, raise×3, FUN_0077c610.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "pt != NULL"; "ct != NULL"; "skey != NULL".
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

void FUN_0077c610(uint8_t *param_1,uint8_t *param_2,uint *param_3)



{

  uint uVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  int iVar8;

  uint8_t local_c;

  

  if (param_1 == (uint8_t *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "pt != NULL",0x12f,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\ciphers\\aes\\aes.c");

    raise(0x16);

  }

  if (param_2 == (uint8_t *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "ct != NULL",0x130,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\ciphers\\aes\\aes.c");

    raise(0x16);

  }

  if (param_3 == (uint *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "skey != NULL",0x131,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\ciphers\\aes\\aes.c");

    raise(0x16);

  }

  uVar6 = CONCAT31(CONCAT21(CONCAT11(param_1[4],param_1[5]),param_1[6]),param_1[7]) ^ param_3[1];

  uVar1 = CONCAT31(CONCAT21(CONCAT11(*param_1,param_1[1]),param_1[2]),param_1[3]) ^ *param_3;

  uVar2 = CONCAT31(CONCAT21(CONCAT11(param_1[8],param_1[9]),param_1[10]),param_1[0xb]) ^ param_3[2];

  uVar4 = CONCAT31(CONCAT21(CONCAT11(param_1[0xc],param_1[0xd]),param_1[0xe]),param_1[0xf]) ^

          param_3[3];

  uVar3 = *(uint *)(&DAT_00a20358 + (uVar2 >> 8 & 0xff) * 4) ^

          *(uint *)(&DAT_00a1ff58 + (uVar6 >> 0x10 & 0xff) * 4) ^

          *(uint *)(&DAT_00a1ef58 + (uVar1 >> 0x18) * 4) ^

          *(uint *)(&DAT_00a20758 + (uVar4 & 0xff) * 4) ^ param_3[4];

  uVar5 = *(uint *)(&DAT_00a20358 + (uVar4 >> 8 & 0xff) * 4) ^

          *(uint *)(&DAT_00a1ff58 + (uVar2 >> 0x10 & 0xff) * 4) ^

          *(uint *)(&DAT_00a1ef58 + (uVar6 >> 0x18) * 4) ^

          *(uint *)(&DAT_00a20758 + (uVar1 & 0xff) * 4) ^ param_3[5];

  uVar7 = *(uint *)(&DAT_00a1ff58 + (uVar4 >> 0x10 & 0xff) * 4) ^

          *(uint *)(&DAT_00a1ef58 + (uVar2 >> 0x18) * 4) ^

          *(uint *)(&DAT_00a20358 + (uVar1 >> 8 & 0xff) * 4) ^

          *(uint *)(&DAT_00a20758 + (uVar6 & 0xff) * 4) ^ param_3[6];

  uVar1 = *(uint *)(&DAT_00a1ef58 + (uVar4 >> 0x18) * 4) ^

          *(uint *)(&DAT_00a20358 + (uVar6 >> 8 & 0xff) * 4) ^

          *(uint *)(&DAT_00a1ff58 + (uVar1 >> 0x10 & 0xff) * 4) ^

          *(uint *)(&DAT_00a20758 + (uVar2 & 0xff) * 4) ^ param_3[7];

  iVar8 = (int)param_3[0x80] >> 1;

  while( true ) {

    iVar8 = iVar8 + -1;

    param_3 = param_3 + 8;

    if (iVar8 == 0) break;

    uVar4 = *(uint *)(&DAT_00a20358 + (uVar1 >> 8 & 0xff) * 4) ^

            *(uint *)(&DAT_00a1ff58 + (uVar7 >> 0x10 & 0xff) * 4) ^

            *(uint *)(&DAT_00a1ef58 + (uVar5 >> 0x18) * 4) ^

            *(uint *)(&DAT_00a20758 + (uVar3 & 0xff) * 4) ^ param_3[1];

    uVar6 = *(uint *)(&DAT_00a1ff58 + (uVar1 >> 0x10 & 0xff) * 4) ^

            *(uint *)(&DAT_00a1ef58 + (uVar7 >> 0x18) * 4) ^

            *(uint *)(&DAT_00a20358 + (uVar3 >> 8 & 0xff) * 4) ^

            *(uint *)(&DAT_00a20758 + (uVar5 & 0xff) * 4) ^ param_3[2];

    uVar2 = *(uint *)(&DAT_00a20358 + (uVar7 >> 8 & 0xff) * 4) ^

            *(uint *)(&DAT_00a1ff58 + (uVar5 >> 0x10 & 0xff) * 4) ^

            *(uint *)(&DAT_00a1ef58 + (uVar3 >> 0x18) * 4) ^

            *(uint *)(&DAT_00a20758 + (uVar1 & 0xff) * 4) ^ *param_3;

    uVar1 = *(uint *)(&DAT_00a1ef58 + (uVar1 >> 0x18) * 4) ^

            *(uint *)(&DAT_00a20358 + (uVar5 >> 8 & 0xff) * 4) ^

            *(uint *)(&DAT_00a1ff58 + (uVar3 >> 0x10 & 0xff) * 4) ^

            *(uint *)(&DAT_00a20758 + (uVar7 & 0xff) * 4) ^ param_3[3];

    uVar3 = *(uint *)(&DAT_00a20358 + (uVar6 >> 8 & 0xff) * 4) ^

            *(uint *)(&DAT_00a1ff58 + (uVar4 >> 0x10 & 0xff) * 4) ^

            *(uint *)(&DAT_00a1ef58 + (uVar2 >> 0x18) * 4) ^

            *(uint *)(&DAT_00a20758 + (uVar1 & 0xff) * 4) ^ param_3[4];

    uVar5 = *(uint *)(&DAT_00a20358 + (uVar1 >> 8 & 0xff) * 4) ^

            *(uint *)(&DAT_00a1ff58 + (uVar6 >> 0x10 & 0xff) * 4) ^

            *(uint *)(&DAT_00a1ef58 + (uVar4 >> 0x18) * 4) ^

            *(uint *)(&DAT_00a20758 + (uVar2 & 0xff) * 4) ^ param_3[5];

    uVar7 = *(uint *)(&DAT_00a1ff58 + (uVar1 >> 0x10 & 0xff) * 4) ^

            *(uint *)(&DAT_00a1ef58 + (uVar6 >> 0x18) * 4) ^

            *(uint *)(&DAT_00a20358 + (uVar2 >> 8 & 0xff) * 4) ^

            *(uint *)(&DAT_00a20758 + (uVar4 & 0xff) * 4) ^ param_3[6];

    uVar1 = *(uint *)(&DAT_00a1ef58 + (uVar1 >> 0x18) * 4) ^

            *(uint *)(&DAT_00a20358 + (uVar4 >> 8 & 0xff) * 4) ^

            *(uint *)(&DAT_00a1ff58 + (uVar2 >> 0x10 & 0xff) * 4) ^

            *(uint *)(&DAT_00a20758 + (uVar6 & 0xff) * 4) ^ param_3[7];

  }

  uVar2 = *(uint *)(&DAT_00a20f58 + (uVar7 >> 8 & 0xff) * 4) ^

          *(uint *)(&DAT_00a21358 + (uVar5 >> 0x10 & 0xff) * 4) ^

          *(uint *)(&DAT_00a21758 + (uVar3 >> 0x18) * 4) ^

          *(uint *)(&DAT_00a20b58 + (uVar1 & 0xff) * 4) ^ *param_3;

  *param_2 = (char)(uVar2 >> 0x18);

  param_2[1] = (char)(uVar2 >> 0x10);

  param_2[2] = (char)(uVar2 >> 8);

  param_1._0_1_ = (uint8_t)uVar2;

  param_2[3] = param_1._0_1_;

  uVar2 = *(uint *)(&DAT_00a20f58 + (uVar1 >> 8 & 0xff) * 4) ^

          *(uint *)(&DAT_00a21358 + (uVar7 >> 0x10 & 0xff) * 4) ^

          *(uint *)(&DAT_00a21758 + (uVar5 >> 0x18) * 4) ^

          *(uint *)(&DAT_00a20b58 + (uVar3 & 0xff) * 4) ^ param_3[1];

  param_2[4] = (char)(uVar2 >> 0x18);

  param_2[5] = (char)(uVar2 >> 0x10);

  param_2[6] = (char)(uVar2 >> 8);

  local_c = (uint8_t)uVar2;

  param_2[7] = local_c;

  uVar2 = *(uint *)(&DAT_00a21358 + (uVar1 >> 0x10 & 0xff) * 4) ^

          *(uint *)(&DAT_00a21758 + (uVar7 >> 0x18) * 4) ^

          *(uint *)(&DAT_00a20f58 + (uVar3 >> 8 & 0xff) * 4) ^

          *(uint *)(&DAT_00a20b58 + (uVar5 & 0xff) * 4) ^ param_3[2];

  param_2[8] = (char)(uVar2 >> 0x18);

  param_2[9] = (char)(uVar2 >> 0x10);

  param_2[10] = (char)(uVar2 >> 8);

  param_1._0_1_ = (uint8_t)uVar2;

  param_2[0xb] = param_1._0_1_;

  uVar3 = *(uint *)(&DAT_00a21758 + (uVar1 >> 0x18) * 4) ^

          *(uint *)(&DAT_00a20f58 + (uVar5 >> 8 & 0xff) * 4) ^

          *(uint *)(&DAT_00a21358 + (uVar3 >> 0x10 & 0xff) * 4) ^

          *(uint *)(&DAT_00a20b58 + (uVar7 & 0xff) * 4) ^ param_3[3];

  param_2[0xc] = (char)(uVar3 >> 0x18);

  param_2[0xd] = (char)(uVar3 >> 0x10);

  param_2[0xe] = (char)(uVar3 >> 8);

  param_2[0xf] = (char)uVar3;

  return;

}
