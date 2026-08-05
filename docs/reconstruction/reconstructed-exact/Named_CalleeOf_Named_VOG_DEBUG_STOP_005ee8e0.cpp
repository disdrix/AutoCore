// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_005ee8e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005ee8e0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x005ee8e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005ee8e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

void Named_CalleeOf_Named_VOG_DEBUG_STOP_005ee8e0(float param_1,int param_2)



{

  *(float *)(param_2 + 4) = param_1 * *(float *)(param_2 + 4);

  *(float *)(param_2 + 0x20) = param_1 * *(float *)(param_2 + 0x20);

  *(float *)(param_2 + 0x30) = param_1 * *(float *)(param_2 + 0x30);

  *(float *)(param_2 + 0x40) = param_1 * *(float *)(param_2 + 0x40);

  *(float *)(param_2 + 0x24) = param_1 * *(float *)(param_2 + 0x24);

  *(float *)(param_2 + 0x34) = param_1 * *(float *)(param_2 + 0x34);

  *(float *)(param_2 + 0x44) = param_1 * *(float *)(param_2 + 0x44);

  *(float *)(param_2 + 0x28) = param_1 * *(float *)(param_2 + 0x28);

  *(float *)(param_2 + 0x38) = param_1 * *(float *)(param_2 + 0x38);

  *(float *)(param_2 + 0x48) = param_1 * *(float *)(param_2 + 0x48);

  return;

}
