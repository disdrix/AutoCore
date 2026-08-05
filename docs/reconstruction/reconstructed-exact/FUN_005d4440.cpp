// =============================================================================
// FUN_005d4440
// -----------------------------------------------------------------------------
// Stable ID: aa_005d4440
// Address:   0x005d4440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d4440 @ 0x005d4440
// Stable ID: aa_005d4440
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×18, goto×4, return×3.
//  - Notable callees: FUN_0055dfb0×5, CVOGHBAI_CreateByAICode×2, FUN_00404d40×2, FUN_00560f30, FUN_00560f70, FUN_00561580, FUN_005617c0, FUN_005d4370.
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

void __thiscall FUN_005d4440(int param_1,int param_2)



{

  bool bVar1;

  bool bVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  uint32_t /* width from decompiler */ uVar7;

  float10 fVar8;

  int iStack_5c;

  uint8_t auStack_54 [16];

  uint8_t auStack_44 [4];

  uint8_t auStack_40 [60];

  

  iStack_5c = (**(code **)(**(int **)(param_1 + 0x3c) + 0x18))();

  if (iStack_5c == param_2) {

    return;

  }

  if ((param_2 == 7) || (bVar1 = true, param_2 == 6)) {

    bVar1 = false;

  }

  if ((iStack_5c == 7) || (bVar2 = true, iStack_5c == 6)) {

    bVar2 = false;

  }

  if (((bVar1) && (!bVar2)) && (iVar3 = FUN_0055dfb0(), iVar3 == 0)) {

    return;

  }

  iVar3 = *(int *)(param_1 + 8);

  FUN_005d4370(0x10);

  if (iVar3 != 0) {

    if (iStack_5c == 7) {

      FUN_005617c0(param_1,auStack_54);

    }

    if (param_2 == 7) {

      FUN_00561580(param_1);

    }

  }

  if (bVar1) {

    if (!bVar2) {

      piVar6 = *(int **)(param_1 + 0x3c);

      piVar5 = (int *)FUN_0055dfb0();

      *(int **)(param_1 + 0x3c) = piVar5;

      iVar4 = (**(code **)(*piVar5 + 0x18))();

      if ((iVar4 != param_2) && (param_2 != 1)) {

        piVar5 = *(int **)(param_1 + 0x3c);

        (**(code **)(*piVar5 + 0x24))(auStack_40);

        fVar8 = (float10)FUN_00404d40(auStack_44,piVar5 + 8);

        iVar4 = CVOGHBAI_CreateByAICode(param_2,(float)fVar8);

        *(int *)(iVar4 + 0x14) = piVar5[5];

        *(int *)(iVar4 + 0x18) = piVar5[6];

        *(int *)(param_1 + 0x3c) = iVar4;

        (**(code **)*piVar5)(1);

      }

      (**(code **)(*piVar6 + 0x78))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x3c));

      (**(code **)(*piVar6 + 0x7c))(0);

      (**(code **)*piVar6)(1);

      goto LAB_005d46ae;

    }

    if (param_2 == 1) goto LAB_005d46ae;

    piVar5 = *(int **)(param_1 + 0x3c);

    (**(code **)(*piVar5 + 0x24))(auStack_40);

    fVar8 = (float10)FUN_00404d40(auStack_44,piVar5 + 8);

    iVar4 = CVOGHBAI_CreateByAICode(param_2,(float)fVar8);

    (**(code **)(*piVar5 + 0x78))(iVar4);

    *(int *)(iVar4 + 0x14) = piVar5[5];

    *(int *)(iVar4 + 0x18) = piVar5[6];

    *(int *)(param_1 + 0x3c) = iVar4;

  }

  else {

    if (param_2 == 7) {

      iVar4 = (**(code **)(*DAT_00b05060 + 0x10))();

      *(uint16_t *)(iVar4 + 4) = 0xd0;

      piVar6 = (int *)CVOGHBAIBase_Default_ctor

                                (*(int *)(param_1 + 0x3c) + 0xb0,*(int *)(param_1 + 0x3c) + 0x30);

    }

    else {

      iVar4 = (**(code **)(*DAT_00b05060 + 0x10))(0xd0,0x29);

      *(uint16_t *)(iVar4 + 4) = 0xd0;

      piVar6 = (int *)CVOGHBAIWalkingCreatureTurreted_ctor

                                (*(int *)(param_1 + 0x3c) + 0xb0,*(int *)(param_1 + 0x3c) + 0x30);

    }

    if (bVar2) {

      (**(code **)(*piVar6 + 0x7c))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x3c));

      *(int **)(param_1 + 0x3c) = piVar6;

      goto LAB_005d46ae;

    }

    piVar5 = *(int **)(param_1 + 0x3c);

    iVar4 = FUN_0055dfb0();

    if (iVar4 != 0) {

      iVar4 = *piVar5;

      uVar7 = FUN_0055dfb0();

      (**(code **)(iVar4 + 0x78))(uVar7);

      iStack_5c = *piVar6;

      uVar7 = FUN_0055dfb0();

      (**(code **)(iStack_5c + 0x7c))(uVar7);

    }

    *(int **)(param_1 + 0x3c) = piVar6;

    if (piVar5 == (int *)0x0) goto LAB_005d46ae;

  }

  (**(code **)*piVar5)(1);

LAB_005d46ae:

  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x3c) + 0x60;

  *(bool *)(param_1 + 0x40) = param_2 == 7;

  if (iVar3 != 0) {

    if (iStack_5c == 7) {

      FUN_00560f70(param_1,auStack_54);

    }

    if (param_2 == 7) {

      FUN_00560f30(param_1);

    }

  }

  FUN_005d43e0();

  return;

}
