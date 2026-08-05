// =============================================================================
// FUN_006054a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006054a0
// Address:   0x006054a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006054a0 @ 0x006054a0
// Stable ID: aa_006054a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00518940, FUN_005743e0, FUN_00581330, FUN_006054a0.
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

uint32_t /* width from decompiler */ * __thiscall FUN_006054a0(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a80ab;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (param_2 != 0) {

    ExceptionList = &local_c;

    param_1[1] = &DAT_009de468;

    FUN_00518940();

    local_4 = 0;

  }

  FUN_00581330(0);

  *param_1 = &PTR_FUN_009de430;

  *(undefined ***)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) = &PTR_LAB_009de16c;

  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0xbc;

  param_1[0x24] = 0;

  param_1[0x25] = 0;

  param_1[0x26] = 0;

  param_1[0x27] = 0;

  param_1[0x28] = 0;

  *(uint8_t *)(param_1 + 0x29) = 0;

  param_1[0x1f] = 0;

  param_1[0x20] = 0;

  *(uint16_t *)(param_1 + 0x21) = 0;

  *(uint8_t *)((int)param_1 + 0x86) = 0;

  local_4 = 2;

  *(uint8_t *)((int)param_1 + 0x87) = 0;

  param_1[0x22] = 0xffffffff;

  FUN_005743e0(0,0,0);

  uVar2 = DAT_00aaa884;

  puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1[1] + 4) + 0x84 + (int)param_1);

  *puVar1 = DAT_00aaaca8;

  puVar1[1] = 0;

  puVar1[2] = uVar2;

  puVar1[3] = 0;

  ExceptionList = local_c;

  return param_1;

}
