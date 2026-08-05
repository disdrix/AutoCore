// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Palantir_00966c10
// -----------------------------------------------------------------------------
// Stable ID: aa_00966c10
// Callee of Named_CalleeOf_Named_Palantir
// Address:   0x00966c10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Palantir: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: for×5, if×1, return×1.
//  - Notable callees: CONCAT31, FUN_0076c4d0, FUN_0076c500, FUN_00966c10.
//  - Return sites: 1.

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

int Named_CalleeOf_Named_CalleeOf_Named_Palantir_00966c10(int param_1)



{

  int iVar1;

  void *unaff_ESI;

  uint32_t /* width from decompiler */ *puVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ac059;

  pvStack_c = ExceptionList;

  DAT_00d1f614 = param_1;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  FUN_0076c500(1000);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = 0;

  _eh_vector_constructor_iterator_

            ((void *)(param_1 + 0x5c),0x14,4,(_func_void_void_ptr *)&LAB_00456b70,FUN_00456b90);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc) = 0;

  local_4 = CONCAT31(local_4._1_3_,2);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc4) = 2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc0) = 0;

  *(uint8_t *)(param_1 + 200) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3d0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3d4) = 0;

  *(uint8_t *)(param_1 + 0x3d8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = 0;

  puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + 0xcc);

  for (iVar1 = 0x4c; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + 0x1fc);

  for (iVar1 = 0x4c; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + 0x32c);

  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + 900);

  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + 0x3dc);

  for (iVar1 = 0x58; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  FUN_0076c4d0();

  iVar1 = (**(code **)(*(int *)*DAT_00d1f044 + 0x1d8))

                    ((int *)*DAT_00d1f044,5,(uint32_t /* width from decompiler */ *)(param_1 + 0x3d4));

  *(uint8_t *)(param_1 + 0x3d8) = 0;

  if (iVar1 < 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3d4) = 0;

  }

  ExceptionList = unaff_ESI;

  return param_1;

}
