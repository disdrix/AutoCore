// =============================================================================
// FUN_00684e30
// -----------------------------------------------------------------------------
// Stable ID: aa_00684e30
// Address:   0x00684e30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00684e30 @ 0x00684e30
// Stable ID: aa_00684e30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0076c500×3, FUN_00684e30.
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

uint32_t /* width from decompiler */ * __fastcall FUN_00684e30(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a9c28;

  local_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_009ea5c4;

  param_1[1] = 8;

  *(uint8_t *)(param_1 + 2) = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  FUN_0076c500(100);

  FUN_0076c500(1000);

  *(uint8_t *)(param_1 + 0x1e) = 0;

  *(uint8_t *)((int)param_1 + 0x79) = 0;

  param_1[0x1f] = 0;

  param_1[0x20] = 0;

  param_1[0x21] = 0;

  param_1[0x22] = 0;

  FUN_0076c500(1000);

  ExceptionList = local_c;

  return param_1;

}
