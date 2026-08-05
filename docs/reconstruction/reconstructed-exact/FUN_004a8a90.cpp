// =============================================================================
// FUN_004a8a90
// -----------------------------------------------------------------------------
// Stable ID: aa_004a8a90
// Address:   0x004a8a90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004a8a90 @ 0x004a8a90
// Stable ID: aa_004a8a90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004a8a90.
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

void __thiscall FUN_004a8a90(int param_1,float param_2,float param_3,uint *param_4,uint *param_5)



{

  uint uVar1;

  uint uVar2;

  

  *param_4 = (int)(param_2 / *(float *)(param_1 + 0x18));

  *param_5 = (int)(param_3 / *(float *)(param_1 + 0x18));

  uVar1 = *param_4;

  uVar2 = *(uint *)(param_1 + 0x10);

  if ((int)(((int)uVar1 < 0) - 1 & uVar1) <= (int)uVar2) {

    uVar2 = ((int)uVar1 < 0) - 1 & uVar1;

  }

  *param_4 = uVar2;

  uVar1 = *param_5;

  if ((int)*(uint *)(param_1 + 0x14) < (int)(((int)uVar1 < 0) - 1 & uVar1)) {

    *param_5 = *(uint *)(param_1 + 0x14);

    return;

  }

  *param_5 = uVar1 & ((int)uVar1 < 0) - 1;

  return;

}
