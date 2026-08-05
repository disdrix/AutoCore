// =============================================================================
// FUN_005fdaf0
// -----------------------------------------------------------------------------
// Stable ID: aa_005fdaf0
// Address:   0x005fdaf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005fdaf0 @ 0x005fdaf0
// Stable ID: aa_005fdaf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005fdaf0.
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

void __fastcall FUN_005fdaf0(int param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a7ceb;

  pvStack_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  if (-1 < *(int *)(param_1 + 0x2c)) {

    ExceptionList = &pvStack_c;

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x24),*(int *)(param_1 + 0x2c) * 4,0x12);

  }

  local_4 = 0xffffffff;

  if (-1 < *(int *)(param_1 + 0x20)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),*(int *)(param_1 + 0x20) * 4,0x12);

  }

  ExceptionList = pvStack_c;

  return;

}
