// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00970bb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00970bb0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00970bb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0043d570, FUN_0076c330, FUN_00970910, FUN_00970bb0.
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00970bb0(uint32_t /* width from decompiler */ param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int iVar4;

  int *unaff_EBX;

  int unaff_ESI;

  float10 fVar5;

  

  fVar5 = (float10)FUN_0076c330();

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_0043d570();

  *puVar2 = unaff_EBX;

  puVar2[1] = (float)fVar5;

  iVar3 = FUN_00970910(param_1);

  iVar4 = (**(code **)(*unaff_EBX + 0x1c))();

  piVar1 = (int *)(unaff_ESI + 0xe8 + iVar3 * 4);

  *piVar1 = *piVar1 + iVar4;

  piVar1 = (int *)(unaff_ESI + 0xfc + iVar3 * 4);

  *piVar1 = *piVar1 + 1;

  return;

}
