// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Palantir_007334a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007334a0
// Callee of Named_CalleeOf_Named_Palantir
// Address:   0x007334a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Palantir: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_0072a5a0, FUN_007334a0, FUN_00746400.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Palantir
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_Palantir_007334a0(void)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad5e0;

  local_c = ExceptionList;

  if (DAT_00d1a600 != 0) {

    return 1;

  }

  ExceptionList = &local_c;

  pvVar1 = operator_new(0x20);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0072a5a0(pvVar1);

  }

  local_4 = 0xffffffff;

  DAT_00d1a600 = iVar2;

  if (iVar2 == 0) {

    ExceptionList = local_c;

    return 0xffffffff;

  }

  *(uint8_t *)(iVar2 + 4) = 1;

  *(uint8_t *)(iVar2 + 6) = 1;

  *(uint8_t *)(iVar2 + 7) = 1;

  *(code **)(iVar2 + 0x1c) = FUN_004691f0;

  uVar3 = FUN_00746400(iVar2);

  ExceptionList = local_c;

  return uVar3;

}
