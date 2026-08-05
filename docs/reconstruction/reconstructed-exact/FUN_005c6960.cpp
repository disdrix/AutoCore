// =============================================================================
// FUN_005c6960
// -----------------------------------------------------------------------------
// Stable ID: aa_005c6960
// Address:   0x005c6960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c6960 @ 0x005c6960
// Stable ID: aa_005c6960
// Embedded strings (evidence for future rename):
//   - "CLoadNode::_initSelection"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0051aed0, FUN_005c6960, FUN_0076cef0, FUN_0076cf00.
//  - Strings: "CLoadNode::_initSelection".
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

uint32_t /* width from decompiler */ __fastcall FUN_005c6960(int param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6dcc;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076cf00("CLoadNode::_initSelection");

  *(uint8_t *)(param_1 + 0x65) = 0;

  local_4 = 0;

  FUN_0051aed0(1,0);

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return 0;

}
