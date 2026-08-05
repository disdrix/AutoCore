// =============================================================================
// Named_CalleeOf_Named_gfxGeometryPiece_0044be40
// -----------------------------------------------------------------------------
// Stable ID: aa_0044be40
// Callee of Named_gfxGeometryPiece (+1 other named callers)
// Address:   0x0044be40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxGeometryPiece: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxGeometryPiece (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~6 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0044be40, FUN_00962940.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxGeometryPiece (+1 other named callers)
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

void Named_CalleeOf_Named_gfxGeometryPiece_0044be40(uint32_t /* width from decompiler */ param_1)



{

  int in_EAX;

  

  FUN_00962940(in_EAX,param_1,0,*(uint32_t /* width from decompiler */ *)(in_EAX + 0x1c));

  return;

}
