// =============================================================================
// FUN_008ab550
// -----------------------------------------------------------------------------
// Stable ID: aa_008ab550
// Address:   0x008ab550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008ab550 @ 0x008ab550
// Stable ID: aa_008ab550
// Embedded strings (evidence for future rename):
//   - "Select a Mission:"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~93 non-empty decompiler lines.
//  - Control keywords: if×19, return×2, do×1, while×1.
//  - Notable callees: FUN_008ab340×2, FUN_007a69d0, FUN_007a6de0, FUN_008ab550.
//  - Strings: "Select a Mission:".
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

void __fastcall FUN_008ab550(int param_1)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int *piVar3;

  float fVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  

  FUN_007a69d0();

  *(int *)(param_1 + 0x648) = in_EAX;

  if ((in_EAX == 0) || (in_EAX == 3)) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x670) = 0;

  }

  else if ((in_EAX == 1) || (in_EAX == 2)) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x678) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x67c) = 0xffffffff;

  }

  if ((in_EAX == 0) || (in_EAX == 3)) {

    *(uint8_t *)(param_1 + 0x580) = 0;

    if (*(int **)(param_1 + 0x6e8) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x6e8) + 4))(0);

    }

  }

  if (*(int **)(param_1 + 0x6dc) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x6dc) + 4))(*(int *)(param_1 + 0x648) != 0);

    if (*(int *)(param_1 + 0x648) == 3) {

      (**(code **)(**(int **)(param_1 + 0x6dc) + 0x1b0))(10);

      iVar2 = *(int *)(param_1 + 0x6dc);

      fVar4 = (float)DAT_00d1e81c;

      uVar6 = 1;

      *(int *)(iVar2 + 0x170) =

           (int)((float)*(int *)(iVar2 + 0x1b8) * (float)DAT_00d1e818 * DAT_00aaa67c);

      uVar5 = 1;

      *(int *)(iVar2 + 0x174) = (int)((float)*(int *)(iVar2 + 0x1bc) * fVar4 * DAT_00aaa678);

      iVar2 = **(int **)(param_1 + 0x6dc);

      uVar1 = FUN_007a6de0("Select a Mission:",0xffffffff);

      (**(code **)(iVar2 + 0x1d8))(uVar1,uVar5,uVar6);

      (**(code **)(**(int **)(param_1 + 0x6dc) + 0x15c))(1,&DAT_00afdf0c);

      (**(code **)(**(int **)(param_1 + 0x6dc) + 0x34c))();

    }

  }

  if ((*(int *)(param_1 + 0x648) == 0) || (*(int *)(param_1 + 0x648) == 3)) {

    if (*(int **)(param_1 + 0x6e4) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x6e4) + 4))(0);

    }

    if (*(int **)(param_1 + 0x68c) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x68c) + 4))(0);

    }

    if (*(int **)(param_1 + 0x690) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x690) + 4))(0);

    }

    if (*(int **)(param_1 + 0x6e8) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x6e8) + 4))(0);

    }

    piVar3 = (int *)(param_1 + 0x6c8);

    iVar2 = 4;

    do {

      if (piVar3[-8] != 0) {

        (**(code **)(*(int *)piVar3[-8] + 4))(0);

      }

      if (*piVar3 != 0) {

        (**(code **)(*(int *)*piVar3 + 4))(0);

      }

      if (piVar3[-0xc] != 0) {

        (**(code **)(*(int *)piVar3[-0xc] + 4))(0);

      }

      if (piVar3[-4] != 0) {

        (**(code **)(*(int *)piVar3[-4] + 4))(0);

      }

      piVar3 = piVar3 + 1;

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

    if ((*(int *)(param_1 + 0x648) == 3) && (*(int **)(param_1 + 0x6f8) != (int *)0x0)) {

      (**(code **)(**(int **)(param_1 + 0x6f8) + 4))(0);

    }

    if (*(int **)(param_1 + 0x6fc) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x6fc) + 4))(0);

    }

  }

  else {

    if (*(int **)(param_1 + 0x6f8) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x6f8) + 4))(1);

    }

    if (*(int **)(param_1 + 0x6fc) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x6fc) + 4))(1);

      FUN_008ab340();

      return;

    }

  }

  FUN_008ab340();

  return;

}
