// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00596de0
// -----------------------------------------------------------------------------
// Stable ID: aa_00596de0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00596de0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00596de0.
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

int * __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00596de0(int *param_1,uint param_2)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a5a68;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = -0x80000000;

  piVar2 = DAT_00b05060;

  piVar1 = DAT_00b05060 + 3;

  local_4 = 0;

  iVar3 = param_2 * 0x20;

  if (*piVar1 < iVar3) {

    iVar4 = (**(code **)(*DAT_00b05060 + 0x24))(iVar3);

  }

  else {

    iVar4 = DAT_00b05060[2];

    DAT_00b05060[2] = iVar4 + iVar3;

    piVar2[3] = *piVar1 + param_2 * -0x20;

  }

  *param_1 = iVar4;

  param_1[3] = iVar4;

  param_1[2] = param_2 | 0x80000000;

  param_1[4] = param_2;

  ExceptionList = local_c;

  return param_1;

}
