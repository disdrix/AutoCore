// =============================================================================
// Named_i
// -----------------------------------------------------------------------------
// Stable ID: aa_0086e900
// Address:   0x0086e900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_i @ 0x0086e900
// Stable ID: aa_0086e900
// Embedded strings (evidence for future rename):
//   - "%s: %i (%i/%i)"
//   - "%s %s"
//   - "Deathmatch"
//   - "%i/%i"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~151 non-empty decompiler lines.
//  - Control keywords: if×19, return×3, do×3, while×3, goto×1.
//  - Notable callees: sprintf×5, FUN_0086e5c0×2, CONCAT12, FUN_00418700, FUN_00418790, FUN_0051fc80, FUN_007a69d0, FUN_007a6de0.
//  - Strings: "%s: %i (%i/%i)"; "%s %s"; "Deathmatch"; "%i/%i".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "%s: %i (%i/%i)"
 * Domain alias of FUN_0086e900 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_i(int *param_1)



{

  int iVar1;

  char cVar2;

  int *in_EAX;

  int *piVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ uVar5;

  int *piVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  void *pvStack_108;

  int iStack_104;

  uint32_t /* width from decompiler */ uStack_100;

  char acStack_fc [252];

  

  cVar2 = (**(code **)(*in_EAX + 0x3d8))();

  if (cVar2 == '\0') {

    return;

  }

  iVar1 = *param_1;

  iVar8 = iVar1 >> 0x1f;

  pvStack_108 = (void *)FUN_007a69d0();

  sprintf((char *)&uStack_100,"%i",param_1[0x10]);

  if (in_EAX[0x15a] != 0) {

    (**(code **)(*(int *)in_EAX[0x15a] + 0x45c))(&uStack_100,iVar1,iVar8,1);

    if ((DAT_00d1b6d8 == 0) || (*(int *)(DAT_00d1b6d8 + 0x6d0 + param_1[0xb] * 4) <= param_1[0x10]))

    {

      (**(code **)(*(int *)in_EAX[0x15a] + 0x46c))(iVar1,iVar8,1);

    }

    else {

      (**(code **)(*(int *)in_EAX[0x15a] + 0x464))(iVar1,iVar8,1,&DAT_00afdf08);

    }

  }

  piVar3 = param_1 + 1;

  piVar6 = piVar3;

  do {

    iVar7 = *piVar6;

    piVar6 = (int *)((int)piVar6 + 1);

  } while ((char)iVar7 != '\0');

  iStack_104 = (int)piVar6 - ((int)param_1 + 5);

  if (iStack_104 == 0) {

    uStack_100._0_1_ = s_No_Name_00a5d850[0];

    uStack_100._1_1_ = s_No_Name_00a5d850[1];

    uStack_100._2_1_ = s_No_Name_00a5d850[2];

    uStack_100._3_1_ = s_No_Name_00a5d850[3];

    acStack_fc[0] = s_No_Name_00a5d850[4];

    acStack_fc[1] = s_No_Name_00a5d850[5];

    acStack_fc[2] = s_No_Name_00a5d850[6];

    acStack_fc[3] = s_No_Name_00a5d850[7];

  }

  else {

    iVar7 = (int)&uStack_100 - (int)piVar3;

    do {

      iVar9 = *piVar3;

      *(char *)(iVar7 + (int)piVar3) = (char)iVar9;

      piVar3 = (int *)((int)piVar3 + 1);

    } while ((char)iVar9 != '\0');

  }

  if (in_EAX[0x15b] != 0) {

    (**(code **)(*(int *)in_EAX[0x15b] + 0x45c))(&uStack_100,iVar1,iVar8,1);

  }

  iVar7 = (int)*(short *)((int)param_1 + 0x32);

  iVar9 = (int)(short)param_1[0xc];

  uVar4 = (uint)*(byte *)(param_1 + 0x11);

  uVar5 = FUN_007a6de0(&DAT_00a5d84c,0xffffffff);

  sprintf((char *)&uStack_100,"%s: %i (%i/%i)",uVar5,uVar4,iVar9,iVar7);

  if (in_EAX[0x15c] != 0) {

    (**(code **)(*(int *)in_EAX[0x15c] + 0x45c))(&uStack_100,iVar1,iVar8,1);

    if ((DAT_00d1b6d8 == 0) ||

       (iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                            0x27c))(), iVar7 <= (int)(uint)*(byte *)(param_1 + 0x11))) {

      (**(code **)(*(int *)in_EAX[0x15c] + 0x46c))(iVar1,iVar8,1);

    }

    else {

      (**(code **)(*(int *)in_EAX[0x15c] + 0x464))(iVar1,iVar8,1,&DAT_00afdf08);

    }

  }

  sprintf((char *)&uStack_100,"%s %s",&DAT_00a1e610 + param_1[0xb] * 0x10,

          "Deathmatch" + param_1[10] * 0x10);

  if (in_EAX[0x15d] != 0) {

    (**(code **)(*(int *)in_EAX[0x15d] + 0x45c))(&uStack_100,iVar1,iVar8,1);

  }

  sprintf((char *)&uStack_100,"%i/%i",param_1[0x14],

          *(uint32_t /* width from decompiler */ *)(&DAT_00a1e5f0 + param_1[0xb] * 4));

  if (in_EAX[0x15e] != 0) {

    (**(code **)(*(int *)in_EAX[0x15e] + 0x45c))(&uStack_100,iVar1,iVar8,1);

    if (param_1[0x14] == *(int *)(&DAT_00a1e5f0 + param_1[0xb] * 4)) {

      (**(code **)(*(int *)in_EAX[0x15e] + 0x464))(iVar1,iVar8,1,&DAT_00afdf08);

    }

    else {

      (**(code **)(*(int *)in_EAX[0x15e] + 0x46c))(iVar1,iVar8,1);

    }

  }

  sprintf((char *)&uStack_100,"%i",0);

  if (in_EAX[0x15f] != 0) {

    (**(code **)(*(int *)in_EAX[0x15f] + 0x45c))(&uStack_100,iVar1,iVar8,1);

    if ((char)in_EAX[0x144] == '\0') {

      (**(code **)(*(int *)in_EAX[0x15f] + 0x46c))(iVar1,iVar8,1);

    }

    else {

      (**(code **)(*(int *)in_EAX[0x15f] + 0x464))(iVar1,iVar8,1,&DAT_00afdf08);

    }

  }

  FUN_0051fc80(param_1[0x12],param_1[0x13],&uStack_100,1);

  if (in_EAX[0x160] != 0) {

    (**(code **)(*(int *)in_EAX[0x160] + 0x45c))(&uStack_100,iVar1,iVar8,1);

    if (DAT_00d1b6d8 != 0) {

      iVar7 = (*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

              (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) < *(uint *)(DAT_00d1b6d8 + 0x728));

      if ((iVar7 <= param_1[0x13]) &&

         ((iVar7 < param_1[0x13] ||

          (*(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728) < (uint)param_1[0x12]))

         )) {

        (**(code **)(*(int *)in_EAX[0x160] + 0x464))(iVar1,iVar8,1,&DAT_00afdf08);

        goto LAB_0086ec7b;

      }

    }

    (**(code **)(*(int *)in_EAX[0x160] + 0x46c))(iVar1,iVar8,1);

  }

LAB_0086ec7b:

  if (*(char *)((int)param_1 + 0x25) == '\0') {

    uStack_100._0_3_ = CONCAT12(DAT_00a3747e,DAT_00a3747c);

  }

  else {

    uStack_100 = 0x736559;

  }

  if (in_EAX[0x161] != 0) {

    (**(code **)(*(int *)in_EAX[0x161] + 0x45c))(&uStack_100,iVar1,iVar8,1);

  }

  piVar3 = (int *)in_EAX[0x146];

  piVar6 = (int *)*piVar3;

  if (piVar6 != piVar3) {

    do {

      if (*(int *)piVar6[2] == *param_1) {

        FUN_0086e5c0();

        return;

      }

      piVar6 = (int *)*piVar6;

    } while (piVar6 != piVar3);

  }

  pvStack_108 = operator_new(0x1e58);

  FUN_0086e5c0();

  iVar1 = in_EAX[0x146];

  iVar8 = FUN_00418700(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4),&pvStack_108);

  FUN_00418790();

  *(int *)(iVar1 + 4) = iVar8;

  **(int **)(iVar8 + 4) = iVar8;

  FUN_007fbd30();

  return;

}
