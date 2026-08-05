// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_004f2d70
// -----------------------------------------------------------------------------
// Stable ID: aa_004f2d70
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x004f2d70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004f2d70.
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

void __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_004f2d70(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  *param_1 = *param_2;

  param_1[1] = param_2[1];

  param_1[2] = param_2[2];

  param_1[3] = param_2[3];

  param_1[4] = param_2[4];

  param_1[5] = param_2[5];

  param_1[6] = param_2[6];

  param_1[7] = param_2[7];

  param_1[8] = param_2[8];

  param_1[9] = param_2[9];

  param_1[10] = param_2[10];

  param_1[0xb] = param_2[0xb];

  return;

}
