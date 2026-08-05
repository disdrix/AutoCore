// =============================================================================
// FUN_004566f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004566f0
// Address:   0x004566f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004566f0 @ 0x004566f0
// Stable ID: aa_004566f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004566f0, FUN_004568c0.
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

void FUN_004566f0(void)



{

  int iVar1;

  int unaff_ESI;

  

  iVar1 = FUN_004568c0();

  *(int *)(unaff_ESI + 4) = iVar1;

  *(uint8_t *)(iVar1 + 0x11) = 1;

  *(int *)(*(int *)(unaff_ESI + 4) + 4) = *(int *)(unaff_ESI + 4);

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(unaff_ESI + 4) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4);

  *(int *)(*(int *)(unaff_ESI + 4) + 8) = *(int *)(unaff_ESI + 4);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = 0;

  return;

}
