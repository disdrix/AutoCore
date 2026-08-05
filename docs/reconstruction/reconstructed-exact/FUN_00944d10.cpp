// =============================================================================
// FUN_00944d10
// -----------------------------------------------------------------------------
// Stable ID: aa_00944d10
// Address:   0x00944d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00944d10 @ 0x00944d10
// Stable ID: aa_00944d10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_009332b0, FUN_00935bc0, FUN_00943db0, FUN_00944d10.
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

void FUN_00944d10(void)



{

  int in_EAX;

  

  FUN_00943db0();

  *(uint8_t *)(in_EAX + 0x113) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x134) = 0;

  if (*(char *)(in_EAX + 0xa6) != '\0') {

    FUN_009332b0();

    return;

  }

  FUN_00935bc0();

  return;

}
