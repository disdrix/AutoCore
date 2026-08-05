// =============================================================================
// Named_CalleeOf_Mission_after_CVOGRegionMissions_005e0610
// -----------------------------------------------------------------------------
// Stable ID: aa_005e0610
// Callee of Mission_after_CVOGRegionMissions
// Address:   0x005e0610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_after_CVOGRegionMissions: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×10, return×2.
//  - Notable callees: CVOGReaction_FailMissionNotify×2, CONCAT31, FUN_00418b80, FUN_004f1e20, FUN_005e0480, FUN_005e0610, FUN_005e18d0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Mission_after_CVOGRegionMissions
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_CalleeOf_Mission_after_CVOGRegionMissions_005e0610(int param_1,int param_2,int param_3,int param_4)



{

  short sVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  uint64_t uVar6;

  uint32_t /* width from decompiler */ uStack_1c;

  int iStack_18;

  uint8_t auStack_14 [4];

  uint uStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  uint uStack_8;

  uint uStack_4;

  

  iStack_18 = (**(code **)(**(int **)(param_2 + 0x3c) + 0x14))();

  iVar5 = *(int *)(param_2 + 0x38);

  uVar2 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x34);

  sVar1 = *(short *)(*(int *)(param_2 + 0x3c) + 0x4b8);

  uStack_1c = uVar2;

  if (*(int *)(param_2 + 0x3c) == 0) {

    FUN_004f1e20(0,1);

  }

  iVar3 = *(int *)(param_2 + 0x3c);

  if (iVar3 != 0) {

    if (*(short *)(iVar3 + 0x3f4) == 0xb) {

      param_2 = 0x46;

    }

    else if (*(short *)(iVar3 + 0x3f4) == 10) {

      param_2 = 0x44;

    }

    else {

      param_2 = iVar5;

      if ((((iVar5 == 0xc) &&

           (piVar4 = (int *)FUN_00418b80(auStack_14,&uStack_1c), *piVar4 == *(int *)(param_1 + 4)))

          && ((*(byte *)(iVar3 + 0x536) & 4) == 0)) && (*(byte *)(iVar3 + 0x535) != 0)) {

        uStack_8 = (uint)*(byte *)(iVar3 + 0x535);

        uStack_10 = CONCAT31(uStack_10._1_3_,*(byte *)(iVar3 + 0x536) >> 1) & 0xffffff01;

        uStack_4 = uStack_10;

        uStack_c = uVar2;

        FUN_005e18d0(auStack_14,&uStack_c);

      }

    }

    if ((iStack_18 != -1) || (param_2 != 0xe)) {

      uVar6 = FUN_005e0480(param_2);

      if (-1 < (int)uVar6) {

        iVar5 = 0;

        if (0 < param_3) {

          iVar5 = param_3 + -1;

        }

        piVar4 = (int *)(param_1 + 0x13ce0c + (int)((ulonglong)uVar6 >> 0x20) * 4);

        *piVar4 = *piVar4 + 1;

        piVar4 = (int *)(param_1 + 0x13ce1c + iVar5 * 4);

        *piVar4 = *piVar4 + 1;

        piVar4 = (int *)(param_1 + 0x13cf5c + (int)uVar6 * 4);

        *piVar4 = *piVar4 + 1;

        piVar4 = (int *)(param_1 + 0x13cf8c + sVar1 * 4);

        *piVar4 = *piVar4 + 1;

        if (param_4 == 0) {

          CVOGReaction_FailMissionNotify(&uStack_1c);

        }

        else if (param_4 == 1) {

          CVOGReaction_FailMissionNotify(&uStack_1c);

          return;

        }

      }

    }

  }

  return;

}
