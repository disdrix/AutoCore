// =============================================================================
// FUN_00494850
// -----------------------------------------------------------------------------
// Stable ID: aa_00494850
// Address:   0x00494850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00494850 @ 0x00494850
// Stable ID: aa_00494850
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00402090, FUN_0040cf90, FUN_0040d1a0, FUN_00494850, FUN_004e87d0, FUN_004e88e0, FUN_005b7ea0, FUN_00972cc0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void FUN_00494850(int param_1)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  int local_30;

  void *local_2c;

  uint32_t /* width from decompiler */ local_28 [2];

  uint32_t /* width from decompiler */ local_20;

  uint8_t local_1c [16];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a0be5;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  local_2c = operator_new(0xc0);

  local_4 = 0;

  if (local_2c == (void *)0x0) {

    local_30 = 0;

  }

  else {

    local_30 = FUN_00972cc0();

  }

  fVar1 = *(float *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xbc + param_1);

  local_4 = 0xffffffff;

  if (((fVar1 != *(float *)(local_30 + 0x9c)) && (fVar1 != *(float *)(local_30 + 0xa0))) &&

     (fVar1 != *(float *)(local_30 + 0xa4))) {

    *(float *)(local_30 + 0xa4) = fVar1;

    *(float *)(local_30 + 0xa0) = fVar1;

    *(float *)(local_30 + 0x9c) = fVar1;

    *(uint32_t /* width from decompiler */ *)(local_30 + 0xbc) = 0xffffffff;

    *(int *)(local_30 + 0xb4) = *(int *)(local_30 + 0xb4) + 1;

    *(uint8_t *)(local_30 + 0xb8) = 0;

  }

  FUN_004e88e0(local_28,*(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1);

  FUN_0040cf90(local_28);

  uVar2 = FUN_004e87d0(local_1c,*(int *)(*(int *)(param_1 + 4) + 4) + 0x94 + param_1);

  FUN_0040d1a0(uVar2);

  uVar2 = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x34);

  piVar3 = &local_30;

  FUN_00402090(local_28[0],local_20);

  FUN_005b7ea0(piVar3,uVar2);

  ExceptionList = local_c;

  return;

}
