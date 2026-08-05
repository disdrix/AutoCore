// =============================================================================
// FUN_006f53a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f53a0
// Address:   0x006f53a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f53a0 @ 0x006f53a0
// Stable ID: aa_006f53a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_006f5230, FUN_006f53a0.
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

float10 __thiscall FUN_006f53a0(int *param_1,int param_2)



{

  float10 fVar1;

  float fStack_24;

  

  FUN_006f5230(param_2);

  fVar1 = (float10)(**(code **)(*param_1 + 0xc))(param_2);

  if (*(int *)(param_2 + 0x2c) - *(int *)(param_2 + 0x28) < 0x10) {

    return (float10)(float)param_1[6] * (float10)DAT_009dc4cc + fVar1 + (float10)fStack_24;

  }

  return (float10)g_flZero + fVar1 + (float10)fStack_24;

}
