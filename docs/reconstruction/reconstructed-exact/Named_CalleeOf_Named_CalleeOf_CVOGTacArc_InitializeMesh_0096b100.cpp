// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGTacArc_InitializeMesh_0096b100
// -----------------------------------------------------------------------------
// Stable ID: aa_0096b100
// Callee of Named_CalleeOf_CVOGTacArc_InitializeMesh
// Address:   0x0096b100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGTacArc_InitializeMesh: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0096b100, FUN_00972cc0, _aligned_malloc.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGTacArc_InitializeMesh
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

void Named_CalleeOf_Named_CalleeOf_CVOGTacArc_InitializeMesh_0096b100(void)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ extraout_EDX;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  pvVar1 = _aligned_malloc(0xc0,0x10);

  uVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_00972cc0();

    uVar2 = extraout_EDX;

  }

  *unaff_ESI = uVar2;

  unaff_ESI[1] = 3;

  unaff_ESI[3] = 0;

  unaff_ESI[4] = 0;

  unaff_ESI[5] = 0;

  unaff_ESI[6] = 0;

  unaff_ESI[7] = 0xffffffff;

  return;

}
