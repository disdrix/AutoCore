// =============================================================================
// Named_CalleeOf_Skill_Skills_004c3300
// -----------------------------------------------------------------------------
// Stable ID: aa_004c3300
// Callee of Skill_Skills (+1 other named callers)
// Address:   0x004c3300  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_Skills: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Skill_Skills (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~4 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004c3300.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Skill_Skills (+1 other named callers)
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

bool __thiscall Named_CalleeOf_Skill_Skills_004c3300(int param_1,char param_2)



{

  return (*(uint *)(param_1 + 0x160) & 1 << (param_2 + 1U & 0x1f)) != 0;

}
