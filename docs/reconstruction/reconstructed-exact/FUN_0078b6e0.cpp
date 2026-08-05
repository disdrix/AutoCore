// =============================================================================
// FUN_0078b6e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0078b6e0
// Address:   0x0078b6e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078b6e0 @ 0x0078b6e0
// Stable ID: aa_0078b6e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: InitializeCriticalSection×2, FUN_0078b6e0, FUN_00792d20.
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

void FUN_0078b6e0(void)



{

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  FUN_00792d20(unaff_ESI);

  *unaff_ESI = &PTR_FUN_00a9a42c;

  *(uint8_t *)((int)unaff_ESI + 0x502) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x501) = 0xff;

  *(uint8_t *)(unaff_ESI + 0x140) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x503) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x506) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x505) = 0xff;

  *(uint8_t *)(unaff_ESI + 0x141) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x507) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x50a) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x509) = 0xff;

  *(uint8_t *)(unaff_ESI + 0x142) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x50b) = 0xff;

  unaff_ESI[0x143] = &PTR_FUN_00a9a3fc;

  unaff_ESI[0x14b] = 0;

  unaff_ESI[0x14a] = 0;

  unaff_ESI[0x14c] = 0;

  *(uint8_t *)(unaff_ESI + 0x14d) = 0;

  InitializeCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x144));

  unaff_ESI[0x143] = &PTR_FUN_00a9a408;

  unaff_ESI[0x14e] = &PTR_FUN_00a9a414;

  unaff_ESI[0x156] = 0;

  unaff_ESI[0x155] = 0;

  unaff_ESI[0x157] = 0;

  *(uint8_t *)(unaff_ESI + 0x158) = 0;

  InitializeCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x14f));

  unaff_ESI[0x14e] = &PTR_FUN_00a9a420;

  *(uint8_t *)(unaff_ESI + 0x159) = 0;

  *(uint8_t *)((int)unaff_ESI + 0x566) = 0;

  *(uint8_t *)((int)unaff_ESI + 0x567) = 0;

  unaff_ESI[0x15a] = 0;

  unaff_ESI[0x13f] = 0;

  unaff_ESI[0x268] = 0xffffffff;

  unaff_ESI[0x15b] = 1;

  *(uint8_t *)((int)unaff_ESI + 0x565) = 1;

  unaff_ESI[0x140] = 0;

  unaff_ESI[0x141] = 0;

  unaff_ESI[0x142] = 0;

  unaff_ESI[0x266] = 0xffffffff;

  unaff_ESI[0x267] = 0xffffffff;

  unaff_ESI[0x12e] = 0;

  unaff_ESI[0x12f] = 0;

  unaff_ESI[0x12d] = 0;

  *(uint8_t *)(unaff_ESI + 0x15c) = 0;

  *(uint8_t *)(unaff_ESI + 0x19d) = 0;

  *(uint8_t *)(unaff_ESI + 0x1de) = 0;

  *(uint8_t *)(unaff_ESI + 0x21f) = 0;

  unaff_ESI[0x260] = 0;

  unaff_ESI[0x261] = 0;

  unaff_ESI[0x262] = 0;

  unaff_ESI[0x263] = 0;

  return;

}
