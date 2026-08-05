// =============================================================================
// FUN_007641c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007641c0
// Address:   0x007641c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007641c0 @ 0x007641c0
// Stable ID: aa_007641c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~93 non-empty decompiler lines.
//  - Control keywords: if×13, return×3, while×2, do×1, for×1.
//  - Notable callees: FUN_00438d80, FUN_0043a660, FUN_00456960, FUN_0073ede0, FUN_007633d0, FUN_007641c0, FUN_0096b210, FUN_0096d9d0.
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

int * FUN_007641c0(int param_1)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  uint32_t /* width from decompiler */ uVar7;

  int *piVar8;

  int *unaff_EDI;

  

  FUN_0096d9d0(param_1);

  unaff_EDI[0x23] = *(int *)(param_1 + 0x8c);

  FUN_0096b210(param_1 + 0x98,unaff_EDI + 0x26);

  unaff_EDI[0x2e] = -1;

  iVar4 = (**(code **)(*unaff_EDI + 0xc))();

  unaff_EDI[0x38] = (int)(unaff_EDI + 1);

  unaff_EDI[0x37] = iVar4;

  if (unaff_EDI[0x23] != 0) {

    iVar4 = NDResource_AcquireInnerObject();

    unaff_EDI[0x24] = iVar4;

  }

  iVar4 = *(int *)(param_1 + 300);

  iVar1 = *(int *)(param_1 + 0x130);

  if (iVar4 != iVar1) {

    do {

      iVar2 = unaff_EDI[0x4b];

      if ((iVar2 == 0) ||

         ((uint)(unaff_EDI[0x4d] - iVar2 >> 3) <= (uint)(unaff_EDI[0x4c] - iVar2 >> 3))) {

        FUN_00438d80(unaff_EDI + 0x4a,unaff_EDI[0x4c],1,iVar4);

      }

      else {

        iVar2 = unaff_EDI[0x4c];

        FUN_0043a660(iVar2,param_1);

        unaff_EDI[0x4c] = iVar2 + 8;

      }

      iVar2 = unaff_EDI[0x4c];

      if ((*(int *)(iVar2 + -4) != 0) && (1 < *(int *)(*(int *)(iVar2 + -4) + 4))) {

        piVar5 = (int *)FUN_0073ede0();

        if ((piVar5 != (int *)0x0) && (piVar5[1] = piVar5[1] + 1, piVar5[1] == 1)) {

          (**(code **)(*piVar5 + 4))();

        }

        piVar8 = *(int **)(iVar2 + -4);

        if (piVar8 != (int *)0x0) {

          piVar6 = piVar8 + 1;

          *piVar6 = *piVar6 + -1;

          if (*piVar6 == 0) {

            (**(code **)(*piVar8 + 8))();

          }

        }

        *(int **)(iVar2 + -4) = piVar5;

      }

      iVar4 = iVar4 + 8;

    } while (iVar4 != iVar1);

  }

  piVar5 = *(int **)(param_1 + 0xc4);

  for (piVar8 = *(int **)(param_1 + 0xc0); piVar8 != piVar5; piVar8 = piVar8 + 1) {

    if ((int *)*piVar8 == (int *)0x0) {

      return unaff_EDI;

    }

    piVar6 = (int *)(**(code **)(*(int *)*piVar8 + 0x7c))();

    iVar4 = unaff_EDI[0x30];

    if ((iVar4 == 0) ||

       ((uint)(unaff_EDI[0x32] - iVar4 >> 2) <= (uint)(unaff_EDI[0x31] - iVar4 >> 2))) {

      FUN_00456960(unaff_EDI[0x31]);

    }

    else {

      puVar3 = (uint32_t /* width from decompiler */ *)unaff_EDI[0x31];

      *puVar3 = piVar6;

      unaff_EDI[0x31] = (int)(puVar3 + 1);

    }

    (**(code **)(*piVar6 + 0x20))();

  }

  piVar5 = *(int **)(param_1 + 0xd0);

  piVar8 = *(int **)(param_1 + 0xd4);

  while( true ) {

    if (piVar5 == piVar8) {

      if (*(int *)(param_1 + 0x94) != 0) {

        if ((uint32_t /* width from decompiler */ *)unaff_EDI[0x25] != (uint32_t /* width from decompiler */ *)0x0) {

          (*(code *)**(uint32_t /* width from decompiler */ **)unaff_EDI[0x25])(1);

        }

        iVar4 = (**(code **)(**(int **)(param_1 + 0x94) + 0x44))();

        unaff_EDI[0x25] = iVar4;

      }

      return unaff_EDI;

    }

    if ((int *)*piVar5 == (int *)0x0) break;

    uVar7 = (**(code **)(*(int *)*piVar5 + 0x7c))();

    FUN_007633d0(unaff_EDI,uVar7);

    piVar5 = piVar5 + 1;

  }

  return unaff_EDI;

}
