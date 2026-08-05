// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006a2f30
// -----------------------------------------------------------------------------
// Stable ID: aa_006a2f30
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x006a2f30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, while×1.
//  - Notable callees: FUN_006a2530×2, FUN_00697f60, FUN_00698400, FUN_006a1be0, FUN_006a1cd0, FUN_006a24d0, FUN_006a2580, FUN_006a2f30.
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006a2f30(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  float fVar2;

  float fVar3;

  void *pvVar4;

  int iVar5;

  int iVar6;

  float *pfVar7;

  float *pfVar8;

  int *piVar9;

  float10 fVar10;

  int local_68;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_44;

  float local_38;

  uint8_t local_34 [12];

  uint8_t local_28 [12];

  uint8_t local_1c [4];

  void *local_18;

  int *local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ab376;

  local_c = ExceptionList;

  local_68 = 0;

  ExceptionList = &local_c;

  if ((DAT_00d08fb8 & 1) == 0) {

    DAT_00d08fb8 = DAT_00d08fb8 | 1;

    local_4 = 0;

    ExceptionList = &local_c;

    FUN_006a1cd0();

    _atexit((_func_4879 *)&LAB_009c55c0);

  }

  local_18 = (void *)0x0;

  local_14 = (int *)0x0;

  local_10 = 0;

  piVar9 = *(int **)(param_1 + 4);

  local_4 = 1;

  if (piVar9 != *(int **)(param_1 + 8)) {

    do {

      fVar10 = (float10)FUN_006a1be0(0,0x3f800000);

      if ((float10)*(float *)(param_1 + 0x14) < fVar10) {

        iVar5 = FUN_006a24d0();

        iVar6 = *piVar9;

        iVar1 = piVar9[1];

        local_44 = *(float *)(iVar1 + 0xc) + *(float *)(iVar6 + 0xc);

        local_64 = (*(float *)(iVar1 + 4) + *(float *)(iVar6 + 4)) * DAT_00a0f298;

        local_60 = (*(float *)(iVar1 + 8) + *(float *)(iVar6 + 8)) * DAT_00a0f298;

        iVar6 = (uint)(*(byte *)(iVar6 + 0x40) >> 1) * 0x54 +

                *(int *)(*(int *)(param_1 + 0x18) + 0x10);

        local_5c = local_44 * DAT_00a0f298;

        fVar2 = *(float *)(iVar6 + 0x4c) * *(float *)(param_1 + 0x1c) * DAT_00a0f298;

        fVar3 = *(float *)(iVar6 + 0x34) - DAT_00a0f298;

        *(float *)(iVar5 + 4) = local_64;

        *(float *)(iVar5 + 8) = local_60;

        local_5c = fVar3 * fVar2 + local_5c;

        *(float *)(iVar5 + 0xc) = local_5c;

        local_68 = iVar5;

        pfVar7 = (float *)FUN_006a2530(local_34);

        pfVar8 = (float *)FUN_006a2530(local_28);

        local_38 = pfVar7[2] + pfVar8[2];

        local_58 = (*pfVar8 + *pfVar7) * DAT_00a0f298;

        local_54 = (pfVar7[1] + pfVar8[1]) * DAT_00a0f298;

        local_50 = local_38 * DAT_00a0f298;

        FUN_006a2580(&local_58,0);

        if ((local_18 == (void *)0x0) ||

           ((uint)(local_10 - (int)local_18 >> 2) <= (uint)((int)local_14 - (int)local_18 >> 2))) {

          FUN_00697f60(local_14,1,&local_68);

        }

        else {

          *local_14 = iVar5;

          local_14 = local_14 + 1;

        }

      }

      piVar9 = piVar9 + 2;

    } while (piVar9 != *(int **)(param_1 + 8));

  }

  pvVar4 = local_18;

  FUN_00698400(local_1c);

  if (pvVar4 == (void *)0x0) {

    ExceptionList = local_c;

    return param_2;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar4);

}
