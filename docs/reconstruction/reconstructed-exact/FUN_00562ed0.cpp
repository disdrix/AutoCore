// =============================================================================
// FUN_00562ed0
// -----------------------------------------------------------------------------
// Stable ID: aa_00562ed0
// Address:   0x00562ed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00562ed0 @ 0x00562ed0
// Stable ID: aa_00562ed0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_004bc180, FUN_00562ed0.
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

void __thiscall FUN_00562ed0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  

  iVar1 = 0;

  if (param_1 != 0x1e0) {

    iVar1 = *(int *)(*(int *)(param_1 + -0x1dc) + 4) + -0x1dc + param_1;

  }

  FUN_004bc180(iVar1);

  if (*(int *)(param_1 + -0x100) != 0) {

    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x100) + 4) + 4) + 4 +

                         *(int *)(param_1 + -0x100)) + 0x2a4))(param_2);

  }

  if (*(int *)(param_1 + -0xfc) != 0) {

    (**(code **)(**(int **)(param_1 + -0xfc) + 0x2a4))(param_2);

  }

  return;

}
