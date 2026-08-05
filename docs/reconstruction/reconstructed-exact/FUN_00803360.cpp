// =============================================================================
// FUN_00803360
// -----------------------------------------------------------------------------
// Stable ID: aa_00803360
// Address:   0x00803360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00803360 @ 0x00803360
// Stable ID: aa_00803360
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CreateFontIndirectA, DeleteObject, FUN_00803360.
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

void __thiscall FUN_00803360(int param_1,LOGFONTA *param_2)



{

  HFONT pHVar1;

  

  if (*(HGDIOBJ *)(param_1 + 0x134) != (HGDIOBJ)0x0) {

    DeleteObject(*(HGDIOBJ *)(param_1 + 0x134));

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x134) = 0;

  }

  pHVar1 = CreateFontIndirectA(param_2);

  *(HFONT *)(param_1 + 0x134) = pHVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x144) = 1;

  return;

}
