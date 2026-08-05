// =============================================================================
// Named_CalleeOf_Named_Sending_Challenge_Response_8x_0042c460
// -----------------------------------------------------------------------------
// Stable ID: aa_0042c460
// Callee of Named_Sending_Challenge_Response_8x (+1 other named callers)
// Address:   0x0042c460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Sending_Challenge_Response_8x: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_Sending_Challenge_Response_8x (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0077fb80×3, FUN_0042c460, FUN_0077dcb0, FUN_0077f960.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Sending_Challenge_Response_8x (+1 other named callers)
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_Sending_Challenge_Response_8x_0042c460(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ local_130 [8];

  uint8_t local_110 [272];

  

  FUN_0077dcb0(local_110);

  FUN_0077fb80(local_110,param_2,0x14);

  FUN_0077fb80(local_110,param_3,8);

  FUN_0077fb80(local_110,param_1 + 0x84,0xc);

  FUN_0077f960(local_110,local_130);

  return local_130[0];

}
