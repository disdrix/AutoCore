// =============================================================================
// FUN_008fd9e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008fd9e0
// Address:   0x008fd9e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008fd9e0 @ 0x008fd9e0
// Stable ID: aa_008fd9e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00792490, FUN_007fea50, FUN_008fc740, FUN_008fc890, FUN_008fd9e0.
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

void __fastcall FUN_008fd9e0(int *param_1)



{

  char cVar1;

  

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    (**(code **)(*param_1 + 0x3b8))(param_1[0x1c4]);

    FUN_008fc740();

    FUN_008fc890();

    (**(code **)(*param_1 + 0x3ac))();

    FUN_00792490();

    FUN_007fea50();

  }

  return;

}
