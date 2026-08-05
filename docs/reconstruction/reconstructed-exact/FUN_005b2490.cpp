// =============================================================================
// FUN_005b2490
// -----------------------------------------------------------------------------
// Stable ID: aa_005b2490
// Address:   0x005b2490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b2490 @ 0x005b2490
// Stable ID: aa_005b2490
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×6, if×1, switch×1.
//  - Notable callees: FUN_00404d70, FUN_005b2490.
//  - Return sites: 6.

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

uint32_t /* width from decompiler */ FUN_005b2490(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  

  iVar1 = FUN_00404d70(param_1);

  if (iVar1 == 0) {

    return 0;

  }

  switch(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x38)) {

  case 8:

  case 0x32:

    return 0xe0;

  default:

    return 0xd8;

  case 10:

    return 0x150;

  case 0xc:

    return 0x188;

  case 0x10:

  case 0x1c:

    return 0x158;

  }

}
