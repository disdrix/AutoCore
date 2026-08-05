// =============================================================================
// UI_hazard_gauge
// -----------------------------------------------------------------------------
// Stable ID: aa_008c4d40
// Address:   0x008c4d40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_hazard_gauge @ 0x008c4d40
// Stable ID: aa_008c4d40
// Embedded strings (evidence for future rename):
//   - "i_d_hazard_2d_gauge.xml"
//   - "i_d_hazard_2d_btn.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00792600, FUN_0079c860, UI_hazard_gauge, FUN_0097ffa0.
//  - Strings: "i_d_hazard_2d_gauge.xml"; "i_d_hazard_2d_btn.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_hazard_2d_gauge.xml"
 * Domain alias of FUN_008c4d40 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_hazard_gauge(int *param_1)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b6a3f;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar1 = operator_new(0x4f8);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0097ffa0(pvVar1);

  }

  local_4 = 0xffffffff;

  param_1[0x145] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x145] + 0x28))("i_d_hazard_2d_gauge.xml");

  (**(code **)(*(int *)param_1[0x145] + 0xfc))(1,0x3f000000);

  piVar3 = (int *)(**(code **)(*(int *)param_1[0x145] + 0x164))(1);

  iVar2 = param_1[0x1a] + 1;

  param_1[0x147] = *piVar3;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x144] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x144] + 0x28))("i_d_hazard_2d_btn.xml");

  (**(code **)(*(int *)param_1[0x144] + 0x74))();

  (**(code **)(*(int *)param_1[0x144] + 0xfc))(1,0x3f000000);

  param_1[0x1a] = param_1[0x1a] + 1;

  iVar2 = param_1[0x1a];

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = (void *)0x9c40;

  return;

}
