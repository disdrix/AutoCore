// =============================================================================
// FUN_0067c060
// -----------------------------------------------------------------------------
// Stable ID: aa_0067c060
// Address:   0x0067c060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067c060 @ 0x0067c060
// Stable ID: aa_0067c060
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0067b110×2, CONCAT31, FUN_0046e280, FUN_0067b070, FUN_0067b0e0, FUN_0067b120, FUN_0067c060.
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

uint32_t /* width from decompiler */ __thiscall FUN_0067c060(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  uint8_t local_2c [16];

  uint8_t local_1c [16];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a9669;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_0067b070();

  local_4 = 1;

  if (*(int *)(param_1 + 0x2984) == 0) {

    uVar1 = FUN_0046e280(local_1c);

    local_4._0_1_ = 2;

    FUN_0067b120(uVar1);

    local_4 = CONCAT31(local_4._1_3_,1);

    FUN_0067b110();

  }

  else {

    (**(code **)(**(int **)(param_1 + 0x2984) + 0x20))(local_2c);

  }

  FUN_0067b0e0(local_2c);

  local_4 = local_4 & 0xffffff00;

  FUN_0067b110();

  ExceptionList = pvStack_c;

  return param_2;

}
