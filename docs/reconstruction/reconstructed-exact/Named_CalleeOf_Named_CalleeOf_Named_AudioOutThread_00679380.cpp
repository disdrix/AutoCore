// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_AudioOutThread_00679380
// -----------------------------------------------------------------------------
// Stable ID: aa_00679380
// Callee of Named_CalleeOf_Named_AudioOutThread
// Address:   0x00679380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_AudioOutThread: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00679380.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_AudioOutThread
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_AudioOutThread_00679380(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  if (*(int *)(param_1 + 0x14) != 0) {

    (**(code **)(**(int **)(param_1 + 0x14) + 0x4c))

              (*(int **)(param_1 + 0x14),*param_2,param_2[1],param_2[2],0);

    return 0;

  }

  return 0xffffffff;

}
