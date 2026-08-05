// =============================================================================
// Named_CalleeOf_Named_packetSizeMultiplier_004a6930
// -----------------------------------------------------------------------------
// Stable ID: aa_004a6930
// Callee of Named_packetSizeMultiplier (+2 other named callers)
// Address:   0x004a6930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_packetSizeMultiplier: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_packetSizeMultiplier (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004a6930.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_packetSizeMultiplier (+2 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined * Named_CalleeOf_Named_packetSizeMultiplier_004a6930(uint32_t /* width from decompiler */ *param_1)



{

  if ((_DAT_00b03624 & 1) == 0) {

    _DAT_00b03624 = _DAT_00b03624 | 1;

  }

  _DAT_00b03618 = *param_1;

  _DAT_00b0361c = param_1[1];

  _DAT_00b03620 = param_1[2];

  return &DAT_00b03618;

}
