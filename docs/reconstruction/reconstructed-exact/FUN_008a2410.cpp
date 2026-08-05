// =============================================================================
// FUN_008a2410
// -----------------------------------------------------------------------------
// Stable ID: aa_008a2410
// Address:   0x008a2410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a2410 @ 0x008a2410
// Stable ID: aa_008a2410
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~105 non-empty decompiler lines.
//  - Control keywords: if×14, goto×5, do×3, while×3, return×1, for×1.
//  - Notable callees: FUN_007a6de0×2, FUN_007a69d0, FUN_008a2410.
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

void FUN_008a2410(int param_1,int param_2)



{

  int iVar1;

  byte bVar2;

  short sVar3;

  short sVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  byte *pbVar8;

  byte *pbVar9;

  uint uVar10;

  int iVar11;

  uint uVar12;

  bool bVar13;

  byte *local_8;

  byte *pbStack_4;

  

  FUN_007a69d0();

  uVar10 = 0;

  do {

    if ((*(int *)(param_2 + 4) == 0) ||

       ((uint)(*(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 2) <= uVar10)) {

      return;

    }

    for (uVar12 = 0;

        (iVar11 = *(int *)(param_2 + 4), iVar11 != 0 &&

        (uVar12 < (uint)(*(int *)(param_2 + 8) - iVar11 >> 2))); uVar12 = uVar12 + 1) {

      if ((((uVar10 != uVar12) && (*(int *)(iVar11 + uVar10 * 4) != 0)) &&

          (iVar1 = uVar12 * 4, *(int *)(iVar1 + iVar11) != 0)) &&

         ((*(int *)(*(int *)(iVar11 + uVar10 * 4) + 0x504) != 0 &&

          (*(int *)(*(int *)(iVar1 + iVar11) + 0x504) != 0)))) {

        iVar5 = *(int *)(*(int *)(*(int *)(iVar11 + uVar10 * 4) + 0x504) + 0x14c);

        iVar6 = *(int *)(*(int *)(*(int *)(iVar1 + iVar11) + 0x504) + 0x14c);

        if (((iVar5 != 0) && ((iVar6 != 0 && (*(int *)(iVar5 + 0x14c) != 0)))) &&

           (*(int *)(iVar6 + 0x14c) != 0)) {

          if ((*(int *)(param_1 + 0x50c) == 0) ||

             (iVar11 = *(int *)(iVar11 + uVar10 * 4), *(int *)(iVar11 + 0x530) == 0)) {

            local_8 = (byte *)0x0;

          }

          else {

            local_8 = (byte *)(**(code **)(**(int **)(iVar11 + 0x530) + 0x1dc))();

          }

          if ((*(int *)(param_1 + 0x50c) == 0) ||

             (iVar11 = *(int *)(iVar1 + *(int *)(param_2 + 4)), *(int *)(iVar11 + 0x530) == 0)) {

            pbStack_4 = (byte *)0x0;

          }

          else {

            pbStack_4 = (byte *)(**(code **)(**(int **)(iVar11 + 0x530) + 0x1dc))();

          }

          uVar7 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x14c);

          pbVar8 = (byte *)FUN_007a6de0(*(uint32_t /* width from decompiler */ *)(iVar6 + 0x14c),0xffffffff);

          pbVar9 = (byte *)FUN_007a6de0(uVar7,0xffffffff);

          do {

            bVar2 = *pbVar9;

            bVar13 = bVar2 < *pbVar8;

            if (bVar2 != *pbVar8) {

LAB_008a25b4:

              iVar11 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);

              goto LAB_008a25b9;

            }

            if (bVar2 == 0) break;

            bVar2 = pbVar9[1];

            bVar13 = bVar2 < pbVar8[1];

            if (bVar2 != pbVar8[1]) goto LAB_008a25b4;

            pbVar9 = pbVar9 + 2;

            pbVar8 = pbVar8 + 2;

          } while (bVar2 != 0);

          iVar11 = 0;

LAB_008a25b9:

          sVar3 = *(short *)(iVar5 + 0x11c);

          sVar4 = *(short *)(iVar6 + 0x11c);

          if ((sVar3 < sVar4) || ((sVar3 == sVar4 && (iVar11 < 0)))) {

LAB_008a261d:

            iVar11 = *(int *)(param_2 + 4);

            uVar7 = *(uint32_t /* width from decompiler */ *)(iVar11 + uVar10 * 4);

            *(uint32_t /* width from decompiler */ *)(iVar11 + uVar10 * 4) = *(uint32_t /* width from decompiler */ *)(uVar12 * 4 + iVar11);

            *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 4) + uVar12 * 4) = uVar7;

          }

          else if ((sVar3 == sVar4) &&

                  (((iVar11 == 0 && (local_8 != (byte *)0x0)) && (pbStack_4 != (byte *)0x0)))) {

            do {

              bVar2 = *local_8;

              bVar13 = bVar2 < *pbStack_4;

              if (bVar2 != *pbStack_4) {

LAB_008a2614:

                iVar11 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);

                goto LAB_008a2619;

              }

              if (bVar2 == 0) break;

              bVar2 = local_8[1];

              bVar13 = bVar2 < pbStack_4[1];

              if (bVar2 != pbStack_4[1]) goto LAB_008a2614;

              local_8 = local_8 + 2;

              pbStack_4 = pbStack_4 + 2;

            } while (bVar2 != 0);

            iVar11 = 0;

LAB_008a2619:

            if (iVar11 < 0) goto LAB_008a261d;

          }

        }

      }

    }

    uVar10 = uVar10 + 1;

  } while( true );

}
