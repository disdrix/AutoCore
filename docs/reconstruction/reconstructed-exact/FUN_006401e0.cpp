// =============================================================================
// FUN_006401e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006401e0
// Address:   0x006401e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006401e0 @ 0x006401e0
// Stable ID: aa_006401e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×9, do×3, while×3, return×1.
//  - Notable callees: FUN_006418e0×13, FUN_00641860×6, FUN_0045d900×4, FUN_00638060×4, CONCAT22×3, FUN_00651d40×3, FUN_00651d50×2, FUN_00651db0×2.
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

void FUN_006401e0(int param_1)



{

  short sVar1;

  int *piVar2;

  byte bVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint uVar8;

  uint16_t extraout_var;

  int iVar9;

  uint16_t extraout_var_00;

  uint16_t extraout_var_01;

  int unaff_EBX;

  int iVar10;

  int unaff_EDI;

  int iStack_1c;

  int iStack_14;

  int iStack_c;

  int iStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  iVar6 = param_1;

  if (*(int *)(param_1 + 8) == 2) {

    piVar2 = *(int **)(param_1 + 0x14);

    uVar4 = (**(code **)(*piVar2 + 0x14))();

    uVar5 = FUN_00638060(uVar4);

    iVar10 = 0;

    iStack_c = 0;

    iStack_8 = 0;

    uStack_4 = 0x80000000;

    FUN_006327e0(&param_1,&iStack_c);

    if (0 < iStack_8) {

      do {

        (**(code **)(*piVar2 + 0x20))(*(uint32_t /* width from decompiler */ *)(iStack_c + iVar10 * 4));

        FUN_00651db0();

        iVar10 = iVar10 + 1;

      } while (iVar10 < iStack_8);

    }

    FUN_006418e0(uVar5);

    FUN_00641860(uVar4,uVar5);

    iVar10 = FUN_00638060(*(uint32_t /* width from decompiler */ *)(iVar6 + 0xc));

    FUN_006418e0(iVar10);

    FUN_00641860(*(uint32_t /* width from decompiler */ *)(iVar6 + 0xc));

    uVar5 = FUN_00638060(*(uint32_t /* width from decompiler */ *)(iVar6 + 0x10));

    FUN_006418e0(uVar5);

    FUN_00641860(*(uint32_t /* width from decompiler */ *)(iVar6 + 0x10),uVar5);

    iVar6 = (**(code **)(*piVar2 + 0x24))();

    FUN_006418e0(iVar6);

    iStack_14 = 0;

    if (0 < iVar6) {

      do {

        puVar7 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar2 + 0x20))(iStack_14);

        uVar5 = *puVar7;

        iStack_14 = FUN_00638060(uVar5);

        FUN_006418e0(iStack_14);

        FUN_00641860(uVar5,iStack_14);

        FUN_006418e0(CONCAT22(extraout_var_00,*(uint16_t *)(puVar7 + 2)));

        sVar1 = *(short *)(puVar7 + 2);

        if (sVar1 == 0x13) {

          uVar8 = FUN_00651d30();

          if ((short)uVar8 == 0x15) {

            FUN_00651d50();

            bVar3 = FUN_0045d900();

            uVar8 = (uint)bVar3 << 8 | 0x15;

          }

        }

        else if (sVar1 == 0x14) {

          uVar8 = FUN_00651d40();

        }

        else if (sVar1 == 0x15) {

          FUN_00651d50();

          bVar3 = FUN_0045d900();

          uVar8 = FUN_00651d40();

          uVar8 = uVar8 | (uint)bVar3 << 8;

        }

        else {

          uVar8 = FUN_00651d40();

        }

        FUN_006418e0(uVar8);

        FUN_006418e0(CONCAT22(extraout_var_01,*(uint16_t *)(puVar7 + 3)));

        FUN_006418e0(CONCAT22(extraout_var,*(uint16_t *)((int)puVar7 + 0xe)));

        iStack_14 = iStack_14 + 1;

      } while (iStack_14 < iVar6);

    }

    FUN_006418e0(uVar4);

    uVar4 = FUN_0045d900();

    FUN_006418e0(uVar4);

    uVar4 = FUN_0045d900();

    FUN_00641860(unaff_EDI,uVar4);

    FUN_006418e0(iVar6);

    iStack_1c = 0;

    if (0 < iVar6) {

      do {

        iVar9 = (**(code **)(*piVar2 + 0x20))(*(uint32_t /* width from decompiler */ *)(unaff_EDI + iStack_1c * 4));

        puVar7 = (uint32_t /* width from decompiler */ *)((uint)*(ushort *)(iVar9 + 0xe) + iVar10);

        iVar9 = FUN_00651db0();

        iVar9 = puVar7[1] * iVar9;

        FUN_006418e0(iVar9);

        FUN_00641860(*puVar7,iVar9);

        iStack_1c = iStack_1c + 1;

      } while (iStack_1c < iVar6);

    }

    if (-1 < unaff_EBX) {

      (**(code **)(*DAT_00b05060 + 0x14))(unaff_EDI,unaff_EBX * 4,0x12);

    }

  }

  return;

}
