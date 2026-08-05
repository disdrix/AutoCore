// =============================================================================
// FUN_007b63a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007b63a0
// Address:   0x007b63a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b63a0 @ 0x007b63a0
// Stable ID: aa_007b63a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007b5dd0, FUN_007b63a0.
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

int * __fastcall FUN_007b63a0(int param_1)



{

  void *pvVar1;

  int *piVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b4107;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  pvVar1 = operator_new(0x488);

  piVar2 = (int *)0x0;

  local_4 = 0;

  if (pvVar1 != (void *)0x0) {

    piVar2 = (int *)FUN_007b5dd0(pvVar1,*(uint32_t /* width from decompiler */ *)(param_1 + 0x290));

  }

  local_4 = 0xffffffff;

  (**(code **)(*piVar2 + 0x38))(param_1);

  *(uint8_t *)((int)piVar2 + 0xcd) = 1;

  ExceptionList = pvVar1;

  return piVar2;

}
