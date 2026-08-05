// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_005abfa0
// -----------------------------------------------------------------------------
// Stable ID: aa_005abfa0
// Callee of Named_CalleeOf_Named_Client_InitInstance
// Address:   0x005abfa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0044e100, FUN_005a9e70, FUN_005ab110, FUN_005abfa0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Client_InitInstance
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_005abfa0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a655b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_009d8da8;

  *(uint8_t *)(param_1 + 0x237) = 0;

  *(uint8_t *)(param_1 + 0x277) = 0;

  *(uint8_t *)(param_1 + 0x46b) = 0;

  *(uint8_t *)(param_1 + 0x4ab) = 0;

  *(uint8_t *)(param_1 + 0x69f) = 0;

  *(uint8_t *)(param_1 + 0x6df) = 0;

  *(uint8_t *)(param_1 + 0x8d3) = 0;

  *(uint8_t *)(param_1 + 0x913) = 0;

  *(uint8_t *)(param_1 + 0xb07) = 0;

  *(uint8_t *)(param_1 + 0xb47) = 0;

  *(uint8_t *)(param_1 + 0xd3b) = 0;

  *(uint8_t *)(param_1 + 0xd7b) = 0;

  *(uint8_t *)(param_1 + 0xf6f) = 0;

  *(uint8_t *)(param_1 + 0xfaf) = 0;

  *(uint8_t *)(param_1 + 0x11a3) = 0;

  *(uint8_t *)(param_1 + 0x11e3) = 0;

  param_1[0x143f] = 0;

  param_1[0x1440] = 0;

  param_1[0x1441] = 0;

  local_4 = 0;

  iVar1 = FUN_0044e100();

  param_1[0x1443] = iVar1;

  *(uint8_t *)(iVar1 + 0x2d) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0x1443] + 4) = param_1[0x1443];

  *(uint32_t /* width from decompiler */ *)param_1[0x1443] = param_1[0x1443];

  *(uint32_t /* width from decompiler */ *)(param_1[0x1443] + 8) = param_1[0x1443];

  param_1[0x1444] = 0;

  param_1[2] = param_2;

  FUN_005a9e70();

  FUN_005ab110();

  ExceptionList = local_c;

  return param_1;

}
