// =============================================================================
// FUN_00711c50
// -----------------------------------------------------------------------------
// Stable ID: aa_00711c50
// Address:   0x00711c50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00711c50 @ 0x00711c50
// Stable ID: aa_00711c50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00711c50.
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



void FUN_00711c50(int param_1,float *param_2,float *param_3)



{

  float fVar1;

  

  *param_2 = *(float *)(param_1 + 0x28) * *param_2;

  fVar1 = _DAT_00a0f528 / *param_3;

  *param_3 = fVar1;

  fVar1 = *(float *)(param_1 + 0x24) * *(float *)(param_1 + 0xc) * fVar1 +

          *(float *)(param_1 + 0x10);

  *param_3 = fVar1;

  if (fVar1 < DAT_00a0f524) {

    *param_3 = 50.0;

  }

  if (DAT_00a0f520 < *param_3) {

    *param_3 = 1000.0;

  }

  *param_3 = _DAT_00a0f528 / *param_3;

  return;

}
