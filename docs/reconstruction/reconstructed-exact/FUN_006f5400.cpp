// =============================================================================
// FUN_006f5400
// -----------------------------------------------------------------------------
// Stable ID: aa_006f5400
// Address:   0x006f5400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f5400 @ 0x006f5400
// Stable ID: aa_006f5400
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006f51d0, FUN_006f52c0, FUN_006f5400.
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

float10 __thiscall FUN_006f5400(int param_1,int param_2)



{

  float10 fVar1;

  float10 fVar2;

  

  fVar1 = (float10)FUN_006f52c0(param_2);

  fVar2 = (float10)FUN_006f51d0(param_2);

  return ((float10)*(float *)(param_2 + 0x38) - (float10)*(float *)(param_2 + 0x20)) *

         (float10)*(float *)(param_2 + 0x10) * (float10)*(float *)(param_1 + 0xc) +

         (float10)*(int *)(param_2 + 0x30) * (float10)*(float *)(param_2 + 0x1c) *

         (float10)*(float *)(param_1 + 8) * (float10)DAT_00aaa688 + fVar2 + (float10)(float)fVar1;

}
