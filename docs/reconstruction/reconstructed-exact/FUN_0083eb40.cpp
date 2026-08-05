// =============================================================================
// FUN_0083eb40
// -----------------------------------------------------------------------------
// Stable ID: aa_0083eb40
// Address:   0x0083eb40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0083eb40 @ 0x0083eb40
// Stable ID: aa_0083eb40
// Embedded strings (evidence for future rename):
//   - "i_w_skill_2d_wnd_frame.xml"
//   - "i_w_skill_2d_wnd_stats.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_007b5dd0×2, FUN_00792600, FUN_0083eb40.
//  - Strings: "i_w_skill_2d_wnd_frame.xml"; "i_w_skill_2d_wnd_stats.xml".
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

void __fastcall FUN_0083eb40(int *param_1)



{

  void *pvVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  char *pcVar5;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b34f7;

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

  pcVar5 = "i_w_skill_2d_wnd_frame.xml";

  (**(code **)(*piVar2 + 0x28))();

  iVar3 = param_1[0x1a] + 1;

  param_1[0x13f] = (int)piVar2;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  uVar4 = 1;

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(piVar2,uVar4,pcVar5,pvVar1);

  (**(code **)(*piVar2 + 0x28))("i_w_skill_2d_wnd_stats.xml");

  param_1[0x140] = (int)piVar2;

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pcVar5;

  return;

}
