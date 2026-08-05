// =============================================================================
// FUN_008ddb30
// -----------------------------------------------------------------------------
// Stable ID: aa_008ddb30
// Address:   0x008ddb30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008ddb30 @ 0x008ddb30
// Stable ID: aa_008ddb30
// Embedded strings (evidence for future rename):
//   - "i_d_et_wnd_bg_texture.xml"
//   - "i_d_et_wnd_info.xml"
//   - "i_d_et_wnd_time.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_007b5dd0×3, FUN_00792600, FUN_008ddb30.
//  - Strings: "i_d_et_wnd_bg_texture.xml"; "i_d_et_wnd_info.xml"; "i_d_et_wnd_time.xml".
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

void __fastcall FUN_008ddb30(int *param_1)



{

  void *pvVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  char *pcVar6;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b39fa;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar1 = operator_new(0x488);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  local_4 = 0xffffffff;

  param_1[0x143] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  pcVar6 = "i_d_et_wnd_bg_texture.xml";

  (**(code **)(*(int *)param_1[0x143] + 0x28))("i_d_et_wnd_bg_texture.xml");

  uVar5 = 0x3f000000;

  (**(code **)(*(int *)param_1[0x143] + 0xfc))(1,0x3f000000);

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  uVar4 = 1;

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x145] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2,uVar4,pvVar1,uVar5,pcVar6,0xffffffff);

  pcVar6 = "i_d_et_wnd_info.xml";

  (**(code **)(*(int *)param_1[0x145] + 0x28))("i_d_et_wnd_info.xml");

  uVar5 = 1;

  (**(code **)(*(int *)param_1[0x145] + 0xfc))(1,0x3f000000);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x144] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3,uVar5,pvVar1,pcVar6,iVar2,0xffffffff);

  (**(code **)(*(int *)param_1[0x144] + 0x28))("i_d_et_wnd_time.xml");

  (**(code **)(*(int *)param_1[0x144] + 0xfc))(1);

  param_1[0x1a] = param_1[0x1a] + 1;

  iVar2 = param_1[0x1a];

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = (void *)0x3f000000;

  return;

}
