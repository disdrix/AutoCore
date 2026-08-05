// =============================================================================
// FUN_007116e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007116e0
// Address:   0x007116e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007116e0 @ 0x007116e0
// Stable ID: aa_007116e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007116e0, FUN_00713880, FUN_00713bd0, FUN_00714350, FUN_007144b0, FUN_00714730.
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



void FUN_007116e0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,float *param_3)



{

  float10 fVar1;

  uint8_t local_c94 [1164];

  uint8_t local_808 [1028];

  uint8_t local_404 [1028];

  

  FUN_00713880(param_1,0x91,0x123,local_c94);

  FUN_00714730(local_c94,&DAT_00a0f2c8,local_c94,0x123);

  fVar1 = (float10)FUN_007144b0(local_c94,local_c94,0x123);

  *param_3 = (float)(fVar1 * (float10)_DAT_00a0f510);

  FUN_00714350(local_c94,0x123,9,local_808,local_404);

  FUN_00713bd0(local_808,local_404,param_2);

  return;

}
