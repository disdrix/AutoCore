// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx_005b3420
// -----------------------------------------------------------------------------
// Stable ID: aa_005b3420
// Callee of Named_CalleeOf_Drive_NDRiver_fx
// Address:   0x005b3420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_NDRiver_fx: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005b3420, FUN_0075b390, FUN_0075b3b0, FUN_0075b450, FUN_0075bf40, FUN_00968a50.
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx_005b3420(int param_1)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ local_14;

  void *local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a67db;

  pvStack_c = ExceptionList;

  local_14 = 0x100;

  local_10 = (void *)0x100;

  ExceptionList = &pvStack_c;

  pvVar1 = operator_new(0x198);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_00968a50();

  }

  *(int *)(param_1 + 0x158) = iVar2;

  *(int *)(iVar2 + 4) = param_1;

  local_4 = 0xffffffff;

  FUN_0075b3b0(0x3f000000);

  FUN_0075bf40(DAT_00afdf08);

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x158) + 0x180) = 0;

  FUN_0075b450();

  FUN_0075b390(0x47c35000);

  iVar2 = *(int *)(param_1 + 0x158);

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0xec) = 0;

  *(uint8_t *)(iVar2 + 0x48) = 1;

  *(uint8_t *)(iVar2 + 0xcc) = 1;

  (**(code **)(**(int **)(param_1 + 0x158) + 0x18))(&local_14);

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x158) + 0x108) = 0;

  *(uint8_t *)(*(int *)(param_1 + 0x158) + 400) = 1;

  ExceptionList = local_10;

  return;

}
