// =============================================================================
// Named_CalleeOf_Mission_bActiveObjectiveOverride_007b87c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007b87c0
// Callee of Mission_bActiveObjectiveOverride (+1 other named callers)
// Address:   0x007b87c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_bActiveObjectiveOverride: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Mission_bActiveObjectiveOverride (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×8, return×3.
//  - Notable callees: SysFreeString×3, FUN_004048e0, FUN_00419ca0, FUN_00419e20, FUN_00419e90, FUN_00419f60, FUN_00423620, FUN_007b87c0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Mission_bActiveObjectiveOverride (+1 other named callers)
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

bool Named_CalleeOf_Mission_bActiveObjectiveOverride_007b87c0(int *param_1,BSTR param_2)



{

  OLECHAR *psz;

  char cVar1;

  int *piVar2;

  int local_18;

  BSTR local_14;

  int *local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009acf78;

  pvStack_c = ExceptionList;

  local_4 = 1;

  ExceptionList = &pvStack_c;

  FUN_00419ca0(&stack0xffffffd4);

  local_4._0_1_ = 2;

  if (param_1 == (int *)0x0) {

    _com_issue_error(-0x7fffbffd);

  }

  local_4._0_1_ = 1;

  FUN_00419f60(&local_10);

  local_4._0_1_ = 3;

  if (local_10 != (int *)0x0) {

    piVar2 = (int *)FUN_00419e90();

    local_4._0_1_ = 4;

    if (((uint32_t /* width from decompiler */ *)*piVar2 == (uint32_t /* width from decompiler */ *)0x0) ||

       (psz = *(OLECHAR **)*piVar2, psz == (OLECHAR *)0x0)) {

      local_14 = (BSTR)0x0;

    }

    else {

      local_14 = SysAllocString(psz);

      if (local_14 == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

        FUN_004048e0();

      }

    }

    local_4._0_1_ = 6;

    if (local_18 != 0) {

      FUN_00419e20();

    }

    cVar1 = FUN_00423620();

    SysFreeString(local_14);

    local_4._0_1_ = 1;

    if (local_10 != (int *)0x0) {

      (**(code **)(*local_10 + 8))();

    }

    local_4 = (uint)local_4._1_3_ << 8;

    if (param_1 != (int *)0x0) {

      (**(code **)(*param_1 + 8))();

    }

    SysFreeString(param_2);

    ExceptionList = pvStack_c;

    return cVar1 != '\0';

  }

  local_4 = (uint)local_4._1_3_ << 8;

  if (param_1 != (int *)0x0) {

    (**(code **)(*param_1 + 8))();

  }

  SysFreeString(param_2);

  ExceptionList = pvStack_c;

  return false;

}
