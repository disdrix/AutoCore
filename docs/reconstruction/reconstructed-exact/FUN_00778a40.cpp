// =============================================================================
// FUN_00778a40
// -----------------------------------------------------------------------------
// Stable ID: aa_00778a40
// Address:   0x00778a40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00778a40 @ 0x00778a40
// Stable ID: aa_00778a40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~116 non-empty decompiler lines.
//  - Control keywords: if×10, return×3, do×2, while×2, goto×2.
//  - Notable callees: FUN_00775f50×16, FUN_00774e60×12, FUN_007716f0×10, FUN_00772390×9, FUN_00770770×8, FUN_00770650×6, FUN_007707a0×4, FUN_00774b50×4.
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

uint32_t /* width from decompiler */ FUN_00778a40(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int in_EAX;

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint64_t uVar4;

  uint8_t local_50 [16];

  uint8_t local_40 [16];

  uint8_t local_30 [16];

  int local_20 [3];

  byte *local_14;

  uint8_t local_10 [16];

  

  iVar1 = FUN_00771cb0(local_50,local_40,local_30,local_20,local_10,0);

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

  if (((iVar1 == 0) && (iVar1 = FUN_00770650(), iVar1 == 0)) && (iVar1 = FUN_00770650(), iVar1 == 0)

     ) {

    iVar1 = FUN_00770770();

    if (((iVar1 == 0) ||

        ((((iVar1 = FUN_00774b50(in_EAX + 0x20,local_50), iVar1 == 0 &&

           (iVar1 = FUN_00775f50(local_50,param_2,param_3), iVar1 == 0)) &&

          ((iVar1 = FUN_00774e60(local_50,local_30,local_30), iVar1 == 0 &&

           ((iVar1 = FUN_00775f50(local_30,param_2,param_3), iVar1 == 0 &&

            (iVar1 = FUN_00774e60(in_EAX + 0x20,local_50,local_50), iVar1 == 0)))))) &&

         ((iVar1 = FUN_00775f50(local_50,param_2,param_3), iVar1 == 0 &&

          ((iVar1 = FUN_00774e60(local_50,local_20,local_20), iVar1 == 0 &&

           (iVar1 = FUN_00775f50(local_20,param_2,param_3), iVar1 == 0)))))))) &&

       ((((iVar1 = FUN_00774b50(local_10,local_50), iVar1 == 0 &&

          (((iVar1 = FUN_00775f50(local_50,param_2,param_3), iVar1 == 0 &&

            (iVar1 = FUN_00774e60(), iVar1 == 0)) &&

           (iVar1 = FUN_00775f50(local_40,param_2,param_3), iVar1 == 0)))) &&

         ((((iVar1 = FUN_00774e60(local_10,local_50,local_50), iVar1 == 0 &&

            (iVar1 = FUN_00775f50(local_50,param_2,param_3), iVar1 == 0)) &&

           (iVar1 = FUN_00774e60(in_EAX + 0x10,local_50,local_50), iVar1 == 0)) &&

          (((iVar1 = FUN_00775f50(local_50,param_2,param_3), iVar1 == 0 &&

            (iVar1 = FUN_007716f0(local_20), iVar1 == 0)) &&

           ((iVar1 = FUN_00770770(), iVar1 != -1 || (iVar1 = FUN_00772390(), iVar1 == 0)))))))) &&

        (iVar1 = FUN_00771a00(local_50,local_50), iVar1 == 0)))) {

      iVar1 = FUN_007707a0();

      if ((iVar1 == -1) || (iVar1 = FUN_007716f0(local_50), iVar1 == 0)) {

        iVar1 = FUN_00772390();

        if (((iVar1 == 0) &&

            ((((iVar1 = FUN_007707a0(), iVar1 == -1 || (iVar1 = FUN_007716f0(local_50), iVar1 == 0))

              && (iVar1 = FUN_007716f0(local_30), iVar1 == 0)) &&

             ((iVar1 = FUN_00770770(), iVar1 != -1 || (iVar1 = FUN_00772390(), iVar1 == 0)))))) &&

           (iVar1 = FUN_00771a00(local_40,local_40), iVar1 == 0)) {

          iVar1 = FUN_007707a0();

          if ((iVar1 == -1) || (iVar1 = FUN_007716f0(local_40), iVar1 == 0)) {

            iVar1 = FUN_00772390();

            if ((iVar1 == 0) &&

               ((iVar1 = FUN_007707a0(), iVar1 == -1 || (iVar1 = FUN_007716f0(local_40), iVar1 == 0)

                ))) {

              uVar4 = FUN_00770770();

              if ((((((int)uVar4 == 0) ||

                    ((iVar1 = FUN_00774e60(local_10,(int)((ulonglong)uVar4 >> 0x20),local_10),

                     iVar1 == 0 && (iVar1 = FUN_00775f50(local_10,param_2,param_3), iVar1 == 0))))

                   && (((iVar1 = FUN_00774e60(local_10,local_30,local_10), iVar1 == 0 &&

                        (((iVar1 = FUN_00775f50(local_10,param_2,param_3), iVar1 == 0 &&

                          (iVar1 = FUN_00774e60(local_50,local_30,local_50), iVar1 == 0)) &&

                         (iVar1 = FUN_00775f50(local_50,param_2,param_3), iVar1 == 0)))) &&

                       ((((iVar1 = FUN_00774b50(local_30,local_30), iVar1 == 0 &&

                          (iVar1 = FUN_00775f50(local_30,param_2,param_3), iVar1 == 0)) &&

                         (iVar1 = FUN_00774e60(local_40,local_30,local_40), iVar1 == 0)) &&

                        ((iVar1 = FUN_00775f50(local_40,param_2,param_3), iVar1 == 0 &&

                         (iVar1 = FUN_00774e60(local_50,local_30,local_50), iVar1 == 0)))))))) &&

                  (((((iVar1 = FUN_00775f50(local_50,param_2,param_3), iVar1 == 0 &&

                      (((iVar1 = FUN_00774b50(local_20,local_30), iVar1 == 0 &&

                        (iVar1 = FUN_00775f50(local_30,param_2,param_3), iVar1 == 0)) &&

                       (iVar1 = FUN_007716f0(local_30), iVar1 == 0)))) &&

                     ((iVar1 = FUN_00770770(), iVar1 != -1 || (iVar1 = FUN_00772390(), iVar1 == 0)))

                     ) && (iVar1 = FUN_007716f0(local_40), iVar1 == 0)) &&

                   (((iVar1 = FUN_00770770(), iVar1 != -1 || (iVar1 = FUN_00772390(), iVar1 == 0))

                    && ((iVar1 = FUN_007716f0(local_40), iVar1 == 0 &&

                        ((((iVar1 = FUN_00770770(), iVar1 != -1 ||

                           (iVar1 = FUN_00772390(), iVar1 == 0)) &&

                          (iVar1 = FUN_00774e60(local_40,local_20,local_40), iVar1 == 0)) &&

                         ((iVar1 = FUN_00775f50(local_40,param_2,param_3), iVar1 == 0 &&

                          (iVar1 = FUN_007716f0(local_40), iVar1 == 0)))))))))))) &&

                 (((iVar1 = FUN_00770770(), iVar1 != -1 || (iVar1 = FUN_00772390(), iVar1 == 0)) &&

                  ((((local_20[0] < 1 || ((*local_14 & 1) == 0)) ||

                    (iVar1 = FUN_00772390(), iVar1 == 0)) &&

                   ((((iVar1 = FUN_00772190(local_20), iVar1 == 0 &&

                      (iVar1 = FUN_00770650(), iVar1 == 0)) && (iVar1 = FUN_00770650(), iVar1 == 0))

                    && (iVar1 = FUN_00770650(), iVar1 == 0)))))))) {

                uVar3 = 0;

                goto LAB_00779123;

              }

            }

          }

        }

      }

    }

  }

  iVar2 = 0;

  do {

    if (iVar1 == (&DAT_00a240d0)[iVar2 * 2]) {

      uVar3 = *(uint32_t /* width from decompiler */ *)(&UNK_00a240d4 + iVar2 * 8);

      goto LAB_00779123;

    }

    iVar2 = iVar2 + 1;

  } while (iVar2 < 3);

  uVar3 = 1;

LAB_00779123:

  FUN_00772250(local_50,local_40,local_30,local_20,local_10,0);

  return uVar3;

}
