// =============================================================================
// FUN_004949a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004949a0
// Address:   0x004949a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004949a0 @ 0x004949a0
// Stable ID: aa_004949a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00402090, FUN_0040cf90, FUN_0040d1a0, FUN_004949a0, FUN_005b7ea0, FUN_0076e3c0, FUN_00972cc0.
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

void FUN_004949a0(uint32_t /* width from decompiler */ param_1,float param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4)



{

  int *piVar1;

  int local_24;

  void *local_20;

  uint8_t local_1c [16];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a0bfa;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  local_20 = operator_new(0xc0);

  local_4 = 0;

  if (local_20 == (void *)0x0) {

    local_24 = 0;

  }

  else {

    local_24 = FUN_00972cc0();

  }

  local_4 = 0xffffffff;

  if (((param_2 != *(float *)(local_24 + 0x9c)) && (param_2 != *(float *)(local_24 + 0xa0))) &&

     (param_2 != *(float *)(local_24 + 0xa4))) {

    *(float *)(local_24 + 0xa4) = param_2;

    *(float *)(local_24 + 0xa0) = param_2;

    *(float *)(local_24 + 0x9c) = param_2;

    *(uint32_t /* width from decompiler */ *)(local_24 + 0xbc) = 0xffffffff;

    *(int *)(local_24 + 0xb4) = *(int *)(local_24 + 0xb4) + 1;

    *(uint8_t *)(local_24 + 0xb8) = 0;

  }

  FUN_0040cf90(param_3);

  FUN_0076e3c0(local_1c,param_4,0,0);

  FUN_0040d1a0(local_1c);

  piVar1 = &local_24;

  FUN_00402090(*param_3,param_3[2]);

  FUN_005b7ea0(piVar1,param_1);

  ExceptionList = local_c;

  return;

}
