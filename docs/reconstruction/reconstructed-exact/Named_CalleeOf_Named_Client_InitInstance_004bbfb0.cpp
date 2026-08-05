// =============================================================================
// Named_CalleeOf_Named_Client_InitInstance_004bbfb0
// -----------------------------------------------------------------------------
// Stable ID: aa_004bbfb0
// Callee of Named_Client_InitInstance
// Address:   0x004bbfb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~120 non-empty decompiler lines.
//  - Control keywords: if×10, return×1.
//  - Notable callees: InitializeCriticalSection×3, FUN_004bcf90×2, CONCAT31, FUN_004bbfb0, FUN_004bce90.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Client_InitInstance
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_Client_InitInstance_004bbfb0(uint32_t /* width from decompiler */ *param_1,int param_2,int param_3)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint8_t local_4;

  undefined3 uStack_3;

  

  puStack_8 = &LAB_009a1742;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_009cb448;

  param_1[0xb] = 0;

  param_1[0xc] = 0;

  param_1[0xd] = 0;

  param_1[0xf] = 0;

  param_1[0x10] = 0;

  param_1[0x11] = 0;

  param_1[0x13] = 0;

  param_1[0x14] = 0;

  param_1[0x15] = 0;

  if (param_2 < 0) {

    param_2 = 0;

  }

  if (param_3 < 0) {

    param_3 = 0;

  }

  local_4 = 2;

  uStack_3 = 0;

  param_1[4] = param_2;

  param_1[5] = param_3;

  *(bool *)(param_1 + 3) = param_2 != 0;

  *(bool *)((int)param_1 + 0xd) = param_3 != 0;

  if (param_2 != 0) {

    pvVar1 = operator_new(0x34);

    local_4 = 3;

    if (pvVar1 == (void *)0x0) {

      uVar2 = 0;

    }

    else {

      uVar2 = FUN_004bcf90(param_2);

    }

  }

  else {

    uVar2 = 0;

  }

  local_4 = 2;

  param_1[1] = uVar2;

  if (*(char *)((int)param_1 + 0xd) == '\0') {

    uVar2 = 0;

  }

  else {

    pvVar1 = operator_new(0x34);

    local_4 = 4;

    if (pvVar1 == (void *)0x0) {

      uVar2 = 0;

    }

    else {

      uVar2 = FUN_004bcf90(param_3);

    }

  }

  local_4 = 2;

  param_1[2] = uVar2;

  pvVar1 = operator_new(0x34);

  local_4 = 5;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_004bce90(5);

  }

  _local_4 = CONCAT31(uStack_3,2);

  param_1[6] = uVar2;

  puVar3 = operator_new(0x2c);

  if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar3 = &PTR_FUN_009cb334;

    puVar3[8] = 0;

    puVar3[7] = 0;

    puVar3[9] = 0;

    *(uint8_t *)(puVar3 + 10) = 0;

    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar3 + 1));

    *puVar3 = &PTR_FUN_009cb378;

  }

  param_1[7] = puVar3;

  puVar3 = operator_new(0x2c);

  if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar3 = &PTR_FUN_009cb334;

    puVar3[8] = 0;

    puVar3[7] = 0;

    puVar3[9] = 0;

    *(uint8_t *)(puVar3 + 10) = 0;

    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar3 + 1));

    *puVar3 = &PTR_FUN_009cb378;

  }

  param_1[8] = puVar3;

  puVar3 = operator_new(0x2c);

  if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar3 = &PTR_FUN_009cb334;

    puVar3[8] = 0;

    puVar3[7] = 0;

    puVar3[9] = 0;

    *(uint8_t *)(puVar3 + 10) = 0;

    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar3 + 1));

    *puVar3 = &PTR_FUN_009cb378;

  }

  param_1[9] = puVar3;

  *(uint8_t *)((int)param_1 + 0xe) = 0;

  ExceptionList = local_c;

  return param_1;

}
