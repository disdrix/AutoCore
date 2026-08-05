// =============================================================================
// FUN_00437990
// -----------------------------------------------------------------------------
// Stable ID: aa_00437990
// Address:   0x00437990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00437990 @ 0x00437990
// Stable ID: aa_00437990
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00437990.
//  - Return sites: 2.

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

void FUN_00437990(char param_1)



{

  int in_EAX;

  

  if (param_1 != '\0') {

    *(uint *)(in_EAX + 0xbc) = *(uint *)(in_EAX + 0xbc) | 0x40;

    return;

  }

  *(uint *)(in_EAX + 0xbc) = *(uint *)(in_EAX + 0xbc) & 0xffffffbf;

  return;

}
