// =============================================================================
// FUN_007b7ea0
// -----------------------------------------------------------------------------
// Stable ID: aa_007b7ea0
// Address:   0x007b7ea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b7ea0 @ 0x007b7ea0
// Stable ID: aa_007b7ea0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_007b7ea0, _com_issue_error.
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

void __fastcall FUN_007b7ea0(int param_1)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  int *piVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009aba9f;

  pvStack_c = ExceptionList;

  local_4 = 1;

  ExceptionList = &pvStack_c;

  iVar3 = param_1;

  if (DAT_00d1793c != '\0') {

    if (DAT_00d1e56c == (int *)0x0) {

      ExceptionList = &pvStack_c;

      _com_issue_error(-0x7fffbffd);

    }

    else {

      ExceptionList = &pvStack_c;

      (**(code **)(*DAT_00d1e56c + 8))(DAT_00d1e56c);

      DAT_00d1e56c = (int *)0x0;

    }

  }

  piVar1 = (int *)(param_1 + 0x28);

  local_4._0_1_ = 2;

  piVar2 = (int *)*piVar1;

  piVar4 = piVar1;

  if (piVar2 != (int *)0x0) {

    *piVar1 = 0;

    (**(code **)(*piVar2 + 8))(piVar2);

  }

  local_4 = (uint)local_4._1_3_ << 8;

  piVar1 = (int *)*piVar1;

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 8))(piVar1);

  }

  local_4 = 0xffffffff;

  piVar1 = *(int **)(param_1 + 0x24);

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 8))(piVar1,iVar3,piVar4);

  }

  ExceptionList = pvStack_c;

  return;

}
