// =============================================================================
// Named_CalleeOf_CVOGReaction_Dispatch_00530710
// -----------------------------------------------------------------------------
// Stable ID: aa_00530710
// Callee of CVOGReaction_Dispatch
// Address:   0x00530710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0053b040×3, FUN_00530710.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_Dispatch
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

void __thiscall Named_CalleeOf_CVOGReaction_Dispatch_00530710(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  

  iVar4 = (int)(short)param_2;

  if ((int)((uint)*(ushort *)(param_1 + 0x60c) + iVar4) < 0) {

    *(uint16_t *)(param_1 + 0x60c) = 0;

  }

  else {

    *(ushort *)(param_1 + 0x60c) = *(ushort *)(param_1 + 0x60c) + (short)param_2;

  }

  param_2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x28c))();

  piVar2 = (int *)FUN_0053b040(&param_2);

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1);

  if (*piVar2 + iVar4 < 0) {

    param_2 = (**(code **)(iVar1 + 0x28c))();

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_0053b040(&param_2);

    *puVar3 = 0;

    return;

  }

  param_2 = (**(code **)(iVar1 + 0x28c))();

  piVar2 = (int *)FUN_0053b040(&param_2);

  *piVar2 = *piVar2 + iVar4;

  return;

}
