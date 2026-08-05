// =============================================================================
// Named_CalleeOf_Named_CloneBase_006c9a50
// -----------------------------------------------------------------------------
// Stable ID: aa_006c9a50
// Callee of Named_CloneBase (+1 other named callers)
// Address:   0x006c9a50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CloneBase: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CloneBase (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006c9a50, FUN_006ce600.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CloneBase (+1 other named callers)
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

int __fastcall Named_CalleeOf_Named_CloneBase_006c9a50(int param_1)



{

  FUN_006ce600();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0x3f800000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0x3f800000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0x3f800000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  return param_1;

}
