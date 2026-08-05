// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: Client_RecvLoginCallback_9, FUN_00944b20, OutputDebugStringA.
//  - Strings: "RecvAccountKicked\n".
//  - Return sites: 2.

// =============================================================================
// Client_RecvLoginCallback_9
// -----------------------------------------------------------------------------
// Stable ID: aa_008226b0
// Address:   0x008226b0  (autoassault.exe, image base 0x400000)
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

void Client_RecvLoginCallback_9(void)



{

  if (((DAT_00d1b77c != 0) && (DAT_00d1b780 != (int *)0x0)) && (*DAT_00d1b780 == DAT_00d1b77c)) {

    OutputDebugStringA("RecvAccountKicked\n");

    FUN_00944b20();

    return;

  }

  return;

}
