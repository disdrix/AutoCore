// =============================================================================
// FUN_004351f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004351f0
// Address:   0x004351f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004351f0 @ 0x004351f0
// Stable ID: aa_004351f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004351f0, malloc, realloc.
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

void FUN_004351f0(void)



{

  uint in_EAX;

  size_t _NewSize;

  void *pvVar1;

  int unaff_ESI;

  

  if (*(uint *)(unaff_ESI + 0x14) < in_EAX) {

    _NewSize = (in_EAX & 0xfffff000) + 0x1000;

    if (*(void **)(unaff_ESI + 4) == (void *)0x0) {

      pvVar1 = malloc(_NewSize);

      *(size_t *)(unaff_ESI + 0x14) = _NewSize;

      *(void **)(unaff_ESI + 4) = pvVar1;

      *(uint8_t *)(unaff_ESI + 0xc) = 1;

      return;

    }

    pvVar1 = realloc(*(void **)(unaff_ESI + 4),_NewSize);

    *(size_t *)(unaff_ESI + 0x14) = _NewSize;

    *(void **)(unaff_ESI + 4) = pvVar1;

    *(uint8_t *)(unaff_ESI + 0xc) = 1;

  }

  return;

}
