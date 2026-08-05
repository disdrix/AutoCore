// =============================================================================
// FUN_008cafd0
// -----------------------------------------------------------------------------
// Stable ID: aa_008cafd0
// Address:   0x008cafd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008cafd0 @ 0x008cafd0
// Stable ID: aa_008cafd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_008cafd0.
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

void __fastcall FUN_008cafd0(int param_1)



{

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4bc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x504) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x508) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x924) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x928) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x92c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x930) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x934) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x938) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x93c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x940) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x944) = 0;

  if (*(int **)(param_1 + 0x948) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x948) + 0x458))();

  }

  if (*(int **)(param_1 + 0x94c) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x94c) + 0x458))();

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x948) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x94c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x950) = 0;

  return;

}
