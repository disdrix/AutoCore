// =============================================================================
// FUN_005df770
// -----------------------------------------------------------------------------
// Stable ID: aa_005df770
// Address:   0x005df770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005df770 @ 0x005df770
// Stable ID: aa_005df770
// Embedded strings (evidence for future rename):
//   - "ed_mappath_default"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00540350, FUN_005df770.
//  - Strings: "ed_mappath_default".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_005df770(void)



{

  int iVar1;

  

  iVar1 = FUN_00540350("ed_mappath_default");

  if (iVar1 != 0) {

    _DAT_00bc56b0 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    return;

  }

  _DAT_00bc56b0 = 0xffffffff;

  return;

}
