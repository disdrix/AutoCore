// =============================================================================
// FUN_00914630
// -----------------------------------------------------------------------------
// Stable ID: aa_00914630
// Address:   0x00914630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00914630 @ 0x00914630
// Stable ID: aa_00914630
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00914630.
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

void FUN_00914630(void)



{

  int in_EAX;

  

  if ((DAT_00d1d866 != '\0') && (*(char *)(in_EAX + 0xa38) == '\x01')) {

    if (DAT_00d1f0d0 != '\0') {

      *(uint8_t *)(in_EAX + 0xa87) = 1;

      DAT_00d1f0d0 = '\0';

    }

    *(uint8_t *)(in_EAX + 0xa32) = 1;

    return;

  }

  DAT_00d1f0d0 = 1;

  *(uint8_t *)(in_EAX + 0xa32) = 0;

  return;

}
