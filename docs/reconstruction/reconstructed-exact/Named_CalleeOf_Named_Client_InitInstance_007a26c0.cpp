// =============================================================================
// Named_CalleeOf_Named_Client_InitInstance_007a26c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007a26c0
// Callee of Named_Client_InitInstance (+1 other named callers)
// Address:   0x007a26c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_Client_InitInstance (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~121 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CONCAT31, FUN_00424bf0, FUN_004933f0, FUN_007543b0, FUN_007a26c0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Client_InitInstance (+1 other named callers)
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_Client_InitInstance_007a26c0(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *pvVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b0088;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_007543b0(param_1);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a97170;

  FUN_00424bf0();

  param_1[0x57] = DAT_00a0f718;

  fVar1 = g_flOne;

  param_1[0x4a] = 0;

  *(uint8_t *)(param_1 + 0x4b) = 0;

  param_1[0x59] = 0;

  param_1[0x5a] = 0;

  param_1[0x5b] = 0;

  param_1[0x5c] = 0;

  param_1[0x5d] = 0;

  param_1[0x5e] = 0;

  param_1[0x5f] = 0;

  param_1[0x60] = 0;

  param_1[0x61] = 0;

  param_1[0x62] = 0;

  param_1[99] = 0;

  param_1[100] = 0;

  param_1[0x65] = 0;

  param_1[0x66] = 0;

  param_1[0x67] = 0;

  param_1[0x68] = 0;

  param_1[0x69] = 0;

  param_1[0x6a] = 0;

  param_1[0x6b] = 0;

  param_1[0x6c] = 0;

  param_1[0x6d] = 0;

  param_1[0x6e] = 0;

  param_1[0x6f] = 0;

  param_1[0x70] = 0;

  param_1[0x71] = 0;

  param_1[0x73] = 0;

  param_1[0x74] = 0;

  param_1[0x75] = 0;

  param_1[0x76] = 0;

  *(uint8_t *)(param_1 + 0x77) = 1;

  param_1[0x78] = 0;

  param_1[0x79] = 0;

  param_1[0x7a] = 0;

  param_1[0x7b] = 0;

  param_1[0x7c] = 0;

  param_1[0x7d] = 0;

  *(uint8_t *)(param_1 + 0x7e) = 0;

  param_1[0x99] = fVar1;

  fVar1 = g_flMultiKillCountBlend;

  param_1[0x9a] = g_flMultiKillCountBlend;

  param_1[0x9b] = fVar1;

  param_1[0x9c] = fVar1;

  param_1[0x9d] = DAT_00a11088;

  uVar2 = DAT_00aaa7a4;

  param_1[0x7f] = &PTR_LAB_00a9add0;

  param_1[0x9e] = uVar2;

  local_4._0_1_ = 1;

  uVar2 = FUN_004933f0();

  param_1[0xb5] = uVar2;

  param_1[0xb6] = 0;

  local_4 = CONCAT31(local_4._1_3_,2);

  *(uint8_t *)((int)param_1 + 0x2e1) = 1;

  param_1[0xb9] = 0;

  DAT_00d17958 = param_1;

  *(uint8_t *)(param_1 + 0x38) = 0;

  *(uint8_t *)((int)param_1 + 0xe2) = 0;

  param_1[0x41] = 800;

  param_1[0x42] = 600;

  param_1[0x43] = 800;

  param_1[0x44] = 600;

  param_1[0x3b] = 0x20;

  param_1[0x3c] = 0x18;

  param_1[0x3d] = 8;

  param_1[0x40] = 0;

  *(uint8_t *)((int)param_1 + 0xe6) = 1;

  *(uint8_t *)(param_1 + 0x3a) = 1;

  *(uint8_t *)((int)param_1 + 0xe7) = 1;

  *(uint8_t *)((int)param_1 + 0xea) = 1;

  pvVar3 = operator_new(0xa8);

  if (pvVar3 == (void *)0x0) {

    pvVar3 = (void *)0x0;

  }

  else {

    *(uint8_t *)((int)pvVar3 + 0xe) = 0xff;

    *(uint8_t *)((int)pvVar3 + 0xd) = 0xff;

    *(uint8_t *)((int)pvVar3 + 0xc) = 0xff;

    *(uint8_t *)((int)pvVar3 + 0xf) = 0xff;

    *(uint8_t *)((int)pvVar3 + 0x12) = 0xff;

    *(uint8_t *)((int)pvVar3 + 0x11) = 0xff;

    *(uint8_t *)((int)pvVar3 + 0x10) = 0xff;

    *(uint8_t *)((int)pvVar3 + 0x13) = 0xff;

    *(uint8_t *)((int)pvVar3 + 0x16) = 0xff;

    *(uint8_t *)((int)pvVar3 + 0x15) = 0xff;

    *(uint8_t *)((int)pvVar3 + 0x14) = 0xff;

    *(uint8_t *)((int)pvVar3 + 0x17) = 0xff;

    *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 0x6c) = 0;

  }

  param_1[0xb7] = pvVar3;

  *(void **)pvVar3 = pvVar3;

  *(uint32_t /* width from decompiler */ *)(param_1[0xb7] + 4) = param_1[0xb7];

  param_1[0x4f] = 0;

  param_1[0x50] = 0;

  param_1[0x51] = 0;

  param_1[0x52] = 0;

  param_1[0x53] = 0;

  param_1[0x54] = 0;

  param_1[0x55] = 0;

  param_1[0x56] = 0;

  ExceptionList = local_c;

  return param_1;

}
