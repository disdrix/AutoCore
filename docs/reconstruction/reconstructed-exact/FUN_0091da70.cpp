// =============================================================================
// FUN_0091da70
// -----------------------------------------------------------------------------
// Stable ID: aa_0091da70
// Address:   0x0091da70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0091da70 @ 0x0091da70
// Stable ID: aa_0091da70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~271 non-empty decompiler lines.
//  - Control keywords: if×22, return×6, goto×3, do×2, while×2.
//  - Notable callees: Client_SendSectorPacket×4, GetTickCount×3, FUN_004e8dc0×2, QueryPerformanceCounter×2, CVOGReaction_RandomUnitScalar, FUN_00402ae0, FUN_004040a0, FUN_00404c30.
//  - Return sites: 6.

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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ FUN_0091da70(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  ushort uVar2;

  int iVar3;

  float fVar4;

  char cVar5;

  int iVar6;

  DWORD DVar7;

  int *piVar8;

  uint uVar9;

  int iVar10;

  byte bVar11;

  int *piVar12;

  uint32_t /* width from decompiler */ local_10fc;

  float fStack_10f8;

  int *piStack_10f4;

  uint32_t /* width from decompiler */ auStack_10f0 [2];

  uint32_t /* width from decompiler */ uStack_10e8;

  uint32_t /* width from decompiler */ uStack_10e4;

  uint32_t /* width from decompiler */ uStack_10e0;

  uint32_t /* width from decompiler */ uStack_10dc;

  uint32_t /* width from decompiler */ uStack_10d8;

  uint32_t /* width from decompiler */ uStack_10d4;

  float fStack_10d0;

  uint32_t /* width from decompiler */ uStack_10cc;

  uint32_t /* width from decompiler */ uStack_10c8;

  uint32_t /* width from decompiler */ uStack_10c4;

  uint32_t /* width from decompiler */ uStack_10c0;

  uint32_t /* width from decompiler */ uStack_10bc;

  uint32_t /* width from decompiler */ uStack_10b8;

  float fStack_10b4;

  uint32_t /* width from decompiler */ uStack_10b0;

  uint32_t /* width from decompiler */ uStack_10ac;

  uint32_t /* width from decompiler */ uStack_10a8;

  uint32_t /* width from decompiler */ uStack_10a0;

  uint32_t /* width from decompiler */ uStack_109c;

  uint32_t /* width from decompiler */ uStack_1098;

  uint32_t /* width from decompiler */ uStack_1090;

  uint32_t /* width from decompiler */ uStack_108c;

  uint32_t /* width from decompiler */ uStack_1088;

  uint32_t /* width from decompiler */ uStack_1084;

  uint32_t /* width from decompiler */ uStack_1070;

  uint32_t /* width from decompiler */ uStack_106c;

  uint32_t /* width from decompiler */ uStack_1068;

  uint32_t /* width from decompiler */ uStack_1064;

  uint32_t /* width from decompiler */ uStack_1054;

  uint32_t /* width from decompiler */ uStack_1050;

  uint32_t /* width from decompiler */ uStack_104c;

  float fStack_1048;

  uint32_t /* width from decompiler */ uStack_1044;

  uint32_t /* width from decompiler */ uStack_1040;

  uint32_t /* width from decompiler */ uStack_103c;

  uint32_t /* width from decompiler */ uStack_1038;

  uint32_t /* width from decompiler */ uStack_1034;

  uint8_t auStack_1030 [24];

  uint32_t /* width from decompiler */ uStack_1018;

  byte bStack_1014;

  int aiStack_1010 [1021];

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009b0494;

  local_1c = ExceptionList;

  aiStack_1010[0x3fb] = 0x91da96;

  local_10fc = 0;

  if (0.0 <= _DAT_00d1b588) {

    return 0;

  }

  if (((g_pSectorNetConnection_INFERRED == (void *)0x0) ||

      (ExceptionList = &local_1c,

      cVar5 = (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 8))(), cVar5 == '\0')) ||

     (DAT_00d1b6d8 == (int *)0x0)) {

    ExceptionList = local_1c;

    return 0;

  }

  if (DAT_00d1b554 != 0) {

    bVar11 = 0;

    uStack_1018 = 0x2011;

    bStack_1014 = 0;

    piStack_10f4 = (int *)*DAT_00d1b550;

    piVar8 = g_pSectorNetConnection_INFERRED;

    piVar12 = DAT_00d1b550;

    if (piStack_10f4 != DAT_00d1b550) {

      do {

        uVar9 = (uint)bVar11;

        aiStack_1010[uVar9 * 4] = piStack_10f4[4];

        aiStack_1010[uVar9 * 4 + 1] = piStack_10f4[5];

        aiStack_1010[uVar9 * 4 + 2] = piStack_10f4[6];

        aiStack_1010[uVar9 * 4 + 3] = piStack_10f4[7];

        bStack_1014 = bStack_1014 + 1;

        if (bStack_1014 == 0xff) {

          if (piVar8 != (int *)0x0) {

            (**(code **)(*piVar8 + 0x18))(0xffffffff,&uStack_1018,0xff8,0);

            piVar8 = g_pSectorNetConnection_INFERRED;

            piVar12 = DAT_00d1b550;

          }

          bStack_1014 = 0;

        }

        bVar11 = bStack_1014;

        FUN_004040a0();

      } while (piStack_10f4 != piVar12);

    }

    Client_SendSectorPacket(&DAT_00d1a840,(ushort)bVar11 * 0x10 + 8,&uStack_1018);

    FUN_00405c80();

  }

  piVar8 = DAT_00d1b6d8;

  if ((DAT_00d1b6d8 != (int *)0x0) && (*(char *)((int)DAT_00d1b6d8 + 0x4f1) != '\0')) {

    fStack_10f8 = *(float *)(DAT_00d17944 + 0x230);

    uStack_1054 = *(uint32_t /* width from decompiler */ *)(DAT_00d17944 + 0x22c);

    uStack_1050 = *(uint32_t /* width from decompiler */ *)(DAT_00d17944 + 0x228);

    uStack_1070 = *(uint32_t /* width from decompiler */ *)(DAT_00d17944 + 0x21c);

    uStack_106c = *(uint32_t /* width from decompiler */ *)(DAT_00d17944 + 0x220);

    uStack_1068 = *(uint32_t /* width from decompiler */ *)(DAT_00d17944 + 0x224);

    uStack_1064 = 0;

    uStack_1044 = 0;

    uStack_104c = uStack_1054;

    fStack_1048 = fStack_10f8;

    FUN_00404c60(&uStack_1050);

    FUN_004e8dc0(&uStack_1070,auStack_1030);

    FUN_00404c30(auStack_1030);

    if ((DAT_00d20c58 & 1) == 0) {

      DAT_00d20c58 = DAT_00d20c58 | 1;

      uStack_14 = 0;

      _DAT_00d20c54 = GetTickCount();

      uStack_14 = 0xffffffff;

    }

    if ((DAT_00d20c58 & 2) == 0) {

      DAT_00d20c58 = DAT_00d20c58 | 2;

      DAT_00d20c50 = DAT_00d1b648;

      uStack_14 = 0xffffffff;

    }

    iVar6 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar6 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar6 + 0xc) = 0;

    }

    uVar2 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);

    *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;

    piStack_10f4 = (int *)((float)uVar2 * DAT_00aaaaf4 + DAT_00aaaae8);

    fVar4 = ROUND((float)piStack_10f4);

    if ((DAT_00d20c50 == DAT_00d1b648) &&

       (DVar7 = GetTickCount(), DVar7 - _DAT_00d20c54 <= (uint)(int)fVar4)) {

      ExceptionList = local_1c;

      return 0;

    }

    DAT_00d20c50 = DAT_00d1b648;

    _DAT_00d20c54 = GetTickCount();

    uStack_10c4 = 0;

    uStack_10c8 = 0;

    uStack_10cc = 0;

    uStack_10b8 = 0;

    uStack_10bc = 0;

    uStack_10c0 = 0;

    uStack_10a8 = 0;

    uStack_10ac = 0;

    uStack_10b0 = 0;

    uStack_1098 = 0;

    uStack_109c = 0;

    uStack_10a0 = 0;

    fStack_10b4 = g_flMsToSeconds_Inferred;

    auStack_10f0[0] = 0x2008;

    puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(DAT_00d1b6d8[1] + 4) + 0x164 + (int)DAT_00d1b6d8);

    uStack_10e8 = *puVar1;

    uStack_10e4 = puVar1[1];

    uStack_10e0 = puVar1[2];

    uStack_10dc = puVar1[3];

    uStack_10d8 = uStack_1050;

    uStack_10d4 = uStack_1054;

    fStack_10d0 = fStack_10f8;

    FUN_004e8dc0(&uStack_1070,&uStack_1040);

    uStack_10c0 = uStack_1040;

    uStack_108c = DAT_00a158bc;

    uStack_10bc = uStack_103c;

    uStack_1090 = DAT_00a158b8;

    uStack_10b8 = uStack_1038;

    uStack_1088 = DAT_00a158c0;

    fStack_10b4 = (float)uStack_1034;

    uStack_1084 = DAT_00a158c4;

    Client_SendSectorPacket(&DAT_00d1a840,0x70,auStack_10f0);

    ExceptionList = local_1c;

    return 0;

  }

  if (DAT_00d1b6d8[0x94] == 0) {

    ExceptionList = local_1c;

    return 0;

  }

  if ((char)DAT_00d1b6d8[0xc3] == '\0') {

    if (*(char *)((int)DAT_00d1b6d8 + 0x6b9) != '\0') goto LAB_0091e046;

  }

  else {

    if (*(char *)((int)DAT_00d1b6d8 + 0x6b9) == '\0') {

      if (*(int *)(DAT_00d1b6d8[0x94] + 8) != 0) {

        FUN_00402ae0(&fStack_10f8);

        if (fStack_10f8 == DAT_00d1b568) {

          fStack_10d0 = 0.0;

          uStack_10d4 = 0;

          uStack_10d8 = 0;

          uStack_10c4 = 0;

          uStack_10c8 = 0;

          uStack_10cc = 0;

          uStack_10b8 = 0;

          uStack_10bc = 0;

          uStack_10c0 = 0;

          fStack_10b4 = g_flMsToSeconds_Inferred;

          uStack_10a8 = 0;

          uStack_10ac = 0;

          uStack_10b0 = 0;

          uStack_1098 = 0;

          uStack_109c = 0;

          uStack_10a0 = 0;

          cVar5 = (**(code **)(*(int *)piVar8[0x94] + 0x48))(auStack_10f0,0);

          piVar8 = DAT_00d1b6d8;

          if (cVar5 != '\0') {

            local_10fc = Client_SendSectorPacket(&DAT_00d1a840,0x80,auStack_10f0);

            piVar8 = DAT_00d1b6d8;

          }

        }

        iVar10 = 3;

        iVar6 = 0;

        do {

          iVar3 = *(int *)(iVar6 + *(int *)(piVar8[0x94] + 0x260));

          if (iVar3 != 0) {

            *(uint8_t *)(iVar3 + 0xc9) = 0;

            piVar8 = DAT_00d1b6d8;

          }

          iVar6 = iVar6 + 4;

          iVar10 = iVar10 + -1;

        } while (iVar10 != 0);

      }

      goto LAB_0091e110;

    }

LAB_0091e046:

    piVar8 = *(int **)(*(int *)(DAT_00d1b6d8[1] + 4) + 0xa4 + (int)DAT_00d1b6d8);

    if (piVar8 == (int *)0x0) goto LAB_0091e110;

    piVar8 = (int *)(**(code **)(*piVar8 + 0x1d8))();

  }

  if ((piVar8 != (int *)0x0) && (piVar8[2] != 0)) {

    fStack_10d0 = 0.0;

    uStack_10d4 = 0;

    uStack_10d8 = 0;

    uStack_10c4 = 0;

    uStack_10c8 = 0;

    uStack_10cc = 0;

    uStack_10b8 = 0;

    uStack_10bc = 0;

    uStack_10c0 = 0;

    fStack_10b4 = g_flMsToSeconds_Inferred;

    uStack_10a8 = 0;

    uStack_10ac = 0;

    uStack_10b0 = 0;

    uStack_1098 = 0;

    uStack_109c = 0;

    uStack_10a0 = 0;

    cVar5 = (**(code **)(*piVar8 + 0x74))(auStack_10f0,0);

    if (cVar5 != '\0') {

      local_10fc = Client_SendSectorPacket(&DAT_00d1a840,0x70,auStack_10f0);

    }

  }

LAB_0091e110:

  fStack_10f8 = DAT_00d1b1cc;

  QueryPerformanceCounter((LARGE_INTEGER *)&DAT_00d1b590);

  QueryPerformanceCounter((LARGE_INTEGER *)&DAT_00d1b598);

  _DAT_00d1b58c = fStack_10f8;

  _DAT_00d1b588 = fStack_10f8;

  DAT_00d1b580 = 1;

  ExceptionList = local_1c;

  return local_10fc;

}
