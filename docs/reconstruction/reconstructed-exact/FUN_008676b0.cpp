// =============================================================================
// FUN_008676b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008676b0
// Address:   0x008676b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008676b0 @ 0x008676b0
// Stable ID: aa_008676b0
// Embedded strings (evidence for future rename):
//   - "i_w_chatlog_2d_wnd_text.xml"
//   - "i_w_chatlog_2d_wnd_icon.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_007b5dd0×3, FUN_00792600, FUN_008676b0.
//  - Strings: "i_w_chatlog_2d_wnd_text.xml"; "i_w_chatlog_2d_wnd_icon.xml".
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

void __fastcall FUN_008676b0(int *param_1)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  char *pcStack_34;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b38d8;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar1 = operator_new(0x488);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  local_4 = 0xffffffff;

  param_1[0x14d] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x14d] + 0x28))();

  *(uint8_t *)(param_1[0x14d] + 0xd8) = 1;

  iVar2 = (**(code **)(*(int *)param_1[0x14d] + 0x164))();

  param_1[0x146] = (uint)*(byte *)(iVar2 + 3);

  pcStack_34 = (char *)0x867758;

  pcStack_34 = operator_new(0x488);

  if (pcStack_34 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    uStack_38 = 0x86776f;

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x14c] = iVar2;

  pcStack_34 = (char *)0x867788;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_34 = "i_w_chatlog_2d_wnd_text.xml";

  uStack_38 = 0x867798;

  (**(code **)(*(int *)param_1[0x14c] + 0x28))();

  uStack_38 = 0;

  uStack_3c = 0x8677a8;

  (**(code **)(*(int *)param_1[0x14c] + 0x20c))();

  *(uint8_t *)(param_1[0x14c] + 0xd8) = 1;

  uStack_3c = 0x9c41;

  uStack_40 = 0x8677c4;

  (**(code **)(*(int *)param_1[0x14c] + 0x74))();

  uStack_40 = 1;

  iVar2 = (**(code **)(*(int *)param_1[0x14c] + 0x164))();

  param_1[0x145] = (uint)*(byte *)(iVar2 + 3);

  pcStack_34 = operator_new(0x488);

  if (pcStack_34 == (void *)0x0) {

    pvVar1 = (void *)0x0;

  }

  else {

    pvVar1 = (void *)FUN_007b5dd0(pcStack_34,0);

  }

  param_1[0x14e] = (int)pvVar1;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x14e] + 0x28))("i_w_chatlog_2d_wnd_icon.xml");

  *(uint8_t *)(param_1[0x14e] + 0xd8) = 1;

  (**(code **)(*(int *)param_1[0x14e] + 0x74))(40000);

  iVar2 = *param_1;

  uVar3 = (**(code **)(iVar2 + 0x140))(&uStack_40,1);

  (**(code **)(iVar2 + 0x130))(uVar3);

  ExceptionList = pvVar1;

  return;

}
