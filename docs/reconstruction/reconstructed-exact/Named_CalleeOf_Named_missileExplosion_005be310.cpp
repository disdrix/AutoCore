// =============================================================================
// Named_CalleeOf_Named_missileExplosion_005be310
// -----------------------------------------------------------------------------
// Stable ID: aa_005be310
// Callee of Named_missileExplosion (+1 other named callers)
// Address:   0x005be310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_missileExplosion: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_missileExplosion (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005bbc50, FUN_005be310.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_missileExplosion (+1 other named callers)
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

void __thiscall Named_CalleeOf_Named_missileExplosion_005be310(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  FUN_005bbc50();

  if (param_2 != (uint32_t /* width from decompiler */ *)0x0) {

    *param_2 = *param_1;

    *param_1 = param_2;

  }

  return;

}
