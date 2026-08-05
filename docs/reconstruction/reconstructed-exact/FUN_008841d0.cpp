// =============================================================================
// FUN_008841d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008841d0
// Address:   0x008841d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008841d0 @ 0x008841d0
// Stable ID: aa_008841d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0085e970, FUN_008841d0, InventoryGrid_SetOwnerFlag_Inferred.
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

void FUN_008841d0(void)



{

  int in_EAX;

  int unaff_ESI;

  

  *(int *)(unaff_ESI + 0x510) = in_EAX;

  if (*(int *)(unaff_ESI + 0x58c) != 0) {

    if (in_EAX != 0) {

      FUN_0085e970();

      InventoryGrid_SetOwnerFlag_Inferred(*(void **)(*(int *)(unaff_ESI + 0x58c) + 0x56c),6);

      return;

    }

    *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x58c) + 0x56c) = 0;

  }

  return;

}
