// =============================================================================
// FUN_0059e210
// -----------------------------------------------------------------------------
// Stable ID: aa_0059e210
// Address:   0x0059e210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0059e210 @ 0x0059e210
// Stable ID: aa_0059e210
// Embedded strings (evidence for future rename):
//   - "EMSG_Global_Xxxx"
//   - "Version: %d.%d.%d.%d.%d.%d.%d.%d, %d:%d \r\n"
//   - "\nMapName: "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×5, if×4.
//  - Notable callees: FUN_0059e210.
//  - Strings: "EMSG_Global_Xxxx"; "Version: %d.%d.%d.%d.%d.%d.%d.%d, %d:%d \r\n"; "\nMapName: ".
//  - Return sites: 5.

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

char * FUN_0059e210(void)



{

  uint in_EAX;

  

  if ((0x7fff < in_EAX) && (in_EAX < 0x8059)) {

    return "EMSG_Global_Xxxx";

  }

  if ((in_EAX != 0) && (in_EAX < 0x2e)) {

    return *(char **)(&DAT_009d7a1c + in_EAX * 4);

  }

  if ((0xfff < in_EAX) && (in_EAX < 0x100e)) {

    return *(char **)("Version: %d.%d.%d.%d.%d.%d.%d.%d, %d:%d \r\n" + in_EAX * 4 + 0x18);

  }

  if ((0x1fff < in_EAX) && (in_EAX < 0x20c7)) {

    return *(char **)(L"\nMapName: " + in_EAX * 2 + 6);

  }

  return "";

}
