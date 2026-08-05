// =============================================================================
// FUN_0059ff60
// -----------------------------------------------------------------------------
// Stable ID: aa_0059ff60
// Address:   0x0059ff60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0059ff60 @ 0x0059ff60
// Stable ID: aa_0059ff60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×9, return×1.
//  - Notable callees: FUN_0059e760, FUN_0059ea60, FUN_0059ed60, FUN_0059ff60.
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

void FUN_0059ff60(int param_1,int *param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  int *piVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a5fce;

  local_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &local_c;

  if (param_1 != 0) {

    if (param_3 == 0) {

      ExceptionList = &local_c;

      if (param_2 != (int *)0x0) {

        ExceptionList = &local_c;

        param_2[2] = param_2[2] + 1;

      }

      FUN_0059ea60(param_4);

    }

    else if (param_3 == 1) {

      ExceptionList = &local_c;

      if (param_2 != (int *)0x0) {

        ExceptionList = &local_c;

        param_2[2] = param_2[2] + 1;

      }

      FUN_0059e760(param_4);

    }

    else {

      ExceptionList = &local_c;

      if (param_3 == 2) {

        ExceptionList = &local_c;

        if (param_2 != (int *)0x0) {

          ExceptionList = &local_c;

          param_2[2] = param_2[2] + 1;

        }

        FUN_0059ed60(param_4);

      }

    }

  }

  local_4 = 0xffffffff;

  if (param_2 != (int *)0x0) {

    piVar1 = param_2 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*param_2 + 8))();

    }

  }

  ExceptionList = local_c;

  return;

}
