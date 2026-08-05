// =============================================================================
// FUN_0048a16c
// -----------------------------------------------------------------------------
// Stable ID: aa_0048a16c
// Address:   0x0048a16c  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048a16c @ 0x0048a16c
// Stable ID: aa_0048a16c
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0048a14a, FUN_0048a16c.
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

uint32_t /* width from decompiler */ FUN_0048a16c(void)



{

  uint32_t /* width from decompiler */ uVar1;

  

  if (DAT_00b033e8 == 0) {

    return 0;

  }

  uVar1 = (**(code **)(DAT_00d21a0c + 4))();

  FUN_0048a14a();

  DAT_00b033e8 = 0;

  return uVar1;

}
