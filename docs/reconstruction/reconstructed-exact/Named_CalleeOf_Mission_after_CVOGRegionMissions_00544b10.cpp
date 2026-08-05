// =============================================================================
// Named_CalleeOf_Mission_after_CVOGRegionMissions_00544b10
// -----------------------------------------------------------------------------
// Stable ID: aa_00544b10
// Callee of Mission_after_CVOGRegionMissions
// Address:   0x00544b10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_after_CVOGRegionMissions: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004223b0, FUN_00544590, FUN_00544b10.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Mission_after_CVOGRegionMissions
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

void __thiscall Named_CalleeOf_Mission_after_CVOGRegionMissions_00544b10(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 4);

  if ((iVar1 != 0) &&

     ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x114) <

      (uint)((*(int *)(param_1 + 0xc) - iVar1) / 0x114))) {

    iVar1 = *(int *)(param_1 + 8);

    FUN_004223b0(iVar1,1,param_2,param_1,param_2);

    *(int *)(param_1 + 8) = iVar1 + 0x114;

    return;

  }

  FUN_00544590(&param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2);

  return;

}
