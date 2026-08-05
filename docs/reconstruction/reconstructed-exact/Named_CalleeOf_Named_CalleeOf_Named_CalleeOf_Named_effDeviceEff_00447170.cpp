// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_effDeviceEff_00447170
// -----------------------------------------------------------------------------
// Stable ID: aa_00447170
// Callee of Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect
// Address:   0x00447170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_004451c0, FUN_00447170, FUN_00447260.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_effDeviceEff_00447170(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009be82e;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = *param_2;

  param_1[1] = param_2[1];

  param_1[2] = param_2[2];

  param_1[3] = param_2[3];

  *(uint8_t *)(param_1 + 4) = *(uint8_t *)(param_2 + 4);

  *(uint8_t *)((int)param_1 + 0x11) = *(uint8_t *)((int)param_2 + 0x11);

  param_1[5] = param_2[5];

  param_1[6] = param_2[6];

  param_1[7] = param_2[7];

  param_1[8] = param_2[8];

  param_1[9] = param_2[9];

  param_1[10] = param_2[10];

  param_1[0xb] = param_2[0xb];

  param_1[0xc] = param_2[0xc];

  param_1[0xd] = param_2[0xd];

  param_1[0xe] = param_2[0xe];

  param_1[0xf] = param_2[0xf];

  param_1[0x10] = param_2[0x10];

  puVar2 = param_2 + 0x11;

  puVar3 = param_1 + 0x11;

  for (iVar1 = 0x1a; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  FUN_004451c0(param_1 + 0x2b,param_2 + 0x2b);

  local_4 = 0;

  FUN_00447260(param_1 + 0x31);

  ExceptionList = local_c;

  return param_1;

}
