// =============================================================================
// FUN_0071f0f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071f0f0
// Address:   0x0071f0f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071f0f0 @ 0x0071f0f0
// Stable ID: aa_0071f0f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0071f060, FUN_0071f0f0, ov_pcm_seek, ov_raw_seek.
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

uint32_t /* width from decompiler */ FUN_0071f0f0(void)



{

  int iVar1;

  int unaff_ESI;

  

  iVar1 = ov_raw_seek(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x40),0,0);

  if (iVar1 != 0) {

    FUN_0071f060();

    return 0x80004005;

  }

  iVar1 = *(int *)(unaff_ESI + 0x40);

  *(uint32_t /* width from decompiler */ *)(iVar1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc) = 0;

  ov_pcm_seek(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x40),0,0);

  return 0;

}
