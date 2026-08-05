// =============================================================================
// FUN_0059b010
// -----------------------------------------------------------------------------
// Stable ID: aa_0059b010
// Address:   0x0059b010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0059b010 @ 0x0059b010
// Stable ID: aa_0059b010
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: FUN_0059aef0, FUN_0059b010.
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

void __fastcall FUN_0059b010(uint32_t /* width from decompiler */ *param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a5b9a;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_009d572c;

  local_4 = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x14d] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x14d])(1);

  }

  param_1[0x14d] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x14e] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x14e])(1);

  }

  param_1[0x14e] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x14f] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x14f])(1);

  }

  param_1[0x14f] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x150] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x150])(1);

  }

  param_1[0x150] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x151] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x151])(1);

  }

  param_1[0x151] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x152] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x152])(1);

  }

  param_1[0x152] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x153] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x153])(1);

  }

  param_1[0x153] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x154] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x154])(1);

  }

  param_1[0x154] = 0;

  local_4 = 0xffffffff;

  FUN_0059aef0();

  ExceptionList = pvStack_c;

  return;

}
