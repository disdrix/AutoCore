// =============================================================================
// FUN_00790f80
// -----------------------------------------------------------------------------
// Stable ID: aa_00790f80
// Address:   0x00790f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00790f80 @ 0x00790f80
// Stable ID: aa_00790f80
// Embedded strings (evidence for future rename):
//   - "HashError:TraverseToNext, not locked for traversal"
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~113 non-empty decompiler lines.
//  - Control keywords: if×22, goto×7, return×2, for×2.
//  - Notable callees: FUN_007a4480×4, FUN_00411e10, FUN_00790f80.
//  - Strings: "HashError:TraverseToNext, not locked for traversal"; "VOG_DEBUG_STOP".
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

int * __thiscall FUN_00790f80(int *param_1,char param_2)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  int *piVar7;

  int *piVar8;

  

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar1 == '\0') || (param_1[0x130] == 0)) {

    return (int *)0x0;

  }

  iVar5 = 0;

  if (param_1[0x12f] == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = (**(code **)(*(int *)param_1[0x12f] + 0x9c))();

  }

  FUN_00411e10();

  piVar7 = (int *)0x0;

  piVar8 = (int *)0x0;

  if (param_2 == '\0') {

LAB_007910c0:

    iVar3 = param_1[0x130];

    if (*(char *)(iVar3 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar5 == 0) {

      iVar5 = *(int *)(iVar3 + 0x14);

    }

    else {

      iVar5 = *(int *)(iVar5 + 0x14);

    }

    if (iVar5 == 0) {

      piVar7 = (int *)0x0;

    }

    else {

      piVar7 = *(int **)(iVar5 + 8);

    }

    if (piVar7 != (int *)0x0) {

      if (*(char *)((int)piVar7 + 0xd2) != '\0') {

        if (piVar8 != (int *)0x0) {

          iVar3 = (**(code **)(*piVar7 + 0x9c))();

          if (iVar3 < iVar2) {

            iVar3 = (**(code **)(*piVar8 + 0x9c))();

            if (iVar2 <= iVar3) goto LAB_007910b4;

          }

          else {

            iVar3 = (**(code **)(*piVar7 + 0x9c))();

            if ((iVar3 <= iVar2) || (iVar3 = (**(code **)(*piVar8 + 0x9c))(), iVar3 < iVar2))

            goto LAB_007910c0;

          }

          iVar3 = (**(code **)(*piVar7 + 0x9c))();

          iVar4 = (**(code **)(*piVar8 + 0x9c))();

          if (iVar3 <= iVar4) goto LAB_007910c0;

        }

LAB_007910b4:

        piVar8 = piVar7;

      }

      goto LAB_007910c0;

    }

  }

  else {

LAB_00790ff0:

    piVar8 = piVar7;

    iVar3 = param_1[0x130];

    if (*(char *)(iVar3 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar5 == 0) {

      iVar5 = *(int *)(iVar3 + 0x14);

    }

    else {

      iVar5 = *(int *)(iVar5 + 0x14);

    }

    if (iVar5 == 0) {

      piVar6 = (int *)0x0;

    }

    else {

      piVar6 = *(int **)(iVar5 + 8);

    }

    if (piVar6 != (int *)0x0) {

      piVar7 = piVar8;

      if ((*(char *)((int)piVar6 + 0xd2) != '\0') && (piVar7 = piVar6, piVar8 != (int *)0x0)) {

        iVar3 = (**(code **)(*piVar6 + 0x9c))();

        if (iVar2 < iVar3) {

          iVar3 = (**(code **)(*piVar8 + 0x9c))();

          if (iVar3 <= iVar2) goto LAB_00790ff0;

        }

        else {

          iVar3 = (**(code **)(*piVar6 + 0x9c))();

          piVar7 = piVar8;

          if ((iVar2 <= iVar3) || (iVar3 = (**(code **)(*piVar8 + 0x9c))(), iVar2 < iVar3))

          goto LAB_00790ff0;

        }

        iVar3 = (**(code **)(*piVar6 + 0x9c))();

        iVar4 = (**(code **)(*piVar8 + 0x9c))();

        piVar7 = piVar8;

        if (iVar3 < iVar4) {

          piVar7 = piVar6;

        }

      }

      goto LAB_00790ff0;

    }

  }

  *(uint8_t *)(param_1[0x130] + 0x1d) = 0;

  return piVar8;

}
