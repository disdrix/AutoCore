// =============================================================================
// FUN_008f8400
// -----------------------------------------------------------------------------
// Stable ID: aa_008f8400
// Address:   0x008f8400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f8400 @ 0x008f8400
// Stable ID: aa_008f8400
// Embedded strings (evidence for future rename):
//   - "i_d_chatlog_2d_btn_options.xml"
//   - "i_d_chatlog_2d_wnd_divider.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~144 non-empty decompiler lines.
//  - Control keywords: if×11, do×1, while×1, return×1.
//  - Notable callees: FUN_007b5dd0×4, FUN_0079c860×2, FUN_00792600, FUN_008f6990, FUN_008f6b70, FUN_008f6f60, FUN_008f7040, FUN_008f8400.
//  - Strings: "i_d_chatlog_2d_btn_options.xml"; "i_d_chatlog_2d_wnd_divider.xml".
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

void __fastcall FUN_008f8400(int *param_1)



{

  void *pvVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uStack_88;

  uint32_t /* width from decompiler */ uStack_84;

  void *pvStack_80;

  char *pcStack_7c;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b79d3;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar1 = operator_new(0x488);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0();

  }

  local_4 = 0xffffffff;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar2 + 0x28))();

  (**(code **)(*piVar2 + 0x74))();

  (**(code **)(*piVar2 + 0xfc))();

  param_1[0x14f] = (int)piVar2;

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar2 + 0x28))();

  (**(code **)(*piVar2 + 0x74))();

  (**(code **)(*piVar2 + 0xcc))();

  param_1[0x14b] = (int)piVar2;

  pvVar1 = operator_new(0x488);

  iVar4 = 2;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar2 + 0x28))();

  (**(code **)(*piVar2 + 0x74))();

  (**(code **)(*piVar2 + 0xcc))();

  param_1[0x14c] = (int)piVar2;

  (**(code **)(*piVar2 + 0x2d4))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar2 + 0x28))();

  (**(code **)(*piVar2 + 0x74))();

  (**(code **)(*piVar2 + 0xcc))();

  iVar3 = param_1[0x1a] + 1;

  param_1[0x14d] = (int)piVar2;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))();

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pcStack_7c = (char *)0x8f8626;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_0079c860();

  }

  pcStack_7c = (char *)0x8f8657;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_7c = "i_d_chatlog_2d_btn_options.xml";

  pvStack_80 = (void *)0x8f8663;

  (**(code **)(*piVar2 + 0x28))();

  pvStack_80 = (void *)0x9c42;

  uStack_84 = 0x8f866f;

  (**(code **)(*piVar2 + 0x74))();

  uStack_84 = 0;

  uStack_88 = 0x8f867b;

  (**(code **)(*piVar2 + 0xcc))();

  iVar3 = param_1[0x1a] + 1;

  param_1[0x142] = (int)piVar2;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  uStack_88 = 1;

  (**(code **)(*param_1 + 0x3f4))();

  pvVar1 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x152] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x152] + 0x28))("i_d_chatlog_2d_wnd_divider.xml");

  (**(code **)(*(int *)param_1[0x152] + 0x74))(0x9c47);

  (**(code **)(*(int *)param_1[0x152] + 0xcc))(0);

  piVar2 = param_1 + 0x150;

  do {

    (**(code **)(*param_1 + 0xa8))(*piVar2);

    (**(code **)(*(int *)*piVar2 + 0x43c))();

    piVar2 = piVar2 + 1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  if ((int *)param_1[0x14d] != (int *)0x0) {

    if (DAT_00af9214 == -1) {

      iVar4 = (**(code **)(*(int *)param_1[0x14d] + 0x124))(&uStack_88);

      DAT_00af9214 = (int)*(float *)(iVar4 + 4);

    }

    FUN_008f6990();

  }

  FUN_008f7040();

  FUN_008f6f60();

  FUN_008f6b70(param_1);

  (**(code **)(*param_1 + 0x450))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvStack_80;

  return;

}
