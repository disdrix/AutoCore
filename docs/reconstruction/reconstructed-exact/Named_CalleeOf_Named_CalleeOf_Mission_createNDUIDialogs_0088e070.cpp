// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_0088e070
// -----------------------------------------------------------------------------
// Stable ID: aa_0088e070
// Callee of Named_CalleeOf_Mission_createNDUIDialogs
// Address:   0x0088e070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_createNDUIDialogs: mission/objective helper. Evidence string: "i_d_shopveh.xml". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "i_d_shopveh.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0087b890, FUN_0088cd60, FUN_0088e070, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_shopveh.xml".
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

int * Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_0088e070(int *param_1)



{

  char cVar1;

  int iVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b5a87;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a52bf4;

  param_1[0x13f] = 0x10;

  param_1[0x140] = 1;

  FUN_0088cd60();

  param_1[0x150] = 0;

  *(uint8_t *)(param_1 + 0x154) = 0;

  param_1[0x143] = 0;

  param_1[0x144] = 0;

  param_1[0x152] = -1;

  param_1[0x153] = -1;

  param_1[0x148] = 0;

  param_1[0x149] = 0;

  param_1[0x14a] = 0;

  param_1[0x14b] = 0;

  param_1[0x14d] = 0;

  param_1[0x14e] = 0;

  param_1[0x14f] = 0;

  NDUIWindow_ReloadInterface("i_d_shopveh.xml");

  if ((int *)param_1[0x173] != (int *)0x0) {

    iVar2 = (**(code **)(*(int *)param_1[0x173] + 0x1a8))();

    *(uint8_t *)(iVar2 + 0x78) = 0;

  }

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    (**(code **)(*param_1 + 0x448))();

  }

  ExceptionList = pvStack_c;

  return param_1;

}
