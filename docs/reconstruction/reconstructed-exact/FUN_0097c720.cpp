// =============================================================================
// FUN_0097c720
// -----------------------------------------------------------------------------
// Stable ID: aa_0097c720
// Address:   0x0097c720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0097c720 @ 0x0097c720
// Stable ID: aa_0097c720
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0040fb90, FUN_0078caf0, FUN_0097c720.
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

uint32_t /* width from decompiler */ * FUN_0097c720(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b49ac;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0078caf0(param_1,0,1);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a6696c;

  uVar1 = FUN_0040fb90();

  param_1[0x152] = uVar1;

  param_1[0x153] = 0;

  param_1[0x155] = 0;

  param_1[0x156] = 0;

  param_1[0x157] = 0;

  param_1[0x13f] = 0;

  param_1[0x140] = 0;

  param_1[0x141] = 0;

  param_1[0x142] = 0;

  param_1[0x143] = 0;

  param_1[0x144] = 0;

  param_1[0x145] = 0;

  param_1[0x146] = 0;

  param_1[0x147] = 0;

  param_1[0x148] = 0;

  param_1[0x149] = 0;

  param_1[0x14a] = 0;

  param_1[0x14b] = 0;

  param_1[0x14c] = 0;

  param_1[0x14d] = 0xffffffff;

  param_1[0x14e] = 0xffffffff;

  param_1[0x14f] = 0xffffffff;

  param_1[0x150] = 0xffffffff;

  ExceptionList = local_c;

  return param_1;

}
