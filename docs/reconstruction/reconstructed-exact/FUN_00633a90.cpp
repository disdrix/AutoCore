// =============================================================================
// FUN_00633a90
// -----------------------------------------------------------------------------
// Stable ID: aa_00633a90
// Address:   0x00633a90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00633a90 @ 0x00633a90
// Stable ID: aa_00633a90
// Embedded strings (evidence for future rename):
//   - "_WinMain@16"
//   - "WinMain(HINSTANCE,HINSTANCE,LPCTSTR,int)"
//   - "_main"
//   - "_mainCRTStartup"
//   - "_wmain"
//   - "wmain(int,TCHAR * *,TCHAR * *)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~316 non-empty decompiler lines.
//  - Control keywords: do×15, while×15, if×14, for×11, return×2.
//  - Notable callees: strchr×3, GlobalFree×2, sprintf×2, strstr×2, FUN_00633a90, GetCurrentProcess, GlobalAlloc, SymGetSymFromAddr.
//  - Strings: "_WinMain@16"; "WinMain(HINSTANCE,HINSTANCE,LPCTSTR,int)"; "_main"; "_mainCRTStartup".
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

uint32_t /* width from decompiler */ FUN_00633a90(uint32_t /* width from decompiler */ param_1,int param_2,char *param_3)



{

  char cVar1;

  uint32_t /* width from decompiler */ *hMem;

  HANDLE pvVar2;

  char *pcVar3;

  char *pcVar4;

  int iVar5;

  uint uVar6;

  char *pcVar7;

  char *pcVar8;

  uint32_t /* width from decompiler */ *puVar9;

  char *pcVar10;

  bool bVar11;

  uint32_t /* width from decompiler */ *puVar12;

  int local_41c;

  uint32_t /* width from decompiler */ *local_414;

  uint32_t /* width from decompiler */ local_410;

  uint32_t /* width from decompiler */ *local_40c;

  uint8_t local_408 [2];

  uint32_t /* width from decompiler */ uStack_406;

  char cStack_402;

  char cStack_401;

  char local_400 [4];

  char local_3fc [4];

  char local_3f8 [496];

  char local_208 [2];

  uint32_t /* width from decompiler */ local_206 [128];

  

  local_408 = (uint8_t  [2])0x3f;

  puVar9 = (uint32_t /* width from decompiler */ *)(local_408 + 2);

  for (iVar5 = 0x7f; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar9 = 0;

    puVar9 = puVar9 + 1;

  }

  *(uint16_t *)puVar9 = 0;

  local_208[0] = '?';

  local_208[1] = '\0';

  puVar9 = local_206;

  for (iVar5 = 0x7f; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar9 = 0;

    puVar9 = puVar9 + 1;

  }

  local_410 = 0;

  *(uint16_t *)puVar9 = 0;

  pcVar7 = local_408;

  hMem = GlobalAlloc(0,10000);

  puVar9 = hMem;

  for (iVar5 = 0x9c4; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar9 = 0;

    puVar9 = puVar9 + 1;

  }

  puVar9 = &local_410;

  *hMem = 10000;

  hMem[4] = 0x26f8;

  param_3[0] = '?';

  param_3[1] = '\0';

  puVar12 = hMem;

  local_40c = hMem;

  pvVar2 = GetCurrentProcess();

  iVar5 = SymGetSymFromAddr(pvVar2,param_1,puVar9,puVar12);

  if (iVar5 == 0) {

    GlobalFree(hMem);

    return 0;

  }

  UnDecorateSymbolName(hMem + 5,local_208,0x200,0x42e2);

  iVar5 = 0;

  do {

    cVar1 = *(char *)((int)local_206 + iVar5 + -2);

    local_408[iVar5] = cVar1;

    iVar5 = iVar5 + 1;

  } while (cVar1 != '\0');

  iVar5 = 0xc;

  bVar11 = true;

  pcVar4 = local_408;

  pcVar3 = "_WinMain@16";

  do {

    if (iVar5 == 0) break;

    iVar5 = iVar5 + -1;

    bVar11 = *pcVar4 == *pcVar3;

    pcVar4 = pcVar4 + 1;

    pcVar3 = pcVar3 + 1;

  } while (bVar11);

  if (bVar11) {

    pcVar4 = "WinMain(HINSTANCE,HINSTANCE,LPCTSTR,int)";

    pcVar3 = local_408;

    for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {

      *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar4;

      pcVar4 = pcVar4 + 4;

      pcVar3 = pcVar3 + 4;

    }

    *pcVar3 = *pcVar4;

  }

  else {

    iVar5 = 6;

    bVar11 = true;

    pcVar4 = local_408;

    pcVar3 = "_main";

    do {

      if (iVar5 == 0) break;

      iVar5 = iVar5 + -1;

      bVar11 = *pcVar4 == *pcVar3;

      pcVar4 = pcVar4 + 1;

      pcVar3 = pcVar3 + 1;

    } while (bVar11);

    if (bVar11) {

      local_408[0] = s_main_int_TCHAR______009e36ac[0];

      local_408[1] = s_main_int_TCHAR______009e36ac[1];

      uStack_406._0_1_ = s_main_int_TCHAR______009e36ac[2];

      uStack_406._1_1_ = s_main_int_TCHAR______009e36ac[3];

      uStack_406._2_1_ = s_main_int_TCHAR______009e36ac[4];

      uStack_406._3_1_ = s_main_int_TCHAR______009e36ac[5];

      cStack_402 = s_main_int_TCHAR______009e36ac[6];

      cStack_401 = s_main_int_TCHAR______009e36ac[7];

      local_400[0] = s_main_int_TCHAR______009e36ac[8];

      local_400[1] = s_main_int_TCHAR______009e36ac[9];

      local_400[2] = s_main_int_TCHAR______009e36ac[10];

      local_400[3] = s_main_int_TCHAR______009e36ac[0xb];

      local_3fc[0] = s_main_int_TCHAR______009e36ac[0xc];

      local_3fc[1] = s_main_int_TCHAR______009e36ac[0xd];

      local_3fc[2] = s_main_int_TCHAR______009e36ac[0xe];

      local_3fc[3] = s_main_int_TCHAR______009e36ac[0xf];

      local_3f8[0] = s_main_int_TCHAR______009e36ac[0x10];

      local_3f8[1] = s_main_int_TCHAR______009e36ac[0x11];

      local_3f8[2] = s_main_int_TCHAR______009e36ac[0x12];

      local_3f8[3] = s_main_int_TCHAR______009e36ac[0x13];

    }

    else {

      iVar5 = 0x10;

      bVar11 = true;

      pcVar4 = local_408;

      pcVar3 = "_mainCRTStartup";

      do {

        if (iVar5 == 0) break;

        iVar5 = iVar5 + -1;

        bVar11 = *pcVar4 == *pcVar3;

        pcVar4 = pcVar4 + 1;

        pcVar3 = pcVar3 + 1;

      } while (bVar11);

      if (bVar11) {

        local_408[0] = s_mainCRTStartup___009e3688[0];

        local_408[1] = s_mainCRTStartup___009e3688[1];

        uStack_406._0_1_ = s_mainCRTStartup___009e3688[2];

        uStack_406._1_1_ = s_mainCRTStartup___009e3688[3];

        uStack_406._2_1_ = s_mainCRTStartup___009e3688[4];

        uStack_406._3_1_ = s_mainCRTStartup___009e3688[5];

        cStack_402 = s_mainCRTStartup___009e3688[6];

        cStack_401 = s_mainCRTStartup___009e3688[7];

        local_400[0] = s_mainCRTStartup___009e3688[8];

        local_400[1] = s_mainCRTStartup___009e3688[9];

        local_400[2] = s_mainCRTStartup___009e3688[10];

        local_400[3] = s_mainCRTStartup___009e3688[0xb];

        local_3fc[0] = s_mainCRTStartup___009e3688[0xc];

        local_3fc[1] = s_mainCRTStartup___009e3688[0xd];

        local_3fc[2] = s_mainCRTStartup___009e3688[0xe];

        local_3fc[3] = s_mainCRTStartup___009e3688[0xf];

        local_3f8[0] = s_mainCRTStartup___009e3688[0x10];

      }

      else {

        iVar5 = 7;

        bVar11 = true;

        pcVar4 = local_408;

        pcVar3 = "_wmain";

        do {

          if (iVar5 == 0) break;

          iVar5 = iVar5 + -1;

          bVar11 = *pcVar4 == *pcVar3;

          pcVar4 = pcVar4 + 1;

          pcVar3 = pcVar3 + 1;

        } while (bVar11);

        if (bVar11) {

          pcVar4 = "wmain(int,TCHAR * *,TCHAR * *)";

          puVar9 = (uint32_t /* width from decompiler */ *)local_408;

          for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {

            *puVar9 = *(uint32_t /* width from decompiler */ *)pcVar4;

            pcVar4 = pcVar4 + 4;

            puVar9 = puVar9 + 1;

          }

          *(uint16_t *)puVar9 = *(uint16_t *)pcVar4;

          *(char *)((int)puVar9 + 2) = pcVar4[2];

        }

        else {

          iVar5 = 0x11;

          bVar11 = true;

          pcVar4 = local_408;

          pcVar3 = "_wmainCRTStartup";

          do {

            if (iVar5 == 0) break;

            iVar5 = iVar5 + -1;

            bVar11 = *pcVar4 == *pcVar3;

            pcVar4 = pcVar4 + 1;

            pcVar3 = pcVar3 + 1;

          } while (bVar11);

          if (bVar11) {

            local_408[0] = s_wmainCRTStartup___009e3638[0];

            local_408[1] = s_wmainCRTStartup___009e3638[1];

            uStack_406._0_1_ = s_wmainCRTStartup___009e3638[2];

            uStack_406._1_1_ = s_wmainCRTStartup___009e3638[3];

            uStack_406._2_1_ = s_wmainCRTStartup___009e3638[4];

            uStack_406._3_1_ = s_wmainCRTStartup___009e3638[5];

            cStack_402 = s_wmainCRTStartup___009e3638[6];

            cStack_401 = s_wmainCRTStartup___009e3638[7];

            local_400[0] = s_wmainCRTStartup___009e3638[8];

            local_400[1] = s_wmainCRTStartup___009e3638[9];

            local_400[2] = s_wmainCRTStartup___009e3638[10];

            local_400[3] = s_wmainCRTStartup___009e3638[0xb];

            local_3fc[0] = s_wmainCRTStartup___009e3638[0xc];

            local_3fc[1] = s_wmainCRTStartup___009e3638[0xd];

            local_3fc[2] = s_wmainCRTStartup___009e3638[0xe];

            local_3fc[3] = s_wmainCRTStartup___009e3638[0xf];

            local_3f8[0] = s_wmainCRTStartup___009e3638[0x10];

            local_3f8[1] = s_wmainCRTStartup___009e3638[0x11];

          }

        }

      }

    }

  }

  *param_3 = '\0';

  pcVar3 = strstr(local_408,"(void)");

  pcVar4 = pcVar7;

  if ((pcVar3 == (char *)0x0) && (pcVar3 = strstr(local_408,"()"), pcVar3 == (char *)0x0)) {

    pcVar4 = strchr(local_408,0x2c);

    local_41c = 0;

    if (pcVar4 != (char *)0x0) {

      local_414 = (uint32_t /* width from decompiler */ *)(param_2 + 8);

      local_41c = 0;

      do {

        *pcVar4 = '\0';

        pcVar3 = pcVar7;

        do {

          cVar1 = *pcVar3;

          pcVar3 = pcVar3 + 1;

        } while (cVar1 != '\0');

        pcVar10 = param_3 + -1;

        do {

          pcVar8 = pcVar10 + 1;

          pcVar10 = pcVar10 + 1;

        } while (*pcVar8 != '\0');

        pcVar8 = pcVar7;

        for (uVar6 = (uint)((int)pcVar3 - (int)pcVar7) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar10 = *(uint32_t /* width from decompiler */ *)pcVar8;

          pcVar8 = pcVar8 + 4;

          pcVar10 = pcVar10 + 4;

        }

        for (uVar6 = (int)pcVar3 - (int)pcVar7 & 3; pcVar7 = param_3, uVar6 != 0; uVar6 = uVar6 - 1)

        {

          *pcVar10 = *pcVar8;

          pcVar8 = pcVar8 + 1;

          pcVar10 = pcVar10 + 1;

        }

        do {

          pcVar3 = pcVar7;

          pcVar7 = pcVar3 + 1;

        } while (*pcVar3 != '\0');

        sprintf(pcVar3,"=0x%08X,",*local_414);

        local_41c = local_41c + 1;

        local_414 = local_414 + 1;

        pcVar7 = pcVar4 + 1;

        pcVar4 = strchr(pcVar7,0x2c);

      } while (pcVar4 != (char *)0x0);

    }

    pcVar3 = strchr(pcVar7,0x29);

    pcVar4 = pcVar7;

    if (pcVar3 != (char *)0x0) {

      *pcVar3 = '\0';

      do {

        cVar1 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      pcVar10 = param_3 + -1;

      do {

        pcVar8 = pcVar10 + 1;

        pcVar10 = pcVar10 + 1;

      } while (*pcVar8 != '\0');

      pcVar8 = pcVar7;

      for (uVar6 = (uint)((int)pcVar4 - (int)pcVar7) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar10 = *(uint32_t /* width from decompiler */ *)pcVar8;

        pcVar8 = pcVar8 + 4;

        pcVar10 = pcVar10 + 4;

      }

      for (uVar6 = (int)pcVar4 - (int)pcVar7 & 3; pcVar7 = param_3, uVar6 != 0; uVar6 = uVar6 - 1) {

        *pcVar10 = *pcVar8;

        pcVar8 = pcVar8 + 1;

        pcVar10 = pcVar10 + 1;

      }

      do {

        pcVar4 = pcVar7;

        pcVar7 = pcVar4 + 1;

      } while (*pcVar4 != '\0');

      sprintf(pcVar4,"=0x%08X)",*(uint32_t /* width from decompiler */ *)(param_2 + 8 + local_41c * 4));

      pcVar7 = pcVar3 + 1;

      pcVar4 = pcVar7;

    }

  }

  do {

    cVar1 = *pcVar7;

    pcVar7 = pcVar7 + 1;

  } while (cVar1 != '\0');

  param_3 = param_3 + -1;

  do {

    pcVar3 = param_3 + 1;

    param_3 = param_3 + 1;

  } while (*pcVar3 != '\0');

  pcVar3 = pcVar4;

  for (uVar6 = (uint)((int)pcVar7 - (int)pcVar4) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

    *(uint32_t /* width from decompiler */ *)param_3 = *(uint32_t /* width from decompiler */ *)pcVar3;

    pcVar3 = pcVar3 + 4;

    param_3 = param_3 + 4;

  }

  for (uVar6 = (int)pcVar7 - (int)pcVar4 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

    *param_3 = *pcVar3;

    pcVar3 = pcVar3 + 1;

    param_3 = param_3 + 1;

  }

  GlobalFree(local_40c);

  return 1;

}
