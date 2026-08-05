// =============================================================================
// Named_i_m_say
// -----------------------------------------------------------------------------
// Stable ID: aa_00831d10
// Address:   0x00831d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_i_m_say @ 0x00831d10
// Stable ID: aa_00831d10
// Embedded strings (evidence for future rename):
//   - "i_m_say.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0082cfb0, FUN_0082d590, FUN_00831310, Named_i_m_say.
//  - Strings: "i_m_say.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_m_say.xml"
 * Domain alias of FUN_00831d10 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * Named_i_m_say(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b452d;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0082d590(param_1);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a70b4c;

  *(uint8_t *)((int)param_1 + 0xbf) = 0;

  *(uint8_t *)(param_1 + 0x124) = 0;

  FUN_00831310();

  FUN_0082cfb0("i_m_say.xml");

  ExceptionList = local_c;

  return param_1;

}
