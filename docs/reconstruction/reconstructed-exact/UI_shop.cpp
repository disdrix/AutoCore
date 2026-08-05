// =============================================================================
// UI_shop
// -----------------------------------------------------------------------------
// Stable ID: aa_0088f810
// Address:   0x0088f810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_shop @ 0x0088f810
// Stable ID: aa_0088f810
// Embedded strings (evidence for future rename):
//   - "i_d_shop.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0087b890, FUN_0088eea0, UI_shop, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_shop.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_shop.xml"
 * Domain alias of FUN_0088f810 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * UI_shop(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b5ab3;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a524c4;

  param_1[0x13f] = 0xf;

  param_1[0x140] = 1;

  FUN_0088eea0();

  *(uint8_t *)(param_1 + 0x14c) = 0;

  param_1[0x14a] = 0xffffffff;

  param_1[0x14b] = 0xffffffff;

  param_1[0x143] = 0;

  param_1[0x144] = 0;

  param_1[0x145] = 0;

  param_1[0x146] = 0;

  param_1[0x147] = 0;

  *(uint8_t *)(param_1 + 0x148) = 0;

  *(uint8_t *)(param_1 + 0x124) = 0;

  NDUIWindow_ReloadInterface("i_d_shop.xml");

  ExceptionList = local_c;

  return param_1;

}
