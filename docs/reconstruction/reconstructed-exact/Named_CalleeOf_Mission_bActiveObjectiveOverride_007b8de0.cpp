// =============================================================================
// Named_CalleeOf_Mission_bActiveObjectiveOverride_007b8de0
// -----------------------------------------------------------------------------
// Stable ID: aa_007b8de0
// Callee of Mission_bActiveObjectiveOverride (+4 other named callers)
// Address:   0x007b8de0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_bActiveObjectiveOverride: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Mission_bActiveObjectiveOverride (+4 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×9, return×3.
//  - Notable callees: SysFreeString×3, wcscpy×2, CONCAT31, FUN_004048e0, FUN_00419ca0, FUN_00419e20, FUN_00419e90, FUN_00419f60.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Mission_bActiveObjectiveOverride (+4 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Mission_bActiveObjectiveOverride_007b8de0(int *param_1,BSTR param_2,wchar_t *param_3)



{

  OLECHAR *psz;

  uint8_t uVar1;

  int *piVar2;

  BSTR _Source;

  int *local_14;

  uint8_t *local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009ad07a;

  pvStack_c = ExceptionList;

  local_10 = &stack0xffffffd8;

  local_4 = 1;

  ExceptionList = &pvStack_c;

  FUN_00419ca0(&stack0xffffffd8);

  local_4._0_1_ = 2;

  if (param_1 == (int *)0x0) {

    _com_issue_error(-0x7fffbffd);

  }

  local_4._0_1_ = 1;

  FUN_00419f60(&local_14);

  local_4._0_1_ = 3;

  uVar1 = (uint8_t)local_4;

  local_4._0_1_ = 3;

  if (local_14 != (int *)0x0) {

    piVar2 = (int *)FUN_00419e90();

    local_4 = CONCAT31(local_4._1_3_,4);

    if (((uint32_t /* width from decompiler */ *)*piVar2 == (uint32_t /* width from decompiler */ *)0x0) ||

       (psz = *(OLECHAR **)*piVar2, psz == (OLECHAR *)0x0)) {

      _Source = (BSTR)0x0;

    }

    else {

      _Source = SysAllocString(psz);

      if (_Source == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

        FUN_004048e0();

      }

    }

    if (local_10 != (uint8_t *)0x0) {

      FUN_00419e20();

    }

    wcscpy(param_3,_Source);

    SysFreeString(_Source);

    local_4._0_1_ = 1;

    if (local_14 != (int *)0x0) {

      (**(code **)(*local_14 + 8))();

    }

    local_4 = (uint)local_4._1_3_ << 8;

    if (param_1 != (int *)0x0) {

      (**(code **)(*param_1 + 8))();

    }

    SysFreeString(param_2);

    ExceptionList = pvStack_c;

    return;

  }

  local_4._0_1_ = uVar1;

  wcscpy(param_3,L"");

  local_4._0_1_ = 1;

  if (local_14 != (int *)0x0) {

    (**(code **)(*local_14 + 8))();

  }

  local_4 = (uint)local_4._1_3_ << 8;

  if (param_1 != (int *)0x0) {

    (**(code **)(*param_1 + 8))();

  }

  SysFreeString(param_2);

  ExceptionList = pvStack_c;

  return;

}
