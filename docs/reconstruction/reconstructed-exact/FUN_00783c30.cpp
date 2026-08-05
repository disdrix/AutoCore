// =============================================================================
// FUN_00783c30
// -----------------------------------------------------------------------------
// Stable ID: aa_00783c30
// Address:   0x00783c30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00783c30 @ 0x00783c30
// Stable ID: aa_00783c30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT22, FUN_00783c30.
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

void __thiscall FUN_00783c30(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = CONCAT22(local_4._2_2_,*(uint16_t *)(param_1 + 2));

  *param_2 = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

  param_2[1] = local_4;

  return;

}
