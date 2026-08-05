// =============================================================================
// Named_CalleeOf_Client_DebugDumpEntityCombatStats_00569dc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00569dc0
// Callee of Client_DebugDumpEntityCombatStats
// Address:   0x00569dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_DebugDumpEntityCombatStats: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~4 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00569dc0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_DebugDumpEntityCombatStats
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

float10 __fastcall Named_CalleeOf_Client_DebugDumpEntityCombatStats_00569dc0(int param_1)



{

  return (float10)(int)*(short *)(param_1 + 0x10c) + (float10)*(float *)(param_1 + 0x114);

}
