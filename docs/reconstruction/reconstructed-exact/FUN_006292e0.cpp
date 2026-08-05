// =============================================================================
// FUN_006292e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006292e0
// Address:   0x006292e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006292e0 @ 0x006292e0
// Stable ID: aa_006292e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~112 non-empty decompiler lines.
//  - Control keywords: if×14, return×4, do×1, while×1.
//  - Notable callees: FUN_0055eb80, FUN_0055efd0, FUN_006291a0, FUN_006292e0.
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

void __thiscall FUN_006292e0(int param_1,int *param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int unaff_EDI;

  int *piVar9;

  int *local_8;

  int local_4;

  

  if (*(uint *)(param_1 + 0x80) < *(uint *)(param_1 + 0x84)) {

    do {

      piVar9 = *(int **)(param_1 + 0x80);

      if ((*(uint *)(*param_2 + 4) <= *(uint *)(*piVar9 + 4)) &&

         ((*(uint *)(*piVar9 + 4) != *(uint *)(*param_2 + 4) ||

          (*(uint *)(param_2[1] + 4) <= *(uint *)(piVar9[1] + 4))))) break;

      piVar1 = *(int **)(param_1 + 0x88);

      *piVar1 = *piVar9;

      piVar1[1] = piVar9[1];

      piVar1[2] = piVar9[2];

      piVar1[3] = piVar9[3];

      *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 0x10;

      *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + 0x10;

    } while (*(uint *)(param_1 + 0x80) < *(uint *)(param_1 + 0x84));

  }

  if ((((*(int *)(param_1 + 0x50) == 0) ||

       (piVar9 = *(int **)(param_1 + 0x80), piVar9 == *(int **)(param_1 + 0x84))) ||

      (*(int *)(*piVar9 + 4) != *(int *)(*param_2 + 4))) ||

     (*(int *)(piVar9[1] + 4) != *(int *)(param_2[1] + 4))) {

    local_8 = *(int **)(param_1 + 0x88);

    if (*param_2 == 0) {

      puVar8 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      puVar8 = (uint32_t /* width from decompiler */ *)(*param_2 + -0x10);

    }

    if (param_2[1] == 0) {

      puVar7 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      puVar7 = (uint32_t /* width from decompiler */ *)(param_2[1] + -0x10);

    }

    if (puVar8 == (uint32_t /* width from decompiler */ *)0x0) {

      puVar2 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      puVar2 = puVar8 + 4;

    }

    *local_8 = (int)puVar2;

    if (puVar7 == (uint32_t /* width from decompiler */ *)0x0) {

      puVar2 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      puVar2 = puVar7 + 4;

    }

    local_8[1] = (int)puVar2;

    iVar4 = puVar8[8];

    local_4 = puVar7[8];

    iVar5 = *(int *)(iVar4 + 0x44);

    if (iVar5 != *(int *)(local_4 + 0x44)) {

      if (iVar5 == param_1 + -0x1c) {

        iVar5 = *(int *)(local_4 + 0x44);

      }

      if ((*(int *)(iVar5 + 0x24) != -1) && (*(char *)(iVar5 + 0x29) == '\0')) {

        FUN_0055eb80(iVar5);

      }

      if (*(char *)(iVar5 + 0x30) == '\0') {

        FUN_006291a0(param_2);

        return;

      }

      if ((*(char *)(iVar4 + 0x40) == '\0') && (*(char *)(local_4 + 0x40) == '\0')) {

        FUN_0055efd0(iVar4,local_4);

      }

    }

    piVar9 = *(int **)(param_1 + 0x7c);

    piVar3 = (int *)(**(code **)(**(int **)(*piVar9 + 0xc +

                                           ((int)*(char *)(local_4 + 0x48) +

                                           *(char *)(iVar4 + 0x48) * 8) * 4) + 4))(puVar8,puVar7);

    piVar1 = *(int **)(param_1 + 0x7c);

    local_8 = (int *)*piVar1;

    iVar4 = (**(code **)(*(int *)*puVar8 + 0x14))();

    iVar5 = (**(code **)(*(int *)*puVar7 + 0x14))();

    iVar4 = (*(code *)local_8[iVar4 * 0x20 + iVar5 + 99])(puVar8,puVar7,piVar1,piVar3);

    *(int *)(unaff_EDI + 8) = iVar4;

    if ((iVar4 != 0) && (*(int *)(iVar4 + 8) != 0)) {

      iVar4 = puVar8[8];

      local_8 = (int *)puVar7[8];

      iVar5 = (**(code **)(**(int **)(iVar4 + 0x3c) + 0x18))();

      piVar1 = local_8;

      if (((iVar5 == 6) || (*(char *)(iVar4 + 0x40) != '\0')) &&

         ((iVar4 = (**(code **)(*(int *)local_8[0xf] + 0x18))(), iVar4 == 6 ||

          ((char)piVar1[0x10] != '\0')))) {

        *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc) = 0xffffffff;

        *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 0x10;

        return;

      }

      pcVar6 = (char *)(**(code **)(**(int **)(*(int *)(param_1 + 4) + 0x250) + 4))

                                 (&local_8,puVar8,puVar7);

      piVar9[3] = (*pcVar6 != '\0') - 1;

      *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 0x10;

      return;

    }

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8) = 0;

    (**(code **)(*piVar3 + 0x10))();

    *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 0x10;

  }

  return;

}
