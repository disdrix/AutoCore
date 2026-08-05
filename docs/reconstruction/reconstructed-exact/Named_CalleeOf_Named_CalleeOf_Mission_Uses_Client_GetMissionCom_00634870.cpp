// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom_00634870
// -----------------------------------------------------------------------------
// Stable ID: aa_00634870
// Callee of Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable
// Address:   0x00634870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~180 non-empty decompiler lines.
//  - Control keywords: if×17, return×2.
//  - Notable callees: FUN_00404d80×2, FUN_00448fc0×2, FUN_00972e50×2, FUN_0044bb80, FUN_004b4ad0, FUN_004b4cc0, FUN_00634870, FUN_00634e00.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom_00634870(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,int *param_3)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ uVar4;

  void *pvVar5;

  int *piVar6;

  int iVar7;

  int local_44;

  int local_3c;

  int local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  pvVar5 = ExceptionList;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a8c76;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = param_2;

  param_1[1] = 0;

  param_1[2] = 0;

  iVar2 = param_3[0x37];

  param_1[3] = iVar2;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[7] = 0;

  if (iVar2 != 0) {

    local_3c = 0;

    local_38 = 0;

    local_34 = 0;

    local_30 = 0;

    local_2c = 0;

    local_28 = 0;

    local_24 = 0;

    local_20 = 4;

    local_1c = 4;

    local_18 = 0;

    local_14 = 0;

    local_10 = 0;

    *(uint *)(iVar2 + 0xbc) = *(uint *)(iVar2 + 0xbc) | 1;

    piVar6 = (int *)(iVar2 + 0x14);

    if (((*(int *)(iVar2 + 0x14) != 0) && (1 < *(int *)(*(int *)(iVar2 + 0x14) + 4))) &&

       (iVar2 = FUN_0099a6b0(0), iVar2 != 0)) {

      FUN_0044bb80(*piVar6);

      FUN_00448fc0(iVar2);

    }

    iVar2 = *(int *)(param_1[3] + 0xc);

    piVar3 = (int *)(param_1[3] + 0xc);

    if (((iVar2 != 0) && (1 < *(int *)(iVar2 + 4))) && (iVar2 = FUN_00988d10(0), iVar2 != 0)) {

      FUN_00634e00(*piVar3);

      FUN_00448fc0(iVar2);

    }

    if (*piVar6 == 0) {

      local_44 = 0;

    }

    else {

      local_44 = *(int *)(*piVar6 + 0x18);

    }

    if (*piVar3 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = *(int *)(*piVar3 + 0x1c);

    }

    local_34 = FUN_007468b0();

    local_38 = iVar2 / 3;

    local_24 = 2;

    local_10 = 1;

    local_3c = local_44;

    local_30 = 6;

    iVar1 = *piVar6;

    if (*(int *)(iVar1 + 0x10) == 0) {

      local_2c = 0;

    }

    else {

      if (local_44 < 1) {

        local_44 = *(int *)(iVar1 + 0x18);

      }

      local_2c = FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x14),local_44,0);

    }

    iVar1 = *piVar3;

    if (*(int *)(iVar1 + 0x10) == 0) {

      local_28 = 0;

    }

    else {

      iVar7 = iVar2;

      if (iVar2 < 1) {

        iVar7 = *(int *)(iVar1 + 0x1c);

      }

      local_28 = FUN_00743be0(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x18),iVar7,0x800);

    }

    uVar4 = FUN_004b4cc0(&local_3c);

    param_1[1] = uVar4;

    if (*(int *)(*piVar3 + 0x10) != 0) {

      FUN_00743ba0();

    }

    if (*(int *)(*piVar6 + 0x10) != 0) {

      FUN_007464e0();

    }

    if (param_1[1] != 0) {

      *param_3 = param_1[1];

      pvVar5 = operator_new__(iVar2 * 0x24);

      local_4 = 0;

      if (pvVar5 == (void *)0x0) {

        pvVar5 = (void *)0x0;

      }

      else {

        FUN_00404d80(pvVar5,0xc,iVar2 * 3,FUN_005edf20);

      }

      local_4 = 0xffffffff;

      param_1[4] = pvVar5;

      pvVar5 = operator_new__(iVar2 * 0x24);

      local_4 = 1;

      if (pvVar5 == (void *)0x0) {

        pvVar5 = (void *)0x0;

      }

      else {

        FUN_00404d80(pvVar5,0xc,iVar2 * 3,FUN_005edf20);

      }

      local_4 = 0xffffffff;

      param_1[5] = pvVar5;

      pvVar5 = operator_new__(iVar2 * 4);

      param_1[7] = pvVar5;

      param_1[6] = 0;

      param_1[8] = 0;

      param_3[0x1e] = param_1[4];

      param_3[0x1f] = param_1[5];

      param_3[0x20] = 0xc;

      param_3[0x21] = 0xc;

      param_3[0x22] = iVar2 * 3;

      param_3[0x23] = (int)(param_1 + 6);

      param_3[0x24] = param_1[7];

      param_3[0x25] = 4;

      param_3[0x26] = iVar2;

      param_3[0x27] = (int)(param_1 + 8);

      piVar6 = (int *)param_1[3];

      if (((piVar6[0x16] != 0) && (piVar6[0x17] != 0)) &&

         (*(int *)(piVar6[0x17] + 0x1c) != piVar6[0x18])) {

        (**(code **)(*piVar6 + 0x80))();

      }

      piVar6 = (int *)piVar6[0x19];

      if (piVar6 != (int *)0x0) {

        if (((*(byte *)(piVar6 + 0x2f) & 1) != 0) &&

           (FUN_00972e50(), (*(byte *)(piVar6 + 0x2f) & 1) != 0)) {

          piVar6 = (int *)FUN_00972e50();

        }

        param_3[1] = *piVar6;

        param_3[2] = piVar6[4];

        param_3[3] = piVar6[8];

        param_3[4] = piVar6[1];

        param_3[5] = piVar6[5];

        param_3[6] = piVar6[9];

        param_3[7] = piVar6[2];

        param_3[8] = piVar6[6];

        param_3[9] = piVar6[10];

        param_3[10] = piVar6[0xc];

        param_3[0xb] = piVar6[0xd];

        param_3[0xc] = piVar6[0xe];

      }

      *(byte *)((int)param_3 + 0xcd) = *(byte *)((int)param_3 + 0xcd) | 0x20;

      FUN_004b4ad0(param_1 + 2,param_3);

    }

    ExceptionList = local_c;

    return param_1;

  }

  ExceptionList = pvVar5;

  return param_1;

}
