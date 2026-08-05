// =============================================================================
// FUN_0061d400
// -----------------------------------------------------------------------------
// Stable ID: aa_0061d400
// Address:   0x0061d400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0061d400 @ 0x0061d400
// Stable ID: aa_0061d400
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005787a0, FUN_0061d400.
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

uint32_t /* width from decompiler */ __thiscall FUN_0061d400(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  if (((char)param_1[8] == '\0') && ((char)param_1[0x1b0] == '\0')) {

    *(uint8_t *)(param_1 + 0x1b0) = 1;

  }

  (**(code **)(*param_1 + 0x50))();

  FUN_005787a0(param_2);

  return param_2;

}
