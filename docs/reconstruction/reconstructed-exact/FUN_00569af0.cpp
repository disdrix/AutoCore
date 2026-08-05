// =============================================================================
// FUN_00569af0
// -----------------------------------------------------------------------------
// Stable ID: aa_00569af0
// Address:   0x00569af0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00569af0 @ 0x00569af0
// Stable ID: aa_00569af0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00569af0.
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

void FUN_00569af0(void)



{

  if (DAT_00b047b8 != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)*DAT_00b047b8)(1);

  }

  DAT_00b047b8 = (uint32_t /* width from decompiler */ *)0x0;

  if (DAT_00b047b4 != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)*DAT_00b047b4)(1);

  }

  DAT_00b047b4 = (uint32_t /* width from decompiler */ *)0x0;

  return;

}
