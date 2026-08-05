// =============================================================================
// FUN_007ae250
// -----------------------------------------------------------------------------
// Stable ID: aa_007ae250
// Address:   0x007ae250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007ae250 @ 0x007ae250
// Stable ID: aa_007ae250
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0041c7e0, FUN_007ae250.
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

void FUN_007ae250(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  puVar1 = operator_new(0xc);

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar1 = 0;

  }

  puVar1[2] = param_1;

  if (puVar1 != unaff_ESI) {

    *puVar1 = *unaff_ESI;

  }

  puVar1[1] = DAT_00afa13c;

  DAT_00afa13c = DAT_00afa13c + 1;

  FUN_0041c7e0(&DAT_00d1e820,puVar1);

  return;

}
