// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, for×2.
//  - Notable callees: FUN_00684df0×2, FUN_00680d90, FUN_00685050, FUN_0076cec0, vog_LogMessage.
//  - Strings: "Encryption failed during SendInternal: %d".
//  - Return sites: 3.

// =============================================================================
// Named_netBaseUdpConnection_00685050
// -----------------------------------------------------------------------------
// Stable ID: aa_00685050
// Address:   0x00685050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "netBaseUdpConnection"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __thiscall Named_netBaseUdpConnection_00685050(int *param_1,int param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ *param_4)



{

  uint in_EAX;

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  

  uVar4 = *(uint *)(param_2 + 0xc);

  if (0x3ec < uVar4) {

    *param_4 = 3;

    return in_EAX & 0xffffff00;

  }

  uVar5 = uVar4 + 8;

  if (((uint)param_1[0x22] < uVar5) && (uVar5 != 0)) {

    if ((void *)param_1[0x20] != (void *)0x0) {

      operator_delete__((void *)param_1[0x20]);

    }

    pvVar1 = operator_new__(uVar5);

    param_1[0x20] = (int)pvVar1;

    param_1[0x22] = uVar5;

  }

  FUN_00680d90(param_1[0x20] + 8);

  puVar6 = (uint32_t /* width from decompiler */ *)param_1[0x20];

  *puVar6 = *param_3;

  *(uint8_t *)(puVar6 + 1) = *(uint8_t *)(param_3 + 1);

  *(uint8_t *)((int)puVar6 + 5) = *(uint8_t *)((int)param_3 + 5);

  *(uint16_t *)((int)puVar6 + 6) = *(uint16_t *)((int)param_3 + 6);

  if ((char)param_1[2] == '\0') {

    iVar7 = uVar4 + 4;

    iVar3 = 0x68518c;

    uVar2 = (**(code **)(*(int *)param_1[3] + 0x18))(param_1[0x20] + 4);

    FUN_00684df0(uVar5);

    puVar6 = (uint32_t /* width from decompiler */ *)(param_1[0x20] + 8);

    puVar8 = (uint32_t /* width from decompiler */ *)(param_1[0x1f] + 8);

    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *puVar8 = *puVar6;

      puVar6 = puVar6 + 1;

      puVar8 = puVar8 + 1;

    }

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *(uint8_t *)puVar8 = *(uint8_t *)puVar6;

      puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

      puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

    }

  }

  else {

    iVar7 = uVar4 + 4;

    uVar2 = (**(code **)(*(int *)param_1[3] + 0x20))(param_1[0x20] + 4);

    uVar5 = uVar4;

    iVar3 = (**(code **)(*(int *)param_1[3] + 8))(uVar4);

    FUN_00684df0(iVar3 + 8);

    iVar3 = (**(code **)(*(int *)param_1[3] + 0xc))

                      (&stack0xfffffffc,&stack0xfffffff8,param_1[0x20] + 8,uVar4,0);

    if (iVar3 != 0) {

      uVar2 = FUN_0076cec0(&stack0xffffffec,"Encryption failed during SendInternal: %d",iVar3);

      uVar4 = vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netBaseUdpConnection.cpp"

                             ,0x1d9,2,uVar2);

      return uVar4 & 0xffffff00;

    }

    iVar3 = uVar5 + 8;

  }

  puVar6 = (uint32_t /* width from decompiler */ *)param_1[0x1f];

  *puVar6 = *param_3;

  *(uint8_t *)(puVar6 + 1) = *(uint8_t *)(param_3 + 1);

  *(uint8_t *)((int)puVar6 + 5) = *(uint8_t *)((int)param_3 + 5);

  *(uint16_t *)((int)puVar6 + 6) = *(uint16_t *)((int)param_3 + 6);

  *(uint32_t /* width from decompiler */ *)param_1[0x1f] = uVar2;

  uVar4 = (**(code **)(*param_1 + 0x3c))(param_1[0x1f],iVar3,iVar7);

  return uVar4;

}
