// =============================================================================
// FUN_0077bf80
// -----------------------------------------------------------------------------
// Stable ID: aa_0077bf80
// Address:   0x0077bf80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0077bf80 @ 0x0077bf80
// Stable ID: aa_0077bf80
// Embedded strings (evidence for future rename):
//   - "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"
//   - "pt != NULL"
//   - "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\ciphers\\aes\\aes.c"
//   - "ct != NULL"
//   - "skey != NULL"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~128 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: CONCAT11×4, CONCAT21×4, CONCAT31×4, fprintf×3, raise×3, FUN_0077bf80.
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

void FUN_0077bf80(uint8_t *param_1,uint8_t *param_2,int param_3)



{

  uint *puVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  uint uVar8;

  int iVar9;

  uint8_t local_10;

  

  if (param_2 == (uint8_t *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "pt != NULL",0x1df,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\ciphers\\aes\\aes.c");

    raise(0x16);

  }

  if (param_1 == (uint8_t *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "ct != NULL",0x1e0,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\ciphers\\aes\\aes.c");

    raise(0x16);

  }

  if (param_3 == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "skey != NULL",0x1e1,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\ciphers\\aes\\aes.c");

    raise(0x16);

  }

  uVar2 = CONCAT31(CONCAT21(CONCAT11(*param_1,param_1[1]),param_1[2]),param_1[3]) ^

          *(uint *)(param_3 + 0x100);

  uVar7 = CONCAT31(CONCAT21(CONCAT11(param_1[4],param_1[5]),param_1[6]),param_1[7]) ^

          *(uint *)(param_3 + 0x104);

  uVar3 = CONCAT31(CONCAT21(CONCAT11(param_1[8],param_1[9]),param_1[10]),param_1[0xb]) ^

          *(uint *)(param_3 + 0x108);

  uVar4 = CONCAT31(CONCAT21(CONCAT11(param_1[0xc],param_1[0xd]),param_1[0xe]),param_1[0xf]) ^

          *(uint *)(param_3 + 0x10c);

  uVar5 = *(uint *)(&DAT_00a21b58 + (uVar4 >> 0x10 & 0xff) * 4) ^

          *(uint *)(&DAT_00a21f58 + (uVar3 >> 8 & 0xff) * 4) ^

          *(uint *)(&DAT_00a1f758 + (uVar2 >> 0x18) * 4) ^

          *(uint *)(&DAT_00a22358 + (uVar7 & 0xff) * 4) ^ *(uint *)(param_3 + 0x110);

  uVar6 = *(uint *)(&DAT_00a21f58 + (uVar4 >> 8 & 0xff) * 4) ^

          *(uint *)(&DAT_00a1f758 + (uVar7 >> 0x18) * 4) ^

          *(uint *)(&DAT_00a21b58 + (uVar2 >> 0x10 & 0xff) * 4) ^

          *(uint *)(&DAT_00a22358 + (uVar3 & 0xff) * 4) ^ *(uint *)(param_3 + 0x114);

  uVar8 = *(uint *)(&DAT_00a1f758 + (uVar3 >> 0x18) * 4) ^

          *(uint *)(&DAT_00a21b58 + (uVar7 >> 0x10 & 0xff) * 4) ^

          *(uint *)(&DAT_00a21f58 + (uVar2 >> 8 & 0xff) * 4) ^

          *(uint *)(&DAT_00a22358 + (uVar4 & 0xff) * 4) ^ *(uint *)(param_3 + 0x118);

  uVar2 = *(uint *)(&DAT_00a1f758 + (uVar4 >> 0x18) * 4) ^

          *(uint *)(&DAT_00a21b58 + (uVar3 >> 0x10 & 0xff) * 4) ^

          *(uint *)(&DAT_00a21f58 + (uVar7 >> 8 & 0xff) * 4) ^

          *(uint *)(&DAT_00a22358 + (uVar2 & 0xff) * 4) ^ *(uint *)(param_3 + 0x11c);

  iVar9 = *(int *)(param_3 + 0x200) >> 1;

  puVar1 = (uint *)(param_3 + 0x120);

  while (iVar9 = iVar9 + -1, iVar9 != 0) {

    uVar7 = *(uint *)(&DAT_00a21b58 + (uVar2 >> 0x10 & 0xff) * 4) ^

            *(uint *)(&DAT_00a21f58 + (uVar8 >> 8 & 0xff) * 4) ^

            *(uint *)(&DAT_00a1f758 + (uVar5 >> 0x18) * 4) ^

            *(uint *)(&DAT_00a22358 + (uVar6 & 0xff) * 4) ^ *puVar1;

    uVar3 = *(uint *)(&DAT_00a21f58 + (uVar2 >> 8 & 0xff) * 4) ^

            *(uint *)(&DAT_00a1f758 + (uVar6 >> 0x18) * 4) ^

            *(uint *)(&DAT_00a21b58 + (uVar5 >> 0x10 & 0xff) * 4) ^

            *(uint *)(&DAT_00a22358 + (uVar8 & 0xff) * 4) ^ puVar1[1];

    uVar4 = *(uint *)(&DAT_00a1f758 + (uVar8 >> 0x18) * 4) ^

            *(uint *)(&DAT_00a21b58 + (uVar6 >> 0x10 & 0xff) * 4) ^

            *(uint *)(&DAT_00a21f58 + (uVar5 >> 8 & 0xff) * 4) ^

            *(uint *)(&DAT_00a22358 + (uVar2 & 0xff) * 4) ^ puVar1[2];

    uVar2 = *(uint *)(&DAT_00a1f758 + (uVar2 >> 0x18) * 4) ^

            *(uint *)(&DAT_00a21b58 + (uVar8 >> 0x10 & 0xff) * 4) ^

            *(uint *)(&DAT_00a21f58 + (uVar6 >> 8 & 0xff) * 4) ^

            *(uint *)(&DAT_00a22358 + (uVar5 & 0xff) * 4) ^ puVar1[3];

    uVar5 = *(uint *)(&DAT_00a21b58 + (uVar2 >> 0x10 & 0xff) * 4) ^

            *(uint *)(&DAT_00a21f58 + (uVar4 >> 8 & 0xff) * 4) ^

            *(uint *)(&DAT_00a1f758 + (uVar7 >> 0x18) * 4) ^

            *(uint *)(&DAT_00a22358 + (uVar3 & 0xff) * 4) ^ puVar1[4];

    uVar6 = *(uint *)(&DAT_00a21f58 + (uVar2 >> 8 & 0xff) * 4) ^

            *(uint *)(&DAT_00a1f758 + (uVar3 >> 0x18) * 4) ^

            *(uint *)(&DAT_00a21b58 + (uVar7 >> 0x10 & 0xff) * 4) ^

            *(uint *)(&DAT_00a22358 + (uVar4 & 0xff) * 4) ^ puVar1[5];

    uVar8 = *(uint *)(&DAT_00a1f758 + (uVar4 >> 0x18) * 4) ^

            *(uint *)(&DAT_00a21b58 + (uVar3 >> 0x10 & 0xff) * 4) ^

            *(uint *)(&DAT_00a21f58 + (uVar7 >> 8 & 0xff) * 4) ^

            *(uint *)(&DAT_00a22358 + (uVar2 & 0xff) * 4) ^ puVar1[6];

    uVar2 = *(uint *)(&DAT_00a1f758 + (uVar2 >> 0x18) * 4) ^

            *(uint *)(&DAT_00a21b58 + (uVar4 >> 0x10 & 0xff) * 4) ^

            *(uint *)(&DAT_00a21f58 + (uVar3 >> 8 & 0xff) * 4) ^

            *(uint *)(&DAT_00a22358 + (uVar7 & 0xff) * 4) ^ puVar1[7];

    puVar1 = puVar1 + 8;

  }

  uVar3 = *(uint *)(&DAT_00a1fb58 + (uVar2 >> 0x10 & 0xff) * 4) & 0xff0000 ^

          *(uint *)(&DAT_00a1fb58 + (uVar8 >> 8 & 0xff) * 4) & 0xff00 ^

          *(uint *)(&DAT_00a1fb58 + (uVar5 >> 0x18) * 4) & 0xff000000 ^

          *(uint *)(&DAT_00a1fb58 + (uVar6 & 0xff) * 4) & 0xff ^ *puVar1;

  *param_2 = (char)(uVar3 >> 0x18);

  param_2[1] = (char)(uVar3 >> 0x10);

  param_2[2] = (char)(uVar3 >> 8);

  param_1._0_1_ = (uint8_t)uVar3;

  param_2[3] = param_1._0_1_;

  uVar3 = *(uint *)(&DAT_00a1fb58 + (uVar5 >> 0x10 & 0xff) * 4) & 0xff0000 ^

          *(uint *)(&DAT_00a1fb58 + (uVar2 >> 8 & 0xff) * 4) & 0xff00 ^

          *(uint *)(&DAT_00a1fb58 + (uVar6 >> 0x18) * 4) & 0xff000000 ^

          *(uint *)(&DAT_00a1fb58 + (uVar8 & 0xff) * 4) & 0xff ^ puVar1[1];

  param_2[4] = (char)(uVar3 >> 0x18);

  param_2[5] = (char)(uVar3 >> 0x10);

  param_2[6] = (char)(uVar3 >> 8);

  param_3._0_1_ = (uint8_t)uVar3;

  param_2[7] = (uint8_t)param_3;

  uVar3 = *(uint *)(&DAT_00a1fb58 + (uVar6 >> 0x10 & 0xff) * 4) & 0xff0000 ^

          *(uint *)(&DAT_00a1fb58 + (uVar8 >> 0x18) * 4) & 0xff000000 ^

          *(uint *)(&DAT_00a1fb58 + (uVar5 >> 8 & 0xff) * 4) & 0xff00 ^

          *(uint *)(&DAT_00a1fb58 + (uVar2 & 0xff) * 4) & 0xff ^ puVar1[2];

  param_2[8] = (char)(uVar3 >> 0x18);

  param_2[9] = (char)(uVar3 >> 0x10);

  param_2[10] = (char)(uVar3 >> 8);

  local_10 = (uint8_t)uVar3;

  param_2[0xb] = local_10;

  uVar5 = *(uint *)(&DAT_00a1fb58 + (uVar8 >> 0x10 & 0xff) * 4) & 0xff0000 ^

          *(uint *)(&DAT_00a1fb58 + (uVar2 >> 0x18) * 4) & 0xff000000 ^

          *(uint *)(&DAT_00a1fb58 + (uVar6 >> 8 & 0xff) * 4) & 0xff00 ^

          *(uint *)(&DAT_00a1fb58 + (uVar5 & 0xff) * 4) & 0xff ^ puVar1[3];

  param_2[0xc] = (char)(uVar5 >> 0x18);

  param_2[0xf] = (char)uVar5;

  param_2[0xd] = (char)(uVar5 >> 0x10);

  param_2[0xe] = (char)(uVar5 >> 8);

  return;

}
