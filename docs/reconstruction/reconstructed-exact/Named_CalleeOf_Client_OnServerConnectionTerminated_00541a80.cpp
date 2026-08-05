// =============================================================================
// Named_CalleeOf_Client_OnServerConnectionTerminated_00541a80
// -----------------------------------------------------------------------------
// Stable ID: aa_00541a80
// Callee of Client_OnServerConnectionTerminated (+1 other named callers)
// Address:   0x00541a80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_OnServerConnectionTerminated: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_OnServerConnectionTerminated (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00541950, FUN_00541a80.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_OnServerConnectionTerminated (+1 other named callers)
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Client_OnServerConnectionTerminated_00541a80(int param_1)



{

  if (*(int *)(*(int *)(param_1 + 0xf1c) + 0xc) < 1) {

    FUN_00541950();

  }

  return *(uint32_t /* width from decompiler */ *)(param_1 + 0xf1c);

}
