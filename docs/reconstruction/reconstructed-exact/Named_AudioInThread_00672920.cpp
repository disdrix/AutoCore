// READABILITY (auto CF):
//  - Body size: ~132 non-empty decompiler lines.
//  - Control keywords: if×11, goto×5, return×2, switch×1.
//  - Notable callees: case×5, FUN_0076cec0×4, vog_LogMessage×2, CONCAT22, FUN_00671fe0, FUN_006725b0, FUN_00672920, FUN_006775d0.
//  - Strings: "Unknown codec type."; "Unable to create codec %d"; "Couldnt create capture sound buffer"; "Couldnt start capture".
//  - Return sites: 2.

// =============================================================================
// Named_AudioInThread_00672920
// -----------------------------------------------------------------------------
// Stable ID: aa_00672920
// Address:   0x00672920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "AudioInThread"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall

Named_AudioInThread_00672920(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,short param_4,uint32_t /* width from decompiler */ param_5,

            uint param_6,void *param_7)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  float fVar3;

  ushort uVar4;

  int *piVar5;

  int iVar6;

  void *pvVar7;

  uint32_t /* width from decompiler */ uVar8;

  ushort in_FPUControlWord;

  uint32_t /* width from decompiler */ uVar9;

  void *pvStack_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &DAT_009a9279;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x15c) != (uint32_t /* width from decompiler */ *)0x0) {

    ExceptionList = &pvStack_c;

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x15c))(1);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x15c) = 0;

  }

  if (*(void **)(param_1 + 0x160) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x160));

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x160) = 0;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x968) = 0;

  FUN_006725b0();

  uVar8 = param_7;

  switch(param_7) {

  case (void *)0x0:

    param_7 = operator_new(0x30);

    uStack_4 = 0;

    if (param_7 == (void *)0x0) {

LAB_00672a4f:

      piVar5 = (int *)0x0;

    }

    else {

      piVar5 = (int *)FUN_00678b90(0);

    }

    break;

  case (void *)0x1:

    param_7 = operator_new(0x98);

    uStack_4 = 1;

    if (param_7 == (void *)0x0) goto LAB_00672a4f;

    piVar5 = (int *)FUN_006775d0(0);

    break;

  case (void *)0x2:

    param_7 = operator_new(0x98);

    uStack_4 = 2;

    if (param_7 == (void *)0x0) goto LAB_00672a4f;

    piVar5 = (int *)FUN_00678520(0);

    break;

  case (void *)0x3:

    param_7 = operator_new(0xdc);

    uStack_4 = 3;

    if (param_7 == (void *)0x0) goto LAB_00672a4f;

    piVar5 = (int *)FUN_00678020(0);

    break;

  case (void *)0x4:

    param_7 = operator_new(0x88);

    uStack_4 = 4;

    if (param_7 == (void *)0x0) goto LAB_00672a4f;

    piVar5 = (int *)FUN_00677d40(0);

    break;

  default:

    uVar8 = FUN_0076cec0(&param_7,"Unknown codec type.");

    uVar9 = 0xfd;

    goto LAB_00672be0;

  }

  *(int **)(param_1 + 0x15c) = piVar5;

  uStack_4 = 0xffffffff;

  iVar6 = (**(code **)(*piVar5 + 4))(param_5,param_6,*(uint8_t *)(param_1 + 0x96d));

  if (iVar6 < 0) {

    uVar8 = FUN_0076cec0(&param_7,"Unable to create codec %d",uVar8);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioInThread.cpp"

                   ,0x104,3,uVar8);

  }

  else {

    uVar2 = *(uint *)(*(int *)(param_1 + 0x15c) + 0xc);

    *(uint *)(param_1 + 0x164) = uVar2;

    pvVar7 = operator_new__(uVar2);

    *(void **)(param_1 + 0x160) = pvVar7;

    puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0xb0);

    *puVar1 = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xb8) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc) = 0;

    *(uint16_t *)(param_1 + 0xc0) = 0;

    *(uint16_t *)(param_1 + 0xc0) = 0x12;

    *(uint16_t *)puVar1 = 1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4) = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x15c) + 0x1c);

    uVar4 = *(ushort *)(*(int *)(param_1 + 0x15c) + 0x20);

    *(ushort *)(param_1 + 0xbe) = uVar4;

    *(short *)(param_1 + 0xb2) = param_4;

    uVar4 = (uVar4 >> 3) * param_4;

    *(ushort *)(param_1 + 0xbc) = uVar4;

    iVar6 = (uint)uVar4 * *(int *)(param_1 + 0xb4);

    *(int *)(param_1 + 0xb8) = iVar6;

    fVar3 = (float)iVar6;

    if (iVar6 < 0) {

      fVar3 = fVar3 + _DAT_00aaa5dc;

    }

    param_7 = (void *)CONCAT22((short)((uint)iVar6 >> 0x10),in_FPUControlWord);

    param_6 = (uint)(in_FPUControlWord | 0xc00);

    *(int *)(param_1 + 0x9ac) = (int)ROUND(fVar3 * DAT_00a0f70c);

    iVar6 = FUN_00671fe0(puVar1);

    if (iVar6 < 0) {

      uVar8 = FUN_0076cec0(&param_7,"Couldnt create capture sound buffer");

      uVar9 = 0x11b;

    }

    else {

      iVar6 = (**(code **)(**(int **)(param_1 + 0x98) + 0x24))(*(int **)(param_1 + 0x98),1);

      if (-1 < iVar6) {

        ExceptionList = pvStack_c;

        return 0;

      }

      uVar8 = FUN_0076cec0(&param_5,"Couldnt start capture");

      uVar9 = 0x121;

    }

LAB_00672be0:

    vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioInThread.cpp"

                   ,uVar9,3,uVar8);

  }

  ExceptionList = pvStack_c;

  return 0xffffffff;

}
