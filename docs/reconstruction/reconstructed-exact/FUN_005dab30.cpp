// =============================================================================
// FUN_005dab30
// -----------------------------------------------------------------------------
// Stable ID: aa_005dab30
// Address:   0x005dab30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005dab30 @ 0x005dab30
// Stable ID: aa_005dab30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005da0a0, FUN_005dab30.
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

void FUN_005dab30(int param_1)



{

  char cVar1;

  

  cVar1 = FUN_005da0a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x14),param_1 + 0x1c,*(uint32_t /* width from decompiler */ *)(param_1 + 8),

                       *(uint32_t /* width from decompiler */ *)(param_1 + 0xc));

  if (cVar1 == '\0') {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 1;

  }

  return;

}
