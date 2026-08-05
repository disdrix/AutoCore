// =============================================================================
// FUN_008c4f10
// -----------------------------------------------------------------------------
// Stable ID: aa_008c4f10
// Address:   0x008c4f10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c4f10 @ 0x008c4f10
// Stable ID: aa_008c4f10
// Embedded strings (evidence for future rename):
//   - "i_d_hazard.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0087b890, FUN_008c4f10, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_hazard.xml".
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

uint32_t /* width from decompiler */ * FUN_008c4f10(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b6a6b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a435e4;

  *(uint8_t *)((int)param_1 + 0x51e) = 0xff;

  *(uint8_t *)((int)param_1 + 0x51d) = 0xff;

  *(uint8_t *)(param_1 + 0x147) = 0xff;

  *(uint8_t *)((int)param_1 + 0x51f) = 0xff;

  param_1[0x146] = 0;

  param_1[0x143] = 0;

  param_1[0x144] = 0;

  param_1[0x145] = 0;

  param_1[0x12e] = 0;

  param_1[0x12f] = 0;

  param_1[0x12d] = 0;

  param_1[0x141] = 0;

  param_1[0x142] = 0;

  NDUIWindow_ReloadInterface("i_d_hazard.xml");

  ExceptionList = local_c;

  return param_1;

}
