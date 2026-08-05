// READABILITY (auto CF):
//  - Body size: ~437 non-empty decompiler lines.
//  - Control keywords: if×48, do×12, while×12, return×6, goto×3, for×3.
//  - Notable callees: FUN_007a6de0×11, FUN_008aab00×2, sprintf×2, CNDHash_LookupByKey, CONCAT22, FUN_0051f940, FUN_0052a0d0, FUN_005465c0.
//  - Strings: "Set Active"; "Set Active For Entire Convoy"; "  [Complete]"; "[%d] %s".
//  - Return sites: 6.

// =============================================================================
// Mission_Client_BuildMissionDetailPanel
// -----------------------------------------------------------------------------
// Purpose:  Populate mission detail UI panel: status (in progress / Complete), description, Rewards section, and actions 'Set Active' / 'Set Active For Entire Convoy'. Resolves mission objects and reward item display rows.
//
// Address:  0x008a3510  (autoassault.exe, image base 0x400000)
// Stable:   aa_008a3510
// System:   missions-progression
//
// Evidence strings (from raw decompile):
//   - "Set Active"
//   - "Set Active For Entire Convoy"
//   - "  [Complete]"
//   - "Status:   "
//   - "(in progress)"
//   - "Description:"
//   - "Rewards: "
//
// Notable callees:
//   - Client_LookupObjectByTfid_Inferred
//   - FUN_008a2020 / FUN_008aab00 / FUN_008ab9b0
//   - FUN_005465c0 / FUN_0052a0d0 / FUN_0051f940
//   - CNDHash_LookupByKey
//   - FUN_00853020 / FUN_008532d0 / FUN_00852c10
//   - sprintf
//
// Notes:    __thiscall panel object + mission id/row pointer.
//
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime / differential verification: OPEN.
// Human rename: 2026-07-23 (string-driven + manual plate).
// =============================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall Mission_Client_BuildMissionDetailPanel(int param_1,int *param_2)



{

  short sVar1;

  int *piVar2;

  ushort uVar3;

  char cVar4;

  uint32_t /* width from decompiler */ uVar5;

  void *pvVar6;

  char *pcVar7;

  ushort *puVar8;

  uint *puVar9;

  int iVar10;

  int iVar11;

  uint uVar12;

  char *pcVar13;

  char *pcVar14;

  uint32_t /* width from decompiler */ *puVar15;

  char *pcVar16;

  uint32_t /* width from decompiler */ uVar17;

  uint32_t /* width from decompiler */ uVar18;

  int iStack_d54;

  uint8_t auStack_d50 [4];

  uint32_t /* width from decompiler */ local_d4c;

  void *pvStack_d48;

  uint8_t auStack_d44 [8];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_d3c [27];

  char cStack_d21;

  char acStack_d20 [4];

  char acStack_d1c [8];

  char acStack_d14 [4];

  char acStack_d10 [2];

  char cStack_d0e;

  char acStack_c24 [8];

  char acStack_c1c [4];

  ushort uStack_c18;

  uint32_t /* width from decompiler */ auStack_c16 [511];

  char cStack_419;

  char acStack_418 [1004];

  void *pvStack_2c;

  void *pvStack_20;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009b3990;

  pvStack_14 = ExceptionList;

  if ((((param_2 == (int *)0x0) || (DAT_00d1b6d8 == (void *)0x0)) || (param_2[0x141] == 0)) ||

     (*(int *)(param_2[0x141] + 0x14c) == 0)) {

    ExceptionList = &pvStack_14;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x518) = 0xffffffff;

    if (*(int **)(param_1 + 0x578) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x578) + 4))();

    }

    if (*(int **)(param_1 + 0x574) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x574) + 4))();

    }

    if (*(int **)(param_1 + 0x570) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x570) + 4))();

    }

    if (*(int **)(param_1 + 0x57c) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x57c) + 4))();

    }

    if (*(int **)(param_1 + 0x580) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x580) + 4))();

    }

    if (*(int **)(param_1 + 0x584) == (int *)0x0) {

      ExceptionList = pvStack_14;

      return;

    }

    (**(code **)(**(int **)(param_1 + 0x584) + 4))();

    ExceptionList = pvStack_14;

    return;

  }

  ExceptionList = &pvStack_14;

  local_d4c = FUN_007a69d0();

  uVar5 = (**(code **)(*param_2 + 0x78))();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x518) = uVar5;

  pvStack_d48 = DAT_00d1b6d8;

  if (*(int *)(param_1 + 0x50c) == 2) {

    pvStack_d48 = Client_LookupObjectByTfid_Inferred

                            (1,*(uint *)(param_1 + 0x510),*(uint *)(param_1 + 0x514));

  }

  if (*(int **)(param_1 + 0x578) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x578) + 4))();

  }

  if (*(int **)(param_1 + 0x574) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x574) + 4))();

  }

  if (*(int **)(param_1 + 0x570) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x570) + 4))();

  }

  piVar2 = *(int **)(param_1 + 0x57c);

  if (*(int *)(param_1 + 0x50c) == 0) {

    if (piVar2 != (int *)0x0) {

      (**(code **)(*piVar2 + 4))();

    }

    if (*(int **)(param_1 + 0x580) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x580) + 4))();

    }

    piVar2 = *(int **)(param_1 + 0x584);

joined_r0x008a367c:

    if (piVar2 != (int *)0x0) {

      (**(code **)(*piVar2 + 4))();

    }

  }

  else {

    if (*(int *)(param_1 + 0x50c) != 1) {

      if (piVar2 != (int *)0x0) {

        (**(code **)(*piVar2 + 4))();

      }

      if (*(int **)(param_1 + 0x580) != (int *)0x0) {

        (**(code **)(**(int **)(param_1 + 0x580) + 4))();

      }

      piVar2 = *(int **)(param_1 + 0x584);

      goto joined_r0x008a367c;

    }

    if (piVar2 != (int *)0x0) {

      (**(code **)(*piVar2 + 4))();

    }

    if (*(int **)(param_1 + 0x580) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x580) + 4))();

    }

    if (*(int **)(param_1 + 0x584) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x584) + 4))();

    }

  }

  if (*(int *)(param_1 + 0x580) != 0) {

    if (((DAT_00d1b6d8 == (void *)0x0) || (*(int *)((int)DAT_00d1b6d8 + 0xcb0) == 0)) ||

       (pvVar6 = (void *)FUN_00574880(), pvVar6 != DAT_00d1b6d8)) {

      (**(code **)(**(int **)(param_1 + 0x580) + 0x1d8))("Set Active",1);

    }

    else {

      (**(code **)(**(int **)(param_1 + 0x580) + 0x1d8))("Set Active For Entire Convoy",1);

    }

    (**(code **)(**(int **)(param_1 + 0x580) + 0x34c))();

  }

  iVar10 = *(int *)(param_1 + 0x578);

  if (iVar10 == 0) {

    ExceptionList = pvStack_14;

    return;

  }

  uStack_c18 = 0;

  puVar15 = auStack_c16;

  for (iVar11 = 0x1ff; iVar11 != 0; iVar11 = iVar11 + -1) {

    *puVar15 = 0;

    puVar15 = puVar15 + 1;

  }

  *(uint16_t *)puVar15 = 0;

  if (*(int *)(iVar10 + 0x500) == 0) goto LAB_008a396a;

  acStack_d1c[0] = s_i_d_q_2d_wnd_icon__00a4cb98[4];

  acStack_d1c[1] = s_i_d_q_2d_wnd_icon__00a4cb98[5];

  acStack_d1c[2] = s_i_d_q_2d_wnd_icon__00a4cb98[6];

  acStack_d1c[3] = s_i_d_q_2d_wnd_icon__00a4cb98[7];

  acStack_d14[0] = s_i_d_q_2d_wnd_icon__00a4cb98[0xc];

  acStack_d14[1] = s_i_d_q_2d_wnd_icon__00a4cb98[0xd];

  acStack_d14[2] = s_i_d_q_2d_wnd_icon__00a4cb98[0xe];

  acStack_d14[3] = s_i_d_q_2d_wnd_icon__00a4cb98[0xf];

  acStack_d20[0] = s_i_d_q_2d_wnd_icon__00a4cb98[0];

  acStack_d20[1] = s_i_d_q_2d_wnd_icon__00a4cb98[1];

  acStack_d20[2] = s_i_d_q_2d_wnd_icon__00a4cb98[2];

  acStack_d20[3] = s_i_d_q_2d_wnd_icon__00a4cb98[3];

  cStack_d0e = s_i_d_q_2d_wnd_icon__00a4cb98[0x12];

  acStack_d1c[4] = s_i_d_q_2d_wnd_icon__00a4cb98[8];

  acStack_d1c[5] = s_i_d_q_2d_wnd_icon__00a4cb98[9];

  acStack_d1c[6] = s_i_d_q_2d_wnd_icon__00a4cb98[10];

  acStack_d1c[7] = s_i_d_q_2d_wnd_icon__00a4cb98[0xb];

  acStack_d10[0] = s_i_d_q_2d_wnd_icon__00a4cb98[0x10];

  acStack_d10[1] = s_i_d_q_2d_wnd_icon__00a4cb98[0x11];

  if ((char)param_2[0x140] == '\x02') {

    pcVar13 = &cStack_d21;

    do {

      pcVar7 = pcVar13;

      pcVar13 = pcVar7 + 1;

    } while (pcVar7[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 1) = DAT_00a4cb90;

    pcVar7[5] = DAT_00a4cb94;

LAB_008a382f:

    (**(code **)(**(int **)(iVar10 + 0x500) + 0x308))();

  }

  else if ((char)param_2[0x140] == '\x01') {

    pcVar13 = &cStack_d21;

    if (*(char *)(*(int *)(param_2[0x141] + 0x14c) + 0x169) == '\0') {

      if (*(short *)(*(int *)(param_2[0x141] + 0x14c) + 0xac) == -1) {

        do {

          pcVar7 = pcVar13;

          pcVar13 = pcVar7 + 1;

        } while (pcVar7[1] != '\0');

        *(uint32_t /* width from decompiler */ *)(pcVar7 + 1) = s_repeat_00a4cb18._0_4_;

        *(uint16_t *)(pcVar7 + 5) = s_repeat_00a4cb18._4_2_;

        pcVar7[7] = s_repeat_00a4cb18[6];

      }

      else {

        do {

          pcVar7 = pcVar13;

          pcVar13 = pcVar7 + 1;

        } while (pcVar7[1] != '\0');

        *(uint32_t /* width from decompiler */ *)(pcVar7 + 1) = DAT_00a4cb90;

        pcVar7[5] = DAT_00a4cb94;

      }

    }

    else {

      do {

        pcVar7 = pcVar13;

        pcVar13 = pcVar7 + 1;

      } while (pcVar7[1] != '\0');

      *(uint32_t /* width from decompiler */ *)(pcVar7 + 1) = s_story_00a4cb6c._0_4_;

      *(uint16_t *)(pcVar7 + 5) = s_story_00a4cb6c._4_2_;

    }

    goto LAB_008a382f;

  }

  if ((*(int *)(param_1 + 0x50c) == 0) && (cVar4 = FUN_008a2020(), cVar4 != '\0')) {

    pcVar13 = &cStack_d21;

    do {

      pcVar7 = pcVar13;

      pcVar13 = pcVar7 + 1;

    } while (pcVar7[1] != '\0');

    iVar10 = *(int *)(param_1 + 0x578);

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 1) = s__done_00a4cac4._0_4_;

    *(uint16_t *)(pcVar7 + 5) = s__done_00a4cac4._4_2_;

    uVar5 = (**(code **)(**(int **)(iVar10 + 0x500) + 0x30c))();

    pcVar7 = (char *)FUN_007a6de0(uVar5);

    pcVar13 = acStack_418;

    do {

      cVar4 = *pcVar7;

      *pcVar13 = cVar4;

      pcVar7 = pcVar7 + 1;

      pcVar13 = pcVar13 + 1;

    } while (cVar4 != '\0');

    pcVar7 = (char *)FUN_007a6de0("  [Complete]");

    pcVar13 = pcVar7;

    do {

      cVar4 = *pcVar13;

      pcVar13 = pcVar13 + 1;

    } while (cVar4 != '\0');

    pcVar16 = &cStack_419;

    do {

      pcVar14 = pcVar16 + 1;

      pcVar16 = pcVar16 + 1;

    } while (*pcVar14 != '\0');

    pcVar14 = pcVar7;

    for (uVar12 = (uint)((int)pcVar13 - (int)pcVar7) >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar16 = *(uint32_t /* width from decompiler */ *)pcVar14;

      pcVar14 = pcVar14 + 4;

      pcVar16 = pcVar16 + 4;

    }

    for (uVar12 = (int)pcVar13 - (int)pcVar7 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {

      *pcVar16 = *pcVar14;

      pcVar14 = pcVar14 + 1;

      pcVar16 = pcVar16 + 1;

    }

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x500) + 0x308))();

  }

  pcVar13 = &cStack_d21;

  do {

    pcVar7 = pcVar13;

    pcVar13 = pcVar7 + 1;

  } while (pcVar7[1] != '\0');

  iVar10 = *(int *)(param_1 + 0x578);

  *(uint32_t /* width from decompiler */ *)(pcVar7 + 1) = DAT_00a2c53c;

  pcVar7[5] = DAT_00a2c540;

  piVar2 = *(int **)(iVar10 + 0x500);

  iVar10 = *piVar2;

  uVar5 = (**(code **)(*piVar2 + 0x2c8))();

  (**(code **)(iVar10 + 0x50))(acStack_d20,uVar5);

LAB_008a396a:

  if (*(int *)(*(int *)(param_1 + 0x578) + 0x504) != 0) {

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x504) + 0x268))();

    sVar1 = *(short *)(*(int *)(param_2[0x141] + 0x14c) + 0x11c);

    FUN_007a6de0(*(uint32_t /* width from decompiler */ *)(*(int *)(param_2[0x141] + 0x14c) + 0x14c));

    sprintf((char *)&uStack_c18,"[%d] %s",(int)sVar1);

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x504) + 0x250))();

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x504) + 0x34c))();

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x504) + 0x140))(&pvStack_d48,1);

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x504) + 300))(&stack0xfffff2a0);

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x504) + 0x13c))();

  }

  if (*(int *)(*(int *)(param_1 + 0x578) + 0x510) != 0) {

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x510) + 0x34c))();

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x510) + 0x268))();

    sVar1 = *(short *)(*(int *)(param_2[0x141] + 0x14c) + 0x92);

    iStack_d54 = CONCAT22(iStack_d54._2_2_,sVar1);

    if (pvStack_d48 == (void *)0x0) {

      if (DAT_00d1b6d8 == (void *)0x0) {

        uVar12 = (uint)*(short *)(*(int *)(param_2[0x141] + 0x14c) + 0x90);

      }

      else {

        uVar12 = (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) +

                                                   0xac + (int)DAT_00d1b6d8) + 0x3c) + 0x532);

      }

    }

    else {

      uVar12 = (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)((int)pvStack_d48 + 4) + 4) + 0xac

                                                + (int)pvStack_d48) + 0x3c) + 0x532);

    }

    if ((-1 < sVar1) && (-1 < (int)uVar12)) {

      FUN_007a6de0(&DAT_00a4caac);

      uVar18 = 0xffffffff;

      uVar5 = FUN_0051f940((int)sVar1,uVar12,0xffffffff);

      uVar5 = FUN_007a6de0(uVar5,uVar18);

      sprintf((char *)&uStack_c18,"(%s %s)",uVar5);

      (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x510) + 0x250))();

    }

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x504) + 0x140))(auStack_d44);

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x510) + 300))(&stack0xfffff2a4);

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x510) + 0x13c))();

  }

  if (*(int *)(*(int *)(param_1 + 0x578) + 0x508) != 0) {

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x508) + 0x268))();

    if (*(int *)param_2[0x141] != 0) {

      (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x508) + 0x250))();

      pcVar7 = (char *)FUN_007a6de0(*(uint32_t /* width from decompiler */ *)param_2[0x141],0xffffffff);

      pcVar13 = acStack_c1c;

      do {

        cVar4 = *pcVar7;

        *pcVar13 = cVar4;

        pcVar7 = pcVar7 + 1;

        pcVar13 = pcVar13 + 1;

      } while (cVar4 != '\0');

      FUN_008aab00(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x578) + 0x508));

      (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x508) + 0x250))(&DAT_00a15104);

    }

    if (*(int *)(param_1 + 0x50c) == 0) {

      puVar8 = &uStack_c18;

      uStack_c18 = uStack_c18 & 0xff00;

      do {

        uVar3 = *puVar8;

        puVar8 = (ushort *)((int)puVar8 + 1);

      } while ((char)uVar3 != '\0');

      FUN_0052a0d0(param_2[0x141],&uStack_c18);

      (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x508) + 0x250))();

      iVar10 = **(int **)(*(int *)(param_1 + 0x578) + 0x508);

      uVar18 = 0xffffffff;

      uVar5 = FUN_007a6de0("Status:  ",0xffffffff);

      (**(code **)(iVar10 + 0x224))(uVar5,uVar18);

      if (acStack_c24[0] == '\0') {

        pcVar7 = (char *)FUN_007a6de0("(in progress)",0xffffffff);

        pcVar13 = acStack_c24;

        do {

          cVar4 = *pcVar7;

          *pcVar13 = cVar4;

          pcVar7 = pcVar7 + 1;

          pcVar13 = pcVar13 + 1;

        } while (cVar4 != '\0');

      }

      (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x508) + 0x224))(acStack_c24,0xffffffff);

      (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x508) + 0x250))(&DAT_00a15104);

    }

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x508) + 0x134))();

    iStack_d54 = 0;

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x508) + 300))(&stack0xfffff2a8);

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x508) + 0x13c))();

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x508) + 0x34c))();

  }

  if (*(int *)(*(int *)(param_1 + 0x578) + 0x50c) != 0) {

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x50c) + 0x34c))();

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x50c) + 0x1d8))(0,1);

    if ((*(int *)(param_1 + 0x50c) != 1) && (iStack_d54 != 0)) {

      iVar10 = **(int **)(*(int *)(param_1 + 0x578) + 0x50c);

      uVar17 = 1;

      uVar18 = 1;

      uVar5 = FUN_007a6de0("Description:",0xffffffff);

      (**(code **)(iVar10 + 0x1d8))(uVar5,uVar18,uVar17);

    }

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x50c) + 0x134))(auStack_d50);

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x50c) + 300))(&stack0xfffff29c);

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x50c) + 0x13c))();

  }

  if (*(int *)(*(int *)(param_1 + 0x578) + 0x514) != 0) {

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x514) + 0x268))();

    if (((*(int *)(param_1 + 0x50c) != 1) && (pvStack_d48 != (void *)0x0)) &&

       (*(int *)(*(int *)(param_2[0x141] + 0x14c) + 0x150) != 0)) {

      pcVar13 = (char *)FUN_007a6de0(*(uint32_t /* width from decompiler */ *)(*(int *)(param_2[0x141] + 0x14c) + 0x150));

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                (abStack_d3c,pcVar13);

      uStack_c = 0;

      FUN_005465c0(pvStack_d48);

      FUN_008aab00();

      (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x514) + 0x250))();

      uStack_c = 0xffffffff;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_d3c);

    }

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x514) + 0x34c))();

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x514) + 0x134))();

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x514) + 300))(&stack0xfffff2a8);

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x514) + 0x13c))();

  }

  puVar9 = CNDHash_LookupByKey(*(void **)((int)DAT_00d1b6d8 + 0x530),

                               **(uint **)(param_2[0x141] + 0x14c));

  if (puVar9 == (uint *)0x0) {

    uVar5 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x578);

    uVar18 = 0;

  }

  else {

    uVar5 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x578);

    uVar18 = 4;

  }

  FUN_00853020(uVar5,uVar18);

  if (*(int *)(*(int *)(param_1 + 0x578) + 0x518) != 0) {

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x518) + 0x268))();

    iVar10 = **(int **)(*(int *)(param_1 + 0x578) + 0x518);

    FUN_007a6de0("Rewards: ");

    (**(code **)(iVar10 + 0x250))();

    cVar4 = FUN_008ab9b0(*(uint32_t /* width from decompiler */ *)(param_2[0x141] + 0x14c));

    if ((cVar4 == '\0') && ((puVar9 == (uint *)0x0 || ((*puVar9 & puVar9[1]) == 0xffffffff)))) {

      (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x518) + 0x268))();

    }

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x518) + 0x34c))();

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x518) + 0x134))(&pvStack_d48);

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x518) + 300))(&stack0xfffff2a4);

    (**(code **)(**(int **)(*(int *)(param_1 + 0x578) + 0x518) + 0x13c))();

  }

  FUN_008532d0();

  if (*(int *)(param_1 + 0x570) == 0) {

    ExceptionList = pvStack_14;

    return;

  }

  iVar10 = (**(code **)(**(int **)(param_1 + 0x578) + 0x140))(auStack_d44);

  iVar11 = FUN_00852c10();

  iVar11 = iVar11 - *(int *)(iVar10 + 4);

  if (0 < iVar11) {

    (**(code **)(**(int **)(param_1 + 0x570) + 0xd4))(1);

    (**(code **)(**(int **)(param_1 + 0x570) + 0x454))(0,0);

    (**(code **)(**(int **)(param_1 + 0x570) + 0x460))

              (g_flOne / ((float)iVar11 / (float)(int)((float)DAT_00d1e81c * _DAT_00aaab24) +

                         g_flOne));

    (**(code **)(**(int **)(param_1 + 0x570) + 0x34c))();

    ExceptionList = pvStack_2c;

    return;

  }

  (**(code **)(**(int **)(param_1 + 0x570) + 0xd4))(0);

  (**(code **)(**(int **)(param_1 + 0x570) + 0x34c))();

  ExceptionList = pvStack_20;

  return;

}
