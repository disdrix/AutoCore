// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_007560d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007560d0
// Callee of Named_VOG_DEBUG_STOP (+2 other named callers)
// Address:   0x007560d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007560d0, FUN_0076c4d0, FUN_0076c500.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+2 other named callers)
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

uint32_t /* width from decompiler */ * __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_007560d0(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009ada99;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00a9f534;

  param_1[1] = 0;

  param_1[2] = 0;

  FUN_0076c500(1000);

  param_1[0x10] = 1000;

  param_1[0x11] = 1000;

  FUN_0076c4d0();

  *(uint8_t *)(param_1 + 0x12) = 0;

  param_1[0x14] = 0;

  param_1[0x15] = 0;

  param_1[0x16] = 0;

  param_1[0x17] = 0;

  fVar1 = g_flHardKillInterpolate;

  param_1[0x18] = DAT_00afdf40;

  param_1[0x19] = DAT_00afdf44;

  param_1[0x1a] = DAT_00afdf48;

  param_1[0x1b] = DAT_00afdf4c;

  param_1[0x1c] = 0;

  param_1[0x1d] = fVar1;

  *(uint8_t *)(param_1 + 0x1e) = 1;

  ExceptionList = local_c;

  return param_1;

}
