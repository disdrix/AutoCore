// =============================================================================
// Named_CalleeOf_CVOGReaction_SpawnObject_00518370
// -----------------------------------------------------------------------------
// Stable ID: aa_00518370
// Callee of CVOGReaction_SpawnObject
// Address:   0x00518370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_SpawnObject: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~86 non-empty decompiler lines.
//  - Control keywords: if×13, return×9, do×2, while×2.
//  - Notable callees: FUN_004a16d0×3, FUN_004eb3b0×3, Client_GetMissionCompleteAudioTable×2, FUN_00723b20×2, CVOGReaction_FailMissionNotify, FUN_004b7e50, FUN_00516930, FUN_00518370.
//  - Return sites: 9.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_SpawnObject
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

void __thiscall Named_CalleeOf_CVOGReaction_SpawnObject_00518370(int *param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  uint uVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  

  iVar2 = param_1[0x55];

  param_1[0x55] = param_2;

  iVar1 = (**(code **)(*param_1 + 0x1cc))();

  if (*(int *)(param_1[0x2a] + 0x88) == 0) {

    return;

  }

  if (iVar1 == 0) {

    return;

  }

  if (*(int *)(iVar1 + 8) == 0) {

    return;

  }

  if ((param_2 == iVar2) && ((*(byte *)(param_1 + 0x61) & 4) != 0)) {

    return;

  }

  FUN_00516930(1);

  iVar2 = param_1[0x55];

  param_1[0x61] = param_1[0x61] | 4;

  if (2 < iVar2) {

    uVar4 = (uint)*(byte *)(param_1 + 0x5a);

    iVar2 = param_1[0x59];

    iVar1 = param_1[0x58];

    uVar7 = 0;

    uVar6 = 0;

    Client_GetMissionCompleteAudioTable(iVar1,iVar2,uVar4,0,0);

    FUN_00723b20(iVar1,iVar2,uVar4,uVar6,uVar7);

    return;

  }

  if (iVar2 == 0) {

    FUN_004eb3b0();

    iVar2 = FUN_004a16d0(9,1,0xffffffff);

  }

  else if (iVar2 == 1) {

    FUN_004eb3b0();

    iVar2 = FUN_004a16d0(10,1,0xffffffff);

    if (iVar2 == 0) {

      return;

    }

    piVar3 = (int *)**(int **)(iVar2 + 0x204);

    if (piVar3 != *(int **)(iVar2 + 0x204)) {

      do {

        *(uint32_t /* width from decompiler */ *)(*(int *)(piVar3[2] + 0x914) + 0x148) = 0xffffffff;

        piVar3 = (int *)*piVar3;

      } while (piVar3 != (int *)*(int *)(iVar2 + 0x204));

    }

  }

  else {

    if (iVar2 != 2) {

      return;

    }

    FUN_004eb3b0();

    iVar2 = FUN_004a16d0(0xb,1,0xffffffff);

    if (iVar2 == 0) {

      return;

    }

    piVar3 = (int *)**(int **)(iVar2 + 0x204);

    if (piVar3 != *(int **)(iVar2 + 0x204)) {

      do {

        *(uint32_t /* width from decompiler */ *)(*(int *)(piVar3[2] + 0x914) + 0x148) = 0xffffffff;

        piVar3 = (int *)*piVar3;

      } while (piVar3 != (int *)*(int *)(iVar2 + 0x204));

    }

  }

  if (iVar2 != 0) {

    (**(code **)(*param_1 + 0xf8))(iVar2,0,param_1 + 0x4d);

    CVOGReaction_FailMissionNotify(&stack0xfffffff8);

    uVar4 = (uint)*(byte *)(param_1 + 0x5a);

    iVar2 = param_1[0x59];

    iVar5 = param_1[0x58];

    uVar7 = 0;

    uVar6 = 0;

    Client_GetMissionCompleteAudioTable(iVar5,iVar2,uVar4,0,0);

    FUN_00723b20(iVar5,iVar2,uVar4,uVar6,uVar7);

    FUN_004b7e50(0,iVar1,0,0,0,0);

  }

  return;

}
