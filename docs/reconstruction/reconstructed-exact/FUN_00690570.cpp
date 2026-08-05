// =============================================================================
// FUN_00690570
// -----------------------------------------------------------------------------
// Stable ID: aa_00690570
// Address:   0x00690570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00690570 @ 0x00690570
// Stable ID: aa_00690570
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~106 non-empty decompiler lines.
//  - Control keywords: if×14, do×2, while×2, goto×1, for×1, return×1.
//  - Notable callees: FUN_006a3db0×6, FUN_0068c5d0, FUN_00690570.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_00690570(int *param_1,uint32_t /* width from decompiler */ param_2,short param_3,uint param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  short sVar4;

  int iVar5;

  int iVar6;

  void *pvVar7;

  int iVar8;

  int iVar9;

  uint uVar10;

  uint uVar11;

  uint uVar12;

  int iVar13;

  int iVar14;

  bool bVar15;

  short local_18;

  

  iVar3 = param_4;

  if (*param_1 != 0) {

    iVar5 = FUN_006a3db0();

    iVar1 = iVar5 + -1;

    iVar6 = FUN_006a3db0();

    iVar2 = iVar6 + -1;

    iVar13 = (iVar6 * 2 + 1) * iVar1 + -1;

    pvVar7 = operator_new__(iVar13 * 2);

    iVar14 = 0;

    param_4 = 0;

    if (0 < iVar1) {

      do {

        sVar4 = FUN_006a3db0();

        uVar11 = param_4 + 1;

        iVar8 = FUN_006a3db0();

        if (param_4 == iVar5 - 2U) {

LAB_00690757:

          iVar8 = 0;

          if (*(int *)(iVar3 + 4) != 0) {

            iVar8 = (*(int *)(iVar3 + 8) - *(int *)(iVar3 + 4)) / 0x38;

          }

          iVar8 = iVar8 + -1;

        }

        else {

          iVar9 = 0;

          if (*(int *)(iVar3 + 4) != 0) {

            iVar9 = (*(int *)(iVar3 + 8) - *(int *)(iVar3 + 4)) / 0x38;

          }

          if (iVar9 + -1 < iVar8) goto LAB_00690757;

        }

        local_18 = (short)iVar8 - sVar4;

        uVar10 = param_4 & 0x80000001;

        bVar15 = uVar10 == 0;

        if ((int)uVar10 < 0) {

          bVar15 = (uVar10 - 1 | 0xfffffffe) == 0xffffffff;

        }

        if (bVar15) {

          sVar4 = (short)*(uint32_t /* width from decompiler */ *)(iVar3 + 0x2c) * sVar4;

          iVar8 = 0;

          if (0 < iVar6) {

            do {

              uVar10 = FUN_006a3db0();

              if (iVar8 == iVar2) {

                uVar10 = *(int *)(iVar3 + 0x2c) - 1;

              }

              uVar12 = *(int *)(iVar3 + 0x2c) - 1;

              if (uVar12 < uVar10) {

                uVar10 = uVar12;

              }

              *(short *)((int)pvVar7 + iVar14 * 2) = param_3 + sVar4 + (short)uVar10;

              *(short *)((int)pvVar7 + (iVar14 + 1) * 2) =

                   *(short *)(iVar3 + 0x2c) * local_18 + param_3 + sVar4 + (short)uVar10;

              iVar14 = iVar14 + 2;

              iVar8 = iVar8 + 1;

            } while (iVar8 < iVar6);

          }

        }

        else {

          sVar4 = (short)*(uint32_t /* width from decompiler */ *)(iVar3 + 0x2c) * sVar4;

          for (iVar8 = iVar2; -1 < iVar8; iVar8 = iVar8 + -1) {

            uVar10 = FUN_006a3db0();

            if (iVar8 == iVar2) {

              uVar10 = *(int *)(iVar3 + 0x2c) - 1;

            }

            uVar12 = *(int *)(iVar3 + 0x2c) - 1;

            if (uVar12 < uVar10) {

              uVar10 = uVar12;

            }

            *(short *)((int)pvVar7 + iVar14 * 2) = sVar4 + param_3 + (short)uVar10;

            *(short *)((int)pvVar7 + (iVar14 + 1) * 2) =

                 *(short *)(iVar3 + 0x2c) * local_18 + sVar4 + (short)uVar10 + param_3;

            iVar14 = iVar14 + 2;

          }

        }

        if ((int)param_4 < (int)(iVar5 - 2U)) {

          *(uint16_t *)((int)pvVar7 + iVar14 * 2) = *(uint16_t *)((int)pvVar7 + iVar14 * 2 + -2)

          ;

          iVar14 = iVar14 + 1;

        }

        param_4 = uVar11;

      } while ((int)uVar11 < iVar1);

    }

    FUN_0068c5d0(param_2,pvVar7,iVar13);

    *(short *)(*param_1 + 0x1e) = *(short *)(*param_1 + 0x1e) + 1;

  }

  return;

}
