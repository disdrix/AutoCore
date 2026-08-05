// =============================================================================
// FUN_00646af0
// -----------------------------------------------------------------------------
// Stable ID: aa_00646af0
// Address:   0x00646af0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00646af0 @ 0x00646af0
// Stable ID: aa_00646af0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: ABS×2, FUN_00646af0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 FUN_00646af0(float param_1,float param_2)



{

  float fVar1;

  float fVar2;

  uint32_t /* width from decompiler */ local_8;

  

  fVar2 = ABS(param_1);

  fVar1 = ABS(param_2);

  if (fVar1 < fVar2) {

    fVar1 = fVar1 / (fVar2 + _DAT_009e45b4);

    local_8 = DAT_009e45bc -

              ((fVar1 - fVar1 * fVar1 * _DAT_009e45c4) - fVar1 * fVar1 * fVar1 * _DAT_009e45c0);

  }

  else {

    fVar2 = fVar2 / (fVar1 + _DAT_009e45b4);

    local_8 = (fVar2 - fVar2 * fVar2 * _DAT_009e45c4) - fVar2 * fVar2 * fVar2 * _DAT_009e45c0;

  }

  if (param_2 < 0.0) {

    local_8 = DAT_009e45b0 - local_8;

  }

  if (param_1 < 0.0) {

    local_8 = 0.0 - local_8;

  }

  return (float10)local_8;

}
