// =============================================================================
// FUN_005bf7d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005bf7d0
// Address:   0x005bf7d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005bf7d0 @ 0x005bf7d0
// Stable ID: aa_005bf7d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005bf530, FUN_005bf7d0.
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

void __thiscall FUN_005bf7d0(int param_1,uint param_2,uint param_3)



{

  uint uVar1;

  

  param_2 = ((int)param_2 < 1) - 1 & param_2;

  uVar1 = *(int *)(param_1 + 4) * *(int *)(param_1 + 0x18) - 1;

  if ((int)uVar1 <= (int)param_2) {

    param_2 = uVar1;

  }

  param_3 = param_3 & ((int)param_3 < 1) - 1;

  uVar1 = *(int *)(param_1 + 8) * *(int *)(param_1 + 0x18) - 1;

  if ((int)param_3 < (int)uVar1) {

    uVar1 = param_3;

  }

  FUN_005bf530((int)param_2 % *(int *)(param_1 + 0x18),(int)uVar1 % *(int *)(param_1 + 0x18));

  return;

}
