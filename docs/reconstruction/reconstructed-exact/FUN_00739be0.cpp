// =============================================================================
// FUN_00739be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00739be0
// Address:   0x00739be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00739be0 @ 0x00739be0
// Stable ID: aa_00739be0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_00737900, FUN_00738d80, FUN_007391c0, FUN_00739670, FUN_00739be0.
//  - Return sites: 3.

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

void __fastcall FUN_00739be0(int param_1)



{

  byte bVar1;

  

  bVar1 = FUN_00737900();

  if (bVar1 != ((byte)(*(uint *)(param_1 + 0xbc) >> 4) & 1)) {

    if ((bVar1 == 0) && (*(int *)(param_1 + 0xe4) == 0)) {

      FUN_007391c0(param_1);

    }

    return;

  }

  if (bVar1 == 0) {

    FUN_00739670();

    return;

  }

  FUN_00738d80(param_1);

  return;

}
