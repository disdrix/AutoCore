// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunker_SubmitForRende_005bfb80
// -----------------------------------------------------------------------------
// Stable ID: aa_005bfb80
// Callee of Named_CalleeOf_CVOGTerrainChunker_SubmitForRendering
// Address:   0x005bfb80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGTerrainChunker_SubmitForRendering: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~163 non-empty decompiler lines.
//  - Control keywords: if×14, do×4, while×4, return×1.
//  - Notable callees: FUN_005bf530×4, FUN_005bfb80, FUN_007464e0, FUN_00746520.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGTerrainChunker_SubmitForRendering
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint __thiscall Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunker_SubmitForRende_005bfb80(int param_1,int param_2,float *param_3)



{

  byte bVar1;

  uint uVar2;

  float *pfVar3;

  int iVar4;

  float *pfVar5;

  ushort uVar6;

  float *pfVar7;

  int iVar8;

  int iVar9;

  float *pfVar10;

  int iVar11;

  uint uVar12;

  int iVar13;

  float fVar14;

  int local_28;

  float *local_20;

  float *local_14;

  float *local_10;

  float *local_c;

  float *local_8;

  

  *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 1;

  local_10 = *(float **)(param_1 + 0x14);

  uVar12 = -(uint)(*(int *)(param_1 + 0xe0) != 1) & 0xffffffe8;

  iVar13 = uVar12 + 0x40;

  if ((local_10[4] != 0.0) &&

     (pfVar7 = (float *)FUN_00746520(local_10[5],local_10[6],0), local_10 = pfVar7,

     pfVar7 != (float *)0x0)) {

    iVar8 = *(int *)(param_2 + 0x18) / *(int *)(param_1 + 0xe0);

    iVar4 = iVar8 * 6;

    if (((*(uint *)(param_1 + 0xe4) ^ (uint)param_3) & 1) != 0) {

      bVar1 = *(byte *)(param_1 + 0xe4);

      local_28 = *(int *)(param_1 + 0xe0);

      if (0 < iVar4) {

        local_14 = pfVar7 + 1;

        local_8 = (float *)((int)pfVar7 + iVar13 * 2 + 4);

        local_20 = pfVar7 + iVar13 * 2 + 1;

        local_c = (float *)((iVar4 - 1U) / 0xc + 1);

        local_10 = (float *)((int)pfVar7 + iVar13 * 6 + 4);

        do {

          if ((bVar1 & 1) == 0) {

            fVar14 = (*local_14 + *local_20) * (float)_DAT_00aaa5e0;

          }

          else {

            uVar6 = FUN_005bf530(local_28 % DAT_00b03654,local_28 / DAT_00b03654);

            fVar14 = (float)uVar6 * *(float *)(param_2 + 0x44);

            local_28 = local_28 + *(int *)(param_1 + 0xe0) * 2;

          }

          local_20 = local_20 + iVar13 * 3;

          local_14 = local_14 + iVar13 * 3;

          *(float *)((int)local_8 + iVar13) = fVar14;

          *local_8 = fVar14;

          local_8 = local_8 + iVar13 * 3;

          local_c = (float *)((int)local_c + -1);

          *local_10 = fVar14;

          local_10 = local_10 + iVar13 * 3;

        } while (local_c != (float *)0x0);

      }

    }

    uVar2 = *(uint *)(param_1 + 0xe4);

    if (((uVar2 ^ (uint)param_3) & 2) != 0) {

      local_28 = *(int *)(param_2 + 0x1c) * *(int *)(param_2 + 0x18) + *(int *)(param_1 + 0xe0);

      iVar9 = (iVar8 + -1) * iVar4;

      if (iVar9 < iVar9 + iVar4) {

        local_14 = (float *)((iVar9 + 1) * iVar13 + 4 + (int)pfVar7);

        local_10 = (float *)((iVar9 + 0xb) * iVar13 + 4 + (int)pfVar7);

        iVar11 = (((iVar9 + iVar4) - iVar9) - 1U) / 0xc + 1;

        local_20 = (float *)((iVar9 + 5) * iVar13 + 4 + (int)pfVar7);

        local_c = (float *)((iVar9 + 7) * iVar13 + 4 + (int)pfVar7);

        local_8 = (float *)((iVar9 + 10) * iVar13 + 4 + (int)pfVar7);

        do {

          if ((uVar2 & 2) == 0) {

            fVar14 = (*local_10 + *local_14) * (float)_DAT_00aaa5e0;

          }

          else {

            uVar6 = FUN_005bf530(local_28 % DAT_00b03654,local_28 / DAT_00b03654);

            fVar14 = (float)uVar6 * *(float *)(param_2 + 0x44);

            local_28 = local_28 + *(int *)(param_1 + 0xe0) * 2;

          }

          local_10 = local_10 + iVar13 * 3;

          local_14 = local_14 + iVar13 * 3;

          *local_20 = fVar14;

          *local_c = fVar14;

          iVar11 = iVar11 + -1;

          *local_8 = fVar14;

          local_20 = local_20 + iVar13 * 3;

          local_c = local_c + iVar13 * 3;

          local_8 = local_8 + iVar13 * 3;

        } while (iVar11 != 0);

      }

    }

    uVar2 = *(uint *)(param_1 + 0xe4);

    if (((uVar2 ^ (uint)param_3) & 4) != 0) {

      local_28 = *(int *)(param_1 + 0xe0) * *(int *)(param_2 + 0x1c);

      local_8 = (float *)0x0;

      if (0 < iVar4 * iVar8) {

        iVar9 = iVar4 * iVar13 * 2;

        local_20 = pfVar7 + 1;

        local_10 = (float *)((int)pfVar7 + iVar4 * iVar13 + 4);

        local_c = pfVar7 + uVar12 + 0x41;

        do {

          if ((uVar2 & 4) == 0) {

            fVar14 = (*(float *)(((int)local_8 + 1 + iVar4) * iVar13 + 4 + (int)pfVar7) + *local_20)

                     * (float)_DAT_00aaa5e0;

          }

          else {

            uVar6 = FUN_005bf530(local_28 % DAT_00b03654,local_28 / DAT_00b03654);

            fVar14 = (float)uVar6 * *(float *)(param_2 + 0x44);

            local_28 = local_28 + *(int *)(param_1 + 0xe0) * *(int *)(param_2 + 0x1c) * 2;

          }

          local_8 = (float *)((int)local_8 + iVar8 * 0xc);

          *(float *)((int)local_20 + iVar13) = fVar14;

          *local_c = fVar14;

          *local_10 = fVar14;

          local_20 = (float *)((int)local_20 + iVar9);

          local_10 = (float *)((int)local_10 + iVar9);

          local_c = (float *)((int)local_c + iVar9);

        } while ((int)local_8 < iVar4 * iVar8);

      }

    }

    pfVar3 = *(float **)(param_1 + 0xe4);

    local_10 = pfVar3;

    if ((((uint)pfVar3 ^ (uint)param_3) & 8) != 0) {

      local_28 = *(int *)(param_1 + 0xe0) * *(int *)(param_2 + 0x1c) + *(int *)(param_2 + 0x18);

      iVar9 = iVar4 + -6;

      pfVar10 = (float *)(iVar4 * iVar8);

      local_10 = pfVar10;

      if (iVar9 < (int)pfVar10) {

        iVar11 = iVar4 * iVar13 * 2;

        param_3 = (float *)((iVar4 + -4) * iVar13 + 4 + (int)pfVar7);

        pfVar5 = (float *)((iVar8 * 0xc + -3) * iVar13 + 4 + (int)pfVar7);

        local_c = (float *)((iVar8 * 0xc + -4) * iVar13 + 4 + (int)pfVar7);

        local_8 = (float *)((iVar4 + -1) * iVar13 + 4 + (int)pfVar7);

        do {

          local_10 = pfVar5;

          if (((uint)pfVar3 & 8) == 0) {

            fVar14 = (*(float *)((iVar9 + 5 + iVar4) * iVar13 + 4 + (int)pfVar7) + *param_3) *

                     (float)_DAT_00aaa5e0;

          }

          else {

            uVar6 = FUN_005bf530(local_28 % DAT_00b03654,local_28 / DAT_00b03654);

            fVar14 = (float)uVar6 * *(float *)(param_2 + 0x44);

            local_28 = local_28 + *(int *)(param_1 + 0xe0) * *(int *)(param_2 + 0x1c) * 2;

          }

          iVar9 = iVar9 + iVar8 * 0xc;

          param_3 = (float *)((int)param_3 + iVar11);

          *local_8 = fVar14;

          *local_c = fVar14;

          *local_10 = fVar14;

          pfVar5 = (float *)((int)local_10 + iVar11);

          local_c = (float *)((int)local_c + iVar11);

          local_8 = (float *)((int)local_8 + iVar11);

        } while (iVar9 < (int)pfVar10);

      }

    }

  }

  if (*(int *)(*(int *)(param_1 + 0x14) + 0x10) != 0) {

    local_10 = (float *)FUN_007464e0();

  }

  return (uint)local_10 & 0xffffff00;

}
