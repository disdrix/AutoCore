// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvCreateC_00923770
// -----------------------------------------------------------------------------
// Stable ID: aa_00923770
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter
// Address:   0x00923770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~185 non-empty decompiler lines.
//  - Control keywords: if×22, for×3, do×2, while×2, return×1.
//  - Notable callees: FUN_007fef20×14, FUN_00403450×3, block×3, FUN_00857ee0×2, Client_MaybeShowFirstTimeTip, FUN_004c3f10, FUN_00850800, FUN_00857c20.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter
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

/* WARNING: Removing unreachable block (ram,0x00923a24) */

/* WARNING: Removing unreachable block (ram,0x00923894) */

/* WARNING: Removing unreachable block (ram,0x00923b0d) */



void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvCreateC_00923770(int *param_1)



{

  char cVar1;

  float fVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  char *pcVar5;

  uint uVar6;

  int iVar7;

  uint uVar8;

  char *pcVar9;

  uint32_t /* width from decompiler */ *puVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  char local_1a0 [127];

  char cStack_121;

  char acStack_120 [2];

  uint32_t /* width from decompiler */ auStack_11e [64];

  void *pvStack_1c;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009bb973;

  pvStack_14 = ExceptionList;

  ExceptionList = &pvStack_14;

  FUN_0093e3c0();

  iVar4 = DAT_00d1b8e4;

  if (DAT_00d1b8e4 != 0) {

    if (DAT_00d1a8e4 != '\0') {

      FUN_007fef20(0x1d,1,0);

    }

    fVar2 = g_flOne;

    iVar7 = *(int *)(DAT_00d1b644 + 0xe4f8);

    fVar11 = (float)*(int *)(iVar7 + 0x14) * *(float *)(iVar7 + 0x18);

    fVar13 = (float)*(int *)(iVar7 + 0x10) * *(float *)(iVar7 + 0x18);

    iVar7 = *(int *)(iVar4 + 0x518);

    if (iVar7 != 0) {

      fVar12 = fVar11;

      if (fVar13 < fVar11) {

        fVar12 = fVar13;

      }

      fVar12 = (fVar12 * DAT_00a0f298) / *(float *)(iVar7 + 0x504);

      DAT_00af931c = fVar13;

      DAT_00af9320 = fVar11;

      *(float *)(iVar7 + 0x4fc) = fVar12;

      if (fVar12 < fVar2) {

        *(float *)(iVar7 + 0x4fc) = fVar2;

      }

    }

    iVar7 = *(int *)(DAT_00d1b644 + 0xe4f8);

    uVar3 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00403450(iVar7 + 0x124,uVar3);

    uStack_c = 0;

    iVar4 = *(int *)(iVar4 + 0x518);

    if (iVar4 != 0) {

      FUN_00857ee0(iVar4);

    }

    uStack_c = 0xffffffff;

  }

  if (DAT_00d1b8d8 != 0) {

    FUN_007fef20(0x1a,1,0);

  }

  FUN_007fef20(0x30,1,0);

  if ((DAT_00d1b6d8 != 0) && (iVar4 = FUN_004c3f10(1), iVar4 != 0)) {

    FUN_007fef20(0x32,1,0);

  }

  iVar4 = DAT_00d1b8e8;

  if (DAT_00d1b8e8 != 0) {

    if (DAT_00d1a8e4 == '\0') {

      FUN_007fef20(0x1e,1,0);

    }

    fVar2 = g_flOne;

    iVar7 = *(int *)(DAT_00d1b644 + 0xe4f8);

    fVar11 = (float)*(int *)(iVar7 + 0x14) * *(float *)(iVar7 + 0x18);

    fVar13 = (float)*(int *)(iVar7 + 0x10) * *(float *)(iVar7 + 0x18);

    iVar7 = *(int *)(iVar4 + 0x538);

    if (iVar7 != 0) {

      fVar12 = fVar11;

      if (fVar13 < fVar11) {

        fVar12 = fVar13;

      }

      fVar12 = (fVar12 * DAT_00a0f298) / *(float *)(iVar7 + 0x504);

      DAT_00af931c = fVar13;

      DAT_00af9320 = fVar11;

      *(float *)(iVar7 + 0x4fc) = fVar12;

      if (fVar12 < fVar2) {

        *(float *)(iVar7 + 0x4fc) = fVar2;

      }

    }

    acStack_120[0] = '\0';

    acStack_120[1] = '\0';

    puVar10 = auStack_11e;

    for (iVar7 = 0x40; iVar7 != 0; iVar7 = iVar7 + -1) {

      *puVar10 = 0;

      puVar10 = puVar10 + 1;

    }

    *(uint16_t *)puVar10 = 0;

    iVar7 = *(int *)(DAT_00d1b644 + 0xe4f8);

    uVar3 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00403450(iVar7 + 0x124,uVar3);

    uStack_c = 1;

    pcVar5 = local_1a0;

    do {

      cVar1 = *pcVar5;

      pcVar5 = pcVar5 + 1;

    } while (cVar1 != '\0');

    uVar6 = (int)pcVar5 - (int)local_1a0;

    pcVar5 = &cStack_121;

    do {

      pcVar9 = pcVar5 + 1;

      pcVar5 = pcVar5 + 1;

    } while (*pcVar9 != '\0');

    pcVar9 = local_1a0;

    for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar5 = *(uint32_t /* width from decompiler */ *)pcVar9;

      pcVar9 = pcVar9 + 4;

      pcVar5 = pcVar5 + 4;

    }

    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

      *pcVar5 = *pcVar9;

      pcVar9 = pcVar9 + 1;

      pcVar5 = pcVar5 + 1;

    }

    uStack_c = 0xffffffff;

    if (*(int *)(iVar4 + 0x538) != 0) {

      FUN_00857ee0(*(int *)(iVar4 + 0x538));

    }

    if (*(int *)(iVar4 + 0x538) != 0) {

      FUN_00857c20();

    }

  }

  if (DAT_00d1a8e4 == '\0') {

    FUN_007fef20(0x21,1,0);

  }

  iVar4 = DAT_00d1b8c4;

  if (DAT_00d1b8c4 != 0) {

    FUN_00899260();

    iVar7 = *(int *)(DAT_00d1b644 + 0xe4f8);

    uVar3 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00403450(iVar7 + 0x124,uVar3);

    uStack_c = 2;

    if (*(int *)(iVar4 + 0x534) != 0) {

      FUN_00850800(*(int *)(iVar4 + 0x534),*(uint32_t /* width from decompiler */ *)(iVar4 + 0x53c));

    }

    uStack_c = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x53c) = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar4 + 0x534) + 0x59c);

  }

  FUN_007fef20(0x20,1,0);

  FUN_007fef20(0x1f,1,0);

  FUN_007fef20(0x16,1,0);

  FUN_007fef20(0x22,1,0);

  FUN_007fef20(0x23,1,0);

  FUN_007fef20(0x2f,1,0);

  FUN_007fef20(0x1c,1,0);

  FUN_007fef20(0x1b,1,0);

  param_1[0x1a] = param_1[0x1a] + 1;

  iVar4 = param_1[0x1a];

  param_1[0x1d] = (int)(float)-iVar4;

  if (param_1[0x1c] < iVar4) {

    param_1[0x1c] = iVar4;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  if ((int *)param_1[0x32c] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x32c] + 4))(1);

  }

  if ((int *)param_1[0x31e] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x31e] + 0x94))();

  }

  param_1[0x1a] = param_1[0x1a] + 1;

  iVar4 = param_1[0x1a];

  param_1[0x1d] = (int)(float)-iVar4;

  if (param_1[0x1c] < iVar4) {

    param_1[0x1c] = iVar4;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  (**(code **)(*param_1 + 0x318))();

  Client_MaybeShowFirstTimeTip(0);

  ExceptionList = pvStack_1c;

  return;

}
