// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, do×1, while×1.
//  - Notable callees: fprintf×3, raise×3, FUN_00974160.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "in != NULL"; "out != NULL"; "outlen != NULL".
//  - Return sites: 2.

// =============================================================================
// Named_base64_encode_00974160
// -----------------------------------------------------------------------------
// Stable ID: aa_00974160
// Address:   0x00974160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "base64_encode"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_base64_encode_00974160(uint param_1,uint8_t *param_2,uint *param_3)



{

  byte *pbVar1;

  byte bVar2;

  undefined *puVar3;

  uint8_t uVar4;

  byte *in_EAX;

  uint8_t *puVar5;

  uint8_t *puVar6;

  int iVar7;

  uint uVar8;

  uint uVar9;

  

  if (in_EAX == (byte *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "in != NULL",0x26,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\misc\\base64\\base64_encode.c");

    raise(0x16);

  }

  if (param_2 == (uint8_t *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "out != NULL",0x27,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\misc\\base64\\base64_encode.c");

    raise(0x16);

  }

  if (param_3 == (uint *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "outlen != NULL",0x28,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\misc\\base64\\base64_encode.c");

    raise(0x16);

  }

  puVar3 = PTR_s_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef_00afa2a4;

  if (((param_1 + 2) / 3) * 4 + 1 <= *param_3) {

    iVar7 = (param_1 / 3) * 3;

    uVar8 = 0;

    puVar6 = param_2;

    if (iVar7 != 0) {

      iVar7 = (iVar7 - 1U) / 3 + 1;

      uVar8 = iVar7 * 3;

      puVar5 = param_2;

      do {

        *puVar5 = puVar3[*in_EAX >> 2];

        puVar5[1] = puVar3[(uint)(in_EAX[1] >> 4) + (uint)*in_EAX * 0x10 & 0x3f];

        puVar6 = puVar5 + 4;

        puVar5[2] = puVar3[(uint)(in_EAX[2] >> 6) + (uint)in_EAX[1] * 4 & 0x3f];

        pbVar1 = in_EAX + 2;

        in_EAX = in_EAX + 3;

        iVar7 = iVar7 + -1;

        puVar5[3] = puVar3[*pbVar1 & 0x3f];

        puVar5 = puVar6;

      } while (iVar7 != 0);

    }

    if (uVar8 < param_1) {

      bVar2 = *in_EAX;

      if (uVar8 + 1 < param_1) {

        uVar9 = (uint)in_EAX[1];

      }

      else {

        uVar9 = 0;

      }

      *puVar6 = puVar3[bVar2 >> 2];

      puVar6[1] = puVar3[(uVar9 >> 4) + (uint)bVar2 * 0x10 & 0x3f];

      if (uVar8 + 1 < param_1) {

        uVar4 = puVar3[(uVar9 & 0xf) * 4];

      }

      else {

        uVar4 = 0x3d;

      }

      puVar6[2] = uVar4;

      puVar6[3] = 0x3d;

      puVar6 = puVar6 + 4;

    }

    *puVar6 = 0;

    *param_3 = (int)puVar6 - (int)param_2;

    return 0;

  }

  return 6;

}
