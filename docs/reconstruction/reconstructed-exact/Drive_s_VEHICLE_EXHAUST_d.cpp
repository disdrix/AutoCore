// READABILITY (auto CF):
//  - Body size: ~205 non-empty decompiler lines.
//  - Control keywords: if×19, do×6, while×6, for×5, goto×5, return×2, switch×1.
//  - Notable callees: FUN_005829d0×7, CVOGReaction_FailMissionNotify×5, FUN_004a0b90×5, _snprintf×5, FUN_00989270×4, CONCAT31, FUN_004b7030, FUN_004ff850.
//  - Strings: "%s_WHEELSET_%d"; "%s_VEHICLE_EXHAUST_%d"; "%s_VEHICLE_BRAKES_%d"; "%s_VEHICLE_LIGHTS_%d".
//  - Return sites: 2.

// =============================================================================
// Drive_s_VEHICLE_EXHAUST_d
// -----------------------------------------------------------------------------
// Stable ID: aa_004ff850
// Address:   0x004ff850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "%s_VEHICLE_EXHAUST_%d"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Drive_s_VEHICLE_EXHAUST_d(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  char cVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int *piVar5;

  int iStack_548;

  uint32_t /* width from decompiler */ uStack_540;

  int local_53c;

  uint local_538;

  int local_534;

  char acStack_530 [2];

  uint32_t /* width from decompiler */ auStack_52e [65];

  char acStack_428 [2];

  uint32_t /* width from decompiler */ auStack_426 [65];

  char acStack_320 [2];

  uint32_t /* width from decompiler */ auStack_31e [65];

  char acStack_218 [2];

  uint32_t /* width from decompiler */ auStack_216 [65];

  char acStack_110 [2];

  uint32_t /* width from decompiler */ auStack_10e [66];

  

  if ((*(int *)(param_2 + 0x94) == 0) ||

     (local_534 = *(int *)(param_2 + 0x98) - *(int *)(param_2 + 0x94) >> 2, local_534 == 0)) {

    FUN_005829d0(param_2,param_3,param_4);

    cVar3 = '\0';

    local_538 = local_538 & 0xffffff00;

    piVar5 = (int *)(param_1 + -0x330);

    do {

      if (*piVar5 != 0) {

        FUN_004b7030(*piVar5,0,1,local_538);

      }

      cVar3 = cVar3 + '\x01';

      piVar5 = piVar5 + 1;

      local_538 = CONCAT31(local_538._1_3_,cVar3);

    } while (cVar3 < '\x03');

    return;

  }

  local_538 = 0;

  local_53c = 0;

LAB_004ff8a0:

  iVar1 = *(int *)(param_2 + 0x94);

  if ((iVar1 == 0) || ((uint)(*(int *)(param_2 + 0x98) - iVar1 >> 2) <= local_538)) {

    FUN_005829d0(param_2,param_3,param_4);

    return;

  }

  switch(*(uint32_t /* width from decompiler */ *)(iVar1 + local_53c)) {

  case 0xb:

    if (*(int *)(param_1 + -0x418) != 0) {

      cVar3 = *(char *)(*(int *)(param_1 + -0x418) + 0xb0);

      if (cVar3 < '\x03') {

        cVar3 = '\x04';

      }

      local_534 = (int)cVar3;

      iStack_548 = 1;

      if (1 < local_534) {

        do {

          acStack_428[0] = '\0';

          acStack_428[1] = '\0';

          puVar4 = auStack_426;

          for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {

            *puVar4 = 0;

            puVar4 = puVar4 + 1;

          }

          *(uint16_t *)puVar4 = 0;

          _snprintf(acStack_428,0x104,"%s_WHEELSET_%d",param_2 + 0xd5,iStack_548);

          uVar2 = FUN_004a0b90(param_2,acStack_428,1,

                               *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x94) + local_53c),iStack_548);

          uStack_540 = uVar2;

          if (param_4 != 0) {

            CVOGReaction_FailMissionNotify(&uStack_540);

          }

          FUN_005829d0(uVar2,param_3,param_4);

          iStack_548 = iStack_548 + 1;

        } while (iStack_548 < local_534);

        local_538 = local_538 + 1;

        local_53c = local_53c + 4;

        goto LAB_004ff8a0;

      }

    }

    break;

  case 0xf:

    if (*(int *)(param_1 + -0x628) != 0) {

      iStack_548 = 0x4bb;

      do {

        if ((*(int *)(*(int *)(param_1 + -0x628) + 100) != 0) &&

           (iVar1 = FUN_00989270(iStack_548), iVar1 != 0)) {

          acStack_530[0] = '\0';

          acStack_530[1] = '\0';

          puVar4 = auStack_52e;

          for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {

            *puVar4 = 0;

            puVar4 = puVar4 + 1;

          }

          *(uint16_t *)puVar4 = 0;

          _snprintf(acStack_530,0x104,"%s_VEHICLE_EXHAUST_%d",param_2 + 0xd5,iStack_548);

          uVar2 = FUN_004a0b90(param_2,acStack_530,1,

                               *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x94) + local_53c),

                               iStack_548 + -0x4ba);

          uStack_540 = uVar2;

          if (param_4 != 0) {

            CVOGReaction_FailMissionNotify(&uStack_540);

          }

          FUN_005829d0(uVar2,param_3,param_4);

        }

        iStack_548 = iStack_548 + 1;

      } while (iStack_548 < 0x4c0);

      local_538 = local_538 + 1;

      local_53c = local_53c + 4;

      goto LAB_004ff8a0;

    }

    break;

  case 0x10:

    if (*(int *)(param_1 + -0x628) != 0) {

      iStack_548 = 0x4c5;

      do {

        if ((*(int *)(*(int *)(param_1 + -0x628) + 100) != 0) &&

           (iVar1 = FUN_00989270(iStack_548), iVar1 != 0)) {

          acStack_110[0] = '\0';

          acStack_110[1] = '\0';

          puVar4 = auStack_10e;

          for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {

            *puVar4 = 0;

            puVar4 = puVar4 + 1;

          }

          *(uint16_t *)puVar4 = 0;

          _snprintf(acStack_110,0x104,"%s_VEHICLE_BRAKES_%d",param_2 + 0xd5,iStack_548);

          uVar2 = FUN_004a0b90(param_2,acStack_110,1,

                               *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x94) + local_53c),

                               iStack_548 + -0x4c4);

          uStack_540 = uVar2;

          if (param_4 != 0) {

            CVOGReaction_FailMissionNotify(&uStack_540);

          }

          FUN_005829d0(uVar2,param_3,param_4);

        }

        iStack_548 = iStack_548 + 1;

      } while (iStack_548 < 0x4cc);

    }

    break;

  case 0x11:

    if (*(int *)(param_1 + -0x628) != 0) {

      iStack_548 = 0x4cf;

      do {

        if ((*(int *)(*(int *)(param_1 + -0x628) + 100) != 0) &&

           (iVar1 = FUN_00989270(iStack_548), iVar1 != 0)) {

          acStack_320[0] = '\0';

          acStack_320[1] = '\0';

          puVar4 = auStack_31e;

          for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {

            *puVar4 = 0;

            puVar4 = puVar4 + 1;

          }

          *(uint16_t *)puVar4 = 0;

          _snprintf(acStack_320,0x104,"%s_VEHICLE_LIGHTS_%d",param_2 + 0xd5,iStack_548);

          uVar2 = FUN_004a0b90(param_2,acStack_320,1,

                               *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x94) + local_53c),

                               iStack_548 + -0x4ce);

          uStack_540 = uVar2;

          if (param_4 != 0) {

            CVOGReaction_FailMissionNotify(&uStack_540);

          }

          FUN_005829d0(uVar2,param_3,param_4);

        }

        iStack_548 = iStack_548 + 1;

      } while (iStack_548 < 0x4d8);

      local_538 = local_538 + 1;

      local_53c = local_53c + 4;

      goto LAB_004ff8a0;

    }

    break;

  case 0x15:

    if (*(int *)(param_1 + -0x628) == 0) break;

    iStack_548 = 0x3e9;

    do {

      if ((*(int *)(*(int *)(param_1 + -0x628) + 100) != 0) &&

         (iVar1 = FUN_00989270(iStack_548), iVar1 != 0)) {

        acStack_218[0] = '\0';

        acStack_218[1] = '\0';

        puVar4 = auStack_216;

        for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {

          *puVar4 = 0;

          puVar4 = puVar4 + 1;

        }

        *(uint16_t *)puVar4 = 0;

        _snprintf(acStack_218,0x104,"%s_VEHICLE_MELEE_%d",param_2 + 0xd5,iStack_548);

        uVar2 = FUN_004a0b90(param_2,acStack_218,1,

                             *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x94) + local_53c),

                             iStack_548 + -1000);

        uStack_540 = uVar2;

        if (param_4 != 0) {

          CVOGReaction_FailMissionNotify(&uStack_540);

        }

        FUN_005829d0(uVar2,param_3,param_4);

      }

      iStack_548 = iStack_548 + 1;

    } while (iStack_548 < 0x409);

    local_538 = local_538 + 1;

    local_53c = local_53c + 4;

    goto LAB_004ff8a0;

  }

  local_538 = local_538 + 1;

  local_53c = local_53c + 4;

  goto LAB_004ff8a0;

}
