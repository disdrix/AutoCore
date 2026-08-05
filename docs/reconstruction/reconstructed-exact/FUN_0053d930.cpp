// =============================================================================
// FUN_0053d930
// -----------------------------------------------------------------------------
// Stable ID: aa_0053d930
// Address:   0x0053d930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0053d930 @ 0x0053d930
// Stable ID: aa_0053d930
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0053d930.
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

float10 __fastcall FUN_0053d930(int param_1)



{

  float fVar1;

  float fVar2;

  

  if (*(int *)(param_1 + 8) != 0) {

    fVar1 = *(float *)(*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0x2c);

    fVar2 = 0.0;

    if (fVar1 != 0.0) {

      fVar2 = g_flOne / fVar1;

    }

    return (float10)fVar2;

  }

  return (float10)g_flZero;

}
