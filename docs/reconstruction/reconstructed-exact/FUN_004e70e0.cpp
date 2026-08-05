// =============================================================================
// FUN_004e70e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004e70e0
// Address:   0x004e70e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004e70e0 @ 0x004e70e0
// Stable ID: aa_004e70e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00404840, FUN_004e70e0.
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

void __thiscall

FUN_004e70e0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)



{

  uint32_t /* width from decompiler */ uVar1;

  

  if (param_1 != param_3) {

    FUN_00404840(param_6);

    *(int *)(param_3 + 8) = *(int *)(param_3 + 8) - param_6;

  }

  **(int **)(param_4 + 4) = param_5;

  **(int **)(param_5 + 4) = param_2;

  **(int **)(param_2 + 4) = param_4;

  uVar1 = *(uint32_t /* width from decompiler */ *)(param_2 + 4);

  *(uint32_t /* width from decompiler */ *)(param_2 + 4) = *(uint32_t /* width from decompiler */ *)(param_5 + 4);

  *(uint32_t /* width from decompiler */ *)(param_5 + 4) = *(uint32_t /* width from decompiler */ *)(param_4 + 4);

  *(uint32_t /* width from decompiler */ *)(param_4 + 4) = uVar1;

  return;

}
