// =============================================================================
// FUN_0049aa00
// -----------------------------------------------------------------------------
// Stable ID: aa_0049aa00
// Address:   0x0049aa00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0049aa00 @ 0x0049aa00
// Stable ID: aa_0049aa00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0049a0d0, FUN_0049aa00.
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

void __thiscall FUN_0049aa00(int param_1,int param_2)



{

  if ((*(int **)(param_1 + 0x184) != (int *)0x0) && (*(char *)(param_1 + 0x1dd) != '\0')) {

    (**(code **)(**(int **)(param_1 + 0x184) + 0x3c))(param_2 + 0x10);

    *(uint8_t *)(param_1 + 0x1dd) = 0;

  }

  if (*(int *)(param_1 + 0x180) == 0) {

    FUN_0049a0d0(param_1);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x180) = DAT_00b035d0;

    return;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x180) = DAT_00b035d0;

  return;

}
