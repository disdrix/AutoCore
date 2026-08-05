// =============================================================================
// FUN_008d80c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008d80c0
// Address:   0x008d80c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d80c0 @ 0x008d80c0
// Stable ID: aa_008d80c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~193 non-empty decompiler lines.
//  - Control keywords: if×26, do×7, while×7, return×2.
//  - Notable callees: FUN_00755db0×7, FUN_00755e80×7, FUN_0076c4d0×7, FUN_004bfd10×4, CONCAT31×2, FUN_005a6e00×2, FUN_005a6e40×2, FUN_00756060.
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

void FUN_008d80c0(uint param_1)



{

  uint uVar1;

  char cVar2;

  char cVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  

  uVar1 = param_1;

  if (DAT_00d1b77c == (int *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x544) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x548) = 0;

    return;

  }

  iVar7 = *(int *)(param_1 + 0x544);

  if (iVar7 != 0) {

    uVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7) + 0x1cc))();

    FUN_004bfd10(uVar4);

    if (*(int *)(*(int *)(param_1 + 0x544) + 0x48) != 0) {

      (**(code **)(*DAT_00d1b77c + 0x1a8))();

      FUN_00756060();

    }

    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x544) + 4) + 4) + 4 +

                         *(int *)(param_1 + 0x544)) + 0xfc))();

  }

  if (*(int *)(param_1 + 0x548) != 0) {

    iVar7 = *(int *)(*(int *)(param_1 + 0x548) + 600);

    if (iVar7 != 0) {

      uVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7) + 0x1cc))();

      FUN_004bfd10(uVar4);

    }

    iVar7 = 0;

    do {

      iVar5 = *(int *)(iVar7 + *(int *)(*(int *)(param_1 + 0x548) + 0x260));

      if (iVar5 != 0) {

        uVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x1cc))();

        FUN_004bfd10(uVar4);

      }

      iVar7 = iVar7 + 4;

    } while (iVar7 < 0xc);

    uVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x548) + 4) + 4) + 4 +

                                 *(int *)(param_1 + 0x548)) + 0x1cc))();

    FUN_004bfd10(uVar4);

    iVar7 = *(int *)(*(int *)(param_1 + 0x548) + 0x48);

    if (iVar7 != 0) {

      iVar5 = (**(code **)(*DAT_00d1b77c + 0x1a8))();

      *(uint8_t *)(iVar5 + 0x48) = 1;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x40);

      FUN_0076c4d0();

      cVar2 = (**(code **)(**(int **)(iVar5 + 8) + 8))(iVar7);

      if (cVar2 != '\0') {

        FUN_00755db0(iVar7);

        FUN_00755e80(iVar7);

      }

    }

    iVar7 = *(int *)(*(int *)(param_1 + 0x548) + 600);

    if (((iVar7 != 0) && (*(char *)(iVar7 + 0x11c) != '\0')) &&

       (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 0xac + iVar7) + 0x3c) +

                 0x4ce) != '\x04')) {

      cVar2 = '\0';

      param_1 = param_1 & 0xffffff00;

      if ('\0' < *(char *)(iVar7 + 0xb0)) {

        do {

          iVar7 = FUN_005a6e00(param_1);

          if (iVar7 != 0) {

            uVar4 = FUN_005a6e00(param_1);

            iVar7 = (**(code **)(*DAT_00d1b77c + 0x1a8))();

            *(uint8_t *)(iVar7 + 0x48) = 1;

            *(uint32_t /* width from decompiler */ *)(iVar7 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x40);

            FUN_0076c4d0();

            cVar3 = (**(code **)(**(int **)(iVar7 + 8) + 8))(uVar4);

            if (cVar3 != '\0') {

              FUN_00755db0(uVar4);

              FUN_00755e80(uVar4);

            }

          }

          cVar2 = cVar2 + '\x01';

          param_1 = CONCAT31(param_1._1_3_,cVar2);

        } while (cVar2 < *(char *)(*(int *)(*(int *)(uVar1 + 0x548) + 600) + 0xb0));

      }

      cVar2 = '\0';

      if ('\0' < *(char *)(*(int *)(*(int *)(uVar1 + 0x548) + 600) + 0xf0)) {

        do {

          param_1 = param_1 & 0xffffff00;

          do {

            iVar7 = FUN_005a6e40(cVar2,param_1);

            if (iVar7 != 0) {

              uVar4 = FUN_005a6e40(cVar2,param_1);

              iVar7 = (**(code **)(*DAT_00d1b77c + 0x1a8))();

              *(uint8_t *)(iVar7 + 0x48) = 1;

              *(uint32_t /* width from decompiler */ *)(iVar7 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x40);

              FUN_0076c4d0();

              cVar3 = (**(code **)(**(int **)(iVar7 + 8) + 8))(uVar4);

              if (cVar3 != '\0') {

                FUN_00755db0(uVar4);

                FUN_00755e80(uVar4);

              }

            }

            cVar3 = (char)param_1 + '\x01';

            param_1 = CONCAT31(param_1._1_3_,cVar3);

          } while (cVar3 < '\x03');

          cVar2 = cVar2 + '\x01';

        } while (cVar2 < *(char *)(*(int *)(*(int *)(uVar1 + 0x548) + 600) + 0xf0));

      }

    }

    iVar7 = *(int *)(*(int *)(uVar1 + 0x548) + 0x3a0);

    if (iVar7 != 0) {

      iVar5 = (**(code **)(*DAT_00d1b77c + 0x1a8))();

      *(uint8_t *)(iVar5 + 0x48) = 1;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x40);

      FUN_0076c4d0();

      cVar2 = (**(code **)(**(int **)(iVar5 + 8) + 8))(iVar7);

      if (cVar2 != '\0') {

        FUN_00755db0(iVar7);

        FUN_00755e80(iVar7);

      }

    }

    iVar7 = 0;

    do {

      iVar5 = *(int *)(iVar7 + *(int *)(*(int *)(uVar1 + 0x548) + 0x260));

      if ((iVar5 != 0) &&

         (iVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x1cc))(),

         iVar5 != 0)) {

        iVar5 = *(int *)(iVar7 + *(int *)(*(int *)(uVar1 + 0x548) + 0x260));

        iVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x1cc))();

        (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0xfc))();

        iVar5 = *(int *)(iVar7 + *(int *)(*(int *)(uVar1 + 0x548) + 0x260));

        iVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x1cc))();

        uVar4 = *(uint32_t /* width from decompiler */ *)(iVar5 + 8);

        iVar5 = (**(code **)(*DAT_00d1b77c + 0x1a8))();

        *(uint8_t *)(iVar5 + 0x48) = 1;

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x40);

        FUN_0076c4d0();

        cVar2 = (**(code **)(**(int **)(iVar5 + 8) + 8))(uVar4);

        if (cVar2 != '\0') {

          FUN_00755db0(uVar4);

          FUN_00755e80(uVar4);

        }

        iVar5 = *(int *)(iVar7 + *(int *)(*(int *)(uVar1 + 0x548) + 0x260));

        if (iVar5 != 0) {

          (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5))(1);

        }

      }

      iVar7 = iVar7 + 4;

    } while (iVar7 < 0xc);

    cVar2 = '\0';

    do {

      iVar7 = *(int *)(*(int *)(uVar1 + 0x548) + 0x340 + cVar2 * 4);

      if (iVar7 == 0) break;

      iVar5 = (**(code **)(*DAT_00d1b77c + 0x1a8))();

      *(uint8_t *)(iVar5 + 0x48) = 1;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x40);

      FUN_0076c4d0();

      cVar3 = (**(code **)(**(int **)(iVar5 + 8) + 8))(iVar7);

      if (cVar3 != '\0') {

        FUN_00755db0(iVar7);

        FUN_00755e80(iVar7);

      }

      cVar2 = cVar2 + '\x01';

    } while (cVar2 < '\x03');

    iVar7 = 0x34c;

    param_1 = 8;

    do {

      iVar5 = *(int *)(iVar7 + *(int *)(uVar1 + 0x548));

      if (iVar5 != 0) {

        iVar6 = (**(code **)(*DAT_00d1b77c + 0x1a8))();

        *(uint8_t *)(iVar6 + 0x48) = 1;

        *(uint32_t /* width from decompiler */ *)(iVar6 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x40);

        FUN_0076c4d0();

        cVar2 = (**(code **)(**(int **)(iVar6 + 8) + 8))(iVar5);

        if (cVar2 != '\0') {

          FUN_00755db0(iVar5);

          FUN_00755e80(iVar5);

        }

      }

      iVar7 = iVar7 + 4;

      param_1 = param_1 + -1;

    } while (param_1 != 0);

    iVar7 = *(int *)(uVar1 + 0x548);

    iVar5 = *(int *)(iVar7 + 600);

    if (iVar7 != 0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7))(1);

    }

    *(uint32_t /* width from decompiler */ *)(uVar1 + 0x548) = 0;

    if (iVar5 != 0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5))(1);

    }

  }

  *(uint32_t /* width from decompiler */ *)(uVar1 + 0x544) = 0;

  *(uint32_t /* width from decompiler */ *)(uVar1 + 0x548) = 0;

  return;

}
