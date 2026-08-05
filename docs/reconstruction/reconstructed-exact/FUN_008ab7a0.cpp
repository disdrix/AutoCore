// =============================================================================
// FUN_008ab7a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008ab7a0
// Address:   0x008ab7a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008ab7a0 @ 0x008ab7a0
// Stable ID: aa_008ab7a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00791f30, FUN_007fcdd0, FUN_008ab7a0, SQRT.
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

void __thiscall FUN_008ab7a0(int *param_1,float param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  char cVar5;

  float *pfVar6;

  

  fVar2 = g_flOne;

  fVar1 = (float)param_1[0x143];

  param_1[0x143] = (int)(param_2 + fVar1);

  if (fVar2 < param_2 + fVar1) {

    cVar5 = (**(code **)(*param_1 + 0x3d8))();

    if (cVar5 != '\0') {

      cVar5 = (**(code **)(*param_1 + 0xd0))();

      if ((((cVar5 != '\0') && (iVar4 = param_1[0x191], iVar4 != 0)) && (DAT_00d1b6d8 != 0)) &&

         (*(int *)(DAT_00d1b6d8 + 0x6b4) < 1)) {

        param_1[0x143] = 0;

        pfVar6 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) +

                                      0x1a0))();

        fVar1 = *pfVar6;

        fVar2 = pfVar6[1];

        fVar3 = pfVar6[2];

        pfVar6 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +

                                               DAT_00d1b6d8) + 0x1a0))();

        if (DAT_00aaa6fc <

            SQRT((*pfVar6 - fVar1) * (*pfVar6 - fVar1) +

                 (pfVar6[1] - fVar2) * (pfVar6[1] - fVar2) +

                 (pfVar6[2] - fVar3) * (pfVar6[2] - fVar3))) {

          FUN_007fcdd0(&DAT_00d1a840,10);

        }

      }

    }

  }

  FUN_00791f30(param_2);

  return;

}
