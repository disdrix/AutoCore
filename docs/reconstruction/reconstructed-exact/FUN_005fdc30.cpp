// =============================================================================
// FUN_005fdc30
// -----------------------------------------------------------------------------
// Stable ID: aa_005fdc30
// Address:   0x005fdc30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005fdc30 @ 0x005fdc30
// Stable ID: aa_005fdc30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: FUN_005fdc30.
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

void __fastcall FUN_005fdc30(int param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009a7d6d;

  pvStack_c = ExceptionList;

  local_4 = 6;

  ExceptionList = &pvStack_c;

  if (-1 < *(int *)(param_1 + 0x60)) {

    ExceptionList = &pvStack_c;

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x58),*(int *)(param_1 + 0x60) * 4,0x12);

  }

  local_4._0_1_ = 5;

  if (-1 < *(int *)(param_1 + 0x54)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x4c),*(int *)(param_1 + 0x54) * 4,0x12);

  }

  local_4._0_1_ = 4;

  if (-1 < *(int *)(param_1 + 0x48)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x40),*(int *)(param_1 + 0x48) * 4,0x12);

  }

  local_4._0_1_ = 3;

  if (-1 < *(int *)(param_1 + 0x3c)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x34),*(int *)(param_1 + 0x3c) * 4,0x12);

  }

  local_4._0_1_ = 2;

  if (-1 < *(int *)(param_1 + 0x30)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x28),*(int *)(param_1 + 0x30) * 4,0x12);

  }

  local_4._0_1_ = 1;

  if (-1 < *(int *)(param_1 + 0x24)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x1c),*(int *)(param_1 + 0x24) * 4,0x12);

  }

  local_4 = (uint)local_4._1_3_ << 8;

  if (-1 < *(int *)(param_1 + 0x18)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),*(int *)(param_1 + 0x18) * 4,0x12);

  }

  local_4 = 0xffffffff;

  if (-1 < *(int *)(param_1 + 0xc)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 4),*(int *)(param_1 + 0xc) * 4,0x12);

  }

  ExceptionList = pvStack_c;

  return;

}
