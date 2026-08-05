// =============================================================================
// FUN_008f65d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008f65d0
// Address:   0x008f65d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f65d0 @ 0x008f65d0
// Stable ID: aa_008f65d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_008f5e20×2, FUN_007906a0, FUN_008f65d0.
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

void __thiscall FUN_008f65d0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  if ((*(int **)(param_1 + 0x548) != (int *)0x0) && (*(char *)(param_1 + 0x54c) != '\0')) {

    *(uint8_t *)(param_1 + 0x54c) = 0;

    (**(code **)(**(int **)(param_1 + 0x548) + 0x34c))();

    FUN_008f5e20();

  }

  if ((*(int **)(param_1 + 0x534) != (int *)0x0) && (*(char *)(param_1 + 0x538) != '\0')) {

    *(uint8_t *)(param_1 + 0x538) = 0;

    (**(code **)(**(int **)(param_1 + 0x534) + 0x34c))();

    FUN_008f5e20();

  }

  FUN_007906a0(param_2,param_3);

  return;

}
