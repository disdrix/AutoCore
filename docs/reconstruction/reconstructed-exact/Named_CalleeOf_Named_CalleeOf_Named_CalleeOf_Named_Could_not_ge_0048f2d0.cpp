// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Could_not_ge_0048f2d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0048f2d0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Could_not_get_Palantir_desk
// Address:   0x0048f2d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Could_not_get_Palantir_desk: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0048f2d0, FUN_00497c80.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_Could_not_get_Palantir_desk
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Could_not_ge_0048f2d0(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  float fVar2;

  

  if (*(int *)(param_1 + 0x100) != 0) {

    FUN_00497c80();

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10c) = DAT_00aaa7ac;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x110) = DAT_00aaa884;

  uVar1 = DAT_009c7748;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = _DAT_009c774c;

  fVar2 = g_flOne;

  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = uVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = uVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x178) = 0;

  *(float *)(param_1 + 0x6c) = fVar2;

  return;

}
