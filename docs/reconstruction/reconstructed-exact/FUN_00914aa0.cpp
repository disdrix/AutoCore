// =============================================================================
// FUN_00914aa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00914aa0
// Address:   0x00914aa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00914aa0 @ 0x00914aa0
// Stable ID: aa_00914aa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CONCAT31, FUN_004f4ff0, FUN_00914aa0.
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

void FUN_00914aa0(void)



{

  int iVar1;

  

  if (((DAT_00d1b6d8 != 0) && (iVar1 = *(int *)(DAT_00d1b6d8 + 0x250), iVar1 != 0)) &&

     (*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xa8 + iVar1) != 0)) {

    FUN_004f4ff0(CONCAT31((int3)((uint)DAT_00d1b6d8 >> 8),*(uint8_t *)(DAT_00d1b6d8 + 0x6b9)),

                 DAT_00d1d888);

  }

  return;

}
