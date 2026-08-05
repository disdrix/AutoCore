// =============================================================================
// FUN_008057e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008057e0
// Address:   0x008057e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008057e0 @ 0x008057e0
// Stable ID: aa_008057e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_008057e0, FillRect, GetStockObject.
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

void FUN_008057e0(void)



{

  HBRUSH hbr;

  int unaff_ESI;

  RECT local_10;

  

  local_10.bottom = *(LONG *)(unaff_ESI + 8);

  local_10.left = 0;

  local_10.top = 0;

  local_10.right = *(LONG *)(unaff_ESI + 4);

  hbr = GetStockObject(4);

  FillRect(*(HDC *)(unaff_ESI + 0x14),&local_10,hbr);

  return;

}
