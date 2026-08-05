// =============================================================================
// FUN_004698c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004698c0
// Address:   0x004698c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004698c0 @ 0x004698c0
// Stable ID: aa_004698c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004698c0.
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

void __fastcall FUN_004698c0(int param_1)



{

  if (1 < *(int *)(param_1 + 0x1c)) {

    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;

    return;

  }

  if (*(void **)(param_1 + 0x18) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x18));

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  }

  return;

}
