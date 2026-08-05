// =============================================================================
// FUN_00783f10
// -----------------------------------------------------------------------------
// Stable ID: aa_00783f10
// Address:   0x00783f10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00783f10 @ 0x00783f10
// Stable ID: aa_00783f10
// Embedded strings (evidence for future rename):
//   - "socket error %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00783aa0, FUN_00783f10, WSAGetLastError.
//  - Strings: "socket error %d".
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

char FUN_00783f10(void)



{

  int iVar1;

  

  iVar1 = WSAGetLastError();

  FUN_00783aa0("socket error %d",iVar1);

  return (iVar1 != 0x2733) + '\x02';

}
