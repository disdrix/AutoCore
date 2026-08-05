// =============================================================================
// FUN_00803870
// -----------------------------------------------------------------------------
// Stable ID: aa_00803870
// Address:   0x00803870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00803870 @ 0x00803870
// Stable ID: aa_00803870
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: CreateFontIndirectA, DeleteObject, FUN_00803870, GetObjectA, MulDiv.
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

void FUN_00803870(int param_1)



{

  LOGFONTA *pLVar1;

  HFONT pHVar2;

  int iVar3;

  int unaff_ESI;

  LOGFONTA local_3c;

  

  pLVar1 = &local_3c;

  for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {

    pLVar1->lfHeight = 0;

    pLVar1 = (LOGFONTA *)((int)pLVar1 + 4);

  }

  GetObjectA(*(HANDLE *)(unaff_ESI + 0x260),0x3c,&local_3c);

  DeleteObject(*(HGDIOBJ *)(unaff_ESI + 0x260));

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x260) = 0;

  local_3c.lfHeight = MulDiv(param_1,0x60,0x48);

  local_3c.lfHeight = -local_3c.lfHeight;

  pHVar2 = CreateFontIndirectA(&local_3c);

  *(HFONT *)(unaff_ESI + 0x260) = pHVar2;

  return;

}
