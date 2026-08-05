// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx_004c1960
// -----------------------------------------------------------------------------
// Stable ID: aa_004c1960
// Callee of Named_CalleeOf_Drive_NDRiver_fx
// Address:   0x004c1960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_NDRiver_fx: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004c0fe0, FUN_004c1800, FUN_004c1960, FUN_007567b0, FUN_0075bf40.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_NDRiver_fx
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx_004c1960(int param_1)



{

  int iVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a1ae5;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pvVar2 = operator_new(0x40);

  local_4 = 0;

  if (pvVar2 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_004c1800(param_1);

  }

  local_4 = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc4) = uVar3;

  FUN_004c0fe0();

  iVar1 = *(int *)(param_1 + 0xc4);

  if (*(char *)(iVar1 + 0x10) != '\x01') {

    FUN_0075bf40(0);

    FUN_007567b0(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x38),0);

    *(uint8_t *)(iVar1 + 0x10) = 1;

  }

  ExceptionList = local_c;

  return;

}
