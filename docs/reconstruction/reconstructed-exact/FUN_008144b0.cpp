// =============================================================================
// FUN_008144b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008144b0
// Address:   0x008144b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008144b0 @ 0x008144b0
// Stable ID: aa_008144b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00811e00, FUN_008120d0, FUN_008144b0.
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

void FUN_008144b0(void)



{

  int iVar1;

  int unaff_ESI;

  uint32_t /* width from decompiler */ unaff_EDI;

  

  iVar1 = CVOGReaction_ResolveObjectTarget

                    (*(uint8_t *)(unaff_ESI + 0x98),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x90),

                     *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x94));

  if (iVar1 != 0) {

    FUN_00811e00(unaff_EDI);

    return;

  }

  FUN_008120d0(unaff_EDI,unaff_ESI);

  return;

}
