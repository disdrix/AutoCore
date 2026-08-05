// =============================================================================
// FUN_005e2510
// -----------------------------------------------------------------------------
// Stable ID: aa_005e2510
// Address:   0x005e2510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e2510 @ 0x005e2510
// Stable ID: aa_005e2510
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×4, while×2, return×1.
//  - Notable callees: FUN_005e2510.
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

void __thiscall FUN_005e2510(int *param_1,char param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  

  piVar6 = (int *)param_1[5];

  *(uint8_t *)(param_1 + 0x58) = 0;

  if (((*piVar6 != 0) && (piVar6[1] == 0)) ||

     ((piVar6[1] != 0 && (iVar4 = (**(code **)(*(int *)piVar6[1] + 0x24))(), iVar4 == 0)))) {

    puVar1 = (uint32_t /* width from decompiler */ *)param_1[5];

    uVar2 = *puVar1;

    *puVar1 = puVar1[1];

    *(uint32_t /* width from decompiler */ *)(param_1[5] + 4) = uVar2;

  }

  iVar4 = *(int *)(param_1[5] + 4);

  piVar6 = param_1;

  while (((iVar4 != 0 &&

          (piVar5 = (int *)(**(code **)(**(int **)(piVar6[5] + 4) + 0x24))(), piVar5 != (int *)0x0))

         && (piVar5 != param_1))) {

    piVar3 = (int *)piVar5[5];

    if ((int *)*piVar3 == piVar6) {

      *(uint8_t *)(piVar5 + 0x58) = 0;

    }

    else {

      iVar4 = *piVar3;

      *piVar3 = piVar3[1];

      *(int *)(piVar5[5] + 4) = iVar4;

      *(uint8_t *)(piVar5 + 0x58) = 1;

    }

    iVar4 = *(int *)(piVar5[5] + 4);

    piVar6 = piVar5;

  }

  if (param_2 != '\0') {

    iVar4 = *(int *)(param_1[5] + 4);

    piVar6 = param_1;

    while (((iVar4 != 0 &&

            (piVar6 = (int *)(**(code **)(**(int **)(piVar6[5] + 4) + 0x24))(), piVar6 != (int *)0x0

            )) && (piVar6 != param_1))) {

      if (((char)piVar6[0x58] != '\0') &&

         ((**(code **)(*piVar6 + 0x78))(), *(char *)(param_1[0x4e] + 0x7d) != '\0')) {

        (**(code **)(*piVar6 + 0x84))();

      }

      iVar4 = *(int *)(piVar6[5] + 4);

    }

  }

  return;

}
