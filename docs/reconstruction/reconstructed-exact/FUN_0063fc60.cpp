// =============================================================================
// FUN_0063fc60
// -----------------------------------------------------------------------------
// Stable ID: aa_0063fc60
// Address:   0x0063fc60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0063fc60 @ 0x0063fc60
// Stable ID: aa_0063fc60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00632560, FUN_0063fc60.
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

void FUN_0063fc60(uint8_t *param_1,int param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  if ((*(int *)(param_2 + 0x20) != 0) && (*(int *)(param_4 + 8) == 2)) {

    FUN_00632560(*(int *)(param_2 + 0x20),*(uint32_t /* width from decompiler */ *)(param_4 + 0x18));

    *param_1 = 1;

    return;

  }

  *param_1 = 0;

  return;

}
