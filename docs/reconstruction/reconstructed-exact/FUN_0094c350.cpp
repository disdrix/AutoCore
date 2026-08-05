// =============================================================================
// FUN_0094c350
// -----------------------------------------------------------------------------
// Stable ID: aa_0094c350
// Address:   0x0094c350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094c350 @ 0x0094c350
// Stable ID: aa_0094c350
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_008073b0, FUN_0094c350.
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

void FUN_0094c350(void)



{

  int in_EAX;

  uint32_t /* width from decompiler */ local_4;

  

  if (*(char *)(in_EAX + 0x31e9) == '\0') {

    *(uint8_t *)(in_EAX + 0x31e9) = 1;

    local_4 = 0x802e;

    FUN_008073b0(4,&local_4);

  }

  return;

}
