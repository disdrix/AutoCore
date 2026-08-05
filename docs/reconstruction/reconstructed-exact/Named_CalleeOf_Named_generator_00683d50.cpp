// =============================================================================
// Named_CalleeOf_Named_generator_00683d50
// -----------------------------------------------------------------------------
// Stable ID: aa_00683d50
// Callee of Named_generator (+1 other named callers)
// Address:   0x00683d50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_generator: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_generator (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: for×2, return×1.
//  - Notable callees: FUN_00680c30, FUN_00680c50, FUN_00681020, FUN_00683d50, FUN_00685050, thunk_FUN_0076c4d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_generator (+1 other named callers)
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

uint8_t Named_CalleeOf_Named_generator_00683d50(uint32_t /* width from decompiler */ param_1)



{

  uint8_t uVar1;

  uint uVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *local_34;

  uint32_t /* width from decompiler */ local_30;

  uint8_t local_2c;

  uint8_t local_2b;

  uint16_t local_2a;

  uint8_t local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a9be0;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00680c30();

  local_4 = 0;

  local_34 = operator_new__(DAT_009ea5a8);

  uVar3 = DAT_009ea5a8;

  local_2c = DAT_009ea59c;

  local_30 = 0;

  local_2b = 0;

  local_2a = 0;

  puVar4 = local_34;

  for (uVar2 = DAT_009ea5a8 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

    *(uint8_t *)puVar4 = 0;

    puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

  }

  FUN_00681020(&local_34,DAT_009ea5a8,1);

  thunk_FUN_0076c4d0();

  uVar1 = FUN_00685050(local_28,&local_30,param_1);

  local_4 = 0xffffffff;

  FUN_00680c50();

  ExceptionList = local_c;

  return uVar1;

}
