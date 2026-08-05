// =============================================================================
// FUN_00425f50
// -----------------------------------------------------------------------------
// Stable ID: aa_00425f50
// Address:   0x00425f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00425f50 @ 0x00425f50
// Stable ID: aa_00425f50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00424e90×4, BitStream_writeFlag×2, FUN_00425f50.
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

void FUN_00425f50(void)



{

  char cVar1;

  uint8_t *in_EAX;

  int unaff_ESI;

  uint32_t /* width from decompiler */ unaff_EDI;

  

  *in_EAX = *(uint8_t *)(unaff_ESI + 0xec);

  *(uint8_t *)(unaff_ESI + 0xec) = 0;

  cVar1 = BitStream_writeFlag(*in_EAX);

  if (cVar1 != '\0') {

    cVar1 = BitStream_writeFlag(*(uint *)(unaff_ESI + 0xb4) >> 2 & 0xffffff01);

    if (cVar1 == '\0') {

      FUN_00424e90(unaff_EDI);

      FUN_00424e90(unaff_EDI);

      FUN_00424e90(unaff_EDI);

      FUN_00424e90(unaff_EDI);

    }

  }

  return;

}
