// =============================================================================
// FUN_004f8430
// -----------------------------------------------------------------------------
// Stable ID: aa_004f8430
// Address:   0x004f8430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f8430 @ 0x004f8430
// Stable ID: aa_004f8430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~213 non-empty decompiler lines.
//  - Control keywords: if×31, return×3, for×2.
//  - Notable callees: SQRT×4, FUN_00404c90×2, FUN_0040d0a0×2, __RTDynamicCast×2, ABS, FUN_004e8a40, FUN_004e9530, FUN_004f8430.
//  - Return sites: 3.

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



void __fastcall FUN_004f8430(int param_1)



{

  int iVar1;

  int *piVar2;

  bool bVar3;

  int iVar4;

  float *pfVar5;

  float10 fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fStack_58;

  float local_40;

  float fStack_3c;

  float local_38;

  float local_30;

  float fStack_2c;

  float local_28;

  float local_20;

  float local_18;

  

  if ((*(int *)(param_1 + 8) != 0) &&

     (*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) != 0)) {

    FUN_004e8a40(*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0x30,&local_30);

    iVar4 = _finite((double)local_30);

    if (iVar4 != 0) {

      iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);

      bVar3 = false;

      if ((((iVar4 == 0) || (iVar4 = *(int *)(iVar4 + 0xa0), iVar4 == 0)) ||

          ((*(uint *)(iVar4 + 0x17c) >> 5 & 1) == 0)) ||

         (iVar4 = __RTDynamicCast(iVar4,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                  &CVOGPhysicsBase::RTTI_Type_Descriptor,0),

         *(int *)(iVar4 + 8) == 0)) {

        if (*(char *)(param_1 + 0x103) == '\0') {

          bVar3 = true;

        }

        else if (*(int *)(*(int *)(param_1 + 0x260) + 4) == 0) {

          iVar4 = *(int *)(*(int *)(param_1 + 8) + 0x3c);

          local_20 = local_30 + *(float *)(iVar4 + 0xb0);

          local_18 = local_28 + *(float *)(iVar4 + 0xb8);

        }

        else {

          pfVar5 = (float *)FUN_004e9530(&local_40,

                                         *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) +

                                                           0xa8 + param_1) + 0xe894) + 0x11c);

          local_20 = *pfVar5;

          local_18 = pfVar5[2];

        }

      }

      else {

        __RTDynamicCast(*(uint32_t /* width from decompiler */ *)

                         (*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) + 0xa0),0,

                        &CVOGClonedObjectBase::RTTI_Type_Descriptor,

                        &CVOGPhysicsBase::RTTI_Type_Descriptor,0);

        pfVar5 = (float *)FUN_00404c90();

        local_20 = *pfVar5;

        local_18 = pfVar5[2];

        iVar4 = *(int *)(*(int *)(param_1 + 4) + 4);

        iVar1 = *(int *)(*(int *)(iVar4 + 0xb0 + param_1) + 0xa0);

        if (iVar1 == iVar4 + param_1 + 4) {

          local_20 = local_30 + local_20;

          local_18 = local_28 + local_18;

        }

        if ((*(int *)(param_1 + 0x284) != 0) &&

           (*(int *)(*(int *)(param_1 + 0x284) + 0x10) != iVar1)) {

          FUN_005a53e0();

          *(int *)(*(int *)(param_1 + 0x284) + 0x10) = iVar1;

        }

      }

      iVar4 = g_dwClientTickMs - *(int *)(param_1 + 0x140);

      fVar8 = (float)iVar4;

      if (iVar4 < 0) {

        fVar8 = fVar8 + _DAT_00aaa5dc;

      }

      fVar8 = fVar8 * g_flMsToSeconds_Inferred;

      *(uint *)(param_1 + 0x140) = g_dwClientTickMs;

      if (bVar3) {

        fVar13 = *(float *)(param_1 + 0x15c) - *(float *)(param_1 + 0x158);

        if ((fVar13 <= DAT_009cd1f0) || (DAT_009cd110 <= fVar13)) {

          for (; fVar13 < DAT_009cd1f0; fVar13 = fVar13 + DAT_00aaa7dc) {

          }

          for (; DAT_009cd110 < fVar13; fVar13 = fVar13 - DAT_00aaa7dc) {

          }

        }

        fVar11 = ABS(fVar13);

        if (g_flMsToSeconds_Inferred <= fVar11) {

          fVar8 = fVar8 * DAT_00aaa7dc;

          fVar9 = g_flOne;

          if (fVar11 <= fVar8) {

            if ((fVar11 < DAT_009cd1f8) && (fVar9 = fVar11 * _DAT_009cd1f4, fVar9 < DAT_00a10e78)) {

              fVar9 = DAT_00a10e78;

            }

          }

          else {

            fVar11 = DAT_00aaa668;

            if (0.0 <= fVar13) {

              fVar11 = g_flOne;

            }

            fVar13 = fVar11 * fVar8;

          }

          fVar8 = fVar9 * fVar13 + *(float *)(param_1 + 0x158);

          if (DAT_00af18a0 < fVar8) {

            fVar8 = fVar8 - DAT_00af18a0;

          }

          if (fVar8 < 0.0) {

            fVar8 = DAT_00af18a0 + fVar8;

          }

          *(float *)(param_1 + 0x158) = fVar8;

        }

      }

      else {

        pfVar5 = (float *)FUN_00404c90();

        local_40 = local_20 - *pfVar5;

        local_38 = local_18 - pfVar5[2];

        if (DAT_009cd10c <

            SQRT(*(float *)(param_1 + 0x178) * *(float *)(param_1 + 0x178) +

                 *(float *)(param_1 + 0x174) * *(float *)(param_1 + 0x174) +

                 *(float *)(param_1 + 0x170) * *(float *)(param_1 + 0x170))) {

          local_40 = *(float *)(param_1 + 0x170);

          local_38 = *(float *)(param_1 + 0x178);

        }

        fVar13 = local_38 * local_38 + local_40 * local_40;

        fVar11 = SQRT(fVar13);

        if (DAT_009cd10c < fVar11) {

          if ((((_DAT_009cd1fc < fVar11) &&

               (piVar2 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1),

               piVar2 != (int *)0x0)) && (piVar2[0x28] != 0)) &&

             ((iVar4 = (**(code **)(*piVar2 + 0x1dc))(), iVar4 != 0 &&

              (*(char *)(iVar4 + 0x6b9) == '\0')))) {

            FUN_005172d0();

            return;

          }

          if (fVar13 == 0.0) {

            fStack_3c = 0.0;

          }

          else {

            fStack_3c = g_flOne / SQRT(fVar13);

          }

          local_40 = fStack_3c * local_40;

          local_38 = local_38 * fStack_3c;

          fStack_58 = *(float *)(param_1 + 0x158);

          fStack_3c = fStack_3c * 0.0;

          fVar6 = (float10)FUN_0040d0a0();

          fVar13 = (float)fVar6;

          if (local_28 * 0.0 + local_30 + fStack_2c * 0.0 < 0.0) {

            fVar13 = DAT_00af18a0 - fVar13;

          }

          fStack_58 = fVar13 + fStack_58;

          if (DAT_00af18a0 < fStack_58) {

            fStack_58 = fStack_58 - DAT_00af18a0;

          }

          if (fStack_58 < 0.0) {

            fStack_58 = DAT_00af18a0 + fStack_58;

          }

          fVar6 = (float10)fsin((float10)fStack_58);

          local_20 = (float)fVar6;

          fVar6 = (float10)fcos((float10)fStack_58);

          local_18 = (float)fVar6;

          fVar9 = local_20 * local_20 + local_18 * local_18;

          if (fVar9 == 0.0) {

            fVar9 = 0.0;

          }

          else {

            fVar9 = g_flOne / SQRT(fVar9);

          }

          local_20 = fVar9 * local_20;

          fVar10 = local_20 * local_40;

          local_18 = local_18 * fVar9;

          fVar7 = fVar9 * 0.0 * fStack_3c;

          fVar12 = local_18 * local_38;

          fStack_58 = fStack_58 - fVar13;

          fVar6 = (float10)FUN_0040d0a0();

          fVar13 = (float)fVar6;

          fVar9 = DAT_00aaa948;

          if ((fVar11 <= DAT_00a1109c) &&

             (fVar9 = DAT_00aaa660, fVar11 <= (float)g_nInferredThreatDefault)) {

            fVar9 = DAT_00a111a8;

          }

          if (fVar10 + fVar12 + fVar7 < fVar9) {

            fVar8 = fVar8 * DAT_00aaa7dc;

            if (fVar13 < fVar8) {

              fVar8 = fVar13;

            }

            fVar11 = g_flOne;

            if ((fVar13 < DAT_009cd1f8) && (fVar11 = fVar13 * _DAT_009cd1f4, fVar11 < DAT_00a10e78))

            {

              fVar11 = DAT_00a10e78;

            }

            if (0.0 <= local_38 * local_20 - local_18 * local_40) {

              fStack_58 = fStack_58 - fVar8 * fVar11;

            }

            else {

              fStack_58 = fVar8 * fVar11 + fStack_58;

            }

            if (DAT_00af18a0 < fStack_58) {

              fStack_58 = fStack_58 - DAT_00af18a0;

            }

            if (fStack_58 < 0.0) {

              fStack_58 = DAT_00af18a0 + fStack_58;

            }

          }

          *(float *)(param_1 + 0x158) = fStack_58;

          return;

        }

      }

    }

  }

  return;

}
