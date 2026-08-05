// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: Client_RecvLoginCallback_6, FUN_007a4480, OutputDebugStringA, code.
//  - Strings: "RecvServerFail\n"; "RecvServerFail: code(%d)".
//  - Return sites: 1.

// =============================================================================
// Client_RecvLoginCallback_6
// -----------------------------------------------------------------------------
// Stable ID: aa_00821c70
// Address:   0x00821c70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

void Client_RecvLoginCallback_6(uint8_t param_1)



{

  if (((DAT_00d1b77c != 0) && (DAT_00d1b780 != (int *)0x0)) && (*DAT_00d1b780 == DAT_00d1b77c)) {

    OutputDebugStringA("RecvServerFail\n");

    FUN_007a4480(1,"RecvServerFail: code(%d)",param_1);

  }

  return;

}
