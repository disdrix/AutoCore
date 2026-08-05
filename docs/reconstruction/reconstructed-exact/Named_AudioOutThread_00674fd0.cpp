// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00674f60, FUN_00674fd0, FUN_0076cec0, vog_LogMessage.
//  - Strings: "AudioOUT CmdStop Command %d".
//  - Return sites: 1.

// =============================================================================
// Named_AudioOutThread_00674fd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00674fd0
// Address:   0x00674fd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "AudioOutThread"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_AudioOutThread_00674fd0(uint param_1)



{

  uint uVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  uVar1 = param_1;

  uVar2 = FUN_0076cec0(&param_1,"AudioOUT CmdStop Command %d",param_1 & 0xff);

  vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioOutThread.cpp"

                 ,0x23f,1,uVar2);

  FUN_00674f60(uVar1);

  return;

}
