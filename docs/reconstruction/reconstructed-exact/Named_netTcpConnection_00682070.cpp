// READABILITY (auto CF):
//  - Body size: ~168 non-empty decompiler lines.
//  - Control keywords: if×17, return×7, for×4, do×1, goto×1, while×1.
//  - Notable callees: FUN_00681dc0×3, FUN_0076cec0×3, vog_LogMessage×3, FUN_0067b790, FUN_006819b0, FUN_00681ad0, FUN_00682070, d.
//  - Strings: "Encryption of outbound packet failed!"; "fatal send error, closing connection".
//  - Return sites: 7.

// =============================================================================
// Named_netTcpConnection_00682070
// -----------------------------------------------------------------------------
// Stable ID: aa_00682070
// Address:   0x00682070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "netTcpConnection"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_netTcpConnection_00682070(int param_1,uint32_t /* width from decompiler */ *param_2,uint param_3,int *param_4)



{

  uint *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint uVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint *puVar7;

  int iVar8;

  uint uVar9;

  uint uVar10;

  uint32_t /* width from decompiler */ *puVar11;

  uint32_t /* width from decompiler */ *puVar12;

  uint32_t /* width from decompiler */ *local_10;

  uint32_t /* width from decompiler */ *local_c;

  int iStack_8;

  uint local_4;

  

  uVar4 = param_3;

  local_4 = param_3;

  local_10 = (uint32_t /* width from decompiler */ *)0x0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

  if (param_3 == 0) {

    uVar6 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

    uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x70);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x74);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x78);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = uVar6;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = uVar2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = 0;

  }

  else {

    if (*(char *)(param_1 + 0x28) != '\0') {

      param_3 = (**(code **)(**(int **)(param_1 + 0x2c) + 8))(param_3);

    }

    uVar10 = *(int *)(param_1 + 0x7c) + 4 + param_3;

    if ((uint)(*(int *)(param_1 + 0x74) - *(int *)(param_1 + 0x78)) < uVar10) {

      FUN_006819b0(uVar10);

      if ((*(int *)(param_1 + 0x70) != 0) && (uVar10 = *(uint *)(param_1 + 0x7c), uVar10 != 0)) {

        puVar11 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x78) + *(int *)(param_1 + 0x70));

        puVar12 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1c);

        for (uVar9 = uVar10 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {

          *puVar12 = *puVar11;

          puVar11 = puVar11 + 1;

          puVar12 = puVar12 + 1;

        }

        for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

          *(uint8_t *)puVar12 = *(uint8_t *)puVar11;

          puVar11 = (uint32_t /* width from decompiler */ *)((int)puVar11 + 1);

          puVar12 = (uint32_t /* width from decompiler */ *)((int)puVar12 + 1);

        }

      }

    }

    else {

      uVar6 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

      uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

      uVar3 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x70);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = uVar3;

      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x74);

      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x78);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = uVar2;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = uVar6;

    }

    iVar8 = *(int *)(param_1 + 0x7c) + *(int *)(param_1 + 0x24);

    local_c = (uint32_t /* width from decompiler */ *)(iVar8 + 4 + *(int *)(param_1 + 0x1c));

    iStack_8 = iVar8;

    if (*(char *)(param_1 + 0x28) == '\0') {

      puVar11 = param_2;

      puVar12 = local_c;

      for (uVar10 = uVar4 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

        *puVar12 = *puVar11;

        puVar11 = puVar11 + 1;

        puVar12 = puVar12 + 1;

      }

      for (uVar10 = uVar4 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

        *(uint8_t *)puVar12 = *(uint8_t *)puVar11;

        puVar11 = (uint32_t /* width from decompiler */ *)((int)puVar11 + 1);

        puVar12 = (uint32_t /* width from decompiler */ *)((int)puVar12 + 1);

      }

      *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + uVar4 + 4;

      *(uint *)(iVar8 + *(int *)(param_1 + 0x1c)) = local_4;

    }

    else {

      iVar5 = (**(code **)(**(int **)(param_1 + 0x2c) + 0xc))(&local_c,&param_3,param_2,uVar4,0);

      if (iVar5 != 0) {

        uVar6 = FUN_0076cec0(&param_4,"Encryption of outbound packet failed!");

        vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                       ,0x123,3,uVar6);

        FUN_00681dc0();

        return 0;

      }

      *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + param_3 + 4;

      *(uint *)(iVar8 + *(int *)(param_1 + 0x1c)) = param_3;

    }

  }

  puVar1 = (uint *)(param_1 + 0x7c);

  puVar7 = puVar1;

  if (0xfffe < *(uint *)(param_1 + 0x7c)) {

    puVar7 = &DAT_009e9758;

  }

  puVar11 = (uint32_t /* width from decompiler */ *)*puVar7;

  if (*puVar1 == 0) {

    *param_4 = 0;

    return 1;

  }

  do {

    puVar12 = (uint32_t /* width from decompiler */ *)*puVar1;

    if (puVar11 < (uint32_t /* width from decompiler */ *)*puVar1) {

      puVar12 = puVar11;

    }

    iVar8 = FUN_0067b790(*(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x1c),puVar12,&local_10,

                         param_4);

    if (iVar8 < 0) {

      uVar6 = FUN_0076cec0(&param_4,"fatal send error, closing connection");

      vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                     ,0x18a,2,uVar6);

      FUN_00681dc0();

      return 0;

    }

    iVar8 = *param_4;

    if ((iVar8 == 0) && (local_10 == puVar12)) {

      *puVar1 = *puVar1 - (int)local_10;

      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (int)local_10;

      puVar11 = (uint32_t /* width from decompiler */ *)0xffff;

      if (*puVar1 == 0) {

LAB_0068225b:

        FUN_00681ad0();

        return 1;

      }

    }

    else {

      if ((iVar8 == 1) || (iVar8 == 0)) {

        *puVar1 = *puVar1 - (int)local_10;

        iVar8 = *(int *)(param_1 + 0x24);

        uVar6 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

        uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x70);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x74);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x78);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = uVar6;

        *(int *)(param_1 + 0x78) = iVar8 + (int)local_10;

        return 1;

      }

      if (iVar8 != 2) {

        uVar6 = FUN_0076cec0(&param_4,

                             "TCP Session: socket returned OK result, but retry was unknown/unhandled value %d (sent = %d, sendBytes = %d)!"

                             ,*param_4,local_10,puVar12);

        vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                       ,0x182,2,uVar6);

        FUN_00681dc0();

        return 0;

      }

      if (puVar12 < (uint32_t /* width from decompiler */ *)0x81) goto LAB_0068225b;

      param_2 = (uint32_t /* width from decompiler */ *)((uint)puVar11 >> 1);

      puVar7 = &DAT_009e975c;

      if ((uint32_t /* width from decompiler */ *)0x7f < (uint32_t /* width from decompiler */ *)((uint)puVar11 >> 1)) {

        puVar7 = (uint *)&param_2;

      }

      puVar11 = (uint32_t /* width from decompiler */ *)*puVar7;

    }

    if (*puVar1 == 0) {

      return 0;

    }

  } while( true );

}
