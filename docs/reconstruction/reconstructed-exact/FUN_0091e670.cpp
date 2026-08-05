// =============================================================================
// FUN_0091e670
// -----------------------------------------------------------------------------
// Stable ID: aa_0091e670
// Address:   0x0091e670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0091e670 @ 0x0091e670
// Stable ID: aa_0091e670
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~112 non-empty decompiler lines.
//  - Control keywords: if×11, while×4, return×2, do×1, goto×1.
//  - Notable callees: FUN_0046f100×2, FUN_004e88e0, FUN_0091e670, FUN_00936210.
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

void FUN_0091e670(void)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int unaff_EDI;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  uint8_t auStack_c [12];

  

  iVar7 = DAT_00d1b938;

  if (DAT_00d1b938 != 0) {

    if ((((*(int *)(unaff_EDI + 0xca0) != 0) &&

         (*(int *)(unaff_EDI + 0xca4) - *(int *)(unaff_EDI + 0xca0) >> 2 != 0)) &&

        (*(int *)(DAT_00d1b938 + 0x528) != 0)) && (*(char *)(unaff_EDI + 0xce1) != '\0')) {

      iVar8 = **(int **)(DAT_00d1b938 + 0x524);

      iVar9 = 0;

      do {

        while( true ) {

          if (*(int *)(unaff_EDI + 0xca0) == 0) {

            iVar3 = 0;

          }

          else {

            iVar3 = *(int *)(unaff_EDI + 0xca4) - *(int *)(unaff_EDI + 0xca0) >> 2;

          }

          if ((iVar3 <= iVar9) || (iVar8 == *(int *)(iVar7 + 0x524))) {

            while( true ) {

              if (*(int *)(unaff_EDI + 0xca0) == 0) {

                iVar7 = 0;

              }

              else {

                iVar7 = *(int *)(unaff_EDI + 0xca4) - *(int *)(unaff_EDI + 0xca0) >> 2;

              }

              if (iVar7 <= iVar9) break;

              (**(code **)(**(int **)(*(int *)(unaff_EDI + 0xca0) + iVar9 * 4) + 4))(0);

              iVar9 = iVar9 + 1;

            }

            return;

          }

          piVar1 = *(int **)(iVar8 + 0x10);

          if (piVar1 != (int *)0x0) break;

LAB_0091e729:

          (**(code **)(**(int **)(*(int *)(unaff_EDI + 0xca0) + iVar9 * 4) + 4))(0);

          iVar9 = iVar9 + 1;

          FUN_0046f100();

        }

        iVar3 = (**(code **)(*piVar1 + 0x214))();

        iVar4 = (**(code **)(*piVar1 + 0x1d4))();

        if ((iVar3 == 0) && (iVar4 == 0)) goto LAB_0091e729;

        uVar5 = (**(code **)(*piVar1 + 0x1a0))();

        FUN_004e88e0(&uStack_30,uVar5);

        iVar4 = *(int *)(*(int *)(unaff_EDI + 0xca0) + iVar9 * 4);

        uStack_24 = uStack_30;

        iVar3 = iVar9 * 4;

        uStack_20 = uStack_2c;

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0x508) = uStack_30;

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0x50c) = uStack_2c;

        uStack_1c = uStack_28;

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0x510) = uStack_28;

        puVar6 = (uint32_t /* width from decompiler */ *)FUN_00936210(&DAT_00d1a840,auStack_c);

        uStack_30 = *puVar6;

        uStack_2c = puVar6[1];

        uStack_28 = puVar6[2];

        iVar4 = *(int *)(*(int *)(unaff_EDI + 0xca0) + iVar3);

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0x514) = uStack_30;

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0x518) = uStack_2c;

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0x51c) = uStack_28;

        if (((uint)piVar1[0x61] >> 1 & 1) == 0) {

          iVar4 = 0;

        }

        else {

          iVar4 = -(int)(float)piVar1[0x46];

        }

        iVar2 = *(int *)(*(int *)(unaff_EDI + 0xca0) + iVar3);

        *(uint32_t /* width from decompiler */ *)(iVar2 + 0x520) = 0;

        *(int *)(iVar2 + 0x524) = iVar4;

        uStack_18 = uStack_30;

        uStack_14 = uStack_2c;

        uStack_10 = uStack_28;

        (**(code **)(**(int **)(*(int *)(unaff_EDI + 0xca0) + iVar3) + 0xcc))(1);

        (**(code **)(**(int **)(*(int *)(unaff_EDI + 0xca0) + iVar3) + 0x34c))();

        iVar9 = iVar9 + 1;

        FUN_0046f100();

      } while( true );

    }

    iVar7 = 0;

    while( true ) {

      if (*(int *)(unaff_EDI + 0xca0) == 0) {

        iVar8 = 0;

      }

      else {

        iVar8 = *(int *)(unaff_EDI + 0xca4) - *(int *)(unaff_EDI + 0xca0) >> 2;

      }

      if (iVar8 <= iVar7) break;

      (**(code **)(**(int **)(*(int *)(unaff_EDI + 0xca0) + iVar7 * 4) + 4))(0);

      iVar7 = iVar7 + 1;

    }

  }

  return;

}
