// =============================================================================
// FUN_00886e90
// -----------------------------------------------------------------------------
// Stable ID: aa_00886e90
// Address:   0x00886e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00886e90 @ 0x00886e90
// Stable ID: aa_00886e90
// Embedded strings (evidence for future rename):
//   - "i_d_timer.xml"
//   - "i_d_timer_2d_wnd_particles.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0087b890, FUN_00885950, FUN_00886e90, FUN_0097c720, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_timer.xml"; "i_d_timer_2d_wnd_particles.xml".
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

int * FUN_00886e90(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  void *pvVar1;

  int *piVar2;

  char *pcVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b56fc;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_0087b890(param_1,param_2);

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a560d4;

  param_1[0x13f] = 4;

  param_1[0x140] = 2;

  FUN_00885950();

  *(uint8_t *)(param_1 + 0x124) = 0;

  NDUIWindow_ReloadInterface("i_d_timer.xml");

  (**(code **)(*param_1 + 0x34c))();

  pvVar1 = operator_new(0x560);

  local_4._0_1_ = 1;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_0097c720(pvVar1);

  }

  local_4 = (uint)local_4._1_3_ << 8;

  param_1[0x162] = (int)piVar2;

  pcVar3 = "i_d_timer_2d_wnd_particles.xml";

  (**(code **)(*piVar2 + 0x28))();

  (**(code **)(*(int *)param_1[0x162] + 0xcc))(0);

  ExceptionList = pcVar3;

  return param_1;

}
