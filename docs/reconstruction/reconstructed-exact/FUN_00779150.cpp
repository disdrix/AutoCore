// =============================================================================
// FUN_00779150
// -----------------------------------------------------------------------------
// Stable ID: aa_00779150
// Address:   0x00779150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00779150 @ 0x00779150
// Stable ID: aa_00779150
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×9, return×3, do×2, while×2, goto×2.
//  - Notable callees: FUN_007716f0×10, FUN_00772390×8, FUN_00775f50×8, FUN_00770770×5, FUN_007707a0×5, FUN_00774b50×4, FUN_00774e60×4, FUN_00770650×3.
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

uint32_t /* width from decompiler */ FUN_00779150(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint8_t local_20 [16];

  int local_10 [3];

  byte *local_4;

  

  iVar1 = FUN_00771cb0(local_20,local_10,0);

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

  iVar1 = FUN_00770650();

  if (iVar1 == 0) {

    iVar2 = param_1 + 0x10;

    iVar1 = FUN_00770650();

    if (iVar1 == 0) {

      iVar3 = param_1 + 0x20;

      iVar1 = FUN_00770650();

      if ((((((iVar1 == 0) && (iVar1 = FUN_00774b50(iVar3,local_20), iVar1 == 0)) &&

            (iVar1 = FUN_00775f50(local_20,param_2,param_3), iVar1 == 0)) &&

           ((iVar1 = FUN_00774e60(iVar3,iVar2,iVar3), iVar1 == 0 &&

            (iVar1 = FUN_00775f50(iVar3,param_2,param_3), iVar1 == 0)))) &&

          ((iVar1 = FUN_00771a00(iVar3,iVar3), iVar1 == 0 &&

           ((iVar1 = FUN_007707a0(), iVar1 == -1 || (iVar1 = FUN_007716f0(iVar3), iVar1 == 0))))))

         && ((iVar1 = FUN_007716f0(param_1), iVar1 == 0 &&

             ((iVar1 = FUN_00770770(), iVar1 != -1 || (iVar1 = FUN_00772390(), iVar1 == 0)))))) {

        iVar1 = FUN_00772390();

        if (((iVar1 == 0) &&

            (((iVar1 = FUN_007707a0(), iVar1 == -1 || (iVar1 = FUN_007716f0(local_20), iVar1 == 0))

             && (iVar1 = FUN_00774e60(local_20,local_10,local_10), iVar1 == 0)))) &&

           ((iVar1 = FUN_00775f50(local_10,param_2,param_3), iVar1 == 0 &&

            (iVar1 = FUN_00771a00(local_10,local_20), iVar1 == 0)))) {

          iVar1 = FUN_007707a0();

          if ((iVar1 == -1) || (iVar1 = FUN_007716f0(local_20), iVar1 == 0)) {

            iVar1 = FUN_00772390();

            if (((((((iVar1 == 0) &&

                    ((iVar1 = FUN_007707a0(), iVar1 == -1 ||

                     (iVar1 = FUN_007716f0(local_20), iVar1 == 0)))) &&

                   ((iVar1 = FUN_00771a00(iVar2,iVar2), iVar1 == 0 &&

                    (((iVar1 = FUN_007707a0(), iVar1 == -1 ||

                      (iVar1 = FUN_007716f0(iVar2), iVar1 == 0)) &&

                     (iVar1 = FUN_00774b50(iVar2,iVar2), iVar1 == 0)))))) &&

                  ((((iVar1 = FUN_00775f50(iVar2,param_2,param_3), iVar1 == 0 &&

                     (iVar1 = FUN_00774b50(iVar2,local_10), iVar1 == 0)) &&

                    (iVar1 = FUN_00775f50(local_10,param_2,param_3), iVar1 == 0)) &&

                   (((local_10[0] < 1 || ((*local_4 & 1) == 0)) ||

                    (iVar1 = FUN_00772390(), iVar1 == 0)))))) &&

                 (((((iVar1 = FUN_00772190(local_10), iVar1 == 0 &&

                     (iVar1 = FUN_00774e60(iVar2,param_1,iVar2), iVar1 == 0)) &&

                    (iVar1 = FUN_00775f50(iVar2,param_2,param_3), iVar1 == 0)) &&

                   ((iVar1 = FUN_00774b50(local_20,param_1), iVar1 == 0 &&

                    (iVar1 = FUN_00775f50(param_1,param_2,param_3), iVar1 == 0)))) &&

                  (iVar1 = FUN_007716f0(param_1), iVar1 == 0)))) &&

                (((iVar1 = FUN_00770770(), iVar1 != -1 || (iVar1 = FUN_00772390(), iVar1 == 0)) &&

                 ((iVar1 = FUN_007716f0(param_1), iVar1 == 0 &&

                  (((iVar1 = FUN_00770770(), iVar1 != -1 || (iVar1 = FUN_00772390(), iVar1 == 0)) &&

                   (iVar1 = FUN_007716f0(iVar2), iVar1 == 0)))))))) &&

               (((((iVar1 = FUN_00770770(), iVar1 != -1 || (iVar1 = FUN_00772390(), iVar1 == 0)) &&

                  (iVar1 = FUN_00774e60(iVar2,local_20,iVar2), iVar1 == 0)) &&

                 ((iVar1 = FUN_00775f50(iVar2,param_2,param_3), iVar1 == 0 &&

                  (iVar1 = FUN_007716f0(iVar2), iVar1 == 0)))) &&

                ((iVar1 = FUN_00770770(), iVar1 != -1 || (iVar1 = FUN_00772390(), iVar1 == 0)))))) {

              uVar4 = 0;

              goto LAB_007795c3;

            }

          }

        }

      }

    }

  }

  iVar2 = 0;

  do {

    if (iVar1 == (&DAT_00a240d0)[iVar2 * 2]) {

      uVar4 = *(uint32_t /* width from decompiler */ *)(&UNK_00a240d4 + iVar2 * 8);

      goto LAB_007795c3;

    }

    iVar2 = iVar2 + 1;

  } while (iVar2 < 3);

  uVar4 = 1;

LAB_007795c3:

  FUN_00772250(local_20,local_10,0);

  return uVar4;

}
