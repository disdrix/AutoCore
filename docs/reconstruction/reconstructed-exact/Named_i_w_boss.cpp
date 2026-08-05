// =============================================================================
// Named_i_w_boss
// -----------------------------------------------------------------------------
// Stable ID: aa_0091f870
// Address:   0x0091f870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_i_w_boss @ 0x0091f870
// Stable ID: aa_0091f870
// Embedded strings (evidence for future rename):
//   - "i_w_boss.xml"
//   - "Warning!  Powerful Enemy Detected!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~177 non-empty decompiler lines.
//  - Control keywords: if×23, return×15, do×1, while×1.
//  - Notable callees: FUN_005134e0, FUN_007fde80, FUN_00861be0, FUN_00861c10, FUN_008694b0, Named_i_w_boss.
//  - Strings: "i_w_boss.xml"; "Warning!  Powerful Enemy Detected!".
//  - Return sites: 15.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_w_boss.xml"
 * Domain alias of FUN_0091f870 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_i_w_boss(float param_1)



{

  int *piVar1;

  float fVar2;

  char cVar3;

  float *pfVar4;

  float *pfVar5;

  int iVar6;

  int iVar7;

  void *pvVar8;

  int *piVar9;

  uint32_t /* width from decompiler */ unaff_EBX;

  int *unaff_EDI;

  float fVar10;

  int *piStack_34;

  float fStack_30;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009b7dda;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  if ((((int *)unaff_EDI[0x330] != (int *)0x0) &&

      (ExceptionList = &pvStack_1c, cVar3 = (**(code **)(*(int *)unaff_EDI[0x330] + 0x3d8))(),

      cVar3 != '\0')) && (cVar3 = (**(code **)(*(int *)unaff_EDI[0x330] + 0xd0))(), cVar3 == '\0'))

  {

    (**(code **)(*(int *)unaff_EDI[0x330] + 0x440))();

    (**(code **)(*unaff_EDI + 0xb0))(unaff_EDI[0x330]);

    if ((uint32_t /* width from decompiler */ *)unaff_EDI[0x330] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)unaff_EDI[0x330])(1);

    }

    unaff_EDI[0x330] = 0;

  }

  if ((((DAT_00d1a8dd == '\0') && (DAT_00d1b6d8 != 0)) &&

      ((*(char *)(DAT_00d1b6d8 + 0x4f1) == '\0' &&

       ((*(int *)(DAT_00d1b6d8 + 0x250) != 0 && (*(char *)(DAT_00d1b644 + 0xf5) == '\0')))))) &&

     (*(char *)(DAT_00d1b644 + 0xf6) == '\0')) {

    if ((((DAT_00d1b968 != 0) && (cVar3 = FUN_00861c10(), cVar3 != '\0')) &&

        (cVar3 = FUN_00861be0(), cVar3 == '\0')) &&

       ((*(int *)(DAT_00d1b968 + 0x518) == -3 && (*(int *)(DAT_00d1b968 + 0x51c) == -1)))) {

      ExceptionList = pvStack_1c;

      return;

    }

    fVar2 = g_flOne;

    fVar10 = (float)unaff_EDI[0x32f];

    unaff_EDI[0x32f] = (int)(param_1 + fVar10);

    if (param_1 + fVar10 < fVar2) {

      ExceptionList = pvStack_1c;

      return;

    }

    unaff_EDI[0x32f] = 0;

    pfVar4 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +

                                           DAT_00d1b6d8) + 0x1a0))();

    if ((((int *)unaff_EDI[0x330] != (int *)0x0) &&

        (cVar3 = (**(code **)(*(int *)unaff_EDI[0x330] + 0x3d8))(), cVar3 != '\0')) &&

       ((cVar3 = (**(code **)(*(int *)unaff_EDI[0x330] + 0xd0))(), cVar3 != '\0' &&

        ((*(int *)(unaff_EDI[0x330] + 0x560) != 0 &&

         (pfVar5 = (float *)(**(code **)(**(int **)(unaff_EDI[0x330] + 0x560) + 0x1a0))(),

         (pfVar5[2] - pfVar4[2]) * (pfVar5[2] - pfVar4[2]) +

         (pfVar5[1] - pfVar4[1]) * (pfVar5[1] - pfVar4[1]) +

         (*pfVar5 - *pfVar4) * (*pfVar5 - *pfVar4) <= DAT_00aaabfc)))))) {

      ExceptionList = pvStack_1c;

      return;

    }

    iVar7 = *(int *)(DAT_00d1b644 + 0xe4e8);

    piStack_34 = (int *)0x0;

    fStack_30 = DAT_00aaabfc;

    if (iVar7 == -0x28) {

      ExceptionList = pvStack_1c;

      return;

    }

    piVar9 = *(int **)(iVar7 + 0x2c);

    if (piVar9 != *(int **)(iVar7 + 0x30)) {

      do {

        piVar1 = (int *)*piVar9;

        if ((((piVar1 != (int *)0x0) && (cVar3 = (**(code **)(*piVar1 + 0x198))(), cVar3 == '\0'))

            && (((uint)piVar1[0x5f] >> 3 & 1) == 0)) &&

           (((cVar3 = FUN_005134e0(), cVar3 == '\0' &&

             (iVar6 = (**(code **)(*piVar1 + 0x210))(0), iVar6 == 0)) &&

            ((iVar6 = (**(code **)(*piVar1 + 0x214))(), iVar6 != 0 &&

             (iVar6 = (**(code **)(*piVar1 + 0x214))(),

             *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0xac + iVar6) + 0x3c) +

                      0x4f9) != '\0')))))) {

          pfVar5 = (float *)(**(code **)(*piVar1 + 0x1a0))();

          fVar10 = (pfVar5[2] - pfVar4[2]) * (pfVar5[2] - pfVar4[2]) +

                   (pfVar5[1] - pfVar4[1]) * (pfVar5[1] - pfVar4[1]) +

                   (*pfVar5 - *pfVar4) * (*pfVar5 - *pfVar4);

          if ((fVar10 <= DAT_00aaabfc) && (fVar10 <= fStack_30)) {

            iVar6 = (**(code **)(*piVar1 + 0x19c))();

            fStack_30 = fVar10;

            if (iVar6 == 0) {

              piStack_34 = (int *)0x0;

            }

            else {

              piStack_34 = (int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6);

            }

          }

        }

        piVar9 = piVar9 + 1;

      } while (piVar9 != *(int **)(iVar7 + 0x30));

      if (piStack_34 != (int *)0x0) {

        if (_DAT_00aaabf8 < fStack_30) {

          ExceptionList = pvStack_1c;

          return;

        }

        iVar7 = (**(code **)(*piStack_34 + 0x214))();

        if (*(char *)(iVar7 + 0x2f0) != '\0') {

          if (unaff_EDI[0x330] != 0) {

            ExceptionList = pvStack_1c;

            return;

          }

          pvVar8 = operator_new(0x564);

          uStack_14 = 0;

          if (pvVar8 == (void *)0x0) {

            iVar7 = 0;

          }

          else {

            iVar7 = FUN_008694b0(pvVar8);

          }

          uStack_14 = 0xffffffff;

          unaff_EDI[0x330] = iVar7;

          (**(code **)(*unaff_EDI + 0xa8))(iVar7);

          (**(code **)(*(int *)unaff_EDI[0x330] + 0x28))("i_w_boss.xml");

          (**(code **)(*(int *)unaff_EDI[0x330] + 0x43c))();

          (**(code **)(*(int *)unaff_EDI[0x330] + 0x444))(unaff_EBX);

          ExceptionList = pfVar4;

          return;

        }

        FUN_007fde80("Warning!  Powerful Enemy Detected!",0,0x40666666,0x3f000000,2);

        if (DAT_00d1b968 != 0) {

          *(uint32_t /* width from decompiler */ *)(DAT_00d1b968 + 0x518) = 0xfffffffd;

          *(uint32_t /* width from decompiler */ *)(DAT_00d1b968 + 0x51c) = 0xffffffff;

        }

        iVar7 = (**(code **)(*piStack_34 + 0x214))();

        *(uint8_t *)(iVar7 + 0x2f0) = 1;

        ExceptionList = pvStack_1c;

        return;

      }

    }

    if ((int *)unaff_EDI[0x330] == (int *)0x0) {

      ExceptionList = pvStack_1c;

      return;

    }

    cVar3 = (**(code **)(*(int *)unaff_EDI[0x330] + 0x3d8))();

    if (cVar3 == '\0') {

      ExceptionList = pvStack_1c;

      return;

    }

    iVar7 = (**(code **)(*(int *)unaff_EDI[0x330] + 0xe8))();

    if (iVar7 == -1) {

      ExceptionList = pvStack_1c;

      return;

    }

    piVar9 = (int *)unaff_EDI[0x330];

  }

  else {

    if ((int *)unaff_EDI[0x330] == (int *)0x0) {

      ExceptionList = pvStack_1c;

      return;

    }

    cVar3 = (**(code **)(*(int *)unaff_EDI[0x330] + 0x3d8))();

    if (cVar3 == '\0') {

      ExceptionList = pvStack_1c;

      return;

    }

    piVar9 = (int *)unaff_EDI[0x330];

    if (piVar9[0x158] == 0) {

      ExceptionList = pvStack_1c;

      return;

    }

  }

  (**(code **)(*piVar9 + 0x444))(0);

  ExceptionList = pvStack_1c;

  return;

}
