// =============================================================================
// FUN_005a14f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005a14f0
// Address:   0x005a14f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a14f0 @ 0x005a14f0
// Stable ID: aa_005a14f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0042c010, FUN_00462f80, FUN_005a14f0.
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

uint32_t /* width from decompiler */ * __thiscall

FUN_005a14f0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint8_t param_4,

            uint32_t /* width from decompiler */ param_5,uint8_t param_6)



{

  int iVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a610b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0042c010(param_3);

  param_1[0x28] = param_2;

  *(uint8_t *)((int)param_1 + 0xae) = param_6;

  local_4 = 0;

  *param_1 = &PTR_LAB_009d7efc;

  *(uint8_t *)(param_1 + 0x29) = param_4;

  param_1[0x2a] = param_5;

  *(uint16_t *)(param_1 + 0x2b) = 0xdc;

  param_1[0x2c] = 0;

  param_1[0x2d] = 0;

  iVar1 = FUN_00462f80();

  param_1[0x2f] = iVar1;

  *(uint8_t *)(iVar1 + 0x21) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0x2f] + 4) = param_1[0x2f];

  *(uint32_t /* width from decompiler */ *)param_1[0x2f] = param_1[0x2f];

  *(uint32_t /* width from decompiler */ *)(param_1[0x2f] + 8) = param_1[0x2f];

  param_1[0x30] = 0;

  ExceptionList = local_c;

  return param_1;

}
