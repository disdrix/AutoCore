// =============================================================================
// FUN_007008b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007008b0
// Address:   0x007008b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007008b0 @ 0x007008b0
// Stable ID: aa_007008b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007008b0.
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



void FUN_007008b0(int param_1,float param_2,float param_3,float *param_4)



{

  uint uVar1;

  uint uVar2;

  

  param_3 = param_3 - param_2;

  uVar1 = param_1 * -0x3e39b193 + 0x3039U & 0x7fffffff;

  uVar2 = uVar1 * -0x3e39b193 + 0x3039 & 0x7fffffff;

  *param_4 = ((float)uVar1 * _DAT_009e45b8 + param_2) * param_3;

  param_4[1] = ((float)uVar2 * _DAT_009e45b8 + param_2) * param_3;

  param_4[2] = ((float)(uVar2 * -0x3e39b193 + 0x3039 & 0x7fffffff) * _DAT_009e45b8 + param_2) *

               param_3;

  return;

}
