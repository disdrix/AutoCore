// =============================================================================
// Named_CalleeOf_Named_VOGMapText_007989b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007989b0
// Callee of Named_VOGMapText (+2 other named callers)
// Address:   0x007989b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOGMapText: map/sector helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOGMapText (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_007989b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOGMapText (+2 other named callers)
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

void __fastcall Named_CalleeOf_Named_VOGMapText_007989b0(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  

  piVar1 = (int *)param_1[2];

  *param_1 = &PTR_FUN_00a98338;

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 8))(piVar1);

    param_1[2] = 0;

  }

  piVar1 = (int *)param_1[1];

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 8))(piVar1);

    param_1[1] = 0;

  }

  operator_delete__((void *)param_1[4]);

  return;

}
