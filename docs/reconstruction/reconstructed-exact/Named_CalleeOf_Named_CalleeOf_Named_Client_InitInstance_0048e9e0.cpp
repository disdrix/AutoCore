// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_0048e9e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0048e9e0
// Callee of Named_CalleeOf_Named_Client_InitInstance
// Address:   0x0048e9e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0048e9e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Client_InitInstance
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_0048e9e0(int param_1)



{

  *(uint16_t *)(param_1 + 0xa8) = 0;

  *(uint16_t *)(param_1 + 0xb0) = 0;

  *(uint16_t *)(param_1 + 0x98) = 0;

  *(uint16_t *)(param_1 + 0xa0) = 0;

  return;

}
