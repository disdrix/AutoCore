// READABILITY (auto CF):
//  - Body size: ~250 non-empty decompiler lines.
//  - Control keywords: if×25, return×4, while×4, do×2, for×2, goto×1.
//  - Notable callees: FUN_0076cec0×3, vog_LogMessage×3, FUN_0067f930×2, FUN_00680c30×2, CONCAT31, FUN_004073a0, FUN_0067c330, FUN_0067d980.
//  - Strings: "Session %lu: Received %d packets, processed %d this pass.".
//  - Return sites: 4.

// =============================================================================
// Named_Session_lu_After_processing_time_expired_d_packe_0067eed0
// -----------------------------------------------------------------------------
// Stable ID: aa_0067eed0
// Address:   0x0067eed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Session %lu: After processing time expired, %d packets remain to process."
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



uint8_t __fastcall Named_Session_lu_After_processing_time_expired_d_packe_0067eed0(int param_1)



{

  int *_Dst;

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  uint uVar6;

  int *piVar7;

  int *piVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint8_t local_bd;

  int iStack_bc;

  void *pvStack_b8;

  int iStack_b4;

  int iStack_b0;

  int iStack_ac;

  uint32_t /* width from decompiler */ *apuStack_a8 [2];

  uint32_t /* width from decompiler */ *puStack_a0;

  uint32_t /* width from decompiler */ *puStack_9c;

  int iStack_98;

  int *piStack_90;

  int *piStack_8c;

  int iStack_88;

  uint32_t /* width from decompiler */ uStack_84;

  uint32_t /* width from decompiler */ uStack_80;

  uint16_t uStack_7c;

  uint16_t uStack_7a;

  char cStack_78;

  uint8_t uStack_77;

  uint16_t uStack_76;

  uint32_t /* width from decompiler */ *puStack_74;

  double dStack_70;

  uint8_t auStack_64 [12];

  uint uStack_58;

  void *pvStack_14;

  uint8_t *puStack_10;

  int iStack_c;

  

  iStack_c = 0xffffffff;

  puStack_10 = &LAB_009a98d7;

  pvStack_14 = ExceptionList;

  local_bd = 1;

  ExceptionList = &pvStack_14;

  cVar2 = (**(code **)(**(int **)(param_1 + 0x2984) + 0x1c))();

  if (cVar2 == '\0') {

    if (*(int **)(param_1 + 0x2984) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x2984) + 0x10))();

      if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x2984) != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x2984))(1);

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x2984) = 0;

      *(uint8_t *)(param_1 + 4) = 0;

    }

    ExceptionList = pvStack_14;

    return 0;

  }

  iStack_b4 = 0;

  iStack_b0 = 0;

  FUN_00680c30();

  iStack_c = 0;

  while ((((*(int *)(param_1 + 0x2978) == 0 ||

           ((uint)(*(int *)(param_1 + 0x297c) - *(int *)(param_1 + 0x2978) >> 2) < 0x200)) &&

          ((*(char *)(param_1 + 0x29d4) == '\0' || (0x1f < *(int *)(param_1 + 0x29cc))))) &&

         (cVar2 = (**(code **)(**(int **)(param_1 + 0x2984) + 8))(auStack_64), cVar2 == '\x01'))) {

    piVar8 = *(int **)(param_1 + 0x2a3c);

    if (piVar8 != (int *)0x0) {

      *piVar8 = *piVar8 + uStack_58;

      piVar8[2] = piVar8[2] + 1;

      uVar6 = piVar8[6];

      if (uStack_58 < (uint)piVar8[6]) {

        uVar6 = uStack_58;

      }

      piVar8[6] = uVar6;

      uVar6 = uStack_58;

      if (uStack_58 <= (uint)piVar8[4]) {

        uVar6 = piVar8[4];

      }

      piVar8[4] = uVar6;

    }

    pvStack_b8 = operator_new(0x1c);

    iStack_c._0_1_ = 1;

    if (pvStack_b8 == (void *)0x0) {

      iVar3 = 0;

    }

    else {

      iVar3 = FUN_00680c30();

    }

    iStack_c = (uint)iStack_c._1_3_ << 8;

    iStack_bc = iVar3;

    FUN_00680dd0(auStack_64);

    iVar5 = *(int *)(param_1 + 0x2978);

    if ((iVar5 == 0) ||

       ((uint)(*(int *)(param_1 + 0x2980) - iVar5 >> 2) <=

        (uint)(*(int *)(param_1 + 0x297c) - iVar5 >> 2))) {

      FUN_0067f930(*(uint32_t /* width from decompiler */ *)(param_1 + 0x297c),1,&iStack_bc);

      iStack_b4 = iStack_b4 + 1;

    }

    else {

      piVar8 = *(int **)(param_1 + 0x297c);

      *piVar8 = iVar3;

      iStack_b4 = iStack_b4 + 1;

      *(int **)(param_1 + 0x297c) = piVar8 + 1;

    }

  }

  if (iStack_b4 != 0) {

    thunk_FUN_0076c4d0();

  }

  piStack_90 = (int *)0x0;

  piStack_8c = (int *)0x0;

  iStack_88 = 0;

  puStack_a0 = (uint32_t /* width from decompiler */ *)0x0;

  puStack_9c = (uint32_t /* width from decompiler */ *)0x0;

  iStack_98 = 0;

  iStack_c = CONCAT31(iStack_c._1_3_,3);

  FUN_0076c500(1000);

  dStack_70 = _DAT_00aaa608;

  iStack_bc = 0;

  piVar7 = (int *)0x0;

  piVar8 = (int *)0x0;

  do {

    while( true ) {

      if (((*(int *)(param_1 + 0x2978) == 0) ||

          (pvStack_b8 = (void *)(*(int *)(param_1 + 0x297c) - *(int *)(param_1 + 0x2978) >> 2),

          pvStack_b8 == (void *)0x0)) ||

         ((((byte)iStack_b0 & 0xf) == 0xf && (_DAT_009e95b8 <= dStack_70)))) {

        for (; piVar8 != piVar7; piVar8 = piVar8 + 1) {

          if ((uint32_t /* width from decompiler */ *)*piVar8 != (uint32_t /* width from decompiler */ *)0x0) {

            (*(code *)**(uint32_t /* width from decompiler */ **)*piVar8)(1);

          }

        }

        FUN_0067fe60(0,0);

        puVar1 = puStack_9c;

        for (puVar9 = puStack_a0; puVar9 != puVar1; puVar9 = puVar9 + 1) {

          operator_delete__((void *)*puVar9);

        }

        FUN_0067fdd0(0,0);

        iVar3 = *(int *)(param_1 + 0x2978);

        if ((iVar3 != 0) && (iStack_ac = *(int *)(param_1 + 0x297c) - iVar3 >> 2, iStack_ac != 0)) {

          iVar5 = 0;

          if (iVar3 != 0) {

            iVar5 = *(int *)(param_1 + 0x297c) - iVar3 >> 2;

          }

          uVar4 = FUN_0076cec0(&iStack_ac,

                               "Session %lu: After processing time expired, %d packets remain to process."

                               ,*(uint32_t /* width from decompiler */ *)(param_1 + 0x2a20),iVar5);

          vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"

                         ,0x369,1,uVar4);

          uVar4 = FUN_0076cec0(&iStack_ac,

                               "Session %lu: Received %d packets, processed %d this pass.",

                               *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a20),iStack_b4,iStack_b0);

          vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"

                         ,0x36a,1,uVar4);

        }

        if (puStack_a0 != (uint32_t /* width from decompiler */ *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(puStack_a0);

        }

        if (piStack_90 != (int *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(piStack_90);

        }

        iStack_c = 0xffffffff;

        FUN_00680c50();

        ExceptionList = pvStack_14;

        return local_bd;

      }

      _Dst = *(int **)(param_1 + 0x2978);

      puVar9 = (uint32_t /* width from decompiler */ *)*_Dst;

      puStack_74 = puVar9;

      memmove(_Dst,_Dst + 1,(*(int *)(param_1 + 0x297c) - (int)(_Dst + 1) >> 2) * 4);

      *(int *)(param_1 + 0x297c) = *(int *)(param_1 + 0x297c) + -4;

      if (0xf < (uint)puVar9[3]) break;

      uVar4 = FUN_0076cec0(&iStack_ac,

                           "Session %lu: Incoming message that is not large enough to contain a header!"

                           ,*(uint32_t /* width from decompiler */ *)(param_1 + 0x2a20));

      vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"

                     ,0x31a,2,uVar4);

      (**(code **)*puVar9)(1);

    }

    pvStack_b8 = (void *)FUN_00680cf0(apuStack_a8);

    if ((piVar8 == (int *)0x0) ||

       ((uint)(iStack_88 - (int)piVar8 >> 2) <= (uint)((int)piVar7 - (int)piVar8 >> 2))) {

      FUN_0067f930(piVar7,1,&puStack_74);

    }

    else {

      *piVar7 = (int)puVar9;

      piStack_8c = piVar7 + 1;

    }

    uStack_84 = *apuStack_a8[0];

    uStack_80 = apuStack_a8[0][1];

    cVar2 = *(char *)(apuStack_a8[0] + 3);

    uStack_7c = *(uint16_t *)(apuStack_a8[0] + 2);

    uStack_7a = *(uint16_t *)((int)apuStack_a8[0] + 10);

    uStack_77 = *(uint8_t *)((int)apuStack_a8[0] + 0xd);

    uStack_76 = *(uint16_t *)((int)apuStack_a8[0] + 0xe);

    puVar9 = apuStack_a8[0] + 4;

    iVar3 = (int)pvStack_b8 + -0x10;

    cStack_78 = cVar2;

    FUN_0067c330(*(uint32_t /* width from decompiler */ *)((int)apuStack_a8[0] + 10),apuStack_a8[0][2]);

    if (cVar2 == '\0') {

      local_bd = FUN_0067e3a0(&uStack_84,puVar9,iVar3);

    }

    else if (cVar2 == -2) {

      FUN_0067d980(0xfe,puVar9,iVar3);

      iVar5 = 0;

      if (*(byte *)(param_1 + 6) != 0) {

        do {

          if (*(char *)(iVar5 + 7 + param_1) == -2) goto LAB_0067f27b;

          iVar5 = iVar5 + 1;

        } while (iVar5 < (int)(uint)*(byte *)(param_1 + 6));

      }

      *(uint8_t *)(*(byte *)(param_1 + 6) + 7 + param_1) = 0xfe;

      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';

LAB_0067f27b:

      local_bd = 1;

    }

    else if (cVar2 == -1) {

      local_bd = FUN_0067ed60(&uStack_84,puVar9,iVar3);

    }

    else {

      local_bd = FUN_0067e2b0(&uStack_84,puVar9,iVar3);

    }

    *(int *)(param_1 + 0x29cc) = *(int *)(param_1 + 0x29cc) + (-0x10 - iVar3);

    if ((puStack_a0 == (uint32_t /* width from decompiler */ *)0x0) ||

       ((uint)(iStack_98 - (int)puStack_a0 >> 2) <= (uint)((int)puStack_9c - (int)puStack_a0 >> 2)))

    {

      FUN_004073a0(puStack_9c,1,apuStack_a8);

    }

    else {

      *puStack_9c = apuStack_a8[0];

      puStack_9c = puStack_9c + 1;

    }

    iStack_b0 = iStack_b0 + 1;

    iStack_bc = iStack_bc + 1;

    piVar7 = piStack_8c;

    piVar8 = piStack_90;

    if (10 < iStack_bc) {

      pvStack_b8 = (void *)FUN_0076c3c0();

      dStack_70 = (double)(int)pvStack_b8;

      if ((int)pvStack_b8 < 0) {

        dStack_70 = dStack_70 + _DAT_00aaa728;

      }

      iStack_bc = 0;

      piVar7 = piStack_8c;

      piVar8 = piStack_90;

    }

  } while( true );

}
