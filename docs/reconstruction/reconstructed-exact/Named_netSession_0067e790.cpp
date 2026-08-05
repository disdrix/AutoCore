// READABILITY (auto CF):
//  - Body size: ~271 non-empty decompiler lines.
//  - Control keywords: if×30, return×9, goto×4, while×1.
//  - Notable callees: FUN_00680c50×7, FUN_00680c30×3, FUN_0076cec0×3, vog_LogMessage×3, CONCAT31×2, FUN_0067c000×2, FUN_00680d90×2, FUN_00681020×2.
//  - Strings: "Session %lu: Failure to send packet, terminating."; "Failure to send keep-alive packet, terminating."; "Session %lu: Failure to send keep-alive packet, terminating.".
//  - Return sites: 9.

// =============================================================================
// Named_netSession_0067e790
// -----------------------------------------------------------------------------
// Stable ID: aa_0067e790
// Address:   0x0067e790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "netSession"
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



uint32_t /* width from decompiler */ __fastcall Named_netSession_0067e790(int param_1)



{

  int *piVar1;

  uint8_t uVar2;

  uint16_t uVar3;

  uint16_t uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  char cVar8;

  int iVar9;

  uint uVar10;

  int *piVar11;

  uint32_t /* width from decompiler */ uVar12;

  uint32_t /* width from decompiler */ *puVar13;

  uint32_t /* width from decompiler */ *puStack_b4;

  int iStack_b0;

  int iStack_ac;

  uint8_t auStack_a8 [4];

  uint32_t /* width from decompiler */ *puStack_a4;

  int iStack_a0;

  uint32_t /* width from decompiler */ uStack_9c;

  int local_98;

  int *piStack_94;

  int aiStack_90 [2];

  uint16_t uStack_88;

  uint8_t uStack_83;

  uint8_t local_74 [28];

  uint8_t auStack_58 [76];

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a98a1;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  local_98 = param_1;

  FUN_00680c30();

  local_4._0_1_ = 0;

  local_4._1_3_ = 0;

  iVar9 = (**(code **)(**(int **)(param_1 + 0x2984) + 0x30))();

  if (iVar9 != 0) {

    (**(code **)(**(int **)(param_1 + 0x2984) + 4))(local_74,&iStack_b0);

  }

  FUN_0076c500(1000);

  uVar10 = FUN_0076c3c0();

  while( true ) {

    if ((0x31 < uVar10) ||

       ((*(char *)(param_1 + 0x29d4) != '\0' &&

        (*(uint *)(param_1 + 0x29d0) < *(uint *)(param_1 + 0x2a24))))) goto LAB_0067eaf3;

    puStack_b4 = (uint32_t /* width from decompiler */ *)0x0;

    puStack_a4 = (uint32_t /* width from decompiler */ *)0x0;

    iStack_a0 = 0;

    uStack_9c = 0;

    local_4._0_1_ = 1;

    uVar10 = FUN_0067dea0(auStack_a8,&puStack_b4);

    if (uVar10 == 0) break;

    FUN_00680c30();

    local_4._0_1_ = 2;

    piVar11 = operator_new__((uint)puStack_b4);

    puVar7 = puStack_a4;

    puVar5 = puStack_b4;

    piStack_94 = piVar11;

    if (uVar10 < 2) {

      piVar1 = (int *)*puStack_a4;

      uStack_83 = *(uint8_t *)((int)piVar1 + 0xd);

      iVar9 = piVar1[2];

      iVar6 = piVar1[1];

      uStack_88 = *(uint16_t *)(param_1 + 0x29ca);

      uVar3 = *(uint16_t *)(param_1 + 0x29c8);

      *(char *)(piVar11 + 3) = (char)piVar1[3];

      piVar11[1] = iVar9;

      *piVar11 = iVar6;

      *(uint16_t *)(piVar11 + 2) = uStack_88;

      *(uint16_t *)((int)piVar11 + 10) = uVar3;

      *(uint8_t *)((int)piVar11 + 0xd) = uStack_83;

      *(uint16_t *)((int)piVar11 + 0xe) = 0;

      if (*piVar1 != 0) {

        FUN_00680d90(piVar11 + 4,*(uint32_t /* width from decompiler */ *)(*piVar1 + 0xc));

        puVar5 = (uint32_t /* width from decompiler */ *)*piVar1;

        piVar11 = puVar5 + 5;

        *piVar11 = *piVar11 + -1;

        if (*piVar11 == 0) {

          (**(code **)*puVar5)(1);

        }

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(piVar1);

    }

    uVar3 = *(uint16_t *)(param_1 + 0x29ca);

    uVar4 = *(uint16_t *)(param_1 + 0x29c8);

    *piVar11 = 0;

    piVar11[1] = 0;

    *(uint16_t *)(piVar11 + 2) = uVar3;

    *(uint16_t *)((int)piVar11 + 10) = uVar4;

    *(uint8_t *)(piVar11 + 3) = 0xff;

    *(uint8_t *)((int)piVar11 + 0xd) = 0x40;

    *(uint16_t *)((int)piVar11 + 0xe) = 0;

    if ((puStack_a4 != (uint32_t /* width from decompiler */ *)0x0) &&

       (iStack_ac = iStack_a0 - (int)puStack_a4 >> 2, iStack_ac != 0)) {

      if (*(int *)(param_1 + 0x2a3c) != 0) {

        piVar1 = (int *)(*(int *)(param_1 + 0x2a3c) + 0x5c);

        *piVar1 = *piVar1 + 1;

      }

      piVar1 = (int *)*puStack_a4;

      memmove(puStack_a4,puStack_a4 + 1,(iStack_a0 - (int)(puStack_a4 + 1) >> 2) * 4);

      aiStack_90[0] = piVar1[1];

      iStack_a0 = iStack_a0 + -4;

      iVar9 = piVar1[2];

      iVar6 = piVar1[3];

      uVar2 = *(uint8_t *)((int)piVar1 + 0xd);

      if (*piVar1 != 0) {

        uVar12 = *(uint32_t /* width from decompiler */ *)(*piVar1 + 0xc);

        piVar11[4] = aiStack_90[0];

        piVar11[5] = iVar9;

        *(short *)(piVar11 + 6) = (short)uVar12;

        *(char *)((int)piVar11 + 0x1a) = (char)iVar6;

        *(uint8_t *)((int)piVar11 + 0x1b) = uVar2;

        FUN_00680d90(piVar11 + 7,uVar12);

        puVar5 = (uint32_t /* width from decompiler */ *)*piVar1;

        piVar11 = puVar5 + 5;

        *piVar11 = *piVar11 + -1;

        if (*piVar11 == 0) {

          (**(code **)*puVar5)(1);

        }

                    /* WARNING: Subroutine does not return */

        operator_delete(piVar1);

      }

      piVar11[4] = aiStack_90[0];

      piVar11[5] = iVar9;

      *(uint16_t *)(piVar11 + 6) = 0;

      *(char *)((int)piVar11 + 0x1a) = (char)iVar6;

      *(uint8_t *)((int)piVar11 + 0x1b) = uVar2;

                    /* WARNING: Subroutine does not return */

      operator_delete(piVar1);

    }

    if (*(int *)(param_1 + 0x2a3c) != 0) {

      piVar11 = (int *)(*(int *)(param_1 + 0x2a3c) + 0x54);

      *piVar11 = *piVar11 + 1;

    }

    FUN_00681020(&piStack_94,puStack_b4,1);

    cVar8 = (**(code **)(**(int **)(param_1 + 0x2984) + 4))(auStack_58,&iStack_b0);

    if (cVar8 == '\x01') {

      if (iStack_b0 == 2) {

LAB_0067ecce:

        if (*(int *)(param_1 + 0x2a3c) != 0) {

          FUN_0067c000(puVar5);

        }

        local_4 = CONCAT31(local_4._1_3_,1);

        FUN_00680c50();

        if (puVar7 != (uint32_t /* width from decompiler */ *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(puVar7);

        }

        goto LAB_0067ed2e;

      }

      iVar9 = *(int *)(param_1 + 0x2a3c);

      if (iVar9 != 0) {

        *(int *)(iVar9 + 4) = *(int *)(iVar9 + 4) + (int)puVar5;

        *(int *)(iVar9 + 0xc) = *(int *)(iVar9 + 0xc) + 1;

        puVar13 = *(uint32_t /* width from decompiler */ **)(iVar9 + 0x1c);

        if (puVar5 < *(uint32_t /* width from decompiler */ **)(iVar9 + 0x1c)) {

          puVar13 = puVar5;

        }

        *(uint32_t /* width from decompiler */ **)(iVar9 + 0x1c) = puVar13;

        puVar13 = *(uint32_t /* width from decompiler */ **)(iVar9 + 0x14);

        if (*(uint32_t /* width from decompiler */ **)(iVar9 + 0x14) < puVar5) {

          puVar13 = puVar5;

        }

        *(uint32_t /* width from decompiler */ **)(iVar9 + 0x14) = puVar13;

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x29b8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x29bc);

    }

    else {

      if (cVar8 != '\0') goto LAB_0067ecce;

      if ((iStack_b0 == 0) || (iStack_b0 == 1)) {

        uVar12 = FUN_0076cec0(&iStack_ac,"Session %lu: Failure to send packet, terminating.",

                              *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a20));

        vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"

                       ,0x646,1,uVar12);

        if (*(int **)(param_1 + 0x2984) != (int *)0x0) {

          (**(code **)(**(int **)(param_1 + 0x2984) + 0x10))();

          if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x2984) != (uint32_t /* width from decompiler */ *)0x0) {

            (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x2984))(1);

          }

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x2984) = 0;

          *(uint8_t *)(param_1 + 4) = 0;

        }

        local_4 = CONCAT31(local_4._1_3_,1);

        FUN_00680c50();

        if (puVar7 != (uint32_t /* width from decompiler */ *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(puVar7);

        }

        goto LAB_0067ec16;

      }

    }

    local_4._0_1_ = 1;

    FUN_00680c50();

    local_4._0_1_ = 0;

    if (puVar7 != (uint32_t /* width from decompiler */ *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar7);

    }

    puStack_a4 = (uint32_t /* width from decompiler */ *)0x0;

    iStack_a0 = 0;

    uStack_9c = 0;

    uVar10 = FUN_0076c3c0();

  }

  local_4._0_1_ = 0;

  if (puStack_a4 != (uint32_t /* width from decompiler */ *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(puStack_a4);

  }

LAB_0067eaf3:

  if (_DAT_009e949c < *(float *)(param_1 + 0x29bc) - *(float *)(param_1 + 0x29b8)) {

    if (*(int *)(param_1 + 0x2a3c) != 0) {

      piVar11 = (int *)(*(int *)(param_1 + 0x2a3c) + 100);

      *piVar11 = *piVar11 + 1;

    }

    FUN_00680c30();

    local_4._0_1_ = 3;

    puStack_b4 = operator_new__(0x18);

    uVar3 = *(uint16_t *)(param_1 + 0x29c8);

    *(uint16_t *)(puStack_b4 + 2) = *(uint16_t *)(param_1 + 0x29ca);

    *(uint16_t *)((int)puStack_b4 + 10) = uVar3;

    *puStack_b4 = 0;

    puStack_b4[1] = 0;

    *(uint8_t *)(puStack_b4 + 3) = 0xff;

    *(uint8_t *)((int)puStack_b4 + 0xd) = 0;

    *(uint16_t *)((int)puStack_b4 + 0xe) = 0;

    puStack_b4[4] = 0;

    puStack_b4[5] = 0;

    FUN_00681020(&puStack_b4,0x18,1);

    cVar8 = (**(code **)(**(int **)(param_1 + 0x2984) + 4))(aiStack_90,&iStack_b0);

    if (cVar8 == '\0') {

      if ((iStack_b0 == 0) || (iStack_b0 == 1)) {

        uVar12 = FUN_0076cec0(&iStack_ac,"Failure to send keep-alive packet, terminating.");

        vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"

                       ,0x67a,1,uVar12);

        uVar12 = FUN_0076cec0(&iStack_ac,

                              "Session %lu: Failure to send keep-alive packet, terminating.",

                              *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a20));

        vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"

                       ,0x67b,1,uVar12);

        FUN_0067c430();

        local_4 = (uint)local_4._1_3_ << 8;

        FUN_00680c50();

LAB_0067ec16:

        local_4 = 0xffffffff;

        FUN_00680c50();

        ExceptionList = pvStack_c;

        return 0;

      }

    }

    else {

      if (*(int *)(param_1 + 0x2a3c) != 0) {

        FUN_0067c000(0x18);

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x29b8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x29bc);

    }

    local_4 = (uint)local_4._1_3_ << 8;

    FUN_00680c50();

  }

LAB_0067ed2e:

  local_4 = 0xffffffff;

  FUN_00680c50();

  ExceptionList = pvStack_c;

  return 1;

}
