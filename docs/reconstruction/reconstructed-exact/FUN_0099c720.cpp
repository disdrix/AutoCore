// =============================================================================
// FUN_0099c720
// -----------------------------------------------------------------------------
// Stable ID: aa_0099c720
// Address:   0x0099c720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0099c720 @ 0x0099c720
// Stable ID: aa_0099c720
// Embedded strings (evidence for future rename):
//   - "specialevent_path_%s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~151 non-empty decompiler lines.
//  - Control keywords: if×9, do×2, while×2, for×2, return×2.
//  - Notable callees: FUN_00720d40×3, EnterCriticalSection×2, LeaveCriticalSection×2, FUN_004b73c0, FUN_004b7e50, FUN_004b9270, FUN_004e8dc0, FUN_009423b0.
//  - Strings: "specialevent_path_%s".
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ * __thiscall FUN_0099c720(int param_1,uint32_t /* width from decompiler */ *param_2,char *param_3)



{

  char cVar1;

  char *pcVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *pvVar4;

  int iVar5;

  uint uVar6;

  char *pcVar7;

  char *pcVar8;

  char local_168 [4];

  char local_164 [4];

  char local_160 [4];

  char local_15c [2];

  char local_15a;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  LPCRITICAL_SECTION local_24;

  uint8_t *puStack_20;

  void *local_1c;

  uint8_t *puStack_18;

  uint local_14;

  

  puStack_18 = &LAB_009bb8e5;

  local_1c = ExceptionList;

  puStack_20 = &stack0xfffffffc;

  ExceptionList = &local_1c;

  *param_2 = &PTR_LAB_00a766f8;

  *(uint8_t *)(param_2 + 1) = 0;

  local_14 = 0;

  *param_2 = &PTR_FUN_00a766e8;

  param_2[2] = 0;

  param_2[6] = 0;

  if (param_1 == DAT_00d1b6d8) {

    local_168[0] = s____maps_paths__00a27d1c[0];

    local_168[1] = s____maps_paths__00a27d1c[1];

    local_168[2] = s____maps_paths__00a27d1c[2];

    local_168[3] = s____maps_paths__00a27d1c[3];

    local_160[0] = s____maps_paths__00a27d1c[8];

    local_160[1] = s____maps_paths__00a27d1c[9];

    local_160[2] = s____maps_paths__00a27d1c[10];

    local_160[3] = s____maps_paths__00a27d1c[0xb];

    local_164[0] = s____maps_paths__00a27d1c[4];

    local_164[1] = s____maps_paths__00a27d1c[5];

    local_164[2] = s____maps_paths__00a27d1c[6];

    local_164[3] = s____maps_paths__00a27d1c[7];

    local_15a = s____maps_paths__00a27d1c[0xe];

    local_15c[0] = s____maps_paths__00a27d1c[0xc];

    local_15c[1] = s____maps_paths__00a27d1c[0xd];

    pcVar2 = param_3;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar8 = &stack0xfffffe97;

    do {

      pcVar7 = pcVar8 + 1;

      pcVar8 = pcVar8 + 1;

    } while (*pcVar7 != '\0');

    pcVar7 = param_3;

    for (uVar6 = (uint)((int)pcVar2 - (int)param_3) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar8 = *(uint32_t /* width from decompiler */ *)pcVar7;

      pcVar7 = pcVar7 + 4;

      pcVar8 = pcVar8 + 4;

    }

    for (uVar6 = (int)pcVar2 - (int)param_3 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

      *pcVar8 = *pcVar7;

      pcVar7 = pcVar7 + 1;

      pcVar8 = pcVar8 + 1;

    }

    local_38 = *(uint32_t /* width from decompiler */ *)(DAT_00d1b628 + 0x230);

    local_3c = *(uint32_t /* width from decompiler */ *)(DAT_00d1b628 + 0x22c);

    local_40 = *(uint32_t /* width from decompiler */ *)(DAT_00d1b628 + 0x228);

    local_50 = *(uint32_t /* width from decompiler */ *)(DAT_00d1b628 + 0x21c);

    local_4c = *(uint32_t /* width from decompiler */ *)(DAT_00d1b628 + 0x220);

    local_48 = *(uint32_t /* width from decompiler */ *)(DAT_00d1b628 + 0x224);

    local_34 = 0;

    local_44 = 0;

    FUN_004e8dc0();

    local_24 = operator_new(0x80);

    local_14._0_1_ = 1;

    if (local_24 == (void *)0x0) {

      puVar3 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      puVar3 = (uint32_t /* width from decompiler */ *)FUN_00976900();

    }

    local_14 = (uint)local_14._1_3_ << 8;

    param_2[6] = puVar3;

    if (DAT_00d1b644 != 0) {

      *puVar3 = *(uint32_t /* width from decompiler */ *)(DAT_00d1b644 + 0x70);

    }

    pvVar4 = (void *)param_2[6];

    if ((*(int *)((int)pvVar4 + 0x6c) == 0) ||

       (local_24 = (LPCRITICAL_SECTION)

                   ((*(int *)((int)pvVar4 + 0x70) - *(int *)((int)pvVar4 + 0x6c)) / 0x28),

       local_24 == (void *)0x0)) {

      if (pvVar4 != (void *)0x0) {

        FUN_00976390();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar4);

      }

      param_2[6] = 0;

    }

    else {

      *(uint8_t *)(param_2 + 3) = *(uint8_t *)(DAT_00d1b6d8 + 0x4f1);

      FUN_009423b0();

      if (DAT_00d1b9a8 != (int *)0x0) {

        (**(code **)(*DAT_00d1b9a8 + 4))();

      }

      sprintf(local_168,"specialevent_path_%s");

      pvVar4 = NDSpecialFX_LoadFromScriptName(local_168,0,0);

      param_2[2] = pvVar4;

      iVar5 = FUN_00720d40();

      local_24 = (LPCRITICAL_SECTION)(iVar5 + 0x158);

      EnterCriticalSection(local_24);

      if ((*(char *)(iVar5 + 0x10) != '\0') && (*(int *)(iVar5 + 0x80) != 0)) {

        *(uint8_t *)(*(int *)(iVar5 + 0x80) + 0x38) = 1;

        *(uint32_t /* width from decompiler */ *)(*(int *)(iVar5 + 0x80) + 0x1b0) = 0;

      }

      local_14 = local_14 & 0xffffff00;

      LeaveCriticalSection(local_24);

      iVar5 = FUN_00720d40();

      local_24 = (LPCRITICAL_SECTION)(iVar5 + 0x158);

      EnterCriticalSection(local_24);

      if ((*(char *)(iVar5 + 0x10) != '\0') && (*(int *)(iVar5 + 0x84) != 0)) {

        *(uint8_t *)(*(int *)(iVar5 + 0x84) + 0x38) = 1;

        *(uint32_t /* width from decompiler */ *)(*(int *)(iVar5 + 0x84) + 0x1b0) = 0;

      }

      local_14 = local_14 & 0xffffff00;

      LeaveCriticalSection(local_24);

      iVar5 = FUN_00720d40();

      *(uint8_t *)(iVar5 + 0x19) = 0;

      if (param_2[2] != 0) {

        *(uint8_t *)(param_2[2] + 9) = 1;

        FUN_004b73c0();

        local_24 = (LPCRITICAL_SECTION)&stack0xfffffe84;

        *(int *)(param_2[2] + 0x2c) = DAT_00d1b644;

        FUN_004b7e50(0,0,0);

        FUN_004b9270();

      }

    }

  }

  ExceptionList = local_1c;

  return param_2;

}
