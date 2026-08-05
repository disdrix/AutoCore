// =============================================================================
// Named_CalleeOf_CVOGHBAIDriver_DoLogic_005cc450
// -----------------------------------------------------------------------------
// Stable ID: aa_005cc450
// Callee of CVOGHBAIDriver_DoLogic
// Address:   0x005cc450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGHBAIDriver_DoLogic: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~5 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005cc450.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGHBAIDriver_DoLogic
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

void __fastcall Named_CalleeOf_CVOGHBAIDriver_DoLogic_005cc450(int *param_1)



{

  (**(code **)(*param_1 + 0x4c))(param_1 + 0x10,1);

  return;

}
