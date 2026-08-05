// =============================================================================
// FUN_00612c80
// -----------------------------------------------------------------------------
// Stable ID: aa_00612c80
// Address:   0x00612c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00612c80 @ 0x00612c80
// Stable ID: aa_00612c80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00612c80, FUN_00637da0.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00612c80(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a8578;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00637da0(param_2);

  *param_1 = &PTR_FUN_009e1854;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[0xe] = 0xffffffff;

  param_1[0x11] = 0xffffffff;

  param_1[0xc] = 0;

  *(uint8_t *)(param_1 + 0xd) = 0;

  *(uint8_t *)(param_1 + 0xf) = 0;

  *(uint8_t *)((int)param_1 + 0x3d) = 0;

  param_1[0x10] = 0;

  param_1[3] = 1;

  ExceptionList = local_c;

  return param_1;

}
