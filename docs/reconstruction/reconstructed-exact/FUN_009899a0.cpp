// =============================================================================
// FUN_009899a0
// -----------------------------------------------------------------------------
// Stable ID: aa_009899a0
// Address:   0x009899a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009899a0 @ 0x009899a0
// Stable ID: aa_009899a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: return×2, for×1, if×1.
//  - Notable callees: FUN_009899a0, _aligned_free.
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

void FUN_009899a0(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *unaff_EDI;

  

  puVar1 = (uint32_t /* width from decompiler */ *)unaff_EDI[8];

  for (puVar2 = (uint32_t /* width from decompiler */ *)unaff_EDI[7]; puVar2 != puVar1; puVar2 = puVar2 + 1) {

    _aligned_free((void *)*puVar2);

  }

  if ((void *)unaff_EDI[7] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)unaff_EDI[7]);

  }

  unaff_EDI[7] = 0;

  unaff_EDI[8] = 0;

  unaff_EDI[9] = 0;

  *unaff_EDI = 0;

  unaff_EDI[1] = 0;

  *(uint8_t *)(unaff_EDI + 3) = 0;

  unaff_EDI[5] = 0;

  unaff_EDI[4] = 8;

  return;

}
