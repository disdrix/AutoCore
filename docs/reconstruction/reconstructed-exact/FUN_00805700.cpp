// =============================================================================
// FUN_00805700
// -----------------------------------------------------------------------------
// Stable ID: aa_00805700
// Address:   0x00805700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00805700 @ 0x00805700
// Stable ID: aa_00805700
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: SelectObject×2, FUN_00805700, FillRect, GetStockObject.
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

void FUN_00805700(int param_1,int param_2,int param_3)



{

  int in_EAX;

  HGDIOBJ h;

  HBRUSH hbr;

  int unaff_ESI;

  RECT local_10;

  

  h = GetStockObject(0);

  hbr = SelectObject(*(HDC *)(unaff_ESI + 0x14),h);

  local_10.left = param_1;

  local_10.right = param_1 + param_2;

  local_10.bottom = in_EAX + param_3;

  FillRect(*(HDC *)(unaff_ESI + 0x14),&local_10,hbr);

  SelectObject(*(HDC *)(unaff_ESI + 0x14),hbr);

  return;

}
