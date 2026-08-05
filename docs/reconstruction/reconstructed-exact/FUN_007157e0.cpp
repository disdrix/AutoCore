// =============================================================================
// FUN_007157e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007157e0
// Address:   0x007157e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007157e0 @ 0x007157e0
// Stable ID: aa_007157e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×9, do×4, while×4, return×1.
//  - Notable callees: FUN_007157e0.
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

void FUN_007157e0(float *param_1,float *param_2,int param_3,uint32_t /* width from decompiler */ param_4,float *param_5,

                 uint32_t /* width from decompiler */ *param_6,int *param_7,int param_8)



{

  float *pfVar1;

  float *pfVar2;

  float *pfVar3;

  float *pfVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  float *pfVar9;

  uint32_t /* width from decompiler */ *puVar10;

  int local_4;

  

  puVar10 = param_6;

  pfVar9 = param_5;

  pfVar1 = param_2;

  iVar8 = param_8;

  if (param_3 <= param_8) {

    iVar8 = param_3;

  }

  iVar5 = 0;

  if (0 < iVar8) {

    iVar7 = (int)param_6 - (int)param_5;

    pfVar2 = param_5;

    param_6 = (uint32_t /* width from decompiler */ *)iVar8;

    do {

      pfVar4 = pfVar2 + 1;

      *pfVar2 = *(float *)((int)param_1 + (-4 - (int)param_5) + (int)pfVar4);

      *(uint32_t /* width from decompiler */ *)((int)pfVar2 + iVar7) =

           *(uint32_t /* width from decompiler */ *)((int)param_2 + (-4 - (int)param_5) + (int)pfVar4);

      param_6 = (uint32_t /* width from decompiler */ *)((int)param_6 + -1);

      pfVar2 = pfVar4;

      iVar5 = iVar8;

    } while (param_6 != (uint32_t /* width from decompiler */ *)0x0);

  }

  local_4 = param_3 + -1;

  if (param_8 - iVar5 < param_3 + -1) {

    local_4 = param_8 - iVar5;

  }

  if (0 < local_4) {

    param_5 = param_1;

    pfVar2 = (float *)(puVar10 + iVar5);

    iVar5 = iVar5 + local_4;

    pfVar4 = param_2;

    do {

      pfVar3 = pfVar4 + 1;

      *(float *)((int)pfVar2 + ((int)pfVar9 - (int)puVar10)) =

           *(float *)(((int)param_1 - (int)param_2) + (int)pfVar3) * *param_5;

      param_5 = param_5 + 1;

      *pfVar2 = *pfVar3 - *pfVar4;

      local_4 = local_4 + -1;

      pfVar2 = pfVar2 + 1;

      pfVar4 = pfVar3;

    } while (local_4 != 0);

  }

  param_8 = param_8 - iVar5;

  if (param_3 + -2 <= param_8) {

    param_8 = param_3 + -2;

  }

  if (0 < param_8) {

    param_2 = param_1;

    pfVar2 = (float *)(puVar10 + iVar5);

    iVar5 = iVar5 + param_8;

    pfVar4 = pfVar1 + 2;

    do {

      *(float *)((int)pfVar2 + ((int)pfVar9 - (int)puVar10)) =

           *(float *)((int)pfVar4 + ((int)param_1 - (int)pfVar1)) * *param_2;

      param_2 = param_2 + 1;

      *pfVar2 = *pfVar4 - pfVar4[-2];

      param_8 = param_8 + -1;

      pfVar4 = pfVar4 + 1;

      pfVar2 = pfVar2 + 1;

    } while (param_8 != 0);

  }

  *param_7 = iVar5;

  if (9 < iVar5) {

    iVar8 = 0;

    if (0 < iVar5) {

      iVar6 = (int)puVar10 - (int)pfVar9;

      iVar7 = (int)pfVar9 - (int)puVar10;

      do {

        if (DAT_00a10e78 < *pfVar9) {

          iVar8 = iVar8 + 1;

          *(float *)((int)puVar10 + iVar7) = *pfVar9;

          *puVar10 = *(uint32_t /* width from decompiler */ *)((int)pfVar9 + iVar6);

          puVar10 = puVar10 + 1;

        }

        pfVar9 = pfVar9 + 1;

        iVar5 = iVar5 + -1;

      } while (iVar5 != 0);

    }

    *param_7 = iVar8;

  }

  return;

}
