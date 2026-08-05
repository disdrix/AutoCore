// =============================================================================
// Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x_00652d00
// -----------------------------------------------------------------------------
// Stable ID: aa_00652d00
// Callee of Named_SERVER_GOT_GIGO_0x_x
// Address:   0x00652d00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_SERVER_GOT_GIGO_0x_x: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~6 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00652910, FUN_00652d00.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_SERVER_GOT_GIGO_0x_x
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

void Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x_00652d00(int param_1)



{

  FUN_00652910(param_1,4,3);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  return;

}
