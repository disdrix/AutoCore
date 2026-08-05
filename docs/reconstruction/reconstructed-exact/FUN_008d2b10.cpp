// =============================================================================
// FUN_008d2b10
// -----------------------------------------------------------------------------
// Stable ID: aa_008d2b10
// Address:   0x008d2b10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d2b10 @ 0x008d2b10
// Stable ID: aa_008d2b10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~191 non-empty decompiler lines.
//  - Control keywords: if×22, return×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×8, FUN_00410050×3, FUN_0051ffb0×3, FUN_008d1890×3, FUN_0096c450×3, FUN_00424830×2, FUN_00521b40, FUN_008d2b10.
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

void FUN_008d2b10(void)



{

  ushort uVar1;

  ushort uVar2;

  char cVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  uint uVar7;

  int unaff_EDI;

  uint8_t auStack_34 [4];

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint8_t **ppuStack_28;

  uint8_t *local_18;

  uint32_t /* width from decompiler */ uStack_14;

  int iStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b0410;

  local_c = ExceptionList;

  local_18 = (uint8_t *)0xffffffff;

  if (*(int *)(unaff_EDI + 0x544) != 0) {

    ExceptionList = &local_c;

    if (*(int **)(unaff_EDI + 0x760) != (int *)0x0) {

      ppuStack_28 = (uint8_t **)0x8d2b61;

      ExceptionList = &local_c;

      iVar4 = (**(code **)(**(int **)(unaff_EDI + 0x760) + 700))();

      if (iVar4 != 0) {

        ppuStack_28 = (uint8_t **)0x8d2b77;

        piVar5 = (int *)(**(code **)(**(int **)(unaff_EDI + 0x760) + 700))();

        iVar4 = *(int *)(*piVar5 + 0x1c);

        iStack_10 = *(int *)(*piVar5 + 0x20);

        ppuStack_28 = (uint8_t **)0x8d2b88;

        iVar6 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar6 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar6 + 0xc) = 0;

        }

        uVar1 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);

        *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;

        ppuStack_28 = (uint8_t **)0x8d2bae;

        iVar6 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar6 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar6 + 0xc) = 0;

        }

        uVar2 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);

        *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;

        iStack_10 = (int)((longlong)(ulonglong)uVar1 % (longlong)iStack_10);

        uStack_14 = (uint32_t /* width from decompiler */)((longlong)(ulonglong)uVar2 % (longlong)iVar4);

        ppuStack_28 = (uint8_t **)0x8d2bf0;

        piVar5 = (int *)(**(code **)(**(int **)(unaff_EDI + 0x760) + 700))();

        if (*piVar5 != 0) {

          ppuStack_28 = &local_18;

          uStack_2c = 0x8d2c04;

          cVar3 = FUN_0096c450();

          if (cVar3 != '\0') {

            ppuStack_28 = (uint8_t **)((uint)local_18 | 0xff000000);

            uStack_2c = 2;

            uStack_30 = 0x8d2c20;

            FUN_0051ffb0();

          }

        }

      }

    }

    if (*(int **)(unaff_EDI + 0x764) != (int *)0x0) {

      ppuStack_28 = (uint8_t **)0x8d2c36;

      iVar4 = (**(code **)(**(int **)(unaff_EDI + 0x764) + 700))();

      if (iVar4 != 0) {

        ppuStack_28 = (uint8_t **)0x8d2c4c;

        piVar5 = (int *)(**(code **)(**(int **)(unaff_EDI + 0x764) + 700))();

        iVar4 = *(int *)(*piVar5 + 0x1c);

        iStack_10 = *(int *)(*piVar5 + 0x20);

        ppuStack_28 = (uint8_t **)0x8d2c5d;

        iVar6 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar6 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar6 + 0xc) = 0;

        }

        uVar1 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);

        *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;

        ppuStack_28 = (uint8_t **)0x8d2c83;

        iVar6 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar6 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar6 + 0xc) = 0;

        }

        uVar2 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);

        *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;

        iStack_10 = (int)((longlong)(ulonglong)uVar1 % (longlong)iStack_10);

        uStack_14 = (uint32_t /* width from decompiler */)((longlong)(ulonglong)uVar2 % (longlong)iVar4);

        ppuStack_28 = (uint8_t **)0x8d2cc5;

        piVar5 = (int *)(**(code **)(**(int **)(unaff_EDI + 0x764) + 700))();

        if (*piVar5 != 0) {

          ppuStack_28 = &local_18;

          uStack_2c = 0x8d2cd9;

          cVar3 = FUN_0096c450();

          if (cVar3 != '\0') {

            ppuStack_28 = (uint8_t **)((uint)local_18 | 0xff000000);

            uStack_2c = 0;

            uStack_30 = 0x8d2cf5;

            FUN_0051ffb0();

          }

        }

      }

    }

    if (*(int **)(unaff_EDI + 0x768) != (int *)0x0) {

      ppuStack_28 = (uint8_t **)0x8d2d0b;

      iVar4 = (**(code **)(**(int **)(unaff_EDI + 0x768) + 700))();

      if (iVar4 != 0) {

        ppuStack_28 = (uint8_t **)0x8d2d21;

        piVar5 = (int *)(**(code **)(**(int **)(unaff_EDI + 0x768) + 700))();

        iVar4 = *(int *)(*piVar5 + 0x1c);

        iStack_10 = *(int *)(*piVar5 + 0x20);

        ppuStack_28 = (uint8_t **)0x8d2d32;

        iVar6 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar6 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar6 + 0xc) = 0;

        }

        uVar1 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);

        *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;

        ppuStack_28 = (uint8_t **)0x8d2d58;

        iVar6 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar6 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar6 + 0xc) = 0;

        }

        uVar2 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);

        *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;

        iStack_10 = (int)((longlong)(ulonglong)uVar1 % (longlong)iStack_10);

        uStack_14 = (uint32_t /* width from decompiler */)((longlong)(ulonglong)uVar2 % (longlong)iVar4);

        ppuStack_28 = (uint8_t **)0x8d2d9a;

        piVar5 = (int *)(**(code **)(**(int **)(unaff_EDI + 0x768) + 700))();

        if (*piVar5 != 0) {

          ppuStack_28 = &local_18;

          uStack_2c = 0x8d2dae;

          cVar3 = FUN_0096c450();

          if (cVar3 != '\0') {

            ppuStack_28 = (uint8_t **)((uint)local_18 | 0xff000000);

            uStack_2c = 1;

            uStack_30 = 0x8d2dca;

            FUN_0051ffb0();

          }

        }

      }

    }

    ppuStack_28 = (uint8_t **)0x8d2dd5;

    FUN_00521b40();

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x86c) = 0;

    piVar5 = *(int **)(unaff_EDI + 0x880);

    if (((piVar5 != (int *)0x0) &&

        (local_18 = (uint8_t *)(*(int *)(unaff_EDI + 0x884) - (int)piVar5 >> 2),

        local_18 != (uint8_t *)0x0)) && (*(int *)(*piVar5 + 0x90) != 0)) {

      ppuStack_28 = (uint8_t **)0x8d2e0a;

      CVOGReaction_RandomUnitScalar();

      piVar5 = *(int **)(unaff_EDI + 0x880);

      ppuStack_28 = (uint8_t **)0x8d2e18;

      uVar7 = FUN_00424830();

      *(uint *)(unaff_EDI + 0x860) = uVar7 % *(uint *)(*piVar5 + 0x90) + 1;

    }

    if (*(int *)(unaff_EDI + 0x8c0) == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = *(int *)(unaff_EDI + 0x8c4) - *(int *)(unaff_EDI + 0x8c0) >> 2;

    }

    if ((*(int *)(unaff_EDI + 0x81c) < iVar4) &&

       (*(int *)(*(int *)(*(int *)(unaff_EDI + 0x8c0) + *(int *)(unaff_EDI + 0x81c) * 4) + 0x90) !=

        0)) {

      ppuStack_28 = (uint8_t **)0x8d2e68;

      CVOGReaction_RandomUnitScalar();

      iVar4 = *(int *)(unaff_EDI + 0x81c);

      iVar6 = *(int *)(unaff_EDI + 0x8c0);

      ppuStack_28 = (uint8_t **)0x8d2e7c;

      uVar7 = FUN_00424830();

      *(uint *)(unaff_EDI + 0x870) = uVar7 % *(uint *)(*(int *)(iVar6 + iVar4 * 4) + 0x90) + 1;

    }

    local_18 = auStack_34;

    FUN_00410050(auStack_34);

    uStack_4 = 0xffffffff;

    FUN_008d1890(0,0);

    local_18 = auStack_34;

    FUN_00410050(auStack_34);

    uStack_4 = 0xffffffff;

    FUN_008d1890(-(*(int *)(unaff_EDI + 0x5a4) != 1) & 3,0);

    local_18 = auStack_34;

    FUN_00410050(auStack_34);

    uStack_4 = 0xffffffff;

    FUN_008d1890(4,0);

  }

  ExceptionList = local_c;

  return;

}
