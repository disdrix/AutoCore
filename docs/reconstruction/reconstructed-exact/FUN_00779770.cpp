// =============================================================================
// FUN_00779770
// -----------------------------------------------------------------------------
// Stable ID: aa_00779770
// Address:   0x00779770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00779770 @ 0x00779770
// Stable ID: aa_00779770
// Embedded strings (evidence for future rename):
//   - "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"
//   - "pt != NULL"
//   - "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: if×10, return×2, do×2, while×2, goto×2.
//  - Notable callees: FUN_00770650×2, FUN_007707d0×2, FUN_007716f0×2, FUN_00772910×2, FUN_00770440, FUN_00770820, FUN_00770850, FUN_00771920.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "pt != NULL"; "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c".
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

uint32_t /* width from decompiler */ FUN_00779770(int param_1,int param_2)



{

  int iVar1;

  uint uVar2;

  uint *puVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint8_t local_40 [16];

  int local_30 [3];

  int local_24;

  uint8_t local_20 [32];

  

  if (param_1 == 0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "pt != NULL",0x3ae,"C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c")

    ;

    raise(0x16);

  }

  iVar1 = FUN_00771cb0(local_40,local_30,local_20,0);

  if (iVar1 != 0) {

    return 0xd;

  }

  uVar2 = FUN_00772910(0x40);

  if (uVar2 == 0) {

    uVar2 = FUN_00775a40(param_1,3);

    if (((((uVar2 == 0) && (uVar2 = FUN_00771920(param_1,3,local_30), uVar2 == 0)) &&

         (uVar2 = FUN_007716f0(local_40), uVar2 == 0)) &&

        ((uVar2 = FUN_00772390(), uVar2 == 0 && (uVar2 = FUN_00772910(0x40), uVar2 == 0)))) &&

       ((uVar2 = FUN_00774f50(local_40,local_40), uVar2 == 0 &&

        ((uVar2 = FUN_00770850(1,local_30), uVar2 == 0 && (uVar2 = FUN_00770440(), uVar2 == 0))))))

    {

      uVar2 = FUN_00770650();

      if (uVar2 == 0) {

        puVar3 = (uint *)(local_24 + -4 + local_30[0] * 4);

        uVar2 = 0;

        if (-1 < local_30[0] + -1) {

          do {

            uVar4 = uVar2 << 0x1a;

            uVar2 = *puVar3 & 3;

            *puVar3 = *puVar3 >> 2 | uVar4;

            puVar3 = puVar3 + -1;

            local_30[0] = local_30[0] + -1;

          } while (local_30[0] != 0);

        }

        FUN_00770820();

        FUN_007707d0();

        uVar2 = FUN_007772e0(local_40,local_30,local_20,local_40);

        if (uVar2 == 0) {

          if (param_2 == 0) {

            iVar1 = FUN_00770650();

          }

          else {

            iVar1 = FUN_007716f0(local_20);

          }

          uVar2 = (uint)(iVar1 != 0);

          if (uVar2 == 0) {

            uVar5 = 0;

            goto LAB_00779959;

          }

        }

      }

      else {

        FUN_007707d0();

      }

    }

  }

  iVar1 = 0;

  do {

    if (uVar2 == (&DAT_00a240d0)[iVar1 * 2]) {

      uVar5 = *(uint32_t /* width from decompiler */ *)(&UNK_00a240d4 + iVar1 * 8);

      goto LAB_00779959;

    }

    iVar1 = iVar1 + 1;

  } while (iVar1 < 3);

  uVar5 = 1;

LAB_00779959:

  FUN_00772250(local_20,local_40,local_30,0);

  return uVar5;

}
