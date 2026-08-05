// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxFontImpl_00410490
// -----------------------------------------------------------------------------
// Stable ID: aa_00410490
// Callee of Named_CalleeOf_Named_gfxFontImpl (+1 other named callers)
// Address:   0x00410490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxFontImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_gfxFontImpl (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00410490, memmove.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxFontImpl (+1 other named callers)
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_gfxFontImpl_00410490(int param_1,uint32_t /* width from decompiler */ *param_2,void *param_3,void *param_4)



{

  size_t _Size;

  void *pvVar1;

  

  if (param_3 != param_4) {

    _Size = (*(int *)(param_1 + 8) - (int)param_4 >> 2) * 4;

    pvVar1 = memmove(param_3,param_4,_Size);

    *(void **)(param_1 + 8) = (void *)((int)pvVar1 + _Size);

  }

  *param_2 = param_3;

  return;

}
