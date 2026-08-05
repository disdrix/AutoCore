// =============================================================================
// FUN_008bf4b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008bf4b0
// Address:   0x008bf4b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008bf4b0 @ 0x008bf4b0
// Stable ID: aa_008bf4b0
// Embedded strings (evidence for future rename):
//   - "i_d_inv_loot_queue.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0087b890, FUN_008bebc0, FUN_008bf4b0, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_inv_loot_queue.xml".
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

int * FUN_008bf4b0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b68f7;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,param_2);

  *param_1 = (int)&PTR_FUN_00a44f04;

  param_1[0x14b] = 0;

  param_1[0x14c] = 0;

  param_1[0x14d] = 0;

  local_4 = 1;

  param_1[0x13f] = 0;

  param_1[0x140] = 2;

  FUN_008bebc0();

  NDUIWindow_ReloadInterface("i_d_inv_loot_queue.xml");

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  *(uint8_t *)((int)param_1 + 0xc5) = 1;

  *(uint8_t *)(param_1 + 0x31) = 0;

  param_1[0x149] = 0;

  ExceptionList = local_c;

  return param_1;

}
