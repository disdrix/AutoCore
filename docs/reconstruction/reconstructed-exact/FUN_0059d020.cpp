// =============================================================================
// FUN_0059d020
// -----------------------------------------------------------------------------
// Stable ID: aa_0059d020
// Address:   0x0059d020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0059d020 @ 0x0059d020
// Stable ID: aa_0059d020
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0059d020, FUN_0059d060, free.
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

void __fastcall FUN_0059d020(int param_1)



{

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  FUN_0059d060();

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x10) != (uint32_t /* width from decompiler */ *)0x0) {

    free((void *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x10));

    operator_delete__(*(void **)(param_1 + 0x10));

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  }

  return;

}
