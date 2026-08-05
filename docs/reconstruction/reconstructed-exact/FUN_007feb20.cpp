// =============================================================================
// FUN_007feb20
// -----------------------------------------------------------------------------
// Stable ID: aa_007feb20
// Address:   0x007feb20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007feb20 @ 0x007feb20
// Stable ID: aa_007feb20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×12, do×1, while×1, return×1.
//  - Notable callees: FUN_007fca10×6, FUN_007fdcc0, FUN_007feb20.
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

void FUN_007feb20(void)



{

  int *piVar1;

  char cVar2;

  int in_EAX;

  int iVar3;

  int *piVar4;

  

  FUN_007fca10();

  FUN_007fca10();

  FUN_007fca10();

  FUN_007fca10();

  FUN_007fca10();

  FUN_007fdcc0(in_EAX);

  if (((*(int **)(in_EAX + 0xf40) != (int *)0x0) &&

      (iVar3 = *(int *)(in_EAX + 0xf38), **(int **)(in_EAX + 0xf40) == iVar3)) && (iVar3 != 0)) {

    if (*(int *)(iVar3 + 0xcb0) != 0) {

      (**(code **)(**(int **)(iVar3 + 0xcb0) + 4))(0);

    }

    if (*(int *)(*(int *)(in_EAX + 0xf38) + 0xcb4) != 0) {

      (**(code **)(**(int **)(*(int *)(in_EAX + 0xf38) + 0xcb4) + 4))(0);

    }

    if (*(int *)(*(int *)(in_EAX + 0xf38) + 0xcb8) != 0) {

      (**(code **)(**(int **)(*(int *)(in_EAX + 0xf38) + 0xcb8) + 4))(0);

    }

    if (*(int *)(*(int *)(in_EAX + 0xf38) + 0xcc0) != 0) {

      (**(code **)(**(int **)(*(int *)(in_EAX + 0xf38) + 0xcc0) + 4))(0);

    }

  }

  if (*(int *)(in_EAX + 0x1164) != 0) {

    cVar2 = (**(code **)(**(int **)(in_EAX + 0x1164) + 0x3d8))();

    if (cVar2 != '\0') {

      (**(code **)(**(int **)(in_EAX + 0x1164) + 4))(0);

    }

  }

  iVar3 = 0;

  piVar4 = (int *)(in_EAX + 0x1030);

  do {

    *(uint8_t *)(in_EAX + 0x5c + iVar3) = 0;

    piVar1 = (int *)*piVar4;

    if (piVar1 != (int *)0x0) {

      if (((((iVar3 == 0x14) || (iVar3 == 0x15)) ||

           ((iVar3 == 0xb || ((iVar3 == 9 || (iVar3 == 7)))))) || (iVar3 == 6)) ||

         (((iVar3 == 0xf || (iVar3 == 10)) || (iVar3 == 0x10)))) {

        cVar2 = (**(code **)(*piVar1 + 0x3d8))();

        if (cVar2 != '\0') {

          FUN_007fca10();

        }

      }

      else {

        cVar2 = (**(code **)(*piVar1 + 0x3d8))();

        if (cVar2 != '\0') {

          cVar2 = (**(code **)(*(int *)*piVar4 + 0xd0))();

          if (cVar2 != '\0') {

            *(uint8_t *)(in_EAX + 0x5c + iVar3) = 1;

            (**(code **)(*(int *)*piVar4 + 4))(0);

          }

        }

      }

    }

    iVar3 = iVar3 + 1;

    piVar4 = piVar4 + 1;

  } while (iVar3 < 0x3a);

  return;

}
