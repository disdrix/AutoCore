// =============================================================================
// FUN_0091ebe0
// -----------------------------------------------------------------------------
// Stable ID: aa_0091ebe0
// Address:   0x0091ebe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0091ebe0 @ 0x0091ebe0
// Stable ID: aa_0091ebe0
// Embedded strings (evidence for future rename):
//   - "i_s_av_2d_wnd_cutscene_frame_top.xml"
//   - "i_s_av_2d_wnd_cutscene_frame_bottom.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×11, return×3.
//  - Notable callees: FUN_007b5dd0×2, FUN_007feb20, FUN_0091b050, FUN_0091ebe0.
//  - Strings: "i_s_av_2d_wnd_cutscene_frame_top.xml"; "i_s_av_2d_wnd_cutscene_frame_bottom.xml".
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

void __fastcall FUN_0091ebe0(int *param_1)



{

  void **ppvVar1;

  int iVar2;

  void *pvVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  char *pcVar7;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b3acb;

  local_c = ExceptionList;

  ppvVar1 = &local_c;

  if (*(char *)((int)param_1 + 0xc65) != '\0') {

    if ((int *)param_1[0x31a] == (int *)0x0) {

      return;

    }

    ExceptionList = &local_c;

    iVar2 = (**(code **)(*(int *)param_1[0x31a] + 0xe8))();

    if (iVar2 != -1) {

      ExceptionList = local_c;

      return;

    }

    (**(code **)(*(int *)param_1[0x31a] + 0x100))();

    FUN_0091b050();

    ppvVar1 = ExceptionList;

  }

  ExceptionList = ppvVar1;

  *(uint8_t *)((int)param_1 + 0xc65) = 1;

  *(uint8_t *)((int)param_1 + 0xc66) = 0;

  FUN_007feb20();

  if (param_1[0x31a] != 0) {

    (**(code **)(*param_1 + 0xb0))(param_1[0x31a]);

    if ((uint32_t /* width from decompiler */ *)param_1[0x31a] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x31a])(1);

    }

    param_1[0x31a] = 0;

  }

  if (param_1[0x31b] != 0) {

    (**(code **)(*param_1 + 0xb0))(param_1[0x31b]);

    if ((uint32_t /* width from decompiler */ *)param_1[0x31b] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x31b])(1);

    }

    param_1[0x31b] = 0;

  }

  pvVar3 = operator_new(0x488);

  uStack_4 = 0;

  if (pvVar3 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar3,0);

  }

  uStack_4 = 0xffffffff;

  param_1[0x31a] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  pcVar7 = "i_s_av_2d_wnd_cutscene_frame_top.xml";

  (**(code **)(*(int *)param_1[0x31a] + 0x28))("i_s_av_2d_wnd_cutscene_frame_top.xml");

  (**(code **)(*(int *)param_1[0x31a] + 0x74))(0x4e64);

  if (DAT_00d1a8dd != '\0') {

    iVar4 = (**(code **)(*(int *)param_1[0x31a] + 0x164))(0);

    *(uint8_t *)(iVar4 + 3) = 0;

  }

  uVar6 = 0x3f000000;

  uVar5 = 1;

  (**(code **)(*(int *)param_1[0x31a] + 0xfc))(1,0x3f000000);

  pvVar3 = operator_new(0x488);

  if (pvVar3 == (void *)0x0) {

    iVar4 = 0;

  }

  else {

    iVar4 = FUN_007b5dd0(pvVar3,0);

  }

  param_1[0x31b] = iVar4;

  (**(code **)(*param_1 + 0xa8))(iVar4,uVar5,uVar6,pvVar3,pcVar7,iVar2,0xffffffff);

  (**(code **)(*(int *)param_1[0x31b] + 0x28))("i_s_av_2d_wnd_cutscene_frame_bottom.xml");

  (**(code **)(*(int *)param_1[0x31b] + 0x74))(0x4e65);

  if (DAT_00d1a8dd != '\0') {

    iVar2 = (**(code **)(*(int *)param_1[0x31b] + 0x164))(0);

    *(uint8_t *)(iVar2 + 3) = 0;

  }

  (**(code **)(*(int *)param_1[0x31b] + 0xfc))(1,0x3f000000);

  ExceptionList = local_c;

  return;

}
