// =============================================================================
// FUN_00652e20
// -----------------------------------------------------------------------------
// Stable ID: aa_00652e20
// Address:   0x00652e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00652e20 @ 0x00652e20
// Stable ID: aa_00652e20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0055e320, FUN_0055e370, FUN_0055e940, FUN_0055e970, FUN_00652320, FUN_00652d50, FUN_00652de0, FUN_00652e20.
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

void __thiscall FUN_00652e20(int param_1,int param_2)



{

  if (param_2 != *(int *)(param_1 + 0xc)) {

    if (*(int *)(param_1 + 0xc) != 0) {

      FUN_0055e320(param_1 + 0x14);

      FUN_0055e370(param_1 + 0x18);

      FUN_00652de0();

    }

    FUN_00652320(param_2);

    if (*(int *)(param_1 + 0xc) != 0) {

      FUN_0055e940(param_1 + 0x14);

      FUN_0055e970(param_1 + 0x18);

      FUN_00652d50();

    }

  }

  return;

}
