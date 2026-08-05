// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter_00826860
// -----------------------------------------------------------------------------
// Stable ID: aa_00826860
// Callee of Named_CalleeOf_Client_RecvCreateCharacter
// Address:   0x00826860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvCreateCharacter: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~132 non-empty decompiler lines.
//  - Control keywords: if×8, do×5, while×5, return×2, for×2.
//  - Notable callees: FUN_00826780, FUN_00826860.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvCreateCharacter
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter_00826860(int *param_1)



{

  char *pcVar1;

  char cVar2;

  int iVar3;

  bool bVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int in_EAX;

  char *pcVar6;

  char *pcVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint uVar9;

  char *pcVar10;

  char *pcVar11;

  uint32_t /* width from decompiler */ *puVar12;

  char local_104 [4];

  char local_100 [4];

  char local_fc [4];

  char local_f8 [4];

  char local_f4 [2];

  char local_f2;

  

  if (in_EAX == 0) {

    return 0;

  }

  if ((param_1[0x152] == 1) && (param_1[0x156] == in_EAX)) {

    bVar4 = false;

  }

  else {

    bVar4 = true;

  }

  iVar3 = *(int *)(in_EAX + 0x5fc);

  param_1[0x154] = iVar3;

  param_1[0x155] = iVar3 >> 0x1f;

  param_1[0x156] = in_EAX;

  param_1[0x152] = 1;

  param_1[0x157] = param_1[0x140] + param_1[0x141] * 10;

  CVOGCharacter_SetQuickBarItem

            (DAT_00d1b6d8,(char)param_1[0x141] * '\n' + (char)param_1[0x140],0xffffffff,0xffffffff);

  CVOGCharacter_SetQuickBarSkill

            (DAT_00d1b6d8,(char)param_1[0x141] * '\n' + (char)param_1[0x140],param_1[0x154]);

  if ((bVar4) && ((char)param_1[0x13f] != '\0')) {

    FUN_00826780(0);

  }

  *(uint8_t *)((int)param_1 + 0x4fe) = 0;

  if ((int *)param_1[0x15f] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x15f] + 4))(1);

  }

  if (param_1[0x159] != 0) {

    local_104[0] = s_i_d_s_2d_wnd_icon__00a540d0[0];

    local_104[1] = s_i_d_s_2d_wnd_icon__00a540d0[1];

    local_104[2] = s_i_d_s_2d_wnd_icon__00a540d0[2];

    local_104[3] = s_i_d_s_2d_wnd_icon__00a540d0[3];

    local_fc[0] = s_i_d_s_2d_wnd_icon__00a540d0[8];

    local_fc[1] = s_i_d_s_2d_wnd_icon__00a540d0[9];

    local_fc[2] = s_i_d_s_2d_wnd_icon__00a540d0[10];

    local_fc[3] = s_i_d_s_2d_wnd_icon__00a540d0[0xb];

    local_100[0] = s_i_d_s_2d_wnd_icon__00a540d0[4];

    local_100[1] = s_i_d_s_2d_wnd_icon__00a540d0[5];

    local_100[2] = s_i_d_s_2d_wnd_icon__00a540d0[6];

    local_100[3] = s_i_d_s_2d_wnd_icon__00a540d0[7];

    local_f8[0] = s_i_d_s_2d_wnd_icon__00a540d0[0xc];

    local_f8[1] = s_i_d_s_2d_wnd_icon__00a540d0[0xd];

    local_f8[2] = s_i_d_s_2d_wnd_icon__00a540d0[0xe];

    local_f8[3] = s_i_d_s_2d_wnd_icon__00a540d0[0xf];

    pcVar1 = (char *)(in_EAX + 0x5a6);

    local_f2 = s_i_d_s_2d_wnd_icon__00a540d0[0x12];

    local_f4[0] = s_i_d_s_2d_wnd_icon__00a540d0[0x10];

    local_f4[1] = s_i_d_s_2d_wnd_icon__00a540d0[0x11];

    pcVar6 = pcVar1;

    do {

      cVar2 = *pcVar6;

      pcVar6 = pcVar6 + 1;

    } while (cVar2 != '\0');

    pcVar11 = &stack0xfffffefb;

    do {

      pcVar10 = pcVar11 + 1;

      pcVar11 = pcVar11 + 1;

    } while (*pcVar10 != '\0');

    pcVar10 = pcVar1;

    for (uVar9 = (uint)((int)pcVar6 - (int)pcVar1) >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar11 = *(uint32_t /* width from decompiler */ *)pcVar10;

      pcVar10 = pcVar10 + 4;

      pcVar11 = pcVar11 + 4;

    }

    pcVar7 = local_104;

    for (uVar9 = (int)pcVar6 - (int)pcVar1 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {

      *pcVar11 = *pcVar10;

      pcVar10 = pcVar10 + 1;

      pcVar11 = pcVar11 + 1;

    }

    iVar3 = 0x580 - (int)pcVar7;

    do {

      cVar2 = *pcVar7;

      pcVar7[(int)param_1 + iVar3] = cVar2;

      pcVar7 = pcVar7 + 1;

    } while (cVar2 != '\0');

    puVar5 = (uint32_t /* width from decompiler */ *)&stack0xfffffefb;

    if (*(char *)((int)param_1 + 0x4fe) == '\0') {

      do {

        puVar12 = puVar5;

        puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar12 + 1);

      } while (*(char *)((int)puVar12 + 1) != '\0');

      *(uint32_t /* width from decompiler */ *)((int)puVar12 + 1) = DAT_00a74e98;

      *(uint32_t /* width from decompiler */ *)((int)puVar12 + 5) = _DAT_00a74e9c;

    }

    else {

      do {

        puVar12 = puVar5;

        puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar12 + 1);

      } while (*(char *)((int)puVar12 + 1) != '\0');

      *(uint32_t /* width from decompiler */ *)((int)puVar12 + 1) = DAT_00a74e8c;

      *(uint32_t /* width from decompiler */ *)((int)puVar12 + 5) = DAT_00a74e90;

      *(uint8_t *)((int)puVar12 + 9) = DAT_00a74e94;

    }

    (**(code **)(*(int *)param_1[0x159] + 0x15c))(0,&DAT_00afdf0c);

    iVar3 = *(int *)param_1[0x159];

    uVar8 = (**(code **)(iVar3 + 0x2c8))(0);

    (**(code **)(iVar3 + 0x50))(&stack0xfffffef4,uVar8);

    (**(code **)(*(int *)param_1[0x159] + 0x34c))();

  }

  if ((int *)param_1[0x15d] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x15d] + 0x1d8))(0,1,1);

    (**(code **)(*(int *)param_1[0x15d] + 0x34c))();

  }

  if ((int *)param_1[0x15e] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x15e] + 0x1d8))(0,1,1);

    (**(code **)(*(int *)param_1[0x15e] + 0x34c))();

  }

  (**(code **)(*param_1 + 0x448))();

  return 1;

}
