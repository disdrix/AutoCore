// =============================================================================
// FUN_005cf560
// -----------------------------------------------------------------------------
// Stable ID: aa_005cf560
// Address:   0x005cf560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005cf560 @ 0x005cf560
// Stable ID: aa_005cf560
// Embedded strings (evidence for future rename):
//   - "CVOGHBAICreatureBase::DoCreaturePursue"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~169 non-empty decompiler lines.
//  - Control keywords: if×13, return×1.
//  - Notable callees: SQRT×2, FUN_004e8a40, FUN_004e8ad0, FUN_0053e510, FUN_00567ce0, FUN_005cf560, FUN_005d1bb0, FUN_005d1c00.
//  - Strings: "CVOGHBAICreatureBase::DoCreaturePursue".
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



void __fastcall FUN_005cf560(int *param_1)



{

  float fVar1;

  int iVar2;

  float *pfVar3;

  int iVar4;

  float10 fVar5;

  float10 fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fStack_90;

  float fStack_80;

  float fStack_7c;

  float fStack_78;

  float fStack_74;

  float fStack_70;

  float fStack_6c;

  float fStack_68;

  float fStack_64;

  float fStack_60;

  float fStack_5c;

  float fStack_58;

  float fStack_50;

  float fStack_4c;

  float fStack_48;

  uint8_t auStack_40 [16];

  uint8_t auStack_30 [20];

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a6faa;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  FUN_0076cf00("CVOGHBAICreatureBase::DoCreaturePursue");

  local_14 = 0;

  if (g_flZero <

      *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 0xac + param_1[0x19])

                         + 0x3c) + 0x4c0)) {

    iVar2 = (**(code **)(**(int **)(param_1[6] + 0xa0) + 0x19c))();

    if ((*(byte *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 0xb8 + param_1[0x19]) & 0x40) == 0) {

      iVar4 = iVar2;

      (**(code **)(*(int *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 4 + param_1[0x19]) + 0x19c))

                (iVar2);

      fVar5 = (float10)FUN_0053e510(iVar4);

      iVar4 = param_1[0x19];

      if (*(float *)(iVar4 + 0x124) <= (float)fVar5) {

        if (*(int *)(iVar2 + 8) == 0) {

          pfVar3 = (float *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x84 + iVar2);

        }

        else {

          pfVar3 = (float *)(*(int *)(*(int *)(iVar2 + 8) + 0x3c) + 0xb0);

        }

      }

      else {

        fStack_90 = 0.0;

        if ((iVar4 != 0) &&

           (iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x27c))()

           , iVar4 < 6)) {

          pfVar3 = &fStack_60;

          (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x1a4))(pfVar3);

          FUN_005d1c00(pfVar3);

          (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x1a4))();

          fVar6 = (float10)FUN_005d1bb0();

          fStack_90 = (float)fVar6;

          if (fStack_5c < 0.0) {

            fStack_90 = 0.0 - fStack_90;

          }

        }

        if (*(int *)(iVar2 + 8) == 0) {

          pfVar3 = (float *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x84 + iVar2);

        }

        else {

          pfVar3 = (float *)(*(int *)(*(int *)(iVar2 + 8) + 0x3c) + 0xb0);

        }

        fStack_80 = *pfVar3;

        fStack_78 = pfVar3[2];

        fStack_74 = pfVar3[3];

        pfVar3 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 4 +

                                               param_1[0x19]) + 0x1a0))();

        fStack_80 = fStack_80 - *pfVar3;

        fStack_78 = fStack_78 - pfVar3[2];

        fVar8 = fStack_78 * fStack_78 + fStack_80 * fStack_80;

        if (fVar8 == 0.0) {

          fStack_7c = 0.0;

        }

        else {

          fStack_7c = g_flOne / SQRT(fVar8);

        }

        fStack_80 = fStack_7c * fStack_80;

        fStack_78 = fStack_78 * fStack_7c;

        fStack_74 = (fStack_74 - pfVar3[3]) * fStack_7c;

        fVar10 = fStack_80 * DAT_00aaa668;

        fStack_7c = fStack_7c * 0.0;

        fStack_60 = fStack_78;

        fStack_58 = fVar10;

        FUN_00567ce0(&DAT_00af41c0,(float)*(byte *)(param_1 + 0x1b) * _DAT_00bc5580 + fStack_90);

        fVar8 = (float)*(byte *)(param_1 + 0x1b) * _DAT_009da8d4 * *(float *)(param_1[0x19] + 0x124)

                * DAT_00a0f298 + *(float *)(param_1[0x19] + 0x124) * DAT_00a0f298;

        FUN_004e8a40(auStack_40,&fStack_50);

        FUN_004e8ad0(auStack_40,auStack_30);

        if ((*(char *)(param_1[0x19] + 0x306) != '\0') ||

           (DAT_009c8354 <

            (fStack_4c * fStack_7c * DAT_00aaa668 - fStack_48 * fStack_78) - fStack_50 * fStack_80))

        {

          pfVar3 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 4 +

                                                 param_1[0x19]) + 0x1a0))();

          fStack_70 = *pfVar3;

          fStack_6c = pfVar3[1];

          fStack_68 = pfVar3[2];

          fStack_64 = pfVar3[3];

          if ((float)fVar5 < fVar8) {

            fVar8 = (*(float *)(param_1[0x19] + 0x34) + *(float *)(iVar2 + 0x34) + fVar8) *

                    DAT_00aaa668;

            fStack_78 = fStack_78 * fVar8;

            fStack_68 = fStack_68 + fStack_78;

            fStack_70 = fStack_70 + fVar8 * fStack_80;

            fStack_6c = fStack_6c + fStack_7c * fVar8;

            fStack_64 = fStack_64 + fStack_74 * fVar8;

          }

        }

        else {

          if (fStack_48 * fVar10 + fStack_78 * fStack_50 + fStack_4c * 0.0 <= 0.0) {

            fStack_60 = fStack_78 * DAT_00aaa668;

            fStack_58 = fVar10 * DAT_00aaa668;

          }

          pfVar3 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 4 +

                                                 param_1[0x19]) + 0x1a0))();

          fVar8 = *(float *)(param_1[0x19] + 0x34) + *(float *)(iVar2 + 0x34) + fVar8;

          fStack_7c = fVar8 * g_flZero;

          fStack_70 = *pfVar3 + fVar8 * fStack_60;

          fStack_6c = pfVar3[1] + fStack_7c;

          fStack_68 = pfVar3[2] + fStack_58 * fVar8;

          fStack_64 = pfVar3[3] + fStack_7c;

        }

        pfVar3 = &fStack_70;

      }

    }

    else {

      if (*(int *)(iVar2 + 8) == 0) {

        pfVar3 = (float *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x84 + iVar2);

      }

      else {

        pfVar3 = (float *)(*(int *)(*(int *)(iVar2 + 8) + 0x3c) + 0xb0);

      }

      fVar8 = *pfVar3;

      fVar10 = pfVar3[1];

      fVar1 = pfVar3[2];

      fVar7 = fVar1 * fVar1 + fVar10 * fVar10 + fVar8 * fVar8;

      fVar9 = 0.0;

      if (fVar7 != 0.0) {

        fVar9 = g_flOne / SQRT(fVar7);

      }

      fStack_80 = fVar9 * fVar8 * DAT_00aaa668 * DAT_00aaa7ac;

      fStack_7c = fVar10 * fVar9 * DAT_00aaa668 * DAT_00aaa7ac;

      fStack_78 = fVar1 * fVar9 * DAT_00aaa668 * DAT_00aaa7ac;

      fStack_74 = pfVar3[3] * fVar9 * DAT_00aaa668 * DAT_00aaa7ac;

      pfVar3 = &fStack_80;

    }

    (**(code **)(*param_1 + 0x4c))(pfVar3,0);

  }

  local_14 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = pvStack_1c;

  return;

}
