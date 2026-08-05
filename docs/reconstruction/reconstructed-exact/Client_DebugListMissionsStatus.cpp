// READABILITY (auto CF):
//  - Body size: ~183 non-empty decompiler lines.
//  - Control keywords: if×20, return×5, while×4, for×1, do×1.
//  - Notable callees: FUN_0040fb90×4, FUN_00800af0×3, CNDHash_LookupByKey×2, CONCAT31×2, FUN_00404840×2, FUN_00411900×2, FUN_00418700×2, FUN_00547920×2.
//  - Strings: "Missions Still To Complete:\n"; "%s - (ID: %d)\n"; "\nMissions Currently Active:\n".
//  - Return sites: 5.

// =============================================================================
// Client_DebugListMissionsStatus
// -----------------------------------------------------------------------------
// Purpose:  DEBUG list: missions still to complete and currently active.
//
// Address:  0x009572e0  (autoassault.exe, image base 0x400000)
// Stable:   aa_009572e0
// System:   missions-progression
//
// String evidence: "Missions Still To Complete" / "Missions Currently Active"
//
// Exactness: Behavior-preserving rewrite of decompiler control flow (scaffold).
// Bit-for-bit vs retail EXE: DEFERRED.
// Source:    Prefer over FUN_009572e0.cpp; FUN_* left intact as raw scaffold twin.
// =============================================================================

/*
 * Behavioral notes:
 * - Renamed from FUN_009572e0 using string evidence: "Missions Still To Complete" / "Missions Currently Active"
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

uint32_t /* width from decompiler */ Client_DebugListMissionsStatus(uint32_t /* width from decompiler */ param_1,char *param_2)

{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  int *piVar3;

  char cVar4;

  char *_Str;

  int *piVar5;

  int *piVar6;

  uint *puVar7;

  int iVar8;

  void *pvVar9;

  int iVar10;

  void *local_148;

  uint *local_144 [2];

  int *local_13c;

  int local_138;

  int *local_130;

  uint32_t /* width from decompiler */ local_12c;

  int local_124;

  uint32_t /* width from decompiler */ local_120;

  uint8_t auStack_11c [4];

  uint32_t /* width from decompiler */ *local_118;

  uint32_t /* width from decompiler */ local_114;

  uint32_t /* width from decompiler */ local_110;

  char acStack_10c [256];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bb3e4;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  _Str = strtok((char *)0x0,param_2);

  local_148 = *(void **)(DAT_00d1b644 + 0xfc);

  if (_Str != (char *)0x0) {

    local_148 = (void *)atoi(_Str);

  }

  if ((local_148 == (void *)0xffffffff) || (DAT_00d1b6d8 == 0)) {

    ExceptionList = local_c;

    return 1;

  }

  piVar5 = (int *)FUN_0040fb90();

  local_12c = 0;

  local_4 = 0;

  local_130 = piVar5;

  local_13c = (int *)FUN_0040fb90();

  local_138 = 0;

  local_4._0_1_ = 1;

  local_124 = FUN_0040fb90();

  local_120 = 0;

  local_4._0_1_ = 2;

  local_118 = (uint32_t /* width from decompiler */ *)FUN_0040fb90();

  local_114 = 0;

  local_4 = CONCAT31(local_4._1_3_,3);

  piVar6 = (int *)FUN_0053fff0();

  iVar10 = *piVar6;

  if (iVar10 != 0) {

    local_110 = 0;

    FUN_00402c40();

    puVar7 = (uint *)FUN_00411900(&local_110);

    while (puVar7 != (uint *)0x0) {

      local_144[0] = puVar7;

      if (((((void *)puVar7[0x3f] == local_148) && ((short)puVar7[0x3e] == 0)) &&

          (puVar7[0x22] != 0xffffffff)) &&

         ((((int)*puVar7 < 0xdfd || (0xe02 < (int)*puVar7)) ||

          ((DAT_00d1b6d8 == 0 ||

           (iVar8 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +

                                         DAT_00d1b6d8) + 0x27c))(), 4 < iVar8)))))) {

        FUN_00402dd0(0);

        cVar4 = FUN_008ec750(puVar7,auStack_11c);

        if (cVar4 != '\0') {

          FUN_00402d10(local_144);

          piVar5 = local_130;

        }

      }

      puVar7 = (uint *)FUN_00411900(&local_110);

    }

    *(uint8_t *)(iVar10 + 0x1d) = 0;

    local_144[0] = (uint *)0x0;

  }

  local_148 = *(void **)(DAT_00d1b6d8 + 0x540);

  if (local_148 != (void *)0x0) {

    pvVar2 = local_148;

    piVar6 = (int *)*piVar5;

    while (piVar3 = piVar6, piVar3 != piVar5) {

      local_144[0] = (uint *)piVar3[2];

      piVar6 = piVar3;

      if (local_144[0] != (uint *)0x0) {

        pvVar9 = CNDHash_LookupByKey(pvVar2,*local_144[0]);

        if (pvVar9 == (void *)0x0) {

          piVar6 = (int *)*piVar3;

        }

        else {

          piVar6 = local_13c + 1;

          iVar10 = FUN_00418700(local_13c,local_13c[1],local_144);

          FUN_00404840(1);

          *piVar6 = iVar10;

          **(int **)(iVar10 + 4) = iVar10;

          pvVar2 = local_148;

          piVar6 = (int *)*piVar3;

          if (piVar3 != piVar5) {

            *(int **)piVar3[1] = (int *)*piVar3;

            *(int *)(*piVar3 + 4) = piVar3[1];

                    /* WARNING: Subroutine does not return */

            operator_delete(piVar3);

          }

        }

      }

    }

  }

  local_148 = *(void **)(DAT_00d1b6d8 + 0x538);

  if (local_148 != (void *)0x0) {

    pvVar2 = local_148;

    piVar6 = (int *)*piVar5;

    while (piVar3 = piVar6, piVar3 != piVar5) {

      local_144[0] = (uint *)piVar3[2];

      piVar6 = piVar3;

      if (local_144[0] != (uint *)0x0) {

        pvVar9 = CNDHash_LookupByKey(pvVar2,*local_144[0]);

        if (pvVar9 == (void *)0x0) {

          piVar6 = (int *)*piVar3;

        }

        else {

          piVar6 = (int *)(local_124 + 4);

          iVar10 = FUN_00418700(local_124,*(uint32_t /* width from decompiler */ *)(local_124 + 4),local_144);

          FUN_00404840(1);

          *piVar6 = iVar10;

          **(int **)(iVar10 + 4) = iVar10;

          pvVar2 = local_148;

          piVar6 = (int *)*piVar3;

          if (piVar3 != piVar5) {

            *(int **)piVar3[1] = (int *)*piVar3;

            *(int *)(*piVar3 + 4) = piVar3[1];

                    /* WARNING: Subroutine does not return */

            operator_delete(piVar3);

          }

        }

      }

    }

  }

  local_148 = (void *)0xffc8ffc8;

  FUN_00800c30(&DAT_00d1a840,0x15197,0,"Missions Still To Complete:\n",&local_148);

  for (piVar6 = (int *)*piVar5; piVar6 != piVar5; piVar6 = (int *)*piVar6) {

    puVar1 = (uint32_t /* width from decompiler */ *)piVar6[2];

    if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

      if (*(char *)(puVar1 + 0x5a) == '\0') {

        FUN_00547920(0);

      }

      sprintf(acStack_10c,"%s - (ID: %d)\n",puVar1[0x53],*puVar1);

      FUN_00800af0(&DAT_00d1a840,0x15197,0,acStack_10c,&DAT_00afdf0c);

    }

  }

  if (local_138 != 0) {

    local_148 = (void *)0xffc8ffc8;

    FUN_00800af0(&DAT_00d1a840,0x15197,0,"\nMissions Currently Active:\n",&local_148);

    piVar5 = (int *)*local_13c;

    if (piVar5 != local_13c) {

      do {

        puVar1 = (uint32_t /* width from decompiler */ *)piVar5[2];

        if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

          if (*(char *)(puVar1 + 0x5a) == '\0') {

            FUN_00547920(0);

          }

          sprintf(acStack_10c,"%s - (ID: %d)\n",puVar1[0x53],*puVar1);

          FUN_00800af0(&DAT_00d1a840,0x15197,0,acStack_10c,&DAT_00afdf0c);

        }

        piVar5 = (int *)*piVar5;

      } while (piVar5 != local_13c);

    }

  }

  local_4 = CONCAT31(local_4._1_3_,2);

  puVar1 = (uint32_t /* width from decompiler */ *)*local_118;

  *local_118 = local_118;

  local_118[1] = local_118;

  local_114 = 0;

  if (puVar1 != local_118) {

                    /* WARNING: Subroutine does not return */

    operator_delete(puVar1);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(local_118);

}
