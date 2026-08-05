// =============================================================================
// FUN_0048ae90
// -----------------------------------------------------------------------------
// Stable ID: aa_0048ae90
// Address:   0x0048ae90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048ae90 @ 0x0048ae90
// Stable ID: aa_0048ae90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0048ae90.
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

void __thiscall FUN_0048ae90(int param_1,int param_2)



{

  *(int *)(param_2 + 0x10) = param_1;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x28) = 0;

  if (*(int *)(param_1 + 0x1c) != 0) {

    *(int *)(*(int *)(param_1 + 0x1c) + 0x28) = param_2;

    *(int *)(param_1 + 0x1c) = param_2;

    return;

  }

  *(int *)(param_1 + 0x18) = param_2;

  *(int *)(param_1 + 0x1c) = param_2;

  return;

}
