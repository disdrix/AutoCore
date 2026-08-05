// =============================================================================
// Named_CalleeOf_Named_Could_not_get_Palantir_desktop_window_004cda90
// -----------------------------------------------------------------------------
// Stable ID: aa_004cda90
// Callee of Named_Could_not_get_Palantir_desktop_window
// Address:   0x004cda90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Could_not_get_Palantir_desktop_window: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_0074e200×2, FUN_0048fc90, FUN_00492dd0, FUN_00496f70, FUN_004cda90, FUN_0075b390, FUN_0075b3b0, FUN_0075ceb0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Could_not_get_Palantir_desktop_window
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_Could_not_get_Palantir_desktop_window_004cda90(int param_1)



{

  int iVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a1ef7;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  pvVar2 = operator_new(0x150);

  local_4 = 0;

  if (pvVar2 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_0075ceb0();

  }

  local_4 = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe890) = uVar3;

  FUN_0075b3b0(0x3f000000);

  uVar3 = DAT_00a0f520;

  if (*(char *)(param_1 + 0x7d) == '\0') {

    uVar3 = DAT_00aaaa90;

  }

  FUN_0075b390(uVar3);

  if (*(int *)(param_1 + 0xe89c) != 0) {

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe89c) + 0x2e4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe890);

    (**(code **)(**(int **)(*(int *)(param_1 + 0xe89c) + 0x2c) + 0xc))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0xe890));

    *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0xe89c) + 0x2c) + 0xc4) = DAT_00afdef0;

  }

  pvVar2 = operator_new(0x198);

  local_4 = 1;

  if (pvVar2 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_00492dd0(0,param_1);

  }

  local_4 = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe894) = uVar3;

  pvVar2 = operator_new(200);

  local_4 = 2;

  if (pvVar2 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_00496f70(param_1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe898) = uVar3;

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe890) + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe894);

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe894) + 0xc0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe890);

  local_4 = 0xffffffff;

  FUN_0048fc90(1);

  iVar1 = *(int *)(*(int *)(param_1 + 0xe894) + 4);

  if (DAT_00d1a54c != 0) {

    FUN_0074e200(0);

  }

  if (iVar1 != 0) {

    FUN_0074e200(1);

  }

  DAT_00d1a54c = iVar1;

  ExceptionList = pvStack_c;

  return 1;

}
