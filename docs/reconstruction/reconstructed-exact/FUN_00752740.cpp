// =============================================================================
// FUN_00752740
// -----------------------------------------------------------------------------
// Stable ID: aa_00752740
// Address:   0x00752740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00752740 @ 0x00752740
// Stable ID: aa_00752740
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_0073d7d0, FUN_00752690, FUN_00752740.
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

void FUN_00752740(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009ac1f6;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a9f9c4;

  local_4 = 2;

  if (DAT_00d1f61c != 0) {

    FUN_0073d7d0();

  }

  FUN_00752690();

  local_4._0_1_ = 1;

  piVar2 = (int *)param_1[6];

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  local_4 = (uint)local_4._1_3_ << 8;

  iVar3 = param_1[2];

  if (iVar3 != 0) {

    piVar2 = (int *)(iVar3 + 8);

    *piVar2 = *piVar2 + -1;

    if (*piVar2 == 0) {

      (**(code **)(*(int *)(iVar3 + 4) + 8))();

    }

  }

  *param_1 = &PTR_LAB_009d45f0;

  ExceptionList = pvStack_c;

  return;

}
