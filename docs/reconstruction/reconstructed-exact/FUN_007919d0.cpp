// =============================================================================
// FUN_007919d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007919d0
// Address:   0x007919d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007919d0 @ 0x007919d0
// Stable ID: aa_007919d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×7, return×3.
//  - Notable callees: FUN_00428340, FUN_00756be0, FUN_007919d0.
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

uint32_t /* width from decompiler */ __thiscall FUN_007919d0(int *param_1,int *param_2)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  int *piVar4;

  

  iVar3 = (int)param_2;

  if (param_1[0x130] == 0) {

    return 0;

  }

  if (param_2 != (int *)0x0) {

    if (param_2 == (int *)param_1[0x12f]) {

      (**(code **)(*param_1 + 0x3c0))(0);

    }

    if (iVar3 == param_1[0x12e]) {

      (**(code **)(*param_1 + 0x318))();

      param_1[0x12e] = 0;

    }

    param_2 = (int *)0x0;

    FUN_00428340(&param_2);

    piVar1 = param_2;

    if (param_2 != (int *)0x0) {

      iVar3 = (**(code **)(*param_2 + 0x34))();

      if (iVar3 != 0) {

        piVar4 = (int *)(**(code **)(*piVar1 + 0x34))();

        cVar2 = (**(code **)(*piVar4 + 0x3d8))();

        if (cVar2 != '\0') {

          piVar4 = (int *)(**(code **)(*piVar1 + 0x34))();

          (**(code **)(*piVar4 + 0x440))();

        }

      }

      (**(code **)(*param_1 + 0x3b0))(piVar1);

      piVar1[0xac] = 0;

      (**(code **)(*piVar1 + 0x334))(0);

      FUN_00756be0(piVar1);

      (**(code **)*piVar1)(1);

      return 1;

    }

  }

  return 0;

}
