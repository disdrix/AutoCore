// =============================================================================
// FUN_00797a10
// -----------------------------------------------------------------------------
// Stable ID: aa_00797a10
// Address:   0x00797a10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00797a10 @ 0x00797a10
// Stable ID: aa_00797a10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00797440, FUN_00797530, FUN_00797a10.
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

void FUN_00797a10(int param_1)



{

  float fVar1;

  

  fVar1 = *(float *)(param_1 + 0xa4) + *(float *)(param_1 + 0xa8);

  if (fVar1 != 0.0) {

    *(float *)(param_1 + 0xa4) = fVar1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8) = 0;

    FUN_00797530(1);

  }

  FUN_00797440();

  return;

}
