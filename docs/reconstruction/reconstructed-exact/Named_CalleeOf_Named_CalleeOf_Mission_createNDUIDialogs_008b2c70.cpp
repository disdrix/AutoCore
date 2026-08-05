// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_008b2c70
// -----------------------------------------------------------------------------
// Stable ID: aa_008b2c70
// Callee of Named_CalleeOf_Mission_createNDUIDialogs
// Address:   0x008b2c70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_createNDUIDialogs: mission/objective helper. Evidence string: "i_d_map.xml". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "i_d_map.xml"
//   - "i_d_map_2d_wnd_particles.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0085ba60, FUN_0087b890, FUN_008b2c70, FUN_0097c720, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_map.xml"; "i_d_map_2d_wnd_particles.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_createNDUIDialogs
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

int * Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_008b2c70(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  void *unaff_ESI;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b65c6;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_0087b890(param_1,param_2);

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a4934c;

  param_1[0x13f] = 4;

  param_1[0x140] = 2;

  param_1[0x12e] = 0;

  param_1[0x12f] = 0;

  param_1[0x12d] = 0;

  param_1[0x141] = 0;

  param_1[0x142] = 0;

  param_1[0x143] = 0;

  param_1[0x144] = 0;

  param_1[0x145] = 0;

  param_1[0x147] = 0;

  param_1[0x148] = 0;

  param_1[0x149] = 0;

  *(uint8_t *)(param_1 + 0x124) = 0;

  NDUIWindow_ReloadInterface("i_d_map.xml");

  (**(code **)(*param_1 + 0x34c))();

  pvVar1 = operator_new(0x6b0);

  local_4._0_1_ = 1;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0085ba60(pvVar1,0);

  }

  local_4._0_1_ = 0;

  param_1[0x146] = iVar2;

  pvVar1 = operator_new(0x560);

  local_4._0_1_ = 2;

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0097c720(pvVar1);

  }

  local_4 = (uint)local_4._1_3_ << 8;

  param_1[0x14a] = (int)piVar3;

  (**(code **)(*piVar3 + 0x28))("i_d_map_2d_wnd_particles.xml");

  (**(code **)(*(int *)param_1[0x14a] + 0xcc))(0);

  ExceptionList = unaff_ESI;

  return param_1;

}
