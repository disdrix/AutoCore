// =============================================================================
// FUN_0062b940
// -----------------------------------------------------------------------------
// Stable ID: aa_0062b940
// Address:   0x0062b940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062b940 @ 0x0062b940
// Stable ID: aa_0062b940
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: while×2, if×1, return×1.
//  - Notable callees: FUN_0062b940.
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

void FUN_0062b940(uint *param_1,uint *param_2,uint param_3)



{

  uint uVar1;

  uint *puVar2;

  

  uVar1 = (int)param_2 - (int)param_1;

  while (0x80 < (int)(uVar1 & 0xfffffff8)) {

    puVar2 = param_1 + ((int)uVar1 >> 4) * 2;

    if (param_1[((int)uVar1 >> 4) * 2] < param_3) {

      param_1 = puVar2;

      puVar2 = param_2;

    }

    param_2 = puVar2;

    uVar1 = (int)puVar2 - (int)param_1;

  }

  uVar1 = *param_1;

  while (uVar1 < param_3) {

    param_1 = param_1 + 2;

    uVar1 = *param_1;

  }

  return;

}
