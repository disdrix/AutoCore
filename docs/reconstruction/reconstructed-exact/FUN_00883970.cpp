// =============================================================================
// FUN_00883970
// -----------------------------------------------------------------------------
// Stable ID: aa_00883970
// Address:   0x00883970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00883970 @ 0x00883970
// Stable ID: aa_00883970
// Embedded strings (evidence for future rename):
//   - "i_d_triangle_scaler_info_bg.xml"
//   - "i_d_triangle_scaler_info.xml"
//   - "i_d_triangle_scaler_effect.xml"
//   - "i_d_triangle_scaler_arrow.xml"
//   - "i_d_triangle_scaler_arrow_empty.xml"
//   - "i_d_triangle_scaler_normal_icon.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00792600, FUN_00883970, FUN_0098c3f0.
//  - Strings: "i_d_triangle_scaler_info_bg.xml"; "i_d_triangle_scaler_info.xml"; "i_d_triangle_scaler_effect.xml"; "i_d_triangle_scaler_arrow.xml".
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

void __fastcall FUN_00883970(int *param_1)



{

  int *piVar1;

  int iVar2;

  void *pvVar3;

  int *piVar4;

  char *pcVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b3923;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x404))(param_1 + 0x14d,"i_d_triangle_scaler_info_bg.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x14c,"i_d_triangle_scaler_info.xml",0xffffffff);

  uVar7 = 0;

  (**(code **)(*(int *)param_1[0x14d] + 0xcc))(0);

  uVar6 = 0;

  (**(code **)(*(int *)param_1[0x14c] + 0xcc))(0);

  pcVar5 = "i_d_triangle_scaler_effect.xml";

  piVar1 = param_1 + 0x149;

  piVar4 = piVar1;

  (**(code **)(*param_1 + 0x404))(piVar1,"i_d_triangle_scaler_effect.xml",0xffffffff);

  (**(code **)(*(int *)*piVar1 + 0xcc))(0);

  pvVar3 = operator_new(0x498);

  if (pvVar3 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0098c3f0(pvVar3);

  }

  param_1[0x14e] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2,piVar4,pcVar5,pvVar3,uVar6,uVar7,0xffffffff);

  (**(code **)(*(int *)param_1[0x14e] + 0x28))("i_d_triangle_scaler_arrow.xml");

  (**(code **)(*(int *)param_1[0x14e] + 0xcc))(0);

  uVar6 = DAT_00aaa7dc;

  *(uint8_t *)(param_1[0x14e] + 0x488) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0x14e] + 0x490) = uVar6;

  *(uint32_t /* width from decompiler */ *)(param_1[0x14e] + 0x48c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1[0x14e] + 0x494) = 0;

  (**(code **)(*param_1 + 0x404))(param_1 + 0x14f,"i_d_triangle_scaler_arrow_empty.xml",0x9c43);

  (**(code **)(*param_1 + 0x40c))

            (param_1 + 0x150,"i_d_triangle_scaler_normal_icon.xml",0x9c41,0x9c44);

  (**(code **)(*param_1 + 0x40c))

            (param_1 + 0x151,"i_d_triangle_scaler_speed_icon.xml",0x9c41,0x9c45);

  (**(code **)(*param_1 + 0x40c))

            (param_1 + 0x152,"i_d_triangle_scaler_offense_icon.xml",0x9c41,0x9c46);

  (**(code **)(*param_1 + 0x40c))

            (param_1 + 0x153,"i_d_triangle_scaler_defense_icon.xml",0x9c41,0x9c47);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x157,"i_d_triangle_scaler_timer.xml");

  (**(code **)(*(int *)param_1[0x157] + 0xcc))(0);

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = (void *)0xffffffff;

  return;

}
