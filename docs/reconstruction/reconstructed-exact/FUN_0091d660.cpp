// =============================================================================
// FUN_0091d660
// -----------------------------------------------------------------------------
// Stable ID: aa_0091d660
// Address:   0x0091d660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0091d660 @ 0x0091d660
// Stable ID: aa_0091d660
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~141 non-empty decompiler lines.
//  - Control keywords: if×15, return×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×3, SQRT×2, CVOGHBBase_Start, CVOGHBList_Enqueue, FUN_00404cb0, FUN_004e8b60, FUN_005075f0, FUN_0091d660.
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



void FUN_0091d660(float param_1)



{

  float fVar1;

  ushort uVar2;

  ushort uVar3;

  ushort uVar4;

  char cVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  void *pvVar8;

  int iVar9;

  CVOGHBBase *pAction;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fStack_50;

  float fStack_4c;

  float fStack_48;

  float fStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint8_t auStack_30 [4];

  float fStack_2c;

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009b0470;

  local_1c = ExceptionList;

  if (DAT_00d1b6d8 == 0) {

    iVar9 = 0;

  }

  else {

    iVar9 = *(int *)(DAT_00d1b6d8 + 0x250);

  }

  if (iVar9 != 0) {

    ExceptionList = &local_1c;

    cVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar9 + 4) + 4) + 4 + iVar9) + 0x198))();

    if ((cVar5 == '\0') && (*(char *)(iVar9 + 0x101) == '\0')) {

      DAT_00d1f0c0 = DAT_00d1f0c0 + param_1;

      if (*(int *)(iVar9 + 8) == 0) {

        puVar6 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar9 + 4) + 4) + 0x94 + iVar9);

      }

      else {

        puVar6 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar9 + 8) + 0x3c) + 0x30);

      }

      uStack_40 = *puVar6;

      uStack_3c = puVar6[1];

      uStack_38 = puVar6[2];

      uStack_34 = puVar6[3];

      FUN_004e8b60(&uStack_40,auStack_30);

      iVar7 = *(int *)(iVar9 + 600);

      fVar10 = DAT_00a0f70c;

      if (((iVar7 != 0) &&

          (*(int *)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 0xac + iVar7) + 0x3c) != 0)) &&

         (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 0xac + iVar7) + 0x3c) +

                   0x4ce) == '\x02')) {

        fVar10 = DAT_00a0f720;

      }

      if (fVar10 <= fStack_2c) {

        DAT_00d1f0bc = 0.0;

        DAT_00d1f0c4 = '\0';

      }

      else {

        if (*(int *)(iVar9 + 8) != 0) {

          iVar7 = *(int *)(*(int *)(iVar9 + 8) + 0x3c);

          if ((SQRT(*(float *)(iVar7 + 0x40) * *(float *)(iVar7 + 0x40) +

                    *(float *)(iVar7 + 0x44) * *(float *)(iVar7 + 0x44) +

                    *(float *)(iVar7 + 0x48) * *(float *)(iVar7 + 0x48)) < g_flVehicleHpTechCoeff)

             && (DAT_00a0f70c < DAT_00d1f0c0)) {

            DAT_00d1f0c4 = DAT_00d1f0c4 + '\x01';

            DAT_00d1f0c0 = 0.0;

          }

        }

        DAT_00d1f0bc = DAT_00d1f0bc + param_1;

      }

      if ((DAT_00afe2ac < DAT_00d1f0c4) || (_DAT_00afe2a8 < DAT_00d1f0bc)) {

        DAT_00d1f0bc = 0.0;

        DAT_00d1f0c4 = '\0';

        iVar7 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar7 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

        }

        uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

        *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

        iVar7 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar7 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

        }

        uVar3 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

        *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

        iVar7 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar7 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

        }

        fVar1 = DAT_00aaa638;

        fVar11 = g_flLevelUpUiBase_Inferred;

        fVar10 = DAT_00a0f298;

        uVar4 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

        *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

        fVar12 = (float)uVar3 * fVar1 - fVar10;

        fVar13 = ((float)uVar2 * fVar1 - fVar10) * fVar11;

        fVar11 = ((float)uVar4 * fVar1 - fVar10) * fVar11;

        fStack_44 = 0.0;

        fVar10 = fVar13 * fVar13 + fVar12 * fVar12 + fVar11 * fVar11;

        if (fVar10 == 0.0) {

          fVar10 = 0.0;

        }

        else {

          fVar10 = g_flOne / SQRT(fVar10);

        }

        fVar1 = *(float *)(*(int *)(*(int *)(iVar9 + 8) + 0x3c) + 0x2c);

        if (fVar1 != 0.0) {

          fStack_44 = g_flOne / fVar1;

        }

        fStack_44 = fStack_44 * DAT_00a110d8;

        fStack_50 = fStack_44 * (fVar10 * fVar11 * g_flOverheatCoolFrac + DAT_00afda50);

        fStack_4c = (fVar10 * fVar12 * g_flOverheatCoolFrac + DAT_00afda54) * fStack_44;

        fStack_48 = (fVar10 * fVar13 * g_flOverheatCoolFrac + DAT_00afda58) * fStack_44;

        fStack_44 = (fVar10 * 0.0 * g_flOverheatCoolFrac + DAT_00afda5c) * fStack_44;

        FUN_00404cb0(&fStack_50);

        pvVar8 = operator_new(0x2c);

        pAction = (CVOGHBBase *)0x0;

        uStack_14 = 0;

        if (pvVar8 != (void *)0x0) {

          pAction = (CVOGHBBase *)FUN_005075f0(iVar9,5000);

        }

        uStack_14 = 0xffffffff;

        CVOGHBList_Enqueue(*(void **)(*(int *)(*(int *)(*(int *)(iVar9 + 4) + 4) + 0xa8 + iVar9) +

                                     0xe4ec),pAction);

        CVOGHBBase_Start(pAction);

      }

    }

  }

  ExceptionList = local_1c;

  return;

}
