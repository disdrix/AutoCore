// =============================================================================
// FUN_00891480
// -----------------------------------------------------------------------------
// Stable ID: aa_00891480
// Address:   0x00891480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00891480 @ 0x00891480
// Stable ID: aa_00891480
// Embedded strings (evidence for future rename):
//   - "i_w_util_wnd_title.xml"
//   - "i_w_util_wnd_text.xml"
//   - "i_w_util_wnd_timer.xml"
//   - "i_w_util_btn_close.xml"
//   - "i_w_util_wnd_gauge_progress.xml"
//   - "i_w_util_wnd_team_name_%i.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~273 non-empty decompiler lines.
//  - Control keywords: if×16, do×5, while×5, for×5, switch×1, return×1.
//  - Notable callees: FUN_007b5dd0×6, sprintf×4, FUN_0079c860×2, FUN_007f9160, FUN_00891480, FUN_0097ffa0, GetTickCount.
//  - Strings: "i_w_util_wnd_title.xml"; "i_w_util_wnd_text.xml"; "i_w_util_wnd_timer.xml"; "i_w_util_btn_close.xml".
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



void FUN_00891480(int *param_1)



{

  char cVar1;

  void *pvVar2;

  int iVar3;

  DWORD DVar4;

  int iVar5;

  char *pcVar6;

  uint uVar7;

  uint uVar8;

  int *piVar9;

  char *pcVar10;

  uint32_t /* width from decompiler */ *puVar11;

  float fVar12;

  uint8_t auStack_178 [2];

  uint8_t auStack_176 [2];

  char *pcStack_174;

  char acStack_150 [4];

  char acStack_14c [16];

  char acStack_13c [3];

  char cStack_139;

  char acStack_138 [8];

  char acStack_130 [18];

  uint32_t /* width from decompiler */ auStack_11e [55];

  uint32_t /* width from decompiler */ uStack_40;

  void *pvStack_2c;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b5b98;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  (**(code **)(*param_1 + 0x3b4))();

  (**(code **)(*param_1 + 0x3ac))();

  pvVar2 = operator_new(0x488);

  uStack_4 = 0;

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  uStack_4 = 0xffffffff;

  param_1[0x143] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x143] + 0x28))();

  (**(code **)(*(int *)param_1[0x143] + 0x74))();

  pcStack_174 = (char *)0x89152a;

  pcStack_174 = operator_new(0x488);

  uStack_10 = 1;

  if (pcStack_174 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    _auStack_178 = 0x891547;

    iVar3 = FUN_007b5dd0();

  }

  uStack_10 = 0xffffffff;

  param_1[0x144] = iVar3;

  pcStack_174 = (char *)0x891564;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_174 = "i_w_util_wnd_title.xml";

  _auStack_178 = 0x891574;

  (**(code **)(*(int *)param_1[0x144] + 0x28))();

  _auStack_178 = 1;

  (**(code **)(*(int *)param_1[0x144] + 0x1d8))(param_1[0x145],1);

  switch(param_1[0x16b]) {

  case 0:

    pcStack_174 = operator_new(0x488);

    uStack_24 = 5;

    if (pcStack_174 == (char *)0x0) {

      iVar3 = 0;

    }

    else {

      iVar3 = FUN_007b5dd0(pcStack_174,0);

    }

    uStack_24 = 0xffffffff;

    param_1[0x146] = iVar3;

    (**(code **)(*param_1 + 0xa8))(iVar3);

    (**(code **)(*(int *)param_1[0x146] + 0x28))("i_w_util_wnd_text.xml");

    (**(code **)(*(int *)param_1[0x146] + 0x1d8))(param_1[0x147],1,1);

    break;

  case 1:

    pcStack_174 = operator_new(0x488);

    uStack_24 = 3;

    if (pcStack_174 == (char *)0x0) {

      iVar3 = 0;

    }

    else {

      iVar3 = FUN_007b5dd0(pcStack_174,0);

    }

    uStack_24 = 0xffffffff;

    param_1[0x148] = iVar3;

    (**(code **)(*param_1 + 0xa8))(iVar3);

    (**(code **)(*(int *)param_1[0x148] + 0x28))("i_w_util_wnd_timer.xml");

    pvVar2 = operator_new(0x4cc);

    pvStack_2c = (void *)0x4;

    iVar3 = 0;

    if (pvVar2 != (void *)0x0) {

      iVar3 = FUN_0079c860();

    }

    pvStack_2c = (void *)0xffffffff;

    param_1[0x141] = iVar3;

    (**(code **)(*param_1 + 0xa8))(iVar3);

    (**(code **)(*(int *)param_1[0x141] + 0x28))("i_w_util_btn_close.xml");

    (**(code **)(*(int *)param_1[0x141] + 0x74))(40000);

    (**(code **)(*(int *)param_1[0x141] + 0xcc))(0);

    break;

  case 2:

    pcStack_174 = operator_new(0x4f8);

    uStack_24 = 2;

    if (pcStack_174 == (char *)0x0) {

      iVar3 = 0;

    }

    else {

      iVar3 = FUN_0097ffa0(pcStack_174);

    }

    uStack_24 = 0xffffffff;

    param_1[0x14c] = iVar3;

    (**(code **)(*param_1 + 0xa8))(iVar3);

    (**(code **)(*(int *)param_1[0x14c] + 0x28))("i_w_util_wnd_gauge_progress.xml");

    (**(code **)(*(int *)param_1[0x14c] + 0x15c))(1,param_1 + 0x14d);

    (**(code **)(*(int *)param_1[0x14c] + 0x15c))(0,param_1 + 0x14e);

    if ((float)param_1[0x150] == g_flZero) {

      (**(code **)(*(int *)param_1[0x14c] + 0x3b0))(param_1[0x14f]);

      (**(code **)(*(int *)param_1[0x14c] + 0x3b4))(0);

    }

    else {

      DVar4 = GetTickCount();

      fVar12 = (float)(int)(DVar4 - param_1[0x168]);

      if ((int)(DVar4 - param_1[0x168]) < 0) {

        fVar12 = fVar12 + _DAT_00aaa5dc;

      }

      fVar12 = (fVar12 * g_flMsToSeconds_Inferred) / (float)param_1[0x150];

      if (g_flOne < fVar12) {

        fVar12 = g_flOne;

      }

      (**(code **)(*(int *)param_1[0x14c] + 0x3b0))(fVar12);

      (**(code **)(*(int *)param_1[0x14c] + 0x3b4))(g_flOne / (float)param_1[0x150]);

    }

    (**(code **)(*(int *)param_1[0x14c] + 0x3ac))(0x3f800000);

    (**(code **)(*(int *)param_1[0x14c] + 0x34c))();

    break;

  case 3:

    pcStack_174 = (char *)0x0;

    iVar3 = 1;

    piVar9 = param_1 + 0x151;

    do {

      pvVar2 = operator_new(0x488);

      uStack_24 = 6;

      if (pvVar2 == (void *)0x0) {

        iVar5 = 0;

      }

      else {

        iVar5 = FUN_007b5dd0(pvVar2,0);

      }

      uStack_24 = 0xffffffff;

      *piVar9 = iVar5;

      (**(code **)(*param_1 + 0xa8))(iVar5);

      sprintf(acStack_130,"i_w_util_wnd_team_name_%i.xml",iVar3);

      (**(code **)(*(int *)*piVar9 + 0x28))(acStack_130);

      (**(code **)(*(int *)*piVar9 + 0x15c))(1,piVar9 + 9);

      pcVar6 = (char *)piVar9[0xd];

      if (pcVar6 == (char *)0x0) {

        sprintf(acStack_13c,"Team %i",iVar3 + -1);

        pcVar6 = acStack_13c;

      }

      (**(code **)(*(int *)*piVar9 + 0x1d8))(pcVar6,1,1);

      pvVar2 = operator_new(0x488);

      uStack_40 = 7;

      if (pvVar2 == (void *)0x0) {

        iVar5 = 0;

      }

      else {

        iVar5 = FUN_007b5dd0(pvVar2,0);

      }

      uStack_40 = 0xffffffff;

      piVar9[4] = iVar5;

      (**(code **)(*param_1 + 0xa8))(iVar5);

      sprintf(acStack_14c,"i_w_util_wnd_team_score_%i.xml",iVar3);

      (**(code **)(*(int *)piVar9[4] + 0x28))(acStack_14c);

      sprintf(acStack_150,"%d",piVar9[0x11]);

      (**(code **)(*(int *)piVar9[4] + 0x1d8))(acStack_150,1,1);

      if (*(ushort *)(param_1 + 0x166) <= (ushort)pcStack_174) {

        (**(code **)(*(int *)*piVar9 + 0xcc))(0);

        (**(code **)(*(int *)piVar9[4] + 0xcc))(0);

      }

      pcStack_174 = pcStack_174 + 1;

      piVar9 = piVar9 + 1;

      iVar3 = iVar3 + 1;

    } while ((ushort)pcStack_174 < 4);

    if ((DAT_00d1b644 != 0) && (*(char *)(DAT_00d1b644 + 0xf6) != '\0')) {

      pvVar2 = operator_new(0x4cc);

      uStack_24 = 8;

      iVar3 = 0;

      if (pvVar2 != (void *)0x0) {

        iVar3 = FUN_0079c860();

      }

      uStack_24 = 0xffffffff;

      param_1[0x159] = iVar3;

      (**(code **)(*param_1 + 0xa8))(iVar3);

      (**(code **)(*(int *)param_1[0x159] + 0x28))("i_w_util_btn_open_results.xml");

      (**(code **)(*(int *)param_1[0x159] + 0x74))(0x9c41);

      pcVar6 = "Open/Close the Scoreboard";

      pcVar10 = acStack_138;

      for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {

        *(uint32_t /* width from decompiler */ *)pcVar10 = *(uint32_t /* width from decompiler */ *)pcVar6;

        pcVar6 = pcVar6 + 4;

        pcVar10 = pcVar10 + 4;

      }

      *(uint16_t *)pcVar10 = *(uint16_t *)pcVar6;

      puVar11 = auStack_11e;

      for (iVar3 = 0x19; iVar3 != 0; iVar3 = iVar3 + -1) {

        *puVar11 = 0;

        puVar11 = puVar11 + 1;

      }

      *(uint16_t *)puVar11 = 0;

      _auStack_178 = _auStack_178 & 0xffff0000;

      puVar11 = (uint32_t /* width from decompiler */ *)(auStack_178 + 2);

      for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {

        *puVar11 = 0;

        puVar11 = puVar11 + 1;

      }

      *(uint16_t *)puVar11 = 0;

      cVar1 = FUN_007f9160(0x77,0);

      if (cVar1 != '\0') {

        pcVar6 = &cStack_139;

        do {

          pcVar10 = pcVar6;

          pcVar6 = pcVar10 + 1;

        } while (pcVar10[1] != '\0');

        *(uint16_t *)(pcVar10 + 1) = DAT_00a5238c;

        pcVar10[3] = DAT_00a5238e;

        pcVar6 = auStack_178;

        do {

          cVar1 = *pcVar6;

          pcVar6 = pcVar6 + 1;

        } while (cVar1 != '\0');

        uVar7 = (int)pcVar6 - (int)auStack_178;

        pcVar6 = &cStack_139;

        do {

          pcVar10 = pcVar6 + 1;

          pcVar6 = pcVar6 + 1;

        } while (*pcVar10 != '\0');

        pcVar10 = auStack_178;

        for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar6 = *(uint32_t /* width from decompiler */ *)pcVar10;

          pcVar10 = pcVar10 + 4;

          pcVar6 = pcVar6 + 4;

        }

        for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

          *pcVar6 = *pcVar10;

          pcVar10 = pcVar10 + 1;

          pcVar6 = pcVar6 + 1;

        }

        pcVar6 = &cStack_139;

        do {

          pcVar10 = pcVar6 + 1;

          pcVar6 = pcVar6 + 1;

        } while (*pcVar10 != '\0');

        *(uint16_t *)pcVar6 = DAT_00a3a4a0;

      }

      (**(code **)(*(int *)param_1[0x159] + 0x308))(acStack_138);

    }

  }

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvStack_2c;

  return;

}
