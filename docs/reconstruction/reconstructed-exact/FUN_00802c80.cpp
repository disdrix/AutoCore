// =============================================================================
// FUN_00802c80
// -----------------------------------------------------------------------------
// Stable ID: aa_00802c80
// Address:   0x00802c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00802c80 @ 0x00802c80
// Stable ID: aa_00802c80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×15, return×7.
//  - Notable callees: FUN_00578270×8, FUN_0051f3b0, FUN_008028e0, FUN_00802c80, FUN_0083cdb0, FUN_0087d810, __RTDynamicCast.
//  - Return sites: 7.

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

void FUN_00802c80(int param_1)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  

  if (((param_1 != 0) && (DAT_00d1b6d8 != 0)) && (*(int **)(param_1 + 0x18) != (int *)0x0)) {

    iVar2 = (**(code **)(**(int **)(param_1 + 0x18) + 0x1dc))();

    if ((iVar2 == DAT_00d1b6d8) ||

       (iVar2 = *(int *)(DAT_00d1b6d8 + 0x250),

       iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 0x1d4))(), iVar3 == iVar2)) {

      if ((DAT_00d1b8b8 != (int *)0x0) &&

         (cVar1 = (**(code **)(*DAT_00d1b8b8 + 0x3d8))(), cVar1 != '\0')) {

        FUN_0087d810(DAT_00d1b8b8);

      }

      if (((*(byte *)(param_1 + 0x639) & 1) != 0) && (iVar2 = FUN_00578270(), iVar2 != 0)) {

        piVar4 = (int *)FUN_00578270();

        iVar2 = (**(code **)(*piVar4 + 0x1dc))();

        if (iVar2 == DAT_00d1b6d8) {

          return;

        }

        piVar4 = (int *)FUN_00578270();

        iVar2 = *(int *)(DAT_00d1b6d8 + 0x250);

        iVar3 = (**(code **)(*piVar4 + 0x1d4))();

        if (iVar3 == iVar2) {

          return;

        }

        iVar2 = *(int *)(DAT_00d1b6d8 + 0x250);

        if (iVar2 == 0) {

          iVar2 = 0;

        }

        else {

          iVar2 = *(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2;

        }

        iVar3 = FUN_00578270();

        if (*(int *)(iVar3 + 0xac) == iVar2) {

          return;

        }

        if (DAT_00d1b6d8 == 0) {

          iVar2 = 0;

        }

        else {

          iVar2 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8;

        }

        iVar3 = FUN_00578270();

        if (*(int *)(iVar3 + 0xac) == iVar2) {

          return;

        }

      }

      cVar1 = FUN_0051f3b0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x620));

      if (((cVar1 == '\0') && (DAT_00d1b8ec != 0)) && (*(int *)(DAT_00d1b8ec + 0x590) != 0)) {

        FUN_0083cdb0(*(int *)(DAT_00d1b8ec + 0x590),param_1,0);

      }

    }

    else if ((*(char *)(param_1 + 0xfe) != '\0') && (iVar2 = FUN_00578270(), iVar2 != 0)) {

      piVar4 = (int *)FUN_00578270();

      iVar2 = (**(code **)(*piVar4 + 0x1dc))();

      if (iVar2 != DAT_00d1b6d8) {

        piVar4 = (int *)FUN_00578270();

        iVar2 = *(int *)(DAT_00d1b6d8 + 0x250);

        iVar3 = (**(code **)(*piVar4 + 0x1d4))();

        if (iVar3 != iVar2) {

          return;

        }

      }

      iVar2 = __RTDynamicCast(param_1,0,&CVOGHBSkillBase::RTTI_Type_Descriptor,

                              &CVOGHBSkill_SummonSnoop::RTTI_Type_Descriptor,0);

      if (iVar2 == 0) {

        FUN_008028e0(param_1);

        return;

      }

    }

  }

  return;

}
