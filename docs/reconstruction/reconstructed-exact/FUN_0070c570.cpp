// =============================================================================
// FUN_0070c570
// -----------------------------------------------------------------------------
// Stable ID: aa_0070c570
// Address:   0x0070c570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0070c570 @ 0x0070c570
// Stable ID: aa_0070c570
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×6, do×4, while×4, return×1.
//  - Notable callees: FUN_00702cb0×2, FUN_0070c570.
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



void FUN_0070c570(float *param_1,int *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,float *param_5)



{

  int iVar1;

  float fVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  float *pfVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int iVar8;

  int iVar9;

  int *piVar10;

  int local_10;

  

  iVar8 = param_2[4];

  iVar6 = param_2[1];

  iVar3 = (int)param_5 + (-(int)param_5 & 3U) + iVar6 * 4;

  piVar10 = (int *)(iVar3 + iVar6 * -4);

  iVar1 = *param_2;

  puVar7 = (uint32_t /* width from decompiler */ *)((-iVar3 & 3U) + iVar3);

  iVar3 = param_2[2];

  if (0 < iVar6) {

    param_5 = (float *)puVar7;

    local_10 = iVar6;

    do {

      if (iVar8 == 0) {

        *param_5 = 0.0;

      }

      else {

        uVar4 = FUN_00702cb0(param_4,1);

        *param_5 = (float)uVar4;

      }

      uVar4 = FUN_00702cb0(param_4,param_2[3]);

      *(uint32_t /* width from decompiler */ *)(((int)piVar10 - (int)puVar7) + (int)param_5) = uVar4;

      param_5 = param_5 + 1;

      local_10 = local_10 + -1;

    } while (local_10 != 0);

    if (0 < iVar6) {

      iVar8 = (int)puVar7 - (int)piVar10;

      param_2 = (int *)0x0;

      param_5 = param_1;

      local_10 = iVar6;

      do {

        fVar2 = g_flOne;

        if (*(int *)(iVar8 + (int)piVar10) != 0) {

          fVar2 = DAT_00aaa668;

        }

        iVar6 = 0;

        if (3 < iVar1) {

          pfVar5 = param_5;

          do {

            *pfVar5 = (float)(int)*(char *)(*piVar10 * iVar1 + iVar6 + iVar3) * fVar2 *

                      (float)_DAT_00a0f258 + *pfVar5;

            pfVar5[1] = (float)(int)*(char *)(*piVar10 * iVar1 + iVar6 + 1 + iVar3) * fVar2 *

                        (float)_DAT_00a0f258 + pfVar5[1];

            pfVar5[2] = (float)(int)*(char *)(*piVar10 * iVar1 + iVar6 + 2 + iVar3) * fVar2 *

                        (float)_DAT_00a0f258 + pfVar5[2];

            iVar9 = *piVar10 * iVar1 + iVar6;

            iVar6 = iVar6 + 4;

            pfVar5[3] = (float)(int)*(char *)(iVar9 + 3 + iVar3) * fVar2 * (float)_DAT_00a0f258 +

                        pfVar5[3];

            pfVar5 = pfVar5 + 4;

          } while (iVar6 < iVar1 + -3);

        }

        if (iVar6 < iVar1) {

          pfVar5 = param_1 + (int)param_2 + iVar6;

          do {

            iVar9 = *piVar10 * iVar1 + iVar6;

            iVar6 = iVar6 + 1;

            *pfVar5 = (float)(int)*(char *)(iVar3 + iVar9) * fVar2 * (float)_DAT_00a0f258 + *pfVar5;

            pfVar5 = pfVar5 + 1;

          } while (iVar6 < iVar1);

        }

        param_5 = param_5 + iVar1;

        param_2 = (int *)((int)param_2 + iVar1);

        piVar10 = piVar10 + 1;

        local_10 = local_10 + -1;

      } while (local_10 != 0);

    }

  }

  return;

}
