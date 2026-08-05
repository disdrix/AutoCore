// =============================================================================
// FUN_00735630
// -----------------------------------------------------------------------------
// Stable ID: aa_00735630
// Address:   0x00735630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00735630 @ 0x00735630
// Stable ID: aa_00735630
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~105 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, while×2, goto×1, return×1.
//  - Notable callees: CONCAT11, CONCAT31, FUN_00440030, FUN_0046d5b0, FUN_00735630.
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

uint32_t /* width from decompiler */ FUN_00735630(int param_1,byte param_2)



{

  int iVar1;

  uint uVar2;

  char cVar3;

  int iVar4;

  int iVar5;

  int unaff_ESI;

  int iStack_48;

  uint uStack_44;

  uint uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  int iStack_38;

  int iStack_34;

  int iStack_30;

  int iStack_2c;

  uint uStack_28;

  

  iStack_38 = *(int *)(unaff_ESI + 0x4c);

  uStack_3c = *(int **)(unaff_ESI + 0x48);

  iVar1 = *(int *)(param_1 + 0xc);

  iStack_34 = 1;

  uStack_40 = 0x735654;

  iStack_30 = iVar1;

  iStack_2c = iVar1;

  uStack_28 = (uint)param_2;

  iVar4 = (**(code **)(*uStack_3c + 0x24))();

  *(bool *)(param_1 + 0x10) = -1 < iVar4;

  iStack_48 = iVar1;

  uStack_44 = iVar1;

  uStack_40 = (uint)param_2;

  iVar4 = (**(code **)(**(int **)(unaff_ESI + 0x48) + 0x24))

                    (*(int **)(unaff_ESI + 0x48),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x4c),2);

  *(bool *)(param_1 + 0x11) = -1 < iVar4;

  uStack_44 = 0;

  do {

    uVar2 = *(uint *)(&DAT_00a24430 + uStack_44);

    if ((*(char *)(param_1 + 0x10) == '\0') ||

       (iVar4 = (**(code **)(**(int **)(unaff_ESI + 0x48) + 0x28))

                          (*(int **)(unaff_ESI + 0x48),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x4c),1,iVar1,2,1

                           ,uVar2), iVar4 < 0)) {

LAB_007356c4:

      uStack_3c = (int *)((uint)uStack_3c & 0xffffff00);

    }

    else {

      iVar4 = (**(code **)(**(int **)(unaff_ESI + 0x48) + 0x30))

                        (*(int **)(unaff_ESI + 0x48),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x4c),1,iVar1,iVar1

                         ,uVar2);

      uStack_3c = (int *)CONCAT31(uStack_3c._1_3_,1);

      if (iVar4 < 0) goto LAB_007356c4;

    }

    if (((*(char *)(param_1 + 0x11) == '\0') ||

        (iVar4 = (**(code **)(**(int **)(unaff_ESI + 0x48) + 0x28))

                           (*(int **)(unaff_ESI + 0x48),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x4c),2,iVar1,2,

                            1,uVar2), iVar4 < 0)) &&

       (iVar4 = (**(code **)(**(int **)(unaff_ESI + 0x48) + 0x30))

                          (*(int **)(unaff_ESI + 0x48),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x4c),2,iVar1,

                           iVar1,uVar2), iVar4 < 0)) {

      cVar3 = '\0';

    }

    else {

      cVar3 = '\x01';

    }

    uStack_3c._0_2_ = CONCAT11(cVar3,(char)uStack_3c);

    if (((char)uStack_3c != '\0') || (cVar3 != '\0')) {

      iStack_38 = 0;

      iStack_34 = 0;

      iVar4 = 4;

      do {

        iStack_48 = 0;

        iVar5 = (**(code **)(**(int **)(unaff_ESI + 0x48) + 0x2c))

                          (*(int **)(unaff_ESI + 0x48),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x4c),1,iVar1,

                           uStack_28 & 0xff,iVar4,&iStack_48);

        if (((-1 < iVar5) &&

            (iVar5 = (**(code **)(**(int **)(unaff_ESI + 0x48) + 0x2c))

                               (*(int **)(unaff_ESI + 0x48),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x4c),1,

                                uVar2,uStack_28 & 0xff,iVar4,&iStack_48), -1 < iVar5)) &&

           (0 < iStack_48)) {

          iStack_34 = iStack_48;

          iStack_38 = iVar4;

          break;

        }

        iVar4 = iVar4 + -1;

      } while (0 < iVar4);

      iVar5 = iStack_2c;

      iVar4 = *(int *)(iStack_2c + 0x18);

      uStack_40 = uVar2;

      if ((iVar4 == 0) ||

         ((uint)(*(int *)(iStack_2c + 0x20) - iVar4 >> 4) <=

          (uint)(*(int *)(iStack_2c + 0x1c) - iVar4 >> 4))) {

        FUN_0046d5b0(*(uint32_t /* width from decompiler */ *)(iStack_2c + 0x1c),&uStack_40);

        param_1 = iStack_2c;

      }

      else {

        iVar4 = *(int *)(iStack_2c + 0x1c);

        FUN_00440030(uStack_28);

        *(int *)(iVar5 + 0x1c) = iVar4 + 0x10;

        param_1 = iStack_2c;

      }

    }

    uStack_44 = uStack_44 + 4;

    if (0x17 < uStack_44) {

      return 0;

    }

  } while( true );

}
