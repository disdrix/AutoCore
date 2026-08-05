// =============================================================================
// UI_icon_default
// -----------------------------------------------------------------------------
// Stable ID: aa_0082b990
// Address:   0x0082b990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_icon_default @ 0x0082b990
// Stable ID: aa_0082b990
// Embedded strings (evidence for future rename):
//   - "i_d_d_2d_wnd_icon_default.dds"
//   - "%i/%i"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~233 non-empty decompiler lines.
//  - Control keywords: if×15, do×9, while×9, return×7, for×5.
//  - Notable callees: FUN_0052ad60×2, FUN_00402d50, FUN_0052ada0, FUN_0052b040, FUN_0052b140, FUN_007b6730, FUN_007b6a20, UI_icon_default.
//  - Strings: "i_d_d_2d_wnd_icon_default.dds"; "%i/%i".
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_d_2d_wnd_icon_default.dds"
 * Domain alias of FUN_0082b990 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_icon_default(int *param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char *pcVar3;

  char *pcVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  uint uVar8;

  char *pcVar9;

  char *pcVar10;

  uint32_t /* width from decompiler */ *puVar11;

  uint8_t *puVar12;

  uint32_t /* width from decompiler */ uVar13;

  int iStack_448;

  uint8_t *puStack_438;

  char cStack_421;

  char local_420 [2];

  uint32_t /* width from decompiler */ auStack_41e [4];

  char local_40e [242];

  uint8_t auStack_31c [4];

  uint8_t local_318 [2];

  uint32_t /* width from decompiler */ uStack_316;

  void *pvStack_24;

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  puStack_438 = &stack0xfffffffc;

  local_c = 0xffffffff;

  puStack_10 = &LAB_009b02e8;

  local_14 = ExceptionList;

  iStack_448 = param_1[0x182];

  ExceptionList = &local_14;

  puVar12 = &stack0xfffffffc;

  if ((iStack_448 == -1) ||

     (ExceptionList = &local_14, cVar1 = FUN_0052b040(), puVar12 = puStack_438, cVar1 == '\0')) {

    puStack_438 = puVar12;

    iStack_448 = 0x82beb8;

    (**(code **)(*param_1 + 0xcc))();

    ExceptionList = local_14;

    return;

  }

  if (param_1[0x184] == 0) {

    ExceptionList = local_14;

    return;

  }

  if (param_1[0x185] == 0) {

    ExceptionList = local_14;

    return;

  }

  if (param_1[0x186] == 0) {

    ExceptionList = local_14;

    return;

  }

  if (param_1[0x187] == 0) {

    ExceptionList = local_14;

    return;

  }

  local_420[0] = '\0';

  local_420[1] = '\0';

  puVar2 = auStack_41e;

  for (iVar7 = 0x40; iVar7 != 0; iVar7 = iVar7 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  *(uint16_t *)puVar2 = 0;

  pcVar4 = &cStack_421;

  do {

    pcVar3 = pcVar4;

    pcVar4 = pcVar3 + 1;

  } while (pcVar3[1] != '\0');

  *(uint32_t /* width from decompiler */ *)(pcVar3 + 1) = s_i_d_d_2d_wnd_icon__00a73968._0_4_;

  *(uint32_t /* width from decompiler */ *)(pcVar3 + 5) = s_i_d_d_2d_wnd_icon__00a73968._4_4_;

  *(uint32_t /* width from decompiler */ *)(pcVar3 + 9) = s_i_d_d_2d_wnd_icon__00a73968._8_4_;

  *(uint32_t /* width from decompiler */ *)(pcVar3 + 0xd) = s_i_d_d_2d_wnd_icon__00a73968._12_4_;

  *(uint16_t *)(pcVar3 + 0x11) = s_i_d_d_2d_wnd_icon__00a73968._16_2_;

  pcVar3[0x13] = s_i_d_d_2d_wnd_icon__00a73968[0x12];

  iStack_448 = 0x82ba83;

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_00402d50();

  local_c = 0;

  pcVar4 = (char *)*puVar2;

  pcVar3 = pcVar4;

  do {

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  pcVar10 = &cStack_421;

  do {

    pcVar9 = pcVar10 + 1;

    pcVar10 = pcVar10 + 1;

  } while (*pcVar9 != '\0');

  pcVar9 = pcVar4;

  for (uVar8 = (uint)((int)pcVar3 - (int)pcVar4) >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar10 = *(uint32_t /* width from decompiler */ *)pcVar9;

    pcVar9 = pcVar9 + 4;

    pcVar10 = pcVar10 + 4;

  }

  for (uVar8 = (int)pcVar3 - (int)pcVar4 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

    *pcVar10 = *pcVar9;

    pcVar9 = pcVar9 + 1;

    pcVar10 = pcVar10 + 1;

  }

  local_c = 0xffffffff;

  if (_local_318 != (void *)((int)&uStack_316 + 2)) {

    iStack_448 = 0x82bae0;

    free(_local_318);

  }

  pcVar4 = local_420;

  do {

    cVar1 = *pcVar4;

    pcVar4 = pcVar4 + 1;

  } while (cVar1 != '\0');

  uVar8 = 0;

  if (pcVar4 != local_420 + 1) {

    do {

      if (*(char *)((int)auStack_41e + (uVar8 - 2)) == ' ') {

        *(uint8_t *)((int)auStack_41e + (uVar8 - 2)) = 0x5f;

      }

      uVar8 = uVar8 + 1;

    } while (uVar8 < (uint)((int)pcVar4 - (int)(local_420 + 1)));

  }

  iStack_448 = 0;

  (**(code **)(*(int *)param_1[0x184] + 0x15c))();

  cVar1 = FUN_0052b140();

  if (cVar1 == '\0') {

    (**(code **)(*(int *)param_1[0x186] + 4))();

    (**(code **)(*(int *)param_1[0x186] + 0x15c))(0,&stack0xfffffbc4);

    (**(code **)(*(int *)param_1[0x184] + 0x15c))(0,&stack0xfffffbbc);

    puVar2 = (uint32_t /* width from decompiler */ *)&stack0xfffffbc3;

    do {

      puVar11 = puVar2;

      puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar11 + 1);

    } while (*(char *)((int)puVar11 + 1) != '\0');

    *(uint32_t /* width from decompiler */ *)((int)puVar11 + 1) = DAT_00a73960;

    puVar2 = (uint32_t /* width from decompiler */ *)&stack0xfffffbb4;

    *(uint8_t *)((int)puVar11 + 5) = DAT_00a73964;

  }

  else {

    iVar7 = FUN_0052ad60();

    if (iVar7 == 0) {

      (**(code **)(*(int *)param_1[0x186] + 4))();

      (**(code **)(*(int *)param_1[0x186] + 0x15c))(0,&stack0xfffffbc4);

      (**(code **)(*(int *)param_1[0x184] + 0x15c))(0,&stack0xfffffbbc);

      puVar2 = (uint32_t /* width from decompiler */ *)&stack0xfffffbc3;

      do {

        puVar11 = puVar2;

        puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar11 + 1);

      } while (*(char *)((int)puVar11 + 1) != '\0');

      *(uint32_t /* width from decompiler */ *)((int)puVar11 + 1) = DAT_00a73960;

      *(uint8_t *)((int)puVar11 + 5) = DAT_00a73964;

    }

    else {

      (**(code **)(*(int *)param_1[0x186] + 4))();

      (**(code **)(*(int *)param_1[0x186] + 0x15c))(0,&stack0xfffffbc4);

      (**(code **)(*(int *)param_1[0x184] + 0x15c))(0,&stack0xfffffbbc);

      puVar2 = (uint32_t /* width from decompiler */ *)&stack0xfffffbc3;

      do {

        pcVar4 = (char *)((int)puVar2 + 1);

        puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar2 + 1);

      } while (*pcVar4 != '\0');

      *puVar2 = DAT_00a540cc;

    }

    puVar2 = &DAT_00afdf0c;

  }

  (**(code **)(*(int *)param_1[0x185] + 0x15c))(0,puVar2);

  puVar2 = (uint32_t /* width from decompiler */ *)((int)&iStack_448 + 3);

  do {

    puVar11 = puVar2;

    puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar11 + 1);

  } while (*(char *)((int)puVar11 + 1) != '\0');

  puVar12 = &stack0xfffffbbc;

  *(uint32_t /* width from decompiler */ *)((int)puVar11 + 1) = DAT_00a2c53c;

  uVar13 = 0xffffffff;

  *(uint8_t *)((int)puVar11 + 5) = DAT_00a2c540;

  FUN_007b6a20(puVar12,0xffffffff);

  cVar1 = FUN_007b6730(puVar12,uVar13);

  if (cVar1 == '\0') {

    pcVar4 = "i_d_d_2d_wnd_icon_default.dds";

    puVar2 = (uint32_t /* width from decompiler */ *)&stack0xfffffbbc;

    for (iVar7 = 7; iVar7 != 0; iVar7 = iVar7 + -1) {

      *puVar2 = *(uint32_t /* width from decompiler */ *)pcVar4;

      pcVar4 = pcVar4 + 4;

      puVar2 = puVar2 + 1;

    }

    *(uint16_t *)puVar2 = *(uint16_t *)pcVar4;

  }

  iVar7 = *(int *)param_1[0x185];

  uVar13 = (**(code **)(*(int *)param_1[0x185] + 0x2c8))(0);

  (**(code **)(iVar7 + 0x50))(&stack0xfffffbbc,uVar13);

  if (DAT_00d1b6d8 == 0) {

    ExceptionList = local_14;

    return;

  }

  _local_318 = (void *)((uint)(ushort)uStack_316 << 0x10);

  puVar2 = (uint32_t /* width from decompiler */ *)(local_318 + 2);

  for (iVar7 = 0x3f; iVar7 != 0; iVar7 = iVar7 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  *(uint16_t *)puVar2 = 0;

  iStack_448 = 0x82bd9e;

  iVar7 = FUN_0052ad60();

  iStack_448 = 0x82bdb2;

  iVar5 = FUN_0052ada0();

  if (iVar7 < 1) {

    _local_318 = (void *)0x302f30;

    iStack_448 = 0x82bdf7;

    (**(code **)(*(int *)param_1[0x187] + 4))();

  }

  else {

    iStack_448 = iVar5;

    sprintf(local_318,"%i/%i");

    iStack_448 = 0x82bddd;

    (**(code **)(*(int *)param_1[0x187] + 4))();

  }

  iStack_448 = 1;

  (**(code **)(*(int *)param_1[0x187] + 0x1d8))(auStack_31c);

  (**(code **)(*(int *)param_1[0x187] + 0x94))();

  if (param_1[0x188] != 0) {

    piVar6 = (int *)(**(code **)(*(int *)param_1[0x188] + 0x140))(&puStack_438,1);

    if (iVar7 < 1) {

      iStack_448 = 0;

    }

    else {

      iStack_448 = (int)(((float)*piVar6 * (float)iVar5) / (float)iVar7);

    }

    (**(code **)(*(int *)param_1[0x188] + 300))(&iStack_448);

  }

  (**(code **)(*(int *)param_1[0x187] + 0x34c))();

  ExceptionList = pvStack_24;

  return;

}
