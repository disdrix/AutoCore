// =============================================================================
// FUN_00805300
// -----------------------------------------------------------------------------
// Stable ID: aa_00805300
// Address:   0x00805300  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00805300 @ 0x00805300
// Stable ID: aa_00805300
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00805860×2, FUN_00805300, FUN_00977f30.
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

void __fastcall FUN_00805300(uint32_t /* width from decompiler */ *param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009ac43f;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a7fb4c;

  local_4 = 1;

  FUN_00805860();

  local_4 = local_4 & 0xffffff00;

  param_1[0x10] = &PTR_FUN_00a7f9e4;

  FUN_00805860();

  local_4 = 0xffffffff;

  FUN_00977f30();

  ExceptionList = pvStack_c;

  return;

}
