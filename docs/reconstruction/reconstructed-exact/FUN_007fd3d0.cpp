// =============================================================================
// FUN_007fd3d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fd3d0
// Address:   0x007fd3d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fd3d0 @ 0x007fd3d0
// Stable ID: aa_007fd3d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007fd3d0, FUN_0083edf0, FUN_0083ee80.
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

void FUN_007fd3d0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  int unaff_EDI;

  

  if (*(int *)(unaff_EDI + 0x30a0) != 0) {

    FUN_0083edf0();

    FUN_0083ee80(param_1,param_2,param_3,param_4);

    *(uint8_t *)(unaff_EDI + 0x30b6) = 0;

    *(uint8_t *)(unaff_EDI + 0x30b7) = 1;

  }

  return;

}
