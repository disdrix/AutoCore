// =============================================================================
// FUN_008fa960
// -----------------------------------------------------------------------------
// Stable ID: aa_008fa960
// Address:   0x008fa960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008fa960 @ 0x008fa960
// Stable ID: aa_008fa960
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00518ec0, FUN_0052f260, FUN_00792c20, FUN_008fa960.
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

void __fastcall FUN_008fa960(uint32_t /* width from decompiler */ *param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009b7a31;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a356f4;

  local_4 = 1;

  if ((uint32_t /* width from decompiler */ *)param_1[0x536] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x536])(1);

  }

  param_1[0x536] = 0;

  local_4 = local_4 & 0xffffff00;

  FUN_0052f260();

  FUN_00518ec0();

  *param_1 = &PTR_FUN_00a58c6c;

  local_4 = 0xffffffff;

  FUN_00792c20();

  ExceptionList = pvStack_c;

  return;

}
