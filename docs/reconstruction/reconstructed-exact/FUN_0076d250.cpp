// =============================================================================
// FUN_0076d250
// -----------------------------------------------------------------------------
// Stable ID: aa_0076d250
// Address:   0x0076d250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076d250 @ 0x0076d250
// Stable ID: aa_0076d250
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0043fe60, FUN_006759b0, FUN_0076d140, FUN_0076d250.
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

void FUN_0076d250(void)



{

  int iVar1;

  int iVar2;

  int *unaff_ESI;

  

  iVar1 = FUN_0076d140();

  iVar1 = *(int *)(iVar1 + 4);

  iVar2 = FUN_006759b0(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4),&stack0xfffffffc);

  FUN_0043fe60();

  *(int *)(iVar1 + 4) = iVar2;

  **(int **)(iVar2 + 4) = iVar2;

  *(uint8_t *)(unaff_ESI + 2) = 1;

  (**(code **)(*unaff_ESI + 8))();

  return;

}
