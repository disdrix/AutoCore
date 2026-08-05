// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI_00970cf0
// -----------------------------------------------------------------------------
// Stable ID: aa_00970cf0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance
// Address:   0x00970cf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: InitializeCriticalSection×4, CONCAT31, CreateEventA, FUN_00439770, FUN_005ae2b0, FUN_00970cf0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI_00970cf0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  HANDLE pvVar1;

  int iVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009accf1;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  param_1[1] = 0;

  *param_1 = &PTR_FUN_00aa9a94;

  *(uint8_t *)(param_1 + 2) = 0;

  pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);

  param_1[1] = pvVar1;

  local_4 = 0;

  param_1[3] = 0;

  iVar2 = FUN_005ae2b0();

  param_1[5] = iVar2;

  *(uint8_t *)(iVar2 + 0x19) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[5] + 4) = param_1[5];

  *(uint32_t /* width from decompiler */ *)param_1[5] = param_1[5];

  *(uint32_t /* width from decompiler */ *)(param_1[5] + 8) = param_1[5];

  param_1[6] = 0;

  param_1[8] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xb] = 0;

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));

  *(uint8_t *)(param_1 + 0x12) = 1;

  param_1[0x14] = 0;

  param_1[0x15] = 0;

  param_1[0x16] = 0;

  param_1[0x17] = 0;

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));

  *(uint8_t *)(param_1 + 0x1e) = 1;

  param_1[0x20] = 0;

  param_1[0x21] = 0;

  param_1[0x22] = 0;

  param_1[0x23] = 0;

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));

  *(uint8_t *)(param_1 + 0x2a) = 1;

  param_1[0x2c] = 0;

  param_1[0x2d] = 0;

  param_1[0x2e] = 0;

  param_1[0x2f] = 0;

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));

  *(uint8_t *)(param_1 + 0x36) = 1;

  local_4 = CONCAT31(local_4._1_3_,5);

  iVar2 = FUN_00439770();

  param_1[0x38] = iVar2;

  *(uint8_t *)(iVar2 + 0x15) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0x38] + 4) = param_1[0x38];

  *(uint32_t /* width from decompiler */ *)param_1[0x38] = param_1[0x38];

  *(uint32_t /* width from decompiler */ *)(param_1[0x38] + 8) = param_1[0x38];

  param_1[0x39] = 0;

  param_1[0x44] = param_2;

  param_1[0x3a] = 0;

  param_1[0x3b] = 0;

  param_1[0x3c] = 0;

  param_1[0x3d] = 0;

  param_1[0x3e] = 0;

  param_1[0x3f] = 0;

  param_1[0x40] = 0;

  param_1[0x41] = 0;

  param_1[0x42] = 0;

  param_1[0x43] = 0;

  ExceptionList = local_c;

  return param_1;

}
