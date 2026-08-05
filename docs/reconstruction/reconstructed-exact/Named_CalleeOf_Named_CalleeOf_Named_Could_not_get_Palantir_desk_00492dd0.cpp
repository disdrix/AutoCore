// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Could_not_get_Palantir_desk_00492dd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00492dd0
// Callee of Named_CalleeOf_Named_Could_not_get_Palantir_desktop_window
// Address:   0x00492dd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Could_not_get_Palantir_desktop_window: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~112 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0096ef70×6, FUN_004933f0×2, CONCAT31, FUN_0044e100, FUN_0048f2d0, FUN_00492dd0, FUN_00497920, FUN_007560d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Could_not_get_Palantir_desktop_window
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_Could_not_get_Palantir_desk_00492dd0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  void *pvVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a0b3b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_007560d0();

  *param_1 = &PTR_FUN_009c7928;

  *(uint8_t *)(param_1 + 0x20) = 1;

  *(uint8_t *)((int)param_1 + 0x81) = 1;

  *(uint8_t *)((int)param_1 + 0x82) = 1;

  *(uint8_t *)((int)param_1 + 0x83) = 1;

  *(uint8_t *)(param_1 + 0x21) = 1;

  *(uint8_t *)((int)param_1 + 0x85) = 1;

  *(uint8_t *)((int)param_1 + 0x86) = 1;

  local_4 = 0;

  *(bool *)((int)param_1 + 0x87) = *(char *)(param_3 + 0x7d) == '\0';

  *(uint8_t *)(param_1 + 0x22) = 1;

  *(uint8_t *)((int)param_1 + 0x89) = 0;

  *(uint8_t *)((int)param_1 + 0x8a) = 0;

  *(uint8_t *)((int)param_1 + 0x8b) = 1;

  *(uint8_t *)(param_1 + 0x23) = 1;

  *(uint8_t *)((int)param_1 + 0x8e) = 1;

  *(uint8_t *)((int)param_1 + 0x8f) = 1;

  *(uint8_t *)(param_1 + 0x24) = 0;

  param_1[0x25] = 0;

  *(uint16_t *)(param_1 + 0x26) = 0xffff;

  FUN_0096ef70();

  local_4._0_1_ = 1;

  *(uint16_t *)(param_1 + 0x28) = 0xffff;

  FUN_0096ef70();

  local_4._0_1_ = 2;

  FUN_0096ef70();

  local_4._0_1_ = 3;

  FUN_0096ef70();

  param_1[0x2f] = param_2;

  param_1[0x2e] = param_3;

  param_1[0x31] = 0;

  param_1[0x32] = 0;

  param_1[0x33] = 0;

  param_1[0x34] = 0;

  local_4._0_1_ = 4;

  param_1[0x35] = &PTR_LAB_009c7744;

  param_1[0x36] = param_1;

  FUN_0096ef70();

  local_4._0_1_ = 5;

  FUN_0096ef70();

  local_4._0_1_ = 6;

  uVar1 = FUN_004933f0();

  param_1[0x3a] = uVar1;

  param_1[0x3b] = 0;

  local_4._0_1_ = 7;

  uVar1 = FUN_004933f0();

  param_1[0x3d] = uVar1;

  param_1[0x3e] = 0;

  *(uint8_t *)(param_1 + 0x3f) = 0;

  param_1[0x41] = 0;

  param_1[0x42] = 0;

  param_1[0x47] = 0;

  param_1[0x48] = 0;

  param_1[0x49] = 0;

  param_1[0x4a] = 0;

  param_1[0x4b] = 0;

  param_1[0x4c] = 0;

  param_1[0x51] = 0;

  param_1[0x52] = 0;

  param_1[0x53] = 0;

  param_1[0x55] = 0;

  param_1[0x56] = 0;

  param_1[0x57] = 0;

  param_1[0x59] = 0;

  param_1[0x5a] = 0;

  param_1[0x5b] = 0;

  local_4._0_1_ = 0xb;

  *(uint8_t *)((int)param_1 + 0x171) = 1;

  param_1[0x5d] = 0;

  param_1[0x5e] = 0;

  param_1[0x5f] = 0;

  iVar2 = FUN_0044e100();

  param_1[100] = iVar2;

  *(uint8_t *)(iVar2 + 0x2d) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[100] + 4) = param_1[100];

  *(uint32_t /* width from decompiler */ *)param_1[100] = param_1[100];

  *(uint32_t /* width from decompiler */ *)(param_1[100] + 8) = param_1[100];

  param_1[0x65] = 0;

  *(bool *)((int)param_1 + 0x172) =

       1 < *(byte *)(*(int *)(*(int *)(param_1[0x2e] + 0xe89c) + 0x28) + 0x799);

  param_1[0x60] = 0;

  param_1[0x61] = 0;

  param_1[0x62] = 0;

  local_4._0_1_ = 0xc;

  param_1[0x1c] = (uint)(*(char *)(param_1[0x2e] + 0x7d) == '\0');

  pvVar3 = operator_new(200);

  local_4._0_1_ = 0xd;

  if (pvVar3 == (void *)0x0) {

    uVar1 = 0;

  }

  else {

    uVar1 = FUN_00497920(param_1[0x2e]);

  }

  local_4 = CONCAT31(local_4._1_3_,0xc);

  param_1[0x40] = uVar1;

  FUN_0048f2d0();

  ExceptionList = local_c;

  return param_1;

}
