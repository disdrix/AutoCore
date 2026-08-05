// =============================================================================
// FUN_0098d660
// -----------------------------------------------------------------------------
// Stable ID: aa_0098d660
// Address:   0x0098d660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0098d660 @ 0x0098d660
// Stable ID: aa_0098d660
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, for×1.
//  - Notable callees: FUN_0074f360×2, FUN_0074fca0×2, FUN_0074f200, FUN_0074fba0, FUN_0098d660.
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

uint32_t /* width from decompiler */ __fastcall FUN_0098d660(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  int iVar8;

  

  if ((*(int *)(param_1 + 0xc) != 0) &&

     (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc) >> 2 != 0)) {

    iVar2 = *(int *)(*(int *)(param_1 + 0x20) + 8);

    FUN_0074fca0(2);

    iVar3 = *(int *)(iVar2 + 0x28);

    if (-1 < *(int *)(&DAT_00afe00c + iVar3 * 0xc)) {

      (**(code **)(**(int **)(iVar2 + 0xc) + 0x108))(*(int **)(iVar2 + 0xc));

    }

    (**(code **)(**(int **)(iVar2 + 0xc) + 0x100))(*(int **)(iVar2 + 0xc),0);

    *(uint32_t /* width from decompiler */ *)(&DAT_00afe00c + iVar3 * 0xc) = 0;

    iVar2 = *(int *)(param_1 + 0x18);

    piVar4 = *(int **)(param_1 + 0x10);

    iVar3 = *(int *)(iVar2 + 8);

    iVar8 = 0;

    for (piVar7 = *(int **)(param_1 + 0xc); piVar7 != piVar4; piVar7 = piVar7 + 1) {

      iVar5 = *(int *)(*piVar7 + 8);

      if (iVar5 != iVar8) {

        FUN_0074fba0(iVar5);

        FUN_0074fca0(2);

        iVar8 = *(int *)(iVar3 + 0x28);

        if (-1 < *(int *)(&DAT_00afe00c + iVar8 * 0xc)) {

          (**(code **)(**(int **)(iVar3 + 0xc) + 0x108))(*(int **)(iVar3 + 0xc));

        }

        (**(code **)(**(int **)(iVar3 + 0xc) + 0x100))(*(int **)(iVar3 + 0xc),0);

        *(uint32_t /* width from decompiler */ *)(&DAT_00afe00c + iVar8 * 0xc) = 0;

        FUN_0074f200(*(uint32_t /* width from decompiler */ *)(iVar2 + 0xc));

        iVar6 = DAT_00d1f614;

        iVar8 = iVar5;

        if (DAT_00d1f614 != 0) {

          piVar1 = (int *)(DAT_00d1f614 + 0xd8 + *(int *)(DAT_00d1f614 + 0xc4) * 0x4c);

          *piVar1 = *piVar1 + 1;

          piVar1 = (int *)(iVar6 + 0xd4 + *(int *)(iVar6 + 0xc4) * 0x4c);

          *piVar1 = *piVar1 + 1;

        }

      }

      (**(code **)(**(int **)*piVar7 + 8))((uint32_t /* width from decompiler */ *)*piVar7);

    }

    FUN_0074f360();

    FUN_0074f360();

    return 0;

  }

  return 1;

}
