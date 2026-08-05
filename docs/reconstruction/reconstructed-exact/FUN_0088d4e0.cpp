// =============================================================================
// FUN_0088d4e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0088d4e0
// Address:   0x0088d4e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0088d4e0 @ 0x0088d4e0
// Stable ID: aa_0088d4e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00791f30, FUN_007fcdd0, FUN_0088d4e0, SQRT.
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

void __thiscall FUN_0088d4e0(int *param_1,float param_2)



{

  float fVar1;

  float fVar2;

  char cVar3;

  float *pfVar4;

  

  cVar3 = (**(code **)(*param_1 + 0x3d8))();

  fVar2 = g_flOne;

  if (cVar3 != '\0') {

    fVar1 = (float)param_1[0x143];

    param_1[0x143] = (int)(fVar1 + param_2);

    if (((fVar2 < fVar1 + param_2) && (DAT_00d1b6d8 != 0)) && (*(int *)(DAT_00d1b6d8 + 0x6b4) < 1))

    {

      param_1[0x143] = 0;

      pfVar4 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +

                                             DAT_00d1b6d8) + 0x1a0))();

      if (DAT_00aaa6fc <

          SQRT((*pfVar4 - (float)param_1[0x148]) * (*pfVar4 - (float)param_1[0x148]) +

               (pfVar4[1] - (float)param_1[0x149]) * (pfVar4[1] - (float)param_1[0x149]) +

               (pfVar4[2] - (float)param_1[0x14a]) * (pfVar4[2] - (float)param_1[0x14a]))) {

        FUN_007fcdd0(&DAT_00d1a840,0xc);

      }

    }

    (**(code **)(*param_1 + 0x470))(param_2);

  }

  FUN_00791f30(param_2);

  return;

}
