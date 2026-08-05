// =============================================================================
// FUN_0048c530
// -----------------------------------------------------------------------------
// Stable ID: aa_0048c530
// Address:   0x0048c530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048c530 @ 0x0048c530
// Stable ID: aa_0048c530
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, for×1, do×1, while×1.
//  - Notable callees: FUN_0048c020×2, FUN_0048a940, FUN_0048b1c0, FUN_0048b240, FUN_0048c530, FUN_0048d0a0.
//  - Return sites: 3.

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

void __thiscall FUN_0048c530(int *param_1,uint32_t /* width from decompiler */ *param_2,char *param_3)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char *pcVar3;

  int iVar4;

  void *pvVar5;

  char *pcVar6;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  puVar2 = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a069b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0048c020(param_2);

  pcVar3 = param_3;

  local_4 = 0;

  FUN_0048c020(param_3);

  local_4._0_1_ = 1;

  iVar4 = FUN_0048b1c0(&param_2);

  if (iVar4 == 0) {

    pvVar5 = operator_new(0x24);

    local_4._0_1_ = 2;

    if (pvVar5 == (void *)0x0) {

      iVar4 = 0;

    }

    else {

      iVar4 = FUN_0048b240(puVar2,pcVar3);

    }

    local_4._0_1_ = 1;

    if (iVar4 == 0) {

      for (; param_1 != (int *)0x0; param_1 = (int *)param_1[4]) {

        iVar4 = (**(code **)(*param_1 + 0x10))();

        if (iVar4 != 0) {

          iVar4 = (**(code **)(*param_1 + 0x10))();

          if (iVar4 != 0) {

            FUN_0048d0a0(3,0,0,0);

          }

          break;

        }

      }

    }

    else {

      *(int **)(iVar4 + 0x20) = param_1 + 0xb;

      *(int *)(iVar4 + 0x1c) = param_1[0x12];

      *(int *)(param_1[0x12] + 0x20) = iVar4;

      param_1[0x12] = iVar4;

    }

  }

  else {

    pcVar6 = pcVar3;

    do {

      cVar1 = *pcVar6;

      pcVar6 = pcVar6 + 1;

    } while (cVar1 != '\0');

    FUN_0048a940(pcVar3,(int)pcVar6 - (int)(pcVar3 + 1));

  }

  local_4 = (uint)local_4._1_3_ << 8;

  if (param_3 != (char *)&DAT_00b03504) {

                    /* WARNING: Subroutine does not return */

    operator_delete(param_3);

  }

  local_4 = 0xffffffff;

  if (param_2 == &DAT_00b03504) {

    ExceptionList = local_c;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(param_2);

}
