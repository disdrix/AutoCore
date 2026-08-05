// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunker_0043f7e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0043f7e0
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunker_SubmitForRende
// Address:   0x0043f7e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunker_SubmitForRende: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0043f7e0, FUN_0043f8a0, FUN_0043fb00.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunker_SubmitForRende
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunker_0043f7e0(uint param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int unaff_EDI;

  

  iVar4 = *(int *)(unaff_EDI + 4);

  if (iVar4 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(int *)(unaff_EDI + 8) - iVar4 >> 4;

  }

  if (uVar2 < param_1) {

    FUN_0043f8a0(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 8),&param_2);

    return;

  }

  if (((iVar4 != 0) && (iVar1 = *(int *)(unaff_EDI + 8), param_1 < (uint)(iVar1 - iVar4 >> 4))) &&

     (iVar4 = param_1 * 0x10 + iVar4, iVar4 != iVar1)) {

    uVar3 = FUN_0043fb00(iVar1,iVar1,iVar4,param_2);

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8) = uVar3;

  }

  return;

}
