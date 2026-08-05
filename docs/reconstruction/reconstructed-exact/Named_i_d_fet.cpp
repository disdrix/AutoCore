// =============================================================================
// Named_i_d_fet
// -----------------------------------------------------------------------------
// Stable ID: aa_008ca3d0
// Address:   0x008ca3d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_i_d_fet @ 0x008ca3d0
// Stable ID: aa_008ca3d0
// Embedded strings (evidence for future rename):
//   - "i_d_fet.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0087b890, FUN_008c91b0, Named_i_d_fet, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_fet.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_fet.xml"
 * Domain alias of FUN_008ca3d0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * Named_i_d_fet(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint8_t extraout_DL;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009b6d20;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,param_2);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a4211c;

  param_1[0x13f] = 0xf;

  param_1[0x140] = 0;

  FUN_008c91b0();

  param_1[0x154] = 0;

  *(uint8_t *)((int)param_1 + 0xbf) = extraout_DL;

  NDUIWindow_ReloadInterface("i_d_fet.xml");

  ExceptionList = local_c;

  return param_1;

}
