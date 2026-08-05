// =============================================================================
// Named_i_d_mem
// -----------------------------------------------------------------------------
// Stable ID: aa_008b4520
// Address:   0x008b4520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_i_d_mem @ 0x008b4520
// Stable ID: aa_008b4520
// Embedded strings (evidence for future rename):
//   - "i_d_mem.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0087b890, FUN_008b2e50, FUN_008b2f00, FUN_008b3050, FUN_008b3670, Named_i_d_mem, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_mem.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_mem.xml"
 * Domain alias of FUN_008b4520 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * Named_i_d_mem(int *param_1)



{

  char cVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b65f2;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a48b4c;

  *(uint8_t *)((int)param_1 + 0x712) = 0xff;

  *(uint8_t *)((int)param_1 + 0x711) = 0xff;

  *(uint8_t *)(param_1 + 0x1c4) = 0xff;

  *(uint8_t *)((int)param_1 + 0x713) = 0xff;

  param_1[0x13f] = 5;

  param_1[0x140] = 1;

  param_1[0x1ab] = 0;

  *(uint16_t *)(param_1 + 0x1ac) = 0;

  *(uint8_t *)(param_1 + 0x1c3) = 0;

  FUN_008b2e50();

  *(uint8_t *)(param_1 + 0x124) = 0;

  NDUIWindow_ReloadInterface("i_d_mem.xml");

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    FUN_008b3670();

    FUN_008b3050();

    FUN_008b2f00();

  }

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = local_c;

  return param_1;

}
