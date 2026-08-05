// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxVertexBufferImpl_0045f7a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0045f7a0
// Callee of Named_CalleeOf_Named_gfxVertexBufferImpl
// Address:   0x0045f7a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxVertexBufferImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0045f7a0, FUN_00460010, FUN_00460b00.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxVertexBufferImpl
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_gfxVertexBufferImpl_0045f7a0(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  int unaff_ESI;

  

  iVar1 = *(int *)(unaff_ESI + 4);

  if ((iVar1 != 0) &&

     ((uint)(*(int *)(unaff_ESI + 8) - iVar1 >> 5) < (uint)(*(int *)(unaff_ESI + 0xc) - iVar1 >> 5))

     ) {

    iVar1 = *(int *)(unaff_ESI + 8);

    FUN_00460b00(iVar1,param_1);

    *(int *)(unaff_ESI + 8) = iVar1 + 0x20;

    return;

  }

  FUN_00460010(unaff_ESI,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),1);

  return;

}
