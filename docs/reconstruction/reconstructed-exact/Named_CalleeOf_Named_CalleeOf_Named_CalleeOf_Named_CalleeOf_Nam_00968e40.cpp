// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00968e40
// -----------------------------------------------------------------------------
// Stable ID: aa_00968e40
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00968e40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: for×2, return×1.
//  - Notable callees: FUN_00732060×2, FUN_00968e40.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

uint __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00968e40(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  

  iVar3 = *(int *)(param_1 + 0xc4);

  uVar4 = 0;

  for (iVar2 = *(int *)(param_1 + 0xc0); iVar2 != iVar3; iVar2 = iVar2 + 4) {

    uVar1 = FUN_00732060(param_3,param_4);

    uVar4 = uVar4 | uVar1;

  }

  iVar2 = *(int *)(param_1 + 0xd4);

  for (iVar3 = *(int *)(param_1 + 0xd0); iVar3 != iVar2; iVar3 = iVar3 + 4) {

    uVar1 = FUN_00732060(param_3,param_4);

    uVar4 = uVar4 | uVar1;

  }

  return uVar4;

}
