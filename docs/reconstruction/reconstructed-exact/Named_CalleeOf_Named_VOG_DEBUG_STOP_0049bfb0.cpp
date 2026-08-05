// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0049bfb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0049bfb0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x0049bfb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_0049bfb0.
//  - Return sites: 2.

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

void Named_CalleeOf_Named_VOG_DEBUG_STOP_0049bfb0(uint32_t /* width from decompiler */ *param_1,int *param_2,int *param_3,int *param_4,int *param_5)



{

  int *piVar1;

  

  if (param_2 == param_3) {

    *param_1 = param_4;

    return;

  }

  do {

    piVar1 = param_4;

    if (*param_2 != *param_5) {

      piVar1 = param_4 + 1;

      *param_4 = *param_2;

    }

    param_2 = param_2 + 1;

    param_4 = piVar1;

  } while (param_2 != param_3);

  *param_1 = piVar1;

  return;

}
