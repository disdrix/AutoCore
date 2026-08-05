// =============================================================================
// FUN_008c57a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008c57a0
// Address:   0x008c57a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c57a0 @ 0x008c57a0
// Stable ID: aa_008c57a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: Experience_GetCumulativeThreshold×2, FUN_008c57a0, ROUND, floor.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_008c57a0(int param_1)



{

  int iVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  ushort wLevel;

  short sVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint uVar7;

  int iVar8;

  uint uVar9;

  float fVar10;

  double dVar11;

  uint32_t /* width from decompiler */ uStack_c;

  

  iVar4 = param_1;

  if (DAT_00d1b6d8 != 0) {

    uVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                        0x27c))();

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x518) = uVar6;

    if ((*(int *)(param_1 + 0x574) != 0) || (*(int *)(param_1 + 0x57c) != 0)) {

      iVar1 = *(int *)(DAT_00d1b6d8 + 0x730);

      uVar9 = 0;

      wLevel = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                           0x27c))();

      uVar7 = Experience_GetCumulativeThreshold(wLevel);

      iVar8 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                          0x27c))();

      if (1 < iVar8) {

        sVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                            0x27c))();

        uVar9 = Experience_GetCumulativeThreshold(sVar5 - 1);

      }

      param_1 = uVar7 - uVar9;

      if (param_1 < 1) {

        param_1 = 1;

      }

      fVar2 = (float)(int)(iVar1 - uVar9);

      dVar11 = floor((double)((fVar2 / (float)param_1) * DAT_00a110d8));

      uStack_c = (int)ROUND(dVar11);

      if (uStack_c < 0) {

        uStack_c = 0;

      }

      else if (9 < uStack_c) {

        uStack_c = 9;

      }

      fVar10 = (float)param_1 * g_flMultiKillCountBlend;

      if (*(int **)(iVar4 + 0x574) != (int *)0x0) {

        fVar3 = (float)uStack_c * _DAT_00aaa7f0;

        (**(code **)(**(int **)(iVar4 + 0x574) + 0x3b0))();

        (**(code **)(**(int **)(iVar4 + 0x574) + 0x3ac))(fVar3);

      }

      if (*(int **)(iVar4 + 0x57c) != (int *)0x0) {

        (**(code **)(**(int **)(iVar4 + 0x57c) + 0x3b0))();

        (**(code **)(**(int **)(iVar4 + 0x57c) + 0x3ac))

                  ((fVar2 - (float)uStack_c * fVar10) / fVar10);

      }

    }

  }

  return;

}
