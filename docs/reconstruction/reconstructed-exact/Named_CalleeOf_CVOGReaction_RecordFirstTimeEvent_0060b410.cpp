// =============================================================================
// Named_CalleeOf_CVOGReaction_RecordFirstTimeEvent_0060b410
// -----------------------------------------------------------------------------
// Stable ID: aa_0060b410
// Callee of CVOGReaction_RecordFirstTimeEvent
// Address:   0x0060b410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_RecordFirstTimeEvent: event/reaction helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00535ed0, FUN_0060b410.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_RecordFirstTimeEvent
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

void __thiscall Named_CalleeOf_CVOGReaction_RecordFirstTimeEvent_0060b410(int *param_1,char param_2)



{

  if ((param_2 != '\0') && (param_1[6] != 0)) {

    FUN_00535ed0(0);

  }

  (**(code **)(*param_1 + 0x18))(1,1);

  return;

}
