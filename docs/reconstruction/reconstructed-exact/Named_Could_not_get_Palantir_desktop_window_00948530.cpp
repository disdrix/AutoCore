// =============================================================================
// Named_Could_not_get_Palantir_desktop_window_00948530
// -----------------------------------------------------------------------------
// Stable ID: aa_00948530
// Address:   0x00948530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Could_not_get_Palantir_desktop_window_00948530 @ 0x00948530
// Stable ID: aa_00948530
// Embedded strings (evidence for future rename):
//   - "XutoAssault"
//   - "Auto Assault"
//   - "Failed to CreateWindowEx!"
//   - "aa.bmp"
//   - "Failed to initialize the RenderEngine!"
//   - "Could not get Palantir desktop window."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~224 non-empty decompiler lines.
//  - Control keywords: if×20, return×3, for×2.
//  - Notable callees: UpdateWindow×2, AdjustWindowRectEx, CreateWindowExA, EnumDisplayMonitors, FUN_0040af40, FUN_0040d9c0, FUN_0043c5f0, FUN_0048eaa0.
//  - Strings: "XutoAssault"; "Auto Assault"; "Failed to CreateWindowEx!"; "aa.bmp".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * String-driven rename evidence: "Could not get Palantir desktop window."
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Restarted to delay deadcode elimination for space: stack */



uint32_t /* width from decompiler */ __fastcall Named_Could_not_get_Palantir_desktop_window_00948530(int param_1)



{

  LPRECT lpRect;

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char cVar3;

  short sVar4;

  ATOM AVar5;

  uint uVar6;

  BOOL BVar7;

  HWND pHVar8;

  void *pvVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint uVar11;

  int iVar12;

  char *pcVar13;

  WNDCLASSA local_6c;

  int local_44;

  int local_40;

  int local_3c;

  int *local_38;

  LONG *local_34;

  uint8_t local_30 [4];

  int local_2c;

  uint local_28;

  uint local_24;

  int local_20;

  uint32_t /* width from decompiler */ local_1c;

  undefined *local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bbb25;

  local_10 = ExceptionList;

  local_14 = &stack0xffffff34;

  DAT_00afa250 = *(uint8_t *)(param_1 + 0x9c1);

  ExceptionList = &local_10;

  EnumDisplayMonitors((HDC)0x0,(LPCRECT)0x0,(MONITORENUMPROC)&LAB_00930d30,0);

  if (DAT_00d1a830 == 0) {

    uVar6 = 0;

  }

  else {

    uVar6 = (DAT_00d1a834 - DAT_00d1a830) / 0xc;

  }

  if (uVar6 <= *(ushort *)(param_1 + 0xa14)) {

    if (DAT_00d1a830 == 0) {

      sVar4 = 0;

    }

    else {

      sVar4 = (short)((DAT_00d1a834 - DAT_00d1a830) / 0xc);

    }

    *(short *)(param_1 + 0xa14) = sVar4 + -1;

  }

  uVar6 = (uint)*(ushort *)(param_1 + 0xa14);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3194) = *(uint32_t /* width from decompiler */ *)(DAT_00d1a830 + uVar6 * 0xc + 4);

  lpRect = (LPRECT)(param_1 + 0x3190);

  lpRect->left = *(LONG *)(DAT_00d1a830 + uVar6 * 0xc);

  *(int *)(param_1 + 0x319c) = *(int *)(DAT_00d1a830 + uVar6 * 0xc + 4) + *(int *)(param_1 + 0xa1c);

  *(int *)(param_1 + 0x3198) = *(int *)(param_1 + 0xa18) + *(int *)(DAT_00d1a830 + uVar6 * 0xc);

  local_6c.style = 0x302b;

  local_6c.lpfnWndProc = (WNDPROC)&LAB_009484d0;

  local_6c.cbClsExtra = 0;

  local_6c.cbWndExtra = 0;

  local_6c.hInstance = *(HINSTANCE *)(param_1 + 0x3180);

  local_6c.hIcon = LoadIconA(local_6c.hInstance,(LPCSTR)0x65);

  local_6c.hCursor = (HCURSOR)0x0;

  local_6c.hbrBackground = (HBRUSH)0x0;

  local_6c.lpszMenuName = (LPCSTR)0x0;

  local_6c.lpszClassName = "XutoAssault";

  *(LONG *)(param_1 + 0x31a0) = lpRect->left;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x31a4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x3194);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x31a8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x3198);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x31ac) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x319c);

  if ((*(char *)(param_1 + 0x9c1) == '\0') ||

     (local_18 = &DAT_00ca0000, *(char *)(param_1 + 0x9c2) == '\0')) {

    local_18 = (undefined *)0x80000000;

  }

  if ((*(char *)(param_1 + 0x9c1) != '\0') &&

     (BVar7 = AdjustWindowRectEx(lpRect,(DWORD)local_18,0,0x40000), BVar7 != 0)) {

    iVar12 = *(LONG *)(param_1 + 0x31a0) - lpRect->left;

    lpRect->left = lpRect->left + iVar12;

    *(int *)(param_1 + 0x3198) = *(int *)(param_1 + 0x3198) + iVar12;

    iVar12 = *(int *)(param_1 + 0x31a4) - *(int *)(param_1 + 0x3194);

    *(int *)(param_1 + 0x3194) = *(int *)(param_1 + 0x3194) + iVar12;

    *(int *)(param_1 + 0x319c) = *(int *)(param_1 + 0x319c) + iVar12;

  }

  iVar12 = *(int *)(param_1 + 0x3198);

  iVar1 = lpRect->left;

  local_44 = *(int *)(param_1 + 0x319c) - *(int *)(param_1 + 0x3194);

  AVar5 = RegisterClassA(&local_6c);

  if (AVar5 != 0) {

    pHVar8 = CreateWindowExA(0x40000,"XutoAssault","Auto Assault",(DWORD)local_18,lpRect->left,

                             *(int *)(param_1 + 0x3194),iVar12 - iVar1,local_44,(HWND)0x0,(HMENU)0x0

                             ,*(HINSTANCE *)(param_1 + 0x3180),(LPVOID)0x0);

    *(HWND *)(param_1 + 0x3188) = pHVar8;

  }

  if (*(int *)(param_1 + 0x3188) == 0) {

    pcVar13 = "Failed to CreateWindowEx!";

  }

  else {

    if (*(int *)(param_1 + 0x1168) == 0) {

      pvVar9 = operator_new(0x590);

      local_8 = 0;

      if (pvVar9 == (void *)0x0) {

        uVar10 = 0;

      }

      else {

        uVar10 = FUN_007fb0a0(pvVar9);

      }

      local_8 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x1168) = uVar10;

    }

    (**(code **)(**(int **)(param_1 + 0x1168) + 4))(0);

    ShowWindow(*(HWND *)(param_1 + 0x3188),1);

    UpdateWindow(*(HWND *)(param_1 + 0x3188));

    local_8 = 1;

    iVar12 = FUN_007a3e90(*(uint32_t /* width from decompiler */ *)(param_1 + 0x3188),param_1 + 0xa18,

                          *(char *)(param_1 + 0x9c1) == '\0',*(uint8_t *)(param_1 + 0x9c6),

                          "aa.bmp");

    if (iVar12 == 0) {

      pcVar13 = "Failed to initialize the RenderEngine!";

    }

    else {

      if (iVar12 == 2) {

        uVar6 = (uint)*(ushort *)(param_1 + 0xa14);

        local_40 = DAT_00d1a830 + uVar6 * 0xc;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x3194) = *(uint32_t /* width from decompiler */ *)(local_40 + 4);

        local_34 = (LONG *)(DAT_00d1a830 + uVar6 * 0xc);

        lpRect->left = *local_34;

        local_3c = DAT_00d1a830 + uVar6 * 0xc;

        *(int *)(param_1 + 0x319c) = *(int *)(local_3c + 4) + *(int *)(param_1 + 0xa1c);

        local_38 = (int *)(DAT_00d1a830 + uVar6 * 0xc);

        *(int *)(param_1 + 0x3198) = *local_38 + *(int *)(param_1 + 0xa18);

        SetWindowPos(*(HWND *)(param_1 + 0x3188),(HWND)0x0,lpRect->left,*(int *)(param_1 + 0x3194),

                     *(int *)(param_1 + 0xa18),*(int *)(param_1 + 0xa1c),6);

        UpdateWindow(*(HWND *)(param_1 + 0x3188));

      }

      local_8 = 0xffffffff;

      *(int *)(param_1 + 0x31b0) = (*(int *)(param_1 + 0x3198) - lpRect->left) / 2 + lpRect->left;

      *(int *)(param_1 + 0x31b4) =

           (*(int *)(param_1 + 0x319c) - *(int *)(param_1 + 0x3194)) / 2 +

           *(int *)(param_1 + 0x3194);

      if (DAT_00d1f050 != 0) {

        local_2c = 0;

        local_28 = 0;

        local_24 = 0;

        local_20 = 0;

        local_8._0_1_ = 3;

        local_8._1_3_ = 0;

        FUN_0043c5f0(local_30);

        for (uVar6 = local_24; uVar6 != local_20 + local_24; uVar6 = uVar6 + 1) {

          pvVar9 = operator_new(4);

          local_8._0_1_ = 4;

          if (pvVar9 == (void *)0x0) {

            local_1c = 0;

          }

          else {

            local_1c = FUN_0040af40(pvVar9);

          }

          local_8._0_1_ = 3;

          uVar11 = uVar6 >> 2;

          iVar12 = uVar11 * -4;

          if (local_28 <= uVar11) {

            uVar11 = uVar11 - local_28;

          }

          iVar12 = *(int *)(*(int *)(local_2c + uVar11 * 4) + (uVar6 + iVar12) * 4);

          puVar2 = *(uint32_t /* width from decompiler */ **)(iVar12 + 4);

          if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

            *puVar2 = &PTR_LAB_00a2c238;

                    /* WARNING: Subroutine does not return */

            operator_delete(puVar2);

          }

          *(uint32_t /* width from decompiler */ *)(iVar12 + 4) = local_1c;

        }

        local_8 = 0xffffffff;

        FUN_0040d9c0();

      }

      cVar3 = *(char *)(param_1 + 0xa0d);

      if ((*(char *)(param_1 + 0x11) != '\0') && (cVar3 == '\0')) {

        cVar3 = '\x01';

      }

      *(char *)(param_1 + 0xa0d) = cVar3;

      if ((*(int **)(param_1 + 0xf40) == (int *)0x0) ||

         (**(int **)(param_1 + 0xf40) != *(int *)(param_1 + 0xf38))) {

        *(bool *)(param_1 + 0xb5) = *(char *)(param_1 + 0x11) != '\0';

      }

      else {

        *(char *)(param_1 + 0xb5) = cVar3;

      }

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe04) + 0xe89c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xde8);

      FUN_004cda90();

      DAT_00b03510 = DAT_00d09874;

      *(uint8_t *)(*(int *)(*(int *)(param_1 + 0xe04) + 0xe898) + 0x4f) = 0;

      *(uint8_t *)(*(int *)(*(int *)(param_1 + 0xe04) + 0xe898) + 0x4e) = 0;

      if (*(int *)(*(int *)(param_1 + 0xde8) + 0x2c) != 0) {

        FUN_007a2fd0();

        FUN_007ae400();

        DAT_00d17948 = param_1 + 0x3020;

        FUN_007b1900();

        FUN_00581580(*(uint32_t /* width from decompiler */ *)(param_1 + 0xde8),DAT_00d09874);

        FUN_00583170();

        FUN_00491ed0();

        FUN_0048eaa0(1);

        FUN_0048eef0(1);

        if (*(char *)(param_1 + 0x9ce) != '\0') {

          FUN_0092f190(1);

        }

        FUN_0092f140(0x5a);

        if (*(char *)(param_1 + 0x9dd) != '\0') {

          FUN_00935fe0();

        }

        ExceptionList = local_10;

        return 0;

      }

      pcVar13 = "Could not get Palantir desktop window.";

    }

  }

  FUN_007a4480(1,pcVar13);

  ExceptionList = local_10;

  return 0x80004005;

}
