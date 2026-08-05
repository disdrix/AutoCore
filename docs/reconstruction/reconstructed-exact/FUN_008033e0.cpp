// =============================================================================
// FUN_008033e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008033e0
// Address:   0x008033e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008033e0 @ 0x008033e0
// Stable ID: aa_008033e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: DrawTextExA, FUN_008033e0, InvertRect.
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

void FUN_008033e0(void)



{

  LONG *pLVar1;

  int iVar2;

  int *unaff_ESI;

  int unaff_EDI;

  tagRECT local_10;

  

  local_10.left = 0;

  local_10.top = 0;

  pLVar1 = (LONG *)(**(code **)(*unaff_ESI + 0x50))();

  local_10.right = *pLVar1;

  iVar2 = (**(code **)(*unaff_ESI + 0x50))();

  local_10.bottom = *(LONG *)(iVar2 + 4);

  DrawTextExA(*(HDC *)(unaff_EDI + 0x14),(LPSTR)(unaff_ESI + 0xd),unaff_ESI[0x4f],&local_10,

              unaff_ESI[0x50],(LPDRAWTEXTPARAMS)(unaff_ESI + 0x52));

  if (unaff_ESI[6] != 0) {

    InvertRect(*(HDC *)(unaff_EDI + 0x14),&local_10);

  }

  return;

}
