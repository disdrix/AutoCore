// =============================================================================
// Named_CalleeOf_CVOGReaction_GiveMission_004111f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004111f0
// Callee of CVOGReaction_GiveMission
// Address:   0x004111f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_GiveMission: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004111f0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_GiveMission
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

void __fastcall Named_CalleeOf_CVOGReaction_GiveMission_004111f0(uint32_t /* width from decompiler */ *param_1)



{

  *(uint8_t *)(param_1 + 0xb) = 0;

  param_1[8] = 0xffffffff;

  param_1[9] = 0xffffffff;

  param_1[10] = 0xffffffff;

  *param_1 = 0xffffffff;

  param_1[1] = 0xffffffff;

  param_1[2] = 0xffffffff;

  param_1[3] = 0xffffffff;

  param_1[4] = 0xffffffff;

  param_1[5] = 0xffffffff;

  param_1[6] = 0xffffffff;

  param_1[7] = 0xffffffff;

  return;

}
