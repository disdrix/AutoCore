// =============================================================================
// FUN_0084fa30
// -----------------------------------------------------------------------------
// Stable ID: aa_0084fa30
// Address:   0x0084fa30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0084fa30 @ 0x0084fa30
// Stable ID: aa_0084fa30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0084fa30, SQRT.
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



uint32_t /* width from decompiler */ __fastcall FUN_0084fa30(float *param_1)



{

  float *in_EAX;

  

  if (SQRT((*param_1 - *in_EAX) * (*param_1 - *in_EAX) +

           (param_1[1] - in_EAX[1]) * (param_1[1] - in_EAX[1]) +

           (param_1[2] - in_EAX[2]) * (param_1[2] - in_EAX[2])) <= _DAT_00af9330) {

    return 1;

  }

  return 0;

}
