// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00596e70
// -----------------------------------------------------------------------------
// Stable ID: aa_00596e70
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00596e70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00596e70.
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00596e70(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int iVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  piVar1 = DAT_00b05060;

  puStack_8 = &LAB_009a5a68;

  pvStack_c = ExceptionList;

  iVar2 = param_1[4] * 0x20;

  local_4 = 0;

  if ((iVar2 == 0) || ((param_1[3] != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {

    ExceptionList = &pvStack_c;

    DAT_00b05060[2] = DAT_00b05060[2] + param_1[4] * -0x20;

    piVar1[3] = piVar1[3] + iVar2;

  }

  else {

    ExceptionList = &pvStack_c;

    (**(code **)(*DAT_00b05060 + 0x28))(param_1[3],iVar2);

  }

  local_4 = 0xffffffff;

  if (-1 < (int)param_1[2]) {

    (**(code **)(*DAT_00b05060 + 0x14))(*param_1,param_1[2] << 5,0x12);

  }

  ExceptionList = pvStack_c;

  return;

}
