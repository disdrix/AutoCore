// =============================================================================
// FUN_008ce6c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008ce6c0
// Address:   0x008ce6c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008ce6c0 @ 0x008ce6c0
// Stable ID: aa_008ce6c0
// Embedded strings (evidence for future rename):
//   - "i_d_fes.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_008cc750, FUN_008ce6c0, FUN_008d8b90, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_fes.xml".
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

int * FUN_008ce6c0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009b9fe6;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_008d8b90(param_1,param_2);

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a40e1c;

  param_1[0x15e] = -1;

  param_1[0x15f] = 0;

  *(uint8_t *)(param_1 + 0x160) = 0;

  param_1[0x161] = 0;

  param_1[0x162] = 0;

  param_1[0x163] = 0;

  param_1[0x164] = 0;

  param_1[0x165] = 0;

  param_1[0x166] = 0;

  *(uint8_t *)(param_1 + 0x196) = 0;

  FUN_008cc750();

  NDUIWindow_ReloadInterface("i_d_fes.xml");

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    cVar1 = (**(code **)(*param_1 + 0xd0))();

    if (cVar1 != '\0') {

      (**(code **)(*param_1 + 0xfc))(1,0x3f000000);

    }

  }

  ExceptionList = local_c;

  return param_1;

}
