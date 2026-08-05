// =============================================================================
// Named_i_d_sw
// -----------------------------------------------------------------------------
// Stable ID: aa_008913d0
// Address:   0x008913d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_i_d_sw @ 0x008913d0
// Stable ID: aa_008913d0
// Embedded strings (evidence for future rename):
//   - "i_d_sw.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_00411b10, FUN_0087b890, Named_i_d_sw, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_sw.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_sw.xml"
 * Domain alias of FUN_008913d0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ * Named_i_d_sw(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b5b10;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a51a84;

  FUN_00411b10(param_1 + 0x143);

  local_4 = CONCAT31(local_4._1_3_,1);

  param_1[0x13f] = 0;

  param_1[0x140] = 0;

  *(uint8_t *)((int)param_1 + 0xc5) = 1;

  param_1[0x14e] = 0;

  NDUIWindow_ReloadInterface("i_d_sw.xml");

  _DAT_00d178fc = param_1[0x1e];

  _DAT_00d17900 = param_1[0x1f];

  _DAT_00d17904 = param_1[0x1e];

  _DAT_00d17908 = param_1[0x1f];

  param_1[0x3b] = 40000;

  ExceptionList = local_c;

  return param_1;

}
