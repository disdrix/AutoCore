// =============================================================================
// FUN_008b6eb0
// -----------------------------------------------------------------------------
// Stable ID: aa_008b6eb0
// Address:   0x008b6eb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b6eb0 @ 0x008b6eb0
// Stable ID: aa_008b6eb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×12, return×6.
//  - Notable callees: FUN_00401c30×2, ROUND×2, FUN_007fca10, FUN_0087b500, FUN_008b6be0, FUN_008b6eb0.
//  - Return sites: 6.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall FUN_008b6eb0(int param_1,int param_2,int param_3)



{

  int *piVar1;

  float fVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  float10 fVar5;

  

  if ((param_3 < 0xa7fe) || (0xb3b5 < param_3)) {

    if (param_3 == 40000) {

      if (param_2 == 8) {

        FUN_007fca10();

        return 1;

      }

    }

    else if (param_3 == 0x9c43) {

      if (param_2 == 0x1a) {

        piVar1 = *(int **)(param_1 + 0x524);

        if (((piVar1 != (int *)0x0) && (DAT_00d1ad2c != -4)) &&

           (iVar3 = FUN_00401c30(), *(int *)(param_1 + 0x520) < iVar3)) {

          fVar5 = (float10)(**(code **)(*piVar1 + 0x458))();

          iVar3 = FUN_00401c30();

          iVar3 = iVar3 - *(int *)(param_1 + 0x520);

          fVar2 = (float)iVar3;

          if (iVar3 < 0) {

            fVar2 = fVar2 + _DAT_00aaa5dc;

          }

          if (*(int *)(param_1 + 0x52c) != (int)ROUND(fVar2 * (float)fVar5)) {

            *(int *)(param_1 + 0x52c) = (int)ROUND(fVar2 * (float)fVar5);

            FUN_008b6be0(0xffffffff,0xffffffff);

            DAT_00d1d8f4 = 1;

            DAT_00d1d8f5 = 0;

            if (DAT_00d1d8dc != (int *)0x0) {

              (**(code **)(*DAT_00d1d8dc + 4))(0);

            }

          }

        }

        return 1;

      }

    }

    else if ((param_3 == 0x9c44) && (param_2 == 7)) {

      return 1;

    }

    uVar4 = FUN_0087b500(param_2,param_3);

    return uVar4;

  }

  if ((param_2 != 5) && (param_2 == 6)) {

    DAT_00d1d8f4 = 1;

    DAT_00d1d8f5 = 0;

    if (DAT_00d1d8dc != (int *)0x0) {

      (**(code **)(*DAT_00d1d8dc + 4))(0);

    }

    return 1;

  }

  return 1;

}
