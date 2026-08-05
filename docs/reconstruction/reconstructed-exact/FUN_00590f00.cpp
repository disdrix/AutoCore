// =============================================================================
// FUN_00590f00
// -----------------------------------------------------------------------------
// Stable ID: aa_00590f00
// Address:   0x00590f00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00590f00 @ 0x00590f00
// Stable ID: aa_00590f00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~131 non-empty decompiler lines.
//  - Control keywords: if×27, goto×6, return×3, do×1, while×1, for×1.
//  - Notable callees: FUN_004d2d60×3, FUN_00561450×3, FUN_00590f00, FUN_00597e00, FUN_0096d550.
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

void __thiscall FUN_00590f00(int param_1,int param_2,int *param_3)



{

  uint8_t *puVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  

  if ((*(int *)(param_1 + 0x914) != 0) &&

     (puVar1 = *(uint8_t **)(*(int *)(param_1 + 0x914) + 0x78), puVar1 != (uint8_t *)0x0)) {

    *puVar1 = 9;

    *(int *)(*(int *)(*(int *)(param_1 + 0x914) + 0x78) + 4) = param_1;

  }

  if ((*(byte *)(param_1 + 0x90e) & 0x80) == 0) goto LAB_00590fe9;

  if (((*(int *)(param_1 + 0x25c) < 0) || (*(int *)(param_1 + 0x14) == 0)) ||

     (piVar2 = *(int **)(*(int *)(param_1 + 0x14) + 0x10), piVar2 == (int *)0x0)) {

    if ((*(int *)(param_1 + 0x914) == 0) || (param_3 == (int *)0x0)) goto LAB_00590fe9;

    iVar6 = (**(code **)(*param_3 + 0x1cc))();

    if ((iVar6 == 0) || (*(int *)(iVar6 + 8) == 0)) goto LAB_00590fe9;

    uVar8 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x914);

  }

  else {

    iVar6 = (**(code **)(*piVar2 + 0x1d4))();

    if (iVar6 == 0) {

      iVar6 = (**(code **)(**(int **)(*(int *)(param_1 + 0x14) + 0x10) + 0x214))();

      if (iVar6 == 0) goto LAB_00590fe9;

      iVar6 = (**(code **)(**(int **)(*(int *)(param_1 + 0x14) + 0x10) + 0x214))();

      if (*(int *)(iVar6 + 0x284) == 0) goto LAB_00590fe9;

      (**(code **)(**(int **)(*(int *)(param_1 + 0x14) + 0x10) + 0x214))();

      uVar8 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x914);

    }

    else {

      if (*(int *)(iVar6 + 0x340 + *(char *)(param_1 + 0x25c) * 4) == 0) goto LAB_00590fe9;

      uVar8 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x914);

    }

  }

  FUN_0096d550(uVar8);

LAB_00590fe9:

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x5c) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x5c))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0;

  if (((*(byte *)(param_1 + 0x90d) & 4) != 0) && (*(int *)(param_1 + 0x50) != 0)) {

    puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x54);

    *(short *)((int)puVar3 + 6) = *(short *)((int)puVar3 + 6) + -1;

    if (*(short *)((int)puVar3 + 6) == 0) {

      (**(code **)*puVar3)(1);

    }

    puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x58);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = 0;

    *(short *)((int)puVar3 + 6) = *(short *)((int)puVar3 + 6) + -1;

    if (*(short *)((int)puVar3 + 6) == 0) {

      (**(code **)*puVar3)(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = 0;

    iVar6 = 0;

    if (0 < *(int *)(*(int *)(param_1 + 0x50) + 0xc)) {

      do {

        iVar4 = *(int *)(*(int *)(param_1 + 0x50) + 8);

        iVar5 = *(int *)(iVar4 + iVar6 * 4);

        if (iVar5 != 0) {

          if (*(int *)(iVar5 + 8) == 0) {

            if (param_2 != 0) {

              FUN_004d2d60(iVar5);

            }

          }

          else {

            FUN_00561450(&param_3,*(uint32_t /* width from decompiler */ *)(iVar4 + iVar6 * 4));

          }

        }

        iVar6 = iVar6 + 1;

      } while (iVar6 < *(int *)(*(int *)(param_1 + 0x50) + 0xc));

    }

  }

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x50) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x50))(1);

  }

  iVar6 = *(int *)(param_1 + 0x260);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = 0;

  if (iVar6 != 0) {

    if (*(int *)(iVar6 + 8) == 0) {

      if (param_2 != 0) {

        FUN_004d2d60(iVar6);

      }

    }

    else {

      FUN_00561450(&param_3,iVar6);

    }

    puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x260);

    *(short *)((int)puVar3 + 6) = *(short *)((int)puVar3 + 6) + -1;

    if (*(short *)((int)puVar3 + 6) == 0) {

      (**(code **)*puVar3)(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x260) = 0;

  }

  if ((*(int *)(param_1 + 0x268) != 0) &&

     (param_3 = (int *)(*(int *)(param_1 + 0x26c) - *(int *)(param_1 + 0x268) >> 2),

     param_3 != (int *)0x0)) {

    for (uVar7 = 0;

        (iVar6 = *(int *)(param_1 + 0x268), iVar6 != 0 &&

        (uVar7 < (uint)(*(int *)(param_1 + 0x26c) - iVar6 >> 2))); uVar7 = uVar7 + 1) {

      uStack_24 = *(uint32_t /* width from decompiler */ *)(iVar6 + uVar7 * 4);

      uStack_28 = 0;

      FUN_00597e00(&uStack_28);

    }

    if (*(void **)(param_1 + 0x268) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(param_1 + 0x268));

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x268) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x26c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x270) = 0;

  }

  iVar6 = *(int *)(param_1 + 0xa4);

  if (iVar6 != 0) {

    if (*(int *)(iVar6 + 8) != 0) {

      FUN_00561450(&param_2,iVar6);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xa4) = 0;

      return;

    }

    if (param_2 != 0) {

      FUN_004d2d60(iVar6);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xa4) = 0;

  }

  return;

}
