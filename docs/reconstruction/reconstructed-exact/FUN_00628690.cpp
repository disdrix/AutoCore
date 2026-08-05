// =============================================================================
// FUN_00628690
// -----------------------------------------------------------------------------
// Stable ID: aa_00628690
// Address:   0x00628690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00628690 @ 0x00628690
// Stable ID: aa_00628690
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~139 non-empty decompiler lines.
//  - Control keywords: if×17, while×6, do×4, return×4, goto×1.
//  - Notable callees: FUN_00628690.
//  - Return sites: 4.

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

void __thiscall FUN_00628690(int param_1,int *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  int iVar8;

  

  piVar4 = *(int **)(param_1 + 0x80);

  *(uint8_t *)(param_1 + 0xc) = 1;

  if (piVar4 < *(int **)(param_1 + 0x84)) {

    do {

      if ((*(uint *)(*param_2 + 4) <= *(uint *)(*piVar4 + 4)) &&

         ((*(uint *)(*piVar4 + 4) != *(uint *)(*param_2 + 4) ||

          (*(uint *)(param_2[1] + 4) <= *(uint *)(piVar4[1] + 4))))) break;

      piVar4 = piVar4 + 4;

    } while (piVar4 < *(int **)(param_1 + 0x84));

  }

  if (((piVar4 != *(int **)(param_1 + 0x84)) && (*(int *)(*piVar4 + 4) == *(int *)(*param_2 + 4)))

     && (*(int *)(piVar4[1] + 4) == *(int *)(param_2[1] + 4))) {

    piVar6 = *(int **)(param_1 + 0x80);

    while (piVar6 < piVar4) {

      puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x80);

      puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x88);

      *puVar1 = *puVar3;

      puVar1[1] = puVar3[1];

      puVar1[2] = puVar3[2];

      puVar1[3] = puVar3[3];

      *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 0x10;

      *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + 0x10;

      piVar6 = *(int **)(param_1 + 0x80);

    }

    piVar4 = *(int **)(*(int *)(param_1 + 0x80) + 8);

    if (piVar4 != (int *)0x0) {

      piVar6 = (int *)piVar4[2];

      (**(code **)(*piVar4 + 0x14))();

      (**(code **)(*piVar6 + 0x10))();

    }

    *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + 0x10;

    return;

  }

  iVar7 = *param_2;

  if (iVar7 == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = iVar7 + -0x10;

  }

  iVar2 = *(int *)(*(int *)(iVar2 + 0x20) + 0x44);

  puVar3 = (uint32_t /* width from decompiler */ *)(iVar2 + 0x74);

  iVar5 = 0;

  if (0 < *(int *)(iVar2 + 0x78)) {

    piVar4 = (int *)*puVar3;

    piVar6 = piVar4;

    do {

      if ((*(int *)(*piVar6 + 4) == *(int *)(iVar7 + 4)) &&

         (*(int *)(piVar6[1] + 4) == *(int *)(param_2[1] + 4))) goto LAB_006287e4;

      iVar5 = iVar5 + 1;

      piVar6 = piVar6 + 2;

    } while (iVar5 < *(int *)(iVar2 + 0x78));

  }

  iVar2 = param_2[1];

  if (iVar2 == 0) {

    iVar5 = 0;

  }

  else {

    iVar5 = iVar2 + -0x10;

  }

  iVar8 = *(int *)(*(int *)(iVar5 + 0x20) + 0x44);

  puVar3 = (uint32_t /* width from decompiler */ *)(iVar8 + 0x74);

  iVar5 = 0;

  if (0 < *(int *)(iVar8 + 0x78)) {

    piVar4 = (int *)*puVar3;

    piVar6 = piVar4;

    do {

      if ((*(int *)(*piVar6 + 4) == *(int *)(iVar7 + 4)) &&

         (*(int *)(piVar6[1] + 4) == *(int *)(iVar2 + 4))) {

LAB_006287e4:

        iVar7 = puVar3[1] + -1;

        puVar3[1] = iVar7;

        piVar4[iVar5 * 2] = piVar4[iVar7 * 2];

        piVar4[iVar5 * 2 + 1] = piVar4[iVar7 * 2 + 1];

        return;

      }

      iVar5 = iVar5 + 1;

      piVar6 = piVar6 + 2;

    } while (iVar5 < *(int *)(iVar8 + 0x78));

  }

  if (iVar7 == 0) {

    iVar5 = 0;

  }

  else {

    iVar5 = iVar7 + -0x10;

  }

  iVar5 = *(int *)(*(int *)(iVar5 + 0x20) + 0x44);

  if (iVar5 == param_1 + -0x1c) {

    if (iVar2 == 0) {

      iVar5 = 0;

    }

    else {

      iVar5 = iVar2 + -0x10;

    }

    iVar5 = *(int *)(*(int *)(iVar5 + 0x20) + 0x44);

  }

  iVar8 = 0;

  if (0 < *(int *)(iVar5 + 0x6c)) {

    piVar4 = *(int **)(iVar5 + 0x68);

    while ((*(int *)(*piVar4 + 4) != *(int *)(iVar7 + 4) ||

           (*(int *)(piVar4[1] + 4) != *(int *)(iVar2 + 4)))) {

      iVar8 = iVar8 + 1;

      piVar4 = piVar4 + 4;

      if (*(int *)(iVar5 + 0x6c) <= iVar8) {

        return;

      }

    }

    iVar7 = iVar8 * 0x10;

    piVar4 = (int *)(*(int **)(iVar5 + 0x68))[iVar8 * 4 + 2];

    if (piVar4 != (int *)0x0) {

      piVar6 = (int *)piVar4[2];

      (**(code **)(*piVar4 + 0x14))();

      (**(code **)(*piVar6 + 0x10))();

    }

    *(int *)(iVar5 + 0x6c) = *(int *)(iVar5 + 0x6c) + -1;

    if (iVar8 < *(int *)(iVar5 + 0x6c)) {

      do {

        puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar5 + 0x68) + iVar7);

        *puVar3 = puVar3[4];

        puVar3[1] = puVar3[5];

        puVar3[2] = puVar3[6];

        iVar8 = iVar8 + 1;

        puVar3[3] = puVar3[7];

        iVar7 = iVar7 + 0x10;

      } while (iVar8 < *(int *)(iVar5 + 0x6c));

    }

  }

  return;

}
