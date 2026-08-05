// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00556da0
// -----------------------------------------------------------------------------
// Stable ID: aa_00556da0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI
// Address:   0x00556da0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI: callee helper. Evidence string: "Failed to load weather FX: %s". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Failed to load weather FX: %s"
//   - "env_time_midday"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~303 non-empty decompiler lines.
//  - Control keywords: if×44, return×8, while×4, do×3, goto×3.
//  - Notable callees: FUN_004b8dc0×8, NDSpecialFX_LoadFromScriptName×8, FUN_004b73c0×4, FUN_004b9270×4, FUN_005592e0×4, FUN_007a4480×4, CONCAT31×2, FUN_00553d20×2.
//  - Strings: "Failed to load weather FX: %s"; "env_time_midday".
//  - Return sites: 8.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00556da0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char *pcVar1;

  char cVar2;

  int iVar3;

  float *pfVar4;

  char *pcVar5;

  void *pvVar6;

  int iVar7;

  float fVar8;

  int iVar9;

  char *pcVar10;

  uint uVar11;

  char *pcVar12;

  float fVar13;

  char local_aed;

  int local_aec;

  char local_ae5;

  float local_ae4;

  float local_ae0;

  uint8_t auStack_adc [8];

  char local_ad4;

  uint8_t local_ad0 [1076];

  void *local_69c;

  char local_570 [1080];

  void *local_138;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a46ce;

  pvStack_c = ExceptionList;

  local_ae5 = '\0';

  local_aed = '\0';

  if ((*(int *)(param_1 + 0x17c) != 0) &&

     (*(char *)(*(int *)(param_1 + 0x17c) + 0x54c) == (char)param_2)) {

    local_ae5 = '\x01';

  }

  if ((*(int *)(param_1 + 0x180) != 0) &&

     (*(char *)(*(int *)(param_1 + 0x180) + 0x54c) == (char)param_2)) {

    local_aed = '\x01';

  }

  local_ad4 = (char)param_2;

  ExceptionList = &pvStack_c;

  local_aec = param_1;

  FUN_005592e0(param_3);

  local_4 = 0;

  local_570[0] = local_ad4;

  FUN_005592e0(local_ad0);

  local_4 = CONCAT31(local_4._1_3_,1);

  FUN_00559680(&local_ae4,local_570);

  fVar8 = local_ae4;

  if (local_138 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_138);

  }

  local_4 = 0xffffffff;

  if (local_69c != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_69c);

  }

  if (local_ae0._0_1_ == '\0') {

    FUN_00555360();

    FUN_00559740(&local_ae4,fVar8);

    local_ad4 = (char)param_2;

    FUN_005592e0(param_3);

    local_4 = 2;

    local_570[0] = local_ad4;

    FUN_005592e0(local_ad0);

    local_4 = CONCAT31(local_4._1_3_,3);

    pfVar4 = (float *)FUN_00559680(auStack_adc,local_570);

    fVar8 = *pfVar4;

    local_ae0 = pfVar4[1];

    if (local_138 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(local_138);

    }

    local_4 = 0xffffffff;

    if (local_69c != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(local_69c);

    }

  }

  local_4 = 0xffffffff;

  if (local_ae5 != '\0') {

    *(int *)(local_aec + 0x17c) = (int)fVar8 + 0x10;

  }

  if (local_aed != '\0') {

    *(int *)(local_aec + 0x180) = (int)fVar8 + 0x10;

  }

  pcVar1 = (char *)((int)fVar8 + 0x10);

  uVar11 = 0;

  *(char *)((int)fVar8 + 0x55c) = (char)param_2;

  fVar13 = 0.0;

  iVar9 = 0;

LAB_00556f81:

  do {

    if ((*(int *)((int)fVar8 + 0x444) == 0) ||

       ((uint)((*(int *)((int)fVar8 + 0x448) - *(int *)((int)fVar8 + 0x444)) / 0x134) <= uVar11))

    break;

    *(uint32_t /* width from decompiler */ *)(iVar9 + *(int *)((int)fVar8 + 0x444) + 0x128) =

         *(uint32_t /* width from decompiler */ *)(iVar9 + 0x120 + *(int *)((int)fVar8 + 0x444));

    iVar7 = iVar9 + *(int *)((int)fVar8 + 0x444);

    if (((*(byte *)(iVar9 + 0x130 + *(int *)((int)fVar8 + 0x444)) & 1) == 0) &&

       ((*(uint *)(iVar7 + 0x130) & 1 << (*(byte *)(*(int *)(local_aec + 0x40) + 0x7c) & 0x1f)) == 0

       )) {

      if (*(char *)(*(int *)(local_aec + 0x40) + 0x7d) == '\0') {

        uVar11 = uVar11 + 1;

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0x118) = 0;

        iVar9 = iVar9 + 0x134;

        goto LAB_00556f81;

      }

    }

    else {

      fVar13 = *(float *)(iVar7 + 0x118) + fVar13;

    }

    uVar11 = uVar11 + 1;

    iVar9 = iVar9 + 0x134;

  } while( true );

  if (fVar13 == 0.0) {

    fVar13 = g_flOne;

  }

  uVar11 = 0;

  fVar13 = g_flOne / fVar13;

  iVar9 = 0;

  while ((*(int *)((int)fVar8 + 0x444) != 0 &&

         (uVar11 < (uint)((*(int *)((int)fVar8 + 0x448) - *(int *)((int)fVar8 + 0x444)) / 0x134))))

  {

    iVar7 = *(int *)((int)fVar8 + 0x444) + iVar9;

    if (((*(byte *)(*(int *)((int)fVar8 + 0x444) + 0x130 + iVar9) & 1) == 0) &&

       ((*(uint *)(iVar7 + 0x130) & 1 << (*(byte *)(*(int *)(local_aec + 0x40) + 0x7c) & 0x1f)) == 0

       )) {

      uVar11 = uVar11 + 1;

      *(uint32_t /* width from decompiler */ *)(iVar7 + 300) = 0;

      iVar9 = iVar9 + 0x134;

    }

    else {

      uVar11 = uVar11 + 1;

      *(float *)(iVar7 + 300) = *(float *)(iVar7 + 0x118) * fVar13;

      iVar9 = iVar9 + 0x134;

    }

  }

  local_aed = '\0';

  FUN_00558eb0(&local_ae4,&local_aed);

  pcVar10 = (char *)((int)local_ae4 + 0x10);

  iVar9 = 4;

  pcVar12 = pcVar1;

  do {

    if (*pcVar12 == '\0') {

      *(uint32_t /* width from decompiler */ *)(pcVar12 + 0x104) = *(uint32_t /* width from decompiler */ *)(pcVar10 + 0x104);

      if (*pcVar10 == '\0') {

        *pcVar12 = '\0';

      }

      else {

        pcVar5 = pcVar10;

        do {

          cVar2 = *pcVar5;

          pcVar5[(int)pcVar12 - (int)pcVar10] = cVar2;

          pcVar5 = pcVar5 + 1;

        } while (cVar2 != '\0');

      }

    }

    pcVar10 = pcVar10 + 0x10c;

    pcVar12 = pcVar12 + 0x10c;

    iVar9 = iVar9 + -1;

  } while (iVar9 != 0);

  if (*(int *)(local_aec + 0x17c) == 0) {

    ExceptionList = pvStack_c;

    return;

  }

  if (*(char *)(*(int *)(local_aec + 0x17c) + 0x54c) != (char)param_2) {

    ExceptionList = pvStack_c;

    return;

  }

  if (*(int *)(local_aec + 0x188) == 0) {

    ExceptionList = pvStack_c;

    return;

  }

  if ((*(int *)((int)fVar8 + 0x444) != 0) &&

     (local_ae4 = (float)((*(int *)((int)fVar8 + 0x448) - *(int *)((int)fVar8 + 0x444)) / 0x134),

     local_ae4 != 0.0)) {

    iVar9 = FUN_005556c0(param_2);

    pcVar12 = (char *)(*(int *)((int)fVar8 + 0x444) + iVar9 * 0x134);

    *(int *)((int)fVar8 + 0x568) = iVar9;

    if ((*(int *)(pcVar12 + 0x104) == 0) && (*pcVar12 != '\0')) {

      pvVar6 = NDSpecialFX_LoadFromScriptName(pcVar12,0,0);

      *(void **)(pcVar12 + 0x104) = pvVar6;

      if (pvVar6 == (void *)0x0) {

        FUN_007a4480(1,"Failed to load weather FX: %s",pcVar12);

        pvVar6 = NDSpecialFX_LoadFromScriptName("env_time_midday",0,0);

        *(void **)(pcVar12 + 0x104) = pvVar6;

      }

      if (*(int *)(pcVar12 + 0x104) != 0) {

        *(uint8_t *)(*(int *)(pcVar12 + 0x104) + 9) = 1;

        FUN_004b8dc0(0,0);

        FUN_004b9270(*(uint32_t /* width from decompiler */ *)(pcVar12 + 0x104));

      }

    }

    iVar9 = *(int *)(pcVar12 + 0x104);

    if ((iVar9 != 0) && (iVar7 = *(int *)(local_aec + 0x188), iVar7 != 0)) {

      FUN_004b73c0(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7);

      FUN_004b8dc0(1,0);

      *(float *)(iVar9 + 0x38) = g_flOne;

      *(uint32_t /* width from decompiler */ *)(iVar9 + 0x2c) = *(uint32_t /* width from decompiler */ *)(local_aec + 0x40);

    }

  }

  iVar9 = *(int *)(local_aec + 0x150);

  if ((-1 < iVar9) && (iVar9 < 4)) {

    pcVar12 = pcVar1 + iVar9 * 0x10c;

    if (*(int *)((int)fVar8 + 0x114 + iVar9 * 0x10c) == 0) {

      if (*pcVar12 != '\0') {

        pvVar6 = NDSpecialFX_LoadFromScriptName(pcVar12,0,0);

        *(void **)(pcVar12 + 0x104) = pvVar6;

        if (pvVar6 == (void *)0x0) {

          FUN_007a4480(1,"Failed to load weather FX: %s",pcVar12);

          pvVar6 = NDSpecialFX_LoadFromScriptName("env_time_midday",0,0);

          *(void **)(pcVar12 + 0x104) = pvVar6;

        }

        if (*(int *)(pcVar12 + 0x104) != 0) {

          *(uint8_t *)(*(int *)(pcVar12 + 0x104) + 9) = 1;

          FUN_004b8dc0(0,0);

          FUN_004b9270(*(uint32_t /* width from decompiler */ *)(pcVar12 + 0x104));

        }

      }

      if (*(int *)(pcVar12 + 0x104) == 0) goto LAB_005573c2;

    }

    iVar9 = local_aec;

    if ((*(int *)(local_aec + 0x150) < 0) || (3 < *(int *)(local_aec + 0x150))) {

      iVar7 = 0;

    }

    else {

      iVar7 = FUN_00553d20(0);

    }

    local_ae4 = g_flOne - *(float *)(iVar9 + 0x15c);

    if ((iVar7 != 0) && (iVar3 = *(int *)(iVar9 + 0x188), iVar3 != 0)) {

      FUN_004b73c0(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3);

      FUN_004b8dc0(1,0);

      *(float *)(iVar7 + 0x38) = local_ae4;

      *(uint32_t /* width from decompiler */ *)(iVar7 + 0x2c) = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x40);

    }

  }

LAB_005573c2:

  iVar7 = local_aec;

  iVar9 = *(int *)(local_aec + 0x154);

  if ((-1 < iVar9) && (iVar9 < 4)) {

    pcVar1 = pcVar1 + iVar9 * 0x10c;

    if (*(int *)((int)fVar8 + 0x114 + iVar9 * 0x10c) == 0) {

      if (*pcVar1 != '\0') {

        pvVar6 = NDSpecialFX_LoadFromScriptName(pcVar1,0,0);

        *(void **)(pcVar1 + 0x104) = pvVar6;

        if (pvVar6 == (void *)0x0) {

          FUN_007a4480(1,"Failed to load weather FX: %s",pcVar1);

          pvVar6 = NDSpecialFX_LoadFromScriptName("env_time_midday",0,0);

          *(void **)(pcVar1 + 0x104) = pvVar6;

        }

        if (*(int *)(pcVar1 + 0x104) != 0) {

          *(uint8_t *)(*(int *)(pcVar1 + 0x104) + 9) = 1;

          FUN_004b8dc0(0,0);

          FUN_004b9270(*(uint32_t /* width from decompiler */ *)(pcVar1 + 0x104));

        }

      }

      if (*(int *)(pcVar1 + 0x104) == 0) goto LAB_005574e6;

    }

    if ((*(int *)(iVar7 + 0x154) < 0) || (3 < *(int *)(iVar7 + 0x154))) {

      iVar9 = 0;

    }

    else {

      iVar9 = FUN_00553d20(0);

    }

    local_ae4 = *(float *)(iVar7 + 0x15c);

    if ((iVar9 != 0) && (iVar3 = *(int *)(iVar7 + 0x188), iVar3 != 0)) {

      FUN_004b73c0(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3);

      FUN_004b8dc0(1,0);

      *(float *)(iVar9 + 0x38) = local_ae4;

      *(uint32_t /* width from decompiler */ *)(iVar9 + 0x2c) = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x40);

    }

  }

LAB_005574e6:

  pcVar1 = (char *)((int)fVar8 + 0x450);

  if ((*(int *)((int)fVar8 + 0x554) == 0) && (*pcVar1 != '\0')) {

    pvVar6 = NDSpecialFX_LoadFromScriptName(pcVar1,0,0);

    *(void **)((int)fVar8 + 0x554) = pvVar6;

    if (pvVar6 == (void *)0x0) {

      FUN_007a4480(1,"Failed to load weather FX: %s",pcVar1);

      pvVar6 = NDSpecialFX_LoadFromScriptName("env_time_midday",0,0);

      *(void **)((int)fVar8 + 0x554) = pvVar6;

    }

    if (*(int *)((int)fVar8 + 0x554) != 0) {

      *(uint8_t *)(*(int *)((int)fVar8 + 0x554) + 9) = 1;

      FUN_004b8dc0(0,0);

      FUN_004b9270(*(uint32_t /* width from decompiler */ *)((int)fVar8 + 0x554));

    }

  }

  iVar9 = *(int *)((int)fVar8 + 0x554);

  if ((iVar9 != 0) && (iVar3 = *(int *)(iVar7 + 0x188), iVar3 != 0)) {

    FUN_004b73c0(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3);

    FUN_004b8dc0(1,0);

    *(float *)(iVar9 + 0x38) = g_flOne;

    *(uint32_t /* width from decompiler */ *)(iVar9 + 0x2c) = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x40);

  }

  ExceptionList = pvStack_c;

  return;

}
