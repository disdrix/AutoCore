// =============================================================================
// FUN_0046a380
// -----------------------------------------------------------------------------
// Stable ID: aa_0046a380
// Address:   0x0046a380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046a380 @ 0x0046a380
// Stable ID: aa_0046a380
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_0046a380, FUN_007315b0, FUN_00748960, FUN_00972cc0.
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

uint32_t /* width from decompiler */ * FUN_0046a380(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ extraout_EDX;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009be460;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00748960();

  local_4 = 0;

  *param_1 = &PTR_FUN_00aa634c;

  param_1[1] = &PTR_LAB_00aa6340;

  FUN_00972cc0();

  param_1[100] = 0;

  param_1[0x65] = 0;

  param_1[0x66] = 0;

  param_1[0x67] = 0;

  param_1[0x68] = 0;

  uVar1 = DAT_00aaa630;

  param_1[0x69] = DAT_00aaa630;

  param_1[0x6a] = uVar1;

  param_1[0x6b] = uVar1;

  uVar1 = DAT_00aaa63c;

  param_1[0x6c] = DAT_00aaa63c;

  param_1[0x6d] = uVar1;

  param_1[0x6e] = uVar1;

  *(uint8_t *)(param_1 + 0x6f) = 1;

  param_1[0x72] = extraout_EDX;

  param_1[0x73] = extraout_EDX;

  param_1[0x74] = extraout_EDX;

  param_1[0x75] = extraout_EDX;

  param_1[0x76] = extraout_EDX;

  param_1[0x78] = extraout_EDX;

  param_1[0x79] = extraout_EDX;

  param_1[0x7a] = extraout_EDX;

  param_1[0x7b] = extraout_EDX;

  param_1[0x7c] = extraout_EDX;

  param_1[0x7e] = extraout_EDX;

  param_1[0x7d] = &PTR_FUN_00a9db18;

  param_1[0x80] = extraout_EDX;

  param_1[0x7f] = &PTR_FUN_00a9da80;

  local_4 = CONCAT31(local_4._1_3_,4);

  FUN_007315b0(param_2);

  ExceptionList = local_c;

  return param_1;

}
