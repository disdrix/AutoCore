// =============================================================================
// FUN_00821650
// -----------------------------------------------------------------------------
// Stable ID: aa_00821650
// Address:   0x00821650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00821650 @ 0x00821650
// Stable ID: aa_00821650
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~113 non-empty decompiler lines.
//  - Control keywords: if×16, while×5, return×2, do×2, switch×1, goto×1.
//  - Notable callees: FUN_008e9140×2, FUN_00417c50, FUN_00821650.
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

void FUN_00821650(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  int iVar7;

  

  piVar3 = (int *)FUN_00417c50(param_1 + 0x14);

  piVar5 = DAT_00d1b8e0;

  if (piVar3 == (int *)0x0) {

    return;

  }

  switch(*piVar3) {

  case 0:

  case 1:

    cVar2 = (**(code **)(*DAT_00d1b8e0 + 0x3d8))();

    if (cVar2 != '\0') {

      iVar7 = 0;

      piVar6 = DAT_00d1b634;

      while( true ) {

        if (piVar6 == (int *)0x0) {

          iVar4 = 0;

        }

        else {

          iVar4 = (int)DAT_00d1b638 - (int)piVar6 >> 2;

        }

        if (iVar4 <= iVar7) break;

        puVar1 = (uint32_t /* width from decompiler */ *)piVar6[iVar7];

        if (*(char *)(puVar1 + 3) == (char)piVar3[2]) {

          FUN_008e9140(piVar5,*puVar1,puVar1[1],*piVar3 == 1);

          piVar6 = DAT_00d1b634;

        }

        iVar7 = iVar7 + 1;

      }

    }

    break;

  case 2:

    iVar7 = (**(code **)(**(int **)(*(int *)(param_1 + 0x58) + 0xe8a0) + 0x1dc))();

    if (iVar7 != 0) {

      *(int *)(iVar7 + 0x52c) = piVar3[1];

    }

    piVar5 = DAT_00d1b8e0;

    cVar2 = (**(code **)(*DAT_00d1b8e0 + 0x3d8))();

    if (cVar2 != '\0') {

      iVar7 = 0;

      piVar6 = DAT_00d1b634;

      while( true ) {

        if (piVar6 == (int *)0x0) {

          iVar4 = 0;

        }

        else {

          iVar4 = (int)DAT_00d1b638 - (int)piVar6 >> 2;

        }

        if (iVar4 <= iVar7) break;

        puVar1 = (uint32_t /* width from decompiler */ *)piVar6[iVar7];

        if (puVar1[2] == piVar3[1]) {

          *(char *)(puVar1 + 3) = (char)piVar3[2];

          FUN_008e9140(piVar5,*puVar1,puVar1[1],0);

          piVar6 = DAT_00d1b634;

        }

        iVar7 = iVar7 + 1;

      }

    }

    break;

  case 3:

    piVar5 = DAT_00d1b634;

    if (DAT_00d1b634 != DAT_00d1b638) {

      do {

        iVar7 = *piVar5;

        piVar5 = piVar5 + 1;

        *(uint8_t *)(iVar7 + 0xd) = 0;

      } while (piVar5 != DAT_00d1b638);

    }

    goto LAB_00821787;

  case 4:

    iVar7 = 0;

    piVar5 = DAT_00d1b634;

    while( true ) {

      if (piVar5 == (int *)0x0) {

        iVar4 = 0;

      }

      else {

        iVar4 = (int)DAT_00d1b638 - (int)piVar5 >> 2;

      }

      if (iVar4 <= iVar7) break;

      iVar4 = piVar5[iVar7];

      if (*(int *)(iVar4 + 8) == piVar3[1]) {

        *(char *)(iVar4 + 0xc) = (char)piVar3[2];

        *(uint8_t *)(iVar4 + 0xd) = 1;

        piVar5 = DAT_00d1b634;

      }

      iVar7 = iVar7 + 1;

    }

LAB_00821787:

    (**(code **)(*DAT_00d1b8e0 + 0x448))();

    break;

  case 5:

    piVar5 = DAT_00d1b634;

    if (DAT_00d1b634 != DAT_00d1b638) {

      do {

        if (*(int *)(*piVar5 + 8) == piVar3[1]) {

          *(uint8_t *)(*piVar5 + 0xd) = 0;

        }

        piVar5 = piVar5 + 1;

      } while (piVar5 != DAT_00d1b638);

    }

    (**(code **)(*DAT_00d1b8e0 + 0x448))();

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(piVar3);

}
