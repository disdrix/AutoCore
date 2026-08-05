// =============================================================================
// FUN_00712650
// -----------------------------------------------------------------------------
// Stable ID: aa_00712650
// Address:   0x00712650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00712650 @ 0x00712650
// Stable ID: aa_00712650
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, goto×1.
//  - Notable callees: _CIpow×2, ftol×2, FUN_00712650.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ FUN_00712650(int param_1,short param_2)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (param_2 < 1) {

    param_2 = 0xb0;

  }

  fVar1 = (float)(int)param_2 - *(float *)(param_1 + 4);

  if (DAT_00a0f6d0 < fVar1) {

    if (_DAT_00a0f260 <= fVar1) {

      fVar1 = fVar1 - DAT_00a0f6d0;

      goto LAB_007126a2;

    }

  }

  else if (_DAT_00a0f260 <= fVar1) {

    return 0;

  }

  fVar1 = fVar1 + DAT_00a0f6d0;

LAB_007126a2:

  if (fVar1 == g_flZero) {

    return 0;

  }

  if (fVar1 < g_flZero) {

    _CIpow();

    uVar2 = ftol();

    return uVar2;

  }

  _CIpow();

  uVar2 = ftol();

  return uVar2;

}
