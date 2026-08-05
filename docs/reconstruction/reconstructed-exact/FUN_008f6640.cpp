// =============================================================================
// FUN_008f6640
// -----------------------------------------------------------------------------
// Stable ID: aa_008f6640
// Address:   0x008f6640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f6640 @ 0x008f6640
// Stable ID: aa_008f6640
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0078ff90, FUN_008f5c40, FUN_008f6640.
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

void __thiscall FUN_008f6640(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  if (*(int **)(param_1 + 0x548) != (int *)0x0) {

    *(uint8_t *)(param_1 + 0x54c) = 0;

    (**(code **)(**(int **)(param_1 + 0x548) + 0x3cc))(0);

    (**(code **)(**(int **)(param_1 + 0x548) + 0x34c))();

  }

  if (*(int **)(param_1 + 0x534) != (int *)0x0) {

    *(uint8_t *)(param_1 + 0x538) = 0;

    (**(code **)(**(int **)(param_1 + 0x534) + 0x34c))();

  }

  FUN_008f5c40();

  FUN_0078ff90(param_2,param_3);

  return;

}
