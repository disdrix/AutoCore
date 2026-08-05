// =============================================================================
// FUN_00811830
// -----------------------------------------------------------------------------
// Stable ID: aa_00811830
// Address:   0x00811830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00811830 @ 0x00811830
// Stable ID: aa_00811830
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00811830, FUN_0093c930.
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

void FUN_00811830(void)



{

  int iVar1;

  int unaff_ESI;

  uint32_t /* width from decompiler */ unaff_EDI;

  

  iVar1 = CVOGReaction_ResolveObjectTarget

                    (1,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc));

  if (iVar1 != 0) {

    FUN_0093c930(unaff_EDI,*(uint16_t *)(unaff_ESI + 0x12),*(uint8_t *)(unaff_ESI + 0x15),

                 *(uint8_t *)(unaff_ESI + 0x14),0);

  }

  return;

}
