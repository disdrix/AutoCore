// =============================================================================
// FUN_005fde60
// -----------------------------------------------------------------------------
// Stable ID: aa_005fde60
// Address:   0x005fde60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005fde60 @ 0x005fde60
// Stable ID: aa_005fde60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_005fdda0, FUN_005fde60.
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

void __fastcall FUN_005fde60(int param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009a7dbe;

  pvStack_c = ExceptionList;

  local_4 = 2;

  ExceptionList = &pvStack_c;

  if (-1 < *(int *)(param_1 + 0x44)) {

    ExceptionList = &pvStack_c;

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x3c),*(int *)(param_1 + 0x44) * 4,0x12);

  }

  local_4._0_1_ = 1;

  if (-1 < *(int *)(param_1 + 0x38)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x30),*(int *)(param_1 + 0x38) * 4,0x12);

  }

  local_4 = (uint)local_4._1_3_ << 8;

  if (-1 < *(int *)(param_1 + 0x2c)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x24),*(int *)(param_1 + 0x2c) * 4,0x12);

  }

  local_4 = 0xffffffff;

  FUN_005fdda0();

  ExceptionList = pvStack_c;

  return;

}
