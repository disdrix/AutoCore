// =============================================================================
// FUN_007799d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007799d0
// Address:   0x007799d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007799d0 @ 0x007799d0
// Stable ID: aa_007799d0
// Embedded strings (evidence for future rename):
//   - "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"
//   - "pt != NULL"
//   - "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c"
//   - "result != NULL"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×10, do×3, return×3, while×3, goto×2.
//  - Notable callees: FUN_007707d0×2, FUN_00772910×2, fprintf×2, raise×2, FUN_00770440, FUN_00770650, FUN_007707a0, FUN_00770820.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "pt != NULL"; "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c"; "result != NULL".
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

uint32_t /* width from decompiler */ FUN_007799d0(int param_1,uint32_t /* width from decompiler */ param_2,uint *param_3)



{

  int iVar1;

  int iVar2;

  uint *puVar3;

  uint uVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint8_t local_40 [16];

  int local_30 [3];

  int local_24;

  uint8_t local_20 [32];

  

  if (param_1 == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "pt != NULL",900,"C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c");

    raise(0x16);

  }

  if (param_3 == (uint *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "result != NULL",0x385,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c");

    raise(0x16);

  }

  iVar1 = FUN_00771cb0(local_40,local_30,local_20,0);

  if (iVar1 != 0) {

    iVar2 = 0;

    do {

      if (iVar1 == (&DAT_00a240d0)[iVar2 * 2]) {

        return *(uint32_t /* width from decompiler */ *)(&UNK_00a240d4 + iVar2 * 8);

      }

      iVar2 = iVar2 + 1;

    } while (iVar2 < 3);

    return 1;

  }

  iVar1 = FUN_00772910(0x40);

  if (iVar1 == 0) {

    iVar1 = FUN_00775a40(param_1,3);

    if (((((iVar1 == 0) && (iVar1 = FUN_00771920(param_1,3,local_30), iVar1 == 0)) &&

         (iVar1 = FUN_007716f0(local_40), iVar1 == 0)) &&

        ((iVar1 = FUN_00772390(), iVar1 == 0 && (iVar1 = FUN_00772910(0x40), iVar1 == 0)))) &&

       ((iVar1 = FUN_00774f50(local_40,local_40), iVar1 == 0 &&

        ((iVar1 = FUN_00770850(1,local_30), iVar1 == 0 && (iVar1 = FUN_00770440(), iVar1 == 0))))))

    {

      iVar1 = FUN_00770650();

      if (iVar1 == 0) {

        puVar3 = (uint *)(local_24 + -4 + local_30[0] * 4);

        uVar4 = 0;

        if (-1 < local_30[0] + -1) {

          do {

            uVar5 = uVar4 << 0x1a;

            uVar4 = *puVar3 & 3;

            *puVar3 = *puVar3 >> 2 | uVar5;

            puVar3 = puVar3 + -1;

            local_30[0] = local_30[0] + -1;

          } while (local_30[0] != 0);

        }

        FUN_00770820();

        FUN_007707d0();

        iVar1 = FUN_007772e0(local_40,local_30,local_20,local_40);

        if (iVar1 == 0) {

          iVar1 = FUN_007707a0();

          *param_3 = (uint)(iVar1 != 0);

          uVar6 = 0;

          goto LAB_00779c2f;

        }

      }

      else {

        FUN_007707d0();

      }

    }

  }

  iVar2 = 0;

  do {

    if (iVar1 == (&DAT_00a240d0)[iVar2 * 2]) {

      uVar6 = *(uint32_t /* width from decompiler */ *)(&UNK_00a240d4 + iVar2 * 8);

      goto LAB_00779c2f;

    }

    iVar2 = iVar2 + 1;

  } while (iVar2 < 3);

  uVar6 = 1;

LAB_00779c2f:

  FUN_00772250(local_20,local_40,local_30,0);

  return uVar6;

}
