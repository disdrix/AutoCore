// =============================================================================
// FUN_007b69e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007b69e0
// Address:   0x007b69e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b69e0 @ 0x007b69e0
// Stable ID: aa_007b69e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_007b69e0, FUN_009717a0, FUN_00989e00.
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

uint32_t /* width from decompiler */ __fastcall FUN_007b69e0(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ local_4;

  

  if (*(int *)(DAT_00d1f050 + 0x6c) != 0) {

    local_4 = param_1;

    FUN_00989e00(&local_4,param_1);

    FUN_009717a0(&local_4);

    return 1;

  }

  return 0;

}
