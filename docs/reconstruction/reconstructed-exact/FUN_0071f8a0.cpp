// =============================================================================
// FUN_0071f8a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071f8a0
// Address:   0x0071f8a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071f8a0 @ 0x0071f8a0
// Stable ID: aa_0071f8a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0071f8a0.
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

uint32_t /* width from decompiler */ __thiscall FUN_0071f8a0(int param_1,uint param_2)



{

  if ((*(int *)(param_1 + 0x10) != 0) && (param_2 < *(uint *)(param_1 + 0x1c))) {

    return *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + param_2 * 4);

  }

  return 0;

}
