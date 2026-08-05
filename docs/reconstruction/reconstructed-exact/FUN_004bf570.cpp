// =============================================================================
// FUN_004bf570
// -----------------------------------------------------------------------------
// Stable ID: aa_004bf570
// Address:   0x004bf570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004bf570 @ 0x004bf570
// Stable ID: aa_004bf570
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×9, return×4, while×2, goto×1.
//  - Notable callees: FUN_004bf7c0×2, FUN_004bf3f0, FUN_004bf570, FUN_005b7e40.
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

uint __thiscall FUN_004bf570(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  uint uVar4;

  int iVar5;

  

  uVar4 = FUN_005b7e40(param_2);

  if ((char)uVar4 == '\0') {

    return uVar4;

  }

  iVar1 = *(int *)(param_2 + 8);

  iVar5 = *(int *)(param_1 + 0x14);

  while( true ) {

    *(int *)(param_1 + 0x18) = iVar5;

    iVar5 = *(int *)(param_1 + 0x18);

    if (((iVar5 != 0) && (piVar2 = *(int **)(iVar5 + 0xc), piVar2 != (int *)0x0)) &&

       (*piVar2 == iVar1)) break;

    if ((*(int *)(param_1 + 0x18) == 0) ||

       (iVar5 = *(int *)(*(int *)(param_1 + 0x18) + 4), iVar5 == 0)) {

      FUN_004bf3f0();

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x5b4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x5b8) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x5bc) = 0;

      if (*(int *)(param_1 + 0x1c) == 0) {

        if (*(void **)(param_1 + 0x340) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(*(void **)(param_1 + 0x340));

        }

        (**(code **)(*(int *)(param_1 + 0x2c8) + 0x58))();

      }

      iVar1 = *(int *)(param_1 + 0xc);

      uVar4 = iVar1 + 0x10;

      if ((*(int *)(iVar1 + 0x14) == 0) ||

         (*(int *)(iVar1 + 0x18) - *(int *)(iVar1 + 0x14) >> 2 == 0)) {

        uVar4 = (**(code **)(*(int *)(param_1 + 0x30) + 0x58))();

      }

      return uVar4 & 0xffffff00;

    }

  }

  FUN_004bf7c0(iVar5);

  if ((char)piVar2[2] == '\0') {

    *(uint8_t *)(param_1 + 0x571) = 1;

  }

  else {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

    while( true ) {

      piVar3 = *(int **)(*(int *)(param_1 + 0x28) + 0xc);

      if ((piVar3 != (int *)0x0) && (*piVar3 == iVar1)) break;

      if ((*(int *)(param_1 + 0x28) == 0) ||

         (iVar5 = *(int *)(*(int *)(param_1 + 0x28) + 4), iVar5 == 0)) goto LAB_004bf60f;

      *(int *)(param_1 + 0x28) = iVar5;

    }

    FUN_004bf7c0(*(int *)(param_1 + 0x28));

  }

LAB_004bf60f:

                    /* WARNING: Subroutine does not return */

  operator_delete(piVar2);

}
