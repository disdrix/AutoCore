// =============================================================================
// FUN_0078e2f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0078e2f0
// Address:   0x0078e2f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078e2f0 @ 0x0078e2f0
// Stable ID: aa_0078e2f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0078e2f0, FUN_00792d20.
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

void FUN_0078e2f0(void)



{

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  FUN_00792d20(unaff_ESI);

  unaff_ESI[0x24b] = 0;

  unaff_ESI[0x24c] = 0;

  unaff_ESI[0x24d] = 0;

  unaff_ESI[0x12e] = 0;

  unaff_ESI[0x12f] = 0;

  unaff_ESI[0x12d] = 0;

  *(uint8_t *)((int)unaff_ESI + 0x4fd) = 0;

  *(uint8_t *)((int)unaff_ESI + 0x4ff) = 0;

  *(uint8_t *)((int)unaff_ESI + 0x603) = 0;

  *(uint8_t *)((int)unaff_ESI + 0x707) = 0;

  *(uint8_t *)((int)unaff_ESI + 0x80b) = 0;

  *unaff_ESI = &PTR_FUN_00a99a14;

  unaff_ESI[0x24a] = 0xffffffff;

  *(uint8_t *)(unaff_ESI + 0x13f) = 1;

  *(uint8_t *)((int)unaff_ESI + 0x4fe) = 1;

  unaff_ESI[0x244] = 0;

  unaff_ESI[0x245] = 0;

  unaff_ESI[0x246] = 0;

  unaff_ESI[0x247] = 0;

  unaff_ESI[0x248] = 0;

  unaff_ESI[0x249] = 0;

  return;

}
