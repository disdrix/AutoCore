// =============================================================================
// FUN_008a5b30
// -----------------------------------------------------------------------------
// Stable ID: aa_008a5b30
// Address:   0x008a5b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a5b30 @ 0x008a5b30
// Stable ID: aa_008a5b30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: FUN_00574810, FUN_008a2d10, FUN_008a4f80, FUN_008a5060, FUN_008a5240, FUN_008a5b30.
//  - Return sites: 4.

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

void __fastcall FUN_008a5b30(int *param_1)



{

  char cVar1;

  

  if ((DAT_00d1b6d8 != 0) && (cVar1 = (**(code **)(*param_1 + 0x3d8))(), cVar1 != '\0')) {

    if ((param_1[0x143] == 0) || (*(int *)(DAT_00d1b6d8 + 0xcb0) == 0)) {

      FUN_008a5240();

      return;

    }

    if (param_1[0x143] == 1) {

      FUN_008a5060(param_1);

      return;

    }

    cVar1 = FUN_00574810(param_1[0x144],param_1[0x145]);

    if (cVar1 != '\0') {

      FUN_008a4f80(param_1);

      return;

    }

  }

  FUN_008a2d10(param_1);

  return;

}
