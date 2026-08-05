// =============================================================================
// FUN_005575c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005575c0
// Address:   0x005575c0  (autoassault.exe, image base 0x400000)
// System:    client weather / env-time transition + nfx preload
// Dual:      W36-F 2026-07-29; prefer WeatherHost_ApplyEnvTime_Inferred.cpp
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE: Twin of WeatherHost_ApplyEnvTime_Inferred (W36-F dual). Scaffold CF body retained.
// Stable ID: aa_005575c0
// Embedded strings (evidence for future rename):
//   - "Somewhere on the map, someone forgot a weather.\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~220 non-empty decompiler lines.
//  - Control keywords: ifÃ—22, returnÃ—9, gotoÃ—2.
//  - Notable callees: FUN_004ed310Ã—4, FUN_00558eb0Ã—3, FUN_00556b10Ã—2, FUN_00971820Ã—2, GetTickCountÃ—2, FUN_005554d0, FUN_00555f10, FUN_00556a60.
//  - Strings: "Somewhere on the map, someone forgot a weather.\n".
//  - Return sites: 9.

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



void __thiscall FUN_005575c0(int param_1,byte param_2)



{

  float fVar1;

  bool bVar2;

  char cVar3;

  float *pfVar4;

  DWORD DVar5;

  int iVar6;

  float fVar7;

  float fVar8;

  uint8_t local_575;

  float local_574;

  int local_570;

  char local_56c [4];

  char local_568 [4];

  char local_564 [4];

  char local_560 [256];

  char local_460 [4];

  char local_45c [4];

  char local_458 [4];

  char local_454 [256];

  char local_354 [4];

  char local_350 [4];

  char local_34c [4];

  char local_348 [256];

  char local_248 [4];

  char local_244 [4];

  char local_240 [4];

  char local_23c [2];

  char local_23a;

  void *local_138;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a46e3;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 0x178) == 0) {

    return;

  }

  ExceptionList = &local_c;

  FUN_00558eb0(&local_574,&param_2);

  fVar1 = *(float *)(param_1 + 0x174);

  fVar7 = local_574;

  if (local_574 == fVar1) {

    local_575 = 0;

    pfVar4 = (float *)FUN_00558eb0(&local_570,&local_575);

    fVar7 = *pfVar4;

    if (fVar7 == fVar1) {

      FUN_007a4480(0,"Somewhere on the map, someone forgot a weather.\n");

      FUN_00556a60();

      local_56c[0] = s_env_time_dawn_009d25f8[0];

      local_56c[1] = s_env_time_dawn_009d25f8[1];

      local_56c[2] = s_env_time_dawn_009d25f8[2];

      local_56c[3] = s_env_time_dawn_009d25f8[3];

      local_560[0] = s_env_time_dawn_009d25f8[0xc];

      local_560[1] = s_env_time_dawn_009d25f8[0xd];

      local_564[0] = s_env_time_dawn_009d25f8[8];

      local_564[1] = s_env_time_dawn_009d25f8[9];

      local_564[2] = s_env_time_dawn_009d25f8[10];

      local_564[3] = s_env_time_dawn_009d25f8[0xb];

      local_568[0] = s_env_time_dawn_009d25f8[4];

      local_568[1] = s_env_time_dawn_009d25f8[5];

      local_568[2] = s_env_time_dawn_009d25f8[6];

      local_568[3] = s_env_time_dawn_009d25f8[7];

      local_45c[0] = s_env_time_midday_009d2570[4];

      local_45c[1] = s_env_time_midday_009d2570[5];

      local_45c[2] = s_env_time_midday_009d2570[6];

      local_45c[3] = s_env_time_midday_009d2570[7];

      local_458[0] = s_env_time_midday_009d2570[8];

      local_458[1] = s_env_time_midday_009d2570[9];

      local_458[2] = s_env_time_midday_009d2570[10];

      local_458[3] = s_env_time_midday_009d2570[0xb];

      local_460[0] = s_env_time_midday_009d2570[0];

      local_460[1] = s_env_time_midday_009d2570[1];

      local_460[2] = s_env_time_midday_009d2570[2];

      local_460[3] = s_env_time_midday_009d2570[3];

      local_354[0] = s_env_time_sunset_009d25e8[0];

      local_354[1] = s_env_time_sunset_009d25e8[1];

      local_354[2] = s_env_time_sunset_009d25e8[2];

      local_354[3] = s_env_time_sunset_009d25e8[3];

      local_350[0] = s_env_time_sunset_009d25e8[4];

      local_350[1] = s_env_time_sunset_009d25e8[5];

      local_350[2] = s_env_time_sunset_009d25e8[6];

      local_350[3] = s_env_time_sunset_009d25e8[7];

      local_454[0] = s_env_time_midday_009d2570[0xc];

      local_454[1] = s_env_time_midday_009d2570[0xd];

      local_454[2] = s_env_time_midday_009d2570[0xe];

      local_454[3] = s_env_time_midday_009d2570[0xf];

      local_348[0] = s_env_time_sunset_009d25e8[0xc];

      local_348[1] = s_env_time_sunset_009d25e8[0xd];

      local_348[2] = s_env_time_sunset_009d25e8[0xe];

      local_348[3] = s_env_time_sunset_009d25e8[0xf];

      local_248[0] = s_env_time_night_009d25d8[0];

      local_248[1] = s_env_time_night_009d25d8[1];

      local_248[2] = s_env_time_night_009d25d8[2];

      local_248[3] = s_env_time_night_009d25d8[3];

      local_23c[0] = s_env_time_night_009d25d8[0xc];

      local_23c[1] = s_env_time_night_009d25d8[0xd];

      local_34c[0] = s_env_time_sunset_009d25e8[8];

      local_34c[1] = s_env_time_sunset_009d25e8[9];

      local_34c[2] = s_env_time_sunset_009d25e8[10];

      local_34c[3] = s_env_time_sunset_009d25e8[0xb];

      local_240[0] = s_env_time_night_009d25d8[8];

      local_240[1] = s_env_time_night_009d25d8[9];

      local_240[2] = s_env_time_night_009d25d8[10];

      local_240[3] = s_env_time_night_009d25d8[0xb];

      local_244[0] = s_env_time_night_009d25d8[4];

      local_244[1] = s_env_time_night_009d25d8[5];

      local_244[2] = s_env_time_night_009d25d8[6];

      local_244[3] = s_env_time_night_009d25d8[7];

      local_4 = 0;

      local_23a = s_env_time_night_009d25d8[0xe];

      FUN_00556da0(0,local_56c);

      local_575 = 0;

      pfVar4 = (float *)FUN_00558eb0(&local_570,&local_575);

      fVar7 = *pfVar4;

      local_4 = 0xffffffff;

      if (local_138 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(local_138);

      }

    }

  }

  iVar6 = *(int *)(param_1 + 0x17c);

  if (iVar6 != 0) {

    if (param_2 == *(byte *)(iVar6 + 0x54c)) {

      ExceptionList = local_c;

      return;

    }

    if (iVar6 != 0) {

      bVar2 = false;

      if ((uint)param_2 != *(uint *)(param_1 + 0x1b8)) {

        iVar6 = param_1 + 400;

        *(uint *)(param_1 + 0x1b8) = (uint)param_2;

        FUN_00556b10(iVar6,(int)fVar7 + 0x10,0);

        local_575 = 0;

        cVar3 = FUN_004ed310(iVar6,&local_575,param_1 + 0x1c0);

        *(char *)(param_1 + 0x1bc) = cVar3;

        bVar2 = true;

        if (cVar3 == '\0') {

          FUN_00971820(iVar6);

          ExceptionList = local_c;

          return;

        }

      }

      if (*(char *)(param_1 + 0x1bc) == '\0') {

        local_575 = 1;

        cVar3 = FUN_004ed310(param_1 + 400,&local_575,param_1 + 0x1c0);

        *(char *)(param_1 + 0x1bc) = cVar3;

        if (cVar3 == '\0') {

          ExceptionList = local_c;

          return;

        }

LAB_00557843:

        iVar6 = param_1 + 0x1a4;

        FUN_00556b10(iVar6,(int)fVar7 + 0x10,1);

        local_575 = 0;

        cVar3 = FUN_004ed310(iVar6,&local_575,param_1 + 0x1c0);

        *(char *)(param_1 + 0x1bd) = cVar3;

        if (cVar3 == '\0') {

          FUN_00971820(iVar6);

          ExceptionList = local_c;

          return;

        }

      }

      else if (bVar2) goto LAB_00557843;

      if (*(char *)(param_1 + 0x1bd) == '\0') {

        local_575 = 1;

        cVar3 = FUN_004ed310(param_1 + 0x1a4,&local_575,param_1 + 0x1c0);

        *(char *)(param_1 + 0x1bd) = cVar3;

        if (cVar3 == '\0') {

          ExceptionList = local_c;

          return;

        }

      }

    }

  }

  if (*(int *)(param_1 + 0x180) == 0) {

    DVar5 = GetTickCount();

  }

  else {

    if (*(byte *)(*(int *)(param_1 + 0x180) + 0x54c) != param_2) {

      if (DAT_00b03e64 == '\0') {

        ExceptionList = local_c;

        return;

      }

      goto LAB_00557960;

    }

    DVar5 = GetTickCount();

    iVar6 = DVar5 - *(int *)(param_1 + 0x18c);

    fVar1 = (float)iVar6;

    if (iVar6 < 0) {

      fVar1 = fVar1 + _DAT_00aaa5dc;

    }

    fVar8 = fVar1 / _DAT_00af2ce8;

    if (g_flOne <= fVar1 / _DAT_00af2ce8) {

      fVar8 = g_flOne;

    }

    local_574 = (g_flOne - fVar8) * _DAT_00af2ce8;

    local_570 = (int)ROUND(local_574);

    DVar5 = DVar5 - local_570;

  }

  *(DWORD *)(param_1 + 0x18c) = DVar5;

LAB_00557960:

  iVar6 = *(int *)(param_1 + 0x17c);

  *(int *)(param_1 + 0x180) = iVar6;

  *(int *)(param_1 + 0x17c) = (int)fVar7 + 0x10;

  if (DAT_00b03e64 != '\0') {

    if (iVar6 != 0) {

      FUN_005554d0();

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x180) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x18c) = 0;

  }

  FUN_00555f10(*(uint32_t /* width from decompiler */ *)(param_1 + 0x188));

  ExceptionList = local_c;

  return;

}

