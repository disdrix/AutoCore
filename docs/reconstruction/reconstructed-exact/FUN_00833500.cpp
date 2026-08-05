// =============================================================================
// FUN_00833500
// -----------------------------------------------------------------------------
// Stable ID: aa_00833500
// Address:   0x00833500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00833500 @ 0x00833500
// Stable ID: aa_00833500
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0076f5f0, FUN_00833500.
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

FUN_00833500(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *extraout_EDX;

  uint32_t /* width from decompiler */ in_XMM0_Da;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad1c3;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  param_2[4] = in_XMM0_Da;

  param_2[5] = 0;

  puVar1 = param_2 + 6;

  param_2[1] = 0;

  param_2[2] = 0;

  *param_2 = &PTR_LAB_00a9a3d4;

  param_2[3] = param_4;

  *puVar1 = *param_1;

  param_2[7] = param_1[1];

  param_2[8] = param_1[2];

  FUN_0076f5f0(puVar1,puVar1);

  *extraout_EDX = &PTR_LAB_00a6ff94;

  extraout_EDX[9] = param_3;

  ExceptionList = local_c;

  return extraout_EDX;

}
