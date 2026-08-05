// =============================================================================
// Named_CalleeOf_Named_matD3DXMathEmu_00973370
// -----------------------------------------------------------------------------
// Stable ID: aa_00973370
// Callee of Named_matD3DXMathEmu
// Address:   0x00973370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_matD3DXMathEmu: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007663b0, FUN_00973370.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_matD3DXMathEmu
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

void Named_CalleeOf_Named_matD3DXMathEmu_00973370(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *unaff_EDI;

  

  FUN_007663b0(&DAT_00afdf60);

  *param_1 = *unaff_EDI;

  param_1[1] = unaff_EDI[1];

  param_1[2] = unaff_EDI[2];

  param_1[3] = unaff_EDI[3];

  return;

}
