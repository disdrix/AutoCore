// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0073fe60, FUN_0076c4d0, FUN_0076c500, FUN_0099ed40, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxPerfGraph.cpp"; "Failed to create font".
//  - Return sites: 1.

// =============================================================================
// Named_gfxPerfGraph
// -----------------------------------------------------------------------------
// Stable ID: aa_0073fe60
// Address:   0x0073fe60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxPerfGraph"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * Named_gfxPerfGraph(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  int iVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b1990;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00aa2918;

  param_1[1] = 0;

  fVar1 = g_flOne;

  local_4 = 2;

  param_1[2] = 0;

  param_1[3] = 10;

  param_1[5] = 100;

  param_1[6] = fVar1;

  FUN_0076c500(2);

  param_1[0x14] = 0;

  param_1[0x15] = DAT_00d1f02c;

  param_1[0x16] = DAT_00d1f030;

  param_1[0x17] = DAT_00d1f034;

  param_1[0x18] = DAT_00d1f038;

  param_1[0x19] = 0;

  iVar2 = FUN_0099ed40(0xc);

  if (iVar2 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxPerfGraph.cpp",0x26,3,

                   "Failed to create font");

  }

  param_1[2] = *(uint32_t /* width from decompiler */ *)(param_1[1] + 0x7c);

  FUN_0076c4d0();

  ExceptionList = local_c;

  return param_1;

}
