// =============================================================================
// Named_CalleeOf_Named_gfxShadowVolume_00746d00
// -----------------------------------------------------------------------------
// Stable ID: aa_00746d00
// Callee of Named_gfxShadowVolume (+1 other named callers)
// Address:   0x00746d00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxShadowVolume: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxShadowVolume (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0044cc30, FUN_00746910, FUN_00746d00.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxShadowVolume (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_gfxShadowVolume_00746d00(void)



{

  int iVar1;

  int unaff_ESI;

  

  iVar1 = *(int *)(unaff_ESI + 8) + -8;

  FUN_0044cc30(*(int *)(unaff_ESI + 4),iVar1,iVar1 - *(int *)(unaff_ESI + 4) >> 3,0);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14) = 0;

  FUN_00746910();

  return;

}
