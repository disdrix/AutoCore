// =============================================================================
// FUN_00740b10
// -----------------------------------------------------------------------------
// Stable ID: aa_00740b10
// Address:   0x00740b10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00740b10 @ 0x00740b10
// Stable ID: aa_00740b10
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxPerfMemPanel.cpp"
//   - "Failed to create font"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00740b10, FUN_0099ed40, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxPerfMemPanel.cpp"; "Failed to create font".
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

uint32_t /* width from decompiler */ * FUN_00740b10(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b19b5;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00aa2688;

  param_1[1] = 0;

  *(uint8_t *)(param_1 + 2) = 0;

  param_1[3] = 0;

  local_4 = 2;

  iVar1 = FUN_0099ed40(0xe);

  if (iVar1 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxPerfMemPanel.cpp",0x1b,3,

                   "Failed to create font");

  }

  ExceptionList = local_c;

  return param_1;

}
