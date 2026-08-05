// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0040cf90
// -----------------------------------------------------------------------------
// Stable ID: aa_0040cf90
// Callee of Named_VOG_DEBUG_STOP (+3 other named callers)
// Address:   0x0040cf90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+3 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0040cf90.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+3 other named callers)
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

void __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_0040cf90(int param_1,float *param_2)



{

  if (((*param_2 != *(float *)(param_1 + 0x90)) || (param_2[1] != *(float *)(param_1 + 0x94))) ||

     (param_2[2] != *(float *)(param_1 + 0x98))) {

    *(float *)(param_1 + 0x90) = *param_2;

    *(float *)(param_1 + 0x94) = param_2[1];

    *(float *)(param_1 + 0x98) = param_2[2];

    if ((*(byte *)(param_1 + 0xbc) & 1) == 0) {

      *(float *)(param_1 + 0x30) = *param_2;

      *(float *)(param_1 + 0x34) = param_2[1];

      *(float *)(param_1 + 0x38) = param_2[2];

      *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 2;

    }

    *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + 1;

  }

  return;

}
