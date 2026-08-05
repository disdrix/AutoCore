// READABILITY (auto CF):
//  - Body size: ~4 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CVOGObjectiveRequirement_Patrol_GetSomething.
//  - Return sites: 1.

// =============================================================================
// CVOGObjectiveRequirement_Patrol_GetSomething
// -----------------------------------------------------------------------------
// Stable ID: aa_0060e9e0
// Address:   0x0060e9e0  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

uint32_t /* width from decompiler */ __fastcall CVOGObjectiveRequirement_Patrol_GetSomething(int param_1)



{

  return *(uint32_t /* width from decompiler */ *)(param_1 + 0x28);

}
