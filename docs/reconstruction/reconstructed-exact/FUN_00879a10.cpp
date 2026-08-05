// =============================================================================
// FUN_00879a10
// -----------------------------------------------------------------------------
// Stable ID: aa_00879a10
// Address:   0x00879a10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00879a10 @ 0x00879a10
// Stable ID: aa_00879a10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00791f30, FUN_007fcdd0, FUN_008793d0, FUN_00879510, FUN_00879a10, SQRT.
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

void __thiscall FUN_00879a10(int *param_1,float param_2)



{

  char cVar1;

  float *pfVar2;

  

  param_1[0x14a] = (int)(param_2 + (float)param_1[0x14a]);

  param_1[0x148] = (int)(param_2 + (float)param_1[0x148]);

  if ((int *)param_1[0x16e] != (int *)0x0) {

    cVar1 = (**(code **)(*(int *)param_1[0x16e] + 0x3bc))();

    if (cVar1 == '\0') {

      FUN_008793d0();

    }

    else {

      FUN_00879510();

    }

  }

  param_1[0x143] = (int)((float)param_1[0x143] + param_2);

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if ((((cVar1 != '\0') && (g_flOne < (float)param_1[0x143])) && (DAT_00d1b6d8 != 0)) &&

     (*(int *)(DAT_00d1b6d8 + 0x6b4) < 1)) {

    param_1[0x143] = 0;

    pfVar2 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +

                                           DAT_00d1b6d8) + 0x1a0))();

    if (DAT_00aaa6fc <

        SQRT((*pfVar2 - (float)param_1[0x144]) * (*pfVar2 - (float)param_1[0x144]) +

             (pfVar2[1] - (float)param_1[0x145]) * (pfVar2[1] - (float)param_1[0x145]) +

             (pfVar2[2] - (float)param_1[0x146]) * (pfVar2[2] - (float)param_1[0x146]))) {

      FUN_007fcdd0(&DAT_00d1a840,0x25);

    }

  }

  FUN_00791f30(param_2);

  return;

}
