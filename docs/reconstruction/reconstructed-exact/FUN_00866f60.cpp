// =============================================================================
// FUN_00866f60
// -----------------------------------------------------------------------------
// Stable ID: aa_00866f60
// Address:   0x00866f60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00866f60 @ 0x00866f60
// Stable ID: aa_00866f60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00866f60.
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

void __thiscall FUN_00866f60(int param_1,uint32_t /* width from decompiler */ param_2)



{

  if (*(int **)(param_1 + 0x530) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x530) + 0x24))(param_2);

  }

  if (*(int **)(param_1 + 0x534) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x534) + 0x24))(param_2);

  }

  if (*(int **)(param_1 + 0x538) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x538) + 0x24))(param_2);

  }

  *(char *)(param_1 + 0x8d) = (char)param_2;

  return;

}
