// =============================================================================
// FUN_00460da0
// -----------------------------------------------------------------------------
// Stable ID: aa_00460da0
// Address:   0x00460da0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00460da0 @ 0x00460da0
// Stable ID: aa_00460da0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, for×1.
//  - Notable callees: FUN_004540b0, FUN_00460da0, FUN_00461f80.
//  - Return sites: 2.

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

void __thiscall FUN_00460da0(int param_1,uint param_2)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  uint uVar4;

  void *pvVar5;

  int *piVar6;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009be630;

  local_10 = ExceptionList;

  ExceptionList = &local_10;

  if (0x15555555 < param_2) {

    ExceptionList = &local_10;

    FUN_004540b0();

  }

  if (*(int *)(param_1 + 4) == 0) {

    uVar4 = 0;

  }

  else {

    uVar4 = (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 4)) / 0xc;

  }

  if (uVar4 < param_2) {

    pvVar5 = operator_new(param_2 * 0xc);

    local_8 = 0;

    FUN_00461f80(*(uint32_t /* width from decompiler */ *)(param_1 + 4),*(uint32_t /* width from decompiler */ *)(param_1 + 8),pvVar5,param_2);

    local_8 = 0xffffffff;

    piVar6 = *(int **)(param_1 + 4);

    if (piVar6 != (int *)0x0) {

      piVar2 = *(int **)(param_1 + 8);

      for (; piVar6 != piVar2; piVar6 = piVar6 + 3) {

        piVar3 = (int *)*piVar6;

        if (piVar3 != (int *)0x0) {

          piVar1 = piVar3 + 1;

          *piVar1 = *piVar1 + -1;

          if (*piVar1 == 0) {

            (**(code **)(*piVar3 + 8))();

          }

        }

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(param_1 + 4));

    }

    *(void **)(param_1 + 0xc) = (void *)((int)pvVar5 + param_2 * 0xc);

    *(void **)(param_1 + 8) = pvVar5;

    *(void **)(param_1 + 4) = pvVar5;

  }

  ExceptionList = local_10;

  return;

}
