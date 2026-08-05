// =============================================================================
// FUN_00517df0
// -----------------------------------------------------------------------------
// Stable ID: aa_00517df0
// Address:   0x00517df0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00517df0 @ 0x00517df0
// Stable ID: aa_00517df0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×10, while×4, do×3, return×2.
//  - Notable callees: FUN_00517df0×8, FUN_004bae00×2, FUN_00517400×2, FUN_00404d70, FUN_004eb0c0, FUN_0051c0e0, FUN_007d8fe0, FUN_007d9440.
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

void FUN_00517df0(int param_1,int param_2)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  uint uStack_8;

  uint8_t local_4;

  

  iVar6 = param_2;

  iVar4 = param_1;

  if ((param_1 != 0) && (param_2 != -1)) {

    param_1 = 0;

    local_4 = 1;

    iVar3 = FUN_00404d70(param_2);

    if ((iVar3 != 0) && (*(int *)(iVar3 + 0x38) != 0x14)) {

      FUN_004eb0c0();

    }

    if ((char)param_2 == '\0') {

      FUN_007d9440(1);

      iVar4 = 0;

      do {

        piVar5 = (int *)FUN_004bae00(iVar4 != 0,&stack0x00000000);

        while (piVar5 != (int *)0x0) {

          if (((*(int *)(piVar5[0x2a] + 0x34) == iVar6) &&

              ((iVar3 = (**(code **)(*piVar5 + 0x1d4))(), iVar3 == 0 ||

               (iVar3 = (**(code **)(*piVar5 + 0x1d4))(), *(int *)(iVar3 + 0x14c) == -1)))) &&

             ((iVar3 = (**(code **)(*piVar5 + 0x1d8))(), iVar3 == 0 ||

              (iVar3 = (**(code **)(*piVar5 + 0x1d8))(), *(int *)(iVar3 + 600) == 0)))) {

            uVar2 = uStack_8;

            if (((int *)piVar5[0x2b] != (int *)0x0) &&

               (iVar6 = (**(code **)(*(int *)piVar5[0x2b] + 0x210))(0), iVar6 != 0)) {

              (**(code **)(*piVar5 + 0x18))();

              iVar6 = (**(code **)(*(int *)piVar5[0x2b] + 0x210))(0);

              if (iVar6 != 0) {

                iVar6 = *(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6;

              }

              FUN_00517400(iVar6,uVar2);

            }

            FUN_00517400(piVar5,uVar2);

            uStack_8 = uStack_8 & 0xffffff00;

            iVar6 = param_1;

          }

          piVar5 = (int *)FUN_004bae00(iVar4 != 0,&stack0x00000000);

        }

        iVar4 = iVar4 + 1;

      } while (iVar4 < 2);

    }

    else {

      FUN_0051c0e0(&uStack_8,&param_1);

      FUN_007d8fe0(*(uint32_t /* width from decompiler */ *)(uStack_8 + 0x10),uStack_8 + 0x10);

      FUN_00517df0(iVar4,*(uint32_t /* width from decompiler */ *)(uStack_8 + 0x2c),0);

      FUN_00517df0(iVar4,*(uint32_t /* width from decompiler */ *)(uStack_8 + 0x18),0);

      FUN_00517df0(iVar4,*(uint32_t /* width from decompiler */ *)(uStack_8 + 0x14),0);

      FUN_00517df0(iVar4,*(uint32_t /* width from decompiler */ *)(uStack_8 + 0x24),0);

      FUN_00517df0(iVar4,*(uint32_t /* width from decompiler */ *)(uStack_8 + 0x20),0);

      FUN_00517df0(iVar4,*(uint32_t /* width from decompiler */ *)(uStack_8 + 0x28),0);

      FUN_00517df0(iVar4,*(uint32_t /* width from decompiler */ *)(uStack_8 + 0x1c),0);

      iVar6 = *(int *)(iVar4 + 0xe4e8);

      piVar5 = *(int **)(iVar6 + 0x2c);

      if (piVar5 != *(int **)(iVar6 + 0x30)) {

        do {

          if (((*(int *)(((int *)*piVar5)[0x2a] + 0x38) == 0xe) &&

              (iVar4 = (**(code **)(*(int *)*piVar5 + 0x1d4))(), *(int *)(iVar4 + 0x14c) == param_1)

              ) && (*(int *)(iVar4 + 0x280) == 0)) {

            iVar3 = *(int *)(iVar4 + 0x254);

            if (iVar3 != 0) {

              (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x18))();

            }

            iVar3 = 0;

            do {

              iVar1 = *(int *)(iVar3 + *(int *)(iVar4 + 0x260));

              if (iVar1 != 0) {

                (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x18))();

              }

              iVar3 = iVar3 + 4;

            } while (iVar3 < 0xc);

          }

          piVar5 = piVar5 + 1;

        } while (piVar5 != *(int **)(iVar6 + 0x30));

        return;

      }

    }

  }

  return;

}
