// =============================================================================
// FUN_006935a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006935a0
// Address:   0x006935a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006935a0 @ 0x006935a0
// Stable ID: aa_006935a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00691d80×2, FUN_00691720, FUN_006935a0.
//  - Return sites: 2.

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

void FUN_006935a0(int param_1,int param_2)



{

  uint8_t uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint8_t local_3c [4];

  void *local_38;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint8_t local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aa8e8;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00691720(param_1);

  local_2c = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

  local_28 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);

  local_20 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

  uVar1 = *(uint8_t *)(param_1 + 0x18);

  uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x28);

  local_1c = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

  local_18 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

  local_10 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c);

  local_4 = 0;

  local_24 = uVar1;

  local_14 = uVar2;

  FUN_00691d80(param_2);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x10);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x14);

  *(uint8_t *)(param_1 + 0x18) = *(uint8_t *)(param_2 + 0x18);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x20);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x24);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x28);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x2c);

  FUN_00691d80(local_3c);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x10) = local_2c;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x14) = local_28;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c) = local_20;

  *(uint8_t *)(param_2 + 0x18) = uVar1;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x20) = local_1c;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x28) = uVar2;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x24) = local_18;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x2c) = local_10;

  if (local_38 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_38);

  }

  ExceptionList = local_c;

  return;

}
