// =============================================================================
// FUN_009387e0
// -----------------------------------------------------------------------------
// Stable ID: aa_009387e0
// Address:   0x009387e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009387e0 @ 0x009387e0
// Stable ID: aa_009387e0
// Embedded strings (evidence for future rename):
//   - "FPS: %.2f, %.5f"
//   - "  Scene Manager: %.5f, %.1f%%;  (%d bodies) (x%d,mx%d,z%d,mz%d) (g:%d/%d, ng:%d/%d)"
//   - "    ^%.5f, v%.5f"
//   - "Obj Cleanup"
//   - "HB Pulse"
//   - "%s: %.5f, %.1f%% \t^%.5f, v%.5f\t(%u size)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~531 non-empty decompiler lines.
//  - Control keywords: if×31, return×6, do×2, while×2, for×1.
//  - Notable callees: sprintf×17, FUN_00759730×16, Client_GetMissionCompleteAudioTable×15, FUN_0040aeb0×15, FUN_009378e0×11, SUB84×9, ROUND×4, CONCAT13×3.
//  - Strings: "FPS: %.2f, %.5f"; "    ^%.5f, v%.5f"; "Obj Cleanup"; "HB Pulse".
//  - Return sites: 6.

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



int FUN_009387e0(int param_1)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint8_t **ppuVar7;

  LPCRITICAL_SECTION lpCriticalSection;

  int iVar8;

  float fVar9;

  uint32_t /* width from decompiler */ local_410;

  LPCRITICAL_SECTION local_40c;

  uint8_t *local_408;

  int local_404;

  float local_400;

  int local_3fc;

  LPCRITICAL_SECTION local_3f8;

  float local_3f4;

  int iStack_3f0;

  float local_3ec;

  uint8_t *local_3e8;

  float local_3e4;

  float local_3e0;

  int local_3dc;

  uint8_t *local_3d8;

  int local_3d4;

  int local_3d0;

  int local_3cc;

  int local_3c8;

  int local_3c4;

  uint8_t *local_3c0;

  float local_3bc;

  float local_3b8;

  int iStack_3a4;

  int iStack_3a0;

  int local_39c;

  uint8_t *puStack_398;

  uint8_t uStack_394;

  uint32_t /* width from decompiler */ local_388 [24];

  char local_328 [512];

  char acStack_128 [268];

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009b3bcf;

  local_1c = ExceptionList;

  local_3fc = 0x18;

  if (DAT_00d1e7ec != 0) {

    local_3fc = *(int *)(DAT_00d1e7ec + 0x7c) + 2;

  }

  iVar2 = *(int *)(param_1 + 0xb8);

  if (iVar2 == 1) {

    local_408 = (uint8_t *)0xa;

    local_404 = 0x3c;

    if (0x32 < DAT_00d1f080) {

      _DAT_00d1f090 = 0.0;

      DAT_00d1f080 = 0;

    }

    if (*(float *)(DAT_00d09874 + 0x30) <= _DAT_00d1f090) {

      DAT_00d1f080 = DAT_00d1f080 + 1;

    }

    else {

      _DAT_00d1f088 = *(uint32_t /* width from decompiler */ *)(DAT_00d09874 + 0x34);

      _DAT_00d1f08c = *(uint32_t /* width from decompiler */ *)(DAT_00d09874 + 0x40);

      _DAT_00d1f084 = *(uint32_t /* width from decompiler */ *)(DAT_00d09874 + 100);

      DAT_00d1f080 = 0;

      _DAT_00d1f090 = *(float *)(DAT_00d09874 + 0x30);

    }

    local_400 = *(float *)(DAT_00d09874 + 0x30);

    if (local_400 == 0.0) {

      local_40c = (LPCRITICAL_SECTION)0x0;

    }

    else {

      local_40c = (LPCRITICAL_SECTION)(g_flOne / *(float *)(DAT_00d09874 + 0x30));

    }

    ExceptionList = &local_1c;

    sprintf(local_328,"FPS: %.2f, %.5f");

    local_3f8 = (LPCRITICAL_SECTION)&stack0xfffffbc0;

    FUN_0040aeb0(&stack0xfffffbc0);

    local_410 = 0xffffff80;

    local_14 = 0xffffffff;

    FUN_00759730(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xde8) + 0x2c),&local_408,&local_410);

    local_404 = local_3fc + 0x3c;

    local_410 = 0xffffff80;

    FUN_009378e0();

    local_40c = (LPCRITICAL_SECTION)g_flOne;

    if (*(float *)(DAT_00d09874 + 0x30) != g_flZero) {

      local_40c = (LPCRITICAL_SECTION)

                  (*(float *)(DAT_00d09874 + 0x38) / *(float *)(DAT_00d09874 + 0x30));

    }

    iVar2 = *(int *)(*(int *)(param_1 + 0xe04) + 0xe898);

    local_400 = *(float *)(iVar2 + 0x70);

    local_3f4 = *(float *)(iVar2 + 0x68);

    local_3ec = *(float *)(iVar2 + 0x6c);

    local_3dc = *(int *)(iVar2 + 100);

    if (*(int *)(iVar2 + 0xac) == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = *(int *)(iVar2 + 0xb0) - *(int *)(iVar2 + 0xac) >> 2;

    }

    sprintf(local_328,

            "  Scene Manager: %.5f, %.1f%%;  (%d bodies) (x%d,mx%d,z%d,mz%d) (g:%d/%d, ng:%d/%d)",

            SUB84((double)*(float *)(DAT_00d09874 + 0x38),0),

            (int)((ulonglong)(double)*(float *)(DAT_00d09874 + 0x38) >> 0x20),

            SUB84((double)((float)local_40c * DAT_00aaa7ac),0),

            (int)((ulonglong)(double)((float)local_40c * DAT_00aaa7ac) >> 0x20),iVar2);

    if ((float)local_40c <= DAT_00a10e78) {

      local_410._0_2_ = 0xff80;

    }

    else {

      local_3f4 = (float)(int)ROUND((float)local_40c * _DAT_00a14018);

      local_40c = (LPCRITICAL_SECTION)((float)local_40c * _DAT_00aaaa30);

      local_400 = (float)(int)ROUND((float)local_40c);

      local_410._0_2_ = CONCAT11(-0x40 - local_400._0_1_,-0x80 - local_3f4._0_1_);

    }

    local_3f8 = (LPCRITICAL_SECTION)&stack0xfffffbc0;

    local_410._0_3_ = CONCAT12(0xff,(uint16_t)local_410);

    local_410 = CONCAT13(0xff,(undefined3)local_410);

    FUN_0040aeb0(&stack0xfffffbc0);

    local_14 = 0xffffffff;

    FUN_00759730(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xde8) + 0x2c),&local_408,&local_410);

    iVar2 = local_3fc;

    local_404 = local_404 + local_3fc;

    sprintf(local_328,"    ^%.5f, v%.5f");

    local_3f8 = (LPCRITICAL_SECTION)&stack0xfffffbc0;

    FUN_0040aeb0(&stack0xfffffbc0);

    local_410 = 0xffffff80;

    local_14 = 0xffffffff;

    FUN_00759730(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xde8) + 0x2c),&local_408,&local_410);

    local_404 = local_404 + iVar2;

    local_410 = 0xffffff80;

    FUN_009378e0();

    local_410 = 0xffffff80;

    FUN_009378e0();

    local_410 = 0xffffff80;

    FUN_009378e0();

    local_410 = 0xffffff80;

    FUN_009378e0();

    local_410 = 0xffffff80;

    FUN_009378e0("Obj Cleanup",&local_410);

    local_410 = 0xffffff80;

    FUN_009378e0("HB Pulse",&local_410);

    local_40c = (LPCRITICAL_SECTION)g_flOne;

    if (*(float *)(DAT_00d09874 + 0x30) != g_flZero) {

      local_40c = (LPCRITICAL_SECTION)

                  (*(float *)(DAT_00d09874 + 0x50) / *(float *)(DAT_00d09874 + 0x30));

    }

    local_400 = *(float *)(DAT_00d09874 + 0x50);

    sprintf(local_328,"%s: %.5f, %.1f%% \t^%.5f, v%.5f\t(%u size)","Sound",

            SUB84((double)local_400,0));

    if ((float)local_40c <= DAT_00a10e78) {

      local_410._0_2_ = 0xff80;

    }

    else {

      local_3f4 = (float)(int)ROUND((float)local_40c * _DAT_00a14018);

      local_40c = (LPCRITICAL_SECTION)((float)local_40c * _DAT_00aaaa30);

      local_400 = (float)(int)ROUND((float)local_40c);

      local_410._0_2_ = CONCAT11(-0x40 - local_400._0_1_,-0x80 - local_3f4._0_1_);

    }

    local_3f8 = (LPCRITICAL_SECTION)&stack0xfffffbc0;

    local_410._0_3_ = CONCAT12(0xff,(uint16_t)local_410);

    local_410 = CONCAT13(0xff,(undefined3)local_410);

    FUN_0040aeb0(&stack0xfffffbc0);

    local_14 = 0xffffffff;

    FUN_00759730(*(uint32_t /* width from decompiler */ *)(DAT_00d1b628 + 0x2c),&local_408,&local_410);

    local_404 = local_404 + local_3fc;

    local_410 = 0xffffff80;

    FUN_009378e0();

    local_410 = 0xffffff80;

    FUN_009378e0();

    local_410 = 0xffffff80;

    FUN_009378e0();

    local_410 = 0xffffff80;

    FUN_009378e0();

    iVar2 = *(int *)(param_1 + 0xde8);

    local_40c = *(LPCRITICAL_SECTION *)(iVar2 + 0x158);

    local_400 = *(float *)(iVar2 + 0x154);

    local_3f4 = *(float *)(iVar2 + 0x150);

    local_3ec = *(float *)(iVar2 + 0x14c);

    sprintf(local_328,

            "Particles(%d) Emitters(%d) GeoParticles(%d) StaticGeo(%d) SpecialFX(%d) Trails(%d) ParticleBudget - Over(%d) MissedBy(%d)"

            ,*(uint32_t /* width from decompiler */ *)(iVar2 + 0x13c),*(uint32_t /* width from decompiler */ *)(iVar2 + 0x148),local_3ec,local_3f4,

            local_400,local_40c,*(uint32_t /* width from decompiler */ *)(iVar2 + 0x140),*(uint32_t /* width from decompiler */ *)(iVar2 + 0x144));

    local_3f8 = (LPCRITICAL_SECTION)&stack0xfffffbc0;

    FUN_0040aeb0(&stack0xfffffbc0);

    local_410 = 0xffe8a0c9;

    local_14 = 0xffffffff;

    FUN_00759730(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xde8) + 0x2c),&local_408,&local_410);

    local_404 = local_404 + local_3fc;

    iVar2 = *(int *)(param_1 + 0xde8);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x13c) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x140) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x144) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x148) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x14c) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x150) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x154) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x158) = 0;

    iVar2 = *(int *)(param_1 + 0xf38);

    if (iVar2 != 0) {

      local_400 = *(float *)(iVar2 + 0xccc);

      local_40c = *(LPCRITICAL_SECTION *)(iVar2 + 0xcd0);

      sprintf(local_328,

              "Camera %d: ZRatio:%.5f, YRation%.5f, Pan:%.5f Zoom: %f -- %f -- %f LOD bias %f Scalar %f"

              ,*(uint32_t /* width from decompiler */ *)(iVar2 + 0x60c),(double)local_400,SUB84((double)(float)local_40c,0),

              (int)((ulonglong)(double)(float)local_40c >> 0x20),

              SUB84((double)*(float *)(iVar2 + 0xcc8),0),

              (int)((ulonglong)(double)*(float *)(iVar2 + 0xcc8) >> 0x20),

              SUB84((double)*(float *)(iVar2 + 0x524),0),

              (int)((ulonglong)(double)*(float *)(iVar2 + 0x524) >> 0x20));

      local_3f8 = (LPCRITICAL_SECTION)&stack0xfffffbc0;

      FUN_0040aeb0(&stack0xfffffbc0);

      local_410 = 0xff40ff80;

      local_14 = 0xffffffff;

      FUN_00759730(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xde8) + 0x2c),&local_408,&local_410);

      local_404 = local_404 + local_3fc;

    }

    if (((*(int *)(param_1 + 0xe98) != 0) &&

        (local_40c = *(LPCRITICAL_SECTION *)(*(int *)(param_1 + 0xe98) + 0x250),

        local_40c != (LPCRITICAL_SECTION)0x0)) && (*(int *)((int)local_40c + 8) != 0)) {

      FUN_00404c90();

      iVar2 = *(int *)(*(int *)((int)local_40c + 8) + 0x3c);

      local_40c = (LPCRITICAL_SECTION)

                  (*(float *)(iVar2 + 0x40) * *(float *)(iVar2 + 0x40) +

                   *(float *)(iVar2 + 0x44) * *(float *)(iVar2 + 0x44) +

                  *(float *)(iVar2 + 0x48) * *(float *)(iVar2 + 0x48));

      sprintf(local_328,"Car Pos(%.2f, %.2f, %.2f) Vel: %.2f");

      local_3f8 = (LPCRITICAL_SECTION)&stack0xfffffbc0;

      FUN_0040aeb0(&stack0xfffffbc0);

      local_410 = 0xff40ff80;

      local_14 = 0xffffffff;

      FUN_00759730(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xde8) + 0x2c),&local_408,&local_410);

      local_404 = local_404 + local_3fc;

    }

    local_40c = *(LPCRITICAL_SECTION *)(*(int *)(param_1 + 0xe04) + 0xe890);

    sprintf(local_328,"GameCam Pos(%.2f, %.2f, %.2f)");

    local_3f8 = (LPCRITICAL_SECTION)&stack0xfffffbc0;

    FUN_0040aeb0(&stack0xfffffbc0);

    local_410 = 0xff40ff80;

    local_14 = 0xffffffff;

    FUN_00759730(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xde8) + 0x2c),&local_408,&local_410);

    local_404 = local_404 + local_3fc;

    iVar2 = local_40c->RecursionCount;

    local_3e0 = g_flOne - (*(float *)(iVar2 + 0x80) * *(float *)(iVar2 + 0x80) +

                          *(float *)(iVar2 + 0x84) * *(float *)(iVar2 + 0x84)) *

                          g_flLevelUpUiBase_Inferred;

    local_3e4 = (*(float *)(iVar2 + 0x88) * *(float *)(iVar2 + 0x84) -

                *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x80)) * g_flLevelUpUiBase_Inferred;

    local_3e8 = (uint8_t *)

                ((*(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x84) +

                 *(float *)(iVar2 + 0x88) * *(float *)(iVar2 + 0x80)) * g_flLevelUpUiBase_Inferred);

    local_3c0 = local_3e8;

    local_3bc = local_3e4;

    local_3b8 = local_3e0;

    sprintf(local_328,"GameCam Heading(%.2f, %.2f, %.2f)");

    local_3f8 = (LPCRITICAL_SECTION)&stack0xfffffbc0;

    FUN_0040aeb0(&stack0xfffffbc0);

    local_410 = 0xff40ff80;

    local_14 = 0xffffffff;

    FUN_00759730(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xde8) + 0x2c),&local_408,&local_410);

    local_404 = local_404 + local_3fc;

    iVar2 = local_40c->RecursionCount;

    local_3e0 = (*(float *)(iVar2 + 0x80) * *(float *)(iVar2 + 0x8c) +

                *(float *)(iVar2 + 0x84) * *(float *)(iVar2 + 0x88)) * g_flLevelUpUiBase_Inferred;

    local_3e4 = g_flOne - (*(float *)(iVar2 + 0x80) * *(float *)(iVar2 + 0x80) +

                          *(float *)(iVar2 + 0x88) * *(float *)(iVar2 + 0x88)) *

                          g_flLevelUpUiBase_Inferred;

    local_3e8 = (uint8_t *)

                ((*(float *)(iVar2 + 0x80) * *(float *)(iVar2 + 0x84) -

                 *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x88)) * g_flLevelUpUiBase_Inferred);

    local_3c0 = local_3e8;

    local_3bc = local_3e4;

    local_3b8 = local_3e0;

    sprintf(local_328,"GameCam Up(%.2f, %.2f, %.2f)");

    local_3f8 = (LPCRITICAL_SECTION)&stack0xfffffbc0;

    FUN_0040aeb0(&stack0xfffffbc0);

    local_410 = 0xff40ff80;

    local_14 = 0xffffffff;

    FUN_00759730(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xde8) + 0x2c),&local_408,&local_410);

    iVar2 = *(int *)(DAT_00d1f050 + 0x6c);

    local_404 = local_404 + local_3fc;

    if (iVar2 != 0) {

      local_3f4 = *(float *)(iVar2 + 0x10c);

      local_400 = *(float *)(iVar2 + 0xf8);

      local_3ec = *(float *)(iVar2 + 0xf4);

      local_3c8 = *(int *)(iVar2 + 0xf0);

      local_3dc = *(int *)(iVar2 + 0x108);

      local_3d4 = *(int *)(iVar2 + 0x100);

      local_3cc = *(int *)(iVar2 + 0x104);

      local_3d0 = *(int *)(iVar2 + 0xec);

      local_40c = (LPCRITICAL_SECTION)(iVar2 + 0x30);

      local_3c4 = *(int *)(iVar2 + 0xe8);

      local_3d8 = *(uint8_t **)(iVar2 + 0xfc);

      if (*(char *)(iVar2 + 0x48) != '\0') {

        EnterCriticalSection(local_40c);

      }

      uVar6 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x2c);

      if (*(char *)&local_40c[1].DebugInfo != '\0') {

        LeaveCriticalSection(local_40c);

      }

      sprintf(local_328,

              "Preloader pending(%d)\tgeo(%d,%d)\tdds(%d,%d)\togg(%d,%d)\txml(%d,%d)\tother(%d,%d)",

              uVar6,local_3d8,local_3c4);

      local_3f8 = (LPCRITICAL_SECTION)&stack0xfffffbc0;

      FUN_0040aeb0(&stack0xfffffbc0);

      local_410 = 0xff13ec08;

      local_14 = 0xffffffff;

      FUN_00759730(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xde8) + 0x2c),&local_408,&local_410);

      local_404 = local_404 + local_3fc;

    }

    FUN_004bfb20();

    _snprintf(local_328,0x200,"Load queue size (%d)");

    local_3f8 = (LPCRITICAL_SECTION)&stack0xfffffbc0;

    FUN_0040aeb0(&stack0xfffffbc0);

    uVar6 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xde8) + 0x2c);

    local_410._0_3_ = 0x13ec08;

    ppuVar7 = &local_408;

  }

  else {

    if (iVar2 == 2) {

      local_3e8 = (uint8_t *)0xa;

      local_3e4 = 7.00649e-44;

      ExceptionList = &local_1c;

      piVar3 = (int *)Client_GetMissionCompleteAudioTable();

      if (*piVar3 != 0) {

        iVar2 = Client_GetMissionCompleteAudioTable();

        lpCriticalSection = (LPCRITICAL_SECTION)(iVar2 + 0x3f8);

        local_40c = lpCriticalSection;

        local_3f8 = lpCriticalSection;

        EnterCriticalSection(lpCriticalSection);

        local_14 = 0xc;

        puVar4 = local_388;

        for (iVar2 = 0x18; iVar2 != 0; iVar2 = iVar2 + -1) {

          *puVar4 = 0;

          puVar4 = puVar4 + 1;

        }

        local_388[0] = 0x60;

        puVar4 = (uint32_t /* width from decompiler */ *)Client_GetMissionCompleteAudioTable();

        iVar2 = (**(code **)(*(int *)*puVar4 + 0x10))();

        if (iVar2 < 0) {

          local_14 = 0xffffffff;

          LeaveCriticalSection(lpCriticalSection);

          ExceptionList = local_1c;

          return iVar2;

        }

        sprintf(local_328,

                "MaxHW3DStrBuf: %d, FreeHW3DStrBuf: %d, MaxHW3DStatBuf: %d, FreeHW3DStatBuf: %d, FreeHWBYTES: %d, MaxFreeHWMemBYTES: %d, TotalHWMemBYTES: %d"

               );

        local_408 = &stack0xfffffbc0;

        FUN_0040aeb0(&stack0xfffffbc0);

        local_410 = -0x80;

        local_14 = CONCAT31((int3)((uint)local_14 >> 8),0xc);

        FUN_00759730(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xde8) + 0x2c),&local_3e8,&local_410);

        local_3e4 = (float)(local_3fc + 0x32);

        local_14 = 0xffffffff;

        LeaveCriticalSection(local_40c);

      }

      if (*(char *)(param_1 + 0x9e6) == '\0') {

        ExceptionList = local_1c;

        return 0;

      }

      local_40c = (LPCRITICAL_SECTION)0x0;

      iVar2 = Client_GetMissionCompleteAudioTable();

      if (*(int *)(iVar2 + 0x210) < 1) {

        ExceptionList = local_1c;

        return 0;

      }

      iVar2 = 0x31c;

      do {

        iVar5 = Client_GetMissionCompleteAudioTable();

        if (*(int *)(iVar5 + iVar2) != 0) {

          Client_GetMissionCompleteAudioTable();

          sprintf(acStack_128,"%s");

          Client_GetMissionCompleteAudioTable();

          Client_GetMissionCompleteAudioTable();

          uVar6 = FUN_00723880();

          iVar5 = Client_GetMissionCompleteAudioTable();

          local_3f4 = (float)(uint)*(byte *)(*(int *)(iVar5 + iVar2) + 0x1c5);

          iVar5 = Client_GetMissionCompleteAudioTable();

          local_408 = *(uint8_t **)(*(int *)(iVar5 + iVar2) + 0x40);

          local_404 = *(int *)(*(int *)(iVar5 + iVar2) + 0x44);

          iVar5 = Client_GetMissionCompleteAudioTable();

          iVar5 = *(int *)(iVar5 + iVar2);

          local_3c0 = *(uint8_t **)(iVar5 + 0x150);

          local_3bc = *(float *)(iVar5 + 0x154);

          local_3b8 = *(float *)(iVar5 + 0x158);

          iVar5 = Client_GetMissionCompleteAudioTable();

          iVar5 = *(int *)(*(int *)(iVar5 + iVar2) + 0x14c);

          if (iVar5 == 0) {

            puStack_398 = DAT_00a2d820;

            uStack_394 = DAT_00a2d824;

          }

          else if (iVar5 == 1) {

            puStack_398 = &LAB_00766157;

          }

          else if (iVar5 == 2) {

            puStack_398 = (uint8_t *)0x67674f;

          }

          iVar5 = Client_GetMissionCompleteAudioTable();

          local_400 = *(float *)(*(int *)(iVar5 + iVar2) + 0x1a4);

          iVar5 = Client_GetMissionCompleteAudioTable();

          sprintf(local_328,

                  "[%2i] Type: %4s, Playing: %i, Looping: %d, Priority: %d, COID: %I64d, Location: %.02f %.02f  %.02f, Vol %.02f, Name: %s"

                  ,local_40c,&puStack_398,local_3f4,(uint)*(byte *)(*(int *)(iVar5 + iVar2) + 0x36),

                  uVar6,local_408,local_404,SUB84((double)(float)local_3c0,0));

          local_3f8 = (LPCRITICAL_SECTION)&stack0xfffffbc0;

          FUN_0040aeb0(&stack0xfffffbc0);

          local_410 = -0x80;

          local_14 = 0xffffffff;

          FUN_00759730(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xde8) + 0x2c),&local_3e8,&local_410);

          local_3e4 = (float)((int)local_3e4 + local_3fc);

        }

        iVar8 = (int)local_40c + 1;

        iVar2 = iVar2 + 4;

        local_40c = (LPCRITICAL_SECTION)iVar8;

        iVar5 = Client_GetMissionCompleteAudioTable();

      } while (iVar8 < *(int *)(iVar5 + 0x210));

      ExceptionList = local_1c;

      return 0;

    }

    if (iVar2 != 3) {

      return 0;

    }

    fVar9 = 1.4013e-44;

    local_3e8 = (uint8_t *)0xa;

    local_3e4 = 1.4013e-44;

    local_40c = (LPCRITICAL_SECTION)0x0;

    local_400 = 0.0;

    local_3f4 = 0.0;

    local_3ec = 0.0;

    local_3dc = 0;

    local_3c8 = 0;

    local_3cc = 0;

    local_3d0 = 0;

    local_3d4 = 0;

    local_3c4 = 0;

    ExceptionList = &local_1c;

    if ((*(int *)(param_1 + 0xc78) != 0) &&

       (ExceptionList = &local_1c, cVar1 = (**(code **)(**(int **)(param_1 + 0xc78) + 8))(),

       cVar1 != '\0')) {

      (**(code **)(**(int **)(param_1 + 0xc78) + 0x54))();

      sprintf(local_328,"Overall Network: ServLatency: %d Roundtrip:%d KeepAlive:%d Pending:%d");

      local_3d8 = &stack0xfffffbc0;

      FUN_0040aeb0(&stack0xfffffbc0);

      iStack_3f0 = -1;

      local_14 = 0xffffffff;

      FUN_00759730(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xde8) + 0x2c),&local_3e8,&iStack_3f0);

      fVar9 = (float)(local_3fc / 2 + 10);

      local_3e4 = fVar9;

    }

    local_39c = 0;

    if (0 < *(int *)(DAT_00d09874 + 0x1c)) {

      local_410 = -0x80;

      local_3d8 = (uint8_t *)0x0;

      iVar2 = DAT_00d09874;

      do {

        iVar5 = *(int *)(iVar2 + 0x18);

        iStack_3f0 = -0x80;

        if (*(int *)(local_3d8 + iVar5 + 0xc) == 0) {

          if (*(float *)(local_3d8 + iVar5 + 0x1c) != g_flZero) {

            iStack_3a0 = -0x3f7f80;

            iStack_3f0 = iStack_3a0;

          }

        }

        else {

          iStack_3a4 = -0x7f80;

          iStack_3f0 = iStack_3a4;

        }

        if (iStack_3f0 != local_410) {

          iVar2 = *(int *)(iVar2 + 0x18);

          local_3f4 = *(float *)(local_3d8 + iVar2 + 0x1c) + local_3f4;

          local_40c = (LPCRITICAL_SECTION)

                      ((int)&local_40c->DebugInfo + *(int *)(local_3d8 + iVar2 + 0xc));

          local_400 = (float)((int)local_400 + *(int *)(local_3d8 + iVar2 + 0x10));

          local_3dc = local_3dc + *(int *)(local_3d8 + iVar2 + 4);

          local_3c8 = local_3c8 + *(int *)(local_3d8 + iVar2 + 8);

          local_3cc = local_3cc + *(int *)(local_3d8 + iVar2 + 0x14);

          local_3d0 = local_3d0 + *(int *)(local_3d8 + iVar2 + 0x18);

          local_3ec = *(float *)(local_3d8 + iVar2 + 0x20) + local_3ec;

          if (*(uint *)(local_3d8 + iVar2 + 0x24) < 1000000) {

            iVar2 = *(int *)(local_3d8 + iVar5 + 0x24);

          }

          else {

            iVar2 = 0;

          }

          local_3d4 = local_3d4 + iVar2;

          local_3c4 = local_3c4 +

                      (~-(uint)(999999 < *(uint *)(local_3d8 + iVar5 + 0x28)) &

                      *(uint *)(local_3d8 + iVar5 + 0x28));

          iVar2 = *(int *)(DAT_00d09874 + 0x18);

          sprintf(local_328,

                  "%d:\t\tTB:%06d TP:%04d AB:%06.0f AP:%04.0f CB:%05d CP:%03d PB:%06d PP:%03d VB:%05d VP:%03d"

                  ,local_39c,*(uint32_t /* width from decompiler */ *)(local_3d8 + iVar2 + 0xc),

                  *(uint32_t /* width from decompiler */ *)(local_3d8 + iVar2 + 0x10),

                  SUB84((double)*(float *)(local_3d8 + iVar2 + 0x1c),0),

                  (int)((ulonglong)(double)*(float *)(local_3d8 + iVar2 + 0x1c) >> 0x20));

          local_408 = &stack0xfffffbc0;

          local_3f8 = (LPCRITICAL_SECTION)&stack0xfffffbc0;

          FUN_0040aef0(&stack0xfffffbc0);

          local_14 = 0xffffffff;

          FUN_00759730(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xde8) + 0x2c),&local_3e8,&iStack_3f0);

          fVar9 = (float)((int)fVar9 + local_3fc / 2);

          iVar2 = DAT_00d09874;

          local_3e4 = fVar9;

        }

        local_39c = local_39c + 1;

        local_3d8 = local_3d8 + 0x2c;

      } while (local_39c < *(int *)(iVar2 + 0x1c));

    }

    sprintf(local_328,

            "TOTAL:\tTB:%06d TP:%04d AB:%06.0f AP:%04.0f CB:%05d CP:%03d PB:%06d PP:%03d VB:%05d VP:%03d"

            ,local_40c,local_400,SUB84((double)local_3f4,0),

            (int)((ulonglong)(double)local_3f4 >> 0x20));

    local_3f8 = (LPCRITICAL_SECTION)&stack0xfffffbc0;

    local_408 = &stack0xfffffbc0;

    FUN_0040aef0(&stack0xfffffbc0);

    uVar6 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xde8) + 0x2c);

    local_410._0_3_ = 0xffffff;

    ppuVar7 = &local_3e8;

  }

  local_14 = 0xffffffff;

  local_410 = CONCAT13(0xff,(undefined3)local_410);

  FUN_00759730(uVar6,ppuVar7,&local_410);

  ExceptionList = local_1c;

  return 0;

}
