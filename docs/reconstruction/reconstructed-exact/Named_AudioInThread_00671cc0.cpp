// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00671cc0, FUN_00677c40, FUN_0076cec0, vog_LogMessage.
//  - Strings: "Set Spec Warp: %f".
//  - Return sites: 1.

// =============================================================================
// Named_AudioInThread_00671cc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00671cc0
// Address:   0x00671cc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "AudioInThread"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_AudioInThread_00671cc0(float *param_1)



{

  float *pfVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  pfVar1 = param_1;

  FUN_00677c40();

  uVar2 = FUN_0076cec0(&param_1,"Set Spec Warp: %f",(double)*pfVar1);

  vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioInThread.cpp"

                 ,0x2d0,1,uVar2);

  return 0;

}
