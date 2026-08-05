// =============================================================================
// Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_00590240
// -----------------------------------------------------------------------------
// Stable ID: aa_00590240
// Callee of Mission_Uses_Client_GetMissionCompleteAudioTable
// Address:   0x00590240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Uses_Client_GetMissionCompleteAudioTable: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~95 non-empty decompiler lines.
//  - Control keywords: if×8, do×1, while×1, return×1.
//  - Notable callees: FUN_0040d1a0, FUN_00590240, FUN_005962a0, FUN_00597280, FUN_00634840, FUN_00634870.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_Uses_Client_GetMissionCompleteAudioTable
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

void __thiscall Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_00590240(char *param_1,uint32_t /* width from decompiler */ *param_2,int param_3)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  float fVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iStack_f4;

  void *pvStack_f0;

  uint8_t auStack_ec [204];

  uint32_t /* width from decompiler */ uStack_20;

  int iStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  int iStack_4;

  

  iStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a5886;

  pvStack_c = ExceptionList;

  iVar3 = 0;

  ExceptionList = &pvStack_c;

  if ((*(int **)(param_1 + 0x914) != (int *)0x0) && (ExceptionList = &pvStack_c, *param_1 == '\0'))

  {

    uVar5 = 3;

    ExceptionList = &pvStack_c;

    iVar2 = (**(code **)(**(int **)(param_1 + 0x914) + 0x10))(3);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0xbc) = 0xffffffff;

    *(int *)(iVar2 + 0xb4) = *(int *)(iVar2 + 0xb4) + 1;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x90) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x824);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x94) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x828);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x98) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x82c);

    (**(code **)(**(int **)(param_1 + 0x914) + 0x10))(3,param_2);

    FUN_0040d1a0(uVar5);

  }

  param_1[0x854] = '\0';

  param_1[0x855] = '\0';

  param_1[0x856] = '\0';

  param_1[0x857] = '\0';

  param_1[0x858] = '\0';

  param_1[0x859] = '\0';

  param_1[0x85a] = '\0';

  param_1[0x85b] = '\0';

  param_1[0x85c] = '\0';

  param_1[0x85d] = '\0';

  param_1[0x85e] = '\0';

  param_1[0x85f] = '\0';

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x894) = *param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x898) = param_2[1];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x89c) = param_2[2];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8a0) = param_2[3];

  fVar4 = g_flOne;

  if (((param_3 != 0) && (*(int **)(param_3 + 8) != (int *)0x0)) && ((param_1[0x90f] & 0x80U) == 0))

  {

    iVar2 = (**(code **)(**(int **)(param_3 + 8) + 0xc))();

    fVar4 = *(float *)(iVar2 + 0x9c);

  }

  *(float *)(param_1 + 0x8d8) = fVar4;

  if ((param_1[0x90d] & 2U) != 0) {

    piVar1 = *(int **)(param_1 + 0x914);

    (**(code **)(*piVar1 + 0x34))();

    if (piVar1[0x30] == 0) {

      iStack_f4 = 0;

    }

    else {

      iStack_f4 = piVar1[0x31] - piVar1[0x30] >> 2;

    }

    if (0 < iStack_f4) {

      do {

        iVar2 = *(int *)(piVar1[0x30] + iVar3 * 4);

        if (iVar2 != 0) {

          FUN_005962a0(param_1 + 0xe4);

          iStack_4 = 0;

          uStack_20 = 0x60;

          iStack_10 = iVar2;

          pvStack_f0 = operator_new(0x24);

          iStack_4._0_1_ = 1;

          if (pvStack_f0 == (void *)0x0) {

            pvStack_f0 = (void *)0x0;

          }

          else {

            pvStack_f0 = (void *)FUN_00634870(DAT_00b036d4,auStack_ec);

          }

          iStack_4 = (uint)iStack_4._1_3_ << 8;

          if (pvStack_f0 != (void *)0x0) {

            FUN_00597280(&pvStack_f0);

          }

          iStack_4 = 0xffffffff;

          FUN_00634840();

        }

        iVar3 = iVar3 + 1;

      } while (iVar3 < iStack_f4);

    }

  }

  ExceptionList = pvStack_c;

  return;

}
