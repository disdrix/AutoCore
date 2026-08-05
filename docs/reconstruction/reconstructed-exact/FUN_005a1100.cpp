// =============================================================================
// FUN_005a1100
// -----------------------------------------------------------------------------
// Stable ID: aa_005a1100
// Address:   0x005a1100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a1100 @ 0x005a1100
// Stable ID: aa_005a1100
// Embedded strings (evidence for future rename):
//   - "Group %d message %d (%d bytes)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: CONCAT31, FUN_005a1100, FUN_005a3160, FUN_005a4240, FUN_007a4480, d.
//  - Strings: "Group %d message %d (%d bytes)".
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

void __thiscall FUN_005a1100(int *param_1,int param_2,int *param_3,uint32_t /* width from decompiler */ param_4,int param_5)



{

  int *piVar1;

  uint8_t local_1c [4];

  void *local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a60bc;

  pvStack_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  if (DAT_00b04ec0 != '\0') {

    ExceptionList = &pvStack_c;

    FUN_007a4480(0xffffffff,"Group %d message %d (%d bytes)");

  }

  if (param_2 == 0) {

    local_18 = (void *)0x0;

    local_14 = 0;

    local_10 = 0;

    local_4 = CONCAT31(local_4._1_3_,1);

    FUN_005a4240();

    if (param_3 != (int *)0x0) {

      param_3[2] = param_3[2] + 1;

    }

    (**(code **)(*param_1 + 0x1c))(local_1c);

    if (local_18 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(local_18);

    }

  }

  else {

    FUN_005a3160();

    if (param_5 != param_1[0x2f]) {

      if (param_3 != (int *)0x0) {

        param_3[2] = param_3[2] + 1;

      }

      (**(code **)(*param_1 + 0x1c))(param_5 + 0x10);

    }

  }

  local_4 = 0xffffffff;

  if (param_3 != (int *)0x0) {

    piVar1 = param_3 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*param_3 + 8))();

    }

  }

  ExceptionList = pvStack_c;

  return;

}
