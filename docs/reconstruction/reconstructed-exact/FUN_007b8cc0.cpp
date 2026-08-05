// =============================================================================
// FUN_007b8cc0
// -----------------------------------------------------------------------------
// Stable ID: aa_007b8cc0
// Address:   0x007b8cc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b8cc0 @ 0x007b8cc0
// Stable ID: aa_007b8cc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×8, do×1, while×1, return×1.
//  - Notable callees: CONCAT31, FUN_00419ca0, FUN_00419e20, FUN_00419e90, FUN_00419f60, FUN_00717fb0, FUN_007b8cc0, SysFreeString.
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

void FUN_007b8cc0(int *param_1,BSTR param_2,char *param_3)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ uVar4;

  char *pcVar5;

  int *local_14;

  uint8_t *local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009ad048;

  pvStack_c = ExceptionList;

  local_10 = &stack0xffffffdc;

  local_4 = 1;

  ExceptionList = &pvStack_c;

  FUN_00419ca0(&stack0xffffffdc);

  local_4._0_1_ = 2;

  if (param_1 == (int *)0x0) {

    _com_issue_error(-0x7fffbffd);

  }

  local_4._0_1_ = 1;

  FUN_00419f60(&local_14);

  local_4._0_1_ = 3;

  if (local_14 == (int *)0x0) {

    *param_3 = '\0';

    local_4 = (uint)local_4._1_3_ << 8;

    if (param_1 != (int *)0x0) {

      (**(code **)(*param_1 + 8))();

    }

  }

  else {

    piVar3 = (int *)FUN_00419e90();

    local_4 = CONCAT31(local_4._1_3_,4);

    iVar2 = *piVar3;

    if (iVar2 == 0) {

      pcVar5 = (char *)0x0;

    }

    else {

      if (*(int *)(iVar2 + 4) == 0) {

        uVar4 = FUN_00717fb0();

        *(uint32_t /* width from decompiler */ *)(iVar2 + 4) = uVar4;

      }

      pcVar5 = *(char **)(iVar2 + 4);

    }

    do {

      cVar1 = *pcVar5;

      *param_3 = cVar1;

      pcVar5 = pcVar5 + 1;

      param_3 = param_3 + 1;

    } while (cVar1 != '\0');

    if (local_10 != (uint8_t *)0x0) {

      FUN_00419e20();

    }

    local_4._0_1_ = 1;

    if (local_14 != (int *)0x0) {

      (**(code **)(*local_14 + 8))();

    }

    local_4 = (uint)local_4._1_3_ << 8;

    if (param_1 != (int *)0x0) {

      (**(code **)(*param_1 + 8))();

    }

  }

  SysFreeString(param_2);

  ExceptionList = pvStack_c;

  return;

}
