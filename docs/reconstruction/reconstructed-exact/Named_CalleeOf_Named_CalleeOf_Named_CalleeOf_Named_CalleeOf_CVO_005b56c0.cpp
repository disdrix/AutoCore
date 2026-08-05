// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_005b56c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b56c0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCreature_Setup
// Address:   0x005b56c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCreature_Setup: creature/setup helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004bd2d0, FUN_005b56c0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCreature_Setup
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ * __thiscall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_005b56c0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            void *param_5,uint32_t /* width from decompiler */ param_6)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009a693d;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  param_1[1] = param_5;

  *param_1 = &PTR_FUN_009d9ab0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[9] = 0;

  param_1[0xb] = 1;

  param_1[0xc] = 0;

  *(uint8_t *)(param_1 + 0xe) = 0;

  param_1[0x10] = 0;

  param_1[0x11] = 0;

  param_1[0x12] = 0;

  fVar1 = g_flOne;

  param_1[0x13] = 0;

  param_1[0x14] = 0;

  param_1[0x15] = 0;

  param_1[0x17] = 0;

  param_1[0x18] = 0;

  param_1[0x19] = 0;

  param_1[0x1b] = 0;

  param_1[0x1c] = 0;

  *(uint16_t *)(param_1 + 0x1d) = 0;

  param_1[0x1e] = 0;

  param_1[0x1f] = 0;

  uVar2 = DAT_00aaa688;

  param_1[0x35] = fVar1;

  param_1[0x31] = fVar1;

  param_1[0x29] = fVar1;

  param_1[0x2d] = fVar1;

  param_1[0x36] = fVar1;

  param_1[0x32] = fVar1;

  param_1[0x2a] = fVar1;

  param_1[0x2e] = fVar1;

  param_1[0x37] = fVar1;

  param_1[0x33] = fVar1;

  param_1[0x2b] = fVar1;

  param_1[0x2f] = fVar1;

  param_1[0x38] = fVar1;

  param_1[0x34] = fVar1;

  param_1[0x2c] = fVar1;

  param_1[0x30] = fVar1;

  param_1[0x39] = uVar2;

  param_1[0x46] = fVar1;

  param_1[0x42] = fVar1;

  param_1[0x3a] = fVar1;

  param_1[0x3e] = fVar1;

  param_1[0x47] = fVar1;

  param_1[0x43] = fVar1;

  param_1[0x3b] = fVar1;

  param_1[0x3f] = fVar1;

  param_1[0x48] = fVar1;

  param_1[0x44] = fVar1;

  param_1[0x3c] = fVar1;

  param_1[0x40] = fVar1;

  param_1[0x49] = fVar1;

  param_1[0x45] = fVar1;

  param_1[0x3d] = fVar1;

  param_1[0x41] = fVar1;

  param_1[0x4a] = uVar2;

  local_4 = 0;

  param_1[0x57] = fVar1;

  param_1[0x53] = fVar1;

  param_1[0x4b] = fVar1;

  param_1[0x4f] = fVar1;

  param_1[0x58] = fVar1;

  param_1[0x54] = fVar1;

  param_1[0x4c] = fVar1;

  param_1[0x50] = fVar1;

  param_1[0x59] = fVar1;

  param_1[0x55] = fVar1;

  param_1[0x4d] = fVar1;

  param_1[0x51] = fVar1;

  param_1[0x5a] = fVar1;

  param_1[0x56] = fVar1;

  param_1[0x4e] = fVar1;

  param_1[0x52] = fVar1;

  param_1[0x5b] = uVar2;

  param_1[0x20] = param_2;

  param_1[0x21] = param_3;

  param_1[0x5c] = 0;

  param_1[0x5d] = param_6;

  param_1[0x22] = param_4;

  _DAT_00b05344 = _DAT_00b05344 + 1;

  param_5 = operator_new(0x158);

  local_4._0_1_ = 1;

  if (param_5 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_004bd2d0(param_1[1],param_1);

  }

  param_1[2] = piVar3;

  local_4 = (uint)local_4._1_3_ << 8;

  (**(code **)(*piVar3 + 0x18))(&param_2);

  ExceptionList = param_1;

  return param_1;

}
