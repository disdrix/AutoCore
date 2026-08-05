// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGTacArc_Initial_00744cc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00744cc0
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGTacArc_InitializeMesh
// Address:   0x00744cc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGTacArc_InitializeMesh: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0044d9b0, FUN_0044e8c0, FUN_00744cc0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGTacArc_InitializeMesh
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGTacArc_Initial_00744cc0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int unaff_ESI;

  int local_4;

  

  iVar1 = DAT_00d1f050;

  uVar2 = 0;

  if (param_1 != *(int *)(unaff_ESI + 0x54)) {

    if (DAT_00d1f050 != 0) {

      FUN_0044e8c0(&local_4);

      if (local_4 != *(int *)(iVar1 + 8)) {

        *(int *)(local_4 + 0x10) = *(int *)(local_4 + 0x10) + -1;

      }

    }

    FUN_0044d9b0(param_1);

    uVar2 = 1;

  }

  return uVar2;

}
