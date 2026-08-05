// =============================================================================
// FUN_0055e970
// -----------------------------------------------------------------------------
// Stable ID: aa_0055e970
// Address:   0x0055e970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055e970 @ 0x0055e970
// Stable ID: aa_0055e970
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0055e970, FUN_005b3370.
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

void __thiscall FUN_0055e970(int param_1,uint32_t /* width from decompiler */ param_2)



{

  if (*(uint *)(param_1 + 0x88) == (*(uint *)(param_1 + 0x8c) & 0x7fffffff)) {

    FUN_005b3370((int *)(param_1 + 0x84),4);

  }

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x84) + *(int *)(param_1 + 0x88) * 4) = param_2;

  *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;

  return;

}
