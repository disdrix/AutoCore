// =============================================================================
// FUN_007f74a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007f74a0
// Address:   0x007f74a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007f74a0 @ 0x007f74a0
// Stable ID: aa_007f74a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: do×4, while×4, return×1.
//  - Notable callees: FUN_007f74a0.
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

void FUN_007f74a0(void)



{

  uint16_t *puVar1;

  int iVar2;

  int unaff_ESI;

  

  puVar1 = (uint16_t *)(unaff_ESI + 0x32);

  iVar2 = 5;

  do {

    puVar1[-0x15] = 0;

    *puVar1 = 0;

    puVar1[-0x16] = 0;

    puVar1[-1] = 0;

    *(uint8_t *)((int)puVar1 + -0x27) = 0;

    *(uint8_t *)(puVar1 + -0x14) = 0;

    *(uint8_t *)(puVar1 + -0x13) = 0;

    puVar1 = puVar1 + 0x1a;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  puVar1 = (uint16_t *)(unaff_ESI + 0x136);

  iVar2 = 6;

  do {

    puVar1[-0x15] = 0;

    *puVar1 = 0;

    puVar1[-0x16] = 0;

    puVar1[-1] = 0;

    *(uint8_t *)((int)puVar1 + -0x27) = 0;

    *(uint8_t *)(puVar1 + -0x14) = 0;

    *(uint8_t *)(puVar1 + -0x13) = 0;

    puVar1 = puVar1 + 0x1a;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  puVar1 = (uint16_t *)(unaff_ESI + 0x26e);

  iVar2 = 0x78;

  do {

    puVar1[-0x15] = 0;

    *puVar1 = 0;

    puVar1[-0x16] = 0;

    puVar1[-1] = 0;

    *(uint8_t *)((int)puVar1 + -0x27) = 0;

    *(uint8_t *)(puVar1 + -0x14) = 0;

    *(uint8_t *)(puVar1 + -0x13) = 0;

    puVar1 = puVar1 + 0x1a;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  puVar1 = (uint16_t *)(unaff_ESI + 0x1ace);

  iVar2 = 0x14;

  do {

    puVar1[-0x15] = 0;

    *puVar1 = 0;

    puVar1[-0x16] = 0;

    puVar1[-1] = 0;

    *(uint8_t *)((int)puVar1 + -0x27) = 0;

    *(uint8_t *)(puVar1 + -0x14) = 0;

    *(uint8_t *)(puVar1 + -0x13) = 0;

    puVar1 = puVar1 + 0x1a;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  return;

}
