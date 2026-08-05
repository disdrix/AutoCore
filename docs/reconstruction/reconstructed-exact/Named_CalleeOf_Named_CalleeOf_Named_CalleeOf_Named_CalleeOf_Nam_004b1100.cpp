// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004b1100
// -----------------------------------------------------------------------------
// Stable ID: aa_004b1100
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x004b1100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~200 non-empty decompiler lines.
//  - Control keywords: if×19, return×2.
//  - Notable callees: FUN_0076e240×3, FUN_0099b8b0×3, FUN_005c4e30×2, FUN_0076e5e0×2, FUN_0076f5f0×2, FUN_004b1100, FUN_004b49a0, FUN_004cd220.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004b1100(int *param_1,int param_2,uint32_t /* width from decompiler */ param_3,float param_4)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  char cVar7;

  int iVar8;

  float *pfVar9;

  int iVar10;

  float *pfVar11;

  int *piVar12;

  float10 fVar13;

  float fVar14;

  float fVar15;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  uint8_t local_1c [12];

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  local_28 = (float)param_1[0x5e];

  piVar12 = (int *)*param_1;

  iVar4 = param_1[1];

  pfVar1 = (float *)(param_1 + 0x5e);

  local_24 = (float)param_1[0x5f];

  local_20 = (float)param_1[0x60];

  if ((uint32_t /* width from decompiler */ *)*piVar12 == (uint32_t /* width from decompiler */ *)0x0) {

    if ((((*(byte *)(iVar4 + 0x1e8) & 0x80) != 0) && ((char)param_1[0x90] == '\0')) &&

       ((*(byte *)((int)piVar12 + 0x98a) & 0x20) != 0)) {

      FUN_0076e240(&local_34,piVar12 + 0x208,piVar12 + 0x20b);

      FUN_0099b8b0(*param_1 + 0x820,&local_34);

      FUN_0076e5e0(&local_10,&local_10);

      FUN_004e8590(*param_1 + 0x814,&local_10,pfVar1,local_1c);

      FUN_0076e240(&local_34,*param_1 + 0x844,*param_1 + 0x850);

      FUN_0099b8b0(*param_1 + 0x844,&local_34);

      FUN_0076e5e0(&local_10,&local_10);

      FUN_004e8320(*param_1 + 0x838,&local_10,local_1c,pfVar1);

    }

    if (((*(byte *)(iVar4 + 0x3e3) & 8) == 0) || (*(int *)(*param_1 + 0xc) == 0)) {

      if ((*(byte *)(iVar4 + 0x1e4) & 8) != 0) {

        if ((*(byte *)(iVar4 + 0x1e9) & 1) == 0) {

          piVar12 = (int *)(*param_1 + 0x838);

        }

        else {

          piVar12 = param_1 + 0x67;

        }

        iVar8 = *param_1;

        FUN_005c36f0(pfVar1,piVar12,iVar4,param_1 + 0x81,param_3,iVar8 + 0x88c,iVar8 + 0x8a4,

                     iVar8 + 0x898,param_4);

      }

      if ((*(byte *)(iVar4 + 0x1e4) & 0x20) != 0) {

        if ((*(byte *)(iVar4 + 0x1e9) & 1) == 0) {

          piVar12 = (int *)(*param_1 + 0x838);

        }

        else {

          piVar12 = param_1 + 0x67;

        }

        FUN_005c4040(pfVar1,piVar12,iVar4,param_1 + 0x87,*param_1,param_3,param_4);

      }

      if ((*(byte *)(iVar4 + 0x1e4) & 0x10) != 0) {

        iVar8 = *param_1;

        FUN_005c2de0(pfVar1,param_1[1],param_1 + 0x6c,param_3,iVar8 + 0x88c,iVar8 + 0x8a4,

                     iVar8 + 0x898,param_4);

      }

      if ((*(byte *)(iVar4 + 0x1e4) & 0x40) != 0) {

        pfVar9 = (float *)(param_1 + 0x61);

        FUN_0076e240(local_1c,pfVar9,param_1 + 100);

        FUN_0099b8b0(pfVar9,local_1c);

        iVar8 = *param_1;

        cVar7 = FUN_005c2030(*(uint32_t /* width from decompiler */ *)(iVar8 + 4),pfVar1,&local_10,param_1[1],param_1 + 0x75,

                             param_3,iVar8 + 0x88c,iVar8 + 0x8a4,iVar8 + 0x898,param_4);

        local_2c = g_flLevelUpUiBase_Inferred;

        local_34 = g_flOne;

        if (cVar7 != '\0') {

          param_1[0x5c] = DAT_00aaa668;

          return;

        }

        fVar14 = (local_8 * local_c - local_4 * local_10) * g_flLevelUpUiBase_Inferred;

        fVar15 = g_flOne - (local_10 * local_10 + local_c * local_c) * g_flLevelUpUiBase_Inferred;

        *pfVar9 = (local_4 * local_c + local_8 * local_10) * g_flLevelUpUiBase_Inferred;

        local_34 = local_34 - (local_8 * local_8 + local_c * local_c) * local_2c;

        param_1[0x62] = (int)fVar14;

        local_30 = (local_c * local_10 + local_4 * local_8) * local_2c;

        local_2c = (local_8 * local_10 - local_4 * local_c) * local_2c;

        param_1[99] = (int)fVar15;

        param_1[100] = (int)local_34;

        param_1[0x65] = (int)local_30;

        param_1[0x66] = (int)local_2c;

      }

      if ((param_2 != 0) && ((*(byte *)(*param_1 + 0x98c) & 0x20) != 0)) {

        fVar13 = (float10)FUN_004cd220(*pfVar1,param_1[0x60]);

        if (((float)param_1[0x5f] < (float)(fVar13 + (float10)DAT_00a0f718)) &&

           ((param_1[0x5f] = (int)(float)(fVar13 + (float10)DAT_00a0f718),

            (*(byte *)(iVar4 + 0x1e4) & 0x10) != 0 &&

            ((float)param_1[0x6d] <= 0.0 && (float)param_1[0x6d] != 0.0)))) {

          param_1[0x6d] = (int)(0.0 - *(float *)(*param_1 + 0x904) * (float)param_1[0x6d]);

        }

      }

    }

    else {

      pfVar11 = (float *)FUN_005c4e30(param_1[0x6a]);

      iVar8 = *param_1;

      fVar14 = pfVar11[2];

      local_34 = *(float *)(iVar8 + 0x880) + (*pfVar11 - *pfVar1);

      pfVar9 = (float *)(param_1 + 0x6c);

      local_30 = *(float *)(iVar8 + 0x884) + (pfVar11[1] - (float)param_1[0x5f]);

      local_2c = *(float *)(iVar8 + 0x888);

      *pfVar9 = local_34;

      param_1[0x6d] = (int)local_30;

      local_2c = local_2c + (fVar14 - (float)param_1[0x60]);

      param_1[0x6e] = (int)local_2c;

      if (param_4 * *(float *)(iVar4 + 0x3c) <=

          SQRT((float)param_1[0x6e] * (float)param_1[0x6e] +

               (float)param_1[0x6d] * (float)param_1[0x6d] + *pfVar9 * *pfVar9)) {

        FUN_0076f5f0(pfVar9,pfVar9);

        fVar14 = *(float *)(iVar4 + 0x3c);

        *pfVar9 = *pfVar9 * fVar14;

        param_1[0x6e] = (int)(fVar14 * (float)param_1[0x6e]);

        param_1[0x6d] = (int)(fVar14 * (float)param_1[0x6d]);

        *pfVar1 = *pfVar9 * param_4 + *pfVar1;

        param_1[0x5f] = (int)((float)param_1[0x5f] + (float)param_1[0x6d] * param_4);

        param_1[0x60] = (int)((float)param_1[0x60] + (float)param_1[0x6e] * param_4);

      }

      else {

        pfVar9 = (float *)FUN_005c4e30(param_1[0x6a]);

        fVar14 = pfVar9[1];

        fVar15 = *(float *)(iVar8 + 0x884);

        fVar2 = pfVar9[2];

        fVar3 = *(float *)(iVar8 + 0x888);

        *pfVar1 = *(float *)(iVar8 + 0x880) + *pfVar9;

        param_1[0x5f] = (int)(fVar14 + fVar15);

        param_1[0x60] = (int)(fVar2 + fVar3);

      }

    }

  }

  else {

    iVar8 = (*(code *)**(uint32_t /* width from decompiler */ **)*piVar12)();

    uVar5 = param_1[0x6a];

    if ((uVar5 < *(uint *)(iVar8 + 0x14)) && (-1 < (int)uVar5)) {

      iVar8 = (**(code **)**(uint32_t /* width from decompiler */ **)*param_1)();

      local_34 = *(float *)(*(int *)(iVar8 + 4) + uVar5 * 0xc);

      iVar8 = *(int *)(iVar8 + 4) + uVar5 * 0xc;

      local_30 = *(float *)(iVar8 + 4);

      local_2c = *(float *)(iVar8 + 8);

      pfVar9 = (float *)FUN_004b49a0(&local_34);

      *pfVar1 = *pfVar9;

      param_1[0x5f] = (int)pfVar9[1];

      param_1[0x60] = (int)pfVar9[2];

      puVar6 = *(uint32_t /* width from decompiler */ **)*param_1;

      if (*(char *)(puVar6 + 6) != '\0') {

        iVar8 = param_1[0x6a];

        iVar10 = (**(code **)*puVar6)();

        fVar14 = (float)puVar6[8] - *(float *)(*(int *)(iVar10 + 0x1c) + iVar8 * 4);

        if (fVar14 < DAT_00a0f298) {

          iVar8 = *param_1;

          fVar15 = *(float *)(iVar8 + 0x8b4);

          fVar2 = *(float *)(iVar8 + 0x8b8);

          fVar14 = (DAT_00a0f298 - fVar14) * param_4 * DAT_00aaa8dc;

          *pfVar1 = *pfVar1 + *(float *)(iVar8 + 0x8b0) * fVar14;

          param_1[0x5f] = (int)((float)param_1[0x5f] + fVar15 * fVar14);

          param_1[0x60] = (int)((float)param_1[0x60] + fVar2 * fVar14);

        }

      }

    }

  }

  iVar8 = *param_1;

  if (*(int *)(iVar8 + 0x984) == 2) {

    local_34 = *pfVar1 - local_28;

    local_30 = (float)param_1[0x5f] - local_24;

    pfVar9 = (float *)(param_1 + 0x61);

    local_2c = (float)param_1[0x60] - local_20;

    *pfVar9 = local_34;

    param_1[0x62] = (int)local_30;

    param_1[99] = (int)local_2c;

    FUN_0076f5f0(pfVar9,pfVar9);

  }

  else if (*(int *)(iVar8 + 0x984) == 4) {

    param_1[0x61] = *(int *)(iVar8 + 0x844);

    param_1[0x62] = *(int *)(iVar8 + 0x848);

    param_1[99] = *(int *)(iVar8 + 0x84c);

  }

  if (((((*(byte *)(iVar4 + 0x1e8) & 0x80) != 0) && ((char)param_1[0x90] == '\0')) &&

      (piVar12 = (int *)*param_1, (*(byte *)((int)piVar12 + 0x98a) & 0x20) == 0)) && (*piVar12 == 0)

     ) {

    fVar14 = (float)piVar12[0x218];

    fVar15 = (float)piVar12[0x219];

    *pfVar1 = *pfVar1 + param_4 * (float)piVar12[0x217];

    param_1[0x5f] = (int)(fVar14 * param_4 + (float)param_1[0x5f]);

    param_1[0x60] = (int)(fVar15 * param_4 + (float)param_1[0x60]);

  }

  return;

}
