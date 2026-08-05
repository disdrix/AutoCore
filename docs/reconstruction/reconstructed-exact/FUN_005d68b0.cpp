// =============================================================================
// FUN_005d68b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005d68b0
// Address:   0x005d68b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d68b0 @ 0x005d68b0
// Stable ID: aa_005d68b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, do×1, if×1, while×1.
//  - Notable callees: FUN_005d68b0.
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

void __thiscall FUN_005d68b0(int param_1,uint8_t *param_2)



{

  int iVar1;

  

  iVar1 = 0;

  do {

    if ((*(uint *)(param_1 + iVar1 * 4) & 0x7f800000) == 0x7f800000) {

      *param_2 = 0;

      return;

    }

    iVar1 = iVar1 + 1;

  } while (iVar1 < 4);

  *param_2 = 1;

  return;

}
