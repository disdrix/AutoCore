// =============================================================================
// FUN_0080be70
// -----------------------------------------------------------------------------
// Stable ID: aa_0080be70
// Address:   0x0080be70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080be70 @ 0x0080be70
// Stable ID: aa_0080be70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×4, switch×1.
//  - Notable callees: FUN_007fb640, FUN_007fd7a0, FUN_007fd850, FUN_007fe8d0, FUN_0080be70.
//  - Return sites: 4.

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

void FUN_0080be70(void)



{

  int in_EAX;

  

  switch(*(uint8_t *)(in_EAX + 4)) {

  case 0:

    FUN_007fe8d0();

    return;

  case 1:

    FUN_007fd850(*(uint32_t /* width from decompiler */ *)(in_EAX + 8),*(uint8_t *)(in_EAX + 0xc));

    return;

  case 2:

    FUN_007fd7a0();

    return;

  case 3:

    FUN_007fb640();

  }

  return;

}
