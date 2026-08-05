// =============================================================================
// FUN_00824c90
// -----------------------------------------------------------------------------
// Stable ID: aa_00824c90
// Address:   0x00824c90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00824c90 @ 0x00824c90
// Stable ID: aa_00824c90
// Embedded strings (evidence for future rename):
//   - "i_d_s_2d_btn_skill_available.xml"
//   - "i_d_s_2d_btn_skill_btn.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00792600, FUN_0079c860, FUN_007b5dd0, FUN_00824c90.
//  - Strings: "i_d_s_2d_btn_skill_available.xml"; "i_d_s_2d_btn_skill_btn.xml".
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

void __fastcall FUN_00824c90(int *param_1)



{

  void *pvVar1;

  int *piVar2;

  int iVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ uVar5;

  char *pcVar6;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b4268;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar1 = operator_new(0x488);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  local_4 = 0xffffffff;

  (**(code **)(*param_1 + 0xa8))(piVar2);

  (**(code **)(*piVar2 + 0x74))(0xea61);

  pcVar6 = "i_d_s_2d_btn_skill_available.xml";

  (**(code **)(*piVar2 + 0x28))("i_d_s_2d_btn_skill_available.xml");

  iVar3 = param_1[0x1a] + 1;

  param_1[0x143] = (int)piVar2;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  uVar5 = 1;

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_0079c860(uVar5,pcVar6,pvVar1);

  }

  piVar4 = piVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar2 + 0x74))(60000);

  (**(code **)(*piVar2 + 0x28))("i_d_s_2d_btn_skill_btn.xml");

  param_1[0x142] = (int)piVar2;

  piVar2 = (int *)(**(code **)(*piVar2 + 0x164))(0);

  param_1[0x140] = *piVar2;

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = piVar4;

  return;

}
