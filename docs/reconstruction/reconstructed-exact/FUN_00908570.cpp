// =============================================================================
// FUN_00908570
// -----------------------------------------------------------------------------
// Stable ID: aa_00908570
// Address:   0x00908570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00908570 @ 0x00908570
// Stable ID: aa_00908570
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: FUN_00791f30×2, GetTickCount×2, FUN_007fcdd0, FUN_00907910, FUN_00907c30, FUN_00908200, FUN_00908570, SQRT.
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

void __thiscall FUN_00908570(int *param_1,float param_2)



{

  char cVar1;

  float *pfVar2;

  DWORD DVar3;

  int iVar4;

  int iVar5;

  

  param_1[0x17c] = (int)(param_2 + (float)param_1[0x17c]);

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if ((((cVar1 != '\0') && (g_flOne < (float)param_1[0x17c])) && (DAT_00d1b6d8 != 0)) &&

     (*(int *)(DAT_00d1b6d8 + 0x6b4) < 1)) {

    param_1[0x17c] = 0;

    pfVar2 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +

                                           DAT_00d1b6d8) + 0x1a0))();

    if (DAT_00aaa6fc <

        SQRT((*pfVar2 - (float)param_1[0x178]) * (*pfVar2 - (float)param_1[0x178]) +

             (pfVar2[1] - (float)param_1[0x179]) * (pfVar2[1] - (float)param_1[0x179]) +

             (pfVar2[2] - (float)param_1[0x17a]) * (pfVar2[2] - (float)param_1[0x17a]))) {

      FUN_007fcdd0(&DAT_00d1a840,0x37);

    }

  }

  if ((int *)param_1[0x19a] != (int *)0x0) {

    cVar1 = (**(code **)(*(int *)param_1[0x19a] + 0xd8))();

    if (cVar1 == '\0') {

      DVar3 = GetTickCount();

      if (3999 < DVar3 - param_1[0x143]) {

        (**(code **)(*(int *)param_1[0x19a] + 0xd4))(1);

        (**(code **)(*(int *)param_1[0x19a] + 0x34c))();

      }

    }

  }

  DVar3 = GetTickCount();

  if (3999 < DVar3 - param_1[0x144]) {

    FUN_00907910(0);

  }

  FUN_00907c30(0);

  if (DAT_00d1b6d8 != 0) {

    iVar4 = *(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728);

    iVar5 = (*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

            (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) < *(uint *)(DAT_00d1b6d8 + 0x728));

    if ((param_1[0x17e] == iVar4) && (param_1[0x17f] == iVar5)) {

      FUN_00791f30(param_2);

      return;

    }

    param_1[0x17e] = iVar4;

    param_1[0x17f] = iVar5;

    FUN_00908200();

  }

  FUN_00791f30(param_2);

  return;

}
