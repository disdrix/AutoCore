// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI_0082cfb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0082cfb0
// Callee of Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs
// Address:   0x0082cfb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_0082cfb0, NDUIWindow_ReloadInterface.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI_0082cfb0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  char cVar5;

  float fVar6;

  float fVar7;

  int local_8;

  int local_4;

  

  NDUIWindow_ReloadInterface(param_2);

  iVar4 = DAT_00d17944;

  fVar3 = DAT_00aaa67c;

  fVar2 = DAT_00aaa678;

  if (*(char *)((int)param_1 + 0x1c9) == '\0') {

    fVar6 = (float)param_1[0x141] * (float)DAT_00d1e81c;

    iVar1 = DAT_00d1e818;

  }

  else {

    fVar6 = (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x84) * (float)param_1[0x141];

    iVar1 = *(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x80);

  }

  local_4 = (int)(fVar6 * DAT_00aaa678);

  local_8 = (int)((float)iVar1 * (float)param_1[0x140] * DAT_00aaa67c);

  param_1[0x140] = local_8;

  param_1[0x141] = local_4;

  param_1[0x148] = local_8;

  param_1[0x149] = local_4;

  if (*(char *)((int)param_1 + 0x1ca) == '\0') {

    fVar6 = (float)param_1[0x142] * (float)DAT_00d1e818;

    fVar7 = (float)param_1[0x143] * (float)DAT_00d1e81c;

  }

  else {

    fVar6 = (float)*(int *)(*(int *)(iVar4 + 0x2c) + 0x80) * (float)param_1[0x142];

    fVar7 = (float)*(int *)(*(int *)(iVar4 + 0x2c) + 0x84) * (float)param_1[0x143];

  }

  local_4 = (int)(fVar7 * fVar2);

  local_8 = (int)(fVar6 * fVar3);

  param_1[0x142] = local_8;

  param_1[0x143] = local_4;

  if (*(char *)((int)param_1 + 0x1ca) == '\0') {

    fVar6 = (float)param_1[0x144] * (float)DAT_00d1e818;

    fVar7 = (float)param_1[0x145] * (float)DAT_00d1e81c;

  }

  else {

    fVar6 = (float)*(int *)(*(int *)(iVar4 + 0x2c) + 0x80) * (float)param_1[0x144];

    fVar7 = (float)*(int *)(*(int *)(iVar4 + 0x2c) + 0x84) * (float)param_1[0x145];

  }

  local_4 = (int)(fVar7 * fVar2);

  local_8 = (int)(fVar6 * fVar3);

  param_1[0x144] = local_8;

  param_1[0x145] = local_4;

  if (*(char *)((int)param_1 + 0x1ca) == '\0') {

    fVar7 = (float)param_1[0x146] * (float)DAT_00d1e818;

    fVar6 = (float)param_1[0x147] * (float)DAT_00d1e81c;

  }

  else {

    fVar7 = (float)*(int *)(*(int *)(iVar4 + 0x2c) + 0x80) * (float)param_1[0x146];

    fVar6 = (float)*(int *)(*(int *)(iVar4 + 0x2c) + 0x84) * (float)param_1[0x147];

  }

  local_4 = (int)(fVar6 * fVar2);

  local_8 = (int)(fVar7 * fVar3);

  param_1[0x146] = local_8;

  param_1[0x147] = local_4;

  (**(code **)(*param_1 + 0x44c))();

  cVar5 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar5 != '\0') {

    (**(code **)(*param_1 + 0x460))(0xffffffff);

  }

  (**(code **)(*param_1 + 0x34c))();

  return;

}
