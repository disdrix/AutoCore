// =============================================================================
// FUN_005fdb80
// -----------------------------------------------------------------------------
// Stable ID: aa_005fdb80
// Address:   0x005fdb80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005fdb80 @ 0x005fdb80
// Stable ID: aa_005fdb80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_005fdb80.
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

void __fastcall FUN_005fdb80(int param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009a7d16;

  pvStack_c = ExceptionList;

  local_4 = 1;

  ExceptionList = &pvStack_c;

  if (-1 < (int)*(uint *)(param_1 + 0x28)) {

    ExceptionList = &pvStack_c;

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x20),*(uint *)(param_1 + 0x28) & 0x7fffffff,0x12);

  }

  local_4 = local_4 & 0xffffff00;

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
