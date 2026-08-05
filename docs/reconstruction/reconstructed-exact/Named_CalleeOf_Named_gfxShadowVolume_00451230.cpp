// =============================================================================
// Named_CalleeOf_Named_gfxShadowVolume_00451230
// -----------------------------------------------------------------------------
// Stable ID: aa_00451230
// Callee of Named_gfxShadowVolume
// Address:   0x00451230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxShadowVolume: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00451230, FUN_00452330, FUN_00455e10.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxShadowVolume
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

void __thiscall Named_CalleeOf_Named_gfxShadowVolume_00451230(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 4);

  if ((iVar1 != 0) &&

     ((uint)((*(int *)(param_1 + 8) - iVar1) / 0xc) <

      (uint)((*(int *)(param_1 + 0xc) - iVar1) / 0xc))) {

    iVar1 = *(int *)(param_1 + 8);

    FUN_00455e10(iVar1,1,param_2,param_1,param_2);

    *(int *)(param_1 + 8) = iVar1 + 0xc;

    return;

  }

  FUN_00452330(&param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2);

  return;

}
