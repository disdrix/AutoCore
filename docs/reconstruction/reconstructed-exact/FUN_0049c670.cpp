// =============================================================================
// FUN_0049c670
// -----------------------------------------------------------------------------
// Stable ID: aa_0049c670
// Address:   0x0049c670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0049c670 @ 0x0049c670
// Stable ID: aa_0049c670
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0049c670, free.
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

void __fastcall FUN_0049c670(int param_1)



{

  if (*(void **)(param_1 + 0x118) != (void *)0x0) {

    free(*(void **)(param_1 + 0x118));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x118) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x11c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x120) = 0;

  return;

}
