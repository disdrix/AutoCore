// =============================================================================
// FUN_004da2e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004da2e0
// Address:   0x004da2e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004da2e0 @ 0x004da2e0
// Stable ID: aa_004da2e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~168 non-empty decompiler lines.
//  - Control keywords: if×15, goto×5, return×3, while×2, for×2, do×1.
//  - Notable callees: CONCAT31, FUN_004bb070, FUN_004d78e0, FUN_004da2e0, FUN_004e0eb0, FUN_004e1600, FUN_004e39d0, Object_ResolveFromTFID.
//  - Return sites: 3.

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

void __thiscall

FUN_004da2e0(int param_1,TFID_16 *param_2,uint param_3,int *param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint param_8,uint param_9,uint32_t /* width from decompiler */ param_10,

            uint32_t /* width from decompiler */ param_11,uint32_t /* width from decompiler */ *param_12)



{

  TFID_16 *pTfid;

  char cVar1;

  uint8_t uVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  int *piVar6;

  uint32_t /* width from decompiler */ *puVar7;

  TFID_16 *pTVar8;

  uint uVar9;

  uint32_t /* width from decompiler */ *puVar10;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ *local_18;

  uint32_t /* width from decompiler */ *local_14;

  int local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a2290;

  pvStack_c = ExceptionList;

  puVar7 = (uint32_t /* width from decompiler */ *)0x0;

  local_18 = (uint32_t /* width from decompiler */ *)0x0;

  local_14 = (uint32_t /* width from decompiler */ *)0x0;

  local_10 = 0;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  if (0 < (int)param_3) {

    pTVar8 = param_2 + 1;

    ExceptionList = &pvStack_c;

    do {

      pTfid = pTVar8 + -1;

      piVar3 = Object_ResolveFromTFID(pTfid);

      if ((piVar3 != (int *)0x0) && (cVar1 = (**(code **)(*piVar3 + 0x198))(), cVar1 == '\0')) {

        uStack_2c = *(uint32_t /* width from decompiler */ *)((int)&pTVar8->dwCoidHi + 2);

        uStack_28._0_1_ = pTVar8->bPad1;

        uStack_28._1_1_ = pTVar8->bPad2;

        uStack_28._2_1_ = pTVar8->bPad3;

        uStack_28._3_1_ = pTVar8->bPad4;

        uStack_24 = CONCAT31(uStack_24._1_3_,pTVar8->bPad5);

        uVar2 = FUN_004d78e0(*(uint8_t *)((int)&pTVar8->dwCoidHi + 1),pTVar8->dwCoidLo,param_4,

                             piVar3,param_6,param_7,param_8,param_9,param_10,param_11,&uStack_2c);

        *(uint8_t *)&pTVar8->dwCoidHi = uVar2;

        param_2 = pTfid;

        if ((local_18 == (uint32_t /* width from decompiler */ *)0x0) ||

           ((uint)(local_10 - (int)local_18 >> 2) <= (uint)((int)puVar7 - (int)local_18 >> 2))) {

          FUN_004e39d0(puVar7,1,&param_2);

          puVar7 = local_14;

        }

        else {

          *puVar7 = pTfid;

          local_14 = puVar7 + 1;

          puVar7 = local_14;

        }

      }

      pTVar8 = pTVar8 + 2;

      param_3 = param_3 - 1;

    } while (param_3 != 0);

    param_3 = 0;

  }

  if (*(char *)(param_1 + 0x7e) == '\0') goto LAB_004da600;

  if (local_18 == (uint32_t /* width from decompiler */ *)0x0) {

    ExceptionList = pvStack_c;

    return;

  }

  uVar9 = (int)puVar7 - (int)local_18 >> 2;

  param_3 = uVar9;

  if (uVar9 == 0) goto LAB_004da600;

  puVar4 = operator_new(0x28);

  piVar3 = param_4;

  puVar7 = (uint32_t /* width from decompiler */ *)0x0;

  if (puVar4 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar4[9] = 0;

    puVar7 = puVar4;

  }

  *(uint8_t *)(puVar7 + 8) = (uint8_t)param_6;

  if (param_4 == (int *)0x0) {

    piVar3 = &DAT_009cbf68;

LAB_004da529:

    puVar7[4] = *piVar3;

    puVar7[5] = piVar3[1];

    puVar7[6] = piVar3[2];

LAB_004da53e:

    iVar5 = piVar3[3];

  }

  else {

    piVar6 = param_4;

    if (*(int *)(param_4[0x2a] + 0x38) != 0x12) {

      piVar3 = param_4 + 0x58;

      uVar9 = param_3;

      goto LAB_004da529;

    }

    while (*(int *)(piVar6[0x2a] + 0x38) == 0x12) {

      iVar5 = (**(code **)(*piVar6 + 0x1d8))();

      uStack_2c = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x228);

      uStack_28 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x22c);

      uStack_24 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x230);

      uStack_20 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x234);

      iVar5 = FUN_004bb070(&uStack_2c);

      if ((iVar5 == 0) ||

         (piVar6 = (int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5), piVar6 == (int *)0x0))

      goto LAB_004da4c7;

    }

    if (*(int *)(piVar6[0x2a] + 0x38) == 0x14) {

      piVar3 = piVar6 + 0x58;

      puVar7[4] = *piVar3;

      puVar7[5] = piVar6[0x59];

      puVar7[6] = piVar6[0x5a];

      uVar9 = param_3;

      goto LAB_004da53e;

    }

LAB_004da4c7:

    puVar7[4] = piVar3[0x58];

    puVar7[5] = piVar3[0x59];

    puVar7[6] = piVar3[0x5a];

    iVar5 = piVar3[0x5b];

    uVar9 = param_3;

  }

  puVar4 = puVar7 + 4;

  puVar7[7] = iVar5;

  if (((param_8 & param_9) != 0xffffffff) || ((char)param_10 != '\0')) {

    puVar4 = &param_8;

  }

  *puVar7 = *puVar4;

  puVar7[1] = puVar4[1];

  puVar7[2] = puVar4[2];

  puVar7[3] = puVar4[3];

  *(short *)((int)puVar7 + 0x22) = (short)uVar9;

  puVar4 = operator_new__((uVar9 & 0xffff) << 5);

  puVar7[9] = puVar4;

  if (uVar9 == 0) {

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_004e0eb0();

  }

  puVar10 = (uint32_t /* width from decompiler */ *)*local_18;

  for (uVar9 = ((uint)*(ushort *)((int)puVar7 + 0x22) << 5) >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {

    *puVar4 = *puVar10;

    puVar10 = puVar10 + 1;

    puVar4 = puVar4 + 1;

  }

  for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {

    *(uint8_t *)puVar4 = *(uint8_t *)puVar10;

    puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

    puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

  }

  if (param_12 != (uint32_t /* width from decompiler */ *)0x0) {

    *(uint8_t *)(puVar7[9] + 0x1c) = *(uint8_t *)((int)param_12 + 6);

    *(uint8_t *)(puVar7[9] + 0x1d) = *(uint8_t *)((int)param_12 + 7);

    *(uint8_t *)(puVar7[9] + 0x1e) = *(uint8_t *)(param_12 + 2);

    iVar5 = puVar7[9];

    *(uint32_t /* width from decompiler */ *)(iVar5 + 0x16) = *param_12;

    *(uint16_t *)(iVar5 + 0x1a) = *(uint16_t *)(param_12 + 1);

  }

  FUN_004e1600(puVar7);

LAB_004da600:

  if (local_18 == (uint32_t /* width from decompiler */ *)0x0) {

    ExceptionList = pvStack_c;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(local_18);

}
