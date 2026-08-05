// =============================================================================
// FUN_0081ab20
// -----------------------------------------------------------------------------
// Stable ID: aa_0081ab20
// Address:   0x0081ab20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0081ab20 @ 0x0081ab20
// Stable ID: aa_0081ab20
// Embedded strings (evidence for future rename):
//   - "i_o_video.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00818790, FUN_00819a60, FUN_0081ab20, NDUIWindow_ReloadInterface.
//  - Strings: "i_o_video.xml".
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

uint32_t /* width from decompiler */ * FUN_0081ab20(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b83c5;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00818790(param_1);

  *param_1 = &PTR_FUN_00a79cbc;

  param_1[0x3bf] = 0;

  param_1[0x3c0] = 0;

  param_1[0x3c1] = 0;

  param_1[0x3c3] = 0;

  param_1[0x3c4] = 0;

  param_1[0x3c5] = 0;

  param_1[0x3ca] = 0;

  param_1[0x3cb] = 0;

  param_1[0x3cc] = 0;

  local_4 = 3;

  param_1[0x3ac] = DAT_00a0f524;

  param_1[0x3ad] = DAT_00aaa870;

  uVar1 = DAT_00aaa874;

  param_1[0x140] = 1;

  param_1[0x3af] = uVar1;

  uVar1 = DAT_00aaaa90;

  param_1[0x13f] = 0xf;

  param_1[0x3b0] = uVar1;

  FUN_00819a60();

  NDUIWindow_ReloadInterface("i_o_video.xml");

  ExceptionList = local_c;

  return param_1;

}
