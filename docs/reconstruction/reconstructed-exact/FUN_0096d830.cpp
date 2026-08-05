// =============================================================================
// FUN_0096d830
// -----------------------------------------------------------------------------
// Stable ID: aa_0096d830
// Address:   0x0096d830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096d830 @ 0x0096d830
// Stable ID: aa_0096d830
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0044aaf0, FUN_0096d830.
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

uint32_t /* width from decompiler */ * FUN_0096d830(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  uVar2 = DAT_00aaa63c;

  uVar1 = DAT_00aaa630;

  puStack_8 = &LAB_009ad9c9;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00aa0824;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = uVar1;

  param_1[7] = uVar1;

  param_1[8] = uVar1;

  param_1[9] = uVar2;

  param_1[10] = uVar2;

  param_1[0xb] = uVar2;

  *(uint8_t *)(param_1 + 0xc) = 1;

  param_1[0xd] = 0;

  param_1[0xe] = 0;

  param_1[0xf] = 0;

  param_1[0x10] = 0;

  param_1[0x11] = 0;

  param_1[0x12] = uVar1;

  param_1[0x13] = uVar1;

  param_1[0x14] = uVar1;

  param_1[0x15] = uVar2;

  param_1[0x16] = uVar2;

  param_1[0x17] = uVar2;

  *(uint8_t *)(param_1 + 0x18) = 1;

  param_1[0x19] = 0;

  param_1[0x1b] = 0;

  param_1[0x1c] = 0;

  param_1[0x1d] = 0;

  param_1[0x1e] = 0;

  param_1[0x20] = 0;

  param_1[0x21] = 0;

  param_1[0x22] = 0;

  local_4 = 2;

  FUN_0044aaf0();

  ExceptionList = local_c;

  return param_1;

}
