// =============================================================================
// FUN_007a13e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007a13e0
// Address:   0x007a13e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a13e0 @ 0x007a13e0
// Stable ID: aa_007a13e0
// Embedded strings (evidence for future rename):
//   - "%s/screenshot_%04d-%02d-%02d_%02d-%02d-%02d.%s"
//   - "%s/screenshot_%04d-%02d-%02d_%02d-%02d-%02d_%d.%s"
//   - "CNDRenderEngine::CaptureScreen() - Failed to save screenshot file - "
//   - "%s - %s\r\n%s"
//   - "C:\\vog\\1_code\\vog_14_117_branch\\libND\\NDRenderEngine.cpp"
//   - "

// READABILITY (auto CF):
//  - Body size: ~173 non-empty decompiler lines.
//  - Control keywords: if×17, return×9, for×4, do×1, while×1.
//  - Notable callees: FUN_007a4480×7, CNDRenderEngine::CaptureScreen×5, ClientToScreen×2, FUN_0076cec0×2, GetSystemMetrics×2, _snprintf×2, vog_LogMessage×2, CONCAT22.
//  - Strings: "%s/screenshot_%04d-%02d-%02d_%02d-%02d-%02d.%s"; "%s/screenshot_%04d-%02d-%02d_%02d-%02d-%02d_%d.%s"; "%s - %s\r\n%s"; "C:\\vog\\1_code\\vog_14_117_branch\\libND\\NDRenderEngine.cpp".
//  - Return sites: 9.

                  );

      return 0;

    }

    FUN_007a4480(1,"
// Readability: control flow preserved from Ghidra decompile; types tentative.

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

uint32_t /* width from decompiler */ FUN_007a13e0(void)



{

  char cVar1;

  int in_EAX;

  int *piVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int iVar5;

  undefined *puVar6;

  char *pcVar7;

  char *pcVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint32_t /* width from decompiler */ uVar10;

  int *piVar11;

  _SYSTEMTIME local_44c;

  uint16_t local_43c;

  uint16_t uStack_43a;

  uint16_t uStack_438;

  uint16_t local_436;

  uint16_t uStack_434;

  uint16_t local_420 [2];

  char local_41c [4];

  char local_418 [4];

  char local_414 [2];

  char local_412;

  uint32_t /* width from decompiler */ local_411 [49];

  char acStack_34c [52];

  char local_318 [2];

  uint32_t /* width from decompiler */ local_316 [52];

  char acStack_244 [69];

  uint32_t /* width from decompiler */ uStack_1ff;

  

  local_420 = (uint16_t  [2])s____ScreenShots_00a9761c._0_4_;

  local_41c = (char  [4])s____ScreenShots_00a9761c._4_4_;

  local_414 = (char  [2])s____ScreenShots_00a9761c._12_2_;

  local_412 = s____ScreenShots_00a9761c[0xe];

  local_418 = (char  [4])s____ScreenShots_00a9761c._8_4_;

  puVar9 = local_411;

  for (iVar4 = 0x3d; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar9 = 0;

    puVar9 = puVar9 + 1;

  }

  *(uint8_t *)puVar9 = 0;

  iVar5 = 0;

  local_318[0] = '\0';

  local_318[1] = '\0';

  puVar9 = local_316;

  for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar9 = 0;

    puVar9 = puVar9 + 1;

  }

  *(uint16_t *)puVar9 = 0;

  uStack_43a = 0;

  uStack_438 = 0;

  local_43c = 0;

  local_436 = 0;

  uStack_434 = 0;

  cVar1 = FUN_0076adc0();

  if ((cVar1 == '\0') && (cVar1 = FUN_0076bc00(), cVar1 == '\0')) {

    FUN_0076cec0();

    vog_LogMessage();

    local_420[0] = 0x2e;

  }

  iVar4 = *(int *)(in_EAX + 0x2e8);

  if (iVar4 == 0) {

    local_43c = 0x706a;

    uStack_43a = 0x67;

  }

  else if (iVar4 == 1) {

    local_43c = 0x6e70;

    uStack_43a = 0x67;

  }

  else if (iVar4 == 2) {

    local_43c = 0x6d62;

    uStack_43a = 0x70;

  }

  GetLocalTime(&local_44c);

  do {

    if (iVar5 == 0) {

      _snprintf(local_318,0x104,"%s/screenshot_%04d-%02d-%02d_%02d-%02d-%02d.%s");

    }

    else {

      _snprintf(local_318,0x104,"%s/screenshot_%04d-%02d-%02d_%02d-%02d-%02d_%d.%s");

    }

    iVar5 = iVar5 + 1;

    iVar4 = _access(local_318,0);

  } while (iVar4 == 0);

  if ((**(int **)(in_EAX + 0x28) == 0) ||

     (piVar2 = (int *)(*(int **)(in_EAX + 0x28))[1], piVar2 == (int *)0x0)) {

    FUN_007a4480();

    return 0;

  }

  iVar4 = (**(code **)(*piVar2 + 0x20))();

  if (iVar4 < 0) {

    FUN_007a4480();

    return 0;

  }

  if (*(char *)(in_EAX + 5) == '\0') {

    piVar2 = (int *)CONCAT22(uStack_43a,local_43c);

  }

  else {

    piVar2 = (int *)GetSystemMetrics(0);

  }

  if (*(char *)(in_EAX + 5) != '\0') {

    GetSystemMetrics(1);

  }

  iVar4 = (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x28) + 0x90))();

  if (-1 < iVar4) {

    iVar4 = (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x28) + 0x84))

                      ((int *)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x28),0);

    if (-1 < iVar4) {

      puVar6 = (undefined *)0x0;

      if (*(char *)(in_EAX + 5) != '\0') {

        puVar6 = &DAT_00d2095c;

        GetClientRect(*(HWND *)(in_EAX + 0xb0),(LPRECT)&DAT_00d2095c);

        ClientToScreen(*(HWND *)(in_EAX + 0xb0),(LPPOINT)&DAT_00d2095c);

        ClientToScreen(*(HWND *)(in_EAX + 0xb0),(LPPOINT)&DAT_00d20964);

      }

      uVar10 = 0;

      piVar11 = piVar2;

      uVar3 = FUN_0079dbc0(piVar2,0,puVar6);

      iVar4 = D3DXSaveSurfaceToFileA(acStack_34c,uVar3,piVar2,uVar10,puVar6);

      if (-1 < iVar4) {

        if (piVar11 != (int *)0x0) {

          (**(code **)(*piVar11 + 8))(piVar11);

        }

        return 1;

      }

      pcVar7 = "CNDRenderEngine::CaptureScreen() - Failed to save screenshot file - ";

      pcVar8 = acStack_244;

      for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {

        *(uint32_t /* width from decompiler */ *)pcVar8 = *(uint32_t /* width from decompiler */ *)pcVar7;

        pcVar7 = pcVar7 + 4;

        pcVar8 = pcVar8 + 4;

      }

      *pcVar8 = *pcVar7;

      puVar9 = &uStack_1ff;

      for (iVar5 = 0x70; iVar5 != 0; iVar5 = iVar5 + -1) {

        *puVar9 = 0;

        puVar9 = puVar9 + 1;

      }

      *(uint16_t *)puVar9 = 0;

      *(uint8_t *)((int)puVar9 + 2) = 0;

      strncat(acStack_244,acStack_34c,0x208);

      uVar3 = FUN_006b7a5a(iVar4,acStack_244);

      uVar3 = FUN_006a5dac(iVar4,uVar3);

      uVar3 = FUN_0076cec0(&stack0xfffffb74,"%s - %s\r\n%s",uVar3);

      vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libND\\NDRenderEngine.cpp",0x363,3,uVar3);

      return 0;

    }

    if (iVar4 == -0x7789f7d9) {

      FUN_007a4480(1,

                   "CNDRenderEngine::CaptureScreen() - Internal driver error. Applications should generally shut down when receiving this error. For more information, see Driver Internal Errors."

                  );

      return 0;

    }

    if (iVar4 == -0x7789f798) {

      FUN_007a4480(1,

                   "CNDRenderEngine::CaptureScreen() - The device has been lost but cannot be reset at this time. Therefore, rendering is not possible."

                  );

      return 0;

    }

    if (iVar4 == -0x7789f794) {

      FUN_007a4480(1,

                   "CNDRenderEngine::CaptureScreen() - The method call is invalid. For example, a method\'s parameter may have an invalid value."

                  );

      return 0;

    }

    FUN_007a4480(1,"CNDRenderEngine::CaptureScreen() - UNKNOWN");

    return 0;

  }

  FUN_007a4480(1);

  return 0;

}
